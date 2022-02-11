static inline bool
F_1 ( const union V_1 * V_2 , const union V_1 * V_3 ,
const union V_1 * V_4 , unsigned short V_5 )
{
switch ( V_5 ) {
case V_6 :
return ( ( V_2 -> V_7 ^ V_4 -> V_7 ) & V_3 -> V_7 ) == 0 ;
case V_8 :
return F_2 ( & V_2 -> V_9 , & V_3 -> V_9 , & V_4 -> V_9 ) == 0 ;
}
return false ;
}
static bool
F_3 ( const struct V_10 * V_11 , const struct V_12 * V_13 ,
unsigned short V_5 )
{
#define F_4 ( V_11 , T_1 , T_2 ) (!e->match.x || \
(xt_addr_cmp(&e->x, &e->y, (const union nf_inet_addr *)(z), family) \
^ e->invert.x))
#define F_5 ( V_11 , T_1 ) (!e->match.x || ((e->x == (y)) ^ e->invert.x))
return F_4 ( V_14 , V_15 , & V_11 -> V_16 . V_14 ) &&
F_4 ( V_17 , V_18 , & V_11 -> V_19 . V_17 ) &&
F_5 ( V_20 , V_11 -> V_19 . V_20 ) &&
F_5 ( V_21 , V_11 -> V_16 . V_21 ) &&
F_5 ( V_22 , V_11 -> V_19 . V_22 ) &&
F_5 ( V_23 , V_11 -> V_16 . V_23 ) ;
}
static int
F_6 ( const struct V_24 * V_25 , const struct V_26 * V_27 ,
unsigned short V_5 )
{
const struct V_12 * V_13 ;
const struct V_28 * V_29 = V_25 -> V_29 ;
int V_30 = V_27 -> V_31 & V_32 ;
int V_33 , V_34 ;
if ( V_29 == NULL )
return - 1 ;
if ( V_30 && V_27 -> V_35 != V_29 -> V_35 )
return 0 ;
for ( V_33 = V_29 -> V_35 - 1 ; V_33 >= 0 ; V_33 -- ) {
V_34 = V_30 ? V_33 - V_29 -> V_35 + 1 : 0 ;
if ( V_34 >= V_27 -> V_35 )
return 0 ;
V_13 = & V_27 -> V_36 [ V_34 ] ;
if ( F_3 ( V_29 -> V_37 [ V_33 ] , V_13 , V_5 ) ) {
if ( ! V_30 )
return 1 ;
} else if ( V_30 )
return 0 ;
}
return V_30 ? 1 : 0 ;
}
static int
F_7 ( const struct V_24 * V_25 , const struct V_26 * V_27 ,
unsigned short V_5 )
{
const struct V_12 * V_13 ;
const struct V_38 * V_39 = F_8 ( V_25 ) ;
int V_30 = V_27 -> V_31 & V_32 ;
int V_33 , V_34 ;
if ( V_39 -> V_40 == NULL )
return - 1 ;
for ( V_33 = 0 ; V_39 && V_39 -> V_40 ; V_39 = V_39 -> V_41 , V_33 ++ ) {
V_34 = V_30 ? V_33 : 0 ;
if ( V_34 >= V_27 -> V_35 )
return 0 ;
V_13 = & V_27 -> V_36 [ V_34 ] ;
if ( F_3 ( V_39 -> V_40 , V_13 , V_5 ) ) {
if ( ! V_30 )
return 1 ;
} else if ( V_30 )
return 0 ;
}
return V_30 ? V_33 == V_27 -> V_35 : 0 ;
}
static bool
F_9 ( const struct V_24 * V_25 , struct V_42 * V_43 )
{
const struct V_26 * V_27 = V_43 -> V_44 ;
int V_45 ;
if ( V_27 -> V_31 & V_46 )
V_45 = F_6 ( V_25 , V_27 , F_10 ( V_43 ) ) ;
else
V_45 = F_7 ( V_25 , V_27 , F_10 ( V_43 ) ) ;
if ( V_45 < 0 )
V_45 = V_27 -> V_31 & V_47 ? true : false ;
else if ( V_27 -> V_31 & V_47 )
V_45 = false ;
return V_45 ;
}
static int F_11 ( const struct V_48 * V_43 )
{
const struct V_26 * V_27 = V_43 -> V_44 ;
if ( ! ( V_27 -> V_31 & ( V_46 | V_49 ) ) ) {
F_12 ( L_1 ) ;
return - V_50 ;
}
if ( V_43 -> V_51 & ( ( 1 << V_52 ) |
( 1 << V_53 ) ) && V_27 -> V_31 & V_49 ) {
F_12 ( L_2 ) ;
return - V_50 ;
}
if ( V_43 -> V_51 & ( ( 1 << V_54 ) |
( 1 << V_55 ) ) && V_27 -> V_31 & V_46 ) {
F_12 ( L_3 ) ;
return - V_50 ;
}
if ( V_27 -> V_35 > V_56 ) {
F_12 ( L_4 ) ;
return - V_50 ;
}
return 0 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( V_57 , F_15 ( V_57 ) ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( V_57 , F_15 ( V_57 ) ) ;
}
