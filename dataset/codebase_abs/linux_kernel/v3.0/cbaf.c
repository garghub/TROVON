static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
void * V_11 , * V_12 ;
int V_13 = 0 , V_14 = 0 ;
V_2 = F_2 (
V_1 -> V_15 , F_3 ( V_1 -> V_15 , 0 ) ,
V_16 ,
V_17 | V_18 | V_19 ,
0 , V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_1 -> V_23 , V_1 -> V_24 , 1000 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_1 ,
V_2 ) ;
return V_2 ;
}
V_7 = V_1 -> V_23 ;
if ( V_2 < sizeof( * V_7 ) ) {
F_4 ( V_4 , L_2
L_3 ,
( T_1 ) V_2 , sizeof( * V_7 ) ) ;
return V_2 ;
}
V_10 = F_5 ( V_7 -> V_25 ) ;
if ( V_2 < V_10 ) {
F_4 ( V_4 , L_2
L_4 ,
( T_1 ) V_10 , sizeof( * V_7 ) ) ;
return V_2 ;
}
V_11 = V_1 -> V_23 + sizeof( * V_7 ) ;
V_12 = V_1 -> V_23 + V_10 ;
F_6 ( V_4 , L_5 ,
V_7 -> V_26 , V_10 ) ;
while ( V_11 < V_12 ) {
T_2 V_27 , V_28 ;
T_3 V_29 ;
const char * V_30 ;
V_9 = V_11 ;
if ( V_12 - V_11 < sizeof( * V_9 ) ) {
F_4 ( V_4 , L_6
L_7 ,
V_12 - V_11 , sizeof( * V_9 ) ) ;
break;
}
V_27 = F_5 ( V_9 -> V_31 ) ;
V_28 = F_5 ( V_9 -> V_32 ) ;
V_29 = F_7 ( V_9 -> V_33 ) ;
V_30 = L_8 ;
switch ( V_27 ) {
case V_34 :
switch ( V_28 ) {
case V_35 :
V_30 = L_9 ;
V_13 = 1 ;
break;
case V_36 :
V_30 = L_10 ;
V_14 = 1 ;
break;
} ;
break;
} ;
F_6 ( V_4 , L_11
L_12 ,
V_9 -> V_37 , V_27 ,
V_28 , ( T_1 ) V_29 , V_30 ) ;
V_11 += sizeof( * V_9 ) ;
}
if ( ! V_13 ) {
F_4 ( V_4 , L_13
L_14 ) ;
return - V_38 ;
}
if ( ! V_14 ) {
F_4 ( V_4 , L_15 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_39 * V_40 ;
T_1 V_41 ;
T_1 V_42 ;
V_40 = V_1 -> V_23 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
* V_40 = V_43 ;
V_40 -> V_44 = V_1 -> V_45 ;
V_40 -> V_46 = 0 ;
F_9 ( V_40 -> V_47 , V_1 -> V_48 , V_49 ) ;
V_41 = strlen ( V_1 -> V_48 ) ;
V_40 -> V_50 . V_51 = F_10 ( V_41 ) ;
V_42 = sizeof( * V_40 ) + V_41 ;
return F_2 ( V_1 -> V_15 , F_11 ( V_1 -> V_15 , 0 ) ,
V_52 ,
V_53 | V_18 | V_19 ,
0x0101 ,
V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_40 , V_42 , 1000 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
struct V_54 * V_55 ;
T_1 V_56 ;
V_55 = V_1 -> V_23 ;
V_2 = F_2 (
V_1 -> V_15 , F_3 ( V_1 -> V_15 , 0 ) ,
V_57 ,
V_17 | V_18 | V_19 ,
0x0200 , V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_55 , V_1 -> V_24 , 1000 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_16 , V_2 ) ;
return V_2 ;
}
V_56 = V_2 < sizeof( * V_55 ) ? sizeof( * V_55 ) : F_7 ( V_55 -> V_25 ) ;
if ( V_2 < V_56 ) {
F_4 ( V_4 , L_17
L_18 , ( T_1 ) V_2 , V_56 ) ;
return V_2 ;
}
F_9 ( V_1 -> V_58 , V_55 -> V_59 , V_49 ) ;
V_1 -> V_60 = V_55 -> V_61 ;
V_1 -> V_62 = F_5 ( V_55 -> V_63 ) ;
return 0 ;
}
static T_4 F_13 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
char * V_66 )
{
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
char V_69 [ V_70 ] ;
F_16 ( V_69 , sizeof( V_69 ) , & V_1 -> V_45 ) ;
return F_17 ( V_66 , V_71 , L_19 , V_69 ) ;
}
static T_4 F_18 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
const char * V_66 , T_1 V_72 )
{
T_4 V_2 ;
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
V_2 = sscanf ( V_66 ,
L_20
L_20
L_20
L_21 ,
& V_1 -> V_45 . V_73 [ 0 ] , & V_1 -> V_45 . V_73 [ 1 ] ,
& V_1 -> V_45 . V_73 [ 2 ] , & V_1 -> V_45 . V_73 [ 3 ] ,
& V_1 -> V_45 . V_73 [ 4 ] , & V_1 -> V_45 . V_73 [ 5 ] ,
& V_1 -> V_45 . V_73 [ 6 ] , & V_1 -> V_45 . V_73 [ 7 ] ,
& V_1 -> V_45 . V_73 [ 8 ] , & V_1 -> V_45 . V_73 [ 9 ] ,
& V_1 -> V_45 . V_73 [ 10 ] , & V_1 -> V_45 . V_73 [ 11 ] ,
& V_1 -> V_45 . V_73 [ 12 ] , & V_1 -> V_45 . V_73 [ 13 ] ,
& V_1 -> V_45 . V_73 [ 14 ] , & V_1 -> V_45 . V_73 [ 15 ] ) ;
if ( V_2 != 16 )
return - V_38 ;
V_2 = F_8 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_12 ( V_1 ) ;
if ( V_2 < 0 )
return - V_2 ;
return V_72 ;
}
static T_4 F_19 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
char * V_66 )
{
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
return F_17 ( V_66 , V_71 , L_19 , V_1 -> V_48 ) ;
}
static T_4 F_20 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
const char * V_66 , T_1 V_72 )
{
T_4 V_2 ;
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
V_2 = sscanf ( V_66 , L_22 , V_1 -> V_48 ) ;
if ( V_2 != 1 )
return - V_38 ;
return V_72 ;
}
static T_4 F_21 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
char * V_66 )
{
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
return F_17 ( V_66 , V_71 , L_23 , V_1 -> V_74 ) ;
}
static T_4 F_22 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
const char * V_66 , T_1 V_72 )
{
T_4 V_2 ;
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
T_2 V_75 = 0 ;
V_2 = sscanf ( V_66 , L_24 , & V_75 ) ;
if ( V_2 != 1 )
return - V_38 ;
V_1 -> V_74 = V_75 ;
return V_72 ;
}
static T_4 F_23 ( struct V_3 * V_4 ,
struct V_64 * V_65 , char * V_66 )
{
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
char V_76 [ V_70 ] ;
F_16 ( V_76 , sizeof( V_76 ) , & V_1 -> V_60 ) ;
return F_17 ( V_66 , V_71 , L_19 , V_76 ) ;
}
static T_4 F_24 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
const char * V_66 , T_1 V_72 )
{
T_4 V_2 ;
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
struct V_77 V_60 ;
V_2 = sscanf ( V_66 ,
L_20
L_20
L_20
L_21 ,
& V_60 . V_73 [ 0 ] , & V_60 . V_73 [ 1 ] ,
& V_60 . V_73 [ 2 ] , & V_60 . V_73 [ 3 ] ,
& V_60 . V_73 [ 4 ] , & V_60 . V_73 [ 5 ] ,
& V_60 . V_73 [ 6 ] , & V_60 . V_73 [ 7 ] ,
& V_60 . V_73 [ 8 ] , & V_60 . V_73 [ 9 ] ,
& V_60 . V_73 [ 10 ] , & V_60 . V_73 [ 11 ] ,
& V_60 . V_73 [ 12 ] , & V_60 . V_73 [ 13 ] ,
& V_60 . V_73 [ 14 ] , & V_60 . V_73 [ 15 ] ) ;
if ( V_2 != 16 )
return - V_38 ;
V_1 -> V_60 = V_60 ;
return V_72 ;
}
static T_4 F_25 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
char * V_66 )
{
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
return F_17 ( V_66 , V_71 , L_23 , V_1 -> V_62 ) ;
}
static T_4 F_26 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
char * V_66 )
{
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
return F_17 ( V_66 , V_71 , L_19 , V_1 -> V_58 ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
struct V_78 * V_79 ;
char V_76 [ V_70 ] ;
V_79 = V_1 -> V_23 ;
* V_79 = V_80 ;
V_79 -> V_44 = V_1 -> V_45 ;
V_79 -> V_61 = V_1 -> V_60 ;
V_79 -> V_81 = V_1 -> V_82 ;
V_79 -> V_63 = F_10 ( V_1 -> V_74 ) ;
F_6 ( V_4 , L_25 ) ;
F_16 ( V_76 , sizeof( V_76 ) , & V_79 -> V_44 ) ;
F_6 ( V_4 , L_26 , V_76 ) ;
F_16 ( V_76 , sizeof( V_76 ) , & V_79 -> V_61 ) ;
F_6 ( V_4 , L_27 , V_76 ) ;
F_6 ( V_4 , L_28 , V_1 -> V_74 ) ;
V_2 = F_2 (
V_1 -> V_15 , F_11 ( V_1 -> V_15 , 0 ) ,
V_52 ,
V_53 | V_18 | V_19 ,
0x0201 , V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_79 , sizeof( * V_79 ) , 1000 ) ;
return V_2 ;
}
static T_4 F_28 ( struct V_3 * V_4 ,
struct V_64 * V_65 ,
const char * V_66 , T_1 V_72 )
{
T_4 V_2 ;
struct V_67 * V_68 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_68 ) ;
V_2 = sscanf ( V_66 ,
L_20
L_20
L_20
L_21 ,
& V_1 -> V_82 . V_73 [ 0 ] , & V_1 -> V_82 . V_73 [ 1 ] ,
& V_1 -> V_82 . V_73 [ 2 ] , & V_1 -> V_82 . V_73 [ 3 ] ,
& V_1 -> V_82 . V_73 [ 4 ] , & V_1 -> V_82 . V_73 [ 5 ] ,
& V_1 -> V_82 . V_73 [ 6 ] , & V_1 -> V_82 . V_73 [ 7 ] ,
& V_1 -> V_82 . V_73 [ 8 ] , & V_1 -> V_82 . V_73 [ 9 ] ,
& V_1 -> V_82 . V_73 [ 10 ] , & V_1 -> V_82 . V_73 [ 11 ] ,
& V_1 -> V_82 . V_73 [ 12 ] , & V_1 -> V_82 . V_73 [ 13 ] ,
& V_1 -> V_82 . V_73 [ 14 ] , & V_1 -> V_82 . V_73 [ 15 ] ) ;
if ( V_2 != 16 )
return - V_38 ;
V_2 = F_27 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
return V_72 ;
}
static int F_29 ( struct V_67 * V_68 ,
const struct V_83 * V_84 )
{
struct V_1 * V_1 ;
struct V_3 * V_4 = & V_68 -> V_4 ;
int V_2 = - V_85 ;
V_1 = F_30 ( sizeof( * V_1 ) , V_86 ) ;
if ( V_1 == NULL )
goto V_87;
V_1 -> V_23 = F_31 ( 512 , V_86 ) ;
if ( V_1 -> V_23 == NULL )
goto V_88;
V_1 -> V_24 = 512 ;
V_1 -> V_15 = F_32 ( F_33 ( V_68 ) ) ;
V_1 -> V_5 = F_34 ( V_68 ) ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_29
L_30 ) ;
goto V_89;
}
V_2 = F_35 ( & V_4 -> V_90 , & V_91 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_31 , V_2 ) ;
goto V_92;
}
F_36 ( V_68 , V_1 ) ;
return 0 ;
V_92:
V_89:
F_37 ( V_1 -> V_23 ) ;
V_88:
F_37 ( V_1 ) ;
V_87:
return V_2 ;
}
static void F_38 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_15 ( V_68 ) ;
struct V_3 * V_4 = & V_68 -> V_4 ;
F_39 ( & V_4 -> V_90 , & V_91 ) ;
F_36 ( V_68 , NULL ) ;
F_40 ( V_68 ) ;
F_37 ( V_1 -> V_23 ) ;
F_41 ( V_1 ) ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_93 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_93 ) ;
}
