static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_2 ( V_2 -> V_3 . V_4 [ 0 ] ) ;
F_3 ( V_2 -> V_3 . V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 ) ;
}
}
void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( V_8 ) {
while ( V_8 -> V_11 ) {
V_10 = V_8 -> V_11 ;
V_8 -> V_11 = V_10 -> V_12 ;
F_5 ( V_10 ) ;
}
while ( V_8 -> V_13 ) {
V_10 = V_8 -> V_13 ;
V_8 -> V_13 = V_10 -> V_12 ;
F_5 ( V_10 ) ;
}
while ( V_8 -> V_14 ) {
V_2 = V_8 -> V_14 ;
V_8 -> V_14 = V_2 -> V_12 ;
F_1 ( V_2 ) ;
}
F_3 ( V_8 ) ;
}
}
static int F_6 ( struct V_7 * V_15 )
{
struct V_1 * V_2 ;
bool V_16 ;
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
F_7 ( L_1 ) ;
return - V_20 ;
}
struct V_7 * F_8 ( const void * V_21 , T_1 V_22 )
{
struct V_23 * V_24 ;
struct V_7 * V_15 = F_9 ( - V_25 ) ;
int V_26 ;
V_24 = F_10 ( sizeof( struct V_23 ) , V_27 ) ;
if ( ! V_24 )
goto V_28;
V_24 -> V_15 = F_10 ( sizeof( struct V_7 ) , V_27 ) ;
if ( ! V_24 -> V_15 )
goto V_29;
V_24 -> V_2 = F_10 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_24 -> V_2 )
goto V_30;
V_24 -> V_21 = ( unsigned long ) V_21 ;
V_24 -> V_31 = & V_24 -> V_11 ;
V_24 -> V_32 = & V_24 -> V_15 -> V_14 ;
V_26 = F_11 ( & V_33 , V_24 , V_21 , V_22 ) ;
if ( V_26 < 0 ) {
V_15 = F_9 ( V_26 ) ;
goto V_34;
}
V_26 = F_6 ( V_24 -> V_15 ) ;
if ( V_26 < 0 )
goto V_34;
V_15 = V_24 -> V_15 ;
V_24 -> V_15 = NULL ;
V_34:
while ( V_24 -> V_11 ) {
struct V_9 * V_10 = V_24 -> V_11 ;
V_24 -> V_11 = V_10 -> V_12 ;
F_5 ( V_10 ) ;
}
F_1 ( V_24 -> V_2 ) ;
V_30:
F_4 ( V_24 -> V_15 ) ;
V_29:
F_3 ( V_24 ) ;
V_28:
return V_15 ;
}
int F_12 ( const struct V_7 * V_8 ,
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
int F_13 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_47 = F_14 ( V_45 , V_46 ) ;
if ( V_24 -> V_47 == V_48 ) {
char V_49 [ 50 ] ;
F_15 ( V_45 , V_46 , V_49 , sizeof( V_49 ) ) ;
F_16 ( L_2 ,
( unsigned long ) V_45 - V_24 -> V_21 , V_49 ) ;
}
return 0 ;
}
int F_17 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
switch ( V_24 -> V_47 ) {
case V_50 :
V_24 -> V_2 -> V_3 . V_51 = V_52 ;
break;
case V_53 :
V_24 -> V_2 -> V_3 . V_51 = V_54 ;
break;
case V_55 :
V_24 -> V_2 -> V_3 . V_51 = V_56 ;
break;
case V_57 :
V_24 -> V_2 -> V_3 . V_51 = V_58 ;
break;
case V_59 :
V_24 -> V_2 -> V_3 . V_51 = V_60 ;
break;
case V_61 :
V_24 -> V_2 -> V_3 . V_51 = V_62 ;
break;
case V_63 :
V_24 -> V_2 -> V_3 . V_51 = V_64 ;
default:
F_16 ( L_3 , V_24 -> V_47 ) ;
return - V_65 ;
}
return 0 ;
}
int F_18 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
switch ( V_24 -> V_47 ) {
case V_66 :
V_24 -> V_2 -> V_3 . V_67 = V_68 ;
break;
default:
F_16 ( L_4 , V_24 -> V_47 ) ;
return - V_65 ;
}
return 0 ;
}
int F_19 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
if ( V_24 -> V_47 != V_69 ) {
F_7 ( L_5 ) ;
return - V_20 ;
}
return 0 ;
}
int F_20 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
unsigned V_70 ;
if ( V_46 != 1 )
goto V_71;
V_24 -> V_15 -> V_70 = V_70 = * ( const V_72 * ) V_45 ;
switch ( V_70 ) {
case 1 :
break;
case 3 :
break;
default:
goto V_71;
}
return 0 ;
V_71:
F_7 ( L_6 ) ;
return - V_20 ;
}
int F_21 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
unsigned V_70 ;
if ( V_46 != 1 )
goto V_71;
V_70 = * ( const V_72 * ) V_45 ;
switch ( V_70 ) {
case 1 :
if ( V_24 -> V_15 -> V_70 != 1 )
goto V_73;
V_24 -> V_74 = false ;
break;
case 3 :
if ( V_24 -> V_15 -> V_70 == 1 )
goto V_73;
V_24 -> V_74 = true ;
break;
default:
goto V_71;
}
return 0 ;
V_71:
F_7 ( L_7 ) ;
return - V_20 ;
V_73:
F_7 ( L_8 ) ;
return - V_75 ;
}
int F_22 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_9 * V_76 ;
if ( V_44 != ( ( V_77 << 6 ) | V_78 | V_79 ) ) {
F_23 ( L_9 ,
V_44 , ( unsigned long ) V_24 - V_24 -> V_21 ) ;
return - V_75 ;
}
V_45 -= V_43 ;
V_46 += V_43 ;
if ( ( ( V_72 * ) V_45 ) [ 1 ] == 0x80 )
V_46 += 2 ;
V_76 = F_24 ( V_45 , V_46 ) ;
if ( F_25 ( V_76 ) )
return F_26 ( V_76 ) ;
V_76 -> V_80 = ++ V_24 -> V_81 ;
F_23 ( L_10 , V_76 -> V_80 , V_76 -> V_82 ) ;
F_23 ( L_11 , V_76 -> V_83 -> V_84 , V_76 -> V_83 -> V_21 ) ;
* V_24 -> V_31 = V_76 ;
V_24 -> V_31 = & V_76 -> V_12 ;
return 0 ;
}
int F_27 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
F_28 ( L_12 , V_44 ) ;
* V_24 -> V_31 = V_24 -> V_15 -> V_11 ;
V_24 -> V_15 -> V_11 = V_24 -> V_11 ;
V_24 -> V_11 = NULL ;
V_24 -> V_31 = & V_24 -> V_11 ;
return 0 ;
}
int F_29 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
if ( V_24 -> V_47 != V_85 &&
V_24 -> V_47 != V_86 ) {
F_7 ( L_13 , V_24 -> V_47 ) ;
return - V_20 ;
}
V_24 -> V_15 -> V_87 = V_24 -> V_47 ;
return 0 ;
}
int F_30 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
F_23 ( L_14 ) ;
V_24 -> V_15 -> V_21 = V_45 ;
V_24 -> V_15 -> V_41 = V_46 ;
V_24 -> V_15 -> V_40 = V_43 ;
return 0 ;
}
int F_31 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_1 * V_2 = V_24 -> V_2 ;
enum V_88 V_89 ;
F_28 ( L_15 , V_44 , V_46 , ( unsigned ) V_46 , V_45 ) ;
switch ( V_24 -> V_47 ) {
case V_90 :
if ( F_32 ( V_91 , & V_2 -> V_92 ) )
goto V_93;
V_89 = F_14 ( V_45 , V_46 ) ;
if ( V_89 != V_24 -> V_15 -> V_87 ) {
F_7 ( L_16 ,
V_24 -> V_15 -> V_87 , V_2 -> V_80 ,
V_89 ) ;
return - V_75 ;
}
return 0 ;
case V_94 :
if ( F_32 ( V_95 , & V_2 -> V_92 ) )
goto V_93;
return F_33 ( & V_2 -> V_96 ,
V_43 , V_44 , V_45 , V_46 ) ;
case V_97 :
if ( F_32 ( V_98 , & V_2 -> V_92 ) )
goto V_93;
if ( V_44 != V_99 )
return - V_75 ;
V_2 -> V_100 = V_45 ;
V_2 -> V_101 = V_46 ;
return 0 ;
case V_102 :
if ( F_32 ( V_103 , & V_2 -> V_92 ) )
goto V_93;
if ( V_24 -> V_15 -> V_87 != V_86 ) {
F_7 ( L_17 ) ;
return - V_104 ;
}
return 0 ;
case V_105 :
if ( F_32 ( V_106 , & V_2 -> V_92 ) )
goto V_93;
goto V_107;
case V_108 :
if ( F_32 ( V_109 , & V_2 -> V_92 ) )
goto V_93;
V_107:
if ( V_24 -> V_15 -> V_87 != V_86 ) {
F_7 ( L_18 ) ;
return - V_104 ;
}
return 0 ;
default:
return 0 ;
}
V_93:
F_7 ( L_19 ) ;
return - V_104 ;
}
int F_34 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_1 * V_2 = V_24 -> V_2 ;
if ( ! F_35 ( V_91 , & V_2 -> V_92 ) ||
! F_35 ( V_98 , & V_2 -> V_92 ) ) {
F_7 ( L_20 ) ;
return - V_75 ;
}
if ( V_24 -> V_15 -> V_87 != V_86 &&
F_35 ( V_106 , & V_2 -> V_92 ) ) {
F_7 ( L_21 ) ;
return - V_75 ;
}
V_2 -> V_17 = V_45 - ( V_43 - 1 ) ;
V_2 -> V_110 = V_46 + ( V_43 - 1 ) ;
return 0 ;
}
int F_36 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_111 = V_45 ;
V_24 -> V_112 = V_46 ;
return 0 ;
}
int F_37 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
V_24 -> V_113 = V_45 ;
V_24 -> V_114 = V_46 ;
return 0 ;
}
int F_38 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
F_28 ( L_22 , V_44 , V_46 , ( unsigned ) V_46 , V_45 ) ;
V_24 -> V_115 = V_45 ;
V_24 -> V_116 = V_46 ;
return 0 ;
}
int F_39 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
T_2 V_4 ;
F_40 ( V_24 -> V_2 -> V_3 . V_67 != V_68 ) ;
V_4 = F_41 ( V_45 , V_46 ) ;
if ( ! V_4 )
return - V_25 ;
V_24 -> V_2 -> V_3 . V_4 [ 0 ] = V_4 ;
V_24 -> V_2 -> V_3 . V_117 = 1 ;
return 0 ;
}
int F_42 ( void * V_42 , T_1 V_43 ,
unsigned char V_44 ,
const void * V_45 , T_1 V_46 )
{
struct V_23 * V_24 = V_42 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_118 * V_119 ;
if ( V_24 -> V_15 -> V_87 == V_86 && ! V_2 -> V_17 ) {
F_7 ( L_23 ) ;
return - V_75 ;
}
if ( ! V_24 -> V_74 ) {
V_119 = F_43 ( V_24 -> V_111 ,
V_24 -> V_112 ,
V_24 -> V_113 ,
V_24 -> V_114 ) ;
} else {
V_119 = F_43 ( V_24 -> V_115 ,
V_24 -> V_116 ,
L_24 , 0 ) ;
}
if ( F_25 ( V_119 ) )
return F_26 ( V_119 ) ;
F_28 ( L_25 , V_119 -> V_84 , V_119 -> V_84 , V_119 -> V_21 ) ;
V_2 -> V_6 = V_119 ;
V_2 -> V_80 = ++ V_24 -> V_120 ;
* V_24 -> V_32 = V_2 ;
V_24 -> V_32 = & V_2 -> V_12 ;
V_24 -> V_2 = F_10 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_24 -> V_2 )
return - V_25 ;
return 0 ;
}
