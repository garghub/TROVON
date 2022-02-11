static const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
default:
return L_7 ;
}
}
static T_1 F_2 ( struct V_8 * V_8 , char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
T_1 V_12 ;
char * V_13 ;
T_5 V_1 = ( T_5 ) V_8 -> V_14 ;
T_6 V_15 , V_16 ;
if ( V_17 ) {
V_12 = F_3 ( V_17 ) ;
if ( V_12 )
return V_12 ;
}
V_16 = F_4 ( V_18 + F_5 ( V_1 ) ) ;
V_15 = F_4 ( V_18 + F_6 ( V_1 ) ) ;
if ( V_17 )
F_7 ( V_17 ) ;
V_13 = F_8 ( V_19 , V_20 ) ;
if ( ! V_13 )
return - V_21 ;
V_12 = snprintf ( V_13 , V_19 , L_8 ,
V_15 , V_16 ) ;
if ( V_16 & V_22 )
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_9 ,
F_1 ( ( V_16 >> 27 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_10 ) ;
if ( V_16 & V_23 )
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_11 ,
F_1 ( ( V_16 >> 22 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_12 ) ;
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 , L_13 ) ;
if ( V_16 & V_24 ) {
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_14 ) ;
} else {
if ( V_16 & V_25 )
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_15 ,
F_1 ( ( V_16 >> 17 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_16 ) ;
if ( V_16 & V_26 )
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_17 ,
F_1 ( ( V_16 >> 12 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_18 ) ;
}
V_12 += snprintf ( V_13 + V_12 , V_19 - V_12 ,
L_19 ,
F_1 ( ( V_15 >> 13 ) & 0x7 ) ) ;
V_12 = F_9 ( V_9 , V_10 , V_11 , V_13 , V_12 ) ;
F_10 ( V_13 ) ;
return V_12 ;
}
static void F_11 ( void )
{
T_5 V_27 ;
char V_13 [ 20 ] ;
V_28 = F_12 ( L_20 , NULL ) ;
if ( ! V_28 ) {
F_13 ( L_21 ) ;
return;
}
for ( V_27 = 0 ; V_27 < V_29 + 1 ; V_27 ++ ) {
snprintf ( V_13 , sizeof( V_13 ) , L_22 , V_27 ) ;
if ( ! F_14 ( V_13 , 0444 , V_28 ,
( void * ) V_27 , & V_30 ) )
F_13 ( L_23 ,
V_27 ) ;
}
}
static void F_15 ( void )
{
F_16 ( V_28 ) ;
}
static inline void F_11 ( void )
{
}
static inline void F_15 ( void )
{
}
int F_17 ( unsigned int V_1 , unsigned int V_31 )
{
if ( V_32 != V_33 )
return - V_34 ;
if ( ! V_18 )
return - V_35 ;
if ( V_1 >= F_18 ( V_36 ) )
return - V_34 ;
F_19 ( V_31 , V_18 + V_36 [ V_1 ] ) ;
return 0 ;
}
int F_20 ( unsigned int V_1 , unsigned int V_16 ,
unsigned int V_15 )
{
int V_12 ;
if ( V_32 != V_37 )
return - V_34 ;
if ( ! V_18 )
return - V_35 ;
if ( V_17 ) {
V_12 = F_3 ( V_17 ) ;
if ( V_12 )
return V_12 ;
}
F_19 ( V_16 , V_18 + F_5 ( V_1 ) ) ;
F_19 ( V_15 , V_18 + F_6 ( V_1 ) ) ;
if ( V_17 )
F_7 ( V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_40 * V_42 ;
F_22 (of_node, child) {
unsigned int V_1 ;
unsigned int V_16 = 0 ;
unsigned int V_15 = 0 ;
unsigned int V_31 = 0 ;
unsigned int V_43 ;
int V_12 ;
int V_27 = 0 ;
V_12 = F_23 ( V_42 , L_24 , & V_1 ) ;
if ( V_12 ) {
F_24 ( & V_39 -> V_44 , L_25 ,
V_42 ) ;
continue;
}
if ( ! F_25 ( V_42 , L_26 ) ) {
F_24 ( & V_39 -> V_44 , L_27 ,
V_42 ) ;
continue;
}
for ( V_27 = 0 ; ( V_12 = F_26 ( V_42 ,
L_26 , V_27 , & V_43 ) ) == 0 ;
++ V_27 ) {
if ( V_32 == V_37 ) {
if ( V_27 % 2 )
V_15 |= V_43 ;
else
V_16 |= V_43 ;
} else {
V_31 |= V_43 ;
}
}
if ( V_12 != - V_45 ) {
F_27 ( & V_39 -> V_44 , L_28 ,
V_27 , V_42 ) ;
continue;
}
if ( V_32 == V_37 ) {
if ( V_27 % 2 ) {
F_27 ( & V_39 -> V_44 , L_29 ,
V_42 ) ;
continue;
}
F_20 ( V_1 , V_16 , V_15 ) ;
} else {
F_17 ( V_1 , V_31 ) ;
}
}
return 0 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_46 * V_47 ;
const struct V_48 * V_49 =
F_29 ( V_50 , & V_39 -> V_44 ) ;
V_47 = F_30 ( V_39 , V_51 , 0 ) ;
V_18 = F_31 ( & V_39 -> V_44 , V_47 ) ;
if ( F_32 ( V_18 ) )
return F_33 ( V_18 ) ;
V_17 = F_34 ( & V_39 -> V_44 , L_20 ) ;
if ( F_32 ( V_17 ) ) {
F_35 ( & V_39 -> V_44 , L_30 ,
F_33 ( V_17 ) ) ;
V_17 = NULL ;
}
if ( V_49 )
V_39 -> V_52 = V_49 -> V_53 ;
V_32 = V_39 -> V_52 -> V_54 ;
if ( V_32 == V_37 )
F_11 () ;
if ( V_49 )
F_21 ( V_39 , V_39 -> V_44 . V_41 ) ;
return 0 ;
}
static int F_36 ( struct V_38 * V_39 )
{
if ( V_32 == V_37 )
F_15 () ;
return 0 ;
}
static int T_7 F_37 ( void )
{
return F_38 ( & V_55 ) ;
}
static void T_8 F_39 ( void )
{
F_40 ( & V_55 ) ;
}
