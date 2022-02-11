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
error = F_15 ( V_2 ) ;
if ( error ) {
goto V_16;
}
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
error = F_22 ( & V_11 -> V_13 ) ;
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
static void F_23 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_24 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_23 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = F_26 ( V_7 ) ;
if ( ! F_24 ( V_2 ) )
return 0 ;
return & V_19 -> V_20 . V_9 == V_6 ;
}
void F_6 ( struct V_21 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_12 ;
struct V_22 * V_23 ;
F_27 (ata_dev, link, ALL) {
F_28 ( V_23 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
}
int F_22 ( struct V_21 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_12 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_22 * V_23 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_3 = F_12 ( & V_11 -> V_12 ) ;
V_2 -> V_4 = F_23 ;
if ( F_29 ( V_13 ) )
F_13 ( V_2 , L_2 , V_11 -> V_15 ) ;
else
F_13 ( V_2 , L_3 , V_11 -> V_15 , V_13 -> V_24 ) ;
F_14 ( V_2 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
goto V_25;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_27 (ata_dev, link, ALL) {
error = F_30 ( V_23 ) ;
if ( error ) {
goto V_26;
}
}
return 0 ;
V_26:
while ( -- V_23 >= V_13 -> V_1 ) {
F_28 ( V_23 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
V_25:
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
return error ;
}
static int F_31 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_32 time ;
F_32 ( V_28 -> V_33 , & time ) ;
V_31 -> V_34 += sprintf ( V_31 -> V_35 + V_31 -> V_34 ,
L_4 ,
time . V_36 , time . V_37 ) ;
V_31 -> V_34 += F_33 ( V_28 -> V_38 ,
V_31 -> V_35 + V_31 -> V_34 ) ;
return 0 ;
}
static T_1
F_34 ( struct V_1 * V_2 ,
struct V_39 * V_40 , char * V_35 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
struct V_30 V_31 = { V_35 , 0 } ;
F_36 ( & V_23 -> V_41 , F_31 , & V_31 ) ;
return V_31 . V_34 ;
}
static T_1
F_37 ( struct V_1 * V_2 ,
struct V_39 * V_40 , char * V_35 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
int V_34 = 0 , V_19 = 0 ;
if ( V_23 -> V_42 == V_43 )
return 0 ;
for( V_19 = 0 ; V_19 < V_44 ; V_19 ++ ) {
V_34 += snprintf ( V_35 + V_34 , 20 , L_5 ,
V_23 -> V_45 [ V_19 ] ,
( ( V_19 + 1 ) & 7 ) ? ' ' : '\n' ) ;
}
return V_34 ;
}
static T_1
F_38 ( struct V_1 * V_2 ,
struct V_39 * V_40 , char * V_35 )
{
struct V_22 * V_23 = F_35 ( V_2 ) ;
int V_34 = 0 , V_19 = 0 ;
if ( V_23 -> V_42 != V_43 )
return 0 ;
for( V_19 = 0 ; V_19 < V_46 ; V_19 ++ ) {
V_34 += snprintf ( V_35 + V_34 , 20 , L_6 ,
V_23 -> V_47 [ V_19 ] ,
( ( V_19 + 1 ) & 3 ) ? ' ' : '\n' ) ;
}
if ( V_46 & 3 )
V_35 [ V_34 - 1 ] = '\n' ;
return V_34 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_40 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_39 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = F_26 ( V_7 ) ;
if ( ! F_40 ( V_2 ) )
return 0 ;
return & V_19 -> V_48 . V_9 == V_6 ;
}
static void F_42 ( struct V_22 * V_2 )
{
F_9 ( & V_2 -> V_12 ) ;
F_2 ( & V_2 -> V_12 ) ;
}
static void F_28 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_12 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_42 ( V_23 ) ;
}
static int F_30 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_12 ;
struct V_21 * V_13 = V_23 -> V_13 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_3 = F_12 ( & V_13 -> V_12 ) ;
V_2 -> V_4 = F_39 ;
if ( F_29 ( V_13 ) )
F_13 ( V_2 , L_7 , V_11 -> V_15 , V_23 -> V_49 ) ;
else
F_13 ( V_2 , L_8 , V_11 -> V_15 , V_13 -> V_24 ) ;
F_14 ( V_2 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
F_42 ( V_23 ) ;
return error ;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
struct V_50 * F_43 ( void )
{
struct V_18 * V_19 ;
int V_51 ;
V_19 = F_44 ( sizeof( struct V_18 ) , V_52 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_53 . V_54 = V_55 ;
V_19 -> V_53 . V_56 = V_57 ;
V_19 -> V_53 . V_58 = V_59 ;
V_19 -> V_53 . V_8 . V_9 . V_60 = & V_19 -> V_61 [ 0 ] ;
V_19 -> V_53 . V_8 . V_9 . V_42 = & V_62 . V_42 ;
V_19 -> V_53 . V_8 . V_9 . V_63 = F_4 ;
F_45 ( & V_19 -> V_53 . V_8 ) ;
V_19 -> V_20 . V_9 . V_42 = & V_64 . V_42 ;
V_19 -> V_20 . V_9 . V_60 = & V_19 -> V_65 [ 0 ] ;
V_19 -> V_20 . V_9 . V_63 = F_25 ;
F_45 ( & V_19 -> V_20 ) ;
V_19 -> V_48 . V_9 . V_42 = & V_66 . V_42 ;
V_19 -> V_48 . V_9 . V_60 = & V_19 -> V_67 [ 0 ] ;
V_19 -> V_48 . V_9 . V_63 = F_41 ;
F_45 ( & V_19 -> V_48 ) ;
V_51 = 0 ;
F_46 ( V_68 ) ;
F_46 ( V_69 ) ;
F_47 ( V_51 > V_70 ) ;
V_19 -> V_61 [ V_51 ] = NULL ;
V_51 = 0 ;
F_48 ( V_71 ) ;
F_48 ( V_72 ) ;
F_48 ( V_73 ) ;
F_47 ( V_51 > V_74 ) ;
V_19 -> V_65 [ V_51 ] = NULL ;
V_51 = 0 ;
F_49 ( V_42 ) ;
F_49 ( V_75 ) ;
F_49 ( V_76 ) ;
F_49 ( V_77 ) ;
F_49 ( V_78 ) ;
F_49 ( V_41 ) ;
F_49 ( V_45 ) ;
F_49 ( V_47 ) ;
F_47 ( V_51 > V_79 ) ;
V_19 -> V_67 [ V_51 ] = NULL ;
return & V_19 -> V_53 ;
}
void F_50 ( struct V_50 * V_53 )
{
struct V_18 * V_19 = F_26 ( V_53 ) ;
F_51 ( & V_19 -> V_53 . V_8 ) ;
F_51 ( & V_19 -> V_20 ) ;
F_51 ( & V_19 -> V_48 ) ;
F_52 ( V_19 ) ;
}
T_2 int F_53 ( void )
{
int error ;
error = F_54 ( & V_64 ) ;
if ( error )
goto V_80;
error = F_54 ( & V_62 ) ;
if ( error )
goto V_81;
error = F_54 ( & V_66 ) ;
if ( error )
goto V_82;
return 0 ;
V_82:
F_55 ( & V_62 ) ;
V_81:
F_55 ( & V_64 ) ;
V_80:
return error ;
}
void T_3 F_56 ( void )
{
F_55 ( & V_64 ) ;
F_55 ( & V_62 ) ;
F_55 ( & V_66 ) ;
}
