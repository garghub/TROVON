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
if ( V_35 == 0x80 ) {
V_1 [ 0 ] = 0x13 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
return 0 ;
}
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
T_4 V_42 , V_43 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
if ( V_41 == 0 ) {
V_1 [ 0 ] = 0xf5 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
return;
}
if ( V_41 <= 0xaaaa ) {
V_42 = 0x0c * V_41 ;
V_43 = 0x80 * V_41 ;
} else {
V_42 = ( 0x0c * 0xaaaa ) + 0x06 * ( V_41 - 0xaaaa ) ;
V_43 = ( 0x80 * 0xaaaa ) + 0xff * ( V_41 - 0xaaaa ) ;
}
switch ( V_14 -> V_16 ) {
case V_44 :
case V_45 :
break;
default:
V_42 = V_42 >> 1 ;
break;
}
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x0d ;
V_1 [ 2 ] = V_42 / 0xaaaa ;
V_1 [ 3 ] = V_42 / 0xaaaa ;
V_1 [ 4 ] = V_43 / 0xaaaa ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
V_1 [ 0 ] = 0x14 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_13 ( struct V_22 * V_23 , T_3 V_41 )
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
static void F_14 ( struct V_5 * V_6 , T_3 V_2 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
F_15 ( L_4 , V_2 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x81 ;
V_1 [ 2 ] = V_2 & 0x00ff ;
V_1 [ 3 ] = ( V_2 & 0xff00 ) >> 8 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_16 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
int V_46 , V_47 , V_48 ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
F_15 ( L_5 , V_2 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 > 200 ) {
V_32 -> V_8 [ 0 ] -> V_1 [ 1 ] = 0x03 ;
V_48 = 900 ;
} else {
V_32 -> V_8 [ 0 ] -> V_1 [ 1 ] = 0x02 ;
V_48 = 200 ;
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
V_46 = ( ( ( V_48 - V_2 + 1 ) * 2047 ) / V_48 ) ;
V_47 = 0xfff - V_46 ;
V_1 [ 2 ] = V_46 >> 4 ;
V_1 [ 3 ] = V_47 >> 4 ;
V_1 [ 4 ] = 0xff ;
V_1 [ 5 ] = ( V_47 & 0xe ) << 4 | ( V_46 & 0xe ) ;
V_1 [ 6 ] = 0xff ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_17 ( struct V_5 * V_6 , const struct V_49 * V_50 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_5 V_51 , V_52 ;
V_52 = 0 ;
while ( V_52 < 7 * V_50 -> V_53 ) {
for ( V_51 = 0 ; V_51 < 7 ; V_51 ++ )
V_32 -> V_8 [ 0 ] -> V_1 [ V_51 ] = V_50 -> V_50 [ V_52 ++ ] ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
}
static T_6 F_18 ( struct V_54 * V_23 , struct V_55 * V_56 ,
char * V_57 )
{
struct V_5 * V_6 = F_19 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_7 V_58 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
V_58 = F_20 ( V_57 , V_59 , L_6 , V_14 -> V_2 ) ;
return V_58 ;
}
static T_6 F_21 ( struct V_54 * V_23 , struct V_55 * V_56 ,
const char * V_57 , T_7 V_58 )
{
struct V_5 * V_6 = F_19 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_2 = F_22 ( V_57 , NULL , 10 ) ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_60 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_60 ;
}
if ( V_2 == 0 )
V_2 = V_14 -> V_3 ;
if ( V_14 -> V_61 != NULL && V_2 >= V_14 -> V_62 && V_2 <= V_14 -> V_3 ) {
V_14 -> V_61 ( V_6 , V_2 ) ;
V_14 -> V_2 = V_2 ;
}
return V_58 ;
}
static void F_23 ( struct V_5 * V_6 , T_5 V_63 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x12 ;
V_1 [ 2 ] = V_63 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_24 ( struct V_64 * V_65 ,
enum V_66 V_1 )
{
struct V_54 * V_23 = V_65 -> V_23 -> V_67 ;
struct V_5 * V_6 = F_25 ( V_23 , struct V_5 , V_23 ) ;
struct V_11 * V_12 = F_12 ( V_6 ) ;
struct V_13 * V_14 ;
int V_51 , V_68 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_7 ) ;
return;
}
V_14 = (struct V_13 * ) V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_8 ) ;
return;
}
for ( V_51 = 0 ; V_51 < 5 ; V_51 ++ ) {
if ( V_65 != V_14 -> V_69 [ V_51 ] )
continue;
V_68 = ( V_14 -> V_70 >> V_51 ) & 1 ;
if ( V_1 == V_71 && V_68 ) {
V_14 -> V_70 &= ~ ( 1 << V_51 ) ;
F_23 ( V_6 , V_14 -> V_70 ) ;
} else if ( V_1 != V_71 && ! V_68 ) {
V_14 -> V_70 |= 1 << V_51 ;
F_23 ( V_6 , V_14 -> V_70 ) ;
}
break;
}
}
static enum V_66 F_26 ( struct V_64 * V_65 )
{
struct V_54 * V_23 = V_65 -> V_23 -> V_67 ;
struct V_5 * V_6 = F_25 ( V_23 , struct V_5 , V_23 ) ;
struct V_11 * V_12 = F_12 ( V_6 ) ;
struct V_13 * V_14 ;
int V_51 , V_1 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_7 ) ;
return V_71 ;
}
V_14 = (struct V_13 * ) V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_8 ) ;
return V_71 ;
}
for ( V_51 = 0 ; V_51 < 5 ; V_51 ++ )
if ( V_65 == V_14 -> V_69 [ V_51 ] ) {
V_1 = ( V_14 -> V_70 >> V_51 ) & 1 ;
break;
}
return V_1 ? V_72 : V_71 ;
}
int F_27 ( struct V_5 * V_6 )
{
struct V_73 * V_20 = F_8 ( V_6 -> V_74 . V_33 , struct V_73 , V_34 ) ;
struct V_22 * V_23 = V_20 -> V_21 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
struct V_75 * V_76 ;
int error , V_51 , V_52 ;
T_2 V_77 , V_78 , V_79 ;
if ( ! F_28 ( V_6 , V_30 , 0 , 0 , 7 ) )
return - 1 ;
for ( V_51 = 0 ; V_51 < F_29 ( V_80 ) ; V_51 ++ ) {
if ( V_6 -> V_81 == V_80 [ V_51 ] . V_16 ) {
F_15 ( L_9 , V_80 [ V_51 ] . V_16 ) ;
break;
}
}
if ( V_51 == F_29 ( V_80 ) ) {
F_4 ( V_6 , L_10
L_11 ) ;
return - 1 ;
}
V_76 = & ( F_30 ( V_6 ) -> V_82 ) ;
if ( ! V_76 ) {
F_4 ( V_6 , L_12 ) ;
return - 1 ;
}
V_77 = F_31 ( V_76 -> V_77 ) ;
V_78 = V_77 >> 8 ;
V_79 = V_77 & 0xff ;
if ( V_80 [ V_51 ] . V_16 == V_83 ) {
F_15 ( L_13 ) ;
F_15 ( L_14 , V_78 , V_79 ) ;
for ( V_52 = 0 ; V_52 < F_29 ( V_84 ) ; V_52 ++ ) {
if ( V_84 [ V_52 ] . V_78 == V_78 && V_84 [ V_52 ] . V_79 == V_79 ) {
F_17 ( V_6 , V_84 [ V_52 ] . V_85 ) ;
F_32 ( V_6 , L_15 ) ;
}
}
}
for ( V_52 = 0 ; V_80 [ V_51 ] . V_86 [ V_52 ] >= 0 ; V_52 ++ )
F_33 ( V_80 [ V_51 ] . V_86 [ V_52 ] , V_23 -> V_87 ) ;
error = F_34 ( V_23 , NULL , F_6 ) ;
if ( error )
return error ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_16 ) ;
return - 1 ;
}
V_14 = F_35 ( sizeof( struct V_13 ) , V_88 ) ;
if ( ! V_14 ) {
F_4 ( V_6 , L_17 ) ;
return - V_89 ;
}
V_12 -> V_15 = V_14 ;
V_14 -> V_16 = V_80 [ V_51 ] . V_16 ;
V_14 -> V_62 = V_80 [ V_51 ] . V_62 ;
V_14 -> V_3 = V_80 [ V_51 ] . V_3 ;
V_14 -> V_61 = V_80 [ V_51 ] . V_61 ;
if ( F_36 ( V_90 , V_23 -> V_87 ) ) {
if ( V_78 == V_91 && V_79 == V_92 )
V_23 -> V_93 -> V_94 = F_13 ;
else
V_23 -> V_93 -> V_94 = F_11 ;
V_23 -> V_93 -> V_94 ( V_23 , 0 ) ;
}
error = F_37 ( & V_6 -> V_23 , & V_95 ) ;
if ( error )
return error ;
F_15 ( L_18 ) ;
V_14 -> V_2 = V_14 -> V_3 ;
if ( V_14 -> V_61 != NULL )
V_14 -> V_61 ( V_6 , V_14 -> V_2 ) ;
#ifdef F_38
V_14 -> V_70 = 0 ;
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ )
V_14 -> V_69 [ V_52 ] = NULL ;
if ( V_80 [ V_51 ] . V_16 == V_96 ) {
struct V_64 * V_69 ;
T_7 V_97 ;
char * V_98 ;
F_23 ( V_6 , 0 ) ;
V_97 = strlen ( F_39 ( & V_6 -> V_23 ) ) + 8 ;
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ ) {
V_69 = F_35 ( sizeof( struct V_64 ) + V_97 , V_88 ) ;
if ( ! V_69 ) {
F_4 ( V_6 , L_19 , V_52 ) ;
goto V_99;
}
V_98 = ( void * ) ( & V_69 [ 1 ] ) ;
snprintf ( V_98 , V_97 , L_20 , F_39 ( & V_6 -> V_23 ) , V_52 + 1 ) ;
V_69 -> V_98 = V_98 ;
V_69 -> V_100 = 0 ;
V_69 -> V_101 = 1 ;
V_69 -> V_102 = F_26 ;
V_69 -> V_103 = F_24 ;
V_14 -> V_69 [ V_52 ] = V_69 ;
error = F_40 ( & V_6 -> V_23 , V_69 ) ;
if ( error ) {
F_4 ( V_6 , L_21 , V_52 ) ;
V_99:
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ ) {
V_69 = V_14 -> V_69 [ V_52 ] ;
V_14 -> V_69 [ V_52 ] = NULL ;
if ( ! V_69 )
continue;
F_41 ( V_69 ) ;
F_42 ( V_69 ) ;
}
goto V_104;
}
}
}
V_104:
#endif
F_32 ( V_6 , L_22 ) ;
return 0 ;
}
int F_43 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
F_44 ( & V_6 -> V_23 , & V_95 ) ;
V_12 = F_12 ( V_6 ) ;
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
int V_52 ;
struct V_64 * V_69 ;
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ ) {
V_69 = V_14 -> V_69 [ V_52 ] ;
V_14 -> V_69 [ V_52 ] = NULL ;
if ( ! V_69 )
continue;
F_41 ( V_69 ) ;
F_42 ( V_69 ) ;
}
}
#endif
F_42 ( V_14 ) ;
F_15 ( L_25 ) ;
return 0 ;
}
