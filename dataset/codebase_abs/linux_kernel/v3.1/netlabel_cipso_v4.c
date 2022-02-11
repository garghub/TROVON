static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
T_1 V_8 = 0 ;
V_4 -> V_9 = F_2 ( V_2 -> V_10 [ V_11 ] ) ;
if ( F_3 ( V_2 -> V_10 [ V_12 ] ,
V_13 ,
V_14 ) != 0 )
return - V_15 ;
F_4 (nla, info->attrs[NLBL_CIPSOV4_A_TAGLST], nla_rem)
if ( F_5 ( V_6 ) == V_16 ) {
if ( V_8 >= V_17 )
return - V_15 ;
V_4 -> V_18 [ V_8 ++ ] = F_6 ( V_6 ) ;
}
while ( V_8 < V_17 )
V_4 -> V_18 [ V_8 ++ ] = V_19 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_22 = - V_15 ;
struct V_3 * V_4 = NULL ;
struct V_5 * V_23 ;
struct V_5 * V_24 ;
int V_25 ;
int V_26 ;
T_1 V_8 ;
if ( ! V_2 -> V_10 [ V_12 ] ||
! V_2 -> V_10 [ V_27 ] )
return - V_15 ;
if ( F_3 ( V_2 -> V_10 [ V_27 ] ,
V_13 ,
V_14 ) != 0 )
return - V_15 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_28 ) ;
if ( V_4 == NULL )
return - V_29 ;
V_4 -> V_30 . V_31 = F_9 ( sizeof( * V_4 -> V_30 . V_31 ) , V_28 ) ;
if ( V_4 -> V_30 . V_31 == NULL ) {
V_22 = - V_29 ;
goto V_32;
}
V_4 -> type = V_33 ;
V_22 = F_1 ( V_2 , V_4 ) ;
if ( V_22 != 0 )
goto V_32;
V_22 = - V_15 ;
F_4 (nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSLVLLST],
nla_a_rem)
if ( F_5 ( V_23 ) == V_34 ) {
if ( F_3 ( V_23 ,
V_13 ,
V_14 ) != 0 )
goto V_32;
F_4 (nla_b, nla_a, nla_b_rem)
switch ( F_5 ( V_24 ) ) {
case V_35 :
if ( F_2 ( V_24 ) >
V_36 )
goto V_32;
if ( F_2 ( V_24 ) >=
V_4 -> V_30 . V_31 -> V_37 . V_38 )
V_4 -> V_30 . V_31 -> V_37 . V_38 =
F_2 ( V_24 ) + 1 ;
break;
case V_39 :
if ( F_2 ( V_24 ) >
V_40 )
goto V_32;
if ( F_2 ( V_24 ) >=
V_4 -> V_30 . V_31 -> V_37 . V_41 )
V_4 -> V_30 . V_31 -> V_37 . V_41 =
F_2 ( V_24 ) + 1 ;
break;
}
}
V_4 -> V_30 . V_31 -> V_37 . V_42 = F_10 ( V_4 -> V_30 . V_31 -> V_37 . V_38 ,
sizeof( T_1 ) ,
V_28 ) ;
if ( V_4 -> V_30 . V_31 -> V_37 . V_42 == NULL ) {
V_22 = - V_29 ;
goto V_32;
}
V_4 -> V_30 . V_31 -> V_37 . V_43 = F_10 ( V_4 -> V_30 . V_31 -> V_37 . V_41 ,
sizeof( T_1 ) ,
V_28 ) ;
if ( V_4 -> V_30 . V_31 -> V_37 . V_43 == NULL ) {
V_22 = - V_29 ;
goto V_32;
}
for ( V_8 = 0 ; V_8 < V_4 -> V_30 . V_31 -> V_37 . V_38 ; V_8 ++ )
V_4 -> V_30 . V_31 -> V_37 . V_42 [ V_8 ] = V_44 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_30 . V_31 -> V_37 . V_41 ; V_8 ++ )
V_4 -> V_30 . V_31 -> V_37 . V_43 [ V_8 ] = V_44 ;
F_4 (nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSLVLLST],
nla_a_rem)
if ( F_5 ( V_23 ) == V_34 ) {
struct V_5 * V_45 ;
struct V_5 * V_46 ;
V_45 = F_11 ( V_23 ,
V_35 ) ;
V_46 = F_11 ( V_23 ,
V_39 ) ;
if ( V_45 == NULL || V_46 == NULL )
goto V_32;
V_4 -> V_30 . V_31 -> V_37 . V_42 [ F_2 ( V_45 ) ] =
F_2 ( V_46 ) ;
V_4 -> V_30 . V_31 -> V_37 . V_43 [ F_2 ( V_46 ) ] =
F_2 ( V_45 ) ;
}
if ( V_2 -> V_10 [ V_47 ] ) {
if ( F_3 ( V_2 -> V_10 [ V_47 ] ,
V_13 ,
V_14 ) != 0 )
goto V_32;
F_4 (nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSCATLST],
nla_a_rem)
if ( F_5 ( V_23 ) == V_48 ) {
if ( F_3 ( V_23 ,
V_13 ,
V_14 ) != 0 )
goto V_32;
F_4 (nla_b, nla_a, nla_b_rem)
switch ( F_5 ( V_24 ) ) {
case V_49 :
if ( F_2 ( V_24 ) >
V_50 )
goto V_32;
if ( F_2 ( V_24 ) >=
V_4 -> V_30 . V_31 -> V_51 . V_38 )
V_4 -> V_30 . V_31 -> V_51 . V_38 =
F_2 ( V_24 ) + 1 ;
break;
case V_52 :
if ( F_2 ( V_24 ) >
V_53 )
goto V_32;
if ( F_2 ( V_24 ) >=
V_4 -> V_30 . V_31 -> V_51 . V_41 )
V_4 -> V_30 . V_31 -> V_51 . V_41 =
F_2 ( V_24 ) + 1 ;
break;
}
}
V_4 -> V_30 . V_31 -> V_51 . V_42 = F_10 (
V_4 -> V_30 . V_31 -> V_51 . V_38 ,
sizeof( T_1 ) ,
V_28 ) ;
if ( V_4 -> V_30 . V_31 -> V_51 . V_42 == NULL ) {
V_22 = - V_29 ;
goto V_32;
}
V_4 -> V_30 . V_31 -> V_51 . V_43 = F_10 (
V_4 -> V_30 . V_31 -> V_51 . V_41 ,
sizeof( T_1 ) ,
V_28 ) ;
if ( V_4 -> V_30 . V_31 -> V_51 . V_43 == NULL ) {
V_22 = - V_29 ;
goto V_32;
}
for ( V_8 = 0 ; V_8 < V_4 -> V_30 . V_31 -> V_51 . V_38 ; V_8 ++ )
V_4 -> V_30 . V_31 -> V_51 . V_42 [ V_8 ] = V_54 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_30 . V_31 -> V_51 . V_41 ; V_8 ++ )
V_4 -> V_30 . V_31 -> V_51 . V_43 [ V_8 ] = V_54 ;
F_4 (nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSCATLST],
nla_a_rem)
if ( F_5 ( V_23 ) == V_48 ) {
struct V_5 * V_55 ;
struct V_5 * V_56 ;
V_55 = F_11 ( V_23 ,
V_49 ) ;
V_56 = F_11 ( V_23 ,
V_52 ) ;
if ( V_55 == NULL || V_56 == NULL )
goto V_32;
V_4 -> V_30 . V_31 -> V_51 . V_42 [
F_2 ( V_55 ) ] =
F_2 ( V_56 ) ;
V_4 -> V_30 . V_31 -> V_51 . V_43 [
F_2 ( V_56 ) ] =
F_2 ( V_55 ) ;
}
}
V_22 = F_12 ( V_4 , V_21 ) ;
if ( V_22 != 0 )
goto V_32;
return 0 ;
V_32:
if ( V_4 )
F_13 ( V_4 ) ;
return V_22 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_22 ;
struct V_3 * V_4 = NULL ;
if ( ! V_2 -> V_10 [ V_12 ] )
return - V_15 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_28 ) ;
if ( V_4 == NULL )
return - V_29 ;
V_4 -> type = V_57 ;
V_22 = F_1 ( V_2 , V_4 ) ;
if ( V_22 != 0 )
goto V_58;
V_22 = F_12 ( V_4 , V_21 ) ;
if ( V_22 != 0 )
goto V_58;
return 0 ;
V_58:
F_13 ( V_4 ) ;
return V_22 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_22 ;
struct V_3 * V_4 = NULL ;
if ( ! V_2 -> V_10 [ V_12 ] )
return - V_15 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_28 ) ;
if ( V_4 == NULL )
return - V_29 ;
V_4 -> type = V_59 ;
V_22 = F_1 ( V_2 , V_4 ) ;
if ( V_22 != 0 )
goto V_60;
V_22 = F_12 ( V_4 , V_21 ) ;
if ( V_22 != 0 )
goto V_60;
return 0 ;
V_60:
F_13 ( V_4 ) ;
return V_22 ;
}
static int F_16 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
int V_22 = - V_15 ;
struct V_20 V_21 ;
if ( ! V_2 -> V_10 [ V_11 ] ||
! V_2 -> V_10 [ V_63 ] )
return - V_15 ;
F_17 ( V_62 , & V_21 ) ;
switch ( F_2 ( V_2 -> V_10 [ V_63 ] ) ) {
case V_33 :
V_22 = F_7 ( V_2 , & V_21 ) ;
break;
case V_57 :
V_22 = F_14 ( V_2 , & V_21 ) ;
break;
case V_59 :
V_22 = F_15 ( V_2 , & V_21 ) ;
break;
}
if ( V_22 == 0 )
F_18 ( & V_64 ) ;
return V_22 ;
}
static int F_19 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
int V_22 ;
struct V_61 * V_65 = NULL ;
T_1 V_66 = 1 ;
void * V_67 ;
T_1 V_9 ;
struct V_5 * V_23 ;
struct V_5 * V_24 ;
struct V_3 * V_4 ;
T_1 V_8 ;
if ( ! V_2 -> V_10 [ V_11 ] ) {
V_22 = - V_15 ;
goto V_68;
}
V_69:
V_65 = F_20 ( V_70 * V_66 , V_28 ) ;
if ( V_65 == NULL ) {
V_22 = - V_29 ;
goto V_68;
}
V_67 = F_21 ( V_65 , V_2 , & V_71 ,
0 , V_72 ) ;
if ( V_67 == NULL ) {
V_22 = - V_29 ;
goto V_68;
}
V_9 = F_2 ( V_2 -> V_10 [ V_11 ] ) ;
F_22 () ;
V_4 = F_23 ( V_9 ) ;
if ( V_4 == NULL ) {
V_22 = - V_15 ;
goto V_73;
}
V_22 = F_24 ( V_65 , V_63 , V_4 -> type ) ;
if ( V_22 != 0 )
goto V_73;
V_23 = F_25 ( V_65 , V_12 ) ;
if ( V_23 == NULL ) {
V_22 = - V_29 ;
goto V_73;
}
for ( V_8 = 0 ;
V_8 < V_17 &&
V_4 -> V_18 [ V_8 ] != V_19 ;
V_8 ++ ) {
V_22 = F_26 ( V_65 ,
V_16 ,
V_4 -> V_18 [ V_8 ] ) ;
if ( V_22 != 0 )
goto V_73;
}
F_27 ( V_65 , V_23 ) ;
switch ( V_4 -> type ) {
case V_33 :
V_23 = F_25 ( V_65 , V_27 ) ;
if ( V_23 == NULL ) {
V_22 = - V_29 ;
goto V_73;
}
for ( V_8 = 0 ;
V_8 < V_4 -> V_30 . V_31 -> V_37 . V_38 ;
V_8 ++ ) {
if ( V_4 -> V_30 . V_31 -> V_37 . V_42 [ V_8 ] ==
V_44 )
continue;
V_24 = F_25 ( V_65 , V_34 ) ;
if ( V_24 == NULL ) {
V_22 = - V_29 ;
goto V_74;
}
V_22 = F_24 ( V_65 ,
V_35 ,
V_8 ) ;
if ( V_22 != 0 )
goto V_74;
V_22 = F_24 ( V_65 ,
V_39 ,
V_4 -> V_30 . V_31 -> V_37 . V_42 [ V_8 ] ) ;
if ( V_22 != 0 )
goto V_74;
F_27 ( V_65 , V_24 ) ;
}
F_27 ( V_65 , V_23 ) ;
V_23 = F_25 ( V_65 , V_47 ) ;
if ( V_23 == NULL ) {
V_22 = - V_29 ;
goto V_74;
}
for ( V_8 = 0 ;
V_8 < V_4 -> V_30 . V_31 -> V_51 . V_38 ;
V_8 ++ ) {
if ( V_4 -> V_30 . V_31 -> V_51 . V_42 [ V_8 ] ==
V_54 )
continue;
V_24 = F_25 ( V_65 , V_48 ) ;
if ( V_24 == NULL ) {
V_22 = - V_29 ;
goto V_74;
}
V_22 = F_24 ( V_65 ,
V_49 ,
V_8 ) ;
if ( V_22 != 0 )
goto V_74;
V_22 = F_24 ( V_65 ,
V_52 ,
V_4 -> V_30 . V_31 -> V_51 . V_42 [ V_8 ] ) ;
if ( V_22 != 0 )
goto V_74;
F_27 ( V_65 , V_24 ) ;
}
F_27 ( V_65 , V_23 ) ;
break;
}
F_28 () ;
F_29 ( V_65 , V_67 ) ;
return F_30 ( V_65 , V_2 ) ;
V_74:
if ( V_66 < 4 ) {
F_28 () ;
F_31 ( V_65 ) ;
V_66 *= 2 ;
goto V_69;
}
V_73:
F_28 () ;
V_68:
F_31 ( V_65 ) ;
return V_22 ;
}
static int F_32 ( struct V_3 * V_4 , void * V_75 )
{
int V_22 = - V_29 ;
struct V_76 * V_77 = V_75 ;
void * V_67 ;
V_67 = F_33 ( V_77 -> V_62 , F_34 ( V_77 -> V_78 -> V_62 ) . V_79 ,
V_77 -> V_80 , & V_71 ,
V_81 , V_82 ) ;
if ( V_67 == NULL )
goto V_83;
V_22 = F_24 ( V_77 -> V_62 , V_11 , V_4 -> V_9 ) ;
if ( V_22 != 0 )
goto V_83;
V_22 = F_24 ( V_77 -> V_62 ,
V_63 ,
V_4 -> type ) ;
if ( V_22 != 0 )
goto V_83;
return F_29 ( V_77 -> V_62 , V_67 ) ;
V_83:
F_35 ( V_77 -> V_62 , V_67 ) ;
return V_22 ;
}
static int F_36 ( struct V_61 * V_62 ,
struct V_84 * V_85 )
{
struct V_76 V_77 ;
T_1 V_86 = V_85 -> args [ 0 ] ;
V_77 . V_78 = V_85 ;
V_77 . V_62 = V_62 ;
V_77 . V_80 = V_85 -> V_87 -> V_88 ;
F_37 ( & V_86 , F_32 , & V_77 ) ;
V_85 -> args [ 0 ] = V_86 ;
return V_62 -> V_89 ;
}
static int F_38 ( struct V_90 * V_91 , void * V_75 )
{
struct V_92 * V_77 = V_75 ;
if ( V_91 -> type == V_93 &&
V_91 -> V_94 . V_95 -> V_9 == V_77 -> V_9 )
return F_39 ( V_91 , V_77 -> V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
int V_22 = - V_15 ;
struct V_92 V_77 ;
struct V_20 V_21 ;
T_1 V_96 = 0 ;
T_1 V_97 = 0 ;
if ( ! V_2 -> V_10 [ V_11 ] )
return - V_15 ;
F_17 ( V_62 , & V_21 ) ;
V_77 . V_9 = F_2 ( V_2 -> V_10 [ V_11 ] ) ;
V_77 . V_21 = & V_21 ;
V_22 = F_41 ( & V_96 , & V_97 ,
F_38 , & V_77 ) ;
if ( V_22 == 0 || V_22 == - V_98 ) {
V_22 = F_42 ( V_77 . V_9 , & V_21 ) ;
if ( V_22 == 0 )
F_43 ( & V_64 ) ;
}
return V_22 ;
}
int T_2 F_44 ( void )
{
return F_45 ( & V_71 ,
V_99 , F_46 ( V_99 ) ) ;
}
