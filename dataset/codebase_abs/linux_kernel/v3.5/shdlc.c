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
V_6 -> V_11 + V_12 +
V_7 , V_13 ) ;
if ( V_8 )
F_5 ( V_8 , V_6 -> V_9 + V_10 ) ;
return V_8 ;
}
static void F_6 ( struct V_4 * V_8 )
{
T_1 V_14 ;
int V_15 ;
V_15 = V_8 -> V_15 + 2 ;
* F_7 ( V_8 , 1 ) = V_15 ;
V_14 = F_8 ( 0xffff , V_8 -> V_16 , V_8 -> V_15 ) ;
V_14 = ~ V_14 ;
* F_9 ( V_8 , 1 ) = V_14 & 0xff ;
* F_9 ( V_8 , 1 ) = V_14 >> 8 ;
}
static int F_10 ( struct V_5 * V_6 ,
enum V_17 V_17 , int V_18 )
{
int V_19 ;
struct V_4 * V_8 ;
F_11 ( L_1 , V_17 , V_18 ) ;
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 == NULL )
return - V_20 ;
* F_7 ( V_8 , 1 ) = V_21 | ( V_17 << 3 ) | V_18 ;
F_6 ( V_8 ) ;
V_19 = V_6 -> V_22 -> V_23 ( V_6 , V_8 ) ;
F_12 ( V_8 ) ;
return V_19 ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_4 * V_8 ,
enum V_24 V_24 )
{
int V_19 ;
F_11 ( L_2 , V_24 ) ;
* F_7 ( V_8 , 1 ) = V_25 | V_24 ;
F_6 ( V_8 ) ;
V_19 = V_6 -> V_22 -> V_23 ( V_6 , V_8 ) ;
F_12 ( V_8 ) ;
return V_19 ;
}
static void F_14 ( struct V_5 * V_6 , int V_26 )
{
struct V_4 * V_8 ;
int V_27 = V_6 -> V_27 ;
F_11 ( L_3 , V_26 ) ;
while ( V_27 != V_26 ) {
F_11 ( L_4 , V_27 ) ;
V_8 = F_15 ( & V_6 -> V_28 ) ;
F_12 ( V_8 ) ;
V_27 = ( V_27 + 1 ) % 8 ;
}
if ( F_16 ( & V_6 -> V_28 ) ) {
if ( V_6 -> V_29 ) {
F_17 ( & V_6 -> V_30 ) ;
V_6 -> V_29 = false ;
F_11
( L_5 ) ;
}
} else {
V_8 = F_18 ( & V_6 -> V_28 ) ;
F_19 ( & V_6 -> V_30 , * ( unsigned long * ) V_8 -> V_31 +
F_20 ( V_32 ) ) ;
V_6 -> V_29 = true ;
F_11
( L_6 ) ;
}
}
static void F_21 ( struct V_5 * V_6 ,
struct V_4 * V_8 , int V_33 , int V_18 )
{
int V_34 = V_33 ;
int V_26 = V_18 ;
F_11 ( L_7 , V_33 , V_18 ) ;
if ( V_6 -> V_35 != V_36 )
goto exit;
if ( V_34 != V_6 -> V_18 ) {
F_10 ( V_6 , V_37 , V_6 -> V_18 ) ;
goto exit;
}
if ( V_6 -> V_38 == false ) {
V_6 -> V_38 = true ;
F_19 ( & V_6 -> V_39 ,
F_20 ( F_22 ( V_6 -> V_40 ) ) ) ;
F_11 ( L_8 ) ;
}
if ( V_8 -> V_15 ) {
F_23 ( V_6 -> V_41 , V_8 ) ;
V_8 = NULL ;
}
V_6 -> V_18 = ( V_6 -> V_18 + 1 ) % 8 ;
if ( F_1 ( V_6 -> V_27 , V_26 , V_6 -> V_33 ) ) {
F_14 ( V_6 , V_26 ) ;
V_6 -> V_27 = V_26 ;
}
exit:
if ( V_8 )
F_12 ( V_8 ) ;
}
static void F_24 ( struct V_5 * V_6 , int V_26 )
{
F_11 ( L_9 , V_26 ) ;
if ( F_1 ( V_6 -> V_27 , V_26 , V_6 -> V_33 ) ) {
F_14 ( V_6 , V_26 ) ;
V_6 -> V_27 = V_26 ;
}
}
static void F_25 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_11 ( L_10 , V_6 -> V_27 ) ;
while ( ( V_8 = F_26 ( & V_6 -> V_28 ) ) ) {
F_27 ( V_8 , 2 ) ;
F_28 ( V_8 , V_8 -> V_15 - 2 ) ;
F_29 ( & V_6 -> V_42 , V_8 ) ;
}
V_6 -> V_33 = V_6 -> V_27 ;
}
static void F_30 ( struct V_5 * V_6 , int V_26 )
{
struct V_4 * V_8 ;
F_11 ( L_11 , V_26 ) ;
if ( F_2 ( V_6 -> V_27 , V_26 , V_6 -> V_33 ) ) {
if ( V_6 -> V_29 ) {
F_17 ( & V_6 -> V_30 ) ;
V_6 -> V_29 = false ;
F_11 ( L_12 ) ;
}
if ( V_6 -> V_27 != V_26 ) {
while ( ( V_6 -> V_27 = ( ( V_6 -> V_27 + 1 ) % 8 ) ) != V_26 ) {
V_8 = F_15 ( & V_6 -> V_28 ) ;
F_12 ( V_8 ) ;
}
}
F_25 ( V_6 ) ;
}
}
static void F_31 ( struct V_5 * V_6 ,
enum V_17 V_43 , int V_18 )
{
struct V_4 * V_8 ;
if ( V_6 -> V_35 != V_36 )
return;
switch ( V_43 ) {
case V_44 :
F_24 ( V_6 , V_18 ) ;
if ( V_6 -> V_45 == true ) {
V_6 -> V_45 = false ;
if ( V_6 -> V_42 . V_46 == 0 ) {
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 )
F_32 ( & V_6 -> V_42 , V_8 ) ;
}
}
break;
case V_37 :
F_30 ( V_6 , V_18 ) ;
break;
case V_47 :
F_24 ( V_6 , V_18 ) ;
V_6 -> V_45 = true ;
break;
default:
break;
}
}
static void F_33 ( struct V_5 * V_6 , int V_19 )
{
F_11 ( L_13 , V_19 ) ;
F_17 ( & V_6 -> V_48 ) ;
if ( V_19 == 0 ) {
V_6 -> V_33 = 0 ;
V_6 -> V_18 = 0 ;
V_6 -> V_27 = 0 ;
V_6 -> V_35 = V_36 ;
} else {
V_6 -> V_35 = V_49 ;
}
V_6 -> V_50 = V_19 ;
F_34 ( V_6 -> V_51 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_11 ( L_14 ) ;
V_8 = F_3 ( V_6 , 2 ) ;
if ( V_8 == NULL )
return - V_20 ;
* F_9 ( V_8 , 1 ) = V_52 ;
* F_9 ( V_8 , 1 ) = V_53 ? 1 : 0 ;
return F_13 ( V_6 , V_8 , V_54 ) ;
}
static int F_36 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
F_11 ( L_14 ) ;
V_8 = F_3 ( V_6 , 0 ) ;
if ( V_8 == NULL )
return - V_20 ;
return F_13 ( V_6 , V_8 , V_55 ) ;
}
static void F_37 ( struct V_5 * V_6 ,
struct V_4 * V_8 ,
enum V_24 V_56 )
{
T_2 V_40 = V_52 ;
bool V_57 = V_53 ;
int V_19 ;
F_11 ( L_15 , V_56 ) ;
switch ( V_56 ) {
case V_54 :
if ( V_6 -> V_35 == V_58 ) {
if ( V_8 -> V_15 > 0 )
V_40 = V_8 -> V_16 [ 0 ] ;
if ( V_8 -> V_15 > 1 )
V_57 = V_8 -> V_16 [ 1 ] & 0x01 ? true :
false ;
if ( ( V_40 <= V_52 ) &&
( V_53 || ( V_57 == false ) ) ) {
V_6 -> V_40 = V_40 ;
V_6 -> V_57 = V_57 ;
V_19 = F_36 ( V_6 ) ;
F_33 ( V_6 , V_19 ) ;
}
} else if ( V_6 -> V_35 > V_58 ) {
}
break;
case V_55 :
if ( ( V_6 -> V_35 == V_59 &&
V_6 -> V_60 > 0 ) ||
( V_6 -> V_35 == V_58 ) )
F_33 ( V_6 , 0 ) ;
break;
default:
break;
}
F_12 ( V_8 ) ;
}
static void F_38 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
T_2 V_61 ;
int V_18 ;
int V_33 ;
enum V_17 V_43 ;
enum V_24 V_56 ;
if ( V_6 -> V_62 . V_46 )
F_11 ( L_16 , V_6 -> V_62 . V_46 ) ;
while ( ( V_8 = F_15 ( & V_6 -> V_62 ) ) != NULL ) {
V_61 = V_8 -> V_16 [ 0 ] ;
F_27 ( V_8 , 1 ) ;
switch ( V_61 & V_63 ) {
case V_64 :
case V_65 :
V_33 = ( V_61 & V_66 ) >> 3 ;
V_18 = V_61 & V_67 ;
F_21 ( V_6 , V_8 , V_33 , V_18 ) ;
break;
case V_21 :
V_43 = ( V_61 & V_68 ) >> 3 ;
V_18 = V_61 & V_67 ;
F_31 ( V_6 , V_43 , V_18 ) ;
F_12 ( V_8 ) ;
break;
case V_25 :
V_56 = V_61 & V_69 ;
F_37 ( V_6 , V_8 , V_56 ) ;
break;
default:
F_39 ( L_17 , V_61 ) ;
F_12 ( V_8 ) ;
break;
}
}
}
static int F_40 ( int V_33 , int V_27 )
{
int V_70 ;
if ( V_27 <= V_33 )
V_70 = V_33 - V_27 ;
else
V_70 = 8 - V_27 + V_33 ;
return V_70 ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_4 * V_8 ;
int V_19 ;
unsigned long V_71 ;
if ( V_6 -> V_42 . V_46 )
F_11
( L_18 ,
V_6 -> V_42 . V_46 , V_6 -> V_33 , V_6 -> V_27 ,
V_6 -> V_45 == false ? L_19 : L_20 ,
V_6 -> V_40 - F_40 ( V_6 -> V_33 , V_6 -> V_27 ) ,
V_6 -> V_28 . V_46 ) ;
while ( V_6 -> V_42 . V_46 && V_6 -> V_28 . V_46 < V_6 -> V_40 &&
( V_6 -> V_45 == false ) ) {
if ( V_6 -> V_38 ) {
F_17 ( & V_6 -> V_39 ) ;
V_6 -> V_38 = false ;
F_11 ( L_21 ) ;
}
V_8 = F_15 ( & V_6 -> V_42 ) ;
* F_7 ( V_8 , 1 ) = V_64 | ( V_6 -> V_33 << 3 ) |
V_6 -> V_18 ;
F_11 ( L_22 , V_6 -> V_33 ,
V_6 -> V_18 ) ;
F_6 ( V_8 ) ;
V_19 = V_6 -> V_22 -> V_23 ( V_6 , V_8 ) ;
if ( V_19 < 0 ) {
V_6 -> V_72 = V_19 ;
break;
}
V_6 -> V_33 = ( V_6 -> V_33 + 1 ) % 8 ;
V_71 = V_73 ;
* ( unsigned long * ) V_8 -> V_31 = V_71 ;
F_32 ( & V_6 -> V_28 , V_8 ) ;
if ( V_6 -> V_29 == false ) {
V_6 -> V_29 = true ;
F_19 ( & V_6 -> V_30 , V_71 +
F_20 ( V_32 ) ) ;
F_11 ( L_23 ) ;
}
}
}
static void F_42 ( unsigned long V_16 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 ;
F_11 ( L_14 ) ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
}
static void F_44 ( unsigned long V_16 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 ;
F_11 ( L_24 ) ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
}
static void F_45 ( unsigned long V_16 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 ;
F_11 ( L_25 ) ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
}
static void F_46 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_47 ( V_77 , struct V_5 , V_75 ) ;
int V_19 ;
F_11 ( L_14 ) ;
F_48 ( & V_6 -> V_78 ) ;
switch ( V_6 -> V_35 ) {
case V_49 :
F_49 ( & V_6 -> V_62 ) ;
F_49 ( & V_6 -> V_42 ) ;
F_49 ( & V_6 -> V_28 ) ;
break;
case V_59 :
if ( V_6 -> V_60 ++ < 5 )
V_19 = F_35 ( V_6 ) ;
else
V_19 = - V_79 ;
if ( V_19 < 0 )
F_33 ( V_6 , V_19 ) ;
else {
F_19 ( & V_6 -> V_48 , V_73 +
F_20 ( V_80 ) ) ;
V_6 -> V_35 = V_58 ;
}
break;
case V_58 :
if ( F_50 ( & V_6 -> V_48 ) == 0 ) {
V_6 -> V_35 = V_59 ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
}
F_38 ( V_6 ) ;
break;
case V_36 :
F_38 ( V_6 ) ;
F_41 ( V_6 ) ;
if ( V_6 -> V_38 && F_50 ( & V_6 -> V_39 ) == 0 ) {
F_11
( L_26 ) ;
V_6 -> V_38 = false ;
V_19 = F_10 ( V_6 , V_44 ,
V_6 -> V_18 ) ;
if ( V_19 < 0 )
V_6 -> V_72 = V_19 ;
}
if ( V_6 -> V_29 && F_50 ( & V_6 -> V_30 ) == 0 ) {
F_11
( L_27 ) ;
V_6 -> V_29 = false ;
F_25 ( V_6 ) ;
F_41 ( V_6 ) ;
}
if ( V_6 -> V_72 ) {
}
break;
default:
break;
}
F_51 ( & V_6 -> V_78 ) ;
}
static int F_52 ( struct V_5 * V_6 )
{
F_53 ( V_51 ) ;
F_11 ( L_14 ) ;
F_48 ( & V_6 -> V_78 ) ;
V_6 -> V_35 = V_59 ;
V_6 -> V_51 = & V_51 ;
V_6 -> V_60 = 0 ;
V_6 -> V_50 = 1 ;
F_51 ( & V_6 -> V_78 ) ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
F_54 ( V_51 , V_6 -> V_50 != 1 ) ;
return V_6 -> V_50 ;
}
static void F_55 ( struct V_5 * V_6 )
{
F_11 ( L_14 ) ;
F_48 ( & V_6 -> V_78 ) ;
V_6 -> V_35 = V_49 ;
F_51 ( & V_6 -> V_78 ) ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
}
void F_56 ( struct V_5 * V_6 , struct V_4 * V_8 )
{
if ( V_8 == NULL ) {
F_39 ( L_28 ) ;
V_6 -> V_72 = - V_81 ;
} else {
F_57 ( L_29 , V_8 ) ;
F_32 ( & V_6 -> V_62 , V_8 ) ;
}
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
}
static int F_58 ( struct V_82 * V_41 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
int V_19 ;
F_11 ( L_14 ) ;
if ( V_6 -> V_22 -> V_83 ) {
V_19 = V_6 -> V_22 -> V_83 ( V_6 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_19 = F_52 ( V_6 ) ;
if ( V_19 < 0 && V_6 -> V_22 -> V_84 )
V_6 -> V_22 -> V_84 ( V_6 ) ;
return V_19 ;
}
static void F_60 ( struct V_82 * V_41 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
F_11 ( L_14 ) ;
F_55 ( V_6 ) ;
if ( V_6 -> V_22 -> V_84 )
V_6 -> V_22 -> V_84 ( V_6 ) ;
}
static int F_61 ( struct V_82 * V_41 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
int V_19 = 0 ;
F_11 ( L_14 ) ;
if ( V_6 -> V_22 -> V_85 )
V_19 = V_6 -> V_22 -> V_85 ( V_6 ) ;
return V_19 ;
}
static int F_62 ( struct V_82 * V_41 , struct V_4 * V_8 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
F_57 ( L_30 , V_8 ) ;
F_32 ( & V_6 -> V_42 , V_8 ) ;
F_43 ( V_6 -> V_74 , & V_6 -> V_75 ) ;
return 0 ;
}
static int F_63 ( struct V_82 * V_41 , T_3 V_86 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
F_11 ( L_14 ) ;
if ( V_6 -> V_22 -> V_87 )
return V_6 -> V_22 -> V_87 ( V_6 , V_86 ) ;
return 0 ;
}
static int F_64 ( struct V_82 * V_41 , T_2 V_88 ,
struct V_89 * V_90 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
if ( V_6 -> V_22 -> V_91 )
return V_6 -> V_22 -> V_91 ( V_6 , V_88 , V_90 ) ;
return - V_92 ;
}
static int F_65 ( struct V_82 * V_41 ,
T_2 V_88 ,
struct V_89 * V_90 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
F_11 ( L_14 ) ;
if ( V_6 -> V_22 -> V_93 )
return V_6 -> V_22 -> V_93 ( V_6 , V_88 ,
V_90 ) ;
return 0 ;
}
static int F_66 ( struct V_82 * V_41 ,
struct V_89 * V_90 ,
struct V_4 * V_8 ,
struct V_4 * * V_94 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
if ( V_6 -> V_22 -> V_95 )
return V_6 -> V_22 -> V_95 ( V_6 , V_90 , V_8 , V_94 ) ;
return - V_92 ;
}
static int F_67 ( struct V_82 * V_41 ,
struct V_89 * V_90 )
{
struct V_5 * V_6 = F_59 ( V_41 ) ;
if ( V_6 -> V_22 -> V_96 )
return V_6 -> V_22 -> V_96 ( V_6 , V_90 ) ;
return 0 ;
}
struct V_5 * F_68 ( struct V_97 * V_22 ,
struct V_98 * V_99 ,
T_3 V_86 ,
int V_100 , int V_101 ,
int V_102 , const char * V_103 )
{
struct V_5 * V_6 ;
int V_19 ;
char V_104 [ 32 ] ;
if ( V_22 -> V_23 == NULL )
return NULL ;
V_6 = F_69 ( sizeof( struct V_5 ) , V_13 ) ;
if ( V_6 == NULL )
return NULL ;
F_70 ( & V_6 -> V_78 ) ;
V_6 -> V_22 = V_22 ;
V_6 -> V_35 = V_49 ;
F_71 ( & V_6 -> V_48 ) ;
V_6 -> V_48 . V_16 = ( unsigned long ) V_6 ;
V_6 -> V_48 . V_105 = F_42 ;
F_71 ( & V_6 -> V_39 ) ;
V_6 -> V_39 . V_16 = ( unsigned long ) V_6 ;
V_6 -> V_39 . V_105 = F_44 ;
F_71 ( & V_6 -> V_30 ) ;
V_6 -> V_30 . V_16 = ( unsigned long ) V_6 ;
V_6 -> V_30 . V_105 = F_45 ;
V_6 -> V_40 = V_52 ;
V_6 -> V_57 = V_53 ;
F_72 ( & V_6 -> V_62 ) ;
F_72 ( & V_6 -> V_42 ) ;
F_72 ( & V_6 -> V_28 ) ;
F_73 ( & V_6 -> V_75 , F_46 ) ;
snprintf ( V_104 , sizeof( V_104 ) , L_31 , V_103 ) ;
V_6 -> V_74 = F_74 ( V_104 , V_106 | V_107 |
V_108 , 1 ) ;
if ( V_6 -> V_74 == NULL )
goto V_109;
V_6 -> V_9 = V_100 ;
V_6 -> V_11 = V_101 ;
V_6 -> V_41 = F_75 ( & V_110 , V_99 , V_86 ,
V_100 + V_10 ,
V_101 + V_12 ,
V_102 ) ;
if ( V_6 -> V_41 == NULL )
goto V_111;
F_76 ( V_6 -> V_41 , V_6 ) ;
V_19 = F_77 ( V_6 -> V_41 ) ;
if ( V_19 < 0 )
goto V_112;
return V_6 ;
V_112:
F_78 ( V_6 -> V_41 ) ;
V_111:
F_79 ( V_6 -> V_74 ) ;
V_109:
F_80 ( V_6 ) ;
return NULL ;
}
void F_81 ( struct V_5 * V_6 )
{
F_11 ( L_14 ) ;
F_82 ( V_6 -> V_41 ) ;
F_78 ( V_6 -> V_41 ) ;
F_79 ( V_6 -> V_74 ) ;
F_49 ( & V_6 -> V_62 ) ;
F_49 ( & V_6 -> V_42 ) ;
F_49 ( & V_6 -> V_28 ) ;
F_80 ( V_6 ) ;
}
void F_83 ( struct V_5 * V_6 , void * V_113 )
{
F_11 ( L_14 ) ;
V_6 -> V_113 = V_113 ;
}
void * F_84 ( struct V_5 * V_6 )
{
return V_6 -> V_113 ;
}
struct V_82 * F_85 ( struct V_5 * V_6 )
{
return V_6 -> V_41 ;
}
