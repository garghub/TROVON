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
static T_4 F_21 ( T_4 T_6 * V_54 )
{
int V_55 ;
T_4 V_56 = 0 ;
F_22 (cpu)
V_56 += * F_23 ( V_54 , V_55 ) ;
return V_56 ;
}
static T_1 F_24 ( struct V_24 * V_25 , struct V_38 * V_39 ,
char * V_3 )
{
struct V_57 * V_58 =
F_13 ( V_39 , struct V_57 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_59 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
if ( ! strncmp ( V_58 -> V_39 . V_60 , L_8 , 7 ) )
return sprintf ( V_3 , L_9 , F_25 ( V_61 ) ) ;
else if ( ! strncmp ( V_58 -> V_39 . V_60 , L_10 , 8 ) )
return sprintf ( V_3 , L_9 , F_25 ( V_62 ) ) ;
else if ( ! strncmp ( V_58 -> V_39 . V_60 , L_11 , 15 ) )
return sprintf ( V_3 , L_9 ,
F_25 ( V_63 ) ) ;
else
return sprintf ( V_3 , L_7 ,
* ( V_64 * ) ( ( char * ) V_50 + V_58 -> V_56 ) ) ;
}
static T_1 F_26 ( struct V_24 * V_25 , struct V_38 * V_39 ,
const char * V_3 , T_2 V_65 )
{
struct V_57 * V_58 =
F_13 ( V_39 , struct V_57 , V_39 ) ;
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_59 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
V_64 V_11 ;
int V_6 ;
V_6 = F_27 ( V_3 , 0 , & V_11 ) ;
if ( V_6 )
return V_6 ;
if ( ! strncmp ( V_58 -> V_39 . V_60 , L_8 , 7 ) )
F_28 ( V_2 , V_11 ) ;
else if ( ! strncmp ( V_58 -> V_39 . V_60 , L_10 , 8 ) )
F_29 ( V_2 , V_11 ) ;
else if ( ! strncmp ( V_58 -> V_39 . V_60 , L_11 , 15 ) )
F_30 ( V_2 , V_11 ) ;
else
* ( V_64 * ) ( ( char * ) V_50 + V_58 -> V_56 ) = V_11 ;
return V_65 ;
}
static T_1 F_31 ( struct V_66 * V_66 , struct V_67 * V_39 ,
char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
return sprintf ( V_3 , L_12 , F_32 ( V_69 ) -> V_72 ) ;
}
static T_1 F_33 ( struct V_66 * V_66 , struct V_67 * V_39 ,
char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
int V_6 ;
if ( ! V_5 -> V_73 )
V_6 = - V_16 ;
else
V_6 = F_2 ( V_3 , V_9 , L_13 , V_5 -> V_73 ) ;
return V_6 ;
}
static T_1 F_34 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
return F_2 ( V_3 , V_9 , L_14 , ( char * ) V_74 ) ;
}
static T_1 F_35 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
return F_2 ( V_3 , V_9 , L_14 , V_5 -> V_75 ) ;
}
static T_1 F_36 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
return F_2 ( V_3 , V_9 , L_14 , V_5 -> V_76 ) ;
}
static T_1 F_37 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
return F_2 ( V_3 , V_9 , L_7 ,
( V_5 -> V_77 > V_5 -> V_78 ) ? 0 :
( V_5 -> V_78 - V_5 -> V_77 ) ) ;
}
static T_1 F_38 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
return F_2 ( V_3 , V_9 , L_7 , V_5 -> V_79 ) ;
}
static T_1 F_39 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
V_3 [ sizeof( V_5 -> V_80 ) ] = '\0' ;
memcpy ( V_3 , V_5 -> V_80 , sizeof( V_5 -> V_80 ) ) ;
strcat ( V_3 , L_6 ) ;
return strlen ( V_3 ) ;
}
static T_1 F_40 ( struct V_66 * V_66 ,
struct V_67 * V_39 , const char * V_3 ,
T_2 V_10 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
int V_6 ;
if ( V_10 < 5 || memcmp ( V_3 , L_15 , 5 ) || ! V_5 -> V_81 ) {
V_6 = - V_16 ;
goto V_20;
}
V_6 = F_41 ( V_5 -> V_82 ) ;
V_20:
return V_6 < 0 ? V_6 : V_10 ;
}
static T_1 F_42 ( struct V_66 * V_66 ,
struct V_67 * V_39 , char * V_3 )
{
struct V_68 * V_69 =
F_13 ( V_66 , struct V_68 , V_70 . V_71 . V_69 ) ;
struct V_4 * V_5 = F_32 ( V_69 ) ;
int V_6 ;
int V_83 ;
T_7 V_84 [ 8 ] ;
V_6 = - V_85 ;
for ( V_83 = 0 ; V_83 < 8 ; ++ V_83 ) {
if ( V_83 == 6 )
continue;
V_6 = V_5 -> V_86 ( V_5 , V_83 ) ;
if ( V_6 < 0 )
break;
V_84 [ V_83 ] = V_6 ;
}
if ( V_83 == 8 )
V_6 = F_2 ( V_3 , V_9 , L_16 ,
* ( signed char * ) ( V_84 ) ,
* ( signed char * ) ( V_84 + 1 ) ,
V_84 [ 2 ] , V_84 [ 3 ] ,
* ( signed char * ) ( V_84 + 5 ) ,
* ( signed char * ) ( V_84 + 7 ) ) ;
return V_6 ;
}
int F_43 ( struct V_87 * V_71 , T_7 V_88 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = F_44 ( V_71 ) ;
int V_6 ;
if ( ! V_88 || V_88 > V_5 -> V_89 ) {
F_5 ( V_5 ,
L_17 ,
V_88 ) ;
V_6 = - V_90 ;
goto V_20;
}
V_2 = & V_5 -> V_91 [ V_88 - 1 ] ;
V_6 = F_45 ( & V_2 -> V_42 , & V_92 , V_25 ,
L_18 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_19 ,
V_6 , V_88 ) ;
goto V_20;
}
F_46 ( & V_2 -> V_42 , V_93 ) ;
V_6 = F_45 ( & V_2 -> V_48 , & V_94 , V_25 ,
L_20 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_21 ,
V_6 , V_88 ) ;
goto V_95;
}
F_46 ( & V_2 -> V_48 , V_93 ) ;
V_6 = F_45 ( & V_2 -> V_59 , & V_96 , V_25 ,
L_22 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_23 ,
V_6 , V_88 ) ;
goto V_97;
}
F_46 ( & V_2 -> V_59 , V_93 ) ;
if ( ! V_30 || ! V_2 -> V_36 )
return 0 ;
V_6 = F_45 ( & V_2 -> V_29 , & V_98 ,
V_25 , L_24 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_25 ,
V_6 , V_88 ) ;
goto V_99;
}
F_46 ( & V_2 -> V_29 , V_93 ) ;
V_6 = F_47 ( & V_2 -> V_29 ,
& V_100 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_26 ,
V_6 , V_88 ) ;
goto V_101;
}
V_6 = F_47 ( & V_2 -> V_29 ,
& V_102 ) ;
if ( V_6 ) {
F_5 ( V_5 ,
L_27 ,
V_6 , V_88 ) ;
goto V_103;
}
F_48 ( V_5 -> V_104 ,
L_28 ,
V_5 -> V_82 , V_88 ) ;
return 0 ;
V_103:
F_49 ( & V_2 -> V_29 , & V_100 ) ;
V_101:
F_50 ( & V_2 -> V_29 ) ;
V_99:
F_50 ( & V_2 -> V_59 ) ;
V_97:
F_50 ( & V_2 -> V_48 ) ;
V_95:
F_50 ( & V_2 -> V_42 ) ;
V_20:
return V_6 ;
}
int F_51 ( struct V_4 * V_5 )
{
struct V_87 * V_69 = & V_5 -> V_105 . V_70 . V_71 ;
int V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < F_52 ( V_106 ) ; ++ V_17 ) {
V_6 = F_53 ( & V_69 -> V_69 , V_106 [ V_17 ] ) ;
if ( V_6 )
goto V_20;
}
return 0 ;
V_20:
for ( V_17 = 0 ; V_17 < F_52 ( V_106 ) ; ++ V_17 )
F_54 ( & V_69 -> V_69 , V_106 [ V_17 ] ) ;
return V_6 ;
}
void F_55 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_89 ; V_17 ++ ) {
V_2 = & V_5 -> V_91 [ V_17 ] ;
if ( V_30 &&
V_2 -> V_36 ) {
F_49 ( & V_2 -> V_29 ,
& V_100 ) ;
F_49 ( & V_2 -> V_29 ,
& V_102 ) ;
F_50 ( & V_2 -> V_29 ) ;
}
F_50 ( & V_2 -> V_48 ) ;
F_50 ( & V_2 -> V_42 ) ;
}
}
