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
V_2 -> V_19 ) ;
if ( V_7 )
return V_7 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_6 , V_7 ;
struct V_22 * V_23 ;
struct V_9 * V_10 ;
F_10 (re, rename_list, list) {
T_1 V_8 ;
struct V_9 * V_24 = V_23 -> V_25 -> V_24 ;
struct V_4 * V_5 = & V_2 -> V_17 [ V_24 -> V_26 ] ;
if ( V_23 -> remove ) {
memcpy ( V_5 , & V_14 ,
sizeof( struct V_4 ) ) ;
continue;
}
V_5 -> V_27 = F_11 ( V_23 -> V_28 ) ;
memcpy ( V_5 -> V_29 , V_23 -> V_30 , V_23 -> V_28 ) ;
memset ( V_5 -> V_29 + V_23 -> V_28 , 0 ,
V_31 + 1 - V_23 -> V_28 ) ;
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
V_2 -> V_19 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_12 ( const struct V_1 * V_2 ,
const struct V_4 * V_17 )
{
int V_6 , V_32 , V_33 , V_34 , V_35 , V_36 , V_27 ;
int V_37 , V_7 ;
T_1 V_8 ;
const char * V_29 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
F_13 () ;
V_33 = F_14 ( V_17 [ V_6 ] . V_33 ) ;
V_34 = F_14 ( V_17 [ V_6 ] . V_34 ) ;
V_35 = F_14 ( V_17 [ V_6 ] . V_35 ) ;
V_37 = V_17 [ V_6 ] . V_37 ;
V_36 = V_17 [ V_6 ] . V_36 ;
V_27 = F_15 ( V_17 [ V_6 ] . V_27 ) ;
V_29 = & V_17 [ V_6 ] . V_29 [ 0 ] ;
V_8 = F_4 ( V_15 , & V_17 [ V_6 ] , V_16 ) ;
if ( F_14 ( V_17 [ V_6 ] . V_8 ) != V_8 ) {
F_16 ( L_1 ,
V_6 , V_8 , F_14 ( V_17 [ V_6 ] . V_8 ) ) ;
F_17 ( & V_17 [ V_6 ] , V_6 ) ;
return 1 ;
}
if ( V_33 == 0 ) {
if ( memcmp ( & V_17 [ V_6 ] , & V_14 ,
V_38 ) ) {
V_7 = 2 ;
goto V_39;
}
continue;
}
if ( V_33 < 0 || V_34 < 0 || V_35 < 0 ||
V_27 < 0 ) {
V_7 = 3 ;
goto V_39;
}
if ( V_34 > V_2 -> V_40 || V_34 == 0 ) {
V_7 = 4 ;
goto V_39;
}
V_32 = V_34 & ( V_2 -> V_41 - 1 ) ;
if ( V_34 != 1 && V_32 ) {
V_7 = 5 ;
goto V_39;
}
V_32 = V_2 -> V_40 % V_34 ;
if ( V_35 != V_32 ) {
F_16 ( L_2 , V_32 ) ;
V_7 = 6 ;
goto V_39;
}
if ( V_36 != V_42 && V_36 != V_43 ) {
V_7 = 7 ;
goto V_39;
}
if ( V_37 != 0 && V_37 != 1 ) {
V_7 = 8 ;
goto V_39;
}
if ( V_33 > V_2 -> V_44 ) {
F_16 ( L_3 ,
V_33 , V_2 -> V_44 ) ;
V_7 = 9 ;
goto V_39;
}
if ( V_27 > V_31 ) {
V_7 = 10 ;
goto V_39;
}
if ( V_29 [ 0 ] == '\0' ) {
V_7 = 11 ;
goto V_39;
}
if ( V_27 != F_18 ( V_29 , V_27 + 1 ) ) {
V_7 = 12 ;
goto V_39;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_11 - 1 ; V_6 ++ ) {
for ( V_32 = V_6 + 1 ; V_32 < V_2 -> V_11 ; V_32 ++ ) {
int V_45 = F_15 ( V_17 [ V_6 ] . V_27 ) ;
int V_46 = F_15 ( V_17 [ V_32 ] . V_27 ) ;
if ( V_45 > 0 && V_45 == V_46 &&
! strncmp ( V_17 [ V_6 ] . V_29 , V_17 [ V_32 ] . V_29 , V_45 ) ) {
F_16 ( L_4 ,
V_6 , V_32 , V_17 [ V_6 ] . V_29 ) ;
F_17 ( & V_17 [ V_6 ] , V_6 ) ;
F_17 ( & V_17 [ V_32 ] , V_32 ) ;
return - V_47 ;
}
}
}
return 0 ;
V_39:
F_16 ( L_5 , V_6 , V_7 ) ;
F_17 ( & V_17 [ V_6 ] , V_6 ) ;
return - V_47 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_50 , void * V_17 )
{
int V_7 , V_51 = 0 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_20 ( L_6 , V_50 + 1 ) ;
V_53 = F_21 ( V_2 , V_56 ) ;
if ( ! V_53 )
return - V_57 ;
V_58:
V_55 = F_22 ( V_2 , V_49 ) ;
if ( F_23 ( V_55 ) ) {
V_7 = F_24 ( V_55 ) ;
goto V_59;
}
V_53 -> V_36 = V_60 ;
V_53 -> V_26 = F_5 ( V_13 ) ;
V_53 -> V_61 = V_62 ;
V_53 -> V_63 = V_53 -> V_64 =
V_53 -> V_35 = F_5 ( 0 ) ;
V_53 -> V_65 = F_5 ( V_50 ) ;
V_53 -> V_66 = F_25 ( ++ V_49 -> V_67 ) ;
V_7 = F_26 ( V_2 , V_55 -> V_68 , V_53 ) ;
if ( V_7 )
goto V_69;
V_7 = F_27 ( V_2 , V_17 , V_55 -> V_68 , 0 , V_2 -> V_19 ) ;
if ( V_7 )
goto V_69;
V_7 = F_28 ( V_2 , V_49 , V_55 -> V_68 , V_55 -> V_70 , V_53 , 0 ) ;
F_29 ( V_49 -> V_71 , V_55 ) ;
F_30 ( V_2 , V_53 ) ;
return V_7 ;
V_69:
if ( V_7 == - V_72 && ++ V_51 <= 5 ) {
F_31 ( & V_55 -> V_73 . V_74 , & V_49 -> V_75 ) ;
goto V_58;
}
F_29 ( V_49 -> V_71 , V_55 ) ;
V_59:
F_30 ( V_2 , V_53 ) ;
return V_7 ;
}
static struct V_4 * F_32 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_76 * V_77 )
{
int V_7 ;
struct V_78 * V_79 ;
struct V_54 * V_80 ;
struct V_4 * V_81 [ V_18 ] = { NULL , NULL } ;
int V_82 [ V_18 ] = { 1 , 1 } ;
F_20 ( L_7 ) ;
F_33 (rb, aeb, &av->root, u.rb) {
V_81 [ V_80 -> V_65 ] = F_34 ( V_2 -> V_19 ) ;
if ( ! V_81 [ V_80 -> V_65 ] ) {
V_7 = - V_57 ;
goto V_59;
}
V_7 = F_35 ( V_2 , V_81 [ V_80 -> V_65 ] , V_80 -> V_68 , 0 ,
V_2 -> V_19 ) ;
if ( V_7 == V_83 || F_36 ( V_7 ) )
V_80 -> V_84 = 1 ;
else if ( V_7 )
goto V_59;
}
V_7 = - V_47 ;
if ( V_81 [ 0 ] ) {
V_82 [ 0 ] = F_12 ( V_2 , V_81 [ 0 ] ) ;
if ( V_82 [ 0 ] < 0 )
goto V_59;
}
if ( ! V_82 [ 0 ] ) {
if ( V_81 [ 1 ] )
V_82 [ 1 ] = memcmp ( V_81 [ 0 ] , V_81 [ 1 ] ,
V_2 -> V_19 ) ;
if ( V_82 [ 1 ] ) {
F_37 ( L_8 ) ;
V_7 = F_19 ( V_2 , V_49 , 1 , V_81 [ 0 ] ) ;
if ( V_7 )
goto V_59;
F_38 ( L_9 ) ;
}
F_39 ( V_81 [ 1 ] ) ;
return V_81 [ 0 ] ;
} else {
if ( V_81 [ 1 ] ) {
V_82 [ 1 ] = F_12 ( V_2 , V_81 [ 1 ] ) ;
if ( V_82 [ 1 ] < 0 )
goto V_59;
}
if ( V_82 [ 1 ] ) {
F_16 ( L_10 ) ;
goto V_59;
}
F_37 ( L_11 ) ;
V_7 = F_19 ( V_2 , V_49 , 0 , V_81 [ 1 ] ) ;
if ( V_7 )
goto V_59;
F_38 ( L_9 ) ;
F_39 ( V_81 [ 0 ] ) ;
return V_81 [ 1 ] ;
}
V_59:
F_39 ( V_81 [ 0 ] ) ;
F_39 ( V_81 [ 1 ] ) ;
return F_40 ( V_7 ) ;
}
static struct V_4 * F_41 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_6 ;
struct V_4 * V_17 ;
V_17 = F_34 ( V_2 -> V_19 ) ;
if ( ! V_17 )
return F_40 ( - V_57 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ )
memcpy ( & V_17 [ V_6 ] , & V_14 , V_38 ) ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
int V_7 ;
V_7 = F_19 ( V_2 , V_49 , V_6 , V_17 ) ;
if ( V_7 ) {
F_39 ( V_17 ) ;
return F_40 ( V_7 ) ;
}
}
return V_17 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_48 * V_49 ,
const struct V_4 * V_17 )
{
int V_6 , V_33 = 0 ;
struct V_76 * V_77 ;
struct V_9 * V_24 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
F_13 () ;
if ( F_14 ( V_17 [ V_6 ] . V_33 ) == 0 )
continue;
V_24 = F_43 ( sizeof( struct V_9 ) , V_56 ) ;
if ( ! V_24 )
return - V_57 ;
V_24 -> V_33 = F_14 ( V_17 [ V_6 ] . V_33 ) ;
V_24 -> V_34 = F_14 ( V_17 [ V_6 ] . V_34 ) ;
V_24 -> V_35 = F_14 ( V_17 [ V_6 ] . V_35 ) ;
V_24 -> V_37 = V_17 [ V_6 ] . V_37 ;
V_24 -> V_36 = V_17 [ V_6 ] . V_36 == V_42 ?
V_85 : V_86 ;
V_24 -> V_27 = F_15 ( V_17 [ V_6 ] . V_27 ) ;
V_24 -> V_87 = V_2 -> V_40 - V_24 -> V_35 ;
memcpy ( V_24 -> V_29 , V_17 [ V_6 ] . V_29 , V_24 -> V_27 ) ;
V_24 -> V_29 [ V_24 -> V_27 ] = '\0' ;
V_24 -> V_26 = V_6 ;
if ( V_17 [ V_6 ] . V_88 & V_89 ) {
if ( V_2 -> V_90 != - 1 ) {
F_16 ( L_12 ,
V_2 -> V_90 , V_6 ) ;
F_44 ( V_24 ) ;
return - V_47 ;
}
V_2 -> V_90 = V_6 ;
}
F_2 ( ! V_2 -> V_12 [ V_6 ] ) ;
V_2 -> V_12 [ V_6 ] = V_24 ;
V_2 -> V_91 += 1 ;
V_24 -> V_2 = V_2 ;
V_33 += V_24 -> V_33 ;
if ( V_24 -> V_36 == V_85 ) {
V_24 -> V_64 = V_24 -> V_33 ;
V_24 -> V_92 = V_24 -> V_87 ;
V_24 -> V_93 =
( long long ) V_24 -> V_64 * V_24 -> V_87 ;
continue;
}
V_77 = F_45 ( V_49 , V_6 ) ;
if ( ! V_77 || ! V_77 -> V_94 ) {
continue;
}
if ( V_77 -> V_94 != V_77 -> V_64 ) {
F_37 ( L_13 ,
V_77 -> V_26 , V_77 -> V_64 - V_77 -> V_94 ) ;
V_24 -> V_95 = 1 ;
continue;
}
V_24 -> V_64 = V_77 -> V_64 ;
V_24 -> V_93 =
( long long ) ( V_24 -> V_64 - 1 ) * V_24 -> V_87 ;
V_24 -> V_93 += V_77 -> V_96 ;
V_24 -> V_92 = V_77 -> V_96 ;
}
V_24 = F_43 ( sizeof( struct V_9 ) , V_56 ) ;
if ( ! V_24 )
return - V_57 ;
V_24 -> V_33 = V_18 ;
V_24 -> V_34 = V_97 ;
V_24 -> V_36 = V_85 ;
V_24 -> V_27 = sizeof( V_98 ) - 1 ;
memcpy ( V_24 -> V_29 , V_98 , V_24 -> V_27 + 1 ) ;
V_24 -> V_87 = V_2 -> V_40 ;
V_24 -> V_64 = V_24 -> V_33 ;
V_24 -> V_92 = V_24 -> V_33 ;
V_24 -> V_93 =
( long long ) V_24 -> V_64 * ( V_2 -> V_40 - V_24 -> V_35 ) ;
V_24 -> V_26 = V_13 ;
V_24 -> V_99 = 1 ;
F_2 ( ! V_2 -> V_12 [ V_6 ] ) ;
V_2 -> V_12 [ F_3 ( V_2 , V_24 -> V_26 ) ] = V_24 ;
V_33 += V_24 -> V_33 ;
V_2 -> V_91 += 1 ;
V_24 -> V_2 = V_2 ;
if ( V_33 > V_2 -> V_100 ) {
F_16 ( L_14 ,
V_33 , V_2 -> V_100 ) ;
if ( V_2 -> V_101 )
F_16 ( L_15 ,
V_2 -> V_101 ) ;
}
V_2 -> V_102 += V_33 ;
V_2 -> V_100 -= V_33 ;
return 0 ;
}
static int F_46 ( const struct V_9 * V_24 ,
const struct V_76 * V_77 )
{
int V_7 ;
if ( V_77 -> V_103 >= V_24 -> V_33 ) {
V_7 = 1 ;
goto V_39;
}
if ( V_77 -> V_94 > V_24 -> V_33 ) {
V_7 = 2 ;
goto V_39;
}
if ( V_77 -> V_36 != V_24 -> V_36 ) {
V_7 = 3 ;
goto V_39;
}
if ( V_77 -> V_64 > V_24 -> V_33 ) {
V_7 = 4 ;
goto V_39;
}
if ( V_77 -> V_35 != V_24 -> V_35 ) {
V_7 = 5 ;
goto V_39;
}
return 0 ;
V_39:
F_16 ( L_16 , V_7 ) ;
F_47 ( V_77 ) ;
F_48 ( V_24 ) ;
return - V_47 ;
}
static int F_49 ( const struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_7 , V_6 ;
struct V_76 * V_77 ;
struct V_9 * V_24 ;
if ( V_49 -> V_104 > V_105 + V_2 -> V_11 ) {
F_16 ( L_17 ,
V_49 -> V_104 , V_105 , V_2 -> V_11 ) ;
return - V_47 ;
}
if ( V_49 -> V_106 >= V_2 -> V_11 + V_105 &&
V_49 -> V_106 < V_107 ) {
F_16 ( L_18 , V_49 -> V_106 ) ;
return - V_47 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_11 + V_105 ; V_6 ++ ) {
F_13 () ;
V_77 = F_45 ( V_49 , V_6 ) ;
V_24 = V_2 -> V_12 [ V_6 ] ;
if ( ! V_24 ) {
if ( V_77 )
F_50 ( V_49 , V_77 ) ;
continue;
}
if ( V_24 -> V_33 == 0 ) {
F_2 ( V_6 < V_2 -> V_11 ) ;
if ( ! V_77 )
continue;
F_38 ( L_19 , V_77 -> V_26 ) ;
F_50 ( V_49 , V_77 ) ;
} else if ( V_77 ) {
V_7 = F_46 ( V_24 , V_77 ) ;
if ( V_7 )
return V_7 ;
}
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
int V_6 , V_7 ;
struct V_76 * V_77 ;
V_14 . V_8 = F_5 ( 0xf116c36b ) ;
V_2 -> V_11 = V_2 -> V_40 / V_38 ;
if ( V_2 -> V_11 > V_108 )
V_2 -> V_11 = V_108 ;
V_2 -> V_19 = V_2 -> V_11 * V_38 ;
V_2 -> V_19 = F_52 ( V_2 -> V_19 , V_2 -> V_41 ) ;
V_77 = F_45 ( V_49 , V_13 ) ;
if ( ! V_77 ) {
if ( V_49 -> V_109 ) {
V_2 -> V_17 = F_41 ( V_2 , V_49 ) ;
if ( F_23 ( V_2 -> V_17 ) )
return F_24 ( V_2 -> V_17 ) ;
} else {
F_16 ( L_20 ) ;
return - V_47 ;
}
} else {
if ( V_77 -> V_94 > V_18 ) {
F_16 ( L_21 ,
V_77 -> V_94 ) ;
return - V_47 ;
}
V_2 -> V_17 = F_32 ( V_2 , V_49 , V_77 ) ;
if ( F_23 ( V_2 -> V_17 ) )
return F_24 ( V_2 -> V_17 ) ;
}
V_2 -> V_100 = V_2 -> V_44 - V_2 -> V_101 ;
V_7 = F_42 ( V_2 , V_49 , V_2 -> V_17 ) ;
if ( V_7 )
goto V_59;
V_7 = F_49 ( V_2 , V_49 ) ;
if ( V_7 )
goto V_59;
return 0 ;
V_59:
F_39 ( V_2 -> V_17 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 + V_105 ; V_6 ++ ) {
F_44 ( V_2 -> V_12 [ V_6 ] ) ;
V_2 -> V_12 [ V_6 ] = NULL ;
}
return V_7 ;
}
static void F_8 ( const struct V_1 * V_2 )
{
if ( ! F_53 ( V_2 ) )
return;
if ( F_12 ( V_2 , V_2 -> V_17 ) ) {
F_16 ( L_22 ) ;
F_54 () ;
}
}
