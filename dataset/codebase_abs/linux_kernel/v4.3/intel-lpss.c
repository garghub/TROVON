static int F_1 ( const char * V_1 )
{
static bool V_2 ;
if ( V_2 )
return 0 ;
V_2 = true ;
return F_2 ( L_1 , V_1 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
V_4 -> V_5 = F_4 ( V_4 -> V_6 + V_7 ) ;
V_4 -> V_8 = F_4 ( V_4 -> V_6 + V_9 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_10 * V_11 ;
V_11 = F_6 ( F_7 ( V_4 -> V_12 ) , V_13 ) ;
if ( F_8 ( V_11 ) )
return F_9 ( V_11 ) ;
F_3 ( V_4 ) ;
F_10 ( L_2 , V_14 , V_11 , & V_4 -> V_15 ) ;
F_10 ( L_3 , V_14 , V_11 , & V_4 -> V_5 ) ;
F_10 ( L_4 , V_14 , V_11 , & V_4 -> V_8 ) ;
V_4 -> V_16 = V_11 ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_16 ) ;
}
static void F_13 ( struct V_17 * V_12 , T_1 V_18 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
T_2 V_19 ;
V_19 = F_4 ( V_4 -> V_6 + V_7 ) ;
if ( V_18 == V_20 || V_18 < 0 ) {
V_19 &= ~ V_21 ;
} else {
V_19 |= V_21 ;
V_19 &= ~ V_22 ;
V_19 &= ~ V_23 ;
if ( V_18 > V_23 )
V_19 |= V_24 | V_18 >> 5 ;
else
V_19 |= V_25 | V_18 ;
}
if ( V_19 == V_4 -> V_5 )
return;
F_15 ( V_19 , V_4 -> V_6 + V_7 ) ;
F_15 ( V_19 , V_4 -> V_6 + V_9 ) ;
F_3 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
V_4 -> V_12 -> V_26 . V_27 = F_13 ;
F_17 ( V_4 -> V_12 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
F_19 ( V_4 -> V_12 ) ;
V_4 -> V_12 -> V_26 . V_27 = NULL ;
}
static int F_20 ( struct V_3 * V_4 )
{
unsigned int type ;
type = V_4 -> V_15 & V_28 ;
type >>= V_29 ;
switch ( type ) {
case V_30 :
V_4 -> V_31 = & V_32 ;
break;
case V_33 :
V_4 -> V_31 = & V_34 ;
break;
case V_35 :
V_4 -> V_31 = & V_36 ;
break;
default:
return - V_37 ;
}
V_4 -> type = type ;
return 0 ;
}
static bool F_21 ( const struct V_3 * V_4 )
{
return ( V_4 -> V_15 & V_38 ) == 0 ;
}
static void F_22 ( const struct V_3 * V_4 )
{
T_3 V_39 = V_4 -> V_40 -> V_41 -> V_42 ;
F_15 ( V_39 , V_4 -> V_6 + V_43 ) ;
#if V_44 > 32
F_15 ( V_39 >> 32 , V_4 -> V_6 + V_45 ) ;
#else
F_15 ( 0 , V_4 -> V_6 + V_45 ) ;
#endif
}
static void F_23 ( const struct V_3 * V_4 )
{
T_2 V_46 = V_47 | V_48 ;
F_15 ( V_46 , V_4 -> V_6 + V_49 ) ;
}
static void F_24 ( const struct V_3 * V_4 )
{
T_2 V_46 = V_50 ;
F_23 ( V_4 ) ;
if ( ! F_21 ( V_4 ) )
return;
F_22 ( V_4 ) ;
if ( V_4 -> type == V_35 )
F_15 ( V_46 , V_4 -> V_6 + V_51 ) ;
}
static void F_25 ( struct V_52 * V_52 )
{
struct V_52 * V_53 ;
while ( V_52 ) {
V_53 = F_26 ( V_52 ) ;
F_27 ( V_52 ) ;
V_52 = V_53 ;
}
}
static int F_28 ( struct V_3 * V_4 ,
const char * V_54 ,
struct V_52 * * V_52 )
{
char V_1 [ 32 ] ;
struct V_52 * V_55 = * V_52 ;
snprintf ( V_1 , sizeof( V_1 ) , L_5 , V_54 ) ;
V_55 = F_29 ( NULL , V_1 , F_30 ( V_55 ) , 0 ,
V_4 -> V_6 , 0 , 0 , NULL ) ;
if ( F_8 ( V_55 ) )
return F_9 ( V_55 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_6 , V_54 ) ;
V_55 = F_31 ( NULL , V_1 , F_30 ( V_55 ) ,
0 , V_4 -> V_6 , 1 , 15 , 16 , 15 , 0 ,
NULL ) ;
if ( F_8 ( V_55 ) )
return F_9 ( V_55 ) ;
* V_52 = V_55 ;
snprintf ( V_1 , sizeof( V_1 ) , L_7 , V_54 ) ;
V_55 = F_29 ( NULL , V_1 , F_30 ( V_55 ) ,
V_56 , V_4 -> V_6 , 31 , 0 , NULL ) ;
if ( F_8 ( V_55 ) )
return F_9 ( V_55 ) ;
* V_52 = V_55 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
const struct V_57 * V_31 = V_4 -> V_31 ;
struct V_52 * V_52 ;
char V_54 [ 24 ] ;
int V_58 ;
if ( ! V_4 -> V_40 -> V_59 )
return 0 ;
V_52 = F_33 ( NULL , F_7 ( V_4 -> V_12 ) , NULL ,
V_60 , V_4 -> V_40 -> V_59 ) ;
if ( F_8 ( V_52 ) )
return F_9 ( V_52 ) ;
snprintf ( V_54 , sizeof( V_54 ) , L_8 , V_31 -> V_1 , V_4 -> V_61 ) ;
if ( V_4 -> type != V_30 ) {
V_58 = F_28 ( V_4 , V_54 , & V_52 ) ;
if ( V_58 )
goto V_62;
}
V_58 = - V_63 ;
V_4 -> clock = F_34 ( V_52 , V_4 -> V_40 -> V_64 , L_1 , V_54 ) ;
if ( ! V_4 -> clock )
goto V_62;
V_4 -> V_52 = V_52 ;
return 0 ;
V_62:
F_25 ( V_52 ) ;
return V_58 ;
}
static void F_35 ( struct V_3 * V_4 )
{
if ( F_36 ( V_4 -> V_52 ) )
return;
F_37 ( V_4 -> clock ) ;
F_25 ( V_4 -> V_52 ) ;
}
int F_38 ( struct V_17 * V_12 ,
const struct V_65 * V_40 )
{
struct V_3 * V_4 ;
int V_58 ;
if ( ! V_40 || ! V_40 -> V_41 || V_40 -> V_66 <= 0 )
return - V_67 ;
V_4 = F_39 ( V_12 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
return - V_63 ;
V_4 -> V_6 = F_40 ( V_12 , V_40 -> V_41 -> V_42 + V_69 ,
V_70 ) ;
if ( ! V_4 -> V_6 )
return - V_63 ;
V_4 -> V_40 = V_40 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_15 = F_4 ( V_4 -> V_6 + V_71 ) ;
F_41 ( V_12 , V_4 ) ;
V_58 = F_20 ( V_4 ) ;
if ( V_58 )
return V_58 ;
F_24 ( V_4 ) ;
V_4 -> V_61 = F_42 ( & V_72 , 0 , 0 , V_68 ) ;
if ( V_4 -> V_61 < 0 )
return V_4 -> V_61 ;
V_58 = F_32 ( V_4 ) ;
if ( V_58 )
goto V_62;
F_16 ( V_4 ) ;
V_58 = F_5 ( V_4 ) ;
if ( V_58 )
F_43 ( V_12 , L_9 ) ;
if ( F_21 ( V_4 ) ) {
F_1 ( V_73 ) ;
V_58 = F_44 ( V_12 , V_4 -> V_61 , & V_74 ,
1 , V_40 -> V_41 , V_40 -> V_66 , NULL ) ;
if ( V_58 )
F_43 ( V_12 , L_10 ,
V_73 ) ;
}
V_58 = F_44 ( V_12 , V_4 -> V_61 , V_4 -> V_31 ,
1 , V_40 -> V_41 , V_40 -> V_66 , NULL ) ;
if ( V_58 )
goto V_75;
return 0 ;
V_75:
F_11 ( V_4 ) ;
F_18 ( V_4 ) ;
V_62:
F_45 ( & V_72 , V_4 -> V_61 ) ;
return V_58 ;
}
void F_46 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
F_47 ( V_12 ) ;
F_11 ( V_4 ) ;
F_18 ( V_4 ) ;
F_35 ( V_4 ) ;
F_45 ( & V_72 , V_4 -> V_61 ) ;
}
static int F_48 ( struct V_17 * V_12 , void * V_76 )
{
F_49 ( V_12 ) ;
return 0 ;
}
int F_50 ( struct V_17 * V_12 )
{
F_51 ( V_12 , NULL , F_48 ) ;
return 0 ;
}
int F_52 ( struct V_17 * V_12 )
{
return 0 ;
}
int F_53 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static int T_4 F_54 ( void )
{
V_13 = F_6 ( L_11 , NULL ) ;
return 0 ;
}
static void T_5 F_55 ( void )
{
F_56 ( V_13 ) ;
}
