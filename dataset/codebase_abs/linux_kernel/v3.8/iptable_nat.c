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
F_9 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
struct V_1 * V_2 ;
enum V_25 V_26 ;
struct V_27 * V_28 ;
enum V_29 V_30 = F_3 ( V_3 ) ;
F_11 ( ! F_12 ( F_13 ( V_16 ) ) ) ;
V_2 = F_14 ( V_16 , & V_26 ) ;
if ( ! V_2 )
return V_24 ;
if ( F_15 ( V_2 ) )
return V_24 ;
V_28 = F_16 ( V_2 ) ;
if ( ! V_28 ) {
if ( F_17 ( V_2 ) )
return V_24 ;
V_28 = F_18 ( V_2 , V_31 , V_32 ) ;
if ( V_28 == NULL ) {
F_2 ( L_2 ) ;
return V_24 ;
}
}
switch ( V_26 ) {
case V_33 :
case V_34 :
if ( F_13 ( V_16 ) -> V_35 == V_36 ) {
if ( ! F_19 ( V_16 , V_2 , V_26 ,
V_3 ) )
return V_37 ;
else
return V_24 ;
}
case V_38 :
if ( ! F_8 ( V_2 , V_30 ) ) {
unsigned int V_21 ;
V_21 = F_5 ( V_16 , V_3 , V_18 , V_19 , V_2 ) ;
if ( V_21 != V_24 )
return V_21 ;
} else {
F_2 ( L_3 ,
V_30 == V_7 ? L_4 : L_5 ,
V_2 ) ;
if ( F_20 ( V_3 , V_26 , V_28 , V_19 ) )
goto V_39;
}
break;
default:
F_11 ( V_26 == V_40 ||
V_26 == V_41 ) ;
if ( F_20 ( V_3 , V_26 , V_28 , V_19 ) )
goto V_39;
}
return F_21 ( V_2 , V_26 , V_3 , V_16 ) ;
V_39:
F_22 ( V_2 , V_26 , V_16 ) ;
return V_37 ;
}
static unsigned int
F_23 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
unsigned int V_21 ;
T_1 V_42 = F_13 ( V_16 ) -> V_42 ;
V_21 = F_9 ( V_3 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_37 && V_21 != V_43 &&
V_42 != F_13 ( V_16 ) -> V_42 )
F_24 ( V_16 ) ;
return V_21 ;
}
static unsigned int
F_25 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
#ifdef F_26
const struct V_1 * V_2 ;
enum V_25 V_26 ;
#endif
unsigned int V_21 ;
if ( V_16 -> V_44 < sizeof( struct V_45 ) ||
F_27 ( V_16 ) < sizeof( struct V_45 ) )
return V_24 ;
V_21 = F_9 ( V_3 , V_16 , V_18 , V_19 , F_10 ) ;
#ifdef F_26
if ( V_21 != V_37 && V_21 != V_43 &&
! ( F_28 ( V_16 ) -> V_6 & V_46 ) &&
( V_2 = F_14 ( V_16 , & V_26 ) ) != NULL ) {
enum V_47 V_48 = F_29 ( V_26 ) ;
if ( ( V_2 -> V_8 [ V_48 ] . V_10 . V_14 . V_12 . V_13 !=
V_2 -> V_8 [ ! V_48 ] . V_10 . V_11 . V_12 . V_13 ) ||
( V_2 -> V_8 [ V_48 ] . V_10 . V_11 . V_49 != V_36 &&
V_2 -> V_8 [ V_48 ] . V_10 . V_14 . V_50 . V_51 !=
V_2 -> V_8 [ ! V_48 ] . V_10 . V_11 . V_50 . V_51 ) )
if ( F_30 ( V_16 , V_52 ) < 0 )
V_21 = V_37 ;
}
#endif
return V_21 ;
}
static unsigned int
F_31 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
const struct V_1 * V_2 ;
enum V_25 V_26 ;
unsigned int V_21 ;
if ( V_16 -> V_44 < sizeof( struct V_45 ) ||
F_27 ( V_16 ) < sizeof( struct V_45 ) )
return V_24 ;
V_21 = F_9 ( V_3 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_37 && V_21 != V_43 &&
( V_2 = F_14 ( V_16 , & V_26 ) ) != NULL ) {
enum V_47 V_48 = F_29 ( V_26 ) ;
if ( V_2 -> V_8 [ V_48 ] . V_10 . V_11 . V_12 . V_13 !=
V_2 -> V_8 [ ! V_48 ] . V_10 . V_14 . V_12 . V_13 ) {
if ( F_32 ( V_16 , V_53 ) )
V_21 = V_37 ;
}
#ifdef F_26
else if ( ! ( F_28 ( V_16 ) -> V_6 & V_46 ) &&
V_2 -> V_8 [ V_48 ] . V_10 . V_11 . V_49 != V_36 &&
V_2 -> V_8 [ V_48 ] . V_10 . V_11 . V_50 . V_51 !=
V_2 -> V_8 [ ! V_48 ] . V_10 . V_14 . V_50 . V_51 )
if ( F_30 ( V_16 , V_52 ) < 0 )
V_21 = V_37 ;
#endif
}
return V_21 ;
}
static int T_2 F_33 ( struct V_20 * V_20 )
{
struct V_54 * V_55 ;
V_55 = F_34 ( & V_56 ) ;
if ( V_55 == NULL )
return - V_57 ;
V_20 -> V_22 . V_23 = F_35 ( V_20 , & V_56 , V_55 ) ;
F_36 ( V_55 ) ;
return F_37 ( V_20 -> V_22 . V_23 ) ;
}
static void T_3 F_38 ( struct V_20 * V_20 )
{
F_39 ( V_20 , V_20 -> V_22 . V_23 ) ;
}
static int T_4 F_40 ( void )
{
int V_58 ;
V_58 = F_41 ( & V_59 ) ;
if ( V_58 < 0 )
goto V_60;
V_58 = F_42 ( V_61 , F_43 ( V_61 ) ) ;
if ( V_58 < 0 )
goto V_62;
return 0 ;
V_62:
F_44 ( & V_59 ) ;
V_60:
return V_58 ;
}
static void T_5 F_45 ( void )
{
F_46 ( V_61 , F_43 ( V_61 ) ) ;
F_44 ( & V_59 ) ;
}
