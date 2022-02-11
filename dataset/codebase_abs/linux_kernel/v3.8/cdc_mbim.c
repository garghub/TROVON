static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_1 , V_9 , F_3 ( & V_5 -> V_10 ) , V_3 ) ;
if ( ( V_3 && F_4 ( 1 , & V_5 -> V_10 ) == 1 ) || ( ! V_3 && F_5 ( & V_5 -> V_10 ) ) ) {
V_7 = F_6 ( V_2 -> V_8 ) ;
if ( V_7 < 0 )
goto V_11;
V_2 -> V_8 -> V_12 = V_3 ;
F_7 ( V_2 -> V_8 ) ;
}
V_11:
return V_7 ;
}
static int F_8 ( struct V_13 * V_8 , int V_14 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
return F_1 ( V_2 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_13 * V_8 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = F_11 ( - V_19 ) ;
int V_20 = - V_19 ;
T_1 V_21 = V_22 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
if ( V_8 -> V_23 == 2 ) {
if ( ! F_12 ( V_8 -> V_24 ) )
F_13 ( V_2 -> V_25 ,
V_8 -> V_24 -> V_26 . V_27 ,
V_28 ) ;
V_21 = V_29 ;
}
if ( ! F_12 ( V_8 -> V_24 ) )
goto V_11;
V_20 = F_14 ( V_2 , V_8 , V_21 ) ;
if ( V_20 )
goto V_11;
V_16 = V_5 -> V_16 ;
if ( V_16 -> V_30 && V_2 -> V_14 )
V_18 = F_15 ( V_16 -> V_31 ,
& V_2 -> V_14 -> V_26 ,
F_16 ( V_16 -> V_30 -> V_32 ) ,
F_8 ) ;
if ( F_17 ( V_18 ) ) {
V_20 = F_18 ( V_18 ) ;
F_19 ( V_2 , V_8 ) ;
goto V_11;
}
V_2 -> V_14 = NULL ;
V_5 -> V_18 = V_18 ;
V_2 -> V_33 -> V_34 |= V_35 ;
V_2 -> V_33 -> V_36 |= V_37 ;
V_11:
return V_20 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_13 * V_8 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
if ( V_5 -> V_18 && V_5 -> V_18 -> V_38 )
V_5 -> V_18 -> V_38 ( V_16 -> V_31 ) ;
V_5 -> V_18 = NULL ;
F_19 ( V_2 , V_8 ) ;
}
static struct V_39 * F_21 ( struct V_1 * V_2 , struct V_39 * V_40 , T_2 V_34 )
{
struct V_39 * V_41 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
T_3 V_42 = F_22 ( V_43 ) ;
T_4 V_44 = 0 ;
T_1 * V_45 ;
if ( ! V_16 )
goto error;
if ( V_40 ) {
if ( V_40 -> V_46 <= sizeof( V_47 ) )
goto error;
F_23 ( V_40 , & V_44 ) ;
switch ( V_44 & 0x0f00 ) {
case 0x0000 :
F_24 ( V_40 ) ;
switch ( F_25 ( V_40 ) -> V_48 ) {
case F_26 ( V_49 ) :
case F_26 ( V_50 ) :
break;
default:
goto error;
}
V_45 = ( T_1 * ) & V_42 ;
V_45 [ 3 ] = V_44 ;
break;
case 0x0100 :
V_42 = F_22 ( V_51 ) ;
V_45 = ( T_1 * ) & V_42 ;
V_45 [ 3 ] = V_44 ;
break;
default:
F_27 ( V_2 , V_52 , V_2 -> V_33 ,
L_2 , V_44 ) ;
goto error;
}
F_28 ( V_40 , V_47 ) ;
}
F_29 ( & V_16 -> V_53 ) ;
V_41 = F_30 ( V_16 , V_40 , V_42 ) ;
F_31 ( & V_16 -> V_53 ) ;
return V_41 ;
error:
if ( V_40 )
F_32 ( V_40 ) ;
return NULL ;
}
static struct V_39 * F_33 ( struct V_1 * V_2 , T_1 * V_54 , T_5 V_46 , T_4 V_44 )
{
T_6 V_55 = F_26 ( V_56 ) ;
struct V_39 * V_40 = NULL ;
if ( V_44 < 256 ) {
if ( V_46 < sizeof( struct V_57 ) )
goto V_11;
switch ( * V_54 & 0xf0 ) {
case 0x40 :
V_55 = F_26 ( V_49 ) ;
break;
case 0x60 :
V_55 = F_26 ( V_50 ) ;
break;
default:
goto V_11;
}
}
V_40 = F_34 ( V_2 -> V_33 , V_46 + V_47 ) ;
if ( ! V_40 )
goto V_11;
F_35 ( V_40 , V_47 ) ;
F_24 ( V_40 ) ;
F_25 ( V_40 ) -> V_48 = V_55 ;
memset ( F_25 ( V_40 ) -> V_58 , 0 , V_59 ) ;
memcpy ( F_25 ( V_40 ) -> V_60 , V_2 -> V_33 -> V_61 , V_59 ) ;
memcpy ( F_35 ( V_40 , V_46 ) , V_54 , V_46 ) ;
if ( V_44 )
F_36 ( V_40 , V_44 ) ;
V_11:
return V_40 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_39 * V_62 )
{
struct V_39 * V_40 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
int V_46 ;
int V_63 ;
int V_64 ;
int V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_70 ;
int V_71 = 50 ;
T_1 * V_45 ;
T_4 V_44 ;
V_70 = F_38 ( V_16 , V_62 ) ;
if ( V_70 < 0 )
goto error;
V_72:
V_63 = F_39 ( V_62 , V_70 ) ;
if ( V_63 < 0 )
goto error;
V_67 = (struct V_66 * ) ( V_62 -> V_6 + V_70 ) ;
switch ( V_67 -> V_73 & F_22 ( 0x00ffffff ) ) {
case F_22 ( V_43 ) :
V_45 = ( T_1 * ) & V_67 -> V_73 ;
V_44 = V_45 [ 3 ] ;
break;
case F_22 ( V_51 ) :
V_45 = ( T_1 * ) & V_67 -> V_73 ;
V_44 = V_45 [ 3 ] + 256 ;
break;
default:
F_40 ( V_2 , V_74 , V_2 -> V_33 ,
L_3 ,
F_41 ( V_67 -> V_73 ) ) ;
goto V_75;
}
V_69 = V_67 -> V_69 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ , V_69 ++ ) {
V_65 = F_16 ( V_69 -> V_76 ) ;
V_46 = F_16 ( V_69 -> V_77 ) ;
if ( ( V_65 == 0 ) || ( V_46 == 0 ) ) {
if ( ! V_64 )
goto V_75;
break;
}
if ( ( ( V_65 + V_46 ) > V_62 -> V_46 ) || ( V_46 > V_16 -> V_78 ) ) {
F_40 ( V_2 , V_74 , V_2 -> V_33 ,
L_4 ,
V_64 , V_65 , V_46 , V_62 ) ;
if ( ! V_64 )
goto V_75;
break;
} else {
V_40 = F_33 ( V_2 , V_62 -> V_6 + V_65 , V_46 , V_44 ) ;
if ( ! V_40 )
goto error;
F_42 ( V_2 , V_40 ) ;
}
}
V_75:
V_70 = F_16 ( V_67 -> V_79 ) ;
if ( V_70 && V_71 -- )
goto V_72;
return 1 ;
error:
return 0 ;
}
static int F_43 ( struct V_13 * V_8 , T_7 V_80 )
{
int V_20 = 0 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
if ( V_16 == NULL ) {
V_20 = - 1 ;
goto error;
}
V_20 = F_44 ( V_8 , V_80 ) ;
if ( V_20 < 0 )
goto error;
if ( V_8 == V_16 -> V_31 && V_5 -> V_18 && V_5 -> V_18 -> V_81 )
V_20 = V_5 -> V_18 -> V_81 ( V_8 , V_80 ) ;
if ( V_20 < 0 )
F_45 ( V_8 ) ;
error:
return V_20 ;
}
static int F_46 ( struct V_13 * V_8 )
{
int V_20 = 0 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
bool V_82 = ( V_8 == V_16 -> V_31 && V_5 -> V_18 && V_5 -> V_18 -> V_83 ) ;
if ( V_82 )
V_20 = V_5 -> V_18 -> V_83 ( V_8 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_45 ( V_8 ) ;
if ( V_20 < 0 && V_82 && V_5 -> V_18 -> V_81 )
V_5 -> V_18 -> V_81 ( V_8 , V_84 ) ;
V_11:
return V_20 ;
}
