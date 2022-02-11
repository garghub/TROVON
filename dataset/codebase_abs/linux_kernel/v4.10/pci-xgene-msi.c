static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 + V_6 +
( V_3 << 19 ) + ( V_4 << 16 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_5 + V_7 + ( V_3 << 16 ) ) ;
}
static T_1 F_4 ( unsigned long V_8 )
{
return ( V_8 / ( V_9 * V_10 ) ) ;
}
static T_1 F_5 ( unsigned long V_8 )
{
return ( V_8 % V_9 ) ;
}
static T_1 F_6 ( unsigned long V_8 )
{
return ( ( V_8 / V_9 ) % V_10 ) ;
}
static void F_7 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
T_1 V_15 = F_4 ( V_12 -> V_8 ) ;
T_1 V_16 = F_5 ( V_12 -> V_8 ) ;
T_2 V_17 = V_2 -> V_18 + ( ( ( 8 * V_16 ) + V_15 ) << 16 ) ;
V_14 -> V_19 = F_9 ( V_17 ) ;
V_14 -> V_20 = F_10 ( V_17 ) ;
V_14 -> V_12 = F_6 ( V_12 -> V_8 ) ;
}
static int F_11 ( unsigned long V_8 )
{
return ( V_8 % V_21 . V_22 ) ;
}
static unsigned long F_12 ( unsigned long V_8 )
{
return ( V_8 - F_11 ( V_8 ) ) ;
}
static int F_13 ( struct V_11 * V_23 ,
const struct V_24 * V_25 , bool V_26 )
{
int V_27 = F_14 ( V_25 ) ;
int V_28 ;
V_28 = F_11 ( V_23 -> V_8 ) ;
if ( V_28 == V_27 )
return V_29 ;
V_23 -> V_8 = F_12 ( V_23 -> V_8 ) + V_27 ;
return V_30 ;
}
static int F_15 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 , void * args )
{
struct V_1 * V_2 = V_32 -> V_35 ;
int V_36 ;
F_16 ( & V_2 -> V_37 ) ;
V_36 = F_17 ( V_2 -> V_38 , V_39 , 0 ,
V_2 -> V_22 , 0 ) ;
if ( V_36 < V_39 )
F_18 ( V_2 -> V_38 , V_36 , V_2 -> V_22 ) ;
else
V_36 = - V_40 ;
F_19 ( & V_2 -> V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
F_20 ( V_32 , V_33 , V_36 ,
& V_41 , V_32 -> V_35 ,
V_42 , NULL , NULL ) ;
return 0 ;
}
static void F_21 ( struct V_31 * V_32 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_11 * V_43 = F_22 ( V_32 , V_33 ) ;
struct V_1 * V_2 = F_8 ( V_43 ) ;
T_1 V_8 ;
F_16 ( & V_2 -> V_37 ) ;
V_8 = F_12 ( V_43 -> V_8 ) ;
F_23 ( V_2 -> V_38 , V_8 , V_2 -> V_22 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_24 ( V_32 , V_33 , V_34 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
V_2 -> V_44 = F_26 ( NULL , V_39 ,
& V_45 , V_2 ) ;
if ( ! V_2 -> V_44 )
return - V_46 ;
V_2 -> V_47 = F_27 ( F_28 ( V_2 -> V_48 ) ,
& V_49 ,
V_2 -> V_44 ) ;
if ( ! V_2 -> V_47 ) {
F_29 ( V_2 -> V_44 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 )
F_29 ( V_2 -> V_47 ) ;
if ( V_2 -> V_44 )
F_29 ( V_2 -> V_44 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
int V_50 = F_32 ( V_39 ) * sizeof( long ) ;
V_1 -> V_38 = F_33 ( V_50 , V_51 ) ;
if ( ! V_1 -> V_38 )
return - V_46 ;
F_34 ( & V_1 -> V_37 ) ;
V_1 -> V_52 = F_35 ( V_9 ,
sizeof( struct V_53 ) ,
V_51 ) ;
if ( ! V_1 -> V_52 )
return - V_46 ;
return 0 ;
}
static void F_36 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_37 ( V_55 ) ;
struct V_53 * V_52 ;
struct V_1 * V_1 ;
unsigned int V_33 ;
int V_58 , V_59 , V_60 ;
T_1 V_61 , V_62 , V_3 ;
F_38 ( V_57 , V_55 ) ;
V_52 = F_39 ( V_55 ) ;
V_1 = V_52 -> V_2 ;
V_3 = V_52 -> V_3 ;
V_62 = F_3 ( V_1 , V_3 ) ;
while ( V_62 ) {
V_58 = F_40 ( V_62 ) - 1 ;
V_59 = F_1 ( V_1 , V_3 , V_58 ) ;
while ( V_59 ) {
V_61 = F_40 ( V_59 ) - 1 ;
V_60 = ( ( ( V_58 * V_10 ) + V_61 ) *
V_9 ) + V_3 ;
V_60 = F_12 ( V_60 ) ;
V_33 = F_41 ( V_1 -> V_44 , V_60 ) ;
F_42 ( ! V_33 ) ;
if ( V_33 != 0 )
F_43 ( V_33 ) ;
V_59 &= ~ ( 1 << V_61 ) ;
}
V_62 &= ~ ( 1 << V_58 ) ;
if ( ! V_62 ) {
V_62 = F_3 ( V_1 , V_3 ) ;
}
}
F_44 ( V_57 , V_55 ) ;
}
static int F_45 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_46 ( V_64 ) ;
if ( V_65 )
F_47 ( V_65 ) ;
F_47 ( V_66 ) ;
F_48 ( V_2 -> V_52 ) ;
F_48 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_49 ( unsigned int V_67 )
{
struct V_1 * V_2 = & V_21 ;
struct V_53 * V_68 ;
T_3 V_25 ;
int V_69 ;
int V_70 ;
for ( V_69 = V_67 ; V_69 < V_9 ; V_69 += V_2 -> V_22 ) {
V_68 = & V_2 -> V_52 [ V_69 ] ;
if ( ! V_68 -> V_71 )
continue;
F_50 ( V_68 -> V_71 ,
F_36 ) ;
V_70 = F_51 ( V_68 -> V_71 , V_68 ) ;
if ( V_70 ) {
F_52 ( L_1 ) ;
return - V_72 ;
}
if ( F_53 ( & V_25 , V_51 ) ) {
F_54 ( V_25 ) ;
F_55 ( V_67 , V_25 ) ;
V_70 = F_56 ( V_68 -> V_71 , V_25 ) ;
if ( V_70 )
F_52 ( L_2 ) ;
F_57 ( V_25 ) ;
} else {
F_52 ( L_3 ) ;
V_70 = - V_72 ;
}
if ( V_70 ) {
F_58 ( V_68 -> V_71 ,
NULL , NULL ) ;
return V_70 ;
}
}
return 0 ;
}
static int F_59 ( unsigned int V_67 )
{
struct V_1 * V_2 = & V_21 ;
struct V_53 * V_68 ;
int V_69 ;
for ( V_69 = V_67 ; V_69 < V_9 ; V_69 += V_2 -> V_22 ) {
V_68 = & V_2 -> V_52 [ V_69 ] ;
if ( ! V_68 -> V_71 )
continue;
F_58 ( V_68 -> V_71 , NULL ,
NULL ) ;
}
return 0 ;
}
static int F_60 ( struct V_63 * V_64 )
{
struct V_73 * V_74 ;
int V_75 , V_76 ;
struct V_1 * V_1 ;
int V_77 ;
T_1 V_78 , V_79 ;
V_1 = & V_21 ;
F_61 ( V_64 , V_1 ) ;
V_74 = F_62 ( V_64 , V_80 , 0 ) ;
V_1 -> V_5 = F_63 ( & V_64 -> V_81 , V_74 ) ;
if ( F_64 ( V_1 -> V_5 ) ) {
F_65 ( & V_64 -> V_81 , L_4 ) ;
V_75 = - V_72 ;
goto error;
}
V_1 -> V_18 = V_74 -> V_82 ;
V_1 -> V_48 = V_64 -> V_81 . V_83 ;
V_1 -> V_22 = F_66 () ;
V_75 = F_31 ( V_1 ) ;
if ( V_75 ) {
F_65 ( & V_64 -> V_81 , L_5 ) ;
goto error;
}
V_75 = F_25 ( V_1 ) ;
if ( V_75 ) {
F_65 ( & V_64 -> V_81 , L_6 ) ;
goto error;
}
for ( V_76 = 0 ; V_76 < V_9 ; V_76 ++ ) {
V_77 = F_67 ( V_64 , V_76 ) ;
if ( V_77 < 0 ) {
F_65 ( & V_64 -> V_81 , L_7 ,
V_76 ) ;
V_75 = - V_72 ;
goto error;
}
V_1 -> V_52 [ V_76 ] . V_71 = V_77 ;
V_1 -> V_52 [ V_76 ] . V_3 = V_76 ;
V_1 -> V_52 [ V_76 ] . V_2 = V_1 ;
}
for ( V_76 = 0 ; V_76 < V_9 ; V_76 ++ ) {
for ( V_79 = 0 ; V_79 < V_84 ; V_79 ++ )
V_78 = F_1 ( V_1 , V_76 ,
V_79 ) ;
V_78 = F_3 ( V_1 , V_76 ) ;
if ( V_78 ) {
F_65 ( & V_64 -> V_81 , L_8 ) ;
V_75 = - V_72 ;
goto error;
}
}
V_75 = F_68 ( V_85 , L_9 ,
F_49 , NULL ) ;
if ( V_75 < 0 )
goto V_86;
V_65 = V_75 ;
V_75 = F_68 ( V_66 , L_10 , NULL ,
F_59 ) ;
if ( V_75 )
goto V_86;
F_69 ( & V_64 -> V_81 , L_11 ) ;
return 0 ;
V_86:
F_65 ( & V_64 -> V_81 , L_12 ) ;
error:
F_45 ( V_64 ) ;
return V_75 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_87 ) ;
}
