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
V_31 = F_31 ( V_4 , V_8 -> V_44 ) ;
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
F_36 ( V_4 , V_66 , 0 ,
V_68 , V_69 ) ;
if ( F_24 ( V_4 , V_66 ) & V_34 )
F_36 ( V_4 , V_66 , 0 ,
V_70 ,
V_71 ) ;
}
if ( V_67 )
F_36 ( V_4 , V_67 , 0 ,
V_70 , V_72 ) ;
}
static void F_37 ( struct V_3 * V_4 , T_1 V_66 , T_1 V_73 )
{
if ( V_66 ) {
F_36 ( V_4 , V_66 , 0 ,
V_68 , V_74 ) ;
if ( F_24 ( V_4 , V_66 ) & V_43 )
F_36 ( V_4 , V_66 , 0 ,
V_70 ,
F_38 ( 0 ) ) ;
}
if ( V_73 )
F_36 ( V_4 , V_73 , 0 , V_70 ,
F_38 ( 0 ) ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_9 . V_32 ; V_30 ++ )
F_35 ( V_4 , V_8 -> V_33 [ V_30 ] ,
V_8 -> V_9 . V_35 [ V_30 ] ) ;
F_35 ( V_4 , V_25 -> V_37 [ 0 ] , V_8 -> V_38 ) ;
F_35 ( V_4 , V_25 -> V_75 [ 0 ] , V_8 -> V_44 ) ;
for ( V_30 = 0 ; V_30 < V_8 -> V_39 ; V_30 ++ )
F_37 ( V_4 , V_8 -> V_42 [ V_30 ] , V_8 -> V_12 [ V_30 ] ) ;
F_37 ( V_4 , V_25 -> V_76 , V_8 -> V_46 ) ;
return 0 ;
}
static void F_40 ( struct V_3 * V_4 )
{
F_41 ( V_4 -> V_8 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
int V_30 , V_77 ;
unsigned int V_78 ;
T_1 V_14 ;
V_77 = 0 ;
for ( V_30 = 0 ; V_30 < V_25 -> V_79 ; V_30 ++ ) {
V_14 = V_25 -> V_80 [ V_30 ] ;
V_78 = F_43 ( V_4 , V_14 ) ;
if ( ! V_78 )
continue;
if ( F_44 ( V_4 , V_14 , & V_8 -> V_56 [ V_30 ] , 1 ) != 1 )
continue;
V_8 -> V_33 [ V_77 ++ ] = V_14 ;
}
V_8 -> V_9 . V_35 = V_8 -> V_56 ;
V_8 -> V_9 . V_32 = V_77 ;
V_8 -> V_9 . V_58 = V_77 * 2 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
int V_30 ;
unsigned int V_78 ;
T_1 V_14 , V_67 ;
if ( ! V_25 -> V_36 )
return;
V_14 = V_25 -> V_37 [ 0 ] ;
V_78 = F_43 ( V_4 , V_14 ) ;
if ( ! V_78 ) {
V_25 -> V_36 = 0 ;
return;
}
if ( F_44 ( V_4 , V_14 , & V_67 , 1 ) != 1 )
return;
for ( V_30 = 0 ; V_30 < V_25 -> V_79 ; V_30 ++ )
if ( V_67 == V_8 -> V_56 [ V_30 ] )
break;
if ( V_30 >= V_25 -> V_79 ) {
V_8 -> V_38 = V_67 ;
V_8 -> V_9 . V_81 = V_67 ;
}
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
T_1 V_14 , V_66 ;
int V_77 , V_30 , V_82 ;
V_77 = 0 ;
V_14 = V_4 -> V_83 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_84 ; V_30 ++ , V_14 ++ ) {
unsigned int V_85 = F_24 ( V_4 , V_14 ) ;
unsigned int type = F_47 ( V_85 ) ;
if ( type != V_86 )
continue;
if ( F_44 ( V_4 , V_14 , & V_66 , 1 ) != 1 )
continue;
if ( V_66 == V_25 -> V_76 ) {
V_8 -> V_46 = V_14 ;
continue;
}
for ( V_82 = 0 ; V_82 < V_25 -> V_39 ; V_82 ++ )
if ( V_25 -> V_87 [ V_82 ] . V_66 == V_66 )
break;
if ( V_82 >= V_25 -> V_39 )
continue;
V_8 -> V_42 [ V_77 ] = V_66 ;
V_8 -> V_41 [ V_77 ] = F_48 ( V_4 , V_66 , 1 ) ;
V_8 -> V_12 [ V_77 ] = V_14 ;
V_77 ++ ;
}
V_8 -> V_39 = V_77 ;
}
static void F_49 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_24 * V_25 = & V_8 -> V_26 ;
if ( V_25 -> V_88 &&
F_44 ( V_4 , V_25 -> V_75 [ 0 ] ,
& V_8 -> V_44 , 1 ) == 1 )
V_8 -> V_9 . V_89 = V_8 -> V_44 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_31 ;
V_31 = F_51 ( V_4 , & V_8 -> V_26 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
F_42 ( V_4 ) ;
F_45 ( V_4 ) ;
F_49 ( V_4 ) ;
F_46 ( V_4 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_31 ;
V_8 = F_53 ( sizeof( * V_8 ) , V_90 ) ;
if ( ! V_8 )
return - V_91 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_92 -> V_93 = 1 ;
V_31 = F_50 ( V_4 ) ;
if ( V_31 < 0 )
goto error;
V_4 -> V_94 = V_95 ;
return 0 ;
error:
F_41 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_31 ;
}
static int T_2 F_54 ( void )
{
return F_55 ( & V_96 ) ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_96 ) ;
}
