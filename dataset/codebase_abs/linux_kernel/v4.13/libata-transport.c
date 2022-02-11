static void F_1 ( struct V_1 * V_2 )
{
}
static int F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == F_1 ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return 0 ;
return & V_6 -> V_7 . V_8 == V_5 ;
}
void F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_11 ;
F_5 ( & V_10 -> V_12 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
}
int F_10 ( struct V_1 * V_13 ,
struct V_9 * V_10 )
{
int error ;
struct V_1 * V_2 = & V_10 -> V_11 ;
F_11 ( V_2 ) ;
V_2 -> type = & V_14 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_3 = F_1 ;
F_12 ( V_2 , L_1 , V_10 -> V_15 ) ;
F_13 ( V_2 ) ;
F_14 ( V_10 ) ;
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
error = F_22 ( & V_10 -> V_12 ) ;
if ( error ) {
goto V_17;
}
return 0 ;
V_17:
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
V_16:
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
return error ;
}
static int F_23 ( int V_18 ) { return V_18 ; }
static void F_24 ( struct V_1 * V_2 )
{
}
static int F_25 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == F_24 ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_27 ( V_6 ) ;
if ( ! F_25 ( V_2 ) )
return 0 ;
return & V_20 -> V_21 . V_8 == V_5 ;
}
void F_5 ( struct V_22 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_11 ;
struct V_23 * V_24 ;
F_28 (ata_dev, link, ALL) {
F_29 ( V_24 ) ;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
}
int F_22 ( struct V_22 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_11 ;
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_23 * V_24 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_13 = & V_10 -> V_11 ;
V_2 -> V_3 = F_24 ;
if ( F_30 ( V_12 ) )
F_12 ( V_2 , L_2 , V_10 -> V_15 ) ;
else
F_12 ( V_2 , L_3 , V_10 -> V_15 , V_12 -> V_25 ) ;
F_13 ( V_2 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
goto V_26;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_28 (ata_dev, link, ALL) {
error = F_31 ( V_24 ) ;
if ( error ) {
goto V_27;
}
}
return 0 ;
V_27:
while ( -- V_24 >= V_12 -> V_1 ) {
F_29 ( V_24 ) ;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
V_26:
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
return error ;
}
static int F_32 ( struct V_28 * V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
T_1 V_33 ;
T_2 V_34 ;
V_33 = F_33 ( V_29 -> V_35 , V_36 , & V_34 ) ;
V_32 -> V_37 += sprintf ( V_32 -> V_38 + V_32 -> V_37 ,
L_4 , V_33 ,
V_34 * V_39 / V_36 ) ;
V_32 -> V_37 += F_34 ( V_29 -> V_40 ,
V_32 -> V_38 + V_32 -> V_37 ) ;
return 0 ;
}
static T_3
F_35 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_38 )
{
struct V_23 * V_24 = F_36 ( V_2 ) ;
struct V_31 V_32 = { V_38 , 0 } ;
F_37 ( & V_24 -> V_43 , F_32 , & V_32 ) ;
return V_32 . V_37 ;
}
static T_3
F_38 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_38 )
{
struct V_23 * V_24 = F_36 ( V_2 ) ;
int V_37 = 0 , V_20 = 0 ;
if ( V_24 -> V_44 == V_45 )
return 0 ;
for( V_20 = 0 ; V_20 < V_46 ; V_20 ++ ) {
V_37 += snprintf ( V_38 + V_37 , 20 , L_5 ,
V_24 -> V_47 [ V_20 ] ,
( ( V_20 + 1 ) & 7 ) ? ' ' : '\n' ) ;
}
return V_37 ;
}
static T_3
F_39 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_38 )
{
struct V_23 * V_24 = F_36 ( V_2 ) ;
int V_37 = 0 , V_20 = 0 ;
if ( V_24 -> V_44 != V_45 )
return 0 ;
for( V_20 = 0 ; V_20 < V_48 ; V_20 ++ ) {
V_37 += snprintf ( V_38 + V_37 , 20 , L_6 ,
V_24 -> V_49 [ V_20 ] ,
( ( V_20 + 1 ) & 3 ) ? ' ' : '\n' ) ;
}
if ( V_48 & 3 )
V_38 [ V_37 - 1 ] = '\n' ;
return V_37 ;
}
static T_3
F_40 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_38 )
{
struct V_23 * V_24 = F_36 ( V_2 ) ;
unsigned char * V_50 ;
if ( ! F_41 ( V_24 -> V_47 ) )
V_50 = L_7 ;
else if ( V_24 -> V_51 & V_52 )
V_50 = L_8 ;
else if ( V_24 -> V_51 & V_53 )
V_50 = L_9 ;
else if ( F_42 ( V_24 ) )
V_50 = L_10 ;
else
V_50 = L_11 ;
return snprintf ( V_38 , 20 , L_12 , V_50 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
}
static int F_44 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == F_43 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_19 * V_20 = F_27 ( V_6 ) ;
if ( ! F_44 ( V_2 ) )
return 0 ;
return & V_20 -> V_54 . V_8 == V_5 ;
}
static void F_46 ( struct V_23 * V_2 )
{
F_8 ( & V_2 -> V_11 ) ;
F_9 ( & V_2 -> V_11 ) ;
}
static void F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_24 -> V_11 ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_46 ( V_24 ) ;
}
static int F_31 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_24 -> V_11 ;
struct V_22 * V_12 = V_24 -> V_12 ;
struct V_9 * V_10 = V_12 -> V_10 ;
int error ;
F_11 ( V_2 ) ;
V_2 -> V_13 = & V_12 -> V_11 ;
V_2 -> V_3 = F_43 ;
if ( F_30 ( V_12 ) )
F_12 ( V_2 , L_13 , V_10 -> V_15 , V_24 -> V_55 ) ;
else
F_12 ( V_2 , L_14 , V_10 -> V_15 , V_12 -> V_25 ) ;
F_13 ( V_2 ) ;
F_47 ( V_24 ) ;
error = F_15 ( V_2 ) ;
if ( error ) {
F_46 ( V_24 ) ;
return error ;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
struct V_56 * F_48 ( void )
{
struct V_19 * V_20 ;
int V_57 ;
V_20 = F_49 ( sizeof( struct V_19 ) , V_58 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_59 . V_60 = V_61 ;
V_20 -> V_59 . V_62 = V_63 ;
V_20 -> V_59 . V_7 . V_8 . V_64 = & V_20 -> V_65 [ 0 ] ;
V_20 -> V_59 . V_7 . V_8 . V_44 = & V_66 . V_44 ;
V_20 -> V_59 . V_7 . V_8 . V_67 = F_3 ;
F_50 ( & V_20 -> V_59 . V_7 ) ;
V_20 -> V_21 . V_8 . V_44 = & V_68 . V_44 ;
V_20 -> V_21 . V_8 . V_64 = & V_20 -> V_69 [ 0 ] ;
V_20 -> V_21 . V_8 . V_67 = F_26 ;
F_50 ( & V_20 -> V_21 ) ;
V_20 -> V_54 . V_8 . V_44 = & V_70 . V_44 ;
V_20 -> V_54 . V_8 . V_64 = & V_20 -> V_71 [ 0 ] ;
V_20 -> V_54 . V_8 . V_67 = F_45 ;
F_50 ( & V_20 -> V_54 ) ;
V_57 = 0 ;
F_51 ( V_72 ) ;
F_51 ( V_73 ) ;
F_51 ( V_74 ) ;
F_52 ( V_57 > V_75 ) ;
V_20 -> V_65 [ V_57 ] = NULL ;
V_57 = 0 ;
F_53 ( V_76 ) ;
F_53 ( V_77 ) ;
F_53 ( V_78 ) ;
F_52 ( V_57 > V_79 ) ;
V_20 -> V_69 [ V_57 ] = NULL ;
V_57 = 0 ;
F_54 ( V_44 ) ;
F_54 ( V_80 ) ;
F_54 ( V_81 ) ;
F_54 ( V_82 ) ;
F_54 ( V_83 ) ;
F_54 ( V_43 ) ;
F_54 ( V_47 ) ;
F_54 ( V_49 ) ;
F_54 ( V_84 ) ;
F_52 ( V_57 > V_85 ) ;
V_20 -> V_71 [ V_57 ] = NULL ;
return & V_20 -> V_59 ;
}
void F_55 ( struct V_56 * V_59 )
{
struct V_19 * V_20 = F_27 ( V_59 ) ;
F_56 ( & V_20 -> V_59 . V_7 ) ;
F_56 ( & V_20 -> V_21 ) ;
F_56 ( & V_20 -> V_54 ) ;
F_57 ( V_20 ) ;
}
T_4 int F_58 ( void )
{
int error ;
error = F_59 ( & V_68 ) ;
if ( error )
goto V_86;
error = F_59 ( & V_66 ) ;
if ( error )
goto V_87;
error = F_59 ( & V_70 ) ;
if ( error )
goto V_88;
return 0 ;
V_88:
F_60 ( & V_66 ) ;
V_87:
F_60 ( & V_68 ) ;
V_86:
return error ;
}
void T_5 F_61 ( void )
{
F_60 ( & V_68 ) ;
F_60 ( & V_66 ) ;
F_60 ( & V_70 ) ;
}
