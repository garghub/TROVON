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
F_7 ( ! ( F_8 ( V_2 ) -> V_49 & F_9 ( V_50 | V_51 ) ) ) ;
V_10 = F_2 ( V_2 , & V_14 ) ;
if ( ! V_10 )
return V_52 ;
if ( F_10 ( V_10 ) )
return V_52 ;
V_46 = F_11 ( V_10 ) ;
if ( ! V_46 ) {
if ( F_12 ( V_10 ) )
return V_52 ;
V_46 = F_13 ( V_10 , V_53 , V_54 ) ;
if ( V_46 == NULL ) {
F_14 ( L_1 ) ;
return V_52 ;
}
}
switch ( V_14 ) {
case V_55 :
case V_56 :
if ( F_8 ( V_2 ) -> V_57 == V_58 ) {
if ( ! F_15 ( V_10 , V_14 ,
V_41 , V_2 ) )
return V_59 ;
else
return V_52 ;
}
case V_60 :
if ( ! F_16 ( V_10 , V_48 ) ) {
unsigned int V_61 ;
V_61 = F_17 ( V_2 , V_41 , V_43 , V_44 , V_10 ) ;
if ( V_61 != V_52 )
return V_61 ;
} else
F_14 ( L_2 ,
V_48 == V_62 ? L_3 : L_4 ,
V_10 ) ;
break;
default:
F_7 ( V_14 == V_63 ||
V_14 == V_64 ) ;
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
unsigned int V_61 ;
T_1 V_24 = F_8 ( V_2 ) -> V_24 ;
V_61 = F_4 ( V_41 , V_2 , V_43 , V_44 , F_5 ) ;
if ( V_61 != V_59 && V_61 != V_65 &&
V_24 != F_8 ( V_2 ) -> V_24 )
F_20 ( V_2 ) ;
return V_61 ;
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
unsigned int V_61 ;
if ( V_2 -> V_66 < sizeof( struct V_67 ) ||
F_23 ( V_2 ) < sizeof( struct V_67 ) )
return V_52 ;
V_61 = F_4 ( V_41 , V_2 , V_43 , V_44 , F_5 ) ;
#ifdef F_22
if ( V_61 != V_59 && V_61 != V_65 &&
( V_10 = F_2 ( V_2 , & V_14 ) ) != NULL ) {
enum V_15 V_16 = F_3 ( V_14 ) ;
if ( ( V_10 -> V_18 [ V_16 ] . V_19 . V_39 . V_26 . V_27 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_25 . V_26 . V_27 ) ||
( V_10 -> V_18 [ V_16 ] . V_19 . V_39 . V_7 . V_68 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_25 . V_7 . V_68 )
)
return F_24 ( V_2 ) == 0 ? V_61 : V_59 ;
}
#endif
return V_61 ;
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
unsigned int V_61 ;
if ( V_2 -> V_66 < sizeof( struct V_67 ) ||
F_23 ( V_2 ) < sizeof( struct V_67 ) )
return V_52 ;
V_61 = F_4 ( V_41 , V_2 , V_43 , V_44 , F_5 ) ;
if ( V_61 != V_59 && V_61 != V_65 &&
( V_10 = F_2 ( V_2 , & V_14 ) ) != NULL ) {
enum V_15 V_16 = F_3 ( V_14 ) ;
if ( V_10 -> V_18 [ V_16 ] . V_19 . V_25 . V_26 . V_27 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_39 . V_26 . V_27 ) {
if ( F_26 ( V_2 , V_69 ) )
V_61 = V_59 ;
}
#ifdef F_22
else if ( V_10 -> V_18 [ V_16 ] . V_19 . V_25 . V_7 . V_68 !=
V_10 -> V_18 [ ! V_16 ] . V_19 . V_39 . V_7 . V_68 )
if ( F_24 ( V_2 ) )
V_61 = V_59 ;
#endif
}
return V_61 ;
}
static int T_2 F_27 ( void )
{
int V_61 = 0 ;
F_28 () ;
#ifdef F_22
F_29 ( V_70 != NULL ) ;
F_30 ( V_70 , F_1 ) ;
#endif
V_61 = F_31 () ;
if ( V_61 < 0 ) {
F_32 ( L_5 ) ;
goto V_71;
}
V_61 = F_33 ( V_72 , F_34 ( V_72 ) ) ;
if ( V_61 < 0 ) {
F_32 ( L_6 ) ;
goto V_73;
}
return V_61 ;
V_73:
F_35 () ;
V_71:
#ifdef F_22
F_30 ( V_70 , NULL ) ;
F_36 () ;
#endif
return V_61 ;
}
static void T_3 F_37 ( void )
{
F_38 ( V_72 , F_34 ( V_72 ) ) ;
F_35 () ;
#ifdef F_22
F_30 ( V_70 , NULL ) ;
F_36 () ;
#endif
}
