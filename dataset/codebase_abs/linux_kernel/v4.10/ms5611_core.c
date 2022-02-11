static bool F_1 ( T_1 * V_1 , T_2 V_2 )
{
int V_3 , V_4 ;
T_3 V_5 = 0 , V_6 = V_1 [ 7 ] & 0x000F ;
V_1 [ 7 ] &= 0xFF00 ;
for ( V_3 = 0 ; V_3 < V_2 * 2 ; V_3 ++ ) {
if ( V_3 % 2 == 1 )
V_5 ^= V_1 [ V_3 >> 1 ] & 0x00FF ;
else
V_5 ^= V_1 [ V_3 >> 1 ] >> 8 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
if ( V_5 & 0x8000 )
V_5 = ( V_5 << 1 ) ^ 0x3000 ;
else
V_5 <<= 1 ;
}
}
V_5 = ( V_5 >> 12 ) & 0x000F ;
return V_6 != 0x0000 && V_5 == V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
int V_9 , V_3 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
V_9 = V_11 -> V_13 ( & V_8 -> V_14 ,
V_3 , & V_11 -> V_15 -> V_1 [ V_3 ] ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_14 ,
L_1 , V_3 ) ;
return V_9 ;
}
}
if ( ! F_1 ( V_11 -> V_15 -> V_1 , V_12 ) ) {
F_4 ( & V_8 -> V_14 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_7 * V_8 ,
T_4 * V_17 , T_4 * V_18 )
{
int V_9 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
V_9 = V_11 -> V_19 ( & V_8 -> V_14 , V_17 , V_18 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_14 ,
L_3 ) ;
return V_9 ;
}
return V_11 -> V_15 -> V_20 ( V_11 -> V_15 ,
V_17 , V_18 ) ;
}
static int F_6 ( struct V_21 * V_15 ,
T_4 * V_17 , T_4 * V_18 )
{
T_4 V_22 = * V_17 , V_23 = * V_18 ;
T_5 V_24 , V_25 , V_26 ;
V_26 = V_22 - ( V_15 -> V_1 [ 5 ] << 8 ) ;
V_24 = ( ( T_5 ) V_15 -> V_1 [ 2 ] << 16 ) + ( ( V_15 -> V_1 [ 4 ] * V_26 ) >> 7 ) ;
V_25 = ( ( T_5 ) V_15 -> V_1 [ 1 ] << 15 ) + ( ( V_15 -> V_1 [ 3 ] * V_26 ) >> 8 ) ;
V_22 = 2000 + ( ( V_15 -> V_1 [ 6 ] * V_26 ) >> 23 ) ;
if ( V_22 < 2000 ) {
T_5 V_27 , V_28 , V_29 ;
V_29 = ( V_26 * V_26 ) >> 31 ;
V_27 = ( 5 * ( V_22 - 2000 ) * ( V_22 - 2000 ) ) >> 1 ;
V_28 = V_27 >> 1 ;
if ( V_22 < - 1500 ) {
T_5 V_30 = ( V_22 + 1500 ) * ( V_22 + 1500 ) ;
V_27 += 7 * V_30 ;
V_28 += ( 11 * V_30 ) >> 1 ;
}
V_22 -= V_29 ;
V_24 -= V_27 ;
V_25 -= V_28 ;
}
* V_17 = V_22 ;
* V_18 = ( ( ( V_23 * V_25 ) >> 21 ) - V_24 ) >> 15 ;
return 0 ;
}
static int F_7 ( struct V_21 * V_15 ,
T_4 * V_17 , T_4 * V_18 )
{
T_4 V_22 = * V_17 , V_23 = * V_18 ;
T_5 V_24 , V_25 , V_26 ;
V_26 = V_22 - ( V_15 -> V_1 [ 5 ] << 8 ) ;
V_24 = ( ( T_5 ) V_15 -> V_1 [ 2 ] << 17 ) + ( ( V_15 -> V_1 [ 4 ] * V_26 ) >> 6 ) ;
V_25 = ( ( T_5 ) V_15 -> V_1 [ 1 ] << 16 ) + ( ( V_15 -> V_1 [ 3 ] * V_26 ) >> 7 ) ;
V_22 = 2000 + ( ( V_15 -> V_1 [ 6 ] * V_26 ) >> 23 ) ;
if ( V_22 < 2000 ) {
T_5 V_27 , V_28 , V_29 , V_30 ;
V_29 = ( V_26 * V_26 ) >> 31 ;
V_30 = ( V_22 - 2000 ) * ( V_22 - 2000 ) ;
V_27 = ( 61 * V_30 ) >> 4 ;
V_28 = V_30 << 1 ;
if ( V_22 < - 1500 ) {
V_30 = ( V_22 + 1500 ) * ( V_22 + 1500 ) ;
V_27 += 15 * V_30 ;
V_28 += 8 * V_30 ;
}
V_22 -= V_29 ;
V_24 -= V_27 ;
V_25 -= V_28 ;
}
* V_17 = V_22 ;
* V_18 = ( ( ( V_23 * V_25 ) >> 21 ) - V_24 ) >> 15 ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
int V_9 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
V_9 = V_11 -> V_31 ( & V_8 -> V_14 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_14 , L_4 ) ;
return V_9 ;
}
F_9 ( 3000 , 4000 ) ;
return 0 ;
}
static T_6 F_10 ( int V_32 , void * V_23 )
{
struct V_33 * V_34 = V_23 ;
struct V_7 * V_8 = V_34 -> V_8 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
T_4 V_35 [ 4 ] ;
int V_9 ;
F_11 ( & V_11 -> V_36 ) ;
V_9 = F_5 ( V_8 , & V_35 [ 1 ] , & V_35 [ 0 ] ) ;
F_12 ( & V_11 -> V_36 ) ;
if ( V_9 < 0 )
goto V_37;
F_13 ( V_8 , V_35 ,
F_14 ( V_8 ) ) ;
V_37:
F_15 ( V_8 -> V_38 ) ;
return V_39 ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_40 const * V_41 ,
int * V_42 , int * V_43 , long V_44 )
{
int V_9 ;
T_4 V_17 , V_18 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
switch ( V_44 ) {
case V_45 :
F_11 ( & V_11 -> V_36 ) ;
V_9 = F_5 ( V_8 ,
& V_17 , & V_18 ) ;
F_12 ( & V_11 -> V_36 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_41 -> type ) {
case V_46 :
* V_42 = V_17 * 10 ;
return V_47 ;
case V_48 :
* V_42 = V_18 / 1000 ;
* V_43 = ( V_18 % 1000 ) * 1000 ;
return V_49 ;
default:
return - V_50 ;
}
case V_51 :
switch ( V_41 -> type ) {
case V_46 :
* V_42 = 10 ;
return V_47 ;
case V_48 :
* V_42 = 0 ;
* V_43 = 1000 ;
return V_49 ;
default:
return - V_50 ;
}
case V_52 :
if ( V_41 -> type != V_46 && V_41 -> type != V_48 )
break;
F_11 ( & V_11 -> V_36 ) ;
if ( V_41 -> type == V_46 )
* V_42 = ( int ) V_11 -> V_53 -> V_54 ;
else
* V_42 = ( int ) V_11 -> V_55 -> V_54 ;
F_12 ( & V_11 -> V_36 ) ;
return V_47 ;
}
return - V_50 ;
}
static const struct V_56 * F_17 ( int V_54 ,
const struct V_56 * V_57 ,
T_2 V_58 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ )
if ( ( unsigned short ) V_54 == V_57 [ V_59 ] . V_54 )
break;
if ( V_59 >= V_58 )
return NULL ;
return & V_57 [ V_59 ] ;
}
static int F_18 ( struct V_7 * V_8 ,
struct V_40 const * V_41 ,
int V_42 , int V_43 , long V_44 )
{
struct V_10 * V_11 = F_3 ( V_8 ) ;
const struct V_56 * V_57 = NULL ;
if ( V_44 != V_52 )
return - V_50 ;
if ( V_41 -> type == V_46 )
V_57 = F_17 ( V_42 , V_60 ,
F_19 ( V_60 ) ) ;
else if ( V_41 -> type == V_48 )
V_57 = F_17 ( V_42 , V_61 ,
F_19 ( V_61 ) ) ;
if ( ! V_57 )
return - V_50 ;
F_11 ( & V_11 -> V_36 ) ;
if ( F_20 ( V_8 ) ) {
F_12 ( & V_11 -> V_36 ) ;
return - V_62 ;
}
if ( V_41 -> type == V_46 )
V_11 -> V_53 = V_57 ;
else
V_11 -> V_55 = V_57 ;
F_12 ( & V_11 -> V_36 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 )
{
int V_9 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
V_11 -> V_63 = F_22 ( V_8 -> V_14 . V_64 , L_5 ) ;
if ( F_23 ( V_11 -> V_63 ) )
return F_24 ( V_11 -> V_63 ) ;
V_9 = F_25 ( V_11 -> V_63 ) ;
if ( V_9 ) {
F_4 ( V_8 -> V_14 . V_64 ,
L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_8 ( V_8 ) ;
if ( V_9 < 0 )
goto V_65;
V_9 = F_2 ( V_8 ) ;
if ( V_9 < 0 )
goto V_65;
return 0 ;
V_65:
F_26 ( V_11 -> V_63 ) ;
return V_9 ;
}
static void F_27 ( const struct V_7 * V_8 )
{
const struct V_10 * V_11 = F_3 ( V_8 ) ;
F_26 ( V_11 -> V_63 ) ;
}
int F_28 ( struct V_7 * V_8 , struct V_66 * V_14 ,
const char * V_67 , int type )
{
int V_9 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
F_29 ( & V_11 -> V_36 ) ;
V_11 -> V_15 = & V_68 [ type ] ;
V_11 -> V_53 =
& V_60 [ F_19 ( V_60 ) - 1 ] ;
V_11 -> V_55 =
& V_61 [ F_19 ( V_61 )
- 1 ] ;
V_8 -> V_14 . V_64 = V_14 ;
V_8 -> V_67 = V_67 ;
V_8 -> V_69 = & V_70 ;
V_8 -> V_71 = V_72 ;
V_8 -> V_73 = F_19 ( V_72 ) ;
V_8 -> V_74 = V_75 ;
V_8 -> V_76 = V_77 ;
V_9 = F_21 ( V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_30 ( V_8 , NULL ,
F_10 , NULL ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 , L_7 ) ;
goto V_78;
}
V_9 = F_31 ( V_8 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 , L_8 ) ;
goto V_79;
}
return 0 ;
V_79:
F_32 ( V_8 ) ;
V_78:
F_27 ( V_8 ) ;
return V_9 ;
}
int F_33 ( struct V_7 * V_8 )
{
F_34 ( V_8 ) ;
F_32 ( V_8 ) ;
F_27 ( V_8 ) ;
return 0 ;
}
