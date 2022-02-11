static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_4 -> V_6 < V_2 -> V_7 -> V_8 )
return 0 ;
switch ( V_4 -> V_9 [ 0 ] & 0xf0 ) {
case 0x40 :
V_5 = F_2 ( V_10 ) ;
break;
case 0x60 :
V_5 = F_2 ( V_11 ) ;
break;
case 0x00 :
if ( F_3 ( V_4 -> V_9 ) )
return 1 ;
F_4 ( V_4 ) ;
goto V_12;
default:
return 1 ;
}
if ( F_5 ( V_4 ) < V_13 )
return 0 ;
F_6 ( V_4 , V_13 ) ;
F_4 ( V_4 ) ;
F_7 ( V_4 ) -> V_14 = V_5 ;
memset ( F_7 ( V_4 ) -> V_15 , 0 , V_16 ) ;
V_12:
memcpy ( F_7 ( V_4 ) -> V_17 , V_2 -> V_7 -> V_18 , V_16 ) ;
return 1 ;
}
static bool F_8 ( const char * V_9 )
{
return ( V_9 [ 0 ] & 0xd0 ) == 0x40 ;
}
static int F_9 ( struct V_19 * V_2 , void * V_20 )
{
int V_21 ;
struct V_22 * V_23 = V_20 ;
V_21 = F_10 ( V_2 , V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( F_8 ( V_23 -> V_24 ) )
return - V_25 ;
F_11 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_26 )
{
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
int V_29 ;
F_13 ( & V_2 -> V_30 -> V_2 , L_1 , V_31 ,
F_14 ( & V_28 -> V_32 ) , V_26 ) ;
if ( ( V_26 && F_15 ( 1 , & V_28 -> V_32 ) == 1 ) ||
( ! V_26 && F_16 ( & V_28 -> V_32 ) ) ) {
V_29 = F_17 ( V_2 -> V_30 ) ;
V_2 -> V_30 -> V_33 = V_26 ;
if ( ! V_29 )
F_18 ( V_2 -> V_30 ) ;
}
return 0 ;
}
static int F_19 ( struct V_34 * V_30 , int V_26 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
if ( ! V_2 )
return 0 ;
return F_12 ( V_2 , V_26 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_35 * V_36 = NULL ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
V_29 = F_22 ( V_2 , V_28 -> V_9 ) ;
if ( V_29 < 0 )
goto V_37;
if ( V_28 -> V_38 != V_28 -> V_9 )
V_2 -> V_39 = & V_28 -> V_38 -> V_40 -> V_41 [ 0 ] ;
if ( ! V_2 -> V_39 ) {
V_29 = - V_42 ;
goto V_37;
}
F_23 ( & V_28 -> V_32 , 0 ) ;
V_36 = F_24 ( V_28 -> V_38 , & V_2 -> V_39 -> V_43 ,
4096 , & F_19 ) ;
if ( F_25 ( V_36 ) ) {
F_26 ( & V_28 -> V_38 -> V_2 , L_2 ) ;
V_29 = F_27 ( V_36 ) ;
goto V_37;
}
V_2 -> V_39 = NULL ;
V_28 -> V_36 = V_36 ;
V_37:
return V_29 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_34 * V_30 )
{
int V_39 = - 1 ;
T_2 * V_44 = V_30 -> V_40 -> V_45 ;
int V_6 = V_30 -> V_40 -> V_46 ;
struct V_47 * V_43 = & V_30 -> V_40 -> V_43 ;
struct V_48 * V_49 = NULL ;
struct V_50 * V_51 = NULL ;
T_3 V_52 = 0 ;
struct V_35 * V_53 = F_29 ( V_30 ) ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
F_30 ( ( sizeof( ( (struct V_1 * ) 0 ) -> V_9 ) <
sizeof( struct V_27 ) ) ) ;
V_28 -> V_38 = V_30 ;
V_28 -> V_9 = V_30 ;
while ( V_6 > 3 ) {
struct V_54 * V_55 = ( void * ) V_44 ;
if ( V_55 -> V_56 != V_57 )
goto V_58;
switch ( V_44 [ 2 ] ) {
case V_59 :
if ( V_52 & 1 << V_59 ) {
F_13 ( & V_30 -> V_2 , L_3 ) ;
goto V_37;
}
if ( V_55 -> V_60 != sizeof( struct V_61 ) ) {
F_13 ( & V_30 -> V_2 , L_4 ,
V_55 -> V_60 ) ;
goto V_37;
}
break;
case V_62 :
if ( V_52 & 1 << V_62 ) {
F_13 ( & V_30 -> V_2 , L_5 ) ;
goto V_37;
}
if ( V_55 -> V_60 != sizeof( struct V_48 ) ) {
F_13 ( & V_30 -> V_2 , L_6 ,
V_55 -> V_60 ) ;
goto V_37;
}
V_49 = (struct V_48 * ) V_44 ;
break;
case V_63 :
if ( V_52 & 1 << V_63 ) {
F_13 ( & V_30 -> V_2 , L_7 ) ;
goto V_37;
}
if ( V_55 -> V_60 != sizeof( struct V_50 ) ) {
F_13 ( & V_30 -> V_2 , L_8 ,
V_55 -> V_60 ) ;
goto V_37;
}
V_51 = (struct V_50 * ) V_44 ;
break;
}
if ( V_44 [ 2 ] < 32 )
V_52 |= 1 << V_44 [ 2 ] ;
V_58:
V_6 -= V_55 -> V_60 ;
V_44 += V_55 -> V_60 ;
}
if ( V_49 ) {
V_28 -> V_9 = F_31 ( V_2 -> V_64 ,
V_49 -> V_65 ) ;
if ( V_43 -> V_66 != V_49 -> V_67 ||
! V_28 -> V_9 ) {
F_26 ( & V_30 -> V_2 ,
L_9 ,
V_49 -> V_67 ,
V_49 -> V_65 ) ;
goto V_37;
}
}
if ( V_51 ) {
V_2 -> V_68 = F_32 ( V_51 -> V_69 ) ;
F_33 ( V_2 , V_51 -> V_70 ) ;
}
if ( V_28 -> V_38 != V_28 -> V_9 ) {
V_39 = F_34 ( V_53 , V_28 -> V_9 , V_2 ) ;
if ( V_39 < 0 )
goto V_37;
}
V_39 = F_21 ( V_2 ) ;
if ( V_39 < 0 && V_28 -> V_38 != V_28 -> V_9 ) {
F_35 ( V_28 -> V_9 , NULL ) ;
F_36 ( V_53 , V_28 -> V_9 ) ;
}
if ( F_37 ( V_2 -> V_7 -> V_18 , V_71 ) )
F_38 ( V_2 -> V_7 ) ;
if ( F_8 ( V_2 -> V_7 -> V_18 ) ) {
V_2 -> V_7 -> V_18 [ 0 ] |= 0x02 ;
V_2 -> V_7 -> V_18 [ 0 ] &= 0xbf ;
}
V_2 -> V_7 -> V_72 = & V_73 ;
V_37:
return V_39 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_34 * V_30 )
{
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
struct V_35 * V_53 = F_29 ( V_30 ) ;
struct V_34 * V_74 ;
if ( V_28 -> V_36 && V_28 -> V_36 -> V_75 )
V_28 -> V_36 -> V_75 ( V_28 -> V_38 ) ;
if ( V_30 == V_28 -> V_38 )
V_74 = V_28 -> V_9 ;
else
V_74 = V_28 -> V_38 ;
if ( V_74 && V_30 != V_74 ) {
F_35 ( V_74 , NULL ) ;
F_36 ( V_53 , V_74 ) ;
}
V_28 -> V_36 = NULL ;
V_28 -> V_9 = NULL ;
V_28 -> V_38 = NULL ;
}
static int F_40 ( struct V_34 * V_30 , T_4 V_76 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
int V_21 ;
V_21 = F_41 ( V_30 , V_76 ) ;
if ( V_21 < 0 )
goto V_37;
if ( V_30 == V_28 -> V_38 && V_28 -> V_36 &&
V_28 -> V_36 -> V_77 )
V_21 = V_28 -> V_36 -> V_77 ( V_30 , V_76 ) ;
if ( V_21 < 0 )
F_42 ( V_30 ) ;
V_37:
return V_21 ;
}
static int F_43 ( struct V_34 * V_30 )
{
struct V_1 * V_2 = F_20 ( V_30 ) ;
struct V_27 * V_28 = ( void * ) & V_2 -> V_9 ;
int V_21 = 0 ;
bool V_78 = ( V_30 == V_28 -> V_38 && V_28 -> V_36 &&
V_28 -> V_36 -> V_79 ) ;
if ( V_78 )
V_21 = V_28 -> V_36 -> V_79 ( V_30 ) ;
if ( V_21 < 0 )
goto V_37;
V_21 = F_42 ( V_30 ) ;
if ( V_21 < 0 && V_78 )
V_28 -> V_36 -> V_77 ( V_30 , V_80 ) ;
V_37:
return V_21 ;
}
static int F_44 ( struct V_34 * V_30 ,
const struct V_81 * V_82 )
{
struct V_81 * V_83 = (struct V_81 * ) V_82 ;
if ( ! V_83 -> V_84 ) {
F_13 ( & V_30 -> V_2 , L_10 ) ;
V_83 -> V_84 = ( unsigned long ) & V_85 ;
}
return F_45 ( V_30 , V_83 ) ;
}
