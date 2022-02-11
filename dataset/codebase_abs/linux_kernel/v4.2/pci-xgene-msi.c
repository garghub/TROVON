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
F_21 ( V_33 , V_43 ) ;
return 0 ;
}
static void F_22 ( struct V_31 * V_32 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_11 * V_44 = F_23 ( V_32 , V_33 ) ;
struct V_1 * V_2 = F_8 ( V_44 ) ;
T_1 V_8 ;
F_16 ( & V_2 -> V_37 ) ;
V_8 = F_12 ( V_44 -> V_8 ) ;
F_24 ( V_2 -> V_38 , V_8 , V_2 -> V_22 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_25 ( V_32 , V_33 , V_34 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
V_2 -> V_32 = F_27 ( NULL , V_39 ,
& V_45 , V_2 ) ;
if ( ! V_2 -> V_32 )
return - V_46 ;
V_2 -> V_47 . V_32 = F_28 ( V_2 -> V_47 . V_48 ,
& V_49 ,
V_2 -> V_32 ) ;
if ( ! V_2 -> V_47 . V_32 ) {
F_29 ( V_2 -> V_32 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 . V_32 )
F_29 ( V_2 -> V_47 . V_32 ) ;
if ( V_2 -> V_32 )
F_29 ( V_2 -> V_32 ) ;
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
static void F_36 ( unsigned int V_54 , struct V_55 * V_56 )
{
struct V_57 * V_58 = F_37 ( V_56 ) ;
struct V_53 * V_52 ;
struct V_1 * V_1 ;
unsigned int V_33 ;
int V_59 , V_60 , V_61 ;
T_1 V_62 , V_63 , V_3 ;
F_38 ( V_58 , V_56 ) ;
V_52 = F_39 ( V_56 ) ;
V_1 = V_52 -> V_2 ;
V_3 = V_52 -> V_3 ;
V_63 = F_3 ( V_1 , V_3 ) ;
while ( V_63 ) {
V_59 = F_40 ( V_63 ) - 1 ;
V_60 = F_1 ( V_1 , V_3 , V_59 ) ;
while ( V_60 ) {
V_62 = F_40 ( V_60 ) - 1 ;
V_61 = ( ( ( V_59 * V_10 ) + V_62 ) *
V_9 ) + V_3 ;
V_61 = F_12 ( V_61 ) ;
V_33 = F_41 ( V_1 -> V_32 , V_61 ) ;
F_42 ( ! V_33 ) ;
if ( V_33 != 0 )
F_43 ( V_33 ) ;
V_60 &= ~ ( 1 << V_62 ) ;
}
V_63 &= ~ ( 1 << V_59 ) ;
if ( ! V_63 ) {
V_63 = F_3 ( V_1 , V_3 ) ;
}
}
F_44 ( V_58 , V_56 ) ;
}
static int F_45 ( struct V_64 * V_65 )
{
int V_33 , V_66 ;
struct V_1 * V_2 = F_46 ( V_65 ) ;
for ( V_66 = 0 ; V_66 < V_9 ; V_66 ++ ) {
V_33 = V_2 -> V_52 [ V_66 ] . V_67 ;
if ( V_33 != 0 ) {
F_47 ( V_33 , NULL ) ;
F_48 ( V_33 , NULL ) ;
}
}
F_49 ( V_2 -> V_52 ) ;
F_49 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_50 ( unsigned int V_68 )
{
struct V_1 * V_2 = & V_21 ;
struct V_53 * V_69 ;
T_3 V_25 ;
int V_66 ;
int V_70 ;
for ( V_66 = V_68 ; V_66 < V_9 ; V_66 += V_2 -> V_22 ) {
V_69 = & V_2 -> V_52 [ V_66 ] ;
if ( ! V_69 -> V_67 )
continue;
F_47 ( V_69 -> V_67 ,
F_36 ) ;
V_70 = F_48 ( V_69 -> V_67 , V_69 ) ;
if ( V_70 ) {
F_51 ( L_1 ) ;
return - V_71 ;
}
if ( F_52 ( & V_25 , V_51 ) ) {
F_53 ( V_25 ) ;
F_54 ( V_68 , V_25 ) ;
V_70 = F_55 ( V_69 -> V_67 , V_25 ) ;
if ( V_70 )
F_51 ( L_2 ) ;
F_56 ( V_25 ) ;
} else {
F_51 ( L_3 ) ;
V_70 = - V_71 ;
}
if ( V_70 ) {
F_47 ( V_69 -> V_67 , NULL ) ;
F_48 ( V_69 -> V_67 , NULL ) ;
return V_70 ;
}
}
return 0 ;
}
static void F_57 ( unsigned int V_68 )
{
struct V_1 * V_2 = & V_21 ;
struct V_53 * V_69 ;
int V_66 ;
for ( V_66 = V_68 ; V_66 < V_9 ; V_66 += V_2 -> V_22 ) {
V_69 = & V_2 -> V_52 [ V_66 ] ;
if ( ! V_69 -> V_67 )
continue;
F_47 ( V_69 -> V_67 , NULL ) ;
F_48 ( V_69 -> V_67 , NULL ) ;
}
}
static int F_58 ( struct V_72 * V_73 ,
unsigned long V_74 , void * V_75 )
{
unsigned V_68 = ( unsigned long ) V_75 ;
switch ( V_74 ) {
case V_76 :
case V_77 :
F_50 ( V_68 ) ;
break;
case V_78 :
case V_79 :
F_57 ( V_68 ) ;
break;
default:
break;
}
return V_80 ;
}
static int F_59 ( struct V_64 * V_65 )
{
struct V_81 * V_82 ;
int V_83 , V_84 ;
struct V_1 * V_1 ;
unsigned int V_68 ;
int V_85 ;
T_1 V_86 , V_87 ;
V_1 = & V_21 ;
F_60 ( V_65 , V_1 ) ;
V_82 = F_61 ( V_65 , V_88 , 0 ) ;
V_1 -> V_5 = F_62 ( & V_65 -> V_89 , V_82 ) ;
if ( F_63 ( V_1 -> V_5 ) ) {
F_64 ( & V_65 -> V_89 , L_4 ) ;
V_83 = - V_71 ;
goto error;
}
V_1 -> V_18 = V_82 -> V_90 ;
V_1 -> V_22 = F_65 () ;
V_83 = F_31 ( V_1 ) ;
if ( V_83 ) {
F_64 ( & V_65 -> V_89 , L_5 ) ;
goto error;
}
V_83 = F_26 ( V_1 ) ;
if ( V_83 ) {
F_64 ( & V_65 -> V_89 , L_6 ) ;
goto error;
}
for ( V_84 = 0 ; V_84 < V_9 ; V_84 ++ ) {
V_85 = F_66 ( V_65 , V_84 ) ;
if ( V_85 < 0 ) {
F_64 ( & V_65 -> V_89 , L_7 ,
V_84 ) ;
V_83 = - V_71 ;
goto error;
}
V_1 -> V_52 [ V_84 ] . V_67 = V_85 ;
V_1 -> V_52 [ V_84 ] . V_3 = V_84 ;
V_1 -> V_52 [ V_84 ] . V_2 = V_1 ;
}
for ( V_84 = 0 ; V_84 < V_9 ; V_84 ++ ) {
for ( V_87 = 0 ; V_87 < V_91 ; V_87 ++ )
V_86 = F_1 ( V_1 , V_84 ,
V_87 ) ;
V_86 = F_3 ( V_1 , V_84 ) ;
if ( V_86 ) {
F_64 ( & V_65 -> V_89 , L_8 ) ;
V_83 = - V_71 ;
goto error;
}
}
F_67 () ;
F_68 (cpu)
if ( F_50 ( V_68 ) ) {
F_64 ( & V_65 -> V_89 , L_9 ) ;
F_69 () ;
goto error;
}
V_83 = F_70 ( & V_92 ) ;
if ( V_83 ) {
F_64 ( & V_65 -> V_89 , L_10 ) ;
F_69 () ;
goto error;
}
F_69 () ;
V_1 -> V_47 . V_48 = V_65 -> V_89 . V_48 ;
V_83 = F_71 ( & V_1 -> V_47 ) ;
if ( V_83 ) {
F_64 ( & V_65 -> V_89 , L_11 ) ;
goto V_93;
}
F_72 ( & V_65 -> V_89 , L_12 ) ;
return 0 ;
V_93:
F_73 ( & V_92 ) ;
error:
F_45 ( V_65 ) ;
return V_83 ;
}
static int T_4 F_74 ( void )
{
return F_75 ( & V_94 ) ;
}
