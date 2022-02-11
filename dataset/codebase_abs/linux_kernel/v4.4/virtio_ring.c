static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
unsigned int V_7 ;
V_5 &= ~ V_8 ;
V_6 = F_2 ( V_4 * sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_6 )
return NULL ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ )
V_6 [ V_7 ] . V_9 = F_3 ( V_3 -> V_10 , V_7 + 1 ) ;
return V_6 ;
}
static inline int F_4 ( struct V_2 * V_3 ,
struct V_11 * V_12 [] ,
unsigned int V_4 ,
unsigned int V_13 ,
unsigned int V_14 ,
void * V_15 ,
T_1 V_5 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
struct V_11 * V_18 ;
struct V_1 * V_6 ;
unsigned int V_7 , V_19 , V_20 , V_21 , V_22 ( V_23 ) ;
int V_24 ;
bool V_25 ;
F_6 ( V_17 ) ;
F_7 ( V_15 == NULL ) ;
if ( F_8 ( V_17 -> V_26 ) ) {
F_9 ( V_17 ) ;
return - V_27 ;
}
#ifdef F_10
{
T_2 V_28 = F_11 () ;
if ( V_17 -> V_29 )
F_12 ( F_13 ( F_14 ( V_28 , V_17 -> V_30 ) )
> 100 ) ;
V_17 -> V_30 = V_28 ;
V_17 -> V_29 = true ;
}
#endif
F_7 ( V_4 > V_17 -> V_31 . V_32 ) ;
F_7 ( V_4 == 0 ) ;
V_24 = V_17 -> V_33 ;
if ( V_17 -> V_25 && V_4 > 1 && V_17 -> V_17 . V_34 )
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
else
V_6 = NULL ;
if ( V_6 ) {
V_17 -> V_31 . V_6 [ V_24 ] . V_35 = F_3 ( V_3 -> V_10 , V_36 ) ;
V_17 -> V_31 . V_6 [ V_24 ] . V_37 = F_15 ( V_3 -> V_10 , F_16 ( V_6 ) ) ;
F_17 ( V_6 ) ;
V_17 -> V_31 . V_6 [ V_24 ] . V_38 = F_18 ( V_3 -> V_10 , V_4 * sizeof( struct V_1 ) ) ;
V_7 = 0 ;
V_21 = 1 ;
V_25 = true ;
} else {
V_6 = V_17 -> V_31 . V_6 ;
V_7 = V_24 ;
V_21 = V_4 ;
V_25 = false ;
}
if ( V_17 -> V_17 . V_34 < V_21 ) {
F_19 ( L_1 ,
V_21 , V_17 -> V_17 . V_34 ) ;
if ( V_13 )
V_17 -> V_39 ( & V_17 -> V_17 ) ;
F_9 ( V_17 ) ;
return - V_40 ;
}
V_17 -> V_17 . V_34 -= V_21 ;
for ( V_19 = 0 ; V_19 < V_13 ; V_19 ++ ) {
for ( V_18 = V_12 [ V_19 ] ; V_18 ; V_18 = F_20 ( V_18 ) ) {
V_6 [ V_7 ] . V_35 = F_3 ( V_3 -> V_10 , V_41 ) ;
V_6 [ V_7 ] . V_37 = F_15 ( V_3 -> V_10 , F_21 ( V_18 ) ) ;
V_6 [ V_7 ] . V_38 = F_18 ( V_3 -> V_10 , V_18 -> V_42 ) ;
V_23 = V_7 ;
V_7 = F_22 ( V_3 -> V_10 , V_6 [ V_7 ] . V_9 ) ;
}
}
for (; V_19 < ( V_13 + V_14 ) ; V_19 ++ ) {
for ( V_18 = V_12 [ V_19 ] ; V_18 ; V_18 = F_20 ( V_18 ) ) {
V_6 [ V_7 ] . V_35 = F_3 ( V_3 -> V_10 , V_41 | V_43 ) ;
V_6 [ V_7 ] . V_37 = F_15 ( V_3 -> V_10 , F_21 ( V_18 ) ) ;
V_6 [ V_7 ] . V_38 = F_18 ( V_3 -> V_10 , V_18 -> V_42 ) ;
V_23 = V_7 ;
V_7 = F_22 ( V_3 -> V_10 , V_6 [ V_7 ] . V_9 ) ;
}
}
V_6 [ V_23 ] . V_35 &= F_3 ( V_3 -> V_10 , ~ V_41 ) ;
if ( V_25 )
V_17 -> V_33 = F_22 ( V_3 -> V_10 , V_17 -> V_31 . V_6 [ V_24 ] . V_9 ) ;
else
V_17 -> V_33 = V_7 ;
V_17 -> V_15 [ V_24 ] = V_15 ;
V_20 = V_17 -> V_44 & ( V_17 -> V_31 . V_32 - 1 ) ;
V_17 -> V_31 . V_20 -> V_45 [ V_20 ] = F_3 ( V_3 -> V_10 , V_24 ) ;
F_23 ( V_17 -> V_46 ) ;
V_17 -> V_44 ++ ;
V_17 -> V_31 . V_20 -> V_47 = F_3 ( V_3 -> V_10 , V_17 -> V_44 ) ;
V_17 -> V_48 ++ ;
F_19 ( L_2 , V_24 , V_17 ) ;
F_9 ( V_17 ) ;
if ( F_8 ( V_17 -> V_48 == ( 1 << 16 ) - 1 ) )
F_24 ( V_3 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_3 ,
struct V_11 * V_12 [] ,
unsigned int V_13 ,
unsigned int V_14 ,
void * V_15 ,
T_1 V_5 )
{
unsigned int V_7 , V_4 = 0 ;
for ( V_7 = 0 ; V_7 < V_13 + V_14 ; V_7 ++ ) {
struct V_11 * V_18 ;
for ( V_18 = V_12 [ V_7 ] ; V_18 ; V_18 = F_20 ( V_18 ) )
V_4 ++ ;
}
return F_4 ( V_3 , V_12 , V_4 , V_13 , V_14 , V_15 , V_5 ) ;
}
int F_26 ( struct V_2 * V_17 ,
struct V_11 * V_18 , unsigned int V_32 ,
void * V_15 ,
T_1 V_5 )
{
return F_4 ( V_17 , & V_18 , V_32 , 1 , 0 , V_15 , V_5 ) ;
}
int F_27 ( struct V_2 * V_17 ,
struct V_11 * V_18 , unsigned int V_32 ,
void * V_15 ,
T_1 V_5 )
{
return F_4 ( V_17 , & V_18 , V_32 , 0 , 1 , V_15 , V_5 ) ;
}
bool F_28 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
T_3 V_49 , V_50 ;
bool V_51 ;
F_6 ( V_17 ) ;
F_29 ( V_17 -> V_46 ) ;
V_50 = V_17 -> V_44 - V_17 -> V_48 ;
V_49 = V_17 -> V_44 ;
V_17 -> V_48 = 0 ;
#ifdef F_10
if ( V_17 -> V_29 ) {
F_12 ( F_13 ( F_14 ( F_11 () ,
V_17 -> V_30 ) ) > 100 ) ;
}
V_17 -> V_29 = false ;
#endif
if ( V_17 -> V_52 ) {
V_51 = F_30 ( F_22 ( V_3 -> V_10 , F_31 ( & V_17 -> V_31 ) ) ,
V_49 , V_50 ) ;
} else {
V_51 = ! ( V_17 -> V_31 . V_53 -> V_35 & F_3 ( V_3 -> V_10 , V_54 ) ) ;
}
F_9 ( V_17 ) ;
return V_51 ;
}
bool F_32 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
if ( F_8 ( V_17 -> V_26 ) )
return false ;
if ( ! V_17 -> V_39 ( V_3 ) ) {
V_17 -> V_26 = true ;
return false ;
}
return true ;
}
bool F_24 ( struct V_2 * V_17 )
{
if ( F_28 ( V_17 ) )
return F_32 ( V_17 ) ;
return true ;
}
static void F_33 ( struct V_16 * V_17 , unsigned int V_24 )
{
unsigned int V_7 ;
V_17 -> V_15 [ V_24 ] = NULL ;
V_7 = V_24 ;
if ( V_17 -> V_31 . V_6 [ V_7 ] . V_35 & F_3 ( V_17 -> V_17 . V_10 , V_36 ) )
F_34 ( F_35 ( F_36 ( V_17 -> V_17 . V_10 , V_17 -> V_31 . V_6 [ V_7 ] . V_37 ) ) ) ;
while ( V_17 -> V_31 . V_6 [ V_7 ] . V_35 & F_3 ( V_17 -> V_17 . V_10 , V_41 ) ) {
V_7 = F_22 ( V_17 -> V_17 . V_10 , V_17 -> V_31 . V_6 [ V_7 ] . V_9 ) ;
V_17 -> V_17 . V_34 ++ ;
}
V_17 -> V_31 . V_6 [ V_7 ] . V_9 = F_3 ( V_17 -> V_17 . V_10 , V_17 -> V_33 ) ;
V_17 -> V_33 = V_24 ;
V_17 -> V_17 . V_34 ++ ;
}
static inline bool F_37 ( const struct V_16 * V_17 )
{
return V_17 -> V_55 != F_22 ( V_17 -> V_17 . V_10 , V_17 -> V_31 . V_53 -> V_47 ) ;
}
void * F_38 ( struct V_2 * V_3 , unsigned int * V_38 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
void * V_56 ;
unsigned int V_7 ;
T_3 V_57 ;
F_6 ( V_17 ) ;
if ( F_8 ( V_17 -> V_26 ) ) {
F_9 ( V_17 ) ;
return NULL ;
}
if ( ! F_37 ( V_17 ) ) {
F_19 ( L_3 ) ;
F_9 ( V_17 ) ;
return NULL ;
}
F_39 ( V_17 -> V_46 ) ;
V_57 = ( V_17 -> V_55 & ( V_17 -> V_31 . V_32 - 1 ) ) ;
V_7 = F_40 ( V_3 -> V_10 , V_17 -> V_31 . V_53 -> V_45 [ V_57 ] . V_58 ) ;
* V_38 = F_40 ( V_3 -> V_10 , V_17 -> V_31 . V_53 -> V_45 [ V_57 ] . V_38 ) ;
if ( F_8 ( V_7 >= V_17 -> V_31 . V_32 ) ) {
F_41 ( V_17 , L_4 , V_7 ) ;
return NULL ;
}
if ( F_8 ( ! V_17 -> V_15 [ V_7 ] ) ) {
F_41 ( V_17 , L_5 , V_7 ) ;
return NULL ;
}
V_56 = V_17 -> V_15 [ V_7 ] ;
F_33 ( V_17 , V_7 ) ;
V_17 -> V_55 ++ ;
if ( ! ( V_17 -> V_59 & V_60 ) ) {
F_42 ( & V_17 -> V_31 ) = F_3 ( V_3 -> V_10 , V_17 -> V_55 ) ;
F_29 ( V_17 -> V_46 ) ;
}
#ifdef F_10
V_17 -> V_29 = false ;
#endif
F_9 ( V_17 ) ;
return V_56 ;
}
void F_43 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
if ( ! ( V_17 -> V_59 & V_60 ) ) {
V_17 -> V_59 |= V_60 ;
V_17 -> V_31 . V_20 -> V_35 = F_3 ( V_3 -> V_10 , V_17 -> V_59 ) ;
}
}
unsigned F_44 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
T_3 V_55 ;
F_6 ( V_17 ) ;
if ( V_17 -> V_59 & V_60 ) {
V_17 -> V_59 &= ~ V_60 ;
V_17 -> V_31 . V_20 -> V_35 = F_3 ( V_3 -> V_10 , V_17 -> V_59 ) ;
}
F_42 ( & V_17 -> V_31 ) = F_3 ( V_3 -> V_10 , V_55 = V_17 -> V_55 ) ;
F_9 ( V_17 ) ;
return V_55 ;
}
bool F_45 ( struct V_2 * V_3 , unsigned V_55 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
F_29 ( V_17 -> V_46 ) ;
return ( T_3 ) V_55 != F_22 ( V_3 -> V_10 , V_17 -> V_31 . V_53 -> V_47 ) ;
}
bool F_46 ( struct V_2 * V_3 )
{
unsigned V_55 = F_44 ( V_3 ) ;
return ! F_45 ( V_3 , V_55 ) ;
}
bool F_47 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
T_3 V_61 ;
F_6 ( V_17 ) ;
if ( V_17 -> V_59 & V_60 ) {
V_17 -> V_59 &= ~ V_60 ;
V_17 -> V_31 . V_20 -> V_35 = F_3 ( V_3 -> V_10 , V_17 -> V_59 ) ;
}
V_61 = ( T_3 ) ( V_17 -> V_44 - V_17 -> V_55 ) * 3 / 4 ;
F_42 ( & V_17 -> V_31 ) = F_3 ( V_3 -> V_10 , V_17 -> V_55 + V_61 ) ;
F_29 ( V_17 -> V_46 ) ;
if ( F_8 ( ( T_3 ) ( F_22 ( V_3 -> V_10 , V_17 -> V_31 . V_53 -> V_47 ) - V_17 -> V_55 ) > V_61 ) ) {
F_9 ( V_17 ) ;
return false ;
}
F_9 ( V_17 ) ;
return true ;
}
void * F_48 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
unsigned int V_7 ;
void * V_62 ;
F_6 ( V_17 ) ;
for ( V_7 = 0 ; V_7 < V_17 -> V_31 . V_32 ; V_7 ++ ) {
if ( ! V_17 -> V_15 [ V_7 ] )
continue;
V_62 = V_17 -> V_15 [ V_7 ] ;
F_33 ( V_17 , V_7 ) ;
V_17 -> V_44 -- ;
V_17 -> V_31 . V_20 -> V_47 = F_3 ( V_3 -> V_10 , V_17 -> V_44 ) ;
F_9 ( V_17 ) ;
return V_62 ;
}
F_7 ( V_17 -> V_17 . V_34 != V_17 -> V_31 . V_32 ) ;
F_9 ( V_17 ) ;
return NULL ;
}
T_4 F_49 ( int V_63 , void * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
if ( ! F_37 ( V_17 ) ) {
F_19 ( L_6 , V_17 ) ;
return V_64 ;
}
if ( F_8 ( V_17 -> V_26 ) )
return V_65 ;
F_19 ( L_7 , V_17 , V_17 -> V_17 . V_66 ) ;
if ( V_17 -> V_17 . V_66 )
V_17 -> V_17 . V_66 ( & V_17 -> V_17 ) ;
return V_65 ;
}
struct V_2 * F_50 ( unsigned int V_67 ,
unsigned int V_32 ,
unsigned int V_68 ,
struct V_69 * V_10 ,
bool V_46 ,
void * V_70 ,
bool (* V_39)( struct V_2 * ) ,
void (* V_66)( struct V_2 * ) ,
const char * V_71 )
{
struct V_16 * V_17 ;
unsigned int V_7 ;
if ( V_32 & ( V_32 - 1 ) ) {
F_51 ( & V_10 -> V_72 , L_8 , V_32 ) ;
return NULL ;
}
V_17 = F_2 ( sizeof( * V_17 ) + sizeof( void * ) * V_32 , V_73 ) ;
if ( ! V_17 )
return NULL ;
F_52 ( & V_17 -> V_31 , V_32 , V_70 , V_68 ) ;
V_17 -> V_17 . V_66 = V_66 ;
V_17 -> V_17 . V_10 = V_10 ;
V_17 -> V_17 . V_71 = V_71 ;
V_17 -> V_17 . V_34 = V_32 ;
V_17 -> V_17 . V_67 = V_67 ;
V_17 -> V_39 = V_39 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_26 = false ;
V_17 -> V_55 = 0 ;
V_17 -> V_59 = 0 ;
V_17 -> V_44 = 0 ;
V_17 -> V_48 = 0 ;
F_53 ( & V_17 -> V_17 . V_74 , & V_10 -> V_75 ) ;
#ifdef F_10
V_17 -> V_76 = false ;
V_17 -> V_29 = false ;
#endif
V_17 -> V_25 = F_54 ( V_10 , V_77 ) ;
V_17 -> V_52 = F_54 ( V_10 , V_78 ) ;
if ( ! V_66 ) {
V_17 -> V_59 |= V_60 ;
V_17 -> V_31 . V_20 -> V_35 = F_3 ( V_10 , V_17 -> V_59 ) ;
}
V_17 -> V_33 = 0 ;
for ( V_7 = 0 ; V_7 < V_32 - 1 ; V_7 ++ ) {
V_17 -> V_31 . V_6 [ V_7 ] . V_9 = F_3 ( V_10 , V_7 + 1 ) ;
V_17 -> V_15 [ V_7 ] = NULL ;
}
V_17 -> V_15 [ V_7 ] = NULL ;
return & V_17 -> V_17 ;
}
void F_55 ( struct V_2 * V_17 )
{
F_56 ( & V_17 -> V_74 ) ;
F_34 ( F_5 ( V_17 ) ) ;
}
void F_57 ( struct V_69 * V_10 )
{
unsigned int V_7 ;
for ( V_7 = V_79 ; V_7 < V_80 ; V_7 ++ ) {
switch ( V_7 ) {
case V_77 :
break;
case V_78 :
break;
case V_81 :
break;
default:
F_58 ( V_10 , V_7 ) ;
}
}
}
unsigned int F_59 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
return V_17 -> V_31 . V_32 ;
}
bool F_60 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
return V_17 -> V_26 ;
}
void F_61 ( struct V_69 * V_72 )
{
struct V_2 * V_3 ;
F_62 (_vq, &dev->vqs, list) {
struct V_16 * V_17 = F_5 ( V_3 ) ;
V_17 -> V_26 = true ;
}
}
void * F_63 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
return V_17 -> V_31 . V_20 ;
}
void * F_64 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_5 ( V_3 ) ;
return V_17 -> V_31 . V_53 ;
}
