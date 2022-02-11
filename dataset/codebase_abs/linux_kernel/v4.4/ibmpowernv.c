static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 , struct V_6 ,
V_8 ) ;
T_1 V_9 ;
T_2 V_10 ;
V_9 = F_3 ( V_7 -> V_11 , & V_10 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> type == V_12 )
V_10 *= 1000 ;
else if ( V_7 -> type == V_13 )
V_10 *= 1000000 ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_14 ) ;
}
static int T_3 F_5 ( int V_15 )
{
int V_16 ;
F_6 (cpu)
if ( F_7 ( V_16 ) == V_15 )
return V_16 ;
return - V_17 ;
}
static void T_3 F_8 ( struct V_18 * V_19 ,
struct V_6 * V_7 ,
const char * V_14 )
{
T_2 V_11 ;
T_4 V_20 ;
V_20 = snprintf ( V_7 -> V_14 , sizeof( V_7 -> V_14 ) , L_3 , V_14 ) ;
if ( ! F_9 ( V_19 , L_4 , & V_11 ) ) {
int V_21 = F_5 ( V_11 ) ;
if ( V_21 >= 0 )
V_20 += snprintf ( V_7 -> V_14 + V_20 ,
sizeof( V_7 -> V_14 ) - V_20 , L_5 ,
V_21 , V_21 + V_22 - 1 ) ;
else
V_20 += snprintf ( V_7 -> V_14 + V_20 ,
sizeof( V_7 -> V_14 ) - V_20 , L_6 , V_11 ) ;
}
if ( ! F_9 ( V_19 , L_7 , & V_11 ) )
V_20 += snprintf ( V_7 -> V_14 + V_20 , sizeof( V_7 -> V_14 ) - V_20 ,
L_8 , V_11 & 0xffff ) ;
}
static int F_10 ( const char * V_23 , T_2 * V_24 , char * V_25 )
{
char * V_26 = strchr ( V_23 , '#' ) ;
char V_5 [ 8 ] = { 0 } ;
char * V_27 ;
T_2 V_28 ;
int V_29 ;
if ( ! V_26 )
return - V_30 ;
V_27 = strchr ( V_26 , '-' ) ;
if ( ! V_27 )
return - V_30 ;
V_28 = V_27 - V_26 - 1 ;
if ( V_28 >= sizeof( V_5 ) )
return - V_30 ;
strncpy ( V_5 , V_26 + 1 , V_28 ) ;
V_29 = F_11 ( V_5 , 10 , V_24 ) ;
if ( V_29 )
return V_29 ;
strncpy ( V_25 , V_27 + 1 , V_31 ) ;
return 0 ;
}
static const char * F_12 ( enum V_32 type ,
const char * V_33 )
{
const char * V_34 = NULL ;
if ( ! strcmp ( V_33 , V_35 ) ) {
V_34 = L_9 ;
} else if ( ! strcmp ( V_33 , V_36 ) ) {
V_34 = L_10 ;
} else if ( ! strcmp ( V_33 , V_37 ) ) {
if ( type == V_12 )
V_34 = L_11 ;
else if ( type == V_38 )
V_34 = L_12 ;
}
return V_34 ;
}
static const char * F_13 ( const char * V_39 ,
enum V_32 type , T_2 * V_24 )
{
char V_40 [ V_31 ] ;
const char * V_34 ;
int V_29 ;
V_29 = F_10 ( V_39 , V_24 , V_40 ) ;
if ( V_29 )
return F_14 ( V_29 ) ;
V_34 = F_12 ( type , V_40 ) ;
if ( ! V_34 )
return F_14 ( - V_17 ) ;
return V_34 ;
}
static int F_15 ( struct V_18 * V_19 )
{
enum V_32 type ;
const char * V_41 ;
for ( type = 0 ; type < V_42 ; type ++ ) {
if ( F_16 ( V_19 , V_43 [ type ] . V_44 ) )
return type ;
}
if ( ! F_16 ( V_19 , L_13 ) )
return V_42 ;
if ( F_17 ( V_19 , L_14 , & V_41 ) )
return V_42 ;
for ( type = 0 ; type < V_42 ; type ++ )
if ( ! strcmp ( V_41 , V_43 [ type ] . V_23 ) )
return type ;
return V_42 ;
}
static T_2 F_18 ( struct V_6 * V_7 ,
struct V_6 * V_45 , int V_46 )
{
int V_47 ;
if ( V_7 -> V_48 != V_49 ) {
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ )
if ( V_45 [ V_47 ] . V_48 == V_7 -> V_48 &&
V_45 [ V_47 ] . type == V_7 -> type )
return V_45 [ V_47 ] . V_50 ;
}
return ++ V_43 [ V_7 -> type ] . V_50 ;
}
static int F_19 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_20 ( V_52 ) ;
const struct V_55 * * V_56 = V_54 -> V_57 ;
struct V_18 * V_58 , * V_19 ;
enum V_32 type ;
V_58 = F_21 ( L_15 ) ;
F_22 (opal, np) {
const char * V_14 ;
if ( V_19 -> V_23 == NULL )
continue;
type = F_15 ( V_19 ) ;
if ( type == V_42 )
continue;
V_43 [ type ] . V_59 ++ ;
if ( ! F_17 ( V_19 , L_16 , & V_14 ) )
V_43 [ type ] . V_59 ++ ;
}
F_23 ( V_58 ) ;
for ( type = 0 ; type < V_42 ; type ++ ) {
V_43 [ type ] . V_60 . V_61 = F_24 ( & V_52 -> V_2 ,
sizeof( struct V_62 * ) *
( V_43 [ type ] . V_59 + 1 ) ,
V_63 ) ;
if ( ! V_43 [ type ] . V_60 . V_61 )
return - V_64 ;
V_56 [ type ] = & V_43 [ type ] . V_60 ;
V_54 -> V_65 += V_43 [ type ] . V_59 ;
V_43 [ type ] . V_59 = 0 ;
}
return 0 ;
}
static void F_25 ( struct V_6 * V_7 , const char * V_34 ,
T_1 (* F_26)( struct V_1 * V_2 ,
struct V_3 * V_25 ,
char * V_5 ) )
{
snprintf ( V_7 -> V_23 , V_31 , L_17 ,
V_43 [ V_7 -> type ] . V_23 , V_7 -> V_50 ,
V_34 ) ;
F_27 ( & V_7 -> V_8 . V_25 ) ;
V_7 -> V_8 . V_25 . V_23 = V_7 -> V_23 ;
V_7 -> V_8 . V_25 . V_66 = V_67 ;
V_7 -> V_8 . F_26 = F_26 ;
}
static int F_28 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_20 ( V_52 ) ;
const struct V_55 * * V_56 = V_54 -> V_57 ;
struct V_18 * V_58 , * V_19 ;
struct V_6 * V_7 ;
T_2 V_68 ;
enum V_32 type ;
T_2 V_46 = 0 ;
int V_29 = 0 ;
V_58 = F_21 ( L_15 ) ;
V_7 = F_24 ( & V_52 -> V_2 , V_54 -> V_65 * sizeof( * V_7 ) ,
V_63 ) ;
if ( ! V_7 ) {
V_29 = - V_64 ;
goto V_69;
}
F_22 (opal, np) {
const char * V_34 ;
T_2 V_48 ;
const char * V_14 ;
if ( V_19 -> V_23 == NULL )
continue;
type = F_15 ( V_19 ) ;
if ( type == V_42 )
continue;
if ( F_9 ( V_19 , L_18 , & V_68 ) &&
F_9 ( V_19 , L_19 , & V_68 ) ) {
F_29 ( & V_52 -> V_2 ,
L_20 ,
V_19 -> V_23 ) ;
continue;
}
V_7 [ V_46 ] . V_11 = V_68 ;
V_7 [ V_46 ] . type = type ;
V_34 = F_13 ( V_19 -> V_23 , type , & V_48 ) ;
if ( F_30 ( V_34 ) ) {
V_34 = L_10 ;
V_48 = V_49 ;
}
V_7 [ V_46 ] . V_48 = V_48 ;
V_7 [ V_46 ] . V_50 =
F_18 ( & V_7 [ V_46 ] , V_7 , V_46 ) ;
F_25 ( & V_7 [ V_46 ] , V_34 , F_1 ) ;
V_56 [ type ] -> V_61 [ V_43 [ type ] . V_59 ++ ] =
& V_7 [ V_46 ++ ] . V_8 . V_25 ;
if ( ! F_17 ( V_19 , L_16 , & V_14 ) ) {
V_7 [ V_46 ] . type = type ;
V_7 [ V_46 ] . V_48 = V_7 [ V_46 - 1 ] . V_48 ;
V_7 [ V_46 ] . V_50 = V_7 [ V_46 - 1 ] . V_50 ;
F_8 ( V_19 , & V_7 [ V_46 ] , V_14 ) ;
F_25 ( & V_7 [ V_46 ] , L_16 , F_4 ) ;
V_56 [ type ] -> V_61 [ V_43 [ type ] . V_59 ++ ] =
& V_7 [ V_46 ++ ] . V_8 . V_25 ;
}
}
V_69:
F_23 ( V_58 ) ;
return V_29 ;
}
static int F_31 ( struct V_51 * V_52 )
{
struct V_53 * V_54 ;
struct V_1 * V_70 ;
int V_29 ;
V_54 = F_24 ( & V_52 -> V_2 , sizeof( * V_54 ) , V_63 ) ;
if ( ! V_54 )
return - V_64 ;
F_32 ( V_52 , V_54 ) ;
V_54 -> V_65 = 0 ;
V_29 = F_19 ( V_52 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_28 ( V_52 ) ;
if ( V_29 )
return V_29 ;
V_70 = F_33 ( & V_52 -> V_2 , V_71 ,
V_54 ,
V_54 -> V_57 ) ;
return F_34 ( V_70 ) ;
}
