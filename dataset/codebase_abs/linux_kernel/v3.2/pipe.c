char * F_1 ( struct V_1 * V_2 )
{
return V_3 [ F_2 ( V_2 ) ] ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_8 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 ) )
F_7 ( V_7 , V_9 , V_4 , V_5 ) ;
else
F_7 ( V_7 , V_10 + V_8 , V_4 , V_5 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_8 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return F_9 ( V_7 , V_9 ) ;
else
return F_9 ( V_7 , V_10 + V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_6 ( V_2 ) )
F_7 ( V_7 , V_11 , V_4 , V_5 ) ;
else
F_7 ( V_7 , V_12 , V_4 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , V_13 , V_14 , V_4 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
if ( F_6 ( V_2 ) )
return;
F_10 ( V_2 , 0 , V_15 , V_4 , V_5 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , V_16 , V_17 , V_4 , V_5 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_15 ( V_7 , V_18 , 0xF & F_16 ( V_2 ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_19 = 1024 ;
T_1 V_5 ;
F_15 ( V_7 , V_20 , 0 ) ;
F_18 ( V_2 ) ;
do {
V_5 = F_8 ( V_2 ) ;
V_5 &= V_21 | V_22 ;
if ( ! V_5 )
return 0 ;
F_19 ( 10 ) ;
} while ( V_19 -- );
return - V_23 ;
}
int F_20 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 & V_24 )
return 0 ;
return - V_23 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_25 = F_8 ( V_2 ) ;
V_25 &= V_22 ;
switch ( V_25 ) {
case V_26 :
F_3 ( V_2 , V_22 , V_27 ) ;
case V_27 :
F_3 ( V_2 , V_22 , V_28 ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
int V_19 = 1024 ;
T_1 V_5 ;
F_21 ( V_2 ) ;
F_3 ( V_2 , V_22 , V_28 ) ;
do {
V_5 = F_8 ( V_2 ) ;
V_5 &= V_29 ;
if ( ! V_5 )
break;
F_19 ( 10 ) ;
} while ( V_19 -- );
}
void F_22 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_3 ( V_2 , V_22 , V_30 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
T_1 V_25 = F_8 ( V_2 ) ;
V_25 &= V_22 ;
switch ( V_25 ) {
case V_28 :
F_3 ( V_2 , V_22 , V_27 ) ;
break;
case V_30 :
F_3 ( V_2 , V_22 , V_26 ) ;
break;
}
}
static int F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_31 ) ||
F_25 ( V_2 , V_32 ) )
return 1 ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
int V_33 ,
int V_34 )
{
T_1 type = 0 ;
T_1 V_35 = 0 ;
T_1 V_36 = 0 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
T_1 V_39 = 0 ;
T_1 V_40 = 0 ;
T_1 V_41 [] = {
[ V_31 ] = V_42 ,
[ V_43 ] = V_44 ,
[ V_32 ] = V_45 ,
} ;
int V_46 = F_24 ( V_2 ) ;
if ( F_6 ( V_2 ) )
return - V_47 ;
type = V_41 [ F_2 ( V_2 ) ] ;
if ( F_25 ( V_2 , V_32 ) ||
F_25 ( V_2 , V_31 ) )
V_35 = 0 ;
if ( F_25 ( V_2 , V_32 ) ||
F_25 ( V_2 , V_31 ) )
V_36 = ( V_46 ) ? V_48 : 0 ;
if ( F_25 ( V_2 , V_31 ) )
V_37 = 0 ;
if ( V_34 )
F_27 ( V_2 , V_49 ) ;
if ( ( V_33 && ! V_34 ) ||
( ! V_33 && V_34 ) )
V_38 |= V_50 ;
if ( ! V_38 )
F_27 ( V_2 , V_51 ) ;
if ( F_25 ( V_2 , V_31 ) &&
! V_38 )
V_40 = V_52 ;
V_39 = 0 ;
return type |
V_35 |
V_36 |
V_37 |
V_38 |
V_40 |
V_39 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_53 * V_54 = F_29 ( V_7 ) ;
struct V_55 * V_56 = F_30 ( V_7 ) ;
int V_57 = F_16 ( V_2 ) ;
int V_46 = F_24 ( V_2 ) ;
T_1 V_58 ;
T_1 V_59 ;
T_1 V_60 ;
if ( F_25 ( V_2 , V_61 ) )
V_58 = 256 ;
else if ( F_25 ( V_2 , V_43 ) )
V_58 = 64 ;
else
V_58 = 512 ;
V_60 = ( V_58 / 64 ) - 1 ;
if ( F_25 ( V_2 , V_43 ) ) {
V_59 = V_57 - 2 ;
} else {
V_59 = V_54 -> V_62 ;
V_54 -> V_62 += V_60 + 1 ;
if ( V_46 )
V_54 -> V_62 += V_60 + 1 ;
}
F_31 ( V_56 , L_1 ,
V_57 , V_58 , V_59 ) ;
return ( 0x1f & V_60 ) << 10 |
( 0xff & V_59 ) << 0 ;
}
void F_32 ( struct V_1 * V_2 , T_1 V_63 ,
T_1 V_39 , T_1 V_64 )
{
if ( V_63 > 0xA ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_55 * V_56 = F_30 ( V_7 ) ;
F_33 ( V_56 , L_2 , V_63 ) ;
V_63 = 0 ;
}
F_17 ( V_2 ) ;
V_2 -> V_64 = V_64 ;
F_14 ( V_2 ) ;
F_13 ( V_2 , 0xFFFF ,
( V_63 << 12 ) |
V_64 ) ;
if ( ! F_6 ( V_2 ) )
F_11 ( V_2 , 0x000F , V_39 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return V_2 -> V_64 ;
}
int F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_2 , V_51 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
return F_36 ( V_2 , V_49 ) ;
}
void F_38 ( struct V_1 * V_2 , int V_65 )
{
T_1 V_4 = ( V_66 | V_67 ) ;
T_1 V_5 = ( V_65 ) ? V_67 : V_66 ;
F_3 ( V_2 , V_4 , V_5 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_68 , V_68 ) ;
F_3 ( V_2 , V_68 , 0 ) ;
}
static struct V_1 * F_40 ( struct V_6 * V_7 , T_2 type )
{
struct V_1 * V_69 , * V_2 ;
int V_70 ;
V_2 = NULL ;
F_41 (pos, priv, i) {
if ( ! F_25 ( V_69 , type ) )
continue;
if ( F_36 ( V_69 , V_71 ) )
continue;
V_2 = V_69 ;
break;
}
if ( ! V_2 )
return NULL ;
F_42 ( V_2 ) ;
F_27 ( V_2 , V_71 ) ;
return V_2 ;
}
void F_43 ( struct V_6 * V_7 ,
int (* F_44)( struct V_72 * V_73 , int V_74 ) )
{
struct V_53 * V_54 = F_29 ( V_7 ) ;
struct V_1 * V_2 ;
int V_70 ;
V_54 -> V_62 = 4 ;
F_41 (pipe, priv, i) {
if ( F_25 ( V_2 , V_43 ) )
V_54 -> V_62 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_75 = NULL ;
V_2 -> V_76 = NULL ;
F_45 ( & V_2 -> V_77 ) ;
F_39 ( V_2 ) ;
}
V_54 -> F_44 = F_44 ;
}
struct V_1 * F_46 ( struct V_6 * V_7 ,
int V_78 ,
int V_34 )
{
struct V_55 * V_56 = F_30 ( V_7 ) ;
struct V_1 * V_2 ;
int V_33 = F_47 ( V_7 ) ;
int V_79 ;
T_1 V_80 , V_81 ;
V_2 = F_40 ( V_7 , V_78 ) ;
if ( ! V_2 ) {
F_33 ( V_56 , L_3 ,
V_3 [ V_78 ] ) ;
return NULL ;
}
F_45 ( & V_2 -> V_77 ) ;
F_18 ( V_2 ) ;
V_79 = F_17 ( V_2 ) ;
if ( V_79 < 0 ) {
F_33 ( V_56 , L_4 , F_16 ( V_2 ) ) ;
return NULL ;
}
V_80 = F_26 ( V_2 , V_33 , V_34 ) ;
V_81 = F_28 ( V_2 ) ;
F_14 ( V_2 ) ;
F_11 ( V_2 , 0xFFFF , V_80 ) ;
F_12 ( V_2 , 0xFFFF , V_81 ) ;
F_48 ( V_2 ) ;
F_31 ( V_56 , L_5 ,
F_16 ( V_2 ) ,
F_1 ( V_2 ) ,
F_35 ( V_2 ) ? L_6 : L_7 ) ;
return V_2 ;
}
void F_49 ( struct V_1 * V_2 , struct V_82 * V_75 )
{
if ( V_2 -> V_75 )
V_2 -> V_75 -> V_2 = NULL ;
V_2 -> V_75 = V_75 ;
if ( V_75 )
V_75 -> V_2 = V_2 ;
}
struct V_1 * F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_40 ( V_7 , V_61 ) ;
if ( ! V_2 )
return NULL ;
F_45 ( & V_2 -> V_77 ) ;
return V_2 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_52 ( ! F_6 ( V_2 ) ) ;
F_22 ( V_2 ) ;
if ( ! F_47 ( V_7 ) )
F_3 ( V_2 , V_83 , V_83 ) ;
}
void F_53 ( struct V_1 * V_2 , int V_84 )
{
F_11 ( V_2 , V_50 ,
V_84 ? V_50 : 0 ) ;
}
int F_54 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = F_29 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_55 * V_56 = F_30 ( V_7 ) ;
T_2 * V_85 = F_55 ( V_7 , V_85 ) ;
int V_86 = F_55 ( V_7 , V_86 ) ;
int V_70 ;
if ( V_85 [ 0 ] != V_61 ) {
F_33 ( V_56 , L_8 ) ;
return - V_47 ;
}
V_54 -> V_2 = F_56 ( sizeof( struct V_1 ) * V_86 , V_87 ) ;
if ( ! V_54 -> V_2 ) {
F_33 ( V_56 , L_9 ) ;
return - V_88 ;
}
V_54 -> V_89 = V_86 ;
F_41 (pipe, priv, i) {
V_2 -> V_7 = V_7 ;
F_2 ( V_2 ) =
V_85 [ V_70 ] & V_90 ;
F_31 ( V_56 , L_10 ,
V_70 , V_3 [ V_85 [ V_70 ] ] ) ;
}
return 0 ;
}
void F_57 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = F_29 ( V_7 ) ;
F_58 ( V_54 -> V_2 ) ;
}
