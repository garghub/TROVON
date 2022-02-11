static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_7 , unsigned int V_8 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_11 * V_12 ;
unsigned int V_13 ;
T_1 V_14 ;
int V_15 ;
if ( V_6 == V_16 ) {
V_12 = & V_2 -> V_17 [ V_7 ] ;
V_15 = F_2 ( V_2 ,
V_8 * V_7 + V_18 ,
& V_14 , sizeof( V_14 ) ) ;
} else {
V_12 = & V_2 -> V_19 [ V_7 ] ;
V_15 = F_3 ( V_2 ,
V_8 * V_7 + V_20 ,
& V_14 , sizeof( V_14 ) ) ;
}
if ( V_15 < 0 )
return V_15 ;
V_10 -> V_21 = V_10 -> V_22 = F_4 ( V_14 ) ;
V_15 = F_5 ( V_2 , & V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_10 -> V_23 = F_6 ( V_13 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static void F_8 ( struct V_9 * V_10 )
{
V_10 -> V_24 = 2 ;
V_10 -> V_25 = V_26 ;
V_10 -> V_27 = 4 * V_10 -> V_22 ;
V_10 -> V_28 = V_10 -> V_27 * 2048 ;
V_10 -> V_29 = V_10 -> V_28 * V_10 -> V_24 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_4 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
enum V_5 V_6 ;
struct V_11 * V_12 ;
T_1 V_14 [ 2 ] ;
unsigned int V_32 , V_8 ;
int V_15 ;
V_10 -> V_33 = V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 ;
if ( V_31 -> V_12 == V_40 ) {
V_10 -> V_41 = V_42 ;
V_6 = V_16 ;
V_12 = & V_2 -> V_17 [ V_31 -> V_43 -> V_44 ] ;
V_15 = F_2 ( V_2 , V_45 , V_14 ,
sizeof( V_14 ) ) ;
} else {
V_10 -> V_41 = V_46 ;
V_6 = V_47 ;
V_12 = & V_2 -> V_19 [ V_31 -> V_43 -> V_44 ] ;
V_15 = F_3 ( V_2 , V_48 , V_14 ,
sizeof( V_14 ) ) ;
}
if ( V_15 < 0 )
return V_15 ;
V_32 = F_10 (unsigned int, be32_to_cpu(reg[0]), MAX_STREAMS) ;
if ( V_31 -> V_43 -> V_44 >= V_32 )
return - V_49 ;
V_8 = F_4 ( V_14 [ 1 ] ) * 4 ;
V_15 = F_1 ( V_2 , V_31 -> V_4 , V_6 ,
V_31 -> V_43 -> V_44 , V_8 ) ;
if ( V_15 < 0 )
return V_15 ;
F_8 ( V_10 ) ;
return F_11 ( V_12 , V_4 ) ;
}
static int F_12 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
int V_15 ;
V_15 = F_13 ( V_2 ) ;
if ( V_15 < 0 )
goto V_51;
V_15 = F_9 ( V_2 , V_31 ) ;
if ( V_15 < 0 )
goto V_52;
F_14 ( V_31 ) ;
V_51:
return V_15 ;
V_52:
F_15 ( V_2 ) ;
return V_15 ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_30 * V_31 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_31 -> V_43 -> V_44 ] ;
int V_15 ;
V_15 = F_18 ( V_31 ,
F_19 ( V_54 ) ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_31 -> V_4 -> V_55 -> V_56 == V_57 ) {
F_20 ( & V_2 -> V_58 ) ;
V_2 -> V_59 ++ ;
F_21 ( & V_2 -> V_58 ) ;
}
F_22 ( V_12 , F_23 ( V_54 ) ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_31 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_31 -> V_43 -> V_44 ] ;
int V_15 ;
V_15 = F_18 ( V_31 ,
F_19 ( V_54 ) ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_31 -> V_4 -> V_55 -> V_56 == V_57 ) {
F_20 ( & V_2 -> V_58 ) ;
V_2 -> V_59 ++ ;
F_21 ( & V_2 -> V_58 ) ;
}
F_22 ( V_12 , F_23 ( V_54 ) ) ;
return 0 ;
}
static int F_25 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
F_20 ( & V_2 -> V_58 ) ;
if ( V_31 -> V_4 -> V_55 -> V_56 != V_57 )
V_2 -> V_59 -- ;
F_26 ( V_2 ) ;
F_21 ( & V_2 -> V_58 ) ;
return F_27 ( V_31 ) ;
}
static int F_28 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
F_20 ( & V_2 -> V_58 ) ;
if ( V_31 -> V_4 -> V_55 -> V_56 != V_57 )
V_2 -> V_59 -- ;
F_26 ( V_2 ) ;
F_21 ( & V_2 -> V_58 ) ;
return F_27 ( V_31 ) ;
}
static int F_29 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_31 -> V_43 -> V_44 ] ;
int V_15 ;
F_20 ( & V_2 -> V_58 ) ;
V_15 = F_30 ( V_2 , V_31 -> V_4 -> V_13 ) ;
F_21 ( & V_2 -> V_58 ) ;
if ( V_15 >= 0 )
F_31 ( V_12 ) ;
return 0 ;
}
static int F_32 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_31 -> V_43 -> V_44 ] ;
int V_15 ;
F_20 ( & V_2 -> V_58 ) ;
V_15 = F_30 ( V_2 , V_31 -> V_4 -> V_13 ) ;
F_21 ( & V_2 -> V_58 ) ;
if ( V_15 >= 0 )
F_31 ( V_12 ) ;
return V_15 ;
}
static int F_33 ( struct V_30 * V_31 , int V_60 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_31 -> V_43 -> V_44 ] ;
switch ( V_60 ) {
case V_61 :
F_34 ( V_12 , V_31 ) ;
break;
case V_62 :
F_34 ( V_12 , NULL ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_35 ( struct V_30 * V_31 , int V_60 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_31 -> V_43 -> V_44 ] ;
switch ( V_60 ) {
case V_61 :
F_34 ( V_12 , V_31 ) ;
break;
case V_62 :
F_34 ( V_12 , NULL ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static T_2 F_36 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_31 -> V_43 -> V_44 ] ;
return F_37 ( V_12 ) ;
}
static T_2 F_38 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_50 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_31 -> V_43 -> V_44 ] ;
return F_37 ( V_12 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
static struct V_64 V_65 = {
. V_66 = F_12 ,
. V_67 = F_16 ,
. V_68 = V_69 ,
. V_54 = F_17 ,
. V_70 = F_25 ,
. V_71 = F_29 ,
. V_72 = F_33 ,
. V_73 = F_36 ,
. V_74 = V_75 ,
. V_76 = V_77 ,
} ;
static struct V_64 V_78 = {
. V_66 = F_12 ,
. V_67 = F_16 ,
. V_68 = V_69 ,
. V_54 = F_24 ,
. V_70 = F_28 ,
. V_71 = F_32 ,
. V_72 = F_35 ,
. V_73 = F_38 ,
. V_74 = V_75 ,
. V_76 = V_77 ,
} ;
T_1 V_14 ;
struct V_79 * V_43 ;
unsigned int V_80 , V_81 , V_82 , V_83 , V_84 ;
int V_15 ;
if ( V_2 -> V_85 ) {
V_81 = V_82 = 2 ;
} else {
V_81 = V_82 = 0 ;
V_15 = F_2 ( V_2 , V_45 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_81 = F_10 (unsigned int, be32_to_cpu(reg), MAX_STREAMS) ;
V_15 = F_3 ( V_2 , V_48 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_82 = F_10 (unsigned int, be32_to_cpu(reg), MAX_STREAMS) ;
}
for ( V_80 = 0 ; V_80 < V_86 ; V_80 ++ ) {
V_83 = V_84 = 0 ;
if ( V_80 < V_81 )
V_83 = 1 ;
if ( V_80 < V_82 )
V_84 = 1 ;
if ( V_83 == 0 && V_84 == 0 )
break;
V_15 = F_40 ( V_2 -> V_87 , L_1 , V_80 , V_84 , V_83 ,
& V_43 ) ;
if ( V_15 < 0 )
return V_15 ;
V_43 -> V_50 = V_2 ;
strcpy ( V_43 -> V_88 , V_2 -> V_87 -> V_89 ) ;
if ( V_83 > 0 )
F_41 ( V_43 , V_40 ,
& V_65 ) ;
if ( V_84 > 0 )
F_41 ( V_43 , V_90 ,
& V_78 ) ;
}
return 0 ;
}
