static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 , V_8 , V_9 ;
for ( V_7 = 0 ; V_7 < V_10 && V_6 -> V_11 [ V_7 ] ; V_7 ++ ) {
V_8 = F_4 ( V_6 -> V_11 [ V_7 ] ) ;
if ( V_8 )
goto V_12;
}
for ( V_9 = 0 ; V_9 < V_6 -> V_13 ; V_9 ++ ) {
if ( V_6 -> V_14 [ V_9 ] ) {
V_8 = F_5 ( V_6 -> V_14 [ V_9 ] ) ;
if ( V_8 )
goto V_15;
V_8 = F_6 ( V_6 -> V_14 [ V_9 ] ) ;
if ( V_8 ) {
F_7 ( V_6 -> V_14 [ V_9 ] ) ;
goto V_15;
}
}
}
return 0 ;
V_15:
while ( -- V_9 >= 0 ) {
if ( V_6 -> V_14 [ V_9 ] ) {
F_8 ( V_6 -> V_14 [ V_9 ] ) ;
F_7 ( V_6 -> V_14 [ V_9 ] ) ;
}
}
V_12:
while ( -- V_7 >= 0 )
F_9 ( V_6 -> V_11 [ V_7 ] ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 , V_9 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_13 ; V_9 ++ ) {
if ( V_6 -> V_14 [ V_9 ] ) {
F_8 ( V_6 -> V_14 [ V_9 ] ) ;
F_7 ( V_6 -> V_14 [ V_9 ] ) ;
}
}
for ( V_7 = V_10 - 1 ; V_7 >= 0 ; V_7 -- )
if ( V_6 -> V_11 [ V_7 ] )
F_9 ( V_6 -> V_11 [ V_7 ] ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 ;
struct V_18 * V_19 = F_12 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 ;
struct V_20 * V_21 ;
const char * V_22 ;
int V_23 , V_24 , V_9 , V_7 = 0 ;
if ( F_13 () )
return - V_25 ;
if ( ! V_19 )
V_19 = & V_26 ;
V_23 = F_14 ( & V_2 -> V_2 , F_15 ( 32 ) ) ;
if ( V_23 )
return V_23 ;
V_24 = F_16 ( V_2 , 0 ) ;
if ( V_24 < 0 ) {
F_17 ( & V_2 -> V_2 , L_1 ) ;
return V_24 ;
}
V_4 = F_18 ( & V_27 , & V_2 -> V_2 ,
F_19 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 )
return - V_28 ;
F_20 ( V_2 , V_4 ) ;
V_2 -> V_2 . V_29 = V_19 ;
V_6 = F_3 ( V_4 ) ;
V_21 = F_21 ( V_4 ) ;
if ( V_19 == & V_26 && V_2 -> V_2 . V_30 ) {
if ( F_22 ( V_2 -> V_2 . V_30 , L_2 ) )
V_21 -> V_31 |= V_32 ;
if ( F_22 ( V_2 -> V_2 . V_30 , L_3 ) )
V_21 -> V_31 |= V_33 ;
if ( F_22 ( V_2 -> V_2 . V_30 , L_4 ) )
V_21 -> V_31 |= V_32 | V_33 ;
if ( F_22 ( V_2 -> V_2 . V_30 , L_5 ) )
V_21 -> V_31 |= V_34 ;
F_23 ( V_2 -> V_2 . V_30 , L_6 ,
& V_21 -> V_35 ) ;
V_6 -> V_13 = F_24 ( V_2 -> V_2 . V_30 ,
L_7 , L_8 ) ;
V_6 -> V_13 = V_6 -> V_13 > 0 ? V_6 -> V_13 : 1 ;
V_6 -> V_14 = F_25 ( & V_2 -> V_2 , V_6 -> V_13 ,
sizeof( struct V_36 * ) , V_37 ) ;
if ( ! V_6 -> V_14 )
return - V_28 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_13 ; V_9 ++ ) {
V_23 = F_26 (
V_2 -> V_2 . V_30 ,
L_9 , V_9 ,
& V_22 ) ;
if ( V_23 < 0 ) {
if ( V_6 -> V_13 > 1 ) {
F_17 ( & V_2 -> V_2 , L_10 ) ;
goto V_38;
} else
V_22 = L_11 ;
}
V_6 -> V_14 [ V_9 ] = F_27 ( & V_2 -> V_2 ,
V_22 ) ;
if ( F_28 ( V_6 -> V_14 [ V_9 ] ) ) {
V_23 = F_29 ( V_6 -> V_14 [ V_9 ] ) ;
if ( ( V_6 -> V_13 > 1 ) ||
( V_23 == - V_39 ) )
goto V_38;
V_6 -> V_14 [ V_9 ] = NULL ;
}
}
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
V_6 -> V_11 [ V_7 ] = F_30 ( V_2 -> V_2 . V_30 , V_7 ) ;
if ( F_28 ( V_6 -> V_11 [ V_7 ] ) ) {
V_23 = F_29 ( V_6 -> V_11 [ V_7 ] ) ;
if ( V_23 == - V_39 )
goto V_40;
V_6 -> V_11 [ V_7 ] = NULL ;
break;
}
}
}
V_6 -> V_41 = F_31 ( & V_2 -> V_2 , NULL ) ;
if ( F_28 ( V_6 -> V_41 ) ) {
V_23 = F_29 ( V_6 -> V_41 ) ;
if ( V_23 == - V_39 )
goto V_40;
V_6 -> V_41 = NULL ;
} else {
V_23 = F_32 ( V_6 -> V_41 ) ;
if ( V_23 )
goto V_40;
}
if ( V_19 -> V_42 )
V_21 -> V_31 |= V_33 ;
if ( V_19 -> V_43 )
V_21 -> V_31 |= V_32 ;
if ( V_19 -> V_44 )
V_21 -> V_31 |= V_34 ;
if ( V_19 -> V_35 )
V_21 -> V_35 = V_19 -> V_35 ;
#ifndef F_33
if ( V_21 -> V_31 & V_32 ) {
F_17 ( & V_2 -> V_2 ,
L_12 ) ;
V_23 = - V_45 ;
goto V_46;
}
#endif
#ifndef F_34
if ( V_21 -> V_31 & V_33 ) {
F_17 ( & V_2 -> V_2 ,
L_13 ) ;
V_23 = - V_45 ;
goto V_46;
}
#endif
if ( V_19 -> V_47 ) {
V_23 = V_19 -> V_47 ( V_2 ) ;
if ( V_23 < 0 )
goto V_46;
}
V_17 = F_35 ( V_2 , V_48 , 0 ) ;
V_4 -> V_49 = F_36 ( & V_2 -> V_2 , V_17 ) ;
if ( F_28 ( V_4 -> V_49 ) ) {
V_23 = F_29 ( V_4 -> V_49 ) ;
goto V_50;
}
V_4 -> V_51 = V_17 -> V_52 ;
V_4 -> V_53 = F_37 ( V_17 ) ;
V_23 = F_38 ( V_4 , V_24 , V_54 ) ;
if ( V_23 )
goto V_50;
F_39 ( V_4 -> V_55 . V_56 ) ;
F_20 ( V_2 , V_4 ) ;
return V_23 ;
V_50:
if ( V_19 -> V_57 )
V_19 -> V_57 ( V_2 ) ;
V_46:
if ( V_6 -> V_41 )
F_40 ( V_6 -> V_41 ) ;
V_40:
while ( -- V_7 >= 0 )
F_41 ( V_6 -> V_11 [ V_7 ] ) ;
V_38:
if ( V_19 == & V_26 )
V_2 -> V_2 . V_29 = NULL ;
F_42 ( V_4 ) ;
return V_23 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_44 ( V_4 ) ;
if ( V_19 -> V_57 )
V_19 -> V_57 ( V_2 ) ;
if ( V_6 -> V_41 )
F_40 ( V_6 -> V_41 ) ;
for ( V_7 = 0 ; V_7 < V_10 && V_6 -> V_11 [ V_7 ] ; V_7 ++ )
F_41 ( V_6 -> V_11 [ V_7 ] ) ;
F_42 ( V_4 ) ;
if ( V_19 == & V_26 )
V_2 -> V_2 . V_29 = NULL ;
return 0 ;
}
static int F_45 ( struct V_58 * V_2 )
{
struct V_3 * V_4 = F_46 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_29 ;
struct V_1 * V_59 =
F_47 ( V_2 , struct V_1 , V_2 ) ;
bool V_60 = F_48 ( V_2 ) ;
int V_8 ;
V_8 = F_49 ( V_4 , V_60 ) ;
if ( V_8 )
return V_8 ;
if ( V_19 -> V_61 )
V_19 -> V_61 ( V_59 ) ;
return V_8 ;
}
static int F_50 ( struct V_58 * V_2 )
{
struct V_3 * V_4 = F_46 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_1 * V_59 =
F_47 ( V_2 , struct V_1 , V_2 ) ;
if ( V_19 -> V_47 ) {
int V_23 = V_19 -> V_47 ( V_59 ) ;
if ( V_23 < 0 )
return V_23 ;
}
F_51 ( V_4 , false ) ;
return 0 ;
}
static int T_1 F_52 ( void )
{
if ( F_13 () )
return - V_25 ;
F_53 ( L_14 V_62 L_15 , V_63 ) ;
F_54 ( & V_27 , & V_64 ) ;
return F_55 ( & V_65 ) ;
}
static void T_2 F_56 ( void )
{
F_57 ( & V_65 ) ;
}
