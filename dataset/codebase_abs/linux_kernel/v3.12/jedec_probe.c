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
F_6 ( L_1 ,
V_5 -> V_13 , V_5 -> V_14 ) ;
F_7 ( 0xaa , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0x55 , V_5 -> V_14 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
F_7 ( 0xF0 , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0xFF , 0 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_4 * V_5 , int V_15 )
{
int V_16 , V_17 ;
T_4 V_18 ;
if ( ! ( V_19 [ V_15 ] . V_20 & V_5 -> V_10 ) ) {
F_6 ( L_2 ,
V_19 [ V_15 ] . V_21 , 4 * ( 1 << V_5 -> V_10 ) ) ;
return 0 ;
}
F_9 ( V_22 L_3 , V_19 [ V_15 ] . V_21 ) ;
V_17 = V_19 [ V_15 ] . V_23 ;
V_5 -> V_24 = F_10 ( sizeof( struct V_25 ) + V_17 * 4 , V_26 ) ;
if ( ! V_5 -> V_24 ) {
return 0 ;
}
memset ( V_5 -> V_24 , 0 , sizeof( struct V_25 ) ) ;
V_5 -> V_24 -> V_27 = V_19 [ V_15 ] . V_28 ;
V_5 -> V_24 -> V_29 = V_19 [ V_15 ] . V_23 ;
V_5 -> V_24 -> V_30 = V_19 [ V_15 ] . V_31 ;
V_5 -> V_32 = V_33 ;
V_5 -> V_34 = F_11 ( 0x30 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_5 -> V_24 -> V_35 [ V_16 ] = V_19 [ V_15 ] . V_36 [ V_16 ] ;
}
V_5 -> V_37 = NULL ;
V_5 -> V_38 = V_19 [ V_15 ] . V_39 ;
V_5 -> V_40 = V_19 [ V_15 ] . V_41 ;
V_18 = V_19 [ V_15 ] . V_18 ;
V_5 -> V_13 = V_42 [ V_18 ] . V_43 / V_5 -> V_10 ;
V_5 -> V_14 = V_42 [ V_18 ] . V_44 / V_5 -> V_10 ;
return 1 ;
}
static inline int F_12 ( T_2 V_3 ,
struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_45 * V_46 )
{
int V_47 = 0 ;
T_1 V_38 , V_40 ;
T_4 V_18 ;
switch ( V_5 -> V_10 ) {
case V_48 :
V_38 = ( T_4 ) V_46 -> V_39 ;
V_40 = ( T_4 ) V_46 -> V_41 ;
if ( V_46 -> V_41 > 0xff ) {
F_6 ( L_4 ,
V_49 ) ;
goto V_50;
}
break;
case V_51 :
V_38 = ( V_52 ) V_46 -> V_39 ;
V_40 = ( V_52 ) V_46 -> V_41 ;
break;
case V_53 :
V_38 = ( V_52 ) V_46 -> V_39 ;
V_40 = ( T_2 ) V_46 -> V_41 ;
break;
default:
F_9 ( V_54
L_5 ,
V_49 , V_5 -> V_10 ) ;
goto V_50;
}
if ( V_5 -> V_38 != V_38 || V_5 -> V_40 != V_40 ) {
goto V_50;
}
F_6 ( L_6 ,
V_49 , V_3 , 1 << V_46 -> V_31 , V_3 + ( 1 << V_46 -> V_31 ) ) ;
if ( V_3 + F_13 ( V_5 ) * ( 1 << V_46 -> V_31 ) > V_2 -> V_55 ) {
F_6 ( L_7 ,
V_49 , V_46 -> V_39 , V_46 -> V_41 ,
1 << V_46 -> V_31 ) ;
goto V_50;
}
if ( ! ( V_46 -> V_20 & V_5 -> V_10 ) )
goto V_50;
V_18 = V_46 -> V_18 ;
F_6 ( L_8 ,
V_49 , V_5 -> V_13 , V_5 -> V_14 ) ;
if ( V_56 != V_18 && V_57 != V_18
&& ( V_42 [ V_18 ] . V_43 / V_5 -> V_10 != V_5 -> V_13 ||
V_42 [ V_18 ] . V_44 / V_5 -> V_10 != V_5 -> V_14 ) ) {
F_6 ( L_9 ,
V_49 ,
V_42 [ V_18 ] . V_43 ,
V_42 [ V_18 ] . V_44 ) ;
goto V_50;
}
F_6 ( L_10 ,
V_49 ) ;
F_5 ( V_3 , V_2 , V_5 ) ;
V_38 = F_1 ( V_2 , V_3 , V_5 ) ;
V_40 = F_4 ( V_2 , V_3 , V_5 ) ;
if ( V_38 == V_5 -> V_38 && V_40 == V_5 -> V_40 ) {
F_6 ( L_11
L_12 ,
V_49 , V_5 -> V_38 , V_5 -> V_40 ) ;
goto V_50;
}
V_47 = 1 ;
F_6 ( L_13 , V_49 ) ;
if ( V_5 -> V_13 ) {
F_7 ( 0xaa , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0x55 , V_5 -> V_14 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
F_7 ( 0x90 , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
V_50:
return V_47 ;
}
static int F_14 ( struct V_1 * V_2 , T_5 V_3 ,
unsigned long * V_58 , struct V_4 * V_5 )
{
int V_16 ;
enum V_18 V_59 = V_60 ;
T_1 V_61 , V_62 ;
V_63:
if ( ! V_5 -> V_64 ) {
V_59 ++ ;
if ( V_56 == V_59 )
return 0 ;
V_5 -> V_13 = V_42 [ V_59 ] . V_43 / V_5 -> V_10 ;
V_5 -> V_14 = V_42 [ V_59 ] . V_44 / V_5 -> V_10 ;
}
if ( V_3 >= V_2 -> V_55 ) {
F_9 ( V_65
L_14 ,
V_3 , V_2 -> V_55 - 1 ) ;
return 0 ;
}
V_61 = F_2 ( V_5 -> V_13 , V_2 , V_5 ) ;
V_62 = F_2 ( V_5 -> V_14 , V_2 , V_5 ) ;
if ( ( ( V_3 + V_61 + F_15 ( V_2 ) ) >= V_2 -> V_55 ) ||
( ( V_3 + V_62 + F_15 ( V_2 ) ) >= V_2 -> V_55 ) )
goto V_63;
F_5 ( V_3 , V_2 , V_5 ) ;
if( V_5 -> V_13 ) {
F_7 ( 0xaa , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
F_7 ( 0x55 , V_5 -> V_14 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
}
F_7 ( 0x90 , V_5 -> V_13 , V_3 , V_2 , V_5 , V_5 -> V_10 , NULL ) ;
if ( ! V_5 -> V_64 ) {
V_5 -> V_38 = F_1 ( V_2 , V_3 , V_5 ) ;
V_5 -> V_40 = F_4 ( V_2 , V_3 , V_5 ) ;
F_6 ( L_15 ,
V_5 -> V_38 , V_5 -> V_40 , F_13 ( V_5 ) , V_5 -> V_10 ) ;
for ( V_16 = 0 ; V_16 < F_16 ( V_19 ) ; V_16 ++ ) {
if ( F_12 ( V_3 , V_2 , V_5 , & V_19 [ V_16 ] ) ) {
F_6 ( L_16 ,
V_49 , V_5 -> V_38 , V_5 -> V_40 ,
V_5 -> V_13 , V_5 -> V_14 ) ;
if ( ! F_8 ( V_2 , V_5 , V_16 ) )
return 0 ;
goto V_66;
}
}
goto V_63;
} else {
V_52 V_38 ;
V_52 V_40 ;
V_38 = F_1 ( V_2 , V_3 , V_5 ) ;
V_40 = F_4 ( V_2 , V_3 , V_5 ) ;
if ( ( V_38 != V_5 -> V_38 ) || ( V_40 != V_5 -> V_40 ) ) {
F_9 ( V_67 L_17 ,
V_2 -> V_21 , V_38 , V_40 , V_3 ) ;
F_5 ( V_3 , V_2 , V_5 ) ;
return 0 ;
}
}
for ( V_16 = 0 ; V_16 < ( V_3 >> V_5 -> V_68 ) ; V_16 ++ ) {
unsigned long V_69 ;
if( ! F_17 ( V_16 , V_58 ) ) {
continue;
}
V_69 = V_16 << V_5 -> V_68 ;
if ( F_1 ( V_2 , V_69 , V_5 ) == V_5 -> V_38 &&
F_4 ( V_2 , V_69 , V_5 ) == V_5 -> V_40 ) {
F_5 ( V_69 , V_2 , V_5 ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) != V_5 -> V_38 ||
F_4 ( V_2 , V_3 , V_5 ) != V_5 -> V_40 ) {
F_9 ( V_67 L_18 ,
V_2 -> V_21 , V_3 , V_69 ) ;
return 0 ;
}
F_5 ( V_3 , V_2 , V_5 ) ;
if ( F_1 ( V_2 , V_3 , V_5 ) == V_5 -> V_38 &&
F_4 ( V_2 , V_3 , V_5 ) == V_5 -> V_40 ) {
F_9 ( V_67 L_18 ,
V_2 -> V_21 , V_3 , V_69 ) ;
return 0 ;
}
}
}
F_18 ( ( V_3 >> V_5 -> V_68 ) , V_58 ) ;
V_5 -> V_64 ++ ;
V_66:
F_5 ( V_3 , V_2 , V_5 ) ;
F_9 ( V_22 L_19 ,
V_2 -> V_21 , F_13 ( V_5 ) , V_5 -> V_10 * 8 , V_3 ,
V_2 -> V_70 * 8 ) ;
return 1 ;
}
static struct V_71 * F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , & V_72 ) ;
}
static int T_6 F_21 ( void )
{
F_22 ( & V_73 ) ;
return 0 ;
}
static void T_7 F_23 ( void )
{
F_24 ( & V_73 ) ;
}
