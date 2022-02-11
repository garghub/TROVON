static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_4 = V_2 -> V_7 [ F_2 ( V_2 , V_8 ) ] ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_6 = F_3 ( V_2 , V_4 , V_5 , V_2 -> V_10 ,
V_2 -> V_11 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , int V_12 ,
struct V_13 * V_14 )
{
int V_6 ;
T_1 V_15 ;
F_5 ( V_12 >= 0 && V_12 < V_2 -> V_16 ) ;
if ( ! V_14 )
V_14 = & V_17 ;
else {
V_15 = F_6 ( V_18 , V_14 , V_19 ) ;
V_14 -> V_15 = F_7 ( V_15 ) ;
}
memcpy ( & V_2 -> V_10 [ V_12 ] , V_14 , sizeof( struct V_13 ) ) ;
V_6 = F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
return V_6 ? V_6 : 0 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 ;
F_10 (re, rename_list, list) {
T_1 V_15 ;
struct V_3 * V_24 = V_23 -> V_25 -> V_24 ;
struct V_13 * V_14 = & V_2 -> V_10 [ V_24 -> V_26 ] ;
if ( V_23 -> remove ) {
memcpy ( V_14 , & V_17 ,
sizeof( struct V_13 ) ) ;
continue;
}
V_14 -> V_27 = F_11 ( V_23 -> V_28 ) ;
memcpy ( V_14 -> V_29 , V_23 -> V_30 , V_23 -> V_28 ) ;
memset ( V_14 -> V_29 + V_23 -> V_28 , 0 ,
V_31 + 1 - V_23 -> V_28 ) ;
V_15 = F_6 ( V_18 , V_14 ,
V_19 ) ;
V_14 -> V_15 = F_7 ( V_15 ) ;
}
return F_1 ( V_2 ) ;
}
static int F_12 ( const struct V_1 * V_2 ,
const struct V_13 * V_10 )
{
int V_5 , V_32 , V_33 , V_34 , V_35 , V_36 , V_27 ;
int V_37 , V_6 ;
T_1 V_15 ;
const char * V_29 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_16 ; V_5 ++ ) {
F_13 () ;
V_33 = F_14 ( V_10 [ V_5 ] . V_33 ) ;
V_34 = F_14 ( V_10 [ V_5 ] . V_34 ) ;
V_35 = F_14 ( V_10 [ V_5 ] . V_35 ) ;
V_37 = V_10 [ V_5 ] . V_37 ;
V_36 = V_10 [ V_5 ] . V_36 ;
V_27 = F_15 ( V_10 [ V_5 ] . V_27 ) ;
V_29 = & V_10 [ V_5 ] . V_29 [ 0 ] ;
V_15 = F_6 ( V_18 , & V_10 [ V_5 ] , V_19 ) ;
if ( F_14 ( V_10 [ V_5 ] . V_15 ) != V_15 ) {
F_16 ( V_2 , L_1 ,
V_5 , V_15 , F_14 ( V_10 [ V_5 ] . V_15 ) ) ;
F_17 ( & V_10 [ V_5 ] , V_5 ) ;
return 1 ;
}
if ( V_33 == 0 ) {
if ( memcmp ( & V_10 [ V_5 ] , & V_17 ,
V_38 ) ) {
V_6 = 2 ;
goto V_39;
}
continue;
}
if ( V_33 < 0 || V_34 < 0 || V_35 < 0 ||
V_27 < 0 ) {
V_6 = 3 ;
goto V_39;
}
if ( V_34 > V_2 -> V_40 || V_34 == 0 ) {
V_6 = 4 ;
goto V_39;
}
V_32 = V_34 & ( V_2 -> V_41 - 1 ) ;
if ( V_34 != 1 && V_32 ) {
V_6 = 5 ;
goto V_39;
}
V_32 = V_2 -> V_40 % V_34 ;
if ( V_35 != V_32 ) {
F_16 ( V_2 , L_2 , V_32 ) ;
V_6 = 6 ;
goto V_39;
}
if ( V_36 != V_42 && V_36 != V_43 ) {
V_6 = 7 ;
goto V_39;
}
if ( V_37 != 0 && V_37 != 1 ) {
V_6 = 8 ;
goto V_39;
}
if ( V_33 > V_2 -> V_44 ) {
F_16 ( V_2 , L_3 ,
V_33 , V_2 -> V_44 ) ;
V_6 = 9 ;
goto V_39;
}
if ( V_27 > V_31 ) {
V_6 = 10 ;
goto V_39;
}
if ( V_29 [ 0 ] == '\0' ) {
V_6 = 11 ;
goto V_39;
}
if ( V_27 != F_18 ( V_29 , V_27 + 1 ) ) {
V_6 = 12 ;
goto V_39;
}
}
for ( V_5 = 0 ; V_5 < V_2 -> V_16 - 1 ; V_5 ++ ) {
for ( V_32 = V_5 + 1 ; V_32 < V_2 -> V_16 ; V_32 ++ ) {
int V_45 = F_15 ( V_10 [ V_5 ] . V_27 ) ;
int V_46 = F_15 ( V_10 [ V_32 ] . V_27 ) ;
if ( V_45 > 0 && V_45 == V_46 &&
! strncmp ( V_10 [ V_5 ] . V_29 , V_10 [ V_32 ] . V_29 , V_45 ) ) {
F_16 ( V_2 , L_4 ,
V_5 , V_32 , V_10 [ V_5 ] . V_29 ) ;
F_17 ( & V_10 [ V_5 ] , V_5 ) ;
F_17 ( & V_10 [ V_32 ] , V_32 ) ;
return - V_47 ;
}
}
}
return 0 ;
V_39:
F_16 ( V_2 , L_5 , V_5 , V_6 ) ;
F_17 ( & V_10 [ V_5 ] , V_5 ) ;
return - V_47 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_50 , void * V_10 )
{
int V_6 , V_51 = 0 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
F_20 ( L_6 , V_50 + 1 ) ;
V_53 = F_21 ( V_2 , V_58 ) ;
if ( ! V_53 )
return - V_59 ;
V_55 = F_22 ( V_53 ) ;
V_60:
V_57 = F_23 ( V_2 , V_49 ) ;
if ( F_24 ( V_57 ) ) {
V_6 = F_25 ( V_57 ) ;
goto V_61;
}
V_55 -> V_36 = V_62 ;
V_55 -> V_26 = F_7 ( V_8 ) ;
V_55 -> V_63 = V_64 ;
V_55 -> V_65 = V_55 -> V_66 =
V_55 -> V_35 = F_7 ( 0 ) ;
V_55 -> V_67 = F_7 ( V_50 ) ;
V_55 -> V_68 = F_26 ( ++ V_49 -> V_69 ) ;
V_6 = F_27 ( V_2 , V_57 -> V_70 , V_53 ) ;
if ( V_6 )
goto V_71;
V_6 = F_28 ( V_2 , V_10 , V_57 -> V_70 , 0 , V_2 -> V_11 ) ;
if ( V_6 )
goto V_71;
V_6 = F_29 ( V_2 , V_49 , V_57 -> V_70 , V_57 -> V_72 , V_55 , 0 ) ;
F_30 ( V_49 , V_57 ) ;
F_31 ( V_53 ) ;
return V_6 ;
V_71:
if ( V_6 == - V_73 && ++ V_51 <= 5 ) {
F_32 ( & V_57 -> V_74 . V_75 , & V_49 -> V_76 ) ;
goto V_60;
}
F_30 ( V_49 , V_57 ) ;
V_61:
F_31 ( V_53 ) ;
return V_6 ;
}
static struct V_13 * F_33 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_77 * V_78 )
{
int V_6 ;
struct V_79 * V_80 ;
struct V_56 * V_81 ;
struct V_13 * V_82 [ V_9 ] = { NULL , NULL } ;
int V_83 [ V_9 ] = { 1 , 1 } ;
F_20 ( L_7 ) ;
F_34 (rb, aeb, &av->root, u.rb) {
V_82 [ V_81 -> V_67 ] = F_35 ( V_2 -> V_11 ) ;
if ( ! V_82 [ V_81 -> V_67 ] ) {
V_6 = - V_59 ;
goto V_61;
}
V_6 = F_36 ( V_2 , V_82 [ V_81 -> V_67 ] , V_81 -> V_70 , 0 ,
V_2 -> V_11 ) ;
if ( V_6 == V_84 || F_37 ( V_6 ) )
V_81 -> V_85 = 1 ;
else if ( V_6 )
goto V_61;
}
V_6 = - V_47 ;
if ( V_82 [ 0 ] ) {
V_83 [ 0 ] = F_12 ( V_2 , V_82 [ 0 ] ) ;
if ( V_83 [ 0 ] < 0 )
goto V_61;
}
if ( ! V_83 [ 0 ] ) {
if ( V_82 [ 1 ] )
V_83 [ 1 ] = memcmp ( V_82 [ 0 ] , V_82 [ 1 ] ,
V_2 -> V_11 ) ;
if ( V_83 [ 1 ] ) {
F_38 ( V_2 , L_8 ) ;
V_6 = F_19 ( V_2 , V_49 , 1 , V_82 [ 0 ] ) ;
if ( V_6 )
goto V_61;
F_39 ( V_2 , L_9 ) ;
}
F_40 ( V_82 [ 1 ] ) ;
return V_82 [ 0 ] ;
} else {
if ( V_82 [ 1 ] ) {
V_83 [ 1 ] = F_12 ( V_2 , V_82 [ 1 ] ) ;
if ( V_83 [ 1 ] < 0 )
goto V_61;
}
if ( V_83 [ 1 ] ) {
F_16 ( V_2 , L_10 ) ;
goto V_61;
}
F_38 ( V_2 , L_11 ) ;
V_6 = F_19 ( V_2 , V_49 , 0 , V_82 [ 1 ] ) ;
if ( V_6 )
goto V_61;
F_39 ( V_2 , L_9 ) ;
F_40 ( V_82 [ 0 ] ) ;
return V_82 [ 1 ] ;
}
V_61:
F_40 ( V_82 [ 0 ] ) ;
F_40 ( V_82 [ 1 ] ) ;
return F_41 ( V_6 ) ;
}
static struct V_13 * F_42 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_5 ;
struct V_13 * V_10 ;
V_10 = F_35 ( V_2 -> V_11 ) ;
if ( ! V_10 )
return F_41 ( - V_59 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_16 ; V_5 ++ )
memcpy ( & V_10 [ V_5 ] , & V_17 , V_38 ) ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
int V_6 ;
V_6 = F_19 ( V_2 , V_49 , V_5 , V_10 ) ;
if ( V_6 ) {
F_40 ( V_10 ) ;
return F_41 ( V_6 ) ;
}
}
return V_10 ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_48 * V_49 ,
const struct V_13 * V_10 )
{
int V_5 , V_33 = 0 ;
struct V_77 * V_78 ;
struct V_3 * V_24 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_16 ; V_5 ++ ) {
F_13 () ;
if ( F_14 ( V_10 [ V_5 ] . V_33 ) == 0 )
continue;
V_24 = F_44 ( sizeof( struct V_3 ) , V_58 ) ;
if ( ! V_24 )
return - V_59 ;
V_24 -> V_33 = F_14 ( V_10 [ V_5 ] . V_33 ) ;
V_24 -> V_34 = F_14 ( V_10 [ V_5 ] . V_34 ) ;
V_24 -> V_35 = F_14 ( V_10 [ V_5 ] . V_35 ) ;
V_24 -> V_37 = V_10 [ V_5 ] . V_37 ;
V_24 -> V_36 = V_10 [ V_5 ] . V_36 == V_42 ?
V_86 : V_87 ;
V_24 -> V_27 = F_15 ( V_10 [ V_5 ] . V_27 ) ;
V_24 -> V_88 = V_2 -> V_40 - V_24 -> V_35 ;
memcpy ( V_24 -> V_29 , V_10 [ V_5 ] . V_29 , V_24 -> V_27 ) ;
V_24 -> V_29 [ V_24 -> V_27 ] = '\0' ;
V_24 -> V_26 = V_5 ;
if ( V_10 [ V_5 ] . V_89 & V_90 ) {
if ( V_2 -> V_91 != - 1 ) {
F_16 ( V_2 , L_12 ,
V_2 -> V_91 , V_5 ) ;
F_45 ( V_24 ) ;
return - V_47 ;
}
V_2 -> V_91 = V_5 ;
}
F_5 ( ! V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_7 [ V_5 ] = V_24 ;
V_2 -> V_92 += 1 ;
V_24 -> V_2 = V_2 ;
V_33 += V_24 -> V_33 ;
if ( V_24 -> V_36 == V_86 ) {
V_24 -> V_66 = V_24 -> V_33 ;
V_24 -> V_93 = V_24 -> V_88 ;
V_24 -> V_94 =
( long long ) V_24 -> V_66 * V_24 -> V_88 ;
continue;
}
V_78 = F_46 ( V_49 , V_5 ) ;
if ( ! V_78 || ! V_78 -> V_95 ) {
continue;
}
if ( V_78 -> V_95 != V_78 -> V_66 ) {
F_38 ( V_2 , L_13 ,
V_78 -> V_26 , V_78 -> V_66 - V_78 -> V_95 ) ;
V_24 -> V_96 = 1 ;
continue;
}
V_24 -> V_66 = V_78 -> V_66 ;
V_24 -> V_94 =
( long long ) ( V_24 -> V_66 - 1 ) * V_24 -> V_88 ;
V_24 -> V_94 += V_78 -> V_97 ;
V_24 -> V_93 = V_78 -> V_97 ;
}
V_24 = F_44 ( sizeof( struct V_3 ) , V_58 ) ;
if ( ! V_24 )
return - V_59 ;
V_24 -> V_33 = V_9 ;
V_24 -> V_34 = V_98 ;
V_24 -> V_36 = V_86 ;
V_24 -> V_27 = sizeof( V_99 ) - 1 ;
memcpy ( V_24 -> V_29 , V_99 , V_24 -> V_27 + 1 ) ;
V_24 -> V_88 = V_2 -> V_40 ;
V_24 -> V_66 = V_24 -> V_33 ;
V_24 -> V_93 = V_24 -> V_33 ;
V_24 -> V_94 =
( long long ) V_24 -> V_66 * ( V_2 -> V_40 - V_24 -> V_35 ) ;
V_24 -> V_26 = V_8 ;
V_24 -> V_100 = 1 ;
F_5 ( ! V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_7 [ F_2 ( V_2 , V_24 -> V_26 ) ] = V_24 ;
V_33 += V_24 -> V_33 ;
V_2 -> V_92 += 1 ;
V_24 -> V_2 = V_2 ;
if ( V_33 > V_2 -> V_101 ) {
F_16 ( V_2 , L_14 ,
V_33 , V_2 -> V_101 ) ;
if ( V_2 -> V_102 )
F_16 ( V_2 , L_15 ,
V_2 -> V_102 ) ;
return - V_103 ;
}
V_2 -> V_104 += V_33 ;
V_2 -> V_101 -= V_33 ;
return 0 ;
}
static int F_47 ( const struct V_3 * V_24 ,
const struct V_77 * V_78 )
{
int V_6 ;
if ( V_78 -> V_105 >= V_24 -> V_33 ) {
V_6 = 1 ;
goto V_39;
}
if ( V_78 -> V_95 > V_24 -> V_33 ) {
V_6 = 2 ;
goto V_39;
}
if ( V_78 -> V_36 != V_24 -> V_36 ) {
V_6 = 3 ;
goto V_39;
}
if ( V_78 -> V_66 > V_24 -> V_33 ) {
V_6 = 4 ;
goto V_39;
}
if ( V_78 -> V_35 != V_24 -> V_35 ) {
V_6 = 5 ;
goto V_39;
}
return 0 ;
V_39:
F_16 ( V_24 -> V_2 , L_16 , V_6 ) ;
F_48 ( V_78 ) ;
F_49 ( V_24 ) ;
return - V_47 ;
}
static int F_50 ( const struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_6 , V_5 ;
struct V_77 * V_78 ;
struct V_3 * V_24 ;
if ( V_49 -> V_106 > V_107 + V_2 -> V_16 ) {
F_16 ( V_2 , L_17 ,
V_49 -> V_106 , V_107 , V_2 -> V_16 ) ;
return - V_47 ;
}
if ( V_49 -> V_108 >= V_2 -> V_16 + V_107 &&
V_49 -> V_108 < V_109 ) {
F_16 ( V_2 , L_18 ,
V_49 -> V_108 ) ;
return - V_47 ;
}
for ( V_5 = 0 ; V_5 < V_2 -> V_16 + V_107 ; V_5 ++ ) {
F_13 () ;
V_78 = F_46 ( V_49 , V_5 ) ;
V_24 = V_2 -> V_7 [ V_5 ] ;
if ( ! V_24 ) {
if ( V_78 )
F_51 ( V_49 , V_78 ) ;
continue;
}
if ( V_24 -> V_33 == 0 ) {
F_5 ( V_5 < V_2 -> V_16 ) ;
if ( ! V_78 )
continue;
F_39 ( V_2 , L_19 , V_78 -> V_26 ) ;
F_51 ( V_49 , V_78 ) ;
} else if ( V_78 ) {
V_6 = F_47 ( V_24 , V_78 ) ;
if ( V_6 )
return V_6 ;
}
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
int V_5 , V_6 ;
struct V_77 * V_78 ;
V_17 . V_15 = F_7 ( 0xf116c36b ) ;
V_2 -> V_16 = V_2 -> V_40 / V_38 ;
if ( V_2 -> V_16 > V_110 )
V_2 -> V_16 = V_110 ;
V_2 -> V_11 = V_2 -> V_16 * V_38 ;
V_2 -> V_11 = F_53 ( V_2 -> V_11 , V_2 -> V_41 ) ;
V_78 = F_46 ( V_49 , V_8 ) ;
if ( ! V_78 ) {
if ( V_49 -> V_111 ) {
V_2 -> V_10 = F_42 ( V_2 , V_49 ) ;
if ( F_24 ( V_2 -> V_10 ) )
return F_25 ( V_2 -> V_10 ) ;
} else {
F_16 ( V_2 , L_20 ) ;
return - V_47 ;
}
} else {
if ( V_78 -> V_95 > V_9 ) {
F_16 ( V_2 , L_21 ,
V_78 -> V_95 ) ;
return - V_47 ;
}
V_2 -> V_10 = F_33 ( V_2 , V_49 , V_78 ) ;
if ( F_24 ( V_2 -> V_10 ) )
return F_25 ( V_2 -> V_10 ) ;
}
V_2 -> V_101 = V_2 -> V_44 - V_2 -> V_102 ;
V_6 = F_43 ( V_2 , V_49 , V_2 -> V_10 ) ;
if ( V_6 )
goto V_61;
V_6 = F_50 ( V_2 , V_49 ) ;
if ( V_6 )
goto V_61;
return 0 ;
V_61:
F_40 ( V_2 -> V_10 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_16 + V_107 ; V_5 ++ ) {
F_45 ( V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_7 [ V_5 ] = NULL ;
}
return V_6 ;
}
static void F_8 ( const struct V_1 * V_2 )
{
if ( ! F_54 ( V_2 ) )
return;
if ( F_12 ( V_2 , V_2 -> V_10 ) ) {
F_16 ( V_2 , L_22 ) ;
F_55 () ;
}
}
