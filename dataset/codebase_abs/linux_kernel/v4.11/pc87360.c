static inline void F_1 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline int F_3 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_4 ( V_1 + 1 ) ;
}
static inline void F_5 ( int V_1 )
{
F_2 ( 0x02 , V_1 ) ;
F_2 ( 0x02 , V_1 + 1 ) ;
}
static inline T_1 F_6 ( int V_3 , int V_4 )
{
if ( V_4 )
V_3 = 255 - V_3 ;
if ( V_3 < 0 )
return 0 ;
if ( V_3 > 255 )
return 255 ;
return V_3 ;
}
static T_2 F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_10 ( V_13 -> V_14 [ V_11 -> V_15 ] ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ) ;
}
static T_2 F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_10 ( V_13 -> V_17 [ V_11 -> V_15 ] ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ) ;
}
static T_2 F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 ,
F_15 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_17 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_17 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_17 = F_20 ( V_17 ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ;
while ( V_17 > 255
&& ( V_13 -> V_16 [ V_11 -> V_15 ] & 0x60 ) != 0x60 ) {
V_17 >>= 1 ;
V_13 -> V_14 [ V_11 -> V_15 ] >>= 1 ;
V_13 -> V_16 [ V_11 -> V_15 ] += 0x20 ;
}
V_13 -> V_17 [ V_11 -> V_15 ] = V_17 > 255 ? 255 : V_17 ;
F_21 ( V_13 , V_21 , V_22 ,
F_22 ( V_11 -> V_15 ) ,
V_13 -> V_17 [ V_11 -> V_15 ] ) ;
F_21 ( V_13 , V_21 , V_22 ,
F_23 ( V_11 -> V_15 ) ,
V_13 -> V_16 [ V_11 -> V_15 ] & 0xF9 ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_25 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 ,
F_26 ( V_13 -> V_23 [ V_11 -> V_15 ] ,
F_27 ( V_13 -> V_24 ,
V_11 -> V_15 ) ) ) ;
}
static T_2 F_28 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_23 [ V_11 -> V_15 ] = F_6 ( V_3 ,
F_27 ( V_13 -> V_24 , V_11 -> V_15 ) ) ;
F_21 ( V_13 , V_21 , V_22 , F_29 ( V_11 -> V_15 ) ,
V_13 -> V_23 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_30 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_25 [ V_11 -> V_15 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_32 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_27 [ V_11 -> V_15 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_33 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_28 [ V_11 -> V_15 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_34 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_29 [ V_11 -> V_15 ] ) ;
}
static T_2 F_35 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_27 [ V_11 -> V_15 ] = F_36 ( V_3 , V_13 -> V_26 ) ;
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_31 ,
V_13 -> V_27 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_37 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_28 [ V_11 -> V_15 ] = F_36 ( V_3 ,
V_13 -> V_26 ) ;
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_32 ,
V_13 -> V_28 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_38 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_29 [ V_33 ] & V_34 ) ) ;
}
static T_2 F_39 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_29 [ V_33 ] & V_35 ) ) ;
}
static T_2 F_40 ( struct V_5 * V_6 ,
struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_41 ( V_13 -> V_36 , V_13 -> V_37 ) ) ;
}
static T_2 F_42 ( struct V_5 * V_6 , struct V_7 * V_11 ,
char * V_9 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_37 ) ;
}
static T_2 F_43 ( struct V_5 * V_6 , struct V_7 * V_11 ,
const char * V_9 , T_3 V_18 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
unsigned long V_3 ;
int V_19 ;
V_19 = F_44 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
if ( V_3 > 255 )
return - V_38 ;
V_13 -> V_37 = V_3 ;
return V_18 ;
}
static T_2 F_45 ( struct V_5 * V_6 ,
struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_39 ) ;
}
static T_2 F_46 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_25 [ V_11 -> V_15 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_47 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_27 [ V_11 -> V_15 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_48 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_28 [ V_11 -> V_15 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_49 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_40 [ V_11 -> V_15 - 11 ] ,
V_13 -> V_26 ) ) ;
}
static T_2 F_50 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_29 [ V_11 -> V_15 ] ) ;
}
static T_2 F_51 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_27 [ V_11 -> V_15 ] = F_36 ( V_3 , V_13 -> V_26 ) ;
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_41 ,
V_13 -> V_27 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_52 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_28 [ V_11 -> V_15 ] = F_36 ( V_3 , V_13 -> V_26 ) ;
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_42 ,
V_13 -> V_28 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_53 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_40 [ V_11 -> V_15 - 11 ] = F_36 ( V_3 , V_13 -> V_26 ) ;
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_43 ,
V_13 -> V_40 [ V_11 -> V_15 - 11 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_54 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_29 [ V_33 ] & V_34 ) ) ;
}
static T_2 F_55 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_29 [ V_33 ] & V_35 ) ) ;
}
static T_2 F_56 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_29 [ V_33 ] & V_44 ) ) ;
}
static T_2 F_57 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_45 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_59 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_46 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_60 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_47 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_61 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 ,
F_58 ( V_13 -> V_48 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_62 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , V_13 -> V_49 [ V_11 -> V_15 ] ) ;
}
static T_2 F_63 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_46 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_50 , V_11 -> V_15 , V_41 ,
V_13 -> V_46 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_65 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_47 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_50 , V_11 -> V_15 , V_42 ,
V_13 -> V_47 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_66 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 ;
int V_19 ;
V_19 = F_18 ( V_9 , 10 , & V_3 ) ;
if ( V_19 )
return V_19 ;
F_19 ( & V_13 -> V_20 ) ;
V_13 -> V_48 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_50 , V_11 -> V_15 , V_43 ,
V_13 -> V_48 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_67 ( struct V_5 * V_6 ,
struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_51 ) ;
}
static T_2 F_68 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_49 [ V_33 ] & V_34 ) ) ;
}
static T_2 F_69 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_49 [ V_33 ] & V_35 ) ) ;
}
static T_2 F_70 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_49 [ V_33 ] & V_44 ) ) ;
}
static T_2 F_71 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_49 [ V_33 ] & V_52 ) ) ;
}
static T_2 F_72 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
return sprintf ( V_9 , L_3 , V_13 -> V_53 ) ;
}
static int T_4 F_73 ( int V_1 , T_1 * V_54 ,
unsigned short * V_55 )
{
T_5 V_3 ;
int V_56 ;
int V_57 ;
V_3 = V_58 ? V_58 : F_3 ( V_1 , V_59 ) ;
switch ( V_3 ) {
case 0xE1 :
case 0xE8 :
case 0xE4 :
V_57 = 1 ;
break;
case 0xE5 :
case 0xE9 :
V_57 = 3 ;
break;
default:
F_5 ( V_1 ) ;
return - V_60 ;
}
* V_54 = V_3 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
F_1 ( V_1 , V_61 , V_62 [ V_56 ] ) ;
V_3 = F_3 ( V_1 , V_63 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_74 ( L_4 , V_62 [ V_56 ] ) ;
continue;
}
V_3 = ( F_3 ( V_1 , V_64 ) << 8 )
| F_3 ( V_1 , V_64 + 1 ) ;
if ( ! V_3 ) {
F_74 ( L_5 ,
V_62 [ V_56 ] ) ;
continue;
}
V_55 [ V_56 ] = V_3 ;
if ( V_56 == 0 ) {
V_65 [ 0 ] = F_3 ( V_1 , 0xF0 ) ;
V_65 [ 1 ] = F_3 ( V_1 , 0xF1 ) ;
F_75 ( L_6 , 1 ,
( V_65 [ 0 ] >> 2 ) & 1 , ( V_65 [ 0 ] >> 3 ) & 1 ,
( V_65 [ 0 ] >> 4 ) & 1 ) ;
F_75 ( L_6 , 2 ,
( V_65 [ 0 ] >> 5 ) & 1 , ( V_65 [ 0 ] >> 6 ) & 1 ,
( V_65 [ 0 ] >> 7 ) & 1 ) ;
F_75 ( L_6 , 3 ,
V_65 [ 1 ] & 1 , ( V_65 [ 1 ] >> 1 ) & 1 ,
( V_65 [ 1 ] >> 2 ) & 1 ) ;
} else if ( V_56 == 1 ) {
if ( * V_54 == 0xE9 ) {
V_65 [ 2 ] = F_3 ( V_1 , 0x2B ) ;
V_65 [ 3 ] = F_3 ( V_1 , 0x25 ) ;
if ( V_65 [ 2 ] & 0x40 ) {
F_74 ( L_7 ) ;
}
if ( V_65 [ 3 ] & 0xE0 ) {
F_74 ( L_8 ,
V_65 [ 3 ] >> 5 ) ;
}
}
}
}
F_5 ( V_1 ) ;
return 0 ;
}
static void F_76 ( struct V_5 * V_6 )
{
int V_56 ;
F_77 ( V_6 , & V_66 ) ;
F_77 ( V_6 , & V_67 ) ;
for ( V_56 = 0 ; V_56 < F_78 ( V_68 ) ; V_56 ++ )
F_79 ( & V_6 -> V_69 , & V_68 [ V_56 ] ) ;
for ( V_56 = 0 ; V_56 < F_78 ( V_70 ) ; V_56 ++ ) {
F_79 ( & V_71 -> V_6 . V_69 , & V_70 [ V_56 ] ) ;
F_77 ( V_6 , & V_23 [ V_56 ] . V_72 ) ;
}
F_79 ( & V_6 -> V_69 , & V_73 ) ;
F_79 ( & V_6 -> V_69 , & V_74 ) ;
}
static int F_80 ( struct V_75 * V_71 )
{
int V_56 ;
struct V_12 * V_13 ;
int V_19 = 0 ;
const char * V_53 ;
int V_76 = 0 ;
struct V_5 * V_6 = & V_71 -> V_6 ;
V_13 = F_81 ( V_6 , sizeof( struct V_12 ) , V_77 ) ;
if ( ! V_13 )
return - V_78 ;
switch ( V_54 ) {
default:
V_53 = L_9 ;
V_13 -> V_79 = 2 ;
break;
case 0xe8 :
V_53 = L_10 ;
V_13 -> V_79 = 2 ;
break;
case 0xe4 :
V_53 = L_11 ;
V_13 -> V_79 = 3 ;
break;
case 0xe5 :
V_53 = L_12 ;
V_13 -> V_79 = V_80 [ 0 ] ? 3 : 0 ;
V_13 -> V_81 = V_80 [ 1 ] ? 11 : 0 ;
V_13 -> V_82 = V_80 [ 2 ] ? 2 : 0 ;
break;
case 0xe9 :
V_53 = L_13 ;
V_13 -> V_79 = V_80 [ 0 ] ? 3 : 0 ;
V_13 -> V_81 = V_80 [ 1 ] ? 14 : 0 ;
V_13 -> V_82 = V_80 [ 2 ] ? 3 : 0 ;
break;
}
V_13 -> V_53 = V_53 ;
F_82 ( & V_13 -> V_83 ) ;
F_82 ( & V_13 -> V_20 ) ;
F_83 ( V_71 , V_13 ) ;
for ( V_56 = 0 ; V_56 < V_84 ; V_56 ++ ) {
V_13 -> V_85 [ V_56 ] = V_80 [ V_56 ] ;
if ( V_13 -> V_85 [ V_56 ]
&& ! F_84 ( V_6 , V_80 [ V_56 ] , V_86 ,
V_87 . V_88 . V_53 ) ) {
F_85 ( V_6 ,
L_14 ,
V_80 [ V_56 ] , V_80 [ V_56 ] + V_86 - 1 ) ;
return - V_89 ;
}
}
if ( V_13 -> V_79 )
V_13 -> V_24 = V_65 [ 0 ] | ( V_65 [ 1 ] << 8 ) ;
if ( V_13 -> V_81 ) {
V_56 = F_86 ( V_13 , V_30 , V_22 ,
V_90 ) ;
if ( V_13 -> V_82 ) {
V_56 &= F_86 ( V_13 , V_50 , V_22 ,
V_91 ) ;
}
V_13 -> V_26 = ( V_56 & 0x02 ) ? 3025 : 2966 ;
F_87 ( V_6 , L_15 ,
( V_56 & 0x02 ) ? L_16 : L_17 ) ;
V_13 -> V_92 = V_65 [ 3 ] ;
V_13 -> V_37 = F_88 () ;
}
for ( V_56 = 0 ; V_56 < V_13 -> V_79 ; V_56 ++ ) {
if ( F_89 ( V_13 -> V_24 , V_56 ) )
V_13 -> V_16 [ V_56 ] = F_86 ( V_13 ,
V_21 , V_22 ,
F_23 ( V_56 ) ) ;
}
if ( V_93 > 0 ) {
if ( V_54 == 0xe9 && V_13 -> V_85 [ 1 ] )
V_76 = V_65 [ 2 ] & 0x40 ;
F_90 ( V_71 , V_76 ) ;
}
if ( V_13 -> V_81 ) {
V_19 = F_91 ( & V_6 -> V_69 , & V_74 ) ;
if ( V_19 )
goto error;
}
if ( V_13 -> V_81 == 14 ) {
V_19 = F_91 ( & V_6 -> V_69 , & V_73 ) ;
if ( V_19 )
goto error;
}
if ( V_13 -> V_82 ) {
for ( V_56 = 0 ; V_56 < V_13 -> V_82 ; V_56 ++ ) {
V_19 = F_91 ( & V_6 -> V_69 ,
& V_68 [ V_56 ] ) ;
if ( V_19 )
goto error;
}
V_19 = F_92 ( V_6 , & V_67 ) ;
if ( V_19 )
goto error;
}
for ( V_56 = 0 ; V_56 < V_13 -> V_79 ; V_56 ++ ) {
if ( F_89 ( V_13 -> V_24 , V_56 ) ) {
V_19 = F_91 ( & V_6 -> V_69 ,
& V_70 [ V_56 ] ) ;
if ( V_19 )
goto error;
}
if ( F_93 ( V_13 -> V_24 , V_56 ) ) {
V_19 = F_92 ( V_6 , & V_23 [ V_56 ] . V_72 ) ;
if ( V_19 )
goto error;
}
}
V_19 = F_92 ( V_6 , & V_66 ) ;
if ( V_19 )
goto error;
V_13 -> V_94 = F_94 ( V_6 ) ;
if ( F_95 ( V_13 -> V_94 ) ) {
V_19 = F_96 ( V_13 -> V_94 ) ;
goto error;
}
return 0 ;
error:
F_76 ( V_6 ) ;
return V_19 ;
}
static int F_97 ( struct V_75 * V_71 )
{
struct V_12 * V_13 = F_98 ( V_71 ) ;
F_99 ( V_13 -> V_94 ) ;
F_76 ( & V_71 -> V_6 ) ;
return 0 ;
}
static int F_86 ( struct V_12 * V_13 , T_1 V_95 , T_1 V_96 ,
T_1 V_2 )
{
int V_97 ;
F_19 ( & ( V_13 -> V_83 ) ) ;
if ( V_96 != V_22 )
F_100 ( V_96 , V_13 -> V_85 [ V_95 ] + V_98 ) ;
V_97 = F_101 ( V_13 -> V_85 [ V_95 ] + V_2 ) ;
F_24 ( & ( V_13 -> V_83 ) ) ;
return V_97 ;
}
static void F_21 ( struct V_12 * V_13 , T_1 V_95 , T_1 V_96 ,
T_1 V_2 , T_1 V_99 )
{
F_19 ( & ( V_13 -> V_83 ) ) ;
if ( V_96 != V_22 )
F_100 ( V_96 , V_13 -> V_85 [ V_95 ] + V_98 ) ;
F_100 ( V_99 , V_13 -> V_85 [ V_95 ] + V_2 ) ;
F_24 ( & ( V_13 -> V_83 ) ) ;
}
static void F_90 ( struct V_75 * V_71 ,
int V_76 )
{
struct V_12 * V_13 = F_98 ( V_71 ) ;
int V_56 , V_33 ;
const T_1 V_100 [ 14 ] = { 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 3 , 1 , 2 , 2 , 2 } ;
const T_1 V_101 [ 3 ] = { 2 , 2 , 1 } ;
T_1 V_2 ;
if ( V_93 >= 2 && V_13 -> V_81 ) {
V_2 = F_86 ( V_13 , V_30 , V_22 ,
V_102 ) ;
F_102 ( & V_71 -> V_6 ,
L_18 ) ;
F_21 ( V_13 , V_30 , V_22 ,
V_102 ,
( V_2 & 0xC0 ) | 0x11 ) ;
}
V_33 = V_13 -> V_81 < 11 ? V_13 -> V_81 : 11 ;
for ( V_56 = 0 ; V_56 < V_33 ; V_56 ++ ) {
V_2 = F_86 ( V_13 , V_30 , V_56 ,
V_103 ) ;
F_87 ( & V_71 -> V_6 , L_19 , V_56 , V_2 ) ;
if ( V_93 >= V_100 [ V_56 ] ) {
if ( ! ( V_2 & V_104 ) ) {
F_87 ( & V_71 -> V_6 , L_20 ,
V_56 ) ;
F_21 ( V_13 , V_30 , V_56 ,
V_103 ,
( V_2 & 0x68 ) | 0x87 ) ;
}
}
}
F_87 ( & V_71 -> V_6 , L_21 , V_76 ) ;
for ( V_56 = 11 ; V_56 < V_13 -> V_81 ; V_56 ++ ) {
V_2 = F_86 ( V_13 , V_30 , V_56 ,
V_105 ) ;
V_76 = V_76 || ( V_2 & V_104 ) ;
F_87 ( & V_71 -> V_6 , L_22 , V_56 - 7 , V_2 ) ;
}
F_87 ( & V_71 -> V_6 , L_23 , V_76 ) ;
V_56 = V_76 ? 2 : 0 ;
for (; V_56 < V_13 -> V_82 ; V_56 ++ ) {
V_2 = F_86 ( V_13 , V_50 , V_56 ,
V_105 ) ;
F_87 ( & V_71 -> V_6 , L_22 , V_56 + 1 , V_2 ) ;
if ( V_93 >= V_101 [ V_56 ] ) {
if ( ! ( V_2 & V_104 ) ) {
F_87 ( & V_71 -> V_6 ,
L_24 , V_56 + 1 ) ;
F_21 ( V_13 , V_50 , V_56 ,
V_105 ,
0xCF ) ;
}
}
}
if ( V_76 ) {
for ( V_56 = 11 ; V_56 < V_13 -> V_81 ; V_56 ++ ) {
if ( V_93 >= V_100 [ V_56 ] ) {
V_2 = F_86 ( V_13 , V_50 ,
( V_56 - 11 ) / 2 , V_105 ) ;
if ( V_2 & V_104 ) {
F_87 ( & V_71 -> V_6 ,
L_25 ,
V_56 - 7 , ( V_56 - 11 ) / 2 ) ;
continue;
}
V_2 = F_86 ( V_13 , V_30 , V_56 ,
V_103 ) ;
if ( ! ( V_2 & V_104 ) ) {
F_87 ( & V_71 -> V_6 ,
L_24 ,
V_56 - 7 ) ;
F_21 ( V_13 , V_30 , V_56 ,
V_105 ,
( V_2 & 0x60 ) | 0x8F ) ;
}
}
}
}
if ( V_13 -> V_81 ) {
V_2 = F_86 ( V_13 , V_30 , V_22 ,
V_90 ) ;
F_87 ( & V_71 -> V_6 , L_26 , V_2 ) ;
if ( V_2 & V_104 ) {
F_87 ( & V_71 -> V_6 ,
L_27 ) ;
F_21 ( V_13 , V_30 , V_22 ,
V_90 ,
V_2 & 0xFE ) ;
}
}
if ( V_13 -> V_82 ) {
V_2 = F_86 ( V_13 , V_50 , V_22 ,
V_91 ) ;
F_87 ( & V_71 -> V_6 , L_28 , V_2 ) ;
if ( V_2 & V_104 ) {
F_87 ( & V_71 -> V_6 ,
L_29 ) ;
F_21 ( V_13 , V_50 , V_22 ,
V_91 ,
V_2 & 0xFE ) ;
}
if ( V_93 >= 2 ) {
F_21 ( V_13 , V_50 , 0xF , 0xA , 0x08 ) ;
F_21 ( V_13 , V_50 , V_22 , 0xB , 0x04 ) ;
F_21 ( V_13 , V_50 , V_22 , 0xC , 0x35 ) ;
F_21 ( V_13 , V_50 , V_22 , 0xD , 0x05 ) ;
F_21 ( V_13 , V_50 , V_22 , 0xE , 0x05 ) ;
}
}
}
static void F_103 ( struct V_5 * V_6 , int V_33 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
T_1 V_106 = V_13 -> V_17 [ V_33 ] ;
if ( ( V_13 -> V_16 [ V_33 ] & 0x04 )
|| ( V_13 -> V_14 [ V_33 ] >= 224 ) ) {
if ( ( V_13 -> V_16 [ V_33 ] & 0x60 ) != 0x60 ) {
V_13 -> V_16 [ V_33 ] += 0x20 ;
V_13 -> V_17 [ V_33 ] >>= 1 ;
V_13 -> V_14 [ V_33 ] >>= 1 ;
F_87 ( V_6 ,
L_30 ,
F_11 ( V_13 -> V_16 [ V_33 ] ) , V_33 + 1 ) ;
}
} else {
while ( ! ( V_13 -> V_17 [ V_33 ] & 0x80 )
&& V_13 -> V_14 [ V_33 ] < 85
&& ( V_13 -> V_16 [ V_33 ] & 0x60 ) != 0x00 ) {
V_13 -> V_16 [ V_33 ] -= 0x20 ;
V_13 -> V_17 [ V_33 ] <<= 1 ;
V_13 -> V_14 [ V_33 ] <<= 1 ;
F_87 ( V_6 ,
L_31 ,
F_11 ( V_13 -> V_16 [ V_33 ] ) ,
V_33 + 1 ) ;
}
}
if ( V_106 != V_13 -> V_17 [ V_33 ] ) {
F_21 ( V_13 , V_21 , V_22 ,
F_22 ( V_33 ) ,
V_13 -> V_17 [ V_33 ] ) ;
}
}
static struct V_12 * F_9 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
T_1 V_56 ;
F_19 ( & V_13 -> V_20 ) ;
if ( F_104 ( V_107 , V_13 -> V_108 + V_109 * 2 ) || ! V_13 -> V_110 ) {
F_87 ( V_6 , L_32 ) ;
for ( V_56 = 0 ; V_56 < V_13 -> V_79 ; V_56 ++ ) {
if ( F_89 ( V_13 -> V_24 , V_56 ) ) {
V_13 -> V_16 [ V_56 ] =
F_86 ( V_13 , V_21 ,
V_22 , F_23 ( V_56 ) ) ;
V_13 -> V_14 [ V_56 ] = F_86 ( V_13 , V_21 ,
V_22 , F_105 ( V_56 ) ) ;
V_13 -> V_17 [ V_56 ] = F_86 ( V_13 ,
V_21 , V_22 ,
F_22 ( V_56 ) ) ;
F_103 ( V_6 , V_56 ) ;
F_21 ( V_13 , V_21 , V_22 ,
F_23 ( V_56 ) ,
V_13 -> V_16 [ V_56 ] ) ;
}
if ( F_93 ( V_13 -> V_24 , V_56 ) )
V_13 -> V_23 [ V_56 ] = F_86 ( V_13 , V_21 ,
V_22 , F_29 ( V_56 ) ) ;
}
for ( V_56 = 0 ; V_56 < V_13 -> V_81 ; V_56 ++ ) {
V_13 -> V_29 [ V_56 ] = F_86 ( V_13 , V_30 , V_56 ,
V_103 ) ;
F_21 ( V_13 , V_30 , V_56 ,
V_103 ,
V_13 -> V_29 [ V_56 ] ) ;
if ( ( V_13 -> V_29 [ V_56 ] & V_111 ) == V_111 ) {
V_13 -> V_25 [ V_56 ] = F_86 ( V_13 , V_30 ,
V_56 , V_112 ) ;
}
if ( V_13 -> V_29 [ V_56 ] & V_104 ) {
V_13 -> V_27 [ V_56 ] = F_86 ( V_13 ,
V_30 , V_56 ,
V_31 ) ;
V_13 -> V_28 [ V_56 ] = F_86 ( V_13 ,
V_30 , V_56 ,
V_32 ) ;
if ( V_56 >= 11 )
V_13 -> V_40 [ V_56 - 11 ] =
F_86 ( V_13 , V_30 ,
V_56 , V_43 ) ;
}
}
if ( V_13 -> V_81 ) {
V_13 -> V_39 = F_86 ( V_13 , V_30 ,
V_22 , V_113 )
| ( ( F_86 ( V_13 , V_30 ,
V_22 , V_114 )
& 0x07 ) << 8 ) ;
V_13 -> V_36 = ( V_13 -> V_92 & 0xE0 ) ?
F_86 ( V_13 , V_30 ,
V_22 , V_115 ) : 0x1F ;
}
for ( V_56 = 0 ; V_56 < V_13 -> V_82 ; V_56 ++ ) {
V_13 -> V_49 [ V_56 ] = F_86 ( V_13 ,
V_50 , V_56 ,
V_105 ) ;
F_21 ( V_13 , V_50 , V_56 ,
V_105 ,
V_13 -> V_49 [ V_56 ] ) ;
if ( ( V_13 -> V_49 [ V_56 ] & V_111 ) == V_111 ) {
V_13 -> V_45 [ V_56 ] = F_86 ( V_13 ,
V_50 , V_56 ,
V_116 ) ;
}
if ( V_13 -> V_49 [ V_56 ] & V_104 ) {
V_13 -> V_46 [ V_56 ] = F_86 ( V_13 ,
V_50 , V_56 ,
V_41 ) ;
V_13 -> V_47 [ V_56 ] = F_86 ( V_13 ,
V_50 , V_56 ,
V_42 ) ;
V_13 -> V_48 [ V_56 ] = F_86 ( V_13 ,
V_50 , V_56 ,
V_43 ) ;
}
}
if ( V_13 -> V_82 ) {
V_13 -> V_51 = F_86 ( V_13 , V_50 ,
V_22 , V_117 )
& 0x3F ;
}
V_13 -> V_108 = V_107 ;
V_13 -> V_110 = 1 ;
}
F_24 ( & V_13 -> V_20 ) ;
return V_13 ;
}
static int T_4 F_106 ( unsigned short V_85 )
{
struct V_118 V_97 [ 3 ] ;
int V_19 , V_56 , V_119 ;
V_71 = F_107 ( L_9 , V_85 ) ;
if ( ! V_71 ) {
V_19 = - V_78 ;
F_108 ( L_33 ) ;
goto exit;
}
memset ( V_97 , 0 , 3 * sizeof( struct V_118 ) ) ;
V_119 = 0 ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( ! V_80 [ V_56 ] )
continue;
V_97 [ V_119 ] . V_120 = V_80 [ V_56 ] ;
V_97 [ V_119 ] . V_121 = V_80 [ V_56 ] + V_86 - 1 ;
V_97 [ V_119 ] . V_53 = L_9 ,
V_97 [ V_119 ] . V_122 = V_123 ,
V_19 = F_109 ( & V_97 [ V_119 ] ) ;
if ( V_19 )
goto V_124;
V_119 ++ ;
}
V_19 = F_110 ( V_71 , V_97 , V_119 ) ;
if ( V_19 ) {
F_108 ( L_34 , V_19 ) ;
goto V_124;
}
V_19 = F_111 ( V_71 ) ;
if ( V_19 ) {
F_108 ( L_35 , V_19 ) ;
goto V_124;
}
return 0 ;
V_124:
F_112 ( V_71 ) ;
exit:
return V_19 ;
}
static int T_4 F_113 ( void )
{
int V_19 , V_56 ;
unsigned short V_85 = 0 ;
if ( F_73 ( 0x2e , & V_54 , V_80 )
&& F_73 ( 0x4e , & V_54 , V_80 ) ) {
F_114 ( L_36 ) ;
return - V_60 ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( V_80 [ V_56 ] != 0x0000 ) {
V_85 = V_80 [ V_56 ] ;
break;
}
}
if ( V_85 == 0x0000 ) {
F_114 ( L_37 ) ;
return - V_60 ;
}
V_19 = F_115 ( & V_87 ) ;
if ( V_19 )
goto exit;
V_19 = F_106 ( V_85 ) ;
if ( V_19 )
goto V_125;
return 0 ;
V_125:
F_116 ( & V_87 ) ;
exit:
return V_19 ;
}
static void T_6 F_117 ( void )
{
F_118 ( V_71 ) ;
F_116 ( & V_87 ) ;
}
