static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_1 * V_7 = V_6 ;
int V_8 ;
int V_9 ;
T_1 V_10 ;
F_4 ( & V_6 -> V_11 ) ;
if ( V_6 -> V_12 &&
! F_5 ( V_13 , V_6 -> V_14
+ F_6 ( V_6 -> V_15 ) ) )
goto abort;
for ( V_9 = 0 ; V_9 < V_6 -> V_16 -> V_17 ; V_9 ++ ) {
if ( V_6 -> V_16 -> V_18 & ( 1 << V_9 ) ) {
V_8 = F_7 ( V_5 ,
V_19 [ V_9 ] ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_20 [ V_9 ] [ V_21 ] = V_8 ;
}
V_8 = F_7 ( V_5 , V_22 [ V_9 ] ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_20 [ V_9 ] [ V_23 ] = V_8 ;
V_8 = F_7 ( V_5 , V_24 [ V_9 ] ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_20 [ V_9 ] [ V_25 ] = V_8 ;
if ( V_6 -> V_16 -> V_26 & ( 1 << V_9 ) ) {
V_8 = F_7 ( V_5 ,
V_27 [ V_9 ] ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_20 [ V_9 ] [ V_28 ] = V_8 ;
}
}
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ ) {
V_8 = F_7 ( V_5 , F_10 ( V_9 ) ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_10 = ( V_10 << 8 ) | V_8 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_14 = V_13 ;
V_6 -> V_12 = true ;
abort:
F_11 ( & V_6 -> V_11 ) ;
return V_7 ;
}
static T_2 F_12 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
int V_32 = F_13 ( V_30 ) -> V_32 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_14 ( V_6 ) )
return F_15 ( V_6 ) ;
V_20 = ( V_6 -> V_20 [ V_32 ] [ V_23 ] - V_6 -> V_33 ) << 3 ;
V_20 |= V_6 -> V_20 [ V_32 ] [ V_21 ] >> 5 ;
return sprintf ( V_31 , L_1 , V_20 * 125 ) ;
}
static T_2 F_16 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
int V_34 = F_17 ( V_30 ) -> V_34 ;
int V_32 = F_17 ( V_30 ) -> V_32 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_14 ( V_6 ) )
return F_15 ( V_6 ) ;
V_20 = V_6 -> V_20 [ V_34 ] [ V_32 ] ;
V_20 -= V_6 -> V_33 ;
return sprintf ( V_31 , L_1 , V_20 * 1000 ) ;
}
static T_2 F_18 ( struct V_2 * V_3 , struct V_29 * V_35 ,
char * V_31 )
{
int V_32 = F_13 ( V_35 ) -> V_32 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_14 ( V_6 ) )
return F_15 ( V_6 ) ;
if ( V_6 -> V_16 -> V_36 )
V_32 = V_6 -> V_16 -> V_36 [ V_32 ] ;
return sprintf ( V_31 , L_2 , ( V_6 -> V_10 >> V_32 ) & 0x1 ) ;
}
static T_2 F_19 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_37 )
{
int V_34 = F_17 ( V_30 ) -> V_34 ;
int V_32 = F_17 ( V_30 ) -> V_32 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
long V_20 ;
int V_7 ;
V_7 = F_20 ( V_31 , 10 , & V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( & V_6 -> V_11 ) ;
V_20 = F_21 ( V_20 , 1000 ) + V_6 -> V_33 ;
V_20 = F_22 ( V_20 , 0 , V_6 -> type == V_38 ? 255 : 127 ) ;
V_6 -> V_20 [ V_34 ] [ V_32 ] = V_20 ;
V_7 = F_23 ( V_5 ,
V_32 == 2 ? V_24 [ V_34 ]
: V_27 [ V_34 ] ,
V_20 ) ;
F_11 ( & V_6 -> V_11 ) ;
return V_7 < 0 ? V_7 : V_37 ;
}
static T_4 F_24 ( struct V_39 * V_40 , struct V_41 * V_35 ,
int V_32 )
{
struct V_2 * V_3 = F_25 ( V_40 , struct V_2 , V_40 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
const struct V_42 * V_16 = V_6 -> V_16 ;
int V_43 = V_32 / 6 ;
int V_34 = V_32 % 6 ;
if ( V_43 >= V_16 -> V_17 )
return 0 ;
if ( ( V_34 == 3 || V_34 == 4 ) && ! ( V_16 -> V_26 & ( 1 << V_43 ) ) )
return 0 ;
if ( V_34 == 5 && ! ( V_16 -> V_44 & ( 1 << V_43 ) ) )
return 0 ;
return V_35 -> V_45 ;
}
static void F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
int V_50 ;
const T_5 * V_51 ;
V_51 = F_27 ( V_47 , L_3 , & V_50 ) ;
if ( V_51 )
V_49 -> V_52 = true ;
V_51 = F_27 ( V_47 , L_4 , & V_50 ) ;
if ( V_51 )
V_49 -> V_53 = true ;
V_51 = F_27 ( V_47 , L_5 , & V_50 ) ;
if ( V_51 )
V_49 -> V_54 = true ;
V_51 = F_27 ( V_47 , L_6 , & V_50 ) ;
if ( V_51 && V_50 == sizeof( T_1 ) )
V_49 -> V_55 = F_28 ( V_51 [ 0 ] ) ;
V_51 = F_27 ( V_47 , L_7 , & V_50 ) ;
if ( V_51 && V_50 == sizeof( T_1 ) )
V_49 -> V_56 = F_28 ( V_51 [ 0 ] ) ;
V_51 = F_27 ( V_47 , L_8 , & V_50 ) ;
if ( V_51 ) {
if ( V_50 == sizeof( T_1 ) )
V_49 -> V_57 = F_28 ( V_51 [ 0 ] ) ;
else
V_49 -> V_57 = 0xfe ;
}
V_51 = F_27 ( V_47 , L_9 , & V_50 ) ;
if ( V_51 && V_50 == 2 * sizeof( T_1 ) ) {
V_49 -> V_58 = F_28 ( V_51 [ 0 ] ) ;
V_49 -> V_59 = F_28 ( V_51 [ 1 ] ) ;
}
}
static int F_29 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_48 * V_49 = F_30 ( & V_5 -> V_3 ) ;
struct V_48 V_60 ;
const struct V_42 * V_16 = V_6 -> V_16 ;
int V_61 = V_16 -> V_17 ;
int V_7 , V_62 ;
if ( ! V_49 && ! V_5 -> V_3 . V_63 ) {
V_62 = F_7 ( V_5 , V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_6 -> type == V_38 ) {
if ( V_62 & V_65 )
V_6 -> V_33 = 64 ;
V_62 = F_7 ( V_5 ,
V_66 ) ;
if ( V_62 < 0 )
return V_62 ;
V_61 += F_31 ( V_62 ) ;
} else {
if ( V_62 & V_67 )
V_61 ++ ;
}
goto V_68;
}
if ( V_5 -> V_3 . V_63 ) {
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_26 ( V_5 -> V_3 . V_63 , & V_60 ) ;
V_49 = & V_60 ;
}
V_62 = 0 ;
if ( V_49 -> V_52 &&
( V_16 -> V_69 & V_70 ) ) {
V_62 |= V_70 ;
}
if ( V_49 -> V_53 &&
( V_16 -> V_69 & V_65 ) ) {
V_62 |= V_65 ;
V_6 -> V_33 = 64 ;
}
if ( V_49 -> V_57 &&
( V_16 -> V_69 & V_67 ) ) {
V_62 |= V_67 ;
V_61 ++ ;
}
if ( V_49 -> V_54 &&
( V_16 -> V_69 & V_71 ) ) {
V_62 |= V_71 ;
}
V_7 = F_23 ( V_5 , V_64 , V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 , V_72 ,
F_32 ( V_49 -> V_55 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 , V_73 ,
F_32 ( V_49 -> V_56 ) ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_6 -> type == V_38 ) {
V_61 += F_31 ( V_49 -> V_57 >> 1 ) ;
V_7 = F_23 ( V_5 , V_66 ,
V_49 -> V_57 >> 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 , V_74 ,
V_49 -> V_58 >> 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 ,
V_75 ,
V_49 -> V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_68:
V_6 -> V_15 = V_61 * V_76 ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 ,
const struct V_77 * V_78 )
{
struct V_79 * V_80 = V_5 -> V_80 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_1 * V_6 ;
int V_81 ;
if ( ! F_34 ( V_80 , V_82 ) )
return - V_83 ;
V_6 = F_35 ( V_3 , sizeof( struct V_1 ) , V_84 ) ;
if ( ! V_6 )
return - V_85 ;
V_6 -> type = V_78 -> V_86 ;
V_6 -> V_16 = & V_42 [ V_6 -> type ] ;
F_36 ( V_5 , V_6 ) ;
F_37 ( & V_6 -> V_11 ) ;
V_81 = F_29 ( V_5 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_38 ( & V_5 -> V_3 . V_40 , & V_87 ) ;
if ( V_81 )
return V_81 ;
V_6 -> V_88 = F_39 ( V_3 ) ;
if ( F_14 ( V_6 -> V_88 ) ) {
V_81 = F_15 ( V_6 -> V_88 ) ;
goto error;
}
return 0 ;
error:
F_40 ( & V_5 -> V_3 . V_40 , & V_87 ) ;
return V_81 ;
}
static int F_41 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_42 ( V_6 -> V_88 ) ;
F_40 ( & V_5 -> V_3 . V_40 , & V_87 ) ;
return 0 ;
}
