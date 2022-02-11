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
return NULL ;
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
if ( F_18 ( V_4 < 0 ) ) {
++ V_25 ;
V_26 = false ;
}
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
return - V_41 ;
#if V_36 V_37
if ( F_20 ( V_35 -> V_42 ) ) {
struct V_43 * V_44 ;
V_45 = F_4 ( L_2 ) ;
if ( F_5 ( V_45 ) )
return F_6 ( V_45 ) ;
V_44 = F_21 ( V_45 , struct V_43 , V_46 ) ;
V_40 = V_44 -> V_40 ;
} else {
struct V_47 * V_48 ;
V_49 = F_4 ( L_3 ) ;
if ( F_5 ( V_49 ) )
return F_6 ( V_49 ) ;
V_48 = F_21 ( V_49 , struct V_47 ,
V_46 ) ;
V_40 = V_48 -> V_40 ;
}
#endif
#ifdef V_38
{
V_50 = F_4 ( L_4 ) ;
if ( F_5 ( V_50 ) ) {
V_4 = F_6 ( V_50 ) ;
goto error;
}
#ifndef V_37
V_40 = F_21 ( V_50 , struct V_51 ,
V_46 ) -> V_40 ;
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
F_26 ( V_40 , V_35 -> V_42 ) ;
V_4 = F_27 ( V_40 ) ;
if ( V_4 )
goto V_55;
if ( F_20 ( V_35 -> V_42 ) ) {
struct V_43 * V_44 ;
V_44 = F_21 ( V_45 , struct V_43 , V_46 ) ;
V_44 -> V_56 = true ;
} else {
struct V_47 * V_48 ;
V_48 = F_21 ( V_49 , struct V_47 ,
V_46 ) ;
V_48 -> V_56 = true ;
}
F_28 ( V_50 , V_40 ) ;
#endif
V_4 = F_29 ( V_35 , V_57 ) ;
if ( F_18 ( V_4 < 0 ) )
goto V_55;
V_58 . V_59 = V_57 [ V_60 ] . V_61 ;
if ( F_30 ( V_35 -> V_42 ) && ! V_62 [ 0 ] ) {
struct V_63 * V_64 ;
V_64 = F_31 ( V_35 -> V_42 ) ;
if ( ! V_64 )
goto V_55;
F_32 ( V_35 -> V_42 , V_64 ) ;
V_62 [ 0 ] = V_64 ;
V_62 [ 1 ] = NULL ;
}
for ( V_3 = 0 ; V_3 < F_33 ( V_65 ) ; ++ V_3 ) {
struct V_66 * V_67 = V_65 + V_3 ;
int V_68 = V_69 + V_3 ;
V_67 -> V_67 . V_70 = V_57 [ V_68 ] . V_71 ;
V_67 -> V_67 . V_72 = V_57 [ V_68 ] . V_61 ;
V_67 -> V_67 . V_73 = 1 + V_3 ;
V_67 -> V_67 . V_74 = V_75 ;
V_67 -> V_76 = V_3 ;
V_4 = F_34 ( V_35 , & V_67 -> V_67 , V_77 ) ;
if ( F_18 ( V_4 < 0 ) )
goto V_78;
}
F_35 ( V_35 , & V_79 ) ;
return 0 ;
V_78:
F_11 ( V_62 [ 0 ] ) ;
V_62 [ 0 ] = NULL ;
V_55:
#ifdef V_38
F_10 ( V_50 ) ;
error:
#endif
#if V_36 V_37
if ( F_20 ( V_35 -> V_42 ) )
F_10 ( V_45 ) ;
else
F_10 ( V_49 ) ;
#endif
return V_4 ;
}
static int F_36 ( struct V_34 * V_35 )
{
int V_3 ;
F_2 () ;
#ifdef V_38
F_37 ( V_80 ) ;
F_10 ( V_50 ) ;
#endif
#if V_36 V_37
if ( F_20 ( V_35 -> V_42 ) ) {
F_37 ( V_81 ) ;
F_10 ( V_45 ) ;
} else {
F_37 ( V_82 ) ;
F_10 ( V_49 ) ;
}
#endif
for ( V_3 = 0 ; V_3 < V_8 * V_5 ; ++ V_3 )
F_37 ( * ( V_7 [ 0 ] + V_3 ) ) ;
F_11 ( V_62 [ 0 ] ) ;
V_62 [ 0 ] = NULL ;
return 0 ;
}
static int V_77 ( struct V_83 * V_67 )
{
struct V_66 * V_84 =
F_21 ( V_67 , struct V_66 , V_67 ) ;
int V_3 ;
int V_4 ;
if ( V_25 )
return - V_41 ;
if ( F_30 ( V_67 -> V_35 -> V_42 ) ) {
V_67 -> V_85 = V_62 ;
V_67 -> V_74 |= V_86 ;
}
if ( V_84 -> V_87 ) {
V_4 = V_84 -> V_87 ( V_67 ) ;
if ( F_18 ( V_4 < 0 ) )
return V_4 ;
}
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_7 [ V_84 -> V_76 ] [ V_3 ] = F_38 ( V_12 [ V_3 ] ) ;
if ( F_5 ( V_7 [ V_84 -> V_76 ] [ V_3 ] ) ) {
V_4 = F_6 ( V_7 [ V_84 -> V_76 ] [ V_3 ] ) ;
goto error;
}
V_4 = F_39 ( V_67 , V_7 [ V_84 -> V_76 ] [ V_3 ] ) ;
if ( V_4 < 0 ) {
F_37 ( V_7 [ V_84 -> V_76 ] [ V_3 ] ) ;
goto error;
}
}
if ( V_67 -> V_88 < F_33 ( V_67 -> V_89 ) )
V_67 -> V_89 [ V_67 -> V_88 ] = NULL ;
return 0 ;
error:
while ( -- V_3 >= 0 ) {
if ( ! F_5 ( V_7 [ V_84 -> V_76 ] [ V_3 ] ) )
F_40 ( V_67 , V_7 [ V_84 -> V_76 ] [ V_3 ] ) ;
F_37 ( V_7 [ V_84 -> V_76 ] [ V_3 ] ) ;
}
return V_4 ;
}
static int F_41 ( struct V_83 * V_67 )
{
int V_90 = 0 ;
if ( F_20 ( V_67 -> V_35 -> V_42 ) ) {
V_81 = F_38 ( V_45 ) ;
if ( F_5 ( V_81 ) )
return F_6 ( V_81 ) ;
V_90 = F_39 ( V_67 , V_81 ) ;
if ( V_90 < 0 )
F_37 ( V_81 ) ;
} else {
V_82 = F_38 ( V_49 ) ;
if ( F_5 ( V_82 ) )
return F_6 ( V_82 ) ;
V_90 = F_39 ( V_67 , V_82 ) ;
if ( V_90 < 0 )
F_37 ( V_82 ) ;
}
return V_90 ;
}
static int F_42 ( struct V_83 * V_67 )
{
int V_90 = 0 ;
V_80 = F_38 ( V_50 ) ;
if ( F_5 ( V_80 ) )
return F_6 ( V_80 ) ;
V_90 = F_39 ( V_67 , V_80 ) ;
if ( V_90 < 0 )
F_37 ( V_80 ) ;
return V_90 ;
}
