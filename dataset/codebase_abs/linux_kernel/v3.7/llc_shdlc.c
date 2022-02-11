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
* F_8 ( V_8 , 1 ) = V_17 | ( V_13 << 3 ) | V_14 ;
V_15 = V_6 -> V_18 ( V_6 -> V_19 , V_8 ) ;
F_9 ( V_8 ) ;
return V_15 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_4 * V_8 ,
enum V_20 V_20 )
{
int V_15 ;
F_7 ( L_2 , V_20 ) ;
* F_8 ( V_8 , 1 ) = V_21 | V_20 ;
V_15 = V_6 -> V_18 ( V_6 -> V_19 , V_8 ) ;
F_9 ( V_8 ) ;
return V_15 ;
}
static void F_11 ( struct V_5 * V_6 , int V_22 )
{
struct V_4 * V_8 ;
int V_23 = V_6 -> V_23 ;
F_7 ( L_3 , V_22 ) ;
while ( V_23 != V_22 ) {
F_7 ( L_4 , V_23 ) ;
V_8 = F_12 ( & V_6 -> V_24 ) ;
F_9 ( V_8 ) ;
V_23 = ( V_23 + 1 ) % 8 ;
}
if ( F_13 ( & V_6 -> V_24 ) ) {
if ( V_6 -> V_25 ) {
F_14 ( & V_6 -> V_26 ) ;
V_6 -> V_25 = false ;
F_7
( L_5 ) ;
}
} else {
V_8 = F_15 ( & V_6 -> V_24 ) ;
F_16 ( & V_6 -> V_26 , * ( unsigned long * ) V_8 -> V_27 +
F_17 ( V_28 ) ) ;
V_6 -> V_25 = true ;
F_7
( L_6 ) ;
}
}
static void F_18 ( struct V_5 * V_6 ,
struct V_4 * V_8 , int V_29 , int V_14 )
{
int V_30 = V_29 ;
int V_22 = V_14 ;
F_7 ( L_7 , V_29 , V_14 ) ;
if ( V_6 -> V_31 != V_32 )
goto exit;
if ( V_30 != V_6 -> V_14 ) {
F_6 ( V_6 , V_33 , V_6 -> V_14 ) ;
goto exit;
}
if ( V_6 -> V_34 == false ) {
V_6 -> V_34 = true ;
F_16 ( & V_6 -> V_35 , V_36 +
F_17 ( F_19 ( V_6 -> V_37 ) ) ) ;
F_7 ( L_8 ) ;
}
if ( V_8 -> V_38 ) {
V_6 -> V_39 ( V_6 -> V_19 , V_8 ) ;
V_8 = NULL ;
}
V_6 -> V_14 = ( V_6 -> V_14 + 1 ) % 8 ;
if ( F_1 ( V_6 -> V_23 , V_22 , V_6 -> V_29 ) ) {
F_11 ( V_6 , V_22 ) ;
V_6 -> V_23 = V_22 ;
}
exit:
F_9 ( V_8 ) ;
}
static void F_20 ( struct V_5 * V_6 , int V_22 )
{
F_7 ( L_9 , V_22 ) ;
if ( F_1 ( V_6 -> V_23 , V_22 , V_6 -> V_29 ) ) {
F_11 ( V_6 , V_22 ) ;
V_6 -> V_23 = V_22 ;
}
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_7 ( L_10 , V_6 -> V_23 ) ;
while ( ( V_8 = F_22 ( & V_6 -> V_24 ) ) ) {
F_23 ( V_8 , 1 ) ;
F_24 ( & V_6 -> V_40 , V_8 ) ;
}
V_6 -> V_29 = V_6 -> V_23 ;
}
static void F_25 ( struct V_5 * V_6 , int V_22 )
{
struct V_4 * V_8 ;
F_7 ( L_11 , V_22 ) ;
if ( F_2 ( V_6 -> V_23 , V_22 , V_6 -> V_29 ) ) {
if ( V_6 -> V_25 ) {
F_14 ( & V_6 -> V_26 ) ;
V_6 -> V_25 = false ;
F_7 ( L_12 ) ;
}
if ( V_6 -> V_23 != V_22 ) {
while ( ( V_6 -> V_23 = ( ( V_6 -> V_23 + 1 ) % 8 ) ) != V_22 ) {
V_8 = F_12 ( & V_6 -> V_24 ) ;
F_9 ( V_8 ) ;
}
}
F_21 ( V_6 ) ;
}
}
static void F_26 ( struct V_5 * V_6 ,
enum V_13 V_41 , int V_14 )
{
struct V_4 * V_8 ;
if ( V_6 -> V_31 != V_32 )
return;
switch ( V_41 ) {
case V_42 :
F_20 ( V_6 , V_14 ) ;
if ( V_6 -> V_43 == true ) {
V_6 -> V_43 = false ;
if ( V_6 -> V_40 . V_44 == 0 ) {
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 )
F_27 ( & V_6 -> V_40 , V_8 ) ;
}
}
break;
case V_33 :
F_25 ( V_6 , V_14 ) ;
break;
case V_45 :
F_20 ( V_6 , V_14 ) ;
V_6 -> V_43 = true ;
break;
default:
break;
}
}
static void F_28 ( struct V_5 * V_6 , int V_15 )
{
F_7 ( L_13 , V_15 ) ;
F_14 ( & V_6 -> V_46 ) ;
if ( V_15 == 0 ) {
V_6 -> V_29 = 0 ;
V_6 -> V_14 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_31 = V_47 ;
} else {
V_6 -> V_31 = V_48 ;
}
V_6 -> V_49 = V_15 ;
F_29 ( V_6 -> V_50 ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_7 ( L_14 ) ;
V_8 = F_3 ( V_6 , 2 ) ;
if ( V_8 == NULL )
return - V_16 ;
* F_31 ( V_8 , 1 ) = V_51 ;
* F_31 ( V_8 , 1 ) = V_52 ? 1 : 0 ;
return F_10 ( V_6 , V_8 , V_53 ) ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_7 ( L_14 ) ;
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 == NULL )
return - V_16 ;
return F_10 ( V_6 , V_8 , V_54 ) ;
}
static void F_33 ( struct V_5 * V_6 ,
struct V_4 * V_8 ,
enum V_20 V_55 )
{
T_1 V_37 = V_51 ;
bool V_56 = V_52 ;
int V_15 ;
F_7 ( L_15 , V_55 ) ;
switch ( V_55 ) {
case V_53 :
switch ( V_6 -> V_31 ) {
case V_57 :
case V_58 :
if ( V_8 -> V_38 > 0 )
V_37 = V_8 -> V_59 [ 0 ] ;
if ( V_8 -> V_38 > 1 )
V_56 = V_8 -> V_59 [ 1 ] & 0x01 ? true :
false ;
if ( ( V_37 <= V_51 ) &&
( V_52 || ( V_56 == false ) ) ) {
V_6 -> V_37 = V_37 ;
V_6 -> V_56 = V_56 ;
V_15 = F_32 ( V_6 ) ;
F_28 ( V_6 , V_15 ) ;
}
break;
case V_47 :
break;
case V_32 :
V_6 -> V_60 = - V_61 ;
break;
default:
break;
}
break;
case V_54 :
if ( ( V_6 -> V_31 == V_58 &&
V_6 -> V_62 > 0 ) ||
( V_6 -> V_31 == V_57 ) ) {
F_28 ( V_6 , 0 ) ;
V_6 -> V_31 = V_32 ;
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
T_1 V_63 ;
int V_14 ;
int V_29 ;
enum V_13 V_41 ;
enum V_20 V_55 ;
if ( V_6 -> V_64 . V_44 )
F_7 ( L_16 , V_6 -> V_64 . V_44 ) ;
while ( ( V_8 = F_12 ( & V_6 -> V_64 ) ) != NULL ) {
V_63 = V_8 -> V_59 [ 0 ] ;
F_23 ( V_8 , 1 ) ;
switch ( V_63 & V_65 ) {
case V_66 :
case V_67 :
if ( V_6 -> V_31 == V_47 )
V_6 -> V_31 = V_32 ;
V_29 = ( V_63 & V_68 ) >> 3 ;
V_14 = V_63 & V_69 ;
F_18 ( V_6 , V_8 , V_29 , V_14 ) ;
break;
case V_17 :
if ( V_6 -> V_31 == V_47 )
V_6 -> V_31 = V_32 ;
V_41 = ( V_63 & V_70 ) >> 3 ;
V_14 = V_63 & V_69 ;
F_26 ( V_6 , V_41 , V_14 ) ;
F_9 ( V_8 ) ;
break;
case V_21 :
V_55 = V_63 & V_71 ;
F_33 ( V_6 , V_8 , V_55 ) ;
break;
default:
F_35 ( L_17 , V_63 ) ;
F_9 ( V_8 ) ;
break;
}
}
}
static int F_36 ( int V_29 , int V_23 )
{
int V_72 ;
if ( V_23 <= V_29 )
V_72 = V_29 - V_23 ;
else
V_72 = 8 - V_23 + V_29 ;
return V_72 ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
int V_15 ;
unsigned long V_73 ;
if ( V_6 -> V_40 . V_44 )
F_7
( L_18 ,
V_6 -> V_40 . V_44 , V_6 -> V_29 , V_6 -> V_23 ,
V_6 -> V_43 == false ? L_19 : L_20 ,
V_6 -> V_37 - F_36 ( V_6 -> V_29 , V_6 -> V_23 ) ,
V_6 -> V_24 . V_44 ) ;
while ( V_6 -> V_40 . V_44 && V_6 -> V_24 . V_44 < V_6 -> V_37 &&
( V_6 -> V_43 == false ) ) {
if ( V_6 -> V_34 ) {
F_14 ( & V_6 -> V_35 ) ;
V_6 -> V_34 = false ;
F_7 ( L_21 ) ;
}
V_8 = F_12 ( & V_6 -> V_40 ) ;
* F_8 ( V_8 , 1 ) = V_66 | ( V_6 -> V_29 << 3 ) |
V_6 -> V_14 ;
F_7 ( L_22 , V_6 -> V_29 ,
V_6 -> V_14 ) ;
F_38 ( L_23 , V_8 ) ;
V_15 = V_6 -> V_18 ( V_6 -> V_19 , V_8 ) ;
if ( V_15 < 0 ) {
V_6 -> V_60 = V_15 ;
break;
}
V_6 -> V_29 = ( V_6 -> V_29 + 1 ) % 8 ;
V_73 = V_36 ;
* ( unsigned long * ) V_8 -> V_27 = V_73 ;
F_27 ( & V_6 -> V_24 , V_8 ) ;
if ( V_6 -> V_25 == false ) {
V_6 -> V_25 = true ;
F_16 ( & V_6 -> V_26 , V_73 +
F_17 ( V_28 ) ) ;
F_7 ( L_24 ) ;
}
}
}
static void F_39 ( unsigned long V_59 )
{
struct V_5 * V_6 = (struct V_5 * ) V_59 ;
F_7 ( L_14 ) ;
F_40 ( & V_6 -> V_74 ) ;
}
static void F_41 ( unsigned long V_59 )
{
struct V_5 * V_6 = (struct V_5 * ) V_59 ;
F_7 ( L_25 ) ;
F_40 ( & V_6 -> V_74 ) ;
}
static void F_42 ( unsigned long V_59 )
{
struct V_5 * V_6 = (struct V_5 * ) V_59 ;
F_7 ( L_26 ) ;
F_40 ( & V_6 -> V_74 ) ;
}
static void F_43 ( struct V_75 * V_76 )
{
struct V_5 * V_6 = F_44 ( V_76 , struct V_5 , V_74 ) ;
int V_15 ;
F_7 ( L_14 ) ;
F_45 ( & V_6 -> V_77 ) ;
switch ( V_6 -> V_31 ) {
case V_48 :
F_46 ( & V_6 -> V_64 ) ;
F_46 ( & V_6 -> V_40 ) ;
F_46 ( & V_6 -> V_24 ) ;
break;
case V_58 :
if ( V_6 -> V_60 ) {
F_28 ( V_6 , V_6 -> V_60 ) ;
break;
}
if ( V_6 -> V_62 ++ < 5 )
V_15 = F_30 ( V_6 ) ;
else
V_15 = - V_78 ;
if ( V_15 < 0 )
F_28 ( V_6 , V_15 ) ;
else {
F_16 ( & V_6 -> V_46 , V_36 +
F_17 ( V_79 ) ) ;
V_6 -> V_31 = V_57 ;
}
break;
case V_57 :
if ( F_47 ( & V_6 -> V_46 ) == 0 ) {
V_6 -> V_31 = V_58 ;
F_40 ( & V_6 -> V_74 ) ;
}
F_34 ( V_6 ) ;
if ( V_6 -> V_60 ) {
F_28 ( V_6 , V_6 -> V_60 ) ;
break;
}
break;
case V_47 :
case V_32 :
F_34 ( V_6 ) ;
F_37 ( V_6 ) ;
if ( V_6 -> V_34 && F_47 ( & V_6 -> V_35 ) == 0 ) {
F_7
( L_27 ) ;
V_6 -> V_34 = false ;
V_15 = F_6 ( V_6 , V_42 ,
V_6 -> V_14 ) ;
if ( V_15 < 0 )
V_6 -> V_60 = V_15 ;
}
if ( V_6 -> V_25 && F_47 ( & V_6 -> V_26 ) == 0 ) {
F_7
( L_28 ) ;
V_6 -> V_25 = false ;
F_21 ( V_6 ) ;
F_37 ( V_6 ) ;
}
if ( V_6 -> V_60 ) {
V_6 -> V_80 ( V_6 -> V_19 , V_6 -> V_60 ) ;
}
break;
default:
break;
}
F_48 ( & V_6 -> V_77 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
F_50 ( V_50 ) ;
F_7 ( L_14 ) ;
F_45 ( & V_6 -> V_77 ) ;
V_6 -> V_31 = V_58 ;
V_6 -> V_50 = & V_50 ;
V_6 -> V_62 = 0 ;
V_6 -> V_49 = 1 ;
F_48 ( & V_6 -> V_77 ) ;
F_40 ( & V_6 -> V_74 ) ;
F_51 ( V_50 , V_6 -> V_49 != 1 ) ;
return V_6 -> V_49 ;
}
static void F_52 ( struct V_5 * V_6 )
{
F_7 ( L_14 ) ;
F_45 ( & V_6 -> V_77 ) ;
V_6 -> V_31 = V_48 ;
F_48 ( & V_6 -> V_77 ) ;
F_40 ( & V_6 -> V_74 ) ;
}
static void F_53 ( struct V_5 * V_6 , struct V_4 * V_8 )
{
if ( V_8 == NULL ) {
F_35 ( L_29 ) ;
V_6 -> V_60 = - V_81 ;
} else {
F_38 ( L_30 , V_8 ) ;
F_27 ( & V_6 -> V_64 , V_8 ) ;
}
F_40 ( & V_6 -> V_74 ) ;
}
static void * F_54 ( struct V_82 * V_19 , T_2 V_18 ,
T_3 V_39 , int V_9 ,
int V_11 , int * V_83 , int * V_84 ,
T_4 V_80 )
{
struct V_5 * V_6 ;
* V_83 = V_10 ;
* V_84 = 0 ;
V_6 = F_55 ( sizeof( struct V_5 ) , V_12 ) ;
if ( V_6 == NULL )
return NULL ;
F_56 ( & V_6 -> V_77 ) ;
V_6 -> V_31 = V_48 ;
F_57 ( & V_6 -> V_46 ) ;
V_6 -> V_46 . V_59 = ( unsigned long ) V_6 ;
V_6 -> V_46 . V_85 = F_39 ;
F_57 ( & V_6 -> V_35 ) ;
V_6 -> V_35 . V_59 = ( unsigned long ) V_6 ;
V_6 -> V_35 . V_85 = F_41 ;
F_57 ( & V_6 -> V_26 ) ;
V_6 -> V_26 . V_59 = ( unsigned long ) V_6 ;
V_6 -> V_26 . V_85 = F_42 ;
V_6 -> V_37 = V_51 ;
V_6 -> V_56 = V_52 ;
F_58 ( & V_6 -> V_64 ) ;
F_58 ( & V_6 -> V_40 ) ;
F_58 ( & V_6 -> V_24 ) ;
F_59 ( & V_6 -> V_74 , F_43 ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_39 = V_39 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_80 = V_80 ;
return V_6 ;
}
static void F_60 ( struct V_86 * V_87 )
{
struct V_5 * V_6 = F_61 ( V_87 ) ;
F_46 ( & V_6 -> V_64 ) ;
F_46 ( & V_6 -> V_40 ) ;
F_46 ( & V_6 -> V_24 ) ;
F_62 ( V_6 ) ;
}
static int F_63 ( struct V_86 * V_87 )
{
struct V_5 * V_6 = F_61 ( V_87 ) ;
return F_49 ( V_6 ) ;
}
static int F_64 ( struct V_86 * V_87 )
{
struct V_5 * V_6 = F_61 ( V_87 ) ;
F_52 ( V_6 ) ;
return 0 ;
}
static void F_65 ( struct V_86 * V_87 , struct V_4 * V_8 )
{
struct V_5 * V_6 = F_61 ( V_87 ) ;
F_53 ( V_6 , V_8 ) ;
}
static int F_66 ( struct V_86 * V_87 , struct V_4 * V_8 )
{
struct V_5 * V_6 = F_61 ( V_87 ) ;
F_27 ( & V_6 -> V_40 , V_8 ) ;
F_40 ( & V_6 -> V_74 ) ;
return 0 ;
}
int F_67 ( void )
{
return F_68 ( V_88 , & V_89 ) ;
}
