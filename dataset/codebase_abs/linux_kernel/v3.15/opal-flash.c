static inline void F_1 ( void )
{
long V_1 ;
void * V_2 = V_3 . V_2 ;
T_1 V_4 , V_5 ;
V_1 = F_2 ( F_3 ( V_2 ) , & V_4 , & V_5 ) ;
V_3 . V_6 = V_1 ;
V_3 . V_7 = F_4 ( V_4 ) ;
V_3 . V_5 = F_4 ( V_5 ) ;
}
static T_2 F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_2 )
{
struct V_12 * V_13 = & V_3 ;
int V_14 ;
if ( V_13 -> V_6 < V_15 ) {
V_14 = sprintf ( V_2 , L_1 , V_13 -> V_6 ) ;
goto V_16;
}
V_14 = sprintf ( V_2 , L_1 , V_13 -> V_5 ) ;
if ( ( V_13 -> V_5 != V_15 ) &&
( V_13 -> V_5 < V_17 ) )
goto V_16;
if ( V_13 -> V_7 > ( V_18 - V_14 ) ) {
memcpy ( V_2 + V_14 , V_13 -> V_2 , V_18 - V_14 ) ;
V_14 = V_18 ;
} else {
memcpy ( V_2 + V_14 , V_13 -> V_2 , V_13 -> V_7 ) ;
V_14 += V_13 -> V_7 ;
}
V_16:
V_13 -> V_6 = V_19 ;
return V_14 ;
}
static T_2 F_6 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_2 , T_3 V_20 )
{
struct V_12 * V_13 = & V_3 ;
if ( V_2 [ 0 ] != '1' )
return - V_21 ;
F_7 ( & V_22 ) ;
if ( V_23 . V_6 != V_24 ||
V_23 . V_4 < V_18 ) {
V_13 -> V_5 = V_25 ;
V_13 -> V_6 = V_26 ;
goto V_16;
}
memcpy ( V_13 -> V_2 , V_23 . V_27 , V_18 ) ;
V_13 -> V_6 = V_28 ;
V_13 -> V_7 = V_18 ;
F_1 () ;
V_16:
F_8 ( & V_22 ) ;
return V_20 ;
}
static inline void F_9 ( T_4 V_29 )
{
struct V_30 * const V_13 = & V_31 ;
V_13 -> V_6 = F_10 ( V_29 ) ;
}
static T_2 F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_2 )
{
struct V_30 * const V_13 = & V_31 ;
int V_32 ;
V_32 = sprintf ( V_2 , L_1 , V_13 -> V_6 ) ;
V_13 -> V_6 = V_19 ;
return V_32 ;
}
static T_2 F_12 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_2 , T_3 V_20 )
{
T_4 V_29 ;
switch ( V_2 [ 0 ] ) {
case '0' :
V_29 = V_33 ;
break;
case '1' :
V_29 = V_34 ;
break;
default:
return - V_21 ;
}
F_9 ( V_29 ) ;
return V_20 ;
}
static int F_13 ( int V_29 )
{
struct V_35 * V_36 ;
unsigned long V_37 ;
T_5 V_32 = V_38 ;
if ( V_29 == V_39 ) {
F_14 ( L_2 ) ;
V_37 = '\0' ;
goto V_40;
}
V_36 = F_15 ( V_23 . V_27 , V_23 . V_4 ) ;
if ( ! V_36 )
goto V_41;
V_37 = F_3 ( V_36 ) ;
F_14 ( L_3 , V_23 . V_4 ) ;
F_14 ( L_4 ) ;
F_14 ( L_5 ) ;
F_14 ( L_6 ) ;
V_40:
V_32 = F_16 ( V_37 ) ;
V_41:
return V_32 ;
}
static T_2 F_17 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_2 )
{
struct V_42 * const V_13 = & V_43 ;
return sprintf ( V_2 , L_1 , V_13 -> V_6 ) ;
}
static T_2 F_18 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_2 , T_3 V_20 )
{
struct V_42 * const V_13 = & V_43 ;
int V_32 = V_20 ;
F_7 ( & V_22 ) ;
switch ( V_2 [ 0 ] ) {
case '0' :
if ( V_13 -> V_6 == V_44 )
F_13 ( V_39 ) ;
V_13 -> V_6 = V_19 ;
break;
case '1' :
if ( V_23 . V_6 == V_24 )
V_13 -> V_6 =
F_13 ( V_45 ) ;
else
V_13 -> V_6 = V_46 ;
break;
default:
V_32 = - V_21 ;
}
F_8 ( & V_22 ) ;
return V_32 ;
}
static void F_19 ( void )
{
void * V_37 ;
int V_4 ;
V_37 = V_23 . V_27 ;
V_4 = F_20 ( V_23 . V_4 ) ;
while ( V_4 > 0 ) {
F_21 ( F_22 ( V_37 ) ) ;
V_37 += V_47 ;
V_4 -= V_47 ;
}
F_23 ( V_23 . V_27 ) ;
V_23 . V_27 = NULL ;
V_23 . V_6 = V_48 ;
}
static int F_24 ( char * V_49 , T_3 V_20 )
{
void * V_37 ;
int V_4 ;
if ( V_20 < sizeof( struct V_50 ) ) {
F_25 ( L_7 ) ;
return - V_21 ;
}
memcpy ( & V_51 , ( void * ) V_49 , sizeof( struct V_50 ) ) ;
V_23 . V_4 = F_4 ( V_51 . V_4 ) ;
F_26 ( L_8 , V_23 . V_4 ) ;
if ( V_23 . V_4 > V_52 ) {
F_25 ( L_9 ) ;
return - V_21 ;
}
if ( V_23 . V_4 < V_18 ) {
F_25 ( L_10 ) ;
return - V_21 ;
}
V_23 . V_27 = F_27 ( F_20 ( V_23 . V_4 ) ) ;
if ( ! V_23 . V_27 ) {
F_28 ( L_11 , V_53 ) ;
return - V_54 ;
}
V_37 = V_23 . V_27 ;
V_4 = F_20 ( V_23 . V_4 ) ;
while ( V_4 > 0 ) {
F_29 ( F_22 ( V_37 ) ) ;
V_37 += V_47 ;
V_4 -= V_47 ;
}
V_23 . V_6 = V_55 ;
return 0 ;
}
static T_2 F_30 ( struct V_56 * V_57 , struct V_8 * V_9 ,
struct V_58 * V_59 ,
char * V_49 , T_6 V_60 , T_3 V_20 )
{
int V_32 ;
F_7 ( & V_22 ) ;
if ( V_60 == 0 ) {
if ( V_23 . V_27 )
F_19 () ;
if ( V_43 . V_6 == V_44 )
F_13 ( V_39 ) ;
V_32 = F_24 ( V_49 , V_20 ) ;
if ( V_32 )
goto V_16;
}
if ( V_23 . V_6 != V_55 ) {
V_32 = - V_54 ;
goto V_16;
}
if ( ( V_60 + V_20 ) > V_23 . V_4 ) {
V_32 = - V_21 ;
goto V_16;
}
memcpy ( V_23 . V_27 + V_60 , ( void * ) V_49 , V_20 ) ;
V_32 = V_20 ;
if ( ( V_60 + V_20 ) == V_23 . V_4 ) {
F_26 ( L_12 ) ;
V_23 . V_6 = V_24 ;
}
V_16:
F_8 ( & V_22 ) ;
return V_32 ;
}
void T_7 F_31 ( void )
{
int V_1 ;
V_3 . V_2 = F_32 ( V_18 , V_61 ) ;
if ( ! V_3 . V_2 ) {
F_28 ( L_11 , V_53 ) ;
return;
}
if ( ! V_62 ) {
F_25 ( L_13 ) ;
goto V_63;
}
V_1 = F_33 ( V_62 , & V_64 ) ;
if ( V_1 ) {
F_25 ( L_14 ) ;
goto V_63;
}
V_1 = F_34 ( V_62 , & V_65 ) ;
if ( V_1 ) {
F_25 ( L_14 ) ;
goto V_66;
}
V_3 . V_6 = V_19 ;
V_31 . V_6 = V_19 ;
V_43 . V_6 = V_19 ;
V_23 . V_6 = V_48 ;
return;
V_66:
F_35 ( V_62 , & V_64 ) ;
V_63:
F_36 ( V_3 . V_2 ) ;
return;
}
