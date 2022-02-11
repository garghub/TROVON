static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_2 ( V_4 , & V_8 -> V_9 , V_6 ,
V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_4 ( V_4 , & V_8 -> V_9 ,
V_10 , V_11 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_6 ( V_4 , & V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_8 ( V_4 , & V_8 -> V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_10 ( V_4 , & V_8 -> V_9 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_12 ( V_4 , & V_8 -> V_9 , V_10 ,
V_11 , V_6 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_14 ( V_4 , V_8 -> V_12 [ V_6 -> V_13 ] ,
V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_12 [ V_6 -> V_13 ] ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , T_1 V_14 , const char * V_15 ,
int V_16 , int V_17 )
{
char V_18 [ 44 ] ;
int type = V_17 ? V_19 : V_20 ;
struct V_21 V_22 =
F_18 ( V_18 , V_14 , V_16 , 0 , type ) ;
sprintf ( V_18 , L_1 , V_15 , V_23 [ V_17 ] ) ;
return F_19 ( V_4 , V_14 , F_20 ( & V_22 , V_4 ) ) ;
}
static int F_21 ( struct V_3 * V_4 , T_1 V_14 , const char * V_15 ,
int V_16 , int V_17 )
{
char V_18 [ 44 ] ;
int type = V_17 ? V_19 : V_20 ;
struct V_21 V_22 =
F_22 ( V_18 , V_14 , V_16 , 0 , type ) ;
sprintf ( V_18 , L_2 , V_15 , V_23 [ V_17 ] ) ;
return F_19 ( V_4 , V_14 , F_20 ( & V_22 , V_4 ) ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
static const char * const V_27 [ V_28 ] = {
L_3 , L_4 , NULL , L_5 , L_6
} ;
T_1 V_29 ;
int V_30 , V_31 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_9 . V_32 ; V_30 ++ ) {
if ( F_24 ( V_4 , V_8 -> V_33 [ V_30 ] ) & V_34 )
V_29 = V_8 -> V_33 [ V_30 ] ;
else
V_29 = V_8 -> V_9 . V_35 [ V_30 ] ;
if ( ! V_27 [ V_30 ] ) {
V_31 = F_25 ( V_4 , V_29 ,
L_7 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_25 ( V_4 , V_29 ,
L_8 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_26 ( V_4 , V_8 -> V_9 . V_35 [ V_30 ] ,
L_7 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_26 ( V_4 , V_8 -> V_9 . V_35 [ V_30 ] ,
L_8 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
} else {
V_31 = F_27 ( V_4 , V_29 ,
V_27 [ V_30 ] ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_28 ( V_4 , V_8 -> V_9 . V_35 [ V_30 ] ,
V_27 [ V_30 ] ) ;
if ( V_31 < 0 )
return V_31 ;
}
}
if ( V_25 -> V_36 ) {
if ( F_24 ( V_4 , V_25 -> V_37 [ 0 ] ) & V_34 )
V_29 = V_25 -> V_37 [ 0 ] ;
else
V_29 = V_8 -> V_9 . V_35 [ V_30 ] ;
V_31 = F_27 ( V_4 , V_29 , L_9 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_8 -> V_38 ) {
V_31 = F_28 ( V_4 , V_8 -> V_38 , L_9 ) ;
if ( V_31 < 0 )
return V_31 ;
}
}
for ( V_30 = 0 ; V_30 < V_8 -> V_39 ; V_30 ++ ) {
const char * V_40 = V_8 -> V_41 [ V_30 ] ;
if ( F_24 ( V_4 , V_8 -> V_42 [ V_30 ] ) & V_43 )
V_29 = V_8 -> V_42 [ V_30 ] ;
else
V_29 = V_8 -> V_12 [ V_30 ] ;
V_31 = F_29 ( V_4 , V_29 , V_40 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_30 ( V_4 , V_8 -> V_12 [ V_30 ] , V_40 ) ;
if ( V_31 < 0 )
return V_31 ;
}
if ( V_8 -> V_44 ) {
V_31 = F_31 ( V_4 , V_8 -> V_44 ,
V_8 -> V_44 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_32 ( V_4 , & V_8 -> V_9 ) ;
if ( V_31 < 0 )
return V_31 ;
V_8 -> V_9 . V_45 = 1 ;
}
if ( V_8 -> V_46 ) {
V_31 = F_33 ( V_4 , V_8 -> V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_30 ( V_4 , V_8 -> V_46 , L_10 ) ;
}
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_47 * V_48 = V_8 -> V_49 ;
V_4 -> V_50 = V_48 ;
V_4 -> V_51 = 0 ;
V_48 -> V_52 = L_11 ;
V_48 -> V_53 [ V_54 ] = V_55 ;
V_48 -> V_53 [ V_54 ] . V_14 = V_8 -> V_56 [ 0 ] ;
V_48 -> V_53 [ V_54 ] . V_57 =
V_8 -> V_9 . V_58 ;
V_48 -> V_53 [ V_59 ] = V_60 ;
V_48 -> V_53 [ V_59 ] . V_61 = V_8 -> V_39 ;
V_48 -> V_53 [ V_59 ] . V_14 = V_8 -> V_12 [ 0 ] ;
V_4 -> V_51 ++ ;
if ( ! V_8 -> V_44 && ! V_8 -> V_46 )
return 0 ;
V_48 ++ ;
V_48 -> V_52 = L_12 ;
V_48 -> V_62 = V_63 ;
if ( V_8 -> V_44 ) {
V_48 -> V_53 [ V_54 ] =
V_64 ;
V_48 -> V_53 [ V_54 ] . V_14 = V_8 -> V_44 ;
}
if ( V_8 -> V_46 ) {
V_48 -> V_53 [ V_59 ] =
V_65 ;
V_48 -> V_53 [ V_59 ] . V_14 = V_8 -> V_46 ;
}
V_4 -> V_51 ++ ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 , T_1 V_66 , T_1 V_67 )
{
if ( V_66 ) {
F_36 ( V_4 , V_66 , V_68 ) ;
if ( F_24 ( V_4 , V_66 ) & V_34 )
F_37 ( V_4 , V_66 , 0 ,
V_69 ,
V_70 ) ;
}
if ( V_67 )
F_37 ( V_4 , V_67 , 0 ,
V_69 , V_71 ) ;
}
static void F_38 ( struct V_3 * V_4 , T_1 V_66 , T_1 V_72 )
{
if ( V_66 ) {
F_36 ( V_4 , V_66 , V_73 |
F_39 ( V_4 , V_66 ) ) ;
if ( F_24 ( V_4 , V_66 ) & V_43 )
F_37 ( V_4 , V_66 , 0 ,
V_69 ,
F_40 ( 0 ) ) ;
}
if ( V_72 )
F_37 ( V_4 , V_72 , 0 , V_69 ,
F_40 ( 0 ) ) ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_9 . V_32 ; V_30 ++ )
F_35 ( V_4 , V_8 -> V_33 [ V_30 ] ,
V_8 -> V_9 . V_35 [ V_30 ] ) ;
F_35 ( V_4 , V_25 -> V_37 [ 0 ] , V_8 -> V_38 ) ;
F_35 ( V_4 , V_25 -> V_74 [ 0 ] , V_8 -> V_44 ) ;
for ( V_30 = 0 ; V_30 < V_8 -> V_39 ; V_30 ++ )
F_38 ( V_4 , V_8 -> V_42 [ V_30 ] , V_8 -> V_12 [ V_30 ] ) ;
F_38 ( V_4 , V_25 -> V_75 , V_8 -> V_46 ) ;
return 0 ;
}
static void F_42 ( struct V_3 * V_4 )
{
F_43 ( V_4 -> V_8 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
int V_30 , V_76 ;
unsigned int V_77 ;
T_1 V_14 ;
V_76 = 0 ;
for ( V_30 = 0 ; V_30 < V_25 -> V_78 ; V_30 ++ ) {
V_14 = V_25 -> V_79 [ V_30 ] ;
V_77 = F_45 ( V_4 , V_14 ) ;
if ( ! V_77 )
continue;
if ( F_46 ( V_4 , V_14 , & V_8 -> V_56 [ V_30 ] , 1 ) != 1 )
continue;
V_8 -> V_33 [ V_76 ++ ] = V_14 ;
}
V_8 -> V_9 . V_35 = V_8 -> V_56 ;
V_8 -> V_9 . V_32 = V_76 ;
V_8 -> V_9 . V_58 = V_76 * 2 ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
int V_30 ;
unsigned int V_77 ;
T_1 V_14 , V_67 ;
if ( ! V_25 -> V_36 )
return;
V_14 = V_25 -> V_37 [ 0 ] ;
V_77 = F_45 ( V_4 , V_14 ) ;
if ( ! V_77 ) {
V_25 -> V_36 = 0 ;
return;
}
if ( F_46 ( V_4 , V_14 , & V_67 , 1 ) != 1 )
return;
for ( V_30 = 0 ; V_30 < V_25 -> V_78 ; V_30 ++ )
if ( V_67 == V_8 -> V_56 [ V_30 ] )
break;
if ( V_30 >= V_25 -> V_78 ) {
V_8 -> V_38 = V_67 ;
V_8 -> V_9 . V_80 = V_67 ;
}
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
T_1 V_14 , V_66 ;
int V_76 , V_30 , V_81 ;
V_76 = 0 ;
V_14 = V_4 -> V_82 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_83 ; V_30 ++ , V_14 ++ ) {
unsigned int V_84 = F_24 ( V_4 , V_14 ) ;
unsigned int type = F_49 ( V_84 ) ;
if ( type != V_85 )
continue;
if ( F_46 ( V_4 , V_14 , & V_66 , 1 ) != 1 )
continue;
if ( V_66 == V_25 -> V_75 ) {
V_8 -> V_46 = V_14 ;
continue;
}
for ( V_81 = 0 ; V_81 < V_25 -> V_39 ; V_81 ++ )
if ( V_25 -> V_86 [ V_81 ] . V_66 == V_66 )
break;
if ( V_81 >= V_25 -> V_39 )
continue;
V_8 -> V_42 [ V_76 ] = V_66 ;
F_50 ( V_4 , V_66 , V_25 ,
V_8 -> V_41 [ V_76 ] ,
sizeof( V_8 -> V_41 [ V_76 ] ) , NULL ) ;
V_8 -> V_12 [ V_76 ] = V_14 ;
V_76 ++ ;
}
V_8 -> V_39 = V_76 ;
}
static void F_51 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
if ( V_25 -> V_87 &&
F_46 ( V_4 , V_25 -> V_74 [ 0 ] ,
& V_8 -> V_44 , 1 ) == 1 )
V_8 -> V_9 . V_88 = V_8 -> V_44 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_31 ;
V_31 = F_53 ( V_4 , & V_8 -> V_26 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
F_44 ( V_4 ) ;
F_47 ( V_4 ) ;
F_51 ( V_4 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_31 ;
V_8 = F_55 ( sizeof( * V_8 ) , V_89 ) ;
if ( ! V_8 )
return - V_90 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_91 -> V_92 = 1 ;
V_31 = F_52 ( V_4 ) ;
if ( V_31 < 0 )
goto error;
V_4 -> V_93 = V_94 ;
return 0 ;
error:
F_43 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_31 ;
}
static int T_2 F_56 ( void )
{
return F_57 ( & V_95 ) ;
}
static void T_3 F_58 ( void )
{
F_59 ( & V_95 ) ;
}
