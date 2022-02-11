static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
F_3 ( & V_8 -> V_11 ) ;
V_8 -> V_12 -- ;
if ( V_8 -> V_12 < 0 ) {
F_4 ( V_10 , L_1 ) ;
V_8 -> V_12 = 0 ;
}
if ( ! V_8 -> V_12 )
V_8 -> V_13 = NULL ;
F_5 ( & V_8 -> V_11 ) ;
}
static int F_6 ( struct V_3 * V_4 , unsigned int V_14 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
V_14 &= V_15 ;
switch ( V_14 ) {
case V_16 :
case V_17 :
case V_18 :
V_8 -> V_14 = V_14 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static bool F_7 ( const struct V_20 * V_13 ,
int V_21 ,
unsigned int V_14 , unsigned int V_22 )
{
const struct V_23 * V_24 ;
V_24 = ( V_21 ) ? & V_13 -> V_25 : & V_13 -> V_26 ;
if ( V_24 -> V_14 != V_14 )
return false ;
if ( V_14 == V_16 ) {
if ( V_24 -> V_22 != V_22 )
return false ;
} else {
if ( V_24 -> V_22 < V_22 )
return false ;
}
return true ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
const struct V_20 * V_13 ;
struct V_9 * V_10 = V_6 -> V_10 ;
unsigned int V_22 = F_9 ( V_28 ) ;
unsigned int V_14 = V_8 -> V_14 ;
unsigned int V_29 ;
int V_21 = V_2 -> V_30 == V_31 ;
int V_32 , V_33 ;
T_1 V_34 , V_35 ;
V_29 = F_10 ( V_28 ) ;
switch ( V_29 ) {
case 32000 :
case 44100 :
case 48000 :
V_35 = V_36 ;
break;
case 88200 :
case 96000 :
V_35 = V_37 ;
break;
case 176400 :
case 192000 :
V_35 = V_38 ;
break;
default:
return - V_19 ;
}
V_34 = V_39 ;
V_33 = - V_19 ;
V_13 = NULL ;
F_3 ( & V_8 -> V_11 ) ;
if ( V_8 -> V_13 ) {
if ( F_7 ( V_8 -> V_13 , V_21 , V_14 , V_22 ) )
V_13 = V_8 -> V_13 ;
} else {
for ( V_32 = F_11 ( V_40 ) ; V_32 >= 0 ; V_32 -- ) {
if ( ! F_7 ( V_40 + V_32 ,
V_21 ,
V_14 , V_22 ) )
continue;
V_13 = V_40 + V_32 ;
break;
}
}
if ( ( V_8 -> V_13 == NULL ) ||
( V_8 -> V_13 == V_13 ) ) {
V_8 -> V_13 = V_13 ;
V_8 -> V_12 ++ ;
V_33 = 0 ;
}
F_5 ( & V_8 -> V_11 ) ;
if ( V_33 < 0 )
goto V_41;
V_34 = F_12 ( V_13 ) ;
F_13 ( V_6 , V_42 , V_43 , V_34 ) ;
F_13 ( V_6 , V_44 , V_45 , V_35 ) ;
F_14 ( V_6 , V_46 , V_8 -> V_47 ) ;
F_14 ( V_6 , V_48 , V_8 -> V_49 ) ;
V_41:
if ( V_33 < 0 )
F_15 ( V_10 , L_2 ) ;
return V_33 ;
}
static int F_16 ( struct V_5 * V_6 ,
enum V_50 V_51 )
{
T_1 V_52 = 0 ;
switch ( V_51 ) {
case V_53 :
V_52 |= V_54 ;
case V_55 :
V_52 |= V_56 | V_57 ;
case V_58 :
V_52 |= V_59 ;
case V_60 :
default:
break;
}
F_14 ( V_6 , V_61 , V_52 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_62 * V_62 = F_18 ( V_6 -> V_10 , NULL ) ;
F_19 ( V_62 , true ) ;
F_20 ( V_62 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_62 * V_62 = F_18 ( V_6 -> V_10 , NULL ) ;
F_19 ( V_62 , false ) ;
return F_22 ( V_62 ) ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_65 ;
char V_66 [ 32 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ ) {
snprintf ( V_66 , sizeof( V_66 ) , L_3 , V_32 + 1 ) ;
if ( ! F_24 ( V_64 , V_66 , NULL ) )
V_8 -> V_47 |= 1 << V_32 ;
}
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ ) {
snprintf ( V_66 , sizeof( V_66 ) , L_4 , V_32 + 1 ) ;
if ( ! F_24 ( V_64 , V_66 , NULL ) )
V_8 -> V_49 |= 1 << V_32 ;
}
}
static int F_25 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_9 * V_10 = & V_68 -> V_10 ;
struct V_63 * V_64 = V_10 -> V_65 ;
const struct V_71 * V_72 ;
struct V_62 * V_62 ;
struct V_7 * V_8 ;
V_72 = NULL ;
if ( V_64 ) {
const struct V_73 * V_74 ;
V_74 = F_26 ( V_75 , V_10 ) ;
if ( V_74 )
V_72 = V_74 -> V_76 ;
} else {
V_72 = ( const struct V_71 * ) V_70 -> V_77 ;
}
if ( ! V_72 )
return - V_19 ;
V_8 = F_27 ( V_10 , sizeof( * V_8 ) , V_78 ) ;
if ( ! V_8 )
return - V_79 ;
F_23 ( V_8 , V_10 ) ;
V_8 -> V_13 = NULL ;
V_8 -> V_12 = 0 ;
F_28 ( & V_8 -> V_11 ) ;
F_29 ( V_68 , V_8 ) ;
V_62 = F_30 ( V_68 , V_72 ) ;
if ( F_31 ( V_62 ) )
return F_32 ( V_62 ) ;
return F_33 ( V_10 , & V_80 ,
& V_81 , 1 ) ;
}
static int F_34 ( struct V_67 * V_82 )
{
F_35 ( & V_82 -> V_10 ) ;
return 0 ;
}
