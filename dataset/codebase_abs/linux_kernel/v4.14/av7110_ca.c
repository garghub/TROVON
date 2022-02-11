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
int V_20 , struct V_21 * V_22 )
{
int V_23 ;
int V_3 = 0 ;
T_1 V_24 [ 8 ] = { 0x00 , 0x06 , 0x00 , 0x00 , 0xff , 0x02 , 0x00 , 0x00 } ;
for ( V_23 = 0 ; V_23 < 2 ; V_23 ++ ) {
if ( V_20 & ( 1 << V_23 ) )
V_3 += 8 ;
}
if ( F_4 ( V_11 ) < V_3 )
return - V_25 ;
for ( V_23 = 0 ; V_23 < 2 ; V_23 ++ ) {
if ( V_20 & ( 1 << V_23 ) ) {
V_24 [ 2 ] = V_23 ;
F_6 ( V_11 , V_24 , 8 ) ;
V_22 [ V_23 ] . V_6 = 0 ;
}
}
return 0 ;
}
static T_3 F_16 ( struct V_10 * V_11 , struct V_19 * V_19 ,
const char T_4 * V_26 , T_5 V_27 , T_6 * V_28 )
{
int free ;
int V_29 = V_19 -> V_30 & V_31 ;
T_1 * V_32 = ( T_1 * ) F_17 ( V_33 ) ;
int V_34 ;
if ( ! V_32 )
return - V_18 ;
V_34 = - V_35 ;
if ( V_27 > 2048 )
goto V_36;
V_34 = - V_37 ;
if ( F_18 ( V_32 , V_26 , V_27 ) )
goto V_36;
free = F_4 ( V_11 ) ;
if ( V_27 + 2 > free ) {
V_34 = - V_38 ;
if ( V_29 )
goto V_36;
V_34 = - V_39 ;
if ( F_19 ( V_11 -> V_12 ,
( F_4 ( V_11 ) >= V_27 + 2 ) ) )
goto V_36;
}
F_5 ( V_11 , V_27 >> 8 ) ;
F_5 ( V_11 , V_27 & 0xff ) ;
V_34 = F_6 ( V_11 , V_32 , V_27 ) ;
V_36:
F_20 ( ( unsigned long ) V_32 ) ;
return V_34 ;
}
static T_3 F_21 ( struct V_10 * V_11 , struct V_19 * V_19 ,
char T_4 * V_26 , T_5 V_27 , T_6 * V_28 )
{
int V_40 ;
int V_29 = V_19 -> V_30 & V_31 ;
T_3 V_3 ;
if ( ! V_11 -> V_2 || ! V_27 )
return 0 ;
if ( V_29 && ( F_22 ( V_11 ) ) )
return - V_38 ;
if ( F_19 ( V_11 -> V_12 ,
! F_22 ( V_11 ) ) )
return - V_39 ;
V_40 = F_23 ( V_11 ) ;
if ( V_40 < 4 )
return 0 ;
V_3 = F_24 ( V_11 , 0 ) << 8 ;
V_3 |= F_24 ( V_11 , 1 ) ;
if ( V_40 < V_3 + 2 || V_27 < V_3 )
return - V_35 ;
F_25 ( V_11 , 2 ) ;
return F_26 ( V_11 , V_26 , V_3 ) ;
}
static int F_27 ( struct V_41 * V_41 , struct V_19 * V_19 )
{
struct V_42 * V_43 = V_19 -> V_44 ;
struct V_1 * V_1 = V_43 -> V_45 ;
int V_46 = F_28 ( V_41 , V_19 ) ;
F_2 ( 8 , L_1 , V_1 ) ;
if ( V_46 < 0 )
return V_46 ;
F_12 ( & V_1 -> V_47 , & V_1 -> V_48 ) ;
return 0 ;
}
static unsigned int F_29 ( struct V_19 * V_19 , T_7 * V_49 )
{
struct V_42 * V_43 = V_19 -> V_44 ;
struct V_1 * V_1 = V_43 -> V_45 ;
struct V_10 * V_50 = & V_1 -> V_47 ;
struct V_10 * V_51 = & V_1 -> V_48 ;
unsigned int V_52 = 0 ;
F_2 ( 8 , L_1 , V_1 ) ;
F_30 ( V_19 , & V_50 -> V_12 , V_49 ) ;
F_30 ( V_19 , & V_51 -> V_12 , V_49 ) ;
if ( ! F_22 ( V_50 ) )
V_52 |= ( V_53 | V_54 ) ;
if ( F_4 ( V_51 ) > 1024 )
V_52 |= ( V_55 | V_56 ) ;
return V_52 ;
}
static int F_31 ( struct V_19 * V_19 , unsigned int V_57 , void * V_58 )
{
struct V_42 * V_43 = V_19 -> V_44 ;
struct V_1 * V_1 = V_43 -> V_45 ;
unsigned long V_59 = ( unsigned long ) V_58 ;
int V_60 = 0 ;
F_2 ( 8 , L_1 , V_1 ) ;
if ( F_32 ( & V_1 -> V_61 ) )
return - V_39 ;
switch ( V_57 ) {
case V_62 :
V_60 = F_15 ( & V_1 -> V_48 , V_19 , V_59 ,
& V_1 -> V_5 [ 0 ] ) ;
break;
case V_63 :
{
struct V_64 V_65 ;
V_65 . V_66 = 2 ;
V_65 . V_67 = ( F_33 ( V_1 -> V_68 ) ?
V_69 : V_70 ) | V_71 ;
V_65 . V_72 = 16 ;
V_65 . V_73 = V_74 ;
memcpy ( V_58 , & V_65 , sizeof( V_65 ) ) ;
break;
}
case V_75 :
{
struct V_21 * V_76 = (struct V_21 * ) V_58 ;
if ( V_76 -> V_77 < 0 || V_76 -> V_77 > 1 ) {
F_34 ( & V_1 -> V_61 ) ;
return - V_35 ;
}
V_1 -> V_5 [ V_76 -> V_77 ] . V_77 = V_76 -> V_77 ;
V_1 -> V_5 [ V_76 -> V_77 ] . type = F_33 ( V_1 -> V_68 ) ?
V_69 : V_70 ;
memcpy ( V_76 , & V_1 -> V_5 [ V_76 -> V_77 ] , sizeof( struct V_21 ) ) ;
break;
}
case V_78 :
break;
case V_79 :
break;
case V_80 :
{
struct V_81 V_76 ;
V_76 . V_77 = 16 ;
V_76 . type = V_74 ;
memcpy ( V_58 , & V_76 , sizeof ( V_76 ) ) ;
break;
}
case V_82 :
{
struct V_83 * V_84 = (struct V_83 * ) V_58 ;
if ( V_84 -> V_85 >= 16 || V_84 -> V_86 > 1 ) {
F_34 ( & V_1 -> V_61 ) ;
return - V_35 ;
}
F_35 ( V_1 , V_87 , V_88 , 5 ,
( V_84 -> V_85 << 8 ) | V_84 -> V_86 ,
( V_84 -> V_89 [ 0 ] << 8 ) | V_84 -> V_89 [ 1 ] ,
( V_84 -> V_89 [ 2 ] << 8 ) | V_84 -> V_89 [ 3 ] ,
( V_84 -> V_89 [ 4 ] << 8 ) | V_84 -> V_89 [ 5 ] ,
( V_84 -> V_89 [ 6 ] << 8 ) | V_84 -> V_89 [ 7 ] ) ;
break;
}
default:
V_60 = - V_35 ;
break;
}
F_34 ( & V_1 -> V_61 ) ;
return V_60 ;
}
static T_3 F_36 ( struct V_19 * V_19 , const char T_4 * V_26 ,
T_5 V_27 , T_6 * V_28 )
{
struct V_42 * V_43 = V_19 -> V_44 ;
struct V_1 * V_1 = V_43 -> V_45 ;
F_2 ( 8 , L_1 , V_1 ) ;
return F_16 ( & V_1 -> V_48 , V_19 , V_26 , V_27 , V_28 ) ;
}
static T_3 F_37 ( struct V_19 * V_19 , char T_4 * V_26 ,
T_5 V_27 , T_6 * V_28 )
{
struct V_42 * V_43 = V_19 -> V_44 ;
struct V_1 * V_1 = V_43 -> V_45 ;
F_2 ( 8 , L_1 , V_1 ) ;
return F_21 ( & V_1 -> V_47 , V_19 , V_26 , V_27 , V_28 ) ;
}
int F_38 ( struct V_1 * V_1 )
{
return F_39 ( & V_1 -> V_90 , & V_1 -> V_91 ,
& V_92 , V_1 , V_93 , 0 ) ;
}
void F_40 ( struct V_1 * V_1 )
{
F_41 ( V_1 -> V_91 ) ;
}
int F_42 ( struct V_1 * V_1 )
{
return F_8 ( & V_1 -> V_47 , & V_1 -> V_48 , 8192 ) ;
}
void F_43 ( struct V_1 * V_1 )
{
F_14 ( & V_1 -> V_47 , & V_1 -> V_48 ) ;
}
