static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
}
}
void F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
if ( V_5 ) {
while ( V_5 -> V_8 ) {
V_7 = V_5 -> V_8 ;
V_5 -> V_8 = V_7 -> V_9 ;
F_5 ( V_7 ) ;
}
while ( V_5 -> V_10 ) {
V_7 = V_5 -> V_10 ;
V_5 -> V_10 = V_7 -> V_9 ;
F_5 ( V_7 ) ;
}
while ( V_5 -> V_11 ) {
V_2 = V_5 -> V_11 ;
V_5 -> V_11 = V_2 -> V_9 ;
F_1 ( V_2 ) ;
}
F_3 ( V_5 ) ;
}
}
static int F_6 ( struct V_4 * V_12 )
{
struct V_1 * V_2 ;
bool V_13 = false ;
V_2 = V_12 -> V_11 ;
if ( V_2 -> V_14 ) {
V_13 = true ;
V_12 -> V_15 = true ;
}
for ( V_2 = V_2 -> V_9 ; V_2 ; V_2 = V_2 -> V_9 )
if ( ! ! V_2 -> V_14 != V_13 )
goto V_16;
return 0 ;
V_16:
F_7 ( L_1 ) ;
return - V_17 ;
}
struct V_4 * F_8 ( const void * V_18 , T_1 V_19 )
{
struct V_20 * V_21 ;
struct V_4 * V_12 = F_9 ( - V_22 ) ;
int V_23 ;
V_21 = F_10 ( sizeof( struct V_20 ) , V_24 ) ;
if ( ! V_21 )
goto V_25;
V_21 -> V_12 = F_10 ( sizeof( struct V_4 ) , V_24 ) ;
if ( ! V_21 -> V_12 )
goto V_26;
V_21 -> V_2 = F_10 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_21 -> V_2 )
goto V_27;
V_21 -> V_2 -> V_3 = F_10 ( sizeof( struct V_28 ) ,
V_24 ) ;
if ( ! V_21 -> V_2 -> V_3 )
goto V_29;
V_21 -> V_18 = ( unsigned long ) V_18 ;
V_21 -> V_30 = & V_21 -> V_8 ;
V_21 -> V_31 = & V_21 -> V_12 -> V_11 ;
V_23 = F_11 ( & V_32 , V_21 , V_18 , V_19 ) ;
if ( V_23 < 0 ) {
V_12 = F_9 ( V_23 ) ;
goto V_33;
}
V_23 = F_6 ( V_21 -> V_12 ) ;
if ( V_23 < 0 )
goto V_33;
V_12 = V_21 -> V_12 ;
V_21 -> V_12 = NULL ;
V_33:
while ( V_21 -> V_8 ) {
struct V_6 * V_7 = V_21 -> V_8 ;
V_21 -> V_8 = V_7 -> V_9 ;
F_5 ( V_7 ) ;
}
V_29:
F_1 ( V_21 -> V_2 ) ;
V_27:
F_4 ( V_21 -> V_12 ) ;
V_26:
F_3 ( V_21 ) ;
V_25:
return V_12 ;
}
int F_12 ( const struct V_4 * V_5 ,
const void * * V_34 , T_1 * V_35 ,
T_1 * V_36 )
{
if ( ! V_5 -> V_18 )
return - V_37 ;
* V_34 = V_5 -> V_18 ;
* V_35 = V_5 -> V_38 ;
if ( V_36 )
* V_36 = V_5 -> V_39 ;
return 0 ;
}
int F_13 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
V_21 -> V_45 = F_14 ( V_43 , V_44 ) ;
if ( V_21 -> V_45 == V_46 ) {
char V_47 [ 50 ] ;
F_15 ( V_43 , V_44 , V_47 , sizeof( V_47 ) ) ;
F_16 ( L_2 ,
( unsigned long ) V_43 - V_21 -> V_18 , V_47 ) ;
}
return 0 ;
}
int F_17 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
switch ( V_21 -> V_45 ) {
case V_48 :
V_21 -> V_2 -> V_3 -> V_49 = L_3 ;
break;
case V_50 :
V_21 -> V_2 -> V_3 -> V_49 = L_4 ;
break;
case V_51 :
V_21 -> V_2 -> V_3 -> V_49 = L_5 ;
break;
case V_52 :
V_21 -> V_2 -> V_3 -> V_49 = L_6 ;
break;
case V_53 :
V_21 -> V_2 -> V_3 -> V_49 = L_7 ;
break;
case V_54 :
V_21 -> V_2 -> V_3 -> V_49 = L_8 ;
break;
case V_55 :
V_21 -> V_2 -> V_3 -> V_49 = L_9 ;
break;
default:
F_16 ( L_10 , V_21 -> V_45 ) ;
return - V_56 ;
}
return 0 ;
}
int F_18 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
switch ( V_21 -> V_45 ) {
case V_57 :
V_21 -> V_2 -> V_3 -> V_58 = L_11 ;
break;
default:
F_16 ( L_12 , V_21 -> V_45 ) ;
return - V_56 ;
}
return 0 ;
}
int F_19 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
if ( V_21 -> V_45 != V_59 ) {
F_7 ( L_13 ) ;
return - V_17 ;
}
return 0 ;
}
int F_20 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
unsigned V_60 ;
if ( V_44 != 1 )
goto V_61;
V_21 -> V_12 -> V_60 = V_60 = * ( const V_62 * ) V_43 ;
switch ( V_60 ) {
case 1 :
break;
case 3 :
break;
default:
goto V_61;
}
return 0 ;
V_61:
F_7 ( L_14 ) ;
return - V_17 ;
}
int F_21 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
unsigned V_60 ;
if ( V_44 != 1 )
goto V_61;
V_60 = * ( const V_62 * ) V_43 ;
switch ( V_60 ) {
case 1 :
if ( V_21 -> V_12 -> V_60 != 1 )
goto V_63;
V_21 -> V_64 = false ;
break;
case 3 :
if ( V_21 -> V_12 -> V_60 == 1 )
goto V_63;
V_21 -> V_64 = true ;
break;
default:
goto V_61;
}
return 0 ;
V_61:
F_7 ( L_15 ) ;
return - V_17 ;
V_63:
F_7 ( L_16 ) ;
return - V_65 ;
}
int F_22 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
struct V_6 * V_66 ;
if ( V_42 != ( ( V_67 << 6 ) | V_68 | V_69 ) ) {
F_23 ( L_17 ,
V_42 , ( unsigned long ) V_21 - V_21 -> V_18 ) ;
return - V_65 ;
}
V_43 -= V_41 ;
V_44 += V_41 ;
if ( ( ( V_62 * ) V_43 ) [ 1 ] == 0x80 )
V_44 += 2 ;
V_66 = F_24 ( V_43 , V_44 ) ;
if ( F_25 ( V_66 ) )
return F_26 ( V_66 ) ;
V_66 -> V_70 = ++ V_21 -> V_71 ;
F_23 ( L_18 , V_66 -> V_70 , V_66 -> V_72 ) ;
F_23 ( L_19 , V_66 -> V_73 -> V_74 , V_66 -> V_73 -> V_18 ) ;
* V_21 -> V_30 = V_66 ;
V_21 -> V_30 = & V_66 -> V_9 ;
return 0 ;
}
int F_27 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
F_28 ( L_20 , V_42 ) ;
* V_21 -> V_30 = V_21 -> V_12 -> V_8 ;
V_21 -> V_12 -> V_8 = V_21 -> V_8 ;
V_21 -> V_8 = NULL ;
V_21 -> V_30 = & V_21 -> V_8 ;
return 0 ;
}
int F_29 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
if ( V_21 -> V_45 != V_75 &&
V_21 -> V_45 != V_76 ) {
F_7 ( L_21 , V_21 -> V_45 ) ;
return - V_17 ;
}
V_21 -> V_12 -> V_77 = V_21 -> V_45 ;
return 0 ;
}
int F_30 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
F_23 ( L_22 ) ;
V_21 -> V_12 -> V_18 = V_43 ;
V_21 -> V_12 -> V_38 = V_44 ;
V_21 -> V_12 -> V_39 = V_41 ;
return 0 ;
}
int F_31 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
struct V_1 * V_2 = V_21 -> V_2 ;
enum V_78 V_79 ;
F_28 ( L_23 , V_42 , V_44 , ( unsigned ) V_44 , V_43 ) ;
switch ( V_21 -> V_45 ) {
case V_80 :
if ( F_32 ( V_81 , & V_2 -> V_82 ) )
goto V_83;
V_79 = F_14 ( V_43 , V_44 ) ;
if ( V_79 != V_21 -> V_12 -> V_77 ) {
F_7 ( L_24 ,
V_21 -> V_12 -> V_77 , V_2 -> V_70 ,
V_79 ) ;
return - V_65 ;
}
return 0 ;
case V_84 :
if ( F_32 ( V_85 , & V_2 -> V_82 ) )
goto V_83;
return F_33 ( & V_2 -> V_86 ,
V_41 , V_42 , V_43 , V_44 ) ;
case V_87 :
if ( F_32 ( V_88 , & V_2 -> V_82 ) )
goto V_83;
if ( V_42 != V_89 )
return - V_65 ;
V_2 -> V_90 = V_43 ;
V_2 -> V_91 = V_44 ;
return 0 ;
case V_92 :
if ( F_32 ( V_93 , & V_2 -> V_82 ) )
goto V_83;
if ( V_21 -> V_12 -> V_77 != V_76 ) {
F_7 ( L_25 ) ;
return - V_94 ;
}
return 0 ;
case V_95 :
if ( F_32 ( V_96 , & V_2 -> V_82 ) )
goto V_83;
goto V_97;
case V_98 :
if ( F_32 ( V_99 , & V_2 -> V_82 ) )
goto V_83;
V_97:
if ( V_21 -> V_12 -> V_77 != V_76 ) {
F_7 ( L_26 ) ;
return - V_94 ;
}
return 0 ;
default:
return 0 ;
}
V_83:
F_7 ( L_27 ) ;
return - V_94 ;
}
int F_34 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
struct V_1 * V_2 = V_21 -> V_2 ;
if ( ! F_35 ( V_81 , & V_2 -> V_82 ) ||
! F_35 ( V_88 , & V_2 -> V_82 ) ) {
F_7 ( L_28 ) ;
return - V_65 ;
}
if ( V_21 -> V_12 -> V_77 != V_76 &&
F_35 ( V_96 , & V_2 -> V_82 ) ) {
F_7 ( L_29 ) ;
return - V_65 ;
}
V_2 -> V_14 = V_43 - ( V_41 - 1 ) ;
V_2 -> V_100 = V_44 + ( V_41 - 1 ) ;
return 0 ;
}
int F_36 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
V_21 -> V_101 = V_43 ;
V_21 -> V_102 = V_44 ;
return 0 ;
}
int F_37 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
V_21 -> V_103 = V_43 ;
V_21 -> V_104 = V_44 ;
return 0 ;
}
int F_38 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
F_28 ( L_30 , V_42 , V_44 , ( unsigned ) V_44 , V_43 ) ;
V_21 -> V_105 = V_43 ;
V_21 -> V_106 = V_44 ;
return 0 ;
}
int F_39 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
V_21 -> V_2 -> V_3 -> V_107 = F_40 ( V_43 , V_44 , V_24 ) ;
if ( ! V_21 -> V_2 -> V_3 -> V_107 )
return - V_22 ;
V_21 -> V_2 -> V_3 -> V_108 = V_44 ;
return 0 ;
}
int F_41 ( void * V_40 , T_1 V_41 ,
unsigned char V_42 ,
const void * V_43 , T_1 V_44 )
{
struct V_20 * V_21 = V_40 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_109 * V_110 ;
if ( V_21 -> V_12 -> V_77 == V_76 && ! V_2 -> V_14 ) {
F_7 ( L_31 ) ;
return - V_65 ;
}
if ( ! V_21 -> V_64 ) {
V_110 = F_42 ( V_21 -> V_101 ,
V_21 -> V_102 ,
V_21 -> V_103 ,
V_21 -> V_104 ) ;
} else {
V_110 = F_42 ( V_21 -> V_105 ,
V_21 -> V_106 ,
L_32 , 0 ) ;
}
if ( F_25 ( V_110 ) )
return F_26 ( V_110 ) ;
F_28 ( L_33 , V_110 -> V_74 , V_110 -> V_74 , V_110 -> V_18 ) ;
V_2 -> V_3 -> V_111 [ 0 ] = V_110 ;
V_2 -> V_70 = ++ V_21 -> V_112 ;
* V_21 -> V_31 = V_2 ;
V_21 -> V_31 = & V_2 -> V_9 ;
V_21 -> V_2 = F_10 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_21 -> V_2 )
return - V_22 ;
V_21 -> V_2 -> V_3 = F_10 ( sizeof( struct V_28 ) ,
V_24 ) ;
if ( ! V_21 -> V_2 -> V_3 )
return - V_22 ;
return 0 ;
}
