static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
V_2 -> V_3 = V_1 -> V_4 ;
return 0 ;
}
static const char * F_2 ( int V_5 )
{
switch ( V_5 ) {
case V_6 :
return L_1 ;
case V_7 :
return L_2 ;
case V_8 :
return L_3 ;
case V_9 :
return L_4 ;
case V_10 :
return L_5 ;
case V_11 :
return L_6 ;
default:
return L_7 ;
}
}
static T_1 F_3 ( struct V_2 * V_2 , char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
T_1 V_15 ;
char * V_16 = F_4 ( V_17 , V_18 ) ;
int V_5 = ( int ) V_2 -> V_3 ;
T_5 V_19 , V_20 ;
if ( ! V_16 )
return - V_21 ;
if ( V_22 )
F_5 ( V_22 ) ;
V_20 = F_6 ( V_23 + F_7 ( V_5 ) ) ;
V_19 = F_6 ( V_23 + F_8 ( V_5 ) ) ;
if ( V_22 )
F_9 ( V_22 ) ;
V_15 = snprintf ( V_16 , V_17 , L_8 ,
V_19 , V_20 ) ;
if ( V_20 & V_24 )
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_9 ,
F_2 ( ( V_20 >> 27 ) & 0x7 ) ) ;
else
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_10 ) ;
if ( V_20 & V_25 )
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_11 ,
F_2 ( ( V_20 >> 22 ) & 0x7 ) ) ;
else
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_12 ) ;
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 , L_13 ) ;
if ( V_20 & V_26 ) {
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_14 ) ;
} else {
if ( V_20 & V_27 )
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_15 ,
F_2 ( ( V_20 >> 17 ) & 0x7 ) ) ;
else
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_16 ) ;
if ( V_20 & V_28 )
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_17 ,
F_2 ( ( V_20 >> 12 ) & 0x7 ) ) ;
else
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_18 ) ;
}
V_15 += snprintf ( V_16 + V_15 , V_17 - V_15 ,
L_19 ,
F_2 ( ( V_19 >> 13 ) & 0x7 ) ) ;
V_15 = F_10 ( V_12 , V_13 , V_14 , V_16 , V_15 ) ;
F_11 ( V_16 ) ;
return V_15 ;
}
static void F_12 ( void )
{
int V_29 ;
char V_16 [ 20 ] ;
V_30 = F_13 ( L_20 , NULL ) ;
if ( ! V_30 ) {
F_14 ( L_21 ) ;
return;
}
for ( V_29 = 1 ; V_29 < 8 ; V_29 ++ ) {
snprintf ( V_16 , sizeof( V_16 ) , L_22 , V_29 ) ;
if ( ! F_15 ( V_16 , 0444 , V_30 ,
( void * ) V_29 , & V_31 ) )
F_14 ( L_23 ,
V_29 ) ;
}
}
static inline void F_12 ( void )
{
}
int F_16 ( unsigned int V_5 , unsigned int V_20 ,
unsigned int V_19 )
{
if ( ! V_23 )
return - V_32 ;
if ( V_22 )
F_5 ( V_22 ) ;
F_17 ( V_20 , V_23 + F_7 ( V_5 ) ) ;
F_17 ( V_19 , V_23 + F_8 ( V_5 ) ) ;
if ( V_22 )
F_9 ( V_22 ) ;
return 0 ;
}
static int F_18 ( void )
{
int V_15 ;
if ( F_19 () ) {
V_23 = F_20 ( V_33 ) ;
} else if ( F_21 () ) {
V_23 = F_22 ( V_34 ) ;
} else if ( F_23 () ) {
V_22 = F_24 ( NULL , L_20 ) ;
if ( F_25 ( V_22 ) ) {
V_15 = F_26 ( V_22 ) ;
F_27 ( V_35 L_24 , V_36 ,
V_15 ) ;
return V_15 ;
}
V_23 = F_28 ( V_37 ) ;
} else if ( F_29 () ) {
V_22 = F_24 ( NULL , L_20 ) ;
if ( F_25 ( V_22 ) ) {
V_15 = F_26 ( V_22 ) ;
F_27 ( V_35 L_24 , V_36 ,
V_15 ) ;
return V_15 ;
}
V_23 = F_30 ( V_38 ) ;
}
F_12 () ;
return 0 ;
}
