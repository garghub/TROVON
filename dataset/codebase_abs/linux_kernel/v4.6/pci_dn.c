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
int V_18 ,
int V_16 , int V_10 )
{
struct V_1 * V_7 ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 ) {
F_11 ( & V_12 -> V_13 , L_1 , V_20 ) ;
return NULL ;
}
V_7 -> V_21 = V_9 -> V_21 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_16 = V_16 ;
V_7 -> V_10 = V_10 ;
#ifdef F_12
V_7 -> V_18 = V_18 ;
V_7 -> V_22 = V_23 ;
#endif
F_13 ( & V_7 -> V_24 ) ;
F_13 ( & V_7 -> V_25 ) ;
F_14 ( & V_7 -> V_25 , & V_9 -> V_24 ) ;
if ( V_12 )
V_12 -> V_13 . V_14 . V_15 = V_7 ;
return V_7 ;
}
struct V_1 * F_15 ( struct V_11 * V_12 )
{
#ifdef F_16
struct V_1 * V_9 , * V_7 ;
struct V_26 * V_27 ;
int V_28 ;
if ( ! V_12 -> V_29 )
return F_8 ( V_12 ) ;
V_7 = F_8 ( V_12 ) ;
if ( ! V_7 || ( V_7 -> V_30 & V_31 ) )
return NULL ;
V_7 -> V_30 |= V_31 ;
V_9 = F_1 ( V_12 -> V_3 ) ;
if ( ! V_9 )
return NULL ;
for ( V_28 = 0 ; V_28 < F_17 ( V_12 ) ; V_28 ++ ) {
V_7 = F_9 ( V_9 , NULL , V_28 ,
F_18 ( V_12 , V_28 ) ,
F_19 ( V_12 , V_28 ) ) ;
if ( ! V_7 ) {
F_11 ( & V_12 -> V_13 , L_2 ,
V_20 , V_28 ) ;
return NULL ;
}
F_20 ( V_7 , F_21 ( V_12 -> V_3 ) ) ;
V_27 = F_22 ( V_7 ) ;
F_23 ( ! V_27 ) ;
V_27 -> V_32 = V_12 ;
}
#endif
return F_8 ( V_12 ) ;
}
void F_24 ( struct V_11 * V_12 )
{
#ifdef F_16
struct V_1 * V_9 ;
struct V_1 * V_7 , * V_33 ;
struct V_26 * V_27 ;
int V_28 ;
if ( V_12 -> V_34 ) {
V_7 = F_8 ( V_12 ) ;
#ifdef F_12
V_7 -> V_22 = V_23 ;
#endif
return;
}
if ( ! V_12 -> V_29 )
return;
V_7 = F_8 ( V_12 ) ;
if ( ! V_7 || ! ( V_7 -> V_30 & V_31 ) )
return;
V_7 -> V_30 &= ~ V_31 ;
V_9 = F_1 ( V_12 -> V_3 ) ;
if ( ! V_9 )
return;
for ( V_28 = 0 ; V_28 < F_17 ( V_12 ) ; V_28 ++ ) {
F_25 (pdn, tmp,
&parent->child_list, list) {
if ( V_7 -> V_16 != F_18 ( V_12 , V_28 ) ||
V_7 -> V_10 != F_19 ( V_12 , V_28 ) )
continue;
V_27 = F_22 ( V_7 ) ;
if ( V_27 ) {
V_7 -> V_27 = NULL ;
F_26 ( V_27 ) ;
}
if ( ! F_27 ( & V_7 -> V_25 ) )
F_28 ( & V_7 -> V_25 ) ;
F_26 ( V_7 ) ;
}
}
#endif
}
void * F_29 ( struct V_5 * V_6 , void * V_35 )
{
struct V_36 * V_21 = V_35 ;
const T_1 * type = F_30 ( V_6 , L_3 , NULL ) ;
const T_1 * V_37 ;
struct V_5 * V_9 ;
struct V_1 * V_7 ;
V_7 = F_31 ( sizeof( * V_7 ) , V_19 ) ;
if ( V_7 == NULL )
return NULL ;
V_6 -> V_35 = V_7 ;
V_7 -> V_38 = V_6 ;
V_7 -> V_21 = V_21 ;
#ifdef F_12
V_7 -> V_22 = V_23 ;
#endif
V_37 = F_30 ( V_6 , L_4 , NULL ) ;
if ( V_37 ) {
T_2 V_39 = F_32 ( V_37 , 1 ) ;
V_7 -> V_16 = ( V_39 >> 16 ) & 0xff ;
V_7 -> V_10 = ( V_39 >> 8 ) & 0xff ;
}
V_37 = F_30 ( V_6 , L_5 , NULL ) ;
V_7 -> V_40 = V_37 ? F_32 ( V_37 , 1 ) : 0 ;
V_37 = F_30 ( V_6 , L_6 , NULL ) ;
V_7 -> V_41 = V_37 ? F_32 ( V_37 , 1 ) : 0 ;
V_37 = F_30 ( V_6 , L_7 , NULL ) ;
V_7 -> V_42 = V_37 ? F_32 ( V_37 , 1 ) : 0 ;
V_7 -> V_43 = ( type && F_32 ( type , 1 ) == 1 ) ;
F_13 ( & V_7 -> V_24 ) ;
F_13 ( & V_7 -> V_25 ) ;
V_9 = F_33 ( V_6 ) ;
V_7 -> V_9 = V_9 ? F_4 ( V_9 ) : NULL ;
if ( V_7 -> V_9 )
F_14 ( & V_7 -> V_25 , & V_7 -> V_9 -> V_24 ) ;
return NULL ;
}
void * F_34 ( struct V_5 * V_44 , T_3 V_45 ,
void * V_35 )
{
struct V_5 * V_6 , * V_46 ;
void * V_47 ;
for ( V_6 = V_44 -> V_48 ; V_6 ; V_6 = V_46 ) {
const T_1 * V_49 ;
T_2 V_50 = 0 ;
V_46 = NULL ;
V_49 = F_30 ( V_6 , L_7 , NULL ) ;
if ( V_49 )
V_50 = F_32 ( V_49 , 1 ) ;
if ( V_45 && ( ( V_47 = V_45 ( V_6 , V_35 ) ) != NULL ) )
return V_47 ;
if ( V_6 -> V_48 && ( ( V_50 >> 8 ) == V_51 ||
( V_50 >> 8 ) == V_52 ) )
V_46 = V_6 -> V_48 ;
else if ( V_6 -> V_53 )
V_46 = V_6 -> V_53 ;
if ( ! V_46 ) {
do {
V_6 = V_6 -> V_9 ;
if ( V_6 == V_44 )
return NULL ;
} while ( V_6 -> V_53 == NULL );
V_46 = V_6 -> V_53 ;
}
}
return NULL ;
}
static struct V_1 * F_35 ( struct V_1 * V_54 ,
struct V_1 * V_7 )
{
struct V_55 * V_56 = V_7 -> V_24 . V_56 ;
if ( V_56 != & V_7 -> V_24 )
return F_36 ( V_56 , struct V_1 , V_25 ) ;
while ( 1 ) {
if ( V_7 == V_54 )
return NULL ;
V_56 = V_7 -> V_25 . V_56 ;
if ( V_56 != & V_7 -> V_9 -> V_24 )
break;
V_7 = V_7 -> V_9 ;
}
return F_36 ( V_56 , struct V_1 , V_25 ) ;
}
void * F_37 ( struct V_1 * V_54 ,
void * (* F_38)( struct V_1 * , void * ) ,
void * V_35 )
{
struct V_1 * V_7 = V_54 ;
void * V_47 ;
for ( V_7 = F_35 ( V_54 , V_7 ) ; V_7 ;
V_7 = F_35 ( V_54 , V_7 ) ) {
V_47 = F_38 ( V_7 , V_35 ) ;
if ( V_47 )
return V_47 ;
}
return NULL ;
}
void F_39 ( struct V_36 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_6 ;
struct V_1 * V_7 ;
F_29 ( V_6 , V_21 ) ;
V_7 = V_6 -> V_35 ;
if ( V_7 ) {
V_7 -> V_10 = V_7 -> V_16 = - 1 ;
V_7 -> V_40 = V_7 -> V_41 = V_7 -> V_42 = 0 ;
V_7 -> V_21 = V_21 ;
V_21 -> V_15 = V_7 ;
}
F_34 ( V_6 , F_29 , V_21 ) ;
}
void T_4 F_40 ( void )
{
struct V_36 * V_21 , * V_33 ;
F_25 (phb, tmp, &hose_list, list_node)
F_39 ( V_21 ) ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
if ( V_12 -> V_13 . V_14 . V_15 )
return;
V_7 = F_8 ( V_12 ) ;
V_12 -> V_13 . V_14 . V_15 = V_7 ;
}
