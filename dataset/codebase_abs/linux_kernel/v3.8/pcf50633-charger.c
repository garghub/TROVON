int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 = 0 ;
T_1 V_8 ;
int V_9 = 1 ;
T_1 V_10 , V_11 ;
unsigned int V_12 ;
if ( V_3 >= 1000 ) {
V_8 = V_13 ;
V_3 = 1000 ;
} else if ( V_3 >= 500 ) {
V_8 = V_14 ;
V_3 = 500 ;
} else if ( V_3 >= 100 ) {
V_8 = V_15 ;
V_3 = 100 ;
} else {
V_8 = V_16 ;
V_9 = 0 ;
V_3 = 0 ;
}
V_7 = F_3 ( V_2 , V_17 ,
V_18 , V_8 ) ;
if ( V_7 )
F_4 ( V_2 -> V_19 , L_1 , V_3 ) ;
else
F_5 ( V_2 -> V_19 , L_2 , V_3 ) ;
if ( V_5 -> V_2 -> V_20 -> V_21 ) {
V_12 = ( V_3 << 8 ) / V_5 -> V_2 -> V_20 -> V_21 ;
if ( V_12 > 255 )
V_12 = 255 ;
F_6 ( V_5 -> V_2 , V_22 , V_12 ) ;
}
V_10 = F_7 ( V_5 -> V_2 , V_23 ) ;
V_11 = ( V_10 & V_24 ) ;
if ( V_11 != V_25 )
F_3 ( V_2 , V_26 ,
V_27 , V_27 ) ;
else {
F_8 ( V_2 , V_26 ,
V_27 ) ;
F_3 ( V_2 , V_26 ,
V_27 , V_27 ) ;
}
F_9 ( & V_5 -> V_28 ) ;
return V_7 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_29 = 0 ;
T_1 V_11 ;
if ( ! V_5 )
return 0 ;
V_11 = F_7 ( V_5 -> V_2 , V_23 )
& V_24 ;
if ( V_5 -> V_30 )
V_29 |= V_31 ;
if ( V_11 == V_32 ||
V_11 == V_33 ||
V_11 == V_34 ||
V_11 == V_35 )
V_29 |= V_36 ;
if ( V_5 -> V_37 )
V_29 |= V_38 ;
if ( V_11 == V_39 ||
V_11 == V_40 ||
V_11 == V_41 ||
V_11 == V_42 )
V_29 |= V_43 ;
return V_29 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_30 ;
}
static T_2
F_12 ( struct V_44 * V_19 , struct V_45 * V_46 , char * V_47 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
T_1 V_10 = F_7 ( V_5 -> V_2 , V_23 ) ;
T_1 V_11 = ( V_10 & V_24 ) ;
return sprintf ( V_47 , L_3 , V_11 ) ;
}
static T_2
F_14 ( struct V_44 * V_19 , struct V_45 * V_46 , char * V_47 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
T_1 V_48 = F_7 ( V_5 -> V_2 , V_17 ) &
V_18 ;
unsigned int V_3 ;
if ( V_48 == V_13 )
V_3 = 1000 ;
else if ( V_48 == V_14 )
V_3 = 500 ;
else if ( V_48 == V_15 )
V_3 = 100 ;
else
V_3 = 0 ;
return sprintf ( V_47 , L_4 , V_3 ) ;
}
static T_2 F_15 ( struct V_44 * V_19 ,
struct V_45 * V_46 , const char * V_47 , T_3 V_49 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
unsigned long V_3 ;
int V_7 ;
V_7 = F_16 ( V_47 , 10 , & V_3 ) ;
if ( V_7 )
return - V_50 ;
F_1 ( V_5 -> V_2 , V_3 ) ;
return V_49 ;
}
static T_2
F_17 ( struct V_44 * V_19 , struct V_45 * V_46 , char * V_47 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
T_1 V_12 = F_7 ( V_5 -> V_2 , V_22 ) ;
unsigned int V_3 ;
if ( ! V_5 -> V_2 -> V_20 -> V_21 )
return - V_51 ;
V_3 = ( V_5 -> V_2 -> V_20 -> V_21 * V_12 ) >> 8 ;
return sprintf ( V_47 , L_4 , V_3 ) ;
}
static T_2 F_18 ( struct V_44 * V_19 ,
struct V_45 * V_46 , const char * V_47 , T_3 V_49 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
unsigned long V_3 ;
unsigned int V_12 ;
int V_7 ;
if ( ! V_5 -> V_2 -> V_20 -> V_21 )
return - V_51 ;
V_7 = F_16 ( V_47 , 10 , & V_3 ) ;
if ( V_7 )
return - V_50 ;
V_12 = ( V_3 << 8 ) / V_5 -> V_2 -> V_20 -> V_21 ;
if ( V_12 > 255 )
V_12 = 255 ;
F_6 ( V_5 -> V_2 , V_22 , V_12 ) ;
return V_49 ;
}
static void
F_19 ( int V_52 , void * V_53 )
{
struct V_4 * V_5 = V_53 ;
if ( V_52 == V_54 ) {
V_5 -> V_30 = 1 ;
} else if ( V_52 == V_55 ) {
V_5 -> V_30 = 0 ;
F_1 ( V_5 -> V_2 , 0 ) ;
}
if ( V_52 == V_56 )
V_5 -> V_37 = 1 ;
else if ( V_52 == V_57 )
V_5 -> V_37 = 0 ;
F_9 ( & V_5 -> V_58 ) ;
F_9 ( & V_5 -> V_28 ) ;
F_9 ( & V_5 -> V_59 ) ;
if ( V_5 -> V_2 -> V_20 -> V_60 )
V_5 -> V_2 -> V_20 -> V_60 ( V_5 -> V_2 , V_52 ) ;
}
static int F_20 ( struct V_61 * V_62 ,
enum V_63 V_64 ,
union V_65 * V_66 )
{
struct V_4 * V_5 = F_21 ( V_62 ,
struct V_4 , V_59 ) ;
int V_7 = 0 ;
switch ( V_64 ) {
case V_67 :
V_66 -> V_68 = V_5 -> V_37 ;
break;
default:
V_7 = - V_50 ;
break;
}
return V_7 ;
}
static int F_22 ( struct V_61 * V_62 ,
enum V_63 V_64 ,
union V_65 * V_66 )
{
struct V_4 * V_5 = F_21 ( V_62 , struct V_4 , V_28 ) ;
int V_7 = 0 ;
T_1 V_48 = F_7 ( V_5 -> V_2 , V_17 ) &
V_18 ;
switch ( V_64 ) {
case V_67 :
V_66 -> V_68 = V_5 -> V_30 &&
( V_48 <= V_14 ) ;
break;
default:
V_7 = - V_50 ;
break;
}
return V_7 ;
}
static int F_23 ( struct V_61 * V_62 ,
enum V_63 V_64 ,
union V_65 * V_66 )
{
struct V_4 * V_5 = F_21 ( V_62 , struct V_4 , V_58 ) ;
int V_7 = 0 ;
T_1 V_48 = F_7 ( V_5 -> V_2 , V_17 ) &
V_18 ;
switch ( V_64 ) {
case V_67 :
V_66 -> V_68 = V_5 -> V_30 &&
( V_48 == V_13 ) ;
break;
default:
V_7 = - V_50 ;
break;
}
return V_7 ;
}
static int F_24 ( struct V_69 * V_70 )
{
struct V_4 * V_5 ;
int V_7 ;
int V_71 ;
T_1 V_72 ;
V_5 = F_25 ( sizeof( * V_5 ) , V_73 ) ;
if ( ! V_5 )
return - V_74 ;
F_26 ( V_70 , V_5 ) ;
V_5 -> V_2 = F_27 ( V_70 -> V_19 . V_75 ) ;
for ( V_71 = 0 ; V_71 < F_28 ( V_76 ) ; V_71 ++ )
F_29 ( V_5 -> V_2 , V_76 [ V_71 ] ,
F_19 , V_5 ) ;
V_5 -> V_59 . V_77 = L_5 ;
V_5 -> V_59 . type = V_78 ;
V_5 -> V_59 . V_79 = V_80 ;
V_5 -> V_59 . V_81 = F_28 ( V_80 ) ;
V_5 -> V_59 . V_82 = & F_20 ;
V_5 -> V_59 . V_83 = V_5 -> V_2 -> V_20 -> V_84 ;
V_5 -> V_59 . V_85 = V_5 -> V_2 -> V_20 -> V_86 ;
V_5 -> V_28 . V_77 = L_6 ;
V_5 -> V_28 . type = V_87 ;
V_5 -> V_28 . V_79 = V_80 ;
V_5 -> V_28 . V_81 = F_28 ( V_80 ) ;
V_5 -> V_28 . V_82 = F_22 ;
V_5 -> V_28 . V_83 = V_5 -> V_2 -> V_20 -> V_84 ;
V_5 -> V_28 . V_85 = V_5 -> V_2 -> V_20 -> V_86 ;
V_5 -> V_58 . V_77 = L_7 ;
V_5 -> V_58 . type = V_78 ;
V_5 -> V_58 . V_79 = V_80 ;
V_5 -> V_58 . V_81 = F_28 ( V_80 ) ;
V_5 -> V_58 . V_82 = F_23 ;
V_5 -> V_58 . V_83 = V_5 -> V_2 -> V_20 -> V_84 ;
V_5 -> V_58 . V_85 = V_5 -> V_2 -> V_20 -> V_86 ;
V_7 = F_30 ( & V_70 -> V_19 , & V_5 -> V_59 ) ;
if ( V_7 ) {
F_4 ( V_5 -> V_2 -> V_19 , L_8 ) ;
F_31 ( V_5 ) ;
return V_7 ;
}
V_7 = F_30 ( & V_70 -> V_19 , & V_5 -> V_28 ) ;
if ( V_7 ) {
F_4 ( V_5 -> V_2 -> V_19 , L_9 ) ;
F_32 ( & V_5 -> V_59 ) ;
F_31 ( V_5 ) ;
return V_7 ;
}
V_7 = F_30 ( & V_70 -> V_19 , & V_5 -> V_58 ) ;
if ( V_7 ) {
F_4 ( V_5 -> V_2 -> V_19 , L_10 ) ;
F_32 ( & V_5 -> V_59 ) ;
F_32 ( & V_5 -> V_28 ) ;
F_31 ( V_5 ) ;
return V_7 ;
}
V_7 = F_33 ( & V_70 -> V_19 . V_88 , & V_89 ) ;
if ( V_7 )
F_4 ( V_5 -> V_2 -> V_19 , L_11 ) ;
V_72 = F_7 ( V_5 -> V_2 , V_90 ) ;
if ( V_72 & V_91 )
F_19 ( V_54 , V_5 ) ;
if ( V_72 & V_92 )
F_19 ( V_56 , V_5 ) ;
return 0 ;
}
static int F_34 ( struct V_69 * V_70 )
{
struct V_4 * V_5 = F_2 ( V_70 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < F_28 ( V_76 ) ; V_71 ++ )
F_35 ( V_5 -> V_2 , V_76 [ V_71 ] ) ;
F_36 ( & V_70 -> V_19 . V_88 , & V_89 ) ;
F_32 ( & V_5 -> V_28 ) ;
F_32 ( & V_5 -> V_59 ) ;
F_32 ( & V_5 -> V_58 ) ;
F_31 ( V_5 ) ;
return 0 ;
}
