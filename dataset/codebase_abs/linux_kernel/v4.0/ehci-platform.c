static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
int V_12 ;
V_2 -> V_13 = V_8 -> V_13 ;
V_11 -> V_14 = V_8 -> V_14 ;
if ( V_8 -> V_15 ) {
V_12 = V_8 -> V_15 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_11 -> V_16 = V_2 -> V_17 + V_8 -> V_18 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 -> V_19 )
V_11 -> V_20 = 0 ;
return 0 ;
}
static int F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 , V_24 , V_25 ;
for ( V_23 = 0 ; V_23 < V_26 && V_22 -> V_27 [ V_23 ] ; V_23 ++ ) {
V_24 = F_9 ( V_22 -> V_27 [ V_23 ] ) ;
if ( V_24 )
goto V_28;
}
for ( V_25 = 0 ; V_25 < V_22 -> V_29 ; V_25 ++ ) {
if ( V_22 -> V_30 [ V_25 ] ) {
V_24 = F_10 ( V_22 -> V_30 [ V_25 ] ) ;
if ( V_24 )
goto V_31;
V_24 = F_11 ( V_22 -> V_30 [ V_25 ] ) ;
if ( V_24 ) {
F_12 ( V_22 -> V_30 [ V_25 ] ) ;
goto V_31;
}
}
}
return 0 ;
V_31:
while ( -- V_25 >= 0 ) {
if ( V_22 -> V_30 [ V_25 ] ) {
F_13 ( V_22 -> V_30 [ V_25 ] ) ;
F_12 ( V_22 -> V_30 [ V_25 ] ) ;
}
}
V_28:
while ( -- V_23 >= 0 )
F_14 ( V_22 -> V_27 [ V_23 ] ) ;
return V_24 ;
}
static void F_15 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 , V_25 ;
for ( V_25 = 0 ; V_25 < V_22 -> V_29 ; V_25 ++ ) {
if ( V_22 -> V_30 [ V_25 ] ) {
F_13 ( V_22 -> V_30 [ V_25 ] ) ;
F_12 ( V_22 -> V_30 [ V_25 ] ) ;
}
}
for ( V_23 = V_26 - 1 ; V_23 >= 0 ; V_23 -- )
if ( V_22 -> V_27 [ V_23 ] )
F_14 ( V_22 -> V_27 [ V_23 ] ) ;
}
static int F_16 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
const char * V_34 ;
int V_35 , V_36 , V_25 , V_23 = 0 ;
if ( F_17 () )
return - V_37 ;
if ( ! V_8 )
V_8 = & V_38 ;
V_35 = F_18 ( & V_9 -> V_9 ,
V_8 -> V_39 ? F_19 ( 64 ) : F_19 ( 32 ) ) ;
if ( V_35 )
return V_35 ;
V_36 = F_20 ( V_9 , 0 ) ;
if ( V_36 < 0 ) {
F_21 ( & V_9 -> V_9 , L_1 ) ;
return V_36 ;
}
V_2 = F_22 ( & V_40 , & V_9 -> V_9 ,
F_23 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_41 ;
F_24 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_42 = V_8 ;
V_22 = F_8 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_8 == & V_38 && V_9 -> V_9 . V_43 ) {
if ( F_25 ( V_9 -> V_9 . V_43 , L_2 ) )
V_11 -> V_44 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_43 , L_3 ) )
V_11 -> V_45 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_43 , L_4 ) )
V_11 -> V_44 = V_11 -> V_45 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_43 ,
L_5 ) )
V_8 -> V_46 = 1 ;
V_22 -> V_29 = F_26 ( V_9 -> V_9 . V_43 ,
L_6 , L_7 ) ;
V_22 -> V_29 = V_22 -> V_29 > 0 ? V_22 -> V_29 : 1 ;
V_22 -> V_30 = F_27 ( & V_9 -> V_9 , V_22 -> V_29 ,
sizeof( struct V_47 * ) , V_48 ) ;
if ( ! V_22 -> V_30 )
return - V_41 ;
for ( V_25 = 0 ; V_25 < V_22 -> V_29 ; V_25 ++ ) {
V_35 = F_28 (
V_9 -> V_9 . V_43 ,
L_8 , V_25 ,
& V_34 ) ;
if ( V_35 < 0 ) {
if ( V_22 -> V_29 > 1 ) {
F_21 ( & V_9 -> V_9 , L_9 ) ;
goto V_49;
} else
V_34 = L_10 ;
}
V_22 -> V_30 [ V_25 ] = F_29 ( & V_9 -> V_9 ,
V_34 ) ;
if ( F_30 ( V_22 -> V_30 [ V_25 ] ) ) {
V_35 = F_31 ( V_22 -> V_30 [ V_25 ] ) ;
if ( ( V_22 -> V_29 > 1 ) ||
( V_35 == - V_50 ) )
goto V_49;
V_22 -> V_30 [ V_25 ] = NULL ;
}
}
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_22 -> V_27 [ V_23 ] = F_32 ( V_9 -> V_9 . V_43 , V_23 ) ;
if ( F_30 ( V_22 -> V_27 [ V_23 ] ) ) {
V_35 = F_31 ( V_22 -> V_27 [ V_23 ] ) ;
if ( V_35 == - V_50 )
goto V_51;
V_22 -> V_27 [ V_23 ] = NULL ;
break;
}
}
}
V_22 -> V_52 = F_33 ( & V_9 -> V_9 , NULL ) ;
if ( F_30 ( V_22 -> V_52 ) ) {
V_35 = F_31 ( V_22 -> V_52 ) ;
if ( V_35 == - V_50 )
goto V_51;
V_22 -> V_52 = NULL ;
} else {
V_35 = F_34 ( V_22 -> V_52 ) ;
if ( V_35 )
goto V_51;
}
if ( V_8 -> V_45 )
V_11 -> V_45 = 1 ;
if ( V_8 -> V_44 )
V_11 -> V_44 = 1 ;
#ifndef F_35
if ( V_11 -> V_44 ) {
F_21 ( & V_9 -> V_9 ,
L_11 ) ;
V_35 = - V_53 ;
goto V_54;
}
#endif
#ifndef F_36
if ( V_11 -> V_45 ) {
F_21 ( & V_9 -> V_9 ,
L_12 ) ;
V_35 = - V_53 ;
goto V_54;
}
#endif
if ( V_8 -> V_55 ) {
V_35 = V_8 -> V_55 ( V_9 ) ;
if ( V_35 < 0 )
goto V_54;
}
V_33 = F_37 ( V_9 , V_56 , 0 ) ;
V_2 -> V_17 = F_38 ( & V_9 -> V_9 , V_33 ) ;
if ( F_30 ( V_2 -> V_17 ) ) {
V_35 = F_31 ( V_2 -> V_17 ) ;
goto V_57;
}
V_2 -> V_58 = V_33 -> V_59 ;
V_2 -> V_60 = F_39 ( V_33 ) ;
V_35 = F_40 ( V_2 , V_36 , V_61 ) ;
if ( V_35 )
goto V_57;
F_41 ( V_2 -> V_5 . V_6 ) ;
F_24 ( V_9 , V_2 ) ;
return V_35 ;
V_57:
if ( V_8 -> V_62 )
V_8 -> V_62 ( V_9 ) ;
V_54:
if ( V_22 -> V_52 )
F_42 ( V_22 -> V_52 ) ;
V_51:
while ( -- V_23 >= 0 )
F_43 ( V_22 -> V_27 [ V_23 ] ) ;
V_49:
if ( V_8 == & V_38 )
V_9 -> V_9 . V_42 = NULL ;
F_44 ( V_2 ) ;
return V_35 ;
}
static int F_45 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 ;
F_46 ( V_2 ) ;
if ( V_8 -> V_62 )
V_8 -> V_62 ( V_9 ) ;
if ( V_22 -> V_52 )
F_42 ( V_22 -> V_52 ) ;
for ( V_23 = 0 ; V_23 < V_26 && V_22 -> V_27 [ V_23 ] ; V_23 ++ )
F_43 ( V_22 -> V_27 [ V_23 ] ) ;
F_44 ( V_2 ) ;
if ( V_8 == & V_38 )
V_9 -> V_9 . V_42 = NULL ;
return 0 ;
}
static int F_47 ( struct V_63 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_49 ( V_9 , struct V_3 , V_9 ) ;
bool V_64 = F_50 ( V_9 ) ;
int V_24 ;
V_24 = F_51 ( V_2 , V_64 ) ;
if ( V_24 )
return V_24 ;
if ( V_8 -> V_65 )
V_8 -> V_65 ( V_4 ) ;
return V_24 ;
}
static int F_52 ( struct V_63 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_49 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_55 ) {
int V_35 = V_8 -> V_55 ( V_4 ) ;
if ( V_35 < 0 )
return V_35 ;
}
F_53 ( V_2 , V_8 -> V_46 ) ;
return 0 ;
}
static int T_1 F_54 ( void )
{
if ( F_17 () )
return - V_37 ;
F_55 ( L_13 V_66 L_14 , V_67 ) ;
F_56 ( & V_40 , & V_68 ) ;
return F_57 ( & V_69 ) ;
}
static void T_2 F_58 ( void )
{
F_59 ( & V_69 ) ;
}
