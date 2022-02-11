static struct V_1 * F_1 ( unsigned int V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
V_3 &= ~ ( V_6 | V_7 ) ;
V_4 = F_2 ( V_2 * sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_4 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
V_4 [ V_5 ] . V_8 = V_5 + 1 ;
return V_4 ;
}
static inline int F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 [] ,
unsigned int V_2 ,
unsigned int V_13 ,
unsigned int V_14 ,
void * V_15 ,
T_1 V_3 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
struct V_11 * V_18 ;
struct V_1 * V_4 ;
unsigned int V_5 , V_19 , V_20 , V_21 , V_22 ( V_23 ) ;
int V_24 ;
bool V_25 ;
F_5 ( V_17 ) ;
F_6 ( V_15 == NULL ) ;
if ( F_7 ( V_17 -> V_26 ) ) {
F_8 ( V_17 ) ;
return - V_27 ;
}
#ifdef F_9
{
T_2 V_28 = F_10 () ;
if ( V_17 -> V_29 )
F_11 ( F_12 ( F_13 ( V_28 , V_17 -> V_30 ) )
> 100 ) ;
V_17 -> V_30 = V_28 ;
V_17 -> V_29 = true ;
}
#endif
F_6 ( V_2 > V_17 -> V_31 . V_32 ) ;
F_6 ( V_2 == 0 ) ;
V_24 = V_17 -> V_33 ;
if ( V_17 -> V_25 && V_2 > 1 && V_17 -> V_17 . V_34 )
V_4 = F_1 ( V_2 , V_3 ) ;
else
V_4 = NULL ;
if ( V_4 ) {
V_17 -> V_31 . V_4 [ V_24 ] . V_35 = V_36 ;
V_17 -> V_31 . V_4 [ V_24 ] . V_37 = F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
V_17 -> V_31 . V_4 [ V_24 ] . V_38 = V_2 * sizeof( struct V_1 ) ;
V_5 = 0 ;
V_21 = 1 ;
V_25 = true ;
} else {
V_4 = V_17 -> V_31 . V_4 ;
V_5 = V_24 ;
V_21 = V_2 ;
V_25 = false ;
}
if ( V_17 -> V_17 . V_34 < V_21 ) {
F_16 ( L_1 ,
V_21 , V_17 -> V_17 . V_34 ) ;
if ( V_13 )
V_17 -> V_39 ( & V_17 -> V_17 ) ;
F_8 ( V_17 ) ;
return - V_40 ;
}
V_17 -> V_17 . V_34 -= V_21 ;
for ( V_19 = 0 ; V_19 < V_13 ; V_19 ++ ) {
for ( V_18 = V_12 [ V_19 ] ; V_18 ; V_18 = F_17 ( V_18 ) ) {
V_4 [ V_5 ] . V_35 = V_41 ;
V_4 [ V_5 ] . V_37 = F_18 ( V_18 ) ;
V_4 [ V_5 ] . V_38 = V_18 -> V_42 ;
V_23 = V_5 ;
V_5 = V_4 [ V_5 ] . V_8 ;
}
}
for (; V_19 < ( V_13 + V_14 ) ; V_19 ++ ) {
for ( V_18 = V_12 [ V_19 ] ; V_18 ; V_18 = F_17 ( V_18 ) ) {
V_4 [ V_5 ] . V_35 = V_41 | V_43 ;
V_4 [ V_5 ] . V_37 = F_18 ( V_18 ) ;
V_4 [ V_5 ] . V_38 = V_18 -> V_42 ;
V_23 = V_5 ;
V_5 = V_4 [ V_5 ] . V_8 ;
}
}
V_4 [ V_23 ] . V_35 &= ~ V_41 ;
if ( V_25 )
V_17 -> V_33 = V_17 -> V_31 . V_4 [ V_24 ] . V_8 ;
else
V_17 -> V_33 = V_5 ;
V_17 -> V_15 [ V_24 ] = V_15 ;
V_20 = ( V_17 -> V_31 . V_20 -> V_44 & ( V_17 -> V_31 . V_32 - 1 ) ) ;
V_17 -> V_31 . V_20 -> V_45 [ V_20 ] = V_24 ;
F_19 ( V_17 -> V_46 ) ;
V_17 -> V_31 . V_20 -> V_44 ++ ;
V_17 -> V_47 ++ ;
if ( F_7 ( V_17 -> V_47 == ( 1 << 16 ) - 1 ) )
F_20 ( V_10 ) ;
F_16 ( L_2 , V_24 , V_17 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 ,
struct V_11 * V_12 [] ,
unsigned int V_13 ,
unsigned int V_14 ,
void * V_15 ,
T_1 V_3 )
{
unsigned int V_5 , V_2 = 0 ;
for ( V_5 = 0 ; V_5 < V_13 + V_14 ; V_5 ++ ) {
struct V_11 * V_18 ;
for ( V_18 = V_12 [ V_5 ] ; V_18 ; V_18 = F_17 ( V_18 ) )
V_2 ++ ;
}
return F_3 ( V_10 , V_12 , V_2 , V_13 , V_14 , V_15 , V_3 ) ;
}
int F_22 ( struct V_9 * V_17 ,
struct V_11 * V_18 , unsigned int V_32 ,
void * V_15 ,
T_1 V_3 )
{
return F_3 ( V_17 , & V_18 , V_32 , 1 , 0 , V_15 , V_3 ) ;
}
int F_23 ( struct V_9 * V_17 ,
struct V_11 * V_18 , unsigned int V_32 ,
void * V_15 ,
T_1 V_3 )
{
return F_3 ( V_17 , & V_18 , V_32 , 0 , 1 , V_15 , V_3 ) ;
}
bool F_24 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
T_3 V_48 , V_49 ;
bool V_50 ;
F_5 ( V_17 ) ;
F_25 ( V_17 -> V_46 ) ;
V_49 = V_17 -> V_31 . V_20 -> V_44 - V_17 -> V_47 ;
V_48 = V_17 -> V_31 . V_20 -> V_44 ;
V_17 -> V_47 = 0 ;
#ifdef F_9
if ( V_17 -> V_29 ) {
F_11 ( F_12 ( F_13 ( F_10 () ,
V_17 -> V_30 ) ) > 100 ) ;
}
V_17 -> V_29 = false ;
#endif
if ( V_17 -> V_51 ) {
V_50 = F_26 ( F_27 ( & V_17 -> V_31 ) ,
V_48 , V_49 ) ;
} else {
V_50 = ! ( V_17 -> V_31 . V_52 -> V_35 & V_53 ) ;
}
F_8 ( V_17 ) ;
return V_50 ;
}
bool F_28 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
if ( F_7 ( V_17 -> V_26 ) )
return false ;
if ( ! V_17 -> V_39 ( V_10 ) ) {
V_17 -> V_26 = true ;
return false ;
}
return true ;
}
bool F_20 ( struct V_9 * V_17 )
{
if ( F_24 ( V_17 ) )
return F_28 ( V_17 ) ;
return true ;
}
static void F_29 ( struct V_16 * V_17 , unsigned int V_24 )
{
unsigned int V_5 ;
V_17 -> V_15 [ V_24 ] = NULL ;
V_5 = V_24 ;
if ( V_17 -> V_31 . V_4 [ V_5 ] . V_35 & V_36 )
F_30 ( F_31 ( V_17 -> V_31 . V_4 [ V_5 ] . V_37 ) ) ;
while ( V_17 -> V_31 . V_4 [ V_5 ] . V_35 & V_41 ) {
V_5 = V_17 -> V_31 . V_4 [ V_5 ] . V_8 ;
V_17 -> V_17 . V_34 ++ ;
}
V_17 -> V_31 . V_4 [ V_5 ] . V_8 = V_17 -> V_33 ;
V_17 -> V_33 = V_24 ;
V_17 -> V_17 . V_34 ++ ;
}
static inline bool F_32 ( const struct V_16 * V_17 )
{
return V_17 -> V_54 != V_17 -> V_31 . V_52 -> V_44 ;
}
void * F_33 ( struct V_9 * V_10 , unsigned int * V_38 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
void * V_55 ;
unsigned int V_5 ;
T_3 V_56 ;
F_5 ( V_17 ) ;
if ( F_7 ( V_17 -> V_26 ) ) {
F_8 ( V_17 ) ;
return NULL ;
}
if ( ! F_32 ( V_17 ) ) {
F_16 ( L_3 ) ;
F_8 ( V_17 ) ;
return NULL ;
}
F_34 ( V_17 -> V_46 ) ;
V_56 = ( V_17 -> V_54 & ( V_17 -> V_31 . V_32 - 1 ) ) ;
V_5 = V_17 -> V_31 . V_52 -> V_45 [ V_56 ] . V_57 ;
* V_38 = V_17 -> V_31 . V_52 -> V_45 [ V_56 ] . V_38 ;
if ( F_7 ( V_5 >= V_17 -> V_31 . V_32 ) ) {
F_35 ( V_17 , L_4 , V_5 ) ;
return NULL ;
}
if ( F_7 ( ! V_17 -> V_15 [ V_5 ] ) ) {
F_35 ( V_17 , L_5 , V_5 ) ;
return NULL ;
}
V_55 = V_17 -> V_15 [ V_5 ] ;
F_29 ( V_17 , V_5 ) ;
V_17 -> V_54 ++ ;
if ( ! ( V_17 -> V_31 . V_20 -> V_35 & V_58 ) ) {
F_36 ( & V_17 -> V_31 ) = V_17 -> V_54 ;
F_25 ( V_17 -> V_46 ) ;
}
#ifdef F_9
V_17 -> V_29 = false ;
#endif
F_8 ( V_17 ) ;
return V_55 ;
}
void F_37 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
V_17 -> V_31 . V_20 -> V_35 |= V_58 ;
}
unsigned F_38 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
T_3 V_54 ;
F_5 ( V_17 ) ;
V_17 -> V_31 . V_20 -> V_35 &= ~ V_58 ;
F_36 ( & V_17 -> V_31 ) = V_54 = V_17 -> V_54 ;
F_8 ( V_17 ) ;
return V_54 ;
}
bool F_39 ( struct V_9 * V_10 , unsigned V_54 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
F_25 ( V_17 -> V_46 ) ;
return ( T_3 ) V_54 != V_17 -> V_31 . V_52 -> V_44 ;
}
bool F_40 ( struct V_9 * V_10 )
{
unsigned V_54 = F_38 ( V_10 ) ;
return ! F_39 ( V_10 , V_54 ) ;
}
bool F_41 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
T_3 V_59 ;
F_5 ( V_17 ) ;
V_17 -> V_31 . V_20 -> V_35 &= ~ V_58 ;
V_59 = ( T_3 ) ( V_17 -> V_31 . V_20 -> V_44 - V_17 -> V_54 ) * 3 / 4 ;
F_36 ( & V_17 -> V_31 ) = V_17 -> V_54 + V_59 ;
F_25 ( V_17 -> V_46 ) ;
if ( F_7 ( ( T_3 ) ( V_17 -> V_31 . V_52 -> V_44 - V_17 -> V_54 ) > V_59 ) ) {
F_8 ( V_17 ) ;
return false ;
}
F_8 ( V_17 ) ;
return true ;
}
void * F_42 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
unsigned int V_5 ;
void * V_60 ;
F_5 ( V_17 ) ;
for ( V_5 = 0 ; V_5 < V_17 -> V_31 . V_32 ; V_5 ++ ) {
if ( ! V_17 -> V_15 [ V_5 ] )
continue;
V_60 = V_17 -> V_15 [ V_5 ] ;
F_29 ( V_17 , V_5 ) ;
V_17 -> V_31 . V_20 -> V_44 -- ;
F_8 ( V_17 ) ;
return V_60 ;
}
F_6 ( V_17 -> V_17 . V_34 != V_17 -> V_31 . V_32 ) ;
F_8 ( V_17 ) ;
return NULL ;
}
T_4 F_43 ( int V_61 , void * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
if ( ! F_32 ( V_17 ) ) {
F_16 ( L_6 , V_17 ) ;
return V_62 ;
}
if ( F_7 ( V_17 -> V_26 ) )
return V_63 ;
F_16 ( L_7 , V_17 , V_17 -> V_17 . V_64 ) ;
if ( V_17 -> V_17 . V_64 )
V_17 -> V_17 . V_64 ( & V_17 -> V_17 ) ;
return V_63 ;
}
struct V_9 * F_44 ( unsigned int V_65 ,
unsigned int V_32 ,
unsigned int V_66 ,
struct V_67 * V_68 ,
bool V_46 ,
void * V_69 ,
bool (* V_39)( struct V_9 * ) ,
void (* V_64)( struct V_9 * ) ,
const char * V_70 )
{
struct V_16 * V_17 ;
unsigned int V_5 ;
if ( V_32 & ( V_32 - 1 ) ) {
F_45 ( & V_68 -> V_71 , L_8 , V_32 ) ;
return NULL ;
}
V_17 = F_2 ( sizeof( * V_17 ) + sizeof( void * ) * V_32 , V_72 ) ;
if ( ! V_17 )
return NULL ;
F_46 ( & V_17 -> V_31 , V_32 , V_69 , V_66 ) ;
V_17 -> V_17 . V_64 = V_64 ;
V_17 -> V_17 . V_68 = V_68 ;
V_17 -> V_17 . V_70 = V_70 ;
V_17 -> V_17 . V_34 = V_32 ;
V_17 -> V_17 . V_65 = V_65 ;
V_17 -> V_39 = V_39 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_26 = false ;
V_17 -> V_54 = 0 ;
V_17 -> V_47 = 0 ;
F_47 ( & V_17 -> V_17 . V_73 , & V_68 -> V_74 ) ;
#ifdef F_9
V_17 -> V_75 = false ;
V_17 -> V_29 = false ;
#endif
V_17 -> V_25 = F_48 ( V_68 , V_76 ) ;
V_17 -> V_51 = F_48 ( V_68 , V_77 ) ;
if ( ! V_64 )
V_17 -> V_31 . V_20 -> V_35 |= V_58 ;
V_17 -> V_33 = 0 ;
for ( V_5 = 0 ; V_5 < V_32 - 1 ; V_5 ++ ) {
V_17 -> V_31 . V_4 [ V_5 ] . V_8 = V_5 + 1 ;
V_17 -> V_15 [ V_5 ] = NULL ;
}
V_17 -> V_15 [ V_5 ] = NULL ;
return & V_17 -> V_17 ;
}
void F_49 ( struct V_9 * V_17 )
{
F_50 ( & V_17 -> V_73 ) ;
F_30 ( F_4 ( V_17 ) ) ;
}
void F_51 ( struct V_67 * V_68 )
{
unsigned int V_5 ;
for ( V_5 = V_78 ; V_5 < V_79 ; V_5 ++ ) {
switch ( V_5 ) {
case V_76 :
break;
case V_77 :
break;
default:
F_52 ( V_5 , V_68 -> V_80 ) ;
}
}
}
unsigned int F_53 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
return V_17 -> V_31 . V_32 ;
}
bool F_54 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
return V_17 -> V_26 ;
}
void F_55 ( struct V_67 * V_71 )
{
struct V_9 * V_10 ;
F_56 (_vq, &dev->vqs, list) {
struct V_16 * V_17 = F_4 ( V_10 ) ;
V_17 -> V_26 = true ;
}
}
