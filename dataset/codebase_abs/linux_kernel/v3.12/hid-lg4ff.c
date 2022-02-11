static T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
T_2 V_3 ;
T_1 V_4 ;
if ( V_2 == 900 )
return V_1 ;
else if ( V_2 == 200 )
return V_1 ;
else if ( V_2 < 200 )
V_3 = 200 ;
else
V_3 = 900 ;
V_4 = 8192 + F_2 ( V_1 - 8192 , V_3 , V_2 ) ;
if ( V_4 < 0 )
return 0 ;
else if ( V_4 > 16383 )
return 16383 ;
else
return V_4 ;
}
int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_1 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_4 = 0 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_1 ) ;
return 0 ;
}
switch ( V_14 -> V_16 ) {
case V_17 :
switch ( V_10 -> V_18 ) {
case V_19 :
V_4 = F_1 ( V_1 , V_14 -> V_2 ) ;
F_5 ( V_8 -> V_20 -> V_21 , V_10 -> type , V_10 -> V_18 , V_4 ) ;
return 1 ;
default:
return 0 ;
}
default:
return 0 ;
}
}
static int F_6 ( struct V_22 * V_23 , void * V_24 , struct V_25 * V_26 )
{
struct V_5 * V_6 = F_7 ( V_23 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
int V_35 ;
#define F_9 ( V_35 ) do { if (x < 0) x = 0; else if (x > 0xff) x = 0xff; } while (0)
switch ( V_26 -> type ) {
case V_36 :
V_35 = V_26 -> V_37 . V_38 . V_39 + 0x80 ;
F_9 ( V_35 ) ;
V_1 [ 0 ] = 0x11 ;
V_1 [ 1 ] = 0x08 ;
V_1 [ 2 ] = V_35 ;
V_1 [ 3 ] = 0x80 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
break;
}
return 0 ;
}
static void F_11 ( struct V_22 * V_23 , T_3 V_41 )
{
struct V_5 * V_6 = F_7 ( V_23 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x0d ;
V_1 [ 2 ] = V_41 >> 13 ;
V_1 [ 3 ] = V_41 >> 13 ;
V_1 [ 4 ] = V_41 >> 8 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_12 ( struct V_22 * V_23 , T_3 V_41 )
{
struct V_5 * V_6 = F_7 ( V_23 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
V_41 = V_41 * 90 / 65535 ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_41 >> 14 ;
V_1 [ 3 ] = V_41 >> 14 ;
V_1 [ 4 ] = V_41 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_13 ( struct V_5 * V_6 , T_3 V_2 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
F_14 ( L_2 , V_2 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x81 ;
V_1 [ 2 ] = V_2 & 0x00ff ;
V_1 [ 3 ] = ( V_2 & 0xff00 ) >> 8 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_15 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
int V_42 , V_43 , V_44 ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
F_14 ( L_3 , V_2 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 > 200 ) {
V_32 -> V_8 [ 0 ] -> V_1 [ 1 ] = 0x03 ;
V_44 = 900 ;
} else {
V_32 -> V_8 [ 0 ] -> V_1 [ 1 ] = 0x02 ;
V_44 = 200 ;
}
F_10 ( V_6 , V_32 , V_40 ) ;
V_1 [ 0 ] = 0x81 ;
V_1 [ 1 ] = 0x0b ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 == 200 || V_2 == 900 ) {
F_10 ( V_6 , V_32 , V_40 ) ;
return;
}
V_42 = ( ( ( V_44 - V_2 + 1 ) * 2047 ) / V_44 ) ;
V_43 = 0xfff - V_42 ;
V_1 [ 2 ] = V_42 >> 4 ;
V_1 [ 3 ] = V_43 >> 4 ;
V_1 [ 4 ] = 0xff ;
V_1 [ 5 ] = ( V_43 & 0xe ) << 4 | ( V_42 & 0xe ) ;
V_1 [ 6 ] = 0xff ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_16 ( struct V_5 * V_6 , const struct V_45 * V_46 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_4 V_47 , V_48 ;
V_48 = 0 ;
while ( V_48 < 7 * V_46 -> V_49 ) {
for ( V_47 = 0 ; V_47 < 7 ; V_47 ++ )
V_32 -> V_8 [ 0 ] -> V_1 [ V_47 ] = V_46 -> V_46 [ V_48 ++ ] ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
}
static T_5 F_17 ( struct V_50 * V_23 , struct V_51 * V_52 , char * V_53 )
{
struct V_5 * V_6 = F_18 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_54 ;
V_12 = F_19 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_4 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_5 ) ;
return 0 ;
}
V_54 = F_20 ( V_53 , V_55 , L_6 , V_14 -> V_2 ) ;
return V_54 ;
}
static T_5 F_21 ( struct V_50 * V_23 , struct V_51 * V_52 , const char * V_53 , T_6 V_54 )
{
struct V_5 * V_6 = F_18 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_2 = F_22 ( V_53 , NULL , 10 ) ;
V_12 = F_19 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_4 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_5 ) ;
return 0 ;
}
if ( V_2 == 0 )
V_2 = V_14 -> V_3 ;
if ( V_14 -> V_56 != NULL && V_2 >= V_14 -> V_57 && V_2 <= V_14 -> V_3 ) {
V_14 -> V_56 ( V_6 , V_2 ) ;
V_14 -> V_2 = V_2 ;
}
return V_54 ;
}
static void F_23 ( struct V_5 * V_6 , T_4 V_58 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x12 ;
V_1 [ 2 ] = V_58 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_24 ( struct V_59 * V_60 ,
enum V_61 V_1 )
{
struct V_50 * V_23 = V_60 -> V_23 -> V_62 ;
struct V_5 * V_6 = F_25 ( V_23 , struct V_5 , V_23 ) ;
struct V_11 * V_12 = F_19 ( V_6 ) ;
struct V_13 * V_14 ;
int V_47 , V_63 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_7 ) ;
return;
}
V_14 = (struct V_13 * ) V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_8 ) ;
return;
}
for ( V_47 = 0 ; V_47 < 5 ; V_47 ++ ) {
if ( V_60 != V_14 -> V_64 [ V_47 ] )
continue;
V_63 = ( V_14 -> V_65 >> V_47 ) & 1 ;
if ( V_1 == V_66 && V_63 ) {
V_14 -> V_65 &= ~ ( 1 << V_47 ) ;
F_23 ( V_6 , V_14 -> V_65 ) ;
} else if ( V_1 != V_66 && ! V_63 ) {
V_14 -> V_65 |= 1 << V_47 ;
F_23 ( V_6 , V_14 -> V_65 ) ;
}
break;
}
}
static enum V_61 F_26 ( struct V_59 * V_60 )
{
struct V_50 * V_23 = V_60 -> V_23 -> V_62 ;
struct V_5 * V_6 = F_25 ( V_23 , struct V_5 , V_23 ) ;
struct V_11 * V_12 = F_19 ( V_6 ) ;
struct V_13 * V_14 ;
int V_47 , V_1 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_7 ) ;
return V_66 ;
}
V_14 = (struct V_13 * ) V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_8 ) ;
return V_66 ;
}
for ( V_47 = 0 ; V_47 < 5 ; V_47 ++ )
if ( V_60 == V_14 -> V_64 [ V_47 ] ) {
V_1 = ( V_14 -> V_65 >> V_47 ) & 1 ;
break;
}
return V_1 ? V_67 : V_66 ;
}
int F_27 ( struct V_5 * V_6 )
{
struct V_68 * V_20 = F_8 ( V_6 -> V_69 . V_33 , struct V_68 , V_34 ) ;
struct V_22 * V_23 = V_20 -> V_21 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
struct V_70 * V_71 ;
int error , V_47 , V_48 ;
T_2 V_72 , V_73 , V_74 ;
if ( ! F_28 ( V_6 , V_30 , 0 , 0 , 7 ) )
return - 1 ;
for ( V_47 = 0 ; V_47 < F_29 ( V_75 ) ; V_47 ++ ) {
if ( V_6 -> V_76 == V_75 [ V_47 ] . V_16 ) {
F_14 ( L_9 , V_75 [ V_47 ] . V_16 ) ;
break;
}
}
if ( V_47 == F_29 ( V_75 ) ) {
F_4 ( V_6 , L_10
L_11 ) ;
return - 1 ;
}
V_71 = & ( F_30 ( V_6 ) -> V_77 ) ;
if ( ! V_71 ) {
F_4 ( V_6 , L_12 ) ;
return - 1 ;
}
V_72 = F_31 ( V_71 -> V_72 ) ;
V_73 = V_72 >> 8 ;
V_74 = V_72 & 0xff ;
if ( V_75 [ V_47 ] . V_16 == V_78 ) {
F_14 ( L_13 ) ;
F_14 ( L_14 , V_73 , V_74 ) ;
for ( V_48 = 0 ; V_48 < F_29 ( V_79 ) ; V_48 ++ ) {
if ( V_79 [ V_48 ] . V_73 == V_73 && V_79 [ V_48 ] . V_74 == V_74 ) {
F_16 ( V_6 , V_79 [ V_48 ] . V_80 ) ;
F_32 ( V_6 , L_15 ) ;
}
}
}
for ( V_48 = 0 ; V_75 [ V_47 ] . V_81 [ V_48 ] >= 0 ; V_48 ++ )
F_33 ( V_75 [ V_47 ] . V_81 [ V_48 ] , V_23 -> V_82 ) ;
error = F_34 ( V_23 , NULL , F_6 ) ;
if ( error )
return error ;
if ( F_35 ( V_83 , V_23 -> V_82 ) ) {
if ( V_73 == V_84 && V_74 == V_85 )
V_23 -> V_86 -> V_87 = F_12 ;
else
V_23 -> V_86 -> V_87 = F_11 ;
V_23 -> V_86 -> V_87 ( V_23 , 0 ) ;
}
V_12 = F_19 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_16 ) ;
return - 1 ;
}
V_14 = F_36 ( sizeof( struct V_13 ) , V_88 ) ;
if ( ! V_14 ) {
F_4 ( V_6 , L_17 ) ;
return - V_89 ;
}
V_12 -> V_15 = V_14 ;
V_14 -> V_16 = V_75 [ V_47 ] . V_16 ;
V_14 -> V_57 = V_75 [ V_47 ] . V_57 ;
V_14 -> V_3 = V_75 [ V_47 ] . V_3 ;
V_14 -> V_56 = V_75 [ V_47 ] . V_56 ;
error = F_37 ( & V_6 -> V_23 , & V_90 ) ;
if ( error )
return error ;
F_14 ( L_18 ) ;
V_14 -> V_2 = V_14 -> V_3 ;
if ( V_14 -> V_56 != NULL )
V_14 -> V_56 ( V_6 , V_14 -> V_2 ) ;
#ifdef F_38
V_14 -> V_65 = 0 ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ )
V_14 -> V_64 [ V_48 ] = NULL ;
if ( V_75 [ V_47 ] . V_16 == V_91 ) {
struct V_59 * V_64 ;
T_6 V_92 ;
char * V_93 ;
F_23 ( V_6 , 0 ) ;
V_92 = strlen ( F_39 ( & V_6 -> V_23 ) ) + 8 ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ ) {
V_64 = F_36 ( sizeof( struct V_59 ) + V_92 , V_88 ) ;
if ( ! V_64 ) {
F_4 ( V_6 , L_19 , V_48 ) ;
goto V_94;
}
V_93 = ( void * ) ( & V_64 [ 1 ] ) ;
snprintf ( V_93 , V_92 , L_20 , F_39 ( & V_6 -> V_23 ) , V_48 + 1 ) ;
V_64 -> V_93 = V_93 ;
V_64 -> V_95 = 0 ;
V_64 -> V_96 = 1 ;
V_64 -> V_97 = F_26 ;
V_64 -> V_98 = F_24 ;
V_14 -> V_64 [ V_48 ] = V_64 ;
error = F_40 ( & V_6 -> V_23 , V_64 ) ;
if ( error ) {
F_4 ( V_6 , L_21 , V_48 ) ;
V_94:
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ ) {
V_64 = V_14 -> V_64 [ V_48 ] ;
V_14 -> V_64 [ V_48 ] = NULL ;
if ( ! V_64 )
continue;
F_41 ( V_64 ) ;
F_42 ( V_64 ) ;
}
goto V_99;
}
}
}
V_99:
#endif
F_32 ( V_6 , L_22 ) ;
return 0 ;
}
int F_43 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
F_44 ( & V_6 -> V_23 , & V_90 ) ;
V_12 = F_19 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_23 ) ;
return - 1 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_24 ) ;
return - 1 ;
}
#ifdef F_38
{
int V_48 ;
struct V_59 * V_64 ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ ) {
V_64 = V_14 -> V_64 [ V_48 ] ;
V_14 -> V_64 [ V_48 ] = NULL ;
if ( ! V_64 )
continue;
F_41 ( V_64 ) ;
F_42 ( V_64 ) ;
}
}
#endif
F_42 ( V_14 ) ;
F_14 ( L_25 ) ;
return 0 ;
}
