static int T_1
F_1 ( char * V_1 )
{
if ( strlen ( V_1 ) > V_2 ) {
F_2 ( V_3 L_1 ,
V_4 ) ;
} else
V_4 = V_1 ;
return 1 ;
}
static void
F_3 ( unsigned long V_5 )
{
struct V_6 * V_7 ;
while ( ( V_7 = V_8 [ V_9 ] . V_7 ) != NULL ) {
F_4 ( & V_10 ) ;
V_8 [ V_9 ] . V_7 = NULL ;
if ( V_11 )
F_2 ( L_2 , V_7 -> V_12 ) ;
(* V_7 -> V_13 )( V_7 ) ;
V_9 = ( V_9 + 1 ) % V_14 ;
}
}
static int
F_5 ( struct V_15 * V_16 , struct V_17 * V_18 ,
T_2 V_19 , int V_20 [] )
{
V_20 [ 0 ] = 64 ;
V_20 [ 1 ] = 32 ;
V_20 [ 2 ] = V_19 >> 11 ;
return 0 ;
}
static void
F_6 ( struct V_6 * V_7 , int V_21 , unsigned long V_22 )
{
int V_23 ;
struct V_24 * V_25 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
V_27 . V_30 = V_31 [ V_7 -> V_32 -> V_33 ] ;
F_7 (sc, sl, scsi_sg_count(sc), i) {
V_29 . V_34 = F_8 ( F_9 ( V_25 ) ) ;
V_29 . V_35 = V_25 -> V_36 ;
if ( V_11 )
F_2 ( L_3 ,
V_21 == V_37 ? L_4 : L_5 , V_29 . V_34 , V_22 ,
F_10 ( V_7 ) - V_23 , V_25 -> V_36 ) ;
F_11 ( V_27 . V_30 , 1 , F_8 ( & V_29 ) , V_22 , V_21 ) ;
F_11 ( F_8 ( & V_27 ) , 0 , 0 , 0 , V_38 ) ;
if ( V_27 . V_39 != V_29 . V_35 ) {
V_7 -> V_40 = V_41 << 16 ;
return;
}
V_22 += V_25 -> V_36 ;
}
V_7 -> V_40 = V_42 ;
}
static void
F_12 ( struct V_6 * V_7 , int V_21 )
{
unsigned long V_22 ;
V_22 = ( ( ( V_7 -> V_43 [ 1 ] & 0x1f ) << 16 ) | ( V_7 -> V_43 [ 2 ] << 8 ) | V_7 -> V_43 [ 3 ] ) * 512 ;
F_6 ( V_7 , V_21 , V_22 ) ;
}
static T_3
F_13 ( int V_30 )
{
struct V_26 V_27 ;
T_3 V_44 , V_45 = 0 ;
struct V_28 V_29 ;
char V_46 [ 512 ] ;
for ( V_44 = ( 128UL << 30 ) / 512 ; V_44 != 0 ; V_44 >>= 1 ) {
V_29 . V_34 = F_8 ( & V_46 ) ;
V_29 . V_35 = sizeof( V_46 ) ;
F_11 ( V_30 , 1 , F_8 ( & V_29 ) , ( ( V_45 | V_44 ) - 1 ) * 512 , V_37 ) ;
V_27 . V_30 = V_30 ;
F_11 ( F_8 ( & V_27 ) , 0 , 0 , 0 , V_38 ) ;
if ( V_27 . V_39 == sizeof( V_46 ) )
V_45 |= V_44 ;
}
return V_45 - 1 ;
}
static void
F_14 ( struct V_6 * V_7 , int V_21 )
{
unsigned long V_22 ;
V_22 = ( ( ( unsigned long ) V_7 -> V_43 [ 2 ] << 24 )
| ( ( unsigned long ) V_7 -> V_43 [ 3 ] << 16 )
| ( ( unsigned long ) V_7 -> V_43 [ 4 ] << 8 )
| ( ( unsigned long ) V_7 -> V_43 [ 5 ] << 0 ) ) * 512UL ;
F_6 ( V_7 , V_21 , V_22 ) ;
}
static int
F_15 ( struct V_6 * V_7 , void (* F_16)( struct V_6 * ) )
{
unsigned int V_47 = V_7 -> V_32 -> V_33 ;
char V_48 [ V_2 + 16 ] ;
T_3 V_49 ;
char * V_46 ;
char V_50 [ 36 ] ;
#if V_51
register long T_4 V_52 ( L_6 ) ;
if ( V_11 )
F_2 ( L_7 ,
V_47 , V_7 -> V_43 [ 0 ] , V_7 -> V_12 , T_4 , F_16 ) ;
#endif
V_7 -> V_40 = V_53 << 16 ;
V_7 -> V_13 = F_16 ;
if ( V_47 <= 15 && V_7 -> V_32 -> V_54 == 0 ) {
switch ( V_7 -> V_43 [ 0 ] ) {
case V_55 :
if ( F_17 ( V_7 ) < 35 ) {
break;
}
sprintf ( V_48 , L_8 , V_4 , 'a' + V_47 ) ;
V_31 [ V_47 ] = F_11 ( F_8 ( V_48 ) , V_56 | V_57 ,
0 , 0 , V_58 ) ;
if ( V_31 [ V_47 ] < 0 ) {
break;
}
V_46 = V_50 ;
V_46 [ 0 ] = 0 ;
V_46 [ 1 ] = 0 ;
V_46 [ 2 ] = 2 ;
V_46 [ 3 ] = 2 ;
V_46 [ 4 ] = 31 ;
V_46 [ 5 ] = 0 ;
V_46 [ 6 ] = 0 ;
V_46 [ 7 ] = 0 ;
memcpy ( V_46 + 8 , L_9 , 28 ) ;
F_18 ( V_7 , V_46 , 36 ) ;
V_7 -> V_40 = V_42 ;
break;
case V_59 :
V_7 -> V_40 = V_42 ;
break;
case V_60 :
if ( V_31 [ V_47 ] < 0 )
break;
F_12 ( V_7 , V_37 ) ;
break;
case V_61 :
if ( V_31 [ V_47 ] < 0 )
break;
F_14 ( V_7 , V_37 ) ;
break;
case V_62 :
if ( V_31 [ V_47 ] < 0 )
break;
F_12 ( V_7 , V_63 ) ;
break;
case V_64 :
if ( V_31 [ V_47 ] < 0 )
break;
F_14 ( V_7 , V_63 ) ;
break;
case V_65 :
if ( V_31 [ V_47 ] < 0 || F_17 ( V_7 ) < 8 ) {
break;
}
V_46 = V_50 ;
V_49 = F_13 ( V_31 [ V_47 ] ) ;
V_46 [ 0 ] = ( V_49 >> 24 ) & 0xff ;
V_46 [ 1 ] = ( V_49 >> 16 ) & 0xff ;
V_46 [ 2 ] = ( V_49 >> 8 ) & 0xff ;
V_46 [ 3 ] = ( V_49 >> 0 ) & 0xff ;
V_46 [ 4 ] = 0 ;
V_46 [ 5 ] = 0 ;
V_46 [ 6 ] = 2 ;
V_46 [ 7 ] = 0 ;
F_18 ( V_7 , V_46 , 8 ) ;
V_7 -> V_40 = V_42 ;
break;
case V_66 :
case V_67 :
F_18 ( V_7 , ( char * ) V_68 ,
V_69 ) ;
V_7 -> V_40 = V_42 ;
break;
case V_70 :
F_2 ( V_3 L_10 ) ;
break;
default:
F_19 ( L_11 , V_7 -> V_43 [ 0 ] ) ;
}
}
if ( V_7 -> V_40 == V_53 ) {
V_7 -> V_40 |= V_71 << 24 ;
V_7 -> V_72 [ 0 ] = 0x70 ;
V_7 -> V_72 [ 2 ] = 0x00 ;
}
if ( F_20 ( & V_10 ) >= V_14 ) {
F_19 ( L_12 ) ;
}
F_21 ( & V_10 ) ;
V_8 [ V_73 ] . V_7 = V_7 ;
V_73 = ( V_73 + 1 ) % V_14 ;
F_22 ( & V_74 ) ;
return 0 ;
}
static int T_1
F_23 ( void )
{
int error ;
V_75 = F_24 ( & V_76 , 0 ) ;
if ( ! V_75 )
return - V_77 ;
error = F_25 ( V_75 , NULL ) ;
if ( error )
goto V_78;
F_26 ( V_75 ) ;
return 0 ;
V_78:
F_27 ( V_75 ) ;
return error ;
}
static void T_5
F_28 ( void )
{
F_29 ( V_75 ) ;
F_27 ( V_75 ) ;
}
