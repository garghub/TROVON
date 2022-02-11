static int F_1 ( void )
{
T_1 V_1 ;
V_2 . V_3 = 14 ;
V_1 = V_2 . V_3 & 0xef ;
V_2 . V_4 = V_1 ;
V_2 . V_4 = V_1 | 0x10 ;
F_2 ( 10 ) ;
V_2 . V_3 = 14 ;
V_2 . V_4 = V_2 . V_3 & 0xef ;
return 0 ;
}
static int F_3 ( T_1 T_2 * V_5 , int V_6 )
{
struct V_7 * V_8 ;
const struct V_9 * V_10 ;
const char V_11 [] = L_1 ;
int V_12 ;
int V_13 ;
F_1 () ;
V_8 = F_4 ( L_2 , 0 , NULL , 0 ) ;
if ( F_5 ( V_8 ) ) {
F_6 ( V_14 L_3 ,
V_11 ) ;
return - V_15 ;
}
V_12 = F_7 ( & V_10 , V_11 , & V_8 -> V_16 ) ;
F_8 ( V_8 ) ;
if ( V_12 ) {
F_6 ( V_14 L_4 ,
V_11 , V_12 ) ;
return V_12 ;
}
if ( V_10 -> V_17 % 3 ) {
F_6 ( V_14 L_5 ,
V_10 -> V_17 , V_11 ) ;
F_9 ( V_10 ) ;
return - V_15 ;
}
for ( V_13 = 0 ; V_13 < V_10 -> V_17 ; V_13 = V_13 + 3 ) {
V_18 . V_19 . V_20 [ 1 ] = V_10 -> V_19 [ V_13 ] ;
V_18 . V_19 . V_20 [ 2 ] = V_10 -> V_19 [ V_13 + 1 ] ;
V_18 . V_19 . V_20 [ 3 ] = V_10 -> V_19 [ V_13 + 2 ] ;
}
F_9 ( V_10 ) ;
for (; V_13 < 512 ; V_13 ++ ) {
V_18 . V_19 . V_20 [ 1 ] = 0 ;
V_18 . V_19 . V_20 [ 2 ] = 0 ;
V_18 . V_19 . V_20 [ 3 ] = 0 ;
}
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
F_10 ( 10 ) ;
F_11 ( V_18 . V_19 . V_20 [ 1 ] , V_5 ++ ) ;
F_11 ( V_18 . V_19 . V_20 [ 2 ] , V_5 ++ ) ;
F_11 ( V_18 . V_19 . V_20 [ 3 ] , V_5 ++ ) ;
}
F_10 ( 10 ) ;
V_18 . V_19 . V_21 = 3 ;
return 0 ;
}
static T_3 F_12 ( struct V_22 * V_22 , char T_2 * V_23 , T_4 V_24 ,
T_5 * V_25 )
{
struct V_26 * V_26 = F_13 ( V_22 ) ;
int V_16 = F_14 ( V_26 ) & 0x0f ;
switch( V_16 )
{
case V_27 :
{
long V_28 ;
if ( ! V_24 ) return 0 ;
V_28 = 0 ;
switch ( V_29 . V_30 ) {
case 1 :
{
F_15 ( V_24 , V_29 . V_31 , V_29 . V_32 , V_33 ,
F_16 ( V_18 . V_19 . V_20 [ 3 ] , V_23 + V_28 ++ ) ) ;
return V_28 ;
}
case 2 :
{
short T_2 * V_19 ;
V_24 /= 2 ;
V_19 = ( short T_2 * ) V_23 ;
F_15 ( V_24 , V_29 . V_31 , V_29 . V_32 , V_33 ,
F_16 ( V_18 . V_19 . V_34 [ 1 ] , V_19 + V_28 ++ ) ) ;
return 2 * V_28 ;
}
case 3 :
{
V_24 /= 3 ;
F_15 (count, dsp56k.maxio, dsp56k.timeout, DSP56K_RECEIVE,
put_user(dsp56k_host_interface.data.b[1], buf+n++);
put_user(dsp56k_host_interface.data.b[2], buf+n++);
put_user(dsp56k_host_interface.data.b[3], buf+n++)) ;
return 3 * V_28 ;
}
case 4 :
{
long T_2 * V_19 ;
V_24 /= 4 ;
V_19 = ( long T_2 * ) V_23 ;
F_15 ( V_24 , V_29 . V_31 , V_29 . V_32 , V_33 ,
F_16 ( V_18 . V_19 . V_21 , V_19 + V_28 ++ ) ) ;
return 4 * V_28 ;
}
}
return - V_35 ;
}
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_36 ;
}
}
static T_3 F_17 ( struct V_22 * V_22 , const char T_2 * V_23 , T_4 V_24 ,
T_5 * V_25 )
{
struct V_26 * V_26 = F_13 ( V_22 ) ;
int V_16 = F_14 ( V_26 ) & 0x0f ;
switch( V_16 )
{
case V_27 :
{
long V_28 ;
if ( ! V_24 ) return 0 ;
V_28 = 0 ;
switch ( V_29 . V_37 ) {
case 1 :
{
F_15 ( V_24 , V_29 . V_31 , V_29 . V_32 , V_38 ,
F_11 ( V_18 . V_19 . V_20 [ 3 ] , V_23 + V_28 ++ ) ) ;
return V_28 ;
}
case 2 :
{
const short T_2 * V_19 ;
V_24 /= 2 ;
V_19 = ( const short T_2 * ) V_23 ;
F_15 ( V_24 , V_29 . V_31 , V_29 . V_32 , V_38 ,
F_11 ( V_18 . V_19 . V_34 [ 1 ] , V_19 + V_28 ++ ) ) ;
return 2 * V_28 ;
}
case 3 :
{
V_24 /= 3 ;
F_15 (count, dsp56k.maxio, dsp56k.timeout, DSP56K_TRANSMIT,
get_user(dsp56k_host_interface.data.b[1], buf+n++);
get_user(dsp56k_host_interface.data.b[2], buf+n++);
get_user(dsp56k_host_interface.data.b[3], buf+n++)) ;
return 3 * V_28 ;
}
case 4 :
{
const long T_2 * V_19 ;
V_24 /= 4 ;
V_19 = ( const long T_2 * ) V_23 ;
F_15 ( V_24 , V_29 . V_31 , V_29 . V_32 , V_38 ,
F_11 ( V_18 . V_19 . V_21 , V_19 + V_28 ++ ) ) ;
return 4 * V_28 ;
}
}
return - V_35 ;
}
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_36 ;
}
}
static long F_18 ( struct V_22 * V_22 , unsigned int V_39 ,
unsigned long V_40 )
{
int V_16 = F_14 ( F_13 ( V_22 ) ) & 0x0f ;
void T_2 * V_41 = ( void T_2 * ) V_40 ;
switch( V_16 )
{
case V_27 :
switch( V_39 ) {
case V_42 :
{
char T_2 * V_5 ;
int V_43 , V_6 ;
struct F_3 T_2 * V_44 = V_41 ;
if( F_11 ( V_6 , & V_44 -> V_6 ) < 0 )
return - V_35 ;
if( F_11 ( V_5 , & V_44 -> V_5 ) < 0 )
return - V_35 ;
if ( V_6 == 0 ) {
return - V_15 ;
}
if ( V_6 > V_45 ) {
return - V_15 ;
}
F_19 ( & V_46 ) ;
V_43 = F_3 ( V_5 , V_6 ) ;
F_20 ( & V_46 ) ;
if ( V_43 < 0 ) {
return V_43 ;
}
break;
}
case V_47 :
if ( V_40 > 4 || V_40 < 1 )
return - V_15 ;
F_19 ( & V_46 ) ;
V_29 . V_37 = ( int ) V_40 ;
F_20 ( & V_46 ) ;
break;
case V_48 :
if ( V_40 > 4 || V_40 < 1 )
return - V_15 ;
F_19 ( & V_46 ) ;
V_29 . V_30 = ( int ) V_40 ;
F_20 ( & V_46 ) ;
break;
case V_49 :
{
int V_50 , V_51 , V_1 ;
struct V_52 T_2 * V_53 = V_41 ;
if( F_11 ( V_50 , & V_53 -> V_50 ) < 0 )
return - V_35 ;
if( F_11 ( V_51 , & V_53 -> V_51 ) < 0 )
return - V_35 ;
F_19 ( & V_46 ) ;
if ( ( V_50 & 0x1 ) && ( V_51 & 0x1 ) )
V_18 . V_54 |= V_55 ;
else if ( V_50 & 0x1 )
V_18 . V_54 &= ~ V_55 ;
if ( ( V_50 & 0x2 ) && ( V_51 & 0x2 ) )
V_18 . V_54 |= V_56 ;
else if ( V_50 & 0x2 )
V_18 . V_54 &= ~ V_56 ;
V_1 = 0 ;
if ( V_18 . V_54 & V_55 ) V_1 |= 0x1 ;
if ( V_18 . V_54 & V_56 ) V_1 |= 0x2 ;
if ( V_18 . V_57 & V_58 ) V_1 |= 0x4 ;
if ( V_18 . V_57 & V_59 ) V_1 |= 0x8 ;
F_20 ( & V_46 ) ;
return F_16 ( V_1 , & V_53 -> V_1 ) ;
}
case V_60 :
if ( V_40 > 31 || V_40 < 0 )
return - V_15 ;
F_19 ( & V_46 ) ;
V_18 . V_61 = ( T_1 ) ( ( V_40 & V_62 ) |
V_63 ) ;
F_20 ( & V_46 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_36 ;
}
}
static int F_21 ( struct V_26 * V_26 , struct V_22 * V_22 )
{
int V_16 = F_14 ( V_26 ) & 0x0f ;
int V_64 = 0 ;
F_19 ( & V_46 ) ;
switch( V_16 )
{
case V_27 :
if ( F_22 ( 0 , & V_29 . V_65 ) ) {
V_64 = - V_66 ;
goto V_51;
}
V_29 . V_32 = V_67 ;
V_29 . V_31 = V_68 ;
V_29 . V_30 = V_29 . V_37 = 4 ;
V_69 ;
V_70 ;
V_18 . V_54 &= ~ V_55 ;
V_18 . V_54 &= ~ V_56 ;
break;
default:
V_64 = - V_71 ;
}
V_51:
F_20 ( & V_46 ) ;
return V_64 ;
}
static int F_23 ( struct V_26 * V_26 , struct V_22 * V_22 )
{
int V_16 = F_14 ( V_26 ) & 0x0f ;
switch( V_16 )
{
case V_27 :
F_24 ( 0 , & V_29 . V_65 ) ;
break;
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_36 ;
}
return 0 ;
}
static int T_6 F_25 ( void )
{
int V_12 = 0 ;
if( ! V_72 || ! F_26 ( V_73 ) ) {
F_6 ( L_7 ) ;
return - V_71 ;
}
if( F_27 ( V_74 , L_2 , & V_75 ) ) {
F_6 ( L_8 ) ;
return - V_71 ;
}
V_76 = F_28 ( V_77 , L_2 ) ;
if ( F_5 ( V_76 ) ) {
V_12 = F_29 ( V_76 ) ;
goto V_78;
}
F_30 ( V_76 , NULL , F_31 ( V_74 , 0 ) , NULL ,
L_2 ) ;
F_6 ( V_79 ) ;
goto V_51;
V_78:
F_32 ( V_74 , L_2 ) ;
V_51:
return V_12 ;
}
static void T_7 F_33 ( void )
{
F_34 ( V_76 , F_31 ( V_74 , 0 ) ) ;
F_35 ( V_76 ) ;
F_32 ( V_74 , L_2 ) ;
}
