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
static T_2 F_7 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_10 ( V_13 -> V_14 [ V_11 -> V_15 ] ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ) ;
}
static T_2 F_12 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_10 ( V_13 -> V_17 [ V_11 -> V_15 ] ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ) ;
}
static T_2 F_13 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 ,
F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_14 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 ,
F_15 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_16 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_17 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_17 = F_20 ( V_17 , F_11 ( V_13 -> V_16 [ V_11 -> V_15 ] ) ) ;
while ( V_17 > 255
&& ( V_13 -> V_16 [ V_11 -> V_15 ] & 0x60 ) != 0x60 ) {
V_17 >>= 1 ;
V_13 -> V_14 [ V_11 -> V_15 ] >>= 1 ;
V_13 -> V_16 [ V_11 -> V_15 ] += 0x20 ;
}
V_13 -> V_17 [ V_11 -> V_15 ] = V_17 > 255 ? 255 : V_17 ;
F_21 ( V_13 , V_20 , V_21 , F_22 ( V_11 -> V_15 ) ,
V_13 -> V_17 [ V_11 -> V_15 ] ) ;
F_21 ( V_13 , V_20 , V_21 , F_23 ( V_11 -> V_15 ) ,
V_13 -> V_16 [ V_11 -> V_15 ] & 0xF9 ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_25 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 ,
F_26 ( V_13 -> V_22 [ V_11 -> V_15 ] ,
F_27 ( V_13 -> V_23 ,
V_11 -> V_15 ) ) ) ;
}
static T_2 F_28 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_22 [ V_11 -> V_15 ] = F_6 ( V_3 ,
F_27 ( V_13 -> V_23 , V_11 -> V_15 ) ) ;
F_21 ( V_13 , V_20 , V_21 , F_29 ( V_11 -> V_15 ) ,
V_13 -> V_22 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_30 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_24 [ V_11 -> V_15 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_32 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_26 [ V_11 -> V_15 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_33 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_27 [ V_11 -> V_15 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_34 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_28 [ V_11 -> V_15 ] ) ;
}
static T_2 F_35 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_26 [ V_11 -> V_15 ] = F_36 ( V_3 , V_13 -> V_25 ) ;
F_21 ( V_13 , V_29 , V_11 -> V_15 , V_30 ,
V_13 -> V_26 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_37 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_27 [ V_11 -> V_15 ] = F_36 ( V_3 ,
V_13 -> V_25 ) ;
F_21 ( V_13 , V_29 , V_11 -> V_15 , V_31 ,
V_13 -> V_27 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_38 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_28 [ V_32 ] & V_33 ) ) ;
}
static T_2 F_39 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_28 [ V_32 ] & V_34 ) ) ;
}
static T_2 F_40 ( struct V_5 * V_6 , struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_41 ( V_13 -> V_35 , V_13 -> V_36 ) ) ;
}
static T_2 F_42 ( struct V_5 * V_6 , struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_36 ) ;
}
static T_2 F_43 ( struct V_5 * V_6 , struct V_7 * V_11 , const char * V_9 , T_3 V_18 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
V_13 -> V_36 = F_44 ( V_9 , NULL , 10 ) ;
return V_18 ;
}
static T_2 F_45 ( struct V_5 * V_6 , struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_37 ) ;
}
static T_2 F_46 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_24 [ V_11 -> V_15 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_47 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_26 [ V_11 -> V_15 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_48 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_27 [ V_11 -> V_15 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_49 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_31 ( V_13 -> V_38 [ V_11 -> V_15 - 11 ] ,
V_13 -> V_25 ) ) ;
}
static T_2 F_50 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_28 [ V_11 -> V_15 ] ) ;
}
static T_2 F_51 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_26 [ V_11 -> V_15 ] = F_36 ( V_3 , V_13 -> V_25 ) ;
F_21 ( V_13 , V_29 , V_11 -> V_15 , V_39 ,
V_13 -> V_26 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_52 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_27 [ V_11 -> V_15 ] = F_36 ( V_3 , V_13 -> V_25 ) ;
F_21 ( V_13 , V_29 , V_11 -> V_15 , V_40 ,
V_13 -> V_27 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_53 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_38 [ V_11 -> V_15 - 11 ] = F_36 ( V_3 , V_13 -> V_25 ) ;
F_21 ( V_13 , V_29 , V_11 -> V_15 , V_41 ,
V_13 -> V_38 [ V_11 -> V_15 - 11 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_54 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_28 [ V_32 ] & V_33 ) ) ;
}
static T_2 F_55 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_28 [ V_32 ] & V_34 ) ) ;
}
static T_2 F_56 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_28 [ V_32 ] & V_42 ) ) ;
}
static T_2 F_57 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_43 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_59 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_44 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_60 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_45 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_61 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , F_58 ( V_13 -> V_46 [ V_11 -> V_15 ] ) ) ;
}
static T_2 F_62 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_2 , V_13 -> V_47 [ V_11 -> V_15 ] ) ;
}
static T_2 F_63 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_44 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_48 , V_11 -> V_15 , V_39 ,
V_13 -> V_44 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_65 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_45 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_48 , V_11 -> V_15 , V_40 ,
V_13 -> V_45 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_66 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 ,
T_3 V_18 )
{
struct V_10 * V_11 = F_8 ( V_8 ) ;
struct V_12 * V_13 = F_17 ( V_6 ) ;
long V_3 = F_18 ( V_9 , NULL , 10 ) ;
F_19 ( & V_13 -> V_19 ) ;
V_13 -> V_46 [ V_11 -> V_15 ] = F_64 ( V_3 ) ;
F_21 ( V_13 , V_48 , V_11 -> V_15 , V_41 ,
V_13 -> V_46 [ V_11 -> V_15 ] ) ;
F_24 ( & V_13 -> V_19 ) ;
return V_18 ;
}
static T_2 F_67 ( struct V_5 * V_6 , struct V_7 * V_11 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
return sprintf ( V_9 , L_1 , V_13 -> V_49 ) ;
}
static T_2 F_68 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_47 [ V_32 ] & V_33 ) ) ;
}
static T_2 F_69 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_47 [ V_32 ] & V_34 ) ) ;
}
static T_2 F_70 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_47 [ V_32 ] & V_42 ) ) ;
}
static T_2 F_71 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_9 ( V_6 ) ;
unsigned V_32 = F_8 ( V_8 ) -> V_15 ;
return sprintf ( V_9 , L_1 , ! ! ( V_13 -> V_47 [ V_32 ] & V_50 ) ) ;
}
static T_2 F_72 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
return sprintf ( V_9 , L_3 , V_13 -> V_51 ) ;
}
static int T_4 F_73 ( int V_1 , T_1 * V_52 , unsigned short * V_53 )
{
T_5 V_3 ;
int V_54 ;
int V_55 ;
V_3 = V_56 ? V_56 : F_3 ( V_1 , V_57 ) ;
switch ( V_3 ) {
case 0xE1 :
case 0xE8 :
case 0xE4 :
V_55 = 1 ;
break;
case 0xE5 :
case 0xE9 :
V_55 = 3 ;
break;
default:
F_5 ( V_1 ) ;
return - V_58 ;
}
* V_52 = V_3 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
F_1 ( V_1 , V_59 , V_60 [ V_54 ] ) ;
V_3 = F_3 ( V_1 , V_61 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_74 ( L_4 , V_60 [ V_54 ] ) ;
continue;
}
V_3 = ( F_3 ( V_1 , V_62 ) << 8 )
| F_3 ( V_1 , V_62 + 1 ) ;
if ( ! V_3 ) {
F_74 ( L_5 ,
V_60 [ V_54 ] ) ;
continue;
}
V_53 [ V_54 ] = V_3 ;
if ( V_54 == 0 ) {
V_63 [ 0 ] = F_3 ( V_1 , 0xF0 ) ;
V_63 [ 1 ] = F_3 ( V_1 , 0xF1 ) ;
F_75 ( L_6 , 1 ,
( V_63 [ 0 ] >> 2 ) & 1 , ( V_63 [ 0 ] >> 3 ) & 1 ,
( V_63 [ 0 ] >> 4 ) & 1 ) ;
F_75 ( L_6 , 2 ,
( V_63 [ 0 ] >> 5 ) & 1 , ( V_63 [ 0 ] >> 6 ) & 1 ,
( V_63 [ 0 ] >> 7 ) & 1 ) ;
F_75 ( L_6 , 3 ,
V_63 [ 1 ] & 1 , ( V_63 [ 1 ] >> 1 ) & 1 ,
( V_63 [ 1 ] >> 2 ) & 1 ) ;
} else if ( V_54 == 1 ) {
if ( * V_52 == 0xE9 ) {
V_63 [ 2 ] = F_3 ( V_1 , 0x2B ) ;
V_63 [ 3 ] = F_3 ( V_1 , 0x25 ) ;
if ( V_63 [ 2 ] & 0x40 ) {
F_74 ( L_7
L_8 ) ;
}
if ( V_63 [ 3 ] & 0xE0 ) {
F_74 ( L_9 ,
V_63 [ 3 ] >> 5 ) ;
}
}
}
}
F_5 ( V_1 ) ;
return 0 ;
}
static int T_6 F_76 ( struct V_64 * V_65 )
{
int V_54 ;
struct V_12 * V_13 ;
int V_66 = 0 ;
const char * V_51 = L_10 ;
int V_67 = 0 ;
struct V_5 * V_6 = & V_65 -> V_6 ;
if ( ! ( V_13 = F_77 ( sizeof( struct V_12 ) , V_68 ) ) )
return - V_69 ;
V_13 -> V_70 = 2 ;
V_13 -> V_71 = 0 ;
V_13 -> V_72 = 0 ;
switch ( V_52 ) {
case 0xe8 :
V_51 = L_11 ;
break;
case 0xe4 :
V_51 = L_12 ;
V_13 -> V_70 = 3 ;
break;
case 0xe5 :
V_51 = L_13 ;
V_13 -> V_70 = V_73 [ 0 ] ? 3 : 0 ;
V_13 -> V_71 = V_73 [ 1 ] ? 11 : 0 ;
V_13 -> V_72 = V_73 [ 2 ] ? 2 : 0 ;
break;
case 0xe9 :
V_51 = L_14 ;
V_13 -> V_70 = V_73 [ 0 ] ? 3 : 0 ;
V_13 -> V_71 = V_73 [ 1 ] ? 14 : 0 ;
V_13 -> V_72 = V_73 [ 2 ] ? 3 : 0 ;
break;
}
V_13 -> V_51 = V_51 ;
V_13 -> V_74 = 0 ;
F_78 ( & V_13 -> V_75 ) ;
F_78 ( & V_13 -> V_19 ) ;
F_79 ( V_65 , V_13 ) ;
for ( V_54 = 0 ; V_54 < V_76 ; V_54 ++ ) {
if ( ( ( V_13 -> V_77 [ V_54 ] = V_73 [ V_54 ] ) )
&& ! F_80 ( V_73 [ V_54 ] , V_78 ,
V_79 . V_80 . V_51 ) ) {
F_81 ( V_6 , L_15
L_16 , V_73 [ V_54 ] ,
V_73 [ V_54 ] + V_78 - 1 ) ;
for ( V_54 -- ; V_54 >= 0 ; V_54 -- )
F_82 ( V_73 [ V_54 ] , V_78 ) ;
V_66 = - V_81 ;
goto V_82;
}
}
if ( V_13 -> V_70 )
V_13 -> V_23 = V_63 [ 0 ] | ( V_63 [ 1 ] << 8 ) ;
if ( V_13 -> V_71 ) {
V_54 = F_83 ( V_13 , V_29 , V_21 ,
V_83 ) ;
if ( V_13 -> V_72 ) {
V_54 &= F_83 ( V_13 , V_48 , V_21 ,
V_84 ) ;
}
V_13 -> V_25 = ( V_54 & 0x02 ) ? 3025 : 2966 ;
F_84 ( V_6 , L_17 ,
( V_54 & 0x02 ) ? L_18 : L_19 ) ;
V_13 -> V_85 = V_63 [ 3 ] ;
V_13 -> V_36 = F_85 () ;
}
for ( V_54 = 0 ; V_54 < V_13 -> V_70 ; V_54 ++ ) {
if ( F_86 ( V_13 -> V_23 , V_54 ) )
V_13 -> V_16 [ V_54 ] = F_83 ( V_13 ,
V_20 , V_21 ,
F_23 ( V_54 ) ) ;
}
if ( V_86 > 0 ) {
if ( V_52 == 0xe9 && V_13 -> V_77 [ 1 ] )
V_67 = V_63 [ 2 ] & 0x40 ;
F_87 ( V_65 , V_67 ) ;
}
if ( V_13 -> V_71 &&
( V_66 = F_88 ( & V_6 -> V_87 ,
& V_88 ) ) )
goto V_89;
if ( V_13 -> V_71 == 14 &&
( V_66 = F_88 ( & V_6 -> V_87 ,
& V_90 ) ) )
goto V_89;
if ( V_13 -> V_72 ) {
for ( V_54 = 0 ; V_54 < V_13 -> V_72 ; V_54 ++ ) {
if ( ( V_66 = F_89 ( V_6 ,
& V_91 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_44 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_45 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_46 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_47 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_93 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_94 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_95 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_96 [ V_54 ] . V_92 ) ) )
goto V_89;
}
if ( ( V_66 = F_89 ( V_6 , & V_97 ) ) )
goto V_89;
}
for ( V_54 = 0 ; V_54 < V_13 -> V_70 ; V_54 ++ ) {
if ( F_86 ( V_13 -> V_23 , V_54 )
&& ( ( V_66 = F_89 ( V_6 ,
& V_98 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_17 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_99 [ V_54 ] . V_92 ) )
|| ( V_66 = F_89 ( V_6 ,
& V_16 [ V_54 ] . V_92 ) ) ) )
goto V_89;
if ( F_90 ( V_13 -> V_23 , V_54 )
&& ( V_66 = F_89 ( V_6 , & V_22 [ V_54 ] . V_92 ) ) )
goto V_89;
}
if ( ( V_66 = F_89 ( V_6 , & V_100 ) ) )
goto V_89;
V_13 -> V_101 = F_91 ( V_6 ) ;
if ( F_92 ( V_13 -> V_101 ) ) {
V_66 = F_93 ( V_13 -> V_101 ) ;
goto V_89;
}
return 0 ;
V_89:
F_94 ( V_6 , & V_100 ) ;
F_95 ( & V_6 -> V_87 , & V_102 ) ;
F_95 ( & V_6 -> V_87 , & V_103 ) ;
F_95 ( & V_6 -> V_87 , & V_90 ) ;
F_95 ( & V_6 -> V_87 , & V_88 ) ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( V_13 -> V_77 [ V_54 ] ) {
F_82 ( V_13 -> V_77 [ V_54 ] , V_78 ) ;
}
}
V_82:
F_96 ( V_13 ) ;
return V_66 ;
}
static int T_7 F_97 ( struct V_64 * V_65 )
{
struct V_12 * V_13 = F_98 ( V_65 ) ;
int V_54 ;
F_99 ( V_13 -> V_101 ) ;
F_94 ( & V_65 -> V_6 , & V_100 ) ;
F_95 ( & V_65 -> V_6 . V_87 , & V_102 ) ;
F_95 ( & V_65 -> V_6 . V_87 , & V_103 ) ;
F_95 ( & V_65 -> V_6 . V_87 , & V_90 ) ;
F_95 ( & V_65 -> V_6 . V_87 , & V_88 ) ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( V_13 -> V_77 [ V_54 ] ) {
F_82 ( V_13 -> V_77 [ V_54 ] , V_78 ) ;
}
}
F_96 ( V_13 ) ;
return 0 ;
}
static int F_83 ( struct V_12 * V_13 , T_1 V_104 , T_1 V_105 ,
T_1 V_2 )
{
int V_106 ;
F_19 ( & ( V_13 -> V_75 ) ) ;
if ( V_105 != V_21 )
F_100 ( V_105 , V_13 -> V_77 [ V_104 ] + V_107 ) ;
V_106 = F_101 ( V_13 -> V_77 [ V_104 ] + V_2 ) ;
F_24 ( & ( V_13 -> V_75 ) ) ;
return V_106 ;
}
static void F_21 ( struct V_12 * V_13 , T_1 V_104 , T_1 V_105 ,
T_1 V_2 , T_1 V_108 )
{
F_19 ( & ( V_13 -> V_75 ) ) ;
if ( V_105 != V_21 )
F_100 ( V_105 , V_13 -> V_77 [ V_104 ] + V_107 ) ;
F_100 ( V_108 , V_13 -> V_77 [ V_104 ] + V_2 ) ;
F_24 ( & ( V_13 -> V_75 ) ) ;
}
static void F_87 ( struct V_64 * V_65 ,
int V_67 )
{
struct V_12 * V_13 = F_98 ( V_65 ) ;
int V_54 , V_32 ;
const T_1 V_109 [ 14 ] = { 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 3 , 1 , 2 , 2 , 2 } ;
const T_1 V_110 [ 3 ] = { 2 , 2 , 1 } ;
T_1 V_2 ;
if ( V_86 >= 2 && V_13 -> V_71 ) {
V_2 = F_83 ( V_13 , V_29 , V_21 ,
V_111 ) ;
F_102 ( & V_65 -> V_6 , L_20
L_21 ) ;
F_21 ( V_13 , V_29 , V_21 ,
V_111 ,
( V_2 & 0xC0 ) | 0x11 ) ;
}
V_32 = V_13 -> V_71 < 11 ? V_13 -> V_71 : 11 ;
for ( V_54 = 0 ; V_54 < V_32 ; V_54 ++ ) {
V_2 = F_83 ( V_13 , V_29 , V_54 ,
V_112 ) ;
F_84 ( & V_65 -> V_6 , L_22 , V_54 , V_2 ) ;
if ( V_86 >= V_109 [ V_54 ] ) {
if ( ! ( V_2 & V_113 ) ) {
F_84 ( & V_65 -> V_6 , L_23
L_24 , V_54 ) ;
F_21 ( V_13 , V_29 , V_54 ,
V_112 ,
( V_2 & 0x68 ) | 0x87 ) ;
}
}
}
F_84 ( & V_65 -> V_6 , L_25 , V_67 ) ;
for ( V_54 = 11 ; V_54 < V_13 -> V_71 ; V_54 ++ ) {
V_2 = F_83 ( V_13 , V_29 , V_54 ,
V_114 ) ;
V_67 = V_67 || ( V_2 & V_113 ) ;
F_84 ( & V_65 -> V_6 , L_26 , V_54 - 7 , V_2 ) ;
}
F_84 ( & V_65 -> V_6 , L_27 , V_67 ) ;
V_54 = V_67 ? 2 : 0 ;
for (; V_54 < V_13 -> V_72 ; V_54 ++ ) {
V_2 = F_83 ( V_13 , V_48 , V_54 ,
V_114 ) ;
F_84 ( & V_65 -> V_6 , L_26 , V_54 + 1 , V_2 ) ;
if ( V_86 >= V_110 [ V_54 ] ) {
if ( ! ( V_2 & V_113 ) ) {
F_84 ( & V_65 -> V_6 , L_23
L_28 , V_54 + 1 ) ;
F_21 ( V_13 , V_48 , V_54 ,
V_114 ,
0xCF ) ;
}
}
}
if ( V_67 ) {
for ( V_54 = 11 ; V_54 < V_13 -> V_71 ; V_54 ++ ) {
if ( V_86 >= V_109 [ V_54 ] ) {
V_2 = F_83 ( V_13 , V_48 ,
( V_54 - 11 ) / 2 , V_114 ) ;
if ( V_2 & V_113 ) {
F_84 ( & V_65 -> V_6 , L_29
L_30
L_31 , V_54 - 7 , ( V_54 - 11 ) / 2 ) ;
continue;
}
V_2 = F_83 ( V_13 , V_29 , V_54 ,
V_112 ) ;
if ( ! ( V_2 & V_113 ) ) {
F_84 ( & V_65 -> V_6 , L_23
L_28 , V_54 - 7 ) ;
F_21 ( V_13 , V_29 , V_54 ,
V_114 ,
( V_2 & 0x60 ) | 0x8F ) ;
}
}
}
}
if ( V_13 -> V_71 ) {
V_2 = F_83 ( V_13 , V_29 , V_21 ,
V_83 ) ;
F_84 ( & V_65 -> V_6 , L_32 , V_2 ) ;
if ( V_2 & V_113 ) {
F_84 ( & V_65 -> V_6 , L_23
L_33 ) ;
F_21 ( V_13 , V_29 , V_21 ,
V_83 ,
V_2 & 0xFE ) ;
}
}
if ( V_13 -> V_72 ) {
V_2 = F_83 ( V_13 , V_48 , V_21 ,
V_84 ) ;
F_84 ( & V_65 -> V_6 , L_34 , V_2 ) ;
if ( V_2 & V_113 ) {
F_84 ( & V_65 -> V_6 , L_35
L_36 ) ;
F_21 ( V_13 , V_48 , V_21 ,
V_84 ,
V_2 & 0xFE ) ;
}
if ( V_86 >= 2 ) {
F_21 ( V_13 , V_48 , 0xF , 0xA , 0x08 ) ;
F_21 ( V_13 , V_48 , V_21 , 0xB , 0x04 ) ;
F_21 ( V_13 , V_48 , V_21 , 0xC , 0x35 ) ;
F_21 ( V_13 , V_48 , V_21 , 0xD , 0x05 ) ;
F_21 ( V_13 , V_48 , V_21 , 0xE , 0x05 ) ;
}
}
}
static void F_103 ( struct V_5 * V_6 , int V_32 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
T_1 V_115 = V_13 -> V_17 [ V_32 ] ;
if ( ( V_13 -> V_16 [ V_32 ] & 0x04 )
|| ( V_13 -> V_14 [ V_32 ] >= 224 ) ) {
if ( ( V_13 -> V_16 [ V_32 ] & 0x60 ) != 0x60 ) {
V_13 -> V_16 [ V_32 ] += 0x20 ;
V_13 -> V_17 [ V_32 ] >>= 1 ;
V_13 -> V_14 [ V_32 ] >>= 1 ;
F_84 ( V_6 , L_37
L_38 ,
F_11 ( V_13 -> V_16 [ V_32 ] ) , V_32 + 1 ) ;
}
} else {
while ( ! ( V_13 -> V_17 [ V_32 ] & 0x80 )
&& V_13 -> V_14 [ V_32 ] < 85
&& ( V_13 -> V_16 [ V_32 ] & 0x60 ) != 0x00 ) {
V_13 -> V_16 [ V_32 ] -= 0x20 ;
V_13 -> V_17 [ V_32 ] <<= 1 ;
V_13 -> V_14 [ V_32 ] <<= 1 ;
F_84 ( V_6 , L_39
L_38 ,
F_11 ( V_13 -> V_16 [ V_32 ] ) ,
V_32 + 1 ) ;
}
}
if ( V_115 != V_13 -> V_17 [ V_32 ] ) {
F_21 ( V_13 , V_20 , V_21 ,
F_22 ( V_32 ) ,
V_13 -> V_17 [ V_32 ] ) ;
}
}
static struct V_12 * F_9 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_17 ( V_6 ) ;
T_1 V_54 ;
F_19 ( & V_13 -> V_19 ) ;
if ( F_104 ( V_116 , V_13 -> V_117 + V_118 * 2 ) || ! V_13 -> V_74 ) {
F_84 ( V_6 , L_40 ) ;
for ( V_54 = 0 ; V_54 < V_13 -> V_70 ; V_54 ++ ) {
if ( F_86 ( V_13 -> V_23 , V_54 ) ) {
V_13 -> V_16 [ V_54 ] =
F_83 ( V_13 , V_20 ,
V_21 , F_23 ( V_54 ) ) ;
V_13 -> V_14 [ V_54 ] = F_83 ( V_13 , V_20 ,
V_21 , F_105 ( V_54 ) ) ;
V_13 -> V_17 [ V_54 ] = F_83 ( V_13 ,
V_20 , V_21 ,
F_22 ( V_54 ) ) ;
F_103 ( V_6 , V_54 ) ;
F_21 ( V_13 , V_20 , V_21 ,
F_23 ( V_54 ) ,
V_13 -> V_16 [ V_54 ] ) ;
}
if ( F_90 ( V_13 -> V_23 , V_54 ) )
V_13 -> V_22 [ V_54 ] = F_83 ( V_13 , V_20 ,
V_21 , F_29 ( V_54 ) ) ;
}
for ( V_54 = 0 ; V_54 < V_13 -> V_71 ; V_54 ++ ) {
V_13 -> V_28 [ V_54 ] = F_83 ( V_13 , V_29 , V_54 ,
V_112 ) ;
F_21 ( V_13 , V_29 , V_54 ,
V_112 ,
V_13 -> V_28 [ V_54 ] ) ;
if ( ( V_13 -> V_28 [ V_54 ] & V_119 ) == V_119 ) {
V_13 -> V_24 [ V_54 ] = F_83 ( V_13 , V_29 ,
V_54 , V_120 ) ;
}
if ( V_13 -> V_28 [ V_54 ] & V_113 ) {
V_13 -> V_26 [ V_54 ] = F_83 ( V_13 ,
V_29 , V_54 ,
V_30 ) ;
V_13 -> V_27 [ V_54 ] = F_83 ( V_13 ,
V_29 , V_54 ,
V_31 ) ;
if ( V_54 >= 11 )
V_13 -> V_38 [ V_54 - 11 ] =
F_83 ( V_13 , V_29 ,
V_54 , V_41 ) ;
}
}
if ( V_13 -> V_71 ) {
V_13 -> V_37 = F_83 ( V_13 , V_29 ,
V_21 , V_121 )
| ( ( F_83 ( V_13 , V_29 ,
V_21 , V_122 )
& 0x07 ) << 8 ) ;
V_13 -> V_35 = ( V_13 -> V_85 & 0xE0 ) ?
F_83 ( V_13 , V_29 ,
V_21 , V_123 ) : 0x1F ;
}
for ( V_54 = 0 ; V_54 < V_13 -> V_72 ; V_54 ++ ) {
V_13 -> V_47 [ V_54 ] = F_83 ( V_13 ,
V_48 , V_54 ,
V_114 ) ;
F_21 ( V_13 , V_48 , V_54 ,
V_114 ,
V_13 -> V_47 [ V_54 ] ) ;
if ( ( V_13 -> V_47 [ V_54 ] & V_119 ) == V_119 ) {
V_13 -> V_43 [ V_54 ] = F_83 ( V_13 ,
V_48 , V_54 ,
V_124 ) ;
}
if ( V_13 -> V_47 [ V_54 ] & V_113 ) {
V_13 -> V_44 [ V_54 ] = F_83 ( V_13 ,
V_48 , V_54 ,
V_39 ) ;
V_13 -> V_45 [ V_54 ] = F_83 ( V_13 ,
V_48 , V_54 ,
V_40 ) ;
V_13 -> V_46 [ V_54 ] = F_83 ( V_13 ,
V_48 , V_54 ,
V_41 ) ;
}
}
if ( V_13 -> V_72 ) {
V_13 -> V_49 = F_83 ( V_13 , V_48 ,
V_21 , V_125 )
& 0x3F ;
}
V_13 -> V_117 = V_116 ;
V_13 -> V_74 = 1 ;
}
F_24 ( & V_13 -> V_19 ) ;
return V_13 ;
}
static int T_4 F_106 ( unsigned short V_77 )
{
struct V_126 V_106 [ 3 ] ;
int V_66 , V_54 , V_127 ;
V_65 = F_107 ( L_10 , V_77 ) ;
if ( ! V_65 ) {
V_66 = - V_69 ;
F_108 ( L_41 ) ;
goto exit;
}
memset ( V_106 , 0 , 3 * sizeof( struct V_126 ) ) ;
V_127 = 0 ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( ! V_73 [ V_54 ] )
continue;
V_106 [ V_127 ] . V_128 = V_73 [ V_54 ] ;
V_106 [ V_127 ] . V_129 = V_73 [ V_54 ] + V_78 - 1 ;
V_106 [ V_127 ] . V_51 = L_10 ,
V_106 [ V_127 ] . V_130 = V_131 ,
V_66 = F_109 ( & V_106 [ V_127 ] ) ;
if ( V_66 )
goto V_132;
V_127 ++ ;
}
V_66 = F_110 ( V_65 , V_106 , V_127 ) ;
if ( V_66 ) {
F_108 ( L_42 , V_66 ) ;
goto V_132;
}
V_66 = F_111 ( V_65 ) ;
if ( V_66 ) {
F_108 ( L_43 , V_66 ) ;
goto V_132;
}
return 0 ;
V_132:
F_112 ( V_65 ) ;
exit:
return V_66 ;
}
static int T_4 F_113 ( void )
{
int V_66 , V_54 ;
unsigned short V_77 = 0 ;
if ( F_73 ( 0x2e , & V_52 , V_73 )
&& F_73 ( 0x4e , & V_52 , V_73 ) ) {
F_114 ( L_44 ) ;
return - V_58 ;
}
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
if ( V_73 [ V_54 ] != 0x0000 ) {
V_77 = V_73 [ V_54 ] ;
break;
}
}
if ( V_77 == 0x0000 ) {
F_114 ( L_45 ) ;
return - V_58 ;
}
V_66 = F_115 ( & V_79 ) ;
if ( V_66 )
goto exit;
V_66 = F_106 ( V_77 ) ;
if ( V_66 )
goto V_133;
return 0 ;
V_133:
F_116 ( & V_79 ) ;
exit:
return V_66 ;
}
static void T_8 F_117 ( void )
{
F_118 ( V_65 ) ;
F_116 ( & V_79 ) ;
}
