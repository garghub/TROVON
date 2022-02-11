static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_1 V_15 = ( T_1 ) - 1 ;
int V_16 ;
int V_17 ;
if ( ! F_2 ( V_3 , V_18 ) )
return 0 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_12 -> V_20 = 1 ;
V_12 -> V_21 = 1 ;
V_12 -> V_22 = 2 ;
V_10 . V_23 = V_24 ;
V_10 . V_25 = 0 ;
V_10 . type = V_26 ;
V_27:
F_4 ( & V_5 -> V_28 ) ;
V_17 = F_5 ( NULL , V_3 , & V_10 , V_12 , 0 , 0 ) ;
if ( V_17 < 0 )
goto V_29;
while ( 1 ) {
if ( F_6 ( V_5 ) )
goto V_29;
V_14 = V_12 -> V_30 [ 0 ] ;
V_16 = V_12 -> V_31 [ 0 ] ;
if ( V_16 >= F_7 ( V_14 ) ) {
V_17 = F_8 ( V_3 , V_12 ) ;
if ( V_17 < 0 )
goto V_29;
else if ( V_17 > 0 )
break;
if ( F_9 () ||
F_10 ( V_5 ) ) {
V_14 = V_12 -> V_30 [ 0 ] ;
if ( F_11 ( F_7 ( V_14 ) == 0 ) )
break;
F_12 ( V_14 , & V_10 , 0 ) ;
F_13 ( V_12 ) ;
V_3 -> V_32 = V_15 ;
F_14 ( & V_5 -> V_28 ) ;
F_15 ( 1 ) ;
goto V_27;
} else
continue;
}
F_12 ( V_14 , & V_10 , V_16 ) ;
if ( V_10 . type != V_26 )
goto V_33;
if ( V_10 . V_23 >= V_3 -> V_34 )
break;
if ( V_15 != ( T_1 ) - 1 && V_15 + 1 != V_10 . V_23 ) {
F_16 ( V_7 , V_15 + 1 ,
V_10 . V_23 - V_15 - 1 ) ;
F_17 ( & V_3 -> V_35 ) ;
}
V_15 = V_10 . V_23 ;
V_33:
V_12 -> V_31 [ 0 ] ++ ;
}
if ( V_15 < V_3 -> V_34 - 1 ) {
F_16 ( V_7 , V_15 + 1 ,
V_3 -> V_34 - V_15 - 1 ) ;
}
F_18 ( & V_3 -> V_36 ) ;
V_3 -> V_37 = V_38 ;
F_19 ( & V_3 -> V_36 ) ;
V_3 -> V_32 = ( T_1 ) - 1 ;
F_20 ( V_3 ) ;
V_29:
F_17 ( & V_3 -> V_35 ) ;
F_14 ( & V_5 -> V_28 ) ;
F_21 ( V_12 ) ;
return V_17 ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_39 * V_40 ;
int V_17 ;
T_1 V_23 ;
if ( ! F_2 ( V_3 , V_18 ) )
return;
F_18 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_37 != V_41 ) {
F_19 ( & V_3 -> V_36 ) ;
return;
}
V_3 -> V_37 = V_42 ;
F_19 ( & V_3 -> V_36 ) ;
V_17 = F_23 ( V_3 -> V_5 , V_3 ) ;
if ( V_17 == 1 ) {
F_18 ( & V_3 -> V_36 ) ;
V_3 -> V_37 = V_38 ;
F_19 ( & V_3 -> V_36 ) ;
return;
}
V_17 = F_24 ( V_3 , & V_23 ) ;
if ( ! V_17 && V_23 <= V_43 ) {
F_16 ( V_7 , V_23 ,
V_43 - V_23 + 1 ) ;
}
V_40 = F_25 ( F_1 , V_3 , L_1 ,
V_3 -> V_44 . V_23 ) ;
if ( F_26 ( V_40 ) ) {
F_27 ( V_3 -> V_5 , L_2 ) ;
F_28 ( V_3 -> V_5 , V_18 ,
L_3 ) ;
}
}
int F_29 ( struct V_2 * V_3 , T_1 * V_23 )
{
if ( ! F_2 ( V_3 , V_18 ) )
return F_24 ( V_3 , V_23 ) ;
V_27:
* V_23 = F_30 ( V_3 ) ;
if ( * V_23 != 0 )
return 0 ;
F_22 ( V_3 ) ;
F_31 ( V_3 -> V_35 ,
V_3 -> V_37 == V_38 ||
V_3 -> V_8 -> V_45 > 0 ) ;
if ( V_3 -> V_37 == V_38 &&
V_3 -> V_8 -> V_45 == 0 )
return - V_46 ;
else
goto V_27;
}
void F_32 ( struct V_2 * V_3 , T_1 V_23 )
{
struct V_6 * V_47 = V_3 -> V_48 ;
if ( ! F_2 ( V_3 , V_18 ) )
return;
V_27:
if ( V_3 -> V_37 == V_38 ) {
F_16 ( V_47 , V_23 , 1 ) ;
} else {
F_33 ( & V_3 -> V_5 -> V_28 ) ;
F_18 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_37 == V_38 ) {
F_19 ( & V_3 -> V_36 ) ;
F_34 ( & V_3 -> V_5 -> V_28 ) ;
goto V_27;
}
F_19 ( & V_3 -> V_36 ) ;
F_22 ( V_3 ) ;
F_16 ( V_47 , V_23 , 1 ) ;
F_34 ( & V_3 -> V_5 -> V_28 ) ;
}
}
void F_20 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_49 * V_50 = & V_3 -> V_48 -> V_51 ;
T_2 * V_52 = & V_3 -> V_48 -> V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_1 V_58 ;
if ( ! F_2 ( V_3 , V_18 ) )
return;
while ( 1 ) {
bool V_59 = true ;
F_18 ( V_52 ) ;
V_57 = F_35 ( V_50 ) ;
if ( ! V_57 ) {
F_19 ( V_52 ) ;
break;
}
V_55 = F_36 ( V_57 , struct V_54 , V_60 ) ;
F_37 ( V_55 -> V_61 ) ;
if ( V_55 -> V_25 > V_3 -> V_32 )
V_59 = false ;
else if ( V_55 -> V_25 + V_55 -> V_62 > V_3 -> V_32 )
V_58 = V_3 -> V_32 - V_55 -> V_25 + 1 ;
else
V_58 = V_55 -> V_62 ;
F_38 ( & V_55 -> V_60 , V_50 ) ;
F_19 ( V_52 ) ;
if ( V_59 )
F_16 ( V_7 , V_55 -> V_25 , V_58 ) ;
F_39 ( V_63 , V_55 ) ;
}
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
int V_64 ;
int V_65 ;
V_57 = F_41 ( & V_7 -> V_51 ) ;
if ( ! V_57 ) {
V_7 -> V_66 = V_67 ;
return;
}
V_55 = F_36 ( V_57 , struct V_54 , V_60 ) ;
V_64 = V_55 -> V_62 - 1 ;
V_65 = F_42 ( V_64 , V_68 ) / V_68 ;
if ( V_65 <= V_7 -> V_69 ) {
V_7 -> V_66 = 0 ;
return;
}
V_7 -> V_66 = ( V_65 - V_7 -> V_69 ) *
V_70 / sizeof( * V_55 ) ;
}
static bool F_43 ( struct V_6 * V_7 ,
struct V_54 * V_55 )
{
if ( V_7 -> V_71 < V_7 -> V_66 ||
V_55 -> V_62 > V_68 / 10 )
return false ;
return true ;
}
static void F_44 ( struct V_6 * V_7 )
{
}
static bool F_45 ( struct V_6 * V_7 ,
struct V_54 * V_55 )
{
return false ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_6 * V_47 = V_3 -> V_48 ;
F_47 ( & V_7 -> V_53 ) ;
V_7 -> V_72 = 1 ;
V_7 -> V_73 = 0 ;
V_7 -> V_74 = NULL ;
V_7 -> V_75 = & V_76 ;
F_48 ( & V_7 -> V_77 ) ;
F_49 ( & V_7 -> V_78 ) ;
V_7 -> V_66 = V_67 ;
F_47 ( & V_47 -> V_53 ) ;
V_47 -> V_72 = 1 ;
V_47 -> V_73 = 0 ;
V_47 -> V_74 = NULL ;
V_47 -> V_66 = 0 ;
V_47 -> V_75 = & V_79 ;
}
int F_50 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_11 * V_12 ;
struct V_82 * V_82 ;
struct V_83 * V_84 ;
T_1 V_85 ;
T_1 V_86 = 0 ;
int V_17 ;
int V_87 ;
bool V_88 = false ;
if ( V_3 -> V_44 . V_23 != V_89 &&
( V_3 -> V_44 . V_23 < V_24 ||
V_3 -> V_44 . V_23 > V_43 ) )
return 0 ;
if ( F_51 ( & V_3 -> V_90 ) == 0 )
return 0 ;
if ( ! F_2 ( V_3 , V_18 ) )
return 0 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_84 = V_81 -> V_91 ;
V_81 -> V_91 = & V_3 -> V_5 -> V_92 ;
V_85 = V_81 -> V_93 ;
V_81 -> V_93 = F_52 ( V_3 , 10 ) ;
V_17 = F_53 ( V_3 , V_81 -> V_91 ,
V_81 -> V_93 ,
V_94 ) ;
if ( V_17 )
goto V_29;
F_54 ( V_3 -> V_5 , L_4 ,
V_81 -> V_95 , V_81 -> V_93 , 1 ) ;
V_27:
V_82 = F_55 ( V_3 , V_12 ) ;
if ( F_26 ( V_82 ) && ( F_56 ( V_82 ) != - V_96 || V_88 ) ) {
V_17 = F_56 ( V_82 ) ;
goto V_97;
}
if ( F_26 ( V_82 ) ) {
F_37 ( V_88 ) ;
V_88 = true ;
V_17 = F_57 ( V_3 , V_81 , V_12 ) ;
if ( V_17 )
goto V_97;
goto V_27;
}
F_58 ( V_82 ) -> V_98 = 0 ;
V_17 = F_59 ( V_81 , V_3 , V_82 ) ;
if ( V_17 ) {
F_60 ( V_81 , V_3 , V_17 ) ;
goto V_99;
}
if ( F_61 ( V_82 ) > 0 ) {
V_17 = F_62 ( V_3 , V_81 , NULL , V_82 ) ;
if ( V_17 ) {
if ( V_17 != - V_46 )
F_60 ( V_81 , V_3 , V_17 ) ;
goto V_99;
}
}
F_18 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_37 != V_38 ) {
V_17 = - 1 ;
F_19 ( & V_3 -> V_36 ) ;
goto V_99;
}
F_19 ( & V_3 -> V_36 ) ;
F_18 ( & V_7 -> V_53 ) ;
V_87 = sizeof( struct V_54 ) * V_7 -> V_71 ;
V_87 = F_42 ( V_87 , V_70 ) ;
V_87 += V_7 -> V_69 * V_70 ;
F_19 ( & V_7 -> V_53 ) ;
V_87 += 8 * V_70 ;
V_17 = F_63 ( V_82 , 0 , V_87 ) ;
if ( V_17 )
goto V_99;
V_17 = F_64 ( V_82 , V_81 , 0 , 0 , V_87 ,
V_87 , V_87 , & V_86 ) ;
if ( V_17 ) {
F_65 ( V_82 , 0 , V_87 ) ;
goto V_99;
}
F_66 ( V_82 , 0 , V_87 ) ;
V_17 = F_67 ( V_3 , V_81 , V_12 , V_82 ) ;
V_99:
F_68 ( V_82 ) ;
V_97:
F_54 ( V_3 -> V_5 , L_4 ,
V_81 -> V_95 , V_81 -> V_93 , 0 ) ;
F_69 ( V_3 , V_81 -> V_91 , V_81 -> V_93 ) ;
V_29:
V_81 -> V_91 = V_84 ;
V_81 -> V_93 = V_85 ;
F_21 ( V_12 ) ;
return V_17 ;
}
static int F_70 ( struct V_2 * V_3 , T_1 * V_23 )
{
struct V_11 * V_12 ;
int V_17 ;
struct V_13 * V_100 ;
struct V_9 V_101 ;
struct V_9 V_102 ;
int V_16 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_101 . V_23 = V_43 ;
V_101 . type = - 1 ;
V_101 . V_25 = ( T_1 ) - 1 ;
V_17 = F_5 ( NULL , V_3 , & V_101 , V_12 , 0 , 0 ) ;
if ( V_17 < 0 )
goto error;
F_37 ( V_17 == 0 ) ;
if ( V_12 -> V_31 [ 0 ] > 0 ) {
V_16 = V_12 -> V_31 [ 0 ] - 1 ;
V_100 = V_12 -> V_30 [ 0 ] ;
F_12 ( V_100 , & V_102 , V_16 ) ;
* V_23 = F_71 ( T_1 , V_102 . V_23 ,
V_24 - 1 ) ;
} else {
* V_23 = V_24 - 1 ;
}
V_17 = 0 ;
error:
F_21 ( V_12 ) ;
return V_17 ;
}
int F_24 ( struct V_2 * V_3 , T_1 * V_23 )
{
int V_17 ;
F_72 ( & V_3 -> V_103 ) ;
if ( F_73 ( V_3 -> V_34 < V_24 ) ) {
V_17 = F_70 ( V_3 ,
& V_3 -> V_34 ) ;
if ( V_17 )
goto V_29;
}
if ( F_73 ( V_3 -> V_34 >= V_43 ) ) {
V_17 = - V_46 ;
goto V_29;
}
* V_23 = ++ V_3 -> V_34 ;
V_17 = 0 ;
V_29:
F_74 ( & V_3 -> V_103 ) ;
return V_17 ;
}
