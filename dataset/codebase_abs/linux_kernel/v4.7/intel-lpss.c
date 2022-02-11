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
const struct V_28 * V_29 ;
unsigned int type ;
type = V_4 -> V_15 & V_30 ;
type >>= V_31 ;
switch ( type ) {
case V_32 :
V_29 = & V_33 ;
break;
case V_34 :
V_29 = & V_35 ;
break;
case V_36 :
V_29 = & V_37 ;
break;
default:
return - V_38 ;
}
V_4 -> V_29 = F_21 ( V_4 -> V_12 , V_29 , sizeof( * V_29 ) , V_39 ) ;
if ( ! V_4 -> V_29 )
return - V_40 ;
V_4 -> type = type ;
return 0 ;
}
static bool F_22 ( const struct V_3 * V_4 )
{
return ( V_4 -> V_15 & V_41 ) == 0 ;
}
static void F_23 ( const struct V_3 * V_4 )
{
T_3 V_42 = V_4 -> V_43 -> V_44 -> V_45 ;
F_24 ( V_42 , V_4 -> V_6 + V_46 ) ;
}
static void F_25 ( const struct V_3 * V_4 )
{
T_2 V_47 = V_48 | V_49 ;
F_15 ( V_47 , V_4 -> V_6 + V_50 ) ;
}
static void F_26 ( const struct V_3 * V_4 )
{
T_2 V_47 = V_51 ;
F_25 ( V_4 ) ;
if ( ! F_22 ( V_4 ) )
return;
F_23 ( V_4 ) ;
if ( V_4 -> type == V_36 )
F_15 ( V_47 , V_4 -> V_6 + V_52 ) ;
}
static void F_27 ( struct V_53 * V_53 )
{
struct V_53 * V_54 ;
while ( V_53 ) {
V_54 = F_28 ( V_53 ) ;
F_29 ( V_53 ) ;
V_53 = V_54 ;
}
}
static int F_30 ( struct V_3 * V_4 ,
const char * V_55 ,
struct V_53 * * V_53 )
{
char V_1 [ 32 ] ;
struct V_53 * V_56 = * V_53 ;
snprintf ( V_1 , sizeof( V_1 ) , L_5 , V_55 ) ;
V_56 = F_31 ( NULL , V_1 , F_32 ( V_56 ) , 0 ,
V_4 -> V_6 , 0 , 0 , NULL ) ;
if ( F_8 ( V_56 ) )
return F_9 ( V_56 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_6 , V_55 ) ;
V_56 = F_33 ( NULL , V_1 , F_32 ( V_56 ) ,
0 , V_4 -> V_6 , 1 , 15 , 16 , 15 , 0 ,
NULL ) ;
if ( F_8 ( V_56 ) )
return F_9 ( V_56 ) ;
* V_53 = V_56 ;
snprintf ( V_1 , sizeof( V_1 ) , L_7 , V_55 ) ;
V_56 = F_31 ( NULL , V_1 , F_32 ( V_56 ) ,
V_57 , V_4 -> V_6 , 31 , 0 , NULL ) ;
if ( F_8 ( V_56 ) )
return F_9 ( V_56 ) ;
* V_53 = V_56 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
const struct V_28 * V_29 = V_4 -> V_29 ;
struct V_53 * V_53 ;
char V_55 [ 24 ] ;
int V_58 ;
if ( ! V_4 -> V_43 -> V_59 )
return 0 ;
V_53 = F_35 ( NULL , F_7 ( V_4 -> V_12 ) , NULL , 0 ,
V_4 -> V_43 -> V_59 ) ;
if ( F_8 ( V_53 ) )
return F_9 ( V_53 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_8 , V_29 -> V_1 , V_4 -> V_60 ) ;
if ( V_4 -> type != V_32 ) {
V_58 = F_30 ( V_4 , V_55 , & V_53 ) ;
if ( V_58 )
goto V_61;
}
V_58 = - V_40 ;
V_4 -> clock = F_36 ( V_53 , V_4 -> V_43 -> V_62 , L_1 , V_55 ) ;
if ( ! V_4 -> clock )
goto V_61;
V_4 -> V_53 = V_53 ;
return 0 ;
V_61:
F_27 ( V_53 ) ;
return V_58 ;
}
static void F_37 ( struct V_3 * V_4 )
{
if ( F_38 ( V_4 -> V_53 ) )
return;
F_39 ( V_4 -> clock ) ;
F_27 ( V_4 -> V_53 ) ;
}
int F_40 ( struct V_17 * V_12 ,
const struct V_63 * V_43 )
{
struct V_3 * V_4 ;
int V_58 ;
if ( ! V_43 || ! V_43 -> V_44 || V_43 -> V_64 <= 0 )
return - V_65 ;
V_4 = F_41 ( V_12 , sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 )
return - V_40 ;
V_4 -> V_6 = F_42 ( V_12 , V_43 -> V_44 -> V_45 + V_66 ,
V_67 ) ;
if ( ! V_4 -> V_6 )
return - V_40 ;
V_4 -> V_43 = V_43 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_15 = F_4 ( V_4 -> V_6 + V_68 ) ;
F_43 ( V_12 , V_4 ) ;
V_58 = F_20 ( V_4 ) ;
if ( V_58 )
return V_58 ;
V_4 -> V_29 -> V_69 = V_43 -> V_69 ;
F_26 ( V_4 ) ;
V_4 -> V_60 = F_44 ( & V_70 , 0 , 0 , V_39 ) ;
if ( V_4 -> V_60 < 0 )
return V_4 -> V_60 ;
V_58 = F_34 ( V_4 ) ;
if ( V_58 )
goto V_61;
F_16 ( V_4 ) ;
V_58 = F_5 ( V_4 ) ;
if ( V_58 )
F_45 ( V_12 , L_9 ) ;
if ( F_22 ( V_4 ) ) {
F_1 ( V_71 ) ;
V_58 = F_46 ( V_12 , V_4 -> V_60 , & V_72 ,
1 , V_43 -> V_44 , V_43 -> V_64 , NULL ) ;
if ( V_58 )
F_45 ( V_12 , L_10 ,
V_71 ) ;
}
V_58 = F_46 ( V_12 , V_4 -> V_60 , V_4 -> V_29 ,
1 , V_43 -> V_44 , V_43 -> V_64 , NULL ) ;
if ( V_58 )
goto V_73;
return 0 ;
V_73:
F_11 ( V_4 ) ;
F_18 ( V_4 ) ;
F_37 ( V_4 ) ;
V_61:
F_47 ( & V_70 , V_4 -> V_60 ) ;
return V_58 ;
}
void F_48 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
F_49 ( V_12 ) ;
F_11 ( V_4 ) ;
F_18 ( V_4 ) ;
F_37 ( V_4 ) ;
F_47 ( & V_70 , V_4 -> V_60 ) ;
}
static int F_50 ( struct V_17 * V_12 , void * V_74 )
{
F_51 ( V_12 ) ;
return 0 ;
}
int F_52 ( struct V_17 * V_12 )
{
F_53 ( V_12 , NULL , F_50 ) ;
return 0 ;
}
int F_54 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
unsigned int V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
V_4 -> V_77 [ V_75 ] = F_4 ( V_4 -> V_6 + V_75 * 4 ) ;
F_15 ( 0 , V_4 -> V_6 + V_50 ) ;
return 0 ;
}
int F_55 ( struct V_17 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
unsigned int V_75 ;
F_25 ( V_4 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
F_15 ( V_4 -> V_77 [ V_75 ] , V_4 -> V_6 + V_75 * 4 ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
V_13 = F_6 ( L_11 , NULL ) ;
return 0 ;
}
static void T_5 F_57 ( void )
{
F_58 ( V_13 ) ;
}
