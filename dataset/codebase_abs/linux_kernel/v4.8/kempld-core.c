static void F_1 ( struct V_1 * V_2 )
{
while ( F_2 ( V_2 -> V_3 ) & V_4 )
F_3 ( 1000 , 3000 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_4 , V_2 -> V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_2 V_6 ;
F_7 ( V_2 ) ;
V_5 = F_8 ( V_2 , V_7 ) ;
V_6 = F_9 ( V_2 , V_8 ) ;
V_2 -> V_9 . V_10 = F_8 ( V_2 , V_11 ) ;
V_2 -> V_9 . V_12 = F_10 ( V_5 ) ;
V_2 -> V_9 . V_13 = F_11 ( V_5 ) ;
V_2 -> V_9 . V_14 = F_12 ( V_5 ) ;
V_2 -> V_9 . type = F_13 ( V_5 ) ;
if ( V_6 == 0xff ) {
V_2 -> V_9 . V_15 = 0 ;
V_2 -> V_9 . V_16 = 1 ;
} else {
V_2 -> V_9 . V_15 = F_14 ( V_6 ) ;
V_2 -> V_9 . V_16 = F_15 ( V_6 ) ;
}
if ( V_2 -> V_9 . V_16 > 0 )
V_2 -> V_17 = F_8 ( V_2 , V_18 ) ;
else
V_2 -> V_17 = 0 ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_19 V_20 [ V_21 ] ;
int V_22 = 0 ;
if ( V_2 -> V_17 & V_23 )
V_20 [ V_22 ++ ] = V_24 [ V_25 ] ;
if ( V_2 -> V_17 & V_26 )
V_20 [ V_22 ++ ] = V_24 [ V_27 ] ;
if ( V_2 -> V_17 & V_28 )
V_20 [ V_22 ++ ] = V_24 [ V_29 ] ;
if ( V_2 -> V_17 & V_30 )
V_20 [ V_22 ++ ] = V_24 [ V_31 ] ;
return F_18 ( V_2 -> V_32 , - 1 , V_20 , V_22 , NULL , 0 , NULL ) ;
}
static int F_19 ( const struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
int V_38 ;
V_39 = F_20 ( L_1 , - 1 ) ;
if ( ! V_39 )
return - V_40 ;
V_38 = F_21 ( V_39 , V_36 , sizeof( * V_36 ) ) ;
if ( V_38 )
goto V_41;
V_38 = F_22 ( V_39 , V_36 -> V_42 , 1 ) ;
if ( V_38 )
goto V_41;
V_38 = F_23 ( V_39 ) ;
if ( V_38 )
goto V_41;
return 0 ;
V_41:
F_24 ( V_39 ) ;
return V_38 ;
}
T_2 F_9 ( struct V_1 * V_2 , T_2 V_43 )
{
F_5 ( V_43 , V_2 -> V_3 ) ;
return F_2 ( V_2 -> V_44 ) ;
}
void F_25 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_45 )
{
F_5 ( V_43 , V_2 -> V_3 ) ;
F_5 ( V_45 , V_2 -> V_44 ) ;
}
T_1 F_8 ( struct V_1 * V_2 , T_2 V_43 )
{
return F_9 ( V_2 , V_43 ) | F_9 ( V_2 , V_43 + 1 ) << 8 ;
}
void F_26 ( struct V_1 * V_2 , T_2 V_43 , T_1 V_45 )
{
F_25 ( V_2 , V_43 , ( T_2 ) V_45 ) ;
F_25 ( V_2 , V_43 + 1 , ( T_2 ) ( V_45 >> 8 ) ) ;
}
T_3 F_27 ( struct V_1 * V_2 , T_2 V_43 )
{
return F_8 ( V_2 , V_43 ) | F_8 ( V_2 , V_43 + 2 ) << 16 ;
}
void F_28 ( struct V_1 * V_2 , T_2 V_43 , T_3 V_45 )
{
F_26 ( V_2 , V_43 , ( T_1 ) V_45 ) ;
F_26 ( V_2 , V_43 + 2 , ( T_1 ) ( V_45 >> 16 ) ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
F_30 ( & V_2 -> V_46 ) ;
V_36 -> V_47 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
V_36 -> V_48 ( V_2 ) ;
F_31 ( & V_2 -> V_46 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
char V_13 , V_12 ;
V_38 = V_36 -> V_49 ( V_2 ) ;
if ( V_38 )
return V_38 ;
if ( V_2 -> V_9 . V_13 < 10 )
V_13 = V_2 -> V_9 . V_13 + '0' ;
else
V_13 = ( V_2 -> V_9 . V_13 - 10 ) + 'A' ;
if ( V_2 -> V_9 . V_12 < 10 )
V_12 = V_2 -> V_9 . V_12 + '0' ;
else
V_12 = ( V_2 -> V_9 . V_12 - 10 ) + 'A' ;
V_38 = F_33 ( V_2 -> V_9 . V_5 , sizeof( V_2 -> V_9 . V_5 ) ,
L_2 , V_2 -> V_9 . V_14 , V_13 , V_12 ,
V_2 -> V_9 . V_10 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
return V_36 -> V_50 ( V_2 ) ;
}
static const char * F_35 ( struct V_1 * V_2 )
{
const char * V_51 ;
switch ( V_2 -> V_9 . type ) {
case 0 :
V_51 = L_3 ;
break;
case 1 :
V_51 = L_4 ;
break;
case 2 :
V_51 = L_5 ;
break;
default:
V_51 = L_6 ;
break;
}
return V_51 ;
}
static T_4 F_36 ( struct V_52 * V_32 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_2 = F_37 ( V_32 ) ;
return F_33 ( V_55 , V_56 , L_7 , V_2 -> V_9 . V_5 ) ;
}
static T_4 F_38 ( struct V_52 * V_32 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_2 = F_37 ( V_32 ) ;
return F_33 ( V_55 , V_56 , L_8 , V_2 -> V_9 . V_16 ,
V_2 -> V_9 . V_15 ) ;
}
static T_4 F_39 ( struct V_52 * V_32 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_1 * V_2 = F_37 ( V_32 ) ;
return F_33 ( V_55 , V_56 , L_7 , F_35 ( V_2 ) ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_2 V_57 ;
int V_38 ;
F_30 ( & V_2 -> V_46 ) ;
V_57 = F_2 ( V_2 -> V_3 ) ;
if ( V_57 == 0xff && F_2 ( V_2 -> V_44 ) == 0xff ) {
F_31 ( & V_2 -> V_46 ) ;
return - V_58 ;
}
if ( ! ( V_57 & V_4 ) ) {
F_5 ( V_4 , V_2 -> V_3 ) ;
F_5 ( V_4 , V_2 -> V_3 ) ;
}
F_31 ( & V_2 -> V_46 ) ;
V_38 = F_32 ( V_2 ) ;
if ( V_38 )
return V_38 ;
F_41 ( V_2 -> V_32 , L_9 ,
V_2 -> V_9 . V_5 , F_35 ( V_2 ) ,
V_2 -> V_9 . V_16 , V_2 -> V_9 . V_15 ) ;
V_38 = F_42 ( & V_2 -> V_32 -> V_59 , & V_60 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_34 ( V_2 ) ;
if ( V_38 )
F_43 ( & V_2 -> V_32 -> V_59 , & V_60 ) ;
return V_38 ;
}
static int F_44 ( struct V_61 * V_62 )
{
struct V_35 * V_36 = F_29 ( & V_62 -> V_32 ) ;
struct V_52 * V_32 = & V_62 -> V_32 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
V_2 = F_45 ( V_32 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_40 ;
V_64 = F_46 ( V_62 , V_66 , 0 ) ;
if ( ! V_64 )
return - V_67 ;
V_2 -> V_68 = F_47 ( V_32 , V_64 -> V_69 ,
V_64 -> V_70 - V_64 -> V_69 ) ;
if ( ! V_2 -> V_68 )
return - V_40 ;
V_2 -> V_3 = V_2 -> V_68 ;
V_2 -> V_44 = V_2 -> V_68 + 1 ;
V_2 -> V_71 = V_36 -> V_71 ;
V_2 -> V_32 = V_32 ;
F_48 ( & V_2 -> V_46 ) ;
F_49 ( V_62 , V_2 ) ;
return F_40 ( V_2 ) ;
}
static int F_50 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_51 ( V_62 ) ;
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
F_43 ( & V_2 -> V_32 -> V_59 , & V_60 ) ;
F_52 ( & V_62 -> V_32 ) ;
V_36 -> V_48 ( V_2 ) ;
return 0 ;
}
static int T_5 F_53 ( void )
{
const struct V_33 * V_34 ;
if ( V_72 [ 0 ] ) {
for ( V_34 = V_73 ;
V_34 -> V_74 [ 0 ] . V_75 != V_76 ; V_34 ++ )
if ( strstr ( V_34 -> V_77 , V_72 ) )
if ( V_34 -> V_78 && ! V_34 -> V_78 ( V_34 ) )
break;
if ( V_34 -> V_74 [ 0 ] . V_75 == V_76 )
return - V_58 ;
} else {
if ( ! F_54 ( V_73 ) )
return - V_58 ;
}
return F_55 ( & V_79 ) ;
}
static void T_6 F_56 ( void )
{
if ( V_39 )
F_57 ( V_39 ) ;
F_58 ( & V_79 ) ;
}
