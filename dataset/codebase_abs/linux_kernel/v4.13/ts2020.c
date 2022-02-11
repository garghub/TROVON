static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_7 -> V_8 , L_1 ) ;
F_3 ( V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_1 V_10 ;
if ( V_4 -> V_11 == V_12 )
V_10 = 0x0a ;
else
V_10 = 0x00 ;
V_9 = F_5 ( V_4 -> V_13 , V_10 , 0x00 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_4 -> V_14 )
F_6 ( & V_4 -> V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_18 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_19 ;
T_1 V_10 ;
if ( V_4 -> V_11 == V_12 ) {
F_5 ( V_4 -> V_13 , 0x42 , 0x73 ) ;
F_5 ( V_4 -> V_13 , 0x05 , V_4 -> V_20 ) ;
F_5 ( V_4 -> V_13 , 0x20 , 0x27 ) ;
F_5 ( V_4 -> V_13 , 0x07 , 0x02 ) ;
F_5 ( V_4 -> V_13 , 0x11 , 0xff ) ;
F_5 ( V_4 -> V_13 , 0x60 , 0xf9 ) ;
F_5 ( V_4 -> V_13 , 0x08 , 0x01 ) ;
F_5 ( V_4 -> V_13 , 0x00 , 0x41 ) ;
} else {
static const struct V_21 V_22 [] = {
{ 0x7d , 0x9d } ,
{ 0x7c , 0x9a } ,
{ 0x7a , 0x76 } ,
{ 0x3b , 0x01 } ,
{ 0x63 , 0x88 } ,
{ 0x61 , 0x85 } ,
{ 0x22 , 0x30 } ,
{ 0x30 , 0x40 } ,
{ 0x20 , 0x23 } ,
{ 0x24 , 0x02 } ,
{ 0x12 , 0xa0 } ,
} ;
F_5 ( V_4 -> V_13 , 0x00 , 0x01 ) ;
F_5 ( V_4 -> V_13 , 0x00 , 0x03 ) ;
switch ( V_4 -> V_23 ) {
case V_24 :
V_10 = 0x60 ;
break;
case V_25 :
V_10 = 0x70 ;
F_5 ( V_4 -> V_13 , 0x05 , V_4 -> V_20 ) ;
break;
case V_26 :
V_10 = 0x6c ;
break;
default:
V_10 = 0x60 ;
break;
}
F_5 ( V_4 -> V_13 , 0x42 , V_10 ) ;
if ( V_4 -> V_27 )
V_10 = 0xec ;
else
V_10 = 0x6c ;
F_5 ( V_4 -> V_13 , 0x62 , V_10 ) ;
for ( V_19 = 0 ; V_19 < F_8 ( V_22 ) ; V_19 ++ )
F_5 ( V_4 -> V_13 , V_22 [ V_19 ] . V_28 ,
V_22 [ V_19 ] . V_29 ) ;
}
V_17 -> V_30 . V_31 = 1 ;
V_17 -> V_30 . V_32 [ 0 ] . V_33 = V_34 ;
V_17 -> V_30 . V_32 [ 0 ] . V_35 = 0 ;
F_9 ( & V_4 -> V_15 . V_36 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_9 = F_5 ( V_4 -> V_13 , 0x51 , 0x1f - V_37 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x51 , 0x1f ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x50 , V_37 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x50 , 0x00 ) ;
F_11 ( 20 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = V_2 -> V_5 ;
int V_9 ;
unsigned int V_38 ;
V_9 = F_13 ( V_8 -> V_13 , 0x3d , & V_38 ) ;
V_38 &= 0x7f ;
if ( V_38 < 0x16 )
V_38 = 0xa1 ;
else if ( V_38 == 0x16 )
V_38 = 0x99 ;
else
V_38 = 0xf9 ;
F_5 ( V_8 -> V_13 , 0x60 , V_38 ) ;
V_9 = F_10 ( V_2 , 0x08 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_18 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
unsigned int V_38 ;
T_2 V_39 , V_40 ;
T_3 V_41 , V_42 , V_43 ;
T_1 V_44 [ 3 ] , V_45 , V_46 , V_47 , V_48 , V_49 ;
unsigned int V_50 , V_51 , V_52 , V_53 , V_54 ;
unsigned int V_55 = V_17 -> V_56 ;
V_50 = V_57 ;
V_52 = F_15 ( V_50 , 2000 ) ;
if ( V_55 < V_4 -> V_58 ) {
V_53 = 4 ;
V_45 = 0x10 ;
} else {
V_53 = 2 ;
V_45 = 0x00 ;
}
V_51 = V_55 * V_53 ;
V_54 = V_51 * V_52 / V_50 ;
V_54 += V_54 % 2 ;
V_4 -> V_55 = V_54 * V_50 / V_52 / V_53 ;
F_16 ( L_2 ,
V_4 -> V_55 , V_4 -> V_55 - V_17 -> V_56 ,
V_51 , V_54 , V_52 , V_53 ) ;
if ( V_4 -> V_11 == V_12 ) {
V_43 = 2766 ;
V_45 |= 0x01 ;
V_9 = F_5 ( V_4 -> V_13 , 0x10 , V_45 ) ;
} else {
V_43 = 3200 ;
V_45 |= 0x0b ;
V_9 = F_5 ( V_4 -> V_13 , 0x10 , V_45 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x11 , 0x40 ) ;
}
V_41 = V_54 - 1024 ;
V_44 [ 0 ] = ( V_41 >> 8 ) & 0xff ;
V_44 [ 1 ] = ( V_41 >> 0 ) & 0xff ;
V_44 [ 2 ] = V_52 - 8 ;
V_9 |= F_5 ( V_4 -> V_13 , 0x01 , V_44 [ 0 ] ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x02 , V_44 [ 1 ] ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x03 , V_44 [ 2 ] ) ;
V_9 |= F_10 ( V_2 , 0x10 ) ;
if ( V_9 < 0 )
return - V_59 ;
V_9 |= F_10 ( V_2 , 0x08 ) ;
if ( V_4 -> V_11 == V_12 )
V_9 |= F_12 ( V_2 ) ;
V_40 = ( V_57 / 1000 * 1694 + 500 ) / 1000 ;
V_9 |= F_5 ( V_4 -> V_13 , 0x04 , V_40 & 0xff ) ;
V_9 |= F_10 ( V_2 , 0x04 ) ;
if ( V_9 < 0 )
return - V_59 ;
if ( V_4 -> V_11 == V_60 ) {
V_9 = F_5 ( V_4 -> V_13 , 0x25 , 0x00 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x27 , 0x70 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x41 , 0x09 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x08 , 0x0b ) ;
if ( V_9 < 0 )
return - V_59 ;
}
F_13 ( V_4 -> V_13 , 0x26 , & V_38 ) ;
V_42 = V_38 ;
V_39 = ( V_17 -> V_61 / 1000 / 2 ) + 2000 ;
V_39 += V_62 ;
V_39 = F_17 ( V_39 , 7000U , 40000U ) ;
V_40 = V_40 * 207 / ( V_42 * 2 + 151 ) ;
V_47 = V_40 * 135 / 100 ;
V_48 = V_40 * 78 / 100 ;
if ( V_47 > 63 )
V_47 = 63 ;
V_49 = ( V_39 * V_40 * 2 / V_43 /
( V_57 / 1000 ) + 1 ) / 2 ;
if ( V_49 > 23 )
V_49 = 23 ;
if ( V_49 < 1 )
V_49 = 1 ;
V_46 = ( V_49 * ( V_57 / 1000 )
* V_43 * 2 / V_39 + 1 ) / 2 ;
if ( V_46 < V_48 ) {
V_49 ++ ;
V_46 = ( V_49 * ( V_57 / 1000 )
* V_43 * 2 / V_39 + 1 ) / 2 ;
}
if ( V_46 > V_47 )
V_46 = V_47 ;
V_9 = F_5 ( V_4 -> V_13 , 0x04 , V_46 ) ;
V_9 |= F_5 ( V_4 -> V_13 , 0x06 , V_49 ) ;
V_9 |= F_10 ( V_2 , 0x04 ) ;
V_9 |= F_10 ( V_2 , 0x01 ) ;
F_11 ( 80 ) ;
return ( V_9 < 0 ) ? - V_63 : 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_56 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
* V_56 = V_4 -> V_55 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_56 )
{
* V_56 = 0 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_64 ,
T_4 * V_65 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_66 , V_67 , V_68 ;
unsigned V_38 ;
int V_9 ;
V_9 = F_13 ( V_4 -> V_13 , 0x3d , & V_38 ) ;
if ( V_9 < 0 )
return V_9 ;
V_66 = V_38 & 0x1f ;
V_9 = F_13 ( V_4 -> V_13 , 0x21 , & V_38 ) ;
if ( V_9 < 0 )
return V_9 ;
V_67 = V_38 & 0x1f ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_66 = F_21 ( long , V_66 , 0 , 15 ) ;
V_67 = F_21 ( long , V_67 , 0 , 13 ) ;
V_64 = F_21 ( long , V_64 , 400 , 1100 ) ;
* V_65 = - ( V_66 * 2330 +
V_67 * 3500 +
V_64 * 24 / 10 * 10 +
10000 ) ;
break;
case V_60 :
V_9 = F_13 ( V_4 -> V_13 , 0x66 , & V_38 ) ;
if ( V_9 < 0 )
return V_9 ;
V_68 = ( V_38 >> 3 ) & 0x07 ;
V_66 = F_21 ( long , V_66 , 0 , 15 ) ;
V_67 = F_21 ( long , V_67 , 2 , 16 ) ;
V_68 = F_21 ( long , V_68 , 0 , 6 ) ;
V_64 = F_21 ( long , V_64 , 600 , 1600 ) ;
* V_65 = - ( V_66 * 2650 +
V_67 * 3380 +
V_68 * 2850 +
V_64 * 176 / 100 * 10 -
30000 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_4 * V_65 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 = 0 , V_9 ;
T_1 V_69 ;
if ( V_4 -> V_70 ) {
V_9 = V_4 -> V_70 ( V_2 , & V_69 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_64 = ( int ) V_69 * 20 - 1166 ;
break;
case V_60 :
V_64 = ( int ) V_69 * 16 - 670 ;
break;
}
if ( V_64 < 0 )
V_64 = 0 ;
}
return F_20 ( V_2 , V_64 , V_65 ) ;
}
static void F_9 ( struct V_71 * V_36 )
{
struct V_3 * V_4 = F_23 ( V_36 , struct V_3 ,
V_15 . V_36 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_16 * V_17 = & V_4 -> V_2 -> V_18 ;
int V_9 ;
F_2 ( & V_7 -> V_8 , L_1 ) ;
V_9 = F_22 ( V_4 -> V_2 , & V_17 -> V_30 . V_32 [ 0 ] . V_72 ) ;
if ( V_9 < 0 )
goto V_73;
V_17 -> V_30 . V_32 [ 0 ] . V_33 = V_34 ;
if ( ! V_4 -> V_14 )
F_24 ( & V_4 -> V_15 , F_25 ( 2000 ) ) ;
return;
V_73:
F_2 ( & V_7 -> V_8 , L_3 , V_9 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_3 * V_74 )
{
struct V_16 * V_17 = & V_2 -> V_18 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned V_30 ;
T_4 V_75 ;
if ( V_4 -> V_14 )
F_9 ( & V_4 -> V_15 . V_36 ) ;
if ( V_17 -> V_30 . V_32 [ 0 ] . V_33 == V_76 ) {
* V_74 = 0 ;
return 0 ;
}
V_75 = V_17 -> V_30 . V_32 [ 0 ] . V_72 ;
if ( V_75 < - 85000 )
V_30 = 0 ;
else if ( V_75 < - 65000 )
V_30 = 0 + F_27 ( ( 85000 + V_75 ) * 3 , 1000 ) ;
else if ( V_75 < - 45000 )
V_30 = 60 + F_27 ( ( 65000 + V_75 ) * 3 , 2000 ) ;
else
V_30 = 90 + F_27 ( ( 45000 + V_75 ) , 5000 ) ;
* V_74 = V_30 * 65535 / 100 ;
return 0 ;
}
struct V_1 * F_28 ( struct V_1 * V_2 ,
const struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_6 * V_7 ;
struct V_81 V_82 ;
struct V_77 V_83 ;
memcpy ( & V_83 , V_78 , sizeof( V_83 ) ) ;
V_83 . V_2 = V_2 ;
V_83 . V_84 = true ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
F_29 ( V_82 . type , L_4 , V_85 ) ;
V_82 . V_86 = V_78 -> V_87 ;
V_82 . V_88 = & V_83 ;
V_7 = F_30 ( V_80 , & V_82 ) ;
if ( ! V_7 || ! V_7 -> V_8 . V_89 )
return NULL ;
return V_2 ;
}
static void F_31 ( void * V_90 )
{
struct V_3 * V_8 = V_90 ;
F_32 ( & V_8 -> V_91 ) ;
if ( V_8 -> V_2 -> V_92 . V_93 )
V_8 -> V_2 -> V_92 . V_93 ( V_8 -> V_2 , 1 ) ;
}
static void F_33 ( void * V_90 )
{
struct V_3 * V_8 = V_90 ;
if ( V_8 -> V_2 -> V_92 . V_93 )
V_8 -> V_2 -> V_92 . V_93 ( V_8 -> V_2 , 0 ) ;
F_34 ( & V_8 -> V_91 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
const struct V_94 * V_95 )
{
struct V_77 * V_83 = V_7 -> V_8 . V_88 ;
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_3 * V_8 ;
int V_9 ;
T_1 V_10 ;
unsigned int V_38 ;
char * V_96 ;
V_8 = F_36 ( sizeof( * V_8 ) , V_97 ) ;
if ( ! V_8 ) {
V_9 = - V_98 ;
goto V_73;
}
F_37 ( & V_8 -> V_91 ) ;
V_8 -> V_99 . V_100 = 8 ,
V_8 -> V_99 . V_101 = 8 ,
V_8 -> V_99 . V_102 = F_31 ,
V_8 -> V_99 . V_103 = F_33 ,
V_8 -> V_99 . V_104 = V_8 ,
V_8 -> V_13 = F_38 ( V_7 , & V_8 -> V_99 ) ;
if ( F_39 ( V_8 -> V_13 ) ) {
V_9 = F_40 ( V_8 -> V_13 ) ;
goto V_105;
}
V_8 -> V_80 = V_7 -> V_106 ;
V_8 -> V_107 = V_7 -> V_86 ;
V_8 -> V_27 = V_83 -> V_27 ;
V_8 -> V_23 = V_83 -> V_23 ;
V_8 -> V_20 = V_83 -> V_20 ;
V_8 -> V_14 = V_83 -> V_14 ;
V_8 -> V_58 = V_83 -> V_58 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_70 = V_83 -> V_70 ;
V_2 -> V_5 = V_8 ;
V_8 -> V_7 = V_7 ;
F_41 ( & V_8 -> V_15 , F_9 ) ;
V_9 = F_13 ( V_8 -> V_13 , 0x00 , & V_38 ) ;
if ( V_9 )
goto V_108;
if ( ( V_38 & 0x03 ) == 0x00 ) {
V_9 = F_5 ( V_8 -> V_13 , 0x00 , 0x01 ) ;
if ( V_9 )
goto V_108;
F_42 ( 2000 , 50000 ) ;
}
V_9 = F_5 ( V_8 -> V_13 , 0x00 , 0x03 ) ;
if ( V_9 )
goto V_108;
F_42 ( 2000 , 50000 ) ;
V_9 = F_13 ( V_8 -> V_13 , 0x00 , & V_38 ) ;
if ( V_9 )
goto V_108;
F_2 ( & V_7 -> V_8 , L_5 , V_38 ) ;
switch ( V_38 ) {
case 0x01 :
case 0x41 :
case 0x81 :
V_8 -> V_11 = V_12 ;
V_96 = L_6 ;
if ( ! V_8 -> V_58 )
V_8 -> V_58 = 1060000 ;
break;
case 0xc3 :
case 0x83 :
V_8 -> V_11 = V_60 ;
V_96 = L_7 ;
if ( ! V_8 -> V_58 )
V_8 -> V_58 = 1103000 ;
break;
default:
V_9 = - V_59 ;
goto V_108;
}
if ( V_8 -> V_11 == V_60 ) {
switch ( V_8 -> V_23 ) {
case V_24 :
V_10 = 0x60 ;
break;
case V_25 :
V_10 = 0x70 ;
V_9 = F_5 ( V_8 -> V_13 , 0x05 , V_8 -> V_20 ) ;
if ( V_9 )
goto V_108;
break;
case V_26 :
V_10 = 0x6c ;
break;
default:
V_9 = - V_63 ;
goto V_108;
}
V_9 = F_5 ( V_8 -> V_13 , 0x42 , V_10 ) ;
if ( V_9 )
goto V_108;
if ( V_8 -> V_27 )
V_10 = 0xec ;
else
V_10 = 0x6c ;
V_9 = F_5 ( V_8 -> V_13 , 0x62 , V_10 ) ;
if ( V_9 )
goto V_108;
}
V_9 = F_5 ( V_8 -> V_13 , 0x00 , 0x00 ) ;
if ( V_9 )
goto V_108;
F_43 ( & V_7 -> V_8 ,
L_8 , V_96 ) ;
memcpy ( & V_2 -> V_92 . V_109 , & V_110 ,
sizeof( struct V_111 ) ) ;
if ( ! V_83 -> V_84 )
V_2 -> V_92 . V_109 . V_112 = NULL ;
F_44 ( V_7 , V_8 ) ;
return 0 ;
V_108:
F_45 ( V_8 -> V_13 ) ;
V_105:
F_46 ( V_8 ) ;
V_73:
F_2 ( & V_7 -> V_8 , L_3 , V_9 ) ;
return V_9 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_48 ( V_7 ) ;
F_2 ( & V_7 -> V_8 , L_1 ) ;
if ( ! V_8 -> V_14 )
F_6 ( & V_8 -> V_15 ) ;
F_45 ( V_8 -> V_13 ) ;
F_46 ( V_8 ) ;
return 0 ;
}
