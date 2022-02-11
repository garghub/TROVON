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
static T_2 F_40 ( struct V_5 * V_6 , struct V_7 * V_11 ,
char * V_9 )
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
V_13 -> V_37 = V_3 ;
return V_18 ;
}
static T_2 F_45 ( struct V_5 * V_6 ,
struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_38 ) ;
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
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_39 [ V_11 -> V_15 - 11 ] ,
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
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_40 ,
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
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_41 ,
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
V_13 -> V_39 [ V_11 -> V_15 - 11 ] = F_36 ( V_3 , V_13 -> V_26 ) ;
F_21 ( V_13 , V_30 , V_11 -> V_15 , V_42 ,
V_13 -> V_39 [ V_11 -> V_15 - 11 ] ) ;
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
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_29 [ V_33 ] & V_43 ) ) ;
}
static T_2 F_57 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_44 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_59 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_45 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_60 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_46 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_61 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 ,
F_58 ( V_13 -> V_47 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_62 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , V_13 -> V_48 [ V_11 -> V_15 ] ) ;
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
V_13 -> V_45 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_49 , V_11 -> V_15 , V_40 ,
V_13 -> V_45 [ V_11 -> V_15 ] ) ;
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
V_13 -> V_46 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_49 , V_11 -> V_15 , V_41 ,
V_13 -> V_46 [ V_11 -> V_15 ] ) ;
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
V_13 -> V_47 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_49 , V_11 -> V_15 , V_42 ,
V_13 -> V_47 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_20 ) ;
return V_18 ;
}
static T_2 F_67 ( struct V_5 * V_6 ,
struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_50 ) ;
}
static T_2 F_68 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_48 [ V_33 ] & V_34 ) ) ;
}
static T_2 F_69 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_48 [ V_33 ] & V_35 ) ) ;
}
static T_2 F_70 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_48 [ V_33 ] & V_43 ) ) ;
}
static T_2 F_71 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_33 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_48 [ V_33 ] & V_51 ) ) ;
}
static T_2 F_72 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
return sprintf ( V_9 , L_3 , V_13 -> V_52 ) ;
}
static int T_4 F_73 ( int V_1 , T_1 * V_53 ,
unsigned short * V_54 )
{
T_5 V_3 ;
int V_55 ;
int V_56 ;
V_3 = V_57 ? V_57 : F_3 ( V_1 , V_58 ) ;
switch ( V_3 ) {
case 0xE1 :
case 0xE8 :
case 0xE4 :
V_56 = 1 ;
break;
case 0xE5 :
case 0xE9 :
V_56 = 3 ;
break;
default:
F_5 ( V_1 ) ;
return - V_59 ;
}
* V_53 = V_3 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
F_1 ( V_1 , V_60 , V_61 [ V_55 ] ) ;
V_3 = F_3 ( V_1 , V_62 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_74 ( L_4 , V_61 [ V_55 ] ) ;
continue;
}
V_3 = ( F_3 ( V_1 , V_63 ) << 8 )
| F_3 ( V_1 , V_63 + 1 ) ;
if ( ! V_3 ) {
F_74 ( L_5 ,
V_61 [ V_55 ] ) ;
continue;
}
V_54 [ V_55 ] = V_3 ;
if ( V_55 == 0 ) {
V_64 [ 0 ] = F_3 ( V_1 , 0xF0 ) ;
V_64 [ 1 ] = F_3 ( V_1 , 0xF1 ) ;
F_75 ( L_6 , 1 ,
( V_64 [ 0 ] >> 2 ) & 1 , ( V_64 [ 0 ] >> 3 ) & 1 ,
( V_64 [ 0 ] >> 4 ) & 1 ) ;
F_75 ( L_6 , 2 ,
( V_64 [ 0 ] >> 5 ) & 1 , ( V_64 [ 0 ] >> 6 ) & 1 ,
( V_64 [ 0 ] >> 7 ) & 1 ) ;
F_75 ( L_6 , 3 ,
V_64 [ 1 ] & 1 , ( V_64 [ 1 ] >> 1 ) & 1 ,
( V_64 [ 1 ] >> 2 ) & 1 ) ;
} else if ( V_55 == 1 ) {
if ( * V_53 == 0xE9 ) {
V_64 [ 2 ] = F_3 ( V_1 , 0x2B ) ;
V_64 [ 3 ] = F_3 ( V_1 , 0x25 ) ;
if ( V_64 [ 2 ] & 0x40 ) {
F_74 ( L_7
L_8 ) ;
}
if ( V_64 [ 3 ] & 0xE0 ) {
F_74 ( L_9 ,
V_64 [ 3 ] >> 5 ) ;
}
}
}
}
F_5 ( V_1 ) ;
return 0 ;
}
static void F_76 ( struct V_5 * V_6 )
{
int V_55 ;
F_77 ( V_6 , & V_65 ) ;
F_77 ( V_6 , & V_66 ) ;
for ( V_55 = 0 ; V_55 < F_78 ( V_67 ) ; V_55 ++ )
F_79 ( & V_6 -> V_68 , & V_67 [ V_55 ] ) ;
for ( V_55 = 0 ; V_55 < F_78 ( V_69 ) ; V_55 ++ ) {
F_79 ( & V_70 -> V_6 . V_68 , & V_69 [ V_55 ] ) ;
F_77 ( V_6 , & V_23 [ V_55 ] . V_71 ) ;
}
F_79 ( & V_6 -> V_68 , & V_72 ) ;
F_79 ( & V_6 -> V_68 , & V_73 ) ;
}
static int T_6 F_80 ( struct V_74 * V_70 )
{
int V_55 ;
struct V_12 * V_13 ;
int V_19 = 0 ;
const char * V_52 = L_10 ;
int V_75 = 0 ;
struct V_5 * V_6 = & V_70 -> V_6 ;
V_13 = F_81 ( sizeof( struct V_12 ) , V_76 ) ;
if ( ! V_13 )
return - V_77 ;
V_13 -> V_78 = 2 ;
V_13 -> V_79 = 0 ;
V_13 -> V_80 = 0 ;
switch ( V_53 ) {
case 0xe8 :
V_52 = L_11 ;
break;
case 0xe4 :
V_52 = L_12 ;
V_13 -> V_78 = 3 ;
break;
case 0xe5 :
V_52 = L_13 ;
V_13 -> V_78 = V_81 [ 0 ] ? 3 : 0 ;
V_13 -> V_79 = V_81 [ 1 ] ? 11 : 0 ;
V_13 -> V_80 = V_81 [ 2 ] ? 2 : 0 ;
break;
case 0xe9 :
V_52 = L_14 ;
V_13 -> V_78 = V_81 [ 0 ] ? 3 : 0 ;
V_13 -> V_79 = V_81 [ 1 ] ? 14 : 0 ;
V_13 -> V_80 = V_81 [ 2 ] ? 3 : 0 ;
break;
}
V_13 -> V_52 = V_52 ;
V_13 -> V_82 = 0 ;
F_82 ( & V_13 -> V_83 ) ;
F_82 ( & V_13 -> V_20 ) ;
F_83 ( V_70 , V_13 ) ;
for ( V_55 = 0 ; V_55 < V_84 ; V_55 ++ ) {
V_13 -> V_85 [ V_55 ] = V_81 [ V_55 ] ;
if ( V_13 -> V_85 [ V_55 ]
&& ! F_84 ( V_81 [ V_55 ] , V_86 ,
V_87 . V_88 . V_52 ) ) {
F_85 ( V_6 , L_15
L_16 , V_81 [ V_55 ] ,
V_81 [ V_55 ] + V_86 - 1 ) ;
for ( V_55 -- ; V_55 >= 0 ; V_55 -- )
F_86 ( V_81 [ V_55 ] , V_86 ) ;
V_19 = - V_89 ;
goto V_90;
}
}
if ( V_13 -> V_78 )
V_13 -> V_24 = V_64 [ 0 ] | ( V_64 [ 1 ] << 8 ) ;
if ( V_13 -> V_79 ) {
V_55 = F_87 ( V_13 , V_30 , V_22 ,
V_91 ) ;
if ( V_13 -> V_80 ) {
V_55 &= F_87 ( V_13 , V_49 , V_22 ,
V_92 ) ;
}
V_13 -> V_26 = ( V_55 & 0x02 ) ? 3025 : 2966 ;
F_88 ( V_6 , L_17 ,
( V_55 & 0x02 ) ? L_18 : L_19 ) ;
V_13 -> V_93 = V_64 [ 3 ] ;
V_13 -> V_37 = F_89 () ;
}
for ( V_55 = 0 ; V_55 < V_13 -> V_78 ; V_55 ++ ) {
if ( F_90 ( V_13 -> V_24 , V_55 ) )
V_13 -> V_16 [ V_55 ] = F_87 ( V_13 ,
V_21 , V_22 ,
F_23 ( V_55 ) ) ;
}
if ( V_94 > 0 ) {
if ( V_53 == 0xe9 && V_13 -> V_85 [ 1 ] )
V_75 = V_64 [ 2 ] & 0x40 ;
F_91 ( V_70 , V_75 ) ;
}
if ( V_13 -> V_79 ) {
V_19 = F_92 ( & V_6 -> V_68 , & V_73 ) ;
if ( V_19 )
goto V_95;
}
if ( V_13 -> V_79 == 14 ) {
V_19 = F_92 ( & V_6 -> V_68 , & V_72 ) ;
if ( V_19 )
goto V_95;
}
if ( V_13 -> V_80 ) {
for ( V_55 = 0 ; V_55 < V_13 -> V_80 ; V_55 ++ ) {
V_19 = F_92 ( & V_6 -> V_68 ,
& V_67 [ V_55 ] ) ;
if ( V_19 )
goto V_95;
}
V_19 = F_93 ( V_6 , & V_66 ) ;
if ( V_19 )
goto V_95;
}
for ( V_55 = 0 ; V_55 < V_13 -> V_78 ; V_55 ++ ) {
if ( F_90 ( V_13 -> V_24 , V_55 ) ) {
V_19 = F_92 ( & V_6 -> V_68 ,
& V_69 [ V_55 ] ) ;
if ( V_19 )
goto V_95;
}
if ( F_94 ( V_13 -> V_24 , V_55 ) ) {
V_19 = F_93 ( V_6 , & V_23 [ V_55 ] . V_71 ) ;
if ( V_19 )
goto V_95;
}
}
V_19 = F_93 ( V_6 , & V_65 ) ;
if ( V_19 )
goto V_95;
V_13 -> V_96 = F_95 ( V_6 ) ;
if ( F_96 ( V_13 -> V_96 ) ) {
V_19 = F_97 ( V_13 -> V_96 ) ;
goto V_95;
}
return 0 ;
V_95:
F_76 ( V_6 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_13 -> V_85 [ V_55 ] )
F_86 ( V_13 -> V_85 [ V_55 ] , V_86 ) ;
}
V_90:
F_98 ( V_13 ) ;
return V_19 ;
}
static int T_7 F_99 ( struct V_74 * V_70 )
{
struct V_12 * V_13 = F_100 ( V_70 ) ;
int V_55 ;
F_101 ( V_13 -> V_96 ) ;
F_76 ( & V_70 -> V_6 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_13 -> V_85 [ V_55 ] )
F_86 ( V_13 -> V_85 [ V_55 ] , V_86 ) ;
}
F_98 ( V_13 ) ;
return 0 ;
}
static int F_87 ( struct V_12 * V_13 , T_1 V_97 , T_1 V_98 ,
T_1 V_2 )
{
int V_99 ;
F_19 ( & ( V_13 -> V_83 ) ) ;
if ( V_98 != V_22 )
F_102 ( V_98 , V_13 -> V_85 [ V_97 ] + V_100 ) ;
V_99 = F_103 ( V_13 -> V_85 [ V_97 ] + V_2 ) ;
F_24 ( & ( V_13 -> V_83 ) ) ;
return V_99 ;
}
static void F_21 ( struct V_12 * V_13 , T_1 V_97 , T_1 V_98 ,
T_1 V_2 , T_1 V_101 )
{
F_19 ( & ( V_13 -> V_83 ) ) ;
if ( V_98 != V_22 )
F_102 ( V_98 , V_13 -> V_85 [ V_97 ] + V_100 ) ;
F_102 ( V_101 , V_13 -> V_85 [ V_97 ] + V_2 ) ;
F_24 ( & ( V_13 -> V_83 ) ) ;
}
static void F_91 ( struct V_74 * V_70 ,
int V_75 )
{
struct V_12 * V_13 = F_100 ( V_70 ) ;
int V_55 , V_33 ;
const T_1 V_102 [ 14 ] = { 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 3 , 1 , 2 , 2 , 2 } ;
const T_1 V_103 [ 3 ] = { 2 , 2 , 1 } ;
T_1 V_2 ;
if ( V_94 >= 2 && V_13 -> V_79 ) {
V_2 = F_87 ( V_13 , V_30 , V_22 ,
V_104 ) ;
F_104 ( & V_70 -> V_6 , L_20
L_21 ) ;
F_21 ( V_13 , V_30 , V_22 ,
V_104 ,
( V_2 & 0xC0 ) | 0x11 ) ;
}
V_33 = V_13 -> V_79 < 11 ? V_13 -> V_79 : 11 ;
for ( V_55 = 0 ; V_55 < V_33 ; V_55 ++ ) {
V_2 = F_87 ( V_13 , V_30 , V_55 ,
V_105 ) ;
F_88 ( & V_70 -> V_6 , L_22 , V_55 , V_2 ) ;
if ( V_94 >= V_102 [ V_55 ] ) {
if ( ! ( V_2 & V_106 ) ) {
F_88 ( & V_70 -> V_6 , L_23
L_24 , V_55 ) ;
F_21 ( V_13 , V_30 , V_55 ,
V_105 ,
( V_2 & 0x68 ) | 0x87 ) ;
}
}
}
F_88 ( & V_70 -> V_6 , L_25 , V_75 ) ;
for ( V_55 = 11 ; V_55 < V_13 -> V_79 ; V_55 ++ ) {
V_2 = F_87 ( V_13 , V_30 , V_55 ,
V_107 ) ;
V_75 = V_75 || ( V_2 & V_106 ) ;
F_88 ( & V_70 -> V_6 , L_26 , V_55 - 7 , V_2 ) ;
}
F_88 ( & V_70 -> V_6 , L_27 , V_75 ) ;
V_55 = V_75 ? 2 : 0 ;
for (; V_55 < V_13 -> V_80 ; V_55 ++ ) {
V_2 = F_87 ( V_13 , V_49 , V_55 ,
V_107 ) ;
F_88 ( & V_70 -> V_6 , L_26 , V_55 + 1 , V_2 ) ;
if ( V_94 >= V_103 [ V_55 ] ) {
if ( ! ( V_2 & V_106 ) ) {
F_88 ( & V_70 -> V_6 ,
L_28 , V_55 + 1 ) ;
F_21 ( V_13 , V_49 , V_55 ,
V_107 ,
0xCF ) ;
}
}
}
if ( V_75 ) {
for ( V_55 = 11 ; V_55 < V_13 -> V_79 ; V_55 ++ ) {
if ( V_94 >= V_102 [ V_55 ] ) {
V_2 = F_87 ( V_13 , V_49 ,
( V_55 - 11 ) / 2 , V_107 ) ;
if ( V_2 & V_106 ) {
F_88 ( & V_70 -> V_6 ,
L_29 ,
V_55 - 7 , ( V_55 - 11 ) / 2 ) ;
continue;
}
V_2 = F_87 ( V_13 , V_30 , V_55 ,
V_105 ) ;
if ( ! ( V_2 & V_106 ) ) {
F_88 ( & V_70 -> V_6 ,
L_28 ,
V_55 - 7 ) ;
F_21 ( V_13 , V_30 , V_55 ,
V_107 ,
( V_2 & 0x60 ) | 0x8F ) ;
}
}
}
}
if ( V_13 -> V_79 ) {
V_2 = F_87 ( V_13 , V_30 , V_22 ,
V_91 ) ;
F_88 ( & V_70 -> V_6 , L_30 , V_2 ) ;
if ( V_2 & V_106 ) {
F_88 ( & V_70 -> V_6 ,
L_31 ) ;
F_21 ( V_13 , V_30 , V_22 ,
V_91 ,
V_2 & 0xFE ) ;
}
}
if ( V_13 -> V_80 ) {
V_2 = F_87 ( V_13 , V_49 , V_22 ,
V_92 ) ;
F_88 ( & V_70 -> V_6 , L_32 , V_2 ) ;
if ( V_2 & V_106 ) {
F_88 ( & V_70 -> V_6 ,
L_33 ) ;
F_21 ( V_13 , V_49 , V_22 ,
V_92 ,
V_2 & 0xFE ) ;
}
if ( V_94 >= 2 ) {
F_21 ( V_13 , V_49 , 0xF , 0xA , 0x08 ) ;
F_21 ( V_13 , V_49 , V_22 , 0xB , 0x04 ) ;
F_21 ( V_13 , V_49 , V_22 , 0xC , 0x35 ) ;
F_21 ( V_13 , V_49 , V_22 , 0xD , 0x05 ) ;
F_21 ( V_13 , V_49 , V_22 , 0xE , 0x05 ) ;
}
}
}
static void F_105 ( struct V_5 * V_6 , int V_33 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
T_1 V_108 = V_13 -> V_17 [ V_33 ] ;
if ( ( V_13 -> V_16 [ V_33 ] & 0x04 )
|| ( V_13 -> V_14 [ V_33 ] >= 224 ) ) {
if ( ( V_13 -> V_16 [ V_33 ] & 0x60 ) != 0x60 ) {
V_13 -> V_16 [ V_33 ] += 0x20 ;
V_13 -> V_17 [ V_33 ] >>= 1 ;
V_13 -> V_14 [ V_33 ] >>= 1 ;
F_88 ( V_6 , L_34
L_35 ,
F_11 ( V_13 -> V_16 [ V_33 ] ) , V_33 + 1 ) ;
}
} else {
while ( ! ( V_13 -> V_17 [ V_33 ] & 0x80 )
&& V_13 -> V_14 [ V_33 ] < 85
&& ( V_13 -> V_16 [ V_33 ] & 0x60 ) != 0x00 ) {
V_13 -> V_16 [ V_33 ] -= 0x20 ;
V_13 -> V_17 [ V_33 ] <<= 1 ;
V_13 -> V_14 [ V_33 ] <<= 1 ;
F_88 ( V_6 , L_36
L_35 ,
F_11 ( V_13 -> V_16 [ V_33 ] ) ,
V_33 + 1 ) ;
}
}
if ( V_108 != V_13 -> V_17 [ V_33 ] ) {
F_21 ( V_13 , V_21 , V_22 ,
F_22 ( V_33 ) ,
V_13 -> V_17 [ V_33 ] ) ;
}
}
static struct V_12 * F_9 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
T_1 V_55 ;
F_19 ( & V_13 -> V_20 ) ;
if ( F_106 ( V_109 , V_13 -> V_110 + V_111 * 2 ) || ! V_13 -> V_82 ) {
F_88 ( V_6 , L_37 ) ;
for ( V_55 = 0 ; V_55 < V_13 -> V_78 ; V_55 ++ ) {
if ( F_90 ( V_13 -> V_24 , V_55 ) ) {
V_13 -> V_16 [ V_55 ] =
F_87 ( V_13 , V_21 ,
V_22 , F_23 ( V_55 ) ) ;
V_13 -> V_14 [ V_55 ] = F_87 ( V_13 , V_21 ,
V_22 , F_107 ( V_55 ) ) ;
V_13 -> V_17 [ V_55 ] = F_87 ( V_13 ,
V_21 , V_22 ,
F_22 ( V_55 ) ) ;
F_105 ( V_6 , V_55 ) ;
F_21 ( V_13 , V_21 , V_22 ,
F_23 ( V_55 ) ,
V_13 -> V_16 [ V_55 ] ) ;
}
if ( F_94 ( V_13 -> V_24 , V_55 ) )
V_13 -> V_23 [ V_55 ] = F_87 ( V_13 , V_21 ,
V_22 , F_29 ( V_55 ) ) ;
}
for ( V_55 = 0 ; V_55 < V_13 -> V_79 ; V_55 ++ ) {
V_13 -> V_29 [ V_55 ] = F_87 ( V_13 , V_30 , V_55 ,
V_105 ) ;
F_21 ( V_13 , V_30 , V_55 ,
V_105 ,
V_13 -> V_29 [ V_55 ] ) ;
if ( ( V_13 -> V_29 [ V_55 ] & V_112 ) == V_112 ) {
V_13 -> V_25 [ V_55 ] = F_87 ( V_13 , V_30 ,
V_55 , V_113 ) ;
}
if ( V_13 -> V_29 [ V_55 ] & V_106 ) {
V_13 -> V_27 [ V_55 ] = F_87 ( V_13 ,
V_30 , V_55 ,
V_31 ) ;
V_13 -> V_28 [ V_55 ] = F_87 ( V_13 ,
V_30 , V_55 ,
V_32 ) ;
if ( V_55 >= 11 )
V_13 -> V_39 [ V_55 - 11 ] =
F_87 ( V_13 , V_30 ,
V_55 , V_42 ) ;
}
}
if ( V_13 -> V_79 ) {
V_13 -> V_38 = F_87 ( V_13 , V_30 ,
V_22 , V_114 )
| ( ( F_87 ( V_13 , V_30 ,
V_22 , V_115 )
& 0x07 ) << 8 ) ;
V_13 -> V_36 = ( V_13 -> V_93 & 0xE0 ) ?
F_87 ( V_13 , V_30 ,
V_22 , V_116 ) : 0x1F ;
}
for ( V_55 = 0 ; V_55 < V_13 -> V_80 ; V_55 ++ ) {
V_13 -> V_48 [ V_55 ] = F_87 ( V_13 ,
V_49 , V_55 ,
V_107 ) ;
F_21 ( V_13 , V_49 , V_55 ,
V_107 ,
V_13 -> V_48 [ V_55 ] ) ;
if ( ( V_13 -> V_48 [ V_55 ] & V_112 ) == V_112 ) {
V_13 -> V_44 [ V_55 ] = F_87 ( V_13 ,
V_49 , V_55 ,
V_117 ) ;
}
if ( V_13 -> V_48 [ V_55 ] & V_106 ) {
V_13 -> V_45 [ V_55 ] = F_87 ( V_13 ,
V_49 , V_55 ,
V_40 ) ;
V_13 -> V_46 [ V_55 ] = F_87 ( V_13 ,
V_49 , V_55 ,
V_41 ) ;
V_13 -> V_47 [ V_55 ] = F_87 ( V_13 ,
V_49 , V_55 ,
V_42 ) ;
}
}
if ( V_13 -> V_80 ) {
V_13 -> V_50 = F_87 ( V_13 , V_49 ,
V_22 , V_118 )
& 0x3F ;
}
V_13 -> V_110 = V_109 ;
V_13 -> V_82 = 1 ;
}
F_24 ( & V_13 -> V_20 ) ;
return V_13 ;
}
static int T_4 F_108 ( unsigned short V_85 )
{
struct V_119 V_99 [ 3 ] ;
int V_19 , V_55 , V_120 ;
V_70 = F_109 ( L_10 , V_85 ) ;
if ( ! V_70 ) {
V_19 = - V_77 ;
F_110 ( L_38 ) ;
goto exit;
}
memset ( V_99 , 0 , 3 * sizeof( struct V_119 ) ) ;
V_120 = 0 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! V_81 [ V_55 ] )
continue;
V_99 [ V_120 ] . V_121 = V_81 [ V_55 ] ;
V_99 [ V_120 ] . V_122 = V_81 [ V_55 ] + V_86 - 1 ;
V_99 [ V_120 ] . V_52 = L_10 ,
V_99 [ V_120 ] . V_123 = V_124 ,
V_19 = F_111 ( & V_99 [ V_120 ] ) ;
if ( V_19 )
goto V_125;
V_120 ++ ;
}
V_19 = F_112 ( V_70 , V_99 , V_120 ) ;
if ( V_19 ) {
F_110 ( L_39 , V_19 ) ;
goto V_125;
}
V_19 = F_113 ( V_70 ) ;
if ( V_19 ) {
F_110 ( L_40 , V_19 ) ;
goto V_125;
}
return 0 ;
V_125:
F_114 ( V_70 ) ;
exit:
return V_19 ;
}
static int T_4 F_115 ( void )
{
int V_19 , V_55 ;
unsigned short V_85 = 0 ;
if ( F_73 ( 0x2e , & V_53 , V_81 )
&& F_73 ( 0x4e , & V_53 , V_81 ) ) {
F_116 ( L_41 ) ;
return - V_59 ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_81 [ V_55 ] != 0x0000 ) {
V_85 = V_81 [ V_55 ] ;
break;
}
}
if ( V_85 == 0x0000 ) {
F_116 ( L_42 ) ;
return - V_59 ;
}
V_19 = F_117 ( & V_87 ) ;
if ( V_19 )
goto exit;
V_19 = F_108 ( V_85 ) ;
if ( V_19 )
goto V_126;
return 0 ;
V_126:
F_118 ( & V_87 ) ;
exit:
return V_19 ;
}
static void T_8 F_119 ( void )
{
F_120 ( V_70 ) ;
F_118 ( & V_87 ) ;
}
