static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
int V_4 = 0 ;
F_2 () ;
if ( V_5 < 2 ) {
V_6 = true ;
V_5 = 1 ;
}
V_7 [ 0 ] = F_3 ( V_5 * V_8 , sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 [ 0 ] ) {
V_4 = - V_10 ;
goto V_11;
}
for ( V_3 = 1 ; V_3 < V_8 ; ++ V_3 )
V_7 [ V_3 ] = V_7 [ 0 ] + V_3 * V_5 ;
V_12 = F_3 ( V_5 , sizeof( * V_12 ) , V_9 ) ;
if ( ! V_12 ) {
V_4 = - V_10 ;
goto V_11;
}
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_12 [ V_3 ] = F_4 ( L_1 ) ;
if ( F_5 ( V_12 [ V_3 ] ) ) {
V_4 = F_6 ( V_12 [ V_3 ] ) ;
-- V_3 ;
goto V_13;
}
V_2 = F_7 ( V_12 [ V_3 ] ) ;
if ( V_6 )
V_4 = F_8 ( V_2 -> V_14 ) ;
else
V_4 = F_9 ( V_2 -> V_14 , V_15 [ V_3 ] ) ;
if ( V_4 )
goto V_13;
V_2 -> V_14 -> V_16 = V_17 ;
V_2 -> V_14 -> V_18 = V_19 ;
V_2 -> V_14 -> V_20 = V_21 ;
V_2 -> V_14 -> V_22 = V_23 ;
V_2 -> V_24 = true ;
}
V_25 = V_5 ;
return 0 ;
V_13:
while ( V_3 >= 0 )
F_10 ( V_12 [ V_3 -- ] ) ;
F_11 ( V_12 ) ;
V_11:
F_11 ( V_7 [ 0 ] ) ;
return V_4 ;
}
static void T_2 F_12 ( void )
{
int V_3 ;
F_2 () ;
if ( V_26 )
F_13 ( & V_27 ) ;
V_26 = false ;
F_11 ( V_7 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
F_10 ( V_12 [ V_3 ] ) ;
F_11 ( V_12 ) ;
}
static void * V_21 ( struct V_28 * V_14 )
{
if ( ! F_14 ( V_29 ) )
return F_15 ( - V_30 ) ;
return 0 ;
}
static void V_23 ( struct V_28 * V_14 )
{
F_16 ( V_29 ) ;
}
static int V_17 ( struct V_31 * V_32 )
{
int V_4 = 0 ;
if ( -- V_25 )
return 0 ;
if ( V_26 )
return - V_33 ;
V_26 = true ;
V_4 = F_17 ( & V_27 ) ;
if ( F_18 ( V_4 < 0 ) )
V_26 = false ;
return V_4 ;
}
static void V_19 ( struct V_31 * V_32 )
{
V_25 ++ ;
if ( V_26 )
F_13 ( & V_27 ) ;
V_26 = false ;
}
static int F_19 ( struct V_34 * V_35 )
{
#if V_36 V_37 || V_36 V_38
struct V_39 * V_40 ;
#endif
int V_4 , V_3 ;
F_2 () ;
if ( V_25 )
return - V_30 ;
#if V_36 V_37
if ( F_20 ( V_35 -> V_41 ) ) {
struct V_42 * V_43 ;
V_44 = F_4 ( L_2 ) ;
if ( F_5 ( V_44 ) )
return F_6 ( V_44 ) ;
V_43 = F_21 ( V_44 , struct V_42 , V_45 ) ;
V_40 = V_43 -> V_40 ;
} else {
struct V_46 * V_47 ;
V_48 = F_4 ( L_3 ) ;
if ( F_5 ( V_48 ) )
return F_6 ( V_48 ) ;
V_47 = F_21 ( V_48 , struct V_46 ,
V_45 ) ;
V_40 = V_47 -> V_40 ;
}
#endif
#ifdef V_38
{
struct V_49 * V_50 ;
V_51 = F_4 ( L_4 ) ;
if ( F_5 ( V_51 ) ) {
V_4 = F_6 ( V_51 ) ;
goto error;
}
V_50 = F_21 ( V_51 , struct V_49 ,
V_45 ) ;
#ifndef V_37
V_40 = V_50 -> V_40 ;
#endif
}
#endif
#if V_36 V_37 || V_36 V_38
F_22 ( V_40 , V_52 ) ;
if ( ! F_23 ( V_40 , V_53 ) )
F_24 ( L_5 , V_53 ) ;
if ( ! F_25 ( V_40 , V_54 ) )
F_24 ( L_6 , V_54 ) ;
#endif
#if V_36 V_38 && V_36 V_37
F_26 ( V_40 , V_35 -> V_41 ) ;
V_4 = F_27 ( V_40 ) ;
if ( V_4 )
goto V_55;
if ( F_20 ( V_35 -> V_41 ) ) {
struct V_42 * V_43 ;
V_43 = F_21 ( V_44 , struct V_42 , V_45 ) ;
V_43 -> V_56 = true ;
} else {
struct V_46 * V_47 ;
V_47 = F_21 ( V_48 , struct V_46 ,
V_45 ) ;
V_47 -> V_56 = true ;
}
F_28 ( V_51 , V_40 ) ;
#endif
V_4 = F_29 ( V_35 , V_57 ) ;
if ( F_18 ( V_4 < 0 ) )
goto V_55;
V_58 . V_59 = V_57 [ V_60 ] . V_61 ;
for ( V_3 = 0 ; V_3 < F_30 ( V_62 ) ; ++ V_3 ) {
struct V_63 * V_64 = V_62 + V_3 ;
int V_65 = V_66 + V_3 ;
V_64 -> V_64 . V_67 = V_57 [ V_65 ] . V_68 ;
V_64 -> V_64 . V_69 = V_57 [ V_65 ] . V_61 ;
V_64 -> V_64 . V_70 = 1 + V_3 ;
V_64 -> V_64 . V_71 = V_72 ;
V_64 -> V_73 = V_3 ;
V_4 = F_31 ( V_35 , & V_64 -> V_64 , V_74 ) ;
if ( F_18 ( V_4 < 0 ) )
goto V_75;
}
F_32 ( V_35 , & V_76 ) ;
return 0 ;
V_75:
V_55:
#ifdef V_38
F_10 ( V_51 ) ;
error:
#endif
#if V_36 V_37
if ( F_20 ( V_35 -> V_41 ) )
F_10 ( V_44 ) ;
else
F_10 ( V_48 ) ;
#endif
return V_4 ;
}
static int F_33 ( struct V_34 * V_35 )
{
int V_3 ;
F_2 () ;
#ifdef V_38
F_34 ( V_77 ) ;
F_10 ( V_51 ) ;
#endif
#if V_36 V_37
if ( F_20 ( V_35 -> V_41 ) ) {
F_34 ( V_78 ) ;
F_10 ( V_44 ) ;
} else {
F_34 ( V_79 ) ;
F_10 ( V_48 ) ;
}
#endif
for ( V_3 = 0 ; V_3 < V_8 * V_5 ; ++ V_3 )
F_34 ( * ( V_7 [ 0 ] + V_3 ) ) ;
return 0 ;
}
static int V_74 ( struct V_80 * V_64 )
{
struct V_63 * V_81 =
F_21 ( V_64 , struct V_63 , V_64 ) ;
int V_3 ;
int V_4 ;
if ( V_25 )
return - V_30 ;
if ( F_35 ( V_64 -> V_35 -> V_41 ) ) {
V_64 -> V_82 = V_83 ;
V_64 -> V_71 |= V_84 ;
}
if ( V_81 -> V_85 ) {
V_4 = V_81 -> V_85 ( V_64 ) ;
if ( F_18 ( V_4 < 0 ) )
return V_4 ;
}
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_7 [ V_81 -> V_73 ] [ V_3 ] = F_36 ( V_12 [ V_3 ] ) ;
if ( F_5 ( V_7 [ V_81 -> V_73 ] [ V_3 ] ) ) {
V_4 = F_6 ( V_7 [ V_81 -> V_73 ] [ V_3 ] ) ;
goto error;
}
V_4 = F_37 ( V_64 , V_7 [ V_81 -> V_73 ] [ V_3 ] ) ;
if ( V_4 < 0 ) {
F_34 ( V_7 [ V_81 -> V_73 ] [ V_3 ] ) ;
goto error;
}
}
if ( V_64 -> V_86 < F_30 ( V_64 -> V_87 ) )
V_64 -> V_87 [ V_64 -> V_86 ] = NULL ;
return 0 ;
error:
while ( -- V_3 >= 0 ) {
if ( ! F_5 ( V_7 [ V_81 -> V_73 ] [ V_3 ] ) )
F_38 ( V_64 , V_7 [ V_81 -> V_73 ] [ V_3 ] ) ;
F_34 ( V_7 [ V_81 -> V_73 ] [ V_3 ] ) ;
}
return V_4 ;
}
static int F_39 ( struct V_80 * V_64 )
{
int V_88 = 0 ;
if ( F_20 ( V_64 -> V_35 -> V_41 ) ) {
V_78 = F_36 ( V_44 ) ;
if ( F_5 ( V_78 ) )
return F_6 ( V_78 ) ;
V_88 = F_37 ( V_64 , V_78 ) ;
if ( V_88 < 0 )
F_34 ( V_78 ) ;
} else {
V_79 = F_36 ( V_48 ) ;
if ( F_5 ( V_79 ) )
return F_6 ( V_79 ) ;
V_88 = F_37 ( V_64 , V_79 ) ;
if ( V_88 < 0 )
F_34 ( V_79 ) ;
}
return V_88 ;
}
static int F_40 ( struct V_80 * V_64 )
{
int V_88 = 0 ;
V_77 = F_36 ( V_51 ) ;
if ( F_5 ( V_77 ) )
return F_6 ( V_77 ) ;
V_88 = F_37 ( V_64 , V_77 ) ;
if ( V_88 < 0 )
F_34 ( V_77 ) ;
return V_88 ;
}
