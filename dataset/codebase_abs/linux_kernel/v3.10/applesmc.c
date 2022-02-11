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
return 0 ;
}
static int F_10 ( T_1 V_7 , const char * V_10 , const T_1 * V_13 , T_1 V_14 )
{
int V_11 ;
if ( F_7 ( V_7 ) || F_8 ( V_10 ) ) {
F_4 ( L_6 , V_10 ) ;
return - V_6 ;
}
if ( F_5 ( V_14 , V_12 ) ) {
F_4 ( L_7 , V_10 ) ;
return - V_6 ;
}
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
if ( F_5 ( V_13 [ V_11 ] , V_12 ) ) {
F_4 ( L_8 , V_10 ) ;
return - V_6 ;
}
}
return 0 ;
}
static int F_11 ( unsigned int * V_15 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_9 ( V_18 , V_19 , ( T_1 * ) & V_16 , 4 ) ;
if ( V_17 )
return V_17 ;
* V_15 = F_12 ( V_16 ) ;
return 0 ;
}
static int F_13 ( const struct V_20 * V_21 ,
T_1 * V_22 , T_1 V_14 )
{
int V_17 ;
if ( V_21 -> V_14 != V_14 )
return - V_23 ;
F_14 ( & V_24 . V_25 ) ;
V_17 = F_9 ( V_18 , V_21 -> V_10 , V_22 , V_14 ) ;
F_15 ( & V_24 . V_25 ) ;
return V_17 ;
}
static int F_16 ( const struct V_20 * V_21 ,
const T_1 * V_22 , T_1 V_14 )
{
int V_17 ;
if ( V_21 -> V_14 != V_14 )
return - V_23 ;
F_14 ( & V_24 . V_25 ) ;
V_17 = F_10 ( V_26 , V_21 -> V_10 , V_22 , V_14 ) ;
F_15 ( & V_24 . V_25 ) ;
return V_17 ;
}
static const struct V_20 * F_17 ( int V_27 )
{
struct V_20 * V_28 = & V_24 . V_28 [ V_27 ] ;
T_1 V_10 [ 4 ] , V_29 [ 6 ] ;
T_3 V_16 ;
int V_17 = 0 ;
if ( V_28 -> V_30 )
return V_28 ;
F_14 ( & V_24 . V_25 ) ;
if ( V_28 -> V_30 )
goto V_31;
V_16 = F_18 ( V_27 ) ;
V_17 = F_9 ( V_32 , ( T_1 * ) & V_16 , V_10 , 4 ) ;
if ( V_17 )
goto V_31;
V_17 = F_9 ( V_33 , V_10 , V_29 , 6 ) ;
if ( V_17 )
goto V_31;
memcpy ( V_28 -> V_10 , V_10 , 4 ) ;
V_28 -> V_14 = V_29 [ 0 ] ;
memcpy ( V_28 -> type , & V_29 [ 1 ] , 4 ) ;
V_28 -> V_34 = V_29 [ 5 ] ;
V_28 -> V_30 = 1 ;
V_31:
F_15 ( & V_24 . V_25 ) ;
if ( V_17 )
return F_19 ( V_17 ) ;
return V_28 ;
}
static int F_20 ( unsigned int * V_35 , const char * V_10 )
{
int V_36 = 0 , V_37 = V_24 . V_38 ;
const struct V_20 * V_21 ;
while ( V_36 != V_37 ) {
int V_39 = V_36 + ( V_37 - V_36 ) / 2 ;
V_21 = F_17 ( V_39 ) ;
if ( F_21 ( V_21 ) ) {
* V_35 = 0 ;
return F_22 ( V_21 ) ;
}
if ( strcmp ( V_21 -> V_10 , V_10 ) < 0 )
V_36 = V_39 + 1 ;
else
V_37 = V_39 ;
}
* V_35 = V_36 ;
return 0 ;
}
static int F_23 ( unsigned int * V_40 , const char * V_10 )
{
int V_36 = 0 , V_37 = V_24 . V_38 ;
const struct V_20 * V_21 ;
while ( V_36 != V_37 ) {
int V_39 = V_36 + ( V_37 - V_36 ) / 2 ;
V_21 = F_17 ( V_39 ) ;
if ( F_21 ( V_21 ) ) {
* V_40 = V_24 . V_38 ;
return F_22 ( V_21 ) ;
}
if ( strcmp ( V_10 , V_21 -> V_10 ) < 0 )
V_37 = V_39 ;
else
V_36 = V_39 + 1 ;
}
* V_40 = V_36 ;
return 0 ;
}
static const struct V_20 * F_24 ( const char * V_10 )
{
int V_36 , V_37 ;
int V_17 ;
V_17 = F_20 ( & V_36 , V_10 ) ;
if ( V_17 )
return F_19 ( V_17 ) ;
V_17 = F_23 ( & V_37 , V_10 ) ;
if ( V_17 )
return F_19 ( V_17 ) ;
if ( V_37 - V_36 != 1 )
return F_19 ( - V_23 ) ;
return F_17 ( V_36 ) ;
}
static int F_25 ( const char * V_10 , T_1 * V_13 , T_1 V_14 )
{
const struct V_20 * V_21 ;
V_21 = F_24 ( V_10 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
return F_13 ( V_21 , V_13 , V_14 ) ;
}
static int F_26 ( const char * V_10 , const T_1 * V_13 , T_1 V_14 )
{
const struct V_20 * V_21 ;
V_21 = F_24 ( V_10 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
return F_16 ( V_21 , V_13 , V_14 ) ;
}
static int F_27 ( const char * V_10 , bool * V_41 )
{
const struct V_20 * V_21 ;
V_21 = F_24 ( V_10 ) ;
if ( F_21 ( V_21 ) && F_22 ( V_21 ) != - V_23 )
return F_22 ( V_21 ) ;
* V_41 = ! F_21 ( V_21 ) ;
return 0 ;
}
static int F_28 ( const char * V_10 , T_4 * V_41 )
{
T_1 V_13 [ 2 ] ;
int V_17 ;
V_17 = F_25 ( V_10 , V_13 , 2 ) ;
if ( V_17 )
return V_17 ;
* V_41 = ( ( T_4 ) V_13 [ 0 ] << 8 ) | V_13 [ 1 ] ;
return 0 ;
}
static void F_29 ( void )
{
int V_42 ;
T_1 V_13 [ 2 ] ;
if ( ! V_24 . V_43 )
return;
for ( V_42 = V_44 ; V_42 > 0 ; V_42 -= V_45 ) {
if ( ! F_25 ( V_46 , V_13 , 2 ) &&
( V_13 [ 0 ] != 0x00 || V_13 [ 1 ] != 0x00 ) )
return;
V_13 [ 0 ] = 0xe0 ;
V_13 [ 1 ] = 0x00 ;
F_26 ( V_46 , V_13 , 2 ) ;
F_30 ( V_45 ) ;
}
F_4 ( L_9 ) ;
}
static int F_31 ( struct V_47 * V_48 )
{
const struct V_20 * V_21 ;
unsigned int V_11 ;
if ( V_48 -> V_27 )
return 0 ;
V_48 -> V_27 = F_32 ( V_48 -> V_49 , sizeof( V_48 -> V_27 [ 0 ] ) , V_50 ) ;
if ( ! V_48 -> V_27 )
return - V_51 ;
for ( V_11 = V_48 -> V_52 ; V_11 < V_48 -> V_53 ; V_11 ++ ) {
V_21 = F_17 ( V_11 ) ;
if ( F_21 ( V_21 ) )
continue;
if ( strcmp ( V_21 -> type , V_54 ) )
continue;
V_48 -> V_27 [ V_48 -> V_55 ++ ] = V_21 -> V_10 ;
}
return 0 ;
}
static int F_33 ( void )
{
struct V_47 * V_48 = & V_24 ;
bool V_56 , V_57 ;
T_1 V_58 [ 1 ] ;
int V_17 ;
if ( V_48 -> V_59 )
return 0 ;
V_17 = F_11 ( & V_48 -> V_38 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_48 -> V_28 )
V_48 -> V_28 = F_32 ( V_48 -> V_38 , sizeof( * V_48 -> V_28 ) , V_50 ) ;
if ( ! V_48 -> V_28 )
return - V_51 ;
V_17 = F_25 ( V_60 , V_58 , 1 ) ;
if ( V_17 )
return V_17 ;
V_48 -> V_61 = V_58 [ 0 ] ;
V_17 = F_20 ( & V_48 -> V_52 , L_10 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_20 ( & V_48 -> V_53 , L_11 ) ;
if ( V_17 )
return V_17 ;
V_48 -> V_49 = V_48 -> V_53 - V_48 -> V_52 ;
V_17 = F_31 ( V_48 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_27 ( V_62 , & V_56 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_27 ( V_63 , & V_57 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_27 ( V_46 , & V_48 -> V_43 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_27 ( V_64 , & V_48 -> V_65 ) ;
if ( V_17 )
return V_17 ;
V_48 -> V_66 = V_56 + V_57 ;
V_48 -> V_59 = true ;
F_34 ( L_12 ,
V_48 -> V_38 , V_48 -> V_61 , V_48 -> V_49 , V_48 -> V_55 ,
V_48 -> V_43 ,
V_48 -> V_66 ,
V_48 -> V_65 ) ;
return 0 ;
}
static void F_35 ( void )
{
F_36 ( V_24 . V_27 ) ;
V_24 . V_27 = NULL ;
F_36 ( V_24 . V_28 ) ;
V_24 . V_28 = NULL ;
V_24 . V_59 = false ;
}
static int F_37 ( void )
{
int V_67 , V_17 ;
for ( V_67 = 0 ; V_67 < V_44 ; V_67 += V_45 ) {
V_17 = F_33 () ;
if ( ! V_17 ) {
if ( V_67 )
F_34 ( L_13 , V_67 ) ;
return 0 ;
}
F_30 ( V_45 ) ;
}
F_35 () ;
return V_17 ;
}
static int F_38 ( struct V_68 * V_69 )
{
int V_17 ;
V_17 = F_37 () ;
if ( V_17 )
return V_17 ;
F_29 () ;
return 0 ;
}
static int F_39 ( struct V_70 * V_69 )
{
if ( V_24 . V_65 )
F_26 ( V_64 , V_71 , 2 ) ;
return 0 ;
}
static int F_40 ( struct V_70 * V_69 )
{
F_29 () ;
return F_39 ( V_69 ) ;
}
static void F_41 ( void )
{
F_28 ( V_72 , & V_73 ) ;
F_28 ( V_74 , & V_75 ) ;
V_73 = - V_73 ;
}
static void F_42 ( struct V_76 * V_69 )
{
struct V_77 * V_78 = V_69 -> V_79 ;
T_4 V_80 , V_81 ;
if ( F_28 ( V_72 , & V_80 ) )
return;
if ( F_28 ( V_74 , & V_81 ) )
return;
V_80 = - V_80 ;
F_43 ( V_78 , V_82 , V_80 - V_73 ) ;
F_43 ( V_78 , V_83 , V_81 - V_75 ) ;
F_44 ( V_78 ) ;
}
static T_5 F_45 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_22 )
{
return snprintf ( V_22 , V_86 , L_14 ) ;
}
static T_5 F_46 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_22 )
{
int V_17 ;
T_4 V_80 , V_81 , V_87 ;
V_17 = F_28 ( V_72 , & V_80 ) ;
if ( V_17 )
goto V_31;
V_17 = F_28 ( V_74 , & V_81 ) ;
if ( V_17 )
goto V_31;
V_17 = F_28 ( V_88 , & V_87 ) ;
if ( V_17 )
goto V_31;
V_31:
if ( V_17 )
return V_17 ;
else
return snprintf ( V_22 , V_86 , L_15 , V_80 , V_81 , V_87 ) ;
}
static T_5 F_47 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
const struct V_20 * V_21 ;
static int V_90 ;
int V_17 ;
T_1 V_91 = 0 , V_92 = 0 ;
T_1 V_13 [ 10 ] ;
if ( ! V_90 ) {
V_21 = F_24 ( V_62 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
if ( V_21 -> V_14 > 10 )
return - V_93 ;
V_90 = V_21 -> V_14 ;
F_34 ( L_16 , V_90 ) ;
}
V_17 = F_25 ( V_62 , V_13 , V_90 ) ;
if ( V_90 == 10 ) {
V_91 = F_48 ( * ( V_94 * ) ( V_13 + 6 ) ) >> 2 ;
goto V_31;
}
V_91 = V_13 [ 2 ] ;
if ( V_17 )
goto V_31;
V_17 = F_25 ( V_63 , V_13 , V_90 ) ;
V_92 = V_13 [ 2 ] ;
V_31:
if ( V_17 )
return V_17 ;
else
return snprintf ( V_89 , V_86 , L_17 , V_91 , V_92 ) ;
}
static T_5 F_49 ( struct V_70 * V_69 ,
struct V_84 * V_95 , char * V_89 )
{
const char * V_10 = V_24 . V_27 [ F_50 ( V_95 ) ] ;
return snprintf ( V_89 , V_86 , L_18 , V_10 ) ;
}
static T_5 F_51 ( struct V_70 * V_69 ,
struct V_84 * V_95 , char * V_89 )
{
const char * V_10 = V_24 . V_27 [ F_50 ( V_95 ) ] ;
int V_17 ;
T_4 V_41 ;
int V_96 ;
V_17 = F_28 ( V_10 , & V_41 ) ;
if ( V_17 )
return V_17 ;
V_96 = 250 * ( V_41 >> 6 ) ;
return snprintf ( V_89 , V_86 , L_19 , V_96 ) ;
}
static T_5 F_52 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
int V_17 ;
unsigned int V_97 = 0 ;
char V_98 [ 5 ] ;
T_1 V_13 [ 2 ] ;
sprintf ( V_98 , V_99 [ F_53 ( V_85 ) ] , F_50 ( V_85 ) ) ;
V_17 = F_25 ( V_98 , V_13 , 2 ) ;
V_97 = ( ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) >> 2 ) ;
if ( V_17 )
return V_17 ;
else
return snprintf ( V_89 , V_86 , L_20 , V_97 ) ;
}
static T_5 F_54 ( struct V_70 * V_69 ,
struct V_84 * V_85 ,
const char * V_89 , T_6 V_15 )
{
int V_17 ;
unsigned long V_97 ;
char V_98 [ 5 ] ;
T_1 V_13 [ 2 ] ;
if ( F_55 ( V_89 , 10 , & V_97 ) < 0 || V_97 >= 0x4000 )
return - V_23 ;
sprintf ( V_98 , V_99 [ F_53 ( V_85 ) ] , F_50 ( V_85 ) ) ;
V_13 [ 0 ] = ( V_97 >> 6 ) & 0xff ;
V_13 [ 1 ] = ( V_97 << 2 ) & 0xff ;
V_17 = F_26 ( V_98 , V_13 , 2 ) ;
if ( V_17 )
return V_17 ;
else
return V_15 ;
}
static T_5 F_56 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
int V_17 ;
T_2 V_100 = 0 ;
T_1 V_13 [ 2 ] ;
V_17 = F_25 ( V_101 , V_13 , 2 ) ;
V_100 = ( ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) >> F_50 ( V_85 ) ) & 0x01 ;
if ( V_17 )
return V_17 ;
else
return snprintf ( V_89 , V_86 , L_19 , V_100 ) ;
}
static T_5 F_57 ( struct V_70 * V_69 ,
struct V_84 * V_85 ,
const char * V_89 , T_6 V_15 )
{
int V_17 ;
T_1 V_13 [ 2 ] ;
unsigned long V_79 ;
T_2 V_102 ;
if ( F_55 ( V_89 , 10 , & V_79 ) < 0 )
return - V_23 ;
V_17 = F_25 ( V_101 , V_13 , 2 ) ;
V_102 = ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) ;
if ( V_17 )
goto V_31;
if ( V_79 )
V_102 = V_102 | ( 0x01 << F_50 ( V_85 ) ) ;
else
V_102 = V_102 & ~ ( 0x01 << F_50 ( V_85 ) ) ;
V_13 [ 0 ] = ( V_102 >> 8 ) & 0xFF ;
V_13 [ 1 ] = V_102 & 0xFF ;
V_17 = F_26 ( V_101 , V_13 , 2 ) ;
V_31:
if ( V_17 )
return V_17 ;
else
return V_15 ;
}
static T_5 F_58 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
int V_17 ;
char V_98 [ 5 ] ;
T_1 V_13 [ 17 ] ;
sprintf ( V_98 , V_103 , F_50 ( V_85 ) ) ;
V_17 = F_25 ( V_98 , V_13 , 16 ) ;
V_13 [ 16 ] = 0 ;
if ( V_17 )
return V_17 ;
else
return snprintf ( V_89 , V_86 , L_18 , V_13 + 4 ) ;
}
static T_5 F_59 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
return snprintf ( V_89 , V_86 , L_17 , V_73 , V_75 ) ;
}
static T_5 F_60 ( struct V_70 * V_69 ,
struct V_84 * V_85 , const char * V_89 , T_6 V_15 )
{
F_41 () ;
return V_15 ;
}
static void F_61 ( struct V_104 * V_105 )
{
F_26 ( V_64 , V_71 , 2 ) ;
}
static void F_62 ( struct V_106 * V_107 ,
enum V_108 V_41 )
{
int V_17 ;
V_71 [ 0 ] = V_41 ;
V_17 = F_63 ( V_109 , & V_110 ) ;
if ( V_111 && ( ! V_17 ) )
F_64 ( V_107 -> V_69 , L_21 ) ;
}
static T_5 F_65 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
int V_17 ;
T_1 V_13 [ 4 ] ;
T_7 V_15 ;
V_17 = F_25 ( V_19 , V_13 , 4 ) ;
V_15 = ( ( T_7 ) V_13 [ 0 ] << 24 ) + ( ( T_7 ) V_13 [ 1 ] << 16 ) +
( ( T_7 ) V_13 [ 2 ] << 8 ) + V_13 [ 3 ] ;
if ( V_17 )
return V_17 ;
else
return snprintf ( V_89 , V_86 , L_19 , V_15 ) ;
}
static T_5 F_66 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
const struct V_20 * V_21 ;
int V_17 ;
V_21 = F_17 ( V_112 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
V_17 = F_13 ( V_21 , V_89 , V_21 -> V_14 ) ;
if ( V_17 )
return V_17 ;
return V_21 -> V_14 ;
}
static T_5 F_67 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
const struct V_20 * V_21 ;
V_21 = F_17 ( V_112 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
return snprintf ( V_89 , V_86 , L_19 , V_21 -> V_14 ) ;
}
static T_5 F_68 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
const struct V_20 * V_21 ;
V_21 = F_17 ( V_112 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
return snprintf ( V_89 , V_86 , L_18 , V_21 -> type ) ;
}
static T_5 F_69 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
const struct V_20 * V_21 ;
V_21 = F_17 ( V_112 ) ;
if ( F_21 ( V_21 ) )
return F_22 ( V_21 ) ;
return snprintf ( V_89 , V_86 , L_18 , V_21 -> V_10 ) ;
}
static T_5 F_70 ( struct V_70 * V_69 ,
struct V_84 * V_85 , char * V_89 )
{
return snprintf ( V_89 , V_86 , L_19 , V_112 ) ;
}
static T_5 F_71 ( struct V_70 * V_69 ,
struct V_84 * V_85 , const char * V_89 , T_6 V_15 )
{
unsigned long V_98 ;
if ( F_55 ( V_89 , 10 , & V_98 ) < 0
|| V_98 >= V_24 . V_38 )
return - V_23 ;
V_112 = V_98 ;
return V_15 ;
}
static void F_72 ( struct V_113 * V_114 )
{
struct V_113 * V_115 ;
struct V_116 * V_117 ;
for ( V_115 = V_114 ; V_115 -> V_118 ; V_115 ++ ) {
for ( V_117 = V_115 -> V_118 ; V_117 -> V_119 . V_120 . V_85 . V_121 ; V_117 ++ )
F_73 ( & V_122 -> V_69 . V_123 ,
& V_117 -> V_119 . V_120 . V_85 ) ;
F_36 ( V_115 -> V_118 ) ;
V_115 -> V_118 = NULL ;
}
}
static int F_74 ( struct V_113 * V_114 , int V_124 )
{
struct V_113 * V_115 ;
struct V_116 * V_117 ;
struct V_125 * V_85 ;
int V_17 , V_11 ;
for ( V_115 = V_114 ; V_115 -> V_126 ; V_115 ++ ) {
V_115 -> V_118 = F_32 ( V_124 + 1 , sizeof( * V_117 ) , V_50 ) ;
if ( ! V_115 -> V_118 ) {
V_17 = - V_51 ;
goto V_31;
}
for ( V_11 = 0 ; V_11 < V_124 ; V_11 ++ ) {
V_117 = & V_115 -> V_118 [ V_11 ] ;
sprintf ( V_117 -> V_121 , V_115 -> V_126 , V_11 + 1 ) ;
V_117 -> V_119 . V_27 = ( V_115 -> V_127 << 16 ) | ( V_11 & 0xffff ) ;
V_117 -> V_119 . V_120 . V_128 = V_115 -> V_128 ;
V_117 -> V_119 . V_120 . V_129 = V_115 -> V_129 ;
V_85 = & V_117 -> V_119 . V_120 . V_85 ;
F_75 ( V_85 ) ;
V_85 -> V_121 = V_117 -> V_121 ;
V_85 -> V_130 = V_131 | ( V_115 -> V_129 ? V_132 : 0 ) ;
V_17 = F_76 ( & V_122 -> V_69 . V_123 , V_85 ) ;
if ( V_17 ) {
V_85 -> V_121 = NULL ;
goto V_31;
}
}
}
return 0 ;
V_31:
F_72 ( V_114 ) ;
return V_17 ;
}
static int F_77 ( void )
{
struct V_77 * V_78 ;
int V_17 ;
if ( ! V_24 . V_43 )
return 0 ;
V_17 = F_74 ( V_133 , 1 ) ;
if ( V_17 )
goto V_31;
V_134 = F_78 () ;
if ( ! V_134 ) {
V_17 = - V_51 ;
goto V_135;
}
V_134 -> V_136 = F_42 ;
V_134 -> V_137 = V_138 ;
F_41 () ;
V_78 = V_134 -> V_79 ;
V_78 -> V_121 = L_22 ;
V_78 -> V_139 . V_140 = V_141 ;
V_78 -> V_69 . V_142 = & V_122 -> V_69 ;
V_78 -> V_143 [ 0 ] = F_79 ( V_144 ) ;
F_80 ( V_78 , V_82 ,
- 256 , 256 , V_145 , V_146 ) ;
F_80 ( V_78 , V_83 ,
- 256 , 256 , V_145 , V_146 ) ;
V_17 = F_81 ( V_134 ) ;
if ( V_17 )
goto V_147;
return 0 ;
V_147:
F_82 ( V_134 ) ;
V_135:
F_72 ( V_133 ) ;
V_31:
F_4 ( L_23 , V_17 ) ;
return V_17 ;
}
static void F_83 ( void )
{
if ( ! V_24 . V_43 )
return;
F_84 ( V_134 ) ;
F_82 ( V_134 ) ;
F_72 ( V_133 ) ;
}
static int F_85 ( void )
{
if ( ! V_24 . V_66 )
return 0 ;
return F_74 ( V_148 , 1 ) ;
}
static void F_86 ( void )
{
if ( ! V_24 . V_66 )
return;
F_72 ( V_148 ) ;
}
static int F_87 ( void )
{
if ( ! V_24 . V_65 )
return 0 ;
V_109 = F_88 ( L_24 ) ;
if ( ! V_109 )
return - V_51 ;
return F_89 ( & V_122 -> V_69 , & V_149 ) ;
}
static void F_90 ( void )
{
if ( ! V_24 . V_65 )
return;
F_91 ( & V_149 ) ;
F_92 ( V_109 ) ;
}
static int F_93 ( const struct V_150 * V_139 )
{
return 1 ;
}
static int T_8 F_94 ( void )
{
int V_17 ;
if ( ! F_95 ( V_151 ) ) {
F_4 ( L_25 ) ;
V_17 = - V_152 ;
goto V_31;
}
if ( ! F_96 ( V_12 , V_153 ,
L_22 ) ) {
V_17 = - V_93 ;
goto V_31;
}
V_17 = F_97 ( & V_154 ) ;
if ( V_17 )
goto V_155;
V_122 = F_98 ( L_22 , V_12 ,
NULL , 0 ) ;
if ( F_21 ( V_122 ) ) {
V_17 = F_22 ( V_122 ) ;
goto V_156;
}
V_17 = F_37 () ;
if ( V_17 )
goto V_157;
V_17 = F_74 ( V_158 , 1 ) ;
if ( V_17 )
goto V_159;
V_17 = F_74 ( V_160 , V_24 . V_61 ) ;
if ( V_17 )
goto V_161;
V_17 = F_74 ( V_162 , V_24 . V_55 ) ;
if ( V_17 )
goto V_163;
V_17 = F_77 () ;
if ( V_17 )
goto V_164;
V_17 = F_85 () ;
if ( V_17 )
goto V_165;
V_17 = F_87 () ;
if ( V_17 )
goto V_166;
V_167 = F_99 ( & V_122 -> V_69 ) ;
if ( F_21 ( V_167 ) ) {
V_17 = F_22 ( V_167 ) ;
goto V_168;
}
return 0 ;
V_168:
F_90 () ;
V_166:
F_86 () ;
V_165:
F_83 () ;
V_164:
F_72 ( V_162 ) ;
V_163:
F_72 ( V_160 ) ;
V_161:
F_72 ( V_158 ) ;
V_159:
F_35 () ;
V_157:
F_100 ( V_122 ) ;
V_156:
F_101 ( & V_154 ) ;
V_155:
F_102 ( V_12 , V_153 ) ;
V_31:
F_4 ( L_23 , V_17 ) ;
return V_17 ;
}
static void T_9 F_103 ( void )
{
F_104 ( V_167 ) ;
F_90 () ;
F_86 () ;
F_83 () ;
F_72 ( V_162 ) ;
F_72 ( V_160 ) ;
F_72 ( V_158 ) ;
F_35 () ;
F_100 ( V_122 ) ;
F_101 ( & V_154 ) ;
F_102 ( V_12 , V_153 ) ;
}
