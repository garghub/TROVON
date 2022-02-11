static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_4 ( V_6 , L_1 , V_9 , V_7 , V_3 ) ;
V_8 = F_5 ( V_2 , V_3 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_6 ( V_4 -> V_10 , V_2 -> V_11 -> V_12 + 1 ,
V_2 -> V_11 -> V_13 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_15 , V_16 ;
int V_7 = F_3 ( V_2 ) ;
F_4 ( V_6 , L_2 , V_9 , V_7 , V_14 ) ;
V_15 = V_17 ;
switch ( V_14 ) {
case V_18 :
V_16 = 0 ;
break;
case V_19 :
V_16 = V_17 ;
break;
default:
F_8 ( & V_2 -> V_6 , L_3 ,
V_2 -> V_11 -> V_20 , V_14 ) ;
return - V_21 ;
}
return F_6 ( V_4 -> V_10 , V_2 -> V_11 -> V_12 ,
V_15 , V_16 ) ;
}
static inline unsigned int F_9 ( unsigned int V_3 , T_1 V_22 , T_1 V_23 )
{
T_2 V_24 ;
if ( V_3 == 0 )
return 0 ;
V_24 = ( T_2 ) V_3 * V_22 ;
F_10 ( V_24 , V_23 ) ;
return V_3 + ( unsigned int ) V_24 ;
}
static int F_11 ( struct V_25 * V_26 ,
const struct V_27 * V_11 ,
struct V_28 * V_29 )
{
struct V_4 * V_4 = V_29 -> V_30 ;
struct V_27 * V_31 = & V_4 -> V_32 [ V_11 -> V_33 ] ;
T_1 V_34 [ 2 ] ;
int V_35 ;
if ( V_11 -> V_33 == V_36 )
return 0 ;
V_35 = F_12 ( V_26 , L_4 , V_34 , 2 ) ;
if ( V_35 ) {
F_13 ( V_4 -> V_6 , L_5 ,
V_35 ) ;
return V_35 ;
}
V_31 -> V_37 = F_9 ( V_11 -> V_37 , V_34 [ 0 ] , V_34 [ 1 ] ) ;
V_31 -> V_38 = F_9 ( V_11 -> V_38 , V_34 [ 0 ] , V_34 [ 1 ] ) ;
V_31 -> V_39 = F_9 ( V_11 -> V_39 , V_34 [ 0 ] , V_34 [ 1 ] ) ;
return 0 ;
}
static bool F_14 ( struct V_5 * V_6 , unsigned int V_40 )
{
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return true ;
}
return false ;
}
static bool F_15 ( struct V_5 * V_6 , unsigned int V_40 )
{
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return true ;
}
return false ;
}
static bool F_16 ( struct V_5 * V_6 , unsigned int V_40 )
{
switch ( V_40 ) {
case V_41 :
case V_64 :
case V_65 :
return true ;
}
return false ;
}
static T_3 F_17 ( int V_66 , void * V_67 )
{
struct V_4 * V_4 = V_67 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_68 , V_69 , V_70 ;
F_18 ( V_4 -> V_10 , V_41 , & V_69 ) ;
F_4 ( V_6 , L_6 , V_66 , V_69 ) ;
if ( V_69 & V_71 ) {
F_8 ( V_6 , L_7 ) ;
V_70 = V_72 ;
for ( V_68 = 0 ; V_68 < V_73 ; V_68 ++ )
F_19 ( V_4 -> V_74 [ V_68 ] ,
V_70 , NULL ) ;
}
if ( V_69 & V_75 ) {
F_20 ( V_6 , L_8 ) ;
V_70 = V_76 ;
for ( V_68 = 0 ; V_68 < V_73 ; V_68 ++ )
F_19 ( V_4 -> V_74 [ V_68 ] ,
V_70 , NULL ) ;
}
F_21 ( V_4 -> V_10 , V_63 , 0 ) ;
return V_77 ;
}
static int F_22 ( struct V_78 * V_79 ,
const struct V_80 * V_33 )
{
struct V_5 * V_6 = & V_79 -> V_6 ;
struct V_81 * V_82 = F_23 ( V_6 ) ;
struct V_27 * V_83 ;
struct V_4 * V_4 ;
int V_68 , V_35 ;
V_4 = F_24 ( V_6 , sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 )
return - V_85 ;
F_25 ( V_79 , V_4 ) ;
V_4 -> V_6 = V_6 ;
V_83 = V_4 -> V_32 ;
memcpy ( V_83 , V_86 , sizeof( V_86 ) ) ;
V_83 [ V_36 ] . V_39 = 1800000 ;
V_4 -> V_10 = F_26 ( V_79 , & V_87 ) ;
if ( F_27 ( V_4 -> V_10 ) ) {
V_35 = F_28 ( V_4 -> V_10 ) ;
F_13 ( V_6 , L_9 , V_35 ) ;
return V_35 ;
}
for ( V_68 = 0 ; V_68 < V_73 ; V_68 ++ ) {
struct V_27 * V_11 = & V_4 -> V_32 [ V_68 ] ;
struct V_28 V_29 = { } ;
if ( V_82 )
V_29 . V_82 = & V_82 [ V_68 ] ;
V_29 . V_6 = V_6 ;
V_29 . V_30 = V_4 ;
V_4 -> V_74 [ V_68 ] = F_29 ( V_6 , V_11 ,
& V_29 ) ;
if ( F_27 ( V_4 -> V_74 [ V_68 ] ) ) {
V_35 = F_28 ( V_4 -> V_74 [ V_68 ] ) ;
F_13 ( V_6 , L_10 ,
V_11 -> V_20 , V_35 ) ;
return V_35 ;
}
}
F_21 ( V_4 -> V_10 , V_63 , 0 ) ;
if ( V_79 -> V_66 ) {
V_35 = F_30 ( V_6 , V_79 -> V_66 , NULL ,
F_17 ,
V_88 | V_89 ,
V_79 -> V_20 , V_4 ) ;
if ( V_35 ) {
F_13 ( V_6 , L_11 , V_35 ) ;
return V_35 ;
}
}
return 0 ;
}
