static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
union {
T_2 V_5 ;
T_1 V_6 [ 4 ] ;
} V_7 ;
V_7 . V_5 = F_2 ( V_8 |
F_3 ( V_3 ) |
( V_4 & V_9 ) ) ;
return F_4 ( V_2 , & V_7 . V_6 [ 1 ] , 3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
union {
T_2 V_5 ;
T_1 V_6 [ 4 ] ;
} V_7 [ 3 ] ;
int V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 [] = {
{
. V_15 = & V_7 [ 0 ] . V_6 [ 1 ] ,
. V_16 = 8 ,
. V_17 = 3 ,
. V_18 = 1 ,
} , {
. V_15 = & V_7 [ 1 ] . V_6 [ 1 ] ,
. V_19 = & V_7 [ 2 ] . V_6 [ 1 ] ,
. V_16 = 8 ,
. V_17 = 3 ,
} ,
} ;
V_7 [ 0 ] . V_5 = F_2 ( V_20 |
F_3 ( V_3 ) ) ;
V_7 [ 1 ] . V_5 = F_2 ( F_3 ( V_21 ) ) ;
F_6 ( & V_12 ) ;
F_7 ( & V_14 [ 0 ] , & V_12 ) ;
F_7 ( & V_14 [ 1 ] , & V_12 ) ;
V_10 = F_8 ( V_2 , & V_12 ) ;
* V_4 = F_9 ( V_7 [ 2 ] . V_5 ) ;
return V_10 ;
}
static T_3 F_10 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_17 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
struct V_31 * V_32 = F_13 ( V_25 ) ;
long V_33 ;
int V_10 ;
V_10 = F_14 ( V_26 , 10 , & V_33 ) ;
if ( V_10 )
return V_10 ;
V_33 += ( 1 << ( V_30 -> V_34 -> V_35 - 1 ) ) ;
V_33 &= F_15 ( V_30 -> V_34 -> V_35 ) ;
V_33 <<= V_30 -> V_34 -> V_36 ;
V_10 = F_1 ( V_30 -> V_2 , V_32 -> V_37 , V_33 ) ;
return V_10 ? V_10 : V_17 ;
}
static T_3 F_16 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
struct V_31 * V_32 = F_13 ( V_25 ) ;
int V_10 ;
int V_4 ;
V_10 = F_5 ( V_30 -> V_2 , V_32 -> V_37 , & V_4 ) ;
if ( V_10 )
return V_10 ;
V_4 &= V_9 ;
V_4 >>= V_30 -> V_34 -> V_36 ;
V_4 -= ( 1 << ( V_30 -> V_34 -> V_35 - 1 ) ) ;
return sprintf ( V_26 , L_1 , V_4 ) ;
}
static T_3 F_17 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
const char V_38 [] [ 14 ] = { L_2 , L_3 } ;
return sprintf ( V_26 , L_4 , V_38 [ V_30 -> V_39 ] ) ;
}
static T_3 F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_17 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
int V_10 ;
if ( F_19 ( V_26 , L_2 ) )
V_30 -> V_39 = V_40 ;
else if ( F_19 ( V_26 , L_3 ) )
V_30 -> V_39 = V_41 ;
else
V_10 = - V_42 ;
return V_10 ? V_10 : V_17 ;
}
static T_3 F_20 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
return sprintf ( V_26 , L_1 , V_30 -> V_43 ) ;
}
static T_3 F_21 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_17 )
{
long V_33 ;
int V_10 ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
V_10 = F_14 ( V_26 , 10 , & V_33 ) ;
if ( V_10 )
return V_10 ;
if ( V_33 == 0 ) {
V_30 -> V_43 = false ;
V_30 -> V_44 &= ~ ( V_45 | V_46 ) ;
} else if ( V_33 == 1 ) {
V_30 -> V_43 = true ;
if ( V_30 -> V_39 == V_40 )
V_30 -> V_44 |= V_45 ;
else if ( V_30 -> V_39 == V_41 )
V_30 -> V_44 |= V_46 ;
} else
V_10 = - V_42 ;
V_10 = F_1 ( V_30 -> V_2 , V_47 , V_30 -> V_44 ) ;
return V_10 ? V_10 : V_17 ;
}
static T_3 F_22 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
unsigned int V_48 = ( V_30 -> V_49 * 1000 ) >> V_30 -> V_34 -> V_35 ;
return sprintf ( V_26 , L_5 , V_48 / 1000 , V_48 % 1000 ) ;
}
static T_3 F_23 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
return sprintf ( V_26 , L_4 , F_24 ( V_30 -> V_2 ) -> V_50 ) ;
}
static int F_25 ( unsigned int V_51 )
{
if ( V_51 <= 10000 )
return V_52 ;
else if ( V_51 <= 12000 )
return V_53 ;
else if ( V_51 <= 16000 )
return V_54 ;
else if ( V_51 <= 19000 )
return V_55 ;
else
return V_56 ;
}
static int F_26 ( unsigned int V_51 )
{
if ( V_51 <= 10000 )
return V_57 ;
else
return V_58 ;
}
static int T_5 F_27 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_23 . V_61 ;
struct V_27 * V_28 ;
struct V_62 * V_63 , * V_64 ;
struct V_29 * V_30 ;
int V_10 , V_65 = 0 , V_66 = 0 ;
V_63 = F_28 ( & V_2 -> V_23 , L_6 ) ;
if ( ! F_29 ( V_63 ) ) {
V_10 = F_30 ( V_63 ) ;
if ( V_10 )
goto V_67;
V_65 = F_31 ( V_63 ) ;
}
V_64 = F_28 ( & V_2 -> V_23 , L_7 ) ;
if ( ! F_29 ( V_64 ) ) {
V_10 = F_30 ( V_64 ) ;
if ( V_10 )
goto V_68;
V_66 = F_31 ( V_64 ) ;
}
V_28 = F_32 ( sizeof( * V_30 ) ) ;
if ( V_28 == NULL ) {
V_10 = - V_69 ;
goto V_70;
}
V_30 = F_12 ( V_28 ) ;
V_30 -> V_43 = true ;
V_30 -> V_2 = V_2 ;
if ( ! F_29 ( V_64 ) && ! F_29 ( V_63 ) )
V_30 -> V_49 = ( V_65 - V_66 ) / 1000 ;
else if ( V_60 )
V_30 -> V_49 = V_60 -> V_71 - V_60 -> V_72 ;
else
F_33 ( & V_2 -> V_23 , L_8 ) ;
V_10 = F_1 ( V_2 , V_73 , V_74 ) ;
if ( V_10 )
goto V_75;
V_30 -> V_34 =
& V_76 [ F_24 ( V_2 ) -> V_77 ] ;
V_30 -> V_44 = F_34 ( V_30 -> V_34 -> V_78 ( V_30 -> V_49 ) )
| ( ( V_60 && V_60 -> V_79 ) ? 0 : V_80 ) |
V_81 ;
V_10 = F_1 ( V_2 , V_47 , V_30 -> V_44 |
V_45 | V_46 ) ;
if ( V_10 )
goto V_75;
V_30 -> V_63 = V_63 ;
V_30 -> V_64 = V_64 ;
F_35 ( V_2 , V_28 ) ;
V_28 -> V_23 . V_82 = & V_2 -> V_23 ;
V_28 -> V_83 = & V_84 ;
V_28 -> V_85 = V_86 ;
V_10 = F_36 ( V_28 ) ;
if ( V_10 )
goto V_75;
return 0 ;
V_75:
F_37 ( V_28 ) ;
V_70:
if ( ! F_29 ( V_64 ) )
F_38 ( V_64 ) ;
V_68:
if ( ! F_29 ( V_64 ) )
F_39 ( V_64 ) ;
if ( ! F_29 ( V_63 ) )
F_38 ( V_63 ) ;
V_67:
if ( ! F_29 ( V_63 ) )
F_39 ( V_63 ) ;
V_87:
return V_10 ;
}
static int T_6 F_40 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_41 ( V_2 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
struct V_62 * V_63 = V_30 -> V_63 ;
struct V_62 * V_64 = V_30 -> V_64 ;
F_42 ( V_28 ) ;
if ( ! F_29 ( V_30 -> V_63 ) ) {
F_38 ( V_63 ) ;
F_39 ( V_63 ) ;
}
if ( ! F_29 ( V_30 -> V_64 ) ) {
F_38 ( V_64 ) ;
F_39 ( V_64 ) ;
}
return 0 ;
}
static T_7 int F_43 ( void )
{
return F_44 ( & V_88 ) ;
}
static T_8 void F_45 ( void )
{
F_46 ( & V_88 ) ;
}
