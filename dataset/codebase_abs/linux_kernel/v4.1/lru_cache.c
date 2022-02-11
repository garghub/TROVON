int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
do {
V_3 = F_2 ( & V_2 -> V_4 , 0 , V_5 ) ;
} while ( F_3 ( V_3 == V_6 ) );
return 0 == V_3 ;
#if 0
unsigned long old, new, val;
do {
old = lc->flags & LC_PARANOIA;
new = old | LC_LOCKED;
val = cmpxchg(&lc->flags, old, new);
} while (unlikely (val == (old ^ LC_PARANOIA)));
return old == val;
#endif
}
struct V_1 * F_4 ( const char * V_7 , struct V_8 * V_9 ,
unsigned V_10 ,
unsigned V_11 , T_1 V_12 , T_1 V_13 )
{
struct V_14 * V_15 = NULL ;
struct V_16 * * V_17 = NULL ;
struct V_1 * V_2 ;
struct V_16 * V_18 ;
unsigned V_19 = F_5 ( V_9 ) ;
unsigned V_20 ;
F_6 ( V_19 < V_12 ) ;
if ( V_19 < V_12 )
return NULL ;
if ( V_11 > V_21 )
return NULL ;
V_15 = F_7 ( V_11 , sizeof( struct V_14 ) , V_22 ) ;
if ( ! V_15 )
goto V_23;
V_17 = F_8 ( V_11 * sizeof( struct V_16 * ) , V_22 ) ;
if ( ! V_17 )
goto V_23;
V_2 = F_8 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
goto V_23;
F_9 ( & V_2 -> V_24 ) ;
F_9 ( & V_2 -> V_25 ) ;
F_9 ( & V_2 -> free ) ;
F_9 ( & V_2 -> V_26 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_27 = V_12 ;
V_2 -> V_28 = V_13 ;
V_2 -> V_29 = V_11 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_30 = V_9 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_31 = V_15 ;
for ( V_20 = 0 ; V_20 < V_11 ; V_20 ++ ) {
void * V_32 = F_10 ( V_9 , V_22 ) ;
if ( ! V_32 )
break;
memset ( V_32 , 0 , V_2 -> V_27 ) ;
V_18 = V_32 + V_13 ;
V_18 -> V_33 = V_20 ;
V_18 -> V_34 = V_35 ;
V_18 -> V_36 = V_35 ;
F_11 ( & V_18 -> V_37 , & V_2 -> free ) ;
V_17 [ V_20 ] = V_18 ;
}
if ( V_20 == V_11 )
return V_2 ;
for ( V_20 -- ; V_20 ; V_20 -- ) {
void * V_32 = V_17 [ V_20 ] ;
F_12 ( V_9 , V_32 - V_13 ) ;
}
F_13 ( V_2 ) ;
V_23:
F_13 ( V_17 ) ;
F_13 ( V_15 ) ;
return NULL ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_20 )
{
void * V_32 = V_2 -> V_16 [ V_20 ] ;
F_6 ( ! V_32 ) ;
if ( V_32 ) {
V_32 -= V_2 -> V_28 ;
F_12 ( V_2 -> V_30 , V_32 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
unsigned V_20 ;
if ( ! V_2 )
return;
for ( V_20 = 0 ; V_20 < V_2 -> V_29 ; V_20 ++ )
F_14 ( V_2 , V_20 ) ;
F_13 ( V_2 -> V_16 ) ;
F_13 ( V_2 -> V_31 ) ;
F_13 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
unsigned V_20 ;
F_9 ( & V_2 -> V_24 ) ;
F_9 ( & V_2 -> V_25 ) ;
F_9 ( & V_2 -> free ) ;
F_9 ( & V_2 -> V_26 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_4 = 0 ;
memset ( V_2 -> V_31 , 0 , sizeof( struct V_14 ) * V_2 -> V_29 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_29 ; V_20 ++ ) {
struct V_16 * V_18 = V_2 -> V_16 [ V_20 ] ;
void * V_32 = V_18 ;
V_32 -= V_2 -> V_28 ;
memset ( V_32 , 0 , V_2 -> V_27 ) ;
V_18 -> V_33 = V_20 ;
V_18 -> V_34 = V_35 ;
V_18 -> V_36 = V_35 ;
F_11 ( & V_18 -> V_37 , & V_2 -> free ) ;
}
}
T_1 F_17 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
F_18 ( V_46 , L_1 ,
V_2 -> V_7 , V_2 -> V_38 , V_2 -> V_29 ,
V_2 -> V_39 , V_2 -> V_40 , V_2 -> V_41 , V_2 -> V_42 , V_2 -> V_43 ) ;
return 0 ;
}
static struct V_14 * F_19 ( struct V_1 * V_2 , unsigned int V_47 )
{
return V_2 -> V_31 + ( V_47 % V_2 -> V_29 ) ;
}
static struct V_16 * F_20 ( struct V_1 * V_2 , unsigned int V_47 ,
bool V_48 )
{
struct V_16 * V_18 ;
F_21 ( ! V_2 ) ;
F_21 ( ! V_2 -> V_29 ) ;
F_22 (e, lc_hash_slot(lc, enr), colision) {
if ( V_18 -> V_36 != V_47 )
continue;
if ( V_18 -> V_36 == V_18 -> V_34 || V_48 )
return V_18 ;
break;
}
return NULL ;
}
struct V_16 * F_23 ( struct V_1 * V_2 , unsigned int V_47 )
{
return F_20 ( V_2 , V_47 , 0 ) ;
}
bool F_24 ( struct V_1 * V_2 , unsigned int V_47 )
{
struct V_16 * V_18 = F_20 ( V_2 , V_47 , 1 ) ;
return V_18 && V_18 -> V_49 ;
}
void F_25 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
F_26 () ;
F_27 ( V_2 , V_18 ) ;
F_21 ( V_18 -> V_49 ) ;
V_18 -> V_34 = V_18 -> V_36 = V_35 ;
F_28 ( & V_18 -> V_50 ) ;
F_29 ( & V_18 -> V_37 , & V_2 -> free ) ;
RETURN () ;
}
static struct V_16 * F_30 ( struct V_1 * V_2 , unsigned V_51 )
{
struct V_52 * V_53 ;
struct V_16 * V_18 ;
if ( ! F_31 ( & V_2 -> free ) )
V_53 = V_2 -> free . V_54 ;
else if ( ! F_31 ( & V_2 -> V_25 ) )
V_53 = V_2 -> V_25 . V_55 ;
else
return NULL ;
V_18 = F_32 ( V_53 , struct V_16 , V_37 ) ;
F_27 ( V_2 , V_18 ) ;
V_18 -> V_36 = V_51 ;
if ( ! F_33 ( & V_18 -> V_50 ) )
F_34 ( & V_18 -> V_50 ) ;
F_35 ( & V_18 -> V_50 , F_19 ( V_2 , V_51 ) ) ;
F_29 ( & V_18 -> V_37 , & V_2 -> V_26 ) ;
return V_18 ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( ! F_31 ( & V_2 -> free ) )
return 1 ;
if ( ! F_31 ( & V_2 -> V_25 ) )
return 1 ;
return 0 ;
}
static struct V_16 * F_37 ( struct V_1 * V_2 , unsigned int V_47 , unsigned int V_4 )
{
struct V_16 * V_18 ;
F_26 () ;
if ( V_2 -> V_4 & V_56 ) {
++ V_2 -> V_41 ;
RETURN ( NULL ) ;
}
V_18 = F_20 ( V_2 , V_47 , 1 ) ;
if ( V_18 ) {
if ( V_18 -> V_36 != V_18 -> V_34 ) {
if ( ! ( V_4 & V_57 ) )
RETURN ( NULL ) ;
++ V_18 -> V_49 ;
++ V_2 -> V_39 ;
RETURN ( V_18 ) ;
}
++ V_2 -> V_39 ;
if ( V_18 -> V_49 ++ == 0 )
V_2 -> V_38 ++ ;
F_29 ( & V_18 -> V_37 , & V_2 -> V_24 ) ;
RETURN ( V_18 ) ;
}
++ V_2 -> V_40 ;
if ( ! ( V_4 & V_58 ) )
RETURN ( NULL ) ;
F_38 ( V_59 , & V_2 -> V_4 ) ;
if ( F_39 ( V_60 , & V_2 -> V_4 ) ) {
++ V_2 -> V_42 ;
RETURN ( NULL ) ;
}
if ( ! F_36 ( V_2 ) ) {
F_40 ( V_61 , & V_2 -> V_4 ) ;
RETURN ( NULL ) ;
}
if ( V_2 -> V_44 >= V_2 -> V_10 )
RETURN ( NULL ) ;
V_18 = F_30 ( V_2 , V_47 ) ;
F_21 ( ! V_18 ) ;
F_41 ( V_61 , & V_2 -> V_4 ) ;
F_21 ( ++ V_18 -> V_49 != 1 ) ;
V_2 -> V_38 ++ ;
V_2 -> V_44 ++ ;
RETURN ( V_18 ) ;
}
struct V_16 * F_42 ( struct V_1 * V_2 , unsigned int V_47 )
{
return F_37 ( V_2 , V_47 , V_58 ) ;
}
struct V_16 * F_43 ( struct V_1 * V_2 , unsigned int V_47 )
{
return F_37 ( V_2 , V_47 , V_58 | V_57 ) ;
}
struct V_16 * F_44 ( struct V_1 * V_2 , unsigned int V_47 )
{
return F_37 ( V_2 , V_47 , 0 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_16 * V_18 , * V_62 ;
F_26 () ;
F_46 (e, tmp, &lc->to_be_changed, list) {
++ V_2 -> V_43 ;
V_18 -> V_34 = V_18 -> V_36 ;
F_29 ( & V_18 -> V_37 , & V_2 -> V_24 ) ;
}
V_2 -> V_44 = 0 ;
RETURN () ;
}
unsigned int F_47 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
F_26 () ;
F_27 ( V_2 , V_18 ) ;
F_21 ( V_18 -> V_49 == 0 ) ;
F_21 ( V_18 -> V_34 != V_18 -> V_36 ) ;
if ( -- V_18 -> V_49 == 0 ) {
F_29 ( & V_18 -> V_37 , & V_2 -> V_25 ) ;
V_2 -> V_38 -- ;
F_48 ( V_61 , & V_2 -> V_4 ) ;
}
RETURN ( V_18 -> V_49 ) ;
}
struct V_16 * F_49 ( struct V_1 * V_2 , unsigned V_20 )
{
F_21 ( V_20 >= V_2 -> V_29 ) ;
F_21 ( V_2 -> V_16 [ V_20 ] == NULL ) ;
F_21 ( V_2 -> V_16 [ V_20 ] -> V_33 != V_20 ) ;
return V_2 -> V_16 [ V_20 ] ;
}
unsigned int F_50 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
F_27 ( V_2 , V_18 ) ;
return V_18 -> V_33 ;
}
void F_51 ( struct V_1 * V_2 , unsigned int V_47 , int V_63 )
{
struct V_16 * V_18 ;
struct V_52 * V_64 ;
if ( V_63 < 0 || V_63 >= V_2 -> V_29 )
return;
V_18 = F_49 ( V_2 , V_63 ) ;
F_21 ( V_18 -> V_34 != V_18 -> V_36 ) ;
F_21 ( V_18 -> V_49 != 0 ) ;
V_18 -> V_34 = V_18 -> V_36 = V_47 ;
F_28 ( & V_18 -> V_50 ) ;
if ( V_47 == V_35 )
V_64 = & V_2 -> free ;
else {
F_35 ( & V_18 -> V_50 , F_19 ( V_2 , V_47 ) ) ;
V_64 = & V_2 -> V_25 ;
}
F_29 ( & V_18 -> V_37 , V_64 ) ;
}
void F_52 ( struct V_45 * V_46 , struct V_1 * V_2 , char * V_65 ,
void (* F_53) ( struct V_45 * , struct V_16 * ) )
{
unsigned int V_29 = V_2 -> V_29 ;
struct V_16 * V_18 ;
int V_20 ;
F_18 ( V_46 , L_2 , V_65 ) ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_18 = F_49 ( V_2 , V_20 ) ;
if ( V_18 -> V_34 != V_18 -> V_36 )
F_18 ( V_46 , L_3 ,
V_20 , V_18 -> V_34 , V_18 -> V_36 , V_18 -> V_49 ) ;
else
F_18 ( V_46 , L_4 ,
V_20 , V_18 -> V_34 , L_5 , V_18 -> V_49 ) ;
if ( F_53 )
F_53 ( V_46 , V_18 ) ;
F_54 ( V_46 , '\n' ) ;
}
}
