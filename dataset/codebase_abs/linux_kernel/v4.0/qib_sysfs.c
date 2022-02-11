static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_6 = V_5 -> V_7 ( V_2 , V_8 ) ;
V_6 = F_2 ( V_3 , V_9 , L_1 , V_6 ) ;
return V_6 ;
}
static T_1 F_3 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
T_3 V_11 ;
V_6 = F_4 ( V_3 , 0 , & V_11 ) ;
if ( V_6 ) {
F_5 ( V_5 , L_2 ) ;
return V_6 ;
}
V_6 = V_5 -> V_12 ( V_2 , V_8 , V_11 ) ;
return V_6 < 0 ? V_6 : V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_10 , V_13 ;
V_13 = V_5 -> V_14 ( V_2 , V_3 ) ;
if ( V_13 < 0 )
V_6 = V_13 ;
return V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
T_3 V_11 ;
V_6 = F_4 ( V_3 , 0 , & V_11 ) ;
if ( V_6 ) {
F_5 ( V_5 , L_3 ) ;
return V_6 ;
}
F_8 ( V_2 , V_11 ) ;
return V_10 ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_6 ;
if ( ! V_2 -> V_15 )
V_6 = - V_16 ;
else
V_6 = F_2 ( V_3 , V_9 , L_4 ,
( unsigned long long ) * ( V_2 -> V_15 ) ) ;
return V_6 ;
}
static T_1 F_10 ( struct V_1 * V_2 , char * V_3 )
{
int V_17 , V_18 ;
T_4 V_19 ;
T_1 V_6 ;
if ( ! V_2 -> V_15 ) {
V_6 = - V_16 ;
goto V_20;
}
V_19 = * ( V_2 -> V_15 ) ;
* V_3 = '\0' ;
for ( V_18 = V_17 = 0 ; V_19 && V_21 [ V_17 ] ; V_17 ++ ) {
if ( V_19 & 1 ) {
if ( V_18 && F_11 ( V_3 , L_5 , V_9 ) >= V_9 )
break;
if ( F_11 ( V_3 , V_21 [ V_17 ] , V_9 ) >=
V_9 )
break;
V_18 = 1 ;
}
V_19 >>= 1 ;
}
if ( V_18 )
F_11 ( V_3 , L_6 , V_9 ) ;
V_6 = strlen ( V_3 ) ;
V_20:
return V_6 ;
}
static T_1 F_12 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_3 , T_5 V_28 , T_2 V_10 )
{
int V_6 ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_29 ) ;
if ( ! V_30 || ! V_2 -> V_31 )
return - V_16 ;
V_6 = V_2 -> V_32 * sizeof( struct V_33 )
+ sizeof( V_34 ) ;
if ( V_28 > V_6 )
return - V_16 ;
if ( V_10 > V_6 - V_28 )
V_10 = V_6 - V_28 ;
if ( ! V_10 )
return V_10 ;
F_14 ( & V_2 -> V_35 ) ;
memcpy ( V_3 , V_2 -> V_31 , V_10 ) ;
F_15 ( & V_2 -> V_35 ) ;
return V_10 ;
}
static void F_16 ( struct V_24 * V_25 )
{
}
static T_1 F_17 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_3 , T_5 V_28 , T_2 V_10 )
{
int V_6 ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_29 ) ;
if ( ! V_30 || ! V_2 -> V_36 )
return - V_16 ;
V_6 = sizeof( struct V_37 ) ;
if ( V_28 > V_6 )
return - V_16 ;
if ( V_10 > V_6 - V_28 )
V_10 = V_6 - V_28 ;
if ( ! V_10 )
return V_10 ;
F_14 ( & V_2 -> V_35 ) ;
memcpy ( V_3 , V_2 -> V_36 , V_10 ) ;
F_15 ( & V_2 -> V_35 ) ;
return V_10 ;
}
static T_1 F_18 ( struct V_24 * V_25 ,
struct V_38 * V_39 , char * V_3 )
{
struct V_40 * V_41 =
F_13 ( V_39 , struct V_40 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_42 ) ;
return V_41 -> V_43 ( V_2 , V_3 ) ;
}
static T_1 F_19 ( struct V_24 * V_25 ,
struct V_38 * V_39 , const char * V_3 , T_2 V_44 )
{
struct V_40 * V_41 =
F_13 ( V_39 , struct V_40 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_42 ) ;
return V_41 -> V_45 ( V_2 , V_3 , V_44 ) ;
}
static T_1 F_20 ( struct V_24 * V_25 , struct V_38 * V_39 ,
char * V_3 )
{
struct V_46 * V_47 =
F_13 ( V_39 , struct V_46 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_48 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
return sprintf ( V_3 , L_7 , V_50 -> V_52 [ V_47 -> V_53 ] ) ;
}
static T_1 F_21 ( struct V_24 * V_25 , struct V_38 * V_39 ,
char * V_3 )
{
struct V_54 * V_55 =
F_13 ( V_39 , struct V_54 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_56 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
return sprintf ( V_3 , L_7 , * ( V_57 * ) ( ( char * ) V_50 + V_55 -> V_58 ) ) ;
}
static T_1 F_22 ( struct V_24 * V_25 , struct V_38 * V_39 ,
const char * V_3 , T_2 V_59 )
{
struct V_54 * V_55 =
F_13 ( V_39 , struct V_54 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_56 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
V_57 V_11 ;
int V_6 ;
V_6 = F_23 ( V_3 , 0 , & V_11 ) ;
if ( V_6 )
return V_6 ;
* ( V_57 * ) ( ( char * ) V_50 + V_55 -> V_58 ) = V_11 ;
return V_59 ;
}
static T_1 F_24 ( struct V_60 * V_60 , struct V_61 * V_39 ,
char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
return sprintf ( V_3 , L_8 , F_25 ( V_63 ) -> V_65 ) ;
}
static T_1 F_26 ( struct V_60 * V_60 , struct V_61 * V_39 ,
char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
int V_6 ;
if ( ! V_5 -> V_66 )
V_6 = - V_16 ;
else
V_6 = F_2 ( V_3 , V_9 , L_9 , V_5 -> V_66 ) ;
return V_6 ;
}
static T_1 F_27 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
return F_2 ( V_3 , V_9 , L_10 , ( char * ) V_67 ) ;
}
static T_1 F_28 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
return F_2 ( V_3 , V_9 , L_10 , V_5 -> V_68 ) ;
}
static T_1 F_29 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
return F_2 ( V_3 , V_9 , L_10 , V_5 -> V_69 ) ;
}
static T_1 F_30 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
return F_2 ( V_3 , V_9 , L_7 ,
( V_5 -> V_70 > V_5 -> V_71 ) ? 0 :
( V_5 -> V_71 - V_5 -> V_70 ) ) ;
}
static T_1 F_31 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
return F_2 ( V_3 , V_9 , L_7 , V_5 -> V_72 ) ;
}
static T_1 F_32 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
V_3 [ sizeof( V_5 -> V_73 ) ] = '\0' ;
memcpy ( V_3 , V_5 -> V_73 , sizeof( V_5 -> V_73 ) ) ;
strcat ( V_3 , L_6 ) ;
return strlen ( V_3 ) ;
}
static T_1 F_33 ( struct V_60 * V_60 ,
struct V_61 * V_39 , const char * V_3 ,
T_2 V_10 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
int V_6 ;
if ( V_10 < 5 || memcmp ( V_3 , L_11 , 5 ) || ! V_5 -> V_74 ) {
V_6 = - V_16 ;
goto V_20;
}
V_6 = F_34 ( V_5 -> V_75 ) ;
V_20:
return V_6 < 0 ? V_6 : V_10 ;
}
static T_1 F_35 ( struct V_60 * V_60 ,
struct V_61 * V_39 , char * V_3 )
{
struct V_62 * V_63 =
F_13 ( V_60 , struct V_62 , V_64 . V_63 ) ;
struct V_4 * V_5 = F_25 ( V_63 ) ;
int V_6 ;
int V_76 ;
T_6 V_77 [ 8 ] ;
V_6 = - V_78 ;
for ( V_76 = 0 ; V_76 < 8 ; ++ V_76 ) {
if ( V_76 == 6 )
continue;
V_6 = V_5 -> V_79 ( V_5 , V_76 ) ;
if ( V_6 < 0 )
break;
V_77 [ V_76 ] = V_6 ;
}
if ( V_76 == 8 )
V_6 = F_2 ( V_3 , V_9 , L_12 ,
* ( signed char * ) ( V_77 ) ,
* ( signed char * ) ( V_77 + 1 ) ,
V_77 [ 2 ] , V_77 [ 3 ] ,
* ( signed char * ) ( V_77 + 5 ) ,
* ( signed char * ) ( V_77 + 7 ) ) ;
return V_6 ;
}
int F_36 ( struct V_80 * V_64 , T_6 V_81 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = F_37 ( V_64 ) ;
int V_6 ;
if ( ! V_81 || V_81 > V_5 -> V_82 ) {
F_5 ( V_5 ,
L_13 ,
V_81 ) ;
V_6 = - V_83 ;
goto V_20;
}
V_2 = & V_5 -> V_84 [ V_81 - 1 ] ;
V_6 = F_38 ( & V_2 -> V_42 , & V_85 , V_25 ,
L_14 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_15 ,
V_6 , V_81 ) ;
goto V_20;
}
F_39 ( & V_2 -> V_42 , V_86 ) ;
V_6 = F_38 ( & V_2 -> V_48 , & V_87 , V_25 ,
L_16 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_17 ,
V_6 , V_81 ) ;
goto V_88;
}
F_39 ( & V_2 -> V_48 , V_86 ) ;
V_6 = F_38 ( & V_2 -> V_56 , & V_89 , V_25 ,
L_18 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_19 ,
V_6 , V_81 ) ;
goto V_90;
}
F_39 ( & V_2 -> V_56 , V_86 ) ;
if ( ! V_30 || ! V_2 -> V_36 )
return 0 ;
V_6 = F_38 ( & V_2 -> V_29 , & V_91 ,
V_25 , L_20 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_21 ,
V_6 , V_81 ) ;
goto V_92;
}
F_39 ( & V_2 -> V_29 , V_86 ) ;
V_6 = F_40 ( & V_2 -> V_29 ,
& V_93 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_22 ,
V_6 , V_81 ) ;
goto V_94;
}
V_6 = F_40 ( & V_2 -> V_29 ,
& V_95 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_23 ,
V_6 , V_81 ) ;
goto V_96;
}
F_41 ( V_5 -> V_97 ,
L_24 ,
V_5 -> V_75 , V_81 ) ;
return 0 ;
V_96:
F_42 ( & V_2 -> V_29 , & V_93 ) ;
V_94:
F_43 ( & V_2 -> V_29 ) ;
V_92:
F_43 ( & V_2 -> V_56 ) ;
V_90:
F_43 ( & V_2 -> V_48 ) ;
V_88:
F_43 ( & V_2 -> V_42 ) ;
V_20:
return V_6 ;
}
int F_44 ( struct V_4 * V_5 )
{
struct V_80 * V_63 = & V_5 -> V_98 . V_64 ;
int V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < F_45 ( V_99 ) ; ++ V_17 ) {
V_6 = F_46 ( & V_63 -> V_63 , V_99 [ V_17 ] ) ;
if ( V_6 )
goto V_20;
}
return 0 ;
V_20:
for ( V_17 = 0 ; V_17 < F_45 ( V_99 ) ; ++ V_17 )
F_47 ( & V_63 -> V_63 , V_99 [ V_17 ] ) ;
return V_6 ;
}
void F_48 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_82 ; V_17 ++ ) {
V_2 = & V_5 -> V_84 [ V_17 ] ;
if ( V_30 &&
V_2 -> V_36 ) {
F_42 ( & V_2 -> V_29 ,
& V_93 ) ;
F_42 ( & V_2 -> V_29 ,
& V_95 ) ;
F_43 ( & V_2 -> V_29 ) ;
}
F_43 ( & V_2 -> V_48 ) ;
F_43 ( & V_2 -> V_42 ) ;
}
}
