static int F_1 ( const struct V_1 * V_2 )
{
int V_3 = ! ! F_2 ( V_2 -> V_4 ) ;
int V_5 = ! ! F_2 ( V_2 -> V_6 ) ;
V_3 ^= V_2 -> V_7 ;
V_5 ^= V_2 -> V_8 ;
return ( ( V_3 << 1 ) | V_5 ) ;
}
static void F_3 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 -> V_11 ) {
F_4 ( V_10 -> V_12 ,
V_2 -> V_13 , V_10 -> V_14 ? - 1 : 1 ) ;
} else {
unsigned int V_15 = V_10 -> V_15 ;
if ( V_10 -> V_14 ) {
if ( V_2 -> V_16 )
V_15 += V_2 -> V_17 ;
if ( V_15 )
V_15 -- ;
} else {
if ( V_2 -> V_16 || V_15 < V_2 -> V_17 )
V_15 ++ ;
}
if ( V_2 -> V_16 )
V_15 %= V_2 -> V_17 ;
V_10 -> V_15 = V_15 ;
F_5 ( V_10 -> V_12 , V_2 -> V_13 , V_10 -> V_15 ) ;
}
F_6 ( V_10 -> V_12 ) ;
}
static T_1 F_7 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
switch ( V_20 ) {
case 0x0 :
if ( V_10 -> V_21 ) {
F_3 ( V_10 ) ;
V_10 -> V_21 = false ;
}
break;
case 0x1 :
case 0x2 :
if ( V_10 -> V_21 )
V_10 -> V_14 = V_20 - 1 ;
break;
case 0x3 :
V_10 -> V_21 = true ;
break;
}
return V_22 ;
}
static T_1 F_8 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
switch ( V_20 ) {
case 0x00 :
case 0x03 :
if ( V_20 != V_10 -> V_23 ) {
F_3 ( V_10 ) ;
V_10 -> V_23 = V_20 ;
}
break;
case 0x01 :
case 0x02 :
V_10 -> V_14 = ( V_10 -> V_23 + V_20 ) & 0x01 ;
break;
}
return V_22 ;
}
static T_1 F_9 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
unsigned char V_24 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
V_24 = ( V_10 -> V_23 << 4 ) + V_20 ;
switch ( V_24 ) {
case 0x31 :
case 0x10 :
case 0x02 :
case 0x23 :
V_10 -> V_14 = 0 ;
break;
case 0x13 :
case 0x01 :
case 0x20 :
case 0x32 :
V_10 -> V_14 = 1 ;
break;
default:
goto V_25;
}
F_3 ( V_10 ) ;
V_25:
V_10 -> V_23 = V_20 ;
return V_22 ;
}
static struct V_1 * F_10 ( struct V_26 * V_27 )
{
const struct V_28 * V_29 =
F_11 ( V_30 , V_27 ) ;
struct V_31 * V_32 = V_27 -> V_33 ;
struct V_1 * V_2 ;
enum V_34 V_35 ;
int error ;
if ( ! V_29 || ! V_32 )
return NULL ;
V_2 = F_12 ( sizeof( struct V_1 ) ,
V_36 ) ;
if ( ! V_2 )
return F_13 ( - V_37 ) ;
F_14 ( V_32 , L_1 , & V_2 -> V_17 ) ;
F_14 ( V_32 , L_2 , & V_2 -> V_13 ) ;
V_2 -> V_4 = F_15 ( V_32 , 0 , & V_35 ) ;
V_2 -> V_7 = V_35 & V_38 ;
V_2 -> V_6 = F_15 ( V_32 , 1 , & V_35 ) ;
V_2 -> V_8 = V_35 & V_38 ;
V_2 -> V_11 =
F_16 ( V_32 , L_3 ) ;
V_2 -> V_16 = F_16 ( V_32 , L_4 ) ;
error = F_14 ( V_32 , L_5 ,
& V_2 -> V_39 ) ;
if ( error ) {
if ( F_16 ( V_32 , L_6 ) ) {
V_2 -> V_39 = 2 ;
} else {
V_2 -> V_39 = 1 ;
}
}
V_2 -> V_40 = F_16 ( V_32 , L_7 ) ;
return V_2 ;
}
static inline struct V_1 *
F_10 ( struct V_26 * V_27 )
{
return NULL ;
}
static int F_17 ( struct V_41 * V_42 )
{
struct V_26 * V_27 = & V_42 -> V_27 ;
const struct V_1 * V_2 = F_18 ( V_27 ) ;
struct V_9 * V_10 ;
struct V_43 * V_12 ;
T_2 V_44 ;
int V_45 ;
if ( ! V_2 ) {
V_2 = F_10 ( V_27 ) ;
if ( F_19 ( V_2 ) )
return F_20 ( V_2 ) ;
if ( ! V_2 ) {
F_21 ( V_27 , L_8 ) ;
return - V_46 ;
}
}
V_10 = F_12 ( sizeof( struct V_9 ) , V_36 ) ;
V_12 = F_22 () ;
if ( ! V_10 || ! V_12 ) {
V_45 = - V_37 ;
goto V_47;
}
V_10 -> V_12 = V_12 ;
V_10 -> V_2 = V_2 ;
V_12 -> V_48 = V_42 -> V_48 ;
V_12 -> V_49 . V_50 = V_51 ;
V_12 -> V_27 . V_52 = V_27 ;
if ( V_2 -> V_11 ) {
V_12 -> V_53 [ 0 ] = F_23 ( V_54 ) ;
V_12 -> V_55 [ 0 ] = F_23 ( V_2 -> V_13 ) ;
} else {
V_12 -> V_53 [ 0 ] = F_23 ( V_56 ) ;
F_24 ( V_10 -> V_12 ,
V_2 -> V_13 , 0 , V_2 -> V_17 , 0 , 1 ) ;
}
V_45 = F_25 ( V_2 -> V_4 , V_57 , F_26 ( V_27 ) ) ;
if ( V_45 ) {
F_21 ( V_27 , L_9 , V_2 -> V_4 ) ;
goto V_47;
}
V_45 = F_25 ( V_2 -> V_6 , V_57 , F_26 ( V_27 ) ) ;
if ( V_45 ) {
F_21 ( V_27 , L_9 , V_2 -> V_6 ) ;
goto V_58;
}
V_10 -> V_59 = F_27 ( V_2 -> V_4 ) ;
V_10 -> V_60 = F_27 ( V_2 -> V_6 ) ;
switch ( V_2 -> V_39 ) {
case 4 :
V_44 = & F_9 ;
V_10 -> V_23 = F_1 ( V_2 ) ;
break;
case 2 :
V_44 = & F_8 ;
V_10 -> V_23 = F_1 ( V_2 ) ;
break;
case 1 :
V_44 = & F_7 ;
break;
default:
F_21 ( V_27 , L_10 ,
V_2 -> V_39 ) ;
V_45 = - V_46 ;
goto V_61;
}
V_45 = F_28 ( V_10 -> V_59 , V_44 ,
V_62 | V_63 ,
V_64 , V_10 ) ;
if ( V_45 ) {
F_21 ( V_27 , L_11 , V_10 -> V_59 ) ;
goto V_61;
}
V_45 = F_28 ( V_10 -> V_60 , V_44 ,
V_62 | V_63 ,
V_64 , V_10 ) ;
if ( V_45 ) {
F_21 ( V_27 , L_11 , V_10 -> V_60 ) ;
goto V_65;
}
V_45 = F_29 ( V_12 ) ;
if ( V_45 ) {
F_21 ( V_27 , L_12 ) ;
goto V_66;
}
F_30 ( & V_42 -> V_27 , V_2 -> V_40 ) ;
F_31 ( V_42 , V_10 ) ;
return 0 ;
V_66:
F_32 ( V_10 -> V_60 , V_10 ) ;
V_65:
F_32 ( V_10 -> V_59 , V_10 ) ;
V_61:
F_33 ( V_2 -> V_6 ) ;
V_58:
F_33 ( V_2 -> V_4 ) ;
V_47:
F_34 ( V_12 ) ;
F_35 ( V_10 ) ;
if ( ! F_18 ( & V_42 -> V_27 ) )
F_35 ( V_2 ) ;
return V_45 ;
}
static int F_36 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_37 ( V_42 ) ;
const struct V_1 * V_2 = V_10 -> V_2 ;
F_30 ( & V_42 -> V_27 , false ) ;
F_32 ( V_10 -> V_59 , V_10 ) ;
F_32 ( V_10 -> V_60 , V_10 ) ;
F_33 ( V_2 -> V_4 ) ;
F_33 ( V_2 -> V_6 ) ;
F_38 ( V_10 -> V_12 ) ;
F_35 ( V_10 ) ;
if ( ! F_18 ( & V_42 -> V_27 ) )
F_35 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_40 ( V_27 ) ;
if ( F_41 ( V_27 ) ) {
F_42 ( V_10 -> V_59 ) ;
F_42 ( V_10 -> V_60 ) ;
}
return 0 ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_40 ( V_27 ) ;
if ( F_41 ( V_27 ) ) {
F_44 ( V_10 -> V_59 ) ;
F_44 ( V_10 -> V_60 ) ;
}
return 0 ;
}
