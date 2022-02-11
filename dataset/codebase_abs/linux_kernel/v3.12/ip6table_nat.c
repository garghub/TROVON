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
T_1 V_31 ;
int V_32 ;
T_2 V_33 ;
V_2 = F_11 ( V_16 , & V_26 ) ;
if ( ! V_2 )
return V_24 ;
if ( F_12 ( V_2 ) )
return V_24 ;
V_28 = F_13 ( V_2 ) ;
if ( ! V_28 ) {
if ( F_14 ( V_2 ) )
return V_24 ;
V_28 = F_15 ( V_2 , V_34 , V_35 ) ;
if ( V_28 == NULL ) {
F_2 ( L_2 ) ;
return V_24 ;
}
}
switch ( V_26 ) {
case V_36 :
case V_37 :
V_33 = F_16 ( V_16 ) -> V_33 ;
V_32 = F_17 ( V_16 , sizeof( struct V_38 ) ,
& V_33 , & V_31 ) ;
if ( V_32 >= 0 && V_33 == V_39 ) {
if ( ! F_18 ( V_16 , V_2 , V_26 ,
V_3 , V_32 ) )
return V_40 ;
else
return V_24 ;
}
case V_41 :
if ( ! F_8 ( V_2 , V_30 ) ) {
unsigned int V_21 ;
V_21 = F_5 ( V_16 , V_3 , V_18 , V_19 , V_2 ) ;
if ( V_21 != V_24 )
return V_21 ;
} else {
F_2 ( L_3 ,
V_30 == V_7 ? L_4 : L_5 ,
V_2 ) ;
if ( F_19 ( V_3 , V_26 , V_28 , V_19 ) )
goto V_42;
}
break;
default:
F_20 ( V_26 == V_43 ||
V_26 == V_44 ) ;
if ( F_19 ( V_3 , V_26 , V_28 , V_19 ) )
goto V_42;
}
return F_21 ( V_2 , V_26 , V_3 , V_16 ) ;
V_42:
F_22 ( V_2 , V_26 , V_16 ) ;
return V_40 ;
}
static unsigned int
F_23 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
unsigned int V_21 ;
struct V_45 V_46 = F_16 ( V_16 ) -> V_46 ;
V_21 = F_9 ( V_3 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_40 && V_21 != V_47 &&
F_24 ( & V_46 , & F_16 ( V_16 ) -> V_46 ) )
F_25 ( V_16 ) ;
return V_21 ;
}
static unsigned int
F_26 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
#ifdef F_27
const struct V_1 * V_2 ;
enum V_25 V_26 ;
int V_48 ;
#endif
unsigned int V_21 ;
if ( V_16 -> V_49 < sizeof( struct V_38 ) )
return V_24 ;
V_21 = F_9 ( V_3 , V_16 , V_18 , V_19 , F_10 ) ;
#ifdef F_27
if ( V_21 != V_40 && V_21 != V_47 &&
! ( F_28 ( V_16 ) -> V_6 & V_50 ) &&
( V_2 = F_11 ( V_16 , & V_26 ) ) != NULL ) {
enum V_51 V_52 = F_29 ( V_26 ) ;
if ( ! F_30 ( & V_2 -> V_8 [ V_52 ] . V_10 . V_14 . V_12 ,
& V_2 -> V_8 [ ! V_52 ] . V_10 . V_11 . V_12 ) ||
( V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_53 != V_39 &&
V_2 -> V_8 [ V_52 ] . V_10 . V_14 . V_54 . V_55 !=
V_2 -> V_8 [ ! V_52 ] . V_10 . V_11 . V_54 . V_55 ) ) {
V_48 = F_31 ( V_16 , V_56 ) ;
if ( V_48 < 0 )
V_21 = F_32 ( V_48 ) ;
}
}
#endif
return V_21 ;
}
static unsigned int
F_33 ( unsigned int V_3 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_10)( struct V_15 * ) )
{
const struct V_1 * V_2 ;
enum V_25 V_26 ;
unsigned int V_21 ;
int V_48 ;
if ( V_16 -> V_49 < sizeof( struct V_38 ) )
return V_24 ;
V_21 = F_9 ( V_3 , V_16 , V_18 , V_19 , F_10 ) ;
if ( V_21 != V_40 && V_21 != V_47 &&
( V_2 = F_11 ( V_16 , & V_26 ) ) != NULL ) {
enum V_51 V_52 = F_29 ( V_26 ) ;
if ( ! F_30 ( & V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_12 ,
& V_2 -> V_8 [ ! V_52 ] . V_10 . V_14 . V_12 ) ) {
V_48 = F_34 ( V_16 ) ;
if ( V_48 < 0 )
V_21 = F_32 ( V_48 ) ;
}
#ifdef F_27
else if ( ! ( F_28 ( V_16 ) -> V_6 & V_50 ) &&
V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_53 != V_39 &&
V_2 -> V_8 [ V_52 ] . V_10 . V_11 . V_54 . V_55 !=
V_2 -> V_8 [ ! V_52 ] . V_10 . V_14 . V_54 . V_55 ) {
V_48 = F_31 ( V_16 , V_56 ) ;
if ( V_48 < 0 )
V_21 = F_32 ( V_48 ) ;
}
#endif
}
return V_21 ;
}
static int T_3 F_35 ( struct V_20 * V_20 )
{
struct V_57 * V_58 ;
V_58 = F_36 ( & V_59 ) ;
if ( V_58 == NULL )
return - V_60 ;
V_20 -> V_22 . V_23 = F_37 ( V_20 , & V_59 , V_58 ) ;
F_38 ( V_58 ) ;
return F_39 ( V_20 -> V_22 . V_23 ) ;
}
static void T_4 F_40 ( struct V_20 * V_20 )
{
F_41 ( V_20 , V_20 -> V_22 . V_23 ) ;
}
static int T_5 F_42 ( void )
{
int V_48 ;
V_48 = F_43 ( & V_61 ) ;
if ( V_48 < 0 )
goto V_62;
V_48 = F_44 ( V_63 , F_45 ( V_63 ) ) ;
if ( V_48 < 0 )
goto V_64;
return 0 ;
V_64:
F_46 ( & V_61 ) ;
V_62:
return V_48 ;
}
static void T_6 F_47 ( void )
{
F_48 ( V_63 , F_45 ( V_63 ) ) ;
F_46 ( & V_61 ) ;
}
