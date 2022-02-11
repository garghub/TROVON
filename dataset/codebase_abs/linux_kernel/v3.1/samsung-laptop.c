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
if ( V_29 != 0 )
V_29 -= V_7 -> V_31 ;
}
return V_29 ;
}
static void F_16 ( T_1 V_29 )
{
T_1 V_32 = V_29 - V_7 -> V_31 ;
F_10 ( V_7 -> V_23 . F_16 , V_32 ) ;
}
static int V_30 ( struct V_33 * V_34 )
{
return ( int ) F_15 () ;
}
static int F_17 ( struct V_33 * V_34 )
{
F_16 ( V_34 -> V_35 . V_36 ) ;
if ( V_34 -> V_35 . V_37 == V_38 )
F_10 ( V_7 -> V_23 . V_26 , 1 ) ;
else
F_10 ( V_7 -> V_23 . V_26 , 0 ) ;
return 0 ;
}
static int F_18 ( void * V_22 , bool V_39 )
{
if ( V_39 )
F_10 ( V_7 -> V_23 . V_28 , 0 ) ;
else
F_10 ( V_7 -> V_23 . V_28 , 1 ) ;
return 0 ;
}
static int F_19 ( struct V_40 * V_41 )
{
int V_4 ;
V_42 = F_20 ( L_9 , & V_41 -> V_43 , V_44 ,
& V_45 , NULL ) ;
if ( ! V_42 )
return - V_46 ;
V_4 = F_21 ( V_42 ) ;
if ( V_4 ) {
F_22 ( V_42 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_23 ( void )
{
F_24 ( V_42 ) ;
F_22 ( V_42 ) ;
}
static T_3 F_25 ( struct V_48 * V_43 ,
struct V_49 * V_50 , char * V_51 )
{
struct V_2 V_3 ;
int V_4 ;
int V_52 ;
V_4 = F_1 ( V_7 -> V_23 . F_25 ,
& V_3 ) ;
if ( V_4 )
return V_4 ;
for ( V_52 = 0 ; V_7 -> V_53 [ V_52 ] . V_54 ; ++ V_52 ) {
if ( V_3 . V_4 [ 0 ] == V_7 -> V_53 [ V_52 ] . V_55 )
return sprintf ( V_51 , L_10 , V_7 -> V_53 [ V_52 ] . V_54 ) ;
}
return sprintf ( V_51 , L_10 , L_11 ) ;
}
static T_3 F_26 ( struct V_48 * V_43 ,
struct V_49 * V_50 , const char * V_51 ,
T_4 V_56 )
{
if ( V_56 >= 1 ) {
int V_52 ;
for ( V_52 = 0 ; V_7 -> V_53 [ V_52 ] . V_54 ; ++ V_52 ) {
const struct V_57 * V_58 =
& V_7 -> V_53 [ V_52 ] ;
if ( ! strncasecmp ( V_58 -> V_54 , V_51 , strlen ( V_58 -> V_54 ) ) ) {
F_10 ( V_7 -> V_23 . F_26 ,
V_58 -> V_55 ) ;
break;
}
}
if ( ! V_7 -> V_53 [ V_52 ] . V_54 )
return - V_21 ;
}
return V_56 ;
}
static int T_5 F_27 ( const struct V_59 * V_60 )
{
F_28 ( L_12 ,
V_60 -> V_61 ) ;
return 1 ;
}
static int F_29 ( void T_6 * V_62 , const char * V_63 )
{
int V_52 = 0 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < 0xffff ; V_64 ++ ) {
char V_65 = F_5 ( V_62 + V_64 ) ;
if ( V_65 == V_63 [ V_52 ] ) {
if ( V_52 == strlen ( V_63 ) - 1 )
break;
++ V_52 ;
} else {
V_52 = 0 ;
}
}
return V_64 ;
}
static int T_5 F_30 ( void )
{
struct V_66 V_35 ;
struct V_2 V_3 ;
unsigned int V_67 ;
int V_52 ;
int V_64 ;
int V_4 ;
F_31 ( & V_11 ) ;
if ( ! V_68 && ! F_32 ( V_69 ) )
return - V_47 ;
V_70 = F_33 ( 0xf0000 , 0xffff ) ;
if ( ! V_70 ) {
F_34 ( L_13 ) ;
return - V_21 ;
}
for ( V_52 = 0 ; V_71 [ V_52 ] . V_72 != 0 ; ++ V_52 ) {
V_7 = & V_71 [ V_52 ] ;
V_64 = F_29 ( V_70 , V_7 -> V_72 ) ;
if ( V_64 != 0xffff )
break;
}
if ( V_64 == 0xffff ) {
F_34 ( L_14 ) ;
goto V_73;
}
V_64 += 1 ;
V_6 = ( V_70 + V_64 ) ;
if ( V_74 ) {
F_12 ( V_25 L_15 ,
V_64 + 0xf0000 - 6 ) ;
F_12 ( V_25 L_16 ) ;
F_12 ( V_25 L_17 ,
F_2 ( V_6 + V_7 -> V_8 . V_5 ) ) ;
F_12 ( V_25 L_18 ,
F_5 ( V_6 + V_7 -> V_8 . V_18 ) ) ;
F_12 ( V_25 L_19 ,
F_5 ( V_6 + V_7 -> V_8 . V_12 ) ) ;
F_12 ( V_25 L_20 ,
F_5 ( V_6 + V_7 -> V_8 . V_19 ) ) ;
F_12 ( V_25 L_21 ,
F_2 ( V_6 + V_7 -> V_8 . V_75 ) ) ;
F_12 ( V_25 L_22 ,
F_2 ( V_6 + V_7 -> V_8 . V_76 ) ) ;
}
V_67 = ( F_2 ( V_6 + V_7 -> V_8 . V_76 ) & 0x0ffff ) << 4 ;
V_67 += F_2 ( V_6 + V_7 -> V_8 . V_75 ) & 0x0ffff ;
V_14 = F_33 ( V_67 , 16 ) ;
if ( ! V_14 ) {
F_34 ( L_23 , V_67 ) ;
goto exit;
}
if ( V_74 ) {
F_12 ( V_25 L_24 , V_67 ) ;
F_12 ( V_25 L_25 , V_14 ) ;
F_11 () ;
F_14 () ;
V_4 = F_1 ( V_7 -> V_23 . V_30 ,
& V_3 ) ;
F_12 ( V_25 L_26 , V_3 . V_4 [ 0 ] ) ;
}
if ( V_7 -> V_23 . V_77 != 0xff ) {
V_4 = F_10 ( V_7 -> V_23 . V_77 ,
0x81 ) ;
if ( V_4 ) {
F_8 ( L_27 ) ;
goto V_78;
}
}
V_41 = F_35 ( L_28 , - 1 , NULL , 0 ) ;
if ( F_36 ( V_41 ) )
goto V_78;
memset ( & V_35 , 0 , sizeof( struct V_66 ) ) ;
V_35 . type = V_79 ;
V_35 . V_80 = V_7 -> V_80 ;
V_33 = F_37 ( L_28 , & V_41 -> V_43 ,
NULL , & V_81 ,
& V_35 ) ;
if ( F_36 ( V_33 ) )
goto V_82;
V_33 -> V_35 . V_36 = F_15 () ;
V_33 -> V_35 . V_37 = V_38 ;
F_38 ( V_33 ) ;
V_4 = F_19 ( V_41 ) ;
if ( V_4 )
goto V_83;
V_4 = F_39 ( & V_41 -> V_43 , & V_84 ) ;
if ( V_4 )
goto V_85;
exit:
return 0 ;
V_85:
F_23 () ;
V_83:
F_40 ( V_33 ) ;
V_82:
F_41 ( V_41 ) ;
V_78:
F_42 ( V_14 ) ;
V_73:
F_42 ( V_70 ) ;
return - V_21 ;
}
static void T_7 F_43 ( void )
{
if ( V_7 -> V_23 . V_77 != 0xff )
F_10 ( V_7 -> V_23 . V_77 , 0x80 ) ;
F_44 ( & V_41 -> V_43 , & V_84 ) ;
F_40 ( V_33 ) ;
F_23 () ;
F_42 ( V_14 ) ;
F_42 ( V_70 ) ;
F_41 ( V_41 ) ;
}
