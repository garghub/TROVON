static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 ,
const void * V_8 , void * V_9 , T_2 V_10 )
{
void * V_11 = NULL , * V_12 = NULL ;
struct V_13 V_14 [ 2 ] = {} ;
T_1 * V_15 ;
int V_16 ;
V_15 = F_4 ( 1 , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_15 [ 0 ] = V_7 ;
V_14 [ 0 ] . V_19 = V_15 ;
V_14 [ 0 ] . V_10 = 1 ;
if ( V_8 && V_10 <= 32 ) {
V_11 = F_4 ( V_10 , V_17 ) ;
if ( ! V_11 ) {
V_16 = - V_18 ;
goto V_20;
}
memcpy ( V_11 , V_8 , V_10 ) ;
}
if ( V_9 ) {
V_12 = F_4 ( V_10 , V_17 ) ;
if ( ! V_12 ) {
V_16 = - V_18 ;
goto V_20;
}
}
V_14 [ 1 ] . V_19 = V_11 ? V_11 : V_8 ;
V_14 [ 1 ] . V_21 = V_12 ;
V_14 [ 1 ] . V_10 = V_10 ;
F_5 ( 80 ) ;
V_16 = F_6 ( V_6 , V_14 , 2 ) ;
if ( V_9 && ! V_16 )
memcpy ( V_9 , V_12 , V_10 ) ;
V_20:
F_7 ( V_15 ) ;
F_7 ( V_11 ) ;
F_7 ( V_12 ) ;
return V_16 ;
}
static int F_8 ( struct V_5 * V_6 , T_1 V_22 ,
const T_1 * V_23 , T_2 V_10 )
{
int V_16 ;
V_16 = F_3 ( V_6 , 0x70 , & V_22 , NULL , 1 ) ;
if ( V_16 )
return V_16 ;
return F_3 ( V_6 , 0x72 , V_23 , NULL , V_10 ) ;
}
static int F_9 ( struct V_5 * V_6 , T_1 V_22 , T_1 V_24 )
{
return F_8 ( V_6 , V_22 , & V_24 , 1 ) ;
}
static int F_10 ( struct V_5 * V_6 , T_1 V_22 )
{
int V_16 ;
T_1 V_24 ;
V_16 = F_3 ( V_6 , 0x70 , & V_22 , NULL , 1 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_3 ( V_6 , 0x73 , NULL , & V_24 , 1 ) ;
return V_16 ? V_16 : V_24 ;
}
static int F_11 ( struct V_5 * V_6 )
{
int V_16 ;
T_1 V_25 ;
V_16 = F_3 ( V_6 , 0x71 , NULL , & V_25 , 1 ) ;
return V_16 ? V_16 : V_25 ;
}
static void F_12 ( struct V_5 * V_6 )
{
const T_1 V_23 [ 1 ] = { 0 } ;
F_13 ( V_6 , V_23 , 1 ) ;
}
static void F_14 ( struct V_1 * V_26 , T_1 * * V_27 ,
const T_1 * V_28 , T_1 V_29 , const T_1 * V_30 ,
enum V_31 V_32 )
{
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < ( V_26 -> V_34 / 8 ) ; V_33 ++ ) {
if ( V_28 ) {
T_1 V_35 = V_28 [ V_33 ] & 0xaa ;
T_1 V_36 = 0xff ;
T_1 V_37 , V_38 , V_39 , V_40 ;
if ( V_30 ) {
V_36 = ( V_30 [ V_33 ] ^ V_35 ) & 0xaa ;
V_36 |= V_36 >> 1 ;
}
switch ( V_32 ) {
case V_41 :
V_35 = 0xaa | ( ( V_35 ^ 0xaa ) >> 1 ) ;
break;
case V_42 :
V_35 = 0x55 + ( ( V_35 ^ 0xaa ) >> 1 ) ;
break;
case V_43 :
V_35 = 0x55 | ( V_35 ^ 0xaa ) ;
break;
case V_44 :
V_35 = 0xaa | ( V_35 >> 1 ) ;
break;
}
V_35 = ( V_35 & V_36 ) | ( ~ V_36 & 0x55 ) ;
V_37 = ( V_35 >> 6 ) & 0x03 ;
V_38 = ( V_35 >> 4 ) & 0x03 ;
V_39 = ( V_35 >> 2 ) & 0x03 ;
V_40 = ( V_35 >> 0 ) & 0x03 ;
V_35 = ( V_37 << 0 ) | ( V_38 << 2 ) | ( V_39 << 4 ) | ( V_40 << 6 ) ;
* ( * V_27 ) ++ = V_35 ;
} else {
* ( * V_27 ) ++ = V_29 ;
}
}
}
static void F_15 ( struct V_1 * V_26 , T_1 * * V_27 ,
const T_1 * V_28 , T_1 V_29 , const T_1 * V_30 ,
enum V_31 V_32 )
{
unsigned int V_33 ;
for ( V_33 = V_26 -> V_34 / 8 ; V_33 > 0 ; V_33 -- ) {
if ( V_28 ) {
T_1 V_35 = V_28 [ V_33 - 1 ] & 0x55 ;
T_1 V_36 = 0xff ;
if ( V_30 ) {
V_36 = ( V_30 [ V_33 - 1 ] ^ V_35 ) & 0x55 ;
V_36 |= V_36 << 1 ;
}
switch ( V_32 ) {
case V_41 :
V_35 = 0xaa | ( V_35 ^ 0x55 ) ;
break;
case V_42 :
V_35 = 0x55 + ( V_35 ^ 0x55 ) ;
break;
case V_43 :
V_35 = 0x55 | ( ( V_35 ^ 0x55 ) << 1 ) ;
break;
case V_44 :
V_35 = 0xaa | V_35 ;
break;
}
V_35 = ( V_35 & V_36 ) | ( ~ V_36 & 0x55 ) ;
* ( * V_27 ) ++ = V_35 ;
} else {
* ( * V_27 ) ++ = V_29 ;
}
}
}
static inline T_3 F_16 ( T_3 V_45 )
{
V_45 = ( V_45 | ( V_45 << 4 ) ) & 0x0f0f ;
V_45 = ( V_45 | ( V_45 << 2 ) ) & 0x3333 ;
V_45 = ( V_45 | ( V_45 << 1 ) ) & 0x5555 ;
return V_45 ;
}
static void F_17 ( struct V_1 * V_26 , T_1 * * V_27 ,
const T_1 * V_28 , T_1 V_29 , const T_1 * V_30 ,
enum V_31 V_32 )
{
unsigned int V_33 ;
for ( V_33 = V_26 -> V_34 / 8 ; V_33 > 0 ; V_33 -- ) {
if ( V_28 ) {
T_3 V_35 = F_16 ( V_28 [ V_33 - 1 ] ) ;
T_3 V_36 = 0xffff ;
if ( V_30 ) {
V_36 = F_16 ( V_30 [ V_33 - 1 ] ) ;
V_36 = ( V_36 ^ V_35 ) & 0x5555 ;
V_36 |= V_36 << 1 ;
}
switch ( V_32 ) {
case V_41 :
V_35 = 0xaaaa | ( V_35 ^ 0x5555 ) ;
break;
case V_42 :
V_35 = 0x5555 + ( V_35 ^ 0x5555 ) ;
break;
case V_43 :
V_35 = 0x5555 | ( ( V_35 ^ 0x5555 ) << 1 ) ;
break;
case V_44 :
V_35 = 0xaaaa | V_35 ;
break;
}
V_35 = ( V_35 & V_36 ) | ( ~ V_36 & 0x5555 ) ;
* ( * V_27 ) ++ = V_35 >> 8 ;
* ( * V_27 ) ++ = V_35 ;
} else {
* ( * V_27 ) ++ = V_29 ;
* ( * V_27 ) ++ = V_29 ;
}
}
}
static void F_18 ( struct V_1 * V_26 , unsigned int line ,
const T_1 * V_28 , T_1 V_29 , const T_1 * V_30 ,
enum V_31 V_32 )
{
T_1 * V_46 = V_26 -> V_47 ;
unsigned int V_33 ;
F_12 ( V_26 -> V_6 ) ;
if ( V_26 -> V_48 )
* V_46 ++ = 0x00 ;
if ( V_26 -> V_49 ) {
F_15 ( V_26 , & V_46 , V_28 , V_29 , V_30 , V_32 ) ;
for ( V_33 = V_26 -> V_50 ; V_33 > 0 ; V_33 -- ) {
if ( line / 4 == V_33 - 1 )
* V_46 ++ = 0x03 << ( 2 * ( line & 0x03 ) ) ;
else
* V_46 ++ = 0x00 ;
}
F_14 ( V_26 , & V_46 , V_28 , V_29 , V_30 , V_32 ) ;
} else {
for ( V_33 = 0 ; V_33 < V_26 -> V_50 ; V_33 ++ ) {
if ( 0 != ( line & 0x01 ) && line / 8 == V_33 )
* V_46 ++ = 0xc0 >> ( line & 0x06 ) ;
else
* V_46 ++ = 0x00 ;
}
F_17 ( V_26 , & V_46 , V_28 , V_29 , V_30 , V_32 ) ;
for ( V_33 = V_26 -> V_50 ; V_33 > 0 ; V_33 -- ) {
if ( 0 == ( line & 0x01 ) && line / 8 == V_33 - 1 )
* V_46 ++ = 0x03 << ( line & 0x06 ) ;
else
* V_46 ++ = 0x00 ;
}
}
switch ( V_26 -> V_51 ) {
case V_52 :
break;
case V_53 :
* V_46 ++ = 0x00 ;
break;
case V_54 :
switch ( V_32 ) {
case V_41 :
case V_42 :
case V_43 :
* V_46 ++ = 0x00 ;
break;
case V_44 :
* V_46 ++ = 0xaa ;
break;
}
break;
}
F_8 ( V_26 -> V_6 , 0x0a , V_26 -> V_47 ,
V_46 - V_26 -> V_47 ) ;
F_9 ( V_26 -> V_6 , 0x02 , 0x07 ) ;
F_12 ( V_26 -> V_6 ) ;
}
static void F_19 ( struct V_1 * V_26 , T_1 V_29 ,
enum V_31 V_32 )
{
unsigned int line ;
for ( line = 0 ; line < V_26 -> V_55 ; line ++ )
F_18 ( V_26 , line , NULL , V_29 , NULL , V_32 ) ;
}
static void F_20 ( struct V_1 * V_26 , const T_1 * V_56 ,
const T_1 * V_30 , enum V_31 V_32 )
{
unsigned int line ;
if ( ! V_30 ) {
for ( line = 0 ; line < V_26 -> V_55 ; line ++ ) {
F_18 ( V_26 , line ,
& V_56 [ line * ( V_26 -> V_34 / 8 ) ] ,
0 , NULL , V_32 ) ;
}
} else {
for ( line = 0 ; line < V_26 -> V_55 ; line ++ ) {
T_2 V_57 = line * V_26 -> V_34 / 8 ;
F_18 ( V_26 , line , & V_56 [ V_57 ] , 0 , & V_30 [ V_57 ] ,
V_32 ) ;
}
}
}
static void F_21 ( struct V_1 * V_26 , T_1 V_29 ,
enum V_31 V_32 )
{
T_4 V_58 = F_22 () ;
T_4 V_59 = V_58 + ( V_26 -> V_60 * 1000 * 1000 ) ;
do {
F_19 ( V_26 , V_29 , V_32 ) ;
} while ( F_22 () < V_59 );
}
static void F_23 ( struct V_1 * V_26 , const T_1 * V_56 ,
const T_1 * V_30 , enum V_31 V_32 )
{
T_4 V_58 = F_22 () ;
T_4 V_59 = V_58 + ( V_26 -> V_60 * 1000 * 1000 ) ;
do {
F_20 ( V_26 , V_56 , V_30 , V_32 ) ;
} while ( F_22 () < V_59 );
}
static void F_24 ( struct V_1 * V_26 )
{
int V_16 , V_61 = 0 ;
unsigned int V_62 ;
if ( ! V_26 -> V_63 )
return;
V_16 = F_25 ( V_26 -> V_63 , & V_61 ) ;
if ( V_16 ) {
F_26 ( & V_26 -> V_6 -> V_64 , L_1 ,
V_16 ) ;
return;
}
V_61 /= 1000 ;
if ( V_61 <= - 10 )
V_62 = 170 ;
else if ( V_61 <= - 5 )
V_62 = 120 ;
else if ( V_61 <= 5 )
V_62 = 80 ;
else if ( V_61 <= 10 )
V_62 = 40 ;
else if ( V_61 <= 15 )
V_62 = 30 ;
else if ( V_61 <= 20 )
V_62 = 20 ;
else if ( V_61 <= 40 )
V_62 = 10 ;
else
V_62 = 7 ;
V_26 -> V_60 = V_26 -> V_65 * V_62 / 10 ;
}
static void F_27 ( T_1 * V_23 , T_5 V_34 , T_5 V_55 )
{
T_1 * V_66 = V_23 , * V_67 = V_23 ;
int V_68 , V_69 , V_70 ;
for ( V_68 = 0 ; V_68 < V_55 ; V_68 ++ )
for ( V_69 = 0 ; V_69 < V_34 / 8 ; V_69 ++ ) {
T_1 V_71 = 0x00 ;
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ ) {
int V_72 = V_69 * 8 + V_70 ;
V_71 >>= 1 ;
if ( V_66 [ V_68 * V_34 + V_72 ] >> 7 )
V_71 |= F_28 ( 7 ) ;
}
* V_67 ++ = V_71 ;
}
}
static int F_29 ( struct V_73 * V_74 ,
struct V_75 * V_76 ,
unsigned int V_77 , unsigned int V_78 ,
struct V_79 * V_80 ,
unsigned int V_81 )
{
struct V_82 * V_83 = F_30 ( V_74 , 0 ) ;
struct V_84 * V_85 = V_83 -> V_86 . V_85 ;
struct V_2 * V_3 = V_74 -> V_64 -> V_87 ;
struct V_1 * V_26 = F_1 ( V_3 ) ;
struct V_79 V_88 ;
T_1 * V_23 = NULL ;
int V_16 = 0 ;
V_88 . V_89 = 0 ;
V_88 . V_90 = V_74 -> V_34 ;
V_88 . y1 = 0 ;
V_88 . V_91 = V_74 -> V_55 ;
F_31 ( & V_3 -> V_92 ) ;
if ( ! V_26 -> V_93 )
goto V_94;
if ( V_3 -> V_95 . V_96 . V_74 != V_74 )
goto V_94;
F_24 ( V_26 ) ;
F_32 ( L_2 , V_74 -> V_86 . V_25 ,
V_26 -> V_60 ) ;
V_23 = F_4 ( V_74 -> V_34 * V_74 -> V_55 , V_17 ) ;
if ( ! V_23 ) {
V_16 = - V_18 ;
goto V_94;
}
if ( V_85 ) {
V_16 = F_33 ( V_85 -> V_97 ,
V_98 ) ;
if ( V_16 )
goto V_94;
}
F_34 ( V_23 , V_83 -> V_99 , V_74 , & V_88 ) ;
if ( V_85 ) {
V_16 = F_35 ( V_85 -> V_97 ,
V_98 ) ;
if ( V_16 )
goto V_94;
}
F_27 ( V_23 , V_74 -> V_34 , V_74 -> V_55 ) ;
if ( V_26 -> V_100 ) {
F_23 ( V_26 , V_23 , V_26 -> V_101 ,
V_44 ) ;
} else if ( V_26 -> V_102 ) {
F_23 ( V_26 , V_26 -> V_101 , NULL ,
V_41 ) ;
F_23 ( V_26 , V_26 -> V_101 , NULL ,
V_42 ) ;
F_23 ( V_26 , V_23 , NULL , V_43 ) ;
F_23 ( V_26 , V_23 , NULL , V_44 ) ;
V_26 -> V_100 = true ;
} else {
F_21 ( V_26 , 0xff , V_41 ) ;
F_21 ( V_26 , 0xff , V_42 ) ;
F_21 ( V_26 , 0xaa , V_43 ) ;
F_21 ( V_26 , 0xaa , V_44 ) ;
F_21 ( V_26 , 0xaa , V_41 ) ;
F_21 ( V_26 , 0xaa , V_42 ) ;
F_23 ( V_26 , V_23 , NULL , V_43 ) ;
F_23 ( V_26 , V_23 , NULL , V_44 ) ;
V_26 -> V_102 = true ;
V_26 -> V_100 = true ;
}
memcpy ( V_26 -> V_101 , V_23 , V_74 -> V_34 * V_74 -> V_55 / 8 ) ;
if ( V_26 -> V_48 ) {
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < ( V_74 -> V_34 / 8 ) ; V_72 ++ )
if ( V_23 [ V_72 + ( V_74 -> V_34 * ( V_74 -> V_55 - 1 ) / 8 ) ] ) {
F_23 ( V_26 , V_23 ,
V_26 -> V_101 ,
V_44 ) ;
break;
}
}
V_94:
F_36 ( & V_3 -> V_92 ) ;
if ( V_16 )
F_26 ( V_74 -> V_64 -> V_64 , L_3 , V_16 ) ;
F_7 ( V_23 ) ;
return V_16 ;
}
static void F_37 ( struct V_1 * V_26 )
{
F_38 ( V_26 -> V_103 , 0 ) ;
F_38 ( V_26 -> V_104 , 0 ) ;
if ( V_26 -> V_105 )
F_38 ( V_26 -> V_105 , 0 ) ;
F_12 ( V_26 -> V_6 ) ;
F_38 ( V_26 -> V_106 , 1 ) ;
F_39 ( 150 ) ;
F_38 ( V_26 -> V_106 , 0 ) ;
}
static void F_40 ( struct V_107 * V_95 ,
struct V_108 * V_109 )
{
struct V_2 * V_3 = F_41 ( V_95 ) ;
struct V_1 * V_26 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_26 -> V_6 ;
struct V_110 * V_64 = & V_6 -> V_64 ;
bool V_111 = false ;
int V_70 , V_16 ;
F_42 ( L_4 ) ;
F_38 ( V_26 -> V_103 , 0 ) ;
F_38 ( V_26 -> V_104 , 0 ) ;
F_38 ( V_26 -> V_106 , 0 ) ;
if ( V_26 -> V_105 )
F_38 ( V_26 -> V_105 , 0 ) ;
F_12 ( V_6 ) ;
F_43 ( 5000 , 10000 ) ;
F_38 ( V_26 -> V_104 , 1 ) ;
F_43 ( 10000 , 15000 ) ;
F_38 ( V_26 -> V_103 , 1 ) ;
if ( V_26 -> V_105 )
F_38 ( V_26 -> V_105 , 1 ) ;
F_43 ( 5000 , 10000 ) ;
F_38 ( V_26 -> V_103 , 0 ) ;
F_43 ( 5000 , 10000 ) ;
F_38 ( V_26 -> V_103 , 1 ) ;
F_43 ( 5000 , 10000 ) ;
for ( V_70 = 100 ; V_70 > 0 ; V_70 -- ) {
if ( ! F_44 ( V_26 -> V_112 ) )
break;
F_43 ( 10 , 100 ) ;
}
if ( ! V_70 ) {
F_26 ( V_64 , L_5 ) ;
F_37 ( V_26 ) ;
return;
}
F_11 ( V_6 ) ;
V_16 = F_11 ( V_6 ) ;
if ( V_16 != V_113 ) {
if ( V_16 < 0 )
F_26 ( V_64 , L_6 , V_16 ) ;
else
F_26 ( V_64 , L_7 , V_16 ) ;
F_37 ( V_26 ) ;
return;
}
F_9 ( V_6 , 0x02 , 0x40 ) ;
V_16 = F_10 ( V_6 , 0x0f ) ;
if ( V_16 < 0 || ! ( V_16 & 0x80 ) ) {
if ( V_16 < 0 )
F_26 ( V_64 , L_6 , V_16 ) ;
else
F_26 ( V_64 , L_8 ) ;
F_37 ( V_26 ) ;
return;
}
F_9 ( V_6 , 0x0b , 0x02 ) ;
F_8 ( V_6 , 0x01 , V_26 -> V_114 , 8 ) ;
F_9 ( V_6 , 0x07 , 0xd1 ) ;
F_9 ( V_6 , 0x08 , 0x02 ) ;
F_9 ( V_6 , 0x09 , 0xc2 ) ;
F_9 ( V_6 , 0x04 , 0x03 ) ;
F_9 ( V_6 , 0x03 , 0x01 ) ;
F_9 ( V_6 , 0x03 , 0x00 ) ;
F_43 ( 5000 , 10000 ) ;
for ( V_70 = 0 ; V_70 < 4 ; ++ V_70 ) {
F_9 ( V_6 , 0x05 , 0x01 ) ;
F_39 ( 240 ) ;
F_9 ( V_6 , 0x05 , 0x03 ) ;
F_39 ( 40 ) ;
F_9 ( V_6 , 0x05 , 0x0f ) ;
F_39 ( 40 ) ;
V_16 = F_10 ( V_6 , 0x0f ) ;
if ( V_16 < 0 ) {
F_26 ( V_64 , L_6 , V_16 ) ;
F_37 ( V_26 ) ;
return;
}
if ( V_16 & 0x40 ) {
V_111 = true ;
break;
}
}
if ( ! V_111 ) {
F_26 ( V_64 , L_9 ) ;
F_37 ( V_26 ) ;
return;
}
F_9 ( V_6 , 0x02 , 0x04 ) ;
V_26 -> V_93 = true ;
V_26 -> V_100 = false ;
}
static void F_45 ( struct V_107 * V_95 )
{
struct V_2 * V_3 = F_41 ( V_95 ) ;
struct V_1 * V_26 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_26 -> V_6 ;
unsigned int line ;
F_42 ( L_4 ) ;
F_31 ( & V_3 -> V_92 ) ;
V_26 -> V_93 = false ;
F_36 ( & V_3 -> V_92 ) ;
for ( line = 0 ; line < V_26 -> V_55 ; line ++ )
F_18 ( V_26 , 0x7fffu , NULL , 0x00 , NULL ,
V_41 ) ;
if ( V_26 -> V_105 ) {
F_18 ( V_26 , 0x7fffu , NULL , 0x00 , NULL ,
V_41 ) ;
F_39 ( 25 ) ;
F_38 ( V_26 -> V_105 , 0 ) ;
F_39 ( 200 ) ;
F_38 ( V_26 -> V_105 , 1 ) ;
} else {
F_18 ( V_26 , 0x7fffu , NULL , 0x00 , NULL ,
V_44 ) ;
F_39 ( 200 ) ;
}
F_9 ( V_6 , 0x0b , 0x00 ) ;
F_9 ( V_6 , 0x03 , 0x01 ) ;
F_9 ( V_6 , 0x05 , 0x03 ) ;
F_9 ( V_6 , 0x05 , 0x01 ) ;
F_39 ( 120 ) ;
F_9 ( V_6 , 0x04 , 0x80 ) ;
F_9 ( V_6 , 0x05 , 0x00 ) ;
F_9 ( V_6 , 0x07 , 0x01 ) ;
F_39 ( 50 ) ;
F_37 ( V_26 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
const struct V_115 * V_116 ;
const struct V_117 * V_118 ;
const struct V_119 * V_120 ;
struct V_110 * V_64 = & V_6 -> V_64 ;
struct V_2 * V_3 ;
enum V_121 V_122 ;
const char * V_123 ;
struct V_1 * V_26 ;
T_2 V_124 ;
int V_16 ;
V_120 = F_47 ( V_125 , V_64 ) ;
if ( V_120 ) {
V_122 = (enum V_121 ) V_120 -> V_28 ;
} else {
V_118 = F_48 ( V_6 ) ;
V_122 = V_118 -> V_126 ;
}
if ( ! V_64 -> V_127 ) {
V_16 = F_49 ( V_64 , F_50 ( 32 ) ) ;
if ( V_16 ) {
F_51 ( V_64 , L_10 , V_16 ) ;
return V_16 ;
}
}
V_26 = F_52 ( V_64 , sizeof( * V_26 ) , V_17 ) ;
if ( ! V_26 )
return - V_18 ;
V_26 -> V_6 = V_6 ;
V_26 -> V_104 = F_53 ( V_64 , L_11 , V_128 ) ;
if ( F_54 ( V_26 -> V_104 ) ) {
V_16 = F_55 ( V_26 -> V_104 ) ;
if ( V_16 != - V_129 )
F_26 ( V_64 , L_12 ) ;
return V_16 ;
}
V_26 -> V_106 = F_53 ( V_64 , L_13 , V_128 ) ;
if ( F_54 ( V_26 -> V_106 ) ) {
V_16 = F_55 ( V_26 -> V_106 ) ;
if ( V_16 != - V_129 )
F_26 ( V_64 , L_14 ) ;
return V_16 ;
}
V_26 -> V_103 = F_53 ( V_64 , L_15 , V_128 ) ;
if ( F_54 ( V_26 -> V_103 ) ) {
V_16 = F_55 ( V_26 -> V_103 ) ;
if ( V_16 != - V_129 )
F_26 ( V_64 , L_16 ) ;
return V_16 ;
}
V_26 -> V_112 = F_53 ( V_64 , L_17 , V_130 ) ;
if ( F_54 ( V_26 -> V_112 ) ) {
V_16 = F_55 ( V_26 -> V_112 ) ;
if ( V_16 != - V_129 )
F_26 ( V_64 , L_18 ) ;
return V_16 ;
}
if ( ! F_56 ( V_64 , L_19 ,
& V_123 ) ) {
V_26 -> V_63 = F_57 ( V_123 ) ;
if ( F_54 ( V_26 -> V_63 ) ) {
F_26 ( V_64 , L_20 ,
V_123 ) ;
return F_55 ( V_26 -> V_63 ) ;
}
}
switch ( V_122 ) {
case V_131 :
V_116 = & V_132 ;
V_26 -> V_114 = V_133 ;
V_26 -> V_65 = 480 ;
V_26 -> V_50 = 96 / 4 ;
V_26 -> V_49 = true ;
V_26 -> V_48 = false ;
V_26 -> V_51 = V_53 ;
break;
case V_134 :
V_116 = & V_135 ;
V_26 -> V_114 = V_136 ;
V_26 -> V_65 = 480 ;
V_26 -> V_50 = 128 / 4 / 2 ;
V_26 -> V_49 = false ;
V_26 -> V_48 = false ;
V_26 -> V_51 = V_54 ;
break;
case V_137 :
V_116 = & V_138 ;
V_26 -> V_114 = V_139 ;
V_26 -> V_65 = 480 ;
V_26 -> V_50 = 96 / 4 ;
V_26 -> V_49 = true ;
V_26 -> V_48 = true ;
V_26 -> V_51 = V_52 ;
break;
case V_140 :
V_26 -> V_105 = F_53 ( V_64 , L_21 , V_128 ) ;
if ( F_54 ( V_26 -> V_105 ) ) {
V_16 = F_55 ( V_26 -> V_105 ) ;
if ( V_16 != - V_129 )
F_26 ( V_64 , L_22 ) ;
return V_16 ;
}
V_116 = & V_141 ;
V_26 -> V_114 = V_142 ;
V_26 -> V_65 = 630 ;
V_26 -> V_50 = 176 / 4 ;
V_26 -> V_49 = true ;
V_26 -> V_48 = true ;
V_26 -> V_51 = V_52 ;
break;
default:
return - V_143 ;
}
V_26 -> V_34 = V_116 -> V_144 ;
V_26 -> V_55 = V_116 -> V_145 ;
V_26 -> V_60 = V_26 -> V_65 ;
V_124 = 2 * V_26 -> V_34 / 8 + V_26 -> V_50 + 2 ;
V_26 -> V_47 = F_52 ( V_64 , V_124 , V_17 ) ;
if ( ! V_26 -> V_47 )
return - V_18 ;
V_26 -> V_101 = F_52 ( V_64 , V_26 -> V_34 * V_26 -> V_55 / 8 ,
V_17 ) ;
if ( ! V_26 -> V_101 )
return - V_18 ;
V_3 = & V_26 -> V_4 ;
V_16 = F_58 ( V_64 , V_3 , & V_146 , & V_147 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_59 ( V_3 , & V_148 ,
V_149 ,
V_150 ,
F_60 ( V_150 ) , V_116 , 0 ) ;
if ( V_16 )
return V_16 ;
F_61 ( V_3 -> V_151 ) ;
V_16 = F_62 ( V_3 ) ;
if ( V_16 )
return V_16 ;
F_63 ( V_6 , V_3 ) ;
F_42 ( L_23 ,
V_3 -> V_151 -> V_152 -> V_153 , F_64 ( V_64 ) ,
V_6 -> V_154 / 1000000 ,
V_3 -> V_151 -> V_155 -> V_156 ) ;
return 0 ;
}
static void F_65 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_66 ( V_6 ) ;
F_67 ( V_3 ) ;
}
