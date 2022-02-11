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
F_23 ( V_39 , V_4 -> V_6 + V_43 ) ;
}
static void F_24 ( const struct V_3 * V_4 )
{
T_2 V_44 = V_45 | V_46 ;
F_15 ( V_44 , V_4 -> V_6 + V_47 ) ;
}
static void F_25 ( const struct V_3 * V_4 )
{
T_2 V_44 = V_48 ;
F_24 ( V_4 ) ;
if ( ! F_21 ( V_4 ) )
return;
F_22 ( V_4 ) ;
if ( V_4 -> type == V_35 )
F_15 ( V_44 , V_4 -> V_6 + V_49 ) ;
}
static void F_26 ( struct V_50 * V_50 )
{
struct V_50 * V_51 ;
while ( V_50 ) {
V_51 = F_27 ( V_50 ) ;
F_28 ( V_50 ) ;
V_50 = V_51 ;
}
}
static int F_29 ( struct V_3 * V_4 ,
const char * V_52 ,
struct V_50 * * V_50 )
{
char V_1 [ 32 ] ;
struct V_50 * V_53 = * V_50 ;
snprintf ( V_1 , sizeof( V_1 ) , L_5 , V_52 ) ;
V_53 = F_30 ( NULL , V_1 , F_31 ( V_53 ) , 0 ,
V_4 -> V_6 , 0 , 0 , NULL ) ;
if ( F_8 ( V_53 ) )
return F_9 ( V_53 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_6 , V_52 ) ;
V_53 = F_32 ( NULL , V_1 , F_31 ( V_53 ) ,
0 , V_4 -> V_6 , 1 , 15 , 16 , 15 , 0 ,
NULL ) ;
if ( F_8 ( V_53 ) )
return F_9 ( V_53 ) ;
* V_50 = V_53 ;
snprintf ( V_1 , sizeof( V_1 ) , L_7 , V_52 ) ;
V_53 = F_30 ( NULL , V_1 , F_31 ( V_53 ) ,
V_54 , V_4 -> V_6 , 31 , 0 , NULL ) ;
if ( F_8 ( V_53 ) )
return F_9 ( V_53 ) ;
* V_50 = V_53 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
const struct V_55 * V_31 = V_4 -> V_31 ;
struct V_50 * V_50 ;
char V_52 [ 24 ] ;
int V_56 ;
if ( ! V_4 -> V_40 -> V_57 )
return 0 ;
V_50 = F_34 ( NULL , F_7 ( V_4 -> V_12 ) , NULL ,
V_58 , V_4 -> V_40 -> V_57 ) ;
if ( F_8 ( V_50 ) )
return F_9 ( V_50 ) ;
snprintf ( V_52 , sizeof( V_52 ) , L_8 , V_31 -> V_1 , V_4 -> V_59 ) ;
if ( V_4 -> type != V_30 ) {
V_56 = F_29 ( V_4 , V_52 , & V_50 ) ;
if ( V_56 )
goto V_60;
}
V_56 = - V_61 ;
V_4 -> clock = F_35 ( V_50 , V_4 -> V_40 -> V_62 , L_1 , V_52 ) ;
if ( ! V_4 -> clock )
goto V_60;
V_4 -> V_50 = V_50 ;
return 0 ;
V_60:
F_26 ( V_50 ) ;
return V_56 ;
}
static void F_36 ( struct V_3 * V_4 )
{
if ( F_37 ( V_4 -> V_50 ) )
return;
F_38 ( V_4 -> clock ) ;
F_26 ( V_4 -> V_50 ) ;
}
int F_39 ( struct V_17 * V_12 ,
const struct V_63 * V_40 )
{
struct V_3 * V_4 ;
int V_56 ;
if ( ! V_40 || ! V_40 -> V_41 || V_40 -> V_64 <= 0 )
return - V_65 ;
V_4 = F_40 ( V_12 , sizeof( * V_4 ) , V_66 ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_6 = F_41 ( V_12 , V_40 -> V_41 -> V_42 + V_67 ,
V_68 ) ;
if ( ! V_4 -> V_6 )
return - V_61 ;
V_4 -> V_40 = V_40 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_15 = F_4 ( V_4 -> V_6 + V_69 ) ;
F_42 ( V_12 , V_4 ) ;
V_56 = F_20 ( V_4 ) ;
if ( V_56 )
return V_56 ;
F_25 ( V_4 ) ;
V_4 -> V_59 = F_43 ( & V_70 , 0 , 0 , V_66 ) ;
if ( V_4 -> V_59 < 0 )
return V_4 -> V_59 ;
V_56 = F_33 ( V_4 ) ;
if ( V_56 )
goto V_60;
F_16 ( V_4 ) ;
V_56 = F_5 ( V_4 ) ;
if ( V_56 )
F_44 ( V_12 , L_9 ) ;
if ( F_21 ( V_4 ) ) {
F_1 ( V_71 ) ;
V_56 = F_45 ( V_12 , V_4 -> V_59 , & V_72 ,
1 , V_40 -> V_41 , V_40 -> V_64 , NULL ) ;
if ( V_56 )
F_44 ( V_12 , L_10 ,
V_71 ) ;
}
V_56 = F_45 ( V_12 , V_4 -> V_59 , V_4 -> V_31 ,
1 , V_40 -> V_41 , V_40 -> V_64 , NULL ) ;
if ( V_56 )
goto V_73;
return 0 ;
V_73:
F_11 ( V_4 ) ;
F_18 ( V_4 ) ;
V_60:
F_46 ( & V_70 , V_4 -> V_59 ) ;
return V_56 ;
}
void F_47 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
F_48 ( V_12 ) ;
F_11 ( V_4 ) ;
F_18 ( V_4 ) ;
F_36 ( V_4 ) ;
F_46 ( & V_70 , V_4 -> V_59 ) ;
}
static int F_49 ( struct V_17 * V_12 , void * V_74 )
{
F_50 ( V_12 ) ;
return 0 ;
}
int F_51 ( struct V_17 * V_12 )
{
F_52 ( V_12 , NULL , F_49 ) ;
return 0 ;
}
int F_53 ( struct V_17 * V_12 )
{
return 0 ;
}
int F_54 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
V_13 = F_6 ( L_11 , NULL ) ;
return 0 ;
}
static void T_5 F_56 ( void )
{
F_57 ( V_13 ) ;
}
