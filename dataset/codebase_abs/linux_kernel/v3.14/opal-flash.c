static inline void F_1 ( void )
{
struct V_1 * V_2 = & V_3 ;
V_2 -> V_4 = F_2 ( F_3 ( V_2 -> V_5 ) ,
& ( V_2 -> V_6 ) ,
& ( V_2 -> V_7 ) ) ;
}
static T_1 F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_5 )
{
struct V_1 * V_2 = & V_3 ;
int V_12 ;
if ( V_2 -> V_4 < V_13 ) {
V_12 = sprintf ( V_5 , L_1 , V_2 -> V_4 ) ;
goto V_14;
}
V_12 = sprintf ( V_5 , L_1 , V_2 -> V_7 ) ;
if ( ( V_2 -> V_7 != V_13 ) &&
( V_2 -> V_7 < V_15 ) )
goto V_14;
if ( V_2 -> V_6 > ( V_16 - V_12 ) ) {
memcpy ( V_5 + V_12 , V_2 -> V_5 , V_16 - V_12 ) ;
V_12 = V_16 ;
} else {
memcpy ( V_5 + V_12 , V_2 -> V_5 , V_2 -> V_6 ) ;
V_12 += V_2 -> V_6 ;
}
V_14:
V_2 -> V_4 = V_17 ;
return V_12 ;
}
static T_1 F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_5 , T_2 V_18 )
{
struct V_1 * V_2 = & V_3 ;
if ( V_5 [ 0 ] != '1' )
return - V_19 ;
F_6 ( & V_20 ) ;
if ( V_21 . V_4 != V_22 ||
V_21 . V_23 < V_16 ) {
V_2 -> V_7 = V_24 ;
V_2 -> V_4 = V_25 ;
goto V_14;
}
memcpy ( V_2 -> V_5 , V_21 . V_26 , V_16 ) ;
V_2 -> V_4 = V_27 ;
V_2 -> V_6 = V_16 ;
F_1 () ;
V_14:
F_7 ( & V_20 ) ;
return V_18 ;
}
static inline void F_8 ( T_3 V_28 )
{
struct V_29 * const V_2 = & V_30 ;
V_2 -> V_4 = F_9 ( V_28 ) ;
}
static T_1 F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_5 )
{
struct V_29 * const V_2 = & V_30 ;
int V_31 ;
V_31 = sprintf ( V_5 , L_1 , V_2 -> V_4 ) ;
V_2 -> V_4 = V_17 ;
return V_31 ;
}
static T_1 F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_5 , T_2 V_18 )
{
T_3 V_28 ;
switch ( V_5 [ 0 ] ) {
case '0' :
V_28 = V_32 ;
break;
case '1' :
V_28 = V_33 ;
break;
default:
return - V_19 ;
}
F_8 ( V_28 ) ;
return V_18 ;
}
static void F_12 ( struct V_34 * V_35 )
{
struct V_34 * V_36 ;
while ( V_35 ) {
V_36 = V_35 -> V_37 ;
F_13 ( V_35 ) ;
V_35 = V_36 ;
}
V_35 = NULL ;
}
static struct V_34 * F_14 ( void )
{
struct V_34 * V_36 , * V_35 = NULL ;
void * V_38 ;
int V_23 ;
V_38 = V_21 . V_26 ;
V_23 = V_21 . V_23 ;
V_36 = F_15 ( V_39 , V_40 ) ;
if ( ! V_36 )
return NULL ;
V_35 = V_36 ;
V_36 -> V_41 = 0 ;
while ( V_23 > 0 ) {
V_36 -> V_42 [ V_36 -> V_41 ] . V_26 =
( void * ) ( F_16 ( V_38 ) << V_43 ) ;
if ( V_23 > V_39 )
V_36 -> V_42 [ V_36 -> V_41 ] . V_44 = V_39 ;
else
V_36 -> V_42 [ V_36 -> V_41 ] . V_44 = V_23 ;
V_36 -> V_41 ++ ;
if ( V_36 -> V_41 >= V_45 ) {
V_36 -> V_37 = F_15 ( V_39 , V_40 ) ;
if ( ! V_36 -> V_37 ) {
F_17 ( L_2 ,
V_46 ) ;
goto V_47;
}
V_36 = V_36 -> V_37 ;
V_36 -> V_41 = 0 ;
}
V_38 += V_39 ;
V_23 -= V_39 ;
}
return V_35 ;
V_47:
F_12 ( V_35 ) ;
return NULL ;
}
static int F_18 ( int V_28 )
{
struct V_34 * V_48 , * V_35 , * V_37 ;
unsigned long V_38 ;
T_4 V_31 = V_49 ;
if ( V_28 == V_50 ) {
F_19 ( L_3 ) ;
V_38 = '\0' ;
goto V_51;
}
V_35 = F_14 () ;
if ( ! V_35 )
goto V_52;
V_38 = F_3 ( V_35 ) ;
for ( V_48 = V_35 ; V_48 ; V_48 = V_37 ) {
V_37 = V_48 -> V_37 ;
if ( V_48 -> V_37 )
V_48 -> V_37 = (struct V_34 * ) F_3 ( V_48 -> V_37 ) ;
else
V_48 -> V_37 = NULL ;
V_48 -> V_41 = ( V_53 << 56 ) |
( V_48 -> V_41 * sizeof( struct V_54 ) + 16 ) ;
}
F_19 ( L_4 , V_21 . V_23 ) ;
F_19 ( L_5 ) ;
F_19 ( L_6 ) ;
F_19 ( L_7 ) ;
V_51:
V_31 = F_20 ( V_38 ) ;
V_52:
return V_31 ;
}
static T_1 F_21 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_5 )
{
struct V_55 * const V_2 = & V_56 ;
return sprintf ( V_5 , L_1 , V_2 -> V_4 ) ;
}
static T_1 F_22 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_5 , T_2 V_18 )
{
struct V_55 * const V_2 = & V_56 ;
int V_31 = V_18 ;
F_6 ( & V_20 ) ;
switch ( V_5 [ 0 ] ) {
case '0' :
if ( V_2 -> V_4 == V_57 )
F_18 ( V_50 ) ;
V_2 -> V_4 = V_17 ;
break;
case '1' :
if ( V_21 . V_4 == V_22 )
V_2 -> V_4 =
F_18 ( V_58 ) ;
else
V_2 -> V_4 = V_59 ;
break;
default:
V_31 = - V_19 ;
}
F_7 ( & V_20 ) ;
return V_31 ;
}
static void F_23 ( void )
{
void * V_38 ;
int V_23 ;
V_38 = V_21 . V_26 ;
V_23 = F_24 ( V_21 . V_23 ) ;
while ( V_23 > 0 ) {
F_25 ( F_26 ( V_38 ) ) ;
V_38 += V_39 ;
V_23 -= V_39 ;
}
F_27 ( V_21 . V_26 ) ;
V_21 . V_26 = NULL ;
V_21 . V_4 = V_60 ;
}
static int F_28 ( char * V_61 , T_2 V_18 )
{
void * V_38 ;
int V_23 ;
if ( V_18 < sizeof( struct V_62 ) ) {
F_29 ( L_8 ) ;
return - V_19 ;
}
memcpy ( & V_63 , ( void * ) V_61 , sizeof( struct V_62 ) ) ;
V_21 . V_23 = F_30 ( V_63 . V_23 ) ;
F_31 ( L_9 , V_21 . V_23 ) ;
if ( V_21 . V_23 > V_64 ) {
F_29 ( L_10 ) ;
return - V_19 ;
}
if ( V_21 . V_23 < V_16 ) {
F_29 ( L_11 ) ;
return - V_19 ;
}
V_21 . V_26 = F_32 ( F_24 ( V_21 . V_23 ) ) ;
if ( ! V_21 . V_26 ) {
F_17 ( L_2 , V_46 ) ;
return - V_65 ;
}
V_38 = V_21 . V_26 ;
V_23 = F_24 ( V_21 . V_23 ) ;
while ( V_23 > 0 ) {
F_33 ( F_26 ( V_38 ) ) ;
V_38 += V_39 ;
V_23 -= V_39 ;
}
V_21 . V_4 = V_66 ;
return 0 ;
}
static T_1 F_34 ( struct V_67 * V_68 , struct V_8 * V_9 ,
struct V_69 * V_70 ,
char * V_61 , T_5 V_71 , T_2 V_18 )
{
int V_31 ;
F_6 ( & V_20 ) ;
if ( V_71 == 0 ) {
if ( V_21 . V_26 )
F_23 () ;
if ( V_56 . V_4 == V_57 )
F_18 ( V_50 ) ;
V_31 = F_28 ( V_61 , V_18 ) ;
if ( V_31 )
goto V_14;
}
if ( V_21 . V_4 != V_66 ) {
V_31 = - V_65 ;
goto V_14;
}
if ( ( V_71 + V_18 ) > V_21 . V_23 ) {
V_31 = - V_19 ;
goto V_14;
}
memcpy ( V_21 . V_26 + V_71 , ( void * ) V_61 , V_18 ) ;
V_31 = V_18 ;
if ( ( V_71 + V_18 ) == V_21 . V_23 ) {
F_31 ( L_12 ) ;
V_21 . V_4 = V_22 ;
}
V_14:
F_7 ( & V_20 ) ;
return V_31 ;
}
void T_6 F_35 ( void )
{
int V_72 ;
V_3 . V_5 = F_15 ( V_16 , V_40 ) ;
if ( ! V_3 . V_5 ) {
F_17 ( L_2 , V_46 ) ;
return;
}
if ( ! V_73 ) {
F_29 ( L_13 ) ;
goto V_74;
}
V_72 = F_36 ( V_73 , & V_75 ) ;
if ( V_72 ) {
F_29 ( L_14 ) ;
goto V_74;
}
V_72 = F_37 ( V_73 , & V_76 ) ;
if ( V_72 ) {
F_29 ( L_14 ) ;
goto V_77;
}
V_3 . V_4 = V_17 ;
V_30 . V_4 = V_17 ;
V_56 . V_4 = V_17 ;
V_21 . V_4 = V_60 ;
return;
V_77:
F_38 ( V_73 , & V_75 ) ;
V_74:
F_13 ( V_3 . V_5 ) ;
return;
}
