static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
struct V_1 * V_9 ;
F_2 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( & V_6 -> V_11 , V_4 ) ;
if ( V_9 )
F_4 ( & V_9 -> V_12 ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( ! V_9 ) {
F_6 ( V_3 , L_1 ,
V_4 ) ;
return NULL ;
}
return V_9 ;
}
void F_7 ( struct V_1 * V_9 )
{
if ( F_8 ( & V_9 -> V_12 ) )
F_9 ( & V_9 -> free ) ;
}
void F_10 ( struct V_2 * V_3 , T_1 V_4 , int V_13 )
{
struct V_1 * V_9 = F_1 ( V_3 , V_4 ) ;
struct V_14 * V_15 ;
if ( ! V_9 )
return;
switch ( V_9 -> V_16 ) {
case V_17 :
V_15 = (struct V_14 * ) V_9 ;
V_15 -> V_18 ( V_15 , V_13 ) ;
break;
default:
F_6 ( V_3 , L_2 , V_4 ) ;
}
F_7 ( V_9 ) ;
}
void F_11 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_23 . V_24 ;
int V_25 = F_12 ( V_22 -> V_26 ) & V_27 ;
struct V_1 * V_9 = F_1 ( V_3 , V_25 ) ;
struct V_14 * V_15 =
F_13 ( V_9 , struct V_14 , V_9 ) ;
struct V_28 V_29 ;
if ( ! V_15 ) {
F_6 ( V_3 , L_3 ,
V_25 ) ;
return;
}
V_29 . V_30 = V_20 -> V_31 ;
V_29 . V_32 = ( F_12 ( V_22 -> V_26 ) >> V_33 ) &
( V_34 | V_35 | V_36 ) ;
V_29 . V_37 = F_12 (
V_22 -> V_37 ) ;
F_14 ( V_3 ,
L_4 ,
V_20 -> V_31 , V_29 . V_32 ) ;
switch ( V_20 -> V_31 ) {
case V_38 :
V_29 . V_39 . V_40 =
F_12 ( V_22 -> V_39 . V_40 ) ;
V_29 . V_39 . V_41 =
F_15 ( V_22 -> V_39 . V_42 ) ;
V_29 . V_39 . V_43 =
F_12 ( V_22 -> V_39 . V_43 ) ;
V_29 . V_39 . V_44 =
F_16 ( V_22 -> V_39 . V_44 ) ;
F_14 ( V_3 ,
L_5 ,
V_25 , V_29 . V_39 . V_40 ) ;
F_14 ( V_3 ,
L_6 ,
V_29 . V_39 . V_43 ) ;
F_14 ( V_3 ,
L_7 ,
V_29 . V_39 . V_44 ) ;
F_14 ( V_3 ,
L_8 ,
V_29 . V_37 ) ;
break;
case V_45 :
V_29 . V_46 . V_47 =
F_15 ( V_22 -> V_46 . V_47 ) ;
V_29 . V_46 . V_41 =
F_15 ( V_22 -> V_46 . V_42 ) ;
F_14 ( V_3 ,
L_9 ,
V_25 , V_29 . V_46 . V_47 ) ;
F_14 ( V_3 ,
L_8 ,
V_29 . V_37 ) ;
break;
default:
F_6 ( V_3 ,
L_10 ,
V_20 -> V_31 , V_25 ) ;
}
if ( V_15 -> V_48 ) {
V_15 -> V_48 ( V_15 , & V_29 ) ;
} else {
F_17 ( V_3 ,
L_11 ,
V_25 ) ;
}
F_7 ( V_9 ) ;
}
int F_18 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_49 * V_50 ,
int V_51 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
struct V_52 V_53 ;
struct V_54 V_55 ;
struct V_56 V_57 ;
int V_58 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_50 -> V_59 . V_60 = F_19 ( V_61 ) ;
V_58 = F_20 ( V_3 , V_50 , V_51 , & V_53 , sizeof( V_53 ) ) ;
if ( V_58 ) {
F_6 ( V_3 , L_12 , V_58 ) ;
return V_58 ;
}
if ( V_53 . V_59 . V_62 ) {
F_6 ( V_3 , L_13 ,
F_21 ( & V_3 -> V_63 ) ) ;
return F_22 ( & V_53 . V_59 ) ;
}
V_15 -> V_25 = F_12 ( V_53 . V_25 ) & 0xffffff ;
F_14 ( V_3 , L_14 , V_15 -> V_25 ) ;
V_15 -> V_9 . V_16 = V_17 ;
F_23 ( & V_6 -> V_10 ) ;
V_58 = F_24 ( & V_6 -> V_11 , V_15 -> V_25 , V_15 ) ;
F_25 ( & V_6 -> V_10 ) ;
if ( V_58 ) {
F_6 ( V_3 , L_15 , V_58 ) ;
goto V_64;
}
V_58 = F_26 ( V_3 , V_15 ) ;
if ( V_58 )
F_14 ( V_3 , L_16 ,
V_15 -> V_25 ) ;
V_15 -> V_65 = V_66 -> V_65 ;
F_27 ( & V_15 -> V_9 . V_12 , 1 ) ;
F_4 ( & V_3 -> V_63 ) ;
F_28 ( & V_15 -> V_9 . free ) ;
return 0 ;
V_64:
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_55 . V_59 . V_60 = F_19 ( V_67 ) ;
V_55 . V_25 = F_29 ( V_15 -> V_25 ) ;
F_20 ( V_3 , & V_55 , sizeof( V_55 ) , & V_53 , sizeof( V_57 ) ) ;
return V_58 ;
}
int F_30 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_54 V_50 ;
struct V_56 V_53 ;
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
unsigned long V_32 ;
int V_58 ;
F_31 ( V_3 , V_15 ) ;
F_32 ( & V_6 -> V_10 , V_32 ) ;
F_33 ( & V_6 -> V_11 , V_15 -> V_25 ) ;
F_34 ( & V_6 -> V_10 , V_32 ) ;
F_7 ( (struct V_1 * ) V_15 ) ;
F_35 ( & V_15 -> V_9 . free ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_50 . V_59 . V_60 = F_19 ( V_67 ) ;
V_50 . V_25 = F_29 ( V_15 -> V_25 ) ;
V_58 = F_20 ( V_3 , & V_50 , sizeof( V_50 ) , & V_53 , sizeof( V_53 ) ) ;
if ( V_58 )
return V_58 ;
if ( V_53 . V_59 . V_62 )
return F_22 ( & V_53 . V_59 ) ;
F_36 ( & V_3 -> V_63 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 , enum V_68 V_69 ,
enum V_68 V_70 ,
struct V_71 * V_50 , int V_72 ,
struct V_14 * V_15 )
{
static const T_2 V_73 [ V_74 ] [ V_74 ] = {
[ V_75 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
[ V_79 ] = V_80 ,
} ,
[ V_79 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
[ V_79 ] = V_81 ,
[ V_82 ] = V_83 ,
} ,
[ V_82 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
[ V_84 ] = V_85 ,
} ,
[ V_84 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
[ V_84 ] = V_86 ,
} ,
[ V_87 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
} ,
[ V_88 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
[ V_84 ] = V_89 ,
} ,
[ V_77 ] = {
[ V_75 ] = V_76 ,
[ V_77 ] = V_78 ,
}
} ;
struct V_90 V_53 ;
int V_58 = 0 ;
T_2 V_91 ;
if ( V_69 >= V_74 || V_70 >= V_74 ||
! V_73 [ V_69 ] [ V_70 ] )
return - V_92 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_91 = V_73 [ V_69 ] [ V_70 ] ;
V_50 -> V_59 . V_60 = F_19 ( V_91 ) ;
V_50 -> V_25 = F_29 ( V_15 -> V_25 ) ;
V_58 = F_20 ( V_3 , V_50 , sizeof( * V_50 ) , & V_53 , sizeof( V_53 ) ) ;
if ( V_58 )
return V_58 ;
return F_22 ( & V_53 . V_59 ) ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
F_39 ( & V_6 -> V_10 ) ;
F_40 ( & V_6 -> V_11 , V_93 ) ;
F_41 ( V_3 ) ;
}
void F_42 ( struct V_2 * V_3 )
{
F_43 ( V_3 ) ;
}
int F_44 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_94 * V_53 , int V_95 )
{
struct V_96 V_50 ;
int V_58 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( V_53 , 0 , V_95 ) ;
V_50 . V_59 . V_60 = F_19 ( V_97 ) ;
V_50 . V_25 = F_29 ( V_15 -> V_25 ) ;
V_58 = F_20 ( V_3 , & V_50 , sizeof( V_50 ) , V_53 , V_95 ) ;
if ( V_58 )
return V_58 ;
if ( V_53 -> V_59 . V_62 )
return F_22 ( & V_53 -> V_59 ) ;
return V_58 ;
}
int F_45 ( struct V_2 * V_3 , T_1 * V_98 )
{
struct V_99 V_50 ;
struct V_100 V_53 ;
int V_58 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_50 . V_59 . V_60 = F_19 ( V_101 ) ;
V_58 = F_20 ( V_3 , & V_50 , sizeof( V_50 ) , & V_53 , sizeof( V_53 ) ) ;
if ( V_58 )
return V_58 ;
if ( V_53 . V_59 . V_62 )
V_58 = F_22 ( & V_53 . V_59 ) ;
else
* V_98 = F_12 ( V_53 . V_98 ) ;
return V_58 ;
}
int F_46 ( struct V_2 * V_3 , T_1 V_98 )
{
struct V_102 V_50 ;
struct V_103 V_53 ;
int V_58 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_50 . V_59 . V_60 = F_19 ( V_104 ) ;
V_50 . V_98 = F_29 ( V_98 ) ;
V_58 = F_20 ( V_3 , & V_50 , sizeof( V_50 ) , & V_53 , sizeof( V_53 ) ) ;
if ( V_58 )
return V_58 ;
if ( V_53 . V_59 . V_62 )
V_58 = F_22 ( & V_53 . V_59 ) ;
return V_58 ;
}
int F_47 ( struct V_2 * V_3 , T_1 V_25 ,
T_3 V_32 , int error )
{
struct V_105 V_50 ;
struct V_106 V_53 ;
int V_58 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_50 . V_59 . V_60 = F_19 ( V_107 ) ;
V_50 . V_59 . V_108 = 0 ;
V_32 &= ( V_109 |
V_110 |
V_111 ) ;
V_32 |= ( error ? V_112 : 0 ) ;
V_50 . V_26 = F_29 ( ( V_25 & V_27 ) |
( V_32 << V_33 ) ) ;
V_58 = F_20 ( V_3 , & V_50 , sizeof( V_50 ) , & V_53 , sizeof( V_53 ) ) ;
if ( V_58 )
return V_58 ;
if ( V_53 . V_59 . V_62 )
V_58 = F_22 ( & V_53 . V_59 ) ;
return V_58 ;
}
