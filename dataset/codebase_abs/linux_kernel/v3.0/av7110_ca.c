void F_1 ( struct V_1 * V_1 , T_1 * V_2 , T_2 V_3 )
{
F_2 ( 8 , L_1 , V_1 ) ;
if ( V_3 < 3 )
return;
switch ( V_2 [ 0 ] ) {
case V_4 :
if ( V_2 [ 2 ] != 1 && V_2 [ 2 ] != 2 )
break;
switch ( V_2 [ 1 ] ) {
case 0 :
V_1 -> V_5 [ V_2 [ 2 ] - 1 ] . V_6 = 0 ;
break;
case 1 :
V_1 -> V_5 [ V_2 [ 2 ] - 1 ] . V_6 |= V_7 ;
break;
case 2 :
V_1 -> V_5 [ V_2 [ 2 ] - 1 ] . V_6 |= V_8 ;
break;
}
break;
case V_9 :
break;
default:
break;
}
}
void F_3 ( struct V_10 * V_11 , T_1 * V_2 , int V_3 )
{
if ( F_4 ( V_11 ) < V_3 + 2 )
return;
F_5 ( V_11 , V_3 >> 8 ) ;
F_5 ( V_11 , V_3 & 0xff ) ;
F_6 ( V_11 , V_2 , V_3 ) ;
F_7 ( & V_11 -> V_12 ) ;
}
static int F_8 ( struct V_10 * V_13 , struct V_10 * V_14 , int V_15 )
{
struct V_10 * V_16 [] = { V_13 , V_14 , NULL } , * * V_17 ;
void * V_2 ;
for ( V_17 = V_16 ; * V_17 ; V_17 ++ ) {
V_2 = F_9 ( V_15 ) ;
if ( ! V_2 ) {
while ( V_17 -- != V_16 ) {
F_10 ( V_17 [ 0 ] -> V_2 ) ;
V_17 [ 0 ] -> V_2 = NULL ;
}
return - V_18 ;
}
F_11 ( * V_17 , V_2 , V_15 ) ;
}
return 0 ;
}
static void F_12 ( struct V_10 * V_13 , struct V_10 * V_14 )
{
F_13 ( V_13 ) ;
F_13 ( V_14 ) ;
}
static void F_14 ( struct V_10 * V_13 , struct V_10 * V_14 )
{
F_10 ( V_13 -> V_2 ) ;
V_13 -> V_2 = NULL ;
F_10 ( V_14 -> V_2 ) ;
V_14 -> V_2 = NULL ;
}
static int F_15 ( struct V_10 * V_11 , struct V_19 * V_19 ,
int V_20 , T_3 * V_21 )
{
int V_22 ;
int V_3 = 0 ;
T_1 V_23 [ 8 ] = { 0x00 , 0x06 , 0x00 , 0x00 , 0xff , 0x02 , 0x00 , 0x00 } ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
if ( V_20 & ( 1 << V_22 ) )
V_3 += 8 ;
}
if ( F_4 ( V_11 ) < V_3 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
if ( V_20 & ( 1 << V_22 ) ) {
V_23 [ 2 ] = V_22 ;
F_6 ( V_11 , V_23 , 8 ) ;
V_21 [ V_22 ] . V_6 = 0 ;
}
}
return 0 ;
}
static T_4 F_16 ( struct V_10 * V_11 , struct V_19 * V_19 ,
const char T_5 * V_25 , T_6 V_26 , T_7 * V_27 )
{
int free ;
int V_28 = V_19 -> V_29 & V_30 ;
T_1 * V_31 = ( T_1 * ) F_17 ( V_32 ) ;
int V_33 ;
if ( ! V_31 )
return - V_18 ;
V_33 = - V_34 ;
if ( V_26 > 2048 )
goto V_35;
V_33 = - V_36 ;
if ( F_18 ( V_31 , V_25 , V_26 ) )
goto V_35;
free = F_4 ( V_11 ) ;
if ( V_26 + 2 > free ) {
V_33 = - V_37 ;
if ( V_28 )
goto V_35;
V_33 = - V_38 ;
if ( F_19 ( V_11 -> V_12 ,
( F_4 ( V_11 ) >= V_26 + 2 ) ) )
goto V_35;
}
F_5 ( V_11 , V_26 >> 8 ) ;
F_5 ( V_11 , V_26 & 0xff ) ;
V_33 = F_6 ( V_11 , V_31 , V_26 ) ;
V_35:
F_20 ( ( unsigned long ) V_31 ) ;
return V_33 ;
}
static T_4 F_21 ( struct V_10 * V_11 , struct V_19 * V_19 ,
char T_5 * V_25 , T_6 V_26 , T_7 * V_27 )
{
int V_39 ;
int V_28 = V_19 -> V_29 & V_30 ;
T_4 V_3 ;
if ( ! V_11 -> V_2 || ! V_26 )
return 0 ;
if ( V_28 && ( F_22 ( V_11 ) ) )
return - V_37 ;
if ( F_19 ( V_11 -> V_12 ,
! F_22 ( V_11 ) ) )
return - V_38 ;
V_39 = F_23 ( V_11 ) ;
if ( V_39 < 4 )
return 0 ;
V_3 = F_24 ( V_11 , 0 ) << 8 ;
V_3 |= F_24 ( V_11 , 1 ) ;
if ( V_39 < V_3 + 2 || V_26 < V_3 )
return - V_34 ;
F_25 ( V_11 , 2 ) ;
return F_26 ( V_11 , V_25 , V_3 ) ;
}
static int F_27 ( struct V_40 * V_40 , struct V_19 * V_19 )
{
struct V_41 * V_42 = V_19 -> V_43 ;
struct V_1 * V_1 = V_42 -> V_44 ;
int V_45 = F_28 ( V_40 , V_19 ) ;
F_2 ( 8 , L_1 , V_1 ) ;
if ( V_45 < 0 )
return V_45 ;
F_12 ( & V_1 -> V_46 , & V_1 -> V_47 ) ;
return 0 ;
}
static unsigned int F_29 ( struct V_19 * V_19 , T_8 * V_48 )
{
struct V_41 * V_42 = V_19 -> V_43 ;
struct V_1 * V_1 = V_42 -> V_44 ;
struct V_10 * V_49 = & V_1 -> V_46 ;
struct V_10 * V_50 = & V_1 -> V_47 ;
unsigned int V_51 = 0 ;
F_2 ( 8 , L_1 , V_1 ) ;
F_30 ( V_19 , & V_49 -> V_12 , V_48 ) ;
F_30 ( V_19 , & V_50 -> V_12 , V_48 ) ;
if ( ! F_22 ( V_49 ) )
V_51 |= ( V_52 | V_53 ) ;
if ( F_4 ( V_50 ) > 1024 )
V_51 |= ( V_54 | V_55 ) ;
return V_51 ;
}
static int F_31 ( struct V_19 * V_19 , unsigned int V_56 , void * V_57 )
{
struct V_41 * V_42 = V_19 -> V_43 ;
struct V_1 * V_1 = V_42 -> V_44 ;
unsigned long V_58 = ( unsigned long ) V_57 ;
F_2 ( 8 , L_1 , V_1 ) ;
switch ( V_56 ) {
case V_59 :
return F_15 ( & V_1 -> V_47 , V_19 , V_58 , & V_1 -> V_5 [ 0 ] ) ;
break;
case V_60 :
{
T_9 V_61 ;
V_61 . V_62 = 2 ;
V_61 . V_63 = ( F_32 ( V_1 -> V_64 ) ?
V_65 : V_66 ) | V_67 ;
V_61 . V_68 = 16 ;
V_61 . V_69 = V_70 ;
memcpy ( V_57 , & V_61 , sizeof( V_61 ) ) ;
break;
}
case V_71 :
{
T_3 * V_72 = ( T_3 * ) V_57 ;
if ( V_72 -> V_73 < 0 || V_72 -> V_73 > 1 )
return - V_34 ;
V_1 -> V_5 [ V_72 -> V_73 ] . V_73 = V_72 -> V_73 ;
V_1 -> V_5 [ V_72 -> V_73 ] . type = F_32 ( V_1 -> V_64 ) ?
V_65 : V_66 ;
memcpy ( V_72 , & V_1 -> V_5 [ V_72 -> V_73 ] , sizeof( T_3 ) ) ;
break;
}
case V_74 :
break;
case V_75 :
break;
case V_76 :
{
T_10 V_72 ;
V_72 . V_73 = 16 ;
V_72 . type = V_70 ;
memcpy ( V_57 , & V_72 , sizeof ( V_72 ) ) ;
break;
}
case V_77 :
{
T_11 * V_78 = ( T_11 * ) V_57 ;
if ( V_78 -> V_79 >= 16 )
return - V_34 ;
if ( V_78 -> V_80 > 1 )
return - V_34 ;
F_33 ( V_1 , V_81 , V_82 , 5 ,
( V_78 -> V_79 << 8 ) | V_78 -> V_80 ,
( V_78 -> V_83 [ 0 ] << 8 ) | V_78 -> V_83 [ 1 ] ,
( V_78 -> V_83 [ 2 ] << 8 ) | V_78 -> V_83 [ 3 ] ,
( V_78 -> V_83 [ 4 ] << 8 ) | V_78 -> V_83 [ 5 ] ,
( V_78 -> V_83 [ 6 ] << 8 ) | V_78 -> V_83 [ 7 ] ) ;
break;
}
default:
return - V_34 ;
}
return 0 ;
}
static T_4 F_34 ( struct V_19 * V_19 , const char T_5 * V_25 ,
T_6 V_26 , T_7 * V_27 )
{
struct V_41 * V_42 = V_19 -> V_43 ;
struct V_1 * V_1 = V_42 -> V_44 ;
F_2 ( 8 , L_1 , V_1 ) ;
return F_16 ( & V_1 -> V_47 , V_19 , V_25 , V_26 , V_27 ) ;
}
static T_4 F_35 ( struct V_19 * V_19 , char T_5 * V_25 ,
T_6 V_26 , T_7 * V_27 )
{
struct V_41 * V_42 = V_19 -> V_43 ;
struct V_1 * V_1 = V_42 -> V_44 ;
F_2 ( 8 , L_1 , V_1 ) ;
return F_21 ( & V_1 -> V_46 , V_19 , V_25 , V_26 , V_27 ) ;
}
int F_36 ( struct V_1 * V_1 )
{
return F_37 ( & V_1 -> V_84 , & V_1 -> V_85 ,
& V_86 , V_1 , V_87 ) ;
}
void F_38 ( struct V_1 * V_1 )
{
F_39 ( V_1 -> V_85 ) ;
}
int F_40 ( struct V_1 * V_1 )
{
return F_8 ( & V_1 -> V_46 , & V_1 -> V_47 , 8192 ) ;
}
void F_41 ( struct V_1 * V_1 )
{
F_14 ( & V_1 -> V_46 , & V_1 -> V_47 ) ;
}
