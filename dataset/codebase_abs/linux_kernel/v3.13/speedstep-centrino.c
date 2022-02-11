static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & F_2 ( V_2 -> V_4 ) ;
struct V_5 * V_6 ;
for( V_6 = V_7 ; V_6 -> V_8 != NULL ; V_6 ++ )
if ( F_3 ( V_4 , V_6 -> V_8 ) &&
( V_6 -> V_9 == NULL ||
strcmp ( V_4 -> V_10 , V_6 -> V_9 ) == 0 ) )
break;
if ( V_6 -> V_8 == NULL ) {
F_4 ( L_1
L_2 V_11 L_3 ,
V_4 -> V_10 ) ;
return - V_12 ;
}
if ( V_6 -> V_13 == NULL ) {
F_4 ( L_4 ,
V_4 -> V_10 ) ;
F_4 ( L_5 ) ;
return - V_12 ;
}
F_5 ( V_14 , V_2 -> V_4 ) = V_6 ;
F_4 ( L_6 ,
V_6 -> V_9 , V_6 -> V_15 ) ;
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 )
{
return - V_16 ;
}
static int F_3 ( const struct V_3 * V_17 ,
const struct V_8 * V_18 )
{
if ( ( V_17 -> V_19 == V_18 -> V_19 ) &&
( V_17 -> V_20 == V_18 -> V_20 ) &&
( V_17 -> V_21 == V_18 -> V_21 ) )
return 1 ;
return 0 ;
}
static unsigned F_6 ( unsigned V_22 , unsigned int V_4 , int V_23 )
{
int V_24 ;
if ( ( F_5 ( V_25 , V_4 ) == & V_26 [ V_27 ] ) ||
( F_5 ( V_25 , V_4 ) == & V_26 [ V_28 ] ) ||
( F_5 ( V_25 , V_4 ) == & V_26 [ V_29 ] ) ) {
V_22 = ( V_22 >> 8 ) & 0xff ;
return V_22 * 100000 ;
}
if ( ( ! F_5 ( V_14 , V_4 ) ) ||
( ! F_5 ( V_14 , V_4 ) -> V_13 ) )
return 0 ;
V_22 &= 0xffff ;
for ( V_24 = 0 ;
F_5 ( V_14 , V_4 ) -> V_13 [ V_24 ] . V_30
!= V_31 ;
V_24 ++ ) {
if ( V_22 == F_5 ( V_14 , V_4 ) -> V_13 [ V_24 ] . V_32 )
return F_5 ( V_14 , V_4 ) ->
V_13 [ V_24 ] . V_30 ;
}
if ( V_23 )
return F_5 ( V_14 , V_4 ) -> V_13 [ V_24 - 1 ] . V_30 ;
else
return 0 ;
}
static unsigned int F_7 ( unsigned int V_4 )
{
unsigned V_33 , V_34 ;
unsigned V_35 ;
F_8 ( V_4 , V_36 , & V_33 , & V_34 ) ;
V_35 = F_6 ( V_33 , V_4 , 0 ) ;
if ( F_9 ( V_35 == 0 ) ) {
F_8 ( V_4 , V_37 , & V_33 , & V_34 ) ;
V_35 = F_6 ( V_33 , V_4 , 1 ) ;
}
return V_35 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & F_2 ( V_2 -> V_4 ) ;
unsigned V_33 , V_34 ;
int V_24 ;
if ( V_4 -> V_38 != V_39 ||
! F_11 ( V_4 , V_40 ) )
return - V_16 ;
if ( F_11 ( V_4 , V_41 ) )
V_42 . V_43 |= V_44 ;
if ( V_2 -> V_4 != 0 )
return - V_16 ;
for ( V_24 = 0 ; V_24 < V_45 ; V_24 ++ )
if ( F_3 ( V_4 , & V_26 [ V_24 ] ) )
break;
if ( V_24 != V_45 )
F_5 ( V_25 , V_2 -> V_4 ) = & V_26 [ V_24 ] ;
if ( ! F_5 ( V_25 , V_2 -> V_4 ) ) {
F_4 ( L_7
L_8
V_11 L_3 ) ;
return - V_16 ;
}
if ( F_1 ( V_2 ) )
return - V_16 ;
F_12 ( V_46 , V_33 , V_34 ) ;
if ( ! ( V_33 & V_47 ) ) {
V_33 |= V_47 ;
F_4 ( L_9 , V_33 ) ;
F_13 ( V_46 , V_33 , V_34 ) ;
F_12 ( V_46 , V_33 , V_34 ) ;
if ( ! ( V_33 & V_47 ) ) {
F_14 (KERN_INFO PFX
L_10 ) ;
return - V_16 ;
}
}
V_2 -> V_48 . V_49 = 10000 ;
return F_15 ( V_2 ,
F_5 ( V_14 , V_2 -> V_4 ) -> V_13 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_4 ;
if ( ! F_5 ( V_14 , V_4 ) )
return - V_16 ;
F_17 ( V_4 ) ;
F_5 ( V_14 , V_4 ) = NULL ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_50 )
{
unsigned int V_22 , V_51 = 0 , V_34 = 0 , V_4 = V_2 -> V_4 ;
int V_52 = 0 ;
unsigned int V_53 , V_54 ;
struct V_55 * V_13 ;
T_1 V_56 ;
if ( F_9 ( ! F_19 ( & V_56 , V_57 ) ) )
return - V_58 ;
if ( F_9 ( F_5 ( V_14 , V_4 ) == NULL ) ) {
V_52 = - V_16 ;
goto V_59;
}
V_54 = 1 ;
V_13 = & F_5 ( V_14 , V_4 ) -> V_13 [ V_50 ] ;
F_20 (j, policy->cpus) {
int V_60 ;
if ( V_2 -> V_61 == V_62 )
V_60 = F_21 ( V_2 -> V_63 ,
V_64 ) ;
else
V_60 = V_53 ;
if ( V_60 >= V_65 ) {
F_4 ( L_11 ) ;
V_52 = - V_66 ;
if ( V_54 ) {
goto V_59;
}
break;
}
V_22 = V_13 -> V_32 ;
if ( V_54 ) {
F_8 ( V_60 , V_37 , & V_51 , & V_34 ) ;
if ( V_22 == ( V_51 & 0xffff ) ) {
F_4 ( L_12
L_13 , V_51 ) ;
V_52 = 0 ;
goto V_59;
}
V_54 = 0 ;
V_51 &= ~ 0xffff ;
V_22 &= 0xffff ;
V_51 |= V_22 ;
}
F_22 ( V_60 , V_37 , V_51 , V_34 ) ;
if ( V_2 -> V_61 == V_62 )
break;
F_23 ( V_53 , V_56 ) ;
}
if ( F_9 ( V_52 ) ) {
F_20 (j, covered_cpus)
F_22 ( V_53 , V_37 , V_51 , V_34 ) ;
}
V_52 = 0 ;
V_59:
F_24 ( V_56 ) ;
return V_52 ;
}
static int T_2 F_25 ( void )
{
if ( ! F_26 ( V_67 ) )
return - V_16 ;
return F_27 ( & V_42 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_42 ) ;
}
