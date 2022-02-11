static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 V_5 ;
V_5 . V_6 = 0 ;
F_2 ( L_1 , V_2 ,
F_3 ( V_3 ) == V_7 ?
& V_2 -> V_8 [ V_9 ] . V_10 . V_11 . V_12 . V_13 :
& V_2 -> V_8 [ V_9 ] . V_10 . V_14 . V_12 . V_13 ) ;
return F_4 ( V_2 , & V_5 , F_3 ( V_3 ) ) ;
}
static unsigned int F_5 ( struct V_15 * V_16 , unsigned int V_3 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
struct V_1 * V_2 )
{
struct V_20 * V_20 = F_6 ( V_2 ) ;
unsigned int V_21 ;
V_21 = F_7 ( V_16 , V_3 , V_18 , V_19 , V_20 -> V_22 . V_23 ) ;
if ( V_21 == V_24 ) {
if ( ! F_8 ( V_2 , F_3 ( V_3 ) ) )
V_21 = F_1 ( V_2 , V_3 ) ;
}
return V_21 ;
}
static unsigned int
F_9 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
struct V_1 * V_2 ;
enum V_27 V_28 ;
struct V_29 * V_30 ;
enum V_31 V_32 = F_3 ( V_26 -> V_3 ) ;
T_1 V_33 ;
int V_34 ;
T_2 V_35 ;
V_2 = F_11 ( V_16 , & V_28 ) ;
if ( ! V_2 )
return V_24 ;
if ( F_12 ( V_2 ) )
return V_24 ;
V_30 = F_13 ( V_2 ) ;
if ( ! V_30 ) {
if ( F_14 ( V_2 ) )
return V_24 ;
V_30 = F_15 ( V_2 , V_36 , V_37 ) ;
if ( V_30 == NULL ) {
F_2 ( L_2 ) ;
return V_24 ;
}
}
switch ( V_28 ) {
case V_38 :
case V_39 :
V_35 = F_16 ( V_16 ) -> V_35 ;
V_34 = F_17 ( V_16 , sizeof( struct V_40 ) ,
& V_35 , & V_33 ) ;
if ( V_34 >= 0 && V_35 == V_41 ) {
if ( ! F_18 ( V_16 , V_2 , V_28 ,
V_26 -> V_3 ,
V_34 ) )
return V_42 ;
else
return V_24 ;
}
case V_43 :
if ( ! F_8 ( V_2 , V_32 ) ) {
unsigned int V_21 ;
V_21 = F_5 ( V_16 , V_26 -> V_3 , V_18 , V_19 , V_2 ) ;
if ( V_21 != V_24 )
return V_21 ;
} else {
F_2 ( L_3 ,
V_32 == V_7 ? L_4 : L_5 ,
V_2 ) ;
if ( F_19 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_44;
}
break;
default:
F_20 ( V_28 == V_45 ||
V_28 == V_46 ) ;
if ( F_19 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_44;
}
return F_21 ( V_2 , V_28 , V_26 -> V_3 , V_16 ) ;
V_44:
F_22 ( V_2 , V_28 , V_16 ) ;
return V_42 ;
}
static unsigned int
F_23 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
unsigned int V_21 ;
struct V_47 V_48 = F_16 ( V_16 ) -> V_48 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_42 && V_21 != V_49 &&
F_24 ( & V_48 , & F_16 ( V_16 ) -> V_48 ) )
F_25 ( V_16 ) ;
return V_21 ;
}
static unsigned int
F_26 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
#ifdef F_27
const struct V_1 * V_2 ;
enum V_27 V_28 ;
int V_50 ;
#endif
unsigned int V_21 ;
if ( V_16 -> V_51 < sizeof( struct V_40 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
#ifdef F_27
if ( V_21 != V_42 && V_21 != V_49 &&
! ( F_28 ( V_16 ) -> V_6 & V_52 ) &&
( V_2 = F_11 ( V_16 , & V_28 ) ) != NULL ) {
enum V_53 V_54 = F_29 ( V_28 ) ;
if ( ! F_30 ( & V_2 -> V_8 [ V_54 ] . V_10 . V_14 . V_12 ,
& V_2 -> V_8 [ ! V_54 ] . V_10 . V_11 . V_12 ) ||
( V_2 -> V_8 [ V_54 ] . V_10 . V_11 . V_55 != V_41 &&
V_2 -> V_8 [ V_54 ] . V_10 . V_14 . V_56 . V_57 !=
V_2 -> V_8 [ ! V_54 ] . V_10 . V_11 . V_56 . V_57 ) ) {
V_50 = F_31 ( V_16 , V_58 ) ;
if ( V_50 < 0 )
V_21 = F_32 ( V_50 ) ;
}
}
#endif
return V_21 ;
}
static unsigned int
F_33 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
const struct V_1 * V_2 ;
enum V_27 V_28 ;
unsigned int V_21 ;
int V_50 ;
if ( V_16 -> V_51 < sizeof( struct V_40 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_42 && V_21 != V_49 &&
( V_2 = F_11 ( V_16 , & V_28 ) ) != NULL ) {
enum V_53 V_54 = F_29 ( V_28 ) ;
if ( ! F_30 ( & V_2 -> V_8 [ V_54 ] . V_10 . V_11 . V_12 ,
& V_2 -> V_8 [ ! V_54 ] . V_10 . V_14 . V_12 ) ) {
V_50 = F_34 ( V_16 ) ;
if ( V_50 < 0 )
V_21 = F_32 ( V_50 ) ;
}
#ifdef F_27
else if ( ! ( F_28 ( V_16 ) -> V_6 & V_52 ) &&
V_2 -> V_8 [ V_54 ] . V_10 . V_11 . V_55 != V_41 &&
V_2 -> V_8 [ V_54 ] . V_10 . V_11 . V_56 . V_57 !=
V_2 -> V_8 [ ! V_54 ] . V_10 . V_14 . V_56 . V_57 ) {
V_50 = F_31 ( V_16 , V_58 ) ;
if ( V_50 < 0 )
V_21 = F_32 ( V_50 ) ;
}
#endif
}
return V_21 ;
}
static int T_3 F_35 ( struct V_20 * V_20 )
{
struct V_59 * V_60 ;
V_60 = F_36 ( & V_61 ) ;
if ( V_60 == NULL )
return - V_62 ;
V_20 -> V_22 . V_23 = F_37 ( V_20 , & V_61 , V_60 ) ;
F_38 ( V_60 ) ;
return F_39 ( V_20 -> V_22 . V_23 ) ;
}
static void T_4 F_40 ( struct V_20 * V_20 )
{
F_41 ( V_20 , V_20 -> V_22 . V_23 ) ;
}
static int T_5 F_42 ( void )
{
int V_50 ;
V_50 = F_43 ( & V_63 ) ;
if ( V_50 < 0 )
goto V_64;
V_50 = F_44 ( V_65 , F_45 ( V_65 ) ) ;
if ( V_50 < 0 )
goto V_66;
return 0 ;
V_66:
F_46 ( & V_63 ) ;
V_64:
return V_50 ;
}
static void T_6 F_47 ( void )
{
F_48 ( V_65 , F_45 ( V_65 ) ) ;
F_46 ( & V_63 ) ;
}
