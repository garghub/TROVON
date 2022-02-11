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
T_2 V_18 [ V_19 ] ;
int V_20 ;
F_7 ( V_18 , V_21 ,
V_17 -> V_22 . V_23 & 0xffffffff ) ;
F_7 ( V_18 , V_24 ,
( V_25 ) V_17 -> V_22 . V_23 >> 32 ) ;
V_20 = F_8 ( V_2 , V_26 ,
V_18 , sizeof( V_18 ) , NULL , 0 , NULL ) ;
if ( V_20 == 0 )
V_17 -> V_27 = V_28 ;
return V_20 ;
}
static T_3 F_9 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
return sprintf ( V_33 , L_3 , V_34 ) ;
}
static int F_10 ( struct V_29 * V_30 , unsigned int V_35 ,
T_4 * V_36 )
{
struct V_1 * V_2 = F_11 ( V_30 ) ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
int V_20 ;
F_12 ( V_37 != 0 ) ;
F_13 ( & V_17 -> V_38 ) ;
if ( F_14 ( V_28 , V_17 -> V_27 + V_39 ) )
V_20 = 0 ;
else
V_20 = F_6 ( V_2 ) ;
* V_36 = ( ( T_4 * ) V_17 -> V_22 . V_40 ) [ V_35 ] ;
F_15 ( & V_17 -> V_38 ) ;
return V_20 ;
}
static T_3 F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_17 ( V_32 , struct V_41 , V_43 ) ;
T_4 V_36 ;
unsigned int V_5 ;
int V_20 ;
V_20 = F_10 ( V_30 , V_42 -> V_35 , & V_36 ) ;
if ( V_20 )
return V_20 ;
V_5 = F_18 ( V_36 , V_44 ) ;
if ( V_11 [ V_42 -> type ] . V_45 == V_46 )
V_5 *= 1000 ;
return sprintf ( V_33 , L_4 , V_5 ) ;
}
static T_3 F_19 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_17 ( V_32 , struct V_41 , V_43 ) ;
unsigned int V_5 ;
V_5 = V_42 -> V_47 ;
if ( V_11 [ V_42 -> type ] . V_45 == V_46 )
V_5 *= 1000 ;
return sprintf ( V_33 , L_4 , V_5 ) ;
}
static T_3 F_20 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_17 ( V_32 , struct V_41 , V_43 ) ;
T_4 V_36 ;
int V_4 ;
int V_20 ;
V_20 = F_10 ( V_30 , V_42 -> V_35 , & V_36 ) ;
if ( V_20 )
return V_20 ;
V_4 = F_18 ( V_36 , V_48 ) ;
return sprintf ( V_33 , L_5 , V_4 != V_49 ) ;
}
static T_3 F_21 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_41 * V_42 =
F_17 ( V_32 , struct V_41 , V_43 ) ;
return sprintf ( V_33 , L_3 ,
V_11 [ V_42 -> type ] . V_12 ) ;
}
static int
F_22 ( struct V_1 * V_2 , const char * V_6 ,
T_3 (* F_23)( struct V_29 * ,
struct V_31 * , char * ) ,
unsigned int V_35 , unsigned int type ,
unsigned int V_47 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_41 * V_32 = & V_17 -> V_50 [ V_17 -> V_51 ] ;
int V_20 ;
F_24 ( V_32 -> V_6 , V_6 , sizeof( V_32 -> V_6 ) ) ;
V_32 -> V_35 = V_35 ;
V_32 -> type = type ;
V_32 -> V_47 = V_47 ;
F_25 ( & V_32 -> V_43 . V_32 ) ;
V_32 -> V_43 . V_32 . V_6 = V_32 -> V_6 ;
V_32 -> V_43 . V_32 . V_52 = V_53 ;
V_32 -> V_43 . V_54 = F_23 ;
V_20 = F_26 ( & V_2 -> V_55 -> V_30 , & V_32 -> V_43 ) ;
if ( V_20 == 0 )
++ V_17 -> V_51 ;
return V_20 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
unsigned int V_51 , V_56 = 0 , V_57 = 0 , V_58 = 0 ;
T_2 V_59 [ V_60 ] ;
T_5 V_61 ;
char V_6 [ 12 ] ;
T_6 V_62 ;
int V_20 , V_63 , type ;
F_12 ( V_64 != 0 ) ;
V_20 = F_8 ( V_2 , V_65 , NULL , 0 ,
V_59 , sizeof( V_59 ) , & V_61 ) ;
if ( V_20 )
return V_20 ;
if ( V_61 < V_66 )
return - V_67 ;
V_62 = F_28 ( V_59 , V_68 ) ;
if ( V_62 == 0 )
return 0 ;
if ( V_61 < F_29 ( F_30 ( V_62 ) ) )
return - V_67 ;
V_20 = F_31 ( V_2 , & V_17 -> V_22 ,
4 * V_69 ) ;
if ( V_20 )
return V_20 ;
F_32 ( & V_17 -> V_38 ) ;
F_6 ( V_2 ) ;
V_51 = 1 + 6 * F_30 ( V_62 ) ;
V_17 -> V_50 = F_33 ( V_51 , sizeof( * V_17 -> V_50 ) , V_70 ) ;
if ( ! V_17 -> V_50 ) {
V_20 = - V_71 ;
goto V_72;
}
V_17 -> V_29 = F_34 ( & V_2 -> V_55 -> V_30 ) ;
if ( F_35 ( V_17 -> V_29 ) ) {
V_20 = F_36 ( V_17 -> V_29 ) ;
goto V_72;
}
V_20 = F_22 ( V_2 , L_6 , F_9 , 0 , 0 , 0 ) ;
if ( V_20 )
goto V_72;
for ( V_63 = 0 , type = - 1 ; ; V_63 ++ ) {
const char * V_73 ;
unsigned V_74 ;
T_7 V_75 , V_76 , V_77 , V_78 ;
type ++ ;
while ( ! ( V_62 & ( 1 << type ) ) ) {
type ++ ;
if ( type == 32 )
return 0 ;
}
if ( V_11 [ type ] . V_45 != V_79 &&
V_11 [ type ] . V_80 >= 0 &&
V_11 [ type ] . V_80 != F_37 ( V_2 ) )
continue;
switch ( V_11 [ type ] . V_45 ) {
case V_46 :
V_73 = L_7 ;
V_74 = ++ V_56 ;
break;
case V_81 :
V_73 = L_8 ;
V_74 = ++ V_57 ;
break;
default:
V_73 = L_9 ;
V_74 = V_58 ++ ;
break;
}
V_75 = F_38 ( V_59 , V_82 ,
V_83 , V_63 , V_84 ) ;
V_76 = F_38 ( V_59 , V_82 ,
V_83 , V_63 , V_85 ) ;
V_77 = F_38 ( V_59 , V_82 ,
V_83 , V_63 , V_86 ) ;
V_78 = F_38 ( V_59 , V_82 ,
V_83 , V_63 , V_87 ) ;
if ( V_75 != V_76 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_10 ,
V_73 , V_74 ) ;
V_20 = F_22 (
V_2 , V_6 , F_16 , V_63 , type , 0 ) ;
if ( V_20 )
goto V_72;
snprintf ( V_6 , sizeof( V_6 ) , L_11 ,
V_73 , V_74 ) ;
V_20 = F_22 (
V_2 , V_6 , F_19 ,
V_63 , type , V_75 ) ;
if ( V_20 )
goto V_72;
snprintf ( V_6 , sizeof( V_6 ) , L_12 ,
V_73 , V_74 ) ;
V_20 = F_22 (
V_2 , V_6 , F_19 ,
V_63 , type , V_76 ) ;
if ( V_20 )
goto V_72;
if ( V_77 != V_78 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_13 ,
V_73 , V_74 ) ;
V_20 = F_22 (
V_2 , V_6 , F_19 ,
V_63 , type , V_78 ) ;
if ( V_20 )
goto V_72;
}
}
snprintf ( V_6 , sizeof( V_6 ) , L_14 ,
V_73 , V_74 ) ;
V_20 = F_22 (
V_2 , V_6 , F_20 , V_63 , type , 0 ) ;
if ( V_20 )
goto V_72;
if ( V_11 [ type ] . V_12 ) {
snprintf ( V_6 , sizeof( V_6 ) , L_15 ,
V_73 , V_74 ) ;
V_20 = F_22 (
V_2 , V_6 , F_21 , V_63 , type , 0 ) ;
if ( V_20 )
goto V_72;
}
}
V_72:
F_39 ( V_2 ) ;
return V_20 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
struct V_16 * V_17 = & V_89 -> V_17 ;
unsigned int V_63 ;
for ( V_63 = 0 ; V_63 < V_17 -> V_51 ; V_63 ++ )
F_40 ( & V_2 -> V_55 -> V_30 ,
& V_17 -> V_50 [ V_63 ] . V_43 ) ;
F_41 ( V_17 -> V_50 ) ;
if ( V_17 -> V_29 )
F_42 ( V_17 -> V_29 ) ;
F_43 ( V_2 , & V_17 -> V_22 ) ;
}
