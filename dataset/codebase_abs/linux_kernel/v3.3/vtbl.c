int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
int V_6 , V_7 ;
T_1 V_8 ;
struct V_9 * V_10 ;
F_2 ( V_3 >= 0 && V_3 < V_2 -> V_11 ) ;
V_10 = V_2 -> V_12 [ F_3 ( V_2 , V_13 ) ] ;
if ( ! V_5 )
V_5 = & V_14 ;
else {
V_8 = F_4 ( V_15 , V_5 , V_16 ) ;
V_5 -> V_8 = F_5 ( V_8 ) ;
}
memcpy ( & V_2 -> V_17 [ V_3 ] , V_5 , sizeof( struct V_4 ) ) ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
V_7 = F_6 ( V_2 , V_10 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( V_2 , V_10 , V_6 , V_2 -> V_17 , 0 ,
V_2 -> V_19 , V_20 ) ;
if ( V_7 )
return V_7 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_6 , V_7 ;
struct V_23 * V_24 ;
struct V_9 * V_10 ;
F_10 (re, rename_list, list) {
T_1 V_8 ;
struct V_9 * V_25 = V_24 -> V_26 -> V_25 ;
struct V_4 * V_5 = & V_2 -> V_17 [ V_25 -> V_27 ] ;
if ( V_24 -> remove ) {
memcpy ( V_5 , & V_14 ,
sizeof( struct V_4 ) ) ;
continue;
}
V_5 -> V_28 = F_11 ( V_24 -> V_29 ) ;
memcpy ( V_5 -> V_30 , V_24 -> V_31 , V_24 -> V_29 ) ;
memset ( V_5 -> V_30 + V_24 -> V_29 , 0 ,
V_32 + 1 - V_24 -> V_29 ) ;
V_8 = F_4 ( V_15 , V_5 ,
V_16 ) ;
V_5 -> V_8 = F_5 ( V_8 ) ;
}
V_10 = V_2 -> V_12 [ F_3 ( V_2 , V_13 ) ] ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
V_7 = F_6 ( V_2 , V_10 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( V_2 , V_10 , V_6 , V_2 -> V_17 , 0 ,
V_2 -> V_19 , V_20 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_12 ( const struct V_1 * V_2 ,
const struct V_4 * V_17 )
{
int V_6 , V_33 , V_34 , V_35 , V_36 , V_37 , V_28 ;
int V_38 , V_7 ;
T_1 V_8 ;
const char * V_30 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
F_13 () ;
V_34 = F_14 ( V_17 [ V_6 ] . V_34 ) ;
V_35 = F_14 ( V_17 [ V_6 ] . V_35 ) ;
V_36 = F_14 ( V_17 [ V_6 ] . V_36 ) ;
V_38 = V_17 [ V_6 ] . V_38 ;
V_37 = V_17 [ V_6 ] . V_37 ;
V_28 = F_15 ( V_17 [ V_6 ] . V_28 ) ;
V_30 = & V_17 [ V_6 ] . V_30 [ 0 ] ;
V_8 = F_4 ( V_15 , & V_17 [ V_6 ] , V_16 ) ;
if ( F_14 ( V_17 [ V_6 ] . V_8 ) != V_8 ) {
F_16 ( L_1 ,
V_6 , V_8 , F_14 ( V_17 [ V_6 ] . V_8 ) ) ;
F_17 ( & V_17 [ V_6 ] , V_6 ) ;
return 1 ;
}
if ( V_34 == 0 ) {
if ( memcmp ( & V_17 [ V_6 ] , & V_14 ,
V_39 ) ) {
V_7 = 2 ;
goto V_40;
}
continue;
}
if ( V_34 < 0 || V_35 < 0 || V_36 < 0 ||
V_28 < 0 ) {
V_7 = 3 ;
goto V_40;
}
if ( V_35 > V_2 -> V_41 || V_35 == 0 ) {
V_7 = 4 ;
goto V_40;
}
V_33 = V_35 & ( V_2 -> V_42 - 1 ) ;
if ( V_35 != 1 && V_33 ) {
V_7 = 5 ;
goto V_40;
}
V_33 = V_2 -> V_41 % V_35 ;
if ( V_36 != V_33 ) {
F_18 ( L_2 , V_33 ) ;
V_7 = 6 ;
goto V_40;
}
if ( V_37 != V_43 && V_37 != V_44 ) {
V_7 = 7 ;
goto V_40;
}
if ( V_38 != 0 && V_38 != 1 ) {
V_7 = 8 ;
goto V_40;
}
if ( V_34 > V_2 -> V_45 ) {
F_18 ( L_3 ,
V_34 , V_2 -> V_45 ) ;
V_7 = 9 ;
goto V_40;
}
if ( V_28 > V_32 ) {
V_7 = 10 ;
goto V_40;
}
if ( V_30 [ 0 ] == '\0' ) {
V_7 = 11 ;
goto V_40;
}
if ( V_28 != F_19 ( V_30 , V_28 + 1 ) ) {
V_7 = 12 ;
goto V_40;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_11 - 1 ; V_6 ++ ) {
for ( V_33 = V_6 + 1 ; V_33 < V_2 -> V_11 ; V_33 ++ ) {
int V_46 = F_15 ( V_17 [ V_6 ] . V_28 ) ;
int V_47 = F_15 ( V_17 [ V_33 ] . V_28 ) ;
if ( V_46 > 0 && V_46 == V_47 &&
! strncmp ( V_17 [ V_6 ] . V_30 , V_17 [ V_33 ] . V_30 , V_46 ) ) {
F_16 ( L_4
L_5 , V_6 , V_33 , V_17 [ V_6 ] . V_30 ) ;
F_17 ( & V_17 [ V_6 ] , V_6 ) ;
F_17 ( & V_17 [ V_33 ] , V_33 ) ;
return - V_48 ;
}
}
}
return 0 ;
V_40:
F_16 ( L_6 , V_6 , V_7 ) ;
F_17 ( & V_17 [ V_6 ] , V_6 ) ;
return - V_48 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_49 * V_50 ,
int V_51 , void * V_17 )
{
int V_7 , V_52 = 0 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
F_21 ( L_7 , V_51 + 1 ) ;
V_54 = F_22 ( V_2 , V_57 ) ;
if ( ! V_54 )
return - V_58 ;
V_59:
V_56 = F_23 ( V_2 , V_50 ) ;
if ( F_24 ( V_56 ) ) {
V_7 = F_25 ( V_56 ) ;
goto V_60;
}
V_54 -> V_37 = V_61 ;
V_54 -> V_27 = F_5 ( V_13 ) ;
V_54 -> V_62 = V_63 ;
V_54 -> V_64 = V_54 -> V_65 =
V_54 -> V_36 = F_5 ( 0 ) ;
V_54 -> V_66 = F_5 ( V_51 ) ;
V_54 -> V_67 = F_26 ( ++ V_50 -> V_68 ) ;
V_7 = F_27 ( V_2 , V_56 -> V_69 , V_54 ) ;
if ( V_7 )
goto V_70;
V_7 = F_28 ( V_2 , V_17 , V_56 -> V_69 , 0 , V_2 -> V_19 ) ;
if ( V_7 )
goto V_70;
V_7 = F_29 ( V_2 , V_50 , V_56 -> V_69 , V_56 -> V_71 ,
V_54 , 0 ) ;
F_30 ( V_56 ) ;
F_31 ( V_2 , V_54 ) ;
return V_7 ;
V_70:
if ( V_7 == - V_72 && ++ V_52 <= 5 ) {
F_32 ( & V_56 -> V_73 . V_74 , & V_50 -> V_75 ) ;
goto V_59;
}
F_30 ( V_56 ) ;
V_60:
F_31 ( V_2 , V_54 ) ;
return V_7 ;
}
static struct V_4 * F_33 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_76 * V_77 )
{
int V_7 ;
struct V_78 * V_79 ;
struct V_55 * V_80 ;
struct V_4 * V_81 [ V_18 ] = { NULL , NULL } ;
int V_82 [ V_18 ] = { 1 , 1 } ;
F_34 ( L_8 ) ;
F_35 (rb, seb, &sv->root, u.rb) {
V_81 [ V_80 -> V_66 ] = F_36 ( V_2 -> V_19 ) ;
if ( ! V_81 [ V_80 -> V_66 ] ) {
V_7 = - V_58 ;
goto V_60;
}
V_7 = F_37 ( V_2 , V_81 [ V_80 -> V_66 ] , V_80 -> V_69 , 0 ,
V_2 -> V_19 ) ;
if ( V_7 == V_83 || F_38 ( V_7 ) )
V_80 -> V_84 = 1 ;
else if ( V_7 )
goto V_60;
}
V_7 = - V_48 ;
if ( V_81 [ 0 ] ) {
V_82 [ 0 ] = F_12 ( V_2 , V_81 [ 0 ] ) ;
if ( V_82 [ 0 ] < 0 )
goto V_60;
}
if ( ! V_82 [ 0 ] ) {
if ( V_81 [ 1 ] )
V_82 [ 1 ] = memcmp ( V_81 [ 0 ] , V_81 [ 1 ] ,
V_2 -> V_19 ) ;
if ( V_82 [ 1 ] ) {
F_39 ( L_9 ) ;
V_7 = F_20 ( V_2 , V_50 , 1 , V_81 [ 0 ] ) ;
if ( V_7 )
goto V_60;
F_21 ( L_10 ) ;
}
F_40 ( V_81 [ 1 ] ) ;
return V_81 [ 0 ] ;
} else {
if ( V_81 [ 1 ] ) {
V_82 [ 1 ] = F_12 ( V_2 , V_81 [ 1 ] ) ;
if ( V_82 [ 1 ] < 0 )
goto V_60;
}
if ( V_82 [ 1 ] ) {
F_16 ( L_11 ) ;
goto V_60;
}
F_39 ( L_12 ) ;
V_7 = F_20 ( V_2 , V_50 , 0 , V_81 [ 1 ] ) ;
if ( V_7 )
goto V_60;
F_21 ( L_10 ) ;
F_40 ( V_81 [ 0 ] ) ;
return V_81 [ 1 ] ;
}
V_60:
F_40 ( V_81 [ 0 ] ) ;
F_40 ( V_81 [ 1 ] ) ;
return F_41 ( V_7 ) ;
}
static struct V_4 * F_42 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int V_6 ;
struct V_4 * V_17 ;
V_17 = F_36 ( V_2 -> V_19 ) ;
if ( ! V_17 )
return F_41 ( - V_58 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ )
memcpy ( & V_17 [ V_6 ] , & V_14 , V_39 ) ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
int V_7 ;
V_7 = F_20 ( V_2 , V_50 , V_6 , V_17 ) ;
if ( V_7 ) {
F_40 ( V_17 ) ;
return F_41 ( V_7 ) ;
}
}
return V_17 ;
}
static int F_43 ( struct V_1 * V_2 , const struct V_49 * V_50 ,
const struct V_4 * V_17 )
{
int V_6 , V_34 = 0 ;
struct V_76 * V_77 ;
struct V_9 * V_25 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
F_13 () ;
if ( F_14 ( V_17 [ V_6 ] . V_34 ) == 0 )
continue;
V_25 = F_44 ( sizeof( struct V_9 ) , V_57 ) ;
if ( ! V_25 )
return - V_58 ;
V_25 -> V_34 = F_14 ( V_17 [ V_6 ] . V_34 ) ;
V_25 -> V_35 = F_14 ( V_17 [ V_6 ] . V_35 ) ;
V_25 -> V_36 = F_14 ( V_17 [ V_6 ] . V_36 ) ;
V_25 -> V_38 = V_17 [ V_6 ] . V_38 ;
V_25 -> V_37 = V_17 [ V_6 ] . V_37 == V_43 ?
V_85 : V_86 ;
V_25 -> V_28 = F_15 ( V_17 [ V_6 ] . V_28 ) ;
V_25 -> V_87 = V_2 -> V_41 - V_25 -> V_36 ;
memcpy ( V_25 -> V_30 , V_17 [ V_6 ] . V_30 , V_25 -> V_28 ) ;
V_25 -> V_30 [ V_25 -> V_28 ] = '\0' ;
V_25 -> V_27 = V_6 ;
if ( V_17 [ V_6 ] . V_88 & V_89 ) {
if ( V_2 -> V_90 != - 1 ) {
F_16 ( L_13
L_14 , V_2 -> V_90 , V_6 ) ;
F_30 ( V_25 ) ;
return - V_48 ;
}
V_2 -> V_90 = V_6 ;
}
F_2 ( ! V_2 -> V_12 [ V_6 ] ) ;
V_2 -> V_12 [ V_6 ] = V_25 ;
V_2 -> V_91 += 1 ;
V_25 -> V_2 = V_2 ;
V_34 += V_25 -> V_34 ;
if ( V_25 -> V_37 == V_85 ) {
V_25 -> V_65 = V_25 -> V_34 ;
V_25 -> V_92 = V_25 -> V_87 ;
V_25 -> V_93 =
( long long ) V_25 -> V_65 * V_25 -> V_87 ;
continue;
}
V_77 = F_45 ( V_50 , V_6 ) ;
if ( ! V_77 ) {
continue;
}
if ( V_77 -> V_94 != V_77 -> V_65 ) {
F_39 ( L_15 ,
V_77 -> V_27 , V_77 -> V_65 - V_77 -> V_94 ) ;
V_25 -> V_95 = 1 ;
continue;
}
V_25 -> V_65 = V_77 -> V_65 ;
V_25 -> V_93 =
( long long ) ( V_25 -> V_65 - 1 ) * V_25 -> V_87 ;
V_25 -> V_93 += V_77 -> V_96 ;
V_25 -> V_92 = V_77 -> V_96 ;
}
V_25 = F_44 ( sizeof( struct V_9 ) , V_57 ) ;
if ( ! V_25 )
return - V_58 ;
V_25 -> V_34 = V_18 ;
V_25 -> V_35 = V_97 ;
V_25 -> V_37 = V_85 ;
V_25 -> V_28 = sizeof( V_98 ) - 1 ;
memcpy ( V_25 -> V_30 , V_98 , V_25 -> V_28 + 1 ) ;
V_25 -> V_87 = V_2 -> V_41 ;
V_25 -> V_65 = V_25 -> V_34 ;
V_25 -> V_92 = V_25 -> V_34 ;
V_25 -> V_93 =
( long long ) V_25 -> V_65 * ( V_2 -> V_41 - V_25 -> V_36 ) ;
V_25 -> V_27 = V_13 ;
V_25 -> V_99 = 1 ;
F_2 ( ! V_2 -> V_12 [ V_6 ] ) ;
V_2 -> V_12 [ F_3 ( V_2 , V_25 -> V_27 ) ] = V_25 ;
V_34 += V_25 -> V_34 ;
V_2 -> V_91 += 1 ;
V_25 -> V_2 = V_2 ;
if ( V_34 > V_2 -> V_100 ) {
F_16 ( L_16 ,
V_34 , V_2 -> V_100 ) ;
if ( V_2 -> V_101 )
F_16 ( L_17 ,
V_2 -> V_101 ) ;
}
V_2 -> V_102 += V_34 ;
V_2 -> V_100 -= V_34 ;
return 0 ;
}
static int F_46 ( const struct V_9 * V_25 ,
const struct V_76 * V_77 )
{
int V_7 ;
if ( V_77 -> V_103 >= V_25 -> V_34 ) {
V_7 = 1 ;
goto V_40;
}
if ( V_77 -> V_94 > V_25 -> V_34 ) {
V_7 = 2 ;
goto V_40;
}
if ( V_77 -> V_37 != V_25 -> V_37 ) {
V_7 = 3 ;
goto V_40;
}
if ( V_77 -> V_65 > V_25 -> V_34 ) {
V_7 = 4 ;
goto V_40;
}
if ( V_77 -> V_36 != V_25 -> V_36 ) {
V_7 = 5 ;
goto V_40;
}
return 0 ;
V_40:
F_16 ( L_18 , V_7 ) ;
F_47 ( V_77 ) ;
F_48 ( V_25 ) ;
return - V_48 ;
}
static int F_49 ( const struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int V_7 , V_6 ;
struct V_76 * V_77 ;
struct V_9 * V_25 ;
if ( V_50 -> V_104 > V_105 + V_2 -> V_11 ) {
F_16 ( L_19 ,
V_50 -> V_104 , V_105 , V_2 -> V_11 ) ;
return - V_48 ;
}
if ( V_50 -> V_106 >= V_2 -> V_11 + V_105 &&
V_50 -> V_106 < V_107 ) {
F_16 ( L_20 ,
V_50 -> V_106 ) ;
return - V_48 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_11 + V_105 ; V_6 ++ ) {
F_13 () ;
V_77 = F_45 ( V_50 , V_6 ) ;
V_25 = V_2 -> V_12 [ V_6 ] ;
if ( ! V_25 ) {
if ( V_77 )
F_50 ( V_50 , V_77 ) ;
continue;
}
if ( V_25 -> V_34 == 0 ) {
F_2 ( V_6 < V_2 -> V_11 ) ;
if ( ! V_77 )
continue;
F_21 ( L_21 , V_77 -> V_27 ) ;
F_50 ( V_50 , V_77 ) ;
} else if ( V_77 ) {
V_7 = F_46 ( V_25 , V_77 ) ;
if ( V_7 )
return V_7 ;
}
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_6 , V_7 ;
struct V_76 * V_77 ;
V_14 . V_8 = F_5 ( 0xf116c36b ) ;
V_2 -> V_11 = V_2 -> V_41 / V_39 ;
if ( V_2 -> V_11 > V_108 )
V_2 -> V_11 = V_108 ;
V_2 -> V_19 = V_2 -> V_11 * V_39 ;
V_2 -> V_19 = F_52 ( V_2 -> V_19 , V_2 -> V_42 ) ;
V_77 = F_45 ( V_50 , V_13 ) ;
if ( ! V_77 ) {
if ( V_50 -> V_109 ) {
V_2 -> V_17 = F_42 ( V_2 , V_50 ) ;
if ( F_24 ( V_2 -> V_17 ) )
return F_25 ( V_2 -> V_17 ) ;
} else {
F_16 ( L_22 ) ;
return - V_48 ;
}
} else {
if ( V_77 -> V_94 > V_18 ) {
F_18 ( L_23 ,
V_77 -> V_94 ) ;
return - V_48 ;
}
V_2 -> V_17 = F_33 ( V_2 , V_50 , V_77 ) ;
if ( F_24 ( V_2 -> V_17 ) )
return F_25 ( V_2 -> V_17 ) ;
}
V_2 -> V_100 = V_2 -> V_45 - V_2 -> V_101 ;
V_7 = F_43 ( V_2 , V_50 , V_2 -> V_17 ) ;
if ( V_7 )
goto V_60;
V_7 = F_49 ( V_2 , V_50 ) ;
if ( V_7 )
goto V_60;
return 0 ;
V_60:
F_40 ( V_2 -> V_17 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 + V_105 ; V_6 ++ ) {
F_30 ( V_2 -> V_12 [ V_6 ] ) ;
V_2 -> V_12 [ V_6 ] = NULL ;
}
return V_7 ;
}
static void F_8 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_110 -> V_111 )
return;
if ( F_12 ( V_2 , V_2 -> V_17 ) ) {
F_16 ( L_24 ) ;
F_53 () ;
}
}
