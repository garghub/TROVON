static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 [ V_7 ] &= ~ V_8 ;
if ( V_4 -> V_9 == V_10 ) {
F_2 ( V_2 , V_11 , V_12 ) ;
} else if ( V_4 -> V_9 == V_13 ) {
F_3 ( V_2 , V_11 , V_12 ) ;
V_4 -> V_6 [ V_7 ] |= V_14 ;
} else {
F_3 ( V_2 , V_11 , V_12 ) ;
}
return F_4 ( V_2 , V_7 ) ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
static const char * const V_19 [ 3 ] = {
L_1 ,
L_2 ,
L_3 ,
} ;
return F_6 ( V_18 , 1 , 3 , V_19 ) ;
}
static int F_7 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( & V_2 -> V_23 ) ;
V_21 -> V_21 . V_24 . V_25 [ 0 ] = V_4 -> V_9 ;
F_9 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_26 = V_21 -> V_21 . V_24 . V_25 [ 0 ] ;
int V_27 = 0 ;
int V_28 ;
F_8 ( & V_2 -> V_23 ) ;
if ( V_4 -> V_9 != V_26 ) {
V_4 -> V_9 = V_26 ;
V_28 = F_1 ( V_2 ) ;
V_27 = V_28 >= 0 ? 1 : V_28 ;
F_11 ( V_2 ) ;
}
F_9 ( & V_2 -> V_23 ) ;
return V_27 ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
V_18 -> type = V_29 ;
V_18 -> V_30 = 2 ;
V_18 -> V_21 . integer . V_31 = 0 ;
V_18 -> V_21 . integer . V_32 = 255 ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_20 * V_33 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_34 ;
F_8 ( & V_2 -> V_23 ) ;
V_34 = ( ~ V_4 -> V_6 [ V_35 ] ) & 255 ;
V_33 -> V_21 . integer . V_21 [ 0 ] = V_34 ;
V_34 = ( ~ V_4 -> V_6 [ V_36 ] ) & 255 ;
V_33 -> V_21 . integer . V_21 [ 1 ] = V_34 ;
F_9 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_20 * V_33 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
int V_27 = 0 ;
long V_37 = V_33 -> V_21 . integer . V_21 [ 0 ] ;
long V_38 = V_33 -> V_21 . integer . V_21 [ 1 ] ;
if ( ( V_37 > 255 ) || ( V_37 < 0 ) || ( V_38 > 255 ) || ( V_38 < 0 ) )
return - V_39 ;
F_8 ( & V_2 -> V_23 ) ;
if ( ( V_4 -> V_6 [ V_35 ] != ~ V_37 ) ||
( V_4 -> V_6 [ V_36 ] != ~ V_38 ) ) {
V_4 -> V_6 [ V_35 ] = ~ V_37 ;
V_4 -> V_6 [ V_36 ] = ~ V_38 ;
V_28 = F_4 ( V_2 , V_35 ) ;
if ( V_28 >= 0 )
V_28 = F_4 ( V_2 , V_36 ) ;
V_27 = V_28 >= 0 ? 1 : V_28 ;
}
F_9 ( & V_2 -> V_23 ) ;
return V_27 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_20 * V_33 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( & V_2 -> V_23 ) ;
V_33 -> V_21 . integer . V_21 [ 0 ] =
! ( V_4 -> V_6 [ V_40 ] & V_41 ) ;
F_9 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 ,
struct V_20 * V_33 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
int V_27 ;
if ( V_33 -> V_21 . integer . V_21 [ 0 ] > 1 )
return - V_39 ;
F_8 ( & V_2 -> V_23 ) ;
V_4 -> V_6 [ V_40 ] &= ~ V_41 ;
V_4 -> V_6 [ V_40 ] |=
( ~ V_33 -> V_21 . integer . V_21 [ 0 ] << 2 ) & V_41 ;
V_28 = F_4 ( V_2 , V_40 ) ;
V_27 = V_28 >= 0 ? 1 : V_28 ;
F_9 ( & V_2 -> V_23 ) ;
return V_27 ;
}
static int F_17 ( struct V_1 * V_2 , char V_42 , char V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
V_4 -> V_6 [ V_44 ] = V_42 ;
V_4 -> V_6 [ V_45 ] = V_43 ;
V_28 = F_4 ( V_2 , V_44 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_4 ( V_2 , V_45 ) ;
}
static int F_18 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
V_18 -> type = V_29 ;
V_18 -> V_30 = 2 ;
V_18 -> V_21 . integer . V_31 = 2 * - 12 ;
V_18 -> V_21 . integer . V_32 = 2 * 12 ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_46 = V_16 -> V_47 ;
F_8 ( & V_2 -> V_23 ) ;
V_21 -> V_21 . integer . V_21 [ 0 ] = V_4 -> V_48 [ V_46 ] [ 0 ] ;
V_21 -> V_21 . integer . V_21 [ 1 ] = V_4 -> V_48 [ V_46 ] [ 1 ] ;
F_9 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_46 = V_16 -> V_47 ;
int V_27 = 0 ;
int V_28 = 0 ;
if ( V_21 -> V_21 . integer . V_21 [ 0 ] < 2 * - 12 ||
V_21 -> V_21 . integer . V_21 [ 0 ] > 2 * 12 ||
V_21 -> V_21 . integer . V_21 [ 1 ] < 2 * - 12 ||
V_21 -> V_21 . integer . V_21 [ 1 ] > 2 * 12 )
return - V_39 ;
F_8 ( & V_2 -> V_23 ) ;
V_27 = V_4 -> V_48 [ V_46 ] [ 0 ] != V_21 -> V_21 . integer . V_21 [ 0 ] ||
V_4 -> V_48 [ V_46 ] [ 1 ] != V_21 -> V_21 . integer . V_21 [ 1 ] ;
if ( V_27 ) {
V_4 -> V_48 [ V_46 ] [ 0 ] = V_21 -> V_21 . integer . V_21 [ 0 ] ;
V_4 -> V_48 [ V_46 ] [ 1 ] = V_21 -> V_21 . integer . V_21 [ 1 ] ;
if ( V_46 == V_4 -> V_49 ) {
V_28 = F_17 ( V_2 ,
V_4 -> V_48 [ V_46 ] [ 0 ] ,
V_4 -> V_48 [ V_46 ] [ 1 ] ) ;
}
V_27 = V_28 >= 0 ? 1 : V_28 ;
}
F_9 ( & V_2 -> V_23 ) ;
return V_27 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 [ V_50 ] &= ~ V_51 ;
if ( V_4 -> V_49 == V_52 )
V_4 -> V_6 [ V_50 ] |= V_53 ;
else if ( V_4 -> V_49 == V_54 )
V_4 -> V_6 [ V_50 ] |= V_55 ;
else if ( V_4 -> V_49 != V_56 )
V_4 -> V_6 [ V_50 ] |= V_57 ;
return F_4 ( V_2 , V_50 ) ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
static const char * const V_19 [ 4 ] = {
L_4 , L_5 , L_6 , L_7
} ;
return F_6 ( V_18 , 1 , 4 , V_19 ) ;
}
static int F_23 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( & V_2 -> V_23 ) ;
V_21 -> V_21 . V_24 . V_25 [ 0 ] = V_4 -> V_49 ;
F_9 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_24 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_27 ;
int V_28 ;
if ( V_21 -> V_21 . V_24 . V_25 [ 0 ] > 3 )
return - V_39 ;
F_8 ( & V_2 -> V_23 ) ;
V_27 = V_21 -> V_21 . V_24 . V_25 [ 0 ] != V_4 -> V_49 ;
if ( V_27 ) {
V_4 -> V_49 = V_21 -> V_21 . V_24 . V_25 [ 0 ] ;
V_28 = F_21 ( V_2 ) ;
if ( V_28 >= 0 )
V_28 = F_17 ( V_2 ,
V_4 -> V_48 [ V_4 -> V_49 ] [ 0 ] ,
V_4 -> V_48 [ V_4 -> V_49 ] [ 1 ] ) ;
V_27 = V_28 >= 0 ? 1 : V_28 ;
}
F_9 ( & V_2 -> V_23 ) ;
return V_27 ;
}
static int F_25 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
static const char * const V_19 [ 2 ] = { L_8 , L_9 } ;
return F_6 ( V_18 , 1 , 2 , V_19 ) ;
}
static int F_26 ( struct V_15 * V_16 , struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_21 -> V_21 . V_24 . V_25 [ 0 ] =
! ! ( V_4 -> V_6 [ V_58 ] & V_59 ) ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 , struct V_20 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_60 ;
int V_27 ;
F_8 ( & V_2 -> V_23 ) ;
V_60 = V_4 -> V_6 [ V_58 ] & ~ V_59 ;
if ( V_21 -> V_21 . V_24 . V_25 [ 0 ] )
V_60 |= V_59 ;
V_27 = V_60 != V_4 -> V_6 [ V_58 ] ;
if ( V_27 ) {
V_4 -> V_6 [ V_58 ] = V_60 ;
F_4 ( V_2 , V_58 ) ;
}
F_9 ( & V_2 -> V_23 ) ;
return V_27 ;
}
static int F_28 ( struct V_61 * V_62 )
{
if ( ! strncmp ( V_62 -> V_63 , L_10 , 16 ) )
return 1 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned int V_64 ;
int V_65 ;
F_1 ( V_2 ) ;
F_21 ( V_2 ) ;
F_11 ( V_2 ) ;
for ( V_64 = 0 ; V_64 < F_30 ( V_66 ) ; ++ V_64 ) {
V_65 = F_31 ( V_2 -> V_67 ,
F_32 ( & V_66 [ V_64 ] , V_2 ) ) ;
if ( V_65 < 0 )
return V_65 ;
}
return 0 ;
}
