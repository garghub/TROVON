static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = ( V_2 -> V_6 >> 24 ) & 0xff ;
V_4 -> type = V_5 == 1 ? V_7 : V_8 ;
V_4 -> V_9 = 1 ;
V_4 -> V_10 . integer . V_11 = 0 ;
V_4 -> V_10 . integer . V_12 = V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_17 = V_2 -> V_6 & 0xff ;
int V_18 = ( V_2 -> V_6 >> 16 ) & 0x07 ;
int V_5 = ( V_2 -> V_6 >> 24 ) & 0xff ;
int V_19 = ( V_2 -> V_6 >> 22 ) & 1 ;
int V_20 ;
F_4 ( & V_16 -> V_21 ) ;
V_20 = ( V_16 -> V_22 [ V_17 ] >> V_18 ) & V_5 ;
F_5 ( & V_16 -> V_21 ) ;
if ( V_19 ) {
V_20 = V_5 - V_20 ;
}
V_14 -> V_10 . integer . V_10 [ 0 ] = V_20 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_17 = V_2 -> V_6 & 0xff ;
int V_18 = ( V_2 -> V_6 >> 16 ) & 0x07 ;
int V_5 = ( V_2 -> V_6 >> 24 ) & 0xff ;
int V_19 = ( V_2 -> V_6 >> 22 ) & 1 ;
int V_23 ;
int V_20 ;
V_20 = V_14 -> V_10 . integer . V_10 [ 0 ] & V_5 ;
if ( V_19 ) {
V_20 = V_5 - V_20 ;
}
V_20 <<= V_18 ;
F_4 ( & V_16 -> V_21 ) ;
V_20 = ( V_16 -> V_22 [ V_17 ] & ~ ( V_5 << V_18 ) ) | V_20 ;
V_23 = V_20 != V_16 -> V_22 [ V_17 ] ;
V_16 -> V_24 ( V_16 , V_17 , V_16 -> V_22 [ V_17 ] = V_20 ) ;
F_5 ( & V_16 -> V_21 ) ;
return V_23 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = ( V_2 -> V_6 >> 24 ) & 0xff ;
V_4 -> type = V_5 == 1 ? V_7 : V_8 ;
V_4 -> V_9 = 2 ;
V_4 -> V_10 . integer . V_11 = 0 ;
V_4 -> V_10 . integer . V_12 = V_5 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_25 = V_2 -> V_6 & 0xff ;
int V_26 = ( V_2 -> V_6 >> 8 ) & 0xff ;
int V_27 = ( V_2 -> V_6 >> 16 ) & 0x07 ;
int V_28 = ( V_2 -> V_6 >> 19 ) & 0x07 ;
int V_5 = ( V_2 -> V_6 >> 24 ) & 0xff ;
int V_19 = ( V_2 -> V_6 >> 22 ) & 1 ;
int V_29 , V_30 ;
F_4 ( & V_16 -> V_21 ) ;
V_29 = ( V_16 -> V_22 [ V_25 ] >> V_27 ) & V_5 ;
V_30 = ( V_16 -> V_22 [ V_26 ] >> V_28 ) & V_5 ;
F_5 ( & V_16 -> V_21 ) ;
if ( V_19 ) {
V_29 = V_5 - V_29 ;
V_30 = V_5 - V_30 ;
}
V_14 -> V_10 . integer . V_10 [ 0 ] = V_29 ;
V_14 -> V_10 . integer . V_10 [ 1 ] = V_30 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_25 = V_2 -> V_6 & 0xff ;
int V_26 = ( V_2 -> V_6 >> 8 ) & 0xff ;
int V_27 = ( V_2 -> V_6 >> 16 ) & 0x07 ;
int V_28 = ( V_2 -> V_6 >> 19 ) & 0x07 ;
int V_5 = ( V_2 -> V_6 >> 24 ) & 0xff ;
int V_19 = ( V_2 -> V_6 >> 22 ) & 1 ;
int V_23 ;
int V_29 , V_30 ;
V_29 = V_14 -> V_10 . integer . V_10 [ 0 ] & V_5 ;
V_30 = V_14 -> V_10 . integer . V_10 [ 1 ] & V_5 ;
if ( V_19 ) {
V_29 = V_5 - V_29 ;
V_30 = V_5 - V_30 ;
}
V_29 <<= V_27 ;
V_30 <<= V_28 ;
F_4 ( & V_16 -> V_21 ) ;
if ( V_25 == V_26 ) {
V_29 = ( V_16 -> V_22 [ V_25 ] & ~ ( ( V_5 << V_27 ) | ( V_5 << V_28 ) ) ) | V_29 | V_30 ;
V_23 = V_29 != V_16 -> V_22 [ V_25 ] ;
V_16 -> V_24 ( V_16 , V_25 , V_16 -> V_22 [ V_25 ] = V_29 ) ;
} else {
V_29 = ( V_16 -> V_22 [ V_25 ] & ~ ( V_5 << V_27 ) ) | V_29 ;
V_30 = ( V_16 -> V_22 [ V_26 ] & ~ ( V_5 << V_28 ) ) | V_30 ;
V_23 = V_29 != V_16 -> V_22 [ V_25 ] || V_30 != V_16 -> V_22 [ V_26 ] ;
V_16 -> V_24 ( V_16 , V_25 , V_16 -> V_22 [ V_25 ] = V_29 ) ;
V_16 -> V_24 ( V_16 , V_26 , V_16 -> V_22 [ V_26 ] = V_30 ) ;
}
F_5 ( & V_16 -> V_21 ) ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_7 ;
V_4 -> V_9 = 4 ;
V_4 -> V_10 . integer . V_11 = 0 ;
V_4 -> V_10 . integer . V_12 = 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_31 = V_2 -> V_6 & 0xff ;
int V_32 = ( V_2 -> V_6 >> 8 ) & 0xff ;
int V_27 = ( V_2 -> V_6 >> 16 ) & 0x0f ;
int V_28 = ( V_2 -> V_6 >> 24 ) & 0x0f ;
F_4 ( & V_16 -> V_21 ) ;
V_14 -> V_10 . integer . V_10 [ 0 ] = ( V_16 -> V_22 [ V_31 ] >> V_27 ) & 1 ;
V_14 -> V_10 . integer . V_10 [ 1 ] = ( V_16 -> V_22 [ V_32 ] >> V_27 ) & 1 ;
V_14 -> V_10 . integer . V_10 [ 2 ] = ( V_16 -> V_22 [ V_31 ] >> V_28 ) & 1 ;
V_14 -> V_10 . integer . V_10 [ 3 ] = ( V_16 -> V_22 [ V_32 ] >> V_28 ) & 1 ;
F_5 ( & V_16 -> V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
int V_31 = V_2 -> V_6 & 0xff ;
int V_32 = ( V_2 -> V_6 >> 8 ) & 0xff ;
int V_27 = ( V_2 -> V_6 >> 16 ) & 0x0f ;
int V_28 = ( V_2 -> V_6 >> 24 ) & 0x0f ;
int V_23 ;
int V_33 , V_34 ;
F_4 ( & V_16 -> V_21 ) ;
V_33 = V_16 -> V_22 [ V_31 ] & ~ ( ( 1 << V_27 ) | ( 1 << V_28 ) ) ;
V_34 = V_16 -> V_22 [ V_32 ] & ~ ( ( 1 << V_27 ) | ( 1 << V_28 ) ) ;
V_33 |= ( V_14 -> V_10 . integer . V_10 [ 0 ] & 1 ) << V_27 ;
V_34 |= ( V_14 -> V_10 . integer . V_10 [ 1 ] & 1 ) << V_27 ;
V_33 |= ( V_14 -> V_10 . integer . V_10 [ 2 ] & 1 ) << V_28 ;
V_34 |= ( V_14 -> V_10 . integer . V_10 [ 3 ] & 1 ) << V_28 ;
V_23 = V_33 != V_16 -> V_22 [ V_31 ] || V_34 != V_16 -> V_22 [ V_32 ] ;
V_16 -> V_24 ( V_16 , V_31 , V_16 -> V_22 [ V_31 ] = V_33 ) ;
V_16 -> V_24 ( V_16 , V_32 , V_16 -> V_22 [ V_32 ] = V_34 ) ;
F_5 ( & V_16 -> V_21 ) ;
return V_23 ;
}
static int F_13 ( struct V_15 * V_16 )
{
if ( V_16 ) {
if ( V_16 -> V_35 )
V_16 -> V_35 ( V_16 ) ;
F_14 ( V_16 ) ;
}
return 0 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_38 ;
return F_13 ( V_16 ) ;
}
int F_16 ( struct V_39 * V_40 ,
struct V_15 * V_41 ,
struct V_15 * * V_42 )
{
unsigned int V_43 ;
int V_44 ;
struct V_15 * V_16 ;
static struct V_45 V_46 = {
. V_47 = F_15 ,
} ;
if ( F_17 ( ! V_40 || ! V_41 ) )
return - V_48 ;
if ( V_42 )
* V_42 = NULL ;
V_16 = F_18 ( sizeof( * V_16 ) , V_49 ) ;
if ( V_16 == NULL )
return - V_50 ;
* V_16 = * V_41 ;
F_19 ( & V_16 -> V_21 ) ;
if ( ( V_44 = F_20 ( V_40 , L_1 ) ) < 0 ) {
F_13 ( V_16 ) ;
return V_44 ;
}
strcpy ( V_40 -> V_51 , L_2 ) ;
V_16 -> V_24 ( V_16 , V_52 , 0x03 ) ;
F_21 ( 100 ) ;
V_16 -> V_24 ( V_16 , V_53 , 0x00 ) ;
for ( V_43 = 0 ; V_43 <= 0x19 ; V_43 ++ ) {
if ( V_43 == V_52 || V_43 == V_53 )
continue;
V_16 -> V_24 ( V_16 , V_43 , V_16 -> V_22 [ V_43 ] = V_54 [ V_43 ] ) ;
}
for ( V_43 = 0 ; V_43 < F_22 ( V_55 ) ; V_43 ++ ) {
if ( ( V_44 = F_23 ( V_40 , F_24 ( & V_55 [ V_43 ] , V_16 ) ) ) < 0 ) {
F_13 ( V_16 ) ;
return V_44 ;
}
}
F_25 ( V_40 , V_16 ) ;
if ( ( V_44 = F_26 ( V_40 , V_56 , V_16 , & V_46 ) ) < 0 ) {
F_13 ( V_16 ) ;
return V_44 ;
}
#if 0
snd_ak4531_dump(ak4531);
#endif
if ( V_42 )
* V_42 = V_16 ;
return 0 ;
}
void F_27 ( struct V_15 * V_16 )
{
V_16 -> V_24 ( V_16 , V_57 , 0x9f ) ;
V_16 -> V_24 ( V_16 , V_58 , 0x9f ) ;
V_16 -> V_24 ( V_16 , V_52 , 0x01 ) ;
}
void F_28 ( struct V_15 * V_16 )
{
int V_43 ;
V_16 -> V_24 ( V_16 , V_52 , 0x03 ) ;
F_21 ( 100 ) ;
V_16 -> V_24 ( V_16 , V_53 , 0x00 ) ;
for ( V_43 = 0 ; V_43 <= 0x19 ; V_43 ++ ) {
if ( V_43 == V_52 || V_43 == V_53 )
continue;
V_16 -> V_24 ( V_16 , V_43 , V_16 -> V_22 [ V_43 ] ) ;
}
}
static void F_29 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_15 * V_16 = V_60 -> V_63 ;
F_30 ( V_62 , L_3 ) ;
F_30 ( V_62 , L_4
L_5 ,
V_16 -> V_22 [ V_64 ] & 1 ? L_6 : L_7 ,
V_16 -> V_22 [ V_65 ] & 1 ? L_8 : L_9 ) ;
}
static void
F_25 ( struct V_39 * V_40 , struct V_15 * V_16 )
{
struct V_59 * V_60 ;
if ( ! F_31 ( V_40 , L_10 , & V_60 ) )
F_32 ( V_60 , V_16 , F_29 ) ;
}
