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
struct V_11 * V_12 ,
int V_16 , int V_10 )
{
struct V_1 * V_7 ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 ) {
F_11 ( & V_12 -> V_13 , L_1 , V_19 ) ;
return NULL ;
}
V_7 -> V_20 = V_9 -> V_20 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_16 = V_16 ;
V_7 -> V_10 = V_10 ;
#ifdef F_12
V_7 -> V_21 = V_22 ;
#endif
F_13 ( & V_7 -> V_23 ) ;
F_13 ( & V_7 -> V_24 ) ;
F_14 ( & V_7 -> V_24 , & V_9 -> V_23 ) ;
if ( V_12 )
V_12 -> V_13 . V_14 . V_15 = V_7 ;
return V_7 ;
}
struct V_1 * F_15 ( struct V_11 * V_12 )
{
#ifdef F_16
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
for ( V_25 = 0 ; V_25 < F_17 ( V_12 ) ; V_25 ++ ) {
V_7 = F_9 ( V_9 , NULL ,
F_18 ( V_12 , V_25 ) ,
F_19 ( V_12 , V_25 ) ) ;
if ( ! V_7 ) {
F_11 ( & V_12 -> V_13 , L_2 ,
V_19 , V_25 ) ;
return NULL ;
}
}
#endif
return F_8 ( V_12 ) ;
}
void F_20 ( struct V_11 * V_12 )
{
#ifdef F_16
struct V_1 * V_9 ;
struct V_1 * V_7 , * V_29 ;
int V_25 ;
if ( V_12 -> V_30 ) {
V_7 = F_8 ( V_12 ) ;
#ifdef F_12
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
for ( V_25 = 0 ; V_25 < F_17 ( V_12 ) ; V_25 ++ ) {
F_21 (pdn, tmp,
&parent->child_list, list) {
if ( V_7 -> V_16 != F_18 ( V_12 , V_25 ) ||
V_7 -> V_10 != F_19 ( V_12 , V_25 ) )
continue;
if ( ! F_22 ( & V_7 -> V_24 ) )
F_23 ( & V_7 -> V_24 ) ;
F_24 ( V_7 ) ;
}
}
#endif
}
void * F_25 ( struct V_5 * V_6 , void * V_31 )
{
struct V_32 * V_20 = V_31 ;
const T_1 * type = F_26 ( V_6 , L_3 , NULL ) ;
const T_1 * V_33 ;
struct V_5 * V_9 ;
struct V_1 * V_7 ;
V_7 = F_27 ( sizeof( * V_7 ) , V_18 ) ;
if ( V_7 == NULL )
return NULL ;
V_6 -> V_31 = V_7 ;
V_7 -> V_34 = V_6 ;
V_7 -> V_20 = V_20 ;
#ifdef F_12
V_7 -> V_21 = V_22 ;
#endif
V_33 = F_26 ( V_6 , L_4 , NULL ) ;
if ( V_33 ) {
T_2 V_35 = F_28 ( V_33 , 1 ) ;
V_7 -> V_16 = ( V_35 >> 16 ) & 0xff ;
V_7 -> V_10 = ( V_35 >> 8 ) & 0xff ;
}
V_33 = F_26 ( V_6 , L_5 , NULL ) ;
V_7 -> V_36 = V_33 ? F_28 ( V_33 , 1 ) : 0 ;
V_33 = F_26 ( V_6 , L_6 , NULL ) ;
V_7 -> V_37 = V_33 ? F_28 ( V_33 , 1 ) : 0 ;
V_33 = F_26 ( V_6 , L_7 , NULL ) ;
V_7 -> V_38 = V_33 ? F_28 ( V_33 , 1 ) : 0 ;
V_7 -> V_39 = ( type && F_28 ( type , 1 ) == 1 ) ;
F_13 ( & V_7 -> V_23 ) ;
F_13 ( & V_7 -> V_24 ) ;
V_9 = F_29 ( V_6 ) ;
V_7 -> V_9 = V_9 ? F_4 ( V_9 ) : NULL ;
if ( V_7 -> V_9 )
F_14 ( & V_7 -> V_24 , & V_7 -> V_9 -> V_23 ) ;
return NULL ;
}
void * F_30 ( struct V_5 * V_40 , T_3 V_41 ,
void * V_31 )
{
struct V_5 * V_6 , * V_42 ;
void * V_43 ;
for ( V_6 = V_40 -> V_44 ; V_6 ; V_6 = V_42 ) {
const T_1 * V_45 ;
T_2 V_46 = 0 ;
V_42 = NULL ;
V_45 = F_26 ( V_6 , L_7 , NULL ) ;
if ( V_45 )
V_46 = F_28 ( V_45 , 1 ) ;
if ( V_41 && ( ( V_43 = V_41 ( V_6 , V_31 ) ) != NULL ) )
return V_43 ;
if ( V_6 -> V_44 && ( ( V_46 >> 8 ) == V_47 ||
( V_46 >> 8 ) == V_48 ) )
V_42 = V_6 -> V_44 ;
else if ( V_6 -> V_49 )
V_42 = V_6 -> V_49 ;
if ( ! V_42 ) {
do {
V_6 = V_6 -> V_9 ;
if ( V_6 == V_40 )
return NULL ;
} while ( V_6 -> V_49 == NULL );
V_42 = V_6 -> V_49 ;
}
}
return NULL ;
}
static struct V_1 * F_31 ( struct V_1 * V_50 ,
struct V_1 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_23 . V_52 ;
if ( V_52 != & V_7 -> V_23 )
return F_32 ( V_52 , struct V_1 , V_24 ) ;
while ( 1 ) {
if ( V_7 == V_50 )
return NULL ;
V_52 = V_7 -> V_24 . V_52 ;
if ( V_52 != & V_7 -> V_9 -> V_23 )
break;
V_7 = V_7 -> V_9 ;
}
return F_32 ( V_52 , struct V_1 , V_24 ) ;
}
void * F_33 ( struct V_1 * V_50 ,
void * (* F_34)( struct V_1 * , void * ) ,
void * V_31 )
{
struct V_1 * V_7 = V_50 ;
void * V_43 ;
for ( V_7 = F_31 ( V_50 , V_7 ) ; V_7 ;
V_7 = F_31 ( V_50 , V_7 ) ) {
V_43 = F_34 ( V_7 , V_31 ) ;
if ( V_43 )
return V_43 ;
}
return NULL ;
}
void F_35 ( struct V_32 * V_20 )
{
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_1 * V_7 ;
F_25 ( V_6 , V_20 ) ;
V_7 = V_6 -> V_31 ;
if ( V_7 ) {
V_7 -> V_10 = V_7 -> V_16 = - 1 ;
V_7 -> V_36 = V_7 -> V_37 = V_7 -> V_38 = 0 ;
V_7 -> V_20 = V_20 ;
V_20 -> V_15 = V_7 ;
}
F_30 ( V_6 , F_25 , V_20 ) ;
}
void T_4 F_36 ( void )
{
struct V_32 * V_20 , * V_29 ;
F_21 (phb, tmp, &hose_list, list_node)
F_35 ( V_20 ) ;
}
static void F_37 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
if ( V_12 -> V_13 . V_14 . V_15 )
return;
V_7 = F_8 ( V_12 ) ;
V_12 -> V_13 . V_14 . V_15 = V_7 ;
}
