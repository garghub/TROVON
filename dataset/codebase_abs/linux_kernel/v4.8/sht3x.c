static T_1 F_1 ( T_2 V_1 )
{
T_3 V_2 ;
T_1 V_3 = F_2 ( V_4 ) ;
if ( V_1 == 0 )
return 0 ;
for ( V_2 = 1 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_4 [ V_2 ] <= V_1 )
return V_2 ;
}
return V_3 - 1 ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
char * V_10 , int V_11 , T_4 V_12 )
{
int V_13 ;
F_4 ( & V_8 -> V_14 ) ;
V_13 = F_5 ( V_6 , V_9 , V_15 ) ;
if ( V_13 != V_15 ) {
V_13 = V_13 < 0 ? V_13 : - V_16 ;
goto V_17;
}
if ( V_12 )
F_6 ( V_12 , V_12 + 1000 ) ;
V_13 = F_7 ( V_6 , V_10 , V_11 ) ;
if ( V_13 != V_11 ) {
V_13 = V_13 < 0 ? V_13 : - V_16 ;
goto V_17;
}
V_13 = 0 ;
V_17:
F_8 ( & V_8 -> V_14 ) ;
return V_13 ;
}
static int F_9 ( T_2 V_18 )
{
return ( ( 21875 * ( int ) V_18 ) >> 13 ) - 45000 ;
}
static T_4 F_10 ( T_2 V_18 )
{
return ( 12500 * ( T_4 ) V_18 ) >> 13 ;
}
static struct V_7 * F_11 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
T_2 V_21 = V_4 [ V_8 -> V_22 ] ;
unsigned long V_23 = F_13 ( V_21 ) ;
unsigned char V_10 [ V_24 ] ;
T_2 V_25 ;
int V_13 = 0 ;
F_4 ( & V_8 -> V_26 ) ;
if ( F_14 ( V_27 , V_8 -> V_28 + V_23 ) ) {
V_13 = F_3 ( V_6 , V_8 , V_8 -> V_9 , V_10 ,
sizeof( V_10 ) , V_8 -> V_12 ) ;
if ( V_13 )
goto V_17;
V_25 = F_15 ( ( V_29 * ) V_10 ) ;
V_8 -> V_30 = F_9 ( V_25 ) ;
V_25 = F_15 ( ( V_29 * ) ( V_10 + 3 ) ) ;
V_8 -> V_31 = F_10 ( V_25 ) ;
V_8 -> V_28 = V_27 ;
}
V_17:
F_8 ( & V_8 -> V_26 ) ;
if ( V_13 )
return F_16 ( V_13 ) ;
return V_8 ;
}
static T_5 F_17 ( struct V_19 * V_20 ,
struct V_32 * V_33 , char * V_10 )
{
struct V_7 * V_8 = F_11 ( V_20 ) ;
if ( F_18 ( V_8 ) )
return F_19 ( V_8 ) ;
return sprintf ( V_10 , L_1 , V_8 -> V_30 ) ;
}
static T_5 F_20 ( struct V_19 * V_20 ,
struct V_32 * V_33 , char * V_10 )
{
struct V_7 * V_8 = F_11 ( V_20 ) ;
if ( F_18 ( V_8 ) )
return F_19 ( V_8 ) ;
return sprintf ( V_10 , L_2 , V_8 -> V_31 ) ;
}
static int F_21 ( struct V_7 * V_8 )
{
int V_13 ;
T_1 V_2 ;
int V_30 ;
T_4 V_31 ;
T_2 V_18 ;
char V_34 [ V_24 ] ;
const struct V_35 * V_36 ;
struct V_5 * V_6 = V_8 -> V_6 ;
for ( V_2 = 0 ; V_2 < V_37 ; V_2 ++ ) {
V_36 = & V_38 [ V_2 ] ;
V_13 = F_3 ( V_6 , V_8 ,
V_36 -> V_39 , V_34 ,
V_24 , 0 ) ;
if ( V_13 )
return V_13 ;
V_18 = F_15 ( ( V_29 * ) V_34 ) ;
V_30 = F_9 ( ( V_18 & 0x01ff ) << 7 ) ;
V_31 = F_10 ( V_18 & 0xfe00 ) ;
V_8 -> V_40 [ V_2 ] = V_30 ;
V_8 -> V_41 [ V_2 ] = V_31 ;
}
return V_13 ;
}
static T_5 F_22 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_10 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
T_1 V_2 = F_23 ( V_33 ) -> V_2 ;
int V_42 = V_8 -> V_40 [ V_2 ] ;
return F_24 ( V_10 , V_43 , L_1 , V_42 ) ;
}
static T_5 F_25 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_10 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
T_1 V_2 = F_23 ( V_33 ) -> V_2 ;
T_4 V_44 = V_8 -> V_41 [ V_2 ] ;
return F_24 ( V_10 , V_43 , L_2 , V_44 ) ;
}
static T_3 F_26 ( struct V_19 * V_20 ,
T_3 V_45 ,
T_1 V_2 ,
int V_30 ,
T_4 V_31 )
{
char V_34 [ V_15 + V_46 + V_47 ] ;
char * V_48 = V_34 ;
int V_13 ;
T_2 V_18 ;
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
const struct V_35 * V_36 ;
V_36 = & V_38 [ V_2 ] ;
memcpy ( V_48 , V_36 -> V_49 , V_15 ) ;
V_48 += V_15 ;
V_18 = ( ( T_4 ) ( V_30 + 45000 ) * 24543 ) >> ( 16 + 7 ) ;
V_18 |= ( ( V_31 * 42950 ) >> 16 ) & 0xfe00 ;
* ( ( V_29 * ) V_48 ) = F_27 ( V_18 ) ;
V_48 += V_46 ;
* V_48 = F_28 ( V_50 ,
V_48 - V_46 ,
V_46 ,
V_51 ) ;
F_4 ( & V_8 -> V_14 ) ;
V_13 = F_5 ( V_6 , V_34 , sizeof( V_34 ) ) ;
F_8 ( & V_8 -> V_14 ) ;
if ( V_13 != sizeof( V_34 ) )
return V_13 < 0 ? V_13 : - V_16 ;
V_8 -> V_40 [ V_2 ] = V_30 ;
V_8 -> V_41 [ V_2 ] = V_31 ;
return V_45 ;
}
static T_5 F_29 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
const char * V_10 ,
T_3 V_45 )
{
int V_30 ;
int V_13 ;
struct V_7 * V_8 = F_12 ( V_20 ) ;
T_1 V_2 = F_23 ( V_33 ) -> V_2 ;
V_13 = F_30 ( V_10 , 0 , & V_30 ) ;
if ( V_13 )
return V_13 ;
V_30 = F_31 ( V_30 , V_52 ,
V_53 ) ;
F_4 ( & V_8 -> V_26 ) ;
V_13 = F_26 ( V_20 , V_45 , V_2 , V_30 ,
V_8 -> V_41 [ V_2 ] ) ;
F_8 ( & V_8 -> V_26 ) ;
return V_13 ;
}
static T_5 F_32 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
const char * V_10 ,
T_3 V_45 )
{
T_4 V_31 ;
int V_13 ;
struct V_7 * V_8 = F_12 ( V_20 ) ;
T_1 V_2 = F_23 ( V_33 ) -> V_2 ;
V_13 = F_33 ( V_10 , 0 , & V_31 ) ;
if ( V_13 )
return V_13 ;
V_31 = F_31 ( V_31 , V_54 , V_55 ) ;
F_4 ( & V_8 -> V_26 ) ;
V_13 = F_26 ( V_20 , V_45 , V_2 , V_8 -> V_40 [ V_2 ] ,
V_31 ) ;
F_8 ( & V_8 -> V_26 ) ;
return V_13 ;
}
static void F_34 ( struct V_7 * V_8 )
{
if ( V_8 -> V_22 > 0 ) {
V_8 -> V_9 = V_56 ;
V_8 -> V_12 = 0 ;
} else if ( V_8 -> V_57 . V_58 ) {
V_8 -> V_9 = V_8 -> V_57 . V_59 ?
V_60 :
V_61 ;
V_8 -> V_12 = 0 ;
} else {
if ( V_8 -> V_57 . V_59 ) {
V_8 -> V_9 = V_62 ;
V_8 -> V_12 = V_63 ;
} else {
V_8 -> V_9 = V_64 ;
V_8 -> V_12 = V_65 ;
}
}
}
static int F_35 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_34 , int V_11 )
{
int V_13 ;
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
V_13 = F_3 ( V_6 , V_8 , V_66 ,
V_34 , V_11 , 0 ) ;
return V_13 ;
}
static T_5 F_36 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_10 )
{
char V_34 [ V_46 + V_47 ] ;
int V_13 ;
V_13 = F_35 ( V_20 , V_33 , V_34 ,
V_46 + V_47 ) ;
if ( V_13 )
return V_13 ;
return F_24 ( V_10 , V_43 , L_1 , ! ! ( V_34 [ 0 ] & 0x04 ) ) ;
}
static T_5 F_37 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_10 )
{
char V_34 [ V_46 + V_47 ] ;
int V_13 ;
V_13 = F_35 ( V_20 , V_33 , V_34 ,
V_46 + V_47 ) ;
if ( V_13 )
return V_13 ;
return F_24 ( V_10 , V_43 , L_1 , ! ! ( V_34 [ 0 ] & 0x08 ) ) ;
}
static T_5 F_38 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_10 )
{
char V_34 [ V_46 + V_47 ] ;
int V_13 ;
V_13 = F_35 ( V_20 , V_33 , V_34 ,
V_46 + V_47 ) ;
if ( V_13 )
return V_13 ;
return F_24 ( V_10 , V_43 , L_1 , ! ! ( V_34 [ 0 ] & 0x20 ) ) ;
}
static T_5 F_39 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
const char * V_10 ,
T_3 V_45 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_13 ;
bool V_67 ;
V_13 = F_40 ( V_10 , & V_67 ) ;
if ( V_13 )
return V_13 ;
F_4 ( & V_8 -> V_14 ) ;
if ( V_67 )
V_13 = F_5 ( V_6 , ( char * ) & V_68 ,
V_15 ) ;
else
V_13 = F_5 ( V_6 , ( char * ) & V_69 ,
V_15 ) ;
F_8 ( & V_8 -> V_14 ) ;
return V_13 ;
}
static T_5 F_41 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
char * V_10 )
{
struct V_7 * V_8 = F_12 ( V_20 ) ;
return F_24 ( V_10 , V_43 , L_2 ,
V_4 [ V_8 -> V_22 ] ) ;
}
static T_5 F_42 ( struct V_19 * V_20 ,
struct V_32 * V_33 ,
const char * V_10 ,
T_3 V_45 )
{
T_2 V_70 ;
T_1 V_22 ;
int V_13 ;
const char * V_9 ;
struct V_7 * V_8 = F_12 ( V_20 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
V_13 = F_43 ( V_10 , 0 , & V_70 ) ;
if ( V_13 )
return V_13 ;
V_22 = F_1 ( V_70 ) ;
F_4 ( & V_8 -> V_26 ) ;
if ( V_22 == V_8 -> V_22 ) {
F_8 ( & V_8 -> V_26 ) ;
return V_45 ;
}
F_4 ( & V_8 -> V_14 ) ;
if ( V_8 -> V_22 > 0 ) {
V_13 = F_5 ( V_6 , V_71 ,
V_15 ) ;
if ( V_13 != V_15 )
goto V_17;
V_8 -> V_22 = 0 ;
}
if ( V_22 > 0 ) {
if ( V_8 -> V_57 . V_59 )
V_9 = V_72 [ V_22 - 1 ] ;
else
V_9 = V_73 [ V_22 - 1 ] ;
V_13 = F_5 ( V_6 , V_9 , V_15 ) ;
if ( V_13 != V_15 )
goto V_17;
}
V_8 -> V_22 = V_22 ;
F_34 ( V_8 ) ;
V_17:
F_8 ( & V_8 -> V_14 ) ;
F_8 ( & V_8 -> V_26 ) ;
if ( V_13 != V_15 )
return V_13 < 0 ? V_13 : - V_16 ;
return V_45 ;
}
static int F_44 ( struct V_5 * V_6 ,
const struct V_74 * V_75 )
{
int V_13 ;
struct V_7 * V_8 ;
struct V_19 * V_76 ;
struct V_77 * V_78 = V_6 -> V_79 ;
struct V_19 * V_20 = & V_6 -> V_20 ;
const struct V_80 * * V_81 ;
if ( ! F_45 ( V_78 , V_82 ) )
return - V_83 ;
V_13 = F_5 ( V_6 , V_84 ,
V_15 ) ;
if ( V_13 != V_15 )
return V_13 < 0 ? V_13 : - V_83 ;
V_8 = F_46 ( V_20 , sizeof( * V_8 ) , V_85 ) ;
if ( ! V_8 )
return - V_86 ;
V_8 -> V_57 . V_58 = false ;
V_8 -> V_57 . V_59 = true ;
V_8 -> V_22 = 0 ;
V_8 -> V_28 = V_27 - F_13 ( 3000 ) ;
V_8 -> V_6 = V_6 ;
F_47 ( V_50 , V_87 ) ;
if ( V_6 -> V_20 . V_88 )
V_8 -> V_57 = * (struct V_89 * ) V_20 -> V_88 ;
F_34 ( V_8 ) ;
F_48 ( & V_8 -> V_14 ) ;
F_48 ( & V_8 -> V_26 ) ;
V_13 = F_21 ( V_8 ) ;
if ( V_13 )
return V_13 ;
if ( V_75 -> V_90 == V_91 )
V_81 = V_92 ;
else
V_81 = V_93 ;
V_76 = F_49 ( V_20 ,
V_6 -> V_94 ,
V_8 ,
V_81 ) ;
if ( F_18 ( V_76 ) )
F_50 ( V_20 , L_3 ) ;
return F_51 ( V_76 ) ;
}
