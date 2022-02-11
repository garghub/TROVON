static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
switch ( V_4 -> V_6 [ 0 ] & 0xf0 ) {
case 0x40 :
V_5 = F_2 ( V_7 ) ;
break;
case 0x60 :
V_5 = F_2 ( V_8 ) ;
break;
case 0x00 :
if ( F_3 ( V_4 -> V_6 ) )
return 1 ;
F_4 ( V_4 ) ;
goto V_9;
default:
return 1 ;
}
if ( F_5 ( V_4 ) < V_10 )
return 0 ;
F_6 ( V_4 , V_10 ) ;
F_4 ( V_4 ) ;
F_7 ( V_4 ) -> V_11 = V_5 ;
memset ( F_7 ( V_4 ) -> V_12 , 0 , V_13 ) ;
V_9:
memcpy ( F_7 ( V_4 ) -> V_14 , V_2 -> V_15 -> V_16 , V_13 ) ;
return 1 ;
}
static bool F_8 ( const char * V_6 )
{
return ( V_6 [ 0 ] & 0xd0 ) == 0x40 ;
}
static int F_9 ( struct V_17 * V_2 , void * V_18 )
{
int V_19 ;
struct V_20 * V_21 = V_18 ;
V_19 = F_10 ( V_2 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_8 ( V_21 -> V_22 ) )
return - V_23 ;
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_24 )
{
struct V_25 * V_26 = ( void * ) & V_2 -> V_6 ;
int V_27 ;
F_13 ( & V_2 -> V_28 -> V_2 , L_1 , V_29 ,
F_14 ( & V_26 -> V_30 ) , V_24 ) ;
if ( ( V_24 && F_15 ( 1 , & V_26 -> V_30 ) == 1 ) ||
( ! V_24 && F_16 ( & V_26 -> V_30 ) ) ) {
V_27 = F_17 ( V_2 -> V_28 ) ;
V_2 -> V_28 -> V_31 = V_24 ;
if ( ! V_27 )
F_18 ( V_2 -> V_28 ) ;
}
return 0 ;
}
static int F_19 ( struct V_32 * V_28 , int V_24 )
{
struct V_1 * V_2 = F_20 ( V_28 ) ;
if ( ! V_2 )
return 0 ;
return F_12 ( V_2 , V_24 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_33 * V_34 = NULL ;
struct V_25 * V_26 = ( void * ) & V_2 -> V_6 ;
V_27 = F_22 ( V_2 , V_26 -> V_6 ) ;
if ( V_27 < 0 )
goto V_35;
if ( V_26 -> V_36 != V_26 -> V_6 )
V_2 -> V_37 = & V_26 -> V_36 -> V_38 -> V_39 [ 0 ] ;
if ( ! V_2 -> V_37 ) {
V_27 = - V_40 ;
goto V_35;
}
F_23 ( & V_26 -> V_30 , 0 ) ;
V_34 = F_24 ( V_26 -> V_36 , & V_2 -> V_37 -> V_41 ,
4096 , & F_19 ) ;
if ( F_25 ( V_34 ) ) {
F_26 ( & V_26 -> V_36 -> V_2 , L_2 ) ;
V_27 = F_27 ( V_34 ) ;
goto V_35;
}
V_2 -> V_37 = NULL ;
V_26 -> V_34 = V_34 ;
V_35:
return V_27 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_32 * V_28 )
{
int V_37 = - 1 ;
T_2 * V_42 = V_28 -> V_38 -> V_43 ;
int V_44 = V_28 -> V_38 -> V_45 ;
struct V_46 * V_41 = & V_28 -> V_38 -> V_41 ;
struct V_47 * V_48 = NULL ;
struct V_49 * V_50 = NULL ;
T_3 V_51 = 0 ;
struct V_33 * V_52 = F_29 ( V_28 ) ;
struct V_25 * V_26 = ( void * ) & V_2 -> V_6 ;
F_30 ( ( sizeof( ( (struct V_1 * ) 0 ) -> V_6 ) <
sizeof( struct V_25 ) ) ) ;
V_26 -> V_36 = V_28 ;
V_26 -> V_6 = V_28 ;
while ( V_44 > 3 ) {
struct V_53 * V_54 = ( void * ) V_42 ;
if ( V_54 -> V_55 != V_56 )
goto V_57;
switch ( V_42 [ 2 ] ) {
case V_58 :
if ( V_51 & 1 << V_58 ) {
F_13 ( & V_28 -> V_2 , L_3 ) ;
goto V_35;
}
if ( V_54 -> V_59 != sizeof( struct V_60 ) ) {
F_13 ( & V_28 -> V_2 , L_4 ,
V_54 -> V_59 ) ;
goto V_35;
}
break;
case V_61 :
if ( V_51 & 1 << V_61 ) {
F_13 ( & V_28 -> V_2 , L_5 ) ;
goto V_35;
}
if ( V_54 -> V_59 != sizeof( struct V_47 ) ) {
F_13 ( & V_28 -> V_2 , L_6 ,
V_54 -> V_59 ) ;
goto V_35;
}
V_48 = (struct V_47 * ) V_42 ;
break;
case V_62 :
if ( V_51 & 1 << V_62 ) {
F_13 ( & V_28 -> V_2 , L_7 ) ;
goto V_35;
}
if ( V_54 -> V_59 != sizeof( struct V_49 ) ) {
F_13 ( & V_28 -> V_2 , L_8 ,
V_54 -> V_59 ) ;
goto V_35;
}
V_50 = (struct V_49 * ) V_42 ;
break;
}
if ( V_42 [ 2 ] < 32 )
V_51 |= 1 << V_42 [ 2 ] ;
V_57:
V_44 -= V_54 -> V_59 ;
V_42 += V_54 -> V_59 ;
}
if ( V_48 ) {
V_26 -> V_6 = F_31 ( V_2 -> V_63 ,
V_48 -> V_64 ) ;
if ( V_41 -> V_65 != V_48 -> V_66 ||
! V_26 -> V_6 ) {
F_26 ( & V_28 -> V_2 ,
L_9 ,
V_48 -> V_66 ,
V_48 -> V_64 ) ;
goto V_35;
}
}
if ( V_50 ) {
V_2 -> V_67 = F_32 ( V_50 -> V_68 ) ;
F_33 ( V_2 , V_50 -> V_69 ) ;
}
if ( V_26 -> V_36 != V_26 -> V_6 ) {
V_37 = F_34 ( V_52 , V_26 -> V_6 , V_2 ) ;
if ( V_37 < 0 )
goto V_35;
}
V_37 = F_21 ( V_2 ) ;
if ( V_37 < 0 && V_26 -> V_36 != V_26 -> V_6 ) {
F_35 ( V_26 -> V_6 , NULL ) ;
F_36 ( V_52 , V_26 -> V_6 ) ;
}
if ( F_37 ( V_2 -> V_15 -> V_16 , V_70 ) )
F_38 ( V_2 -> V_15 ) ;
if ( F_8 ( V_2 -> V_15 -> V_16 ) ) {
V_2 -> V_15 -> V_16 [ 0 ] |= 0x02 ;
V_2 -> V_15 -> V_16 [ 0 ] &= 0xbf ;
}
V_2 -> V_15 -> V_71 = & V_72 ;
V_35:
return V_37 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_32 * V_28 )
{
struct V_25 * V_26 = ( void * ) & V_2 -> V_6 ;
struct V_33 * V_52 = F_29 ( V_28 ) ;
struct V_32 * V_73 ;
if ( V_26 -> V_34 && V_26 -> V_34 -> V_74 )
V_26 -> V_34 -> V_74 ( V_26 -> V_36 ) ;
if ( V_28 == V_26 -> V_36 )
V_73 = V_26 -> V_6 ;
else
V_73 = V_26 -> V_36 ;
if ( V_73 && V_28 != V_73 ) {
F_35 ( V_73 , NULL ) ;
F_36 ( V_52 , V_73 ) ;
}
V_26 -> V_34 = NULL ;
V_26 -> V_6 = NULL ;
V_26 -> V_36 = NULL ;
}
static int F_40 ( struct V_32 * V_28 , T_4 V_75 )
{
struct V_1 * V_2 = F_20 ( V_28 ) ;
struct V_25 * V_26 = ( void * ) & V_2 -> V_6 ;
int V_19 ;
V_19 = F_41 ( V_28 , V_75 ) ;
if ( V_19 < 0 )
goto V_35;
if ( V_28 == V_26 -> V_36 && V_26 -> V_34 &&
V_26 -> V_34 -> V_76 )
V_19 = V_26 -> V_34 -> V_76 ( V_28 , V_75 ) ;
if ( V_19 < 0 )
F_42 ( V_28 ) ;
V_35:
return V_19 ;
}
static int F_43 ( struct V_32 * V_28 )
{
struct V_1 * V_2 = F_20 ( V_28 ) ;
struct V_25 * V_26 = ( void * ) & V_2 -> V_6 ;
int V_19 = 0 ;
bool V_77 = ( V_28 == V_26 -> V_36 && V_26 -> V_34 &&
V_26 -> V_34 -> V_78 ) ;
if ( V_77 )
V_19 = V_26 -> V_34 -> V_78 ( V_28 ) ;
if ( V_19 < 0 )
goto V_35;
V_19 = F_42 ( V_28 ) ;
if ( V_19 < 0 && V_77 )
V_26 -> V_34 -> V_76 ( V_28 , V_79 ) ;
V_35:
return V_19 ;
}
static int F_44 ( struct V_32 * V_28 ,
const struct V_80 * V_81 )
{
struct V_80 * V_82 = (struct V_80 * ) V_81 ;
if ( ! V_82 -> V_83 ) {
F_13 ( & V_28 -> V_2 , L_10 ) ;
V_82 -> V_83 = ( unsigned long ) & V_84 ;
}
return F_45 ( V_28 , V_82 ) ;
}
