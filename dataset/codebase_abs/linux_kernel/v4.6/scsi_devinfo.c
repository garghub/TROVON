static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
int V_4 = 0 ;
F_2 (devinfo_table, &scsi_dev_info_list, node)
if ( V_3 -> V_2 == V_2 ) {
V_4 = 1 ;
break;
}
if ( ! V_4 )
return F_3 ( - V_5 ) ;
return V_3 ;
}
static void F_4 ( char * V_6 , char * V_7 , T_1 V_8 ,
char * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = strlen ( V_9 ) ;
strncpy ( V_7 , V_9 , F_5 ( V_8 , V_11 ) ) ;
if ( V_11 < V_8 ) {
if ( V_10 ) {
V_7 [ V_11 ] = '\0' ;
} else {
strncpy ( & V_7 [ V_11 ] , V_12 ,
V_8 - V_11 ) ;
}
}
if ( V_11 > V_8 )
F_6 ( V_13 L_1 ,
V_14 , V_6 , V_9 ) ;
}
static int F_7 ( int V_10 , char * V_15 , char * V_16 ,
char * V_17 , int V_18 )
{
return F_8 ( V_10 , V_15 , V_16 ,
V_17 , V_18 ,
V_19 ) ;
}
int F_8 ( int V_10 , char * V_15 , char * V_16 ,
char * V_17 , int V_18 , int V_2 )
{
struct V_20 * V_21 ;
struct V_1 * V_3 =
F_1 ( V_2 ) ;
if ( F_9 ( V_3 ) )
return F_10 ( V_3 ) ;
V_21 = F_11 ( sizeof( * V_21 ) , V_22 ) ;
if ( ! V_21 ) {
F_6 ( V_23 L_2 , V_14 ) ;
return - V_24 ;
}
F_4 ( L_3 , V_21 -> V_15 , sizeof( V_21 -> V_15 ) ,
V_15 , V_10 ) ;
F_4 ( L_4 , V_21 -> V_16 , sizeof( V_21 -> V_16 ) ,
V_16 , V_10 ) ;
if ( V_17 )
V_21 -> V_18 = F_12 ( V_17 , NULL , 0 ) ;
else
V_21 -> V_18 = V_18 ;
V_21 -> V_10 = V_10 ;
if ( V_10 )
F_13 ( & V_21 -> V_25 ,
& V_3 -> V_20 ) ;
else
F_14 ( & V_21 -> V_25 ,
& V_3 -> V_20 ) ;
return 0 ;
}
static struct V_20 * F_15 ( const char * V_15 ,
const char * V_16 , int V_2 )
{
struct V_20 * V_21 ;
struct V_1 * V_3 =
F_1 ( V_2 ) ;
T_1 V_26 , V_27 ;
const char * V_28 , * V_29 ;
if ( F_9 ( V_3 ) )
return (struct V_20 * ) V_3 ;
V_26 = 8 ;
V_28 = V_15 ;
while ( V_26 > 0 && * V_28 == ' ' ) {
V_26 -- ;
V_28 ++ ;
}
while ( V_26 > 0 && V_28 [ V_26 - 1 ] == ' ' )
-- V_26 ;
V_27 = 16 ;
V_29 = V_16 ;
while ( V_27 > 0 && * V_29 == ' ' ) {
V_27 -- ;
V_29 ++ ;
}
while ( V_27 > 0 && V_29 [ V_27 - 1 ] == ' ' )
-- V_27 ;
F_2 (devinfo, &devinfo_table->scsi_dev_info_list,
dev_info_list) {
if ( V_21 -> V_10 ) {
if ( memcmp ( V_21 -> V_15 , V_28 , V_26 ) ||
V_21 -> V_15 [ V_26 ] )
continue;
if ( memcmp ( V_21 -> V_16 , V_29 , V_27 ) ||
V_21 -> V_16 [ V_27 ] )
continue;
return V_21 ;
} else {
if ( ! memcmp ( V_21 -> V_15 , V_15 ,
sizeof( V_21 -> V_15 ) ) &&
! memcmp ( V_21 -> V_16 , V_16 ,
sizeof( V_21 -> V_16 ) ) )
return V_21 ;
}
}
return F_3 ( - V_30 ) ;
}
int F_16 ( char * V_15 , char * V_16 , int V_2 )
{
struct V_20 * V_4 ;
V_4 = F_15 ( V_15 , V_16 , V_2 ) ;
if ( F_9 ( V_4 ) )
return F_10 ( V_4 ) ;
F_17 ( & V_4 -> V_25 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
static int F_19 ( char * V_31 )
{
char * V_15 , * V_16 , * V_17 , * V_32 ;
char * V_33 ;
int V_34 = 0 ;
V_32 = V_31 ;
if ( V_32 && V_32 [ 0 ] == '"' ) {
V_32 ++ ;
V_33 = L_5 ;
} else {
V_33 = L_6 ;
}
for ( V_15 = F_20 ( & V_32 , L_7 ) ; V_15 && ( V_15 [ 0 ] != '\0' )
&& ( V_34 == 0 ) ; V_15 = F_20 ( & V_32 , L_7 ) ) {
V_17 = NULL ;
V_16 = F_20 ( & V_32 , L_7 ) ;
if ( V_16 )
V_17 = F_20 ( & V_32 , V_33 ) ;
if ( ! V_16 || ! V_17 ) {
F_6 ( V_23 L_8
L_9 , V_14 , V_15 , V_16 ,
V_17 ) ;
V_34 = - V_5 ;
} else
V_34 = F_7 ( 0 , V_15 ,
V_16 , V_17 , 0 ) ;
}
return V_34 ;
}
int F_21 ( struct V_35 * V_36 ,
const unsigned char * V_15 ,
const unsigned char * V_16 )
{
return F_22 ( V_36 , V_15 , V_16 ,
V_19 ) ;
}
int F_22 ( struct V_35 * V_36 ,
const unsigned char * V_15 ,
const unsigned char * V_16 ,
int V_2 )
{
struct V_20 * V_21 ;
int V_37 ;
V_21 = F_15 ( V_15 , V_16 , V_2 ) ;
if ( ! F_9 ( V_21 ) )
return V_21 -> V_18 ;
V_37 = F_10 ( V_21 ) ;
if ( V_37 != - V_30 )
return V_37 ;
if ( V_2 != V_19 )
return 0 ;
if ( V_36 -> V_38 )
return V_36 -> V_38 ;
return V_39 ;
}
static int F_23 ( struct V_40 * V_41 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
struct V_1 * V_3 =
F_24 ( V_44 -> V_45 , struct V_1 , V_46 ) ;
struct V_20 * V_21 =
F_24 ( V_44 -> V_47 , struct V_20 ,
V_25 ) ;
if ( V_3 -> V_20 . V_32 == V_44 -> V_47 &&
V_3 -> V_6 )
F_25 ( V_41 , L_10 , V_3 -> V_6 ) ;
F_25 ( V_41 , L_11 ,
V_21 -> V_15 , V_21 -> V_16 , V_21 -> V_18 ) ;
return 0 ;
}
static void * F_26 ( struct V_40 * V_41 , T_2 * V_48 )
{
struct V_43 * V_44 = F_11 ( sizeof( * V_44 ) , V_22 ) ;
T_2 V_49 = * V_48 ;
if ( ! V_44 )
return NULL ;
F_27 (dl->top, &scsi_dev_info_list) {
struct V_1 * V_3 =
F_24 ( V_44 -> V_45 , struct V_1 ,
V_46 ) ;
F_27 (dl->bottom, &devinfo_table->scsi_dev_info_list)
if ( V_49 -- == 0 )
return V_44 ;
}
F_18 ( V_44 ) ;
return NULL ;
}
static void * F_28 ( struct V_40 * V_41 , void * V_42 , T_2 * V_48 )
{
struct V_43 * V_44 = V_42 ;
struct V_1 * V_3 =
F_24 ( V_44 -> V_45 , struct V_1 , V_46 ) ;
++ * V_48 ;
V_44 -> V_47 = V_44 -> V_47 -> V_32 ;
while ( & V_3 -> V_20 == V_44 -> V_47 ) {
V_44 -> V_45 = V_44 -> V_45 -> V_32 ;
if ( V_44 -> V_45 == & V_20 ) {
F_18 ( V_44 ) ;
return NULL ;
}
V_3 = F_24 ( V_44 -> V_45 ,
struct V_1 ,
V_46 ) ;
V_44 -> V_47 = V_3 -> V_20 . V_32 ;
}
return V_44 ;
}
static void F_29 ( struct V_40 * V_41 , void * V_42 )
{
F_18 ( V_42 ) ;
}
static int F_30 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return F_31 ( V_51 , & V_52 ) ;
}
static T_3 F_32 ( struct V_51 * V_51 ,
const char T_4 * V_53 ,
T_1 V_54 , T_2 * V_48 )
{
char * V_55 ;
T_3 V_37 = V_54 ;
if ( ! V_53 || V_54 > V_56 )
return - V_5 ;
if ( ! ( V_55 = ( char * ) F_33 ( V_22 ) ) )
return - V_24 ;
if ( F_34 ( V_55 , V_53 , V_54 ) ) {
V_37 = - V_57 ;
goto V_58;
}
if ( V_54 < V_56 )
V_55 [ V_54 ] = '\0' ;
else if ( V_55 [ V_56 - 1 ] ) {
V_37 = - V_5 ;
goto V_58;
}
F_19 ( V_55 ) ;
V_58:
F_35 ( ( unsigned long ) V_55 ) ;
return V_37 ;
}
void F_36 ( void )
{
#ifdef F_37
F_38 ( L_12 , NULL ) ;
#endif
F_39 ( V_19 ) ;
}
int F_40 ( int V_2 , const char * V_6 )
{
struct V_1 * V_3 =
F_1 ( V_2 ) ;
if ( ! F_9 ( V_3 ) )
return - V_59 ;
V_3 = F_11 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 )
return - V_24 ;
F_41 ( & V_3 -> V_46 ) ;
F_41 ( & V_3 -> V_20 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_2 = V_2 ;
F_13 ( & V_3 -> V_46 , & V_20 ) ;
return 0 ;
}
int F_39 ( int V_2 )
{
struct V_60 * V_61 , * V_62 ;
struct V_1 * V_3 =
F_1 ( V_2 ) ;
if ( F_9 ( V_3 ) )
return - V_5 ;
F_17 ( & V_3 -> V_46 ) ;
F_42 (lh, lh_next, &devinfo_table->scsi_dev_info_list) {
struct V_20 * V_21 ;
V_21 = F_24 ( V_61 , struct V_20 ,
V_25 ) ;
F_18 ( V_21 ) ;
}
F_18 ( V_3 ) ;
return 0 ;
}
int T_5 F_43 ( void )
{
#ifdef F_37
struct V_63 * V_64 ;
#endif
int error , V_65 ;
error = F_40 ( V_19 , NULL ) ;
if ( error )
return error ;
error = F_19 ( V_66 ) ;
if ( error )
goto V_58;
for ( V_65 = 0 ; V_67 [ V_65 ] . V_15 ; V_65 ++ ) {
error = F_7 ( 1 ,
V_67 [ V_65 ] . V_15 ,
V_67 [ V_65 ] . V_16 ,
NULL ,
V_67 [ V_65 ] . V_18 ) ;
if ( error )
goto V_58;
}
#ifdef F_37
V_64 = F_44 ( L_12 , 0 , NULL , & V_68 ) ;
if ( ! V_64 ) {
error = - V_24 ;
goto V_58;
}
#endif
V_58:
if ( error )
F_36 () ;
return error ;
}
