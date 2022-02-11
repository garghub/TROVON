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
unsigned V_38 ;
unsigned V_33 , V_34 ;
int V_39 ;
int V_24 ;
if ( V_4 -> V_40 != V_41 ||
! F_11 ( V_4 , V_42 ) )
return - V_16 ;
if ( F_11 ( V_4 , V_43 ) )
V_44 . V_45 |= V_46 ;
if ( V_2 -> V_4 != 0 )
return - V_16 ;
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ )
if ( F_3 ( V_4 , & V_26 [ V_24 ] ) )
break;
if ( V_24 != V_47 )
F_5 ( V_25 , V_2 -> V_4 ) = & V_26 [ V_24 ] ;
if ( ! F_5 ( V_25 , V_2 -> V_4 ) ) {
F_4 ( L_7
L_8
V_11 L_3 ) ;
return - V_16 ;
}
if ( F_1 ( V_2 ) ) {
return - V_16 ;
}
F_12 ( V_48 , V_33 , V_34 ) ;
if ( ! ( V_33 & V_49 ) ) {
V_33 |= V_49 ;
F_4 ( L_9 , V_33 ) ;
F_13 ( V_48 , V_33 , V_34 ) ;
F_12 ( V_48 , V_33 , V_34 ) ;
if ( ! ( V_33 & V_49 ) ) {
F_14 (KERN_INFO PFX
L_10 ) ;
return - V_16 ;
}
}
V_38 = F_7 ( V_2 -> V_4 ) ;
V_2 -> V_50 . V_51 = 10000 ;
V_2 -> V_52 = V_38 ;
F_4 ( L_11 , V_2 -> V_52 ) ;
V_39 = F_15 ( V_2 ,
F_5 ( V_14 , V_2 -> V_4 ) -> V_13 ) ;
if ( V_39 )
return ( V_39 ) ;
F_16 (
F_5 ( V_14 , V_2 -> V_4 ) -> V_13 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_4 ;
if ( ! F_5 ( V_14 , V_4 ) )
return - V_16 ;
F_18 ( V_4 ) ;
F_5 ( V_14 , V_4 ) = NULL ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ,
F_5 ( V_14 , V_2 -> V_4 ) -> V_13 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_53 ,
unsigned int V_54 )
{
unsigned int V_55 = 0 ;
unsigned int V_22 , V_56 = 0 , V_34 = 0 , V_4 = V_2 -> V_4 ;
struct V_57 V_58 ;
int V_59 = 0 ;
unsigned int V_60 , V_61 , V_62 , V_63 ;
T_1 V_64 ;
if ( F_9 ( ! F_22 ( & V_64 , V_65 ) ) )
return - V_66 ;
if ( F_9 ( F_5 ( V_14 , V_4 ) == NULL ) ) {
V_59 = - V_16 ;
goto V_67;
}
if ( F_9 ( F_23 ( V_2 ,
F_5 ( V_14 , V_4 ) -> V_13 ,
V_53 ,
V_54 ,
& V_55 ) ) ) {
V_59 = - V_68 ;
goto V_67;
}
V_62 = 1 ;
F_24 (j, policy->cpus) {
int V_69 ;
if ( ! F_25 ( V_60 ) )
continue;
if ( V_2 -> V_70 == V_71 )
V_69 = F_26 ( V_2 -> V_72 ,
V_73 ) ;
else
V_69 = V_60 ;
if ( V_69 >= V_74 ) {
F_4 ( L_12 ) ;
V_59 = - V_75 ;
if ( V_62 ) {
goto V_67;
}
break;
}
V_22 = F_5 ( V_14 , V_4 ) -> V_13 [ V_55 ] . V_32 ;
if ( V_62 ) {
F_8 ( V_69 , V_37 , & V_56 , & V_34 ) ;
if ( V_22 == ( V_56 & 0xffff ) ) {
F_4 ( L_13
L_14 , V_56 ) ;
V_59 = 0 ;
goto V_67;
}
V_58 . V_76 = F_6 ( V_56 , V_4 , 0 ) ;
V_58 . V_77 = F_6 ( V_22 , V_4 , 0 ) ;
F_4 ( L_15 ,
V_53 , V_58 . V_76 , V_58 . V_77 , V_22 ) ;
F_24 (k, policy->cpus) {
if ( ! F_25 ( V_61 ) )
continue;
V_58 . V_4 = V_61 ;
F_27 ( & V_58 ,
V_78 ) ;
}
V_62 = 0 ;
V_56 &= ~ 0xffff ;
V_22 &= 0xffff ;
V_56 |= V_22 ;
}
F_28 ( V_69 , V_37 , V_56 , V_34 ) ;
if ( V_2 -> V_70 == V_71 )
break;
F_29 ( V_60 , V_64 ) ;
}
F_24 (k, policy->cpus) {
if ( ! F_25 ( V_61 ) )
continue;
V_58 . V_4 = V_61 ;
F_27 ( & V_58 , V_79 ) ;
}
if ( F_9 ( V_59 ) ) {
F_24 (j, covered_cpus)
F_28 ( V_60 , V_37 , V_56 , V_34 ) ;
V_63 = V_58 . V_77 ;
V_58 . V_77 = V_58 . V_76 ;
V_58 . V_76 = V_63 ;
F_24 (j, policy->cpus) {
if ( ! F_25 ( V_60 ) )
continue;
F_27 ( & V_58 , V_78 ) ;
F_27 ( & V_58 , V_79 ) ;
}
}
V_59 = 0 ;
V_67:
F_30 ( V_64 ) ;
return V_59 ;
}
static int T_2 F_31 ( void )
{
struct V_3 * V_4 = & F_2 ( 0 ) ;
if ( ! F_11 ( V_4 , V_42 ) )
return - V_16 ;
return F_32 ( & V_44 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_44 ) ;
}
