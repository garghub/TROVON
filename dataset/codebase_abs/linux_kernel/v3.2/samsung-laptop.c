static int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
int V_4 = 0 ;
T_2 V_5 = F_2 ( V_6 + V_7 -> V_8 . V_5 ) ;
T_1 V_9 , V_10 ;
F_3 ( & V_11 ) ;
F_4 ( F_5 ( V_6 + V_7 -> V_8 . V_12 ) , V_5 ) ;
F_6 ( V_7 -> V_13 , V_14 + V_15 ) ;
F_6 ( V_1 , V_14 + V_16 ) ;
F_7 ( 0 , V_14 + V_17 ) ;
F_4 ( F_5 ( V_6 + V_7 -> V_8 . V_18 ) , V_5 ) ;
F_4 ( F_5 ( V_6 + V_7 -> V_8 . V_19 ) , V_5 ) ;
V_9 = F_5 ( V_14 + V_17 ) ;
V_10 = F_5 ( V_14 + V_20 ) ;
if ( V_9 != 0xaa || V_10 == 0xff ) {
F_8 ( L_1 ,
V_1 , V_9 , V_10 ) ;
V_4 = - V_21 ;
goto exit;
}
V_3 -> V_4 [ 0 ] = F_5 ( V_14 + V_20 ) ;
V_3 -> V_4 [ 1 ] = F_5 ( V_14 + V_20 + 1 ) ;
V_3 -> V_4 [ 2 ] = F_5 ( V_14 + V_20 + 2 ) ;
V_3 -> V_4 [ 3 ] = F_5 ( V_14 + V_20 + 3 ) ;
exit:
F_9 ( & V_11 ) ;
return V_4 ;
}
static int F_10 ( T_1 V_1 , T_1 V_22 )
{
int V_4 = 0 ;
T_2 V_5 = F_2 ( V_6 + V_7 -> V_8 . V_5 ) ;
T_1 V_9 , V_10 ;
F_3 ( & V_11 ) ;
F_4 ( F_5 ( V_6 + V_7 -> V_8 . V_12 ) , V_5 ) ;
F_6 ( V_7 -> V_13 , V_14 + V_15 ) ;
F_6 ( V_1 , V_14 + V_16 ) ;
F_7 ( 0 , V_14 + V_17 ) ;
F_7 ( V_22 , V_14 + V_20 ) ;
F_4 ( F_5 ( V_6 + V_7 -> V_8 . V_18 ) , V_5 ) ;
F_4 ( F_5 ( V_6 + V_7 -> V_8 . V_19 ) , V_5 ) ;
V_9 = F_5 ( V_14 + V_17 ) ;
V_10 = F_5 ( V_14 + V_20 ) ;
if ( V_9 != 0xaa || V_10 == 0xff ) {
F_8 ( L_2 ,
V_1 , V_9 , V_10 ) ;
V_4 = - V_21 ;
}
F_9 ( & V_11 ) ;
return V_4 ;
}
static void F_11 ( void )
{
struct V_2 V_3 ;
F_1 ( V_7 -> V_23 . V_24 , & V_3 ) ;
F_12 ( V_25 L_3 , V_3 . V_4 [ 0 ] ) ;
F_10 ( V_7 -> V_23 . V_26 , 0 ) ;
F_12 ( V_25 L_4 ) ;
F_1 ( V_7 -> V_23 . V_24 , & V_3 ) ;
F_12 ( V_25 L_3 , V_3 . V_4 [ 0 ] ) ;
F_13 ( 1000 ) ;
F_10 ( V_7 -> V_23 . V_26 , 1 ) ;
F_12 ( V_25 L_5 ) ;
F_1 ( V_7 -> V_23 . V_24 , & V_3 ) ;
F_12 ( V_25 L_3 , V_3 . V_4 [ 0 ] ) ;
}
static void F_14 ( void )
{
struct V_2 V_3 ;
F_1 ( V_7 -> V_23 . V_27 , & V_3 ) ;
F_12 ( V_25 L_6 , V_3 . V_4 [ 0 ] ) ;
F_10 ( V_7 -> V_23 . V_28 , 0 ) ;
F_12 ( V_25 L_7 ) ;
F_1 ( V_7 -> V_23 . V_27 , & V_3 ) ;
F_12 ( V_25 L_6 , V_3 . V_4 [ 0 ] ) ;
F_13 ( 1000 ) ;
F_10 ( V_7 -> V_23 . V_28 , 1 ) ;
F_12 ( V_25 L_8 ) ;
F_1 ( V_7 -> V_23 . V_27 , & V_3 ) ;
F_12 ( V_25 L_6 , V_3 . V_4 [ 0 ] ) ;
}
static T_1 F_15 ( void )
{
struct V_2 V_3 ;
int V_29 = 0 ;
int V_4 ;
V_4 = F_1 ( V_7 -> V_23 . V_30 ,
& V_3 ) ;
if ( ! V_4 ) {
V_29 = V_3 . V_4 [ 0 ] ;
if ( V_29 > V_7 -> V_31 )
V_29 -= V_7 -> V_31 ;
else
V_29 = 0 ;
}
return V_29 ;
}
static void F_16 ( T_1 V_29 )
{
T_1 V_32 = V_29 + V_7 -> V_31 ;
if ( V_33 && V_32 != 0 ) {
if ( V_29 == F_15 () )
return;
F_10 ( V_7 -> V_23 . F_16 , 0 ) ;
}
F_10 ( V_7 -> V_23 . F_16 , V_32 ) ;
}
static int V_30 ( struct V_34 * V_35 )
{
return ( int ) F_15 () ;
}
static void F_17 ( void )
{
T_1 V_36 ;
T_1 V_37 ;
T_1 V_38 = F_15 () ;
if ( V_38 == 0 )
F_16 ( 1 ) ;
V_36 = F_15 () ;
if ( V_36 <= 2 )
V_37 = V_36 + 2 ;
else
V_37 = V_36 - 2 ;
V_33 = false ;
F_16 ( V_37 ) ;
if ( F_15 () != V_37 ) {
V_33 = true ;
F_18 ( L_9 ) ;
}
F_16 ( V_38 ) ;
}
static int F_19 ( struct V_34 * V_35 )
{
F_16 ( V_35 -> V_39 . V_40 ) ;
if ( V_35 -> V_39 . V_41 == V_42 )
F_10 ( V_7 -> V_23 . V_26 , 1 ) ;
else
F_10 ( V_7 -> V_23 . V_26 , 0 ) ;
return 0 ;
}
static int F_20 ( void * V_22 , bool V_43 )
{
if ( V_43 )
F_10 ( V_7 -> V_23 . V_28 , 0 ) ;
else
F_10 ( V_7 -> V_23 . V_28 , 1 ) ;
return 0 ;
}
static int F_21 ( struct V_44 * V_45 )
{
int V_4 ;
V_46 = F_22 ( L_10 , & V_45 -> V_47 , V_48 ,
& V_49 , NULL ) ;
if ( ! V_46 )
return - V_50 ;
V_4 = F_23 ( V_46 ) ;
if ( V_4 ) {
F_24 ( V_46 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_25 ( void )
{
F_26 ( V_46 ) ;
F_24 ( V_46 ) ;
}
static T_3 F_27 ( struct V_52 * V_47 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_2 V_3 ;
int V_4 ;
int V_56 ;
V_4 = F_1 ( V_7 -> V_23 . F_27 ,
& V_3 ) ;
if ( V_4 )
return V_4 ;
for ( V_56 = 0 ; V_7 -> V_57 [ V_56 ] . V_58 ; ++ V_56 ) {
if ( V_3 . V_4 [ 0 ] == V_7 -> V_57 [ V_56 ] . V_59 )
return sprintf ( V_55 , L_11 , V_7 -> V_57 [ V_56 ] . V_58 ) ;
}
return sprintf ( V_55 , L_11 , L_12 ) ;
}
static T_3 F_28 ( struct V_52 * V_47 ,
struct V_53 * V_54 , const char * V_55 ,
T_4 V_60 )
{
if ( V_60 >= 1 ) {
int V_56 ;
for ( V_56 = 0 ; V_7 -> V_57 [ V_56 ] . V_58 ; ++ V_56 ) {
const struct V_61 * V_62 =
& V_7 -> V_57 [ V_56 ] ;
if ( ! strncasecmp ( V_62 -> V_58 , V_55 , strlen ( V_62 -> V_58 ) ) ) {
F_10 ( V_7 -> V_23 . F_28 ,
V_62 -> V_59 ) ;
break;
}
}
if ( ! V_7 -> V_57 [ V_56 ] . V_58 )
return - V_21 ;
}
return V_60 ;
}
static int T_5 F_29 ( const struct V_63 * V_64 )
{
F_18 ( L_13 ,
V_64 -> V_65 ) ;
return 1 ;
}
static int F_30 ( void T_6 * V_66 , const char * V_67 )
{
int V_56 = 0 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < 0xffff ; V_68 ++ ) {
char V_69 = F_5 ( V_66 + V_68 ) ;
if ( V_69 == V_67 [ V_56 ] ) {
if ( V_56 == strlen ( V_67 ) - 1 )
break;
++ V_56 ;
} else {
V_56 = 0 ;
}
}
return V_68 ;
}
static int T_5 F_31 ( void )
{
struct V_70 V_39 ;
struct V_2 V_3 ;
unsigned int V_71 ;
int V_56 ;
int V_68 ;
int V_4 ;
F_32 ( & V_11 ) ;
if ( ! V_72 && ! F_33 ( V_73 ) )
return - V_51 ;
V_74 = F_34 ( 0xf0000 , 0xffff ) ;
if ( ! V_74 ) {
F_35 ( L_14 ) ;
return - V_21 ;
}
for ( V_56 = 0 ; V_75 [ V_56 ] . V_76 != 0 ; ++ V_56 ) {
V_7 = & V_75 [ V_56 ] ;
V_68 = F_30 ( V_74 , V_7 -> V_76 ) ;
if ( V_68 != 0xffff )
break;
}
if ( V_68 == 0xffff ) {
F_35 ( L_15 ) ;
goto V_77;
}
V_68 += 1 ;
V_6 = ( V_74 + V_68 ) ;
if ( V_78 ) {
F_12 ( V_25 L_16 ,
V_68 + 0xf0000 - 6 ) ;
F_12 ( V_25 L_17 ) ;
F_12 ( V_25 L_18 ,
F_2 ( V_6 + V_7 -> V_8 . V_5 ) ) ;
F_12 ( V_25 L_19 ,
F_5 ( V_6 + V_7 -> V_8 . V_18 ) ) ;
F_12 ( V_25 L_20 ,
F_5 ( V_6 + V_7 -> V_8 . V_12 ) ) ;
F_12 ( V_25 L_21 ,
F_5 ( V_6 + V_7 -> V_8 . V_19 ) ) ;
F_12 ( V_25 L_22 ,
F_2 ( V_6 + V_7 -> V_8 . V_79 ) ) ;
F_12 ( V_25 L_23 ,
F_2 ( V_6 + V_7 -> V_8 . V_80 ) ) ;
}
V_71 = ( F_2 ( V_6 + V_7 -> V_8 . V_80 ) & 0x0ffff ) << 4 ;
V_71 += F_2 ( V_6 + V_7 -> V_8 . V_79 ) & 0x0ffff ;
V_14 = F_34 ( V_71 , 16 ) ;
if ( ! V_14 ) {
F_35 ( L_24 , V_71 ) ;
goto V_77;
}
if ( V_78 ) {
F_12 ( V_25 L_25 , V_71 ) ;
F_12 ( V_25 L_26 , V_14 ) ;
F_11 () ;
F_14 () ;
V_4 = F_1 ( V_7 -> V_23 . V_30 ,
& V_3 ) ;
F_12 ( V_25 L_27 , V_3 . V_4 [ 0 ] ) ;
}
if ( V_7 -> V_23 . V_81 != 0xff ) {
V_4 = F_10 ( V_7 -> V_23 . V_81 ,
0x81 ) ;
if ( V_4 ) {
F_8 ( L_28 ) ;
goto V_82;
}
}
F_17 () ;
V_45 = F_36 ( L_29 , - 1 , NULL , 0 ) ;
if ( F_37 ( V_45 ) )
goto V_82;
memset ( & V_39 , 0 , sizeof( struct V_70 ) ) ;
V_39 . type = V_83 ;
V_39 . V_84 = V_7 -> V_84 -
V_7 -> V_31 ;
V_34 = F_38 ( L_29 , & V_45 -> V_47 ,
NULL , & V_85 ,
& V_39 ) ;
if ( F_37 ( V_34 ) )
goto V_86;
V_34 -> V_39 . V_40 = F_15 () ;
V_34 -> V_39 . V_41 = V_42 ;
F_39 ( V_34 ) ;
V_4 = F_21 ( V_45 ) ;
if ( V_4 )
goto V_87;
V_4 = F_40 ( & V_45 -> V_47 , & V_88 ) ;
if ( V_4 )
goto V_89;
return 0 ;
V_89:
F_25 () ;
V_87:
F_41 ( V_34 ) ;
V_86:
F_42 ( V_45 ) ;
V_82:
F_43 ( V_14 ) ;
V_77:
F_43 ( V_74 ) ;
return - V_21 ;
}
static void T_7 F_44 ( void )
{
if ( V_7 -> V_23 . V_81 != 0xff )
F_10 ( V_7 -> V_23 . V_81 , 0x80 ) ;
F_45 ( & V_45 -> V_47 , & V_88 ) ;
F_41 ( V_34 ) ;
F_25 () ;
F_43 ( V_14 ) ;
F_43 ( V_74 ) ;
F_42 ( V_45 ) ;
}
