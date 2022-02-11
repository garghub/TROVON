static inline bool F_1 ( unsigned int V_1 )
{
return V_1 % 4 == 0 && ( V_1 % 100 != 0 || V_1 % 400 == 0 ) ;
}
static inline unsigned int F_2 ( struct V_2 * V_3 , T_1 time )
{
unsigned int V_4 , V_5 ;
V_4 = time % V_6 ;
V_3 -> V_7 = V_4 % 60 ;
V_5 = V_4 / 60 ;
V_3 -> V_8 = V_5 % 60 ;
V_3 -> V_9 = V_5 / 60 ;
return V_4 ;
}
static inline void F_3 ( struct V_2 * V_3 , T_1 time )
{
V_3 -> V_10 = time / 86400 ;
V_3 -> V_11 = ( 4 + V_3 -> V_10 - 1 ) % 7 + 1 ;
}
static void F_4 ( struct V_2 * V_3 , T_1 time )
{
unsigned int V_12 , V_13 , V_5 = V_3 -> V_10 ;
for ( V_13 = 0 , V_12 = V_14 ; V_15 [ V_13 ] > V_5 ;
++ V_13 , -- V_12 )
;
V_5 -= V_15 [ V_13 ] ;
if ( F_1 ( V_12 ) ) {
for ( V_13 = F_5 ( V_16 ) - 1 ;
V_13 > 0 && V_16 [ V_13 ] > V_5 ; -- V_13 )
;
V_3 -> V_17 = V_5 - V_16 [ V_13 ] + 1 ;
} else {
for ( V_13 = F_5 ( V_18 ) - 1 ;
V_13 > 0 && V_18 [ V_13 ] > V_5 ; -- V_13 )
;
V_3 -> V_17 = V_5 - V_18 [ V_13 ] + 1 ;
}
V_3 -> V_19 = V_13 + 1 ;
}
static bool
F_6 ( const struct V_20 * V_21 , struct V_22 * V_23 )
{
const struct V_24 * V_25 = V_23 -> V_26 ;
unsigned int V_27 ;
struct V_2 V_28 ;
T_2 V_29 ;
if ( V_21 -> V_30 == 0 )
F_7 ( (struct V_20 * ) V_21 ) ;
V_29 = F_8 ( V_21 -> V_30 ) ;
V_29 = F_9 ( V_29 , V_31 ) ;
if ( V_25 -> V_32 & V_33 )
V_29 -= 60 * V_34 . V_35 ;
if ( V_29 < V_25 -> V_36 || V_29 > V_25 -> V_37 )
return false ;
V_27 = F_2 ( & V_28 , V_29 ) ;
if ( V_25 -> V_38 < V_25 -> V_39 ) {
if ( V_27 < V_25 -> V_38 ||
V_27 > V_25 -> V_39 )
return false ;
} else {
if ( V_27 < V_25 -> V_38 &&
V_27 > V_25 -> V_39 )
return false ;
if ( ( V_25 -> V_32 & V_40 ) &&
V_27 <= V_25 -> V_39 )
V_29 -= V_6 ;
}
F_3 ( & V_28 , V_29 ) ;
if ( ! ( V_25 -> V_41 & ( 1 << V_28 . V_11 ) ) )
return false ;
if ( V_25 -> V_42 != V_43 ) {
F_4 ( & V_28 , V_29 ) ;
if ( ! ( V_25 -> V_42 & ( 1 << V_28 . V_17 ) ) )
return false ;
}
return true ;
}
static int F_10 ( const struct V_44 * V_23 )
{
const struct V_24 * V_25 = V_23 -> V_26 ;
if ( V_25 -> V_38 > V_45 ||
V_25 -> V_39 > V_45 ) {
F_11 ( L_1
L_2 ) ;
return - V_46 ;
}
if ( V_25 -> V_32 & ~ V_47 ) {
F_11 ( L_3 , V_25 -> V_32 & ~ V_47 ) ;
return - V_48 ;
}
if ( ( V_25 -> V_32 & V_40 ) &&
V_25 -> V_38 < V_25 -> V_39 )
return - V_48 ;
return 0 ;
}
static int T_3 F_12 ( void )
{
int V_49 = V_34 . V_35 ;
if ( V_49 < 0 )
F_13 (KERN_INFO KBUILD_MODNAME
L_4 ,
-minutes / 60 , -minutes % 60 ) ;
else
F_13 (KERN_INFO KBUILD_MODNAME
L_5 ,
minutes / 60 , minutes % 60 ) ;
return F_14 ( & V_50 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_50 ) ;
}
