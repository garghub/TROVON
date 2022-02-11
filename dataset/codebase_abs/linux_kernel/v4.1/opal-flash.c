static inline void F_1 ( void )
{
long V_1 ;
void * V_2 = V_3 . V_2 ;
T_1 V_4 = F_2 ( V_3 . V_5 ) ;
T_1 V_6 ;
V_1 = F_3 ( F_4 ( V_2 ) , & V_4 , & V_6 ) ;
V_3 . V_7 = V_1 ;
V_3 . V_5 = F_5 ( V_4 ) ;
V_3 . V_6 = F_5 ( V_6 ) ;
}
static T_2 F_6 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_2 )
{
struct V_12 * V_13 = & V_3 ;
int V_14 ;
if ( V_13 -> V_7 < V_15 ) {
V_14 = sprintf ( V_2 , L_1 , V_13 -> V_7 ) ;
goto V_16;
}
V_14 = sprintf ( V_2 , L_1 , V_13 -> V_6 ) ;
if ( ( V_13 -> V_6 != V_15 ) &&
( V_13 -> V_6 < V_17 ) )
goto V_16;
if ( V_13 -> V_5 > ( V_18 - V_14 ) ) {
memcpy ( V_2 + V_14 , V_13 -> V_2 , V_18 - V_14 ) ;
V_14 = V_18 ;
} else {
memcpy ( V_2 + V_14 , V_13 -> V_2 , V_13 -> V_5 ) ;
V_14 += V_13 -> V_5 ;
}
V_16:
V_13 -> V_7 = V_19 ;
return V_14 ;
}
static T_2 F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_2 , T_3 V_20 )
{
struct V_12 * V_13 = & V_3 ;
if ( V_2 [ 0 ] != '1' )
return - V_21 ;
F_8 ( & V_22 ) ;
if ( V_23 . V_7 != V_24 ||
V_23 . V_4 < V_18 ) {
V_13 -> V_6 = V_25 ;
V_13 -> V_7 = V_26 ;
goto V_16;
}
memcpy ( V_13 -> V_2 , V_23 . V_27 , V_18 ) ;
V_13 -> V_7 = V_28 ;
V_13 -> V_5 = V_18 ;
F_1 () ;
V_16:
F_9 ( & V_22 ) ;
return V_20 ;
}
static inline void F_10 ( T_4 V_29 )
{
struct V_30 * const V_13 = & V_31 ;
V_13 -> V_7 = F_11 ( V_29 ) ;
}
static T_2 F_12 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_2 )
{
struct V_30 * const V_13 = & V_31 ;
int V_32 ;
V_32 = sprintf ( V_2 , L_1 , V_13 -> V_7 ) ;
V_13 -> V_7 = V_19 ;
return V_32 ;
}
static T_2 F_13 ( struct V_8 * V_9 ,
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
F_10 ( V_29 ) ;
return V_20 ;
}
static int F_14 ( int V_29 )
{
struct V_35 * V_36 ;
unsigned long V_37 ;
T_5 V_32 = V_38 ;
if ( V_29 == V_39 ) {
F_15 ( L_2 ) ;
V_37 = '\0' ;
goto V_40;
}
V_36 = F_16 ( V_23 . V_27 , V_23 . V_4 ) ;
if ( ! V_36 )
goto V_41;
V_37 = F_4 ( V_36 ) ;
V_40:
V_32 = F_17 ( V_37 ) ;
V_41:
return V_32 ;
}
static void F_18 ( void * V_42 )
{
int V_43 = F_19 () ;
if ( ! F_20 ( V_43 ) )
return;
F_21 () ;
F_22 () ;
}
void F_23 ( void )
{
struct V_44 V_45 ;
if ( V_46 . V_7 != V_47 )
return;
F_15 ( L_3 ) ;
F_15 ( L_4 , V_23 . V_4 ) ;
F_15 ( L_5 ) ;
F_15 ( L_6 ) ;
F_24 ( 500 ) ;
F_25 ( & V_45 , V_48 ) ;
F_26 ( F_19 () , & V_45 ) ;
if ( ! F_27 ( & V_45 ) )
F_28 ( & V_45 ,
F_18 , NULL , false ) ;
F_21 () ;
}
static T_2 F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_2 )
{
struct V_49 * const V_13 = & V_46 ;
return sprintf ( V_2 , L_1 , V_13 -> V_7 ) ;
}
static T_2 F_30 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_2 , T_3 V_20 )
{
struct V_49 * const V_13 = & V_46 ;
int V_32 = V_20 ;
F_8 ( & V_22 ) ;
switch ( V_2 [ 0 ] ) {
case '0' :
if ( V_13 -> V_7 == V_47 )
F_14 ( V_39 ) ;
V_13 -> V_7 = V_19 ;
break;
case '1' :
if ( V_23 . V_7 == V_24 )
V_13 -> V_7 =
F_14 ( V_50 ) ;
else
V_13 -> V_7 = V_51 ;
break;
default:
V_32 = - V_21 ;
}
F_9 ( & V_22 ) ;
return V_32 ;
}
static void F_31 ( void )
{
void * V_37 ;
int V_4 ;
V_37 = V_23 . V_27 ;
V_4 = F_32 ( V_23 . V_4 ) ;
while ( V_4 > 0 ) {
F_33 ( F_34 ( V_37 ) ) ;
V_37 += V_52 ;
V_4 -= V_52 ;
}
F_35 ( V_23 . V_27 ) ;
V_23 . V_27 = NULL ;
V_23 . V_7 = V_53 ;
}
static int F_36 ( char * V_54 , T_3 V_20 )
{
void * V_37 ;
int V_4 ;
if ( V_20 < sizeof( struct V_55 ) ) {
F_37 ( L_7 ) ;
return - V_21 ;
}
memcpy ( & V_56 , ( void * ) V_54 , sizeof( struct V_55 ) ) ;
V_23 . V_4 = F_5 ( V_56 . V_4 ) ;
F_38 ( L_8 , V_23 . V_4 ) ;
if ( V_23 . V_4 > V_57 ) {
F_37 ( L_9 ) ;
return - V_21 ;
}
if ( V_23 . V_4 < V_18 ) {
F_37 ( L_10 ) ;
return - V_21 ;
}
V_23 . V_27 = F_39 ( F_32 ( V_23 . V_4 ) ) ;
if ( ! V_23 . V_27 ) {
F_40 ( L_11 , V_58 ) ;
return - V_59 ;
}
V_37 = V_23 . V_27 ;
V_4 = F_32 ( V_23 . V_4 ) ;
while ( V_4 > 0 ) {
F_41 ( F_34 ( V_37 ) ) ;
V_37 += V_52 ;
V_4 -= V_52 ;
}
V_23 . V_7 = V_60 ;
return 0 ;
}
static T_2 F_42 ( struct V_61 * V_62 , struct V_8 * V_9 ,
struct V_63 * V_64 ,
char * V_54 , T_6 V_65 , T_3 V_20 )
{
int V_32 ;
F_8 ( & V_22 ) ;
if ( V_65 == 0 ) {
if ( V_23 . V_27 )
F_31 () ;
if ( V_46 . V_7 == V_47 )
F_14 ( V_39 ) ;
V_32 = F_36 ( V_54 , V_20 ) ;
if ( V_32 )
goto V_16;
}
if ( V_23 . V_7 != V_60 ) {
V_32 = - V_59 ;
goto V_16;
}
if ( ( V_65 + V_20 ) > V_23 . V_4 ) {
V_32 = - V_21 ;
goto V_16;
}
memcpy ( V_23 . V_27 + V_65 , ( void * ) V_54 , V_20 ) ;
V_32 = V_20 ;
if ( ( V_65 + V_20 ) == V_23 . V_4 ) {
F_38 ( L_12 ) ;
V_23 . V_7 = V_24 ;
}
V_16:
F_9 ( & V_22 ) ;
return V_32 ;
}
void T_7 F_43 ( void )
{
int V_1 ;
V_3 . V_2 = F_44 ( V_18 , V_66 ) ;
if ( ! V_3 . V_2 ) {
F_40 ( L_11 , V_58 ) ;
return;
}
if ( ! V_67 ) {
F_37 ( L_13 ) ;
goto V_68;
}
V_1 = F_45 ( V_67 , & V_69 ) ;
if ( V_1 ) {
F_37 ( L_14 ) ;
goto V_68;
}
V_1 = F_46 ( V_67 , & V_70 ) ;
if ( V_1 ) {
F_37 ( L_14 ) ;
goto V_71;
}
V_3 . V_7 = V_19 ;
V_31 . V_7 = V_19 ;
V_46 . V_7 = V_19 ;
V_23 . V_7 = V_53 ;
return;
V_71:
F_47 ( V_67 , & V_69 ) ;
V_68:
F_48 ( V_3 . V_2 ) ;
return;
}
