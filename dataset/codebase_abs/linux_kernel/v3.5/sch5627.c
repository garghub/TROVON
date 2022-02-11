static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 ;
int V_6 , V_7 ;
F_3 ( & V_4 -> V_8 ) ;
if ( F_4 ( V_9 , V_4 -> V_10 + 300 * V_11 ) ) {
F_5 ( V_4 -> V_12 , V_13 ,
V_4 -> V_14 | 0x10 ) ;
V_4 -> V_10 = V_9 ;
}
if ( F_4 ( V_9 , V_4 -> V_15 + V_11 ) || ! V_4 -> V_16 ) {
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
V_7 = F_6 ( V_4 -> V_12 ,
V_18 [ V_6 ] ,
V_19 [ V_6 ] ,
V_20 [ V_6 ] ) ;
if ( F_7 ( V_7 < 0 ) ) {
V_5 = F_8 ( V_7 ) ;
goto abort;
}
V_4 -> V_21 [ V_6 ] = V_7 ;
}
for ( V_6 = 0 ; V_6 < V_22 ; V_6 ++ ) {
V_7 = F_9 ( V_4 -> V_12 ,
V_23 [ V_6 ] ) ;
if ( F_7 ( V_7 < 0 ) ) {
V_5 = F_8 ( V_7 ) ;
goto abort;
}
V_4 -> V_24 [ V_6 ] = V_7 ;
}
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ ) {
V_7 = F_6 ( V_4 -> V_12 ,
V_26 [ V_6 ] ,
V_27 [ V_6 ] ,
V_28 [ V_6 ] ) ;
if ( F_7 ( V_7 < 0 ) ) {
V_5 = F_8 ( V_7 ) ;
goto abort;
}
V_4 -> V_29 [ V_6 ] = V_7 ;
}
V_4 -> V_15 = V_9 ;
V_4 -> V_16 = 1 ;
}
abort:
F_10 ( & V_4 -> V_8 ) ;
return V_5 ;
}
static int T_1 F_11 ( struct V_1 * V_4 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
V_7 = F_12 ( V_4 -> V_12 ,
V_30 [ V_6 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_31 [ V_6 ] = V_7 ;
V_7 = F_12 ( V_4 -> V_12 ,
V_32 [ V_6 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_33 [ V_6 ] = V_7 ;
}
for ( V_6 = 0 ; V_6 < V_22 ; V_6 ++ ) {
V_7 = F_9 ( V_4 -> V_12 ,
V_34 [ V_6 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_35 [ V_6 ] = V_7 ;
}
return 0 ;
}
static int F_13 ( T_2 V_36 )
{
return ( V_36 * 625 ) / 10 - 64000 ;
}
static int F_14 ( T_3 V_36 )
{
return ( V_36 - 64 ) * 1000 ;
}
static int F_15 ( T_2 V_36 )
{
if ( V_36 == 0 )
return - V_37 ;
if ( V_36 == 0xffff )
return 0 ;
return 5400540 / V_36 ;
}
static T_4 F_16 ( struct V_2 * V_3 , struct V_38 * V_39 ,
char * V_40 )
{
return snprintf ( V_40 , V_41 , L_1 , V_42 ) ;
}
static T_4 F_17 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_19 ( V_4 ) )
return F_20 ( V_4 ) ;
V_7 = F_13 ( V_4 -> V_21 [ V_44 -> V_45 ] ) ;
return snprintf ( V_40 , V_41 , L_2 , V_7 ) ;
}
static T_4 F_21 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_19 ( V_4 ) )
return F_20 ( V_4 ) ;
return snprintf ( V_40 , V_41 , L_2 , V_4 -> V_21 [ V_44 -> V_45 ] == 0 ) ;
}
static T_4 F_22 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_7 ;
V_7 = F_14 ( V_4 -> V_31 [ V_44 -> V_45 ] ) ;
return snprintf ( V_40 , V_41 , L_2 , V_7 ) ;
}
static T_4 F_23 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_7 ;
V_7 = F_14 ( V_4 -> V_33 [ V_44 -> V_45 ] ) ;
return snprintf ( V_40 , V_41 , L_2 , V_7 ) ;
}
static T_4 F_24 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_19 ( V_4 ) )
return F_20 ( V_4 ) ;
V_7 = F_15 ( V_4 -> V_24 [ V_44 -> V_45 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return snprintf ( V_40 , V_41 , L_2 , V_7 ) ;
}
static T_4 F_25 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_19 ( V_4 ) )
return F_20 ( V_4 ) ;
return snprintf ( V_40 , V_41 , L_2 ,
V_4 -> V_24 [ V_44 -> V_45 ] == 0xffff ) ;
}
static T_4 F_26 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_7 = F_15 ( V_4 -> V_35 [ V_44 -> V_45 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return snprintf ( V_40 , V_41 , L_2 , V_7 ) ;
}
static T_4 F_27 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( F_19 ( V_4 ) )
return F_20 ( V_4 ) ;
V_7 = F_28 (
V_4 -> V_29 [ V_44 -> V_45 ] * V_46 [ V_44 -> V_45 ] ,
10000 ) ;
return snprintf ( V_40 , V_41 , L_2 , V_7 ) ;
}
static T_4 F_29 ( struct V_2 * V_3 , struct V_38
* V_39 , char * V_40 )
{
struct V_43 * V_44 = F_18 ( V_39 ) ;
return snprintf ( V_40 , V_41 , L_1 ,
V_47 [ V_44 -> V_45 ] ) ;
}
static int F_30 ( struct V_48 * V_49 )
{
struct V_1 * V_4 = F_31 ( V_49 ) ;
if ( V_4 -> V_50 )
F_32 ( V_4 -> V_50 ) ;
if ( V_4 -> V_51 )
F_33 ( V_4 -> V_51 ) ;
F_34 ( & V_49 -> V_3 . V_52 , & V_53 ) ;
F_35 ( V_49 , NULL ) ;
F_36 ( V_4 ) ;
return 0 ;
}
static int T_1 F_37 ( struct V_48 * V_49 )
{
struct V_1 * V_4 ;
int V_54 , V_55 , V_56 , V_57 , V_7 ;
V_4 = F_38 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_4 )
return - V_59 ;
V_4 -> V_12 = F_39 ( V_49 , V_60 , 0 ) -> V_61 ;
F_40 ( & V_4 -> V_8 ) ;
F_35 ( V_49 , V_4 ) ;
V_7 = F_12 ( V_4 -> V_12 , V_62 ) ;
if ( V_7 < 0 ) {
V_54 = V_7 ;
goto error;
}
if ( V_7 != V_63 ) {
F_41 ( L_3 , L_4 ,
V_7 , V_63 ) ;
V_54 = - V_64 ;
goto error;
}
V_7 = F_12 ( V_4 -> V_12 , V_65 ) ;
if ( V_7 < 0 ) {
V_54 = V_7 ;
goto error;
}
if ( V_7 != V_66 ) {
F_41 ( L_3 , L_5 ,
V_7 , V_66 ) ;
V_54 = - V_64 ;
goto error;
}
V_7 = F_12 ( V_4 -> V_12 , V_67 ) ;
if ( V_7 < 0 ) {
V_54 = V_7 ;
goto error;
}
if ( V_7 != V_68 ) {
F_41 ( L_3 , L_6 ,
V_7 , V_68 ) ;
V_54 = - V_64 ;
goto error;
}
V_55 = F_12 ( V_4 -> V_12 ,
V_69 ) ;
if ( V_55 < 0 ) {
V_54 = V_55 ;
goto error;
}
V_56 = F_9 ( V_4 -> V_12 ,
V_70 ) ;
if ( V_56 < 0 ) {
V_54 = V_56 ;
goto error;
}
V_57 = F_12 ( V_4 -> V_12 ,
V_71 ) ;
if ( V_57 < 0 ) {
V_54 = V_57 ;
goto error;
}
V_7 = F_12 ( V_4 -> V_12 , V_13 ) ;
if ( V_7 < 0 ) {
V_54 = V_7 ;
goto error;
}
V_4 -> V_14 = V_7 ;
if ( ! ( V_4 -> V_14 & 0x01 ) ) {
F_41 ( L_7 ) ;
V_54 = - V_64 ;
goto error;
}
F_5 ( V_4 -> V_12 , V_13 ,
V_4 -> V_14 | 0x10 ) ;
V_4 -> V_10 = V_9 ;
V_54 = F_11 ( V_4 ) ;
if ( V_54 )
goto error;
F_42 ( L_8 , V_42 , V_4 -> V_12 ) ;
F_42 ( L_9 ,
V_55 , V_56 , V_57 ) ;
V_54 = F_43 ( & V_49 -> V_3 . V_52 , & V_53 ) ;
if ( V_54 )
goto error;
V_4 -> V_51 = F_44 ( & V_49 -> V_3 ) ;
if ( F_19 ( V_4 -> V_51 ) ) {
V_54 = F_20 ( V_4 -> V_51 ) ;
V_4 -> V_51 = NULL ;
goto error;
}
V_4 -> V_50 = F_45 ( & V_49 -> V_3 , V_4 -> V_12 ,
( V_55 << 24 ) | ( V_56 << 8 ) | V_57 ,
& V_4 -> V_8 , 1 ) ;
return 0 ;
error:
F_30 ( V_49 ) ;
return V_54 ;
}
