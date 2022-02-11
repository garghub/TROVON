static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_1 >> V_2 , V_3 ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return F_2 ( ( V_1 & 0x0ffff000 ) >> V_2 ,
V_4 ) ;
}
static inline T_1 F_4 ( T_1 V_5 )
{
return F_2 ( V_5 & 0xfffffffffULL , V_6 ) ;
}
static inline T_1 F_5 ( T_1 V_5 )
{
return F_2 ( ( V_5 & 0xffffff000ULL ) >> 12 ,
V_7 ) ;
}
void F_6 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
T_1 V_12 ;
struct V_13 * V_14 = F_7 ( V_9 ) ;
F_8 ( V_11 ) ;
F_9 ( & V_14 -> V_15 ) ;
V_12 = F_1 ( V_11 -> V_11 . V_1 ) ;
F_10 ( & V_11 -> V_16 , & V_14 -> V_17 [ V_12 ] ) ;
V_12 = F_3 ( V_11 -> V_11 . V_1 ) ;
F_10 ( & V_11 -> V_18 ,
& V_14 -> V_19 [ V_12 ] ) ;
V_12 = F_4 ( V_11 -> V_11 . V_5 ) ;
F_10 ( & V_11 -> V_20 , & V_14 -> V_21 [ V_12 ] ) ;
V_12 = F_5 ( V_11 -> V_11 . V_5 ) ;
F_10 ( & V_11 -> V_22 ,
& V_14 -> V_23 [ V_12 ] ) ;
F_11 ( & V_14 -> V_15 ) ;
}
static void F_12 ( struct V_24 * V_25 )
{
struct V_10 * V_11 = F_13 ( V_25 , struct V_10 , V_24 ) ;
F_14 ( V_10 , V_11 ) ;
}
static void F_15 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
F_16 ( V_11 ) ;
F_17 ( V_9 , V_11 ) ;
F_9 ( & V_14 -> V_15 ) ;
if ( F_18 ( & V_11 -> V_16 ) ) {
F_11 ( & V_14 -> V_15 ) ;
return;
}
F_19 ( & V_11 -> V_16 ) ;
F_19 ( & V_11 -> V_18 ) ;
F_19 ( & V_11 -> V_20 ) ;
F_19 ( & V_11 -> V_22 ) ;
F_11 ( & V_14 -> V_15 ) ;
V_14 -> V_26 -- ;
F_20 ( & V_11 -> V_24 , F_12 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_10 * V_11 ;
struct V_27 * V_28 ;
int V_29 ;
F_22 () ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
struct V_31 * V_32 = & V_14 -> V_23 [ V_29 ] ;
F_23 (pte, node, list, list_vpte_long)
F_15 ( V_9 , V_11 ) ;
}
F_24 () ;
}
static void F_25 ( struct V_8 * V_9 , T_2 V_33 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_31 * V_32 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
V_32 = & V_14 -> V_17 [ F_1 ( V_33 ) ] ;
F_22 () ;
F_23 (pte, node, list, list_pte)
if ( ( V_11 -> V_11 . V_1 & ~ 0xfffUL ) == V_33 )
F_15 ( V_9 , V_11 ) ;
F_24 () ;
}
static void F_26 ( struct V_8 * V_9 , T_2 V_33 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_31 * V_32 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
V_32 = & V_14 -> V_19 [
F_3 ( V_33 ) ] ;
F_22 () ;
F_23 (pte, node, list, list_pte_long)
if ( ( V_11 -> V_11 . V_1 & 0x0ffff000UL ) == V_33 )
F_15 ( V_9 , V_11 ) ;
F_24 () ;
}
void F_27 ( struct V_8 * V_9 , T_2 V_33 , T_2 V_34 )
{
F_28 ( L_1 , V_9 , V_33 , V_34 ) ;
V_33 &= V_34 ;
switch ( V_34 ) {
case ~ 0xfffUL :
F_25 ( V_9 , V_33 ) ;
break;
case 0x0ffff000 :
F_26 ( V_9 , V_33 ) ;
break;
case 0 :
F_21 ( V_9 ) ;
break;
default:
F_29 ( 1 ) ;
break;
}
}
static void F_30 ( struct V_8 * V_9 , T_1 V_35 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_31 * V_32 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
T_1 V_36 = 0xfffffffffULL ;
V_32 = & V_14 -> V_21 [ F_4 ( V_35 ) ] ;
F_22 () ;
F_23 (pte, node, list, list_vpte)
if ( ( V_11 -> V_11 . V_5 & V_36 ) == V_35 )
F_15 ( V_9 , V_11 ) ;
F_24 () ;
}
static void F_31 ( struct V_8 * V_9 , T_1 V_35 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_31 * V_32 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
T_1 V_36 = 0xffffff000ULL ;
V_32 = & V_14 -> V_23 [
F_5 ( V_35 ) ] ;
F_22 () ;
F_23 (pte, node, list, list_vpte_long)
if ( ( V_11 -> V_11 . V_5 & V_36 ) == V_35 )
F_15 ( V_9 , V_11 ) ;
F_24 () ;
}
void F_32 ( struct V_8 * V_9 , T_1 V_35 , T_1 V_36 )
{
F_28 ( L_2 , V_9 , V_35 , V_36 ) ;
V_35 &= V_36 ;
switch( V_36 ) {
case 0xfffffffffULL :
F_30 ( V_9 , V_35 ) ;
break;
case 0xffffff000ULL :
F_31 ( V_9 , V_35 ) ;
break;
default:
F_29 ( 1 ) ;
return;
}
}
void F_33 ( struct V_8 * V_9 , T_2 V_37 , T_2 V_38 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
int V_29 ;
F_28 ( L_3 , V_9 , V_37 , V_38 ) ;
F_22 () ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
struct V_31 * V_32 = & V_14 -> V_23 [ V_29 ] ;
F_23 (pte, node, list, list_vpte_long)
if ( ( V_11 -> V_11 . V_39 >= V_37 ) &&
( V_11 -> V_11 . V_39 < V_38 ) )
F_15 ( V_9 , V_11 ) ;
}
F_24 () ;
}
struct V_10 * F_34 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
struct V_10 * V_11 ;
V_11 = F_35 ( V_10 , V_40 ) ;
V_14 -> V_26 ++ ;
if ( V_14 -> V_26 == V_41 )
F_21 ( V_9 ) ;
return V_11 ;
}
void F_36 ( struct V_8 * V_9 )
{
F_27 ( V_9 , 0 , 0 ) ;
}
static void F_37 ( struct V_31 * V_42 , int V_43 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_43 ; V_29 ++ )
F_38 ( & V_42 [ V_29 ] ) ;
}
int F_39 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_7 ( V_9 ) ;
F_37 ( V_14 -> V_17 ,
F_40 ( V_14 -> V_17 ) ) ;
F_37 ( V_14 -> V_19 ,
F_40 ( V_14 -> V_19 ) ) ;
F_37 ( V_14 -> V_21 ,
F_40 ( V_14 -> V_21 ) ) ;
F_37 ( V_14 -> V_23 ,
F_40 ( V_14 -> V_23 ) ) ;
F_41 ( & V_14 -> V_15 ) ;
return 0 ;
}
int F_42 ( void )
{
V_10 = F_43 ( L_4 , sizeof( struct V_10 ) ,
sizeof( struct V_10 ) , 0 , NULL ) ;
return 0 ;
}
void F_44 ( void )
{
F_45 ( V_10 ) ;
}
