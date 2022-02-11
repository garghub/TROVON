static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_3 ( & V_7 -> V_8 . V_9 , L_1 , V_10 ,
__LINE__ , V_2 -> V_11 , V_2 -> V_12 , V_2 -> V_13 ) ;
V_2 -> V_14 = 1 ;
V_2 -> V_15 = 1 ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_18 V_19 ;
unsigned char V_20 = V_17 -> V_21 [ 0 ] ;
int V_22 ;
T_1 V_23 ;
F_3 ( & V_7 -> V_8 . V_9 , L_2 , V_10 ,
__LINE__ , V_20 ) ;
memset ( & V_19 , 0 , sizeof( struct V_18 ) ) ;
memcpy ( & V_19 . V_24 , V_17 -> V_21 , 12 ) ;
V_19 . V_25 = 12 ;
V_19 . V_26 = 1 ;
V_19 . V_27 = V_19 . V_28 = F_5 ( V_17 ) ;
V_19 . V_29 = V_7 -> V_30 ;
switch ( V_17 -> V_31 ) {
case V_32 :
if ( F_5 ( V_17 ) >= V_33 )
V_19 . V_34 = V_35 ;
else
V_19 . V_34 = V_36 ;
V_19 . V_37 = V_38 ;
break;
case V_39 :
if ( F_5 ( V_17 ) >= V_33 )
V_19 . V_34 = V_35 ;
else
V_19 . V_34 = V_40 ;
V_19 . V_37 = V_41 ;
F_6 ( V_17 , V_7 -> V_42 , V_7 -> V_43 ) ;
break;
default:
V_19 . V_34 = V_44 ;
break;
}
V_23 = F_7 ( F_8 ( & V_19 ) ) ;
V_22 = F_9 ( V_7 -> V_8 . V_45 ,
V_46 ,
V_23 , sizeof( V_19 ) ,
V_19 . V_29 ,
V_19 . V_28 , & V_7 -> V_47 ) ;
if ( V_22 == V_48 ) {
F_3 ( & V_7 -> V_8 . V_9 ,
L_3 ,
V_10 , __LINE__ , V_20 ) ;
return V_49 << 16 ;
}
if ( V_22 ) {
F_10 ( & V_7 -> V_8 . V_9 ,
L_4 , V_10 ,
__LINE__ , V_20 , V_22 ) ;
return V_49 << 16 ;
}
return 0 ;
}
static inline unsigned int F_11 ( const struct V_16 * V_17 )
{
return V_17 -> V_21 [ 2 ] << 24 | V_17 -> V_21 [ 3 ] << 16 | V_17 -> V_21 [ 4 ] << 8 |
V_17 -> V_21 [ 5 ] ;
}
static inline unsigned int F_12 ( const struct V_16 * V_17 )
{
return V_17 -> V_21 [ 7 ] << 8 | V_17 -> V_21 [ 8 ] ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_16 * V_17 , T_2 V_50 ,
T_2 V_51 )
{
int V_22 ;
F_3 ( & V_7 -> V_8 . V_9 , L_5 ,
V_10 , __LINE__ , V_51 , V_50 ) ;
V_22 = F_14 ( V_7 -> V_8 . V_45 ,
V_7 -> V_52 [ V_7 -> V_53 ] . V_11 , V_50 ,
V_51 , 0 , V_7 -> V_30 , & V_7 -> V_47 ) ;
if ( V_22 ) {
F_10 ( & V_7 -> V_8 . V_9 , L_6 , V_10 ,
__LINE__ , V_22 ) ;
return V_49 << 16 ;
}
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_16 * V_17 , T_2 V_50 ,
T_2 V_51 )
{
int V_22 ;
F_3 ( & V_7 -> V_8 . V_9 , L_7 ,
V_10 , __LINE__ , V_51 , V_50 ) ;
F_6 ( V_17 , V_7 -> V_42 , V_7 -> V_43 ) ;
V_22 = F_16 ( V_7 -> V_8 . V_45 ,
V_7 -> V_52 [ V_7 -> V_53 ] . V_11 , V_50 ,
V_51 , 0 , V_7 -> V_30 , & V_7 -> V_47 ) ;
if ( V_22 ) {
F_10 ( & V_7 -> V_8 . V_9 , L_8 , V_10 ,
__LINE__ , V_22 ) ;
return V_49 << 16 ;
}
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
void (* F_18)( struct V_16 * ) )
{
struct V_3 * V_4 = F_2 ( V_17 -> V_54 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned char V_20 ;
int V_22 ;
#ifdef F_19
F_20 ( V_17 ) ;
#endif
V_4 -> V_55 = V_17 ;
V_17 -> V_56 = F_18 ;
V_20 = V_17 -> V_21 [ 0 ] ;
switch ( V_20 ) {
case V_57 :
V_22 = F_13 ( V_7 , V_17 , F_11 ( V_17 ) ,
F_12 ( V_17 ) ) ;
break;
case V_58 :
V_22 = F_15 ( V_7 , V_17 , F_11 ( V_17 ) ,
F_12 ( V_17 ) ) ;
break;
default:
V_22 = F_4 ( V_7 , V_17 ) ;
break;
}
if ( V_22 ) {
memset ( V_17 -> V_59 , 0 , V_60 ) ;
V_17 -> V_61 = V_22 ;
V_17 -> V_59 [ 0 ] = 0x70 ;
V_17 -> V_59 [ 2 ] = V_62 ;
V_4 -> V_55 = NULL ;
V_17 -> V_56 ( V_17 ) ;
}
return 0 ;
}
T_3 F_21 ( int V_63 , void * V_64 )
{
struct V_6 * V_7 = V_64 ;
struct V_65 * V_5 ;
struct V_3 * V_4 ;
struct V_16 * V_17 ;
int V_22 ;
T_1 V_47 , V_66 ;
unsigned char V_67 , V_68 , V_69 ;
V_22 = F_22 ( V_7 -> V_8 . V_45 , & V_47 , & V_66 ) ;
if ( V_47 != V_7 -> V_47 )
F_10 ( & V_7 -> V_8 . V_9 ,
L_9 ,
V_10 , __LINE__ , V_47 , V_7 -> V_47 ) ;
if ( V_22 ) {
F_10 ( & V_7 -> V_8 . V_9 , L_10 ,
V_10 , __LINE__ , V_22 , V_66 ) ;
return V_70 ;
}
V_5 = F_23 ( & V_7 -> V_8 ) ;
V_4 = F_2 ( V_5 ) ;
V_17 = V_4 -> V_55 ;
if ( ! V_66 ) {
if ( V_17 -> V_31 == V_32 ) {
int V_71 ;
V_71 = F_24 ( V_17 ,
V_7 -> V_42 ,
V_7 -> V_43 ) ;
F_25 ( V_17 , F_5 ( V_17 ) - V_71 ) ;
}
V_17 -> V_61 = V_72 << 16 ;
goto F_18;
}
if ( V_17 -> V_21 [ 0 ] == V_73 ) {
F_10 ( & V_7 -> V_8 . V_9 , L_11 ,
V_10 , __LINE__ ) ;
V_17 -> V_61 = V_49 << 16 | V_74 ;
goto F_18;
}
if ( F_26 ( V_66 , & V_67 , & V_68 , & V_69 ) ) {
V_17 -> V_61 = V_49 << 16 ;
goto F_18;
}
F_27 ( 0 , V_17 -> V_59 , V_67 , V_68 , V_69 ) ;
V_17 -> V_61 = V_74 ;
F_18:
V_4 -> V_55 = NULL ;
V_17 -> V_56 ( V_17 ) ;
return V_70 ;
}
static int F_28 ( struct V_75 * V_76 )
{
struct V_6 * V_7 = F_29 ( & V_76 -> V_9 ) ;
int error ;
struct V_65 * V_5 ;
struct V_3 * V_4 ;
if ( V_7 -> V_77 != V_33 ) {
F_10 ( & V_7 -> V_8 . V_9 ,
L_12 , V_10 ,
__LINE__ , V_7 -> V_77 ) ;
return - V_78 ;
}
V_7 -> V_43 = V_79 ;
V_7 -> V_42 = F_30 ( V_79 , V_80 ) ;
if ( ! V_7 -> V_42 )
return - V_81 ;
error = F_31 ( V_7 , F_21 ) ;
if ( error )
goto V_82;
V_5 = F_32 ( & V_83 ,
sizeof( struct V_3 ) ) ;
if ( ! V_5 ) {
F_10 ( & V_7 -> V_8 . V_9 , L_13 ,
V_10 , __LINE__ ) ;
goto V_84;
}
V_4 = F_2 ( V_5 ) ;
F_33 ( & V_7 -> V_8 , V_5 ) ;
V_4 -> V_7 = V_7 ;
V_5 -> V_85 = 1 ;
V_5 -> V_86 = 1 ;
error = F_34 ( V_5 , & V_7 -> V_8 . V_9 ) ;
if ( error ) {
F_10 ( & V_7 -> V_8 . V_9 , L_14 ,
V_10 , __LINE__ , error ) ;
error = - V_87 ;
goto V_88;
}
F_35 ( V_5 ) ;
return 0 ;
V_88:
F_36 ( V_5 ) ;
F_33 ( & V_7 -> V_8 , NULL ) ;
V_84:
F_37 ( V_7 ) ;
V_82:
F_38 ( V_7 -> V_42 ) ;
return error ;
}
static int F_39 ( struct V_75 * V_76 )
{
struct V_6 * V_7 = F_29 ( & V_76 -> V_9 ) ;
struct V_65 * V_5 = F_23 ( & V_7 -> V_8 ) ;
F_40 ( V_5 ) ;
F_37 ( V_7 ) ;
F_36 ( V_5 ) ;
F_33 ( & V_7 -> V_8 , NULL ) ;
F_38 ( V_7 -> V_42 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_89 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_89 ) ;
}
