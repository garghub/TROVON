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
if ( V_2 -> V_16 -> V_17 -> V_18 )
V_13 = F_5 ( V_2 -> V_14 ) ;
if ( ! V_2 -> V_5 . V_11 )
V_15 = ( ( V_13 + V_19 ) >=
V_20 ) ? true : false ;
else
V_15 = ( ( V_13 + V_19 ) >=
V_21 ) ? true : false ;
return V_15 ;
}
bool F_6 ( struct V_1 * V_2 )
{
bool V_22 = false ;
if ( F_4 ( V_2 ) ) {
F_7 ( V_2 ) ;
V_22 = true ;
}
return V_22 ;
}
enum V_23 F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_9 * V_10 ;
if ( ! V_2 -> V_5 . V_11 )
return V_24 ;
V_10 = V_4 -> V_10 + V_4 -> V_6 ;
return V_10 -> V_25 ;
}
enum V_23 F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_9 * V_10 ;
if ( ! V_2 -> V_5 . V_11 )
return V_24 ;
V_10 = V_4 -> V_10 + V_4 -> V_6 ;
return V_10 -> V_26 ;
}
static void F_10 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
unsigned long V_28 ;
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
if ( V_4 -> V_6 == V_31 ) {
if ( V_2 -> V_5 . V_32 ) {
F_12 ( V_2 , V_33 ,
V_34 ) ;
V_2 -> V_5 . V_32 = false ;
} else {
F_12 ( V_2 , V_35 ,
V_34 ) ;
V_2 -> V_5 . V_32 = true ;
}
F_13 ( V_2 , V_36 ) ;
F_14 ( & V_2 -> V_37 , V_28 ) ;
if ( ! F_15 ( V_2 ) )
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_37 , V_28 ) ;
F_18 ( V_2 , L_1 ) ;
F_19 ( & V_2 -> V_5 . V_38 ,
V_39 + V_40 * V_41 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
bool V_42 )
{
if ( V_42 ) {
F_18 ( V_2 , L_2 ) ;
if ( V_2 -> V_43 )
F_21 ( V_2 -> V_44 ) ;
F_18 ( V_2 ,
L_3 ) ;
F_19 ( & V_2 -> V_5 . V_38 ,
V_39 + V_40 * V_41 ) ;
} else {
F_18 ( V_2 , L_4 ) ;
if ( V_2 -> V_43 )
F_22 ( V_2 -> V_44 ) ;
}
}
static void F_23 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
if ( V_4 -> V_6 != V_31 ) {
F_18 ( V_2 , L_5
L_6 ) ;
V_4 -> V_6 = V_31 ;
F_24 ( V_45 , & V_2 -> V_30 ) ;
F_20 ( V_2 , true ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_18 ( V_2 , L_7 ) ;
F_26 ( V_2 , V_46 , false ) ;
F_19 ( & V_2 -> V_5 . V_47 ,
V_39 + F_27 ( V_48 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_13 , bool V_49 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
enum V_50 V_51 ;
#ifdef F_29
if ( ( V_4 -> V_52 ) &&
( V_13 > V_4 -> V_52 ) &&
( ( V_13 - V_4 -> V_52 ) >
V_53 ) ) {
F_18 ( V_2 ,
L_8 ,
( V_13 - V_4 -> V_52 ) ) ;
}
#endif
V_51 = V_4 -> V_6 ;
if ( V_13 >= V_54 )
V_4 -> V_6 = V_31 ;
else if ( V_13 >= V_55 )
V_4 -> V_6 = V_56 ;
else if ( V_13 >= V_57 )
V_4 -> V_6 = V_7 ;
else
V_4 -> V_6 = V_58 ;
#ifdef F_29
V_4 -> V_52 = V_13 ;
#endif
F_30 ( & V_2 -> V_5 . V_47 ) ;
if ( V_4 -> V_6 != V_51 ) {
switch ( V_4 -> V_6 ) {
case V_58 :
break;
case V_7 :
V_4 -> V_8 = V_59 ;
break;
case V_56 :
V_4 -> V_8 = V_60 ;
break;
default:
V_4 -> V_8 = V_61 ;
break;
}
F_31 ( & V_2 -> V_62 ) ;
if ( V_51 == V_31 )
F_32 ( V_45 , & V_2 -> V_30 ) ;
if ( V_4 -> V_6 != V_31 &&
F_33 ( V_2 , true ) ) {
if ( V_51 == V_31 )
F_24 ( V_45 , & V_2 -> V_30 ) ;
V_4 -> V_6 = V_51 ;
F_34 ( V_2 , L_9
L_10 ) ;
} else {
if ( V_4 -> V_6 == V_31 ) {
if ( V_49 ) {
F_24 ( V_45 , & V_2 -> V_30 ) ;
F_20 ( V_2 , true ) ;
} else {
F_25 ( V_2 ) ;
V_4 -> V_6 = V_51 ;
}
} else if ( V_51 == V_31 &&
V_4 -> V_6 != V_31 )
F_20 ( V_2 , false ) ;
F_18 ( V_2 , L_11 ,
V_4 -> V_6 ) ;
F_18 ( V_2 , L_12 ,
V_4 -> V_8 ) ;
}
F_35 ( & V_2 -> V_62 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , T_2 V_13 , bool V_49 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_63 ;
bool V_64 = false ;
enum V_50 V_51 ;
struct V_65 * V_66 ;
V_51 = V_4 -> V_6 ;
for ( V_63 = 0 ; V_63 < V_67 - 1 ; V_63 ++ ) {
V_66 = V_4 -> V_66 +
( ( V_51 * ( V_67 - 1 ) ) + V_63 ) ;
if ( V_13 >= V_66 -> V_68 &&
V_13 <= V_66 -> V_69 ) {
#ifdef F_29
if ( ( V_4 -> V_52 ) &&
( V_13 > V_4 -> V_52 ) &&
( ( V_13 - V_4 -> V_52 ) >
V_53 ) ) {
F_18 ( V_2 ,
L_13
L_14 ,
( V_13 - V_4 -> V_52 ) ) ;
}
V_4 -> V_52 = V_13 ;
#endif
if ( V_51 !=
V_66 -> V_70 ) {
V_64 = true ;
V_4 -> V_6 =
V_66 -> V_70 ;
}
break;
}
}
F_30 ( & V_2 -> V_5 . V_47 ) ;
if ( V_64 ) {
if ( V_4 -> V_6 >= V_7 ) {
V_4 -> V_8 = V_61 ;
if ( ! F_3 ( V_2 ) ) {
struct V_71 * V_72 ;
F_37 (priv, ctx) {
struct V_73 * V_74 ;
V_74 = & V_72 -> V_75 ;
V_74 -> V_28 &= ~ (
V_76 |
V_77 |
V_78 |
V_79 ) ;
}
} else {
F_38 ( V_2 , & V_2 -> V_80 ) ;
}
} else {
F_38 ( V_2 , & V_2 -> V_80 ) ;
}
F_31 ( & V_2 -> V_62 ) ;
if ( V_51 == V_31 )
F_32 ( V_45 , & V_2 -> V_30 ) ;
if ( V_4 -> V_6 != V_31 &&
F_33 ( V_2 , true ) ) {
F_34 ( V_2 , L_9
L_10 ) ;
if ( V_51 == V_31 )
F_24 ( V_45 , & V_2 -> V_30 ) ;
V_4 -> V_6 = V_51 ;
} else {
F_18 ( V_2 ,
L_15 ,
V_4 -> V_6 ) ;
if ( V_51 != V_31 &&
V_4 -> V_6 == V_31 ) {
if ( V_49 ) {
F_18 ( V_2 ,
L_16 ) ;
F_24 ( V_45 , & V_2 -> V_30 ) ;
F_20 ( V_2 , true ) ;
} else {
F_25 ( V_2 ) ;
V_4 -> V_6 = V_51 ;
}
} else if ( V_51 == V_31 &&
V_4 -> V_6 != V_31 ) {
F_18 ( V_2 , L_17 ) ;
F_20 ( V_2 , false ) ;
}
}
F_35 ( & V_2 -> V_62 ) ;
}
}
static void F_39 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 , struct V_1 , V_83 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
if ( ! F_41 ( V_2 ) )
return;
if ( V_4 -> V_6 != V_31 ) {
F_34 ( V_2 , L_18
L_19 ) ;
if ( ! V_2 -> V_5 . V_11 )
F_28 ( V_2 ,
V_54 ,
true ) ;
else
F_36 ( V_2 ,
V_21 + 1 , true ) ;
}
}
static void F_42 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 , struct V_1 , V_84 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
if ( ! F_41 ( V_2 ) )
return;
F_30 ( & V_2 -> V_5 . V_38 ) ;
if ( V_4 -> V_6 == V_31 ) {
F_34 ( V_2 ,
L_20
L_21 ) ;
V_2 -> V_14 = 0 ;
if ( ! V_2 -> V_5 . V_11 )
F_28 ( V_2 ,
V_55 ,
true ) ;
else
F_36 ( V_2 , V_85 ,
true ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
F_18 ( V_2 , L_22 ) ;
F_43 ( V_2 -> V_86 , & V_2 -> V_83 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
F_18 ( V_2 , L_23 ) ;
F_43 ( V_2 -> V_86 , & V_2 -> V_84 ) ;
}
static void F_45 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_40 ( V_82 , struct V_1 , V_87 ) ;
T_2 V_13 = V_2 -> V_14 ;
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
if ( V_2 -> V_16 -> V_17 -> V_18 )
V_13 = F_5 ( V_2 -> V_14 ) ;
if ( ! V_2 -> V_5 . V_11 )
F_28 ( V_2 , V_13 , false ) ;
else
F_36 ( V_2 , V_13 , false ) ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( F_11 ( V_29 , & V_2 -> V_30 ) )
return;
F_18 ( V_2 , L_24 ) ;
F_43 ( V_2 -> V_86 , & V_2 -> V_87 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_88 = sizeof( struct V_65 ) * ( V_67 - 1 ) ;
struct V_65 * V_66 ;
F_18 ( V_2 , L_25 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_6 = V_58 ;
F_48 ( & V_2 -> V_5 . V_38 ) ;
V_2 -> V_5 . V_38 . V_27 = ( unsigned long ) V_2 ;
V_2 -> V_5 . V_38 . V_89 =
F_10 ;
F_48 ( & V_2 -> V_5 . V_47 ) ;
V_2 -> V_5 . V_47 . V_27 =
( unsigned long ) V_2 ;
V_2 -> V_5 . V_47 . V_89 =
F_23 ;
F_49 ( & V_2 -> V_87 , F_45 ) ;
F_49 ( & V_2 -> V_83 , F_39 ) ;
F_49 ( & V_2 -> V_84 , F_42 ) ;
if ( V_2 -> V_16 -> V_17 -> V_90 ) {
F_18 ( V_2 , L_26 ) ;
V_4 -> V_10 = F_50 ( sizeof( struct V_9 ) *
V_67 , V_91 ) ;
V_4 -> V_66 = F_50 ( sizeof( struct V_65 ) *
V_67 * ( V_67 - 1 ) ,
V_91 ) ;
if ( ! V_4 -> V_10 || ! V_4 -> V_66 ) {
F_34 ( V_2 , L_27 ) ;
V_2 -> V_5 . V_11 = false ;
F_51 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_51 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
} else {
V_66 = V_4 -> V_66 +
( V_58 * ( V_67 - 1 ) ) ;
memcpy ( V_66 , & V_92 [ 0 ] , V_88 ) ;
V_66 = V_4 -> V_66 +
( V_7 * ( V_67 - 1 ) ) ;
memcpy ( V_66 , & V_93 [ 0 ] , V_88 ) ;
V_66 = V_4 -> V_66 +
( V_56 * ( V_67 - 1 ) ) ;
memcpy ( V_66 , & V_94 [ 0 ] , V_88 ) ;
V_66 = V_4 -> V_66 +
( V_31 * ( V_67 - 1 ) ) ;
memcpy ( V_66 , & V_95 [ 0 ] , V_88 ) ;
V_88 = sizeof( struct V_9 ) *
V_67 ;
memcpy ( V_4 -> V_10 ,
& V_96 [ 0 ] , V_88 ) ;
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
F_30 ( & V_2 -> V_5 . V_38 ) ;
F_30 ( & V_2 -> V_5 . V_47 ) ;
F_53 ( & V_2 -> V_87 ) ;
F_53 ( & V_2 -> V_83 ) ;
F_53 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_5 . V_11 ) {
F_51 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_51 ( V_4 -> V_66 ) ;
V_4 -> V_66 = NULL ;
}
}
