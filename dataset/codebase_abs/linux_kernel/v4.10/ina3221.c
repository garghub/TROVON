static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_4 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_3 , & V_5 ) ;
if ( V_6 )
return V_6 ;
* V_4 = F_3 ( V_5 >> 3 , 12 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_3 = V_14 -> V_15 ;
int V_4 , V_16 , V_6 ;
V_6 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_16 = V_4 * 8 ;
return snprintf ( V_12 , V_17 , L_1 , V_16 ) ;
}
static T_1 F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_3 = V_14 -> V_15 ;
int V_4 , V_18 , V_6 ;
V_6 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_18 = V_4 * 40 ;
return snprintf ( V_12 , V_17 , L_1 , V_18 ) ;
}
static T_1 F_8 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_3 = V_14 -> V_15 ;
unsigned int V_19 = V_20 [ V_3 ] ;
int V_21 = V_2 -> V_22 [ V_19 ] ;
int V_4 , V_23 , V_24 , V_6 ;
V_6 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_24 = V_4 * 40000 ;
V_23 = F_9 ( V_24 , V_21 ) ;
return snprintf ( V_12 , V_17 , L_1 , V_23 ) ;
}
static T_1 F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_2 V_25 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_3 = V_14 -> V_15 ;
unsigned int V_19 = V_20 [ V_3 ] ;
int V_21 = V_2 -> V_22 [ V_19 ] ;
int V_4 , V_23 , V_18 , V_6 ;
V_6 = F_11 ( V_12 , 0 , & V_23 ) ;
if ( V_6 )
return V_6 ;
V_23 = F_12 ( V_23 ,
V_26 / V_21 ,
V_27 / V_21 ) ;
V_18 = F_9 ( V_23 * V_21 , 1000 ) ;
V_18 = F_12 ( V_18 , - 163800 , 163800 ) ;
V_4 = F_9 ( V_18 , 5 ) & 0xfff8 ;
V_6 = F_13 ( V_2 -> V_7 , V_3 , V_4 ) ;
if ( V_6 )
return V_6 ;
return V_25 ;
}
static T_1 F_14 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_19 = V_14 -> V_15 ;
unsigned int V_21 ;
V_21 = V_2 -> V_22 [ V_19 ] ;
return snprintf ( V_12 , V_17 , L_1 , V_21 ) ;
}
static T_1 F_15 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_2 V_25 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_19 = V_14 -> V_15 ;
int V_4 ;
int V_6 ;
V_6 = F_11 ( V_12 , 0 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_4 = F_12 ( V_4 , 1 , V_27 ) ;
V_2 -> V_22 [ V_19 ] = V_4 ;
return V_25 ;
}
static T_1 F_16 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_28 = V_14 -> V_15 ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_17 ( V_2 -> V_29 [ V_28 ] , & V_5 ) ;
if ( V_6 )
return V_6 ;
return snprintf ( V_12 , V_17 , L_1 , V_5 ) ;
}
static int F_18 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_8 * V_9 = & V_31 -> V_9 ;
struct V_1 * V_2 ;
struct V_8 * V_34 ;
int V_35 , V_6 ;
V_2 = F_19 ( V_9 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_7 = F_20 ( V_31 , & V_38 ) ;
if ( F_21 ( V_2 -> V_7 ) ) {
F_22 ( V_9 , L_2 ) ;
return F_23 ( V_2 -> V_7 ) ;
}
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ ) {
V_2 -> V_29 [ V_35 ] = F_24 ( V_9 ,
V_2 -> V_7 ,
V_40 [ V_35 ] ) ;
if ( F_21 ( V_2 -> V_29 [ V_35 ] ) ) {
F_22 ( V_9 , L_3 ) ;
return F_23 ( V_2 -> V_29 [ V_35 ] ) ;
}
}
for ( V_35 = 0 ; V_35 < V_41 ; V_35 ++ )
V_2 -> V_22 [ V_35 ] = V_42 ;
V_6 = F_25 ( V_2 -> V_29 [ V_43 ] , true ) ;
if ( V_6 ) {
F_22 ( V_9 , L_4 ) ;
return V_6 ;
}
V_34 = F_26 ( V_9 ,
V_31 -> V_44 ,
V_2 , V_45 ) ;
if ( F_21 ( V_34 ) ) {
F_22 ( V_9 , L_5 ) ;
return F_23 ( V_34 ) ;
}
return 0 ;
}
