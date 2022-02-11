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
struct V_1 * V_2 = F_12 ( V_20 ) ;
if ( V_2 -> V_10 )
return sprintf ( V_18 , L_4 ) ;
else
return sprintf ( V_18 , L_5 ) ;
}
static T_2 F_13 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
const char * V_18 ,
T_3 V_21 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
if ( strcmp ( V_18 , L_6 ) ) {
F_2 ( V_2 -> V_7 , 1 ) ;
V_2 -> V_10 = V_22 ;
} else {
F_2 ( V_2 -> V_7 , 0 ) ;
V_2 -> V_10 = V_11 ;
}
return V_21 ;
}
static T_2 F_14 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
return sprintf ( V_18 , L_7 ) ;
}
static T_2 F_15 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
return sprintf ( V_18 , L_8 , V_2 -> V_8 ) ;
}
static T_2 F_16 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
const char * V_18 ,
T_3 V_21 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
unsigned long V_3 ;
int V_6 ;
V_6 = F_17 ( V_18 , 10 , & V_3 ) ;
if ( V_6 )
return - V_23 ;
if ( V_3 > V_24 && V_3 != V_25 ) {
F_4 ( & V_2 -> V_5 -> V_9 , L_9 ,
V_3 , V_20 -> V_26 ) ;
return - V_23 ;
} else if ( strcmp ( V_20 -> V_26 , L_10 ) == 0 && V_3 > 1 ) {
F_4 ( & V_2 -> V_5 -> V_9 ,
L_11 , V_3 ) ;
return - V_23 ;
} else if ( strcmp ( V_20 -> V_26 , L_12 ) == 0 && V_3 > 0 ) {
F_4 ( & V_2 -> V_5 -> V_9 ,
L_13 , V_3 ) ;
return - V_23 ;
}
V_2 -> V_8 = V_3 ;
return V_21 ;
}
static T_2 F_18 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
T_1 V_3 ;
T_4 V_27 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_3 ) ;
if ( V_6 )
return - V_28 ;
V_3 >>= V_29 ;
if ( V_2 -> V_8 == 0 ) {
V_27 = ( T_4 ) ( ( V_3 >> V_30 ) - 103 ) ;
V_3 &= V_31 ;
if ( V_27 < 0 )
V_3 = ( 1 << V_30 ) - V_3 ;
return sprintf ( V_18 , L_14 , V_27 , V_3 * 25 ) ;
} else
return sprintf ( V_18 , L_15 , V_3 ) ;
}
static T_5 F_19 ( int V_32 , void * V_33 )
{
F_20 ( V_33 , V_34 , F_21 () ) ;
return V_35 ;
}
static T_2 F_22 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
int V_27 ;
if ( V_2 -> V_8 > V_24 ) {
F_4 ( V_9 , L_16 , V_2 -> V_8 ) ;
return - V_23 ;
} else if ( V_2 -> V_8 == 0 ) {
V_27 = V_36 +
( V_2 -> V_37 [ V_2 -> V_8 ] -
V_38 ) ;
return sprintf ( V_18 , L_8 , V_27 ) ;
} else
return sprintf ( V_18 , L_15 , V_2 -> V_37 [ V_2 -> V_8 ] ) ;
}
static inline T_2 F_23 ( struct V_15 * V_9 ,
struct V_16 * V_17 ,
const char * V_18 ,
T_3 V_21 )
{
struct V_19 * V_20 = F_11 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
long V_27 ;
V_14 V_3 ;
int V_6 ;
V_6 = F_24 ( V_18 , 10 , & V_27 ) ;
if ( V_2 -> V_8 > V_24 ) {
F_4 ( V_9 , L_16 , V_2 -> V_8 ) ;
return - V_23 ;
} else if ( V_2 -> V_8 == 0 ) {
if ( V_6 || V_27 < V_36 ||
V_27 > V_39 )
return - V_23 ;
V_3 = ( V_14 ) ( V_27 - V_36 +
V_38 ) ;
} else {
if ( V_6 || V_27 < V_38 || V_27 > 255 )
return - V_23 ;
V_3 = ( V_14 ) V_27 ;
}
V_6 = F_9 ( V_2 , V_3 ) ;
if ( V_6 )
return - V_28 ;
V_2 -> V_37 [ V_2 -> V_8 ] = V_3 ;
return V_21 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
unsigned short * V_40 = V_5 -> V_9 . V_41 ;
int V_6 = 0 ;
int V_42 ;
if ( ! V_40 ) {
F_4 ( & V_5 -> V_9 , L_17 ) ;
return - V_23 ;
}
V_20 = F_26 ( sizeof( * V_2 ) ) ;
if ( V_20 == NULL ) {
V_6 = - V_43 ;
goto V_44;
}
V_2 = F_12 ( V_20 ) ;
F_27 ( & V_5 -> V_9 , V_20 ) ;
V_2 -> V_5 = V_5 ;
for ( V_42 = 0 ; V_42 <= V_24 ; V_42 ++ )
V_2 -> V_37 [ V_42 ] = 203 ;
V_2 -> V_7 = V_40 [ 0 ] ;
V_2 -> V_12 = V_40 [ 1 ] ;
V_2 -> V_13 = V_40 [ 2 ] ;
V_6 = F_28 ( V_2 -> V_7 , F_29 ( V_5 ) -> V_26 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_9 , L_18 ,
V_2 -> V_7 ) ;
goto V_45;
}
F_30 ( V_2 -> V_7 ) ;
V_6 = F_28 ( V_2 -> V_12 , F_29 ( V_5 ) -> V_26 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_9 , L_19 ,
V_2 -> V_12 ) ;
goto V_46;
}
F_30 ( V_2 -> V_12 ) ;
V_6 = F_28 ( V_2 -> V_13 , F_29 ( V_5 ) -> V_26 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_9 , L_20 ,
V_2 -> V_13 ) ;
goto V_47;
}
F_30 ( V_2 -> V_13 ) ;
V_20 -> V_26 = F_29 ( V_5 ) -> V_26 ;
V_20 -> V_9 . V_48 = & V_5 -> V_9 ;
V_20 -> V_49 = & V_50 ;
V_20 -> V_51 = V_52 ;
if ( V_5 -> V_32 ) {
V_6 = F_31 ( V_5 -> V_32 ,
NULL ,
& F_19 ,
V_53 | V_54 ,
V_20 -> V_26 ,
V_20 ) ;
if ( V_6 )
goto V_55;
}
V_6 = F_32 ( V_20 ) ;
if ( V_6 )
goto V_56;
F_33 ( & V_5 -> V_9 , L_21 ,
V_20 -> V_26 ) ;
return 0 ;
V_56:
F_34 ( V_5 -> V_32 , V_20 ) ;
V_55:
F_35 ( V_2 -> V_13 ) ;
V_47:
F_35 ( V_2 -> V_12 ) ;
V_46:
F_35 ( V_2 -> V_7 ) ;
V_45:
F_36 ( V_20 ) ;
V_44:
return V_6 ;
}
static int F_37 ( struct V_4 * V_5 )
{
struct V_19 * V_20 = F_38 ( & V_5 -> V_9 ) ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
F_39 ( V_20 ) ;
F_27 ( & V_5 -> V_9 , NULL ) ;
if ( V_5 -> V_32 )
F_34 ( V_5 -> V_32 , V_20 ) ;
F_35 ( V_2 -> V_13 ) ;
F_35 ( V_2 -> V_12 ) ;
F_35 ( V_2 -> V_7 ) ;
F_36 ( V_20 ) ;
return 0 ;
}
