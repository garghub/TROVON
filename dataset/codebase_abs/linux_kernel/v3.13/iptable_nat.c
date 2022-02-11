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
F_11 ( ! F_12 ( F_13 ( V_16 ) ) ) ;
V_2 = F_14 ( V_16 , & V_28 ) ;
if ( ! V_2 )
return V_24 ;
if ( F_15 ( V_2 ) )
return V_24 ;
V_30 = F_16 ( V_2 ) ;
if ( ! V_30 ) {
if ( F_17 ( V_2 ) )
return V_24 ;
V_30 = F_18 ( V_2 , V_33 , V_34 ) ;
if ( V_30 == NULL ) {
F_2 ( L_2 ) ;
return V_24 ;
}
}
switch ( V_28 ) {
case V_35 :
case V_36 :
if ( F_13 ( V_16 ) -> V_37 == V_38 ) {
if ( ! F_19 ( V_16 , V_2 , V_28 ,
V_26 -> V_3 ) )
return V_39 ;
else
return V_24 ;
}
case V_40 :
if ( ! F_8 ( V_2 , V_32 ) ) {
unsigned int V_21 ;
V_21 = F_5 ( V_16 , V_26 -> V_3 , V_18 , V_19 , V_2 ) ;
if ( V_21 != V_24 )
return V_21 ;
} else {
F_2 ( L_3 ,
V_32 == V_7 ? L_4 : L_5 ,
V_2 ) ;
if ( F_20 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_41;
}
break;
default:
F_11 ( V_28 == V_42 ||
V_28 == V_43 ) ;
if ( F_20 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_41;
}
return F_21 ( V_2 , V_28 , V_26 -> V_3 , V_16 ) ;
V_41:
F_22 ( V_2 , V_28 , V_16 ) ;
return V_39 ;
}
static unsigned int
F_23 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
unsigned int V_21 ;
T_1 V_44 = F_13 ( V_16 ) -> V_44 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_39 && V_21 != V_45 &&
V_44 != F_13 ( V_16 ) -> V_44 )
F_24 ( V_16 ) ;
return V_21 ;
}
static unsigned int
F_25 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
#ifdef F_26
const struct V_1 * V_2 ;
enum V_27 V_28 ;
int V_46 ;
#endif
unsigned int V_21 ;
if ( V_16 -> V_47 < sizeof( struct V_48 ) ||
F_27 ( V_16 ) < sizeof( struct V_48 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
#ifdef F_26
if ( V_21 != V_39 && V_21 != V_45 &&
! ( F_28 ( V_16 ) -> V_6 & V_49 ) &&
( V_2 = F_14 ( V_16 , & V_28 ) ) != NULL ) {
enum V_50 V_51 = F_29 ( V_28 ) ;
if ( ( V_2 -> V_8 [ V_51 ] . V_10 . V_14 . V_12 . V_13 !=
V_2 -> V_8 [ ! V_51 ] . V_10 . V_11 . V_12 . V_13 ) ||
( V_2 -> V_8 [ V_51 ] . V_10 . V_11 . V_52 != V_38 &&
V_2 -> V_8 [ V_51 ] . V_10 . V_14 . V_53 . V_54 !=
V_2 -> V_8 [ ! V_51 ] . V_10 . V_11 . V_53 . V_54 ) ) {
V_46 = F_30 ( V_16 , V_55 ) ;
if ( V_46 < 0 )
V_21 = F_31 ( V_46 ) ;
}
}
#endif
return V_21 ;
}
static unsigned int
F_32 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
const struct V_1 * V_2 ;
enum V_27 V_28 ;
unsigned int V_21 ;
int V_46 ;
if ( V_16 -> V_47 < sizeof( struct V_48 ) ||
F_27 ( V_16 ) < sizeof( struct V_48 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_39 && V_21 != V_45 &&
( V_2 = F_14 ( V_16 , & V_28 ) ) != NULL ) {
enum V_50 V_51 = F_29 ( V_28 ) ;
if ( V_2 -> V_8 [ V_51 ] . V_10 . V_11 . V_12 . V_13 !=
V_2 -> V_8 [ ! V_51 ] . V_10 . V_14 . V_12 . V_13 ) {
V_46 = F_33 ( V_16 , V_56 ) ;
if ( V_46 < 0 )
V_21 = F_31 ( V_46 ) ;
}
#ifdef F_26
else if ( ! ( F_28 ( V_16 ) -> V_6 & V_49 ) &&
V_2 -> V_8 [ V_51 ] . V_10 . V_11 . V_52 != V_38 &&
V_2 -> V_8 [ V_51 ] . V_10 . V_11 . V_53 . V_54 !=
V_2 -> V_8 [ ! V_51 ] . V_10 . V_14 . V_53 . V_54 ) {
V_46 = F_30 ( V_16 , V_55 ) ;
if ( V_46 < 0 )
V_21 = F_31 ( V_46 ) ;
}
#endif
}
return V_21 ;
}
static int T_2 F_34 ( struct V_20 * V_20 )
{
struct V_57 * V_58 ;
V_58 = F_35 ( & V_59 ) ;
if ( V_58 == NULL )
return - V_60 ;
V_20 -> V_22 . V_23 = F_36 ( V_20 , & V_59 , V_58 ) ;
F_37 ( V_58 ) ;
return F_38 ( V_20 -> V_22 . V_23 ) ;
}
static void T_3 F_39 ( struct V_20 * V_20 )
{
F_40 ( V_20 , V_20 -> V_22 . V_23 ) ;
}
static int T_4 F_41 ( void )
{
int V_46 ;
V_46 = F_42 ( & V_61 ) ;
if ( V_46 < 0 )
goto V_62;
V_46 = F_43 ( V_63 , F_44 ( V_63 ) ) ;
if ( V_46 < 0 )
goto V_64;
return 0 ;
V_64:
F_45 ( & V_61 ) ;
V_62:
return V_46 ;
}
static void T_5 F_46 ( void )
{
F_47 ( V_63 , F_44 ( V_63 ) ) ;
F_45 ( & V_61 ) ;
}
