static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_7 = V_6 ;
V_6 = F_2 ( V_2 , V_5 + 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_8 = V_6 ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
return F_5 ( V_2 , V_13 , V_11 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
return F_3 ( V_10 , V_14 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
return F_3 ( V_10 , V_15 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
return F_5 ( V_2 , V_16 ,
V_17 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned int V_18 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 ;
V_6 = F_5 ( V_2 , V_19 , V_18 ) ;
if ( ! V_6 )
V_10 -> V_18 = V_18 ;
return V_6 ;
}
static unsigned int F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 ;
V_6 = F_2 ( V_2 , V_20 ) ;
if ( V_6 < 0 )
V_6 = 0 ;
return V_6 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 ;
unsigned long V_18 ;
V_18 = V_21 + F_12 ( V_22 ) ;
do {
if ( F_13 ( V_21 , V_18 ) )
return - V_23 ;
F_14 ( 5000 , 10000 ) ;
V_6 = F_15 ( V_2 ) ;
if ( V_6 < 0 ) {
F_16 ( & V_2 -> V_24 , L_1 ) ;
return V_6 ;
}
} while ( V_6 == V_25 );
return V_6 == V_26 ? 0 : - V_27 ;
}
static int F_17 ( struct V_9 * V_10 , T_2 V_28 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
T_1 V_29 [ 2 ] ;
V_29 [ 0 ] = V_28 & 0xff ;
V_29 [ 1 ] = ( V_28 >> 8 ) & 0xff ;
return F_18 ( V_2 ,
V_30 ,
F_19 ( V_29 ) , V_29 ) ;
}
static int F_20 ( struct V_9 * V_10 ,
T_1 V_5 , T_1 V_31 , const T_1 * V_32 ,
bool V_33 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 ;
V_6 = F_18 ( V_2 , V_5 , V_31 , V_32 ) ;
if ( V_6 ) {
F_16 ( & V_2 -> V_24 ,
L_2 , V_5 , V_6 ) ;
return V_6 ;
}
if ( V_33 )
V_6 = F_11 ( V_10 ) ;
return V_6 ;
}
static int F_21 ( struct V_9 * V_10 , T_1 V_5 ,
T_1 V_34 , bool V_33 )
{
return F_20 ( V_10 , V_5 , 1 , & V_34 ,
V_33 ) ;
}
static int F_22 ( struct V_9 * V_10 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
T_1 V_37 , V_38 = 0 , V_39 [ V_40 ] ;
int V_6 ;
T_2 V_28 ;
memset ( V_39 , 0 , F_19 ( V_39 ) ) ;
V_39 [ 0 ] = ( T_1 ) F_23 ( V_36 -> V_41 ) ;
V_28 = ( F_24 ( V_36 -> V_28 ) & 0xffff ) >> 1 ;
V_39 [ 1 ] = V_28 & 0xff ;
V_39 [ 2 ] = ( V_28 & 0xff00 ) >> 8 ;
if ( F_23 ( V_36 -> V_41 ) > V_42 )
return - V_43 ;
memcpy ( V_39 + 3 , V_36 -> V_32 , F_23 ( V_36 -> V_41 ) ) ;
for ( V_37 = 0 ; V_37 < V_40 - 1 ; V_37 ++ )
V_38 += V_39 [ V_37 ] ;
V_39 [ V_40 - 1 ] = V_38 ;
V_6 = F_20 ( V_10 , V_44 ,
F_19 ( V_39 ) , V_39 , true ) ;
if ( V_6 )
F_16 ( & V_2 -> V_24 ,
L_3 ,
V_28 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_9 * V_10 ,
const struct V_45 * V_46 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
const struct V_35 * V_36 ;
int V_37 , V_6 ;
T_1 V_32 [ V_42 ] ;
T_2 V_28 ;
for ( V_36 = ( void * ) V_46 -> V_32 ; V_36 ; V_36 = F_26 ( V_36 ) ) {
if ( ! F_23 ( V_36 -> V_41 ) )
break;
V_28 = ( F_24 ( V_36 -> V_28 ) & 0xffff ) >> 1 ;
if ( V_28 < V_47 ||
V_28 > V_48 )
continue;
V_6 = F_17 ( V_10 , V_28 ) ;
if ( V_6 ) {
F_16 ( & V_2 -> V_24 ,
L_4 ,
V_6 ) ;
return V_6 ;
}
for ( V_37 = 0 ; V_37 < F_19 ( V_32 ) ; V_37 ++ ) {
V_6 = F_2 ( V_2 ,
V_49 ) ;
if ( V_6 < 0 ) {
F_16 ( & V_2 -> V_24 ,
L_5 , V_6 ) ;
return V_6 ;
}
V_32 [ V_37 ] = V_6 ;
}
if ( memcmp ( V_32 , V_36 -> V_32 , F_23 ( V_36 -> V_41 ) ) ) {
F_16 ( & V_2 -> V_24 ,
L_6 , V_28 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 ,
const struct V_45 * V_46 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 , V_51 ;
const struct V_35 * V_36 ;
struct V_35 * V_52 ;
V_6 = F_21 ( V_10 , V_53 , 1 ,
false ) ;
if ( V_6 )
return V_6 ;
F_28 ( 500 ) ;
V_6 = F_21 ( V_10 , V_54 , 1 , true ) ;
if ( V_6 )
return V_6 ;
F_28 ( 500 ) ;
for ( V_36 = ( void * ) V_46 -> V_32 ; V_36 ; V_36 = F_26 ( V_36 ) ) {
if ( ! F_23 ( V_36 -> V_41 ) )
break;
if ( F_23 ( V_36 -> V_41 ) > V_42 ) {
F_16 ( & V_2 -> V_24 , L_7 ,
F_23 ( V_36 -> V_41 ) ) ;
return - V_43 ;
}
V_51 = ( 64 - ( ( F_24 ( V_36 -> V_28 ) >> 1 ) &
0x3f ) ) ;
if ( ( F_23 ( V_36 -> V_41 ) >> 1 ) > V_51 ) {
V_52 = F_29 ( sizeof( struct V_35 ) +
( V_51 << 1 ) ,
V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_52 -> V_41 = F_30 ( V_51 << 1 ) ;
V_52 -> V_28 = V_36 -> V_28 ;
memcpy ( V_52 -> V_32 , V_36 -> V_32 ,
F_23 ( V_52 -> V_41 ) ) ;
V_6 = F_22 ( V_10 , V_52 ) ;
F_31 ( V_52 ) ;
if ( V_6 )
return V_6 ;
V_52 = F_29 ( sizeof( struct V_35 ) +
F_23 ( V_36 -> V_41 ) -
( V_51 << 1 ) ,
V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_52 -> V_41 = V_36 -> V_41 -
F_30 ( V_51 << 1 ) ;
V_52 -> V_28 = F_32 ( F_24 ( V_36 -> V_28 ) +
( V_51 << 1 ) ) ;
memcpy ( V_52 -> V_32 ,
V_36 -> V_32 + ( V_51 << 1 ) ,
F_23 ( V_52 -> V_41 ) ) ;
V_6 = F_22 ( V_10 , V_52 ) ;
F_31 ( V_52 ) ;
if ( V_6 )
return V_6 ;
} else {
V_6 = F_22 ( V_10 , V_36 ) ;
if ( V_6 )
return V_6 ;
}
}
V_52 = F_29 ( sizeof( struct V_35 ) + 1 , V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_6 = F_22 ( V_10 , V_52 ) ;
F_31 ( V_52 ) ;
if ( V_6 ) {
F_16 ( & V_2 -> V_24 , L_8 , V_6 ) ;
return V_6 ;
}
F_28 ( 20 ) ;
V_6 = F_25 ( V_10 , V_46 ) ;
if ( V_6 ) {
F_16 ( & V_2 -> V_24 ,
L_9 , V_6 ) ;
return V_6 ;
}
V_6 = F_21 ( V_10 , V_57 , 1 , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_21 ( V_10 , V_58 , 1 ,
false ) ;
if ( V_6 )
return V_6 ;
F_28 ( 500 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_4 ( V_24 -> V_12 ) ;
struct V_63 * V_64 = F_34 ( V_2 ) ;
int V_6 ;
V_6 = F_35 ( & V_64 -> V_65 ) ;
if ( V_6 )
return V_6 ;
V_6 = sprintf ( V_62 , L_10 , V_64 -> V_66 . V_7 ,
V_64 -> V_66 . V_8 ) ;
F_36 ( & V_64 -> V_65 ) ;
return V_6 ;
}
static T_3 F_37 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_4 ( V_24 -> V_12 ) ;
struct V_63 * V_64 = F_34 ( V_2 ) ;
int V_6 ;
V_6 = F_35 ( & V_64 -> V_65 ) ;
if ( V_6 )
return V_6 ;
V_6 = sprintf ( V_62 , L_11 , V_64 -> V_67 . V_7 ,
V_64 -> V_67 . V_8 ) ;
F_36 ( & V_64 -> V_65 ) ;
return V_6 ;
}
static T_3 F_38 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_4 ( V_24 -> V_12 ) ;
struct V_63 * V_64 = F_34 ( V_2 ) ;
int V_6 ;
V_6 = F_35 ( & V_64 -> V_65 ) ;
if ( V_6 )
return V_6 ;
V_6 = sprintf ( V_62 , L_12 , V_68 [ V_64 -> V_69 ] ) ;
F_36 ( & V_64 -> V_65 ) ;
return V_6 ;
}
static T_3 F_39 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
const char * V_62 , T_4 V_70 )
{
struct V_1 * V_2 = F_4 ( V_24 -> V_12 ) ;
struct V_63 * V_64 = F_34 ( V_2 ) ;
const struct V_45 * V_46 ;
int V_71 ;
V_71 = F_40 ( & V_46 , V_72 , V_24 ) ;
if ( V_71 ) {
F_16 ( & V_2 -> V_24 , L_13 ) ;
return V_71 ;
}
V_71 = F_35 ( & V_64 -> V_65 ) ;
if ( V_71 )
goto V_73;
V_71 = F_27 ( & V_64 -> V_10 , V_46 ) ;
if ( V_71 ) {
F_16 ( & V_2 -> V_24 , L_14 , V_71 ) ;
goto V_74;
}
V_71 = F_1 ( V_2 , & V_64 -> V_66 ,
V_75 ) ;
if ( V_71 ) {
F_16 ( & V_2 -> V_24 , L_15 ,
V_71 ) ;
goto V_74;
}
F_41 ( & V_2 -> V_24 , L_16 ,
V_64 -> V_66 . V_7 , V_64 -> V_66 . V_8 ) ;
V_71 = F_9 ( & V_64 -> V_10 , V_64 -> V_10 . V_18 ) ;
if ( V_71 )
F_16 ( & V_2 -> V_24 , L_17 , V_71 ) ;
V_74:
F_36 ( & V_64 -> V_65 ) ;
V_73:
V_73 ( V_46 ) ;
return V_71 ? V_71 : V_70 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_76 ) {
if ( ! V_2 -> V_24 . V_77 )
V_6 = - V_78 ;
else
V_6 = F_43 ( V_2 -> V_24 . V_77 ,
L_18 ,
& V_76 ) ;
if ( V_6 ) {
F_41 ( & V_2 -> V_24 ,
L_19 ) ;
return 0 ;
}
}
if ( V_76 < 1 || V_76 > 255 )
return - V_50 ;
F_41 ( & V_2 -> V_24 , L_20 ,
V_76 ) ;
return F_5 ( V_2 , V_79 ,
V_76 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
int V_6 ;
struct V_63 * V_64 ;
int V_82 ;
if ( ! F_45 ( V_2 -> V_83 , V_84 ) )
return - V_78 ;
V_64 = F_46 ( & V_2 -> V_24 , sizeof( * V_64 ) , V_55 ) ;
if ( ! V_64 )
return - V_56 ;
F_47 ( & V_64 -> V_65 ) ;
V_64 -> V_10 . V_85 = & V_86 ;
V_64 -> V_10 . V_87 = & V_88 ;
V_64 -> V_10 . V_89 = V_90 ;
V_64 -> V_10 . V_91 = V_92 ;
V_64 -> V_10 . V_12 = & V_2 -> V_24 ;
V_64 -> V_10 . V_93 = V_94 ;
V_6 = F_48 ( & V_64 -> V_10 , V_95 , & V_2 -> V_24 ) ;
if ( V_6 ) {
F_41 ( & V_2 -> V_24 ,
L_21 ) ;
}
if ( V_64 -> V_10 . V_18 == 0 ) {
V_82 = F_2 ( V_2 , V_19 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_82 < V_90 )
return - V_78 ;
V_64 -> V_10 . V_18 = V_82 ;
} else {
V_6 = F_9 ( & V_64 -> V_10 ,
V_64 -> V_10 . V_18 ) ;
if ( V_6 )
return V_6 ;
F_41 ( & V_2 -> V_24 , L_22 ,
V_64 -> V_10 . V_18 ) ;
}
F_49 ( & V_64 -> V_10 , V_96 ) ;
F_50 ( V_2 , V_64 ) ;
V_82 = F_2 ( V_2 , V_13 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_82 == V_97 )
F_7 ( & V_64 -> V_10 ) ;
V_6 = F_42 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , & V_64 -> V_66 ,
V_75 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , & V_64 -> V_67 ,
V_98 ) ;
if ( V_6 )
return V_6 ;
V_64 -> V_69 = F_2 ( V_2 ,
V_99 ) ;
if ( V_64 -> V_69 < 0 )
return V_64 -> V_69 ;
if ( V_64 -> V_69 >= F_19 ( V_68 ) ||
! V_68 [ V_64 -> V_69 ] )
return - V_78 ;
V_6 = F_51 ( & V_64 -> V_10 ) ;
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = F_34 ( V_2 ) ;
F_53 ( & V_64 -> V_10 ) ;
return 0 ;
}
