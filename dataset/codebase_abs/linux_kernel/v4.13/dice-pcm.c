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
static int F_8 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
enum V_5 V_6 ;
struct V_11 * V_12 ;
T_1 V_14 [ 2 ] ;
unsigned int V_26 , V_8 ;
int V_15 ;
if ( V_25 -> V_12 == V_27 ) {
V_10 -> V_28 = V_29 ;
V_6 = V_16 ;
V_12 = & V_2 -> V_17 [ V_25 -> V_30 -> V_31 ] ;
V_15 = F_2 ( V_2 , V_32 , V_14 ,
sizeof( V_14 ) ) ;
} else {
V_10 -> V_28 = V_33 ;
V_6 = V_34 ;
V_12 = & V_2 -> V_19 [ V_25 -> V_30 -> V_31 ] ;
V_15 = F_3 ( V_2 , V_35 , V_14 ,
sizeof( V_14 ) ) ;
}
if ( V_15 < 0 )
return V_15 ;
V_26 = F_9 (unsigned int, be32_to_cpu(reg[0]), MAX_STREAMS) ;
if ( V_25 -> V_30 -> V_31 >= V_26 )
return - V_36 ;
V_8 = F_4 ( V_14 [ 1 ] ) * 4 ;
V_15 = F_1 ( V_2 , V_25 -> V_4 , V_6 ,
V_25 -> V_30 -> V_31 , V_8 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_10 ( V_12 , V_4 ) ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
int V_15 ;
V_15 = F_12 ( V_2 ) ;
if ( V_15 < 0 )
goto V_38;
V_15 = F_8 ( V_2 , V_25 ) ;
if ( V_15 < 0 )
goto V_39;
F_13 ( V_25 ) ;
V_38:
return V_15 ;
V_39:
F_14 ( V_2 ) ;
return V_15 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
int V_15 ;
V_15 = F_17 ( V_25 ,
F_18 ( V_41 ) ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_25 -> V_4 -> V_42 -> V_43 == V_44 ) {
F_19 ( & V_2 -> V_45 ) ;
V_2 -> V_46 ++ ;
F_20 ( & V_2 -> V_45 ) ;
}
return 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
int V_15 ;
V_15 = F_17 ( V_25 ,
F_18 ( V_41 ) ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_25 -> V_4 -> V_42 -> V_43 == V_44 ) {
F_19 ( & V_2 -> V_45 ) ;
V_2 -> V_46 ++ ;
F_20 ( & V_2 -> V_45 ) ;
}
return 0 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
F_19 ( & V_2 -> V_45 ) ;
if ( V_25 -> V_4 -> V_42 -> V_43 != V_44 )
V_2 -> V_46 -- ;
F_23 ( V_2 ) ;
F_20 ( & V_2 -> V_45 ) ;
return F_24 ( V_25 ) ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
F_19 ( & V_2 -> V_45 ) ;
if ( V_25 -> V_4 -> V_42 -> V_43 != V_44 )
V_2 -> V_46 -- ;
F_23 ( V_2 ) ;
F_20 ( & V_2 -> V_45 ) ;
return F_24 ( V_25 ) ;
}
static int F_26 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_25 -> V_30 -> V_31 ] ;
int V_15 ;
F_19 ( & V_2 -> V_45 ) ;
V_15 = F_27 ( V_2 , V_25 -> V_4 -> V_13 ) ;
F_20 ( & V_2 -> V_45 ) ;
if ( V_15 >= 0 )
F_28 ( V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_25 -> V_30 -> V_31 ] ;
int V_15 ;
F_19 ( & V_2 -> V_45 ) ;
V_15 = F_27 ( V_2 , V_25 -> V_4 -> V_13 ) ;
F_20 ( & V_2 -> V_45 ) ;
if ( V_15 >= 0 )
F_28 ( V_12 ) ;
return V_15 ;
}
static int F_30 ( struct V_24 * V_25 , int V_47 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_25 -> V_30 -> V_31 ] ;
switch ( V_47 ) {
case V_48 :
F_31 ( V_12 , V_25 ) ;
break;
case V_49 :
F_31 ( V_12 , NULL ) ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_32 ( struct V_24 * V_25 , int V_47 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_25 -> V_30 -> V_31 ] ;
switch ( V_47 ) {
case V_48 :
F_31 ( V_12 , V_25 ) ;
break;
case V_49 :
F_31 ( V_12 , NULL ) ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static T_2 F_33 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_25 -> V_30 -> V_31 ] ;
return F_34 ( V_12 ) ;
}
static T_2 F_35 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_25 -> V_30 -> V_31 ] ;
return F_34 ( V_12 ) ;
}
static int F_36 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_17 [ V_25 -> V_30 -> V_31 ] ;
return F_37 ( V_12 ) ;
}
static int F_38 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_37 ;
struct V_11 * V_12 = & V_2 -> V_19 [ V_25 -> V_30 -> V_31 ] ;
return F_37 ( V_12 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
static const struct V_51 V_52 = {
. V_53 = F_11 ,
. V_54 = F_15 ,
. V_55 = V_56 ,
. V_41 = F_16 ,
. V_57 = F_22 ,
. V_58 = F_26 ,
. V_59 = F_30 ,
. V_60 = F_33 ,
. V_61 = F_36 ,
. V_62 = V_63 ,
. V_64 = V_65 ,
} ;
static const struct V_51 V_66 = {
. V_53 = F_11 ,
. V_54 = F_15 ,
. V_55 = V_56 ,
. V_41 = F_21 ,
. V_57 = F_25 ,
. V_58 = F_29 ,
. V_59 = F_32 ,
. V_60 = F_35 ,
. V_61 = F_38 ,
. V_62 = V_63 ,
. V_64 = V_65 ,
} ;
T_1 V_14 ;
struct V_67 * V_30 ;
unsigned int V_68 , V_69 , V_70 , V_71 , V_72 ;
int V_15 ;
if ( V_2 -> V_73 ) {
V_69 = V_70 = 2 ;
} else {
V_69 = V_70 = 0 ;
V_15 = F_2 ( V_2 , V_32 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_69 = F_9 (unsigned int, be32_to_cpu(reg), MAX_STREAMS) ;
V_15 = F_3 ( V_2 , V_35 , & V_14 ,
sizeof( V_14 ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_70 = F_9 (unsigned int, be32_to_cpu(reg), MAX_STREAMS) ;
}
for ( V_68 = 0 ; V_68 < V_74 ; V_68 ++ ) {
V_71 = V_72 = 0 ;
if ( V_68 < V_69 )
V_71 = 1 ;
if ( V_68 < V_70 )
V_72 = 1 ;
if ( V_71 == 0 && V_72 == 0 )
break;
V_15 = F_40 ( V_2 -> V_75 , L_1 , V_68 , V_72 , V_71 ,
& V_30 ) ;
if ( V_15 < 0 )
return V_15 ;
V_30 -> V_37 = V_2 ;
strcpy ( V_30 -> V_76 , V_2 -> V_75 -> V_77 ) ;
if ( V_71 > 0 )
F_41 ( V_30 , V_27 ,
& V_52 ) ;
if ( V_72 > 0 )
F_41 ( V_30 , V_78 ,
& V_66 ) ;
}
return 0 ;
}
