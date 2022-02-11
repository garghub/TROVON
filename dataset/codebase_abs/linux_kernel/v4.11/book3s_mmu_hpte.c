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
static inline T_1 F_6 ( T_1 V_5 )
{
return F_2 ( ( V_5 & 0xffffffff0ULL ) >> 4 ,
V_8 ) ;
}
void F_7 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
T_1 V_13 ;
struct V_14 * V_15 = F_8 ( V_10 ) ;
F_9 ( V_12 ) ;
F_10 ( & V_15 -> V_16 ) ;
V_13 = F_1 ( V_12 -> V_12 . V_1 ) ;
F_11 ( & V_12 -> V_17 , & V_15 -> V_18 [ V_13 ] ) ;
V_13 = F_3 ( V_12 -> V_12 . V_1 ) ;
F_11 ( & V_12 -> V_19 ,
& V_15 -> V_20 [ V_13 ] ) ;
V_13 = F_4 ( V_12 -> V_12 . V_5 ) ;
F_11 ( & V_12 -> V_21 , & V_15 -> V_22 [ V_13 ] ) ;
V_13 = F_5 ( V_12 -> V_12 . V_5 ) ;
F_11 ( & V_12 -> V_23 ,
& V_15 -> V_24 [ V_13 ] ) ;
#ifdef F_12
V_13 = F_6 ( V_12 -> V_12 . V_5 ) ;
F_11 ( & V_12 -> V_25 ,
& V_15 -> V_26 [ V_13 ] ) ;
#endif
V_15 -> V_27 ++ ;
F_13 ( & V_15 -> V_16 ) ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = F_15 ( V_29 , struct V_11 , V_28 ) ;
F_16 ( V_11 , V_12 ) ;
}
static void F_17 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
F_18 ( V_12 ) ;
F_19 ( V_10 , V_12 ) ;
F_10 ( & V_15 -> V_16 ) ;
if ( F_20 ( & V_12 -> V_17 ) ) {
F_13 ( & V_15 -> V_16 ) ;
return;
}
F_21 ( & V_12 -> V_17 ) ;
F_21 ( & V_12 -> V_19 ) ;
F_21 ( & V_12 -> V_21 ) ;
F_21 ( & V_12 -> V_23 ) ;
#ifdef F_12
F_21 ( & V_12 -> V_25 ) ;
#endif
V_15 -> V_27 -- ;
F_13 ( & V_15 -> V_16 ) ;
F_22 ( & V_12 -> V_28 , F_14 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_11 * V_12 ;
int V_30 ;
F_24 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_32 * V_33 = & V_15 -> V_24 [ V_30 ] ;
F_25 (pte, list, list_vpte_long)
F_17 ( V_10 , V_12 ) ;
}
F_26 () ;
}
static void F_27 ( struct V_9 * V_10 , T_2 V_34 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
V_33 = & V_15 -> V_18 [ F_1 ( V_34 ) ] ;
F_24 () ;
F_25 (pte, list, list_pte)
if ( ( V_12 -> V_12 . V_1 & ~ 0xfffUL ) == V_34 )
F_17 ( V_10 , V_12 ) ;
F_26 () ;
}
static void F_28 ( struct V_9 * V_10 , T_2 V_34 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
V_33 = & V_15 -> V_20 [
F_3 ( V_34 ) ] ;
F_24 () ;
F_25 (pte, list, list_pte_long)
if ( ( V_12 -> V_12 . V_1 & 0x0ffff000UL ) == V_34 )
F_17 ( V_10 , V_12 ) ;
F_26 () ;
}
void F_29 ( struct V_9 * V_10 , T_2 V_34 , T_2 V_35 )
{
F_30 ( L_1 , V_10 , V_34 , V_35 ) ;
V_34 &= V_35 ;
switch ( V_35 ) {
case ~ 0xfffUL :
F_27 ( V_10 , V_34 ) ;
break;
case 0x0ffff000 :
F_28 ( V_10 , V_34 ) ;
break;
case 0 :
F_23 ( V_10 ) ;
break;
default:
F_31 ( 1 ) ;
break;
}
}
static void F_32 ( struct V_9 * V_10 , T_1 V_36 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
T_1 V_37 = 0xfffffffffULL ;
V_33 = & V_15 -> V_22 [ F_4 ( V_36 ) ] ;
F_24 () ;
F_25 (pte, list, list_vpte)
if ( ( V_12 -> V_12 . V_5 & V_37 ) == V_36 )
F_17 ( V_10 , V_12 ) ;
F_26 () ;
}
static void F_33 ( struct V_9 * V_10 , T_1 V_36 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
T_1 V_37 = 0xffffffff0ULL ;
V_33 = & V_15 -> V_26 [
F_6 ( V_36 ) ] ;
F_24 () ;
F_25 (pte, list, list_vpte_64k)
if ( ( V_12 -> V_12 . V_5 & V_37 ) == V_36 )
F_17 ( V_10 , V_12 ) ;
F_26 () ;
}
static void F_34 ( struct V_9 * V_10 , T_1 V_36 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_32 * V_33 ;
struct V_11 * V_12 ;
T_1 V_37 = 0xffffff000ULL ;
V_33 = & V_15 -> V_24 [
F_5 ( V_36 ) ] ;
F_24 () ;
F_25 (pte, list, list_vpte_long)
if ( ( V_12 -> V_12 . V_5 & V_37 ) == V_36 )
F_17 ( V_10 , V_12 ) ;
F_26 () ;
}
void F_35 ( struct V_9 * V_10 , T_1 V_36 , T_1 V_37 )
{
F_30 ( L_2 , V_10 , V_36 , V_37 ) ;
V_36 &= V_37 ;
switch( V_37 ) {
case 0xfffffffffULL :
F_32 ( V_10 , V_36 ) ;
break;
#ifdef F_12
case 0xffffffff0ULL :
F_33 ( V_10 , V_36 ) ;
break;
#endif
case 0xffffff000ULL :
F_34 ( V_10 , V_36 ) ;
break;
default:
F_31 ( 1 ) ;
return;
}
}
void F_36 ( struct V_9 * V_10 , T_2 V_38 , T_2 V_39 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_11 * V_12 ;
int V_30 ;
F_30 ( L_3 , V_10 , V_38 , V_39 ) ;
F_24 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_32 * V_33 = & V_15 -> V_24 [ V_30 ] ;
F_25 (pte, list, list_vpte_long)
if ( ( V_12 -> V_12 . V_40 >= V_38 ) &&
( V_12 -> V_12 . V_40 < V_39 ) )
F_17 ( V_10 , V_12 ) ;
}
F_26 () ;
}
struct V_11 * F_37 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_11 * V_12 ;
if ( V_15 -> V_27 == V_41 )
F_23 ( V_10 ) ;
V_12 = F_38 ( V_11 , V_42 ) ;
return V_12 ;
}
void F_39 ( struct V_11 * V_12 )
{
F_16 ( V_11 , V_12 ) ;
}
void F_40 ( struct V_9 * V_10 )
{
F_29 ( V_10 , 0 , 0 ) ;
}
static void F_41 ( struct V_32 * V_43 , int V_44 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ )
F_42 ( & V_43 [ V_30 ] ) ;
}
int F_43 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
F_41 ( V_15 -> V_18 ,
F_44 ( V_15 -> V_18 ) ) ;
F_41 ( V_15 -> V_20 ,
F_44 ( V_15 -> V_20 ) ) ;
F_41 ( V_15 -> V_22 ,
F_44 ( V_15 -> V_22 ) ) ;
F_41 ( V_15 -> V_24 ,
F_44 ( V_15 -> V_24 ) ) ;
#ifdef F_12
F_41 ( V_15 -> V_26 ,
F_44 ( V_15 -> V_26 ) ) ;
#endif
F_45 ( & V_15 -> V_16 ) ;
return 0 ;
}
int F_46 ( void )
{
V_11 = F_47 ( L_4 , sizeof( struct V_11 ) ,
sizeof( struct V_11 ) , 0 , NULL ) ;
return 0 ;
}
void F_48 ( void )
{
F_49 ( V_11 ) ;
}
