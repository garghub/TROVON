void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned int type , V_4 , V_5 ;
const char * V_6 = NULL , * V_7 ;
type = F_2 ( * V_3 , V_8 ) ;
V_4 = F_2 ( * V_3 , V_9 ) ;
V_5 = F_2 ( * V_3 , V_10 ) ;
if ( type < F_3 ( V_11 ) )
V_6 = V_11 [ type ] . V_12 ;
if ( ! V_6 )
V_6 = L_1 ;
F_4 ( V_4 >= F_3 ( V_13 ) ) ;
V_7 = V_13 [ V_4 ] ;
F_5 ( V_2 , V_14 , V_2 -> V_15 ,
L_2 ,
type , V_6 , V_7 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
F_7 ( V_18 , V_19 ) ;
int V_20 ;
F_8 ( V_18 , V_21 ,
V_17 -> V_22 . V_23 ) ;
F_9 ( V_18 , V_24 , V_17 -> V_22 . V_25 ) ;
V_20 = F_10 ( V_2 , V_26 ,
V_18 , sizeof( V_18 ) , NULL , 0 , NULL ) ;
if ( V_20 == 0 )
V_17 -> V_27 = V_28 ;
return V_20 ;
}
static int F_11 ( struct V_29 * V_30 , unsigned int V_31 ,
T_2 * V_32 )
{
struct V_1 * V_2 = F_12 ( V_30 -> V_33 ) ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
int V_20 ;
F_13 ( V_34 != 0 ) ;
F_14 ( & V_17 -> V_35 ) ;
if ( F_15 ( V_28 , V_17 -> V_27 + V_36 ) )
V_20 = 0 ;
else
V_20 = F_6 ( V_2 ) ;
* V_32 = ( ( T_2 * ) V_17 -> V_22 . V_37 ) [ V_31 ] ;
F_16 ( & V_17 -> V_35 ) ;
return V_20 ;
}
static T_3 F_17 ( struct V_29 * V_30 ,
struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 =
F_18 ( V_39 , struct V_41 , V_43 ) ;
T_2 V_32 ;
unsigned int V_5 , V_4 ;
int V_20 ;
V_20 = F_11 ( V_30 , V_42 -> V_31 , & V_32 ) ;
if ( V_20 )
return V_20 ;
V_4 = F_19 ( V_32 , V_44 ) ;
if ( V_4 == V_45 )
return - V_46 ;
V_5 = F_19 ( V_32 , V_47 ) ;
switch ( V_42 -> V_48 ) {
case V_49 :
V_5 *= 1000 ;
break;
case V_50 :
V_5 *= 1000000 ;
break;
default:
break;
}
return sprintf ( V_40 , L_3 , V_5 ) ;
}
static T_3 F_20 ( struct V_29 * V_30 ,
struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 =
F_18 ( V_39 , struct V_41 , V_43 ) ;
unsigned int V_5 ;
V_5 = V_42 -> V_51 ;
switch ( V_42 -> V_48 ) {
case V_49 :
V_5 *= 1000 ;
break;
case V_50 :
V_5 *= 1000000 ;
break;
default:
break;
}
return sprintf ( V_40 , L_3 , V_5 ) ;
}
static T_3 F_21 ( struct V_29 * V_30 ,
struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 =
F_18 ( V_39 , struct V_41 , V_43 ) ;
T_2 V_32 ;
int V_4 ;
int V_20 ;
V_20 = F_11 ( V_30 , V_42 -> V_31 , & V_32 ) ;
if ( V_20 )
return V_20 ;
V_4 = F_19 ( V_32 , V_44 ) ;
return sprintf ( V_40 , L_4 , V_4 != V_52 ) ;
}
static T_3 F_22 ( struct V_29 * V_30 ,
struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 =
F_18 ( V_39 , struct V_41 , V_43 ) ;
return sprintf ( V_40 , L_5 ,
V_11 [ V_42 -> type ] . V_12 ) ;
}
static void
F_23 ( struct V_1 * V_2 , const char * V_6 ,
T_3 (* F_24)( struct V_29 * ,
struct V_38 * , char * ) ,
unsigned int V_31 , unsigned int type ,
unsigned int V_51 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_41 * V_39 = & V_17 -> V_53 [ V_17 -> V_54 ] ;
F_25 ( V_39 -> V_6 , V_6 , sizeof( V_39 -> V_6 ) ) ;
V_39 -> V_31 = V_31 ;
V_39 -> type = type ;
if ( type < F_3 ( V_11 ) )
V_39 -> V_48 = V_11 [ type ] . V_48 ;
else
V_39 -> V_48 = V_55 ;
V_39 -> V_51 = V_51 ;
F_26 ( & V_39 -> V_43 . V_39 ) ;
V_39 -> V_43 . V_39 . V_6 = V_39 -> V_6 ;
V_39 -> V_43 . V_39 . V_56 = V_57 ;
V_39 -> V_43 . V_58 = F_24 ;
V_17 -> V_59 . V_53 [ V_17 -> V_54 ++ ] = & V_39 -> V_43 . V_39 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_60 = 0 , V_61 = 0 , V_62 = 0 , V_63 = 0 , V_64 = 0 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
F_7 ( V_18 , V_65 ) ;
F_7 ( V_66 , V_67 ) ;
unsigned int V_68 , V_69 , V_54 , V_70 ;
T_4 V_71 ;
char V_6 [ 12 ] ;
T_5 V_72 ;
int V_20 , V_73 , V_74 , type ;
V_69 = 0 ;
V_70 = 0 ;
do {
F_9 ( V_18 , V_75 , V_70 ) ;
V_20 = F_10 ( V_2 , V_76 , V_18 , sizeof( V_18 ) ,
V_66 , sizeof( V_66 ) , & V_71 ) ;
if ( V_20 )
return V_20 ;
if ( V_71 < V_77 )
return - V_78 ;
V_72 = F_28 ( V_66 , V_79 ) ;
V_69 += F_29 ( V_72 & ~ ( 1 << V_80 ) ) ;
++ V_70 ;
} while ( V_72 & ( 1 << V_80 ) );
V_68 = V_70 ;
if ( V_69 == 0 )
return 0 ;
V_20 = F_30 (
V_2 , & V_17 -> V_22 ,
V_69 * V_81 ,
V_82 ) ;
if ( V_20 )
return V_20 ;
F_31 ( & V_17 -> V_35 ) ;
F_6 ( V_2 ) ;
V_54 = 6 * V_69 ;
V_17 -> V_53 = F_32 ( V_54 , sizeof( * V_17 -> V_53 ) , V_82 ) ;
if ( ! V_17 -> V_53 ) {
V_20 = - V_83 ;
goto V_84;
}
V_17 -> V_59 . V_53 = F_32 ( V_54 + 1 , sizeof( struct V_85 * ) ,
V_82 ) ;
if ( ! V_17 -> V_59 . V_53 ) {
V_20 = - V_83 ;
goto V_84;
}
for ( V_73 = 0 , V_74 = - 1 , type = - 1 ; ; V_73 ++ ) {
enum V_86 V_48 ;
const char * V_87 ;
unsigned V_88 ;
T_6 V_89 , V_90 , V_91 , V_92 ;
do {
type ++ ;
if ( ( type % 32 ) == 0 ) {
V_70 = type / 32 ;
V_74 = - 1 ;
if ( V_70 == V_68 )
goto V_93;
F_9 ( V_18 , V_75 ,
V_70 ) ;
V_20 = F_10 ( V_2 , V_76 ,
V_18 , sizeof( V_18 ) ,
V_66 , sizeof( V_66 ) ,
& V_71 ) ;
if ( V_20 )
goto V_84;
if ( V_71 < V_77 ) {
V_20 = - V_78 ;
goto V_84;
}
V_72 = ( F_28 ( V_66 ,
V_79 ) &
~ ( 1 << V_80 ) ) ;
if ( V_71 <
F_33 ( F_29 ( V_72 ) ) ) {
V_20 = - V_78 ;
goto V_84;
}
}
} while ( ! ( V_72 & ( 1 << type % 32 ) ) );
V_74 ++ ;
if ( type < F_3 ( V_11 ) ) {
V_48 = V_11 [ type ] . V_48 ;
if ( V_48 != V_55 &&
V_11 [ type ] . V_94 >= 0 &&
V_11 [ type ] . V_94 !=
F_34 ( V_2 ) )
continue;
} else {
V_48 = V_55 ;
}
switch ( V_48 ) {
case V_49 :
V_87 = L_6 ;
V_88 = ++ V_60 ;
break;
case V_95 :
V_87 = L_7 ;
V_88 = ++ V_61 ;
break;
default:
V_87 = L_8 ;
V_88 = V_62 ++ ;
break;
case V_96 :
V_87 = L_9 ;
V_88 = ++ V_63 ;
break;
case V_50 :
V_87 = L_10 ;
V_88 = ++ V_64 ;
break;
}
V_89 = F_35 ( V_66 , V_97 ,
V_98 , V_74 , V_99 ) ;
V_90 = F_35 ( V_66 , V_97 ,
V_98 , V_74 , V_100 ) ;
V_91 = F_35 ( V_66 , V_97 ,
V_98 , V_74 , V_101 ) ;
V_92 = F_35 ( V_66 , V_97 ,
V_98 , V_74 , V_102 ) ;
if ( V_89 != V_90 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_11 ,
V_87 , V_88 ) ;
F_23 (
V_2 , V_6 , F_17 , V_73 , type , 0 ) ;
if ( V_48 != V_50 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_12 ,
V_87 , V_88 ) ;
F_23 (
V_2 , V_6 , F_20 ,
V_73 , type , V_89 ) ;
}
snprintf ( V_6 , sizeof( V_6 ) , L_13 ,
V_87 , V_88 ) ;
F_23 (
V_2 , V_6 , F_20 ,
V_73 , type , V_90 ) ;
if ( V_91 != V_92 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_14 ,
V_87 , V_88 ) ;
F_23 (
V_2 , V_6 , F_20 ,
V_73 , type , V_92 ) ;
}
}
snprintf ( V_6 , sizeof( V_6 ) , L_15 ,
V_87 , V_88 ) ;
F_23 (
V_2 , V_6 , F_21 , V_73 , type , 0 ) ;
if ( type < F_3 ( V_11 ) &&
V_11 [ type ] . V_12 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_16 ,
V_87 , V_88 ) ;
F_23 (
V_2 , V_6 , F_22 , V_73 , type , 0 ) ;
}
}
V_93:
V_17 -> V_103 [ 0 ] = & V_17 -> V_59 ;
V_17 -> V_29 = F_36 ( & V_2 -> V_104 -> V_30 ,
V_105 , NULL ,
V_17 -> V_103 ) ;
if ( F_37 ( V_17 -> V_29 ) ) {
V_20 = F_38 ( V_17 -> V_29 ) ;
goto V_84;
}
return 0 ;
V_84:
F_39 ( V_2 ) ;
return V_20 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
if ( V_17 -> V_29 )
F_40 ( V_17 -> V_29 ) ;
F_41 ( V_17 -> V_53 ) ;
F_41 ( V_17 -> V_59 . V_53 ) ;
F_42 ( V_2 , & V_17 -> V_22 ) ;
}
