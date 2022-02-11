static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_1 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 ) )
return 0 ;
return & V_7 -> V_8 . V_9 == V_6 ;
}
void F_5 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_12 ;
F_6 ( & V_11 -> V_13 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
}
int F_10 ( struct V_1 * V_3 ,
struct V_10 * V_11 )
{
int error ;
struct V_1 * V_2 = & V_11 -> V_12 ;
F_11 ( V_2 ) ;
V_2 -> type = & V_14 ;
V_2 -> V_3 = F_12 ( V_3 ) ;
V_2 -> V_4 = F_1 ;
F_13 ( V_2 , L_1 , V_11 -> V_15 ) ;
F_14 ( V_2 ) ;
F_15 ( V_11 ) ;
error = F_16 ( V_2 ) ;
if ( error ) {
goto V_16;
}
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
error = F_23 ( & V_11 -> V_13 ) ;
if ( error ) {
goto V_17;
}
return 0 ;
V_17:
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
V_16:
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
return error ;
}
static int F_24 ( int V_18 ) { return V_18 ; }
static void F_25 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_26 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_25 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_28 ( V_7 ) ;
if ( ! F_26 ( V_2 ) )
return 0 ;
return & V_20 -> V_21 . V_9 == V_6 ;
}
void F_6 ( struct V_22 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_12 ;
struct V_23 * V_24 ;
F_29 (ata_dev, link, ALL) {
F_30 ( V_24 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
}
int F_23 ( struct V_22 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_12 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_23 * V_24 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_3 = F_12 ( & V_11 -> V_12 ) ;
V_2 -> V_4 = F_25 ;
if ( F_31 ( V_13 ) )
F_13 ( V_2 , L_2 , V_11 -> V_15 ) ;
else
F_13 ( V_2 , L_3 , V_11 -> V_15 , V_13 -> V_25 ) ;
F_14 ( V_2 ) ;
error = F_16 ( V_2 ) ;
if ( error ) {
goto V_26;
}
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_29 (ata_dev, link, ALL) {
error = F_32 ( V_24 ) ;
if ( error ) {
goto V_27;
}
}
return 0 ;
V_27:
while ( -- V_24 >= V_13 -> V_1 ) {
F_30 ( V_24 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
V_26:
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
return error ;
}
static int F_33 ( struct V_28 * V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_33 time ;
F_34 ( V_29 -> V_34 , & time ) ;
V_32 -> V_35 += sprintf ( V_32 -> V_36 + V_32 -> V_35 ,
L_4 ,
time . V_37 , time . V_38 ) ;
V_32 -> V_35 += F_35 ( V_29 -> V_39 ,
V_32 -> V_36 + V_32 -> V_35 ) ;
return 0 ;
}
static T_1
F_36 ( struct V_1 * V_2 ,
struct V_40 * V_41 , char * V_36 )
{
struct V_23 * V_24 = F_37 ( V_2 ) ;
struct V_31 V_32 = { V_36 , 0 } ;
F_38 ( & V_24 -> V_42 , F_33 , & V_32 ) ;
return V_32 . V_35 ;
}
static T_1
F_39 ( struct V_1 * V_2 ,
struct V_40 * V_41 , char * V_36 )
{
struct V_23 * V_24 = F_37 ( V_2 ) ;
int V_35 = 0 , V_20 = 0 ;
if ( V_24 -> V_43 == V_44 )
return 0 ;
for( V_20 = 0 ; V_20 < V_45 ; V_20 ++ ) {
V_35 += snprintf ( V_36 + V_35 , 20 , L_5 ,
V_24 -> V_46 [ V_20 ] ,
( ( V_20 + 1 ) & 7 ) ? ' ' : '\n' ) ;
}
return V_35 ;
}
static T_1
F_40 ( struct V_1 * V_2 ,
struct V_40 * V_41 , char * V_36 )
{
struct V_23 * V_24 = F_37 ( V_2 ) ;
int V_35 = 0 , V_20 = 0 ;
if ( V_24 -> V_43 != V_44 )
return 0 ;
for( V_20 = 0 ; V_20 < V_47 ; V_20 ++ ) {
V_35 += snprintf ( V_36 + V_35 , 20 , L_6 ,
V_24 -> V_48 [ V_20 ] ,
( ( V_20 + 1 ) & 3 ) ? ' ' : '\n' ) ;
}
if ( V_47 & 3 )
V_36 [ V_35 - 1 ] = '\n' ;
return V_35 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_42 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_41 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_28 ( V_7 ) ;
if ( ! F_42 ( V_2 ) )
return 0 ;
return & V_20 -> V_49 . V_9 == V_6 ;
}
static void F_44 ( struct V_23 * V_2 )
{
F_9 ( & V_2 -> V_12 ) ;
F_2 ( & V_2 -> V_12 ) ;
}
static void F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_24 -> V_12 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_44 ( V_24 ) ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_24 -> V_12 ;
struct V_22 * V_13 = V_24 -> V_13 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_3 = F_12 ( & V_13 -> V_12 ) ;
V_2 -> V_4 = F_41 ;
if ( F_31 ( V_13 ) )
F_13 ( V_2 , L_7 , V_11 -> V_15 , V_24 -> V_50 ) ;
else
F_13 ( V_2 , L_8 , V_11 -> V_15 , V_13 -> V_25 ) ;
F_14 ( V_2 ) ;
F_45 ( V_24 ) ;
error = F_16 ( V_2 ) ;
if ( error ) {
F_44 ( V_24 ) ;
return error ;
}
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
struct V_51 * F_46 ( void )
{
struct V_19 * V_20 ;
int V_52 ;
V_20 = F_47 ( sizeof( struct V_19 ) , V_53 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_54 . V_55 = V_56 ;
V_20 -> V_54 . V_57 = V_58 ;
V_20 -> V_54 . V_59 = V_60 ;
V_20 -> V_54 . V_8 . V_9 . V_61 = & V_20 -> V_62 [ 0 ] ;
V_20 -> V_54 . V_8 . V_9 . V_43 = & V_63 . V_43 ;
V_20 -> V_54 . V_8 . V_9 . V_64 = F_4 ;
F_48 ( & V_20 -> V_54 . V_8 ) ;
V_20 -> V_21 . V_9 . V_43 = & V_65 . V_43 ;
V_20 -> V_21 . V_9 . V_61 = & V_20 -> V_66 [ 0 ] ;
V_20 -> V_21 . V_9 . V_64 = F_27 ;
F_48 ( & V_20 -> V_21 ) ;
V_20 -> V_49 . V_9 . V_43 = & V_67 . V_43 ;
V_20 -> V_49 . V_9 . V_61 = & V_20 -> V_68 [ 0 ] ;
V_20 -> V_49 . V_9 . V_64 = F_43 ;
F_48 ( & V_20 -> V_49 ) ;
V_52 = 0 ;
F_49 ( V_69 ) ;
F_49 ( V_70 ) ;
F_49 ( V_71 ) ;
F_50 ( V_52 > V_72 ) ;
V_20 -> V_62 [ V_52 ] = NULL ;
V_52 = 0 ;
F_51 ( V_73 ) ;
F_51 ( V_74 ) ;
F_51 ( V_75 ) ;
F_50 ( V_52 > V_76 ) ;
V_20 -> V_66 [ V_52 ] = NULL ;
V_52 = 0 ;
F_52 ( V_43 ) ;
F_52 ( V_77 ) ;
F_52 ( V_78 ) ;
F_52 ( V_79 ) ;
F_52 ( V_80 ) ;
F_52 ( V_42 ) ;
F_52 ( V_46 ) ;
F_52 ( V_48 ) ;
F_50 ( V_52 > V_81 ) ;
V_20 -> V_68 [ V_52 ] = NULL ;
return & V_20 -> V_54 ;
}
void F_53 ( struct V_51 * V_54 )
{
struct V_19 * V_20 = F_28 ( V_54 ) ;
F_54 ( & V_20 -> V_54 . V_8 ) ;
F_54 ( & V_20 -> V_21 ) ;
F_54 ( & V_20 -> V_49 ) ;
F_55 ( V_20 ) ;
}
T_2 int F_56 ( void )
{
int error ;
error = F_57 ( & V_65 ) ;
if ( error )
goto V_82;
error = F_57 ( & V_63 ) ;
if ( error )
goto V_83;
error = F_57 ( & V_67 ) ;
if ( error )
goto V_84;
return 0 ;
V_84:
F_58 ( & V_63 ) ;
V_83:
F_58 ( & V_65 ) ;
V_82:
return error ;
}
void T_3 F_59 ( void )
{
F_58 ( & V_65 ) ;
F_58 ( & V_63 ) ;
F_58 ( & V_67 ) ;
}
