static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
union V_5 V_6 [] = {
{ . integer . type = V_7 ,
. integer . V_8 = V_3 , } ,
{ . integer . type = V_7 ,
. integer . V_8 = V_4 , } ,
} ;
struct V_9 V_10 = {
. V_11 = F_2 ( V_6 ) ,
. V_12 = V_6 ,
} ;
T_1 V_13 = V_14 ;
V_13 = F_3 ( V_2 -> V_15 , V_16 ,
& V_10 , NULL ) ;
return ( V_13 == V_14 ) ? 0 : - V_17 ;
}
static inline int F_4 ( struct V_18 * V_19 )
{
unsigned long long V_20 ;
T_1 V_13 ;
V_13 = F_5 ( V_19 -> V_15 , V_21 ,
NULL , & V_20 ) ;
if ( F_6 ( V_13 ) )
return V_20 ;
else {
F_7 ( ( V_22 ,
L_1 ) ) ;
return - V_23 ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_13 ;
struct V_24 V_25 = { V_26 , NULL } ;
union V_5 * V_27 = NULL ;
int V_28 ;
V_13 = F_3 ( V_2 -> V_15 , V_29 , NULL ,
& V_25 ) ;
if ( F_9 ( V_13 ) ) {
F_7 ( ( V_22 ,
L_2 ) ) ;
return 0 ;
}
V_27 = V_25 . V_12 ;
if ( ! V_27 || ( V_27 -> type != V_30 ) ) {
F_7 ( ( V_22 , L_3 ) ) ;
V_13 = V_31 ;
goto V_32;
}
if ( V_2 -> V_33 < V_27 -> V_34 . V_11 ) {
F_7 ( ( V_22 ,
L_4 ) ) ;
V_13 = V_31 ;
goto V_32;
}
for ( V_28 = 0 ; V_28 < V_27 -> V_34 . V_11 ; V_28 ++ ) {
union V_5 * V_35 = & ( V_27 -> V_34 . V_36 [ V_28 ] ) ;
if ( F_10 ( V_35 -> type == V_7 ) ) {
V_2 -> V_37 [ V_28 ] = V_35 -> integer . V_8 ;
} else
F_7 ( ( V_22 ,
L_5 ) ) ;
}
V_2 -> V_37 [ V_27 -> V_34 . V_11 ] = - 1 ;
V_32:
F_11 ( V_25 . V_12 ) ;
return V_13 == V_14 ;
}
static int F_12 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_13 ( V_39 ) ;
if ( ! F_8 ( V_2 ) )
return - V_17 ;
return V_2 -> V_37 [ V_40 ] ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_13 ( V_39 ) ;
int V_41 = V_39 -> V_42 . V_43 ;
int V_44 ;
if ( ! F_8 ( V_2 ) )
return - V_17 ;
if ( V_41 < V_2 -> V_37 [ V_45 ] )
V_41 = V_2 -> V_37 [ V_45 ] ;
if ( V_41 < V_2 -> V_37 [ V_46 ] )
V_41 = V_2 -> V_37 [ V_46 ] ;
if ( V_41 < V_2 -> V_37 [ V_45 ] ||
V_41 > V_2 -> V_37 [ V_47 ] )
return - V_23 ;
V_44 = F_1 ( V_2 , V_40 , V_41 ) ;
if ( V_44 < 0 )
return V_44 ;
return F_1 ( V_2 , V_48 , V_41 ) ;
}
static T_2 F_15 ( struct V_19 * V_49 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_18 * V_53 = F_16 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_53 ) ;
if ( ! F_8 ( V_2 ) )
return - V_17 ;
return snprintf ( V_52 , V_54 , L_6 , V_2 -> V_37 [ V_55 ] ) ;
}
static T_2 F_18 ( struct V_19 * V_49 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_18 * V_53 = F_16 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_53 ) ;
if ( ! F_8 ( V_2 ) )
return - V_17 ;
return snprintf ( V_52 , V_54 , L_6 , V_2 -> V_37 [ V_56 ] ) ;
}
static T_2 F_19 ( struct V_19 * V_49 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_18 * V_53 = F_16 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_53 ) ;
if ( ! F_8 ( V_2 ) )
return - V_17 ;
return snprintf ( V_52 , V_54 , L_6 , V_2 -> V_37 [ V_57 ] ) ;
}
static T_2 F_20 ( struct V_19 * V_49 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_18 * V_53 = F_16 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_53 ) ;
if ( ! F_8 ( V_2 ) )
return - V_17 ;
return snprintf ( V_52 , V_54 , L_6 , V_2 -> V_37 [ V_58 ] ) ;
}
static T_2 F_21 ( struct V_19 * V_49 , struct V_50 * V_51 ,
const char * V_52 , T_3 V_11 )
{
struct V_18 * V_53 = F_16 ( V_49 ) ;
struct V_1 * V_2 = F_17 ( V_53 ) ;
int V_4 ;
if ( V_11 && sscanf ( V_52 , L_7 , & V_4 ) == 1 &&
( V_4 == 0 || V_4 == 1 ) ) {
F_1 ( V_2 , V_58 , V_4 ) ;
V_2 -> V_59 = V_4 ;
}
return V_11 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_60 ;
int V_44 ;
unsigned long long V_62 ;
V_44 = F_5 ( V_2 -> V_15 , V_63 ,
NULL , & V_62 ) ;
if ( F_9 ( V_44 ) ) {
F_7 ( ( V_22 ,
L_8 ) ) ;
return;
}
if ( ( V_62 & 0xf ) == 0x7 || ( V_62 & 0xf ) == 0xa ) {
if ( V_62 & 0x80 )
V_64 = 1 ;
if ( ! V_64 )
F_23 ( V_61 ,
V_62 & 0xf , 0x80 , false ) ;
}
if ( ! F_23 ( V_61 ,
V_62 & 0xf , V_62 & 0x80 , false ) )
F_7 ( ( V_22 ,
L_9 , V_62 ) ) ;
}
static void F_24 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
switch ( V_65 ) {
case V_66 :
F_22 ( V_2 ) ;
break;
default:
break;
}
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_60 * V_60 ;
int error ;
V_60 = F_26 () ;
if ( ! V_60 )
return - V_67 ;
V_60 -> V_68 = V_69 ;
V_60 -> V_70 = V_71 ;
V_60 -> V_72 . V_73 = V_74 ;
V_60 -> V_72 . V_75 = 0x0001 ;
V_60 -> V_72 . V_76 = 0x0001 ;
V_60 -> V_72 . V_77 = 0x0100 ;
error = F_27 ( V_60 , V_78 , NULL ) ;
if ( error ) {
F_7 ( ( V_22 ,
L_10 ) ) ;
goto V_79;
}
error = F_28 ( V_60 ) ;
if ( error ) {
F_7 ( ( V_22 ,
L_11 ) ) ;
goto V_80;
}
V_2 -> V_60 = V_60 ;
return 0 ;
V_80:
F_29 ( V_60 ) ;
V_79:
F_30 ( V_60 ) ;
return error ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_60 ) ;
F_32 ( V_2 -> V_60 ) ;
}
static int F_33 ( struct V_19 * V_49 )
{
struct V_1 * V_2 ;
if ( ! V_49 )
return - V_23 ;
V_2 = F_17 ( F_16 ( V_49 ) ) ;
if ( ! V_2 )
return - V_23 ;
F_7 ( ( V_22 , L_12 ,
V_2 -> V_59 ) ) ;
return F_1 ( V_2 , V_58 , V_2 -> V_59 ) ;
}
static int F_34 ( struct V_18 * V_19 )
{
struct V_81 V_42 ;
struct V_1 * V_2 ;
int V_33 , V_62 ;
if ( ! V_19 )
return - V_23 ;
V_33 = F_4 ( V_19 ) ;
if ( V_33 < 0 || V_33 > 255 ) {
F_7 ( ( V_22 , L_13 ) ) ;
return - V_82 ;
}
V_2 = F_35 ( sizeof( struct V_1 ) , V_83 ) ;
if ( ! V_2 ) {
F_7 ( ( V_22 ,
L_14 ) ) ;
return - V_67 ;
}
V_2 -> V_37 = F_35 ( sizeof( T_4 ) * ( V_33 + 1 ) , V_83 ) ;
if ( ! V_2 -> V_37 ) {
V_62 = - V_67 ;
goto V_84;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_15 = V_19 -> V_15 ;
V_2 -> V_33 = V_33 ;
V_19 -> V_85 = V_2 ;
strcpy ( F_36 ( V_19 ) , V_86 ) ;
strcpy ( F_37 ( V_19 ) , V_87 ) ;
V_62 = F_25 ( V_2 ) ;
if ( V_62 ) {
F_7 ( ( V_22 ,
L_15 ) ) ;
goto V_88;
}
if ( ! F_8 ( V_2 ) ) {
F_7 ( ( V_22 ,
L_16 ) ) ;
V_62 = - V_17 ;
goto V_89;
}
memset ( & V_42 , 0 , sizeof( struct V_81 ) ) ;
V_42 . type = V_90 ;
V_42 . V_91 = V_2 -> V_37 [ V_47 ] ;
V_2 -> V_92 = F_38 ( L_17 , NULL , V_2 ,
& V_93 , & V_42 ) ;
if ( F_39 ( V_2 -> V_92 ) ) {
V_62 = F_40 ( V_2 -> V_92 ) ;
goto V_89;
}
V_2 -> V_92 -> V_42 . V_43 = V_2 -> V_37 [ V_40 ] ;
V_2 -> V_59 = V_2 -> V_37 [ V_58 ] ;
V_62 = F_41 ( & V_19 -> V_49 . V_94 , & V_95 ) ;
if ( V_62 )
goto V_96;
return 0 ;
V_96:
F_42 ( V_2 -> V_92 ) ;
V_89:
F_31 ( V_2 ) ;
V_88:
F_11 ( V_2 -> V_37 ) ;
V_84:
F_11 ( V_2 ) ;
return V_62 ;
}
static int F_43 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
if ( ! V_19 || ! V_2 )
return - V_23 ;
F_44 ( & V_19 -> V_49 . V_94 , & V_95 ) ;
F_42 ( V_2 -> V_92 ) ;
F_31 ( V_2 ) ;
F_11 ( V_2 -> V_37 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
