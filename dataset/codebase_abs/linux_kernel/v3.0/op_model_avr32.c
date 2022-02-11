static void F_1 ( void )
{
F_2 ( V_1 , ( F_3 ( V_2 )
| F_3 ( V_3 )
| F_3 ( V_4 )
| F_3 ( V_5 )
| F_3 ( V_6 ) ) ) ;
}
static T_1 F_4 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_11 * V_12 ;
T_2 V_13 ;
if ( F_5 ( ! ( F_6 ( V_14 )
& ( 1 << V_15 ) ) ) )
return V_16 ;
V_12 = F_7 () ;
V_13 = F_8 ( V_1 ) ;
F_2 ( V_1 , V_13 ) ;
if ( V_10 -> V_17 && ( V_13 & V_10 -> V_18 ) ) {
F_2 ( V_19 , - V_10 -> V_20 ) ;
F_9 ( V_12 , V_19 ) ;
}
V_10 ++ ;
if ( V_10 -> V_17 && ( V_13 & V_10 -> V_18 ) ) {
F_2 ( V_21 , - V_10 -> V_20 ) ;
F_9 ( V_12 , V_21 ) ;
}
V_10 ++ ;
if ( V_10 -> V_17 && ( V_13 & V_10 -> V_18 ) ) {
F_2 ( V_22 , - V_10 -> V_20 ) ;
F_9 ( V_12 , V_22 ) ;
}
return V_23 ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_26 * V_28 ;
unsigned int V_29 ;
char V_30 [ 4 ] ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
snprintf ( V_30 , sizeof( V_30 ) , L_1 , V_29 ) ;
V_28 = F_11 ( V_25 , V_27 , V_30 ) ;
F_12 ( V_25 , V_28 , L_2 ,
& V_32 [ V_29 ] . V_17 ) ;
F_12 ( V_25 , V_28 , L_3 ,
& V_32 [ V_29 ] . V_33 ) ;
F_12 ( V_25 , V_28 , L_4 ,
& V_32 [ V_29 ] . V_20 ) ;
F_12 ( V_25 , V_28 , L_5 ,
& V_32 [ V_29 ] . V_34 ) ;
F_12 ( V_25 , V_28 , L_6 ,
& V_32 [ V_29 ] . V_35 ) ;
F_12 ( V_25 , V_28 , L_7 ,
& V_32 [ V_29 ] . V_36 ) ;
}
return 0 ;
}
static int F_13 ( void )
{
struct V_9 * V_10 ;
T_2 V_13 ;
int V_37 ;
int V_29 ;
F_14 ( L_8 ) ;
if ( F_8 ( V_1 ) & F_3 ( V_38 ) ) {
F_15 ( V_39
L_9 ) ;
return - V_40 ;
}
V_37 = F_16 ( V_14 ,
F_4 , V_41 ,
L_10 , V_32 ) ;
if ( V_37 )
return V_37 ;
F_1 () ;
V_13 = 0 ;
for ( V_29 = V_19 ; V_29 < V_31 ; V_29 ++ ) {
V_10 = & V_32 [ V_29 ] ;
if ( ! V_10 -> V_17 )
continue;
F_14 ( L_11 , V_29 ) ;
V_13 |= V_10 -> V_42 ;
switch ( V_29 ) {
case V_19 :
F_2 ( V_19 , - V_10 -> V_20 ) ;
break;
case V_21 :
V_13 |= F_17 ( V_43 , V_10 -> V_33 ) ;
F_2 ( V_21 , - V_10 -> V_20 ) ;
break;
case V_22 :
V_13 |= F_17 ( V_44 , V_10 -> V_33 ) ;
F_2 ( V_22 , - V_10 -> V_20 ) ;
break;
}
}
F_14 ( L_12 , V_13 ) ;
F_2 ( V_1 , V_13 ) ;
return 0 ;
}
static void F_18 ( void )
{
F_14 ( L_13 ) ;
F_1 () ;
F_19 ( V_14 , V_32 ) ;
}
static int F_20 ( void )
{
F_14 ( L_14 ) ;
F_2 ( V_1 , F_8 ( V_1 ) | F_3 ( V_38 ) ) ;
return 0 ;
}
static void F_21 ( void )
{
F_14 ( L_15 ) ;
F_2 ( V_1 , F_8 ( V_1 ) & ~ F_3 ( V_38 ) ) ;
}
int T_3 F_22 ( struct V_45 * V_46 )
{
if ( ! ( V_47 . V_48 & V_49 ) )
return - V_50 ;
memcpy ( V_46 , & V_51 ,
sizeof( struct V_45 ) ) ;
V_46 -> V_52 = V_53 ;
F_15 ( V_54 L_16 ) ;
return 0 ;
}
void F_23 ( void )
{
}
