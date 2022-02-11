static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static inline int F_4 ( int V_1 )
{
if ( ! F_5 ( V_1 , 2 , L_1 ) ) {
F_6 ( L_2 , V_1 ) ;
return - V_3 ;
}
F_2 ( V_4 , V_1 ) ;
return 0 ;
}
static inline void F_7 ( int V_1 , int V_5 )
{
F_2 ( V_6 , V_1 ) ;
F_2 ( V_5 , V_1 + 1 ) ;
}
static inline void F_8 ( int V_1 )
{
F_2 ( V_7 , V_1 ) ;
F_9 ( V_1 , 2 ) ;
}
static int F_10 ( T_1 V_8 , T_2 V_9 , T_1 V_2 , T_2 V_10 )
{
T_2 V_11 ;
int V_12 ;
const int V_13 = 64 ;
const int V_14 = 32 ;
V_11 = F_3 ( V_8 + 1 ) ;
F_2 ( V_11 , V_8 + 1 ) ;
F_2 ( 0x00 , V_8 + 2 ) ;
F_2 ( 0x80 , V_8 + 3 ) ;
F_2 ( V_9 , V_8 + 4 ) ;
F_2 ( 0x01 , V_8 + 5 ) ;
F_2 ( 0x04 , V_8 + 2 ) ;
if ( V_9 == V_15 )
F_2 ( V_10 , V_8 + 4 ) ;
F_2 ( V_2 & 0xff , V_8 + 6 ) ;
F_2 ( V_2 >> 8 , V_8 + 7 ) ;
F_2 ( 0x01 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_13 + V_14 ; V_12 ++ ) {
if ( V_12 >= V_13 )
F_11 ( 1 ) ;
V_11 = F_3 ( V_8 + 8 ) ;
if ( V_11 )
F_2 ( V_11 , V_8 + 8 ) ;
if ( V_11 & 0x01 )
break;
}
if ( V_12 == V_13 + V_14 ) {
F_6 ( L_3
L_4 , V_2 , 1 ) ;
return - V_16 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = F_3 ( V_8 + 1 ) ;
if ( V_11 == 0x01 )
break;
if ( V_12 == 0 )
F_12 ( L_5
L_6 , ( unsigned int ) V_11 , V_2 ) ;
}
if ( V_12 == V_13 ) {
F_6 ( L_3
L_4 , V_2 , 2 ) ;
return - V_16 ;
}
if ( V_9 == V_17 )
return F_3 ( V_8 + 4 ) ;
return 0 ;
}
int F_13 ( T_1 V_8 , T_1 V_2 )
{
return F_10 ( V_8 , V_17 , V_2 , 0 ) ;
}
int F_14 ( T_1 V_8 , T_1 V_2 , T_2 V_11 )
{
return F_10 ( V_8 , V_15 , V_2 , V_11 ) ;
}
int F_15 ( T_1 V_8 , T_1 V_2 )
{
int V_18 , V_19 ;
V_18 = F_13 ( V_8 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = F_13 ( V_8 , V_2 + 1 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_18 | ( V_19 << 8 ) ;
}
int F_16 ( T_1 V_8 , T_1 V_20 , T_1 V_21 ,
int V_22 )
{
int V_19 , V_23 ;
V_19 = F_13 ( V_8 , V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_23 = F_13 ( V_8 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_22 )
return ( V_19 << 4 ) | ( V_23 >> 4 ) ;
else
return ( V_19 << 4 ) | ( V_23 & 0x0f ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 =
F_18 ( V_25 , struct V_26 , V_24 ) ;
F_19 ( V_27 ) ;
}
static int F_20 ( struct V_26 * V_27 ,
int V_28 )
{
int V_29 , V_30 ;
T_2 V_31 ;
if ( V_28 <= 255 )
V_30 = 1 ;
else
V_30 = 60 ;
if ( V_28 < V_30 || V_28 > ( V_30 * 255 ) )
return - V_32 ;
F_21 ( & V_27 -> V_33 ) ;
if ( ! V_27 -> V_8 ) {
V_29 = - V_34 ;
goto V_35;
}
if ( V_30 == 1 )
V_31 = V_27 -> V_36 | V_37 ;
else
V_31 = V_27 -> V_36 & ~ V_37 ;
if ( V_27 -> V_36 != V_31 ) {
F_21 ( V_27 -> V_38 ) ;
V_29 = F_14 ( V_27 -> V_8 ,
V_39 ,
V_31 ) ;
F_22 ( V_27 -> V_38 ) ;
if ( V_29 )
goto V_35;
V_27 -> V_36 = V_31 ;
}
V_27 -> V_40 = F_23 ( V_28 , V_30 ) ;
V_29 = V_27 -> V_40 * V_30 ;
V_35:
F_22 ( & V_27 -> V_33 ) ;
return V_29 ;
}
static int F_24 ( struct V_26 * V_27 )
{
int V_28 ;
F_21 ( & V_27 -> V_33 ) ;
if ( V_27 -> V_36 & V_37 )
V_28 = V_27 -> V_40 ;
else
V_28 = V_27 -> V_40 * 60 ;
F_22 ( & V_27 -> V_33 ) ;
return V_28 ;
}
static int F_25 ( struct V_26 * V_27 )
{
int V_29 ;
T_2 V_11 ;
F_21 ( & V_27 -> V_33 ) ;
if ( ! V_27 -> V_8 ) {
V_29 = - V_34 ;
goto V_41;
}
F_21 ( V_27 -> V_38 ) ;
V_29 = F_14 ( V_27 -> V_8 , V_42 ,
V_27 -> V_40 ) ;
if ( V_29 )
goto V_35;
if ( ! ( V_27 -> V_43 & V_44 ) ) {
V_11 = V_27 -> V_43 |
V_44 ;
V_29 = F_14 ( V_27 -> V_8 ,
V_45 ,
V_11 ) ;
if ( V_29 )
goto V_35;
V_27 -> V_43 = V_11 ;
}
V_11 = F_3 ( V_27 -> V_8 + 9 ) ;
if ( V_11 & 0x01 )
F_2 ( 0x01 , V_27 -> V_8 + 9 ) ;
V_35:
F_22 ( V_27 -> V_38 ) ;
V_41:
F_22 ( & V_27 -> V_33 ) ;
return V_29 ;
}
static int F_26 ( struct V_26 * V_27 )
{
int V_29 ;
F_21 ( & V_27 -> V_33 ) ;
if ( ! V_27 -> V_8 ) {
V_29 = - V_34 ;
goto V_35;
}
F_21 ( V_27 -> V_38 ) ;
V_29 = F_14 ( V_27 -> V_8 , V_42 ,
V_27 -> V_40 ) ;
F_22 ( V_27 -> V_38 ) ;
V_35:
F_22 ( & V_27 -> V_33 ) ;
return V_29 ;
}
static int F_27 ( struct V_26 * V_27 )
{
int V_29 = 0 ;
T_2 V_11 ;
if ( ! V_27 -> V_8 )
return - V_34 ;
if ( V_27 -> V_43 & V_44 ) {
V_11 = V_27 -> V_43 &
~ V_44 ;
F_21 ( V_27 -> V_38 ) ;
V_29 = F_14 ( V_27 -> V_8 ,
V_45 ,
V_11 ) ;
F_22 ( V_27 -> V_38 ) ;
if ( V_29 )
return V_29 ;
V_27 -> V_43 = V_11 ;
}
return V_29 ;
}
static int F_28 ( struct V_26 * V_27 )
{
int V_29 ;
F_21 ( & V_27 -> V_33 ) ;
V_29 = F_27 ( V_27 ) ;
F_22 ( & V_27 -> V_33 ) ;
return V_29 ;
}
static int F_29 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_26 * V_27 = V_48 -> V_49 ;
if ( V_27 -> V_50 ) {
F_28 ( V_27 ) ;
V_27 -> V_50 = 0 ;
} else {
F_26 ( V_27 ) ;
F_30 ( L_7 ) ;
}
F_31 ( 0 , & V_27 -> V_51 ) ;
F_21 ( & V_52 ) ;
F_32 ( & V_27 -> V_24 , F_17 ) ;
F_22 ( & V_52 ) ;
return 0 ;
}
static int F_33 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
struct V_26 * V_53 , * V_27 = NULL ;
int V_29 , V_51 ;
if ( ! F_34 ( & V_52 ) )
return - V_54 ;
F_35 (pos, &watchdog_data_list, list) {
if ( V_53 -> V_55 . V_56 == F_36 ( V_46 ) ) {
V_27 = V_53 ;
break;
}
}
V_51 = F_37 ( 0 , & V_27 -> V_51 ) ;
if ( ! V_51 )
F_38 ( & V_27 -> V_24 ) ;
F_22 ( & V_52 ) ;
if ( V_51 )
return - V_3 ;
V_48 -> V_49 = V_27 ;
V_29 = F_25 ( V_27 ) ;
if ( V_29 ) {
F_29 ( V_46 , V_48 ) ;
return V_29 ;
}
return F_39 ( V_46 , V_48 ) ;
}
static T_3 F_40 ( struct V_47 * V_48 , const char T_4 * V_57 ,
T_5 V_58 , T_6 * V_59 )
{
int V_29 ;
struct V_26 * V_27 = V_48 -> V_49 ;
if ( V_58 ) {
if ( ! V_60 ) {
T_5 V_12 ;
V_27 -> V_50 = 0 ;
for ( V_12 = 0 ; V_12 != V_58 ; V_12 ++ ) {
char V_61 ;
if ( F_41 ( V_61 , V_57 + V_12 ) )
return - V_62 ;
if ( V_61 == 'V' )
V_27 -> V_50 = 1 ;
}
}
V_29 = F_26 ( V_27 ) ;
if ( V_29 )
return V_29 ;
}
return V_58 ;
}
static long F_42 ( struct V_47 * V_48 , unsigned int V_9 ,
unsigned long V_63 )
{
struct V_64 V_65 = {
. V_66 = V_67 | V_68 ,
. V_69 = L_8
} ;
int V_12 , V_29 = 0 ;
struct V_26 * V_27 = V_48 -> V_49 ;
switch ( V_9 ) {
case V_70 :
V_65 . V_71 = V_27 -> V_72 ;
if ( ! V_60 )
V_65 . V_66 |= V_73 ;
if ( F_43 ( ( void T_4 * ) V_63 , & V_65 , sizeof( V_65 ) ) )
V_29 = - V_62 ;
break;
case V_74 :
case V_75 :
V_29 = F_44 ( 0 , ( int T_4 * ) V_63 ) ;
break;
case V_76 :
V_29 = F_26 ( V_27 ) ;
break;
case V_77 :
V_12 = F_24 ( V_27 ) ;
V_29 = F_44 ( V_12 , ( int T_4 * ) V_63 ) ;
break;
case V_78 :
if ( F_41 ( V_12 , ( int T_4 * ) V_63 ) ) {
V_29 = - V_62 ;
break;
}
V_29 = F_20 ( V_27 , V_12 ) ;
if ( V_29 >= 0 )
V_29 = F_44 ( V_29 , ( int T_4 * ) V_63 ) ;
break;
case V_79 :
if ( F_41 ( V_12 , ( int T_4 * ) V_63 ) ) {
V_29 = - V_62 ;
break;
}
if ( V_12 & V_80 )
V_29 = F_28 ( V_27 ) ;
else if ( V_12 & V_81 )
V_29 = F_26 ( V_27 ) ;
else
V_29 = - V_32 ;
break;
default:
V_29 = - V_82 ;
}
return V_29 ;
}
struct V_26 * F_45 (
T_1 V_8 , T_7 V_72 , struct V_83 * V_38 , int V_84 )
{
struct V_26 * V_27 ;
int V_12 , V_85 , V_31 , V_86 ;
const int V_87 [] = { V_88 , 212 , 213 , 214 , 215 } ;
F_21 ( V_38 ) ;
V_31 =
F_13 ( V_8 , V_39 ) ;
V_86 =
F_13 ( V_8 , V_45 ) ;
F_22 ( V_38 ) ;
if ( V_31 < 0 )
return NULL ;
if ( V_86 < 0 )
return NULL ;
if ( V_84 && ! ( V_86 & V_44 ) ) {
F_12 ( L_9 ) ;
return NULL ;
}
V_27 = F_46 ( sizeof( struct V_26 ) , V_89 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_8 = V_8 ;
V_27 -> V_72 = V_72 ;
V_27 -> V_38 = V_38 ;
V_27 -> V_36 = V_31 ;
V_27 -> V_43 = V_86 ;
F_47 ( & V_27 -> V_33 ) ;
F_48 ( & V_27 -> V_90 ) ;
F_49 ( & V_27 -> V_24 ) ;
V_85 = F_20 ( V_27 , 60 ) ;
if ( V_85 < 0 )
goto error;
F_21 ( & V_52 ) ;
for ( V_12 = 0 ; V_12 < F_50 ( V_87 ) ; V_12 ++ ) {
snprintf ( V_27 -> V_91 , sizeof( V_27 -> V_91 ) ,
L_10 , ( V_12 == 0 ) ? '\0' : ( '0' + V_12 ) ) ;
V_27 -> V_55 . V_92 = V_27 -> V_91 ;
V_27 -> V_55 . V_93 = & V_94 ;
V_27 -> V_55 . V_56 = V_87 [ V_12 ] ;
V_85 = F_51 ( & V_27 -> V_55 ) ;
if ( V_85 == - V_3 )
continue;
if ( V_85 )
break;
F_52 ( & V_27 -> V_90 , & V_95 ) ;
F_53 ( L_11 ,
V_27 -> V_91 , V_87 [ V_12 ] ) ;
break;
}
F_22 ( & V_52 ) ;
if ( V_85 ) {
F_6 ( L_12 , V_85 ) ;
goto error;
}
if ( V_12 == F_50 ( V_87 ) ) {
F_12 ( L_13 ) ;
goto error;
}
return V_27 ;
error:
F_19 ( V_27 ) ;
return NULL ;
}
void F_54 ( struct V_26 * V_27 )
{
F_21 ( & V_52 ) ;
F_55 ( & V_27 -> V_55 ) ;
F_56 ( & V_27 -> V_90 ) ;
F_22 ( & V_52 ) ;
F_21 ( & V_27 -> V_33 ) ;
if ( V_27 -> V_51 ) {
F_12 ( L_14
L_15 ) ;
F_27 ( V_27 ) ;
}
V_27 -> V_8 = 0 ;
V_27 -> V_38 = NULL ;
F_22 ( & V_27 -> V_33 ) ;
F_21 ( & V_52 ) ;
F_32 ( & V_27 -> V_24 , F_17 ) ;
F_22 ( & V_52 ) ;
}
static int T_8 F_57 ( int V_96 , unsigned short * V_97 ,
const char * * V_92 )
{
T_2 V_98 ;
int V_85 ;
V_85 = F_4 ( V_96 ) ;
if ( V_85 )
return V_85 ;
V_98 = F_1 ( V_96 , V_99 ) ;
switch ( V_98 ) {
case V_100 :
* V_92 = L_16 ;
break;
case V_101 :
* V_92 = L_17 ;
break;
default:
F_58 ( L_18 ,
( unsigned int ) V_98 ) ;
V_85 = - V_34 ;
goto exit;
}
F_7 ( V_96 , V_102 ) ;
if ( ! ( F_1 ( V_96 , V_103 ) & 0x01 ) ) {
F_12 ( L_19 ) ;
V_85 = - V_34 ;
goto exit;
}
* V_97 = F_1 ( V_96 , V_104 ) |
F_1 ( V_96 , V_104 + 1 ) << 8 ;
if ( * V_97 == 0 ) {
F_12 ( L_20 ) ;
V_85 = - V_34 ;
goto exit;
}
exit:
F_8 ( V_96 ) ;
return V_85 ;
}
static int T_8 F_59 ( unsigned short V_97 , const char * V_92 )
{
struct V_105 V_106 = {
. V_107 = V_97 ,
. V_108 = V_97 + V_109 - 1 ,
. V_110 = V_111 ,
} ;
int V_85 ;
V_112 = F_60 ( V_92 , V_97 ) ;
if ( ! V_112 )
return - V_113 ;
V_106 . V_92 = V_112 -> V_92 ;
V_85 = F_61 ( & V_106 ) ;
if ( V_85 )
goto V_114;
V_85 = F_62 ( V_112 , & V_106 , 1 ) ;
if ( V_85 ) {
F_6 ( L_21 ) ;
goto V_114;
}
V_85 = F_63 ( V_112 ) ;
if ( V_85 ) {
F_6 ( L_22 ) ;
goto V_114;
}
return 0 ;
V_114:
F_64 ( V_112 ) ;
return V_85 ;
}
static int T_8 F_65 ( void )
{
int V_85 ;
unsigned short V_97 ;
const char * V_92 ;
V_85 = F_57 ( 0x4e , & V_97 , & V_92 ) ;
if ( V_85 )
V_85 = F_57 ( 0x2e , & V_97 , & V_92 ) ;
if ( V_85 )
return V_85 ;
return F_59 ( V_97 , V_92 ) ;
}
static void T_9 F_66 ( void )
{
F_67 ( V_112 ) ;
}
