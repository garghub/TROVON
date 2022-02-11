bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( V_4 -> V_6 >= V_7 )
return true ;
return false ;
}
T_1 F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
return V_4 -> V_8 ;
}
bool F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_9 * V_10 ;
if ( ! V_2 -> V_5 . V_11 )
return true ;
V_10 = V_4 -> V_10 + V_4 -> V_6 ;
return V_10 -> V_12 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
T_2 V_13 = V_2 -> V_14 ;
bool V_15 = false ;
if ( ! V_2 -> V_5 . V_11 )
V_15 = ( ( V_13 + V_16 ) >=
V_17 ) ? true : false ;
else
V_15 = ( ( V_13 + V_16 ) >=
V_18 ) ? true : false ;
return V_15 ;
}
bool F_5 ( struct V_1 * V_2 )
{
bool V_19 = false ;
if ( F_4 ( V_2 ) ) {
F_6 ( V_2 ) ;
V_19 = true ;
}
return V_19 ;
}
enum V_20 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_9 * V_10 ;
if ( ! V_2 -> V_5 . V_11 )
return V_21 ;
V_10 = V_4 -> V_10 + V_4 -> V_6 ;
return V_10 -> V_22 ;
}
enum V_20 F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_9 * V_10 ;
if ( ! V_2 -> V_5 . V_11 )
return V_21 ;
V_10 = V_4 -> V_10 + V_4 -> V_6 ;
return V_10 -> V_23 ;
}
static void F_9 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
unsigned long V_25 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( V_4 -> V_6 == V_28 ) {
if ( V_2 -> V_5 . V_29 ) {
F_11 ( V_2 -> V_30 , V_31 ,
V_32 ) ;
V_2 -> V_5 . V_29 = false ;
} else {
F_11 ( V_2 -> V_30 , V_33 ,
V_32 ) ;
V_2 -> V_5 . V_29 = true ;
}
F_12 ( V_2 -> V_30 , V_34 ) ;
if ( F_13 ( V_2 -> V_30 , false , & V_25 ) )
F_14 ( V_2 -> V_30 , & V_25 ) ;
F_15 ( V_2 , L_1 ) ;
F_16 ( & V_2 -> V_5 . V_35 ,
V_36 + V_37 * V_38 ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
bool V_39 )
{
if ( V_39 ) {
F_15 ( V_2 , L_2 ) ;
if ( V_2 -> V_40 )
F_18 ( V_2 -> V_41 ) ;
F_15 ( V_2 ,
L_3 ) ;
F_16 ( & V_2 -> V_5 . V_35 ,
V_36 + V_37 * V_38 ) ;
} else {
F_15 ( V_2 , L_4 ) ;
if ( V_2 -> V_40 )
F_19 ( V_2 -> V_41 ) ;
}
}
static void F_20 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( V_4 -> V_6 != V_28 ) {
F_15 ( V_2 , L_5
L_6 ) ;
V_4 -> V_6 = V_28 ;
F_21 ( V_42 , & V_2 -> V_27 ) ;
F_17 ( V_2 , true ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
F_15 ( V_2 , L_7 ) ;
F_23 ( V_2 , V_43 , false ) ;
F_16 ( & V_2 -> V_5 . V_44 ,
V_36 + F_24 ( V_45 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_13 , bool V_46 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
enum V_47 V_48 ;
#ifdef F_26
if ( ( V_4 -> V_49 ) &&
( V_13 > V_4 -> V_49 ) &&
( ( V_13 - V_4 -> V_49 ) >
V_50 ) ) {
F_15 ( V_2 ,
L_8 ,
( V_13 - V_4 -> V_49 ) ) ;
}
#endif
V_48 = V_4 -> V_6 ;
if ( V_13 >= V_51 )
V_4 -> V_6 = V_28 ;
else if ( V_13 >= V_52 )
V_4 -> V_6 = V_53 ;
else if ( V_13 >= V_54 )
V_4 -> V_6 = V_7 ;
else
V_4 -> V_6 = V_55 ;
#ifdef F_26
V_4 -> V_49 = V_13 ;
#endif
F_27 ( & V_2 -> V_5 . V_44 ) ;
if ( V_4 -> V_6 != V_48 ) {
switch ( V_4 -> V_6 ) {
case V_55 :
break;
case V_7 :
V_4 -> V_8 = V_56 ;
break;
case V_53 :
V_4 -> V_8 = V_57 ;
break;
default:
V_4 -> V_8 = V_58 ;
break;
}
F_28 ( & V_2 -> V_59 ) ;
if ( V_48 == V_28 )
F_29 ( V_42 , & V_2 -> V_27 ) ;
if ( V_4 -> V_6 != V_28 &&
F_30 ( V_2 , true ) ) {
if ( V_48 == V_28 )
F_21 ( V_42 , & V_2 -> V_27 ) ;
V_4 -> V_6 = V_48 ;
F_31 ( V_2 , L_9
L_10 ) ;
} else {
if ( V_4 -> V_6 == V_28 ) {
if ( V_46 ) {
F_21 ( V_42 , & V_2 -> V_27 ) ;
F_17 ( V_2 , true ) ;
} else {
F_22 ( V_2 ) ;
V_4 -> V_6 = V_48 ;
}
} else if ( V_48 == V_28 &&
V_4 -> V_6 != V_28 )
F_17 ( V_2 , false ) ;
F_15 ( V_2 , L_11 ,
V_4 -> V_6 ) ;
F_15 ( V_2 , L_12 ,
V_4 -> V_8 ) ;
}
F_32 ( & V_2 -> V_59 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , T_2 V_13 , bool V_46 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_60 ;
bool V_61 = false ;
enum V_47 V_48 ;
struct V_62 * V_63 ;
V_48 = V_4 -> V_6 ;
for ( V_60 = 0 ; V_60 < V_64 - 1 ; V_60 ++ ) {
V_63 = V_4 -> V_63 +
( ( V_48 * ( V_64 - 1 ) ) + V_60 ) ;
if ( V_13 >= V_63 -> V_65 &&
V_13 <= V_63 -> V_66 ) {
#ifdef F_26
if ( ( V_4 -> V_49 ) &&
( V_13 > V_4 -> V_49 ) &&
( ( V_13 - V_4 -> V_49 ) >
V_50 ) ) {
F_15 ( V_2 ,
L_13
L_14 ,
( V_13 - V_4 -> V_49 ) ) ;
}
V_4 -> V_49 = V_13 ;
#endif
if ( V_48 !=
V_63 -> V_67 ) {
V_61 = true ;
V_4 -> V_6 =
V_63 -> V_67 ;
}
break;
}
}
F_27 ( & V_2 -> V_5 . V_44 ) ;
if ( V_61 ) {
if ( V_4 -> V_6 >= V_7 ) {
V_4 -> V_8 = V_58 ;
if ( ! F_3 ( V_2 ) ) {
struct V_68 * V_69 ;
F_34 (priv, ctx) {
struct V_70 * V_71 ;
V_71 = & V_69 -> V_72 ;
V_71 -> V_25 &= ~ (
V_73 |
V_74 |
V_75 |
V_76 ) ;
}
} else {
F_35 ( V_2 , & V_2 -> V_77 ) ;
}
} else {
F_35 ( V_2 , & V_2 -> V_77 ) ;
}
F_28 ( & V_2 -> V_59 ) ;
if ( V_48 == V_28 )
F_29 ( V_42 , & V_2 -> V_27 ) ;
if ( V_4 -> V_6 != V_28 &&
F_30 ( V_2 , true ) ) {
F_31 ( V_2 , L_9
L_10 ) ;
if ( V_48 == V_28 )
F_21 ( V_42 , & V_2 -> V_27 ) ;
V_4 -> V_6 = V_48 ;
} else {
F_15 ( V_2 ,
L_15 ,
V_4 -> V_6 ) ;
if ( V_48 != V_28 &&
V_4 -> V_6 == V_28 ) {
if ( V_46 ) {
F_15 ( V_2 ,
L_16 ) ;
F_21 ( V_42 , & V_2 -> V_27 ) ;
F_17 ( V_2 , true ) ;
} else {
V_4 -> V_6 = V_48 ;
F_22 ( V_2 ) ;
}
} else if ( V_48 == V_28 &&
V_4 -> V_6 != V_28 ) {
F_15 ( V_2 , L_17 ) ;
F_17 ( V_2 , false ) ;
}
}
F_32 ( & V_2 -> V_59 ) ;
}
}
static void F_36 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_37 ( V_79 , struct V_1 , V_80 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( ! F_38 ( V_2 ) )
return;
if ( V_4 -> V_6 != V_28 ) {
F_31 ( V_2 , L_18
L_19 ) ;
if ( ! V_2 -> V_5 . V_11 )
F_25 ( V_2 ,
V_51 ,
true ) ;
else
F_33 ( V_2 ,
V_18 + 1 , true ) ;
}
}
static void F_39 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_37 ( V_79 , struct V_1 , V_81 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( ! F_38 ( V_2 ) )
return;
F_27 ( & V_2 -> V_5 . V_35 ) ;
if ( V_4 -> V_6 == V_28 ) {
F_31 ( V_2 ,
L_20
L_21 ) ;
V_2 -> V_14 = 0 ;
if ( ! V_2 -> V_5 . V_11 )
F_25 ( V_2 ,
V_52 ,
true ) ;
else
F_33 ( V_2 , V_82 ,
true ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
F_15 ( V_2 , L_22 ) ;
F_40 ( V_2 -> V_83 , & V_2 -> V_80 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
F_15 ( V_2 , L_23 ) ;
F_40 ( V_2 -> V_83 , & V_2 -> V_81 ) ;
}
static void F_42 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_37 ( V_79 , struct V_1 , V_84 ) ;
T_2 V_13 = V_2 -> V_14 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( ! V_2 -> V_5 . V_11 )
F_25 ( V_2 , V_13 , false ) ;
else
F_33 ( V_2 , V_13 , false ) ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
F_15 ( V_2 , L_24 ) ;
F_40 ( V_2 -> V_83 , & V_2 -> V_84 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_85 = sizeof( struct V_62 ) * ( V_64 - 1 ) ;
struct V_62 * V_63 ;
F_15 ( V_2 , L_25 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_6 = V_55 ;
F_45 ( & V_2 -> V_5 . V_35 ) ;
V_2 -> V_5 . V_35 . V_24 = ( unsigned long ) V_2 ;
V_2 -> V_5 . V_35 . V_86 =
F_9 ;
F_45 ( & V_2 -> V_5 . V_44 ) ;
V_2 -> V_5 . V_44 . V_24 =
( unsigned long ) V_2 ;
V_2 -> V_5 . V_44 . V_86 =
F_20 ;
F_46 ( & V_2 -> V_84 , F_42 ) ;
F_46 ( & V_2 -> V_80 , F_36 ) ;
F_46 ( & V_2 -> V_81 , F_39 ) ;
if ( V_2 -> V_87 -> V_88 -> V_89 ) {
F_15 ( V_2 , L_26 ) ;
V_4 -> V_10 = F_47 ( V_64 ,
sizeof( struct V_9 ) ,
V_90 ) ;
V_4 -> V_63 = F_47 ( V_64 *
( V_64 - 1 ) ,
sizeof( struct V_62 ) ,
V_90 ) ;
if ( ! V_4 -> V_10 || ! V_4 -> V_63 ) {
F_31 ( V_2 , L_27 ) ;
V_2 -> V_5 . V_11 = false ;
F_48 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_48 ( V_4 -> V_63 ) ;
V_4 -> V_63 = NULL ;
} else {
V_63 = V_4 -> V_63 +
( V_55 * ( V_64 - 1 ) ) ;
memcpy ( V_63 , & V_91 [ 0 ] , V_85 ) ;
V_63 = V_4 -> V_63 +
( V_7 * ( V_64 - 1 ) ) ;
memcpy ( V_63 , & V_92 [ 0 ] , V_85 ) ;
V_63 = V_4 -> V_63 +
( V_53 * ( V_64 - 1 ) ) ;
memcpy ( V_63 , & V_93 [ 0 ] , V_85 ) ;
V_63 = V_4 -> V_63 +
( V_28 * ( V_64 - 1 ) ) ;
memcpy ( V_63 , & V_94 [ 0 ] , V_85 ) ;
V_85 = sizeof( struct V_9 ) *
V_64 ;
memcpy ( V_4 -> V_10 ,
& V_95 [ 0 ] , V_85 ) ;
V_2 -> V_5 . V_11 = true ;
}
} else {
F_15 ( V_2 , L_28 ) ;
V_2 -> V_5 . V_11 = false ;
}
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_27 ( & V_2 -> V_5 . V_35 ) ;
F_27 ( & V_2 -> V_5 . V_44 ) ;
F_50 ( & V_2 -> V_84 ) ;
F_50 ( & V_2 -> V_80 ) ;
F_50 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_5 . V_11 ) {
F_48 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_48 ( V_4 -> V_63 ) ;
V_4 -> V_63 = NULL ;
}
}
