static int F_1 ( struct V_1 * V_2 ,
struct V_3 V_4 [] ,
unsigned int V_5 ,
unsigned int V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 ;
unsigned V_10 ;
int V_11 ;
V_7 &= ~ ( V_12 | V_13 ) ;
V_9 = F_2 ( ( V_5 + V_6 ) * sizeof( struct V_8 ) , V_7 ) ;
if ( ! V_9 )
return - V_14 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
V_9 [ V_11 ] . V_15 = V_16 ;
V_9 [ V_11 ] . V_17 = F_3 ( V_4 ) ;
V_9 [ V_11 ] . V_18 = V_4 -> V_19 ;
V_9 [ V_11 ] . V_20 = V_11 + 1 ;
V_4 ++ ;
}
for (; V_11 < ( V_5 + V_6 ) ; V_11 ++ ) {
V_9 [ V_11 ] . V_15 = V_16 | V_21 ;
V_9 [ V_11 ] . V_17 = F_3 ( V_4 ) ;
V_9 [ V_11 ] . V_18 = V_4 -> V_19 ;
V_9 [ V_11 ] . V_20 = V_11 + 1 ;
V_4 ++ ;
}
V_9 [ V_11 - 1 ] . V_15 &= ~ V_16 ;
V_9 [ V_11 - 1 ] . V_20 = 0 ;
V_2 -> V_2 . V_22 -- ;
V_10 = V_2 -> V_23 ;
V_2 -> V_24 . V_9 [ V_10 ] . V_15 = V_25 ;
V_2 -> V_24 . V_9 [ V_10 ] . V_17 = F_4 ( V_9 ) ;
V_2 -> V_24 . V_9 [ V_10 ] . V_18 = V_11 * sizeof( struct V_8 ) ;
V_2 -> V_23 = V_2 -> V_24 . V_9 [ V_10 ] . V_20 ;
return V_10 ;
}
int F_5 ( struct V_26 * V_27 ,
struct V_3 V_4 [] ,
unsigned int V_5 ,
unsigned int V_6 ,
void * V_28 ,
T_1 V_7 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
unsigned int V_11 , V_29 , V_30 ( V_31 ) ;
int V_10 ;
F_7 ( V_2 ) ;
F_8 ( V_28 == NULL ) ;
#ifdef F_9
{
T_2 V_32 = F_10 () ;
if ( V_2 -> V_33 )
F_11 ( F_12 ( F_13 ( V_32 , V_2 -> V_34 ) )
> 100 ) ;
V_2 -> V_34 = V_32 ;
V_2 -> V_33 = true ;
}
#endif
if ( V_2 -> V_35 && ( V_5 + V_6 ) > 1 && V_2 -> V_2 . V_22 ) {
V_10 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_14 ( V_10 >= 0 ) )
goto V_36;
}
F_8 ( V_5 + V_6 > V_2 -> V_24 . V_37 ) ;
F_8 ( V_5 + V_6 == 0 ) ;
if ( V_2 -> V_2 . V_22 < V_5 + V_6 ) {
F_15 ( L_1 ,
V_5 + V_6 , V_2 -> V_2 . V_22 ) ;
if ( V_5 )
V_2 -> V_38 ( & V_2 -> V_2 ) ;
F_16 ( V_2 ) ;
return - V_39 ;
}
V_2 -> V_2 . V_22 -= V_5 + V_6 ;
V_10 = V_2 -> V_23 ;
for ( V_11 = V_2 -> V_23 ; V_5 ; V_11 = V_2 -> V_24 . V_9 [ V_11 ] . V_20 , V_5 -- ) {
V_2 -> V_24 . V_9 [ V_11 ] . V_15 = V_16 ;
V_2 -> V_24 . V_9 [ V_11 ] . V_17 = F_3 ( V_4 ) ;
V_2 -> V_24 . V_9 [ V_11 ] . V_18 = V_4 -> V_19 ;
V_31 = V_11 ;
V_4 ++ ;
}
for (; V_6 ; V_11 = V_2 -> V_24 . V_9 [ V_11 ] . V_20 , V_6 -- ) {
V_2 -> V_24 . V_9 [ V_11 ] . V_15 = V_16 | V_21 ;
V_2 -> V_24 . V_9 [ V_11 ] . V_17 = F_3 ( V_4 ) ;
V_2 -> V_24 . V_9 [ V_11 ] . V_18 = V_4 -> V_19 ;
V_31 = V_11 ;
V_4 ++ ;
}
V_2 -> V_24 . V_9 [ V_31 ] . V_15 &= ~ V_16 ;
V_2 -> V_23 = V_11 ;
V_36:
V_2 -> V_28 [ V_10 ] = V_28 ;
V_29 = ( V_2 -> V_24 . V_29 -> V_40 & ( V_2 -> V_24 . V_37 - 1 ) ) ;
V_2 -> V_24 . V_29 -> V_41 [ V_29 ] = V_10 ;
F_17 ( V_2 ) ;
V_2 -> V_24 . V_29 -> V_40 ++ ;
V_2 -> V_42 ++ ;
if ( F_18 ( V_2 -> V_42 == ( 1 << 16 ) - 1 ) )
F_19 ( V_27 ) ;
F_15 ( L_2 , V_10 , V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
bool F_20 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
T_3 V_43 , V_44 ;
bool V_45 ;
F_7 ( V_2 ) ;
F_21 ( V_2 ) ;
V_44 = V_2 -> V_24 . V_29 -> V_40 - V_2 -> V_42 ;
V_43 = V_2 -> V_24 . V_29 -> V_40 ;
V_2 -> V_42 = 0 ;
#ifdef F_9
if ( V_2 -> V_33 ) {
F_11 ( F_12 ( F_13 ( F_10 () ,
V_2 -> V_34 ) ) > 100 ) ;
}
V_2 -> V_33 = false ;
#endif
if ( V_2 -> V_46 ) {
V_45 = F_22 ( F_23 ( & V_2 -> V_24 ) ,
V_43 , V_44 ) ;
} else {
V_45 = ! ( V_2 -> V_24 . V_47 -> V_15 & V_48 ) ;
}
F_16 ( V_2 ) ;
return V_45 ;
}
void F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
V_2 -> V_38 ( V_27 ) ;
}
void F_19 ( struct V_26 * V_2 )
{
if ( F_20 ( V_2 ) )
F_24 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned int V_11 ;
V_2 -> V_28 [ V_10 ] = NULL ;
V_11 = V_10 ;
if ( V_2 -> V_24 . V_9 [ V_11 ] . V_15 & V_25 )
F_26 ( F_27 ( V_2 -> V_24 . V_9 [ V_11 ] . V_17 ) ) ;
while ( V_2 -> V_24 . V_9 [ V_11 ] . V_15 & V_16 ) {
V_11 = V_2 -> V_24 . V_9 [ V_11 ] . V_20 ;
V_2 -> V_2 . V_22 ++ ;
}
V_2 -> V_24 . V_9 [ V_11 ] . V_20 = V_2 -> V_23 ;
V_2 -> V_23 = V_10 ;
V_2 -> V_2 . V_22 ++ ;
}
static inline bool F_28 ( const struct V_1 * V_2 )
{
return V_2 -> V_49 != V_2 -> V_24 . V_47 -> V_40 ;
}
void * F_29 ( struct V_26 * V_27 , unsigned int * V_18 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
void * V_50 ;
unsigned int V_11 ;
T_3 V_51 ;
F_7 ( V_2 ) ;
if ( F_18 ( V_2 -> V_52 ) ) {
F_16 ( V_2 ) ;
return NULL ;
}
if ( ! F_28 ( V_2 ) ) {
F_15 ( L_3 ) ;
F_16 ( V_2 ) ;
return NULL ;
}
F_30 ( V_2 ) ;
V_51 = ( V_2 -> V_49 & ( V_2 -> V_24 . V_37 - 1 ) ) ;
V_11 = V_2 -> V_24 . V_47 -> V_41 [ V_51 ] . V_53 ;
* V_18 = V_2 -> V_24 . V_47 -> V_41 [ V_51 ] . V_18 ;
if ( F_18 ( V_11 >= V_2 -> V_24 . V_37 ) ) {
F_31 ( V_2 , L_4 , V_11 ) ;
return NULL ;
}
if ( F_18 ( ! V_2 -> V_28 [ V_11 ] ) ) {
F_31 ( V_2 , L_5 , V_11 ) ;
return NULL ;
}
V_50 = V_2 -> V_28 [ V_11 ] ;
F_25 ( V_2 , V_11 ) ;
V_2 -> V_49 ++ ;
if ( ! ( V_2 -> V_24 . V_29 -> V_15 & V_54 ) ) {
F_32 ( & V_2 -> V_24 ) = V_2 -> V_49 ;
F_21 ( V_2 ) ;
}
#ifdef F_9
V_2 -> V_33 = false ;
#endif
F_16 ( V_2 ) ;
return V_50 ;
}
void F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
V_2 -> V_24 . V_29 -> V_15 |= V_54 ;
}
bool F_34 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
F_7 ( V_2 ) ;
V_2 -> V_24 . V_29 -> V_15 &= ~ V_54 ;
F_32 ( & V_2 -> V_24 ) = V_2 -> V_49 ;
F_21 ( V_2 ) ;
if ( F_18 ( F_28 ( V_2 ) ) ) {
F_16 ( V_2 ) ;
return false ;
}
F_16 ( V_2 ) ;
return true ;
}
bool F_35 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
T_3 V_55 ;
F_7 ( V_2 ) ;
V_2 -> V_24 . V_29 -> V_15 &= ~ V_54 ;
V_55 = ( T_3 ) ( V_2 -> V_24 . V_29 -> V_40 - V_2 -> V_49 ) * 3 / 4 ;
F_32 ( & V_2 -> V_24 ) = V_2 -> V_49 + V_55 ;
F_21 ( V_2 ) ;
if ( F_18 ( ( T_3 ) ( V_2 -> V_24 . V_47 -> V_40 - V_2 -> V_49 ) > V_55 ) ) {
F_16 ( V_2 ) ;
return false ;
}
F_16 ( V_2 ) ;
return true ;
}
void * F_36 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
unsigned int V_11 ;
void * V_56 ;
F_7 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_24 . V_37 ; V_11 ++ ) {
if ( ! V_2 -> V_28 [ V_11 ] )
continue;
V_56 = V_2 -> V_28 [ V_11 ] ;
F_25 ( V_2 , V_11 ) ;
V_2 -> V_24 . V_29 -> V_40 -- ;
F_16 ( V_2 ) ;
return V_56 ;
}
F_8 ( V_2 -> V_2 . V_22 != V_2 -> V_24 . V_37 ) ;
F_16 ( V_2 ) ;
return NULL ;
}
T_4 F_37 ( int V_57 , void * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
if ( ! F_28 ( V_2 ) ) {
F_15 ( L_6 , V_2 ) ;
return V_58 ;
}
if ( F_18 ( V_2 -> V_52 ) )
return V_59 ;
F_15 ( L_7 , V_2 , V_2 -> V_2 . V_60 ) ;
if ( V_2 -> V_2 . V_60 )
V_2 -> V_2 . V_60 ( & V_2 -> V_2 ) ;
return V_59 ;
}
struct V_26 * F_38 ( unsigned int V_61 ,
unsigned int V_37 ,
unsigned int V_62 ,
struct V_63 * V_64 ,
bool V_65 ,
void * V_66 ,
void (* V_38)( struct V_26 * ) ,
void (* V_60)( struct V_26 * ) ,
const char * V_67 )
{
struct V_1 * V_2 ;
unsigned int V_11 ;
if ( V_37 & ( V_37 - 1 ) ) {
F_39 ( & V_64 -> V_68 , L_8 , V_37 ) ;
return NULL ;
}
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( void * ) * V_37 , V_69 ) ;
if ( ! V_2 )
return NULL ;
F_40 ( & V_2 -> V_24 , V_37 , V_66 , V_62 ) ;
V_2 -> V_2 . V_60 = V_60 ;
V_2 -> V_2 . V_64 = V_64 ;
V_2 -> V_2 . V_67 = V_67 ;
V_2 -> V_2 . V_22 = V_37 ;
V_2 -> V_2 . V_61 = V_61 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_52 = false ;
V_2 -> V_49 = 0 ;
V_2 -> V_42 = 0 ;
F_41 ( & V_2 -> V_2 . V_70 , & V_64 -> V_71 ) ;
#ifdef F_9
V_2 -> V_72 = false ;
V_2 -> V_33 = false ;
#endif
V_2 -> V_35 = F_42 ( V_64 , V_73 ) ;
V_2 -> V_46 = F_42 ( V_64 , V_74 ) ;
if ( ! V_60 )
V_2 -> V_24 . V_29 -> V_15 |= V_54 ;
V_2 -> V_23 = 0 ;
for ( V_11 = 0 ; V_11 < V_37 - 1 ; V_11 ++ ) {
V_2 -> V_24 . V_9 [ V_11 ] . V_20 = V_11 + 1 ;
V_2 -> V_28 [ V_11 ] = NULL ;
}
V_2 -> V_28 [ V_11 ] = NULL ;
return & V_2 -> V_2 ;
}
void F_43 ( struct V_26 * V_2 )
{
F_44 ( & V_2 -> V_70 ) ;
F_26 ( F_6 ( V_2 ) ) ;
}
void F_45 ( struct V_63 * V_64 )
{
unsigned int V_11 ;
for ( V_11 = V_75 ; V_11 < V_76 ; V_11 ++ ) {
switch ( V_11 ) {
case V_73 :
break;
case V_74 :
break;
default:
F_46 ( V_11 , V_64 -> V_77 ) ;
}
}
}
unsigned int F_47 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_27 ) ;
return V_2 -> V_24 . V_37 ;
}
