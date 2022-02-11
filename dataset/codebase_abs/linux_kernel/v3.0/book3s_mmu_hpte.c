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
F_7 ( V_11 ) ;
F_8 ( & V_9 -> V_13 . V_14 ) ;
V_12 = F_1 ( V_11 -> V_11 . V_1 ) ;
F_9 ( & V_11 -> V_15 , & V_9 -> V_13 . V_16 [ V_12 ] ) ;
V_12 = F_3 ( V_11 -> V_11 . V_1 ) ;
F_9 ( & V_11 -> V_17 ,
& V_9 -> V_13 . V_18 [ V_12 ] ) ;
V_12 = F_4 ( V_11 -> V_11 . V_5 ) ;
F_9 ( & V_11 -> V_19 , & V_9 -> V_13 . V_20 [ V_12 ] ) ;
V_12 = F_5 ( V_11 -> V_11 . V_5 ) ;
F_9 ( & V_11 -> V_21 ,
& V_9 -> V_13 . V_22 [ V_12 ] ) ;
F_10 ( & V_9 -> V_13 . V_14 ) ;
}
static void F_11 ( struct V_23 * V_24 )
{
struct V_10 * V_11 = F_12 ( V_24 , struct V_10 , V_23 ) ;
F_13 ( V_10 , V_11 ) ;
}
static void F_14 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
F_15 ( V_11 ) ;
F_16 ( V_9 , V_11 ) ;
F_8 ( & V_9 -> V_13 . V_14 ) ;
if ( F_17 ( & V_11 -> V_15 ) ) {
F_10 ( & V_9 -> V_13 . V_14 ) ;
return;
}
F_18 ( & V_11 -> V_15 ) ;
F_18 ( & V_11 -> V_17 ) ;
F_18 ( & V_11 -> V_19 ) ;
F_18 ( & V_11 -> V_21 ) ;
if ( V_11 -> V_11 . V_25 )
F_19 ( V_11 -> V_26 ) ;
else
F_20 ( V_11 -> V_26 ) ;
F_10 ( & V_9 -> V_13 . V_14 ) ;
V_9 -> V_13 . V_27 -- ;
F_21 ( & V_11 -> V_23 , F_11 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_28 * V_29 ;
int V_30 ;
F_23 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_32 * V_33 = & V_9 -> V_13 . V_22 [ V_30 ] ;
F_24 (pte, node, list, list_vpte_long)
F_14 ( V_9 , V_11 ) ;
}
F_25 () ;
}
static void F_26 ( struct V_8 * V_9 , T_2 V_34 )
{
struct V_32 * V_33 ;
struct V_28 * V_29 ;
struct V_10 * V_11 ;
V_33 = & V_9 -> V_13 . V_16 [ F_1 ( V_34 ) ] ;
F_23 () ;
F_24 (pte, node, list, list_pte)
if ( ( V_11 -> V_11 . V_1 & ~ 0xfffUL ) == V_34 )
F_14 ( V_9 , V_11 ) ;
F_25 () ;
}
static void F_27 ( struct V_8 * V_9 , T_2 V_34 )
{
struct V_32 * V_33 ;
struct V_28 * V_29 ;
struct V_10 * V_11 ;
V_33 = & V_9 -> V_13 . V_18 [
F_3 ( V_34 ) ] ;
F_23 () ;
F_24 (pte, node, list, list_pte_long)
if ( ( V_11 -> V_11 . V_1 & 0x0ffff000UL ) == V_34 )
F_14 ( V_9 , V_11 ) ;
F_25 () ;
}
void F_28 ( struct V_8 * V_9 , T_2 V_34 , T_2 V_35 )
{
F_29 ( L_1 , V_9 , V_34 , V_35 ) ;
V_34 &= V_35 ;
switch ( V_35 ) {
case ~ 0xfffUL :
F_26 ( V_9 , V_34 ) ;
break;
case 0x0ffff000 :
F_27 ( V_9 , V_34 ) ;
break;
case 0 :
F_22 ( V_9 ) ;
break;
default:
F_30 ( 1 ) ;
break;
}
}
static void F_31 ( struct V_8 * V_9 , T_1 V_36 )
{
struct V_32 * V_33 ;
struct V_28 * V_29 ;
struct V_10 * V_11 ;
T_1 V_37 = 0xfffffffffULL ;
V_33 = & V_9 -> V_13 . V_20 [ F_4 ( V_36 ) ] ;
F_23 () ;
F_24 (pte, node, list, list_vpte)
if ( ( V_11 -> V_11 . V_5 & V_37 ) == V_36 )
F_14 ( V_9 , V_11 ) ;
F_25 () ;
}
static void F_32 ( struct V_8 * V_9 , T_1 V_36 )
{
struct V_32 * V_33 ;
struct V_28 * V_29 ;
struct V_10 * V_11 ;
T_1 V_37 = 0xffffff000ULL ;
V_33 = & V_9 -> V_13 . V_22 [
F_5 ( V_36 ) ] ;
F_23 () ;
F_24 (pte, node, list, list_vpte_long)
if ( ( V_11 -> V_11 . V_5 & V_37 ) == V_36 )
F_14 ( V_9 , V_11 ) ;
F_25 () ;
}
void F_33 ( struct V_8 * V_9 , T_1 V_36 , T_1 V_37 )
{
F_29 ( L_2 , V_9 , V_36 , V_37 ) ;
V_36 &= V_37 ;
switch( V_37 ) {
case 0xfffffffffULL :
F_31 ( V_9 , V_36 ) ;
break;
case 0xffffff000ULL :
F_32 ( V_9 , V_36 ) ;
break;
default:
F_30 ( 1 ) ;
return;
}
}
void F_34 ( struct V_8 * V_9 , T_2 V_38 , T_2 V_39 )
{
struct V_28 * V_29 ;
struct V_10 * V_11 ;
int V_30 ;
F_29 ( L_3 , V_9 , V_38 , V_39 ) ;
F_23 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_32 * V_33 = & V_9 -> V_13 . V_22 [ V_30 ] ;
F_24 (pte, node, list, list_vpte_long)
if ( ( V_11 -> V_11 . V_40 >= V_38 ) &&
( V_11 -> V_11 . V_40 < V_39 ) )
F_14 ( V_9 , V_11 ) ;
}
F_25 () ;
}
struct V_10 * F_35 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_36 ( V_10 , V_41 ) ;
V_9 -> V_13 . V_27 ++ ;
if ( V_9 -> V_13 . V_27 == V_42 )
F_22 ( V_9 ) ;
return V_11 ;
}
void F_37 ( struct V_8 * V_9 )
{
F_28 ( V_9 , 0 , 0 ) ;
}
static void F_38 ( struct V_32 * V_43 , int V_44 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ )
F_39 ( & V_43 [ V_30 ] ) ;
}
int F_40 ( struct V_8 * V_9 )
{
F_38 ( V_9 -> V_13 . V_16 ,
F_41 ( V_9 -> V_13 . V_16 ) ) ;
F_38 ( V_9 -> V_13 . V_18 ,
F_41 ( V_9 -> V_13 . V_18 ) ) ;
F_38 ( V_9 -> V_13 . V_20 ,
F_41 ( V_9 -> V_13 . V_20 ) ) ;
F_38 ( V_9 -> V_13 . V_22 ,
F_41 ( V_9 -> V_13 . V_22 ) ) ;
F_42 ( & V_9 -> V_13 . V_14 ) ;
return 0 ;
}
int F_43 ( void )
{
V_10 = F_44 ( L_4 , sizeof( struct V_10 ) ,
sizeof( struct V_10 ) , 0 , NULL ) ;
return 0 ;
}
void F_45 ( void )
{
F_46 ( V_10 ) ;
}
