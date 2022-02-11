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
if ( V_7 -> V_20 )
F_3 ( V_7 -> V_20 ) ;
}
static int F_4 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_22 -> V_27 . V_28 ;
int V_29 ;
const char * V_30 ;
int V_31 ;
V_29 = F_5 ( V_26 , L_1 , & V_24 -> V_32 ) ;
if ( V_29 ) {
F_6 ( & V_22 -> V_27 , L_2 ) ;
return V_29 ;
}
V_29 = F_5 ( V_26 , L_3 , & V_24 -> V_33 ) ;
if ( V_29 ) {
F_6 ( & V_22 -> V_27 , L_4 ) ;
return V_29 ;
}
V_29 = F_5 ( V_26 , L_5 , & V_24 -> V_34 ) ;
if ( V_29 ) {
F_6 ( & V_22 -> V_27 , L_6 ) ;
return V_29 ;
}
V_29 = F_7 ( V_26 , L_7 , & V_30 ) ;
if ( V_29 ) {
F_6 ( & V_22 -> V_27 , L_8 ) ;
return V_29 ;
}
V_24 -> V_30 = NULL ;
for ( V_31 = 0 ; V_31 < F_8 ( V_35 ) ; V_31 ++ ) {
if ( strcmp ( V_30 , V_35 [ V_31 ] . V_36 ) )
continue;
V_24 -> V_30 = & V_35 [ V_31 ] ;
break;
}
if ( ! V_24 -> V_30 ) {
F_6 ( & V_22 -> V_27 , L_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_9 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_37 * V_38 = F_10 ( & V_22 -> V_27 ) ;
int V_31 ;
V_24 -> V_32 = V_38 -> V_32 ;
V_24 -> V_33 = V_38 -> V_33 ;
V_24 -> V_34 = V_38 -> V_34 ;
V_24 -> V_30 = NULL ;
for ( V_31 = 0 ; V_31 < F_8 ( V_35 ) ; V_31 ++ ) {
if ( strcmp ( V_38 -> V_30 , V_35 [ V_31 ] . V_36 ) )
continue;
V_24 -> V_30 = & V_35 [ V_31 ] ;
break;
}
if ( ! V_24 -> V_30 ) {
F_6 ( & V_22 -> V_27 , L_9 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_11 ( struct V_39 * V_40 ,
struct V_21 * V_22 )
{
struct V_25 * V_26 = V_22 -> V_27 . V_28 ;
struct V_41 * clock ;
int V_31 , V_29 ;
if ( F_10 ( & V_22 -> V_27 ) || ! V_26 )
return 0 ;
V_40 -> V_42 = F_12 ( V_26 ) ;
if ( V_40 -> V_42 <= 0 )
return 0 ;
V_40 -> V_43 = F_13 ( V_40 -> V_42 , sizeof( struct V_41 * ) , V_44 ) ;
if ( ! V_40 -> V_43 )
return - V_45 ;
for ( V_31 = 0 ; V_31 < V_40 -> V_42 ; V_31 ++ ) {
clock = F_14 ( V_26 , V_31 ) ;
if ( F_15 ( clock ) ) {
if ( F_16 ( clock ) == - V_46 ) {
while ( -- V_31 >= 0 ) {
if ( V_40 -> V_43 [ V_31 ] )
F_17 ( V_40 -> V_43 [ V_31 ] ) ;
}
F_18 ( V_40 -> V_43 ) ;
return - V_46 ;
}
F_6 ( & V_22 -> V_27 , L_10 ,
V_47 , V_31 , F_16 ( clock ) ) ;
continue;
}
V_40 -> V_43 [ V_31 ] = clock ;
}
for ( V_31 = 0 ; V_31 < V_40 -> V_42 ; V_31 ++ ) {
if ( V_40 -> V_43 [ V_31 ] ) {
V_29 = F_19 ( V_40 -> V_43 [ V_31 ] ) ;
if ( V_29 ) {
F_6 ( & V_22 -> V_27 ,
L_11 ,
V_47 , V_31 , V_29 ) ;
F_17 ( V_40 -> V_43 [ V_31 ] ) ;
V_40 -> V_43 [ V_31 ] = NULL ;
}
}
}
return 0 ;
}
static void F_20 ( struct V_39 * V_40 )
{
int V_31 ;
if ( ! V_40 -> V_43 )
return;
for ( V_31 = 0 ; V_31 < V_40 -> V_42 ; V_31 ++ ) {
if ( V_40 -> V_43 [ V_31 ] ) {
F_21 ( V_40 -> V_43 [ V_31 ] ) ;
F_17 ( V_40 -> V_43 [ V_31 ] ) ;
}
}
F_18 ( V_40 -> V_43 ) ;
}
static int F_11 ( struct V_39 * V_40 ,
struct V_21 * V_22 ) { return 0 ; }
static void F_20 ( struct V_39 * V_40 ) { }
static int F_22 ( struct V_21 * V_22 )
{
int V_29 ;
struct V_23 V_24 ;
struct V_6 * V_7 ;
struct V_39 * V_40 ;
struct V_48 * V_49 ;
if ( F_23 ( L_12 , NULL ) )
return - V_50 ;
V_29 = - V_50 ;
if ( F_10 ( & V_22 -> V_27 ) )
V_29 = F_9 ( V_22 , & V_24 ) ;
else if ( V_22 -> V_27 . V_28 )
V_29 = F_4 ( V_22 , & V_24 ) ;
if ( V_29 )
return V_29 ;
V_49 = F_24 ( V_22 , V_51 , 0 ) ;
if ( ! V_49 ) {
F_6 ( & V_22 -> V_27 , L_13 ) ;
return - V_17 ;
}
V_7 = F_25 ( sizeof( struct V_39 ) , & V_22 -> V_27 ) ;
if ( ! V_7 )
return - V_45 ;
F_26 ( V_22 , V_7 ) ;
V_40 = V_7 -> V_40 ;
V_7 -> V_52 = V_53 ;
V_7 -> V_52 . V_54 = V_49 -> V_55 ;
V_7 -> V_52 . V_56 = F_27 ( V_49 ) ;
V_7 -> V_52 . V_57 = V_24 . V_34 ;
V_7 -> V_11 = V_58 ;
V_7 -> V_11 . V_59 = V_24 . V_32 ;
V_7 -> V_11 . V_60 = V_24 . V_33 ;
V_7 -> V_11 . V_61 = V_24 . V_32 ;
V_7 -> V_11 . V_62 = V_24 . V_33 ;
V_7 -> V_11 . V_63 = V_24 . V_30 -> V_63 ;
V_7 -> V_11 . V_2 = V_24 . V_30 -> V_2 ;
V_7 -> V_11 . V_3 = V_24 . V_30 -> V_3 ;
V_7 -> V_11 . V_4 = V_24 . V_30 -> V_4 ;
V_7 -> V_11 . V_5 = V_24 . V_30 -> V_5 ;
V_7 -> V_64 = F_28 ( 1 ) ;
if ( ! V_7 -> V_64 ) {
V_29 = - V_45 ;
goto V_65;
}
V_7 -> V_64 -> V_66 [ 0 ] . V_67 = V_7 -> V_52 . V_54 ;
V_7 -> V_64 -> V_66 [ 0 ] . V_68 = V_7 -> V_52 . V_56 ;
V_7 -> V_69 = & V_70 ;
V_7 -> V_71 = V_72 | V_73 ;
V_7 -> V_20 = F_29 ( V_7 -> V_52 . V_54 ,
V_7 -> V_52 . V_56 ) ;
if ( ! V_7 -> V_20 ) {
V_29 = - V_45 ;
goto V_65;
}
V_7 -> V_9 = V_40 -> V_74 ;
V_29 = F_11 ( V_40 , V_22 ) ;
if ( V_29 < 0 )
goto V_75;
F_30 ( & V_22 -> V_27 , L_14 ,
V_7 -> V_52 . V_54 , V_7 -> V_52 . V_56 ,
V_7 -> V_20 ) ;
F_30 ( & V_22 -> V_27 , L_15 ,
V_24 . V_30 -> V_36 ,
V_7 -> V_11 . V_59 , V_7 -> V_11 . V_60 ,
V_7 -> V_11 . V_63 , V_7 -> V_52 . V_57 ) ;
V_29 = F_31 ( V_7 ) ;
if ( V_29 < 0 ) {
F_6 ( & V_22 -> V_27 , L_16 , V_29 ) ;
goto V_76;
}
F_30 ( & V_22 -> V_27 , L_17 , V_7 -> V_77 ) ;
return 0 ;
V_76:
F_20 ( V_40 ) ;
V_75:
F_3 ( V_7 -> V_20 ) ;
V_65:
F_32 ( V_7 ) ;
return V_29 ;
}
static int F_33 ( struct V_21 * V_22 )
{
struct V_6 * V_7 = F_34 ( V_22 ) ;
struct V_39 * V_40 = V_7 -> V_40 ;
F_35 ( V_7 ) ;
F_20 ( V_40 ) ;
F_32 ( V_7 ) ;
return 0 ;
}
static int T_3 F_36 ( void )
{
int V_29 ;
struct V_25 * V_26 ;
V_29 = F_37 ( & V_78 ) ;
if ( V_29 )
return V_29 ;
if ( F_38 ( V_79 ) && V_80 ) {
F_39 (of_chosen, np) {
if ( F_40 ( V_26 , L_18 ) )
F_41 ( V_26 , NULL , NULL ) ;
}
}
return 0 ;
}
