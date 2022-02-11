static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
int V_12 ;
V_11 -> V_13 = V_8 -> V_13 ;
if ( V_8 -> V_14 ) {
V_12 = V_8 -> V_14 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_11 -> V_15 = V_2 -> V_16 + V_8 -> V_17 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 -> V_18 )
V_11 -> V_19 = 0 ;
return 0 ;
}
static int F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_22 , V_23 , V_24 ;
for ( V_22 = 0 ; V_22 < V_25 && V_21 -> V_26 [ V_22 ] ; V_22 ++ ) {
V_23 = F_9 ( V_21 -> V_26 [ V_22 ] ) ;
if ( V_23 )
goto V_27;
}
for ( V_24 = 0 ; V_24 < V_21 -> V_28 ; V_24 ++ ) {
V_23 = F_10 ( V_21 -> V_29 [ V_24 ] ) ;
if ( V_23 )
goto V_30;
V_23 = F_11 ( V_21 -> V_29 [ V_24 ] ) ;
if ( V_23 ) {
F_12 ( V_21 -> V_29 [ V_24 ] ) ;
goto V_30;
}
}
return 0 ;
V_30:
while ( -- V_24 >= 0 ) {
F_13 ( V_21 -> V_29 [ V_24 ] ) ;
F_12 ( V_21 -> V_29 [ V_24 ] ) ;
}
V_27:
while ( -- V_22 >= 0 )
F_14 ( V_21 -> V_26 [ V_22 ] ) ;
return V_23 ;
}
static void F_15 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_22 , V_24 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_28 ; V_24 ++ ) {
F_13 ( V_21 -> V_29 [ V_24 ] ) ;
F_12 ( V_21 -> V_29 [ V_24 ] ) ;
}
for ( V_22 = V_25 - 1 ; V_22 >= 0 ; V_22 -- )
if ( V_21 -> V_26 [ V_22 ] )
F_14 ( V_21 -> V_26 [ V_22 ] ) ;
}
static int F_16 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_20 * V_21 ;
struct V_10 * V_11 ;
int V_33 , V_34 , V_24 , V_22 = 0 , V_35 ;
if ( F_17 () )
return - V_36 ;
if ( ! V_8 )
V_8 = & V_37 ;
V_33 = F_18 ( & V_9 -> V_9 ,
V_8 -> V_38 ? F_19 ( 64 ) : F_19 ( 32 ) ) ;
if ( V_33 ) {
F_20 ( & V_9 -> V_9 , L_1 ) ;
return V_33 ;
}
V_34 = F_21 ( V_9 , 0 ) ;
if ( V_34 < 0 ) {
F_20 ( & V_9 -> V_9 , L_2 ) ;
return V_34 ;
}
V_2 = F_22 ( & V_39 , & V_9 -> V_9 ,
F_23 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_40 ;
F_24 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_41 = V_8 ;
V_21 = F_8 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_8 == & V_37 && V_9 -> V_9 . V_42 ) {
if ( F_25 ( V_9 -> V_9 . V_42 , L_3 ) )
V_11 -> V_43 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_42 , L_4 ) )
V_11 -> V_44 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_42 , L_5 ) )
V_11 -> V_43 = V_11 -> V_44 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_42 ,
L_6 ) )
V_21 -> V_45 = true ;
if ( F_25 ( V_9 -> V_9 . V_42 ,
L_7 ) )
V_2 -> V_46 = 1 ;
V_21 -> V_28 = F_26 ( V_9 -> V_9 . V_42 ,
L_8 , L_9 ) ;
if ( V_21 -> V_28 > 0 ) {
V_21 -> V_29 = F_27 ( & V_9 -> V_9 , V_21 -> V_28 ,
sizeof( struct V_47 * ) , V_48 ) ;
if ( ! V_21 -> V_29 )
return - V_40 ;
} else
V_21 -> V_28 = 0 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_28 ; V_24 ++ ) {
V_21 -> V_29 [ V_24 ] = F_28 (
& V_9 -> V_9 , V_9 -> V_9 . V_42 , V_24 ) ;
if ( F_29 ( V_21 -> V_29 [ V_24 ] ) ) {
V_33 = F_30 ( V_21 -> V_29 [ V_24 ] ) ;
goto V_49;
} else if ( ! V_2 -> V_47 ) {
V_2 -> V_47 = V_21 -> V_29 [ V_24 ] ;
}
}
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
V_21 -> V_26 [ V_22 ] = F_31 ( V_9 -> V_9 . V_42 , V_22 ) ;
if ( F_29 ( V_21 -> V_26 [ V_22 ] ) ) {
V_33 = F_30 ( V_21 -> V_26 [ V_22 ] ) ;
if ( V_33 == - V_50 )
goto V_51;
V_21 -> V_26 [ V_22 ] = NULL ;
break;
}
}
}
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ ) {
V_21 -> V_53 [ V_35 ] = F_32 (
& V_9 -> V_9 , V_35 ) ;
if ( F_29 ( V_21 -> V_53 [ V_35 ] ) ) {
V_33 = F_30 ( V_21 -> V_53 [ V_35 ] ) ;
if ( V_33 == - V_50 )
goto V_54;
V_21 -> V_53 [ V_35 ] = NULL ;
break;
}
V_33 = F_33 ( V_21 -> V_53 [ V_35 ] ) ;
if ( V_33 )
goto V_54;
}
if ( V_8 -> V_44 )
V_11 -> V_44 = 1 ;
if ( V_8 -> V_43 )
V_11 -> V_43 = 1 ;
if ( V_8 -> V_46 )
V_2 -> V_46 = 1 ;
if ( V_8 -> V_45 )
V_21 -> V_45 = true ;
#ifndef F_34
if ( V_11 -> V_43 ) {
F_20 ( & V_9 -> V_9 ,
L_10 ) ;
V_33 = - V_55 ;
goto V_54;
}
#endif
#ifndef F_35
if ( V_11 -> V_44 ) {
F_20 ( & V_9 -> V_9 ,
L_11 ) ;
V_33 = - V_55 ;
goto V_54;
}
#endif
if ( V_8 -> V_56 ) {
V_33 = V_8 -> V_56 ( V_9 ) ;
if ( V_33 < 0 )
goto V_54;
}
V_32 = F_36 ( V_9 , V_57 , 0 ) ;
V_2 -> V_16 = F_37 ( & V_9 -> V_9 , V_32 ) ;
if ( F_29 ( V_2 -> V_16 ) ) {
V_33 = F_30 ( V_2 -> V_16 ) ;
goto V_58;
}
V_2 -> V_59 = V_32 -> V_60 ;
V_2 -> V_61 = F_38 ( V_32 ) ;
V_33 = F_39 ( V_2 , V_34 , V_62 ) ;
if ( V_33 )
goto V_58;
F_40 ( V_2 -> V_5 . V_6 ) ;
F_41 ( V_2 -> V_5 . V_6 ) ;
F_24 ( V_9 , V_2 ) ;
return V_33 ;
V_58:
if ( V_8 -> V_63 )
V_8 -> V_63 ( V_9 ) ;
V_54:
while ( -- V_35 >= 0 )
F_42 ( V_21 -> V_53 [ V_35 ] ) ;
V_51:
while ( -- V_22 >= 0 )
F_43 ( V_21 -> V_26 [ V_22 ] ) ;
V_49:
if ( V_8 == & V_37 )
V_9 -> V_9 . V_41 = NULL ;
F_44 ( V_2 ) ;
return V_33 ;
}
static int F_45 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_22 , V_35 ;
F_46 ( V_2 ) ;
if ( V_8 -> V_63 )
V_8 -> V_63 ( V_9 ) ;
for ( V_35 = 0 ; V_35 < V_52 && V_21 -> V_53 [ V_35 ] ; V_35 ++ )
F_42 ( V_21 -> V_53 [ V_35 ] ) ;
for ( V_22 = 0 ; V_22 < V_25 && V_21 -> V_26 [ V_22 ] ; V_22 ++ )
F_43 ( V_21 -> V_26 [ V_22 ] ) ;
F_44 ( V_2 ) ;
if ( V_8 == & V_37 )
V_9 -> V_9 . V_41 = NULL ;
return 0 ;
}
static int F_47 ( struct V_64 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_9 ) ;
bool V_65 = F_49 ( V_9 ) ;
int V_23 ;
V_23 = F_50 ( V_2 , V_65 ) ;
if ( V_23 )
return V_23 ;
if ( V_8 -> V_66 )
V_8 -> V_66 ( V_4 ) ;
return V_23 ;
}
static int F_51 ( struct V_64 * V_9 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_9 ) ;
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_64 * V_67 ;
if ( V_8 -> V_56 ) {
int V_33 = V_8 -> V_56 ( V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_67 = F_52 ( V_2 -> V_5 . V_6 ) ;
if ( V_67 ) {
F_53 ( V_2 -> V_5 . V_6 , V_67 ) ;
F_54 ( V_67 ) ;
}
F_55 ( V_2 , V_21 -> V_45 ) ;
return 0 ;
}
static int T_1 F_56 ( void )
{
if ( F_17 () )
return - V_36 ;
F_57 ( L_12 V_68 L_13 , V_69 ) ;
F_58 ( & V_39 , & V_70 ) ;
return F_59 ( & V_71 ) ;
}
static void T_2 F_60 ( void )
{
F_61 ( & V_71 ) ;
}
