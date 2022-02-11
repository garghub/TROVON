static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
unsigned V_4 = V_3 -> V_5 ;
F_2 ( V_3 -> V_6 . V_7 & V_8 ) ;
if ( V_3 -> V_6 . V_7 & V_9 )
memset ( V_3 -> V_10 , 0 , V_11 ) ;
switch ( V_3 -> V_6 . V_12 ) {
case - V_13 :
F_3 ( V_3 ) ;
return;
case - V_14 :
V_4 |= V_15 ;
goto V_16;
case - V_17 :
case - V_18 :
goto V_16;
case - V_19 :
V_4 |= V_20 ;
goto V_16;
case 0 :
break;
default:
F_4 () ;
}
V_4 = V_3 -> V_21 ;
if ( V_3 -> V_6 . V_7 & V_22 ) {
if ( V_3 -> V_21 == V_23 )
V_4 = V_24 ;
else if ( V_3 -> V_21 == V_24 )
V_4 = V_23 ;
else
F_4 () ;
}
F_5 ( V_25 , & V_3 -> V_26 ) ;
F_6 ( V_3 , V_4 ) ;
return;
V_16:
if ( ! F_7 ( V_25 , & V_3 -> V_26 ) )
V_3 -> V_6 . V_27 = 0 ;
F_6 ( V_3 , V_4 ) ;
}
static void F_8 ( void * V_1 , int V_28 )
{
struct V_2 * V_3 = V_1 ;
switch ( V_28 ) {
case V_29 :
F_9 ( V_3 , V_30 ) ;
break;
case V_31 :
F_9 ( V_3 , V_24 ) ;
break;
case V_32 :
F_9 ( V_3 , V_23 ) ;
break;
default:
F_10 ( V_33 L_1 , V_28 ) ;
F_4 () ;
}
}
static int F_11 ( const unsigned int V_34 )
{
switch ( V_34 ) {
case V_30 :
return V_35 ;
case V_36 :
return V_29 ;
case V_24 :
return V_31 ;
case V_23 :
return V_32 ;
}
F_10 ( V_33 L_2 , V_34 ) ;
F_4 () ;
return - 1 ;
}
static T_1 F_12 ( const T_1 V_37 , const unsigned int V_38 ,
const int V_39 )
{
T_1 V_40 = 0 ;
if ( V_38 & V_41 )
V_40 |= V_42 ;
if ( V_38 & V_43 ) {
V_40 |= V_42 ;
V_40 |= V_44 ;
}
if ( V_38 & V_45 ) {
V_40 |= V_46 ;
V_40 |= V_47 ;
}
if ( V_38 & V_48 ) {
if ( V_39 == V_32 )
V_40 |= V_49 ;
else if ( V_39 == V_31 )
V_40 |= V_50 ;
else
F_4 () ;
}
if ( V_37 != 0 )
V_40 |= V_51 ;
V_40 |= V_52 ;
return V_40 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned int V_53 ,
unsigned int V_54 )
{
struct V_55 * V_56 = & V_3 -> V_57 -> V_58 ;
int V_39 ;
T_1 V_40 ;
V_39 = F_11 ( V_53 ) ;
V_40 = F_12 ( V_3 -> V_6 . V_27 , V_54 , V_39 ) ;
return F_14 ( V_56 -> V_59 , V_39 , & V_3 -> V_6 , V_40 , V_3 -> V_60 ,
V_61 - 1 , 0 , F_1 , V_3 , F_8 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_62 * V_63 = V_3 -> V_57 ;
struct V_55 * V_56 = & V_63 -> V_58 ;
int error ;
if ( V_3 -> V_6 . V_27 == 0 ) {
F_3 ( V_3 ) ;
return;
}
error = F_16 ( V_56 -> V_59 , V_3 -> V_6 . V_27 , V_52 ,
NULL , V_3 ) ;
if ( error ) {
F_10 ( V_33 L_3 ,
V_3 -> V_64 . V_65 ,
( unsigned long long ) V_3 -> V_64 . V_66 , error ) ;
return;
}
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_55 * V_56 = & V_3 -> V_57 -> V_58 ;
F_16 ( V_56 -> V_59 , V_3 -> V_6 . V_27 , V_67 , NULL , V_3 ) ;
}
static int F_18 ( struct V_62 * V_63 , const char * V_68 )
{
struct V_55 * V_56 = & V_63 -> V_58 ;
int error ;
if ( V_68 == NULL ) {
F_19 ( V_63 , L_4 ) ;
return - V_69 ;
}
error = F_20 ( V_68 , strlen ( V_68 ) , & V_56 -> V_59 ,
V_70 | V_71 |
( V_56 -> V_72 ? V_73 : 0 ) ,
V_11 ) ;
if ( error )
F_10 ( V_33 L_5 , error ) ;
return error ;
}
static void F_21 ( struct V_62 * V_63 )
{
struct V_55 * V_56 = & V_63 -> V_58 ;
if ( V_56 -> V_59 ) {
F_22 ( V_56 -> V_59 , 2 ) ;
V_56 -> V_59 = NULL ;
}
}
