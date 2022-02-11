static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
T_1 V_6 ;
switch ( V_3 ) {
case V_7 :
F_3 ( V_5 , V_8 , & V_6 ) ;
if ( ( V_6 & V_9 ) == 0 )
return 0 ;
F_3 ( V_5 , V_10 , & V_6 ) ;
if ( ( V_6 & V_11 ) == 0 )
return 0 ;
return 1 ;
default:
return - V_12 ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_6 ;
struct V_4 * V_5 = V_2 -> V_4 ;
struct V_13 * V_13 = F_5 ( V_2 ) ;
const struct V_14 * V_15 =
& V_16 [ V_13 -> V_17 ] ;
if ( F_2 ( V_2 ) != V_7 )
return - V_12 ;
F_3 ( V_5 , V_18 , & V_6 ) ;
if ( ( V_6 & V_19 ) == 0 )
return V_15 -> V_20 ;
V_6 = ( ( V_6 & V_21 ) >>
V_22 ) ;
return V_15 -> V_23 + V_6 * V_15 -> V_24 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_25 , int V_26 )
{
T_1 V_6 ;
int V_27 ;
struct V_13 * V_13 = F_5 ( V_2 ) ;
const struct V_14 * V_15 =
& V_16 [ V_13 -> V_17 ] ;
if ( F_2 ( V_2 ) != V_7 )
return - V_12 ;
V_27 = F_7 ( V_15 , V_25 , V_26 , & V_6 ) ;
if ( V_27 )
return V_27 ;
return F_8 ( V_2 -> V_4 , V_18 ,
V_19 | V_21 ,
V_6 ) ;
}
static inline struct V_28 * F_9 ( int V_29 ,
enum V_30 V_17 )
{
switch ( V_17 ) {
case V_31 :
return V_32 [ V_29 ] . V_33 ;
case V_34 :
default:
return V_35 [ V_29 ] . V_33 ;
}
}
static inline struct V_36 * F_10 ( int V_29 ,
enum V_30 V_17 )
{
switch ( V_17 ) {
case V_31 :
return V_32 [ V_29 ] . V_37 ;
case V_34 :
default:
return V_35 [ V_29 ] . V_37 ;
}
}
static inline struct V_28 * F_9 ( int V_29 ,
enum V_30 V_17 )
{
return NULL ;
}
static inline struct V_36 * F_10 ( int V_29 ,
enum V_30 V_17 )
{
return NULL ;
}
static struct V_4 * F_11 ( struct V_13 * V_13 ,
int V_38 )
{
switch ( V_13 -> V_17 ) {
case V_31 :
switch ( V_38 ) {
case V_39 ... V_40 :
return V_13 -> V_4 ;
default:
return V_13 -> V_41 ;
}
case V_34 :
default:
return V_13 -> V_4 ;
}
}
static int F_12 ( struct V_42 * V_43 )
{
struct V_13 * V_13 = F_13 ( V_43 -> V_44 . V_45 ) ;
struct V_46 * V_47 = F_14 ( V_13 -> V_44 ) ;
int V_48 , V_27 = 0 ;
struct V_49 V_50 = {} ;
const struct V_51 * V_52 ;
unsigned int V_53 ;
enum V_30 V_17 = V_13 -> V_17 ;
switch ( V_17 ) {
case V_31 :
V_52 = V_54 ;
V_53 = F_15 ( V_54 ) ;
break;
case V_34 :
default:
V_52 = V_55 ;
V_53 = F_15 ( V_55 ) ;
}
V_50 . V_44 = V_13 -> V_44 ;
V_50 . V_56 = V_13 ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
struct V_1 * V_57 ;
if ( V_47 && V_47 -> V_58 ) {
V_50 . V_33 = V_47 -> V_58 [ V_48 ] . V_59 ;
V_50 . V_37 = V_47 -> V_58 [ V_48 ] . V_37 ;
} else {
V_50 . V_33 = F_9 ( V_48 , V_17 ) ;
V_50 . V_37 = F_10 ( V_48 , V_17 ) ;
}
V_50 . V_4 = F_11 ( V_13 ,
V_52 [ V_48 ] . V_60 ) ;
V_57 = F_16 ( & V_43 -> V_44 ,
& V_52 [ V_48 ] , & V_50 ) ;
if ( F_17 ( V_57 ) ) {
V_27 = F_18 ( V_57 ) ;
F_19 ( & V_43 -> V_44 ,
L_1 ,
V_48 , V_52 [ V_48 ] . V_61 , V_27 ) ;
return V_27 ;
}
}
return V_27 ;
}
static int T_2 F_20 ( void )
{
F_21 ( F_15 ( V_55 ) != V_62 ) ;
F_21 ( F_15 ( V_54 ) != V_63 ) ;
F_21 ( V_64 +
( V_65 *
( V_66 - 1 ) ) !=
V_67 ) ;
return F_22 ( & V_68 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_68 ) ;
}
