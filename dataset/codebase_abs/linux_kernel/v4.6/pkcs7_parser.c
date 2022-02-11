static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 . V_4 ) ;
F_2 ( V_2 -> V_3 . V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 ) ;
}
}
void F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( V_8 ) {
while ( V_8 -> V_11 ) {
V_10 = V_8 -> V_11 ;
V_8 -> V_11 = V_10 -> V_12 ;
F_4 ( V_10 ) ;
}
while ( V_8 -> V_13 ) {
V_10 = V_8 -> V_13 ;
V_8 -> V_13 = V_10 -> V_12 ;
F_4 ( V_10 ) ;
}
while ( V_8 -> V_14 ) {
V_2 = V_8 -> V_14 ;
V_8 -> V_14 = V_2 -> V_12 ;
F_1 ( V_2 ) ;
}
F_2 ( V_8 ) ;
}
}
static int F_5 ( struct V_7 * V_15 )
{
struct V_1 * V_2 ;
bool V_16 = false ;
V_2 = V_15 -> V_14 ;
if ( V_2 -> V_17 ) {
V_16 = true ;
V_15 -> V_18 = true ;
}
for ( V_2 = V_2 -> V_12 ; V_2 ; V_2 = V_2 -> V_12 )
if ( ! ! V_2 -> V_17 != V_16 )
goto V_19;
return 0 ;
V_19:
F_6 ( L_1 ) ;
return - V_20 ;
}
struct V_7 * F_7 ( const void * V_21 , T_1 V_22 )
{
struct V_23 * V_24 ;
struct V_7 * V_15 = F_8 ( - V_25 ) ;
int V_26 ;
V_24 = F_9 ( sizeof( struct V_23 ) , V_27 ) ;
if ( ! V_24 )
goto V_28;
V_24 -> V_15 = F_9 ( sizeof( struct V_7 ) , V_27 ) ;
if ( ! V_24 -> V_15 )
goto V_29;
V_24 -> V_2 = F_9 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_24 -> V_2 )
goto V_30;
V_24 -> V_21 = ( unsigned long ) V_21 ;
V_24 -> V_31 = & V_24 -> V_11 ;
V_24 -> V_32 = & V_24 -> V_15 -> V_14 ;
V_26 = F_10 ( & V_33 , V_24 , V_21 , V_22 ) ;
if ( V_26 < 0 ) {
V_15 = F_8 ( V_26 ) ;
goto V_34;
}
V_26 = F_5 ( V_24 -> V_15 ) ;
if ( V_26 < 0 )
goto V_34;
V_15 = V_24 -> V_15 ;
V_24 -> V_15 = NULL ;
V_34:
while ( V_24 -> V_11 ) {
struct V_9 * V_10 = V_24 -> V_11 ;
V_24 -> V_11 = V_10 -> V_12 ;
F_4 ( V_10 ) ;
}
F_1 ( V_24 -> V_2 ) ;
V_30:
F_3 ( V_24 -> V_15 ) ;
V_29:
F_2 ( V_24 ) ;
V_28:
return V_15 ;
}
int F_11 ( const struct V_7 * V_8 ,
const void * * V_35 , T_1 * V_36 ,
bool V_37 )
{
T_1 V_38 ;
if ( ! V_8 -> V_21 )
return - V_39 ;
V_38 = V_37 ? V_8 -> V_40 : 0 ;
* V_35 = V_8 -> V_21 - V_38 ;
* V_36 = V_8 -> V_41 + V_38 ;
return 0 ;
}
int F_12 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_47 = F_13 ( V_45 , V_46 ) ;
if ( V_24 -> V_47 == V_48 ) {
char V_49 [ 50 ] ;
F_14 ( V_45 , V_46 , V_49 , sizeof( V_49 ) ) ;
F_15 ( L_2 ,
( unsigned long ) V_45 - V_24 -> V_21 , V_49 ) ;
}
return 0 ;
}
int F_16 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
switch ( V_24 -> V_47 ) {
case V_50 :
V_24 -> V_2 -> V_3 . V_51 = L_3 ;
break;
case V_52 :
V_24 -> V_2 -> V_3 . V_51 = L_4 ;
break;
case V_53 :
V_24 -> V_2 -> V_3 . V_51 = L_5 ;
break;
case V_54 :
V_24 -> V_2 -> V_3 . V_51 = L_6 ;
break;
case V_55 :
V_24 -> V_2 -> V_3 . V_51 = L_7 ;
break;
case V_56 :
V_24 -> V_2 -> V_3 . V_51 = L_8 ;
break;
case V_57 :
V_24 -> V_2 -> V_3 . V_51 = L_9 ;
default:
F_15 ( L_10 , V_24 -> V_47 ) ;
return - V_58 ;
}
return 0 ;
}
int F_17 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
switch ( V_24 -> V_47 ) {
case V_59 :
V_24 -> V_2 -> V_3 . V_60 = L_11 ;
break;
default:
F_15 ( L_12 , V_24 -> V_47 ) ;
return - V_58 ;
}
return 0 ;
}
int F_18 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
if ( V_24 -> V_47 != V_61 ) {
F_6 ( L_13 ) ;
return - V_20 ;
}
return 0 ;
}
int F_19 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
unsigned V_62 ;
if ( V_46 != 1 )
goto V_63;
V_24 -> V_15 -> V_62 = V_62 = * ( const V_64 * ) V_45 ;
switch ( V_62 ) {
case 1 :
break;
case 3 :
break;
default:
goto V_63;
}
return 0 ;
V_63:
F_6 ( L_14 ) ;
return - V_20 ;
}
int F_20 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
unsigned V_62 ;
if ( V_46 != 1 )
goto V_63;
V_62 = * ( const V_64 * ) V_45 ;
switch ( V_62 ) {
case 1 :
if ( V_24 -> V_15 -> V_62 != 1 )
goto V_65;
V_24 -> V_66 = false ;
break;
case 3 :
if ( V_24 -> V_15 -> V_62 == 1 )
goto V_65;
V_24 -> V_66 = true ;
break;
default:
goto V_63;
}
return 0 ;
V_63:
F_6 ( L_15 ) ;
return - V_20 ;
V_65:
F_6 ( L_16 ) ;
return - V_67 ;
}
int F_21 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_9 * V_68 ;
if ( V_44 != ( ( V_69 << 6 ) | V_70 | V_71 ) ) {
F_22 ( L_17 ,
V_44 , ( unsigned long ) V_24 - V_24 -> V_21 ) ;
return - V_67 ;
}
V_45 -= V_43 ;
V_46 += V_43 ;
if ( ( ( V_64 * ) V_45 ) [ 1 ] == 0x80 )
V_46 += 2 ;
V_68 = F_23 ( V_45 , V_46 ) ;
if ( F_24 ( V_68 ) )
return F_25 ( V_68 ) ;
V_68 -> V_72 = ++ V_24 -> V_73 ;
F_22 ( L_18 , V_68 -> V_72 , V_68 -> V_74 ) ;
F_22 ( L_19 , V_68 -> V_75 -> V_76 , V_68 -> V_75 -> V_21 ) ;
* V_24 -> V_31 = V_68 ;
V_24 -> V_31 = & V_68 -> V_12 ;
return 0 ;
}
int F_26 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
F_27 ( L_20 , V_44 ) ;
* V_24 -> V_31 = V_24 -> V_15 -> V_11 ;
V_24 -> V_15 -> V_11 = V_24 -> V_11 ;
V_24 -> V_11 = NULL ;
V_24 -> V_31 = & V_24 -> V_11 ;
return 0 ;
}
int F_28 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
if ( V_24 -> V_47 != V_77 &&
V_24 -> V_47 != V_78 ) {
F_6 ( L_21 , V_24 -> V_47 ) ;
return - V_20 ;
}
V_24 -> V_15 -> V_79 = V_24 -> V_47 ;
return 0 ;
}
int F_29 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
F_22 ( L_22 ) ;
V_24 -> V_15 -> V_21 = V_45 ;
V_24 -> V_15 -> V_41 = V_46 ;
V_24 -> V_15 -> V_40 = V_43 ;
return 0 ;
}
int F_30 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_1 * V_2 = V_24 -> V_2 ;
enum V_80 V_81 ;
F_27 ( L_23 , V_44 , V_46 , ( unsigned ) V_46 , V_45 ) ;
switch ( V_24 -> V_47 ) {
case V_82 :
if ( F_31 ( V_83 , & V_2 -> V_84 ) )
goto V_85;
V_81 = F_13 ( V_45 , V_46 ) ;
if ( V_81 != V_24 -> V_15 -> V_79 ) {
F_6 ( L_24 ,
V_24 -> V_15 -> V_79 , V_2 -> V_72 ,
V_81 ) ;
return - V_67 ;
}
return 0 ;
case V_86 :
if ( F_31 ( V_87 , & V_2 -> V_84 ) )
goto V_85;
return F_32 ( & V_2 -> V_88 ,
V_43 , V_44 , V_45 , V_46 ) ;
case V_89 :
if ( F_31 ( V_90 , & V_2 -> V_84 ) )
goto V_85;
if ( V_44 != V_91 )
return - V_67 ;
V_2 -> V_92 = V_45 ;
V_2 -> V_93 = V_46 ;
return 0 ;
case V_94 :
if ( F_31 ( V_95 , & V_2 -> V_84 ) )
goto V_85;
if ( V_24 -> V_15 -> V_79 != V_78 ) {
F_6 ( L_25 ) ;
return - V_96 ;
}
return 0 ;
case V_97 :
if ( F_31 ( V_98 , & V_2 -> V_84 ) )
goto V_85;
goto V_99;
case V_100 :
if ( F_31 ( V_101 , & V_2 -> V_84 ) )
goto V_85;
V_99:
if ( V_24 -> V_15 -> V_79 != V_78 ) {
F_6 ( L_26 ) ;
return - V_96 ;
}
return 0 ;
default:
return 0 ;
}
V_85:
F_6 ( L_27 ) ;
return - V_96 ;
}
int F_33 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_1 * V_2 = V_24 -> V_2 ;
if ( ! F_34 ( V_83 , & V_2 -> V_84 ) ||
! F_34 ( V_90 , & V_2 -> V_84 ) ) {
F_6 ( L_28 ) ;
return - V_67 ;
}
if ( V_24 -> V_15 -> V_79 != V_78 &&
F_34 ( V_98 , & V_2 -> V_84 ) ) {
F_6 ( L_29 ) ;
return - V_67 ;
}
V_2 -> V_17 = V_45 - ( V_43 - 1 ) ;
V_2 -> V_102 = V_46 + ( V_43 - 1 ) ;
return 0 ;
}
int F_35 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_103 = V_45 ;
V_24 -> V_104 = V_46 ;
return 0 ;
}
int F_36 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_105 = V_45 ;
V_24 -> V_106 = V_46 ;
return 0 ;
}
int F_37 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
F_27 ( L_30 , V_44 , V_46 , ( unsigned ) V_46 , V_45 ) ;
V_24 -> V_107 = V_45 ;
V_24 -> V_108 = V_46 ;
return 0 ;
}
int F_38 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_2 -> V_3 . V_4 = F_39 ( V_45 , V_46 , V_27 ) ;
if ( ! V_24 -> V_2 -> V_3 . V_4 )
return - V_25 ;
V_24 -> V_2 -> V_3 . V_109 = V_46 ;
return 0 ;
}
int F_40 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_110 * V_111 ;
if ( V_24 -> V_15 -> V_79 == V_78 && ! V_2 -> V_17 ) {
F_6 ( L_31 ) ;
return - V_67 ;
}
if ( ! V_24 -> V_66 ) {
V_111 = F_41 ( V_24 -> V_103 ,
V_24 -> V_104 ,
V_24 -> V_105 ,
V_24 -> V_106 ) ;
} else {
V_111 = F_41 ( V_24 -> V_107 ,
V_24 -> V_108 ,
L_32 , 0 ) ;
}
if ( F_24 ( V_111 ) )
return F_25 ( V_111 ) ;
F_27 ( L_33 , V_111 -> V_76 , V_111 -> V_76 , V_111 -> V_21 ) ;
V_2 -> V_6 = V_111 ;
V_2 -> V_72 = ++ V_24 -> V_112 ;
* V_24 -> V_32 = V_2 ;
V_24 -> V_32 = & V_2 -> V_12 ;
V_24 -> V_2 = F_9 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_24 -> V_2 )
return - V_25 ;
return 0 ;
}
