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
if ( V_30 == NULL )
return V_24 ;
switch ( V_28 ) {
case V_36 :
case V_37 :
V_35 = F_14 ( V_16 ) -> V_35 ;
V_34 = F_15 ( V_16 , sizeof( struct V_38 ) ,
& V_35 , & V_33 ) ;
if ( V_34 >= 0 && V_35 == V_39 ) {
if ( ! F_16 ( V_16 , V_2 , V_28 ,
V_26 -> V_3 ,
V_34 ) )
return V_40 ;
else
return V_24 ;
}
case V_41 :
if ( ! F_8 ( V_2 , V_32 ) ) {
unsigned int V_21 ;
V_21 = F_5 ( V_16 , V_26 -> V_3 , V_18 , V_19 , V_2 ) ;
if ( V_21 != V_24 )
return V_21 ;
} else {
F_2 ( L_2 ,
V_32 == V_7 ? L_3 : L_4 ,
V_2 ) ;
if ( F_17 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_42;
}
break;
default:
F_18 ( V_28 == V_43 ||
V_28 == V_44 ) ;
if ( F_17 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_42;
}
return F_19 ( V_2 , V_28 , V_26 -> V_3 , V_16 ) ;
V_42:
F_20 ( V_2 , V_28 , V_16 ) ;
return V_40 ;
}
static unsigned int
F_21 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
unsigned int V_21 ;
struct V_45 V_46 = F_14 ( V_16 ) -> V_46 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_40 && V_21 != V_47 &&
F_22 ( & V_46 , & F_14 ( V_16 ) -> V_46 ) )
F_23 ( V_16 ) ;
return V_21 ;
}
static unsigned int
F_24 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
#ifdef F_25
const struct V_1 * V_2 ;
enum V_27 V_28 ;
int V_48 ;
#endif
unsigned int V_21 ;
if ( V_16 -> V_49 < sizeof( struct V_38 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
#ifdef F_25
if ( V_21 != V_40 && V_21 != V_47 &&
! ( F_26 ( V_16 ) -> V_6 & V_50 ) &&
( V_2 = F_11 ( V_16 , & V_28 ) ) != NULL ) {
enum V_51 V_52 = F_27 ( V_28 ) ;
if ( ! F_28 ( & V_2 -> V_8 [ V_52 ] . V_10 . V_14 . V_12 ,
& V_2 -> V_8 [ ! V_52 ] . V_10 . V_11 . V_12 ) ||
( V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_53 != V_39 &&
V_2 -> V_8 [ V_52 ] . V_10 . V_14 . V_54 . V_55 !=
V_2 -> V_8 [ ! V_52 ] . V_10 . V_11 . V_54 . V_55 ) ) {
V_48 = F_29 ( V_16 , V_56 ) ;
if ( V_48 < 0 )
V_21 = F_30 ( V_48 ) ;
}
}
#endif
return V_21 ;
}
static unsigned int
F_31 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
const struct V_1 * V_2 ;
enum V_27 V_28 ;
unsigned int V_21 ;
int V_48 ;
if ( V_16 -> V_49 < sizeof( struct V_38 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_40 && V_21 != V_47 &&
( V_2 = F_11 ( V_16 , & V_28 ) ) != NULL ) {
enum V_51 V_52 = F_27 ( V_28 ) ;
if ( ! F_28 ( & V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_12 ,
& V_2 -> V_8 [ ! V_52 ] . V_10 . V_14 . V_12 ) ) {
V_48 = F_32 ( V_16 ) ;
if ( V_48 < 0 )
V_21 = F_30 ( V_48 ) ;
}
#ifdef F_25
else if ( ! ( F_26 ( V_16 ) -> V_6 & V_50 ) &&
V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_53 != V_39 &&
V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_54 . V_55 !=
V_2 -> V_8 [ ! V_52 ] . V_10 . V_14 . V_54 . V_55 ) {
V_48 = F_29 ( V_16 , V_56 ) ;
if ( V_48 < 0 )
V_21 = F_30 ( V_48 ) ;
}
#endif
}
return V_21 ;
}
static int T_3 F_33 ( struct V_20 * V_20 )
{
struct V_57 * V_58 ;
V_58 = F_34 ( & V_59 ) ;
if ( V_58 == NULL )
return - V_60 ;
V_20 -> V_22 . V_23 = F_35 ( V_20 , & V_59 , V_58 ) ;
F_36 ( V_58 ) ;
return F_37 ( V_20 -> V_22 . V_23 ) ;
}
static void T_4 F_38 ( struct V_20 * V_20 )
{
F_39 ( V_20 , V_20 -> V_22 . V_23 ) ;
}
static int T_5 F_40 ( void )
{
int V_48 ;
V_48 = F_41 ( & V_61 ) ;
if ( V_48 < 0 )
goto V_62;
V_48 = F_42 ( V_63 , F_43 ( V_63 ) ) ;
if ( V_48 < 0 )
goto V_64;
return 0 ;
V_64:
F_44 ( & V_61 ) ;
V_62:
return V_48 ;
}
static void T_6 F_45 ( void )
{
F_46 ( V_63 , F_43 ( V_63 ) ) ;
F_44 ( & V_61 ) ;
}
