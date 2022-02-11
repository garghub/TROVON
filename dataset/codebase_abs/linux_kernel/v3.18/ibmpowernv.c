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
static int T_3 F_4 ( const char * V_14 , T_2 * V_15 ,
char * V_16 )
{
char * V_17 = strchr ( V_14 , '#' ) ;
char V_5 [ 8 ] = { 0 } ;
char * V_18 ;
T_2 V_19 ;
int V_20 ;
if ( ! V_17 )
return - V_21 ;
V_18 = strchr ( V_17 , '-' ) ;
if ( ! V_18 )
return - V_21 ;
V_19 = V_18 - V_17 - 1 ;
if ( V_19 >= sizeof( V_5 ) )
return - V_21 ;
strncpy ( V_5 , V_17 + 1 , V_19 ) ;
V_20 = F_5 ( V_5 , 10 , V_15 ) ;
if ( V_20 )
return V_20 ;
strncpy ( V_16 , V_18 + 1 , V_22 ) ;
return 0 ;
}
static int T_3 F_6 ( struct V_1 * V_2 , enum V_23 type ,
const char * V_24 ,
char * V_25 )
{
char V_26 [ V_22 ] ;
char * V_27 ;
T_2 V_15 ;
int V_20 ;
V_20 = F_4 ( V_24 , & V_15 , V_26 ) ;
if ( V_20 ) {
F_7 ( V_2 , L_2 ,
V_24 ) ;
return V_20 ;
}
if ( ! strcmp ( V_26 , V_28 ) ) {
V_27 = L_3 ;
} else if ( ! strcmp ( V_26 , V_29 ) ) {
V_27 = L_4 ;
} else if ( ! strcmp ( V_26 , V_30 ) ) {
if ( type == V_12 )
V_27 = L_5 ;
else if ( type == V_31 )
V_27 = L_6 ;
else
return - V_32 ;
} else {
return - V_32 ;
}
snprintf ( V_25 , V_22 , L_7 ,
V_33 [ type ] . V_14 , V_15 , V_27 ) ;
return 0 ;
}
static int T_3 F_8 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_9 ( V_35 ) ;
const struct V_38 * * V_39 = V_37 -> V_40 ;
struct V_41 * V_42 , * V_43 ;
enum V_23 type ;
V_42 = F_10 ( L_8 ) ;
if ( ! V_42 ) {
F_11 ( & V_35 -> V_2 , L_9 ) ;
return - V_44 ;
}
F_12 (opal, np) {
if ( V_43 -> V_14 == NULL )
continue;
for ( type = 0 ; type < V_45 ; type ++ )
if ( F_13 ( V_43 ,
V_33 [ type ] . V_46 ) ) {
V_33 [ type ] . V_47 ++ ;
break;
}
}
F_14 ( V_42 ) ;
for ( type = 0 ; type < V_45 ; type ++ ) {
V_33 [ type ] . V_48 . V_49 = F_15 ( & V_35 -> V_2 ,
sizeof( struct V_50 * ) *
( V_33 [ type ] . V_47 + 1 ) ,
V_51 ) ;
if ( ! V_33 [ type ] . V_48 . V_49 )
return - V_52 ;
V_39 [ type ] = & V_33 [ type ] . V_48 ;
V_37 -> V_53 += V_33 [ type ] . V_47 ;
V_33 [ type ] . V_47 = 0 ;
}
return 0 ;
}
static int T_3 F_16 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_9 ( V_35 ) ;
const struct V_38 * * V_39 = V_37 -> V_40 ;
struct V_41 * V_42 , * V_43 ;
struct V_6 * V_7 ;
T_2 V_54 ;
enum V_23 type ;
T_2 V_55 = 0 ;
int V_20 = 0 ;
V_42 = F_10 ( L_8 ) ;
V_7 = F_15 ( & V_35 -> V_2 , V_37 -> V_53 * sizeof( * V_7 ) ,
V_51 ) ;
if ( ! V_7 ) {
V_20 = - V_52 ;
goto V_56;
}
F_12 (opal, np) {
if ( V_43 -> V_14 == NULL )
continue;
for ( type = 0 ; type < V_45 ; type ++ )
if ( F_13 ( V_43 ,
V_33 [ type ] . V_46 ) )
break;
if ( type == V_45 )
continue;
if ( F_17 ( V_43 , L_10 , & V_54 ) ) {
F_18 ( & V_35 -> V_2 ,
L_11 ,
V_43 -> V_14 ) ;
continue;
}
V_7 [ V_55 ] . V_11 = V_54 ;
V_7 [ V_55 ] . type = type ;
V_20 = F_6 ( & V_35 -> V_2 , type , V_43 -> V_14 ,
V_7 [ V_55 ] . V_14 ) ;
if ( V_20 )
goto V_56;
F_19 ( & V_7 [ V_55 ] . V_8 . V_16 ) ;
V_7 [ V_55 ] . V_8 . V_16 . V_14 = V_7 [ V_55 ] . V_14 ;
V_7 [ V_55 ] . V_8 . V_16 . V_57 = V_58 ;
V_7 [ V_55 ] . V_8 . V_59 = F_1 ;
V_39 [ type ] -> V_49 [ V_33 [ type ] . V_47 ++ ] =
& V_7 [ V_55 ++ ] . V_8 . V_16 ;
}
V_56:
F_14 ( V_42 ) ;
return V_20 ;
}
static int T_3 F_20 ( struct V_34 * V_35 )
{
struct V_36 * V_37 ;
struct V_1 * V_60 ;
int V_20 ;
V_37 = F_15 ( & V_35 -> V_2 , sizeof( * V_37 ) , V_51 ) ;
if ( ! V_37 )
return - V_52 ;
F_21 ( V_35 , V_37 ) ;
V_37 -> V_53 = 0 ;
V_20 = F_8 ( V_35 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_16 ( V_35 ) ;
if ( V_20 )
return V_20 ;
V_60 = F_22 ( & V_35 -> V_2 , V_61 ,
V_37 ,
V_37 -> V_40 ) ;
return F_23 ( V_60 ) ;
}
static int T_3 F_24 ( void )
{
int V_20 ;
V_62 = F_25 ( V_61 , 0 ) ;
if ( ! V_62 ) {
F_26 ( L_12 ) ;
V_20 = - V_52 ;
goto exit;
}
V_20 = F_27 ( V_62 ) ;
if ( V_20 ) {
F_26 ( L_13 , V_20 ) ;
goto V_63;
}
V_20 = F_28 ( & V_64 , F_20 ) ;
if ( V_20 ) {
if ( V_20 != - V_44 )
F_26 ( L_14 , V_20 ) ;
goto V_65;
}
return 0 ;
V_65:
F_29 ( V_62 ) ;
V_63:
F_30 ( V_62 ) ;
exit:
return V_20 ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_64 ) ;
F_33 ( V_62 ) ;
}
