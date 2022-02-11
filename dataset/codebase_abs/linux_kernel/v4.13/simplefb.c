static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
T_2 * V_8 = V_7 -> V_9 ;
T_2 V_10 = V_2 >> ( 16 - V_7 -> V_11 . V_2 . V_12 ) ;
T_2 V_13 = V_3 >> ( 16 - V_7 -> V_11 . V_3 . V_12 ) ;
T_2 V_14 = V_4 >> ( 16 - V_7 -> V_11 . V_4 . V_12 ) ;
T_2 V_15 ;
if ( V_1 >= V_16 )
return - V_17 ;
V_15 = ( V_10 << V_7 -> V_11 . V_2 . V_18 ) |
( V_13 << V_7 -> V_11 . V_3 . V_18 ) |
( V_14 << V_7 -> V_11 . V_4 . V_18 ) ;
if ( V_7 -> V_11 . V_5 . V_12 > 0 ) {
T_2 V_19 = ( 1 << V_7 -> V_11 . V_5 . V_12 ) - 1 ;
V_19 <<= V_7 -> V_11 . V_5 . V_18 ;
V_15 |= V_19 ;
}
V_8 [ V_1 ] = V_15 ;
return 0 ;
}
static void F_2 ( struct V_6 * V_7 )
{
F_3 ( V_7 -> V_20 ) ;
F_4 ( V_7 -> V_20 ) ;
if ( V_7 -> V_21 )
F_5 ( V_7 -> V_21 ) ;
}
static int F_6 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_28 . V_29 ;
int V_30 ;
const char * V_31 ;
int V_32 ;
V_30 = F_7 ( V_27 , L_1 , & V_25 -> V_33 ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 , L_2 ) ;
return V_30 ;
}
V_30 = F_7 ( V_27 , L_3 , & V_25 -> V_34 ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 , L_4 ) ;
return V_30 ;
}
V_30 = F_7 ( V_27 , L_5 , & V_25 -> V_35 ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 , L_6 ) ;
return V_30 ;
}
V_30 = F_9 ( V_27 , L_7 , & V_31 ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 , L_8 ) ;
return V_30 ;
}
V_25 -> V_31 = NULL ;
for ( V_32 = 0 ; V_32 < F_10 ( V_36 ) ; V_32 ++ ) {
if ( strcmp ( V_31 , V_36 [ V_32 ] . V_37 ) )
continue;
V_25 -> V_31 = & V_36 [ V_32 ] ;
break;
}
if ( ! V_25 -> V_31 ) {
F_8 ( & V_23 -> V_28 , L_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_38 * V_39 = F_12 ( & V_23 -> V_28 ) ;
int V_32 ;
V_25 -> V_33 = V_39 -> V_33 ;
V_25 -> V_34 = V_39 -> V_34 ;
V_25 -> V_35 = V_39 -> V_35 ;
V_25 -> V_31 = NULL ;
for ( V_32 = 0 ; V_32 < F_10 ( V_36 ) ; V_32 ++ ) {
if ( strcmp ( V_39 -> V_31 , V_36 [ V_32 ] . V_37 ) )
continue;
V_25 -> V_31 = & V_36 [ V_32 ] ;
break;
}
if ( ! V_25 -> V_31 ) {
F_8 ( & V_23 -> V_28 , L_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_13 ( struct V_40 * V_20 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = V_23 -> V_28 . V_29 ;
struct V_41 * clock ;
int V_32 ;
if ( F_12 ( & V_23 -> V_28 ) || ! V_27 )
return 0 ;
V_20 -> V_42 = F_14 ( V_27 ) ;
if ( ! V_20 -> V_42 )
return 0 ;
V_20 -> V_43 = F_15 ( V_20 -> V_42 , sizeof( struct V_41 * ) , V_44 ) ;
if ( ! V_20 -> V_43 )
return - V_45 ;
for ( V_32 = 0 ; V_32 < V_20 -> V_42 ; V_32 ++ ) {
clock = F_16 ( V_27 , V_32 ) ;
if ( F_17 ( clock ) ) {
if ( F_18 ( clock ) == - V_46 ) {
while ( -- V_32 >= 0 ) {
if ( V_20 -> V_43 [ V_32 ] )
F_19 ( V_20 -> V_43 [ V_32 ] ) ;
}
F_20 ( V_20 -> V_43 ) ;
return - V_46 ;
}
F_8 ( & V_23 -> V_28 , L_10 ,
V_47 , V_32 , F_18 ( clock ) ) ;
continue;
}
V_20 -> V_43 [ V_32 ] = clock ;
}
return 0 ;
}
static void F_21 ( struct V_40 * V_20 ,
struct V_22 * V_23 )
{
int V_32 , V_30 ;
for ( V_32 = 0 ; V_32 < V_20 -> V_42 ; V_32 ++ ) {
if ( V_20 -> V_43 [ V_32 ] ) {
V_30 = F_22 ( V_20 -> V_43 [ V_32 ] ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 ,
L_11 ,
V_47 , V_32 , V_30 ) ;
F_19 ( V_20 -> V_43 [ V_32 ] ) ;
V_20 -> V_43 [ V_32 ] = NULL ;
}
}
}
V_20 -> V_48 = true ;
}
static void F_4 ( struct V_40 * V_20 )
{
int V_32 ;
if ( ! V_20 -> V_43 )
return;
for ( V_32 = 0 ; V_32 < V_20 -> V_42 ; V_32 ++ ) {
if ( V_20 -> V_43 [ V_32 ] ) {
if ( V_20 -> V_48 )
F_23 ( V_20 -> V_43 [ V_32 ] ) ;
F_19 ( V_20 -> V_43 [ V_32 ] ) ;
}
}
F_20 ( V_20 -> V_43 ) ;
}
static int F_13 ( struct V_40 * V_20 ,
struct V_22 * V_23 ) { return 0 ; }
static void F_21 ( struct V_40 * V_20 ,
struct V_22 * V_23 ) { }
static void F_4 ( struct V_40 * V_20 ) { }
static int F_24 ( struct V_40 * V_20 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = V_23 -> V_28 . V_29 ;
struct V_49 * V_50 ;
struct V_51 * V_51 ;
const char * V_52 ;
int V_53 = 0 , V_32 = 0 ;
if ( F_12 ( & V_23 -> V_28 ) || ! V_27 )
return 0 ;
F_25 (np, prop) {
V_52 = strstr ( V_50 -> V_37 , V_54 ) ;
if ( V_52 && V_52 != V_50 -> V_37 )
V_53 ++ ;
}
if ( ! V_53 )
return 0 ;
V_20 -> V_55 = F_26 ( & V_23 -> V_28 , V_53 ,
sizeof( struct V_51 * ) , V_44 ) ;
if ( ! V_20 -> V_55 )
return - V_45 ;
F_25 (np, prop) {
char V_37 [ 32 ] ;
V_52 = strstr ( V_50 -> V_37 , V_54 ) ;
if ( ! V_52 || V_52 == V_50 -> V_37 )
continue;
F_27 ( V_37 , V_50 -> V_37 ,
strlen ( V_50 -> V_37 ) - strlen ( V_54 ) + 1 ) ;
V_51 = F_28 ( & V_23 -> V_28 , V_37 ) ;
if ( F_17 ( V_51 ) ) {
if ( F_18 ( V_51 ) == - V_46 )
return - V_46 ;
F_8 ( & V_23 -> V_28 , L_12 ,
V_37 , F_18 ( V_51 ) ) ;
continue;
}
V_20 -> V_55 [ V_32 ++ ] = V_51 ;
}
V_20 -> V_56 = V_32 ;
return 0 ;
}
static void F_29 ( struct V_40 * V_20 ,
struct V_22 * V_23 )
{
int V_32 , V_30 ;
for ( V_32 = 0 ; V_32 < V_20 -> V_56 ; V_32 ++ ) {
V_30 = F_30 ( V_20 -> V_55 [ V_32 ] ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 ,
L_13 ,
V_32 , V_30 ) ;
F_31 ( V_20 -> V_55 [ V_32 ] ) ;
V_20 -> V_55 [ V_32 ] = NULL ;
}
}
V_20 -> V_57 = true ;
}
static void F_3 ( struct V_40 * V_20 )
{
int V_32 ;
if ( ! V_20 -> V_55 || ! V_20 -> V_57 )
return;
for ( V_32 = 0 ; V_32 < V_20 -> V_56 ; V_32 ++ )
if ( V_20 -> V_55 [ V_32 ] )
F_32 ( V_20 -> V_55 [ V_32 ] ) ;
}
static int F_24 ( struct V_40 * V_20 ,
struct V_22 * V_23 ) { return 0 ; }
static void F_29 ( struct V_40 * V_20 ,
struct V_22 * V_23 ) { }
static void F_3 ( struct V_40 * V_20 ) { }
static int F_33 ( struct V_22 * V_23 )
{
int V_30 ;
struct V_24 V_25 ;
struct V_6 * V_7 ;
struct V_40 * V_20 ;
struct V_58 * V_59 ;
if ( F_34 ( L_14 , NULL ) )
return - V_60 ;
V_30 = - V_60 ;
if ( F_12 ( & V_23 -> V_28 ) )
V_30 = F_11 ( V_23 , & V_25 ) ;
else if ( V_23 -> V_28 . V_29 )
V_30 = F_6 ( V_23 , & V_25 ) ;
if ( V_30 )
return V_30 ;
V_59 = F_35 ( V_23 , V_61 , 0 ) ;
if ( ! V_59 ) {
F_8 ( & V_23 -> V_28 , L_15 ) ;
return - V_17 ;
}
V_7 = F_36 ( sizeof( struct V_40 ) , & V_23 -> V_28 ) ;
if ( ! V_7 )
return - V_45 ;
F_37 ( V_23 , V_7 ) ;
V_20 = V_7 -> V_20 ;
V_7 -> V_62 = V_63 ;
V_7 -> V_62 . V_64 = V_59 -> V_65 ;
V_7 -> V_62 . V_66 = F_38 ( V_59 ) ;
V_7 -> V_62 . V_67 = V_25 . V_35 ;
V_7 -> V_11 = V_68 ;
V_7 -> V_11 . V_69 = V_25 . V_33 ;
V_7 -> V_11 . V_70 = V_25 . V_34 ;
V_7 -> V_11 . V_71 = V_25 . V_33 ;
V_7 -> V_11 . V_72 = V_25 . V_34 ;
V_7 -> V_11 . V_73 = V_25 . V_31 -> V_73 ;
V_7 -> V_11 . V_2 = V_25 . V_31 -> V_2 ;
V_7 -> V_11 . V_3 = V_25 . V_31 -> V_3 ;
V_7 -> V_11 . V_4 = V_25 . V_31 -> V_4 ;
V_7 -> V_11 . V_5 = V_25 . V_31 -> V_5 ;
V_7 -> V_74 = F_39 ( 1 ) ;
if ( ! V_7 -> V_74 ) {
V_30 = - V_45 ;
goto V_75;
}
V_7 -> V_74 -> V_76 [ 0 ] . V_77 = V_7 -> V_62 . V_64 ;
V_7 -> V_74 -> V_76 [ 0 ] . V_78 = V_7 -> V_62 . V_66 ;
V_7 -> V_79 = & V_80 ;
V_7 -> V_81 = V_82 | V_83 ;
V_7 -> V_21 = F_40 ( V_7 -> V_62 . V_64 ,
V_7 -> V_62 . V_66 ) ;
if ( ! V_7 -> V_21 ) {
V_30 = - V_45 ;
goto V_75;
}
V_7 -> V_9 = V_20 -> V_84 ;
V_30 = F_13 ( V_20 , V_23 ) ;
if ( V_30 < 0 )
goto V_85;
V_30 = F_24 ( V_20 , V_23 ) ;
if ( V_30 < 0 )
goto V_86;
F_21 ( V_20 , V_23 ) ;
F_29 ( V_20 , V_23 ) ;
F_41 ( & V_23 -> V_28 , L_16 ,
V_7 -> V_62 . V_64 , V_7 -> V_62 . V_66 ,
V_7 -> V_21 ) ;
F_41 ( & V_23 -> V_28 , L_17 ,
V_25 . V_31 -> V_37 ,
V_7 -> V_11 . V_69 , V_7 -> V_11 . V_70 ,
V_7 -> V_11 . V_73 , V_7 -> V_62 . V_67 ) ;
V_30 = F_42 ( V_7 ) ;
if ( V_30 < 0 ) {
F_8 ( & V_23 -> V_28 , L_18 , V_30 ) ;
goto V_87;
}
F_41 ( & V_23 -> V_28 , L_19 , V_7 -> V_88 ) ;
return 0 ;
V_87:
F_3 ( V_20 ) ;
V_86:
F_4 ( V_20 ) ;
V_85:
F_5 ( V_7 -> V_21 ) ;
V_75:
F_43 ( V_7 ) ;
return V_30 ;
}
static int F_44 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = F_45 ( V_23 ) ;
F_46 ( V_7 ) ;
F_43 ( V_7 ) ;
return 0 ;
}
static int T_3 F_47 ( void )
{
int V_30 ;
struct V_26 * V_27 ;
V_30 = F_48 ( & V_89 ) ;
if ( V_30 )
return V_30 ;
if ( F_49 ( V_90 ) && V_91 ) {
F_50 (of_chosen, np) {
if ( F_51 ( V_27 , L_20 ) )
F_52 ( V_27 , NULL , NULL ) ;
}
}
return 0 ;
}
