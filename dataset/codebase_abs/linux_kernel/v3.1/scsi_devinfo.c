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
int F_15 ( char * V_15 , char * V_16 , int V_2 )
{
struct V_20 * V_21 , * V_4 = NULL ;
struct V_1 * V_3 =
F_1 ( V_2 ) ;
if ( F_9 ( V_3 ) )
return F_10 ( V_3 ) ;
F_2 (devinfo, &devinfo_table->scsi_dev_info_list,
dev_info_list) {
if ( V_21 -> V_10 ) {
T_1 V_26 ;
V_26 = 8 ;
while ( ( V_26 > 0 ) && * V_15 == ' ' ) {
V_26 -- ;
V_15 ++ ;
}
if ( memcmp ( V_21 -> V_15 , V_15 ,
F_5 ( V_26 , strlen ( V_21 -> V_15 ) ) ) )
continue;
V_26 = 16 ;
while ( ( V_26 > 0 ) && * V_16 == ' ' ) {
V_26 -- ;
V_16 ++ ;
}
if ( memcmp ( V_21 -> V_16 , V_16 ,
F_5 ( V_26 , strlen ( V_21 -> V_16 ) ) ) )
continue;
V_4 = V_21 ;
} else {
if ( ! memcmp ( V_21 -> V_15 , V_15 ,
sizeof( V_21 -> V_15 ) ) &&
! memcmp ( V_21 -> V_16 , V_16 ,
sizeof( V_21 -> V_16 ) ) )
V_4 = V_21 ;
}
if ( V_4 )
break;
}
if ( V_4 ) {
F_16 ( & V_4 -> V_25 ) ;
F_17 ( V_4 ) ;
return 0 ;
}
return - V_27 ;
}
static int F_18 ( char * V_28 )
{
char * V_15 , * V_16 , * V_17 , * V_29 ;
char * V_30 ;
int V_31 = 0 ;
V_29 = V_28 ;
if ( V_29 && V_29 [ 0 ] == '"' ) {
V_29 ++ ;
V_30 = L_5 ;
} else {
V_30 = L_6 ;
}
for ( V_15 = F_19 ( & V_29 , L_7 ) ; V_15 && ( V_15 [ 0 ] != '\0' )
&& ( V_31 == 0 ) ; V_15 = F_19 ( & V_29 , L_7 ) ) {
V_17 = NULL ;
V_16 = F_19 ( & V_29 , L_7 ) ;
if ( V_16 )
V_17 = F_19 ( & V_29 , V_30 ) ;
if ( ! V_16 || ! V_17 ) {
F_6 ( V_23 L_8
L_9 , V_14 , V_15 , V_16 ,
V_17 ) ;
V_31 = - V_5 ;
} else
V_31 = F_7 ( 0 , V_15 ,
V_16 , V_17 , 0 ) ;
}
return V_31 ;
}
int F_20 ( struct V_32 * V_33 ,
const unsigned char * V_15 ,
const unsigned char * V_16 )
{
return F_21 ( V_33 , V_15 , V_16 ,
V_19 ) ;
}
int F_21 ( struct V_32 * V_33 ,
const unsigned char * V_15 ,
const unsigned char * V_16 ,
int V_2 )
{
struct V_20 * V_21 ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( F_9 ( V_3 ) )
return F_10 ( V_3 ) ;
F_2 (devinfo, &devinfo_table->scsi_dev_info_list,
dev_info_list) {
if ( V_21 -> V_10 ) {
T_1 V_26 ;
V_26 = 8 ;
while ( ( V_26 > 0 ) && * V_15 == ' ' ) {
V_26 -- ;
V_15 ++ ;
}
if ( memcmp ( V_21 -> V_15 , V_15 ,
F_5 ( V_26 , strlen ( V_21 -> V_15 ) ) ) )
continue;
V_26 = 16 ;
while ( ( V_26 > 0 ) && * V_16 == ' ' ) {
V_26 -- ;
V_16 ++ ;
}
if ( memcmp ( V_21 -> V_16 , V_16 ,
F_5 ( V_26 , strlen ( V_21 -> V_16 ) ) ) )
continue;
return V_21 -> V_18 ;
} else {
if ( ! memcmp ( V_21 -> V_15 , V_15 ,
sizeof( V_21 -> V_15 ) ) &&
! memcmp ( V_21 -> V_16 , V_16 ,
sizeof( V_21 -> V_16 ) ) )
return V_21 -> V_18 ;
}
}
if ( V_2 != V_19 )
return 0 ;
if ( V_33 -> V_34 )
return V_33 -> V_34 ;
return V_35 ;
}
static int F_22 ( struct V_36 * V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_1 * V_3 =
F_23 ( V_40 -> V_41 , struct V_1 , V_42 ) ;
struct V_20 * V_21 =
F_23 ( V_40 -> V_43 , struct V_20 ,
V_25 ) ;
if ( V_3 -> V_20 . V_29 == V_40 -> V_43 &&
V_3 -> V_6 )
F_24 ( V_37 , L_10 , V_3 -> V_6 ) ;
F_24 ( V_37 , L_11 ,
V_21 -> V_15 , V_21 -> V_16 , V_21 -> V_18 ) ;
return 0 ;
}
static void * F_25 ( struct V_36 * V_37 , T_2 * V_44 )
{
struct V_39 * V_40 = F_11 ( sizeof( * V_40 ) , V_22 ) ;
T_2 V_45 = * V_44 ;
if ( ! V_40 )
return NULL ;
F_26 (dl->top, &scsi_dev_info_list) {
struct V_1 * V_3 =
F_23 ( V_40 -> V_41 , struct V_1 ,
V_42 ) ;
F_26 (dl->bottom, &devinfo_table->scsi_dev_info_list)
if ( V_45 -- == 0 )
return V_40 ;
}
F_17 ( V_40 ) ;
return NULL ;
}
static void * F_27 ( struct V_36 * V_37 , void * V_38 , T_2 * V_44 )
{
struct V_39 * V_40 = V_38 ;
struct V_1 * V_3 =
F_23 ( V_40 -> V_41 , struct V_1 , V_42 ) ;
++ * V_44 ;
V_40 -> V_43 = V_40 -> V_43 -> V_29 ;
while ( & V_3 -> V_20 == V_40 -> V_43 ) {
V_40 -> V_41 = V_40 -> V_41 -> V_29 ;
if ( V_40 -> V_41 == & V_20 ) {
F_17 ( V_40 ) ;
return NULL ;
}
V_3 = F_23 ( V_40 -> V_41 ,
struct V_1 ,
V_42 ) ;
V_40 -> V_43 = V_3 -> V_20 . V_29 ;
}
return V_40 ;
}
static void F_28 ( struct V_36 * V_37 , void * V_38 )
{
F_17 ( V_38 ) ;
}
static int F_29 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_30 ( V_47 , & V_48 ) ;
}
static T_3 F_31 ( struct V_47 * V_47 ,
const char T_4 * V_49 ,
T_1 V_50 , T_2 * V_44 )
{
char * V_51 ;
T_3 V_52 = V_50 ;
if ( ! V_49 || V_50 > V_53 )
return - V_5 ;
if ( ! ( V_51 = ( char * ) F_32 ( V_22 ) ) )
return - V_24 ;
if ( F_33 ( V_51 , V_49 , V_50 ) ) {
V_52 = - V_54 ;
goto V_55;
}
if ( V_50 < V_53 )
V_51 [ V_50 ] = '\0' ;
else if ( V_51 [ V_53 - 1 ] ) {
V_52 = - V_5 ;
goto V_55;
}
F_18 ( V_51 ) ;
V_55:
F_34 ( ( unsigned long ) V_51 ) ;
return V_52 ;
}
void F_35 ( void )
{
#ifdef F_36
F_37 ( L_12 , NULL ) ;
#endif
F_38 ( V_19 ) ;
}
int F_39 ( int V_2 , const char * V_6 )
{
struct V_1 * V_3 =
F_1 ( V_2 ) ;
if ( ! F_9 ( V_3 ) )
return - V_56 ;
V_3 = F_11 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 )
return - V_24 ;
F_40 ( & V_3 -> V_42 ) ;
F_40 ( & V_3 -> V_20 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_2 = V_2 ;
F_13 ( & V_3 -> V_42 , & V_20 ) ;
return 0 ;
}
int F_38 ( int V_2 )
{
struct V_57 * V_58 , * V_59 ;
struct V_1 * V_3 =
F_1 ( V_2 ) ;
if ( F_9 ( V_3 ) )
return - V_5 ;
F_16 ( & V_3 -> V_42 ) ;
F_41 (lh, lh_next, &devinfo_table->scsi_dev_info_list) {
struct V_20 * V_21 ;
V_21 = F_23 ( V_58 , struct V_20 ,
V_25 ) ;
F_17 ( V_21 ) ;
}
F_17 ( V_3 ) ;
return 0 ;
}
int T_5 F_42 ( void )
{
#ifdef F_36
struct V_60 * V_61 ;
#endif
int error , V_62 ;
error = F_39 ( V_19 , NULL ) ;
if ( error )
return error ;
error = F_18 ( V_63 ) ;
if ( error )
goto V_55;
for ( V_62 = 0 ; V_64 [ V_62 ] . V_15 ; V_62 ++ ) {
error = F_7 ( 1 ,
V_64 [ V_62 ] . V_15 ,
V_64 [ V_62 ] . V_16 ,
NULL ,
V_64 [ V_62 ] . V_18 ) ;
if ( error )
goto V_55;
}
#ifdef F_36
V_61 = F_43 ( L_12 , 0 , NULL , & V_65 ) ;
if ( ! V_61 ) {
error = - V_24 ;
goto V_55;
}
#endif
V_55:
if ( error )
F_35 () ;
return error ;
}
