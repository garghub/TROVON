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
struct V_35 * V_36 = V_2 -> V_32 -> V_46 ;
F_29 ( & V_2 -> V_47 ) ;
V_36 -> V_48 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_32 -> V_46 ;
V_36 -> V_49 ( V_2 ) ;
F_30 ( & V_2 -> V_47 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_32 -> V_46 ;
return V_36 -> V_50 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_32 -> V_46 ;
return V_36 -> V_51 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
char * V_52 ;
T_2 V_53 ;
int V_38 ;
F_29 ( & V_2 -> V_47 ) ;
V_53 = F_2 ( V_2 -> V_3 ) ;
if ( V_53 == 0xff && F_2 ( V_2 -> V_44 ) == 0xff ) {
F_30 ( & V_2 -> V_47 ) ;
return - V_54 ;
}
if ( ! ( V_53 & V_4 ) )
F_5 ( V_4 , V_2 -> V_3 ) ;
F_30 ( & V_2 -> V_47 ) ;
V_38 = F_31 ( V_2 ) ;
if ( V_38 )
return V_38 ;
switch ( V_2 -> V_9 . type ) {
case 0 :
V_52 = L_2 ;
break;
case 1 :
V_52 = L_3 ;
break;
case 2 :
V_52 = L_4 ;
break;
default:
V_52 = L_5 ;
}
F_34 ( V_2 -> V_32 , L_6 , V_2 -> V_9 . V_14 ) ;
F_34 ( V_2 -> V_32 , L_7 ,
V_52 , V_2 -> V_9 . V_13 , V_2 -> V_9 . V_12 ,
V_2 -> V_9 . V_10 , V_2 -> V_9 . V_16 ,
V_2 -> V_9 . V_15 ) ;
return F_32 ( V_2 ) ;
}
static int F_35 ( struct V_55 * V_56 )
{
struct V_35 * V_36 = V_56 -> V_32 . V_46 ;
struct V_57 * V_32 = & V_56 -> V_32 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
int V_38 ;
V_2 = F_36 ( V_32 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_40 ;
V_59 = F_37 ( V_56 , V_61 , 0 ) ;
if ( ! V_59 )
return - V_62 ;
V_2 -> V_63 = F_38 ( V_32 , V_59 -> V_64 ,
V_59 -> V_65 - V_59 -> V_64 ) ;
if ( ! V_2 -> V_63 )
return - V_40 ;
V_2 -> V_3 = V_2 -> V_63 ;
V_2 -> V_44 = V_2 -> V_63 + 1 ;
V_2 -> V_66 = V_36 -> V_66 ;
V_2 -> V_32 = V_32 ;
F_39 ( & V_2 -> V_47 ) ;
F_40 ( V_56 , V_2 ) ;
V_38 = F_33 ( V_2 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int F_41 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_42 ( V_56 ) ;
struct V_35 * V_36 = V_2 -> V_32 -> V_46 ;
F_43 ( & V_56 -> V_32 ) ;
V_36 -> V_49 ( V_2 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
const struct V_33 * V_34 ;
int V_38 ;
if ( V_67 [ 0 ] ) {
for ( V_34 = V_68 ; V_34 -> V_69 [ 0 ] . V_70 != V_71 ; V_34 ++ )
if ( strstr ( V_34 -> V_72 , V_67 ) )
if ( V_34 -> V_73 && V_34 -> V_73 ( V_34 ) )
break;
if ( V_34 -> V_69 [ 0 ] . V_70 == V_71 )
return - V_54 ;
} else {
if ( ! F_45 ( V_68 ) )
return - V_54 ;
}
V_38 = F_46 ( & V_74 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static void T_5 F_47 ( void )
{
if ( V_39 )
F_48 ( V_39 ) ;
F_49 ( & V_74 ) ;
}
