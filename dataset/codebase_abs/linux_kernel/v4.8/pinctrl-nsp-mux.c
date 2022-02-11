static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_6 , const unsigned int * * V_9 ,
unsigned int * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned int V_13 )
{
F_6 ( V_12 , L_1 , F_7 ( V_2 -> V_14 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_15 ;
}
static const char * F_9 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_16 [ V_6 ] . V_8 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_6 ,
const char * const * * V_7 ,
unsigned * const V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_7 = V_4 -> V_16 [ V_6 ] . V_7 ;
* V_5 = V_4 -> V_16 [ V_6 ] . V_5 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
const struct V_23 * V_24 = & V_20 -> V_24 ;
int V_25 ;
T_1 V_26 , V_27 ;
unsigned long V_28 ;
void T_2 * V_29 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_5 ; V_25 ++ ) {
if ( ( V_24 -> V_30 != V_22 [ V_25 ] . V_24 . V_30 ) ||
( V_24 -> V_31 != V_22 [ V_25 ] . V_24 . V_31 ) )
continue;
if ( ! V_22 [ V_25 ] . V_32 )
break;
if ( V_22 [ V_25 ] . V_24 . V_33 != V_24 -> V_33 ) {
F_12 ( V_4 -> V_14 ,
L_2 ) ;
F_12 ( V_4 -> V_14 , L_3 ,
V_18 -> V_8 , V_20 -> V_8 ) ;
return - V_34 ;
}
return 0 ;
}
if ( V_25 == V_4 -> V_5 )
return - V_34 ;
V_27 = V_24 -> V_27 ;
V_22 [ V_25 ] . V_24 . V_33 = V_24 -> V_33 ;
V_22 [ V_25 ] . V_32 = true ;
switch ( V_24 -> V_31 ) {
case V_35 :
V_29 = V_4 -> V_36 ;
break;
case V_37 :
V_29 = V_4 -> V_38 ;
break;
case V_39 :
V_29 = V_4 -> V_40 ;
break;
default:
return - V_34 ;
}
F_13 ( & V_4 -> V_41 , V_28 ) ;
V_26 = F_14 ( V_29 ) ;
V_26 &= ~ ( V_27 << V_20 -> V_24 . V_30 ) ;
V_26 |= V_20 -> V_24 . V_33 << V_20 -> V_24 . V_30 ;
F_15 ( V_26 , V_29 ) ;
F_16 ( & V_4 -> V_41 , V_28 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_17 * V_18 ;
const struct V_19 * V_20 ;
if ( V_43 > V_4 -> V_5 ||
V_42 > V_4 -> V_15 )
return - V_34 ;
V_18 = & V_4 -> V_16 [ V_42 ] ;
V_20 = & V_4 -> V_7 [ V_43 ] ;
F_18 ( V_2 -> V_14 , L_4 ,
V_42 , V_18 -> V_8 , V_43 , V_20 -> V_8 ) ;
F_18 ( V_2 -> V_14 , L_5 , V_20 -> V_24 . V_30 ,
V_20 -> V_24 . V_33 ) ;
return F_11 ( V_4 , V_18 , V_20 , V_4 -> V_22 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
unsigned int V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_47 = V_2 -> V_48 -> V_9 [ V_46 ] . V_49 ;
T_1 V_26 ;
unsigned long V_28 ;
F_13 ( & V_4 -> V_41 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_36 ) ;
if ( ( V_26 & F_20 ( V_46 ) ) != ( * V_47 << V_46 ) ) {
V_26 &= ~ F_20 ( V_46 ) ;
V_26 |= * V_47 << V_46 ;
F_15 ( V_26 , V_4 -> V_36 ) ;
}
F_16 ( & V_4 -> V_41 , V_28 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
unsigned int V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_47 = V_2 -> V_48 -> V_9 [ V_46 ] . V_49 ;
T_1 V_26 ;
unsigned long V_28 ;
F_13 ( & V_4 -> V_41 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_36 ) ;
if ( ( V_26 & ( 1 << V_46 ) ) == ( * V_47 << V_46 ) ) {
V_26 &= ~ ( 1 << V_46 ) ;
if ( ! ( * V_47 ) )
V_26 |= ( 1 << V_46 ) ;
F_15 ( V_26 , V_4 -> V_36 ) ;
}
F_16 ( & V_4 -> V_41 , V_28 ) ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_21 * log ;
unsigned int V_25 ;
T_1 V_50 = F_23 ( V_51 ) ;
V_4 -> V_22 = F_24 ( V_4 -> V_14 , V_50 ,
sizeof( struct V_21 ) ,
V_52 ) ;
if ( ! V_4 -> V_22 )
return - V_53 ;
for ( V_25 = 0 ; V_25 < V_50 ; V_25 ++ ) {
log = & V_4 -> V_22 [ V_25 ] ;
log -> V_24 . V_31 = V_51 [ V_25 ] . V_24 . V_31 ;
log -> V_24 . V_30 = V_51 [ V_25 ] . V_24 . V_30 ;
log -> V_24 . V_33 = 0 ;
log -> V_32 = false ;
}
return 0 ;
}
static int F_25 ( struct V_54 * V_55 )
{
struct V_3 * V_4 ;
struct V_56 * V_57 ;
int V_25 , V_58 ;
struct V_59 * V_9 ;
unsigned int V_10 = F_23 ( V_60 ) ;
V_4 = F_26 ( & V_55 -> V_14 , sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_14 = & V_55 -> V_14 ;
F_27 ( V_55 , V_4 ) ;
F_28 ( & V_4 -> V_41 ) ;
V_57 = F_29 ( V_55 , V_61 , 0 ) ;
V_4 -> V_36 = F_30 ( & V_55 -> V_14 , V_57 ) ;
if ( F_31 ( V_4 -> V_36 ) )
return F_32 ( V_4 -> V_36 ) ;
V_57 = F_29 ( V_55 , V_61 , 1 ) ;
V_4 -> V_38 = F_33 ( & V_55 -> V_14 , V_57 -> V_62 ,
F_34 ( V_57 ) ) ;
if ( ! V_4 -> V_38 ) {
F_12 ( & V_55 -> V_14 , L_6 ) ;
return - V_53 ;
}
V_57 = F_29 ( V_55 , V_61 , 2 ) ;
V_4 -> V_40 = F_30 ( & V_55 -> V_14 , V_57 ) ;
if ( F_31 ( V_4 -> V_40 ) )
return F_32 ( V_4 -> V_40 ) ;
V_58 = F_22 ( V_4 ) ;
if ( V_58 ) {
F_12 ( & V_55 -> V_14 , L_7 ) ;
return V_58 ;
}
V_9 = F_24 ( & V_55 -> V_14 , V_10 , sizeof( * V_9 ) , V_52 ) ;
if ( ! V_9 )
return - V_53 ;
for ( V_25 = 0 ; V_25 < V_10 ; V_25 ++ ) {
V_9 [ V_25 ] . V_63 = V_60 [ V_25 ] . V_46 ;
V_9 [ V_25 ] . V_8 = V_60 [ V_25 ] . V_8 ;
V_9 [ V_25 ] . V_49 = & V_60 [ V_25 ] . V_47 ;
}
V_4 -> V_7 = V_51 ;
V_4 -> V_5 = F_23 ( V_51 ) ;
V_4 -> V_16 = V_64 ;
V_4 -> V_15 = F_23 ( V_64 ) ;
V_65 . V_9 = V_9 ;
V_65 . V_66 = V_10 ;
V_4 -> V_67 = F_35 ( & V_55 -> V_14 , & V_65 ,
V_4 ) ;
if ( F_31 ( V_4 -> V_67 ) ) {
F_12 ( & V_55 -> V_14 , L_8 ) ;
return F_32 ( V_4 -> V_67 ) ;
}
return 0 ;
}
static int T_3 F_36 ( void )
{
return F_37 ( & V_68 ) ;
}
