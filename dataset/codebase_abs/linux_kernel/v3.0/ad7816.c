static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
F_2 ( V_2 -> V_7 , 1 ) ;
F_2 ( V_2 -> V_7 , 0 ) ;
V_6 = F_3 ( V_5 , & V_2 -> V_8 , sizeof( V_2 -> V_8 ) ) ;
if ( V_6 < 0 ) {
F_4 ( & V_5 -> V_9 , L_1 ) ;
return V_6 ;
}
F_2 ( V_2 -> V_7 , 1 ) ;
if ( V_2 -> V_10 == V_11 ) {
F_2 ( V_2 -> V_12 , 1 ) ;
F_2 ( V_2 -> V_12 , 0 ) ;
} else {
F_2 ( V_2 -> V_12 , 0 ) ;
F_2 ( V_2 -> V_12 , 1 ) ;
}
while ( F_5 ( V_2 -> V_13 ) )
F_6 () ;
F_2 ( V_2 -> V_7 , 0 ) ;
F_2 ( V_2 -> V_7 , 1 ) ;
V_6 = F_7 ( V_5 , ( V_14 * ) V_3 , sizeof( * V_3 ) ) ;
if ( V_6 < 0 ) {
F_4 ( & V_5 -> V_9 , L_2 ) ;
return V_6 ;
}
* V_3 = F_8 ( * V_3 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , V_14 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
F_2 ( V_2 -> V_7 , 1 ) ;
F_2 ( V_2 -> V_7 , 0 ) ;
V_6 = F_3 ( V_5 , & V_3 , sizeof( V_3 ) ) ;
if ( V_6 < 0 )
F_4 ( & V_5 -> V_9 , L_3 ) ;
return V_6 ;
}
static T_2 F_10 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
if ( V_2 -> V_10 )
return sprintf ( V_18 , L_4 ) ;
else
return sprintf ( V_18 , L_5 ) ;
}
static T_2 F_12 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
const char * V_18 ,
T_3 V_22 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
if ( strcmp ( V_18 , L_6 ) ) {
F_2 ( V_2 -> V_7 , 1 ) ;
V_2 -> V_10 = V_23 ;
} else {
F_2 ( V_2 -> V_7 , 0 ) ;
V_2 -> V_10 = V_11 ;
}
return V_22 ;
}
static T_2 F_13 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
return sprintf ( V_18 , L_7 ) ;
}
static T_2 F_14 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_18 , L_8 , V_2 -> V_8 ) ;
}
static T_2 F_15 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
const char * V_18 ,
T_3 V_22 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_3 ;
int V_6 ;
V_6 = F_16 ( V_18 , 10 , & V_3 ) ;
if ( V_6 )
return - V_24 ;
if ( V_3 > V_25 && V_3 != V_26 ) {
F_4 ( & V_2 -> V_5 -> V_9 , L_9 ,
V_3 , V_20 -> V_27 ) ;
return - V_24 ;
} else if ( strcmp ( V_20 -> V_27 , L_10 ) == 0 && V_3 > 1 ) {
F_4 ( & V_2 -> V_5 -> V_9 ,
L_11 , V_3 ) ;
return - V_24 ;
} else if ( strcmp ( V_20 -> V_27 , L_12 ) == 0 && V_3 > 0 ) {
F_4 ( & V_2 -> V_5 -> V_9 ,
L_13 , V_3 ) ;
return - V_24 ;
}
V_2 -> V_8 = V_3 ;
return V_22 ;
}
static T_2 F_17 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_3 ;
T_4 V_28 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_3 ) ;
if ( V_6 )
return - V_29 ;
V_3 >>= V_30 ;
if ( V_2 -> V_8 == 0 ) {
V_28 = ( T_4 ) ( ( V_3 >> V_31 ) - 103 ) ;
V_3 &= V_32 ;
if ( V_28 < 0 )
V_3 = ( 1 << V_31 ) - V_3 ;
return sprintf ( V_18 , L_14 , V_28 , V_3 * 25 ) ;
} else
return sprintf ( V_18 , L_15 , V_3 ) ;
}
static T_5 F_18 ( int V_33 , void * V_34 )
{
F_19 ( V_34 , 0 ,
V_35 ,
F_20 () ) ;
return V_36 ;
}
static T_2 F_21 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
int V_28 ;
if ( V_2 -> V_8 > V_25 ) {
F_4 ( V_9 , L_16 , V_2 -> V_8 ) ;
return - V_24 ;
} else if ( V_2 -> V_8 == 0 ) {
V_28 = V_37 +
( V_2 -> V_38 [ V_2 -> V_8 ] -
V_39 ) ;
return sprintf ( V_18 , L_8 , V_28 ) ;
} else
return sprintf ( V_18 , L_15 , V_2 -> V_38 [ V_2 -> V_8 ] ) ;
}
static inline T_2 F_22 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
const char * V_18 ,
T_3 V_22 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
long V_28 ;
V_14 V_3 ;
int V_6 ;
V_6 = F_23 ( V_18 , 10 , & V_28 ) ;
if ( V_2 -> V_8 > V_25 ) {
F_4 ( V_9 , L_16 , V_2 -> V_8 ) ;
return - V_24 ;
} else if ( V_2 -> V_8 == 0 ) {
if ( V_6 || V_28 < V_37 ||
V_28 > V_40 )
return - V_24 ;
V_3 = ( V_14 ) ( V_28 - V_37 +
V_39 ) ;
} else {
if ( V_6 || V_28 < V_39 || V_28 > 255 )
return - V_24 ;
V_3 = ( V_14 ) V_28 ;
}
V_6 = F_9 ( V_2 , V_3 ) ;
if ( V_6 )
return - V_29 ;
V_2 -> V_38 [ V_2 -> V_8 ] = V_3 ;
return V_22 ;
}
static int T_6 F_24 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned short * V_41 = V_5 -> V_9 . V_42 ;
int V_6 = 0 ;
int V_43 ;
if ( ! V_41 ) {
F_4 ( & V_5 -> V_9 , L_17 ) ;
return - V_24 ;
}
V_2 = F_25 ( sizeof( struct V_1 ) , V_44 ) ;
if ( V_2 == NULL )
return - V_45 ;
F_26 ( & V_5 -> V_9 , V_2 ) ;
V_2 -> V_5 = V_5 ;
for ( V_43 = 0 ; V_43 <= V_25 ; V_43 ++ )
V_2 -> V_38 [ V_43 ] = 203 ;
V_2 -> V_7 = V_41 [ 0 ] ;
V_2 -> V_12 = V_41 [ 1 ] ;
V_2 -> V_13 = V_41 [ 2 ] ;
V_6 = F_27 ( V_2 -> V_7 , F_28 ( V_5 ) -> V_27 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_9 , L_18 ,
V_2 -> V_7 ) ;
goto V_46;
}
F_29 ( V_2 -> V_7 ) ;
V_6 = F_27 ( V_2 -> V_12 , F_28 ( V_5 ) -> V_27 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_9 , L_19 ,
V_2 -> V_12 ) ;
goto V_47;
}
F_29 ( V_2 -> V_12 ) ;
V_6 = F_27 ( V_2 -> V_13 , F_28 ( V_5 ) -> V_27 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_9 , L_20 ,
V_2 -> V_13 ) ;
goto V_48;
}
F_29 ( V_2 -> V_13 ) ;
V_2 -> V_49 = F_30 ( 0 ) ;
if ( V_2 -> V_49 == NULL ) {
V_6 = - V_45 ;
goto V_50;
}
V_2 -> V_49 -> V_27 = F_28 ( V_5 ) -> V_27 ;
V_2 -> V_49 -> V_9 . V_51 = & V_5 -> V_9 ;
V_2 -> V_49 -> V_52 = & V_53 ;
V_2 -> V_49 -> V_21 = ( void * ) V_2 ;
V_2 -> V_49 -> V_54 = V_55 ;
V_6 = F_31 ( V_2 -> V_49 ) ;
if ( V_6 )
goto V_56;
if ( V_5 -> V_33 ) {
V_6 = F_32 ( V_5 -> V_33 ,
NULL ,
& F_18 ,
V_57 ,
V_2 -> V_49 -> V_27 ,
V_2 -> V_49 ) ;
if ( V_6 )
goto V_58;
}
V_20 ( & V_5 -> V_9 , L_21 ,
V_2 -> V_49 -> V_27 ) ;
return 0 ;
V_58:
F_33 ( V_2 -> V_49 ) ;
V_56:
F_34 ( V_2 -> V_49 ) ;
V_50:
F_35 ( V_2 -> V_13 ) ;
V_48:
F_35 ( V_2 -> V_12 ) ;
V_47:
F_35 ( V_2 -> V_7 ) ;
V_46:
F_36 ( V_2 ) ;
return V_6 ;
}
static int T_7 F_37 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_11 ( & V_5 -> V_9 ) ;
struct V_19 * V_49 = V_2 -> V_49 ;
F_26 ( & V_5 -> V_9 , NULL ) ;
if ( V_5 -> V_33 )
F_38 ( V_5 -> V_33 , V_49 ) ;
F_33 ( V_49 ) ;
F_34 ( V_2 -> V_49 ) ;
F_35 ( V_2 -> V_13 ) ;
F_35 ( V_2 -> V_12 ) ;
F_35 ( V_2 -> V_7 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static T_8 int F_39 ( void )
{
return F_40 ( & V_59 ) ;
}
static T_9 void F_41 ( void )
{
F_42 ( & V_59 ) ;
}
