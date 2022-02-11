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
V_21 ) ;
else
V_20 += snprintf ( V_7 -> V_14 + V_20 ,
sizeof( V_7 -> V_14 ) - V_20 , L_6 , V_11 ) ;
}
if ( ! F_9 ( V_19 , L_7 , & V_11 ) )
V_20 += snprintf ( V_7 -> V_14 + V_20 , sizeof( V_7 -> V_14 ) - V_20 ,
L_5 , V_11 & 0xffff ) ;
}
static int F_10 ( const char * V_22 , T_2 * V_23 , char * V_24 )
{
char * V_25 = strchr ( V_22 , '#' ) ;
char V_5 [ 8 ] = { 0 } ;
char * V_26 ;
T_2 V_27 ;
int V_28 ;
if ( ! V_25 )
return - V_29 ;
V_26 = strchr ( V_25 , '-' ) ;
if ( ! V_26 )
return - V_29 ;
V_27 = V_26 - V_25 - 1 ;
if ( V_27 >= sizeof( V_5 ) )
return - V_29 ;
strncpy ( V_5 , V_25 + 1 , V_27 ) ;
V_28 = F_11 ( V_5 , 10 , V_23 ) ;
if ( V_28 )
return V_28 ;
strncpy ( V_24 , V_26 + 1 , V_30 ) ;
return 0 ;
}
static const char * F_12 ( enum V_31 type ,
const char * V_32 )
{
const char * V_33 = NULL ;
if ( ! strcmp ( V_32 , V_34 ) ) {
V_33 = L_8 ;
} else if ( ! strcmp ( V_32 , V_35 ) ) {
V_33 = L_9 ;
} else if ( ! strcmp ( V_32 , V_36 ) ) {
if ( type == V_12 )
V_33 = L_10 ;
else if ( type == V_37 )
V_33 = L_11 ;
}
return V_33 ;
}
static const char * F_13 ( const char * V_38 ,
enum V_31 type , T_2 * V_23 )
{
char V_39 [ V_30 ] ;
const char * V_33 ;
int V_28 ;
V_28 = F_10 ( V_38 , V_23 , V_39 ) ;
if ( V_28 )
return F_14 ( V_28 ) ;
V_33 = F_12 ( type , V_39 ) ;
if ( ! V_33 )
return F_14 ( - V_17 ) ;
return V_33 ;
}
static int F_15 ( struct V_18 * V_19 )
{
enum V_31 type ;
const char * V_40 ;
for ( type = 0 ; type < V_41 ; type ++ ) {
if ( F_16 ( V_19 , V_42 [ type ] . V_43 ) )
return type ;
}
if ( ! F_16 ( V_19 , L_12 ) )
return V_41 ;
if ( F_17 ( V_19 , L_13 , & V_40 ) )
return V_41 ;
for ( type = 0 ; type < V_41 ; type ++ )
if ( ! strcmp ( V_40 , V_42 [ type ] . V_22 ) )
return type ;
return V_41 ;
}
static T_2 F_18 ( struct V_6 * V_7 ,
struct V_6 * V_44 , int V_45 )
{
int V_46 ;
if ( V_7 -> V_47 != V_48 ) {
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ )
if ( V_44 [ V_46 ] . V_47 == V_7 -> V_47 &&
V_44 [ V_46 ] . type == V_7 -> type )
return V_44 [ V_46 ] . V_49 ;
}
return ++ V_42 [ V_7 -> type ] . V_49 ;
}
static int F_19 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_20 ( V_51 ) ;
const struct V_54 * * V_55 = V_53 -> V_56 ;
struct V_18 * V_57 , * V_19 ;
enum V_31 type ;
V_57 = F_21 ( L_14 ) ;
F_22 (opal, np) {
const char * V_14 ;
if ( V_19 -> V_22 == NULL )
continue;
type = F_15 ( V_19 ) ;
if ( type == V_41 )
continue;
V_42 [ type ] . V_58 ++ ;
if ( ! F_17 ( V_19 , L_15 , & V_14 ) )
V_42 [ type ] . V_58 ++ ;
}
F_23 ( V_57 ) ;
for ( type = 0 ; type < V_41 ; type ++ ) {
V_42 [ type ] . V_59 . V_60 = F_24 ( & V_51 -> V_2 ,
sizeof( struct V_61 * ) *
( V_42 [ type ] . V_58 + 1 ) ,
V_62 ) ;
if ( ! V_42 [ type ] . V_59 . V_60 )
return - V_63 ;
V_55 [ type ] = & V_42 [ type ] . V_59 ;
V_53 -> V_64 += V_42 [ type ] . V_58 ;
V_42 [ type ] . V_58 = 0 ;
}
return 0 ;
}
static void F_25 ( struct V_6 * V_7 , const char * V_33 ,
T_1 (* F_26)( struct V_1 * V_2 ,
struct V_3 * V_24 ,
char * V_5 ) )
{
snprintf ( V_7 -> V_22 , V_30 , L_16 ,
V_42 [ V_7 -> type ] . V_22 , V_7 -> V_49 ,
V_33 ) ;
F_27 ( & V_7 -> V_8 . V_24 ) ;
V_7 -> V_8 . V_24 . V_22 = V_7 -> V_22 ;
V_7 -> V_8 . V_24 . V_65 = V_66 ;
V_7 -> V_8 . F_26 = F_26 ;
}
static int F_28 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_20 ( V_51 ) ;
const struct V_54 * * V_55 = V_53 -> V_56 ;
struct V_18 * V_57 , * V_19 ;
struct V_6 * V_7 ;
T_2 V_67 ;
enum V_31 type ;
T_2 V_45 = 0 ;
int V_28 = 0 ;
V_57 = F_21 ( L_14 ) ;
V_7 = F_24 ( & V_51 -> V_2 , V_53 -> V_64 * sizeof( * V_7 ) ,
V_62 ) ;
if ( ! V_7 ) {
V_28 = - V_63 ;
goto V_68;
}
F_22 (opal, np) {
const char * V_33 ;
T_2 V_47 ;
const char * V_14 ;
if ( V_19 -> V_22 == NULL )
continue;
type = F_15 ( V_19 ) ;
if ( type == V_41 )
continue;
if ( F_9 ( V_19 , L_17 , & V_67 ) &&
F_9 ( V_19 , L_18 , & V_67 ) ) {
F_29 ( & V_51 -> V_2 ,
L_19 ,
V_19 -> V_22 ) ;
continue;
}
V_7 [ V_45 ] . V_11 = V_67 ;
V_7 [ V_45 ] . type = type ;
V_33 = F_13 ( V_19 -> V_22 , type , & V_47 ) ;
if ( F_30 ( V_33 ) ) {
V_33 = L_9 ;
V_47 = V_48 ;
}
V_7 [ V_45 ] . V_47 = V_47 ;
V_7 [ V_45 ] . V_49 =
F_18 ( & V_7 [ V_45 ] , V_7 , V_45 ) ;
F_25 ( & V_7 [ V_45 ] , V_33 , F_1 ) ;
V_55 [ type ] -> V_60 [ V_42 [ type ] . V_58 ++ ] =
& V_7 [ V_45 ++ ] . V_8 . V_24 ;
if ( ! F_17 ( V_19 , L_15 , & V_14 ) ) {
V_7 [ V_45 ] . type = type ;
V_7 [ V_45 ] . V_47 = V_7 [ V_45 - 1 ] . V_47 ;
V_7 [ V_45 ] . V_49 = V_7 [ V_45 - 1 ] . V_49 ;
F_8 ( V_19 , & V_7 [ V_45 ] , V_14 ) ;
F_25 ( & V_7 [ V_45 ] , L_15 , F_4 ) ;
V_55 [ type ] -> V_60 [ V_42 [ type ] . V_58 ++ ] =
& V_7 [ V_45 ++ ] . V_8 . V_24 ;
}
}
V_68:
F_23 ( V_57 ) ;
return V_28 ;
}
static int F_31 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_1 * V_69 ;
int V_28 ;
V_53 = F_24 ( & V_51 -> V_2 , sizeof( * V_53 ) , V_62 ) ;
if ( ! V_53 )
return - V_63 ;
F_32 ( V_51 , V_53 ) ;
V_53 -> V_64 = 0 ;
V_28 = F_19 ( V_51 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_28 ( V_51 ) ;
if ( V_28 )
return V_28 ;
V_69 = F_33 ( & V_51 -> V_2 , V_70 ,
V_53 ,
V_53 -> V_56 ) ;
return F_34 ( V_69 ) ;
}
