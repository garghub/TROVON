static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
T_3 V_6 ;
unsigned long V_7 ;
int V_8 = 0 ;
do {
T_2 V_9 = F_2 ( 0 + ( V_8 << 8 ) , V_2 , V_5 ) ;
V_7 = ( 1 << ( V_5 -> V_10 * 8 ) ) - 1 ;
V_6 = F_3 ( V_2 , V_3 + V_9 ) ;
V_8 ++ ;
} while ( ( V_6 . V_11 [ 0 ] & V_7 ) == V_12 );
return V_6 . V_11 [ 0 ] & V_7 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_4 * V_5 )
{
T_3 V_6 ;
unsigned long V_7 ;
T_1 V_9 = F_2 ( 1 , V_2 , V_5 ) ;
V_7 = ( 1 << ( V_5 -> V_10 * 8 ) ) - 1 ;
V_6 = F_3 ( V_2 , V_3 + V_9 ) ;
return V_6 . V_11 [ 0 ] & V_7 ;
}
static void F_5 ( T_1 V_3 , struct V_1 * V_2 , struct V_4 * V_5 )
{
if ( V_5 -> V_13 ) {
F_6 ( V_14 ,
L_1 ,
V_5 -> V_13 , V_5 -> V_15 ) ;
F_7 ( 0xaa , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0x55 , V_5 -> V_15 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
F_7 ( 0xF0 , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0xFF , 0 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_4 * V_5 , int V_16 )
{
int V_17 , V_18 ;
T_4 V_19 ;
if ( ! ( V_20 [ V_16 ] . V_21 & V_5 -> V_10 ) ) {
F_6 ( V_22 , L_2 ,
V_20 [ V_16 ] . V_23 , 4 * ( 1 << V_5 -> V_10 ) ) ;
return 0 ;
}
F_9 ( V_24 L_3 , V_20 [ V_16 ] . V_23 ) ;
V_18 = V_20 [ V_16 ] . V_25 ;
V_5 -> V_26 = F_10 ( sizeof( struct V_27 ) + V_18 * 4 , V_28 ) ;
if ( ! V_5 -> V_26 ) {
return 0 ;
}
memset ( V_5 -> V_26 , 0 , sizeof( struct V_27 ) ) ;
V_5 -> V_26 -> V_29 = V_20 [ V_16 ] . V_30 ;
V_5 -> V_26 -> V_31 = V_20 [ V_16 ] . V_25 ;
V_5 -> V_26 -> V_32 = V_20 [ V_16 ] . V_33 ;
V_5 -> V_34 = V_35 ;
V_5 -> V_36 = F_11 ( 0x30 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_5 -> V_26 -> V_37 [ V_17 ] = V_20 [ V_16 ] . V_38 [ V_17 ] ;
}
V_5 -> V_39 = NULL ;
V_5 -> V_40 = V_20 [ V_16 ] . V_41 ;
V_5 -> V_42 = V_20 [ V_16 ] . V_43 ;
V_19 = V_20 [ V_16 ] . V_19 ;
V_5 -> V_13 = V_44 [ V_19 ] . V_45 / V_5 -> V_10 ;
V_5 -> V_15 = V_44 [ V_19 ] . V_46 / V_5 -> V_10 ;
return 1 ;
}
static inline int F_12 ( T_2 V_3 ,
struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_47 * V_48 )
{
int V_49 = 0 ;
T_1 V_40 , V_42 ;
T_4 V_19 ;
switch ( V_5 -> V_10 ) {
case V_50 :
V_40 = ( T_4 ) V_48 -> V_41 ;
V_42 = ( T_4 ) V_48 -> V_43 ;
if ( V_48 -> V_43 > 0xff ) {
F_6 ( V_14 , L_4 ,
V_51 ) ;
goto V_52;
}
break;
case V_53 :
V_40 = ( V_54 ) V_48 -> V_41 ;
V_42 = ( V_54 ) V_48 -> V_43 ;
break;
case V_55 :
V_40 = ( V_54 ) V_48 -> V_41 ;
V_42 = ( T_2 ) V_48 -> V_43 ;
break;
default:
F_9 ( V_56
L_5 ,
V_51 , V_5 -> V_10 ) ;
goto V_52;
}
if ( V_5 -> V_40 != V_40 || V_5 -> V_42 != V_42 ) {
goto V_52;
}
F_6 ( V_14 ,
L_6 ,
V_51 , V_3 , 1 << V_48 -> V_33 , V_3 + ( 1 << V_48 -> V_33 ) ) ;
if ( V_3 + F_13 ( V_5 ) * ( 1 << V_48 -> V_33 ) > V_2 -> V_57 ) {
F_6 ( V_14 ,
L_7 ,
V_51 , V_48 -> V_41 , V_48 -> V_43 ,
1 << V_48 -> V_33 ) ;
goto V_52;
}
if ( ! ( V_48 -> V_21 & V_5 -> V_10 ) )
goto V_52;
V_19 = V_48 -> V_19 ;
F_6 ( V_14 , L_8 ,
V_51 , V_5 -> V_13 , V_5 -> V_15 ) ;
if ( V_58 != V_19 && V_59 != V_19
&& ( V_44 [ V_19 ] . V_45 / V_5 -> V_10 != V_5 -> V_13 ||
V_44 [ V_19 ] . V_46 / V_5 -> V_10 != V_5 -> V_15 ) ) {
F_6 ( V_14 ,
L_9 ,
V_51 ,
V_44 [ V_19 ] . V_45 ,
V_44 [ V_19 ] . V_46 ) ;
goto V_52;
}
F_6 ( V_14 ,
L_10 ,
V_51 ) ;
F_5 ( V_3 , V_2 , V_5 ) ;
V_40 = F_1 ( V_2 , V_3 , V_5 ) ;
V_42 = F_4 ( V_2 , V_3 , V_5 ) ;
if ( V_40 == V_5 -> V_40 && V_42 == V_5 -> V_42 ) {
F_6 ( V_14 ,
L_11
L_12 ,
V_51 , V_5 -> V_40 , V_5 -> V_42 ) ;
goto V_52;
}
V_49 = 1 ;
F_6 ( V_14 , L_13 , V_51 ) ;
if ( V_5 -> V_13 ) {
F_7 ( 0xaa , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0x55 , V_5 -> V_15 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
F_7 ( 0x90 , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
V_52:
return V_49 ;
}
static int F_14 ( struct V_1 * V_2 , T_5 V_3 ,
unsigned long * V_60 , struct V_4 * V_5 )
{
int V_17 ;
enum V_19 V_61 = V_62 ;
T_1 V_63 , V_64 ;
V_65:
if ( ! V_5 -> V_66 ) {
V_61 ++ ;
if ( V_58 == V_61 )
return 0 ;
V_5 -> V_13 = V_44 [ V_61 ] . V_45 / V_5 -> V_10 ;
V_5 -> V_15 = V_44 [ V_61 ] . V_46 / V_5 -> V_10 ;
}
if ( V_3 >= V_2 -> V_57 ) {
F_9 ( V_67
L_14 ,
V_3 , V_2 -> V_57 - 1 ) ;
return 0 ;
}
V_63 = F_2 ( V_5 -> V_13 , V_2 , V_5 ) ;
V_64 = F_2 ( V_5 -> V_15 , V_2 , V_5 ) ;
if ( ( ( V_3 + V_63 + F_15 ( V_2 ) ) >= V_2 -> V_57 ) ||
( ( V_3 + V_64 + F_15 ( V_2 ) ) >= V_2 -> V_57 ) )
goto V_65;
F_5 ( V_3 , V_2 , V_5 ) ;
if( V_5 -> V_13 ) {
F_7 ( 0xaa , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0x55 , V_5 -> V_15 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
F_7 ( 0x90 , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
if ( ! V_5 -> V_66 ) {
V_5 -> V_40 = F_1 ( V_2 , V_3 , V_5 ) ;
V_5 -> V_42 = F_4 ( V_2 , V_3 , V_5 ) ;
F_6 ( V_14 ,
L_15 ,
V_5 -> V_40 , V_5 -> V_42 , F_13 ( V_5 ) , V_5 -> V_10 ) ;
for ( V_17 = 0 ; V_17 < F_16 ( V_20 ) ; V_17 ++ ) {
if ( F_12 ( V_3 , V_2 , V_5 , & V_20 [ V_17 ] ) ) {
F_6 ( V_14 ,
L_16 ,
V_51 , V_5 -> V_40 , V_5 -> V_42 ,
V_5 -> V_13 , V_5 -> V_15 ) ;
if ( ! F_8 ( V_2 , V_5 , V_17 ) )
return 0 ;
goto V_68;
}
}
goto V_65;
} else {
V_54 V_40 ;
V_54 V_42 ;
V_40 = F_1 ( V_2 , V_3 , V_5 ) ;
V_42 = F_4 ( V_2 , V_3 , V_5 ) ;
if ( ( V_40 != V_5 -> V_40 ) || ( V_42 != V_5 -> V_42 ) ) {
F_9 ( V_69 L_17 ,
V_2 -> V_23 , V_40 , V_42 , V_3 ) ;
F_5 ( V_3 , V_2 , V_5 ) ;
return 0 ;
}
}
for ( V_17 = 0 ; V_17 < ( V_3 >> V_5 -> V_70 ) ; V_17 ++ ) {
unsigned long V_71 ;
if( ! F_17 ( V_17 , V_60 ) ) {
continue;
}
V_71 = V_17 << V_5 -> V_70 ;
if ( F_1 ( V_2 , V_71 , V_5 ) == V_5 -> V_40 &&
F_4 ( V_2 , V_71 , V_5 ) == V_5 -> V_42 ) {
F_5 ( V_71 , V_2 , V_5 ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) != V_5 -> V_40 ||
F_4 ( V_2 , V_3 , V_5 ) != V_5 -> V_42 ) {
F_9 ( V_69 L_18 ,
V_2 -> V_23 , V_3 , V_71 ) ;
return 0 ;
}
F_5 ( V_3 , V_2 , V_5 ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) == V_5 -> V_40 &&
F_4 ( V_2 , V_3 , V_5 ) == V_5 -> V_42 ) {
F_9 ( V_69 L_18 ,
V_2 -> V_23 , V_3 , V_71 ) ;
return 0 ;
}
}
}
F_18 ( ( V_3 >> V_5 -> V_70 ) , V_60 ) ;
V_5 -> V_66 ++ ;
V_68:
F_5 ( V_3 , V_2 , V_5 ) ;
F_9 ( V_24 L_19 ,
V_2 -> V_23 , F_13 ( V_5 ) , V_5 -> V_10 * 8 , V_3 ,
V_2 -> V_72 * 8 ) ;
return 1 ;
}
static struct V_73 * F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , & V_74 ) ;
}
static int T_6 F_21 ( void )
{
F_22 ( & V_75 ) ;
return 0 ;
}
static void T_7 F_23 ( void )
{
F_24 ( & V_75 ) ;
}
