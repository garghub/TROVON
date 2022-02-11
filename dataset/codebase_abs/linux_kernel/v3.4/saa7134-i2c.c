static inline enum V_1 F_1 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
V_4 = F_2 ( V_5 ) & 0x0f ;
F_3 ( V_6 L_1 , V_3 -> V_7 ,
V_8 [ V_4 ] ) ;
return V_4 ;
}
static inline void F_4 ( struct V_2 * V_3 ,
enum V_1 V_4 )
{
F_3 ( V_6 L_2 , V_3 -> V_7 ,
V_8 [ V_4 ] ) ;
F_5 ( V_5 , 0x0f , V_4 ) ;
}
static inline void F_6 ( struct V_2 * V_3 , enum V_9 V_10 )
{
F_3 ( V_6 L_3 , V_3 -> V_7 ,
V_11 [ V_10 ] ) ;
F_5 ( V_5 , 0xc0 , V_10 << 6 ) ;
}
static inline int F_7 ( enum V_1 V_4 )
{
switch ( V_4 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
return true ;
default:
return false ;
}
}
static inline int F_8 ( enum V_1 V_4 )
{
switch ( V_4 ) {
case V_18 :
case V_19 :
return true ;
default:
return false ;
}
}
static inline int F_9 ( enum V_1 V_4 )
{
switch ( V_4 ) {
case V_20 :
case V_21 :
case V_22 :
return true ;
default:
return false ;
}
}
static int F_10 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( ! F_9 ( V_4 ) )
break;
F_11 ( V_25 ) ;
}
if ( V_24 == V_23 )
return false ;
return true ;
}
static int F_12 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
int V_23 ;
F_3 ( V_6 L_4 , V_3 -> V_7 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_7 ( V_4 ) )
return true ;
F_4 ( V_3 , V_4 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( ! F_7 ( V_4 ) )
break;
F_13 ( V_25 ) ;
}
if ( V_24 == V_23 )
return false ;
if ( ! F_8 ( V_4 ) )
return false ;
F_6 ( V_3 , V_26 ) ;
return true ;
}
static inline int F_14 ( struct V_2 * V_3 ,
enum V_9 V_10 ,
unsigned char V_27 )
{
enum V_1 V_4 ;
T_1 V_28 ;
V_28 = F_15 ( V_5 >> 2 ) ;
V_28 &= 0x0f ;
V_28 |= ( V_10 << 6 ) ;
V_28 |= ( ( T_1 ) V_27 << 8 ) ;
V_28 |= 0x00 << 16 ;
V_28 |= 0xf0 << 24 ;
F_16 ( V_5 >> 2 , V_28 ) ;
F_3 ( V_6 L_5 , V_3 -> V_7 , V_27 ) ;
if ( ! F_10 ( V_3 ) )
return - V_29 ;
V_4 = F_1 ( V_3 ) ;
if ( F_7 ( V_4 ) )
return - V_29 ;
return 0 ;
}
static inline int F_17 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
unsigned char V_27 ;
F_6 ( V_3 , CONTINUE ) ;
if ( ! F_10 ( V_3 ) )
return - V_29 ;
V_4 = F_1 ( V_3 ) ;
if ( F_7 ( V_4 ) )
return - V_29 ;
V_27 = F_2 ( V_30 ) ;
F_3 ( V_6 L_6 , V_3 -> V_7 , V_27 ) ;
return V_27 ;
}
static int F_18 ( struct V_31 * V_32 ,
struct V_33 * V_34 , int V_35 )
{
struct V_2 * V_3 = V_32 -> V_36 ;
enum V_1 V_4 ;
unsigned char V_27 ;
int V_37 , V_38 , V_39 , V_40 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_8 ( V_4 ) )
if ( ! F_12 ( V_3 ) )
return - V_29 ;
F_3 ( L_7 ) ;
F_19 ( V_6 L_8 , V_3 -> V_7 ) ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 ++ ) {
if ( ! ( V_34 [ V_39 ] . V_41 & V_42 ) || 0 == V_39 ) {
F_3 ( L_9 ) ;
V_37 = V_34 [ V_39 ] . V_37 << 1 ;
if ( V_34 [ V_39 ] . V_41 & V_43 )
V_37 |= 1 ;
if ( V_39 > 0 && V_34 [ V_39 ] . V_41 &
V_43 && V_34 [ V_39 ] . V_37 != 0x40 &&
V_34 [ V_39 ] . V_37 != 0x19 ) {
int V_44 = 0xfe ;
F_19 ( L_10 , V_44 ) ;
F_14 ( V_3 , V_45 , V_44 ) ;
F_17 ( V_3 ) ;
}
F_19 ( L_11 , V_37 ) ;
V_38 = F_14 ( V_3 , V_45 , V_37 ) ;
if ( V_38 < 0 )
goto V_46;
}
if ( V_34 [ V_39 ] . V_41 & V_43 ) {
F_3 ( L_12 ) ;
for ( V_40 = 0 ; V_40 < V_34 [ V_39 ] . V_47 ; V_40 ++ ) {
F_19 ( L_13 ) ;
V_38 = F_17 ( V_3 ) ;
if ( V_38 < 0 )
goto V_46;
F_19 ( L_14 , V_38 ) ;
V_34 [ V_39 ] . V_48 [ V_40 ] = V_38 ;
}
if ( 0x19 == V_34 [ V_39 ] . V_37 ) {
F_19 ( L_15 ) ;
V_38 = F_17 ( V_3 ) ;
if ( V_38 < 0 )
goto V_46;
F_19 ( L_14 , V_38 ) ;
}
} else {
F_3 ( L_16 ) ;
for ( V_40 = 0 ; V_40 < V_34 [ V_39 ] . V_47 ; V_40 ++ ) {
V_27 = V_34 [ V_39 ] . V_48 [ V_40 ] ;
F_19 ( L_17 , V_27 ) ;
V_38 = F_14 ( V_3 , CONTINUE , V_27 ) ;
if ( V_38 < 0 )
goto V_46;
}
}
}
F_3 ( L_18 ) ;
F_19 ( L_19 ) ;
F_6 ( V_3 , V_49 ) ;
V_38 = - V_29 ;
if ( ! F_10 ( V_3 ) )
goto V_46;
V_4 = F_1 ( V_3 ) ;
if ( F_7 ( V_4 ) )
goto V_46;
F_20 ( 1 ) ;
F_19 ( L_20 ) ;
return V_35 ;
V_46:
if ( 1 == V_50 ) {
V_4 = F_1 ( V_3 ) ;
F_21 ( L_21 , V_8 [ V_4 ] ) ;
}
return V_38 ;
}
static T_2 F_22 ( struct V_31 * V_51 )
{
return V_52 ;
}
static int
F_23 ( struct V_2 * V_3 , unsigned char * V_53 , int V_47 )
{
unsigned char V_48 ;
int V_39 , V_46 ;
V_3 -> V_54 . V_37 = 0xa0 >> 1 ;
V_48 = 0 ;
if ( 1 != ( V_46 = F_24 ( & V_3 -> V_54 , & V_48 , 1 ) ) ) {
F_21 ( V_55 L_22 ,
V_3 -> V_7 , V_46 ) ;
return - 1 ;
}
if ( V_47 != ( V_46 = F_25 ( & V_3 -> V_54 , V_53 , V_47 ) ) ) {
F_21 ( V_56 L_23 ,
V_3 -> V_7 , V_46 ) ;
return - 1 ;
}
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ ) {
if ( 0 == ( V_39 % 16 ) )
F_21 ( V_55 L_24 , V_3 -> V_7 , V_39 ) ;
F_21 ( L_17 , V_53 [ V_39 ] ) ;
if ( 15 == ( V_39 % 16 ) )
F_21 ( L_20 ) ;
}
return 0 ;
}
static void F_26 ( char * V_7 , struct V_54 * V_57 )
{
unsigned char V_48 ;
int V_39 , V_38 ;
for ( V_39 = 0 ; V_39 < F_27 ( V_58 ) ; V_39 ++ ) {
V_57 -> V_37 = V_39 ;
V_38 = F_25 ( V_57 , & V_48 , 0 ) ;
if ( V_38 < 0 )
continue;
F_21 ( L_25 ,
V_7 , V_39 << 1 , V_58 [ V_39 ] ? V_58 [ V_39 ] : L_26 ) ;
}
}
int F_28 ( struct V_2 * V_3 )
{
V_3 -> V_32 = V_59 ;
V_3 -> V_32 . V_3 . V_60 = & V_3 -> V_61 -> V_3 ;
strcpy ( V_3 -> V_32 . V_7 , V_3 -> V_7 ) ;
V_3 -> V_32 . V_36 = V_3 ;
F_29 ( & V_3 -> V_32 , & V_3 -> V_62 ) ;
F_30 ( & V_3 -> V_32 ) ;
V_3 -> V_54 = V_63 ;
V_3 -> V_54 . V_64 = & V_3 -> V_32 ;
F_23 ( V_3 , V_3 -> V_53 , sizeof( V_3 -> V_53 ) ) ;
if ( V_65 )
F_26 ( V_3 -> V_7 , & V_3 -> V_54 ) ;
F_31 ( V_3 ) ;
return 0 ;
}
int F_32 ( struct V_2 * V_3 )
{
F_33 ( & V_3 -> V_32 ) ;
return 0 ;
}
