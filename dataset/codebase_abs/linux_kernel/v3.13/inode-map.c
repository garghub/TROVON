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
F_4 ( & V_3 -> V_28 ) ;
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
F_14 ( & V_3 -> V_28 ) ;
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
F_14 ( & V_3 -> V_28 ) ;
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
F_26 ( F_27 ( V_40 ) ) ;
}
int F_28 ( struct V_2 * V_3 , T_1 * V_23 )
{
if ( ! F_2 ( V_3 , V_18 ) )
return F_24 ( V_3 , V_23 ) ;
V_27:
* V_23 = F_29 ( V_3 ) ;
if ( * V_23 != 0 )
return 0 ;
F_22 ( V_3 ) ;
F_30 ( V_3 -> V_35 ,
V_3 -> V_37 == V_38 ||
V_3 -> V_8 -> V_45 > 0 ) ;
if ( V_3 -> V_37 == V_38 &&
V_3 -> V_8 -> V_45 == 0 )
return - V_46 ;
else
goto V_27;
}
void F_31 ( struct V_2 * V_3 , T_1 V_23 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_6 * V_47 = V_3 -> V_48 ;
if ( ! F_2 ( V_3 , V_18 ) )
return;
V_27:
if ( V_3 -> V_37 == V_38 ) {
F_16 ( V_7 , V_23 , 1 ) ;
} else {
F_4 ( & V_3 -> V_28 ) ;
F_18 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_37 == V_38 ) {
F_19 ( & V_3 -> V_36 ) ;
F_14 ( & V_3 -> V_28 ) ;
goto V_27;
}
F_19 ( & V_3 -> V_36 ) ;
F_22 ( V_3 ) ;
if ( V_23 <= V_3 -> V_32 ||
V_23 >= V_3 -> V_34 )
F_16 ( V_7 , V_23 , 1 ) ;
else
F_16 ( V_47 , V_23 , 1 ) ;
F_14 ( & V_3 -> V_28 ) ;
}
}
void F_20 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_49 * V_50 = & V_3 -> V_48 -> V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_1 V_56 ;
if ( ! F_2 ( V_3 , V_18 ) )
return;
while ( 1 ) {
V_55 = F_32 ( V_50 ) ;
if ( ! V_55 )
break;
V_53 = F_33 ( V_55 , struct V_52 , V_57 ) ;
F_26 ( V_53 -> V_58 ) ;
if ( V_53 -> V_25 > V_3 -> V_32 )
goto free;
else if ( V_53 -> V_25 + V_53 -> V_59 > V_3 -> V_32 )
V_56 = V_3 -> V_32 - V_53 -> V_25 + 1 ;
else
V_56 = V_53 -> V_59 ;
F_16 ( V_7 , V_53 -> V_25 , V_56 ) ;
free:
F_34 ( & V_53 -> V_57 , V_50 ) ;
F_35 ( V_53 ) ;
}
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_60 ;
int V_61 ;
V_55 = F_37 ( & V_7 -> V_51 ) ;
if ( ! V_55 ) {
V_7 -> V_62 = V_63 ;
return;
}
V_53 = F_33 ( V_55 , struct V_52 , V_57 ) ;
V_60 = V_53 -> V_59 - 1 ;
V_61 = F_38 ( V_60 , V_64 ) / V_64 ;
if ( V_61 <= V_7 -> V_65 ) {
V_7 -> V_62 = 0 ;
return;
}
V_7 -> V_62 = ( V_61 - V_7 -> V_65 ) *
V_66 / sizeof( * V_53 ) ;
}
static bool F_39 ( struct V_6 * V_7 ,
struct V_52 * V_53 )
{
if ( V_7 -> V_67 < V_7 -> V_62 ||
V_53 -> V_59 > V_64 / 10 )
return false ;
return true ;
}
static void F_40 ( struct V_6 * V_7 )
{
}
static bool F_41 ( struct V_6 * V_7 ,
struct V_52 * V_53 )
{
return false ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_6 * V_47 = V_3 -> V_48 ;
F_43 ( & V_7 -> V_68 ) ;
V_7 -> V_69 = 1 ;
V_7 -> V_70 = 0 ;
V_7 -> V_71 = NULL ;
V_7 -> V_72 = & V_73 ;
V_7 -> V_62 = V_63 ;
F_43 ( & V_47 -> V_68 ) ;
V_47 -> V_69 = 1 ;
V_47 -> V_70 = 0 ;
V_47 -> V_71 = NULL ;
V_47 -> V_62 = 0 ;
V_47 -> V_72 = & V_74 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_75 * V_76 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_11 * V_12 ;
struct V_77 * V_77 ;
struct V_78 * V_79 ;
T_1 V_80 ;
T_1 V_81 = 0 ;
int V_17 ;
int V_82 ;
bool V_83 = false ;
if ( V_3 -> V_44 . V_23 != V_84 &&
( V_3 -> V_44 . V_23 < V_24 ||
V_3 -> V_44 . V_23 > V_43 ) )
return 0 ;
if ( F_45 ( & V_3 -> V_85 ) == 0 )
return 0 ;
if ( ! F_2 ( V_3 , V_18 ) )
return 0 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_79 = V_76 -> V_86 ;
V_76 -> V_86 = & V_3 -> V_5 -> V_87 ;
V_80 = V_76 -> V_88 ;
V_76 -> V_88 = F_46 ( V_3 , 10 ) ;
V_17 = F_47 ( V_3 , V_76 -> V_86 ,
V_76 -> V_88 ,
V_89 ) ;
if ( V_17 )
goto V_29;
F_48 ( V_3 -> V_5 , L_2 ,
V_76 -> V_90 , V_76 -> V_88 , 1 ) ;
V_27:
V_77 = F_49 ( V_3 , V_12 ) ;
if ( F_27 ( V_77 ) && ( F_50 ( V_77 ) != - V_91 || V_83 ) ) {
V_17 = F_50 ( V_77 ) ;
goto V_92;
}
if ( F_27 ( V_77 ) ) {
F_26 ( V_83 ) ;
V_83 = true ;
V_17 = F_51 ( V_3 , V_76 , V_12 ) ;
if ( V_17 )
goto V_92;
goto V_27;
}
F_52 ( V_77 ) -> V_93 = 0 ;
V_17 = F_53 ( V_76 , V_3 , V_77 ) ;
if ( V_17 ) {
F_54 ( V_76 , V_3 , V_17 ) ;
goto V_94;
}
if ( F_55 ( V_77 ) > 0 ) {
V_17 = F_56 ( V_3 , V_76 , V_77 ) ;
if ( V_17 ) {
if ( V_17 != - V_46 )
F_54 ( V_76 , V_3 , V_17 ) ;
goto V_94;
}
}
F_18 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_37 != V_38 ) {
V_17 = - 1 ;
F_19 ( & V_3 -> V_36 ) ;
goto V_94;
}
F_19 ( & V_3 -> V_36 ) ;
F_18 ( & V_7 -> V_68 ) ;
V_82 = sizeof( struct V_52 ) * V_7 -> V_67 ;
V_82 = F_38 ( V_82 , V_66 ) ;
V_82 += V_7 -> V_65 * V_66 ;
F_19 ( & V_7 -> V_68 ) ;
V_82 += 8 * V_66 ;
V_17 = F_57 ( V_77 , V_82 ) ;
if ( V_17 )
goto V_94;
V_17 = F_58 ( V_77 , V_76 , 0 , 0 , V_82 ,
V_82 , V_82 , & V_81 ) ;
if ( V_17 ) {
F_59 ( V_77 , V_82 ) ;
goto V_94;
}
F_60 ( V_77 , V_82 ) ;
V_17 = F_61 ( V_3 , V_76 , V_12 , V_77 ) ;
V_94:
F_62 ( V_77 ) ;
V_92:
F_48 ( V_3 -> V_5 , L_2 ,
V_76 -> V_90 , V_76 -> V_88 , 0 ) ;
F_63 ( V_3 , V_76 -> V_86 , V_76 -> V_88 ) ;
V_29:
V_76 -> V_86 = V_79 ;
V_76 -> V_88 = V_80 ;
F_21 ( V_12 ) ;
return V_17 ;
}
static int F_64 ( struct V_2 * V_3 , T_1 * V_23 )
{
struct V_11 * V_12 ;
int V_17 ;
struct V_13 * V_95 ;
struct V_9 V_96 ;
struct V_9 V_97 ;
int V_16 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_96 . V_23 = V_43 ;
V_96 . type = - 1 ;
V_96 . V_25 = ( T_1 ) - 1 ;
V_17 = F_5 ( NULL , V_3 , & V_96 , V_12 , 0 , 0 ) ;
if ( V_17 < 0 )
goto error;
F_26 ( V_17 == 0 ) ;
if ( V_12 -> V_31 [ 0 ] > 0 ) {
V_16 = V_12 -> V_31 [ 0 ] - 1 ;
V_95 = V_12 -> V_30 [ 0 ] ;
F_12 ( V_95 , & V_97 , V_16 ) ;
* V_23 = F_65 ( T_1 , V_97 . V_23 ,
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
F_4 ( & V_3 -> V_98 ) ;
if ( F_66 ( V_3 -> V_34 < V_24 ) ) {
V_17 = F_64 ( V_3 ,
& V_3 -> V_34 ) ;
if ( V_17 )
goto V_29;
}
if ( F_66 ( V_3 -> V_34 >= V_43 ) ) {
V_17 = - V_46 ;
goto V_29;
}
* V_23 = ++ V_3 -> V_34 ;
V_17 = 0 ;
V_29:
F_14 ( & V_3 -> V_98 ) ;
return V_17 ;
}
