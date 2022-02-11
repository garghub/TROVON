static inline bool F_1 ( unsigned int V_1 )
{
return V_1 % 4 == 0 && ( V_1 % 100 != 0 || V_1 % 400 == 0 ) ;
}
static inline unsigned int F_2 ( struct V_2 * V_3 , T_1 time )
{
unsigned int V_4 , V_5 ;
V_4 = time % 86400 ;
V_3 -> V_6 = V_4 % 60 ;
V_5 = V_4 / 60 ;
V_3 -> V_7 = V_5 % 60 ;
V_3 -> V_8 = V_5 / 60 ;
return V_4 ;
}
static inline void F_3 ( struct V_2 * V_3 , T_1 time )
{
V_3 -> V_9 = time / 86400 ;
V_3 -> V_10 = ( 4 + V_3 -> V_9 - 1 ) % 7 + 1 ;
}
static void F_4 ( struct V_2 * V_3 , T_1 time )
{
unsigned int V_11 , V_12 , V_5 = V_3 -> V_9 ;
for ( V_12 = 0 , V_11 = V_13 ; V_14 [ V_12 ] > V_5 ;
++ V_12 , -- V_11 )
;
V_5 -= V_14 [ V_12 ] ;
if ( F_1 ( V_11 ) ) {
for ( V_12 = F_5 ( V_15 ) - 1 ;
V_12 > 0 && V_15 [ V_12 ] > V_5 ; -- V_12 )
;
V_3 -> V_16 = V_5 - V_15 [ V_12 ] + 1 ;
} else {
for ( V_12 = F_5 ( V_17 ) - 1 ;
V_12 > 0 && V_17 [ V_12 ] > V_5 ; -- V_12 )
;
V_3 -> V_16 = V_5 - V_17 [ V_12 ] + 1 ;
}
V_3 -> V_18 = V_12 + 1 ;
}
static bool
F_6 ( const struct V_19 * V_20 , struct V_21 * V_22 )
{
const struct V_23 * V_24 = V_22 -> V_25 ;
unsigned int V_26 ;
struct V_2 V_27 ;
T_2 V_28 ;
if ( V_20 -> V_29 . V_30 == 0 )
F_7 ( (struct V_19 * ) V_20 ) ;
V_28 = F_8 ( V_20 -> V_29 ) ;
V_28 = F_9 ( V_28 , V_31 ) ;
if ( V_24 -> V_32 & V_33 )
V_28 -= 60 * V_34 . V_35 ;
if ( V_28 < V_24 -> V_36 || V_28 > V_24 -> V_37 )
return false ;
V_26 = F_2 ( & V_27 , V_28 ) ;
if ( V_24 -> V_38 < V_24 -> V_39 ) {
if ( V_26 < V_24 -> V_38 ||
V_26 > V_24 -> V_39 )
return false ;
} else {
if ( V_26 < V_24 -> V_38 &&
V_26 > V_24 -> V_39 )
return false ;
}
F_3 ( & V_27 , V_28 ) ;
if ( ! ( V_24 -> V_40 & ( 1 << V_27 . V_10 ) ) )
return false ;
if ( V_24 -> V_41 != V_42 ) {
F_4 ( & V_27 , V_28 ) ;
if ( ! ( V_24 -> V_41 & ( 1 << V_27 . V_16 ) ) )
return false ;
}
return true ;
}
static int F_10 ( const struct V_43 * V_22 )
{
const struct V_23 * V_24 = V_22 -> V_25 ;
if ( V_24 -> V_38 > V_44 ||
V_24 -> V_39 > V_44 ) {
F_11 ( L_1
L_2 ) ;
return - V_45 ;
}
return 0 ;
}
static int T_3 F_12 ( void )
{
int V_46 = V_34 . V_35 ;
if ( V_46 < 0 )
F_13 (KERN_INFO KBUILD_MODNAME
L_3 ,
-minutes / 60 , -minutes % 60 ) ;
else
F_13 (KERN_INFO KBUILD_MODNAME
L_4 ,
minutes / 60 , minutes % 60 ) ;
return F_14 ( & V_47 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_47 ) ;
}
