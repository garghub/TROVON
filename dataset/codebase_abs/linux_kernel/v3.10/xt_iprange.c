static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
bool V_10 ;
if ( V_6 -> V_11 & V_12 ) {
V_10 = F_3 ( V_9 -> V_13 ) < F_3 ( V_6 -> V_14 . V_15 ) ;
V_10 |= F_3 ( V_9 -> V_13 ) > F_3 ( V_6 -> V_16 . V_15 ) ;
V_10 ^= ! ! ( V_6 -> V_11 & V_17 ) ;
if ( V_10 ) {
F_4 ( L_1 ,
& V_9 -> V_13 ,
( V_6 -> V_11 & V_17 ) ? L_2 : L_3 ,
& V_6 -> V_14 . V_15 ,
& V_6 -> V_16 . V_15 ) ;
return false ;
}
}
if ( V_6 -> V_11 & V_18 ) {
V_10 = F_3 ( V_9 -> V_19 ) < F_3 ( V_6 -> V_20 . V_15 ) ;
V_10 |= F_3 ( V_9 -> V_19 ) > F_3 ( V_6 -> V_21 . V_15 ) ;
V_10 ^= ! ! ( V_6 -> V_11 & V_22 ) ;
if ( V_10 ) {
F_4 ( L_4 ,
& V_9 -> V_19 ,
( V_6 -> V_11 & V_22 ) ? L_2 : L_3 ,
& V_6 -> V_20 . V_15 ,
& V_6 -> V_21 . V_15 ) ;
return false ;
}
}
return true ;
}
static inline int
F_5 ( const struct V_23 * V_24 , const struct V_23 * V_25 )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 ) {
if ( V_24 -> V_27 [ V_26 ] != V_25 -> V_27 [ V_26 ] )
return F_3 ( V_24 -> V_27 [ V_26 ] ) < F_3 ( V_25 -> V_27 [ V_26 ] ) ;
}
return 0 ;
}
static bool
F_6 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_28 * V_9 = F_7 ( V_2 ) ;
bool V_10 ;
if ( V_6 -> V_11 & V_12 ) {
V_10 = F_5 ( & V_9 -> V_13 , & V_6 -> V_14 . V_29 ) ;
V_10 |= F_5 ( & V_6 -> V_16 . V_29 , & V_9 -> V_13 ) ;
V_10 ^= ! ! ( V_6 -> V_11 & V_17 ) ;
if ( V_10 ) {
F_4 ( L_5 ,
& V_9 -> V_13 ,
( V_6 -> V_11 & V_17 ) ? L_2 : L_3 ,
& V_6 -> V_14 . V_29 ,
& V_6 -> V_16 . V_29 ) ;
return false ;
}
}
if ( V_6 -> V_11 & V_18 ) {
V_10 = F_5 ( & V_9 -> V_19 , & V_6 -> V_20 . V_29 ) ;
V_10 |= F_5 ( & V_6 -> V_21 . V_29 , & V_9 -> V_19 ) ;
V_10 ^= ! ! ( V_6 -> V_11 & V_22 ) ;
if ( V_10 ) {
F_4 ( L_6 ,
& V_9 -> V_19 ,
( V_6 -> V_11 & V_22 ) ? L_2 : L_3 ,
& V_6 -> V_20 . V_29 ,
& V_6 -> V_21 . V_29 ) ;
return false ;
}
}
return true ;
}
static int T_1 F_8 ( void )
{
return F_9 ( V_30 , F_10 ( V_30 ) ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( V_30 , F_10 ( V_30 ) ) ;
}
