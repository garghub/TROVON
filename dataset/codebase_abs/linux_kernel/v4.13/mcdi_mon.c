void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned int type , V_4 , V_5 ;
enum V_6 V_7 = V_8 ;
const char * V_9 = NULL , * V_10 , * V_11 ;
type = F_2 ( * V_3 , V_12 ) ;
V_4 = F_2 ( * V_3 , V_13 ) ;
V_5 = F_2 ( * V_3 , V_14 ) ;
if ( type < F_3 ( V_15 ) ) {
V_9 = V_15 [ type ] . V_16 ;
V_7 = V_15 [ type ] . V_7 ;
}
if ( ! V_9 )
V_9 = L_1 ;
F_4 ( V_4 >= F_3 ( V_17 ) ) ;
V_10 = V_17 [ V_4 ] ;
F_4 ( V_7 >= V_18 ) ;
V_11 = V_19 [ V_7 ] ;
if ( ! V_11 )
V_11 = L_2 ;
F_5 ( V_2 , V_20 , V_2 -> V_21 ,
L_3 ,
type , V_9 , V_10 , V_5 , V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_22 ( V_2 ) ;
F_7 ( V_24 , V_25 ) ;
int V_26 ;
F_8 ( V_24 , V_27 ,
V_23 -> V_28 . V_29 ) ;
F_9 ( V_24 , V_30 , V_23 -> V_28 . V_31 ) ;
V_26 = F_10 ( V_2 , V_32 ,
V_24 , sizeof( V_24 ) , NULL , 0 , NULL ) ;
if ( V_26 == 0 )
V_23 -> V_33 = V_34 ;
return V_26 ;
}
static int F_11 ( struct V_35 * V_36 , unsigned int V_37 ,
T_2 * V_38 )
{
struct V_1 * V_2 = F_12 ( V_36 -> V_39 ) ;
struct V_22 * V_23 = V_22 ( V_2 ) ;
int V_26 ;
F_13 ( V_40 != 0 ) ;
F_14 ( & V_23 -> V_41 ) ;
if ( F_15 ( V_34 , V_23 -> V_33 + V_42 ) )
V_26 = 0 ;
else
V_26 = F_6 ( V_2 ) ;
* V_38 = ( ( T_2 * ) V_23 -> V_28 . V_43 ) [ V_37 ] ;
F_16 ( & V_23 -> V_41 ) ;
return V_26 ;
}
static T_3 F_17 ( struct V_35 * V_36 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 =
F_18 ( V_45 , struct V_47 , V_49 ) ;
T_2 V_38 ;
unsigned int V_5 , V_4 ;
int V_26 ;
V_26 = F_11 ( V_36 , V_48 -> V_37 , & V_38 ) ;
if ( V_26 )
return V_26 ;
V_4 = F_19 ( V_38 , V_50 ) ;
if ( V_4 == V_51 )
return - V_52 ;
V_5 = F_19 ( V_38 , V_53 ) ;
switch ( V_48 -> V_7 ) {
case V_54 :
V_5 *= 1000 ;
break;
case V_55 :
V_5 *= 1000000 ;
break;
default:
break;
}
return sprintf ( V_46 , L_4 , V_5 ) ;
}
static T_3 F_20 ( struct V_35 * V_36 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 =
F_18 ( V_45 , struct V_47 , V_49 ) ;
unsigned int V_5 ;
V_5 = V_48 -> V_56 ;
switch ( V_48 -> V_7 ) {
case V_54 :
V_5 *= 1000 ;
break;
case V_55 :
V_5 *= 1000000 ;
break;
default:
break;
}
return sprintf ( V_46 , L_4 , V_5 ) ;
}
static T_3 F_21 ( struct V_35 * V_36 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 =
F_18 ( V_45 , struct V_47 , V_49 ) ;
T_2 V_38 ;
int V_4 ;
int V_26 ;
V_26 = F_11 ( V_36 , V_48 -> V_37 , & V_38 ) ;
if ( V_26 )
return V_26 ;
V_4 = F_19 ( V_38 , V_50 ) ;
return sprintf ( V_46 , L_5 , V_4 != V_57 ) ;
}
static T_3 F_22 ( struct V_35 * V_36 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_47 * V_48 =
F_18 ( V_45 , struct V_47 , V_49 ) ;
return sprintf ( V_46 , L_6 ,
V_15 [ V_48 -> type ] . V_16 ) ;
}
static void
F_23 ( struct V_1 * V_2 , const char * V_9 ,
T_3 (* F_24)( struct V_35 * ,
struct V_44 * , char * ) ,
unsigned int V_37 , unsigned int type ,
unsigned int V_56 )
{
struct V_22 * V_23 = V_22 ( V_2 ) ;
struct V_47 * V_45 = & V_23 -> V_58 [ V_23 -> V_59 ] ;
F_25 ( V_45 -> V_9 , V_9 , sizeof( V_45 -> V_9 ) ) ;
V_45 -> V_37 = V_37 ;
V_45 -> type = type ;
if ( type < F_3 ( V_15 ) )
V_45 -> V_7 = V_15 [ type ] . V_7 ;
else
V_45 -> V_7 = V_8 ;
V_45 -> V_56 = V_56 ;
F_26 ( & V_45 -> V_49 . V_45 ) ;
V_45 -> V_49 . V_45 . V_9 = V_45 -> V_9 ;
V_45 -> V_49 . V_45 . V_60 = V_61 ;
V_45 -> V_49 . V_62 = F_24 ;
V_23 -> V_63 . V_58 [ V_23 -> V_59 ++ ] = & V_45 -> V_49 . V_45 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_64 = 0 , V_65 = 0 , V_66 = 0 , V_67 = 0 , V_68 = 0 ;
struct V_22 * V_23 = V_22 ( V_2 ) ;
F_7 ( V_24 , V_69 ) ;
F_7 ( V_70 , V_71 ) ;
unsigned int V_72 , V_73 , V_59 , V_74 ;
T_4 V_75 ;
char V_9 [ 12 ] ;
T_5 V_76 ;
int V_26 , V_77 , V_78 , type ;
V_73 = 0 ;
V_74 = 0 ;
do {
F_9 ( V_24 , V_79 , V_74 ) ;
V_26 = F_10 ( V_2 , V_80 , V_24 , sizeof( V_24 ) ,
V_70 , sizeof( V_70 ) , & V_75 ) ;
if ( V_26 )
return V_26 ;
if ( V_75 < V_81 )
return - V_82 ;
V_76 = F_28 ( V_70 , V_83 ) ;
V_73 += F_29 ( V_76 & ~ ( 1 << V_84 ) ) ;
++ V_74 ;
} while ( V_76 & ( 1 << V_84 ) );
V_72 = V_74 ;
if ( V_73 == 0 )
return 0 ;
V_26 = F_30 (
V_2 , & V_23 -> V_28 ,
V_73 * V_85 ,
V_86 ) ;
if ( V_26 )
return V_26 ;
F_31 ( & V_23 -> V_41 ) ;
F_6 ( V_2 ) ;
V_59 = 6 * V_73 ;
V_23 -> V_58 = F_32 ( V_59 , sizeof( * V_23 -> V_58 ) , V_86 ) ;
if ( ! V_23 -> V_58 ) {
V_26 = - V_87 ;
goto V_88;
}
V_23 -> V_63 . V_58 = F_32 ( V_59 + 1 , sizeof( struct V_89 * ) ,
V_86 ) ;
if ( ! V_23 -> V_63 . V_58 ) {
V_26 = - V_87 ;
goto V_88;
}
for ( V_77 = 0 , V_78 = - 1 , type = - 1 ; ; V_77 ++ ) {
enum V_6 V_7 ;
const char * V_90 ;
unsigned V_91 ;
T_6 V_92 , V_93 , V_94 , V_95 ;
do {
type ++ ;
if ( ( type % 32 ) == 0 ) {
V_74 = type / 32 ;
V_78 = - 1 ;
if ( V_74 == V_72 )
goto V_96;
F_9 ( V_24 , V_79 ,
V_74 ) ;
V_26 = F_10 ( V_2 , V_80 ,
V_24 , sizeof( V_24 ) ,
V_70 , sizeof( V_70 ) ,
& V_75 ) ;
if ( V_26 )
goto V_88;
if ( V_75 < V_81 ) {
V_26 = - V_82 ;
goto V_88;
}
V_76 = ( F_28 ( V_70 ,
V_83 ) &
~ ( 1 << V_84 ) ) ;
if ( V_75 <
F_33 ( F_29 ( V_76 ) ) ) {
V_26 = - V_82 ;
goto V_88;
}
}
} while ( ! ( V_76 & ( 1 << type % 32 ) ) );
V_78 ++ ;
if ( type < F_3 ( V_15 ) ) {
V_7 = V_15 [ type ] . V_7 ;
if ( V_7 != V_8 &&
V_15 [ type ] . V_97 >= 0 &&
V_15 [ type ] . V_97 !=
F_34 ( V_2 ) )
continue;
} else {
V_7 = V_8 ;
}
switch ( V_7 ) {
case V_54 :
V_90 = L_7 ;
V_91 = ++ V_64 ;
break;
case V_98 :
V_90 = L_8 ;
V_91 = ++ V_65 ;
break;
default:
V_90 = L_9 ;
V_91 = V_66 ++ ;
break;
case V_99 :
V_90 = L_10 ;
V_91 = ++ V_67 ;
break;
case V_55 :
V_90 = L_11 ;
V_91 = ++ V_68 ;
break;
}
V_92 = F_35 ( V_70 , V_100 ,
V_101 , V_78 , V_102 ) ;
V_93 = F_35 ( V_70 , V_100 ,
V_101 , V_78 , V_103 ) ;
V_94 = F_35 ( V_70 , V_100 ,
V_101 , V_78 , V_104 ) ;
V_95 = F_35 ( V_70 , V_100 ,
V_101 , V_78 , V_105 ) ;
if ( V_92 != V_93 ) {
snprintf ( V_9 , sizeof( V_9 ) , L_12 ,
V_90 , V_91 ) ;
F_23 (
V_2 , V_9 , F_17 , V_77 , type , 0 ) ;
if ( V_7 != V_55 ) {
snprintf ( V_9 , sizeof( V_9 ) , L_13 ,
V_90 , V_91 ) ;
F_23 (
V_2 , V_9 , F_20 ,
V_77 , type , V_92 ) ;
}
snprintf ( V_9 , sizeof( V_9 ) , L_14 ,
V_90 , V_91 ) ;
F_23 (
V_2 , V_9 , F_20 ,
V_77 , type , V_93 ) ;
if ( V_94 != V_95 ) {
snprintf ( V_9 , sizeof( V_9 ) , L_15 ,
V_90 , V_91 ) ;
F_23 (
V_2 , V_9 , F_20 ,
V_77 , type , V_95 ) ;
}
}
snprintf ( V_9 , sizeof( V_9 ) , L_16 ,
V_90 , V_91 ) ;
F_23 (
V_2 , V_9 , F_21 , V_77 , type , 0 ) ;
if ( type < F_3 ( V_15 ) &&
V_15 [ type ] . V_16 ) {
snprintf ( V_9 , sizeof( V_9 ) , L_17 ,
V_90 , V_91 ) ;
F_23 (
V_2 , V_9 , F_22 , V_77 , type , 0 ) ;
}
}
V_96:
V_23 -> V_106 [ 0 ] = & V_23 -> V_63 ;
V_23 -> V_35 = F_36 ( & V_2 -> V_107 -> V_36 ,
V_108 , NULL ,
V_23 -> V_106 ) ;
if ( F_37 ( V_23 -> V_35 ) ) {
V_26 = F_38 ( V_23 -> V_35 ) ;
goto V_88;
}
return 0 ;
V_88:
F_39 ( V_2 ) ;
return V_26 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_22 ( V_2 ) ;
if ( V_23 -> V_35 )
F_40 ( V_23 -> V_35 ) ;
F_41 ( V_23 -> V_58 ) ;
F_41 ( V_23 -> V_63 . V_58 ) ;
F_42 ( V_2 , & V_23 -> V_28 ) ;
}
