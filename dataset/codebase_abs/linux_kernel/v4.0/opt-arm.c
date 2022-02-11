int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 != NULL ;
}
int F_2 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_3 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_9 < 0 )
return 0 ;
if ( V_7 -> V_8 . V_9 > 255 - sizeof( struct V_10 ) )
return 0 ;
return 1 ;
}
static void
F_4 ( struct V_4 * V_5 , int V_11 )
{
if ( V_5 -> V_2 . V_3 ) {
F_5 ( V_5 -> V_2 . V_3 , V_11 ) ;
V_5 -> V_2 . V_3 = NULL ;
}
}
static void
F_6 ( struct V_4 * V_5 , struct V_10 * V_12 )
{
unsigned long V_13 ;
struct V_6 * V_14 = & V_5 -> V_7 ;
struct V_15 * V_16 = F_7 () ;
V_12 -> V_17 = ( unsigned long ) V_5 -> V_7 . V_18 ;
V_12 -> V_19 = ~ 0UL ;
F_8 ( V_13 ) ;
if ( F_9 () ) {
F_10 ( & V_5 -> V_7 ) ;
} else {
F_11 ( V_20 , & V_5 -> V_7 ) ;
V_16 -> V_21 = V_22 ;
F_12 ( & V_5 -> V_7 , V_12 ) ;
F_11 ( V_20 , NULL ) ;
}
if ( ! V_14 -> V_8 . V_23 )
V_5 -> V_7 . V_8 . V_24 ( V_14 -> V_25 , & V_14 -> V_8 , V_12 ) ;
F_13 ( V_13 ) ;
}
int F_14 ( struct V_4 * V_5 , struct V_6 * V_26 )
{
T_1 * V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
unsigned long V_30 = sizeof( struct V_10 ) ;
if ( ! F_3 ( V_26 ) )
return - V_31 ;
V_27 = F_15 () ;
if ( ! V_27 )
return - V_32 ;
V_28 = ( unsigned long ) ( ( long ) V_27 -
( long ) V_26 -> V_18 + 8 ) & 0xfe000003 ;
if ( ( V_28 != 0 ) && ( V_28 != 0xfe000000 ) ) {
F_5 ( V_27 , 0 ) ;
return - V_33 ;
}
memcpy ( V_27 , & V_34 ,
V_35 * sizeof( T_1 ) ) ;
F_16 ( V_26 -> V_8 . V_9 < 0 ) ;
V_30 += V_26 -> V_8 . V_9 ;
F_16 ( V_30 > 255 ) ;
V_27 [ V_36 ] = F_17 ( 0xe24dd000 | V_30 ) ;
V_27 [ V_37 ] = F_17 ( 0xe28d3000 | V_30 ) ;
V_29 = ( unsigned long ) V_5 ;
V_27 [ V_38 ] = V_29 ;
V_29 = ( unsigned long ) F_6 ;
V_27 [ V_39 ] = V_29 ;
V_26 -> V_8 . V_23 = false ;
if ( F_18 ( V_26 -> V_8 . V_40 ) ) {
T_1 V_41 = F_19 (
( unsigned long ) ( & V_27 [ V_42 ] ) ,
( unsigned long ) ( V_5 -> V_7 . V_18 ) + 4 ) ;
if ( V_41 != 0 ) {
V_27 [ V_43 ] = F_17 ( 0xe89d7fff ) ;
V_27 [ V_44 ] = F_17 ( V_26 -> V_25 ) ;
V_27 [ V_42 ] = F_17 ( V_41 ) ;
V_26 -> V_8 . V_23 = true ;
}
}
F_20 ( ( unsigned long ) V_27 ,
( unsigned long ) ( & V_27 [ V_35 ] ) ) ;
V_5 -> V_2 . V_3 = V_27 ;
return 0 ;
}
void T_2 F_21 ( struct V_45 * V_46 )
{
struct V_4 * V_5 , * V_47 ;
F_22 (op, tmp, oplist, list) {
unsigned long V_3 ;
F_23 ( F_24 ( & V_5 -> V_7 ) ) ;
memcpy ( V_5 -> V_2 . V_48 , V_5 -> V_7 . V_18 ,
V_49 ) ;
V_3 = F_19 ( ( unsigned long ) V_5 -> V_7 . V_18 ,
( unsigned long ) V_5 -> V_2 . V_3 ) ;
F_16 ( V_3 == 0 ) ;
V_3 = ( F_25 (
V_5 -> V_2 . V_48 [ 0 ] ) & 0xf0000000 ) |
( V_3 & 0x0fffffff ) ;
F_26 ( V_5 -> V_7 . V_18 , V_3 ) ;
F_27 ( & V_5 -> V_50 ) ;
}
}
void F_28 ( struct V_4 * V_5 )
{
F_29 ( & V_5 -> V_7 ) ;
}
void F_30 ( struct V_45 * V_46 ,
struct V_45 * V_51 )
{
struct V_4 * V_5 , * V_47 ;
F_22 (op, tmp, oplist, list) {
F_28 ( V_5 ) ;
F_31 ( & V_5 -> V_50 , V_51 ) ;
}
}
int F_32 ( struct V_4 * V_5 ,
unsigned long V_18 )
{
return ( ( unsigned long ) V_5 -> V_7 . V_18 <= V_18 &&
( unsigned long ) V_5 -> V_7 . V_18 + V_49 > V_18 ) ;
}
void F_33 ( struct V_4 * V_5 )
{
F_4 ( V_5 , 1 ) ;
}
