static void F_1 ( struct V_1 * V_2 )
{
while ( F_2 ( V_2 -> V_3 ) & V_4 )
F_3 ( 1 ) ;
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
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
return V_36 -> V_49 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
return V_36 -> V_50 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
char * V_51 ;
T_2 V_52 ;
int V_38 ;
F_30 ( & V_2 -> V_46 ) ;
V_52 = F_2 ( V_2 -> V_3 ) ;
if ( V_52 == 0xff && F_2 ( V_2 -> V_44 ) == 0xff ) {
F_31 ( & V_2 -> V_46 ) ;
return - V_53 ;
}
if ( ! ( V_52 & V_4 ) )
F_5 ( V_4 , V_2 -> V_3 ) ;
F_31 ( & V_2 -> V_46 ) ;
V_38 = F_32 ( V_2 ) ;
if ( V_38 )
return V_38 ;
switch ( V_2 -> V_9 . type ) {
case 0 :
V_51 = L_2 ;
break;
case 1 :
V_51 = L_3 ;
break;
case 2 :
V_51 = L_4 ;
break;
default:
V_51 = L_5 ;
}
F_35 ( V_2 -> V_32 , L_6 , V_2 -> V_9 . V_14 ) ;
F_35 ( V_2 -> V_32 , L_7 ,
V_51 , V_2 -> V_9 . V_13 , V_2 -> V_9 . V_12 ,
V_2 -> V_9 . V_10 , V_2 -> V_9 . V_16 ,
V_2 -> V_9 . V_15 ) ;
return F_33 ( V_2 ) ;
}
static int F_36 ( struct V_54 * V_55 )
{
struct V_35 * V_36 = F_29 ( & V_55 -> V_32 ) ;
struct V_56 * V_32 = & V_55 -> V_32 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
int V_38 ;
V_2 = F_37 ( V_32 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_40 ;
V_58 = F_38 ( V_55 , V_60 , 0 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_62 = F_39 ( V_32 , V_58 -> V_63 ,
V_58 -> V_64 - V_58 -> V_63 ) ;
if ( ! V_2 -> V_62 )
return - V_40 ;
V_2 -> V_3 = V_2 -> V_62 ;
V_2 -> V_44 = V_2 -> V_62 + 1 ;
V_2 -> V_65 = V_36 -> V_65 ;
V_2 -> V_32 = V_32 ;
F_40 ( & V_2 -> V_46 ) ;
F_41 ( V_55 , V_2 ) ;
V_38 = F_34 ( V_2 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_42 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_43 ( V_55 ) ;
struct V_35 * V_36 = F_29 ( V_2 -> V_32 ) ;
F_44 ( & V_55 -> V_32 ) ;
V_36 -> V_48 ( V_2 ) ;
return 0 ;
}
static int T_4 F_45 ( void )
{
const struct V_33 * V_34 ;
int V_38 ;
if ( V_66 [ 0 ] ) {
for ( V_34 = V_67 ; V_34 -> V_68 [ 0 ] . V_69 != V_70 ; V_34 ++ )
if ( strstr ( V_34 -> V_71 , V_66 ) )
if ( V_34 -> V_72 && V_34 -> V_72 ( V_34 ) )
break;
if ( V_34 -> V_68 [ 0 ] . V_69 == V_70 )
return - V_53 ;
} else {
if ( ! F_46 ( V_67 ) )
return - V_53 ;
}
V_38 = F_47 ( & V_73 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static void T_5 F_48 ( void )
{
if ( V_39 )
F_49 ( V_39 ) ;
F_50 ( & V_73 ) ;
}
