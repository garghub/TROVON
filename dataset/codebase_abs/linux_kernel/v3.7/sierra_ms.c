static bool F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 >= 0x2100 && V_2 -> V_3 <= 0x2FFF ) ||
( V_2 -> V_3 >= 0x7100 && V_2 -> V_3 <= 0x7FFF ) )
return true ;
else
return false ;
}
static int F_2 ( struct V_4 * V_5 , T_1 V_6 )
{
int V_7 ;
F_3 ( L_1 , L_2 ) ;
V_7 = F_4 ( V_5 , F_5 ( V_5 , 0 ) ,
V_8 ,
V_9 | V_10 ,
V_6 ,
0x0000 ,
NULL ,
0 ,
V_11 ) ;
return V_7 ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
int V_7 ;
F_3 ( L_3 ) ;
V_7 = F_4 ( V_5 , F_7 ( V_5 , 0 ) ,
V_12 ,
V_9 | V_13 ,
0 ,
0 ,
( void * ) V_2 ,
sizeof( struct V_1 ) ,
V_11 ) ;
V_2 -> V_3 = F_8 ( V_2 -> V_3 ) ;
V_2 -> V_14 = F_8 ( V_2 -> V_14 ) ;
return V_7 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_3 ( L_4 , V_2 -> V_15 ) ;
F_3 ( L_5 , V_2 -> V_3 ) ;
F_3 ( L_6 , V_2 -> V_14 ) ;
}
static T_2 F_10 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = F_11 ( V_17 ) ;
struct V_4 * V_5 = F_12 ( V_22 ) ;
int V_7 ;
if ( V_23 == V_24 ) {
V_7 = snprintf ( V_20 , V_25 , L_7 ) ;
} else {
V_2 = F_13 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 ) {
F_3 ( L_8 ) ;
snprintf ( V_20 , V_25 , L_9 ) ;
return - V_27 ;
}
V_7 = F_6 ( V_5 , V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( L_10 ) ;
F_14 ( V_2 ) ;
snprintf ( V_20 , V_25 , L_9 ) ;
return - V_28 ;
}
F_9 ( V_2 ) ;
V_7 = snprintf ( V_20 , V_25 ,
L_11 ,
V_2 -> V_15 ,
V_2 -> V_3 ,
V_2 -> V_14 ) ;
F_14 ( V_2 ) ;
}
return V_7 ;
}
int F_15 ( struct V_29 * V_30 )
{
int V_7 , V_31 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_32 * V_33 ;
V_31 = 3 ;
V_7 = 0 ;
V_5 = V_30 -> V_34 ;
V_33 = F_16 ( V_30 ) ;
F_17 ( V_33 ) ;
F_3 ( L_12 ) ;
if ( V_23 == V_35 ) {
F_3 ( L_1 , L_13 ) ;
V_7 = F_2 ( V_5 , V_36 ) ;
if ( V_7 < 0 )
F_3 ( L_14 ) ;
return - V_28 ;
}
else if ( V_23 == V_24 ) {
F_3 ( L_1 , L_15 ) ;
goto V_37;
}
else {
F_3 ( L_1 , L_16 ) ;
V_2 = F_13 ( sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_2 ) {
F_3 ( L_1 , L_17 ) ;
return - V_27 ;
}
V_31 = 3 ;
do {
V_31 -- ;
V_7 = F_6 ( V_5 , V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( L_1 , L_18 ) ;
F_18 ( 2 * V_38 ) ;
}
} while ( V_31 && V_7 < 0 );
if ( V_7 < 0 ) {
F_3 ( L_1 ,
L_19 ) ;
F_14 ( V_2 ) ;
return - V_28 ;
}
F_9 ( V_2 ) ;
if ( ! F_1 ( V_2 ) ) {
F_3 ( L_1 ,
L_20 ) ;
V_7 = F_2 ( V_5 ,
V_36 ) ;
if ( V_7 < 0 )
F_3 ( L_21 ) ;
F_14 ( V_2 ) ;
return - V_28 ;
}
F_14 ( V_2 ) ;
}
V_37:
V_7 = F_19 ( & V_30 -> V_39 -> V_17 , & V_40 ) ;
return 0 ;
}
