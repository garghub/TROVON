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
int V_32 , V_30 ;
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
for ( V_32 = 0 ; V_32 < V_20 -> V_42 ; V_32 ++ ) {
if ( V_20 -> V_43 [ V_32 ] ) {
V_30 = F_21 ( V_20 -> V_43 [ V_32 ] ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 ,
L_11 ,
V_47 , V_32 , V_30 ) ;
F_19 ( V_20 -> V_43 [ V_32 ] ) ;
V_20 -> V_43 [ V_32 ] = NULL ;
}
}
}
return 0 ;
}
static void F_4 ( struct V_40 * V_20 )
{
int V_32 ;
if ( ! V_20 -> V_43 )
return;
for ( V_32 = 0 ; V_32 < V_20 -> V_42 ; V_32 ++ ) {
if ( V_20 -> V_43 [ V_32 ] ) {
F_22 ( V_20 -> V_43 [ V_32 ] ) ;
F_19 ( V_20 -> V_43 [ V_32 ] ) ;
}
}
F_20 ( V_20 -> V_43 ) ;
}
static int F_13 ( struct V_40 * V_20 ,
struct V_22 * V_23 ) { return 0 ; }
static void F_4 ( struct V_40 * V_20 ) { }
static int F_23 ( struct V_40 * V_20 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = V_23 -> V_28 . V_29 ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
const char * V_51 ;
int V_52 = 0 , V_32 = 0 , V_30 ;
if ( F_12 ( & V_23 -> V_28 ) || ! V_27 )
return 0 ;
F_24 (np, prop) {
V_51 = strstr ( V_49 -> V_37 , V_53 ) ;
if ( V_51 && V_51 != V_49 -> V_37 )
V_52 ++ ;
}
if ( ! V_52 )
return 0 ;
V_20 -> V_54 = F_25 ( & V_23 -> V_28 , V_52 ,
sizeof( struct V_50 * ) , V_44 ) ;
if ( ! V_20 -> V_54 )
return - V_45 ;
F_24 (np, prop) {
char V_37 [ 32 ] ;
V_51 = strstr ( V_49 -> V_37 , V_53 ) ;
if ( ! V_51 || V_51 == V_49 -> V_37 )
continue;
F_26 ( V_37 , V_49 -> V_37 ,
strlen ( V_49 -> V_37 ) - strlen ( V_53 ) + 1 ) ;
V_50 = F_27 ( & V_23 -> V_28 , V_37 ) ;
if ( F_17 ( V_50 ) ) {
if ( F_18 ( V_50 ) == - V_46 )
return - V_46 ;
F_8 ( & V_23 -> V_28 , L_12 ,
V_37 , F_18 ( V_50 ) ) ;
continue;
}
V_20 -> V_54 [ V_32 ++ ] = V_50 ;
}
V_20 -> V_55 = V_32 ;
for ( V_32 = 0 ; V_32 < V_20 -> V_55 ; V_32 ++ ) {
V_30 = F_28 ( V_20 -> V_54 [ V_32 ] ) ;
if ( V_30 ) {
F_8 ( & V_23 -> V_28 ,
L_13 ,
V_32 , V_30 ) ;
F_29 ( V_20 -> V_54 [ V_32 ] ) ;
V_20 -> V_54 [ V_32 ] = NULL ;
}
}
return 0 ;
}
static void F_3 ( struct V_40 * V_20 )
{
int V_32 ;
if ( ! V_20 -> V_54 )
return;
for ( V_32 = 0 ; V_32 < V_20 -> V_55 ; V_32 ++ )
if ( V_20 -> V_54 [ V_32 ] )
F_30 ( V_20 -> V_54 [ V_32 ] ) ;
}
static int F_23 ( struct V_40 * V_20 ,
struct V_22 * V_23 ) { return 0 ; }
static void F_3 ( struct V_40 * V_20 ) { }
static int F_31 ( struct V_22 * V_23 )
{
int V_30 ;
struct V_24 V_25 ;
struct V_6 * V_7 ;
struct V_40 * V_20 ;
struct V_56 * V_57 ;
if ( F_32 ( L_14 , NULL ) )
return - V_58 ;
V_30 = - V_58 ;
if ( F_12 ( & V_23 -> V_28 ) )
V_30 = F_11 ( V_23 , & V_25 ) ;
else if ( V_23 -> V_28 . V_29 )
V_30 = F_6 ( V_23 , & V_25 ) ;
if ( V_30 )
return V_30 ;
V_57 = F_33 ( V_23 , V_59 , 0 ) ;
if ( ! V_57 ) {
F_8 ( & V_23 -> V_28 , L_15 ) ;
return - V_17 ;
}
V_7 = F_34 ( sizeof( struct V_40 ) , & V_23 -> V_28 ) ;
if ( ! V_7 )
return - V_45 ;
F_35 ( V_23 , V_7 ) ;
V_20 = V_7 -> V_20 ;
V_7 -> V_60 = V_61 ;
V_7 -> V_60 . V_62 = V_57 -> V_63 ;
V_7 -> V_60 . V_64 = F_36 ( V_57 ) ;
V_7 -> V_60 . V_65 = V_25 . V_35 ;
V_7 -> V_11 = V_66 ;
V_7 -> V_11 . V_67 = V_25 . V_33 ;
V_7 -> V_11 . V_68 = V_25 . V_34 ;
V_7 -> V_11 . V_69 = V_25 . V_33 ;
V_7 -> V_11 . V_70 = V_25 . V_34 ;
V_7 -> V_11 . V_71 = V_25 . V_31 -> V_71 ;
V_7 -> V_11 . V_2 = V_25 . V_31 -> V_2 ;
V_7 -> V_11 . V_3 = V_25 . V_31 -> V_3 ;
V_7 -> V_11 . V_4 = V_25 . V_31 -> V_4 ;
V_7 -> V_11 . V_5 = V_25 . V_31 -> V_5 ;
V_7 -> V_72 = F_37 ( 1 ) ;
if ( ! V_7 -> V_72 ) {
V_30 = - V_45 ;
goto V_73;
}
V_7 -> V_72 -> V_74 [ 0 ] . V_75 = V_7 -> V_60 . V_62 ;
V_7 -> V_72 -> V_74 [ 0 ] . V_76 = V_7 -> V_60 . V_64 ;
V_7 -> V_77 = & V_78 ;
V_7 -> V_79 = V_80 | V_81 ;
V_7 -> V_21 = F_38 ( V_7 -> V_60 . V_62 ,
V_7 -> V_60 . V_64 ) ;
if ( ! V_7 -> V_21 ) {
V_30 = - V_45 ;
goto V_73;
}
V_7 -> V_9 = V_20 -> V_82 ;
V_30 = F_13 ( V_20 , V_23 ) ;
if ( V_30 < 0 )
goto V_83;
V_30 = F_23 ( V_20 , V_23 ) ;
if ( V_30 < 0 )
goto V_84;
F_39 ( & V_23 -> V_28 , L_16 ,
V_7 -> V_60 . V_62 , V_7 -> V_60 . V_64 ,
V_7 -> V_21 ) ;
F_39 ( & V_23 -> V_28 , L_17 ,
V_25 . V_31 -> V_37 ,
V_7 -> V_11 . V_67 , V_7 -> V_11 . V_68 ,
V_7 -> V_11 . V_71 , V_7 -> V_60 . V_65 ) ;
V_30 = F_40 ( V_7 ) ;
if ( V_30 < 0 ) {
F_8 ( & V_23 -> V_28 , L_18 , V_30 ) ;
goto V_85;
}
F_39 ( & V_23 -> V_28 , L_19 , V_7 -> V_86 ) ;
return 0 ;
V_85:
F_3 ( V_20 ) ;
V_84:
F_4 ( V_20 ) ;
V_83:
F_5 ( V_7 -> V_21 ) ;
V_73:
F_41 ( V_7 ) ;
return V_30 ;
}
static int F_42 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = F_43 ( V_23 ) ;
F_44 ( V_7 ) ;
F_41 ( V_7 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
int V_30 ;
struct V_26 * V_27 ;
V_30 = F_46 ( & V_87 ) ;
if ( V_30 )
return V_30 ;
if ( F_47 ( V_88 ) && V_89 ) {
F_48 (of_chosen, np) {
if ( F_49 ( V_27 , L_20 ) )
F_50 ( V_27 , NULL , NULL ) ;
}
}
return 0 ;
}
