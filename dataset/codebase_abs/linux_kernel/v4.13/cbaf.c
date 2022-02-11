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
V_1 -> V_23 , V_1 -> V_24 , V_25 ) ;
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
V_10 = F_5 ( V_7 -> V_26 ) ;
if ( V_2 < V_10 ) {
F_4 ( V_4 , L_2
L_4 ,
( T_1 ) V_10 , sizeof( * V_7 ) ) ;
return V_2 ;
}
V_11 = V_1 -> V_23 + sizeof( * V_7 ) ;
V_12 = V_1 -> V_23 + V_10 ;
F_6 ( V_4 , L_5 ,
V_7 -> V_27 , V_10 ) ;
while ( V_11 < V_12 ) {
T_2 V_28 , V_29 ;
T_3 V_30 ;
const char * V_31 ;
V_9 = V_11 ;
if ( V_12 - V_11 < sizeof( * V_9 ) ) {
F_4 ( V_4 , L_6
L_7 ,
V_12 - V_11 , sizeof( * V_9 ) ) ;
break;
}
V_28 = F_5 ( V_9 -> V_32 ) ;
V_29 = F_5 ( V_9 -> V_33 ) ;
V_30 = F_7 ( V_9 -> V_34 ) ;
V_31 = L_8 ;
switch ( V_28 ) {
case V_35 :
switch ( V_29 ) {
case V_36 :
V_31 = L_9 ;
V_13 = 1 ;
break;
case V_37 :
V_31 = L_10 ;
V_14 = 1 ;
break;
}
break;
}
F_6 ( V_4 , L_11
L_12 ,
V_9 -> V_38 , V_28 ,
V_29 , ( T_1 ) V_30 , V_31 ) ;
V_11 += sizeof( * V_9 ) ;
}
if ( ! V_13 ) {
F_4 ( V_4 , L_13
L_14 ) ;
return - V_39 ;
}
if ( ! V_14 ) {
F_4 ( V_4 , L_15 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_40 * V_41 ;
T_1 V_42 ;
T_1 V_43 ;
V_41 = V_1 -> V_23 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
* V_41 = V_44 ;
V_41 -> V_45 = V_1 -> V_46 ;
V_41 -> V_47 = 0 ;
F_9 ( V_41 -> V_48 , V_1 -> V_49 , V_50 ) ;
V_42 = strlen ( V_1 -> V_49 ) ;
V_41 -> V_51 . V_52 = F_10 ( V_42 ) ;
V_43 = sizeof( * V_41 ) + V_42 ;
return F_2 ( V_1 -> V_15 ,
F_11 ( V_1 -> V_15 , 0 ) ,
V_53 ,
V_54 | V_18 | V_19 ,
0x0101 ,
V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_41 , V_43 , V_55 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
struct V_56 * V_57 ;
T_1 V_58 ;
V_57 = V_1 -> V_23 ;
V_2 = F_2 (
V_1 -> V_15 , F_3 ( V_1 -> V_15 , 0 ) ,
V_59 ,
V_17 | V_18 | V_19 ,
0x0200 , V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_57 , V_1 -> V_24 , V_25 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_16 ,
V_2 ) ;
return V_2 ;
}
V_58 = V_2 < sizeof( * V_57 ) ? sizeof( * V_57 ) : F_7 ( V_57 -> V_26 ) ;
if ( V_2 < V_58 ) {
F_4 ( V_4 , L_17
L_18 , ( T_1 ) V_2 , V_58 ) ;
return - V_60 ;
}
F_9 ( V_1 -> V_61 , V_57 -> V_62 , V_50 ) ;
V_1 -> V_63 = V_57 -> V_64 ;
V_1 -> V_65 = F_5 ( V_57 -> V_66 ) ;
return 0 ;
}
static T_4 F_13 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
char V_72 [ V_73 ] ;
F_16 ( V_72 , sizeof( V_72 ) , & V_1 -> V_46 ) ;
return F_17 ( V_69 , V_74 , L_19 , V_72 ) ;
}
static T_4 F_18 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
const char * V_69 , T_1 V_75 )
{
T_4 V_2 ;
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
V_2 = sscanf ( V_69 ,
L_20
L_20
L_20
L_21 ,
& V_1 -> V_46 . V_76 [ 0 ] , & V_1 -> V_46 . V_76 [ 1 ] ,
& V_1 -> V_46 . V_76 [ 2 ] , & V_1 -> V_46 . V_76 [ 3 ] ,
& V_1 -> V_46 . V_76 [ 4 ] , & V_1 -> V_46 . V_76 [ 5 ] ,
& V_1 -> V_46 . V_76 [ 6 ] , & V_1 -> V_46 . V_76 [ 7 ] ,
& V_1 -> V_46 . V_76 [ 8 ] , & V_1 -> V_46 . V_76 [ 9 ] ,
& V_1 -> V_46 . V_76 [ 10 ] , & V_1 -> V_46 . V_76 [ 11 ] ,
& V_1 -> V_46 . V_76 [ 12 ] , & V_1 -> V_46 . V_76 [ 13 ] ,
& V_1 -> V_46 . V_76 [ 14 ] , & V_1 -> V_46 . V_76 [ 15 ] ) ;
if ( V_2 != 16 )
return - V_39 ;
V_2 = F_8 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_12 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
return V_75 ;
}
static T_4 F_19 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
return F_17 ( V_69 , V_74 , L_19 , V_1 -> V_49 ) ;
}
static T_4 F_20 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
const char * V_69 , T_1 V_75 )
{
T_4 V_2 ;
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
V_2 = sscanf ( V_69 , L_22 , V_1 -> V_49 ) ;
if ( V_2 != 1 )
return - V_39 ;
return V_75 ;
}
static T_4 F_21 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
return F_17 ( V_69 , V_74 , L_23 , V_1 -> V_77 ) ;
}
static T_4 F_22 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
const char * V_69 , T_1 V_75 )
{
T_4 V_2 ;
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
T_2 V_78 = 0 ;
V_2 = sscanf ( V_69 , L_24 , & V_78 ) ;
if ( V_2 != 1 )
return - V_39 ;
V_1 -> V_77 = V_78 ;
return V_75 ;
}
static T_4 F_23 ( struct V_3 * V_4 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
char V_79 [ V_73 ] ;
F_16 ( V_79 , sizeof( V_79 ) , & V_1 -> V_63 ) ;
return F_17 ( V_69 , V_74 , L_19 , V_79 ) ;
}
static T_4 F_24 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
const char * V_69 , T_1 V_75 )
{
T_4 V_2 ;
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
struct V_80 V_63 ;
V_2 = sscanf ( V_69 ,
L_20
L_20
L_20
L_21 ,
& V_63 . V_76 [ 0 ] , & V_63 . V_76 [ 1 ] ,
& V_63 . V_76 [ 2 ] , & V_63 . V_76 [ 3 ] ,
& V_63 . V_76 [ 4 ] , & V_63 . V_76 [ 5 ] ,
& V_63 . V_76 [ 6 ] , & V_63 . V_76 [ 7 ] ,
& V_63 . V_76 [ 8 ] , & V_63 . V_76 [ 9 ] ,
& V_63 . V_76 [ 10 ] , & V_63 . V_76 [ 11 ] ,
& V_63 . V_76 [ 12 ] , & V_63 . V_76 [ 13 ] ,
& V_63 . V_76 [ 14 ] , & V_63 . V_76 [ 15 ] ) ;
if ( V_2 != 16 )
return - V_39 ;
V_1 -> V_63 = V_63 ;
return V_75 ;
}
static T_4 F_25 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
return F_17 ( V_69 , V_74 , L_23 , V_1 -> V_65 ) ;
}
static T_4 F_26 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
return F_17 ( V_69 , V_74 , L_19 , V_1 -> V_61 ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_2 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
struct V_81 * V_82 ;
char V_79 [ V_73 ] ;
V_82 = V_1 -> V_23 ;
* V_82 = V_83 ;
V_82 -> V_45 = V_1 -> V_46 ;
V_82 -> V_64 = V_1 -> V_63 ;
V_82 -> V_84 = V_1 -> V_85 ;
V_82 -> V_66 = F_10 ( V_1 -> V_77 ) ;
F_6 ( V_4 , L_25 ) ;
F_16 ( V_79 , sizeof( V_79 ) , & V_82 -> V_45 ) ;
F_6 ( V_4 , L_26 , V_79 ) ;
F_16 ( V_79 , sizeof( V_79 ) , & V_82 -> V_64 ) ;
F_6 ( V_4 , L_27 , V_79 ) ;
F_6 ( V_4 , L_28 , V_1 -> V_77 ) ;
V_2 = F_2 (
V_1 -> V_15 , F_11 ( V_1 -> V_15 , 0 ) ,
V_53 ,
V_54 | V_18 | V_19 ,
0x0201 , V_1 -> V_5 -> V_20 -> V_21 . V_22 ,
V_82 , sizeof( * V_82 ) , V_55 ) ;
return V_2 ;
}
static T_4 F_28 ( struct V_3 * V_4 ,
struct V_67 * V_68 ,
const char * V_69 , T_1 V_75 )
{
T_4 V_2 ;
struct V_70 * V_71 = F_14 ( V_4 ) ;
struct V_1 * V_1 = F_15 ( V_71 ) ;
V_2 = sscanf ( V_69 ,
L_20
L_20
L_20
L_21 ,
& V_1 -> V_85 . V_76 [ 0 ] , & V_1 -> V_85 . V_76 [ 1 ] ,
& V_1 -> V_85 . V_76 [ 2 ] , & V_1 -> V_85 . V_76 [ 3 ] ,
& V_1 -> V_85 . V_76 [ 4 ] , & V_1 -> V_85 . V_76 [ 5 ] ,
& V_1 -> V_85 . V_76 [ 6 ] , & V_1 -> V_85 . V_76 [ 7 ] ,
& V_1 -> V_85 . V_76 [ 8 ] , & V_1 -> V_85 . V_76 [ 9 ] ,
& V_1 -> V_85 . V_76 [ 10 ] , & V_1 -> V_85 . V_76 [ 11 ] ,
& V_1 -> V_85 . V_76 [ 12 ] , & V_1 -> V_85 . V_76 [ 13 ] ,
& V_1 -> V_85 . V_76 [ 14 ] , & V_1 -> V_85 . V_76 [ 15 ] ) ;
if ( V_2 != 16 )
return - V_39 ;
V_2 = F_27 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
return V_75 ;
}
static int F_29 ( struct V_70 * V_71 ,
const struct V_86 * V_87 )
{
struct V_1 * V_1 ;
struct V_3 * V_4 = & V_71 -> V_4 ;
int V_2 = - V_88 ;
V_1 = F_30 ( sizeof( * V_1 ) , V_89 ) ;
if ( V_1 == NULL )
goto V_90;
V_1 -> V_23 = F_31 ( 512 , V_89 ) ;
if ( V_1 -> V_23 == NULL )
goto V_91;
V_1 -> V_24 = 512 ;
V_1 -> V_15 = F_32 ( F_33 ( V_71 ) ) ;
V_1 -> V_5 = F_34 ( V_71 ) ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_29 ) ;
goto V_92;
}
V_2 = F_35 ( & V_4 -> V_93 , & V_94 ) ;
if ( V_2 < 0 ) {
F_4 ( V_4 , L_30 , V_2 ) ;
goto V_95;
}
F_36 ( V_71 , V_1 ) ;
return 0 ;
V_95:
V_92:
F_37 ( V_71 ) ;
F_38 ( V_1 -> V_15 ) ;
F_39 ( V_1 -> V_23 ) ;
V_91:
F_39 ( V_1 ) ;
V_90:
return V_2 ;
}
static void F_40 ( struct V_70 * V_71 )
{
struct V_1 * V_1 = F_15 ( V_71 ) ;
struct V_3 * V_4 = & V_71 -> V_4 ;
F_41 ( & V_4 -> V_93 , & V_94 ) ;
F_36 ( V_71 , NULL ) ;
F_37 ( V_71 ) ;
F_38 ( V_1 -> V_15 ) ;
F_39 ( V_1 -> V_23 ) ;
F_42 ( V_1 ) ;
}
