static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 , const unsigned * * V_9 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned V_13 )
{
F_6 ( V_12 , L_1 , F_7 ( V_2 -> V_14 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_15 ;
}
static const char * F_9 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_16 [ V_6 ] . V_8 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_6 ,
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
T_1 V_26 , V_27 = 0x7 ;
unsigned long V_28 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
if ( V_24 -> V_13 != V_22 [ V_25 ] . V_24 . V_13 ||
V_24 -> V_30 != V_22 [ V_25 ] . V_24 . V_30 )
continue;
if ( ! V_22 [ V_25 ] . V_31 )
break;
if ( V_22 [ V_25 ] . V_24 . V_32 != V_24 -> V_32 ) {
F_12 ( V_4 -> V_14 ,
L_2 ) ;
F_12 ( V_4 -> V_14 , L_3 ,
V_18 -> V_8 , V_20 -> V_8 ) ;
return - V_33 ;
} else {
return 0 ;
}
}
V_22 [ V_25 ] . V_24 . V_32 = V_24 -> V_32 ;
V_22 [ V_25 ] . V_31 = true ;
F_13 ( & V_4 -> V_34 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_35 + V_20 -> V_24 . V_13 ) ;
V_26 &= ~ ( V_27 << V_20 -> V_24 . V_30 ) ;
V_26 |= V_20 -> V_24 . V_32 << V_20 -> V_24 . V_30 ;
F_15 ( V_26 , V_4 -> V_35 + V_20 -> V_24 . V_13 ) ;
F_16 ( & V_4 -> V_34 , V_28 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_36 , unsigned V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_17 * V_18 =
& V_4 -> V_16 [ V_36 ] ;
const struct V_19 * V_20 = & V_4 -> V_7 [ V_37 ] ;
F_18 ( V_2 -> V_14 , L_4 ,
V_36 , V_18 -> V_8 , V_37 , V_20 -> V_8 ) ;
F_18 ( V_2 -> V_14 , L_5 ,
V_20 -> V_24 . V_13 , V_20 -> V_24 . V_30 , V_20 -> V_24 . V_32 ) ;
return F_11 ( V_4 , V_18 , V_20 , V_4 -> V_22 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
unsigned V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_41 * V_24 = V_2 -> V_42 -> V_9 [ V_40 ] . V_43 ;
T_1 V_26 ;
unsigned long V_28 ;
if ( ! V_24 -> V_44 )
return - V_45 ;
F_13 ( & V_4 -> V_34 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_46 + V_24 -> V_13 ) ;
V_26 |= 0x3 << V_24 -> V_30 ;
F_15 ( V_26 , V_4 -> V_46 + V_24 -> V_13 ) ;
F_16 ( & V_4 -> V_34 , V_28 ) ;
F_18 ( V_2 -> V_14 ,
L_6 ,
V_40 , V_24 -> V_13 , V_24 -> V_30 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
unsigned V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_41 * V_24 = V_2 -> V_42 -> V_9 [ V_40 ] . V_43 ;
T_1 V_26 ;
unsigned long V_28 ;
if ( ! V_24 -> V_44 )
return;
F_13 ( & V_4 -> V_34 , V_28 ) ;
V_26 = F_14 ( V_4 -> V_46 + V_24 -> V_13 ) ;
V_26 &= ~ ( 0x3 << V_24 -> V_30 ) ;
F_15 ( V_26 , V_4 -> V_46 + V_24 -> V_13 ) ;
F_16 ( & V_4 -> V_34 , V_28 ) ;
F_12 ( V_2 -> V_14 ,
L_7 ,
V_40 , V_24 -> V_13 , V_24 -> V_30 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_21 * log ;
unsigned int V_25 , V_47 ;
V_4 -> V_22 = F_22 ( V_4 -> V_14 , V_29 ,
sizeof( struct V_21 ) ,
V_48 ) ;
if ( ! V_4 -> V_22 )
return - V_49 ;
log = V_4 -> V_22 ;
for ( V_25 = 0 ; V_25 < V_50 ; V_25 ++ ) {
for ( V_47 = 0 ; V_47 < V_51 ; V_47 ++ ) {
log = & V_4 -> V_22 [ V_25 * V_51
+ V_47 ] ;
log -> V_24 . V_13 = V_25 * 4 ;
log -> V_24 . V_30 = V_47 * 4 ;
log -> V_24 . V_32 = 0 ;
log -> V_31 = false ;
}
}
return 0 ;
}
static int F_23 ( struct V_52 * V_53 )
{
struct V_3 * V_4 ;
struct V_54 * V_55 ;
int V_25 , V_56 ;
struct V_57 * V_9 ;
unsigned V_10 = F_24 ( V_58 ) ;
V_4 = F_25 ( & V_53 -> V_14 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_4 -> V_14 = & V_53 -> V_14 ;
F_26 ( V_53 , V_4 ) ;
F_27 ( & V_4 -> V_34 ) ;
V_55 = F_28 ( V_53 , V_59 , 0 ) ;
V_4 -> V_35 = F_29 ( & V_53 -> V_14 , V_55 ) ;
if ( F_30 ( V_4 -> V_35 ) ) {
F_12 ( & V_53 -> V_14 , L_8 ) ;
return F_31 ( V_4 -> V_35 ) ;
}
V_55 = F_28 ( V_53 , V_59 , 1 ) ;
V_4 -> V_46 = F_29 ( & V_53 -> V_14 , V_55 ) ;
if ( F_30 ( V_4 -> V_46 ) ) {
F_12 ( & V_53 -> V_14 , L_8 ) ;
return F_31 ( V_4 -> V_46 ) ;
}
V_56 = F_21 ( V_4 ) ;
if ( V_56 ) {
F_12 ( & V_53 -> V_14 , L_9 ) ;
return V_56 ;
}
V_9 = F_22 ( & V_53 -> V_14 , V_10 , sizeof( * V_9 ) , V_48 ) ;
if ( ! V_9 )
return - V_49 ;
for ( V_25 = 0 ; V_25 < V_10 ; V_25 ++ ) {
V_9 [ V_25 ] . V_60 = V_58 [ V_25 ] . V_40 ;
V_9 [ V_25 ] . V_8 = V_58 [ V_25 ] . V_8 ;
V_9 [ V_25 ] . V_43 = & V_58 [ V_25 ] . V_61 ;
}
V_4 -> V_7 = V_62 ;
V_4 -> V_5 = F_24 ( V_62 ) ;
V_4 -> V_16 = V_63 ;
V_4 -> V_15 = F_24 ( V_63 ) ;
V_64 . V_9 = V_9 ;
V_64 . V_65 = V_10 ;
V_4 -> V_66 = F_32 ( & V_64 , & V_53 -> V_14 ,
V_4 ) ;
if ( ! V_4 -> V_66 ) {
F_12 ( & V_53 -> V_14 , L_10 ) ;
return - V_33 ;
}
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_67 ) ;
}
