static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( ( F_2 ( V_2 , V_3 ) << 8 )
| F_2 ( V_2 , V_3 + 1 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
int V_5 = F_5 ( V_2 , V_3 , ( V_4 << 8 ) ) ;
if ( V_5 )
return;
F_5 ( V_2 , V_3 + 1 , ( V_4 & 0xFF ) ) ;
}
static struct V_6 * F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_10 ;
F_10 ( & V_9 -> V_11 ) ;
if ( F_11 ( V_12 , V_9 -> V_13 + 60 * V_14 )
|| ! V_9 -> V_15 ) {
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_9 -> V_16 [ V_10 ] =
F_1 ( V_2 , F_12 ( V_10 ) ) ;
V_9 -> V_17 [ V_10 ] =
F_1 ( V_2 , F_13 ( V_10 ) ) ;
V_9 -> V_18 [ V_10 ] =
F_3 ( V_2 , F_14 ( V_10 ) ) ;
V_9 -> V_19 [ V_10 ] =
F_3 ( V_2 , F_15 ( V_10 ) ) ;
V_9 -> V_20 [ V_10 ] =
F_3 ( V_2 , F_16 ( V_10 ) ) ;
V_9 -> V_21 [ V_10 ] = F_1 ( V_2 ,
F_17 ( V_10 ) ) ;
}
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_9 -> V_22 [ V_10 ] =
F_1 ( V_2 , F_18 ( V_10 ) ) ;
V_9 -> V_23 [ V_10 ] =
F_1 ( V_2 , F_19 ( V_10 ) ) ;
}
V_9 -> V_24 = F_1 ( V_2 , V_25 ) ;
V_9 -> V_13 = V_12 ;
}
if ( F_11 ( V_12 , V_9 -> V_26 + 2 * V_14 )
|| ! V_9 -> V_15 ) {
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_9 -> V_27 [ V_10 ] =
F_1 ( V_2 , F_20 ( V_10 ) ) ;
V_9 -> V_28 [ V_10 ] =
F_3 ( V_2 , F_21 ( V_10 ) ) ;
}
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
V_9 -> V_29 [ V_10 ] =
F_1 ( V_2 , F_22 ( V_10 ) ) ;
V_9 -> V_26 = V_12 ;
V_9 -> V_15 = 1 ;
}
F_23 ( & V_9 -> V_11 ) ;
return V_9 ;
}
static inline T_2 F_24 ( T_2 V_3 )
{
if ( V_3 == 0 || V_3 == 0xffff )
return 0 ;
return ( 1500000 / V_3 ) ;
}
static inline T_2 F_25 ( int V_30 )
{
if ( V_30 < 367 || V_30 > 0xffff )
return 0xffff ;
return ( 1500000 / V_30 ) ;
}
static T_3 F_26 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_19 [ V_10 ] = F_25 ( V_36 ) ;
F_6 ( V_2 , F_15 ( V_10 ) , V_9 -> V_19 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_29 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_20 [ V_10 ] = F_25 ( V_36 ) ;
F_6 ( V_2 , F_16 ( V_10 ) , V_9 -> V_20 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_30 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_21 [ V_10 ] = F_31 ( V_36 , 0 , 255 ) ;
F_4 ( V_2 , F_17 ( V_10 ) , V_9 -> V_21 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_32 ( struct V_7 * V_8 , struct V_31
* V_32 , char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , V_9 -> V_37 [ V_10 ] ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_10 , int V_36 )
{
struct V_6 * V_9 = F_9 ( V_2 ) ;
T_1 V_38 ;
if ( V_36 < 0 || V_36 > 4 )
return - V_39 ;
V_38 = F_1 ( V_2 , V_25 ) ;
V_38 &= ~ ( 3 << F_34 ( V_10 ) ) ;
switch ( V_36 ) {
case 0 :
V_38 |= ( 3 << F_34 ( V_10 ) ) ;
V_9 -> V_21 [ V_10 ] = 255 ;
F_4 ( V_2 , F_17 ( V_10 ) ,
V_9 -> V_21 [ V_10 ] ) ;
break;
case 1 :
V_38 |= ( 3 << F_34 ( V_10 ) ) ;
break;
case 2 :
V_38 |= ( 2 << F_34 ( V_10 ) ) ;
break;
case 3 :
break;
}
F_4 ( V_2 , V_25 , V_38 ) ;
V_9 -> V_37 [ V_10 ] = V_36 ;
return 0 ;
}
static T_3 F_35 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
int V_5 = 0 ;
F_10 ( & V_9 -> V_11 ) ;
V_5 = F_33 ( V_2 , V_10 , V_36 ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_5 ? V_5 : V_34 ;
}
static T_3 F_36 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
T_1 V_40 = 0 ;
if ( ! ( V_36 == 0 || V_36 == 1 ) )
return - V_39 ;
F_10 ( & V_9 -> V_11 ) ;
V_40 = F_1 ( V_2 , V_41 ) ;
V_40 &= ~ ( 1 << F_37 ( V_10 ) ) ;
if ( V_36 == 0 )
V_40 |= ( 1 << F_37 ( V_10 ) ) ;
F_4 ( V_2 , V_41 , V_40 ) ;
V_9 -> V_42 [ V_10 ] = V_36 ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_38 ( struct V_7 * V_8 , struct V_31
* V_32 , char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , V_9 -> V_21 [ V_10 ] ) ;
}
static T_3 F_39 ( struct V_7 * V_8 , struct V_31
* V_32 , char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , V_9 -> V_42 [ V_10 ] ) ;
}
static T_3 F_40 ( struct V_7 * V_8 , struct V_31 * V_32 ,
char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , F_41 ( V_9 -> V_29 [ V_10 ] ) ) ;
}
static T_3 F_42 ( struct V_7 * V_8 , struct V_31 * V_32 ,
char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , F_41 ( V_9 -> V_22 [ V_10 ] ) ) ;
}
static T_3 F_43 ( struct V_7 * V_8 , struct V_31 * V_32 ,
char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , F_41 ( V_9 -> V_23 [ V_10 ] ) ) ;
}
static T_3 F_44 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
V_36 = F_31 ( F_45 ( V_36 ) , 0 , 0xff ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_22 [ V_10 ] = V_36 ;
F_4 ( V_2 , F_18 ( V_10 ) , V_9 -> V_22 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_46 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_28 ( V_33 , NULL , 10 ) ;
V_36 = F_31 ( F_45 ( V_36 ) , 0 , 0xff ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_23 [ V_10 ] = V_36 ;
F_4 ( V_2 , F_19 ( V_10 ) , V_9 -> V_23 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_47 ( struct V_7 * V_8 , struct V_31 * V_32 ,
char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , F_48 ( V_9 -> V_27 [ V_10 ] ) ) ;
}
static T_3 F_49 ( struct V_7 * V_8 , struct V_31 * V_32 ,
char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , F_48 ( V_9 -> V_16 [ V_10 ] ) ) ;
}
static T_3 F_50 ( struct V_7 * V_8 ,
struct V_31 * V_32 , char * V_33 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_33 , L_1 , F_48 ( V_9 -> V_17 [ V_10 ] ) ) ;
}
static T_3 F_51 ( struct V_7 * V_8 , struct V_31 * V_32 ,
const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_52 ( V_33 , NULL , 10 ) ;
V_36 = F_31 ( F_53 ( V_36 ) , 0 , 127 ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_16 [ V_10 ] = V_36 ;
F_4 ( V_2 , F_12 ( V_10 ) , V_9 -> V_16 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static T_3 F_54 ( struct V_7 * V_8 ,
struct V_31 * V_32 , const char * V_33 , T_4 V_34 )
{
int V_10 = F_27 ( V_32 ) -> V_35 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
struct V_6 * V_9 = F_9 ( V_2 ) ;
int V_36 = F_52 ( V_33 , NULL , 10 ) ;
V_36 = F_31 ( F_53 ( V_36 ) , 0 , 127 ) ;
F_10 ( & V_9 -> V_11 ) ;
V_9 -> V_17 [ V_10 ] = V_36 ;
F_4 ( V_2 , F_13 ( V_10 ) ,
V_9 -> V_17 [ V_10 ] ) ;
F_23 ( & V_9 -> V_11 ) ;
return V_34 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_6 * V_9 ,
struct V_43 * V_44 )
{
int V_10 ;
F_33 ( V_2 , 0 , V_44 -> V_37 [ 0 ] ) ;
F_33 ( V_2 , 1 , V_44 -> V_37 [ 1 ] ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_9 -> V_21 [ V_10 ] = F_31 ( V_44 -> V_21 [ V_10 ] , 0 , 255 ) ;
F_4 ( V_2 , F_17 ( V_10 ) ,
V_9 -> V_21 [ V_10 ] ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_6 * V_9 ;
struct V_43 * V_44 = V_2 -> V_8 . V_47 ;
int V_5 ;
if ( ! F_57 ( V_2 -> V_48 ,
V_49 ) )
return - V_50 ;
if ( ! ( V_9 = F_58 ( sizeof( struct V_6 ) , V_51 ) ) )
return - V_52 ;
F_59 ( V_2 , V_9 ) ;
F_60 ( & V_9 -> V_11 ) ;
V_9 -> V_53 = V_46 -> V_54 ;
if ( ( V_5 = F_61 ( & V_2 -> V_8 . V_55 , & V_56 ) ) )
goto V_57;
if ( V_9 -> V_53 == V_58 ) {
V_5 = F_62 ( & V_2 -> V_8 . V_55 ,
& V_59 . V_60 . V_32 ,
V_61 | V_62 ) ;
if ( V_5 )
goto V_63;
V_5 = F_62 ( & V_2 -> V_8 . V_55 ,
& V_64 . V_60 . V_32 ,
V_61 | V_62 ) ;
if ( V_5 )
goto V_63;
}
V_9 -> V_65 = F_63 ( & V_2 -> V_8 ) ;
if ( F_64 ( V_9 -> V_65 ) ) {
V_5 = F_65 ( V_9 -> V_65 ) ;
goto V_63;
}
if ( V_44 != NULL )
F_55 ( V_2 , V_9 , V_44 ) ;
return 0 ;
V_63:
F_66 ( & V_2 -> V_8 . V_55 , & V_56 ) ;
V_57:
F_67 ( V_9 ) ;
return V_5 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_9 = F_9 ( V_2 ) ;
F_69 ( V_9 -> V_65 ) ;
F_66 ( & V_2 -> V_8 . V_55 , & V_56 ) ;
F_67 ( V_9 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_68 * V_48 = V_2 -> V_48 ;
T_2 V_69 , V_70 ;
T_1 V_71 ;
const char * V_72 ;
V_69 = F_3 ( V_2 , V_73 ) ;
V_70 = F_3 ( V_2 , V_74 ) ;
if ( V_70 == 0x0306 && V_69 == 0x1934 )
V_72 = L_2 ;
else if ( V_70 == 0x0204 && V_69 == 0x1934 )
V_72 = L_3 ;
else
return - V_75 ;
V_71 = F_1 ( V_2 , V_76 ) ;
F_71 ( & V_48 -> V_8 , L_4 , V_72 , V_71 ) ;
F_72 ( V_67 -> type , V_72 , V_77 ) ;
return 0 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_78 ) ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_78 ) ;
}
