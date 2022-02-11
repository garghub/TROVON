static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 ;
struct V_6 V_8 ;
V_7 = F_2 ( V_2 , V_3 , 8 , & V_8 ) ;
if ( V_7 == NULL )
return false ;
V_5 -> V_9 . V_10 . V_11 . V_12 = V_7 -> V_13 ;
V_5 -> V_14 . V_10 . V_11 . V_12 = V_7 -> V_15 ;
return true ;
}
static bool F_3 ( struct V_4 * V_5 ,
const struct V_4 * V_16 )
{
V_5 -> V_9 . V_10 . V_11 . V_12 = V_16 -> V_14 . V_10 . V_11 . V_12 ;
V_5 -> V_14 . V_10 . V_11 . V_12 = V_16 -> V_9 . V_10 . V_11 . V_12 ;
return true ;
}
static int F_4 ( struct V_17 * V_18 ,
const struct V_4 * V_5 )
{
return F_5 ( V_18 , L_1 ,
F_6 ( V_5 -> V_9 . V_10 . V_11 . V_12 ) ,
F_6 ( V_5 -> V_14 . V_10 . V_11 . V_12 ) ) ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
enum V_21 V_22 ;
F_8 ( & V_20 -> V_23 ) ;
V_22 = V_20 -> V_24 . V_11 . V_22 ;
F_9 ( & V_20 -> V_23 ) ;
return F_5 ( V_18 , L_2 , V_25 [ V_22 ] ) ;
}
static int F_10 ( struct V_19 * V_20 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned long * V_26 )
{
T_1 V_27 , V_28 ;
T_2 V_29 , * V_30 ;
int V_31 ;
V_31 = 0 ;
F_11 (skb, sch, _sch, offset, dataoff, count) {
F_12 ( L_3 , V_28 , V_30 -> type ) ;
if ( V_30 -> type == V_32 ||
V_30 -> type == V_33 ||
V_30 -> type == V_34 )
V_31 = 1 ;
if ( ( ( V_30 -> type == V_35 ||
V_30 -> type == V_36 ||
V_31 ) &&
V_28 != 0 ) || ! V_30 -> V_37 ) {
F_12 ( L_4 ) ;
return 1 ;
}
if ( V_26 )
F_13 ( V_30 -> type , V_26 ) ;
}
F_12 ( L_5 ) ;
return V_28 == 0 ;
}
static int F_14 ( enum V_38 V_39 ,
enum V_21 V_40 ,
int V_41 )
{
int V_42 ;
F_12 ( L_6 , V_41 ) ;
switch ( V_41 ) {
case V_32 :
F_12 ( L_7 ) ;
V_42 = 0 ;
break;
case V_33 :
F_12 ( L_8 ) ;
V_42 = 1 ;
break;
case V_43 :
F_12 ( L_9 ) ;
V_42 = 2 ;
break;
case V_44 :
F_12 ( L_10 ) ;
V_42 = 3 ;
break;
case V_45 :
F_12 ( L_11 ) ;
V_42 = 4 ;
break;
case V_46 :
F_12 ( L_12 ) ;
V_42 = 5 ;
break;
case V_36 :
F_12 ( L_13 ) ;
V_42 = 6 ;
break;
case V_35 :
F_12 ( L_14 ) ;
V_42 = 7 ;
break;
case V_34 :
F_12 ( L_15 ) ;
V_42 = 8 ;
break;
default:
F_12 ( L_16 ,
V_25 [ V_40 ] ) ;
return V_40 ;
}
F_12 ( L_17 ,
V_39 , V_25 [ V_40 ] , V_41 ,
V_25 [ V_47 [ V_39 ] [ V_42 ] [ V_40 ] ] ) ;
return V_47 [ V_39 ] [ V_42 ] [ V_40 ] ;
}
static int F_15 ( struct V_19 * V_20 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_48 V_49 ,
T_3 V_50 ,
unsigned int V_51 )
{
enum V_21 V_52 , V_53 ;
enum V_38 V_39 = F_16 ( V_49 ) ;
const struct V_6 * V_54 ;
struct V_6 V_55 ;
const struct V_56 * V_30 ;
struct V_56 V_29 ;
T_1 V_27 , V_28 ;
unsigned long V_26 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_54 = F_2 ( V_2 , V_3 , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 == NULL )
goto V_57;
if ( F_10 ( V_20 , V_2 , V_3 , V_26 ) != 0 )
goto V_57;
if ( ! F_17 ( V_32 , V_26 ) &&
! F_17 ( V_34 , V_26 ) &&
! F_17 ( V_36 , V_26 ) &&
! F_17 ( V_43 , V_26 ) &&
! F_17 ( V_45 , V_26 ) &&
V_54 -> V_58 != V_20 -> V_24 . V_11 . V_58 [ V_39 ] ) {
F_12 ( L_18 ) ;
goto V_57;
}
V_53 = V_52 = V_59 ;
F_8 ( & V_20 -> V_23 ) ;
F_11 (skb, sch, _sch, offset, dataoff, count) {
if ( V_30 -> type == V_32 ) {
if ( V_54 -> V_58 != 0 )
goto V_60;
} else if ( V_30 -> type == V_43 ) {
if ( V_54 -> V_58 != V_20 -> V_24 . V_11 . V_58 [ V_39 ] &&
V_54 -> V_58 != V_20 -> V_24 . V_11 . V_58 [ ! V_39 ] )
goto V_60;
} else if ( V_30 -> type == V_34 ) {
if ( V_54 -> V_58 != V_20 -> V_24 . V_11 . V_58 [ V_39 ] &&
V_54 -> V_58 != V_20 -> V_24 . V_11 . V_58 [ ! V_39 ] &&
V_30 -> V_61 & V_62 )
goto V_60;
} else if ( V_30 -> type == V_36 ) {
if ( V_54 -> V_58 != V_20 -> V_24 . V_11 . V_58 [ V_39 ] )
goto V_60;
}
V_53 = V_20 -> V_24 . V_11 . V_22 ;
V_52 = F_14 ( V_39 , V_53 , V_30 -> type ) ;
if ( V_52 == V_63 ) {
F_12 ( L_19
L_20 ,
V_39 , V_30 -> type , V_53 ) ;
goto V_60;
}
if ( V_30 -> type == V_32 ||
V_30 -> type == V_33 ) {
T_4 V_64 , * V_65 ;
V_65 = F_2 ( V_2 , V_27 + sizeof( T_2 ) ,
sizeof( V_64 ) , & V_64 ) ;
if ( V_65 == NULL )
goto V_60;
F_12 ( L_21 ,
V_65 -> V_66 , ! V_39 ) ;
V_20 -> V_24 . V_11 . V_58 [ ! V_39 ] = V_65 -> V_66 ;
}
V_20 -> V_24 . V_11 . V_22 = V_52 ;
if ( V_53 != V_52 )
F_18 ( V_67 , V_20 ) ;
}
F_9 ( & V_20 -> V_23 ) ;
F_19 ( V_20 , V_49 , V_2 , V_68 [ V_52 ] ) ;
if ( V_53 == V_69 &&
V_39 == V_70 &&
V_52 == V_71 ) {
F_12 ( L_22 ) ;
F_13 ( V_72 , & V_20 -> V_73 ) ;
F_18 ( V_74 , V_20 ) ;
}
return V_75 ;
V_60:
F_9 ( & V_20 -> V_23 ) ;
V_57:
return - V_75 ;
}
static bool F_20 ( struct V_19 * V_20 , const struct V_1 * V_2 ,
unsigned int V_3 )
{
enum V_21 V_52 ;
const struct V_6 * V_54 ;
struct V_6 V_55 ;
const struct V_56 * V_30 ;
struct V_56 V_29 ;
T_1 V_27 , V_28 ;
unsigned long V_26 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_54 = F_2 ( V_2 , V_3 , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 == NULL )
return false ;
if ( F_10 ( V_20 , V_2 , V_3 , V_26 ) != 0 )
return false ;
if ( F_17 ( V_43 , V_26 ) ||
F_17 ( V_34 , V_26 ) ||
F_17 ( V_35 , V_26 ) )
return false ;
memset ( & V_20 -> V_24 . V_11 , 0 , sizeof( V_20 -> V_24 . V_11 ) ) ;
V_52 = V_63 ;
F_11 (skb, sch, _sch, offset, dataoff, count) {
V_52 = F_14 ( V_76 ,
V_59 , V_30 -> type ) ;
if ( V_52 == V_59 ||
V_52 == V_63 ) {
F_12 ( L_23 ) ;
return false ;
}
if ( V_30 -> type == V_32 ) {
if ( V_54 -> V_58 == 0 ) {
T_4 V_64 , * V_65 ;
V_65 = F_2 ( V_2 , V_27 + sizeof( T_2 ) ,
sizeof( V_64 ) , & V_64 ) ;
if ( V_65 == NULL )
return false ;
F_12 ( L_24 ,
V_65 -> V_66 ) ;
V_20 -> V_24 . V_11 . V_58 [ V_70 ] =
V_65 -> V_66 ;
} else {
return false ;
}
}
else {
F_12 ( L_25 ,
V_54 -> V_58 ) ;
V_20 -> V_24 . V_11 . V_58 [ V_70 ] = V_54 -> V_58 ;
}
V_20 -> V_24 . V_11 . V_22 = V_52 ;
}
return true ;
}
static int F_21 ( struct V_1 * V_2 , struct V_77 * V_78 ,
struct V_19 * V_20 )
{
struct V_77 * V_79 ;
F_8 ( & V_20 -> V_23 ) ;
V_79 = F_22 ( V_2 , V_80 | V_81 ) ;
if ( ! V_79 )
goto V_82;
F_23 ( V_2 , V_83 , V_20 -> V_24 . V_11 . V_22 ) ;
F_24 ( V_2 ,
V_84 ,
V_20 -> V_24 . V_11 . V_58 [ V_76 ] ) ;
F_24 ( V_2 ,
V_85 ,
V_20 -> V_24 . V_11 . V_58 [ V_70 ] ) ;
F_9 ( & V_20 -> V_23 ) ;
F_25 ( V_2 , V_79 ) ;
return 0 ;
V_82:
F_9 ( & V_20 -> V_23 ) ;
return - 1 ;
}
static int F_26 ( struct V_77 * V_86 [] , struct V_19 * V_20 )
{
struct V_77 * V_87 = V_86 [ V_80 ] ;
struct V_77 * V_88 [ V_89 + 1 ] ;
int V_90 ;
if ( ! V_87 )
return 0 ;
V_90 = F_27 ( V_88 ,
V_89 ,
V_87 ,
V_91 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( ! V_88 [ V_83 ] ||
! V_88 [ V_84 ] ||
! V_88 [ V_85 ] )
return - V_92 ;
F_8 ( & V_20 -> V_23 ) ;
V_20 -> V_24 . V_11 . V_22 = F_28 ( V_88 [ V_83 ] ) ;
V_20 -> V_24 . V_11 . V_58 [ V_76 ] =
F_29 ( V_88 [ V_84 ] ) ;
V_20 -> V_24 . V_11 . V_58 [ V_70 ] =
F_29 ( V_88 [ V_85 ] ) ;
F_9 ( & V_20 -> V_23 ) ;
return 0 ;
}
static int F_30 ( void )
{
return F_31 ( 0 )
+ F_32 ( V_91 , V_89 + 1 ) ;
}
static int T_5 F_33 ( void )
{
int V_93 ;
V_93 = F_34 ( & V_94 ) ;
if ( V_93 ) {
F_35 ( L_26 ) ;
goto V_57;
}
V_93 = F_34 ( & V_95 ) ;
if ( V_93 ) {
F_35 ( L_27 ) ;
goto V_96;
}
return V_93 ;
V_96:
F_36 ( & V_94 ) ;
V_57:
return V_93 ;
}
static void T_6 F_37 ( void )
{
F_36 ( & V_95 ) ;
F_36 ( & V_94 ) ;
}
