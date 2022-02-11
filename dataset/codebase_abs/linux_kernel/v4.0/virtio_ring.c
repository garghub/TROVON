static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
unsigned int V_7 ;
V_5 &= ~ ( V_8 | V_9 ) ;
V_6 = F_2 ( V_4 * sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_6 )
return NULL ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ )
V_6 [ V_7 ] . V_10 = F_3 ( V_3 -> V_11 , V_7 + 1 ) ;
return V_6 ;
}
static inline int F_4 ( struct V_2 * V_3 ,
struct V_12 * V_13 [] ,
unsigned int V_4 ,
unsigned int V_14 ,
unsigned int V_15 ,
void * V_16 ,
T_1 V_5 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
struct V_12 * V_19 ;
struct V_1 * V_6 ;
unsigned int V_7 , V_20 , V_21 , V_22 , V_23 ( V_24 ) ;
int V_25 ;
bool V_26 ;
F_6 ( V_18 ) ;
F_7 ( V_16 == NULL ) ;
if ( F_8 ( V_18 -> V_27 ) ) {
F_9 ( V_18 ) ;
return - V_28 ;
}
#ifdef F_10
{
T_2 V_29 = F_11 () ;
if ( V_18 -> V_30 )
F_12 ( F_13 ( F_14 ( V_29 , V_18 -> V_31 ) )
> 100 ) ;
V_18 -> V_31 = V_29 ;
V_18 -> V_30 = true ;
}
#endif
F_7 ( V_4 > V_18 -> V_32 . V_33 ) ;
F_7 ( V_4 == 0 ) ;
V_25 = V_18 -> V_34 ;
if ( V_18 -> V_26 && V_4 > 1 && V_18 -> V_18 . V_35 )
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
else
V_6 = NULL ;
if ( V_6 ) {
V_18 -> V_32 . V_6 [ V_25 ] . V_36 = F_3 ( V_3 -> V_11 , V_37 ) ;
V_18 -> V_32 . V_6 [ V_25 ] . V_38 = F_15 ( V_3 -> V_11 , F_16 ( V_6 ) ) ;
F_17 ( V_6 ) ;
V_18 -> V_32 . V_6 [ V_25 ] . V_39 = F_18 ( V_3 -> V_11 , V_4 * sizeof( struct V_1 ) ) ;
V_7 = 0 ;
V_22 = 1 ;
V_26 = true ;
} else {
V_6 = V_18 -> V_32 . V_6 ;
V_7 = V_25 ;
V_22 = V_4 ;
V_26 = false ;
}
if ( V_18 -> V_18 . V_35 < V_22 ) {
F_19 ( L_1 ,
V_22 , V_18 -> V_18 . V_35 ) ;
if ( V_14 )
V_18 -> V_40 ( & V_18 -> V_18 ) ;
F_9 ( V_18 ) ;
return - V_41 ;
}
V_18 -> V_18 . V_35 -= V_22 ;
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ ) {
for ( V_19 = V_13 [ V_20 ] ; V_19 ; V_19 = F_20 ( V_19 ) ) {
V_6 [ V_7 ] . V_36 = F_3 ( V_3 -> V_11 , V_42 ) ;
V_6 [ V_7 ] . V_38 = F_15 ( V_3 -> V_11 , F_21 ( V_19 ) ) ;
V_6 [ V_7 ] . V_39 = F_18 ( V_3 -> V_11 , V_19 -> V_43 ) ;
V_24 = V_7 ;
V_7 = F_22 ( V_3 -> V_11 , V_6 [ V_7 ] . V_10 ) ;
}
}
for (; V_20 < ( V_14 + V_15 ) ; V_20 ++ ) {
for ( V_19 = V_13 [ V_20 ] ; V_19 ; V_19 = F_20 ( V_19 ) ) {
V_6 [ V_7 ] . V_36 = F_3 ( V_3 -> V_11 , V_42 | V_44 ) ;
V_6 [ V_7 ] . V_38 = F_15 ( V_3 -> V_11 , F_21 ( V_19 ) ) ;
V_6 [ V_7 ] . V_39 = F_18 ( V_3 -> V_11 , V_19 -> V_43 ) ;
V_24 = V_7 ;
V_7 = F_22 ( V_3 -> V_11 , V_6 [ V_7 ] . V_10 ) ;
}
}
V_6 [ V_24 ] . V_36 &= F_3 ( V_3 -> V_11 , ~ V_42 ) ;
if ( V_26 )
V_18 -> V_34 = F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_6 [ V_25 ] . V_10 ) ;
else
V_18 -> V_34 = V_7 ;
V_18 -> V_16 [ V_25 ] = V_16 ;
V_21 = F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_21 -> V_45 ) & ( V_18 -> V_32 . V_33 - 1 ) ;
V_18 -> V_32 . V_21 -> V_46 [ V_21 ] = F_3 ( V_3 -> V_11 , V_25 ) ;
F_23 ( V_18 -> V_47 ) ;
V_18 -> V_32 . V_21 -> V_45 = F_3 ( V_3 -> V_11 , F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_21 -> V_45 ) + 1 ) ;
V_18 -> V_48 ++ ;
F_19 ( L_2 , V_25 , V_18 ) ;
F_9 ( V_18 ) ;
if ( F_8 ( V_18 -> V_48 == ( 1 << 16 ) - 1 ) )
F_24 ( V_3 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_3 ,
struct V_12 * V_13 [] ,
unsigned int V_14 ,
unsigned int V_15 ,
void * V_16 ,
T_1 V_5 )
{
unsigned int V_7 , V_4 = 0 ;
for ( V_7 = 0 ; V_7 < V_14 + V_15 ; V_7 ++ ) {
struct V_12 * V_19 ;
for ( V_19 = V_13 [ V_7 ] ; V_19 ; V_19 = F_20 ( V_19 ) )
V_4 ++ ;
}
return F_4 ( V_3 , V_13 , V_4 , V_14 , V_15 , V_16 , V_5 ) ;
}
int F_26 ( struct V_2 * V_18 ,
struct V_12 * V_19 , unsigned int V_33 ,
void * V_16 ,
T_1 V_5 )
{
return F_4 ( V_18 , & V_19 , V_33 , 1 , 0 , V_16 , V_5 ) ;
}
int F_27 ( struct V_2 * V_18 ,
struct V_12 * V_19 , unsigned int V_33 ,
void * V_16 ,
T_1 V_5 )
{
return F_4 ( V_18 , & V_19 , V_33 , 0 , 1 , V_16 , V_5 ) ;
}
bool F_28 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
T_3 V_49 , V_50 ;
bool V_51 ;
F_6 ( V_18 ) ;
F_29 ( V_18 -> V_47 ) ;
V_50 = F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_21 -> V_45 ) - V_18 -> V_48 ;
V_49 = F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_21 -> V_45 ) ;
V_18 -> V_48 = 0 ;
#ifdef F_10
if ( V_18 -> V_30 ) {
F_12 ( F_13 ( F_14 ( F_11 () ,
V_18 -> V_31 ) ) > 100 ) ;
}
V_18 -> V_30 = false ;
#endif
if ( V_18 -> V_52 ) {
V_51 = F_30 ( F_22 ( V_3 -> V_11 , F_31 ( & V_18 -> V_32 ) ) ,
V_49 , V_50 ) ;
} else {
V_51 = ! ( V_18 -> V_32 . V_53 -> V_36 & F_3 ( V_3 -> V_11 , V_54 ) ) ;
}
F_9 ( V_18 ) ;
return V_51 ;
}
bool F_32 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
if ( F_8 ( V_18 -> V_27 ) )
return false ;
if ( ! V_18 -> V_40 ( V_3 ) ) {
V_18 -> V_27 = true ;
return false ;
}
return true ;
}
bool F_24 ( struct V_2 * V_18 )
{
if ( F_28 ( V_18 ) )
return F_32 ( V_18 ) ;
return true ;
}
static void F_33 ( struct V_17 * V_18 , unsigned int V_25 )
{
unsigned int V_7 ;
V_18 -> V_16 [ V_25 ] = NULL ;
V_7 = V_25 ;
if ( V_18 -> V_32 . V_6 [ V_7 ] . V_36 & F_3 ( V_18 -> V_18 . V_11 , V_37 ) )
F_34 ( F_35 ( F_36 ( V_18 -> V_18 . V_11 , V_18 -> V_32 . V_6 [ V_7 ] . V_38 ) ) ) ;
while ( V_18 -> V_32 . V_6 [ V_7 ] . V_36 & F_3 ( V_18 -> V_18 . V_11 , V_42 ) ) {
V_7 = F_22 ( V_18 -> V_18 . V_11 , V_18 -> V_32 . V_6 [ V_7 ] . V_10 ) ;
V_18 -> V_18 . V_35 ++ ;
}
V_18 -> V_32 . V_6 [ V_7 ] . V_10 = F_3 ( V_18 -> V_18 . V_11 , V_18 -> V_34 ) ;
V_18 -> V_34 = V_25 ;
V_18 -> V_18 . V_35 ++ ;
}
static inline bool F_37 ( const struct V_17 * V_18 )
{
return V_18 -> V_55 != F_22 ( V_18 -> V_18 . V_11 , V_18 -> V_32 . V_53 -> V_45 ) ;
}
void * F_38 ( struct V_2 * V_3 , unsigned int * V_39 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
void * V_56 ;
unsigned int V_7 ;
T_3 V_57 ;
F_6 ( V_18 ) ;
if ( F_8 ( V_18 -> V_27 ) ) {
F_9 ( V_18 ) ;
return NULL ;
}
if ( ! F_37 ( V_18 ) ) {
F_19 ( L_3 ) ;
F_9 ( V_18 ) ;
return NULL ;
}
F_39 ( V_18 -> V_47 ) ;
V_57 = ( V_18 -> V_55 & ( V_18 -> V_32 . V_33 - 1 ) ) ;
V_7 = F_40 ( V_3 -> V_11 , V_18 -> V_32 . V_53 -> V_46 [ V_57 ] . V_58 ) ;
* V_39 = F_40 ( V_3 -> V_11 , V_18 -> V_32 . V_53 -> V_46 [ V_57 ] . V_39 ) ;
if ( F_8 ( V_7 >= V_18 -> V_32 . V_33 ) ) {
F_41 ( V_18 , L_4 , V_7 ) ;
return NULL ;
}
if ( F_8 ( ! V_18 -> V_16 [ V_7 ] ) ) {
F_41 ( V_18 , L_5 , V_7 ) ;
return NULL ;
}
V_56 = V_18 -> V_16 [ V_7 ] ;
F_33 ( V_18 , V_7 ) ;
V_18 -> V_55 ++ ;
if ( ! ( V_18 -> V_32 . V_21 -> V_36 & F_3 ( V_3 -> V_11 , V_59 ) ) ) {
F_42 ( & V_18 -> V_32 ) = F_3 ( V_3 -> V_11 , V_18 -> V_55 ) ;
F_29 ( V_18 -> V_47 ) ;
}
#ifdef F_10
V_18 -> V_30 = false ;
#endif
F_9 ( V_18 ) ;
return V_56 ;
}
void F_43 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
V_18 -> V_32 . V_21 -> V_36 |= F_3 ( V_3 -> V_11 , V_59 ) ;
}
unsigned F_44 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
T_3 V_55 ;
F_6 ( V_18 ) ;
V_18 -> V_32 . V_21 -> V_36 &= F_3 ( V_3 -> V_11 , ~ V_59 ) ;
F_42 ( & V_18 -> V_32 ) = F_3 ( V_3 -> V_11 , V_55 = V_18 -> V_55 ) ;
F_9 ( V_18 ) ;
return V_55 ;
}
bool F_45 ( struct V_2 * V_3 , unsigned V_55 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
F_29 ( V_18 -> V_47 ) ;
return ( T_3 ) V_55 != F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_53 -> V_45 ) ;
}
bool F_46 ( struct V_2 * V_3 )
{
unsigned V_55 = F_44 ( V_3 ) ;
return ! F_45 ( V_3 , V_55 ) ;
}
bool F_47 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
T_3 V_60 ;
F_6 ( V_18 ) ;
V_18 -> V_32 . V_21 -> V_36 &= F_3 ( V_3 -> V_11 , ~ V_59 ) ;
V_60 = ( T_3 ) ( F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_21 -> V_45 ) - V_18 -> V_55 ) * 3 / 4 ;
F_42 ( & V_18 -> V_32 ) = F_3 ( V_3 -> V_11 , V_18 -> V_55 + V_60 ) ;
F_29 ( V_18 -> V_47 ) ;
if ( F_8 ( ( T_3 ) ( F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_53 -> V_45 ) - V_18 -> V_55 ) > V_60 ) ) {
F_9 ( V_18 ) ;
return false ;
}
F_9 ( V_18 ) ;
return true ;
}
void * F_48 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
unsigned int V_7 ;
void * V_61 ;
F_6 ( V_18 ) ;
for ( V_7 = 0 ; V_7 < V_18 -> V_32 . V_33 ; V_7 ++ ) {
if ( ! V_18 -> V_16 [ V_7 ] )
continue;
V_61 = V_18 -> V_16 [ V_7 ] ;
F_33 ( V_18 , V_7 ) ;
V_18 -> V_32 . V_21 -> V_45 = F_3 ( V_3 -> V_11 , F_22 ( V_3 -> V_11 , V_18 -> V_32 . V_21 -> V_45 ) - 1 ) ;
F_9 ( V_18 ) ;
return V_61 ;
}
F_7 ( V_18 -> V_18 . V_35 != V_18 -> V_32 . V_33 ) ;
F_9 ( V_18 ) ;
return NULL ;
}
T_4 F_49 ( int V_62 , void * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
if ( ! F_37 ( V_18 ) ) {
F_19 ( L_6 , V_18 ) ;
return V_63 ;
}
if ( F_8 ( V_18 -> V_27 ) )
return V_64 ;
F_19 ( L_7 , V_18 , V_18 -> V_18 . V_65 ) ;
if ( V_18 -> V_18 . V_65 )
V_18 -> V_18 . V_65 ( & V_18 -> V_18 ) ;
return V_64 ;
}
struct V_2 * F_50 ( unsigned int V_66 ,
unsigned int V_33 ,
unsigned int V_67 ,
struct V_68 * V_11 ,
bool V_47 ,
void * V_69 ,
bool (* V_40)( struct V_2 * ) ,
void (* V_65)( struct V_2 * ) ,
const char * V_70 )
{
struct V_17 * V_18 ;
unsigned int V_7 ;
if ( V_33 & ( V_33 - 1 ) ) {
F_51 ( & V_11 -> V_71 , L_8 , V_33 ) ;
return NULL ;
}
V_18 = F_2 ( sizeof( * V_18 ) + sizeof( void * ) * V_33 , V_72 ) ;
if ( ! V_18 )
return NULL ;
F_52 ( & V_18 -> V_32 , V_33 , V_69 , V_67 ) ;
V_18 -> V_18 . V_65 = V_65 ;
V_18 -> V_18 . V_11 = V_11 ;
V_18 -> V_18 . V_70 = V_70 ;
V_18 -> V_18 . V_35 = V_33 ;
V_18 -> V_18 . V_66 = V_66 ;
V_18 -> V_40 = V_40 ;
V_18 -> V_47 = V_47 ;
V_18 -> V_27 = false ;
V_18 -> V_55 = 0 ;
V_18 -> V_48 = 0 ;
F_53 ( & V_18 -> V_18 . V_73 , & V_11 -> V_74 ) ;
#ifdef F_10
V_18 -> V_75 = false ;
V_18 -> V_30 = false ;
#endif
V_18 -> V_26 = F_54 ( V_11 , V_76 ) ;
V_18 -> V_52 = F_54 ( V_11 , V_77 ) ;
if ( ! V_65 )
V_18 -> V_32 . V_21 -> V_36 |= F_3 ( V_11 , V_59 ) ;
V_18 -> V_34 = 0 ;
for ( V_7 = 0 ; V_7 < V_33 - 1 ; V_7 ++ ) {
V_18 -> V_32 . V_6 [ V_7 ] . V_10 = F_3 ( V_11 , V_7 + 1 ) ;
V_18 -> V_16 [ V_7 ] = NULL ;
}
V_18 -> V_16 [ V_7 ] = NULL ;
return & V_18 -> V_18 ;
}
void F_55 ( struct V_2 * V_18 )
{
F_56 ( & V_18 -> V_73 ) ;
F_34 ( F_5 ( V_18 ) ) ;
}
void F_57 ( struct V_68 * V_11 )
{
unsigned int V_7 ;
for ( V_7 = V_78 ; V_7 < V_79 ; V_7 ++ ) {
switch ( V_7 ) {
case V_76 :
break;
case V_77 :
break;
case V_80 :
break;
default:
F_58 ( V_11 , V_7 ) ;
}
}
}
unsigned int F_59 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
return V_18 -> V_32 . V_33 ;
}
bool F_60 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
return V_18 -> V_27 ;
}
void F_61 ( struct V_68 * V_71 )
{
struct V_2 * V_3 ;
F_62 (_vq, &dev->vqs, list) {
struct V_17 * V_18 = F_5 ( V_3 ) ;
V_18 -> V_27 = true ;
}
}
void * F_63 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
return V_18 -> V_32 . V_21 ;
}
void * F_64 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_5 ( V_3 ) ;
return V_18 -> V_32 . V_53 ;
}
