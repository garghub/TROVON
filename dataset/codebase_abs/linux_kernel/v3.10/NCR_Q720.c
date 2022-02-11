static T_1
F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_2 V_5 = ( F_2 ( V_4 -> V_6 + 0x0d ) & 0xf0 ) >> 4 ;
T_2 V_7 ;
V_5 |= ~ V_4 -> V_8 ;
if( V_5 == 0xff )
return V_9 ;
while( ( V_7 = F_3 ( V_5 ) ) < V_4 -> V_10 ) {
V_5 |= 1 << V_7 ;
F_4 ( V_1 , V_4 -> V_11 [ V_7 ] ) ;
}
return V_12 ;
}
static int T_3
F_5 ( struct V_3 * V_4 , int V_7 ,
int V_1 , int V_13 , T_4 V_14 , void T_5 * V_15 )
{
struct V_16 V_17 ;
T_2 V_18 ;
static int V_19 = 0 ;
T_2 V_20 = F_2 ( V_15 + V_21 + 1 ) ;
T_2 V_22 = F_2 ( V_15 + V_21 ) & 0x20 ;
T_2 V_23 ;
int error ;
V_18 = V_20 >> 4 ;
V_20 |= 0x02 ;
V_20 |= 0x04 ;
F_6 ( V_20 , V_15 + V_21 + 1 ) ;
F_7 ( 10 ) ;
V_23 = F_2 ( V_15 + 0x18 ) >> 4 ;
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 . V_24 = V_25 ;
V_17 . V_24 . V_26 = V_23 ;
V_17 . V_27 = V_18 ;
V_17 . V_28 = V_4 -> V_28 ;
V_17 . V_13 . V_29 = V_14 ;
V_17 . V_13 . V_30 = V_14 ;
V_17 . V_13 . V_31 = V_15 ;
V_17 . V_13 . V_1 = V_1 ;
V_17 . V_22 = V_22 ? 2 : 0 ;
F_8 ( L_1 , V_19 , V_7 ,
( unsigned long ) V_14 , V_22 , V_23 ) ;
V_4 -> V_11 [ V_7 ] = F_9 ( & V_32 , V_19 ++ , & V_17 ) ;
if ( ! V_4 -> V_11 [ V_7 ] )
goto V_33;
V_4 -> V_8 |= ( 1 << V_7 ) ;
V_20 = F_2 ( V_15 + V_21 + 1 ) ;
V_20 &= ~ 0x01 ;
F_6 ( V_20 , V_15 + V_21 + 1 ) ;
error = F_10 ( V_4 -> V_11 [ V_7 ] , V_4 -> V_28 ) ;
if ( error )
F_11 ( V_4 -> V_11 [ V_7 ] ) ;
else
F_12 ( V_4 -> V_11 [ V_7 ] ) ;
return error ;
V_33:
return - V_34 ;
}
static int T_3
F_13 ( struct V_17 * V_28 )
{
struct V_3 * V_4 ;
static int V_35 = 1 ;
struct V_36 * V_37 = F_14 ( V_28 ) ;
int V_13 = V_37 -> V_13 ;
int V_38 = 0 ;
int V_1 , V_39 , V_10 ;
T_2 V_40 , V_41 , V_42 , V_43 , V_44 ;
T_6 V_45 ;
T_4 V_46 , V_47 ;
void T_5 * V_6 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_40 = F_16 ( V_37 , 2 ) ;
V_40 |= V_50 | V_51 ;
F_17 ( V_37 , 2 , V_40 ) ;
V_45 = ( V_40 & V_52 ) << V_53 ;
if( V_35 ) {
F_8 ( V_54 L_2 V_55 L_3
L_4
L_5 ) ;
V_35 = 0 ;
}
V_45 = F_18 ( V_37 , V_45 ) ;
V_39 = F_19 ( V_45 ) | ( F_19 ( V_45 + 1 ) << 8 ) ;
if( V_39 != V_56 ) {
F_8 ( V_57 L_6 , V_45 , V_39 ) ;
F_20 ( V_4 ) ;
return - V_34 ;
}
V_41 = F_19 ( V_45 + 4 ) ;
V_41 |= 0x01 ;
F_21 ( V_41 , V_45 + 4 ) ;
V_46 = ( V_41 & 0x7e ) << 20 ;
V_46 += ( V_41 & 0x80 ) << 23 ;
V_44 = F_19 ( V_45 + 0x12 ) ;
V_46 += ( V_44 & 0x80 ) << 24 ;
V_46 += ( V_44 & 0x70 ) << 23 ;
V_43 = F_19 ( V_45 + 0x11 ) ;
V_39 = ( V_43 & 0xc0 ) >> 6 ;
if( V_39 == 0 )
V_47 = 1024 ;
else
V_47 = 1 << ( 19 + V_39 ) ;
V_43 |= 0x20 ;
V_43 &= ~ 0x10 ;
F_21 ( V_43 , V_45 + 0x11 ) ;
if( ! F_22 ( V_46 , V_47 , L_7 ) ) {
F_8 ( V_57 L_8 ,
( unsigned long ) V_46 ,
( unsigned long ) ( V_46 + V_47 ) ) ;
goto V_58;
}
if ( F_23 ( V_28 , V_46 , V_46 ,
V_47 , V_59 )
!= V_59 ) {
F_8 ( V_57 L_9 ) ;
goto V_60;
}
V_6 = F_24 ( V_28 , V_46 ,
1024 ) ;
if ( F_25 ( V_6 ) ) {
F_8 ( L_10 ) ;
goto V_61;
}
V_42 = F_19 ( V_45 + 0x0a ) ;
V_42 |= 0x01 ;
F_21 ( V_42 , V_45 + 0x0a ) ;
V_10 = ( ( V_42 & 0xe0 ) >> 5 ) + 1 ;
V_39 = F_26 ( V_6 ) ;
if( V_39 != V_56 ) {
F_8 ( V_57 L_11 , ( unsigned long ) V_46 , V_39 ) ;
goto V_61;
}
V_1 = F_2 ( V_6 + 5 ) & 0x0f ;
V_1 = F_27 ( V_37 , V_1 ) ;
F_8 ( V_54 L_12 , V_13 , V_1 , ( unsigned long ) V_46 , V_10 ) ;
F_8 ( V_54 L_13 , V_47 / 1024 ) ;
V_4 -> V_28 = V_28 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_62 = V_46 ;
V_4 -> V_47 = V_47 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_10 = V_10 ;
if ( F_28 ( V_1 , F_1 , V_63 , L_7 , V_4 ) ) {
F_8 ( V_57 L_14 , V_1 ) ;
goto V_61;
}
for( V_39 = 0 ; V_39 < V_10 ; V_39 ++ ) {
void T_5 * V_64 = V_6 + V_65
+ V_39 * V_66 + V_21 + 1 ;
T_2 V_20 = F_2 ( V_64 ) ;
V_20 |= 0x01 ;
F_6 ( V_20 , V_64 ) ;
}
for ( V_39 = 0 ; V_39 < V_10 ; V_39 ++ ) {
void T_5 * V_67 = V_6 + V_65
+ V_39 * V_66 ;
T_4 V_68 = V_46 + V_65
+ V_39 * V_66 ;
T_6 V_69 = V_45 + V_65
+ V_39 * V_66 ;
int V_70 ;
F_21 ( 0xff , V_69 + 0x40 ) ;
F_21 ( 0x07 , V_69 + 0x41 ) ;
if ( ( V_70 = F_5 ( V_4 , V_39 , V_1 , V_13 ,
V_68 , V_67 ) ) != 0 )
F_8 ( L_15 ,
V_39 , V_70 ) ;
else
V_38 ++ ;
}
if ( ! V_38 ) {
F_20 ( V_4 ) ;
return - V_34 ;
}
F_29 ( V_37 , 1 ) ;
F_30 ( V_37 , L_7 ) ;
F_31 ( V_28 , V_4 ) ;
return 0 ;
V_61:
F_32 ( V_28 ) ;
V_60:
F_33 ( V_46 , V_47 ) ;
V_58:
F_20 ( V_4 ) ;
return - V_34 ;
}
static void T_7
F_34 ( struct V_71 * V_72 )
{
F_35 ( V_72 ) ;
F_11 ( V_72 ) ;
}
static int T_7
F_36 ( struct V_17 * V_28 )
{
struct V_3 * V_4 = F_37 ( V_28 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_10 ; V_39 ++ )
if( V_4 -> V_11 [ V_39 ] )
F_34 ( V_4 -> V_11 [ V_39 ] ) ;
F_32 ( V_28 ) ;
F_33 ( V_4 -> V_62 , V_4 -> V_47 ) ;
F_38 ( V_4 -> V_1 , V_4 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static int T_3
F_39 ( void )
{
int V_73 = F_40 () ;
if ( ! V_73 )
V_73 = F_41 ( & V_74 ) ;
if ( V_73 )
F_42 () ;
return V_73 ;
}
static void T_7
F_43 ( void )
{
F_44 ( & V_74 ) ;
F_42 () ;
}
