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
if ( V_30 == NULL )
return V_24 ;
switch ( V_28 ) {
case V_33 :
case V_34 :
if ( F_13 ( V_16 ) -> V_35 == V_36 ) {
if ( ! F_17 ( V_16 , V_2 , V_28 ,
V_26 -> V_3 ) )
return V_37 ;
else
return V_24 ;
}
case V_38 :
if ( ! F_8 ( V_2 , V_32 ) ) {
unsigned int V_21 ;
V_21 = F_5 ( V_16 , V_26 -> V_3 , V_18 , V_19 , V_2 ) ;
if ( V_21 != V_24 )
return V_21 ;
} else {
F_2 ( L_2 ,
V_32 == V_7 ? L_3 : L_4 ,
V_2 ) ;
if ( F_18 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_39;
}
break;
default:
F_11 ( V_28 == V_40 ||
V_28 == V_41 ) ;
if ( F_18 ( V_26 -> V_3 , V_28 , V_30 , V_19 ) )
goto V_39;
}
return F_19 ( V_2 , V_28 , V_26 -> V_3 , V_16 ) ;
V_39:
F_20 ( V_2 , V_28 , V_16 ) ;
return V_37 ;
}
static unsigned int
F_21 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
unsigned int V_21 ;
T_1 V_42 = F_13 ( V_16 ) -> V_42 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_37 && V_21 != V_43 &&
V_42 != F_13 ( V_16 ) -> V_42 )
F_22 ( V_16 ) ;
return V_21 ;
}
static unsigned int
F_23 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
#ifdef F_24
const struct V_1 * V_2 ;
enum V_27 V_28 ;
int V_44 ;
#endif
unsigned int V_21 ;
if ( V_16 -> V_45 < sizeof( struct V_46 ) ||
F_25 ( V_16 ) < sizeof( struct V_46 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
#ifdef F_24
if ( V_21 != V_37 && V_21 != V_43 &&
! ( F_26 ( V_16 ) -> V_6 & V_47 ) &&
( V_2 = F_14 ( V_16 , & V_28 ) ) != NULL ) {
enum V_48 V_49 = F_27 ( V_28 ) ;
if ( ( V_2 -> V_8 [ V_49 ] . V_10 . V_14 . V_12 . V_13 !=
V_2 -> V_8 [ ! V_49 ] . V_10 . V_11 . V_12 . V_13 ) ||
( V_2 -> V_8 [ V_49 ] . V_10 . V_11 . V_50 != V_36 &&
V_2 -> V_8 [ V_49 ] . V_10 . V_14 . V_51 . V_52 !=
V_2 -> V_8 [ ! V_49 ] . V_10 . V_11 . V_51 . V_52 ) ) {
V_44 = F_28 ( V_16 , V_53 ) ;
if ( V_44 < 0 )
V_21 = F_29 ( V_44 ) ;
}
}
#endif
return V_21 ;
}
static unsigned int
F_30 ( const struct V_25 * V_26 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
const struct V_1 * V_2 ;
enum V_27 V_28 ;
unsigned int V_21 ;
int V_44 ;
if ( V_16 -> V_45 < sizeof( struct V_46 ) ||
F_25 ( V_16 ) < sizeof( struct V_46 ) )
return V_24 ;
V_21 = F_9 ( V_26 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_37 && V_21 != V_43 &&
( V_2 = F_14 ( V_16 , & V_28 ) ) != NULL ) {
enum V_48 V_49 = F_27 ( V_28 ) ;
if ( V_2 -> V_8 [ V_49 ] . V_10 . V_11 . V_12 . V_13 !=
V_2 -> V_8 [ ! V_49 ] . V_10 . V_14 . V_12 . V_13 ) {
V_44 = F_31 ( V_16 , V_54 ) ;
if ( V_44 < 0 )
V_21 = F_29 ( V_44 ) ;
}
#ifdef F_24
else if ( ! ( F_26 ( V_16 ) -> V_6 & V_47 ) &&
V_2 -> V_8 [ V_49 ] . V_10 . V_11 . V_50 != V_36 &&
V_2 -> V_8 [ V_49 ] . V_10 . V_11 . V_51 . V_52 !=
V_2 -> V_8 [ ! V_49 ] . V_10 . V_14 . V_51 . V_52 ) {
V_44 = F_28 ( V_16 , V_53 ) ;
if ( V_44 < 0 )
V_21 = F_29 ( V_44 ) ;
}
#endif
}
return V_21 ;
}
static int T_2 F_32 ( struct V_20 * V_20 )
{
struct V_55 * V_56 ;
V_56 = F_33 ( & V_57 ) ;
if ( V_56 == NULL )
return - V_58 ;
V_20 -> V_22 . V_23 = F_34 ( V_20 , & V_57 , V_56 ) ;
F_35 ( V_56 ) ;
return F_36 ( V_20 -> V_22 . V_23 ) ;
}
static void T_3 F_37 ( struct V_20 * V_20 )
{
F_38 ( V_20 , V_20 -> V_22 . V_23 ) ;
}
static int T_4 F_39 ( void )
{
int V_44 ;
V_44 = F_40 ( & V_59 ) ;
if ( V_44 < 0 )
goto V_60;
V_44 = F_41 ( V_61 , F_42 ( V_61 ) ) ;
if ( V_44 < 0 )
goto V_62;
return 0 ;
V_62:
F_43 ( & V_59 ) ;
V_60:
return V_44 ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_61 , F_42 ( V_61 ) ) ;
F_43 ( & V_59 ) ;
}
