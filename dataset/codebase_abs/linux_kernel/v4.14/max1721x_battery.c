static inline int F_1 ( unsigned int V_1 )
{
return V_1 * 5625 / 1000 ;
}
static inline int F_2 ( unsigned int V_1 )
{
return V_1 / 256 ;
}
static inline int F_3 ( unsigned int V_1 )
{
return V_1 * 1250 ;
}
static inline int F_4 ( unsigned int V_1 )
{
return V_1 * 500 ;
}
static inline int F_5 ( unsigned int V_1 )
{
int V_2 = ( V_3 ) ( V_1 ) ;
return V_2 * 10 / 256 ;
}
static inline int F_6 ( unsigned int V_1 )
{
int V_2 = ( V_3 ) ( V_1 ) ;
return V_2 * 156252 ;
}
static inline struct V_4 *
F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_6 ) ;
}
static int F_9 ( struct V_5 * V_6 ,
enum V_7 V_8 ,
union V_9 * V_2 )
{
struct V_4 * V_10 = F_7 ( V_6 ) ;
unsigned int V_1 = 0 ;
int V_11 = 0 ;
switch ( V_8 ) {
case V_12 :
V_2 -> V_13 =
F_10 ( V_10 -> V_14 , V_15 ,
& V_1 ) ? 0 : ! ( V_1 & V_16 ) ;
break;
case V_17 :
V_11 = F_10 ( V_10 -> V_14 , V_18 , & V_1 ) ;
V_2 -> V_13 = F_2 ( V_1 ) ;
break;
case V_19 :
V_11 = F_10 ( V_10 -> V_14 , V_20 , & V_1 ) ;
V_2 -> V_13 = F_3 ( V_1 ) ;
break;
case V_21 :
V_11 = F_10 ( V_10 -> V_14 , V_22 , & V_1 ) ;
V_2 -> V_13 = F_4 ( V_1 ) ;
break;
case V_23 :
V_11 = F_10 ( V_10 -> V_14 , V_24 , & V_1 ) ;
V_2 -> V_13 = F_4 ( V_1 ) ;
break;
case V_25 :
V_11 = F_10 ( V_10 -> V_14 , V_26 , & V_1 ) ;
V_2 -> V_13 = F_1 ( V_1 ) ;
break;
case V_27 :
V_11 = F_10 ( V_10 -> V_14 , V_28 , & V_1 ) ;
V_2 -> V_13 = F_1 ( V_1 ) ;
break;
case V_29 :
V_11 = F_10 ( V_10 -> V_14 , V_30 , & V_1 ) ;
V_2 -> V_13 = F_5 ( V_1 ) ;
break;
case V_31 :
V_11 = F_10 ( V_10 -> V_14 , V_32 , & V_1 ) ;
V_2 -> V_13 =
F_6 ( V_1 ) / ( int ) V_10 -> V_33 ;
break;
case V_34 :
V_11 = F_10 ( V_10 -> V_14 , V_35 , & V_1 ) ;
V_2 -> V_13 =
F_6 ( V_1 ) / ( int ) V_10 -> V_33 ;
break;
case V_36 :
V_11 = F_10 ( V_10 -> V_14 , V_37 , & V_1 ) ;
V_2 -> V_38 = V_10 -> V_39 ;
break;
case V_40 :
V_11 = F_10 ( V_10 -> V_14 , V_41 , & V_1 ) ;
V_2 -> V_38 = V_10 -> V_42 ;
break;
case V_43 :
V_11 = F_10 ( V_10 -> V_14 , V_44 , & V_1 ) ;
V_2 -> V_38 = V_10 -> V_45 ;
break;
default:
V_11 = - V_46 ;
}
return V_11 ;
}
static int F_11 ( struct V_4 * V_10 ,
T_1 V_1 , T_2 V_47 , char * V_48 )
{
unsigned int V_2 ;
if ( ! V_48 || ! ( V_1 == V_41 ||
V_1 == V_37 ) )
return - V_49 ;
while ( V_47 -- ) {
if ( F_10 ( V_10 -> V_14 , V_1 ++ , & V_2 ) )
return - V_49 ;
* V_48 ++ = V_2 >> 8 & 0x00FF ;
* V_48 ++ = V_2 & 0x00FF ;
}
return 0 ;
}
static int F_12 ( struct V_4 * V_10 , char * V_48 )
{
unsigned int V_2 [ 3 ] ;
if ( ! V_48 )
return - V_49 ;
if ( F_10 ( V_10 -> V_14 , V_44 , & V_2 [ 0 ] ) )
return - V_49 ;
if ( F_10 ( V_10 -> V_14 , V_44 + 1 , & V_2 [ 1 ] ) )
return - V_49 ;
if ( F_10 ( V_10 -> V_14 , V_44 + 2 , & V_2 [ 2 ] ) )
return - V_49 ;
snprintf ( V_48 , 13 , L_1 , V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ) ;
return 0 ;
}
static int F_13 ( struct V_50 * V_51 )
{
struct V_52 V_53 = {} ;
struct V_4 * V_10 ;
V_10 = F_14 ( & V_51 -> V_54 , sizeof( * V_10 ) , V_55 ) ;
if ( ! V_10 )
return - V_56 ;
V_51 -> V_57 = ( void * ) V_10 ;
V_10 -> V_58 = & V_51 -> V_54 ;
snprintf ( V_10 -> V_59 , sizeof( V_10 -> V_59 ) ,
L_2 , ( unsigned int ) V_51 -> V_60 . V_61 ) ;
V_10 -> V_62 . V_59 = V_10 -> V_59 ;
V_10 -> V_62 . V_63 = true ;
V_10 -> V_62 . type = V_64 ;
V_10 -> V_62 . V_65 = V_66 ;
V_10 -> V_62 . V_67 = F_15 ( V_66 ) ;
V_10 -> V_62 . V_68 = F_9 ;
V_53 . V_69 = V_10 ;
V_10 -> V_14 = F_16 ( V_10 -> V_58 ,
& V_70 ) ;
if ( F_17 ( V_10 -> V_14 ) ) {
int V_71 = F_18 ( V_10 -> V_14 ) ;
F_19 ( V_10 -> V_58 , L_3 ,
V_71 ) ;
return V_71 ;
}
V_10 -> V_33 = 0 ;
if ( F_10 ( V_10 -> V_14 , V_72 , & V_10 -> V_33 ) ) {
F_19 ( V_10 -> V_58 , L_4 ) ;
return - V_73 ;
}
if ( ! V_10 -> V_33 ) {
F_20 ( V_10 -> V_58 , L_5 ) ;
V_10 -> V_33 = 1000 ;
}
F_21 ( V_10 -> V_58 , L_6 , V_10 -> V_33 / 100 ) ;
if ( F_11 ( V_10 , V_41 ,
V_74 , V_10 -> V_42 ) ) {
F_19 ( V_10 -> V_58 , L_7 ) ;
return - V_73 ;
}
if ( ! V_10 -> V_42 [ 0 ] )
strncpy ( V_10 -> V_42 , V_75 ,
2 * V_74 ) ;
if ( F_11 ( V_10 , V_37 ,
V_76 , V_10 -> V_39 ) ) {
F_19 ( V_10 -> V_58 , L_8 ) ;
return - V_73 ;
}
if ( ! V_10 -> V_39 [ 0 ] ) {
unsigned int V_77 ;
if ( F_10 ( V_10 -> V_14 ,
V_78 , & V_77 ) ) {
F_19 ( V_10 -> V_58 , L_9 ) ;
return - V_73 ;
}
switch ( V_77 & V_79 ) {
case V_80 :
strncpy ( V_10 -> V_39 , V_81 ,
2 * V_76 ) ;
break;
case V_82 :
strncpy ( V_10 -> V_39 , V_83 ,
2 * V_76 ) ;
break;
default:
strncpy ( V_10 -> V_39 , V_84 ,
2 * V_76 ) ;
}
}
if ( F_12 ( V_10 , V_10 -> V_45 ) ) {
F_19 ( V_10 -> V_58 , L_10 ) ;
return - V_73 ;
}
V_10 -> V_85 = F_22 ( & V_51 -> V_54 , & V_10 -> V_62 ,
& V_53 ) ;
if ( F_17 ( V_10 -> V_85 ) ) {
F_19 ( V_10 -> V_58 , L_11 ) ;
return F_18 ( V_10 -> V_85 ) ;
}
return 0 ;
}
