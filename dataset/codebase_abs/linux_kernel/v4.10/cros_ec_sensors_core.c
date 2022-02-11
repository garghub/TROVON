int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 -> V_7 . V_12 ) ;
struct V_13 * V_14 = F_4 ( V_7 ) ;
F_5 ( V_2 , V_4 ) ;
V_9 -> V_11 = V_11 -> V_15 ;
V_9 -> V_16 = F_6 ( & V_2 -> V_7 ,
F_7 ( ( V_17 ) sizeof( struct V_18 ) ,
V_9 -> V_11 -> V_19 ) , V_20 ) ;
if ( ! V_9 -> V_16 )
return - V_21 ;
V_9 -> V_22 = (struct V_23 * ) V_9 -> V_16 -> V_24 ;
F_8 ( & V_9 -> V_25 ) ;
V_9 -> V_16 -> V_26 = 2 ;
V_9 -> V_16 -> V_27 = V_28 + V_11 -> V_29 ;
V_9 -> V_16 -> V_30 = sizeof( struct V_18 ) ;
V_4 -> V_7 . V_12 = & V_2 -> V_7 ;
V_4 -> V_31 = V_2 -> V_31 ;
if ( V_5 ) {
V_4 -> V_32 = V_33 ;
V_9 -> V_34 . V_35 = V_36 ;
V_9 -> V_34 . V_37 . V_38 = V_14 -> V_38 ;
if ( F_9 ( V_9 , 0 ) ) {
F_10 ( V_7 , L_1 ) ;
return - V_39 ;
}
V_9 -> type = V_9 -> V_22 -> V_37 . type ;
V_9 -> V_40 = V_9 -> V_22 -> V_37 . V_41 ;
}
return 0 ;
}
int F_9 ( struct V_8 * V_9 ,
V_17 V_42 )
{
int V_43 ;
if ( V_42 )
V_9 -> V_16 -> V_44 = F_11 ( V_42 , V_9 -> V_11 -> V_19 ) ;
else
V_9 -> V_16 -> V_44 = V_9 -> V_11 -> V_19 ;
memcpy ( V_9 -> V_16 -> V_24 , & V_9 -> V_34 , sizeof( V_9 -> V_34 ) ) ;
V_43 = F_12 ( V_9 -> V_11 , V_9 -> V_16 ) ;
if ( V_43 < 0 )
return - V_39 ;
if ( V_43 &&
V_9 -> V_22 != (struct V_23 * ) V_9 -> V_16 -> V_24 )
memcpy ( V_9 -> V_22 , V_9 -> V_16 -> V_24 , V_43 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_3 * V_4 ,
T_2 V_45 , const struct V_46 * V_47 ,
const char * V_48 , T_3 V_49 )
{
struct V_8 * V_50 = F_2 ( V_4 ) ;
int V_43 , V_51 ;
bool V_52 ;
V_43 = F_14 ( V_48 , & V_52 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_52 )
return - V_53 ;
F_15 ( & V_50 -> V_25 ) ;
V_50 -> V_34 . V_35 = V_54 ;
V_43 = F_9 ( V_50 , 0 ) ;
if ( V_43 != 0 ) {
F_10 ( & V_4 -> V_7 , L_2 ) ;
} else {
for ( V_51 = V_55 ; V_51 < V_56 ; V_51 ++ )
V_50 -> V_57 [ V_51 ] = V_50 -> V_22 -> V_58 . V_59 [ V_51 ] ;
}
F_16 ( & V_50 -> V_25 ) ;
return V_43 ? V_43 : V_49 ;
}
static T_1 F_17 ( struct V_3 * V_4 ,
T_2 V_45 , const struct V_46 * V_47 ,
char * V_48 )
{
struct V_8 * V_50 = F_2 ( V_4 ) ;
return snprintf ( V_48 , V_60 , L_3 , V_61 [ V_50 -> V_40 ] ) ;
}
static unsigned int F_18 (
struct V_8 * V_50 ,
unsigned int V_62 )
{
if ( V_50 -> type == V_63 )
return V_64 + sizeof( V_17 ) *
( 1 + V_62 + V_50 -> V_34 . V_37 . V_38 *
V_56 ) ;
return V_65 + sizeof( V_17 ) * V_62 ;
}
static int F_19 ( struct V_66 * V_11 ,
unsigned int V_59 , T_4 * V_67 )
{
return V_11 -> V_68 ( V_11 , V_59 , 1 , V_67 ) ;
}
static int F_20 ( struct V_66 * V_11 ,
unsigned int V_59 , V_17 * V_67 )
{
T_5 V_69 ;
int V_43 = V_11 -> V_68 ( V_11 , V_59 , 2 , & V_69 ) ;
if ( V_43 >= 0 )
* V_67 = F_21 ( V_69 ) ;
return V_43 ;
}
static int F_22 (
struct V_8 * V_50 )
{
struct V_66 * V_11 = V_50 -> V_11 ;
T_4 V_70 ;
int V_43 , V_71 = 0 ;
V_43 = F_19 ( V_11 , V_72 , & V_70 ) ;
if ( V_43 < 0 )
return V_43 ;
while ( V_70 & V_73 ) {
if ( V_71 ++ >= 50 )
return - V_39 ;
if ( V_71 % 5 == 0 )
F_23 ( 25 ) ;
V_43 = F_19 ( V_11 , V_72 ,
& V_70 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return V_70 ;
}
static int F_24 ( struct V_3 * V_4 ,
unsigned long V_74 , T_6 * V_24 )
{
struct V_8 * V_50 = F_2 ( V_4 ) ;
struct V_66 * V_11 = V_50 -> V_11 ;
unsigned int V_51 ;
int V_43 ;
F_25 (i, &scan_mask, indio_dev->masklength) {
V_43 = F_20 ( V_11 ,
F_18 ( V_50 , V_51 ) ,
V_24 ) ;
if ( V_43 < 0 )
return V_43 ;
V_24 ++ ;
}
return 0 ;
}
int F_26 ( struct V_3 * V_4 ,
unsigned long V_74 , T_6 * V_24 )
{
struct V_8 * V_50 = F_2 ( V_4 ) ;
struct V_66 * V_11 = V_50 -> V_11 ;
T_4 V_75 = 0xff , V_70 = 0 ;
int V_43 , V_71 = 0 ;
while ( ( V_70 & ( V_73 |
V_76 ) ) != V_75 ) {
if ( V_71 ++ >= 5 )
return - V_39 ;
V_43 = F_22 ( V_50 ) ;
if ( V_43 < 0 )
return V_43 ;
V_75 = V_43 & V_76 ;
V_43 = F_24 ( V_4 , V_74 ,
V_24 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_19 ( V_11 , V_72 ,
& V_70 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
int F_27 ( struct V_3 * V_4 ,
unsigned long V_74 , T_6 * V_24 )
{
struct V_8 * V_50 = F_2 ( V_4 ) ;
int V_43 ;
unsigned int V_51 ;
V_50 -> V_34 . V_35 = V_77 ;
V_43 = F_9 ( V_50 , sizeof( V_50 -> V_22 -> V_24 ) ) ;
if ( V_43 != 0 ) {
F_10 ( & V_4 -> V_7 , L_4 ) ;
return V_43 ;
}
F_25 (i, &scan_mask, indio_dev->masklength) {
* V_24 = V_50 -> V_22 -> V_24 . V_24 [ V_51 ] ;
V_24 ++ ;
}
return 0 ;
}
T_7 F_28 ( int V_78 , void * V_79 )
{
struct V_80 * V_81 = V_79 ;
struct V_3 * V_4 = V_81 -> V_4 ;
struct V_8 * V_50 = F_2 ( V_4 ) ;
int V_43 ;
F_15 ( & V_50 -> V_25 ) ;
memset ( V_50 -> V_82 , 0 , V_4 -> V_83 ) ;
V_43 = V_50 -> V_84 ( V_4 ,
* ( V_4 -> V_85 ) ,
( T_6 * ) V_50 -> V_82 ) ;
if ( V_43 < 0 )
goto V_86;
F_29 ( V_4 , V_50 -> V_82 ,
F_30 ( V_4 ) ) ;
V_86:
F_31 ( V_4 -> V_87 ) ;
F_16 ( & V_50 -> V_25 ) ;
return V_88 ;
}
int F_32 ( struct V_8 * V_50 ,
struct V_46 const * V_47 ,
int * V_89 , int * V_90 , long V_91 )
{
int V_43 = V_92 ;
switch ( V_91 ) {
case V_93 :
V_50 -> V_34 . V_35 = V_94 ;
V_50 -> V_34 . V_95 . V_24 =
V_96 ;
if ( F_9 ( V_50 , 0 ) )
V_43 = - V_39 ;
else
* V_89 = V_50 -> V_22 -> V_95 . V_43 ;
break;
case V_97 :
V_50 -> V_34 . V_35 = V_98 ;
V_50 -> V_34 . V_99 . V_24 =
V_96 ;
if ( F_9 ( V_50 , 0 ) )
V_43 = - V_39 ;
else
* V_89 = V_50 -> V_22 -> V_99 . V_43 ;
break;
default:
break;
}
return V_43 ;
}
int F_33 ( struct V_8 * V_50 ,
struct V_46 const * V_47 ,
int V_89 , int V_90 , long V_91 )
{
int V_43 = 0 ;
switch ( V_91 ) {
case V_97 :
V_50 -> V_34 . V_35 = V_98 ;
V_50 -> V_34 . V_99 . V_24 = V_89 ;
V_50 -> V_34 . V_99 . V_100 = 1 ;
if ( F_9 ( V_50 , 0 ) )
V_43 = - V_39 ;
break;
case V_93 :
V_50 -> V_34 . V_35 = V_94 ;
V_50 -> V_34 . V_95 . V_24 = V_89 ;
if ( F_9 ( V_50 , 0 ) )
V_43 = - V_39 ;
else
V_50 -> V_101 = V_89 ;
break;
default:
V_43 = - V_53 ;
break;
}
return V_43 ;
}
