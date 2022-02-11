struct V_1 * F_1 ( const char * V_2 , struct V_3 * V_4 ,
unsigned V_5 , T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = NULL ;
struct V_10 * * V_11 = NULL ;
struct V_1 * V_12 ;
struct V_10 * V_13 ;
unsigned V_14 = F_2 ( V_4 ) ;
unsigned V_15 ;
F_3 ( V_14 < V_6 ) ;
if ( V_14 < V_6 )
return NULL ;
if ( V_5 > V_16 )
return NULL ;
V_9 = F_4 ( V_5 , sizeof( struct V_8 ) , V_17 ) ;
if ( ! V_9 )
goto V_18;
V_11 = F_5 ( V_5 * sizeof( struct V_10 * ) , V_17 ) ;
if ( ! V_11 )
goto V_18;
V_12 = F_5 ( sizeof( * V_12 ) , V_17 ) ;
if ( ! V_12 )
goto V_18;
F_6 ( & V_12 -> V_19 ) ;
F_6 ( & V_12 -> V_20 ) ;
F_6 ( & V_12 -> free ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_21 = V_6 ;
V_12 -> V_22 = V_7 ;
V_12 -> V_23 = V_5 ;
V_12 -> V_24 = V_25 ;
V_12 -> V_26 = V_4 ;
V_12 -> V_10 = V_11 ;
V_12 -> V_27 = V_9 ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
void * V_28 = F_7 ( V_4 , V_17 ) ;
if ( ! V_28 )
break;
memset ( V_28 , 0 , V_12 -> V_21 ) ;
V_13 = V_28 + V_7 ;
V_13 -> V_29 = V_15 ;
V_13 -> V_30 = V_25 ;
F_8 ( & V_13 -> V_31 , & V_12 -> free ) ;
V_11 [ V_15 ] = V_13 ;
}
if ( V_15 == V_5 )
return V_12 ;
for ( V_15 -- ; V_15 ; V_15 -- ) {
void * V_28 = V_11 [ V_15 ] ;
F_9 ( V_4 , V_28 - V_7 ) ;
}
F_10 ( V_12 ) ;
V_18:
F_10 ( V_11 ) ;
F_10 ( V_9 ) ;
return NULL ;
}
void F_11 ( struct V_1 * V_12 , unsigned V_15 )
{
void * V_28 = V_12 -> V_10 [ V_15 ] ;
F_3 ( ! V_28 ) ;
if ( V_28 ) {
V_28 -= V_12 -> V_22 ;
F_9 ( V_12 -> V_26 , V_28 ) ;
}
}
void F_12 ( struct V_1 * V_12 )
{
unsigned V_15 ;
if ( ! V_12 )
return;
for ( V_15 = 0 ; V_15 < V_12 -> V_23 ; V_15 ++ )
F_11 ( V_12 , V_15 ) ;
F_10 ( V_12 -> V_10 ) ;
F_10 ( V_12 -> V_27 ) ;
F_10 ( V_12 ) ;
}
void F_13 ( struct V_1 * V_12 )
{
unsigned V_15 ;
F_6 ( & V_12 -> V_19 ) ;
F_6 ( & V_12 -> V_20 ) ;
F_6 ( & V_12 -> free ) ;
V_12 -> V_32 = 0 ;
V_12 -> V_33 = 0 ;
V_12 -> V_34 = 0 ;
V_12 -> V_35 = 0 ;
V_12 -> V_36 = 0 ;
V_12 -> V_37 = 0 ;
V_12 -> V_38 = 0 ;
V_12 -> V_39 = NULL ;
V_12 -> V_24 = V_25 ;
memset ( V_12 -> V_27 , 0 , sizeof( struct V_8 ) * V_12 -> V_23 ) ;
for ( V_15 = 0 ; V_15 < V_12 -> V_23 ; V_15 ++ ) {
struct V_10 * V_13 = V_12 -> V_10 [ V_15 ] ;
void * V_28 = V_13 ;
V_28 -= V_12 -> V_22 ;
memset ( V_28 , 0 , V_12 -> V_21 ) ;
V_13 -> V_29 = V_15 ;
V_13 -> V_30 = V_25 ;
F_8 ( & V_13 -> V_31 , & V_12 -> free ) ;
}
}
T_1 F_14 ( struct V_40 * V_41 , struct V_1 * V_12 )
{
return F_15 ( V_41 , L_1
L_2 ,
V_12 -> V_2 , V_12 -> V_32 , V_12 -> V_23 ,
V_12 -> V_33 , V_12 -> V_34 , V_12 -> V_35 , V_12 -> V_36 , V_12 -> V_37 ) ;
}
static struct V_8 * F_16 ( struct V_1 * V_12 , unsigned int V_42 )
{
return V_12 -> V_27 + ( V_42 % V_12 -> V_23 ) ;
}
struct V_10 * F_17 ( struct V_1 * V_12 , unsigned int V_42 )
{
struct V_43 * V_44 ;
struct V_10 * V_13 ;
F_18 ( ! V_12 ) ;
F_18 ( ! V_12 -> V_23 ) ;
F_19 (e, n, lc_hash_slot(lc, enr), colision) {
if ( V_13 -> V_30 == V_42 )
return V_13 ;
}
return NULL ;
}
static struct V_10 * F_20 ( struct V_1 * V_12 )
{
struct V_45 * V_44 ;
struct V_10 * V_13 ;
if ( F_21 ( & V_12 -> V_20 ) )
return NULL ;
V_44 = V_12 -> V_20 . V_46 ;
V_13 = F_22 ( V_44 , struct V_10 , V_31 ) ;
F_23 ( V_12 , V_13 ) ;
F_24 ( & V_13 -> V_31 ) ;
F_25 ( & V_13 -> V_47 ) ;
return V_13 ;
}
void F_26 ( struct V_1 * V_12 , struct V_10 * V_13 )
{
F_27 () ;
F_23 ( V_12 , V_13 ) ;
F_18 ( V_13 -> V_48 ) ;
V_13 -> V_30 = V_25 ;
F_28 ( & V_13 -> V_47 ) ;
F_29 ( & V_13 -> V_31 , & V_12 -> free ) ;
RETURN () ;
}
static struct V_10 * F_30 ( struct V_1 * V_12 )
{
struct V_45 * V_44 ;
if ( F_21 ( & V_12 -> free ) )
return F_20 ( V_12 ) ;
V_44 = V_12 -> free . V_49 ;
F_24 ( V_44 ) ;
return F_22 ( V_44 , struct V_10 , V_31 ) ;
}
static int F_31 ( struct V_1 * V_12 )
{
if ( ! F_21 ( & V_12 -> free ) )
return 1 ;
if ( ! F_21 ( & V_12 -> V_20 ) )
return 1 ;
return 0 ;
}
struct V_10 * F_32 ( struct V_1 * V_12 , unsigned int V_42 )
{
struct V_10 * V_13 ;
F_27 () ;
if ( V_12 -> V_38 & V_50 ) {
++ V_12 -> V_35 ;
RETURN ( NULL ) ;
}
V_13 = F_17 ( V_12 , V_42 ) ;
if ( V_13 ) {
++ V_12 -> V_33 ;
if ( V_13 -> V_48 ++ == 0 )
V_12 -> V_32 ++ ;
F_29 ( & V_13 -> V_31 , & V_12 -> V_19 ) ;
RETURN ( V_13 ) ;
}
++ V_12 -> V_34 ;
if ( ! F_31 ( V_12 ) ) {
F_33 ( V_51 , & V_12 -> V_38 ) ;
RETURN ( NULL ) ;
}
if ( F_34 ( V_52 , & V_12 -> V_38 ) ) {
++ V_12 -> V_36 ;
RETURN ( NULL ) ;
}
V_13 = F_30 ( V_12 ) ;
F_18 ( ! V_13 ) ;
F_35 ( V_51 , & V_12 -> V_38 ) ;
F_18 ( ++ V_13 -> V_48 != 1 ) ;
V_12 -> V_32 ++ ;
V_12 -> V_39 = V_13 ;
V_12 -> V_24 = V_42 ;
RETURN ( V_13 ) ;
}
struct V_10 * F_36 ( struct V_1 * V_12 , unsigned int V_42 )
{
struct V_10 * V_13 ;
F_27 () ;
if ( V_12 -> V_38 & V_50 ) {
++ V_12 -> V_35 ;
RETURN ( NULL ) ;
}
V_13 = F_17 ( V_12 , V_42 ) ;
if ( V_13 ) {
++ V_12 -> V_33 ;
if ( V_13 -> V_48 ++ == 0 )
V_12 -> V_32 ++ ;
F_29 ( & V_13 -> V_31 , & V_12 -> V_19 ) ;
}
RETURN ( V_13 ) ;
}
void F_37 ( struct V_1 * V_12 , struct V_10 * V_13 )
{
F_27 () ;
F_18 ( V_13 != V_12 -> V_39 ) ;
F_23 ( V_12 , V_13 ) ;
++ V_12 -> V_37 ;
V_13 -> V_30 = V_12 -> V_24 ;
F_8 ( & V_13 -> V_31 , & V_12 -> V_19 ) ;
F_38 ( & V_13 -> V_47 , F_16 ( V_12 , V_12 -> V_24 ) ) ;
V_12 -> V_39 = NULL ;
V_12 -> V_24 = V_25 ;
F_35 ( V_52 , & V_12 -> V_38 ) ;
F_39 () ;
RETURN () ;
}
unsigned int F_40 ( struct V_1 * V_12 , struct V_10 * V_13 )
{
F_27 () ;
F_23 ( V_12 , V_13 ) ;
F_18 ( V_13 -> V_48 == 0 ) ;
F_18 ( V_13 == V_12 -> V_39 ) ;
if ( -- V_13 -> V_48 == 0 ) {
F_29 ( & V_13 -> V_31 , & V_12 -> V_20 ) ;
V_12 -> V_32 -- ;
F_35 ( V_51 , & V_12 -> V_38 ) ;
F_39 () ;
}
RETURN ( V_13 -> V_48 ) ;
}
struct V_10 * F_41 ( struct V_1 * V_12 , unsigned V_15 )
{
F_18 ( V_15 >= V_12 -> V_23 ) ;
F_18 ( V_12 -> V_10 [ V_15 ] == NULL ) ;
F_18 ( V_12 -> V_10 [ V_15 ] -> V_29 != V_15 ) ;
return V_12 -> V_10 [ V_15 ] ;
}
unsigned int F_42 ( struct V_1 * V_12 , struct V_10 * V_13 )
{
F_23 ( V_12 , V_13 ) ;
return V_13 -> V_29 ;
}
void F_43 ( struct V_1 * V_12 , unsigned int V_42 , int V_53 )
{
struct V_10 * V_13 ;
if ( V_53 < 0 || V_53 >= V_12 -> V_23 )
return;
V_13 = F_41 ( V_12 , V_53 ) ;
V_13 -> V_30 = V_42 ;
F_28 ( & V_13 -> V_47 ) ;
F_38 ( & V_13 -> V_47 , F_16 ( V_12 , V_42 ) ) ;
F_29 ( & V_13 -> V_31 , V_13 -> V_48 ? & V_12 -> V_19 : & V_12 -> V_20 ) ;
}
void F_44 ( struct V_40 * V_41 , struct V_1 * V_12 , char * V_54 ,
void (* F_45) ( struct V_40 * , struct V_10 * ) )
{
unsigned int V_23 = V_12 -> V_23 ;
struct V_10 * V_13 ;
int V_15 ;
F_15 ( V_41 , L_3 , V_54 ) ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_13 = F_41 ( V_12 , V_15 ) ;
if ( V_13 -> V_30 == V_25 ) {
F_15 ( V_41 , L_4 , V_15 ) ;
} else {
F_15 ( V_41 , L_5 , V_15 ,
V_13 -> V_30 , V_13 -> V_48 ) ;
F_45 ( V_41 , V_13 ) ;
}
}
}
