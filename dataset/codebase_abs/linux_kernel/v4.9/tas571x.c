static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return V_2 -> V_7 -> V_8 ;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return 4 ;
default:
return 1 ;
}
}
static int F_2 ( void * V_16 , unsigned int V_3 ,
unsigned int V_17 )
{
struct V_18 * V_19 = V_16 ;
struct V_1 * V_2 = F_3 ( V_19 ) ;
unsigned int V_20 , V_21 ;
T_1 V_22 [ 5 ] ;
int V_23 ;
V_21 = F_1 ( V_2 , V_3 ) ;
V_22 [ 0 ] = V_3 ;
for ( V_20 = V_21 ; V_20 >= 1 ; -- V_20 ) {
V_22 [ V_20 ] = V_17 ;
V_17 >>= 8 ;
}
V_23 = F_4 ( V_19 , V_22 , V_21 + 1 ) ;
if ( V_23 == V_21 + 1 )
return 0 ;
else if ( V_23 < 0 )
return V_23 ;
else
return - V_24 ;
}
static int F_5 ( void * V_16 , unsigned int V_3 ,
unsigned int * V_17 )
{
struct V_18 * V_19 = V_16 ;
struct V_1 * V_2 = F_3 ( V_19 ) ;
T_1 V_25 , V_26 [ 4 ] ;
struct V_27 V_28 [ 2 ] ;
unsigned int V_21 ;
unsigned int V_20 ;
int V_23 ;
V_21 = F_1 ( V_2 , V_3 ) ;
V_25 = V_3 ;
V_28 [ 0 ] . V_29 = V_19 -> V_29 ;
V_28 [ 0 ] . V_30 = sizeof( V_25 ) ;
V_28 [ 0 ] . V_22 = & V_25 ;
V_28 [ 0 ] . V_31 = 0 ;
V_28 [ 1 ] . V_29 = V_19 -> V_29 ;
V_28 [ 1 ] . V_30 = V_21 ;
V_28 [ 1 ] . V_22 = V_26 ;
V_28 [ 1 ] . V_31 = V_32 ;
V_23 = F_6 ( V_19 -> V_33 , V_28 , F_7 ( V_28 ) ) ;
if ( V_23 < 0 )
return V_23 ;
else if ( V_23 != F_7 ( V_28 ) )
return - V_24 ;
* V_17 = 0 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
* V_17 <<= 8 ;
* V_17 |= V_26 [ V_20 ] ;
}
return 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
unsigned int V_3 , const long V_34 [] , T_2 V_30 )
{
T_2 V_20 ;
T_1 * V_22 , * V_35 ;
int V_23 ;
T_2 V_36 = 1 + V_30 * sizeof( V_37 ) ;
V_22 = F_9 ( V_36 , V_38 | V_39 ) ;
if ( ! V_22 )
return - V_40 ;
V_22 [ 0 ] = V_3 ;
for ( V_20 = 0 , V_35 = V_22 + 1 ; V_20 < V_30 ; V_20 ++ , V_35 += sizeof( V_37 ) )
F_10 ( V_34 [ V_20 ] , V_35 ) ;
V_23 = F_4 ( V_19 , V_22 , V_36 ) ;
F_11 ( V_22 ) ;
if ( V_23 == V_36 )
return 0 ;
else if ( V_23 < 0 )
return V_23 ;
else
return - V_24 ;
}
static int F_12 ( struct V_18 * V_19 ,
unsigned int V_3 , long V_34 [] , T_2 V_30 )
{
unsigned int V_20 ;
T_1 V_25 ;
T_1 * V_26 , * V_35 ;
struct V_27 V_28 [ 2 ] ;
unsigned int V_41 = V_30 * sizeof( V_37 ) ;
int V_23 ;
V_26 = F_9 ( V_41 , V_38 | V_39 ) ;
if ( ! V_26 )
return - V_40 ;
V_25 = V_3 ;
V_28 [ 0 ] . V_29 = V_19 -> V_29 ;
V_28 [ 0 ] . V_30 = sizeof( V_25 ) ;
V_28 [ 0 ] . V_22 = & V_25 ;
V_28 [ 0 ] . V_31 = 0 ;
V_28 [ 1 ] . V_29 = V_19 -> V_29 ;
V_28 [ 1 ] . V_30 = V_41 ;
V_28 [ 1 ] . V_22 = V_26 ;
V_28 [ 1 ] . V_31 = V_32 ;
V_23 = F_6 ( V_19 -> V_33 , V_28 , F_7 ( V_28 ) ) ;
if ( V_23 < 0 )
goto V_42;
else if ( V_23 != F_7 ( V_28 ) ) {
V_23 = - V_24 ;
goto V_42;
}
for ( V_20 = 0 , V_35 = V_26 ; V_20 < V_30 ; V_20 ++ , V_35 += sizeof( V_37 ) )
V_34 [ V_20 ] = F_13 ( V_35 ) ;
V_42:
F_11 ( V_26 ) ;
return V_23 ;
}
static int F_14 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
int V_47 = V_44 -> V_48 >> 16 ;
V_46 -> type = V_49 ;
V_46 -> V_50 = V_47 ;
V_46 -> V_17 . integer . V_51 = 0 ;
V_46 -> V_17 . integer . V_52 = 0xffffffff ;
return 0 ;
}
static int F_15 ( struct V_43 * V_44 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = F_16 ( V_44 ) ;
struct V_18 * V_57 = F_17 ( V_56 -> V_58 ) ;
int V_47 = V_44 -> V_48 >> 16 ;
int V_59 = V_44 -> V_48 & 0xffff ;
return F_12 ( V_57 , V_59 ,
V_54 -> V_17 . integer . V_17 , V_47 ) ;
}
static int F_18 ( struct V_43 * V_44 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = F_16 ( V_44 ) ;
struct V_18 * V_57 = F_17 ( V_56 -> V_58 ) ;
int V_47 = V_44 -> V_48 >> 16 ;
int V_59 = V_44 -> V_48 & 0xffff ;
return F_8 ( V_57 , V_59 ,
V_54 -> V_17 . integer . V_17 , V_47 ) ;
}
static int F_19 ( struct V_60 * V_61 , unsigned int V_62 )
{
struct V_1 * V_2 = F_20 ( V_61 -> V_56 ) ;
V_2 -> V_62 = V_62 ;
return 0 ;
}
static int F_21 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_20 ( V_61 -> V_56 ) ;
T_3 V_67 ;
switch ( V_2 -> V_62 & V_68 ) {
case V_69 :
V_67 = 0x00 ;
break;
case V_70 :
V_67 = 0x03 ;
break;
case V_71 :
V_67 = 0x06 ;
break;
default:
return - V_72 ;
}
if ( F_22 ( V_66 ) >= 24 )
V_67 += 2 ;
else if ( F_22 ( V_66 ) >= 20 )
V_67 += 1 ;
return F_23 ( V_2 -> V_73 , V_74 ,
V_75 , V_67 ) ;
}
static int F_24 ( struct V_60 * V_61 , int V_76 )
{
struct V_55 * V_56 = V_61 -> V_56 ;
T_4 V_77 ;
int V_23 ;
V_77 = V_76 ? V_78 : 0 ;
V_23 = F_25 ( V_56 ,
V_79 ,
V_78 ,
V_77 ) ;
F_26 ( 1000 , 2000 ) ;
return V_23 ;
}
static int F_27 ( struct V_55 * V_56 ,
enum V_80 V_81 )
{
struct V_1 * V_2 = F_20 ( V_56 ) ;
int V_23 ;
switch ( V_81 ) {
case V_82 :
break;
case V_83 :
break;
case V_84 :
if ( F_28 ( V_56 ) == V_85 ) {
if ( ! F_29 ( V_2 -> V_86 ) ) {
V_23 = F_30 ( V_2 -> V_86 ) ;
if ( V_23 ) {
F_31 ( V_56 -> V_58 ,
L_1 ,
V_23 ) ;
return V_23 ;
}
}
}
break;
case V_85 :
if ( ! F_29 ( V_2 -> V_86 ) )
F_32 ( V_2 -> V_86 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_18 * V_19 ,
const struct V_87 * V_88 )
{
struct V_1 * V_2 ;
struct V_89 * V_58 = & V_19 -> V_58 ;
const struct V_90 * V_91 ;
int V_20 , V_23 ;
V_2 = F_34 ( V_58 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_40 ;
F_35 ( V_19 , V_2 ) ;
V_91 = F_36 ( V_92 , V_58 ) ;
if ( V_91 )
V_2 -> V_7 = V_91 -> V_93 ;
else
V_2 -> V_7 = ( void * ) V_88 -> V_94 ;
V_2 -> V_86 = F_37 ( V_58 , L_2 ) ;
if ( F_29 ( V_2 -> V_86 ) && F_38 ( V_2 -> V_86 ) != - V_95 ) {
F_31 ( V_58 , L_3 ,
F_38 ( V_2 -> V_86 ) ) ;
return F_38 ( V_2 -> V_86 ) ;
}
F_39 ( V_2 -> V_7 -> V_96 > V_97 ) ;
for ( V_20 = 0 ; V_20 < V_2 -> V_7 -> V_96 ; V_20 ++ )
V_2 -> V_98 [ V_20 ] . V_99 = V_2 -> V_7 -> V_100 [ V_20 ] ;
V_23 = F_40 ( V_58 , V_2 -> V_7 -> V_96 ,
V_2 -> V_98 ) ;
if ( V_23 ) {
F_31 ( V_58 , L_4 , V_23 ) ;
return V_23 ;
}
V_23 = F_41 ( V_2 -> V_7 -> V_96 ,
V_2 -> V_98 ) ;
if ( V_23 ) {
F_31 ( V_58 , L_5 , V_23 ) ;
return V_23 ;
}
V_2 -> V_73 = F_42 ( V_58 , NULL , V_19 ,
V_2 -> V_7 -> V_101 ) ;
if ( F_29 ( V_2 -> V_73 ) )
return F_38 ( V_2 -> V_73 ) ;
V_2 -> V_102 = F_43 ( V_58 , L_6 , V_103 ) ;
if ( F_29 ( V_2 -> V_102 ) ) {
F_31 ( V_58 , L_7 ,
F_38 ( V_2 -> V_102 ) ) ;
return F_38 ( V_2 -> V_102 ) ;
}
V_2 -> V_104 = F_43 ( V_58 , L_8 ,
V_105 ) ;
if ( F_29 ( V_2 -> V_104 ) ) {
F_31 ( V_58 , L_9 ,
F_38 ( V_2 -> V_104 ) ) ;
return F_38 ( V_2 -> V_104 ) ;
} else if ( V_2 -> V_104 ) {
F_26 ( 100 , 200 ) ;
F_44 ( V_2 -> V_104 , 0 ) ;
F_26 ( 13500 , 20000 ) ;
}
V_23 = F_45 ( V_2 -> V_73 , V_106 , 0 ) ;
if ( V_23 )
return V_23 ;
F_26 ( 50000 , 60000 ) ;
memcpy ( & V_2 -> V_107 , & V_108 , sizeof( V_2 -> V_107 ) ) ;
V_2 -> V_107 . V_109 . V_110 = V_2 -> V_7 -> V_110 ;
V_2 -> V_107 . V_109 . V_111 = V_2 -> V_7 -> V_111 ;
if ( V_2 -> V_7 -> V_8 == 2 ) {
V_23 = F_23 ( V_2 -> V_73 , V_4 , 1 , 0 ) ;
if ( V_23 )
return V_23 ;
}
return F_46 ( & V_19 -> V_58 , & V_2 -> V_107 ,
& V_112 , 1 ) ;
}
static int F_47 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_3 ( V_19 ) ;
F_48 ( & V_19 -> V_58 ) ;
F_49 ( V_2 -> V_7 -> V_96 , V_2 -> V_98 ) ;
return 0 ;
}
