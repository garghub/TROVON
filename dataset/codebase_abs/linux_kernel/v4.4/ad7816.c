static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
T_2 V_7 ;
F_2 ( V_2 -> V_8 , 1 ) ;
F_2 ( V_2 -> V_8 , 0 ) ;
V_6 = F_3 ( V_5 , & V_2 -> V_9 , sizeof( V_2 -> V_9 ) ) ;
if ( V_6 < 0 ) {
F_4 ( & V_5 -> V_10 , L_1 ) ;
return V_6 ;
}
F_2 ( V_2 -> V_8 , 1 ) ;
if ( V_2 -> V_11 == V_12 ) {
F_2 ( V_2 -> V_13 , 1 ) ;
F_2 ( V_2 -> V_13 , 0 ) ;
} else {
F_2 ( V_2 -> V_13 , 0 ) ;
F_2 ( V_2 -> V_13 , 1 ) ;
}
while ( F_5 ( V_2 -> V_14 ) )
F_6 () ;
F_2 ( V_2 -> V_8 , 0 ) ;
F_2 ( V_2 -> V_8 , 1 ) ;
V_6 = F_7 ( V_5 , & V_7 , sizeof( * V_3 ) ) ;
if ( V_6 < 0 ) {
F_4 ( & V_5 -> V_10 , L_2 ) ;
return V_6 ;
}
* V_3 = F_8 ( V_7 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , T_3 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
F_2 ( V_2 -> V_8 , 1 ) ;
F_2 ( V_2 -> V_8 , 0 ) ;
V_6 = F_3 ( V_5 , & V_3 , sizeof( V_3 ) ) ;
if ( V_6 < 0 )
F_4 ( & V_5 -> V_10 , L_3 ) ;
return V_6 ;
}
static T_4 F_10 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
char * V_7 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
if ( V_2 -> V_11 )
return sprintf ( V_7 , L_4 ) ;
return sprintf ( V_7 , L_5 ) ;
}
static T_4 F_13 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
const char * V_7 ,
T_5 V_20 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
if ( strcmp ( V_7 , L_6 ) ) {
F_2 ( V_2 -> V_8 , 1 ) ;
V_2 -> V_11 = V_21 ;
} else {
F_2 ( V_2 -> V_8 , 0 ) ;
V_2 -> V_11 = V_12 ;
}
return V_20 ;
}
static T_4 F_14 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
char * V_7 )
{
return sprintf ( V_7 , L_7 ) ;
}
static T_4 F_15 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
char * V_7 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
return sprintf ( V_7 , L_8 , V_2 -> V_9 ) ;
}
static T_4 F_16 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
const char * V_7 ,
T_5 V_20 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
unsigned long V_3 ;
int V_6 ;
V_6 = F_17 ( V_7 , 10 , & V_3 ) ;
if ( V_6 )
return V_6 ;
if ( V_3 > V_22 && V_3 != V_23 ) {
F_4 ( & V_2 -> V_5 -> V_10 , L_9 ,
V_3 , V_19 -> V_24 ) ;
return - V_25 ;
} else if ( strcmp ( V_19 -> V_24 , L_10 ) == 0 && V_3 > 1 ) {
F_4 ( & V_2 -> V_5 -> V_10 ,
L_11 , V_3 ) ;
return - V_25 ;
} else if ( strcmp ( V_19 -> V_24 , L_12 ) == 0 && V_3 > 0 ) {
F_4 ( & V_2 -> V_5 -> V_10 ,
L_13 , V_3 ) ;
return - V_25 ;
}
V_2 -> V_9 = V_3 ;
return V_20 ;
}
static T_4 F_18 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
char * V_7 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
T_1 V_3 ;
T_6 V_26 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_3 ) ;
if ( V_6 )
return - V_27 ;
V_3 >>= V_28 ;
if ( V_2 -> V_9 == 0 ) {
V_26 = ( T_6 ) ( ( V_3 >> V_29 ) - 103 ) ;
V_3 &= V_30 ;
if ( V_26 < 0 )
V_3 = ( 1 << V_29 ) - V_3 ;
return sprintf ( V_7 , L_14 , V_26 , V_3 * 25 ) ;
}
return sprintf ( V_7 , L_15 , V_3 ) ;
}
static T_7 F_19 ( int V_31 , void * V_32 )
{
F_20 ( V_32 , V_33 , F_21 () ) ;
return V_34 ;
}
static T_4 F_22 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
char * V_7 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
int V_26 ;
if ( V_2 -> V_9 > V_22 ) {
F_4 ( V_10 , L_16 , V_2 -> V_9 ) ;
return - V_25 ;
} else if ( V_2 -> V_9 == 0 ) {
V_26 = V_35 +
( V_2 -> V_36 [ V_2 -> V_9 ] -
V_37 ) ;
return sprintf ( V_7 , L_8 , V_26 ) ;
}
return sprintf ( V_7 , L_15 , V_2 -> V_36 [ V_2 -> V_9 ] ) ;
}
static inline T_4 F_23 ( struct V_15 * V_10 ,
struct V_16 * V_17 ,
const char * V_7 ,
T_5 V_20 )
{
struct V_18 * V_19 = F_11 ( V_10 ) ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
long V_26 ;
T_3 V_3 ;
int V_6 ;
V_6 = F_24 ( V_7 , 10 , & V_26 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_9 > V_22 ) {
F_4 ( V_10 , L_16 , V_2 -> V_9 ) ;
return - V_25 ;
} else if ( V_2 -> V_9 == 0 ) {
if ( V_6 || V_26 < V_35 ||
V_26 > V_38 )
return - V_25 ;
V_3 = ( T_3 ) ( V_26 - V_35 +
V_37 ) ;
} else {
if ( V_6 || V_26 < V_37 || V_26 > 255 )
return - V_25 ;
V_3 = ( T_3 ) V_26 ;
}
V_6 = F_9 ( V_2 , V_3 ) ;
if ( V_6 )
return - V_27 ;
V_2 -> V_36 [ V_2 -> V_9 ] = V_3 ;
return V_20 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
unsigned short * V_39 = V_5 -> V_10 . V_40 ;
int V_6 = 0 ;
int V_41 ;
if ( ! V_39 ) {
F_4 ( & V_5 -> V_10 , L_17 ) ;
return - V_25 ;
}
V_19 = F_26 ( & V_5 -> V_10 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_42 ;
V_2 = F_12 ( V_19 ) ;
F_27 ( & V_5 -> V_10 , V_19 ) ;
V_2 -> V_5 = V_5 ;
for ( V_41 = 0 ; V_41 <= V_22 ; V_41 ++ )
V_2 -> V_36 [ V_41 ] = 203 ;
V_2 -> V_8 = V_39 [ 0 ] ;
V_2 -> V_13 = V_39 [ 1 ] ;
V_2 -> V_14 = V_39 [ 2 ] ;
V_6 = F_28 ( & V_5 -> V_10 , V_2 -> V_8 ,
F_29 ( V_5 ) -> V_24 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_10 , L_18 ,
V_2 -> V_8 ) ;
return V_6 ;
}
F_30 ( V_2 -> V_8 ) ;
V_6 = F_28 ( & V_5 -> V_10 , V_2 -> V_13 ,
F_29 ( V_5 ) -> V_24 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_10 , L_19 ,
V_2 -> V_13 ) ;
return V_6 ;
}
F_30 ( V_2 -> V_13 ) ;
V_6 = F_28 ( & V_5 -> V_10 , V_2 -> V_14 ,
F_29 ( V_5 ) -> V_24 ) ;
if ( V_6 ) {
F_4 ( & V_5 -> V_10 , L_20 ,
V_2 -> V_14 ) ;
return V_6 ;
}
F_30 ( V_2 -> V_14 ) ;
V_19 -> V_24 = F_29 ( V_5 ) -> V_24 ;
V_19 -> V_10 . V_43 = & V_5 -> V_10 ;
V_19 -> V_44 = & V_45 ;
V_19 -> V_46 = V_47 ;
if ( V_5 -> V_31 ) {
V_6 = F_31 ( & V_5 -> V_10 , V_5 -> V_31 ,
NULL ,
& F_19 ,
V_48 | V_49 ,
V_19 -> V_24 ,
V_19 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_32 ( & V_5 -> V_10 , V_19 ) ;
if ( V_6 )
return V_6 ;
F_33 ( & V_5 -> V_10 , L_21 ,
V_19 -> V_24 ) ;
return 0 ;
}
