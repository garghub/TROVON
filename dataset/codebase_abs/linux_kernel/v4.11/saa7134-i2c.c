static inline enum V_1 F_1 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
V_4 = F_2 ( V_5 ) & 0x0f ;
F_3 ( 2 , L_1 , V_6 [ V_4 ] ) ;
return V_4 ;
}
static inline void F_4 ( struct V_2 * V_3 ,
enum V_1 V_4 )
{
F_3 ( 2 , L_2 , V_6 [ V_4 ] ) ;
F_5 ( V_5 , 0x0f , V_4 ) ;
}
static inline void F_6 ( struct V_2 * V_3 , enum V_7 V_8 )
{
F_3 ( 2 , L_3 , V_9 [ V_8 ] ) ;
F_5 ( V_5 , 0xc0 , V_8 << 6 ) ;
}
static inline int F_7 ( enum V_1 V_4 )
{
switch ( V_4 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static inline int F_8 ( enum V_1 V_4 )
{
switch ( V_4 ) {
case V_16 :
case V_17 :
return true ;
default:
return false ;
}
}
static inline int F_9 ( enum V_1 V_4 )
{
switch ( V_4 ) {
case V_18 :
case V_19 :
case V_20 :
return true ;
default:
return false ;
}
}
static int F_10 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( ! F_9 ( V_4 ) )
break;
F_11 ( V_23 ) ;
}
if ( V_22 == V_21 )
return false ;
return true ;
}
static int F_12 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
int V_21 ;
F_3 ( 2 , L_4 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_7 ( V_4 ) )
return true ;
F_4 ( V_3 , V_4 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( ! F_7 ( V_4 ) )
break;
F_13 ( V_23 ) ;
}
if ( V_22 == V_21 )
return false ;
if ( ! F_8 ( V_4 ) )
return false ;
F_6 ( V_3 , V_24 ) ;
return true ;
}
static inline int F_14 ( struct V_2 * V_3 ,
enum V_7 V_8 ,
unsigned char V_25 )
{
enum V_1 V_4 ;
T_1 V_26 ;
V_26 = F_15 ( V_5 >> 2 ) ;
V_26 &= 0x0f ;
V_26 |= ( V_8 << 6 ) ;
V_26 |= ( ( T_1 ) V_25 << 8 ) ;
V_26 |= 0x00 << 16 ;
V_26 |= 0xf0 << 24 ;
F_16 ( V_5 >> 2 , V_26 ) ;
F_3 ( 2 , L_5 , V_25 ) ;
if ( ! F_10 ( V_3 ) )
return - V_27 ;
V_4 = F_1 ( V_3 ) ;
if ( F_7 ( V_4 ) )
return - V_27 ;
return 0 ;
}
static inline int F_17 ( struct V_2 * V_3 )
{
enum V_1 V_4 ;
unsigned char V_25 ;
F_6 ( V_3 , CONTINUE ) ;
if ( ! F_10 ( V_3 ) )
return - V_27 ;
V_4 = F_1 ( V_3 ) ;
if ( F_7 ( V_4 ) )
return - V_27 ;
V_25 = F_2 ( V_28 ) ;
F_3 ( 2 , L_6 , V_25 ) ;
return V_25 ;
}
static int F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 , int V_33 )
{
struct V_2 * V_3 = V_30 -> V_34 ;
enum V_1 V_4 ;
unsigned char V_25 ;
int V_35 , V_36 , V_37 , V_38 ;
V_4 = F_1 ( V_3 ) ;
if ( ! F_8 ( V_4 ) )
if ( ! F_12 ( V_3 ) )
return - V_27 ;
F_3 ( 2 , L_7 ) ;
F_3 ( 1 , L_8 ) ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
if ( ! ( V_32 [ V_37 ] . V_39 & V_40 ) || 0 == V_37 ) {
F_3 ( 2 , L_9 ) ;
V_35 = V_32 [ V_37 ] . V_35 << 1 ;
if ( V_32 [ V_37 ] . V_39 & V_41 )
V_35 |= 1 ;
if ( V_37 > 0 && V_32 [ V_37 ] . V_39 &
V_41 && V_32 [ V_37 ] . V_35 != 0x40 &&
V_32 [ V_37 ] . V_35 != 0x41 &&
V_32 [ V_37 ] . V_35 != 0x19 ) {
int V_42 = 0xfe ;
F_19 ( 1 , L_10 , V_42 ) ;
F_14 ( V_3 , V_43 , V_42 ) ;
F_17 ( V_3 ) ;
}
F_19 ( 1 , L_11 , V_35 ) ;
V_36 = F_14 ( V_3 , V_43 , V_35 ) ;
if ( V_36 < 0 )
goto V_44;
}
if ( V_32 [ V_37 ] . V_39 & V_41 ) {
F_3 ( 2 , L_12 ) ;
for ( V_38 = 0 ; V_38 < V_32 [ V_37 ] . V_45 ; V_38 ++ ) {
F_19 ( 1 , L_13 ) ;
V_36 = F_17 ( V_3 ) ;
if ( V_36 < 0 )
goto V_44;
F_19 ( 1 , L_14 , V_36 ) ;
V_32 [ V_37 ] . V_46 [ V_38 ] = V_36 ;
}
if ( 0x19 == V_32 [ V_37 ] . V_35 ) {
F_19 ( 1 , L_15 ) ;
V_36 = F_17 ( V_3 ) ;
if ( V_36 < 0 )
goto V_44;
F_19 ( 1 , L_14 , V_36 ) ;
}
} else {
F_3 ( 2 , L_16 ) ;
for ( V_38 = 0 ; V_38 < V_32 [ V_37 ] . V_45 ; V_38 ++ ) {
V_25 = V_32 [ V_37 ] . V_46 [ V_38 ] ;
F_19 ( 1 , L_17 , V_25 ) ;
V_36 = F_14 ( V_3 , CONTINUE , V_25 ) ;
if ( V_36 < 0 )
goto V_44;
}
}
}
F_3 ( 2 , L_18 ) ;
F_19 ( 1 , L_19 ) ;
F_6 ( V_3 , V_47 ) ;
V_36 = - V_27 ;
if ( ! F_10 ( V_3 ) )
goto V_44;
V_4 = F_1 ( V_3 ) ;
if ( F_7 ( V_4 ) )
goto V_44;
F_20 ( 1 ) ;
F_19 ( 1 , L_20 ) ;
return V_33 ;
V_44:
if ( 1 == V_48 ) {
V_4 = F_1 ( V_3 ) ;
F_19 ( 1 , L_21 , V_6 [ V_4 ] ) ;
}
return V_36 ;
}
static T_2 F_21 ( struct V_29 * V_49 )
{
return V_50 ;
}
static void F_22 ( struct V_2 * V_3 )
{
T_3 V_51 = 0x7 , V_52 ;
T_3 V_25 [ 2 ] ;
int V_53 ;
struct V_31 V_54 [] = { { . V_35 = 0x08 , . V_39 = 0 ,
. V_46 = & V_51 , . V_45 = 1 } ,
{ . V_35 = 0x08 ,
. V_39 = V_41 ,
. V_46 = & V_52 , . V_45 = 1 }
} ;
struct V_31 V_55 [] = { { . V_35 = 0x08 , . V_39 = 0 ,
. V_46 = V_25 , . V_45 = 2 } } ;
V_53 = F_23 ( & V_3 -> V_30 , V_54 , 2 ) ;
if ( ( V_53 == 2 ) && ( V_52 & 0x2 ) ) {
F_24 ( L_22 ,
V_3 -> V_56 ) ;
V_25 [ 0 ] = V_51 ;
V_25 [ 1 ] = ( V_52 & ~ 0x2 ) ;
if ( F_23 ( & V_3 -> V_30 , V_55 , 1 ) != 1 )
F_25 ( L_23 ,
V_3 -> V_56 ) ;
}
}
static int
F_26 ( struct V_2 * V_3 , unsigned char * V_57 , int V_45 )
{
unsigned char V_46 ;
int V_37 , V_44 ;
if ( V_3 -> V_58 == V_59 )
F_22 ( V_3 ) ;
V_3 -> V_60 . V_35 = 0xa0 >> 1 ;
V_46 = 0 ;
if ( 1 != ( V_44 = F_27 ( & V_3 -> V_60 , & V_46 , 1 ) ) ) {
F_28 ( L_24 ,
V_3 -> V_56 , V_44 ) ;
return - 1 ;
}
if ( V_45 != ( V_44 = F_29 ( & V_3 -> V_60 , V_57 , V_45 ) ) ) {
F_30 ( L_25 ,
V_3 -> V_56 , V_44 ) ;
return - 1 ;
}
for ( V_37 = 0 ; V_37 < V_45 ; V_37 += 16 ) {
int V_61 = ( V_45 - V_37 ) > 16 ? 16 : V_45 - V_37 ;
F_28 ( L_26 , V_37 , V_61 , & V_57 [ V_37 ] ) ;
}
return 0 ;
}
static void F_31 ( struct V_60 * V_62 )
{
unsigned char V_46 ;
int V_37 , V_36 ;
for ( V_37 = 0 ; V_37 < F_32 ( V_63 ) ; V_37 ++ ) {
V_62 -> V_35 = V_37 ;
V_36 = F_29 ( V_62 , & V_46 , 0 ) ;
if ( V_36 < 0 )
continue;
F_28 ( L_27 ,
V_37 << 1 , V_63 [ V_37 ] ? V_63 [ V_37 ] : L_28 ) ;
}
}
int F_33 ( struct V_2 * V_3 )
{
V_3 -> V_30 = V_64 ;
V_3 -> V_30 . V_3 . V_65 = & V_3 -> V_66 -> V_3 ;
strcpy ( V_3 -> V_30 . V_56 , V_3 -> V_56 ) ;
V_3 -> V_30 . V_34 = V_3 ;
F_34 ( & V_3 -> V_30 , & V_3 -> V_67 ) ;
F_35 ( & V_3 -> V_30 ) ;
V_3 -> V_60 = V_68 ;
V_3 -> V_60 . V_69 = & V_3 -> V_30 ;
F_26 ( V_3 , V_3 -> V_57 , sizeof( V_3 -> V_57 ) ) ;
if ( V_70 )
F_31 ( & V_3 -> V_60 ) ;
F_36 ( V_3 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 )
{
F_38 ( & V_3 -> V_30 ) ;
return 0 ;
}
