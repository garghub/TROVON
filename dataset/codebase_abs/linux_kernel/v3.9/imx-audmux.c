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
char * V_13 = F_3 ( V_14 , V_15 ) ;
int V_1 = ( int ) V_8 -> V_16 ;
T_5 V_17 , V_18 ;
if ( ! V_13 )
return - V_19 ;
if ( V_20 )
F_4 ( V_20 ) ;
V_18 = F_5 ( V_21 + F_6 ( V_1 ) ) ;
V_17 = F_5 ( V_21 + F_7 ( V_1 ) ) ;
if ( V_20 )
F_8 ( V_20 ) ;
V_12 = snprintf ( V_13 , V_14 , L_8 ,
V_17 , V_18 ) ;
if ( V_18 & V_22 )
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_9 ,
F_1 ( ( V_18 >> 27 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_10 ) ;
if ( V_18 & V_23 )
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_11 ,
F_1 ( ( V_18 >> 22 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_12 ) ;
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 , L_13 ) ;
if ( V_18 & V_24 ) {
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_14 ) ;
} else {
if ( V_18 & V_25 )
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_15 ,
F_1 ( ( V_18 >> 17 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_16 ) ;
if ( V_18 & V_26 )
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_17 ,
F_1 ( ( V_18 >> 12 ) & 0x7 ) ) ;
else
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_18 ) ;
}
V_12 += snprintf ( V_13 + V_12 , V_14 - V_12 ,
L_19 ,
F_1 ( ( V_17 >> 13 ) & 0x7 ) ) ;
V_12 = F_9 ( V_9 , V_10 , V_11 , V_13 , V_12 ) ;
F_10 ( V_13 ) ;
return V_12 ;
}
static void T_6 F_11 ( void )
{
int V_27 ;
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
if ( ! V_21 )
return - V_35 ;
if ( V_1 >= F_18 ( V_36 ) )
return - V_34 ;
F_19 ( V_31 , V_21 + V_36 [ V_1 ] ) ;
return 0 ;
}
int F_20 ( unsigned int V_1 , unsigned int V_18 ,
unsigned int V_17 )
{
if ( V_32 != V_37 )
return - V_34 ;
if ( ! V_21 )
return - V_35 ;
if ( V_20 )
F_4 ( V_20 ) ;
F_19 ( V_18 , V_21 + F_6 ( V_1 ) ) ;
F_19 ( V_17 , V_21 + F_7 ( V_1 ) ) ;
if ( V_20 )
F_8 ( V_20 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_42 ;
const struct V_43 * V_44 =
F_22 ( V_45 , & V_39 -> V_46 ) ;
V_41 = F_23 ( V_39 , V_47 , 0 ) ;
V_21 = F_24 ( & V_39 -> V_46 , V_41 ) ;
if ( F_25 ( V_21 ) )
return F_26 ( V_21 ) ;
V_42 = F_27 ( & V_39 -> V_46 ) ;
if ( F_25 ( V_42 ) ) {
F_28 ( & V_39 -> V_46 , L_24 ) ;
return F_26 ( V_42 ) ;
}
V_20 = F_29 ( & V_39 -> V_46 , L_20 ) ;
if ( F_25 ( V_20 ) ) {
F_30 ( & V_39 -> V_46 , L_25 ,
F_26 ( V_20 ) ) ;
V_20 = NULL ;
}
if ( V_44 )
V_39 -> V_48 = V_44 -> V_49 ;
V_32 = V_39 -> V_48 -> V_50 ;
if ( V_32 == V_37 )
F_11 () ;
return 0 ;
}
static int F_31 ( struct V_38 * V_39 )
{
if ( V_32 == V_37 )
F_15 () ;
F_32 ( V_20 ) ;
return 0 ;
}
static int T_6 F_33 ( void )
{
return F_34 ( & V_51 ) ;
}
static void T_7 F_35 ( void )
{
F_36 ( & V_51 ) ;
}
