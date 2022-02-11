static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
return ( V_2 -> V_5 -> V_6 ) ?
V_2 -> V_5 -> V_6 ( V_2 -> V_7 , V_3 , V_4 ) :
- V_8 ;
}
static int F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return ( V_2 -> V_5 -> V_9 ) ?
V_2 -> V_5 -> V_9 ( V_2 -> V_7 , V_3 , V_4 ) :
- V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
return ( V_2 -> V_5 -> V_12 ) ?
V_2 -> V_5 -> V_12 ( V_2 -> V_7 , V_11 ) :
- V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_13 )
{
return ( V_2 -> V_5 -> V_14 ) ?
V_2 -> V_5 -> V_14 ( V_2 -> V_7 , V_13 ) :
- V_8 ;
}
static struct V_10 * F_5 ( T_2 V_15 ,
T_1 V_16 )
{
T_1 V_17 ;
switch ( V_16 ) {
case 0 :
V_17 = 25 ;
break;
case 1 :
V_17 = 69 ;
break;
case 6 :
V_17 = 21 ;
break;
case 7 :
V_17 = 42 ;
break;
case 8 :
V_17 = 63 ;
break;
default:
F_6 ( L_1 , V_18 ) ;
return NULL ;
}
V_15 /= 1000000 ;
V_15 *= 64 ;
#if 0
freq += 0.5;
#endif
V_19 [ 0 ] . V_4 = V_17 ;
V_19 [ 1 ] . V_4 = ( V_15 & 0xff ) ;
V_19 [ 2 ] . V_4 = ( V_15 >> 8 ) & 0xff ;
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_20 ;
T_1 V_21 ;
#if 0
u16 iffcw;
u32 if_freq;
#endif
F_8 ( L_2 ,
V_2 -> V_5 -> V_22 , V_2 -> V_5 -> V_23 ) ;
V_21 = V_2 -> V_5 -> V_22 ;
V_21 |= V_2 -> V_5 -> V_23 ;
V_20 = F_2 ( V_2 , V_24 , V_21 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
#if 0
if_freq /= 1000000;
if_freq += 0.5;
if (MXL_IF_LO == state->cfg->if_freq) {
ctrl = 0x08;
iffcw = (u16)(if_freq / (108 * 4096));
} else if (MXL_IF_HI == state->cfg->if_freq) {
ctrl = 0x08;
iffcw = (u16)(if_freq / (216 * 4096));
} else {
ctrl = 0;
iffcw = 0;
}
ctrl |= (iffcw >> 8);
#endif
V_20 = F_1 ( V_2 , V_26 , & V_21 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_21 &= 0xf0 ;
V_21 |= 0x90 ;
V_20 = F_2 ( V_2 , V_26 , V_21 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
#if 0
ctrl = iffcw & 0x00ff;
#endif
V_20 = F_2 ( V_2 , V_27 , V_21 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_2 -> V_23 = V_2 -> V_5 -> V_23 ;
V_25:
return V_20 ;
}
static int F_10 ( struct V_28 * V_29 , T_2 V_15 , T_1 V_16 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
static struct V_10 * V_31 ;
int V_20 ;
T_1 V_32 ;
F_8 ( L_3 , V_15 , V_16 ) ;
V_20 = F_2 ( V_2 , V_33 , 0 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_20 = F_1 ( V_2 , V_34 , & V_32 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_31 = F_5 ( V_15 , V_16 ) ;
if ( ! V_31 )
return - V_8 ;
V_20 = F_3 ( V_2 , V_31 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
if ( ( V_32 & V_35 ) == V_36 ) {
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
}
V_20 = F_2 ( V_2 , V_33 , 1 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
if ( V_2 -> V_5 -> V_37 )
V_2 -> V_5 -> V_37 ( V_29 ) ;
V_25:
return V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
int * V_38 ,
int * V_39 )
{
int V_20 ;
T_1 V_4 ;
* V_38 = 0 ;
* V_39 = 0 ;
V_20 = F_1 ( V_2 , V_40 , & V_4 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
* V_39 = ( ( V_4 & 0x03 ) == 0x03 ) ? 1 : 0 ;
* V_38 = ( ( V_4 & 0x0c ) == 0x0c ) ? 1 : 0 ;
V_25:
return V_20 ;
}
static int F_12 ( struct V_28 * V_29 )
{
struct V_41 * V_42 = & V_29 -> V_43 ;
T_2 V_44 = V_42 -> V_45 ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_20 ;
T_1 V_16 ;
F_8 ( L_4 ) ;
switch ( V_44 ) {
case V_46 :
V_16 = 0 ;
break;
case V_47 :
V_16 = 1 ;
break;
case V_48 :
switch ( V_42 -> V_49 ) {
case 6000000 :
V_16 = 6 ;
break;
case 7000000 :
V_16 = 7 ;
break;
case 8000000 :
V_16 = 8 ;
break;
default:
F_6 ( L_5 , V_18 ) ;
return - V_8 ;
}
break;
default:
F_6 ( L_6 , V_18 ) ;
return - V_8 ;
}
V_20 = F_10 ( V_29 , V_42 -> V_50 , V_16 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_2 -> V_50 = V_42 -> V_50 ;
V_2 -> V_51 = V_42 -> V_49 ;
V_25:
return V_20 ;
}
static int F_13 ( struct V_28 * V_29 , T_2 * V_52 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_53 , V_54 , V_20 ;
* V_52 = 0 ;
V_20 = F_11 ( V_2 , & V_53 , & V_54 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
F_14 ( L_7 , V_53 ? L_8 : L_9 ,
V_54 ? L_10 : L_9 ) ;
if ( ( V_53 ) || ( V_54 ) )
* V_52 |= V_55 ;
V_25:
return V_20 ;
}
static int F_15 ( struct V_28 * V_29 , T_3 * V_56 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
T_1 V_57 , V_58 ;
int V_20 ;
* V_56 = 0 ;
V_20 = F_2 ( V_2 , 0x00 , 0x02 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_20 = F_1 ( V_2 , V_59 , & V_57 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
V_20 = F_1 ( V_2 , V_60 , & V_58 ) ;
if ( F_9 ( V_20 ) )
goto V_25;
* V_56 = V_57 | ( ( V_58 & 0x07 ) << 8 ) ;
V_25:
V_20 = F_2 ( V_2 , 0x00 , 0x00 ) ;
F_9 ( V_20 ) ;
return V_20 ;
}
static int F_16 ( struct V_28 * V_29 , T_2 * V_50 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
* V_50 = V_2 -> V_50 ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 , T_2 * V_51 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
* V_51 = V_2 -> V_51 ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 ,
T_2 * V_50 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
* V_50 = 0 ;
switch ( V_2 -> V_23 ) {
case V_61 :
* V_50 = 4000000 ;
break;
case V_62 :
* V_50 = 4500000 ;
break;
case V_63 :
* V_50 = 4570000 ;
break;
case V_64 :
* V_50 = 5000000 ;
break;
case V_65 :
* V_50 = 5380000 ;
break;
case V_66 :
* V_50 = 6000000 ;
break;
case V_67 :
* V_50 = 6280000 ;
break;
case V_68 :
* V_50 = 7200000 ;
break;
case V_69 :
* V_50 = 35250000 ;
break;
case V_70 :
* V_50 = 36000000 ;
break;
case V_71 :
* V_50 = 36150000 ;
break;
case V_72 :
* V_50 = 44000000 ;
break;
}
return 0 ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
F_8 ( L_4 ) ;
F_20 ( V_2 ) ;
V_29 -> V_30 = NULL ;
return 0 ;
}
struct V_28 * F_21 ( struct V_28 * V_29 ,
struct V_73 * V_7 ,
struct V_74 * V_5 )
{
struct V_1 * V_2 = NULL ;
F_8 ( L_4 ) ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_75 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = V_5 ;
memcpy ( & V_29 -> V_76 . V_77 , & V_78 ,
sizeof( struct V_79 ) ) ;
V_29 -> V_30 = V_2 ;
return V_29 ;
}
