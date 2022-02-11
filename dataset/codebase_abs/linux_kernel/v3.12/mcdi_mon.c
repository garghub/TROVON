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
static T_2 F_11 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
return sprintf ( V_33 , L_3 , V_34 ) ;
}
static int F_12 ( struct V_29 * V_30 , unsigned int V_35 ,
T_3 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_30 ) ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
int V_20 ;
F_14 ( V_37 != 0 ) ;
F_15 ( & V_17 -> V_38 ) ;
if ( F_16 ( V_28 , V_17 -> V_27 + V_39 ) )
V_20 = 0 ;
else
V_20 = F_6 ( V_2 ) ;
* V_36 = ( ( T_3 * ) V_17 -> V_22 . V_40 ) [ V_35 ] ;
F_17 ( & V_17 -> V_38 ) ;
return V_20 ;
}
static T_2 F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_19 ( V_32 , struct V_41 , V_43 ) ;
T_3 V_36 ;
unsigned int V_5 , V_4 ;
int V_20 ;
V_20 = F_12 ( V_30 , V_42 -> V_35 , & V_36 ) ;
if ( V_20 )
return V_20 ;
V_4 = F_20 ( V_36 , V_44 ) ;
if ( V_4 == V_45 )
return - V_46 ;
V_5 = F_20 ( V_36 , V_47 ) ;
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
return sprintf ( V_33 , L_4 , V_5 ) ;
}
static T_2 F_21 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_19 ( V_32 , struct V_41 , V_43 ) ;
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
return sprintf ( V_33 , L_4 , V_5 ) ;
}
static T_2 F_22 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_19 ( V_32 , struct V_41 , V_43 ) ;
T_3 V_36 ;
int V_4 ;
int V_20 ;
V_20 = F_12 ( V_30 , V_42 -> V_35 , & V_36 ) ;
if ( V_20 )
return V_20 ;
V_4 = F_20 ( V_36 , V_44 ) ;
return sprintf ( V_33 , L_5 , V_4 != V_52 ) ;
}
static T_2 F_23 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_19 ( V_32 , struct V_41 , V_43 ) ;
return sprintf ( V_33 , L_3 ,
V_11 [ V_42 -> type ] . V_12 ) ;
}
static int
F_24 ( struct V_1 * V_2 , const char * V_6 ,
T_2 (* F_25)( struct V_29 * ,
struct V_31 * , char * ) ,
unsigned int V_35 , unsigned int type ,
unsigned int V_51 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_41 * V_32 = & V_17 -> V_53 [ V_17 -> V_54 ] ;
int V_20 ;
F_26 ( V_32 -> V_6 , V_6 , sizeof( V_32 -> V_6 ) ) ;
V_32 -> V_35 = V_35 ;
V_32 -> type = type ;
if ( type < F_3 ( V_11 ) )
V_32 -> V_48 = V_11 [ type ] . V_48 ;
else
V_32 -> V_48 = V_55 ;
V_32 -> V_51 = V_51 ;
F_27 ( & V_32 -> V_43 . V_32 ) ;
V_32 -> V_43 . V_32 . V_6 = V_32 -> V_6 ;
V_32 -> V_43 . V_32 . V_56 = V_57 ;
V_32 -> V_43 . V_58 = F_25 ;
V_20 = F_28 ( & V_2 -> V_59 -> V_30 , & V_32 -> V_43 ) ;
if ( V_20 == 0 )
++ V_17 -> V_54 ;
return V_20 ;
}
int F_29 ( struct V_1 * V_2 )
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
V_72 = F_30 ( V_66 , V_79 ) ;
V_69 += F_31 ( V_72 & ~ ( 1 << V_80 ) ) ;
++ V_70 ;
} while ( V_72 & ( 1 << V_80 ) );
V_68 = V_70 ;
if ( V_69 == 0 )
return 0 ;
V_20 = F_32 (
V_2 , & V_17 -> V_22 ,
V_69 * V_81 ,
V_82 ) ;
if ( V_20 )
return V_20 ;
F_33 ( & V_17 -> V_38 ) ;
F_6 ( V_2 ) ;
V_54 = 1 + 6 * V_69 ;
V_17 -> V_53 = F_34 ( V_54 , sizeof( * V_17 -> V_53 ) , V_82 ) ;
if ( ! V_17 -> V_53 ) {
V_20 = - V_83 ;
goto V_84;
}
V_17 -> V_29 = F_35 ( & V_2 -> V_59 -> V_30 ) ;
if ( F_36 ( V_17 -> V_29 ) ) {
V_20 = F_37 ( V_17 -> V_29 ) ;
goto V_84;
}
V_20 = F_24 ( V_2 , L_6 , F_11 , 0 , 0 , 0 ) ;
if ( V_20 )
goto V_84;
for ( V_73 = 0 , V_74 = - 1 , type = - 1 ; ; V_73 ++ ) {
enum V_85 V_48 ;
const char * V_86 ;
unsigned V_87 ;
T_6 V_88 , V_89 , V_90 , V_91 ;
do {
type ++ ;
if ( ( type % 32 ) == 0 ) {
V_70 = type / 32 ;
V_74 = - 1 ;
if ( V_70 == V_68 )
return 0 ;
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
V_72 = ( F_30 ( V_66 ,
V_79 ) &
~ ( 1 << V_80 ) ) ;
if ( V_71 <
F_38 ( F_31 ( V_72 ) ) ) {
V_20 = - V_78 ;
goto V_84;
}
}
} while ( ! ( V_72 & ( 1 << type % 32 ) ) );
V_74 ++ ;
if ( type < F_3 ( V_11 ) ) {
V_48 = V_11 [ type ] . V_48 ;
if ( V_48 != V_55 &&
V_11 [ type ] . V_92 >= 0 &&
V_11 [ type ] . V_92 !=
F_39 ( V_2 ) )
continue;
} else {
V_48 = V_55 ;
}
switch ( V_48 ) {
case V_49 :
V_86 = L_7 ;
V_87 = ++ V_60 ;
break;
case V_93 :
V_86 = L_8 ;
V_87 = ++ V_61 ;
break;
default:
V_86 = L_9 ;
V_87 = V_62 ++ ;
break;
case V_94 :
V_86 = L_10 ;
V_87 = ++ V_63 ;
break;
case V_50 :
V_86 = L_11 ;
V_87 = ++ V_64 ;
break;
}
V_88 = F_40 ( V_66 , V_95 ,
V_96 , V_74 , V_97 ) ;
V_89 = F_40 ( V_66 , V_95 ,
V_96 , V_74 , V_98 ) ;
V_90 = F_40 ( V_66 , V_95 ,
V_96 , V_74 , V_99 ) ;
V_91 = F_40 ( V_66 , V_95 ,
V_96 , V_74 , V_100 ) ;
if ( V_88 != V_89 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_12 ,
V_86 , V_87 ) ;
V_20 = F_24 (
V_2 , V_6 , F_18 , V_73 , type , 0 ) ;
if ( V_20 )
goto V_84;
if ( V_48 != V_50 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_13 ,
V_86 , V_87 ) ;
V_20 = F_24 (
V_2 , V_6 , F_21 ,
V_73 , type , V_88 ) ;
if ( V_20 )
goto V_84;
}
snprintf ( V_6 , sizeof( V_6 ) , L_14 ,
V_86 , V_87 ) ;
V_20 = F_24 (
V_2 , V_6 , F_21 ,
V_73 , type , V_89 ) ;
if ( V_20 )
goto V_84;
if ( V_90 != V_91 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_15 ,
V_86 , V_87 ) ;
V_20 = F_24 (
V_2 , V_6 , F_21 ,
V_73 , type , V_91 ) ;
if ( V_20 )
goto V_84;
}
}
snprintf ( V_6 , sizeof( V_6 ) , L_16 ,
V_86 , V_87 ) ;
V_20 = F_24 (
V_2 , V_6 , F_22 , V_73 , type , 0 ) ;
if ( V_20 )
goto V_84;
if ( type < F_3 ( V_11 ) &&
V_11 [ type ] . V_12 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_17 ,
V_86 , V_87 ) ;
V_20 = F_24 (
V_2 , V_6 , F_23 , V_73 , type , 0 ) ;
if ( V_20 )
goto V_84;
}
}
V_84:
F_41 ( V_2 ) ;
return V_20 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_17 -> V_54 ; V_73 ++ )
F_42 ( & V_2 -> V_59 -> V_30 ,
& V_17 -> V_53 [ V_73 ] . V_43 ) ;
F_43 ( V_17 -> V_53 ) ;
if ( V_17 -> V_29 )
F_44 ( V_17 -> V_29 ) ;
F_45 ( V_2 , & V_17 -> V_22 ) ;
}
