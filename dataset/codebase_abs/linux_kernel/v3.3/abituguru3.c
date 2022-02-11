static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = V_5 ;
while ( ( V_3 = F_2 ( V_2 -> V_6 + V_7 ) ) &
V_8 ) {
V_4 -- ;
if ( V_4 == 0 )
return V_3 ;
if ( V_4 == 1 )
F_3 ( 1 ) ;
}
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = V_5 ;
while ( ! ( ( V_3 = F_2 ( V_2 -> V_6 + V_7 ) ) &
V_10 ) ) {
V_4 -- ;
if ( V_4 == 0 )
return V_3 ;
if ( V_4 == 1 )
F_3 ( 1 ) ;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_11 ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_1
L_2 , V_3 ) ;
return - V_12 ;
}
F_7 ( 0x20 , V_2 -> V_6 + V_7 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_3
L_4 , V_3 ) ;
return - V_12 ;
}
F_7 ( 0x10 , V_2 -> V_6 + V_13 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_5
L_4 , V_3 ) ;
return - V_12 ;
}
F_7 ( 0x00 , V_2 -> V_6 + V_13 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_6
L_4 , V_3 ) ;
return - V_12 ;
}
if ( ( V_3 = F_4 ( V_2 ) ) != V_9 ) {
F_6 ( L_7
L_4 , V_3 ) ;
return - V_12 ;
}
while ( ( V_3 = F_8 ( V_2 -> V_6 + V_13 ) ) != 0xAC ) {
V_4 -- ;
if ( V_4 == 0 ) {
F_6 ( L_8
L_9 ,
V_3 ) ;
return - V_12 ;
}
F_3 ( 1 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 ,
T_1 V_16 , T_1 * V_17 )
{
int V_18 , V_3 ;
if ( ( V_3 = F_5 ( V_2 ) ) )
return V_3 ;
F_7 ( 0x1A , V_2 -> V_6 + V_7 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_10
L_11 , ( unsigned int ) V_14 ,
( unsigned int ) V_15 , V_3 ) ;
return - V_12 ;
}
F_7 ( V_14 , V_2 -> V_6 + V_13 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_10
L_12 ,
( unsigned int ) V_14 , ( unsigned int ) V_15 , V_3 ) ;
return - V_12 ;
}
F_7 ( V_15 , V_2 -> V_6 + V_13 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_10
L_13 ,
( unsigned int ) V_14 , ( unsigned int ) V_15 , V_3 ) ;
return - V_12 ;
}
F_7 ( V_16 , V_2 -> V_6 + V_13 ) ;
if ( ( V_3 = F_1 ( V_2 ) ) != V_9 ) {
F_6 ( L_10
L_14 ,
( unsigned int ) V_14 , ( unsigned int ) V_15 , V_3 ) ;
return - V_12 ;
}
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ ) {
if ( ( V_3 = F_4 ( V_2 ) ) !=
V_9 ) {
F_6 ( L_15
L_16 , V_18 ,
( unsigned int ) V_14 , ( unsigned int ) V_15 , V_3 ) ;
break;
}
V_17 [ V_18 ] = F_8 ( V_2 -> V_6 + V_13 ) ;
}
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 V_15 , T_1 V_16 ,
T_1 * V_17 , int V_19 )
{
int V_18 , V_3 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
if ( ( V_3 = F_9 ( V_2 , V_14 , V_15 + V_18 , V_16 ,
V_17 + V_18 * V_16 ) ) != V_16 ) {
if ( V_3 < 0 )
return V_3 ;
return V_18 * V_16 + V_3 ;
}
return V_18 * V_16 ;
}
static T_2 F_11 ( struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_17 )
{
int V_24 ;
struct V_25 * V_26 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_13 ( V_21 ) ;
const struct V_27 * V_28 ;
if ( ! V_2 )
return - V_12 ;
V_28 = & V_2 -> V_29 [ V_26 -> V_30 ] ;
if ( V_26 -> V_31 )
V_24 = V_2 -> V_32 [ V_28 -> V_33 ] [ V_26 -> V_31 ] ;
else
V_24 = V_2 -> V_24 [ V_28 -> V_33 ] ;
V_24 = ( V_24 * V_28 -> V_34 ) / V_28 -> V_35 +
V_28 -> V_15 ;
if ( V_28 -> type == V_36 )
V_24 *= 1000 ;
return sprintf ( V_17 , L_17 , V_24 ) ;
}
static T_2 F_14 ( struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_17 )
{
int V_33 ;
struct V_25 * V_26 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_13 ( V_21 ) ;
if ( ! V_2 )
return - V_12 ;
V_33 = V_2 -> V_29 [ V_26 -> V_30 ] . V_33 ;
if ( ( V_2 -> V_37 [ V_33 / 8 ] & ( 0x01 << ( V_33 % 8 ) ) ) &&
( ! V_26 -> V_31 || ( V_2 -> V_32 [ V_33 ] [ 0 ] & V_26 -> V_31 ) ) )
return sprintf ( V_17 , L_18 ) ;
else
return sprintf ( V_17 , L_19 ) ;
}
static T_2 F_15 ( struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_17 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
if ( V_2 -> V_32 [ V_2 -> V_29 [ V_26 -> V_30 ] . V_33 ] [ 0 ] & V_26 -> V_31 )
return sprintf ( V_17 , L_18 ) ;
else
return sprintf ( V_17 , L_19 ) ;
}
static T_2 F_17 ( struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_17 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
return sprintf ( V_17 , L_20 , V_2 -> V_29 [ V_26 -> V_30 ] . V_38 ) ;
}
static T_2 F_18 ( struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_17 )
{
return sprintf ( V_17 , L_20 , V_39 ) ;
}
static int T_3 F_19 ( struct V_40 * V_41 )
{
const int V_42 [ 3 ] = { 10 , 8 , 7 } ;
int V_43 [ 3 ] = { 0 , 1 , 1 } ;
struct V_1 * V_2 ;
int V_18 , V_44 , type , V_45 , V_46 , V_47 , V_48 = - V_49 ;
char * V_50 ;
T_1 V_17 [ 2 ] ;
T_4 V_51 ;
if ( ! ( V_2 = F_20 ( sizeof( struct V_1 ) , V_52 ) ) )
return - V_53 ;
V_2 -> V_6 = F_21 ( V_41 , V_54 , 0 ) -> V_55 ;
F_22 ( & V_2 -> V_56 ) ;
F_23 ( V_41 , V_2 ) ;
if ( ( V_18 = F_9 ( V_2 , V_57 ,
V_58 , 2 , V_17 ) ) != 2 ) {
goto V_59;
}
if ( ! F_13 ( & V_41 -> V_21 ) )
goto V_59;
V_51 = ( ( T_4 ) V_17 [ 0 ] << 8 ) | ( T_4 ) V_17 [ 1 ] ;
for ( V_18 = 0 ; V_60 [ V_18 ] . V_51 ; V_18 ++ )
if ( V_60 [ V_18 ] . V_51 == V_51 )
break;
if ( ! V_60 [ V_18 ] . V_51 ) {
F_24 ( L_21 ,
( unsigned int ) V_51 , V_61 ) ;
goto V_59;
}
V_2 -> V_29 = V_60 [ V_18 ] . V_29 ;
F_25 ( L_22 , ( unsigned int ) V_51 ) ;
V_47 = 0 ;
V_50 = V_2 -> V_62 ;
V_46 = V_63 ;
for ( V_18 = 0 ; V_2 -> V_29 [ V_18 ] . V_38 ; V_18 ++ ) {
if ( V_18 >= V_64 ) {
F_24 ( L_23 ,
V_65 , V_61 ) ;
V_48 = - V_66 ;
goto V_59;
}
type = V_2 -> V_29 [ V_18 ] . type ;
for ( V_44 = 0 ; V_44 < V_42 [ type ] ; V_44 ++ ) {
V_45 = snprintf ( V_50 , V_46 ,
V_67 [ type ] [ V_44 ] . V_68 . V_26 .
V_38 , V_43 [ type ] ) + 1 ;
V_2 -> V_69 [ V_47 ] =
V_67 [ type ] [ V_44 ] ;
V_2 -> V_69 [ V_47 ] . V_68 . V_26 . V_38 =
V_50 ;
V_2 -> V_69 [ V_47 ] . V_30 = V_18 ;
V_50 += V_45 ;
V_46 -= V_45 ;
V_47 ++ ;
}
V_43 [ type ] ++ ;
}
if ( V_46 < 0 ) {
F_24 ( L_24 ,
V_65 , V_61 ) ;
V_48 = - V_66 ;
goto V_59;
}
for ( V_18 = 0 ; V_18 < V_47 ; V_18 ++ )
if ( F_26 ( & V_41 -> V_21 ,
& V_2 -> V_69 [ V_18 ] . V_68 ) )
goto V_59;
for ( V_18 = 0 ; V_18 < F_27 ( V_70 ) ; V_18 ++ )
if ( F_26 ( & V_41 -> V_21 ,
& V_70 [ V_18 ] . V_68 ) )
goto V_59;
V_2 -> V_71 = F_28 ( & V_41 -> V_21 ) ;
if ( F_29 ( V_2 -> V_71 ) ) {
V_48 = F_30 ( V_2 -> V_71 ) ;
goto V_59;
}
return 0 ;
V_59:
for ( V_18 = 0 ; V_2 -> V_69 [ V_18 ] . V_68 . V_26 . V_38 ; V_18 ++ )
F_31 ( & V_41 -> V_21 , & V_2 -> V_69 [ V_18 ] . V_68 ) ;
for ( V_18 = 0 ; V_18 < F_27 ( V_70 ) ; V_18 ++ )
F_31 ( & V_41 -> V_21 ,
& V_70 [ V_18 ] . V_68 ) ;
F_32 ( V_2 ) ;
return V_48 ;
}
static int T_5 F_33 ( struct V_40 * V_41 )
{
int V_18 ;
struct V_1 * V_2 = F_34 ( V_41 ) ;
F_23 ( V_41 , NULL ) ;
F_35 ( V_2 -> V_71 ) ;
for ( V_18 = 0 ; V_2 -> V_69 [ V_18 ] . V_68 . V_26 . V_38 ; V_18 ++ )
F_31 ( & V_41 -> V_21 , & V_2 -> V_69 [ V_18 ] . V_68 ) ;
for ( V_18 = 0 ; V_18 < F_27 ( V_70 ) ; V_18 ++ )
F_31 ( & V_41 -> V_21 ,
& V_70 [ V_18 ] . V_68 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static struct V_1 * F_13 ( struct V_20 * V_21 )
{
int V_18 ;
struct V_1 * V_2 = F_16 ( V_21 ) ;
F_36 ( & V_2 -> V_56 ) ;
if ( ! V_2 -> V_72 || F_37 ( V_73 , V_2 -> V_74 + V_75 ) ) {
V_2 -> V_72 = 0 ;
if ( F_10 ( V_2 ,
V_76 ,
V_77 ,
1 , V_2 -> V_37 , 48 / 8 ) != ( 48 / 8 ) )
goto V_78;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ ) {
if ( F_9 ( V_2 , V_79 ,
V_80 + V_18 ,
1 , & V_2 -> V_24 [ V_18 ] ) != 1 )
goto V_78;
if ( F_10 ( V_2 ,
V_76 ,
V_81 + V_18 * 3 ,
1 ,
V_2 -> V_32 [ V_18 ] , 3 ) != 3 )
goto V_78;
}
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
if ( F_9 ( V_2 , V_79 ,
V_80 + 32 + V_18 ,
1 , & V_2 -> V_24 [ 32 + V_18 ] ) != 1 )
goto V_78;
if ( F_10 ( V_2 ,
V_76 ,
V_81 + 32 * 3 +
V_18 * 2 , 1 ,
V_2 -> V_32 [ 32 + V_18 ] , 2 ) != 2 )
goto V_78;
}
V_2 -> V_74 = V_73 ;
V_2 -> V_72 = 1 ;
}
V_78:
F_38 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_72 )
return V_2 ;
else
return NULL ;
}
static int F_39 ( struct V_40 * V_41 , T_6 V_82 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
F_36 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_40 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
F_38 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int T_7 F_41 ( void )
{
const char * V_83 , * V_84 ;
int V_18 , V_85 = ( V_86 ) ? 1 : - V_49 ;
const char * const * V_87 ;
T_8 V_88 ;
V_83 = F_42 ( V_89 ) ;
if ( ! V_83 || strcmp ( V_83 , L_25 ) )
return V_85 ;
V_84 = F_42 ( V_90 ) ;
if ( ! V_84 )
return V_85 ;
V_88 = strcspn ( V_84 , L_26 ) ;
while ( V_88 > 0 && V_84 [ V_88 - 1 ] == ' ' )
V_88 -- ;
for ( V_18 = 0 ; V_60 [ V_18 ] . V_51 ; V_18 ++ ) {
V_87 = V_60 [ V_18 ] . V_87 ;
for ( ; * V_87 ; V_87 ++ ) {
if ( strlen ( * V_87 ) != V_88 )
continue;
if ( ! strncasecmp ( V_84 , * V_87 , V_88 ) )
return 0 ;
}
}
return 1 ;
}
static int T_7 F_43 ( void )
{
T_1 V_91 = F_2 ( V_92 + V_7 ) ;
T_1 V_93 = F_2 ( V_92 + V_13 ) ;
if ( ( ( V_91 == 0x00 ) || ( V_91 == 0x08 ) ) &&
( ( V_93 == 0xAC ) || ( V_93 == 0x05 ) ||
( V_93 == 0x55 ) ) )
return 0 ;
F_6 ( L_27
L_28 , ( unsigned int ) V_91 , ( unsigned int ) V_93 ) ;
if ( V_86 ) {
F_25 ( L_29 ) ;
return 0 ;
}
return - V_49 ;
}
static int T_7 F_44 ( void )
{
struct V_94 V_48 = { . V_95 = V_54 } ;
int V_85 ;
V_85 = F_41 () ;
if ( V_85 < 0 )
return V_85 ;
if ( V_85 > 0 ) {
V_85 = F_43 () ;
if ( V_85 )
return V_85 ;
F_45 ( L_30
L_31 ) ;
}
V_85 = F_46 ( & V_96 ) ;
if ( V_85 )
goto exit;
V_97 = F_47 ( V_39 ,
V_92 ) ;
if ( ! V_97 ) {
F_24 ( L_32 ) ;
V_85 = - V_53 ;
goto V_98;
}
V_48 . V_55 = V_92 ;
V_48 . V_99 = V_92 + V_100 - 1 ;
V_48 . V_38 = V_39 ;
V_85 = F_48 ( V_97 , & V_48 , 1 ) ;
if ( V_85 ) {
F_24 ( L_33 , V_85 ) ;
goto V_101;
}
V_85 = F_49 ( V_97 ) ;
if ( V_85 ) {
F_24 ( L_34 , V_85 ) ;
goto V_101;
}
return 0 ;
V_101:
F_50 ( V_97 ) ;
V_98:
F_51 ( & V_96 ) ;
exit:
return V_85 ;
}
static void T_9 F_52 ( void )
{
F_53 ( V_97 ) ;
F_51 ( & V_96 ) ;
}
