static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static inline int F_4 ( int V_1 )
{
if ( ! F_5 ( V_1 , 2 , V_3 ) ) {
F_6 ( L_1 , V_1 ) ;
return - V_4 ;
}
F_2 ( V_5 , V_1 ) ;
return 0 ;
}
static inline void F_7 ( int V_1 , int V_6 )
{
F_2 ( V_7 , V_1 ) ;
F_2 ( V_6 , V_1 + 1 ) ;
}
static inline void F_8 ( int V_1 )
{
F_2 ( V_8 , V_1 ) ;
F_9 ( V_1 , 2 ) ;
}
static int F_10 ( struct V_9 * V_10 , T_1 V_11 , T_2 V_2 , T_1 V_12 )
{
T_1 V_13 ;
int V_14 ;
const int V_15 = 64 ;
const int V_16 = 32 ;
V_13 = F_3 ( V_10 -> V_17 + 1 ) ;
F_2 ( V_13 , V_10 -> V_17 + 1 ) ;
F_2 ( 0x00 , V_10 -> V_17 + 2 ) ;
F_2 ( 0x80 , V_10 -> V_17 + 3 ) ;
F_2 ( V_11 , V_10 -> V_17 + 4 ) ;
F_2 ( 0x01 , V_10 -> V_17 + 5 ) ;
F_2 ( 0x04 , V_10 -> V_17 + 2 ) ;
if ( V_11 == V_18 )
F_2 ( V_12 , V_10 -> V_17 + 4 ) ;
F_2 ( V_2 & 0xff , V_10 -> V_17 + 6 ) ;
F_2 ( V_2 >> 8 , V_10 -> V_17 + 7 ) ;
F_2 ( 0x01 , V_10 -> V_17 ) ;
for ( V_14 = 0 ; V_14 < V_15 + V_16 ; V_14 ++ ) {
if ( V_14 >= V_15 )
F_11 ( 1 ) ;
V_13 = F_3 ( V_10 -> V_17 + 8 ) ;
if ( V_13 )
F_2 ( V_13 , V_10 -> V_17 + 8 ) ;
if ( V_13 & 0x01 )
break;
}
if ( V_14 == V_15 + V_16 ) {
F_6 ( L_2
L_3 , V_2 , 1 ) ;
return - V_19 ;
}
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 = F_3 ( V_10 -> V_17 + 1 ) ;
if ( V_13 == 0x01 )
break;
if ( V_14 == 0 )
F_12 ( L_4
L_5 , ( unsigned int ) V_13 , V_2 ) ;
}
if ( V_14 == V_15 ) {
F_6 ( L_2
L_3 , V_2 , 2 ) ;
return - V_19 ;
}
if ( V_11 == V_20 )
return F_3 ( V_10 -> V_17 + 4 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , T_2 V_2 )
{
return F_10 ( V_10 , V_20 , V_2 , 0 ) ;
}
static int F_14 ( struct V_9 * V_10 ,
T_2 V_2 , T_1 V_13 )
{
return F_10 ( V_10 , V_18 , V_2 , V_13 ) ;
}
static int F_15 ( struct V_9 * V_10 , T_2 V_2 )
{
int V_21 , V_22 ;
V_21 = F_13 ( V_10 , V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_22 = F_13 ( V_10 , V_2 + 1 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_21 | ( V_22 << 8 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_2 V_23 ,
T_2 V_24 , int V_25 )
{
int V_22 , V_26 ;
V_22 = F_13 ( V_10 , V_23 ) ;
if ( V_22 < 0 )
return V_22 ;
V_26 = F_13 ( V_10 , V_24 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_25 )
return ( V_22 << 4 ) | ( V_26 >> 4 ) ;
else
return ( V_22 << 4 ) | ( V_26 & 0x0f ) ;
}
static struct V_9 * F_17 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_18 ( V_28 ) ;
struct V_9 * V_29 = V_10 ;
int V_14 , V_13 ;
F_19 ( & V_10 -> V_30 ) ;
if ( F_20 ( V_31 , V_10 -> V_32 + 300 * V_33 ) ) {
F_14 ( V_10 , V_34 ,
V_10 -> V_35 | 0x10 ) ;
V_10 -> V_32 = V_31 ;
}
if ( F_20 ( V_31 , V_10 -> V_36 + V_33 ) || ! V_10 -> V_37 ) {
for ( V_14 = 0 ; V_14 < V_38 ; V_14 ++ ) {
V_13 = F_16 ( V_10 ,
V_39 [ V_14 ] ,
V_40 [ V_14 ] ,
V_41 [ V_14 ] ) ;
if ( F_21 ( V_13 < 0 ) ) {
V_29 = F_22 ( V_13 ) ;
goto abort;
}
V_10 -> V_42 [ V_14 ] = V_13 ;
}
for ( V_14 = 0 ; V_14 < V_43 ; V_14 ++ ) {
V_13 = F_15 ( V_10 ,
V_44 [ V_14 ] ) ;
if ( F_21 ( V_13 < 0 ) ) {
V_29 = F_22 ( V_13 ) ;
goto abort;
}
V_10 -> V_45 [ V_14 ] = V_13 ;
}
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ ) {
V_13 = F_16 ( V_10 ,
V_47 [ V_14 ] ,
V_48 [ V_14 ] ,
V_49 [ V_14 ] ) ;
if ( F_21 ( V_13 < 0 ) ) {
V_29 = F_22 ( V_13 ) ;
goto abort;
}
V_10 -> V_50 [ V_14 ] = V_13 ;
}
V_10 -> V_36 = V_31 ;
V_10 -> V_37 = 1 ;
}
abort:
F_23 ( & V_10 -> V_30 ) ;
return V_29 ;
}
static int T_3 F_24 ( struct V_9 * V_10 )
{
int V_14 , V_13 ;
for ( V_14 = 0 ; V_14 < V_38 ; V_14 ++ ) {
V_13 = F_13 ( V_10 , V_51 [ V_14 ] ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 -> V_52 [ V_14 ] = V_13 ;
V_13 = F_13 ( V_10 , V_53 [ V_14 ] ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 -> V_54 [ V_14 ] = V_13 ;
}
for ( V_14 = 0 ; V_14 < V_43 ; V_14 ++ ) {
V_13 = F_15 ( V_10 , V_55 [ V_14 ] ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 -> V_56 [ V_14 ] = V_13 ;
}
return 0 ;
}
static int F_25 ( T_2 V_2 )
{
return ( V_2 * 625 ) / 10 - 64000 ;
}
static int F_26 ( T_1 V_2 )
{
return ( V_2 - 64 ) * 1000 ;
}
static int F_27 ( T_2 V_2 )
{
if ( V_2 == 0 )
return - V_19 ;
if ( V_2 == 0xffff )
return 0 ;
return 5400540 / V_2 ;
}
static T_4 F_28 ( struct V_27 * V_28 , struct V_57 * V_58 ,
char * V_59 )
{
return snprintf ( V_59 , V_60 , L_6 , V_61 ) ;
}
static T_4 F_29 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_17 ( V_28 ) ;
int V_13 ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_13 = F_25 ( V_10 -> V_42 [ V_63 -> V_64 ] ) ;
return snprintf ( V_59 , V_60 , L_7 , V_13 ) ;
}
static T_4 F_33 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_17 ( V_28 ) ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
return snprintf ( V_59 , V_60 , L_7 , V_10 -> V_42 [ V_63 -> V_64 ] == 0 ) ;
}
static T_4 F_34 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_18 ( V_28 ) ;
int V_13 ;
V_13 = F_26 ( V_10 -> V_52 [ V_63 -> V_64 ] ) ;
return snprintf ( V_59 , V_60 , L_7 , V_13 ) ;
}
static T_4 F_35 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_18 ( V_28 ) ;
int V_13 ;
V_13 = F_26 ( V_10 -> V_54 [ V_63 -> V_64 ] ) ;
return snprintf ( V_59 , V_60 , L_7 , V_13 ) ;
}
static T_4 F_36 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_17 ( V_28 ) ;
int V_13 ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_13 = F_27 ( V_10 -> V_45 [ V_63 -> V_64 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return snprintf ( V_59 , V_60 , L_7 , V_13 ) ;
}
static T_4 F_37 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_17 ( V_28 ) ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
return snprintf ( V_59 , V_60 , L_7 ,
V_10 -> V_45 [ V_63 -> V_64 ] == 0xffff ) ;
}
static T_4 F_38 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_18 ( V_28 ) ;
int V_13 = F_27 ( V_10 -> V_56 [ V_63 -> V_64 ] ) ;
if ( V_13 < 0 )
return V_13 ;
return snprintf ( V_59 , V_60 , L_7 , V_13 ) ;
}
static T_4 F_39 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
struct V_9 * V_10 = F_17 ( V_28 ) ;
int V_13 ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_13 = F_40 (
V_10 -> V_50 [ V_63 -> V_64 ] * V_65 [ V_63 -> V_64 ] ,
10000 ) ;
return snprintf ( V_59 , V_60 , L_7 , V_13 ) ;
}
static T_4 F_41 ( struct V_27 * V_28 , struct V_57
* V_58 , char * V_59 )
{
struct V_62 * V_63 = F_30 ( V_58 ) ;
return snprintf ( V_59 , V_60 , L_6 ,
V_66 [ V_63 -> V_64 ] ) ;
}
static int F_42 ( struct V_67 * V_68 )
{
struct V_9 * V_10 = F_43 ( V_68 ) ;
if ( V_10 -> V_69 )
F_44 ( V_10 -> V_69 ) ;
F_45 ( & V_68 -> V_28 . V_70 , & V_71 ) ;
F_46 ( V_68 , NULL ) ;
F_47 ( V_10 ) ;
return 0 ;
}
static int T_3 F_48 ( struct V_67 * V_68 )
{
struct V_9 * V_10 ;
int V_72 , V_73 , V_74 , V_75 , V_13 ;
V_10 = F_49 ( sizeof( struct V_9 ) , V_76 ) ;
if ( ! V_10 )
return - V_77 ;
V_10 -> V_17 = F_50 ( V_68 , V_78 , 0 ) -> V_79 ;
F_51 ( & V_10 -> V_30 ) ;
F_46 ( V_68 , V_10 ) ;
V_13 = F_13 ( V_10 , V_80 ) ;
if ( V_13 < 0 ) {
V_72 = V_13 ;
goto error;
}
if ( V_13 != V_81 ) {
F_6 ( L_8 , L_9 ,
V_13 , V_81 ) ;
V_72 = - V_82 ;
goto error;
}
V_13 = F_13 ( V_10 , V_83 ) ;
if ( V_13 < 0 ) {
V_72 = V_13 ;
goto error;
}
if ( V_13 != V_84 ) {
F_6 ( L_8 , L_10 ,
V_13 , V_84 ) ;
V_72 = - V_82 ;
goto error;
}
V_13 = F_13 ( V_10 , V_85 ) ;
if ( V_13 < 0 ) {
V_72 = V_13 ;
goto error;
}
if ( V_13 != V_86 ) {
F_6 ( L_8 , L_11 ,
V_13 , V_86 ) ;
V_72 = - V_82 ;
goto error;
}
V_73 = F_13 ( V_10 , V_87 ) ;
if ( V_73 < 0 ) {
V_72 = V_73 ;
goto error;
}
V_74 = F_15 ( V_10 , V_88 ) ;
if ( V_74 < 0 ) {
V_72 = V_74 ;
goto error;
}
V_75 = F_13 ( V_10 , V_89 ) ;
if ( V_75 < 0 ) {
V_72 = V_75 ;
goto error;
}
V_13 = F_13 ( V_10 , V_34 ) ;
if ( V_13 < 0 ) {
V_72 = V_13 ;
goto error;
}
V_10 -> V_35 = V_13 ;
if ( ! ( V_10 -> V_35 & 0x01 ) ) {
F_6 ( L_12 ) ;
V_72 = - V_82 ;
goto error;
}
F_14 ( V_10 , V_34 ,
V_10 -> V_35 | 0x10 ) ;
V_10 -> V_32 = V_31 ;
V_72 = F_24 ( V_10 ) ;
if ( V_72 )
goto error;
F_52 ( L_13 ,
V_73 , V_74 , V_75 ) ;
V_72 = F_53 ( & V_68 -> V_28 . V_70 , & V_71 ) ;
if ( V_72 )
goto error;
V_10 -> V_69 = F_54 ( & V_68 -> V_28 ) ;
if ( F_31 ( V_10 -> V_69 ) ) {
V_72 = F_32 ( V_10 -> V_69 ) ;
V_10 -> V_69 = NULL ;
goto error;
}
return 0 ;
error:
F_42 ( V_68 ) ;
return V_72 ;
}
static int T_5 F_55 ( int V_90 , unsigned short * V_91 )
{
T_1 V_92 ;
int V_72 = F_4 ( V_90 ) ;
if ( V_72 )
return V_72 ;
V_92 = F_1 ( V_90 , V_93 ) ;
if ( V_92 != V_94 ) {
F_56 ( L_14 ,
( unsigned int ) V_92 ) ;
V_72 = - V_82 ;
goto exit;
}
F_7 ( V_90 , V_95 ) ;
if ( ! ( F_1 ( V_90 , V_96 ) & 0x01 ) ) {
F_12 ( L_15 ) ;
V_72 = - V_82 ;
goto exit;
}
* V_91 = F_1 ( V_90 , V_97 ) |
F_1 ( V_90 , V_97 + 1 ) << 8 ;
if ( * V_91 == 0 ) {
F_12 ( L_16 ) ;
V_72 = - V_82 ;
goto exit;
}
F_52 ( L_17 , V_61 , * V_91 ) ;
exit:
F_8 ( V_90 ) ;
return V_72 ;
}
static int T_5 F_57 ( unsigned short V_91 )
{
struct V_98 V_99 = {
. V_79 = V_91 ,
. V_100 = V_91 + V_101 - 1 ,
. V_102 = V_78 ,
} ;
int V_72 ;
V_103 = F_58 ( V_3 , V_91 ) ;
if ( ! V_103 )
return - V_77 ;
V_99 . V_104 = V_103 -> V_104 ;
V_72 = F_59 ( & V_99 ) ;
if ( V_72 )
goto V_105;
V_72 = F_60 ( V_103 , & V_99 , 1 ) ;
if ( V_72 ) {
F_6 ( L_18 ) ;
goto V_105;
}
V_72 = F_61 ( V_103 ) ;
if ( V_72 ) {
F_6 ( L_19 ) ;
goto V_105;
}
return 0 ;
V_105:
F_62 ( V_103 ) ;
return V_72 ;
}
static int T_5 F_63 ( void )
{
int V_72 = - V_82 ;
unsigned short V_91 ;
if ( F_55 ( 0x4e , & V_91 ) && F_55 ( 0x2e , & V_91 ) )
goto exit;
V_72 = F_64 ( & V_106 ) ;
if ( V_72 )
goto exit;
V_72 = F_57 ( V_91 ) ;
if ( V_72 )
goto V_107;
return 0 ;
V_107:
F_65 ( & V_106 ) ;
exit:
return V_72 ;
}
static void T_6 F_66 ( void )
{
F_67 ( V_103 ) ;
F_65 ( & V_106 ) ;
}
