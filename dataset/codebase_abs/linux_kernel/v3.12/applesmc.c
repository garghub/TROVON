static int F_1 ( void )
{
T_1 V_1 ;
int V_2 ;
for ( V_2 = V_3 ; V_2 < V_4 ; V_2 <<= 1 ) {
F_2 ( V_2 ) ;
V_1 = F_3 ( V_5 ) ;
if ( V_1 & 0x01 )
return 0 ;
}
F_4 ( L_1 , V_1 ) ;
return - V_6 ;
}
static int F_5 ( T_1 V_7 , T_2 V_8 )
{
T_1 V_1 ;
int V_2 ;
F_6 ( V_7 , V_8 ) ;
for ( V_2 = V_3 ; V_2 < V_4 ; V_2 <<= 1 ) {
F_2 ( V_2 ) ;
V_1 = F_3 ( V_5 ) ;
if ( V_1 & 0x02 )
continue;
if ( V_1 & 0x04 )
return 0 ;
if ( V_2 << 1 == V_4 )
break;
F_2 ( V_9 ) ;
F_6 ( V_7 , V_8 ) ;
}
F_4 ( L_2 , V_7 , V_8 , V_1 ) ;
return - V_6 ;
}
static int F_7 ( T_1 V_7 )
{
return F_5 ( V_7 , V_5 ) ;
}
static int F_8 ( const char * V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ )
if ( F_5 ( V_10 [ V_11 ] , V_12 ) )
return - V_6 ;
return 0 ;
}
static int F_9 ( T_1 V_7 , const char * V_10 , T_1 * V_13 , T_1 V_14 )
{
T_1 V_1 , V_15 = 0 ;
int V_11 ;
if ( F_7 ( V_7 ) || F_8 ( V_10 ) ) {
F_4 ( L_3 , V_10 ) ;
return - V_6 ;
}
if ( F_5 ( V_14 , V_12 ) ) {
F_4 ( L_4 , V_10 ) ;
return - V_6 ;
}
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
if ( F_1 () ) {
F_4 ( L_5 , V_10 , V_11 ) ;
return - V_6 ;
}
V_13 [ V_11 ] = F_3 ( V_12 ) ;
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
F_2 ( V_3 ) ;
V_1 = F_3 ( V_5 ) ;
if ( ! ( V_1 & 0x01 ) )
break;
V_15 = F_3 ( V_12 ) ;
}
if ( V_11 )
F_4 ( L_6 , V_11 , V_15 ) ;
return 0 ;
}
static int F_10 ( T_1 V_7 , const char * V_10 , const T_1 * V_13 , T_1 V_14 )
{
int V_11 ;
if ( F_7 ( V_7 ) || F_8 ( V_10 ) ) {
F_4 ( L_7 , V_10 ) ;
return - V_6 ;
}
if ( F_5 ( V_14 , V_12 ) ) {
F_4 ( L_8 , V_10 ) ;
return - V_6 ;
}
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
if ( F_5 ( V_13 [ V_11 ] , V_12 ) ) {
F_4 ( L_9 , V_10 ) ;
return - V_6 ;
}
}
return 0 ;
}
static int F_11 ( unsigned int * V_16 )
{
T_3 V_17 ;
int V_18 ;
V_18 = F_9 ( V_19 , V_20 , ( T_1 * ) & V_17 , 4 ) ;
if ( V_18 )
return V_18 ;
* V_16 = F_12 ( V_17 ) ;
return 0 ;
}
static int F_13 ( const struct V_21 * V_22 ,
T_1 * V_23 , T_1 V_14 )
{
int V_18 ;
if ( V_22 -> V_14 != V_14 )
return - V_24 ;
F_14 ( & V_25 . V_26 ) ;
V_18 = F_9 ( V_19 , V_22 -> V_10 , V_23 , V_14 ) ;
F_15 ( & V_25 . V_26 ) ;
return V_18 ;
}
static int F_16 ( const struct V_21 * V_22 ,
const T_1 * V_23 , T_1 V_14 )
{
int V_18 ;
if ( V_22 -> V_14 != V_14 )
return - V_24 ;
F_14 ( & V_25 . V_26 ) ;
V_18 = F_10 ( V_27 , V_22 -> V_10 , V_23 , V_14 ) ;
F_15 ( & V_25 . V_26 ) ;
return V_18 ;
}
static const struct V_21 * F_17 ( int V_28 )
{
struct V_21 * V_29 = & V_25 . V_29 [ V_28 ] ;
T_1 V_10 [ 4 ] , V_30 [ 6 ] ;
T_3 V_17 ;
int V_18 = 0 ;
if ( V_29 -> V_31 )
return V_29 ;
F_14 ( & V_25 . V_26 ) ;
if ( V_29 -> V_31 )
goto V_32;
V_17 = F_18 ( V_28 ) ;
V_18 = F_9 ( V_33 , ( T_1 * ) & V_17 , V_10 , 4 ) ;
if ( V_18 )
goto V_32;
V_18 = F_9 ( V_34 , V_10 , V_30 , 6 ) ;
if ( V_18 )
goto V_32;
memcpy ( V_29 -> V_10 , V_10 , 4 ) ;
V_29 -> V_14 = V_30 [ 0 ] ;
memcpy ( V_29 -> type , & V_30 [ 1 ] , 4 ) ;
V_29 -> V_35 = V_30 [ 5 ] ;
V_29 -> V_31 = 1 ;
V_32:
F_15 ( & V_25 . V_26 ) ;
if ( V_18 )
return F_19 ( V_18 ) ;
return V_29 ;
}
static int F_20 ( unsigned int * V_36 , const char * V_10 )
{
int V_37 = 0 , V_38 = V_25 . V_39 ;
const struct V_21 * V_22 ;
while ( V_37 != V_38 ) {
int V_40 = V_37 + ( V_38 - V_37 ) / 2 ;
V_22 = F_17 ( V_40 ) ;
if ( F_21 ( V_22 ) ) {
* V_36 = 0 ;
return F_22 ( V_22 ) ;
}
if ( strcmp ( V_22 -> V_10 , V_10 ) < 0 )
V_37 = V_40 + 1 ;
else
V_38 = V_40 ;
}
* V_36 = V_37 ;
return 0 ;
}
static int F_23 ( unsigned int * V_41 , const char * V_10 )
{
int V_37 = 0 , V_38 = V_25 . V_39 ;
const struct V_21 * V_22 ;
while ( V_37 != V_38 ) {
int V_40 = V_37 + ( V_38 - V_37 ) / 2 ;
V_22 = F_17 ( V_40 ) ;
if ( F_21 ( V_22 ) ) {
* V_41 = V_25 . V_39 ;
return F_22 ( V_22 ) ;
}
if ( strcmp ( V_10 , V_22 -> V_10 ) < 0 )
V_38 = V_40 ;
else
V_37 = V_40 + 1 ;
}
* V_41 = V_37 ;
return 0 ;
}
static const struct V_21 * F_24 ( const char * V_10 )
{
int V_37 , V_38 ;
int V_18 ;
V_18 = F_20 ( & V_37 , V_10 ) ;
if ( V_18 )
return F_19 ( V_18 ) ;
V_18 = F_23 ( & V_38 , V_10 ) ;
if ( V_18 )
return F_19 ( V_18 ) ;
if ( V_38 - V_37 != 1 )
return F_19 ( - V_24 ) ;
return F_17 ( V_37 ) ;
}
static int F_25 ( const char * V_10 , T_1 * V_13 , T_1 V_14 )
{
const struct V_21 * V_22 ;
V_22 = F_24 ( V_10 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
return F_13 ( V_22 , V_13 , V_14 ) ;
}
static int F_26 ( const char * V_10 , const T_1 * V_13 , T_1 V_14 )
{
const struct V_21 * V_22 ;
V_22 = F_24 ( V_10 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
return F_16 ( V_22 , V_13 , V_14 ) ;
}
static int F_27 ( const char * V_10 , bool * V_42 )
{
const struct V_21 * V_22 ;
V_22 = F_24 ( V_10 ) ;
if ( F_21 ( V_22 ) && F_22 ( V_22 ) != - V_24 )
return F_22 ( V_22 ) ;
* V_42 = ! F_21 ( V_22 ) ;
return 0 ;
}
static int F_28 ( const char * V_10 , T_4 * V_42 )
{
T_1 V_13 [ 2 ] ;
int V_18 ;
V_18 = F_25 ( V_10 , V_13 , 2 ) ;
if ( V_18 )
return V_18 ;
* V_42 = ( ( T_4 ) V_13 [ 0 ] << 8 ) | V_13 [ 1 ] ;
return 0 ;
}
static void F_29 ( void )
{
int V_43 ;
T_1 V_13 [ 2 ] ;
if ( ! V_25 . V_44 )
return;
for ( V_43 = V_45 ; V_43 > 0 ; V_43 -= V_46 ) {
if ( ! F_25 ( V_47 , V_13 , 2 ) &&
( V_13 [ 0 ] != 0x00 || V_13 [ 1 ] != 0x00 ) )
return;
V_13 [ 0 ] = 0xe0 ;
V_13 [ 1 ] = 0x00 ;
F_26 ( V_47 , V_13 , 2 ) ;
F_30 ( V_46 ) ;
}
F_4 ( L_10 ) ;
}
static int F_31 ( struct V_48 * V_49 )
{
const struct V_21 * V_22 ;
unsigned int V_11 ;
if ( V_49 -> V_28 )
return 0 ;
V_49 -> V_28 = F_32 ( V_49 -> V_50 , sizeof( V_49 -> V_28 [ 0 ] ) , V_51 ) ;
if ( ! V_49 -> V_28 )
return - V_52 ;
for ( V_11 = V_49 -> V_53 ; V_11 < V_49 -> V_54 ; V_11 ++ ) {
V_22 = F_17 ( V_11 ) ;
if ( F_21 ( V_22 ) )
continue;
if ( strcmp ( V_22 -> type , V_55 ) )
continue;
V_49 -> V_28 [ V_49 -> V_56 ++ ] = V_22 -> V_10 ;
}
return 0 ;
}
static int F_33 ( void )
{
struct V_48 * V_49 = & V_25 ;
bool V_57 , V_58 ;
unsigned int V_16 ;
T_1 V_59 [ 1 ] ;
int V_18 ;
if ( V_49 -> V_60 )
return 0 ;
V_18 = F_11 ( & V_16 ) ;
if ( V_18 )
return V_18 ;
if ( V_49 -> V_29 && V_49 -> V_39 != V_16 ) {
F_4 ( L_11 ,
V_49 -> V_39 , V_16 ) ;
F_34 ( V_49 -> V_29 ) ;
V_49 -> V_29 = NULL ;
}
V_49 -> V_39 = V_16 ;
if ( ! V_49 -> V_29 )
V_49 -> V_29 = F_32 ( V_49 -> V_39 , sizeof( * V_49 -> V_29 ) , V_51 ) ;
if ( ! V_49 -> V_29 )
return - V_52 ;
V_18 = F_25 ( V_61 , V_59 , 1 ) ;
if ( V_18 )
return V_18 ;
V_49 -> V_62 = V_59 [ 0 ] ;
V_18 = F_20 ( & V_49 -> V_53 , L_12 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_20 ( & V_49 -> V_54 , L_13 ) ;
if ( V_18 )
return V_18 ;
V_49 -> V_50 = V_49 -> V_54 - V_49 -> V_53 ;
V_18 = F_31 ( V_49 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_27 ( V_63 , & V_57 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_27 ( V_64 , & V_58 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_27 ( V_47 , & V_49 -> V_44 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_27 ( V_65 , & V_49 -> V_66 ) ;
if ( V_18 )
return V_18 ;
V_49 -> V_67 = V_57 + V_58 ;
V_49 -> V_60 = true ;
F_35 ( L_14 ,
V_49 -> V_39 , V_49 -> V_62 , V_49 -> V_50 , V_49 -> V_56 ,
V_49 -> V_44 ,
V_49 -> V_67 ,
V_49 -> V_66 ) ;
return 0 ;
}
static void F_36 ( void )
{
F_34 ( V_25 . V_28 ) ;
V_25 . V_28 = NULL ;
F_34 ( V_25 . V_29 ) ;
V_25 . V_29 = NULL ;
V_25 . V_60 = false ;
}
static int F_37 ( void )
{
int V_68 , V_18 ;
for ( V_68 = 0 ; V_68 < V_45 ; V_68 += V_46 ) {
V_18 = F_33 () ;
if ( ! V_18 ) {
if ( V_68 )
F_35 ( L_15 , V_68 ) ;
return 0 ;
}
F_30 ( V_46 ) ;
}
F_36 () ;
return V_18 ;
}
static int F_38 ( struct V_69 * V_70 )
{
int V_18 ;
V_18 = F_37 () ;
if ( V_18 )
return V_18 ;
F_29 () ;
return 0 ;
}
static int F_39 ( struct V_71 * V_70 )
{
if ( V_25 . V_66 )
F_26 ( V_65 , V_72 , 2 ) ;
return 0 ;
}
static int F_40 ( struct V_71 * V_70 )
{
F_29 () ;
return F_39 ( V_70 ) ;
}
static void F_41 ( void )
{
F_28 ( V_73 , & V_74 ) ;
F_28 ( V_75 , & V_76 ) ;
V_74 = - V_74 ;
}
static void F_42 ( struct V_77 * V_70 )
{
struct V_78 * V_79 = V_70 -> V_80 ;
T_4 V_81 , V_82 ;
if ( F_28 ( V_73 , & V_81 ) )
return;
if ( F_28 ( V_75 , & V_82 ) )
return;
V_81 = - V_81 ;
F_43 ( V_79 , V_83 , V_81 - V_74 ) ;
F_43 ( V_79 , V_84 , V_82 - V_76 ) ;
F_44 ( V_79 ) ;
}
static T_5 F_45 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_23 )
{
return snprintf ( V_23 , V_87 , L_16 ) ;
}
static T_5 F_46 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_23 )
{
int V_18 ;
T_4 V_81 , V_82 , V_88 ;
V_18 = F_28 ( V_73 , & V_81 ) ;
if ( V_18 )
goto V_32;
V_18 = F_28 ( V_75 , & V_82 ) ;
if ( V_18 )
goto V_32;
V_18 = F_28 ( V_89 , & V_88 ) ;
if ( V_18 )
goto V_32;
V_32:
if ( V_18 )
return V_18 ;
else
return snprintf ( V_23 , V_87 , L_17 , V_81 , V_82 , V_88 ) ;
}
static T_5 F_47 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
const struct V_21 * V_22 ;
static int V_91 ;
int V_18 ;
T_1 V_92 = 0 , V_93 = 0 ;
T_1 V_13 [ 10 ] ;
if ( ! V_91 ) {
V_22 = F_24 ( V_63 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
if ( V_22 -> V_14 > 10 )
return - V_94 ;
V_91 = V_22 -> V_14 ;
F_35 ( L_18 , V_91 ) ;
}
V_18 = F_25 ( V_63 , V_13 , V_91 ) ;
if ( V_91 == 10 ) {
V_92 = F_48 ( * ( V_95 * ) ( V_13 + 6 ) ) >> 2 ;
goto V_32;
}
V_92 = V_13 [ 2 ] ;
if ( V_18 )
goto V_32;
V_18 = F_25 ( V_64 , V_13 , V_91 ) ;
V_93 = V_13 [ 2 ] ;
V_32:
if ( V_18 )
return V_18 ;
else
return snprintf ( V_90 , V_87 , L_19 , V_92 , V_93 ) ;
}
static T_5 F_49 ( struct V_71 * V_70 ,
struct V_85 * V_96 , char * V_90 )
{
const char * V_10 = V_25 . V_28 [ F_50 ( V_96 ) ] ;
return snprintf ( V_90 , V_87 , L_20 , V_10 ) ;
}
static T_5 F_51 ( struct V_71 * V_70 ,
struct V_85 * V_96 , char * V_90 )
{
const char * V_10 = V_25 . V_28 [ F_50 ( V_96 ) ] ;
int V_18 ;
T_4 V_42 ;
int V_97 ;
V_18 = F_28 ( V_10 , & V_42 ) ;
if ( V_18 )
return V_18 ;
V_97 = 250 * ( V_42 >> 6 ) ;
return snprintf ( V_90 , V_87 , L_21 , V_97 ) ;
}
static T_5 F_52 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
int V_18 ;
unsigned int V_98 = 0 ;
char V_99 [ 5 ] ;
T_1 V_13 [ 2 ] ;
sprintf ( V_99 , V_100 [ F_53 ( V_86 ) ] , F_50 ( V_86 ) ) ;
V_18 = F_25 ( V_99 , V_13 , 2 ) ;
V_98 = ( ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) >> 2 ) ;
if ( V_18 )
return V_18 ;
else
return snprintf ( V_90 , V_87 , L_22 , V_98 ) ;
}
static T_5 F_54 ( struct V_71 * V_70 ,
struct V_85 * V_86 ,
const char * V_90 , T_6 V_16 )
{
int V_18 ;
unsigned long V_98 ;
char V_99 [ 5 ] ;
T_1 V_13 [ 2 ] ;
if ( F_55 ( V_90 , 10 , & V_98 ) < 0 || V_98 >= 0x4000 )
return - V_24 ;
sprintf ( V_99 , V_100 [ F_53 ( V_86 ) ] , F_50 ( V_86 ) ) ;
V_13 [ 0 ] = ( V_98 >> 6 ) & 0xff ;
V_13 [ 1 ] = ( V_98 << 2 ) & 0xff ;
V_18 = F_26 ( V_99 , V_13 , 2 ) ;
if ( V_18 )
return V_18 ;
else
return V_16 ;
}
static T_5 F_56 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
int V_18 ;
T_2 V_101 = 0 ;
T_1 V_13 [ 2 ] ;
V_18 = F_25 ( V_102 , V_13 , 2 ) ;
V_101 = ( ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) >> F_50 ( V_86 ) ) & 0x01 ;
if ( V_18 )
return V_18 ;
else
return snprintf ( V_90 , V_87 , L_21 , V_101 ) ;
}
static T_5 F_57 ( struct V_71 * V_70 ,
struct V_85 * V_86 ,
const char * V_90 , T_6 V_16 )
{
int V_18 ;
T_1 V_13 [ 2 ] ;
unsigned long V_80 ;
T_2 V_103 ;
if ( F_55 ( V_90 , 10 , & V_80 ) < 0 )
return - V_24 ;
V_18 = F_25 ( V_102 , V_13 , 2 ) ;
V_103 = ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) ;
if ( V_18 )
goto V_32;
if ( V_80 )
V_103 = V_103 | ( 0x01 << F_50 ( V_86 ) ) ;
else
V_103 = V_103 & ~ ( 0x01 << F_50 ( V_86 ) ) ;
V_13 [ 0 ] = ( V_103 >> 8 ) & 0xFF ;
V_13 [ 1 ] = V_103 & 0xFF ;
V_18 = F_26 ( V_102 , V_13 , 2 ) ;
V_32:
if ( V_18 )
return V_18 ;
else
return V_16 ;
}
static T_5 F_58 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
int V_18 ;
char V_99 [ 5 ] ;
T_1 V_13 [ 17 ] ;
sprintf ( V_99 , V_104 , F_50 ( V_86 ) ) ;
V_18 = F_25 ( V_99 , V_13 , 16 ) ;
V_13 [ 16 ] = 0 ;
if ( V_18 )
return V_18 ;
else
return snprintf ( V_90 , V_87 , L_20 , V_13 + 4 ) ;
}
static T_5 F_59 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
return snprintf ( V_90 , V_87 , L_19 , V_74 , V_76 ) ;
}
static T_5 F_60 ( struct V_71 * V_70 ,
struct V_85 * V_86 , const char * V_90 , T_6 V_16 )
{
F_41 () ;
return V_16 ;
}
static void F_61 ( struct V_105 * V_106 )
{
F_26 ( V_65 , V_72 , 2 ) ;
}
static void F_62 ( struct V_107 * V_108 ,
enum V_109 V_42 )
{
int V_18 ;
V_72 [ 0 ] = V_42 ;
V_18 = F_63 ( V_110 , & V_111 ) ;
if ( V_112 && ( ! V_18 ) )
F_64 ( V_108 -> V_70 , L_23 ) ;
}
static T_5 F_65 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
int V_18 ;
T_1 V_13 [ 4 ] ;
T_7 V_16 ;
V_18 = F_25 ( V_20 , V_13 , 4 ) ;
V_16 = ( ( T_7 ) V_13 [ 0 ] << 24 ) + ( ( T_7 ) V_13 [ 1 ] << 16 ) +
( ( T_7 ) V_13 [ 2 ] << 8 ) + V_13 [ 3 ] ;
if ( V_18 )
return V_18 ;
else
return snprintf ( V_90 , V_87 , L_21 , V_16 ) ;
}
static T_5 F_66 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
const struct V_21 * V_22 ;
int V_18 ;
V_22 = F_17 ( V_113 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
V_18 = F_13 ( V_22 , V_90 , V_22 -> V_14 ) ;
if ( V_18 )
return V_18 ;
return V_22 -> V_14 ;
}
static T_5 F_67 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
const struct V_21 * V_22 ;
V_22 = F_17 ( V_113 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
return snprintf ( V_90 , V_87 , L_21 , V_22 -> V_14 ) ;
}
static T_5 F_68 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
const struct V_21 * V_22 ;
V_22 = F_17 ( V_113 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
return snprintf ( V_90 , V_87 , L_20 , V_22 -> type ) ;
}
static T_5 F_69 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
const struct V_21 * V_22 ;
V_22 = F_17 ( V_113 ) ;
if ( F_21 ( V_22 ) )
return F_22 ( V_22 ) ;
return snprintf ( V_90 , V_87 , L_20 , V_22 -> V_10 ) ;
}
static T_5 F_70 ( struct V_71 * V_70 ,
struct V_85 * V_86 , char * V_90 )
{
return snprintf ( V_90 , V_87 , L_21 , V_113 ) ;
}
static T_5 F_71 ( struct V_71 * V_70 ,
struct V_85 * V_86 , const char * V_90 , T_6 V_16 )
{
unsigned long V_99 ;
if ( F_55 ( V_90 , 10 , & V_99 ) < 0
|| V_99 >= V_25 . V_39 )
return - V_24 ;
V_113 = V_99 ;
return V_16 ;
}
static void F_72 ( struct V_114 * V_115 )
{
struct V_114 * V_116 ;
struct V_117 * V_118 ;
for ( V_116 = V_115 ; V_116 -> V_119 ; V_116 ++ ) {
for ( V_118 = V_116 -> V_119 ; V_118 -> V_120 . V_121 . V_86 . V_122 ; V_118 ++ )
F_73 ( & V_123 -> V_70 . V_124 ,
& V_118 -> V_120 . V_121 . V_86 ) ;
F_34 ( V_116 -> V_119 ) ;
V_116 -> V_119 = NULL ;
}
}
static int F_74 ( struct V_114 * V_115 , int V_125 )
{
struct V_114 * V_116 ;
struct V_117 * V_118 ;
struct V_126 * V_86 ;
int V_18 , V_11 ;
for ( V_116 = V_115 ; V_116 -> V_127 ; V_116 ++ ) {
V_116 -> V_119 = F_32 ( V_125 + 1 , sizeof( * V_118 ) , V_51 ) ;
if ( ! V_116 -> V_119 ) {
V_18 = - V_52 ;
goto V_32;
}
for ( V_11 = 0 ; V_11 < V_125 ; V_11 ++ ) {
V_118 = & V_116 -> V_119 [ V_11 ] ;
sprintf ( V_118 -> V_122 , V_116 -> V_127 , V_11 + 1 ) ;
V_118 -> V_120 . V_28 = ( V_116 -> V_128 << 16 ) | ( V_11 & 0xffff ) ;
V_118 -> V_120 . V_121 . V_129 = V_116 -> V_129 ;
V_118 -> V_120 . V_121 . V_130 = V_116 -> V_130 ;
V_86 = & V_118 -> V_120 . V_121 . V_86 ;
F_75 ( V_86 ) ;
V_86 -> V_122 = V_118 -> V_122 ;
V_86 -> V_131 = V_132 | ( V_116 -> V_130 ? V_133 : 0 ) ;
V_18 = F_76 ( & V_123 -> V_70 . V_124 , V_86 ) ;
if ( V_18 ) {
V_86 -> V_122 = NULL ;
goto V_32;
}
}
}
return 0 ;
V_32:
F_72 ( V_115 ) ;
return V_18 ;
}
static int F_77 ( void )
{
struct V_78 * V_79 ;
int V_18 ;
if ( ! V_25 . V_44 )
return 0 ;
V_18 = F_74 ( V_134 , 1 ) ;
if ( V_18 )
goto V_32;
V_135 = F_78 () ;
if ( ! V_135 ) {
V_18 = - V_52 ;
goto V_136;
}
V_135 -> V_137 = F_42 ;
V_135 -> V_138 = V_139 ;
F_41 () ;
V_79 = V_135 -> V_80 ;
V_79 -> V_122 = L_24 ;
V_79 -> V_140 . V_141 = V_142 ;
V_79 -> V_70 . V_143 = & V_123 -> V_70 ;
V_79 -> V_144 [ 0 ] = F_79 ( V_145 ) ;
F_80 ( V_79 , V_83 ,
- 256 , 256 , V_146 , V_147 ) ;
F_80 ( V_79 , V_84 ,
- 256 , 256 , V_146 , V_147 ) ;
V_18 = F_81 ( V_135 ) ;
if ( V_18 )
goto V_148;
return 0 ;
V_148:
F_82 ( V_135 ) ;
V_136:
F_72 ( V_134 ) ;
V_32:
F_4 ( L_25 , V_18 ) ;
return V_18 ;
}
static void F_83 ( void )
{
if ( ! V_25 . V_44 )
return;
F_84 ( V_135 ) ;
F_82 ( V_135 ) ;
F_72 ( V_134 ) ;
}
static int F_85 ( void )
{
if ( ! V_25 . V_67 )
return 0 ;
return F_74 ( V_149 , 1 ) ;
}
static void F_86 ( void )
{
if ( ! V_25 . V_67 )
return;
F_72 ( V_149 ) ;
}
static int F_87 ( void )
{
if ( ! V_25 . V_66 )
return 0 ;
V_110 = F_88 ( L_26 ) ;
if ( ! V_110 )
return - V_52 ;
return F_89 ( & V_123 -> V_70 , & V_150 ) ;
}
static void F_90 ( void )
{
if ( ! V_25 . V_66 )
return;
F_91 ( & V_150 ) ;
F_92 ( V_110 ) ;
}
static int F_93 ( const struct V_151 * V_140 )
{
return 1 ;
}
static int T_8 F_94 ( void )
{
int V_18 ;
if ( ! F_95 ( V_152 ) ) {
F_4 ( L_27 ) ;
V_18 = - V_153 ;
goto V_32;
}
if ( ! F_96 ( V_12 , V_154 ,
L_24 ) ) {
V_18 = - V_94 ;
goto V_32;
}
V_18 = F_97 ( & V_155 ) ;
if ( V_18 )
goto V_156;
V_123 = F_98 ( L_24 , V_12 ,
NULL , 0 ) ;
if ( F_21 ( V_123 ) ) {
V_18 = F_22 ( V_123 ) ;
goto V_157;
}
V_18 = F_37 () ;
if ( V_18 )
goto V_158;
V_18 = F_74 ( V_159 , 1 ) ;
if ( V_18 )
goto V_160;
V_18 = F_74 ( V_161 , V_25 . V_62 ) ;
if ( V_18 )
goto V_162;
V_18 = F_74 ( V_163 , V_25 . V_56 ) ;
if ( V_18 )
goto V_164;
V_18 = F_77 () ;
if ( V_18 )
goto V_165;
V_18 = F_85 () ;
if ( V_18 )
goto V_166;
V_18 = F_87 () ;
if ( V_18 )
goto V_167;
V_168 = F_99 ( & V_123 -> V_70 ) ;
if ( F_21 ( V_168 ) ) {
V_18 = F_22 ( V_168 ) ;
goto V_169;
}
return 0 ;
V_169:
F_90 () ;
V_167:
F_86 () ;
V_166:
F_83 () ;
V_165:
F_72 ( V_163 ) ;
V_164:
F_72 ( V_161 ) ;
V_162:
F_72 ( V_159 ) ;
V_160:
F_36 () ;
V_158:
F_100 ( V_123 ) ;
V_157:
F_101 ( & V_155 ) ;
V_156:
F_102 ( V_12 , V_154 ) ;
V_32:
F_4 ( L_25 , V_18 ) ;
return V_18 ;
}
static void T_9 F_103 ( void )
{
F_104 ( V_168 ) ;
F_90 () ;
F_86 () ;
F_83 () ;
F_72 ( V_163 ) ;
F_72 ( V_161 ) ;
F_72 ( V_159 ) ;
F_36 () ;
F_100 ( V_123 ) ;
F_101 ( & V_155 ) ;
F_102 ( V_12 , V_154 ) ;
}
