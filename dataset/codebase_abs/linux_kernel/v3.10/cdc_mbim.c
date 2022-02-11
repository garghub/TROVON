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
T_1 V_21 = F_12 ( V_2 , V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
if ( ! F_13 ( V_8 -> V_22 ) )
goto V_11;
V_20 = F_14 ( V_2 , V_8 , V_21 ) ;
if ( V_20 )
goto V_11;
V_16 = V_5 -> V_16 ;
if ( V_16 -> V_23 && V_2 -> V_14 )
V_18 = F_15 ( V_16 -> V_24 ,
& V_2 -> V_14 -> V_25 ,
F_16 ( V_16 -> V_23 -> V_26 ) ,
F_8 ) ;
if ( F_17 ( V_18 ) ) {
V_20 = F_18 ( V_18 ) ;
F_19 ( V_2 , V_8 ) ;
goto V_11;
}
V_2 -> V_14 = NULL ;
V_5 -> V_18 = V_18 ;
V_2 -> V_27 -> V_28 |= V_29 ;
V_2 -> V_27 -> V_30 |= V_31 ;
V_11:
return V_20 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_13 * V_8 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
if ( V_5 -> V_18 && V_5 -> V_18 -> V_32 )
V_5 -> V_18 -> V_32 ( V_16 -> V_24 ) ;
V_5 -> V_18 = NULL ;
F_19 ( V_2 , V_8 ) ;
}
static struct V_33 * F_21 ( struct V_1 * V_2 , struct V_33 * V_34 , T_2 V_28 )
{
struct V_33 * V_35 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
T_3 V_36 = F_22 ( V_37 ) ;
T_4 V_38 = 0 ;
T_1 * V_39 ;
if ( ! V_16 )
goto error;
if ( V_34 ) {
if ( V_34 -> V_40 <= V_41 )
goto error;
F_23 ( V_34 , & V_38 ) ;
switch ( V_38 & 0x0f00 ) {
case 0x0000 :
F_24 ( V_34 ) ;
switch ( F_25 ( V_34 ) -> V_42 ) {
case F_26 ( V_43 ) :
case F_26 ( V_44 ) :
break;
default:
goto error;
}
V_39 = ( T_1 * ) & V_36 ;
V_39 [ 3 ] = V_38 ;
break;
case 0x0100 :
V_36 = F_22 ( V_45 ) ;
V_39 = ( T_1 * ) & V_36 ;
V_39 [ 3 ] = V_38 ;
break;
default:
F_27 ( V_2 , V_46 , V_2 -> V_27 ,
L_2 , V_38 ) ;
goto error;
}
F_28 ( V_34 , V_41 ) ;
}
F_29 ( & V_16 -> V_47 ) ;
V_35 = F_30 ( V_16 , V_34 , V_36 ) ;
F_31 ( & V_16 -> V_47 ) ;
return V_35 ;
error:
if ( V_34 )
F_32 ( V_34 ) ;
return NULL ;
}
static struct V_33 * F_33 ( struct V_1 * V_2 , T_1 * V_48 , T_5 V_40 , T_4 V_38 )
{
T_6 V_49 = F_26 ( V_50 ) ;
struct V_33 * V_34 = NULL ;
if ( V_38 < 256 ) {
if ( V_40 < sizeof( struct V_51 ) )
goto V_11;
switch ( * V_48 & 0xf0 ) {
case 0x40 :
V_49 = F_26 ( V_43 ) ;
break;
case 0x60 :
V_49 = F_26 ( V_44 ) ;
break;
default:
goto V_11;
}
}
V_34 = F_34 ( V_2 -> V_27 , V_40 + V_41 ) ;
if ( ! V_34 )
goto V_11;
F_35 ( V_34 , V_41 ) ;
F_24 ( V_34 ) ;
F_25 ( V_34 ) -> V_42 = V_49 ;
memset ( F_25 ( V_34 ) -> V_52 , 0 , V_53 ) ;
memcpy ( F_25 ( V_34 ) -> V_54 , V_2 -> V_27 -> V_55 , V_53 ) ;
memcpy ( F_35 ( V_34 , V_40 ) , V_48 , V_40 ) ;
if ( V_38 )
F_36 ( V_34 , F_26 ( V_56 ) , V_38 ) ;
V_11:
return V_34 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_33 * V_57 )
{
struct V_33 * V_34 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
int V_40 ;
int V_58 ;
int V_59 ;
int V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_65 ;
int V_66 = 50 ;
T_1 * V_39 ;
T_4 V_38 ;
V_65 = F_38 ( V_16 , V_57 ) ;
if ( V_65 < 0 )
goto error;
V_67:
V_58 = F_39 ( V_57 , V_65 ) ;
if ( V_58 < 0 )
goto error;
V_62 = (struct V_61 * ) ( V_57 -> V_6 + V_65 ) ;
switch ( V_62 -> V_68 & F_22 ( 0x00ffffff ) ) {
case F_22 ( V_37 ) :
V_39 = ( T_1 * ) & V_62 -> V_68 ;
V_38 = V_39 [ 3 ] ;
break;
case F_22 ( V_45 ) :
V_39 = ( T_1 * ) & V_62 -> V_68 ;
V_38 = V_39 [ 3 ] + 256 ;
break;
default:
F_40 ( V_2 , V_69 , V_2 -> V_27 ,
L_3 ,
F_41 ( V_62 -> V_68 ) ) ;
goto V_70;
}
V_64 = V_62 -> V_64 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ , V_64 ++ ) {
V_60 = F_16 ( V_64 -> V_71 ) ;
V_40 = F_16 ( V_64 -> V_72 ) ;
if ( ( V_60 == 0 ) || ( V_40 == 0 ) ) {
if ( ! V_59 )
goto V_70;
break;
}
if ( ( ( V_60 + V_40 ) > V_57 -> V_40 ) || ( V_40 > V_16 -> V_73 ) ) {
F_40 ( V_2 , V_69 , V_2 -> V_27 ,
L_4 ,
V_59 , V_60 , V_40 , V_57 ) ;
if ( ! V_59 )
goto V_70;
break;
} else {
V_34 = F_33 ( V_2 , V_57 -> V_6 + V_60 , V_40 , V_38 ) ;
if ( ! V_34 )
goto error;
F_42 ( V_2 , V_34 ) ;
}
}
V_70:
V_65 = F_16 ( V_62 -> V_74 ) ;
if ( V_65 && V_66 -- )
goto V_67;
return 1 ;
error:
return 0 ;
}
static int F_43 ( struct V_13 * V_8 , T_7 V_75 )
{
int V_20 = 0 ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_15 * V_16 = V_5 -> V_16 ;
if ( V_16 == NULL ) {
V_20 = - 1 ;
goto error;
}
V_20 = F_44 ( V_8 , V_75 ) ;
if ( V_20 < 0 )
goto error;
if ( V_8 == V_16 -> V_24 && V_5 -> V_18 && V_5 -> V_18 -> V_76 )
V_20 = V_5 -> V_18 -> V_76 ( V_8 , V_75 ) ;
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
bool V_77 = ( V_8 == V_16 -> V_24 && V_5 -> V_18 && V_5 -> V_18 -> V_78 ) ;
if ( V_77 )
V_20 = V_5 -> V_18 -> V_78 ( V_8 ) ;
if ( V_20 < 0 )
goto V_11;
V_20 = F_45 ( V_8 ) ;
if ( V_20 < 0 && V_77 && V_5 -> V_18 -> V_76 )
V_5 -> V_18 -> V_76 ( V_8 , V_79 ) ;
V_11:
return V_20 ;
}
