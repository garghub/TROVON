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
F_13 ( & V_2 -> V_30 -> V_35 , V_25 ) ;
if ( F_14 ( F_15 ( V_2 -> V_30 ) ) )
F_16 ( V_2 -> V_30 ) ;
F_17 ( & V_2 -> V_30 -> V_35 , V_25 ) ;
F_18 ( V_2 , L_1 ) ;
F_19 ( & V_2 -> V_5 . V_36 ,
V_37 + V_38 * V_39 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
bool V_40 )
{
if ( V_40 ) {
F_18 ( V_2 , L_2 ) ;
if ( V_2 -> V_41 )
F_21 ( V_2 -> V_42 ) ;
F_18 ( V_2 ,
L_3 ) ;
F_19 ( & V_2 -> V_5 . V_36 ,
V_37 + V_38 * V_39 ) ;
} else {
F_18 ( V_2 , L_4 ) ;
if ( V_2 -> V_41 )
F_22 ( V_2 -> V_42 ) ;
}
}
static void F_23 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( V_4 -> V_6 != V_28 ) {
F_18 ( V_2 , L_5
L_6 ) ;
V_4 -> V_6 = V_28 ;
F_24 ( V_43 , & V_2 -> V_27 ) ;
F_20 ( V_2 , true ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_18 ( V_2 , L_7 ) ;
F_26 ( V_2 , V_44 , false ) ;
F_19 ( & V_2 -> V_5 . V_45 ,
V_37 + F_27 ( V_46 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_13 , bool V_47 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
enum V_48 V_49 ;
#ifdef F_29
if ( ( V_4 -> V_50 ) &&
( V_13 > V_4 -> V_50 ) &&
( ( V_13 - V_4 -> V_50 ) >
V_51 ) ) {
F_18 ( V_2 ,
L_8 ,
( V_13 - V_4 -> V_50 ) ) ;
}
#endif
V_49 = V_4 -> V_6 ;
if ( V_13 >= V_52 )
V_4 -> V_6 = V_28 ;
else if ( V_13 >= V_53 )
V_4 -> V_6 = V_54 ;
else if ( V_13 >= V_55 )
V_4 -> V_6 = V_7 ;
else
V_4 -> V_6 = V_56 ;
#ifdef F_29
V_4 -> V_50 = V_13 ;
#endif
F_30 ( & V_2 -> V_5 . V_45 ) ;
if ( V_4 -> V_6 != V_49 ) {
switch ( V_4 -> V_6 ) {
case V_56 :
break;
case V_7 :
V_4 -> V_8 = V_57 ;
break;
case V_54 :
V_4 -> V_8 = V_58 ;
break;
default:
V_4 -> V_8 = V_59 ;
break;
}
F_31 ( & V_2 -> V_60 ) ;
if ( V_49 == V_28 )
F_32 ( V_43 , & V_2 -> V_27 ) ;
if ( V_4 -> V_6 != V_28 &&
F_33 ( V_2 , true ) ) {
if ( V_49 == V_28 )
F_24 ( V_43 , & V_2 -> V_27 ) ;
V_4 -> V_6 = V_49 ;
F_34 ( V_2 , L_9
L_10 ) ;
} else {
if ( V_4 -> V_6 == V_28 ) {
if ( V_47 ) {
F_24 ( V_43 , & V_2 -> V_27 ) ;
F_20 ( V_2 , true ) ;
} else {
F_25 ( V_2 ) ;
V_4 -> V_6 = V_49 ;
}
} else if ( V_49 == V_28 &&
V_4 -> V_6 != V_28 )
F_20 ( V_2 , false ) ;
F_18 ( V_2 , L_11 ,
V_4 -> V_6 ) ;
F_18 ( V_2 , L_12 ,
V_4 -> V_8 ) ;
}
F_35 ( & V_2 -> V_60 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , T_2 V_13 , bool V_47 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_61 ;
bool V_62 = false ;
enum V_48 V_49 ;
struct V_63 * V_64 ;
V_49 = V_4 -> V_6 ;
for ( V_61 = 0 ; V_61 < V_65 - 1 ; V_61 ++ ) {
V_64 = V_4 -> V_64 +
( ( V_49 * ( V_65 - 1 ) ) + V_61 ) ;
if ( V_13 >= V_64 -> V_66 &&
V_13 <= V_64 -> V_67 ) {
#ifdef F_29
if ( ( V_4 -> V_50 ) &&
( V_13 > V_4 -> V_50 ) &&
( ( V_13 - V_4 -> V_50 ) >
V_51 ) ) {
F_18 ( V_2 ,
L_13
L_14 ,
( V_13 - V_4 -> V_50 ) ) ;
}
V_4 -> V_50 = V_13 ;
#endif
if ( V_49 !=
V_64 -> V_68 ) {
V_62 = true ;
V_4 -> V_6 =
V_64 -> V_68 ;
}
break;
}
}
F_30 ( & V_2 -> V_5 . V_45 ) ;
if ( V_62 ) {
if ( V_4 -> V_6 >= V_7 ) {
V_4 -> V_8 = V_59 ;
if ( ! F_3 ( V_2 ) ) {
struct V_69 * V_70 ;
F_37 (priv, ctx) {
struct V_71 * V_72 ;
V_72 = & V_70 -> V_73 ;
V_72 -> V_25 &= ~ (
V_74 |
V_75 |
V_76 |
V_77 ) ;
}
} else {
F_38 ( V_2 , & V_2 -> V_78 ) ;
}
} else {
F_38 ( V_2 , & V_2 -> V_78 ) ;
}
F_31 ( & V_2 -> V_60 ) ;
if ( V_49 == V_28 )
F_32 ( V_43 , & V_2 -> V_27 ) ;
if ( V_4 -> V_6 != V_28 &&
F_33 ( V_2 , true ) ) {
F_34 ( V_2 , L_9
L_10 ) ;
if ( V_49 == V_28 )
F_24 ( V_43 , & V_2 -> V_27 ) ;
V_4 -> V_6 = V_49 ;
} else {
F_18 ( V_2 ,
L_15 ,
V_4 -> V_6 ) ;
if ( V_49 != V_28 &&
V_4 -> V_6 == V_28 ) {
if ( V_47 ) {
F_18 ( V_2 ,
L_16 ) ;
F_24 ( V_43 , & V_2 -> V_27 ) ;
F_20 ( V_2 , true ) ;
} else {
F_25 ( V_2 ) ;
V_4 -> V_6 = V_49 ;
}
} else if ( V_49 == V_28 &&
V_4 -> V_6 != V_28 ) {
F_18 ( V_2 , L_17 ) ;
F_20 ( V_2 , false ) ;
}
}
F_35 ( & V_2 -> V_60 ) ;
}
}
static void F_39 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_40 ( V_80 , struct V_1 , V_81 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( ! F_41 ( V_2 ) )
return;
if ( V_4 -> V_6 != V_28 ) {
F_34 ( V_2 , L_18
L_19 ) ;
if ( ! V_2 -> V_5 . V_11 )
F_28 ( V_2 ,
V_52 ,
true ) ;
else
F_36 ( V_2 ,
V_18 + 1 , true ) ;
}
}
static void F_42 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_40 ( V_80 , struct V_1 , V_82 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( ! F_41 ( V_2 ) )
return;
F_30 ( & V_2 -> V_5 . V_36 ) ;
if ( V_4 -> V_6 == V_28 ) {
F_34 ( V_2 ,
L_20
L_21 ) ;
V_2 -> V_14 = 0 ;
if ( ! V_2 -> V_5 . V_11 )
F_28 ( V_2 ,
V_53 ,
true ) ;
else
F_36 ( V_2 , V_83 ,
true ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
F_18 ( V_2 , L_22 ) ;
F_43 ( V_2 -> V_84 , & V_2 -> V_81 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
F_18 ( V_2 , L_23 ) ;
F_43 ( V_2 -> V_84 , & V_2 -> V_82 ) ;
}
static void F_45 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_40 ( V_80 , struct V_1 , V_85 ) ;
T_2 V_13 = V_2 -> V_14 ;
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
if ( ! V_2 -> V_5 . V_11 )
F_28 ( V_2 , V_13 , false ) ;
else
F_36 ( V_2 , V_13 , false ) ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( F_10 ( V_26 , & V_2 -> V_27 ) )
return;
F_18 ( V_2 , L_24 ) ;
F_43 ( V_2 -> V_84 , & V_2 -> V_85 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_86 = sizeof( struct V_63 ) * ( V_65 - 1 ) ;
struct V_63 * V_64 ;
F_18 ( V_2 , L_25 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_6 = V_56 ;
F_48 ( & V_2 -> V_5 . V_36 ) ;
V_2 -> V_5 . V_36 . V_24 = ( unsigned long ) V_2 ;
V_2 -> V_5 . V_36 . V_87 =
F_9 ;
F_48 ( & V_2 -> V_5 . V_45 ) ;
V_2 -> V_5 . V_45 . V_24 =
( unsigned long ) V_2 ;
V_2 -> V_5 . V_45 . V_87 =
F_23 ;
F_49 ( & V_2 -> V_85 , F_45 ) ;
F_49 ( & V_2 -> V_81 , F_39 ) ;
F_49 ( & V_2 -> V_82 , F_42 ) ;
if ( V_2 -> V_88 -> V_89 -> V_90 ) {
F_18 ( V_2 , L_26 ) ;
V_4 -> V_10 = F_50 ( V_65 ,
sizeof( struct V_9 ) ,
V_91 ) ;
V_4 -> V_64 = F_50 ( V_65 *
( V_65 - 1 ) ,
sizeof( struct V_63 ) ,
V_91 ) ;
if ( ! V_4 -> V_10 || ! V_4 -> V_64 ) {
F_34 ( V_2 , L_27 ) ;
V_2 -> V_5 . V_11 = false ;
F_51 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_51 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
} else {
V_64 = V_4 -> V_64 +
( V_56 * ( V_65 - 1 ) ) ;
memcpy ( V_64 , & V_92 [ 0 ] , V_86 ) ;
V_64 = V_4 -> V_64 +
( V_7 * ( V_65 - 1 ) ) ;
memcpy ( V_64 , & V_93 [ 0 ] , V_86 ) ;
V_64 = V_4 -> V_64 +
( V_54 * ( V_65 - 1 ) ) ;
memcpy ( V_64 , & V_94 [ 0 ] , V_86 ) ;
V_64 = V_4 -> V_64 +
( V_28 * ( V_65 - 1 ) ) ;
memcpy ( V_64 , & V_95 [ 0 ] , V_86 ) ;
V_86 = sizeof( struct V_9 ) *
V_65 ;
memcpy ( V_4 -> V_10 ,
& V_96 [ 0 ] , V_86 ) ;
V_2 -> V_5 . V_11 = true ;
}
} else {
F_18 ( V_2 , L_28 ) ;
V_2 -> V_5 . V_11 = false ;
}
}
void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_30 ( & V_2 -> V_5 . V_36 ) ;
F_30 ( & V_2 -> V_5 . V_45 ) ;
F_53 ( & V_2 -> V_85 ) ;
F_53 ( & V_2 -> V_81 ) ;
F_53 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_5 . V_11 ) {
F_51 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_51 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
}
}
