static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
int F_3 ( const struct V_1 * V_2 )
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
V_2 -> V_3 = F_12 ( V_3 ) ;
V_2 -> V_4 = F_1 ;
F_13 ( V_2 , L_1 , V_11 -> V_14 ) ;
F_14 ( V_2 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
goto V_15;
}
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
error = F_18 ( & V_11 -> V_13 ) ;
if ( error ) {
goto V_16;
}
return 0 ;
V_16:
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
V_15:
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
return error ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
int F_20 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_19 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 = F_22 ( V_7 ) ;
if ( ! F_20 ( V_2 ) )
return 0 ;
return & V_18 -> V_19 . V_9 == V_6 ;
}
void F_6 ( struct V_20 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_12 ;
struct V_21 * V_22 ;
F_23 (ata_dev, link, ALL) {
F_24 ( V_22 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
}
int F_18 ( struct V_20 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_12 ;
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_21 * V_22 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_3 = F_12 ( & V_11 -> V_12 ) ;
V_2 -> V_4 = F_19 ;
if ( F_25 ( V_13 ) )
F_13 ( V_2 , L_2 , V_11 -> V_14 ) ;
else
F_13 ( V_2 , L_3 , V_11 -> V_14 , V_13 -> V_23 ) ;
F_14 ( V_2 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
goto V_24;
}
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_23 (ata_dev, link, ALL) {
error = F_26 ( V_22 ) ;
if ( error ) {
goto V_25;
}
}
return 0 ;
V_25:
while ( -- V_22 >= V_13 -> V_1 ) {
F_24 ( V_22 ) ;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
V_24:
F_9 ( V_2 ) ;
F_2 ( V_2 ) ;
return error ;
}
static int F_27 ( struct V_26 * V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_31 time ;
F_28 ( V_27 -> V_32 , & time ) ;
V_30 -> V_33 += sprintf ( V_30 -> V_34 + V_30 -> V_33 ,
L_4 ,
time . V_35 , time . V_36 ) ;
V_30 -> V_33 += F_29 ( V_27 -> V_37 ,
V_30 -> V_34 + V_30 -> V_33 ) ;
return 0 ;
}
static T_1
F_30 ( struct V_1 * V_2 ,
struct V_38 * V_39 , char * V_34 )
{
struct V_21 * V_22 = F_31 ( V_2 ) ;
struct V_29 V_30 = { V_34 , 0 } ;
F_32 ( & V_22 -> V_40 , F_27 , & V_30 ) ;
return V_30 . V_33 ;
}
static T_1
F_33 ( struct V_1 * V_2 ,
struct V_38 * V_39 , char * V_34 )
{
struct V_21 * V_22 = F_31 ( V_2 ) ;
int V_33 = 0 , V_18 = 0 ;
if ( V_22 -> V_41 == V_42 )
return 0 ;
for( V_18 = 0 ; V_18 < V_43 ; V_18 ++ ) {
V_33 += snprintf ( V_34 + V_33 , 20 , L_5 ,
V_22 -> V_44 [ V_18 ] ,
( ( V_18 + 1 ) & 7 ) ? ' ' : '\n' ) ;
}
return V_33 ;
}
static T_1
F_34 ( struct V_1 * V_2 ,
struct V_38 * V_39 , char * V_34 )
{
struct V_21 * V_22 = F_31 ( V_2 ) ;
int V_33 = 0 , V_18 = 0 ;
if ( V_22 -> V_41 != V_42 )
return 0 ;
for( V_18 = 0 ; V_18 < V_45 ; V_18 ++ ) {
V_33 += snprintf ( V_34 + V_33 , 20 , L_6 ,
V_22 -> V_46 [ V_18 ] ,
( ( V_18 + 1 ) & 3 ) ? ' ' : '\n' ) ;
}
if ( V_45 & 3 )
V_34 [ V_33 - 1 ] = '\n' ;
return V_33 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
int F_36 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 == F_35 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 = F_22 ( V_7 ) ;
if ( ! F_36 ( V_2 ) )
return 0 ;
return & V_18 -> V_47 . V_9 == V_6 ;
}
static void F_38 ( struct V_21 * V_2 )
{
F_9 ( & V_2 -> V_12 ) ;
F_2 ( & V_2 -> V_12 ) ;
}
static void F_24 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = & V_22 -> V_12 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_38 ( V_22 ) ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = & V_22 -> V_12 ;
struct V_20 * V_13 = V_22 -> V_13 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_3 = F_12 ( & V_13 -> V_12 ) ;
V_2 -> V_4 = F_35 ;
if ( F_25 ( V_13 ) )
F_13 ( V_2 , L_7 , V_11 -> V_14 , V_22 -> V_48 ) ;
else
F_13 ( V_2 , L_8 , V_11 -> V_14 , V_13 -> V_23 ) ;
F_14 ( V_2 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
F_38 ( V_22 ) ;
return error ;
}
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
struct V_49 * F_39 ( void )
{
struct V_17 * V_18 ;
int V_50 ;
V_18 = F_40 ( sizeof( struct V_17 ) , V_51 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_52 . V_53 = V_54 ;
V_18 -> V_52 . V_55 = V_56 ;
V_18 -> V_52 . V_57 = V_58 ;
V_18 -> V_52 . V_8 . V_9 . V_59 = & V_18 -> V_60 [ 0 ] ;
V_18 -> V_52 . V_8 . V_9 . V_41 = & V_61 . V_41 ;
V_18 -> V_52 . V_8 . V_9 . V_62 = F_4 ;
F_41 ( & V_18 -> V_52 . V_8 ) ;
V_18 -> V_19 . V_9 . V_41 = & V_63 . V_41 ;
V_18 -> V_19 . V_9 . V_59 = & V_18 -> V_64 [ 0 ] ;
V_18 -> V_19 . V_9 . V_62 = F_21 ;
F_41 ( & V_18 -> V_19 ) ;
V_18 -> V_47 . V_9 . V_41 = & V_65 . V_41 ;
V_18 -> V_47 . V_9 . V_59 = & V_18 -> V_66 [ 0 ] ;
V_18 -> V_47 . V_9 . V_62 = F_37 ;
F_41 ( & V_18 -> V_47 ) ;
V_50 = 0 ;
F_42 ( V_67 ) ;
F_42 ( V_68 ) ;
F_43 ( V_50 > V_69 ) ;
V_18 -> V_60 [ V_50 ] = NULL ;
V_50 = 0 ;
F_44 ( V_70 ) ;
F_44 ( V_71 ) ;
F_44 ( V_72 ) ;
F_43 ( V_50 > V_73 ) ;
V_18 -> V_64 [ V_50 ] = NULL ;
V_50 = 0 ;
F_45 ( V_41 ) ;
F_45 ( V_74 ) ;
F_45 ( V_75 ) ;
F_45 ( V_76 ) ;
F_45 ( V_77 ) ;
F_45 ( V_40 ) ;
F_45 ( V_44 ) ;
F_45 ( V_46 ) ;
F_43 ( V_50 > V_78 ) ;
V_18 -> V_66 [ V_50 ] = NULL ;
return & V_18 -> V_52 ;
}
void F_46 ( struct V_49 * V_52 )
{
struct V_17 * V_18 = F_22 ( V_52 ) ;
F_47 ( & V_18 -> V_52 . V_8 ) ;
F_47 ( & V_18 -> V_19 ) ;
F_47 ( & V_18 -> V_47 ) ;
F_48 ( V_18 ) ;
}
T_2 int F_49 ( void )
{
int error ;
error = F_50 ( & V_63 ) ;
if ( error )
goto V_79;
error = F_50 ( & V_61 ) ;
if ( error )
goto V_80;
error = F_50 ( & V_65 ) ;
if ( error )
goto V_81;
return 0 ;
V_81:
F_51 ( & V_61 ) ;
V_80:
F_51 ( & V_63 ) ;
V_79:
return error ;
}
void T_3 F_52 ( void )
{
F_51 ( & V_63 ) ;
F_51 ( & V_61 ) ;
F_51 ( & V_65 ) ;
}
