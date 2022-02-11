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
struct V_26 * V_26 = V_22 -> V_27 . V_28 -> V_29 ;
int V_16 = F_13 ( V_26 ) & 0x0f ;
switch( V_16 )
{
case V_30 :
{
long V_31 ;
if ( ! V_24 ) return 0 ;
V_31 = 0 ;
switch ( V_32 . V_33 ) {
case 1 :
{
F_14 ( V_24 , V_32 . V_34 , V_32 . V_35 , V_36 ,
F_15 ( V_18 . V_19 . V_20 [ 3 ] , V_23 + V_31 ++ ) ) ;
return V_31 ;
}
case 2 :
{
short T_2 * V_19 ;
V_24 /= 2 ;
V_19 = ( short T_2 * ) V_23 ;
F_14 ( V_24 , V_32 . V_34 , V_32 . V_35 , V_36 ,
F_15 ( V_18 . V_19 . V_37 [ 1 ] , V_19 + V_31 ++ ) ) ;
return 2 * V_31 ;
}
case 3 :
{
V_24 /= 3 ;
F_14 (count, dsp56k.maxio, dsp56k.timeout, DSP56K_RECEIVE,
put_user(dsp56k_host_interface.data.b[1], buf+n++);
put_user(dsp56k_host_interface.data.b[2], buf+n++);
put_user(dsp56k_host_interface.data.b[3], buf+n++)) ;
return 3 * V_31 ;
}
case 4 :
{
long T_2 * V_19 ;
V_24 /= 4 ;
V_19 = ( long T_2 * ) V_23 ;
F_14 ( V_24 , V_32 . V_34 , V_32 . V_35 , V_36 ,
F_15 ( V_18 . V_19 . V_21 , V_19 + V_31 ++ ) ) ;
return 4 * V_31 ;
}
}
return - V_38 ;
}
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_39 ;
}
}
static T_3 F_16 ( struct V_22 * V_22 , const char T_2 * V_23 , T_4 V_24 ,
T_5 * V_25 )
{
struct V_26 * V_26 = V_22 -> V_27 . V_28 -> V_29 ;
int V_16 = F_13 ( V_26 ) & 0x0f ;
switch( V_16 )
{
case V_30 :
{
long V_31 ;
if ( ! V_24 ) return 0 ;
V_31 = 0 ;
switch ( V_32 . V_40 ) {
case 1 :
{
F_14 ( V_24 , V_32 . V_34 , V_32 . V_35 , V_41 ,
F_11 ( V_18 . V_19 . V_20 [ 3 ] , V_23 + V_31 ++ ) ) ;
return V_31 ;
}
case 2 :
{
const short T_2 * V_19 ;
V_24 /= 2 ;
V_19 = ( const short T_2 * ) V_23 ;
F_14 ( V_24 , V_32 . V_34 , V_32 . V_35 , V_41 ,
F_11 ( V_18 . V_19 . V_37 [ 1 ] , V_19 + V_31 ++ ) ) ;
return 2 * V_31 ;
}
case 3 :
{
V_24 /= 3 ;
F_14 (count, dsp56k.maxio, dsp56k.timeout, DSP56K_TRANSMIT,
get_user(dsp56k_host_interface.data.b[1], buf+n++);
get_user(dsp56k_host_interface.data.b[2], buf+n++);
get_user(dsp56k_host_interface.data.b[3], buf+n++)) ;
return 3 * V_31 ;
}
case 4 :
{
const long T_2 * V_19 ;
V_24 /= 4 ;
V_19 = ( const long T_2 * ) V_23 ;
F_14 ( V_24 , V_32 . V_34 , V_32 . V_35 , V_41 ,
F_11 ( V_18 . V_19 . V_21 , V_19 + V_31 ++ ) ) ;
return 4 * V_31 ;
}
}
return - V_38 ;
}
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_39 ;
}
}
static long F_17 ( struct V_22 * V_22 , unsigned int V_42 ,
unsigned long V_43 )
{
int V_16 = F_13 ( V_22 -> V_27 . V_28 -> V_29 ) & 0x0f ;
void T_2 * V_44 = ( void T_2 * ) V_43 ;
switch( V_16 )
{
case V_30 :
switch( V_42 ) {
case V_45 :
{
char T_2 * V_5 ;
int V_46 , V_6 ;
struct F_3 T_2 * V_47 = V_44 ;
if( F_11 ( V_6 , & V_47 -> V_6 ) < 0 )
return - V_38 ;
if( F_11 ( V_5 , & V_47 -> V_5 ) < 0 )
return - V_38 ;
if ( V_6 == 0 ) {
return - V_15 ;
}
if ( V_6 > V_48 ) {
return - V_15 ;
}
F_18 ( & V_49 ) ;
V_46 = F_3 ( V_5 , V_6 ) ;
F_19 ( & V_49 ) ;
if ( V_46 < 0 ) {
return V_46 ;
}
break;
}
case V_50 :
if ( V_43 > 4 || V_43 < 1 )
return - V_15 ;
F_18 ( & V_49 ) ;
V_32 . V_40 = ( int ) V_43 ;
F_19 ( & V_49 ) ;
break;
case V_51 :
if ( V_43 > 4 || V_43 < 1 )
return - V_15 ;
F_18 ( & V_49 ) ;
V_32 . V_33 = ( int ) V_43 ;
F_19 ( & V_49 ) ;
break;
case V_52 :
{
int V_53 , V_54 , V_1 ;
struct V_55 T_2 * V_56 = V_44 ;
if( F_11 ( V_53 , & V_56 -> V_53 ) < 0 )
return - V_38 ;
if( F_11 ( V_54 , & V_56 -> V_54 ) < 0 )
return - V_38 ;
F_18 ( & V_49 ) ;
if ( ( V_53 & 0x1 ) && ( V_54 & 0x1 ) )
V_18 . V_57 |= V_58 ;
else if ( V_53 & 0x1 )
V_18 . V_57 &= ~ V_58 ;
if ( ( V_53 & 0x2 ) && ( V_54 & 0x2 ) )
V_18 . V_57 |= V_59 ;
else if ( V_53 & 0x2 )
V_18 . V_57 &= ~ V_59 ;
V_1 = 0 ;
if ( V_18 . V_57 & V_58 ) V_1 |= 0x1 ;
if ( V_18 . V_57 & V_59 ) V_1 |= 0x2 ;
if ( V_18 . V_60 & V_61 ) V_1 |= 0x4 ;
if ( V_18 . V_60 & V_62 ) V_1 |= 0x8 ;
F_19 ( & V_49 ) ;
return F_15 ( V_1 , & V_56 -> V_1 ) ;
}
case V_63 :
if ( V_43 > 31 || V_43 < 0 )
return - V_15 ;
F_18 ( & V_49 ) ;
V_18 . V_64 = ( T_1 ) ( ( V_43 & V_65 ) |
V_66 ) ;
F_19 ( & V_49 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_39 ;
}
}
static int F_20 ( struct V_26 * V_26 , struct V_22 * V_22 )
{
int V_16 = F_13 ( V_26 ) & 0x0f ;
int V_67 = 0 ;
F_18 ( & V_49 ) ;
switch( V_16 )
{
case V_30 :
if ( F_21 ( 0 , & V_32 . V_68 ) ) {
V_67 = - V_69 ;
goto V_54;
}
V_32 . V_35 = V_70 ;
V_32 . V_34 = V_71 ;
V_32 . V_33 = V_32 . V_40 = 4 ;
V_72 ;
V_73 ;
V_18 . V_57 &= ~ V_58 ;
V_18 . V_57 &= ~ V_59 ;
break;
default:
V_67 = - V_74 ;
}
V_54:
F_19 ( & V_49 ) ;
return V_67 ;
}
static int F_22 ( struct V_26 * V_26 , struct V_22 * V_22 )
{
int V_16 = F_13 ( V_26 ) & 0x0f ;
switch( V_16 )
{
case V_30 :
F_23 ( 0 , & V_32 . V_68 ) ;
break;
default:
F_6 ( V_14 L_6 , V_16 ) ;
return - V_39 ;
}
return 0 ;
}
static int T_6 F_24 ( void )
{
int V_12 = 0 ;
if( ! V_75 || ! F_25 ( V_76 ) ) {
F_6 ( L_7 ) ;
return - V_74 ;
}
if( F_26 ( V_77 , L_2 , & V_78 ) ) {
F_6 ( L_8 ) ;
return - V_74 ;
}
V_79 = F_27 ( V_80 , L_2 ) ;
if ( F_5 ( V_79 ) ) {
V_12 = F_28 ( V_79 ) ;
goto V_81;
}
F_29 ( V_79 , NULL , F_30 ( V_77 , 0 ) , NULL ,
L_2 ) ;
F_6 ( V_82 ) ;
goto V_54;
V_81:
F_31 ( V_77 , L_2 ) ;
V_54:
return V_12 ;
}
static void T_7 F_32 ( void )
{
F_33 ( V_79 , F_30 ( V_77 , 0 ) ) ;
F_34 ( V_79 ) ;
F_31 ( V_77 , L_2 ) ;
}
