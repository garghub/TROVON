static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 . V_8 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 ;
enum V_13 V_14 ;
enum V_15 V_16 ;
unsigned long V_17 ;
V_10 = F_2 ( V_2 , & V_14 ) ;
if ( V_10 == NULL )
return;
V_16 = F_3 ( V_14 ) ;
V_12 = & V_10 -> V_18 [ V_16 ] . V_19 ;
if ( V_16 == V_20 )
V_17 = V_21 ;
else
V_17 = V_22 ;
if ( V_10 -> V_23 & V_17 ) {
V_6 -> V_24 = V_12 -> V_25 . V_26 . V_27 ;
if ( V_12 -> V_25 . V_28 == V_29 ||
V_12 -> V_25 . V_28 == V_30 ||
V_12 -> V_25 . V_28 == V_31 ||
V_12 -> V_25 . V_28 == V_32 ||
V_12 -> V_25 . V_28 == V_33 )
V_6 -> V_34 = V_12 -> V_25 . V_7 . V_35 . V_36 ;
}
V_17 ^= V_37 ;
if ( V_10 -> V_23 & V_17 ) {
V_6 -> V_38 = V_12 -> V_39 . V_26 . V_27 ;
if ( V_12 -> V_25 . V_28 == V_29 ||
V_12 -> V_25 . V_28 == V_30 ||
V_12 -> V_25 . V_28 == V_31 ||
V_12 -> V_25 . V_28 == V_32 ||
V_12 -> V_25 . V_28 == V_33 )
V_6 -> V_40 = V_12 -> V_39 . V_7 . V_35 . V_36 ;
}
}
static unsigned int
F_4 ( unsigned int V_41 ,
struct V_1 * V_2 ,
const struct V_42 * V_43 ,
const struct V_42 * V_44 ,
int (* F_5)( struct V_1 * ) )
{
struct V_9 * V_10 ;
enum V_13 V_14 ;
struct V_45 * V_46 ;
enum V_47 V_48 = F_6 ( V_41 ) ;
F_7 ( ! F_8 ( F_9 ( V_2 ) ) ) ;
V_10 = F_2 ( V_2 , & V_14 ) ;
if ( ! V_10 )
return V_49 ;
if ( F_10 ( V_10 ) )
return V_49 ;
V_46 = F_11 ( V_10 ) ;
if ( ! V_46 ) {
if ( F_12 ( V_10 ) )
return V_49 ;
V_46 = F_13 ( V_10 , V_50 , V_51 ) ;
if ( V_46 == NULL ) {
F_14 ( L_1 ) ;
return V_49 ;
}
}
switch ( V_14 ) {
case V_52 :
case V_53 :
if ( F_9 ( V_2 ) -> V_54 == V_55 ) {
if ( ! F_15 ( V_10 , V_14 ,
V_41 , V_2 ) )
return V_56 ;
else
return V_49 ;
}
case V_57 :
if ( ! F_16 ( V_10 , V_48 ) ) {
unsigned int V_58 ;
V_58 = F_17 ( V_2 , V_41 , V_43 , V_44 , V_10 ) ;
if ( V_58 != V_49 )
return V_58 ;
} else
F_14 ( L_2 ,
V_48 == V_59 ? L_3 : L_4 ,
V_10 ) ;
break;
default:
F_7 ( V_14 == V_60 ||
V_14 == V_61 ) ;
}
return F_18 ( V_10 , V_14 , V_41 , V_2 ) ;
}
static unsigned int
F_19 ( unsigned int V_41 ,
struct V_1 * V_2 ,
const struct V_42 * V_43 ,
const struct V_42 * V_44 ,
int (* F_5)( struct V_1 * ) )
{
unsigned int V_58 ;
T_1 V_24 = F_9 ( V_2 ) -> V_24 ;
V_58 = F_4 ( V_41 , V_2 , V_43 , V_44 , F_5 ) ;
if ( V_58 != V_56 && V_58 != V_62 &&
V_24 != F_9 ( V_2 ) -> V_24 )
F_20 ( V_2 ) ;
return V_58 ;
}
static unsigned int
F_21 ( unsigned int V_41 ,
struct V_1 * V_2 ,
const struct V_42 * V_43 ,
const struct V_42 * V_44 ,
int (* F_5)( struct V_1 * ) )
{
#ifdef F_22
const struct V_9 * V_10 ;
enum V_13 V_14 ;
#endif
unsigned int V_58 ;
if ( V_2 -> V_63 < sizeof( struct V_64 ) ||
F_23 ( V_2 ) < sizeof( struct V_64 ) )
return V_49 ;
V_58 = F_4 ( V_41 , V_2 , V_43 , V_44 , F_5 ) ;
#ifdef F_22
if ( V_58 != V_56 && V_58 != V_62 &&
( V_10 = F_2 ( V_2 , & V_14 ) ) != NULL ) {
enum V_15 V_16 = F_3 ( V_14 ) ;
if ( ( V_10 -> V_18 [ V_16 ] . V_19 . V_39 . V_26 . V_27 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_25 . V_26 . V_27 ) ||
( V_10 -> V_18 [ V_16 ] . V_19 . V_39 . V_7 . V_65 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_25 . V_7 . V_65 )
)
return F_24 ( V_2 ) == 0 ? V_58 : V_56 ;
}
#endif
return V_58 ;
}
static unsigned int
F_25 ( unsigned int V_41 ,
struct V_1 * V_2 ,
const struct V_42 * V_43 ,
const struct V_42 * V_44 ,
int (* F_5)( struct V_1 * ) )
{
const struct V_9 * V_10 ;
enum V_13 V_14 ;
unsigned int V_58 ;
if ( V_2 -> V_63 < sizeof( struct V_64 ) ||
F_23 ( V_2 ) < sizeof( struct V_64 ) )
return V_49 ;
V_58 = F_4 ( V_41 , V_2 , V_43 , V_44 , F_5 ) ;
if ( V_58 != V_56 && V_58 != V_62 &&
( V_10 = F_2 ( V_2 , & V_14 ) ) != NULL ) {
enum V_15 V_16 = F_3 ( V_14 ) ;
if ( V_10 -> V_18 [ V_16 ] . V_19 . V_25 . V_26 . V_27 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_39 . V_26 . V_27 ) {
if ( F_26 ( V_2 , V_66 ) )
V_58 = V_56 ;
}
#ifdef F_22
else if ( V_10 -> V_18 [ V_16 ] . V_19 . V_25 . V_7 . V_65 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_39 . V_7 . V_65 )
if ( F_24 ( V_2 ) )
V_58 = V_56 ;
#endif
}
return V_58 ;
}
static int T_2 F_27 ( void )
{
int V_58 = 0 ;
F_28 () ;
#ifdef F_22
F_29 ( V_67 != NULL ) ;
F_30 ( V_67 , F_1 ) ;
#endif
V_58 = F_31 () ;
if ( V_58 < 0 ) {
F_32 ( L_5 ) ;
goto V_68;
}
V_58 = F_33 ( V_69 , F_34 ( V_69 ) ) ;
if ( V_58 < 0 ) {
F_32 ( L_6 ) ;
goto V_70;
}
return V_58 ;
V_70:
F_35 () ;
V_68:
#ifdef F_22
F_30 ( V_67 , NULL ) ;
F_36 () ;
#endif
return V_58 ;
}
static void T_3 F_37 ( void )
{
F_38 ( V_69 , F_34 ( V_69 ) ) ;
F_35 () ;
#ifdef F_22
F_30 ( V_67 , NULL ) ;
F_36 () ;
#endif
}
