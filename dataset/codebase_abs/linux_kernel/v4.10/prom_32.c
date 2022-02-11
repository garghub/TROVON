void * T_1 F_1 ( unsigned long V_1 )
{
void * V_2 ;
V_2 = F_2 ( V_1 , V_3 , 0UL ) ;
if ( V_2 != NULL )
memset ( V_2 , 0 , V_1 ) ;
V_4 += V_1 ;
return V_2 ;
}
static void T_1 F_3 ( struct V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_11 = F_4 ( V_6 , L_1 , NULL ) ;
if ( ! V_11 )
return;
V_9 = V_11 -> V_12 ;
sprintf ( V_7 , L_2 ,
V_6 -> V_13 ,
V_9 -> V_14 , V_9 -> V_15 ) ;
}
static void T_1 F_5 ( struct V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_16 ;
V_16 = F_4 ( V_6 , L_1 , NULL ) ;
if ( ! V_16 )
return;
V_9 = V_16 -> V_12 ;
sprintf ( V_7 , L_2 ,
V_6 -> V_13 ,
V_9 -> V_14 ,
V_9 -> V_15 ) ;
}
static void T_1 F_6 ( struct V_5 * V_6 , char * V_7 )
{
struct V_17 * V_9 ;
struct V_10 * V_16 ;
unsigned int V_18 ;
V_16 = F_4 ( V_6 , L_1 , NULL ) ;
if ( ! V_16 )
return;
V_9 = V_16 -> V_12 ;
V_18 = ( V_9 -> V_19 >> 8 ) & 0xff ;
if ( V_18 & 0x07 ) {
sprintf ( V_7 , L_2 ,
V_6 -> V_13 ,
V_18 >> 3 ,
V_18 & 0x07 ) ;
} else {
sprintf ( V_7 , L_3 ,
V_6 -> V_13 ,
V_18 >> 3 ) ;
}
}
static void T_1 F_7 ( struct V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_16 ;
V_16 = F_4 ( V_6 , L_1 , NULL ) ;
if ( ! V_16 )
return;
V_9 = V_16 -> V_12 ;
sprintf ( V_7 , L_2 ,
V_6 -> V_13 ,
V_9 -> V_14 , V_9 -> V_15 ) ;
}
static void T_1 F_8 ( struct V_5 * V_6 , char * V_7 )
{
struct V_20 * V_9 ;
unsigned int * V_21 , * V_22 , * V_23 , V_24 ;
struct V_10 * V_16 ;
int V_25 = 0 ;
V_16 = F_4 ( V_6 , L_1 , NULL ) ;
if ( ! V_16 ) {
V_24 = ( unsigned int ) V_6 -> V_26 ;
} else {
V_9 = V_16 -> V_12 ;
V_24 = V_9 -> V_15 ;
}
V_16 = F_4 ( V_6 , L_4 , NULL ) ;
if ( ! V_16 )
V_21 = & V_25 ;
else
V_21 = V_16 -> V_12 ;
V_16 = F_4 ( V_6 , L_5 , NULL ) ;
if ( ! V_16 )
return;
V_23 = V_16 -> V_12 ;
V_16 = F_4 ( V_6 , L_6 , NULL ) ;
if ( ! V_16 )
return;
V_22 = V_16 -> V_12 ;
sprintf ( V_7 , L_7 ,
V_6 -> V_13 , * V_23 , * V_22 ,
* V_21 , V_24 ) ;
}
static void T_1 F_9 ( struct V_5 * V_6 , char * V_7 )
{
struct V_5 * V_27 = V_6 -> V_27 ;
if ( V_27 != NULL ) {
if ( ! strcmp ( V_27 -> type , L_8 ) ||
! strcmp ( V_27 -> type , L_9 ) )
return F_6 ( V_6 , V_7 ) ;
if ( ! strcmp ( V_27 -> type , L_10 ) )
return F_5 ( V_6 , V_7 ) ;
if ( ! strcmp ( V_27 -> type , L_11 ) )
return F_7 ( V_6 , V_7 ) ;
if ( ! strcmp ( V_27 -> type , L_12 ) )
return F_8 ( V_6 , V_7 ) ;
}
return F_3 ( V_6 , V_7 ) ;
}
char * T_1 F_10 ( struct V_5 * V_6 )
{
char V_7 [ 64 ] , * V_28 ;
V_7 [ 0 ] = '\0' ;
F_9 ( V_6 , V_7 ) ;
if ( V_7 [ 0 ] == '\0' )
strcpy ( V_7 , V_6 -> V_13 ) ;
V_28 = F_1 ( strlen ( V_7 ) + 1 ) ;
strcpy ( V_28 , V_7 ) ;
return V_28 ;
}
void T_1 F_11 ( void )
{
char * V_29 = L_13 ;
struct V_5 * V_6 ;
unsigned long V_30 ;
const char * type ;
V_26 V_31 ;
int V_32 , V_33 , V_34 ;
V_35 = F_1 ( 256 ) ;
switch ( V_36 ) {
case V_37 :
V_32 = 0 ;
switch ( * V_38 -> V_39 ) {
case V_40 :
type = L_14 ;
break;
case V_41 :
V_32 = 1 ;
case V_42 :
type = L_15 ;
break;
default:
F_12 ( L_16 ,
* V_38 -> V_39 ) ;
F_13 () ;
}
V_33 = V_32 ;
F_14 (dp, type) {
if ( ! V_33 -- )
break;
}
if ( ! V_6 ) {
F_12 ( L_17 ) ;
F_13 () ;
}
V_43 = V_6 ;
strcpy ( V_35 , V_6 -> V_44 ) ;
if ( ! strcmp ( type , L_15 ) ) {
strcat ( V_35 ,
( V_32 ? L_18 : L_19 ) ) ;
}
break;
default:
case V_45 :
case V_46 :
V_34 = * V_38 -> V_47 . V_48 ;
F_15 ( & V_49 , V_30 ) ;
V_31 = (* V_38 -> V_50 . V_51 )( V_34 ) ;
F_16 () ;
F_17 ( & V_49 , V_30 ) ;
if ( ! V_31 ) {
F_12 ( L_20
L_21 , V_34 ) ;
F_13 () ;
}
V_6 = F_18 ( V_31 ) ;
type = F_19 ( V_6 , L_22 , NULL ) ;
if ( ! type ) {
F_12 ( L_23
L_24 ) ;
F_13 () ;
}
if ( strcmp ( type , L_14 ) && strcmp ( type , L_15 ) ) {
F_12 ( L_25
L_26 ) ;
F_13 () ;
}
V_43 = V_6 ;
if ( V_36 == V_45 ) {
strcpy ( V_35 , V_6 -> V_44 ) ;
switch ( * V_38 -> V_39 ) {
case V_42 :
strcat ( V_35 , L_19 ) ;
break;
case V_41 :
strcat ( V_35 , L_18 ) ;
break;
}
} else {
const char * V_52 ;
V_6 = F_20 ( L_27 ) ;
V_52 = F_19 ( V_6 , L_28 , NULL ) ;
if ( ! V_52 ) {
F_12 ( L_29 ) ;
F_13 () ;
}
strcpy ( V_35 , V_52 ) ;
}
break;
}
V_53 = strrchr ( V_35 , ':' ) ;
if ( V_53 ) {
V_53 ++ ;
if ( * V_53 == '\0' )
V_53 = NULL ;
}
F_21 ( V_29 , V_35 ) ;
}
void T_1 F_22 ( void )
{
}
void T_1 F_23 ( struct V_5 * V_6 )
{
}
