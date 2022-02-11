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
if ( ! F_2 ( V_5 , V_18 ) )
return 0 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_12 -> V_20 = 1 ;
V_12 -> V_21 = 1 ;
V_12 -> V_22 = V_23 ;
V_10 . V_24 = V_25 ;
V_10 . V_26 = 0 ;
V_10 . type = V_27 ;
V_28:
F_4 ( & V_5 -> V_29 ) ;
V_17 = F_5 ( NULL , V_3 , & V_10 , V_12 , 0 , 0 ) ;
if ( V_17 < 0 )
goto V_30;
while ( 1 ) {
if ( F_6 ( V_5 ) )
goto V_30;
V_14 = V_12 -> V_31 [ 0 ] ;
V_16 = V_12 -> V_32 [ 0 ] ;
if ( V_16 >= F_7 ( V_14 ) ) {
V_17 = F_8 ( V_3 , V_12 ) ;
if ( V_17 < 0 )
goto V_30;
else if ( V_17 > 0 )
break;
if ( F_9 () ||
F_10 ( V_5 ) ) {
V_14 = V_12 -> V_31 [ 0 ] ;
if ( F_11 ( F_7 ( V_14 ) == 0 ) )
break;
F_12 ( V_14 , & V_10 , 0 ) ;
F_13 ( V_12 ) ;
V_3 -> V_33 = V_15 ;
F_14 ( & V_5 -> V_29 ) ;
F_15 ( 1 ) ;
goto V_28;
} else
continue;
}
F_12 ( V_14 , & V_10 , V_16 ) ;
if ( V_10 . type != V_27 )
goto V_34;
if ( V_10 . V_24 >= V_3 -> V_35 )
break;
if ( V_15 != ( T_1 ) - 1 && V_15 + 1 != V_10 . V_24 ) {
F_16 ( V_5 , V_7 , V_15 + 1 ,
V_10 . V_24 - V_15 - 1 ) ;
F_17 ( & V_3 -> V_36 ) ;
}
V_15 = V_10 . V_24 ;
V_34:
V_12 -> V_32 [ 0 ] ++ ;
}
if ( V_15 < V_3 -> V_35 - 1 ) {
F_16 ( V_5 , V_7 , V_15 + 1 ,
V_3 -> V_35 - V_15 - 1 ) ;
}
F_18 ( & V_3 -> V_37 ) ;
V_3 -> V_38 = V_39 ;
F_19 ( & V_3 -> V_37 ) ;
V_3 -> V_33 = ( T_1 ) - 1 ;
F_20 ( V_3 ) ;
V_30:
F_17 ( & V_3 -> V_36 ) ;
F_14 ( & V_5 -> V_29 ) ;
F_21 ( V_12 ) ;
return V_17 ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_40 * V_41 ;
int V_17 ;
T_1 V_24 ;
if ( ! F_2 ( V_5 , V_18 ) )
return;
F_18 ( & V_3 -> V_37 ) ;
if ( V_3 -> V_38 != V_42 ) {
F_19 ( & V_3 -> V_37 ) ;
return;
}
V_3 -> V_38 = V_43 ;
F_19 ( & V_3 -> V_37 ) ;
V_17 = F_23 ( V_5 , V_3 ) ;
if ( V_17 == 1 ) {
F_18 ( & V_3 -> V_37 ) ;
V_3 -> V_38 = V_39 ;
F_19 ( & V_3 -> V_37 ) ;
return;
}
V_17 = F_24 ( V_3 , & V_24 ) ;
if ( ! V_17 && V_24 <= V_44 ) {
F_16 ( V_5 , V_7 , V_24 ,
V_44 - V_24 + 1 ) ;
}
V_41 = F_25 ( F_1 , V_3 , L_1 ,
V_3 -> V_45 . V_24 ) ;
if ( F_26 ( V_41 ) ) {
F_27 ( V_5 , L_2 ) ;
F_28 ( V_5 , V_18 ,
L_3 ) ;
}
}
int F_29 ( struct V_2 * V_3 , T_1 * V_24 )
{
if ( ! F_2 ( V_3 -> V_5 , V_18 ) )
return F_24 ( V_3 , V_24 ) ;
V_28:
* V_24 = F_30 ( V_3 ) ;
if ( * V_24 != 0 )
return 0 ;
F_22 ( V_3 ) ;
F_31 ( V_3 -> V_36 ,
V_3 -> V_38 == V_39 ||
V_3 -> V_8 -> V_46 > 0 ) ;
if ( V_3 -> V_38 == V_39 &&
V_3 -> V_8 -> V_46 == 0 )
return - V_47 ;
else
goto V_28;
}
void F_32 ( struct V_2 * V_3 , T_1 V_24 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_48 = V_3 -> V_49 ;
if ( ! F_2 ( V_5 , V_18 ) )
return;
V_28:
if ( V_3 -> V_38 == V_39 ) {
F_16 ( V_5 , V_48 , V_24 , 1 ) ;
} else {
F_33 ( & V_5 -> V_29 ) ;
F_18 ( & V_3 -> V_37 ) ;
if ( V_3 -> V_38 == V_39 ) {
F_19 ( & V_3 -> V_37 ) ;
F_34 ( & V_5 -> V_29 ) ;
goto V_28;
}
F_19 ( & V_3 -> V_37 ) ;
F_22 ( V_3 ) ;
F_16 ( V_5 , V_48 , V_24 , 1 ) ;
F_34 ( & V_5 -> V_29 ) ;
}
}
void F_20 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_50 * V_51 = & V_3 -> V_49 -> V_52 ;
T_2 * V_53 = & V_3 -> V_49 -> V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_1 V_59 ;
if ( ! F_2 ( V_3 -> V_5 , V_18 ) )
return;
while ( 1 ) {
bool V_60 = true ;
F_18 ( V_53 ) ;
V_58 = F_35 ( V_51 ) ;
if ( ! V_58 ) {
F_19 ( V_53 ) ;
break;
}
V_56 = F_36 ( V_58 , struct V_55 , V_61 ) ;
F_37 ( V_56 -> V_62 ) ;
if ( V_56 -> V_26 > V_3 -> V_33 )
V_60 = false ;
else if ( V_56 -> V_26 + V_56 -> V_63 > V_3 -> V_33 )
V_59 = V_3 -> V_33 - V_56 -> V_26 + 1 ;
else
V_59 = V_56 -> V_63 ;
F_38 ( & V_56 -> V_61 , V_51 ) ;
F_19 ( V_53 ) ;
if ( V_60 )
F_16 ( V_3 -> V_5 , V_7 ,
V_56 -> V_26 , V_59 ) ;
F_39 ( V_64 , V_56 ) ;
}
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_65 ;
int V_66 ;
V_58 = F_41 ( & V_7 -> V_52 ) ;
if ( ! V_58 ) {
V_7 -> V_67 = V_68 ;
return;
}
V_56 = F_36 ( V_58 , struct V_55 , V_61 ) ;
V_65 = V_56 -> V_63 - 1 ;
V_66 = F_42 ( V_65 , V_69 ) / V_69 ;
if ( V_66 <= V_7 -> V_70 ) {
V_7 -> V_67 = 0 ;
return;
}
V_7 -> V_67 = ( V_66 - V_7 -> V_70 ) *
V_71 / sizeof( * V_56 ) ;
}
static bool F_43 ( struct V_6 * V_7 ,
struct V_55 * V_56 )
{
if ( V_7 -> V_72 < V_7 -> V_67 ||
V_56 -> V_63 > V_69 / 10 )
return false ;
return true ;
}
static void F_44 ( struct V_6 * V_7 )
{
}
static bool F_45 ( struct V_6 * V_7 ,
struct V_55 * V_56 )
{
return false ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_6 * V_48 = V_3 -> V_49 ;
F_47 ( & V_7 -> V_54 ) ;
V_7 -> V_73 = 1 ;
V_7 -> V_74 = 0 ;
V_7 -> V_75 = NULL ;
V_7 -> V_76 = & V_77 ;
F_48 ( & V_7 -> V_78 ) ;
F_49 ( & V_7 -> V_79 ) ;
V_7 -> V_67 = V_68 ;
F_47 ( & V_48 -> V_54 ) ;
V_48 -> V_73 = 1 ;
V_48 -> V_74 = 0 ;
V_48 -> V_75 = NULL ;
V_48 -> V_67 = 0 ;
V_48 -> V_76 = & V_80 ;
}
int F_50 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_11 * V_12 ;
struct V_83 * V_83 ;
struct V_84 * V_85 ;
T_1 V_86 ;
T_1 V_87 = 0 ;
int V_17 ;
int V_88 ;
bool V_89 = false ;
if ( V_3 -> V_45 . V_24 != V_90 &&
( V_3 -> V_45 . V_24 < V_25 ||
V_3 -> V_45 . V_24 > V_44 ) )
return 0 ;
if ( F_51 ( & V_3 -> V_91 ) == 0 )
return 0 ;
if ( ! F_2 ( V_5 , V_18 ) )
return 0 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_85 = V_82 -> V_92 ;
V_82 -> V_92 = & V_5 -> V_93 ;
V_86 = V_82 -> V_94 ;
V_82 -> V_94 = F_52 ( V_5 , 10 ) ;
V_17 = F_53 ( V_3 , V_82 -> V_92 ,
V_82 -> V_94 ,
V_95 ) ;
if ( V_17 )
goto V_30;
F_54 ( V_5 , L_4 , V_82 -> V_96 ,
V_82 -> V_94 , 1 ) ;
V_28:
V_83 = F_55 ( V_3 , V_12 ) ;
if ( F_26 ( V_83 ) && ( F_56 ( V_83 ) != - V_97 || V_89 ) ) {
V_17 = F_56 ( V_83 ) ;
goto V_98;
}
if ( F_26 ( V_83 ) ) {
F_37 ( V_89 ) ;
V_89 = true ;
V_17 = F_57 ( V_3 , V_82 , V_12 ) ;
if ( V_17 )
goto V_98;
goto V_28;
}
F_58 ( V_83 ) -> V_99 = 0 ;
V_17 = F_59 ( V_82 , V_3 , V_83 ) ;
if ( V_17 ) {
F_60 ( V_82 , V_17 ) ;
goto V_100;
}
if ( F_61 ( V_83 ) > 0 ) {
V_17 = F_62 ( V_3 , V_82 , NULL , V_83 ) ;
if ( V_17 ) {
if ( V_17 != - V_47 )
F_60 ( V_82 , V_17 ) ;
goto V_100;
}
}
F_18 ( & V_3 -> V_37 ) ;
if ( V_3 -> V_38 != V_39 ) {
V_17 = - 1 ;
F_19 ( & V_3 -> V_37 ) ;
goto V_100;
}
F_19 ( & V_3 -> V_37 ) ;
F_18 ( & V_7 -> V_54 ) ;
V_88 = sizeof( struct V_55 ) * V_7 -> V_72 ;
V_88 = F_42 ( V_88 , V_71 ) ;
V_88 += V_7 -> V_70 * V_71 ;
F_19 ( & V_7 -> V_54 ) ;
V_88 += 8 * V_71 ;
V_17 = F_63 ( V_83 , 0 , V_88 ) ;
if ( V_17 )
goto V_100;
V_17 = F_64 ( V_83 , V_82 , 0 , 0 , V_88 ,
V_88 , V_88 , & V_87 ) ;
if ( V_17 ) {
F_65 ( V_83 , V_88 ) ;
goto V_100;
}
V_17 = F_66 ( V_3 , V_82 , V_12 , V_83 ) ;
V_100:
F_67 ( V_83 ) ;
V_98:
F_54 ( V_5 , L_4 , V_82 -> V_96 ,
V_82 -> V_94 , 0 ) ;
F_68 ( V_5 , V_82 -> V_92 ,
V_82 -> V_94 ) ;
V_30:
V_82 -> V_92 = V_85 ;
V_82 -> V_94 = V_86 ;
F_21 ( V_12 ) ;
return V_17 ;
}
int F_69 ( struct V_2 * V_3 , T_1 * V_24 )
{
struct V_11 * V_12 ;
int V_17 ;
struct V_13 * V_101 ;
struct V_9 V_102 ;
struct V_9 V_103 ;
int V_16 ;
V_12 = F_3 () ;
if ( ! V_12 )
return - V_19 ;
V_102 . V_24 = V_44 ;
V_102 . type = - 1 ;
V_102 . V_26 = ( T_1 ) - 1 ;
V_17 = F_5 ( NULL , V_3 , & V_102 , V_12 , 0 , 0 ) ;
if ( V_17 < 0 )
goto error;
F_37 ( V_17 == 0 ) ;
if ( V_12 -> V_32 [ 0 ] > 0 ) {
V_16 = V_12 -> V_32 [ 0 ] - 1 ;
V_101 = V_12 -> V_31 [ 0 ] ;
F_12 ( V_101 , & V_103 , V_16 ) ;
* V_24 = F_70 ( T_1 , V_103 . V_24 ,
V_25 - 1 ) ;
} else {
* V_24 = V_25 - 1 ;
}
V_17 = 0 ;
error:
F_21 ( V_12 ) ;
return V_17 ;
}
int F_24 ( struct V_2 * V_3 , T_1 * V_24 )
{
int V_17 ;
F_71 ( & V_3 -> V_104 ) ;
if ( F_72 ( V_3 -> V_35 >= V_44 ) ) {
F_27 ( V_3 -> V_5 ,
L_5 ,
V_3 -> V_45 . V_24 ) ;
V_17 = - V_47 ;
goto V_30;
}
* V_24 = ++ V_3 -> V_35 ;
V_17 = 0 ;
V_30:
F_73 ( & V_3 -> V_104 ) ;
return V_17 ;
}
