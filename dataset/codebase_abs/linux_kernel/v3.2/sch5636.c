static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 ;
int V_6 , V_7 ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_9 && ! F_4 ( V_10 , V_4 -> V_11 + V_12 ) )
goto abort;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
V_7 = F_5 ( V_4 -> V_14 ,
V_15 [ V_6 ] ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_5 = F_7 ( V_7 ) ;
goto abort;
}
V_4 -> V_16 [ V_6 ] = V_7 ;
}
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
if ( V_4 -> V_18 [ V_6 ] & V_19 )
continue;
V_7 = F_5 ( V_4 -> V_14 ,
V_20 [ V_6 ] ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_5 = F_7 ( V_7 ) ;
goto abort;
}
V_4 -> V_21 [ V_6 ] = V_7 ;
V_7 = F_5 ( V_4 -> V_14 ,
F_8 ( V_6 ) ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_5 = F_7 ( V_7 ) ;
goto abort;
}
V_4 -> V_18 [ V_6 ] = V_7 ;
if ( V_7 & V_22 ) {
F_9 ( V_4 -> V_14 ,
F_8 ( V_6 ) , V_7 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
if ( V_4 -> V_24 [ V_6 ] & V_25 )
continue;
V_7 = F_10 ( V_4 -> V_14 ,
V_26 [ V_6 ] ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_5 = F_7 ( V_7 ) ;
goto abort;
}
V_4 -> V_27 [ V_6 ] = V_7 ;
V_7 = F_5 ( V_4 -> V_14 ,
F_11 ( V_6 ) ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_5 = F_7 ( V_7 ) ;
goto abort;
}
V_4 -> V_24 [ V_6 ] = V_7 ;
if ( V_7 & V_28 ) {
F_9 ( V_4 -> V_14 ,
F_11 ( V_6 ) , V_7 ) ;
}
}
V_4 -> V_11 = V_10 ;
V_4 -> V_9 = 1 ;
abort:
F_12 ( & V_4 -> V_8 ) ;
return V_5 ;
}
static int F_13 ( T_1 V_29 )
{
if ( V_29 == 0 )
return - V_30 ;
if ( V_29 == 0xffff )
return 0 ;
return 5400540 / V_29 ;
}
static T_2 F_14 ( struct V_2 * V_3 , struct V_31 * V_32 ,
char * V_33 )
{
return snprintf ( V_33 , V_34 , L_1 , V_35 ) ;
}
static T_2 F_15 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = F_19 (
V_4 -> V_16 [ V_37 -> V_38 ] * V_39 [ V_37 -> V_38 ] ,
255 ) ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static T_2 F_20 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
return snprintf ( V_33 , V_34 , L_1 ,
V_40 [ V_37 -> V_38 ] ) ;
}
static T_2 F_21 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = ( V_4 -> V_21 [ V_37 -> V_38 ] - 64 ) * 1000 ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static T_2 F_22 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = ( V_4 -> V_18 [ V_37 -> V_38 ] & V_41 ) ? 0 : 1 ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static T_2 F_23 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = ( V_4 -> V_18 [ V_37 -> V_38 ] & V_22 ) ? 1 : 0 ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static T_2 F_24 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = F_13 ( V_4 -> V_27 [ V_37 -> V_38 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static T_2 F_25 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = ( V_4 -> V_24 [ V_37 -> V_38 ] & V_42 ) ? 1 : 0 ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static T_2 F_26 ( struct V_2 * V_3 , struct V_31
* V_32 , char * V_33 )
{
struct V_36 * V_37 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = ( V_4 -> V_24 [ V_37 -> V_38 ] & V_28 ) ? 1 : 0 ;
return snprintf ( V_33 , V_34 , L_2 , V_7 ) ;
}
static int F_27 ( struct V_43 * V_44 )
{
struct V_1 * V_4 = F_28 ( V_44 ) ;
int V_6 ;
if ( V_4 -> V_45 )
F_29 ( V_4 -> V_45 ) ;
for ( V_6 = 0 ; V_6 < F_30 ( V_46 ) ; V_6 ++ )
F_31 ( & V_44 -> V_3 , & V_46 [ V_6 ] . V_47 ) ;
for ( V_6 = 0 ; V_6 < V_17 * 3 ; V_6 ++ )
F_31 ( & V_44 -> V_3 ,
& V_48 [ V_6 ] . V_47 ) ;
for ( V_6 = 0 ; V_6 < V_23 * 3 ; V_6 ++ )
F_31 ( & V_44 -> V_3 ,
& V_49 [ V_6 ] . V_47 ) ;
F_32 ( V_44 , NULL ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static int T_3 F_34 ( struct V_43 * V_44 )
{
struct V_1 * V_4 ;
int V_6 , V_50 , V_7 , V_51 [ 2 ] ;
char V_52 [ 4 ] ;
V_4 = F_35 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_4 -> V_14 = F_36 ( V_44 , V_55 , 0 ) -> V_56 ;
F_37 ( & V_4 -> V_8 ) ;
F_32 ( V_44 , V_4 ) ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
V_7 = F_5 ( V_4 -> V_14 ,
V_57 + V_6 ) ;
if ( V_7 < 0 ) {
F_38 ( L_3 ,
V_57 + V_6 ) ;
V_50 = V_7 ;
goto error;
}
V_52 [ V_6 ] = V_7 ;
}
V_52 [ V_6 ] = '\0' ;
if ( strcmp ( V_52 , L_4 ) ) {
F_38 ( L_5 ,
V_52 [ 0 ] , V_52 [ 1 ] , V_52 [ 2 ] ) ;
V_50 = - V_58 ;
goto error;
}
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_7 = F_5 ( V_4 -> V_14 ,
V_59 + V_6 ) ;
if ( V_7 < 0 ) {
V_50 = V_7 ;
goto error;
}
V_51 [ V_6 ] = V_7 ;
}
F_39 ( L_6 , V_35 ,
V_4 -> V_14 , V_51 [ 0 ] , V_51 [ 1 ] ) ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
V_7 = F_5 ( V_4 -> V_14 ,
F_8 ( V_6 ) ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_50 = V_7 ;
goto error;
}
V_4 -> V_18 [ V_6 ] = V_7 ;
}
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ ) {
V_7 = F_5 ( V_4 -> V_14 ,
F_11 ( V_6 ) ) ;
if ( F_6 ( V_7 < 0 ) ) {
V_50 = V_7 ;
goto error;
}
V_4 -> V_24 [ V_6 ] = V_7 ;
}
for ( V_6 = 0 ; V_6 < F_30 ( V_46 ) ; V_6 ++ ) {
V_50 = F_40 ( & V_44 -> V_3 ,
& V_46 [ V_6 ] . V_47 ) ;
if ( V_50 )
goto error;
}
for ( V_6 = 0 ; V_6 < ( V_17 * 3 ) ; V_6 ++ ) {
if ( V_4 -> V_18 [ V_6 / 3 ] & V_19 )
continue;
V_50 = F_40 ( & V_44 -> V_3 ,
& V_48 [ V_6 ] . V_47 ) ;
if ( V_50 )
goto error;
}
for ( V_6 = 0 ; V_6 < ( V_23 * 3 ) ; V_6 ++ ) {
if ( V_4 -> V_24 [ V_6 / 3 ] & V_25 )
continue;
V_50 = F_40 ( & V_44 -> V_3 ,
& V_49 [ V_6 ] . V_47 ) ;
if ( V_50 )
goto error;
}
V_4 -> V_45 = F_41 ( & V_44 -> V_3 ) ;
if ( F_17 ( V_4 -> V_45 ) ) {
V_50 = F_18 ( V_4 -> V_45 ) ;
V_4 -> V_45 = NULL ;
goto error;
}
return 0 ;
error:
F_27 ( V_44 ) ;
return V_50 ;
}
