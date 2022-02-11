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
static void F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
int V_43 ;
const T_4 * V_44 ;
V_44 = F_25 ( V_40 , L_3 , & V_43 ) ;
if ( V_44 )
V_42 -> V_45 = true ;
V_44 = F_25 ( V_40 , L_4 , & V_43 ) ;
if ( V_44 )
V_42 -> V_46 = true ;
V_44 = F_25 ( V_40 , L_5 , & V_43 ) ;
if ( V_44 )
V_42 -> V_47 = true ;
V_44 = F_25 ( V_40 , L_6 , & V_43 ) ;
if ( V_44 && V_43 == sizeof( T_1 ) )
V_42 -> V_48 = F_26 ( V_44 [ 0 ] ) ;
V_44 = F_25 ( V_40 , L_7 , & V_43 ) ;
if ( V_44 && V_43 == sizeof( T_1 ) )
V_42 -> V_49 = F_26 ( V_44 [ 0 ] ) ;
V_44 = F_25 ( V_40 , L_8 , & V_43 ) ;
if ( V_44 ) {
if ( V_43 == sizeof( T_1 ) )
V_42 -> V_50 = F_26 ( V_44 [ 0 ] ) ;
else
V_42 -> V_50 = 0xfe ;
}
V_44 = F_25 ( V_40 , L_9 , & V_43 ) ;
if ( V_44 && V_43 == 2 * sizeof( T_1 ) ) {
V_42 -> V_51 = F_26 ( V_44 [ 0 ] ) ;
V_42 -> V_52 = F_26 ( V_44 [ 1 ] ) ;
}
}
static int F_27 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_41 * V_42 = F_28 ( & V_5 -> V_3 ) ;
struct V_41 V_53 ;
const struct V_54 * V_16 = V_6 -> V_16 ;
int V_55 = V_16 -> V_17 ;
int V_7 , V_56 ;
if ( ! V_42 && ! V_5 -> V_3 . V_57 ) {
V_56 = F_7 ( V_5 , V_58 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_6 -> type == V_38 ) {
if ( V_56 & V_59 )
V_6 -> V_33 = 64 ;
V_56 = F_7 ( V_5 ,
V_60 ) ;
if ( V_56 < 0 )
return V_56 ;
V_55 += F_29 ( V_56 ) ;
} else {
if ( V_56 & V_61 )
V_55 ++ ;
}
goto V_62;
}
if ( V_5 -> V_3 . V_57 ) {
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
F_24 ( V_5 -> V_3 . V_57 , & V_53 ) ;
V_42 = & V_53 ;
}
V_56 = 0 ;
if ( V_42 -> V_45 &&
( V_16 -> V_63 & V_64 ) ) {
V_56 |= V_64 ;
}
if ( V_42 -> V_46 &&
( V_16 -> V_63 & V_59 ) ) {
V_56 |= V_59 ;
V_6 -> V_33 = 64 ;
}
if ( V_42 -> V_50 &&
( V_16 -> V_63 & V_61 ) ) {
V_56 |= V_61 ;
V_55 ++ ;
}
if ( V_42 -> V_47 &&
( V_16 -> V_63 & V_65 ) ) {
V_56 |= V_65 ;
}
V_7 = F_23 ( V_5 , V_58 , V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 , V_66 ,
F_30 ( V_42 -> V_48 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 , V_67 ,
F_30 ( V_42 -> V_49 ) ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_6 -> type == V_38 ) {
V_55 += F_29 ( V_42 -> V_50 >> 1 ) ;
V_7 = F_23 ( V_5 , V_60 ,
V_42 -> V_50 >> 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 , V_68 ,
V_42 -> V_51 >> 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_5 ,
V_69 ,
V_42 -> V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_62:
V_6 -> V_15 = V_55 * V_70 ;
return 0 ;
}
static void F_31 ( struct V_4 * V_5 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_32 ( V_71 ) ; V_9 ++ )
F_33 ( & V_5 -> V_3 . V_72 , & V_71 [ V_9 ] ) ;
}
static int F_34 ( struct V_4 * V_5 ,
const struct V_73 * V_74 )
{
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_1 * V_6 ;
int V_9 , V_77 ;
if ( ! F_35 ( V_76 , V_78 ) )
return - V_79 ;
V_6 = F_36 ( V_3 , sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_6 )
return - V_81 ;
V_6 -> type = V_74 -> V_82 ;
V_6 -> V_16 = & V_54 [ V_6 -> type ] ;
F_37 ( V_5 , V_6 ) ;
F_38 ( & V_6 -> V_11 ) ;
V_77 = F_27 ( V_5 ) ;
if ( V_77 )
return V_77 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_16 -> V_17 ; V_9 ++ ) {
V_77 = F_39 ( & V_3 -> V_72 ,
V_83 [ V_9 ] [ 0 ] ) ;
if ( V_77 )
goto error;
V_77 = F_39 ( & V_3 -> V_72 ,
V_83 [ V_9 ] [ 1 ] ) ;
if ( V_77 )
goto error;
V_77 = F_39 ( & V_3 -> V_72 ,
V_83 [ V_9 ] [ 2 ] ) ;
if ( V_77 )
goto error;
if ( V_6 -> V_16 -> V_26 & ( 1 << V_9 ) ) {
V_77 = F_39 ( & V_3 -> V_72 ,
V_83 [ V_9 ] [ 3 ] ) ;
if ( V_77 )
goto error;
V_77 = F_39 ( & V_3 -> V_72 ,
V_83 [ V_9 ] [ 4 ] ) ;
if ( V_77 )
goto error;
}
if ( V_6 -> V_16 -> V_84 & ( 1 << V_9 ) ) {
V_77 = F_39 ( & V_3 -> V_72 ,
V_83 [ V_9 ] [ 5 ] ) ;
if ( V_77 )
goto error;
}
}
V_6 -> V_85 = F_40 ( V_3 ) ;
if ( F_14 ( V_6 -> V_85 ) ) {
V_77 = F_15 ( V_6 -> V_85 ) ;
goto error;
}
return 0 ;
error:
F_31 ( V_5 ) ;
return V_77 ;
}
static int F_41 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_42 ( V_6 -> V_85 ) ;
F_31 ( V_5 ) ;
return 0 ;
}
