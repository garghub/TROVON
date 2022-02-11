static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_2 * V_4 ;
struct V_5 * V_6 ;
struct V_1 * V_7 ;
V_4 = V_3 ;
while ( V_4 ) {
if ( F_2 ( V_4 ) || V_4 -> V_8 )
break;
V_4 = V_4 -> V_9 ;
}
V_6 = F_3 ( V_4 ) ;
V_7 = V_6 ? F_4 ( V_6 ) : NULL ;
return V_7 ;
}
struct V_1 * F_5 ( struct V_2 * V_3 ,
int V_10 )
{
struct V_5 * V_6 = NULL ;
struct V_1 * V_9 , * V_7 ;
struct V_11 * V_12 = NULL ;
F_6 (pdev, &bus->devices, bus_list) {
if ( V_12 -> V_10 == V_10 ) {
if ( V_12 -> V_13 . V_14 . V_15 )
return V_12 -> V_13 . V_14 . V_15 ;
V_6 = F_7 ( V_12 ) ;
break;
}
}
V_7 = V_6 ? F_4 ( V_6 ) : NULL ;
if ( V_7 )
return V_7 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 )
return NULL ;
F_6 (pdn, &parent->child_list, list) {
if ( V_7 -> V_16 == V_3 -> V_17 &&
V_7 -> V_10 == V_10 )
return V_7 ;
}
return NULL ;
}
struct V_1 * F_8 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
struct V_1 * V_9 , * V_7 ;
if ( V_12 -> V_13 . V_14 . V_15 )
return V_12 -> V_13 . V_14 . V_15 ;
V_6 = F_7 ( V_12 ) ;
V_7 = V_6 ? F_4 ( V_6 ) : NULL ;
if ( V_7 )
return V_7 ;
V_9 = F_1 ( V_12 -> V_3 ) ;
if ( ! V_9 )
return NULL ;
F_6 (pdn, &parent->child_list, list) {
if ( V_7 -> V_16 == V_12 -> V_3 -> V_17 &&
V_7 -> V_10 == V_12 -> V_10 )
return V_7 ;
}
return NULL ;
}
static struct V_1 * F_9 ( struct V_1 * V_9 ,
int V_18 ,
int V_16 , int V_10 )
{
struct V_1 * V_7 ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_20 = V_9 -> V_20 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_16 = V_16 ;
V_7 -> V_10 = V_10 ;
#ifdef F_11
V_7 -> V_18 = V_18 ;
V_7 -> V_21 = V_22 ;
#endif
F_12 ( & V_7 -> V_23 ) ;
F_12 ( & V_7 -> V_24 ) ;
F_13 ( & V_7 -> V_24 , & V_9 -> V_23 ) ;
return V_7 ;
}
struct V_1 * F_14 ( struct V_11 * V_12 )
{
#ifdef F_15
struct V_1 * V_9 , * V_7 ;
int V_25 ;
if ( ! V_12 -> V_26 )
return F_8 ( V_12 ) ;
V_7 = F_8 ( V_12 ) ;
if ( ! V_7 || ( V_7 -> V_27 & V_28 ) )
return NULL ;
V_7 -> V_27 |= V_28 ;
V_9 = F_1 ( V_12 -> V_3 ) ;
if ( ! V_9 )
return NULL ;
for ( V_25 = 0 ; V_25 < F_16 ( V_12 ) ; V_25 ++ ) {
struct V_29 * T_1 V_30 ;
V_7 = F_9 ( V_9 , V_25 ,
F_17 ( V_12 , V_25 ) ,
F_18 ( V_12 , V_25 ) ) ;
if ( ! V_7 ) {
F_19 ( & V_12 -> V_13 , L_1 ,
V_31 , V_25 ) ;
return NULL ;
}
#ifdef F_20
T_1 = F_21 ( V_7 ) ;
F_22 ( ! T_1 ) ;
T_1 -> V_32 = V_12 ;
#endif
}
#endif
return F_8 ( V_12 ) ;
}
void F_23 ( struct V_11 * V_12 )
{
#ifdef F_15
struct V_1 * V_9 ;
struct V_1 * V_7 , * V_33 ;
int V_25 ;
if ( V_12 -> V_34 ) {
V_7 = F_8 ( V_12 ) ;
#ifdef F_11
V_7 -> V_21 = V_22 ;
#endif
return;
}
if ( ! V_12 -> V_26 )
return;
V_7 = F_8 ( V_12 ) ;
if ( ! V_7 || ! ( V_7 -> V_27 & V_28 ) )
return;
V_7 -> V_27 &= ~ V_28 ;
V_9 = F_1 ( V_12 -> V_3 ) ;
if ( ! V_9 )
return;
for ( V_25 = 0 ; V_25 < F_16 ( V_12 ) ; V_25 ++ ) {
struct V_29 * T_1 V_30 ;
F_24 (pdn, tmp,
&parent->child_list, list) {
if ( V_7 -> V_16 != F_17 ( V_12 , V_25 ) ||
V_7 -> V_10 != F_18 ( V_12 , V_25 ) )
continue;
#ifdef F_20
T_1 = F_25 ( V_7 ) ;
if ( T_1 ) {
V_7 -> T_1 = NULL ;
F_26 ( T_1 ) ;
}
#endif
if ( ! F_27 ( & V_7 -> V_24 ) )
F_28 ( & V_7 -> V_24 ) ;
F_26 ( V_7 ) ;
}
}
#endif
}
struct V_1 * F_29 ( struct V_35 * V_36 ,
struct V_5 * V_6 )
{
const T_2 * type = F_30 ( V_6 , L_2 , NULL ) ;
const T_2 * V_37 ;
struct V_5 * V_9 ;
struct V_1 * V_7 ;
#ifdef F_20
struct V_29 * T_1 ;
#endif
V_7 = F_10 ( sizeof( * V_7 ) , V_19 ) ;
if ( V_7 == NULL )
return NULL ;
V_6 -> V_38 = V_7 ;
V_7 -> V_20 = V_36 ;
#ifdef F_11
V_7 -> V_21 = V_22 ;
#endif
V_37 = F_30 ( V_6 , L_3 , NULL ) ;
if ( V_37 ) {
T_3 V_39 = F_31 ( V_37 , 1 ) ;
V_7 -> V_16 = ( V_39 >> 16 ) & 0xff ;
V_7 -> V_10 = ( V_39 >> 8 ) & 0xff ;
}
V_37 = F_30 ( V_6 , L_4 , NULL ) ;
V_7 -> V_40 = V_37 ? F_31 ( V_37 , 1 ) : 0 ;
V_37 = F_30 ( V_6 , L_5 , NULL ) ;
V_7 -> V_41 = V_37 ? F_31 ( V_37 , 1 ) : 0 ;
V_37 = F_30 ( V_6 , L_6 , NULL ) ;
V_7 -> V_42 = V_37 ? F_31 ( V_37 , 1 ) : 0 ;
V_7 -> V_43 = ( type && F_31 ( type , 1 ) == 1 ) ;
#ifdef F_20
T_1 = F_21 ( V_7 ) ;
if ( ! T_1 ) {
F_26 ( V_7 ) ;
return NULL ;
}
#endif
F_12 ( & V_7 -> V_23 ) ;
F_12 ( & V_7 -> V_24 ) ;
V_9 = F_32 ( V_6 ) ;
V_7 -> V_9 = V_9 ? F_4 ( V_9 ) : NULL ;
if ( V_7 -> V_9 )
F_13 ( & V_7 -> V_24 , & V_7 -> V_9 -> V_23 ) ;
return V_7 ;
}
void F_33 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 ? F_4 ( V_6 ) : NULL ;
struct V_5 * V_9 ;
#ifdef F_20
struct V_29 * T_1 = F_25 ( V_7 ) ;
if ( T_1 )
T_1 -> V_7 = NULL ;
#endif
if ( ! V_7 )
return;
F_34 ( ! F_27 ( & V_7 -> V_23 ) ) ;
F_28 ( & V_7 -> V_24 ) ;
V_9 = F_32 ( V_6 ) ;
if ( V_9 )
F_35 ( V_9 ) ;
V_6 -> V_38 = NULL ;
F_26 ( V_7 ) ;
}
void * F_36 ( struct V_5 * V_44 ,
void * (* F_37)( struct V_5 * , void * ) ,
void * V_38 )
{
struct V_5 * V_6 , * V_45 ;
void * V_46 ;
for ( V_6 = V_44 -> V_47 ; V_6 ; V_6 = V_45 ) {
const T_2 * V_48 ;
T_3 V_49 = 0 ;
V_45 = NULL ;
V_48 = F_30 ( V_6 , L_6 , NULL ) ;
if ( V_48 )
V_49 = F_31 ( V_48 , 1 ) ;
if ( F_37 ) {
V_46 = F_37 ( V_6 , V_38 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_6 -> V_47 && ( ( V_49 >> 8 ) == V_50 ||
( V_49 >> 8 ) == V_51 ) )
V_45 = V_6 -> V_47 ;
else if ( V_6 -> V_52 )
V_45 = V_6 -> V_52 ;
if ( ! V_45 ) {
do {
V_6 = V_6 -> V_9 ;
if ( V_6 == V_44 )
return NULL ;
} while ( V_6 -> V_52 == NULL );
V_45 = V_6 -> V_52 ;
}
}
return NULL ;
}
static struct V_1 * F_38 ( struct V_1 * V_53 ,
struct V_1 * V_7 )
{
struct V_54 * V_55 = V_7 -> V_23 . V_55 ;
if ( V_55 != & V_7 -> V_23 )
return F_39 ( V_55 , struct V_1 , V_24 ) ;
while ( 1 ) {
if ( V_7 == V_53 )
return NULL ;
V_55 = V_7 -> V_24 . V_55 ;
if ( V_55 != & V_7 -> V_9 -> V_23 )
break;
V_7 = V_7 -> V_9 ;
}
return F_39 ( V_55 , struct V_1 , V_24 ) ;
}
void * F_40 ( struct V_1 * V_53 ,
void * (* F_37)( struct V_1 * , void * ) ,
void * V_38 )
{
struct V_1 * V_7 = V_53 ;
void * V_46 ;
for ( V_7 = F_38 ( V_53 , V_7 ) ; V_7 ;
V_7 = F_38 ( V_53 , V_7 ) ) {
V_46 = F_37 ( V_7 , V_38 ) ;
if ( V_46 )
return V_46 ;
}
return NULL ;
}
static void * F_41 ( struct V_5 * V_6 , void * V_38 )
{
struct V_35 * V_36 = V_38 ;
struct V_1 * V_7 ;
V_7 = F_29 ( V_36 , V_6 ) ;
if ( ! V_7 )
return F_42 ( - V_56 ) ;
return NULL ;
}
void F_43 ( struct V_35 * V_20 )
{
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_1 * V_7 ;
V_7 = F_29 ( V_20 , V_6 ) ;
if ( V_7 ) {
V_7 -> V_10 = V_7 -> V_16 = - 1 ;
V_7 -> V_40 = V_7 -> V_41 = V_7 -> V_42 = 0 ;
V_7 -> V_20 = V_20 ;
V_20 -> V_15 = V_7 ;
}
F_36 ( V_6 , F_41 , V_20 ) ;
}
static int T_4 F_44 ( void )
{
struct V_35 * V_20 , * V_33 ;
F_24 (phb, tmp, &hose_list, list_node)
F_43 ( V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
if ( V_12 -> V_13 . V_14 . V_15 )
return;
V_7 = F_8 ( V_12 ) ;
V_12 -> V_13 . V_14 . V_15 = V_7 ;
}
