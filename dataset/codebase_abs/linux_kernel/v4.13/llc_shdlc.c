static bool F_1 ( int V_1 , int V_2 , int V_3 )
{
if ( V_1 < V_3 )
return ( ( V_1 < V_2 ) && ( V_2 <= V_3 ) ) ? true : false ;
else
return ( ( V_2 > V_1 ) || ( V_2 <= V_3 ) ) ? true : false ;
}
static bool F_2 ( int V_1 , int V_2 , int V_3 )
{
if ( V_1 <= V_3 )
return ( ( V_1 <= V_2 ) && ( V_2 < V_3 ) ) ? true : false ;
else
return ( ( V_2 >= V_1 ) || ( V_2 < V_3 ) ) ? true : false ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 ,
int V_7 )
{
struct V_4 * V_8 ;
V_8 = F_4 ( V_6 -> V_9 + V_10 +
V_6 -> V_11 + V_7 , V_12 ) ;
if ( V_8 )
F_5 ( V_8 , V_6 -> V_9 + V_10 ) ;
return V_8 ;
}
static int F_6 ( struct V_5 * V_6 ,
enum V_13 V_13 , int V_14 )
{
int V_15 ;
struct V_4 * V_8 ;
F_7 ( L_1 , V_13 , V_14 ) ;
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
* ( V_17 * ) F_8 ( V_8 , 1 ) = V_18 | ( V_13 << 3 ) | V_14 ;
V_15 = V_6 -> V_19 ( V_6 -> V_20 , V_8 ) ;
F_9 ( V_8 ) ;
return V_15 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_4 * V_8 ,
enum V_21 V_21 )
{
int V_15 ;
F_7 ( L_2 , V_21 ) ;
* ( V_17 * ) F_8 ( V_8 , 1 ) = V_22 | V_21 ;
V_15 = V_6 -> V_19 ( V_6 -> V_20 , V_8 ) ;
F_9 ( V_8 ) ;
return V_15 ;
}
static void F_11 ( struct V_5 * V_6 , int V_23 )
{
struct V_4 * V_8 ;
int V_24 = V_6 -> V_24 ;
F_7 ( L_3 , V_23 ) ;
while ( V_24 != V_23 ) {
F_7 ( L_4 , V_24 ) ;
V_8 = F_12 ( & V_6 -> V_25 ) ;
F_9 ( V_8 ) ;
V_24 = ( V_24 + 1 ) % 8 ;
}
if ( F_13 ( & V_6 -> V_25 ) ) {
if ( V_6 -> V_26 ) {
F_14 ( & V_6 -> V_27 ) ;
V_6 -> V_26 = false ;
F_7
( L_5 ) ;
}
} else {
V_8 = F_15 ( & V_6 -> V_25 ) ;
F_16 ( & V_6 -> V_27 , * ( unsigned long * ) V_8 -> V_28 +
F_17 ( V_29 ) ) ;
V_6 -> V_26 = true ;
F_7
( L_6 ) ;
}
}
static void F_18 ( struct V_5 * V_6 ,
struct V_4 * V_8 , int V_30 , int V_14 )
{
int V_31 = V_30 ;
int V_23 = V_14 ;
F_7 ( L_7 , V_30 , V_14 ) ;
if ( V_6 -> V_32 != V_33 )
goto exit;
if ( V_31 != V_6 -> V_14 ) {
F_6 ( V_6 , V_34 , V_6 -> V_14 ) ;
goto exit;
}
if ( V_6 -> V_35 == false ) {
V_6 -> V_35 = true ;
F_16 ( & V_6 -> V_36 , V_37 +
F_17 ( F_19 ( V_6 -> V_38 ) ) ) ;
F_7 ( L_8 ) ;
}
if ( V_8 -> V_39 ) {
V_6 -> V_40 ( V_6 -> V_20 , V_8 ) ;
V_8 = NULL ;
}
V_6 -> V_14 = ( V_6 -> V_14 + 1 ) % 8 ;
if ( F_1 ( V_6 -> V_24 , V_23 , V_6 -> V_30 ) ) {
F_11 ( V_6 , V_23 ) ;
V_6 -> V_24 = V_23 ;
}
exit:
F_9 ( V_8 ) ;
}
static void F_20 ( struct V_5 * V_6 , int V_23 )
{
F_7 ( L_9 , V_23 ) ;
if ( F_1 ( V_6 -> V_24 , V_23 , V_6 -> V_30 ) ) {
F_11 ( V_6 , V_23 ) ;
V_6 -> V_24 = V_23 ;
}
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_7 ( L_10 , V_6 -> V_24 ) ;
while ( ( V_8 = F_22 ( & V_6 -> V_25 ) ) ) {
F_23 ( V_8 , 1 ) ;
F_24 ( & V_6 -> V_41 , V_8 ) ;
}
V_6 -> V_30 = V_6 -> V_24 ;
}
static void F_25 ( struct V_5 * V_6 , int V_23 )
{
struct V_4 * V_8 ;
F_7 ( L_11 , V_23 ) ;
if ( F_2 ( V_6 -> V_24 , V_23 , V_6 -> V_30 ) ) {
if ( V_6 -> V_26 ) {
F_14 ( & V_6 -> V_27 ) ;
V_6 -> V_26 = false ;
F_7 ( L_12 ) ;
}
if ( V_6 -> V_24 != V_23 ) {
while ( ( V_6 -> V_24 = ( ( V_6 -> V_24 + 1 ) % 8 ) ) != V_23 ) {
V_8 = F_12 ( & V_6 -> V_25 ) ;
F_9 ( V_8 ) ;
}
}
F_21 ( V_6 ) ;
}
}
static void F_26 ( struct V_5 * V_6 ,
enum V_13 V_42 , int V_14 )
{
struct V_4 * V_8 ;
if ( V_6 -> V_32 != V_33 )
return;
switch ( V_42 ) {
case V_43 :
F_20 ( V_6 , V_14 ) ;
if ( V_6 -> V_44 == true ) {
V_6 -> V_44 = false ;
if ( V_6 -> V_41 . V_45 == 0 ) {
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 )
F_27 ( & V_6 -> V_41 , V_8 ) ;
}
}
break;
case V_34 :
F_25 ( V_6 , V_14 ) ;
break;
case V_46 :
F_20 ( V_6 , V_14 ) ;
V_6 -> V_44 = true ;
break;
default:
break;
}
}
static void F_28 ( struct V_5 * V_6 , int V_15 )
{
F_7 ( L_13 , V_15 ) ;
F_14 ( & V_6 -> V_47 ) ;
if ( V_15 == 0 ) {
V_6 -> V_30 = 0 ;
V_6 -> V_14 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_32 = V_48 ;
} else {
V_6 -> V_32 = V_49 ;
}
V_6 -> V_50 = V_15 ;
F_29 ( V_6 -> V_51 ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_7 ( L_14 ) ;
V_8 = F_3 ( V_6 , 2 ) ;
if ( V_8 == NULL )
return - V_16 ;
F_31 ( V_8 , V_52 ) ;
F_31 ( V_8 , V_53 ? 1 : 0 ) ;
return F_10 ( V_6 , V_8 , V_54 ) ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_7 ( L_14 ) ;
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
return F_10 ( V_6 , V_8 , V_55 ) ;
}
static void F_33 ( struct V_5 * V_6 ,
struct V_4 * V_8 ,
enum V_21 V_56 )
{
V_17 V_38 = V_52 ;
bool V_57 = V_53 ;
int V_15 ;
F_7 ( L_15 , V_56 ) ;
switch ( V_56 ) {
case V_54 :
switch ( V_6 -> V_32 ) {
case V_58 :
case V_59 :
if ( V_8 -> V_39 > 0 )
V_38 = V_8 -> V_60 [ 0 ] ;
if ( V_8 -> V_39 > 1 )
V_57 = V_8 -> V_60 [ 1 ] & 0x01 ? true :
false ;
if ( ( V_38 <= V_52 ) &&
( V_53 || ( V_57 == false ) ) ) {
V_6 -> V_38 = V_38 ;
V_6 -> V_57 = V_57 ;
V_15 = F_32 ( V_6 ) ;
F_28 ( V_6 , V_15 ) ;
}
break;
case V_48 :
break;
case V_33 :
V_6 -> V_61 = - V_62 ;
break;
default:
break;
}
break;
case V_55 :
if ( ( V_6 -> V_32 == V_59 &&
V_6 -> V_63 > 0 ) ||
( V_6 -> V_32 == V_58 ) ) {
F_28 ( V_6 , 0 ) ;
V_6 -> V_32 = V_33 ;
}
break;
default:
break;
}
F_9 ( V_8 ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
V_17 V_64 ;
int V_14 ;
int V_30 ;
enum V_13 V_42 ;
enum V_21 V_56 ;
if ( V_6 -> V_65 . V_45 )
F_7 ( L_16 , V_6 -> V_65 . V_45 ) ;
while ( ( V_8 = F_12 ( & V_6 -> V_65 ) ) != NULL ) {
V_64 = V_8 -> V_60 [ 0 ] ;
F_23 ( V_8 , 1 ) ;
switch ( V_64 & V_66 ) {
case V_67 :
case V_68 :
if ( V_6 -> V_32 == V_48 )
V_6 -> V_32 = V_33 ;
V_30 = ( V_64 & V_69 ) >> 3 ;
V_14 = V_64 & V_70 ;
F_18 ( V_6 , V_8 , V_30 , V_14 ) ;
break;
case V_18 :
if ( V_6 -> V_32 == V_48 )
V_6 -> V_32 = V_33 ;
V_42 = ( V_64 & V_71 ) >> 3 ;
V_14 = V_64 & V_70 ;
F_26 ( V_6 , V_42 , V_14 ) ;
F_9 ( V_8 ) ;
break;
case V_22 :
V_56 = V_64 & V_72 ;
F_33 ( V_6 , V_8 , V_56 ) ;
break;
default:
F_35 ( L_17 , V_64 ) ;
F_9 ( V_8 ) ;
break;
}
}
}
static int F_36 ( int V_30 , int V_24 )
{
int V_73 ;
if ( V_24 <= V_30 )
V_73 = V_30 - V_24 ;
else
V_73 = 8 - V_24 + V_30 ;
return V_73 ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
int V_15 ;
unsigned long V_74 ;
if ( V_6 -> V_41 . V_45 )
F_7
( L_18 ,
V_6 -> V_41 . V_45 , V_6 -> V_30 , V_6 -> V_24 ,
V_6 -> V_44 == false ? L_19 : L_20 ,
V_6 -> V_38 - F_36 ( V_6 -> V_30 , V_6 -> V_24 ) ,
V_6 -> V_25 . V_45 ) ;
while ( V_6 -> V_41 . V_45 && V_6 -> V_25 . V_45 < V_6 -> V_38 &&
( V_6 -> V_44 == false ) ) {
if ( V_6 -> V_35 ) {
F_14 ( & V_6 -> V_36 ) ;
V_6 -> V_35 = false ;
F_7 ( L_21 ) ;
}
V_8 = F_12 ( & V_6 -> V_41 ) ;
* ( V_17 * ) F_8 ( V_8 , 1 ) = V_67 | ( V_6 -> V_30 << 3 ) |
V_6 -> V_14 ;
F_7 ( L_22 , V_6 -> V_30 ,
V_6 -> V_14 ) ;
F_38 ( L_23 , V_8 ) ;
V_15 = V_6 -> V_19 ( V_6 -> V_20 , V_8 ) ;
if ( V_15 < 0 ) {
V_6 -> V_61 = V_15 ;
break;
}
V_6 -> V_30 = ( V_6 -> V_30 + 1 ) % 8 ;
V_74 = V_37 ;
* ( unsigned long * ) V_8 -> V_28 = V_74 ;
F_27 ( & V_6 -> V_25 , V_8 ) ;
if ( V_6 -> V_26 == false ) {
V_6 -> V_26 = true ;
F_16 ( & V_6 -> V_27 , V_74 +
F_17 ( V_29 ) ) ;
F_7 ( L_24 ) ;
}
}
}
static void F_39 ( unsigned long V_60 )
{
struct V_5 * V_6 = (struct V_5 * ) V_60 ;
F_7 ( L_14 ) ;
F_40 ( & V_6 -> V_75 ) ;
}
static void F_41 ( unsigned long V_60 )
{
struct V_5 * V_6 = (struct V_5 * ) V_60 ;
F_7 ( L_25 ) ;
F_40 ( & V_6 -> V_75 ) ;
}
static void F_42 ( unsigned long V_60 )
{
struct V_5 * V_6 = (struct V_5 * ) V_60 ;
F_7 ( L_26 ) ;
F_40 ( & V_6 -> V_75 ) ;
}
static void F_43 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_44 ( V_77 , struct V_5 , V_75 ) ;
int V_15 ;
F_7 ( L_14 ) ;
F_45 ( & V_6 -> V_78 ) ;
switch ( V_6 -> V_32 ) {
case V_49 :
F_46 ( & V_6 -> V_65 ) ;
F_46 ( & V_6 -> V_41 ) ;
F_46 ( & V_6 -> V_25 ) ;
break;
case V_59 :
if ( V_6 -> V_61 ) {
F_28 ( V_6 , V_6 -> V_61 ) ;
break;
}
if ( V_6 -> V_63 ++ < 5 )
V_15 = F_30 ( V_6 ) ;
else
V_15 = - V_79 ;
if ( V_15 < 0 ) {
F_28 ( V_6 , V_15 ) ;
} else {
F_16 ( & V_6 -> V_47 , V_37 +
F_17 ( V_80 ) ) ;
V_6 -> V_32 = V_58 ;
}
break;
case V_58 :
if ( F_47 ( & V_6 -> V_47 ) == 0 ) {
V_6 -> V_32 = V_59 ;
F_40 ( & V_6 -> V_75 ) ;
}
F_34 ( V_6 ) ;
if ( V_6 -> V_61 ) {
F_28 ( V_6 , V_6 -> V_61 ) ;
break;
}
break;
case V_48 :
case V_33 :
F_34 ( V_6 ) ;
F_37 ( V_6 ) ;
if ( V_6 -> V_35 && F_47 ( & V_6 -> V_36 ) == 0 ) {
F_7
( L_27 ) ;
V_6 -> V_35 = false ;
V_15 = F_6 ( V_6 , V_43 ,
V_6 -> V_14 ) ;
if ( V_15 < 0 )
V_6 -> V_61 = V_15 ;
}
if ( V_6 -> V_26 && F_47 ( & V_6 -> V_27 ) == 0 ) {
F_7
( L_28 ) ;
V_6 -> V_26 = false ;
F_21 ( V_6 ) ;
F_37 ( V_6 ) ;
}
if ( V_6 -> V_61 )
V_6 -> V_81 ( V_6 -> V_20 , V_6 -> V_61 ) ;
break;
default:
break;
}
F_48 ( & V_6 -> V_78 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
F_50 ( V_51 ) ;
F_7 ( L_14 ) ;
F_45 ( & V_6 -> V_78 ) ;
V_6 -> V_32 = V_59 ;
V_6 -> V_51 = & V_51 ;
V_6 -> V_63 = 0 ;
V_6 -> V_50 = 1 ;
F_48 ( & V_6 -> V_78 ) ;
F_40 ( & V_6 -> V_75 ) ;
F_51 ( V_51 , V_6 -> V_50 != 1 ) ;
return V_6 -> V_50 ;
}
static void F_52 ( struct V_5 * V_6 )
{
F_7 ( L_14 ) ;
F_45 ( & V_6 -> V_78 ) ;
V_6 -> V_32 = V_49 ;
F_48 ( & V_6 -> V_78 ) ;
F_40 ( & V_6 -> V_75 ) ;
}
static void F_53 ( struct V_5 * V_6 , struct V_4 * V_8 )
{
if ( V_8 == NULL ) {
F_35 ( L_29 ) ;
V_6 -> V_61 = - V_82 ;
} else {
F_38 ( L_30 , V_8 ) ;
F_27 ( & V_6 -> V_65 , V_8 ) ;
}
F_40 ( & V_6 -> V_75 ) ;
}
static void * F_54 ( struct V_83 * V_20 , T_1 V_19 ,
T_2 V_40 , int V_9 ,
int V_11 , int * V_84 , int * V_85 ,
T_3 V_81 )
{
struct V_5 * V_6 ;
* V_84 = V_10 ;
* V_85 = 0 ;
V_6 = F_55 ( sizeof( struct V_5 ) , V_12 ) ;
if ( V_6 == NULL )
return NULL ;
F_56 ( & V_6 -> V_78 ) ;
V_6 -> V_32 = V_49 ;
F_57 ( & V_6 -> V_47 ) ;
V_6 -> V_47 . V_60 = ( unsigned long ) V_6 ;
V_6 -> V_47 . V_86 = F_39 ;
F_57 ( & V_6 -> V_36 ) ;
V_6 -> V_36 . V_60 = ( unsigned long ) V_6 ;
V_6 -> V_36 . V_86 = F_41 ;
F_57 ( & V_6 -> V_27 ) ;
V_6 -> V_27 . V_60 = ( unsigned long ) V_6 ;
V_6 -> V_27 . V_86 = F_42 ;
V_6 -> V_38 = V_52 ;
V_6 -> V_57 = V_53 ;
F_58 ( & V_6 -> V_65 ) ;
F_58 ( & V_6 -> V_41 ) ;
F_58 ( & V_6 -> V_25 ) ;
F_59 ( & V_6 -> V_75 , F_43 ) ;
V_6 -> V_20 = V_20 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_40 = V_40 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_81 = V_81 ;
return V_6 ;
}
static void F_60 ( struct V_87 * V_88 )
{
struct V_5 * V_6 = F_61 ( V_88 ) ;
F_46 ( & V_6 -> V_65 ) ;
F_46 ( & V_6 -> V_41 ) ;
F_46 ( & V_6 -> V_25 ) ;
F_62 ( V_6 ) ;
}
static int F_63 ( struct V_87 * V_88 )
{
struct V_5 * V_6 = F_61 ( V_88 ) ;
return F_49 ( V_6 ) ;
}
static int F_64 ( struct V_87 * V_88 )
{
struct V_5 * V_6 = F_61 ( V_88 ) ;
F_52 ( V_6 ) ;
return 0 ;
}
static void F_65 ( struct V_87 * V_88 , struct V_4 * V_8 )
{
struct V_5 * V_6 = F_61 ( V_88 ) ;
F_53 ( V_6 , V_8 ) ;
}
static int F_66 ( struct V_87 * V_88 , struct V_4 * V_8 )
{
struct V_5 * V_6 = F_61 ( V_88 ) ;
F_27 ( & V_6 -> V_41 , V_8 ) ;
F_40 ( & V_6 -> V_75 ) ;
return 0 ;
}
int F_67 ( void )
{
return F_68 ( V_89 , & V_90 ) ;
}
