static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 0 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 1 ) ;
}
static inline void F_4 ( enum V_4 V_5 , struct V_1 * V_2 )
{
switch ( V_5 ) {
case V_6 :
F_2 ( V_2 -> V_7 , 0 ) ;
F_2 ( V_2 -> V_8 , 0 ) ;
break;
case V_9 :
F_2 ( V_2 -> V_7 , 0 ) ;
F_2 ( V_2 -> V_8 , 1 ) ;
break;
case V_10 :
F_2 ( V_2 -> V_7 , 1 ) ;
F_2 ( V_2 -> V_8 , 1 ) ;
break;
default:
F_2 ( V_2 -> V_7 , 1 ) ;
F_2 ( V_2 -> V_8 , 0 ) ;
}
V_2 -> V_5 = V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned char V_11 )
{
struct V_12 V_13 ;
int V_14 = 0 ;
V_2 -> V_15 . V_16 = 1 ;
F_4 ( V_10 , V_2 ) ;
F_6 ( & V_13 ) ;
F_7 ( & V_2 -> V_15 , & V_13 ) ;
V_2 -> V_17 [ 0 ] = V_11 ;
V_14 = F_8 ( V_2 -> V_18 , & V_13 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_19 = 1 ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_20 ,
unsigned char * V_11 )
{
struct V_12 V_13 ;
int V_14 = 0 ;
V_2 -> V_15 . V_16 = 2 ;
F_4 ( V_10 , V_2 ) ;
F_6 ( & V_13 ) ;
F_7 ( & V_2 -> V_15 , & V_13 ) ;
V_2 -> V_17 [ 0 ] = V_20 | V_21 ;
V_2 -> V_17 [ 1 ] = V_22 ;
V_14 = F_8 ( V_2 -> V_18 , & V_13 ) ;
if ( V_14 )
return V_14 ;
* V_11 = V_2 -> V_23 [ 1 ] ;
V_2 -> V_19 = 1 ;
return V_14 ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
unsigned char V_24 ;
V_24 = ( unsigned char ) ( V_2 -> V_25 * ( 1 << 15 ) / V_2 -> V_26 ) ;
if ( V_24 >= V_27 && V_24 <= V_28 ) {
F_5 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_24 ) ;
} else
F_11 ( L_1 ) ;
}
static inline unsigned char F_12 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
V_11 = ( F_13 ( V_2 -> V_30 ) << 1 ) |
F_13 ( V_2 -> V_31 ) ;
return V_32 [ V_11 ] ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_33 ) {
case V_34 :
F_2 ( V_2 -> V_30 , 0 ) ;
F_2 ( V_2 -> V_31 , 0 ) ;
break;
case V_35 :
F_2 ( V_2 -> V_30 , 0 ) ;
F_2 ( V_2 -> V_31 , 1 ) ;
break;
case V_36 :
F_2 ( V_2 -> V_30 , 1 ) ;
F_2 ( V_2 -> V_31 , 0 ) ;
break;
case V_37 :
F_2 ( V_2 -> V_30 , 1 ) ;
F_2 ( V_2 -> V_31 , 1 ) ;
break;
}
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_38 ) ;
F_5 ( V_2 , 0x0 ) ;
}
static T_1 F_16 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
int V_14 ;
F_18 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_19 ) {
V_14 = sprintf ( V_43 , L_2 , V_2 -> V_23 [ 0 ] ) ;
V_2 -> V_19 = 0 ;
} else
V_14 = 0 ;
F_19 ( & V_2 -> V_47 ) ;
return V_14 ;
}
static T_1 F_20 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned long V_48 ;
unsigned char V_11 ;
int V_14 ;
V_14 = F_21 ( V_43 , 16 , & V_48 ) ;
if ( V_14 )
return - V_49 ;
V_11 = V_48 & 0xff ;
F_18 ( & V_2 -> V_47 ) ;
F_5 ( V_2 , V_11 ) ;
F_19 ( & V_2 -> V_47 ) ;
return 1 ;
}
static T_1 F_22 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
F_18 ( & V_2 -> V_47 ) ;
F_15 ( V_2 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_16 ;
}
static T_1 F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
return sprintf ( V_43 , L_3 , V_2 -> V_26 ) ;
}
static T_1 F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned long V_26 ;
int V_14 ;
V_14 = F_21 ( V_43 , 10 , & V_26 ) ;
if ( ! V_14 && V_26 >= V_50 &&
V_26 <= V_51 ) {
F_18 ( & V_2 -> V_47 ) ;
V_2 -> V_26 = V_26 ;
} else {
F_11 ( L_4 ) ;
return - V_49 ;
}
F_10 ( V_2 ) ;
F_15 ( V_2 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_16 ;
}
static T_1 F_25 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
return sprintf ( V_43 , L_3 , V_2 -> V_25 ) ;
}
static T_1 F_26 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned long V_25 ;
int V_14 ;
V_14 = F_21 ( V_43 , 10 , & V_25 ) ;
if ( ! V_14 && V_25 >= V_52 &&
V_25 <= V_53 ) {
F_18 ( & V_2 -> V_47 ) ;
V_2 -> V_25 = V_25 ;
} else {
F_11 ( L_5 ) ;
return - V_49 ;
}
F_10 ( V_2 ) ;
F_15 ( V_2 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_16 ;
}
static T_1 F_27 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned char V_11 ;
F_18 ( & V_2 -> V_47 ) ;
F_9 ( V_2 , V_54 , & V_11 ) ;
F_19 ( & V_2 -> V_47 ) ;
return sprintf ( V_43 , L_2 , V_11 ) ;
}
static T_1 F_28 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned long V_48 ;
unsigned char V_11 ;
int V_14 ;
V_14 = F_21 ( V_43 , 16 , & V_48 ) ;
if ( V_14 ) {
V_14 = - V_49 ;
goto V_55;
}
F_18 ( & V_2 -> V_47 ) ;
F_5 ( V_2 , V_54 ) ;
V_11 = V_48 & V_56 ;
F_5 ( V_2 , V_11 ) ;
F_9 ( V_2 , V_54 , & V_11 ) ;
if ( V_11 & V_21 ) {
V_14 = - V_57 ;
F_11 ( L_6 ) ;
goto V_55;
}
V_2 -> V_33 = V_32 [ V_11 & V_58 ] ;
#if F_29 ( V_59 )
V_11 = F_12 ( V_2 ) ;
if ( V_11 != V_2 -> V_33 )
F_30 ( L_7 ) ;
#elif F_29 ( V_60 )
F_14 ( V_2 ) ;
#endif
V_14 = V_16 ;
if ( V_11 & V_61 )
V_2 -> V_62 = 1 ;
else
V_2 -> V_62 = 0 ;
V_55:
F_19 ( & V_2 -> V_47 ) ;
return V_14 ;
}
static T_1 F_31 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
return sprintf ( V_43 , L_3 , V_2 -> V_33 ) ;
}
static T_1 F_32 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned char V_11 ;
unsigned long V_48 ;
int V_14 ;
V_14 = F_21 ( V_43 , 10 , & V_48 ) ;
if ( V_14 || V_48 < V_34 || V_48 > V_37 ) {
F_11 ( L_8 ) ;
return - V_49 ;
}
F_18 ( & V_2 -> V_47 ) ;
F_9 ( V_2 , V_54 , & V_11 ) ;
V_11 &= ~ V_58 ;
V_11 |= ( V_48 - V_34 ) >> 1 ;
F_5 ( V_2 , V_54 ) ;
F_5 ( V_2 , V_11 & V_56 ) ;
F_9 ( V_2 , V_54 , & V_11 ) ;
if ( V_11 & V_21 ) {
V_14 = - V_57 ;
F_11 ( L_9 ) ;
goto V_55;
}
V_2 -> V_33 = V_32 [ V_11 & V_58 ] ;
#if F_29 ( V_59 )
V_11 = F_12 ( V_2 ) ;
if ( V_11 != V_2 -> V_33 )
F_30 ( L_7 ) ;
#elif F_29 ( V_60 )
F_14 ( V_2 ) ;
#endif
V_14 = V_16 ;
V_55:
F_19 ( & V_2 -> V_47 ) ;
return V_14 ;
}
static T_1 F_33 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
int V_14 = 0 ;
T_1 V_16 = 0 ;
unsigned char V_11 ;
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
F_18 ( & V_2 -> V_47 ) ;
V_14 = F_9 ( V_2 , V_22 , & V_11 ) ;
if ( V_14 )
goto V_55;
V_16 = sprintf ( V_43 , L_2 , V_11 ) ;
V_55:
F_19 ( & V_2 -> V_47 ) ;
return V_14 ? V_14 : V_16 ;
}
static T_1 F_34 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned char V_11 ;
F_18 ( & V_2 -> V_47 ) ;
F_1 ( V_2 ) ;
F_35 ( 1 ) ;
F_3 ( V_2 ) ;
F_9 ( V_2 , V_22 , & V_11 ) ;
F_1 ( V_2 ) ;
F_3 ( V_2 ) ;
F_19 ( & V_2 -> V_47 ) ;
return 0 ;
}
static T_1 F_36 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned char V_11 ;
struct V_63 * V_64 = F_37 ( V_42 ) ;
F_18 ( & V_2 -> V_47 ) ;
F_9 ( V_2 , V_64 -> V_20 , & V_11 ) ;
F_19 ( & V_2 -> V_47 ) ;
return sprintf ( V_43 , L_3 , V_11 ) ;
}
static T_1 F_38 ( struct V_39 * V_40 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_16 )
{
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
unsigned long V_11 ;
int V_14 ;
struct V_63 * V_64 = F_37 ( V_42 ) ;
V_14 = F_21 ( V_43 , 10 , & V_11 ) ;
if ( V_14 )
return - V_49 ;
F_18 ( & V_2 -> V_47 ) ;
F_5 ( V_2 , V_64 -> V_20 ) ;
F_5 ( V_2 , V_11 & V_56 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_16 ;
}
static T_1 F_39 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_12 V_13 ;
int V_14 = 0 ;
T_1 V_16 = 0 ;
T_3 V_65 ;
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
V_2 -> V_15 . V_16 = 2 ;
F_18 ( & V_2 -> V_47 ) ;
F_1 ( V_2 ) ;
F_35 ( 1 ) ;
F_4 ( V_6 , V_2 ) ;
F_6 ( & V_13 ) ;
F_7 ( & V_2 -> V_15 , & V_13 ) ;
V_14 = F_8 ( V_2 -> V_18 , & V_13 ) ;
if ( V_14 )
goto V_55;
V_65 = ( ( ( ( T_3 ) ( V_2 -> V_23 [ 0 ] ) ) << 8 ) | ( V_2 -> V_23 [ 1 ] ) ) ;
if ( V_2 -> V_62 )
V_65 >>= 16 - V_2 -> V_33 ;
V_16 = sprintf ( V_43 , L_3 , V_65 ) ;
V_55:
F_3 ( V_2 ) ;
F_35 ( 1 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_14 ? V_14 : V_16 ;
}
static T_1 F_40 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_12 V_13 ;
unsigned short V_66 ;
int V_14 = 0 ;
T_1 V_16 = 0 ;
T_4 V_67 ;
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
V_2 -> V_15 . V_16 = 2 ;
F_18 ( & V_2 -> V_47 ) ;
F_1 ( V_2 ) ;
F_35 ( 1 ) ;
F_4 ( V_9 , V_2 ) ;
F_6 ( & V_13 ) ;
F_7 ( & V_2 -> V_15 , & V_13 ) ;
V_14 = F_8 ( V_2 -> V_18 , & V_13 ) ;
if ( V_14 )
goto V_55;
V_66 = V_2 -> V_23 [ 0 ] & 0x80 ;
V_67 = ( ( ( ( T_4 ) ( V_2 -> V_23 [ 0 ] ) ) << 8 ) | ( V_2 -> V_23 [ 1 ] ) ) ;
V_67 >>= 16 - V_2 -> V_33 ;
if ( V_66 ) {
V_66 = ( 0xffff >> V_2 -> V_33 ) << V_2 -> V_33 ;
V_67 |= V_66 ;
}
V_16 = sprintf ( V_43 , L_3 , V_67 ) ;
V_55:
F_3 ( V_2 ) ;
F_35 ( 1 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_14 ? V_14 : V_16 ;
}
static T_1 F_41 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_12 V_13 ;
unsigned short V_66 ;
int V_14 = 0 ;
T_1 V_16 = 0 ;
T_3 V_65 ;
T_4 V_67 ;
struct V_44 * V_45 = F_17 ( V_40 ) ;
struct V_1 * V_2 = V_45 -> V_46 ;
V_2 -> V_15 . V_16 = 2 ;
F_18 ( & V_2 -> V_47 ) ;
F_1 ( V_2 ) ;
F_35 ( 1 ) ;
F_4 ( V_6 , V_2 ) ;
F_6 ( & V_13 ) ;
F_7 ( & V_2 -> V_15 , & V_13 ) ;
V_14 = F_8 ( V_2 -> V_18 , & V_13 ) ;
if ( V_14 )
goto V_55;
V_65 = ( ( ( ( T_3 ) ( V_2 -> V_23 [ 0 ] ) ) << 8 ) | ( V_2 -> V_23 [ 1 ] ) ) ;
if ( V_2 -> V_62 )
V_65 >>= 16 - V_2 -> V_33 ;
V_16 = sprintf ( V_43 , L_10 , V_65 ) ;
V_2 -> V_15 . V_16 = 2 ;
F_4 ( V_9 , V_2 ) ;
F_6 ( & V_13 ) ;
F_7 ( & V_2 -> V_15 , & V_13 ) ;
V_14 = F_8 ( V_2 -> V_18 , & V_13 ) ;
if ( V_14 )
goto V_55;
V_66 = V_2 -> V_23 [ 0 ] & 0x80 ;
V_67 = ( ( ( ( T_4 ) ( V_2 -> V_23 [ 0 ] ) ) << 8 ) | ( V_2 -> V_23 [ 1 ] ) ) ;
V_67 >>= 16 - V_2 -> V_33 ;
if ( V_66 ) {
V_66 = ( 0xffff >> V_2 -> V_33 ) << V_2 -> V_33 ;
V_67 |= V_66 ;
}
V_16 += sprintf ( V_43 + V_16 , L_3 , V_67 ) ;
V_55:
F_3 ( V_2 ) ;
F_35 ( 1 ) ;
F_19 ( & V_2 -> V_47 ) ;
return V_14 ? V_14 : V_16 ;
}
static int T_5 F_42 ( struct V_1 * V_2 )
{
unsigned char V_11 ;
int V_14 ;
F_18 ( & V_2 -> V_47 ) ;
#if F_29 ( V_59 )
V_2 -> V_33 = F_12 ( V_2 ) ;
#elif F_29 ( V_60 )
F_14 ( V_2 ) ;
#endif
F_5 ( V_2 , V_54 ) ;
V_11 = V_68 & ~ ( V_58 ) ;
V_11 |= ( V_2 -> V_33 - V_34 ) >> 1 ;
F_5 ( V_2 , V_11 ) ;
V_14 = F_9 ( V_2 , V_54 , & V_11 ) ;
if ( V_14 )
goto V_55;
if ( V_11 & V_21 ) {
V_14 = - V_57 ;
goto V_55;
}
F_10 ( V_2 ) ;
F_15 ( V_2 ) ;
V_55:
F_19 ( & V_2 -> V_47 ) ;
return V_14 ;
}
static int T_5 F_43 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
int V_71 , V_14 = 0 ;
unsigned short * V_72 = V_70 -> V_40 . V_73 ;
for ( V_71 = 0 ; V_71 < V_74 ; V_71 ++ ) {
if ( F_44 ( V_72 [ V_71 ] , V_75 ) ) {
F_11 ( L_11 ,
V_75 , V_72 [ V_71 ] ) ;
goto V_55;
}
if ( V_71 < V_76 )
F_45 ( V_72 [ V_71 ] , 1 ) ;
else {
#if F_29 ( V_59 )
F_46 ( V_72 [ V_71 ] ) ;
#elif F_29 ( V_60 )
F_45 ( V_72 [ V_71 ] , 1 ) ;
#endif
}
}
V_2 = F_47 ( sizeof( * V_2 ) , V_77 ) ;
if ( V_2 == NULL ) {
V_14 = - V_78 ;
goto V_55;
}
F_48 ( V_70 , V_2 ) ;
F_49 ( & V_2 -> V_47 ) ;
V_2 -> V_18 = V_70 ;
V_2 -> V_15 . V_79 = V_2 -> V_17 ;
V_2 -> V_15 . V_80 = V_2 -> V_23 ;
V_2 -> V_62 = 1 ;
V_2 -> V_5 = V_10 ;
V_2 -> V_33 = V_35 ;
V_2 -> V_26 = V_81 ;
V_2 -> V_25 = V_82 ;
V_2 -> V_3 = V_72 [ 0 ] ;
V_2 -> V_7 = V_72 [ 1 ] ;
V_2 -> V_8 = V_72 [ 2 ] ;
V_2 -> V_30 = V_72 [ 3 ] ;
V_2 -> V_31 = V_72 [ 4 ] ;
V_2 -> V_45 = F_50 ( 0 ) ;
if ( V_2 -> V_45 == NULL ) {
V_14 = - V_78 ;
goto V_83;
}
V_2 -> V_45 -> V_40 . V_84 = & V_70 -> V_40 ;
V_2 -> V_45 -> V_85 = & V_86 ;
V_2 -> V_45 -> V_46 = ( void * ) ( V_2 ) ;
V_2 -> V_45 -> V_87 = V_88 ;
V_14 = F_51 ( V_2 -> V_45 ) ;
if ( V_14 )
goto V_89;
if ( V_70 -> V_90 != V_81 )
V_2 -> V_26 = V_70 -> V_90 ;
V_70 -> V_5 = V_91 ;
F_52 ( V_70 ) ;
F_42 ( V_2 ) ;
return 0 ;
V_89:
F_53 ( V_2 -> V_45 ) ;
V_83:
F_54 ( V_2 ) ;
V_55:
for ( -- V_71 ; V_71 >= 0 ; V_71 -- )
F_55 ( V_72 [ V_71 ] ) ;
return V_14 ;
}
static int T_6 F_56 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_57 ( V_70 ) ;
F_58 ( V_2 -> V_45 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static T_7 int F_59 ( void )
{
return F_60 ( & V_92 ) ;
}
static T_8 void F_61 ( void )
{
F_62 ( & V_92 ) ;
}
