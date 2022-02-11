static struct V_1 * F_1 ( struct V_2 * V_3 , int type )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 ) return NULL ;
V_4 -> type = type ;
V_4 -> V_3 = V_3 ;
F_3 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 ) ;
return V_4 ;
}
int T_1 F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 , V_9 ) ;
if ( ! V_4 ) {
F_5 ( L_1 , V_10 ) ;
return - V_11 ;
}
F_6 () ;
F_7 ( & V_4 -> V_7 , & V_12 ) ;
F_8 () ;
F_9 ( L_2 , V_3 -> V_13 ) ;
return 0 ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_11 (pe, &eeh_phb_pe, child) {
if ( ( V_4 -> type & V_9 ) && V_4 -> V_3 == V_3 )
return V_4 ;
}
return NULL ;
}
static struct V_1 * F_12 ( struct V_1 * V_4 ,
struct V_1 * V_14 )
{
struct V_15 * V_16 = V_4 -> V_6 . V_16 ;
if ( V_16 == & V_4 -> V_6 ) {
while ( 1 ) {
if ( V_4 == V_14 )
return NULL ;
V_16 = V_4 -> V_7 . V_16 ;
if ( V_16 != & V_4 -> V_17 -> V_6 )
break;
V_4 = V_4 -> V_17 ;
}
}
return F_13 ( V_16 , struct V_1 , V_7 ) ;
}
static void * F_14 ( struct V_1 * V_14 ,
T_2 V_18 , void * V_19 )
{
struct V_1 * V_4 ;
void * V_20 ;
for ( V_4 = V_14 ; V_4 ; V_4 = F_12 ( V_4 , V_14 ) ) {
V_20 = V_18 ( V_4 , V_19 ) ;
if ( V_20 ) return V_20 ;
}
return NULL ;
}
void * F_15 ( struct V_1 * V_14 ,
T_2 V_18 , void * V_19 )
{
struct V_1 * V_4 ;
struct V_21 * V_22 ;
void * V_20 ;
if ( ! V_14 ) {
F_16 ( L_3 , V_10 , V_14 ) ;
return NULL ;
}
F_6 () ;
for ( V_4 = V_14 ; V_4 ; V_4 = F_12 ( V_4 , V_14 ) ) {
F_17 (pe, edev) {
V_20 = V_18 ( V_22 , V_19 ) ;
if ( V_20 ) {
F_8 () ;
return V_20 ;
}
}
}
F_8 () ;
return NULL ;
}
static void * F_18 ( void * V_23 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_23 ;
struct V_21 * V_22 = (struct V_21 * ) V_19 ;
if ( V_4 -> type & V_9 )
return NULL ;
if ( V_22 -> V_24 &&
( V_22 -> V_24 == V_4 -> V_25 ) )
return V_4 ;
if ( V_22 -> V_24 &&
( V_22 -> V_26 == V_4 -> V_26 ) )
return V_4 ;
return NULL ;
}
static struct V_1 * F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_14 = F_10 ( V_22 -> V_3 ) ;
struct V_1 * V_4 ;
V_4 = F_14 ( V_14 , F_18 , V_22 ) ;
return V_4 ;
}
static struct V_1 * F_20 ( struct V_21 * V_22 )
{
struct V_27 * V_28 ;
struct V_21 * V_17 ;
V_28 = V_22 -> V_28 -> V_17 ;
while ( V_28 ) {
if ( ! F_21 ( V_28 ) ) return NULL ;
V_17 = F_22 ( V_28 ) ;
if ( ! V_17 ) return NULL ;
if ( V_17 -> V_4 )
return V_17 -> V_4 ;
V_28 = V_28 -> V_17 ;
}
return NULL ;
}
int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_4 , * V_17 ;
F_6 () ;
V_4 = F_19 ( V_22 ) ;
if ( V_4 && ! ( V_4 -> type & V_29 ) ) {
if ( ! V_22 -> V_24 ) {
F_8 () ;
F_5 ( L_4 ,
V_10 , V_22 -> V_26 ) ;
return - V_30 ;
}
V_4 -> type = V_31 ;
V_22 -> V_4 = V_4 ;
F_7 ( & V_22 -> V_32 , & V_4 -> V_8 ) ;
F_8 () ;
F_9 ( L_5 ,
V_22 -> V_28 -> V_33 , V_4 -> V_25 ) ;
return 0 ;
} else if ( V_4 && ( V_4 -> type & V_29 ) ) {
F_7 ( & V_22 -> V_32 , & V_4 -> V_8 ) ;
V_22 -> V_4 = V_4 ;
V_17 = V_4 ;
while ( V_17 ) {
if ( ! ( V_17 -> type & V_29 ) )
break;
V_17 -> type &= ~ V_29 ;
V_17 = V_17 -> V_17 ;
}
F_8 () ;
F_9 ( L_6 ,
V_22 -> V_28 -> V_33 , V_4 -> V_25 , V_4 -> V_17 -> V_25 ) ;
return 0 ;
}
V_4 = F_1 ( V_22 -> V_3 , V_34 ) ;
if ( ! V_4 ) {
F_8 () ;
F_5 ( L_1 , V_10 ) ;
return - V_11 ;
}
V_4 -> V_25 = V_22 -> V_24 ;
V_4 -> V_26 = V_22 -> V_26 ;
V_17 = F_20 ( V_22 ) ;
if ( ! V_17 ) {
V_17 = F_10 ( V_22 -> V_3 ) ;
if ( ! V_17 ) {
F_8 () ;
F_5 ( L_7 ,
V_10 , V_22 -> V_3 -> V_13 ) ;
V_22 -> V_4 = NULL ;
F_24 ( V_4 ) ;
return - V_30 ;
}
}
V_4 -> V_17 = V_17 ;
F_7 ( & V_4 -> V_7 , & V_17 -> V_6 ) ;
F_7 ( & V_22 -> V_32 , & V_4 -> V_8 ) ;
V_22 -> V_4 = V_4 ;
F_8 () ;
F_9 ( L_6 ,
V_22 -> V_28 -> V_33 , V_4 -> V_25 , V_4 -> V_17 -> V_25 ) ;
return 0 ;
}
int F_25 ( struct V_21 * V_22 , int V_35 )
{
struct V_1 * V_4 , * V_17 , * V_7 ;
int V_36 ;
if ( ! V_22 -> V_4 ) {
F_16 ( L_8 ,
V_10 , V_22 -> V_28 -> V_33 ) ;
return - V_30 ;
}
F_6 () ;
V_4 = V_22 -> V_4 ;
V_22 -> V_4 = NULL ;
F_26 ( & V_22 -> V_32 ) ;
while ( 1 ) {
V_17 = V_4 -> V_17 ;
if ( V_4 -> type & V_9 )
break;
if ( V_35 ) {
if ( F_27 ( & V_4 -> V_8 ) &&
F_27 ( & V_4 -> V_6 ) ) {
F_26 ( & V_4 -> V_7 ) ;
F_24 ( V_4 ) ;
} else {
break;
}
} else {
if ( F_27 ( & V_4 -> V_8 ) ) {
V_36 = 0 ;
F_11 (child, &pe->child_list, child) {
if ( ! ( V_7 -> type & V_29 ) ) {
V_36 ++ ;
break;
}
}
if ( ! V_36 )
V_4 -> type |= V_29 ;
else
break;
}
}
V_4 = V_17 ;
}
F_8 () ;
return 0 ;
}
static void * F_28 ( void * V_23 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_23 ;
int V_37 = * ( ( int * ) V_19 ) ;
struct V_21 * V_38 ;
struct V_39 * V_40 ;
V_4 -> V_37 |= V_37 ;
F_17 (pe, tmp) {
V_40 = F_29 ( V_38 ) ;
if ( V_40 )
V_40 -> V_41 = V_42 ;
}
return NULL ;
}
void F_30 ( struct V_1 * V_4 , int V_37 )
{
F_6 () ;
F_14 ( V_4 , F_28 , & V_37 ) ;
F_8 () ;
}
static void * F_31 ( void * V_23 , void * V_19 )
{
struct V_1 * V_4 = (struct V_1 * ) V_23 ;
int V_37 = * ( ( int * ) V_19 ) ;
V_4 -> V_37 &= ~ V_37 ;
V_4 -> V_43 = 0 ;
return NULL ;
}
void F_32 ( struct V_1 * V_4 , int V_37 )
{
F_6 () ;
F_14 ( V_4 , F_31 , & V_37 ) ;
F_8 () ;
}
static void * F_33 ( void * V_23 , void * V_19 )
{
int V_44 ;
T_3 V_45 ;
struct V_21 * V_22 = (struct V_21 * ) V_23 ;
struct V_27 * V_28 = F_34 ( V_22 ) ;
for ( V_44 = 4 ; V_44 < 10 ; V_44 ++ )
V_46 -> V_47 ( V_28 , V_44 * 4 , 4 , V_22 -> V_48 [ V_44 ] ) ;
V_46 -> V_47 ( V_28 , 12 * 4 , 4 , V_22 -> V_48 [ 12 ] ) ;
#define F_35 ( T_4 ) (8*((OFF)/4)+3-(OFF))
#define F_36 ( T_4 ) (((u8 *)(edev->config_space))[BYTE_SWAP(OFF)])
V_46 -> V_47 ( V_28 , V_49 , 1 ,
F_36 ( V_49 ) ) ;
V_46 -> V_47 ( V_28 , V_50 , 1 ,
F_36 ( V_50 ) ) ;
V_46 -> V_47 ( V_28 , 15 * 4 , 4 , V_22 -> V_48 [ 15 ] ) ;
V_46 -> V_51 ( V_28 , V_52 , 4 , & V_45 ) ;
if ( V_22 -> V_48 [ 1 ] & V_53 )
V_45 |= V_53 ;
else
V_45 &= ~ V_53 ;
if ( V_22 -> V_48 [ 1 ] & V_54 )
V_45 |= V_54 ;
else
V_45 &= ~ V_54 ;
V_46 -> V_47 ( V_28 , V_52 , 4 , V_45 ) ;
return NULL ;
}
void F_37 ( struct V_1 * V_4 )
{
F_15 ( V_4 , F_33 , NULL ) ;
}
struct V_55 * F_38 ( struct V_1 * V_4 )
{
struct V_55 * V_56 = NULL ;
struct V_21 * V_22 ;
struct V_39 * V_40 ;
F_6 () ;
if ( V_4 -> type & V_9 ) {
V_56 = V_4 -> V_3 -> V_56 ;
} else if ( V_4 -> type & V_31 ) {
V_22 = F_39 ( & V_4 -> V_8 , struct V_21 , V_32 ) ;
V_40 = F_29 ( V_22 ) ;
if ( V_40 )
V_56 = V_40 -> V_56 ;
}
F_8 () ;
return V_56 ;
}
