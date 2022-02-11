static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , int V_6 , T_1 V_7 ,
T_1 V_8 , int V_9 )
{
struct V_10 * V_11 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_11 -> V_3 = V_3 ;
if ( V_5 )
V_11 -> V_5 = * V_5 ;
else
memset ( & V_11 -> V_5 , 0 , sizeof( V_11 -> V_5 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_8 = V_8 ;
F_3 ( & V_11 -> V_14 , V_2 ) ;
return 0 ;
}
static int F_4 ( struct V_15 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_21 * V_22 , int V_6 ,
T_1 V_23 , T_1 V_8 )
{
int V_24 ;
int V_25 ;
struct V_26 * V_27 ;
struct V_4 V_5 ;
T_1 V_28 ;
V_29:
V_24 = F_5 ( V_20 , V_22 -> V_30 , 0 , V_31 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_6 != 0 )
return 0 ;
while ( 1 ) {
V_24 = F_6 ( V_16 , V_18 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 )
return 0 ;
V_22 = V_18 -> V_32 [ 0 ] ;
for ( V_25 = 0 ; V_25 < F_7 ( V_22 ) ; ++ V_25 ) {
F_8 ( V_22 , & V_5 , V_25 ) ;
if ( V_5 . V_33 != V_23 ||
V_5 . type != V_34 )
return 0 ;
V_27 = F_9 ( V_22 , V_25 ,
struct V_26 ) ;
V_28 = F_10 ( V_22 , V_27 ) ;
if ( V_28 == V_8 )
goto V_29;
}
}
return 0 ;
}
static int F_11 ( struct V_35 * V_36 ,
int V_37 ,
struct V_10 * V_11 ,
struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
struct V_4 V_38 ;
struct V_4 V_5 = { 0 } ;
struct V_21 * V_22 ;
int V_24 = 0 ;
int V_39 ;
int V_6 = V_11 -> V_6 ;
V_18 = F_12 () ;
if ( ! V_18 )
return - V_13 ;
V_18 -> V_37 = ! ! V_37 ;
V_38 . V_33 = V_11 -> V_3 ;
V_38 . type = V_40 ;
V_38 . V_41 = ( T_1 ) - 1 ;
V_16 = F_13 ( V_36 , & V_38 ) ;
if ( F_14 ( V_16 ) ) {
V_24 = F_15 ( V_16 ) ;
goto V_42;
}
F_16 () ;
V_39 = F_17 ( V_16 -> V_43 ) ;
F_18 () ;
if ( V_39 + 1 == V_6 )
goto V_42;
V_18 -> V_44 = V_6 ;
V_24 = F_19 ( NULL , V_16 , & V_11 -> V_5 , V_18 , 0 , 0 ) ;
F_20 ( L_1
L_2 ,
( unsigned long long ) V_11 -> V_3 , V_6 , V_11 -> V_9 , V_24 ,
( unsigned long long ) V_11 -> V_5 . V_33 , V_11 -> V_5 . type ,
( unsigned long long ) V_11 -> V_5 . V_41 ) ;
if ( V_24 < 0 )
goto V_42;
V_22 = V_18 -> V_32 [ V_6 ] ;
if ( ! V_22 ) {
F_21 ( 1 ) ;
V_24 = 1 ;
goto V_42;
}
if ( V_6 == 0 ) {
if ( V_24 == 1 && V_18 -> V_45 [ 0 ] >= F_7 ( V_22 ) ) {
V_24 = F_6 ( V_16 , V_18 ) ;
if ( V_24 )
goto V_42;
V_22 = V_18 -> V_32 [ 0 ] ;
}
F_8 ( V_22 , & V_5 , V_18 -> V_45 [ 0 ] ) ;
}
V_24 = F_4 ( V_16 , V_18 , V_20 , V_22 , V_6 , V_5 . V_33 ,
V_11 -> V_8 ) ;
V_42:
F_22 ( V_18 ) ;
return V_24 ;
}
static int F_23 ( struct V_35 * V_36 ,
int V_37 ,
struct V_1 * V_2 )
{
int V_46 ;
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_10 * V_47 ;
struct V_10 * V_48 ;
struct V_19 * V_20 ;
struct V_49 * V_43 ;
V_20 = F_24 ( V_31 ) ;
if ( ! V_20 )
return - V_13 ;
F_25 (ref, ref_safe, head, list) {
if ( V_11 -> V_7 )
continue;
if ( V_11 -> V_9 == 0 )
continue;
V_46 = F_11 ( V_36 , V_37 ,
V_11 , V_20 ) ;
if ( V_46 ) {
if ( V_24 == 0 )
V_24 = V_46 ;
continue;
}
V_43 = F_26 ( V_20 , NULL ) ;
V_11 -> V_7 = V_43 ? V_43 -> V_50 : 0 ;
while ( ( V_43 = F_26 ( V_20 , V_43 ) ) ) {
V_48 = F_2 ( sizeof( * V_48 ) , V_31 ) ;
if ( ! V_48 ) {
V_24 = - V_13 ;
break;
}
memcpy ( V_48 , V_11 , sizeof( * V_11 ) ) ;
V_48 -> V_7 = V_43 -> V_50 ;
F_27 ( & V_48 -> V_14 , & V_11 -> V_14 ) ;
}
F_28 ( V_20 ) ;
}
F_29 ( V_20 ) ;
return V_24 ;
}
static int F_30 ( struct V_1 * V_2 , int V_51 )
{
struct V_1 * V_52 ;
F_31 (pos1, head) {
struct V_1 * V_53 ;
struct V_1 * V_54 ;
struct V_10 * V_55 ;
V_55 = F_32 ( V_52 , struct V_10 , V_14 ) ;
if ( V_51 == 1 && V_55 -> V_5 . type == 0 )
continue;
for ( V_54 = V_52 -> V_56 , V_53 = V_54 -> V_56 ; V_54 != V_2 ;
V_54 = V_53 , V_53 = V_54 -> V_56 ) {
struct V_10 * V_57 ;
V_57 = F_32 ( V_54 , struct V_10 , V_14 ) ;
if ( V_51 == 1 ) {
if ( memcmp ( & V_55 -> V_5 , & V_57 -> V_5 ,
sizeof( V_55 -> V_5 ) ) ||
V_55 -> V_6 != V_57 -> V_6 ||
V_55 -> V_3 != V_57 -> V_3 )
continue;
V_55 -> V_9 += V_57 -> V_9 ;
} else {
if ( V_55 -> V_7 != V_57 -> V_7 )
continue;
V_55 -> V_9 += V_57 -> V_9 ;
}
F_33 ( & V_57 -> V_14 ) ;
F_34 ( V_57 ) ;
}
}
return 0 ;
}
static int F_35 ( struct V_58 * V_2 , T_1 V_59 ,
struct V_4 * V_60 ,
struct V_1 * V_61 )
{
struct V_62 * V_63 = V_2 -> V_63 ;
struct V_64 * V_65 = & V_2 -> V_43 . V_64 ;
int V_66 ;
int V_24 = 0 ;
if ( V_63 && V_63 -> V_67 )
F_36 ( V_60 , & V_63 -> V_5 ) ;
while ( ( V_65 = F_37 ( V_65 ) ) ) {
struct V_68 * V_43 ;
V_43 = F_38 ( V_65 , struct V_68 ,
V_64 ) ;
if ( V_43 -> V_69 != V_2 -> V_43 . V_69 )
break;
F_21 ( V_43 -> V_70 ) ;
if ( V_43 -> V_59 > V_59 )
continue;
switch ( V_43 -> V_71 ) {
case V_72 :
case V_73 :
F_21 ( 1 ) ;
continue;
case V_74 :
V_66 = 1 ;
break;
case V_75 :
V_66 = - 1 ;
break;
default:
F_39 ( 1 ) ;
}
switch ( V_43 -> type ) {
case V_76 : {
struct V_77 * V_11 ;
V_11 = F_40 ( V_43 ) ;
V_24 = F_1 ( V_61 , V_11 -> V_16 , V_60 ,
V_11 -> V_6 + 1 , 0 , V_43 -> V_69 ,
V_43 -> V_78 * V_66 ) ;
break;
}
case V_79 : {
struct V_77 * V_11 ;
V_11 = F_40 ( V_43 ) ;
V_24 = F_1 ( V_61 , V_11 -> V_16 , V_60 ,
V_11 -> V_6 + 1 , V_11 -> V_7 ,
V_43 -> V_69 ,
V_43 -> V_78 * V_66 ) ;
break;
}
case V_80 : {
struct V_81 * V_11 ;
struct V_4 V_5 ;
V_11 = F_41 ( V_43 ) ;
V_5 . V_33 = V_11 -> V_33 ;
V_5 . type = V_34 ;
V_5 . V_41 = V_11 -> V_41 ;
V_24 = F_1 ( V_61 , V_11 -> V_16 , & V_5 , 0 , 0 ,
V_43 -> V_69 ,
V_43 -> V_78 * V_66 ) ;
break;
}
case V_82 : {
struct V_81 * V_11 ;
struct V_4 V_5 ;
V_11 = F_41 ( V_43 ) ;
V_5 . V_33 = V_11 -> V_33 ;
V_5 . type = V_34 ;
V_5 . V_41 = V_11 -> V_41 ;
V_24 = F_1 ( V_61 , V_11 -> V_16 , & V_5 , 0 ,
V_11 -> V_7 , V_43 -> V_69 ,
V_43 -> V_78 * V_66 ) ;
break;
}
default:
F_21 ( 1 ) ;
}
F_39 ( V_24 ) ;
}
return 0 ;
}
static int F_42 ( struct V_35 * V_36 ,
struct V_17 * V_18 , T_1 V_69 ,
struct V_4 * V_60 , int * V_83 ,
struct V_1 * V_61 )
{
int V_24 = 0 ;
int V_25 ;
struct V_21 * V_84 ;
struct V_4 V_5 ;
unsigned long V_85 ;
unsigned long V_86 ;
struct V_87 * V_88 ;
T_1 V_89 ;
T_1 V_90 ;
V_84 = V_18 -> V_32 [ 0 ] ;
V_25 = V_18 -> V_45 [ 0 ] - 1 ;
V_90 = F_43 ( V_84 , V_25 ) ;
F_39 ( V_90 < sizeof( * V_88 ) ) ;
V_88 = F_9 ( V_84 , V_25 , struct V_87 ) ;
V_89 = F_44 ( V_84 , V_88 ) ;
V_85 = ( unsigned long ) ( V_88 + 1 ) ;
V_86 = ( unsigned long ) V_88 + V_90 ;
if ( V_89 & V_91 ) {
struct V_92 * V_93 ;
struct V_94 V_95 ;
V_93 = (struct V_92 * ) V_85 ;
* V_83 = F_45 ( V_84 , V_93 ) ;
F_46 ( V_84 , V_93 , & V_95 ) ;
F_36 ( V_60 , & V_95 ) ;
V_85 += sizeof( struct V_92 ) ;
F_39 ( V_85 > V_86 ) ;
} else {
F_39 ( ! ( V_89 & V_96 ) ) ;
}
while ( V_85 < V_86 ) {
struct V_97 * V_98 ;
T_1 V_41 ;
int type ;
V_98 = (struct V_97 * ) V_85 ;
type = F_47 ( V_84 , V_98 ) ;
V_41 = F_48 ( V_84 , V_98 ) ;
switch ( type ) {
case V_79 :
V_24 = F_1 ( V_61 , 0 , V_60 ,
* V_83 + 1 , V_41 ,
V_69 , 1 ) ;
break;
case V_82 : {
struct V_99 * V_100 ;
int V_9 ;
V_100 = (struct V_99 * ) ( V_98 + 1 ) ;
V_9 = F_49 ( V_84 , V_100 ) ;
V_24 = F_1 ( V_61 , 0 , NULL , 0 , V_41 ,
V_69 , V_9 ) ;
break;
}
case V_76 :
V_24 = F_1 ( V_61 , V_41 , V_60 ,
* V_83 + 1 , 0 , V_69 , 1 ) ;
break;
case V_80 : {
struct V_101 * V_102 ;
int V_9 ;
T_1 V_16 ;
V_102 = (struct V_101 * ) ( & V_98 -> V_41 ) ;
V_9 = F_50 ( V_84 , V_102 ) ;
V_5 . V_33 = F_51 ( V_84 ,
V_102 ) ;
V_5 . type = V_34 ;
V_5 . V_41 = F_52 ( V_84 , V_102 ) ;
V_16 = F_53 ( V_84 , V_102 ) ;
V_24 = F_1 ( V_61 , V_16 , & V_5 , 0 , 0 , V_69 ,
V_9 ) ;
break;
}
default:
F_21 ( 1 ) ;
}
F_39 ( V_24 ) ;
V_85 += F_54 ( type ) ;
}
return 0 ;
}
static int F_55 ( struct V_35 * V_36 ,
struct V_17 * V_18 , T_1 V_69 ,
struct V_4 * V_60 , int V_83 ,
struct V_1 * V_61 )
{
struct V_15 * V_103 = V_36 -> V_103 ;
int V_24 ;
int V_25 ;
struct V_21 * V_84 ;
struct V_4 V_5 ;
while ( 1 ) {
V_24 = F_56 ( V_103 , V_18 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_25 = V_18 -> V_45 [ 0 ] ;
V_84 = V_18 -> V_32 [ 0 ] ;
F_8 ( V_84 , & V_5 , V_25 ) ;
if ( V_5 . V_33 != V_69 )
break;
if ( V_5 . type < V_76 )
continue;
if ( V_5 . type > V_82 )
break;
switch ( V_5 . type ) {
case V_79 :
V_24 = F_1 ( V_61 , 0 , V_60 ,
V_83 + 1 , V_5 . V_41 ,
V_69 , 1 ) ;
break;
case V_82 : {
struct V_99 * V_100 ;
int V_9 ;
V_100 = F_9 ( V_84 , V_25 ,
struct V_99 ) ;
V_9 = F_49 ( V_84 , V_100 ) ;
V_24 = F_1 ( V_61 , 0 , NULL , 0 , V_5 . V_41 ,
V_69 , V_9 ) ;
break;
}
case V_76 :
V_24 = F_1 ( V_61 , V_5 . V_41 , V_60 ,
V_83 + 1 , 0 , V_69 , 1 ) ;
break;
case V_80 : {
struct V_101 * V_102 ;
int V_9 ;
T_1 V_16 ;
V_102 = F_9 ( V_84 , V_25 ,
struct V_101 ) ;
V_9 = F_50 ( V_84 , V_102 ) ;
V_5 . V_33 = F_51 ( V_84 ,
V_102 ) ;
V_5 . type = V_34 ;
V_5 . V_41 = F_52 ( V_84 , V_102 ) ;
V_16 = F_53 ( V_84 , V_102 ) ;
V_24 = F_1 ( V_61 , V_16 , & V_5 , 0 , 0 ,
V_69 , V_9 ) ;
break;
}
default:
F_21 ( 1 ) ;
}
F_39 ( V_24 ) ;
}
return V_24 ;
}
static int F_57 ( struct V_104 * V_105 ,
struct V_35 * V_36 , T_1 V_69 ,
T_1 V_59 , struct V_19 * V_106 , struct V_19 * V_107 )
{
struct V_4 V_5 ;
struct V_17 * V_18 ;
struct V_4 V_60 = { 0 } ;
struct V_108 * V_109 = NULL ;
struct V_58 * V_2 ;
int V_83 = 0 ;
int V_24 ;
int V_37 = ( V_105 == V_110 ) ;
struct V_1 V_111 ;
struct V_1 V_61 ;
struct V_10 * V_11 ;
F_58 ( & V_61 ) ;
F_58 ( & V_111 ) ;
V_5 . V_33 = V_69 ;
V_5 . type = V_112 ;
V_5 . V_41 = ( T_1 ) - 1 ;
V_18 = F_12 () ;
if ( ! V_18 )
return - V_13 ;
V_18 -> V_37 = ! ! V_37 ;
V_113:
V_2 = NULL ;
V_24 = F_19 ( V_105 , V_36 -> V_103 , & V_5 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_42;
F_39 ( V_24 == 0 ) ;
if ( V_105 != V_110 ) {
V_109 = & V_105 -> V_114 -> V_109 ;
F_59 ( & V_109 -> V_115 ) ;
V_2 = F_60 ( V_105 , V_69 ) ;
if ( V_2 ) {
if ( ! F_61 ( & V_2 -> V_116 ) ) {
F_62 ( & V_2 -> V_43 . V_106 ) ;
F_63 ( & V_109 -> V_115 ) ;
F_64 ( V_18 ) ;
F_65 ( & V_2 -> V_116 ) ;
F_66 ( & V_2 -> V_116 ) ;
F_67 ( & V_2 -> V_43 ) ;
goto V_113;
}
V_24 = F_35 ( V_2 , V_59 , & V_60 ,
& V_111 ) ;
if ( V_24 ) {
F_63 ( & V_109 -> V_115 ) ;
goto V_42;
}
}
F_63 ( & V_109 -> V_115 ) ;
}
if ( V_18 -> V_45 [ 0 ] ) {
struct V_21 * V_84 ;
int V_25 ;
V_84 = V_18 -> V_32 [ 0 ] ;
V_25 = V_18 -> V_45 [ 0 ] - 1 ;
F_8 ( V_84 , & V_5 , V_25 ) ;
if ( V_5 . V_33 == V_69 &&
V_5 . type == V_112 ) {
V_24 = F_42 ( V_36 , V_18 , V_69 ,
& V_60 , & V_83 , & V_61 ) ;
if ( V_24 )
goto V_42;
V_24 = F_55 ( V_36 , V_18 , V_69 , & V_60 ,
V_83 , & V_61 ) ;
if ( V_24 )
goto V_42;
}
}
F_64 ( V_18 ) ;
F_68 (ref, &prefs_delayed, list) {
if ( ( V_11 -> V_5 . V_41 | V_11 -> V_5 . type | V_11 -> V_5 . V_33 ) == 0 )
memcpy ( & V_11 -> V_5 , & V_60 , sizeof( V_11 -> V_5 ) ) ;
}
F_69 ( & V_111 , & V_61 ) ;
V_24 = F_30 ( & V_61 , 1 ) ;
if ( V_24 )
goto V_42;
V_24 = F_23 ( V_36 , V_37 , & V_61 ) ;
if ( V_24 )
goto V_42;
V_24 = F_30 ( & V_61 , 2 ) ;
if ( V_24 )
goto V_42;
while ( ! F_70 ( & V_61 ) ) {
V_11 = F_71 ( & V_61 , struct V_10 , V_14 ) ;
F_33 ( & V_11 -> V_14 ) ;
if ( V_11 -> V_9 < 0 )
F_21 ( 1 ) ;
if ( V_11 -> V_9 && V_11 -> V_3 && V_11 -> V_7 == 0 ) {
V_24 = F_5 ( V_107 , V_11 -> V_3 , 0 , V_31 ) ;
F_39 ( V_24 < 0 ) ;
}
if ( V_11 -> V_9 && V_11 -> V_7 ) {
V_24 = F_5 ( V_106 , V_11 -> V_7 , 0 , V_31 ) ;
F_39 ( V_24 < 0 ) ;
}
F_34 ( V_11 ) ;
}
V_42:
if ( V_2 )
F_66 ( & V_2 -> V_116 ) ;
F_22 ( V_18 ) ;
while ( ! F_70 ( & V_61 ) ) {
V_11 = F_71 ( & V_61 , struct V_10 , V_14 ) ;
F_33 ( & V_11 -> V_14 ) ;
F_34 ( V_11 ) ;
}
while ( ! F_70 ( & V_111 ) ) {
V_11 = F_71 ( & V_111 , struct V_10 ,
V_14 ) ;
F_33 ( & V_11 -> V_14 ) ;
F_34 ( V_11 ) ;
}
return V_24 ;
}
static int F_72 ( struct V_104 * V_105 ,
struct V_35 * V_36 , T_1 V_69 ,
T_1 V_117 , T_1 V_59 , struct V_19 * * V_118 )
{
struct V_19 * V_119 ;
int V_24 ;
V_119 = F_24 ( V_31 ) ;
if ( ! V_119 )
return - V_13 ;
* V_118 = F_24 ( V_31 ) ;
if ( ! * V_118 ) {
F_29 ( V_119 ) ;
return - V_13 ;
}
V_24 = F_57 ( V_105 , V_36 , V_69 , V_59 , * V_118 , V_119 ) ;
F_29 ( V_119 ) ;
if ( V_24 < 0 && V_24 != - V_120 ) {
F_29 ( * V_118 ) ;
return V_24 ;
}
return 0 ;
}
int F_73 ( struct V_104 * V_105 ,
struct V_35 * V_36 , T_1 V_69 ,
T_1 V_117 , T_1 V_59 , struct V_19 * * V_107 )
{
struct V_19 * V_119 ;
struct V_49 * V_43 = NULL ;
int V_24 ;
V_119 = F_24 ( V_31 ) ;
if ( ! V_119 )
return - V_13 ;
* V_107 = F_24 ( V_31 ) ;
if ( ! * V_107 ) {
F_29 ( V_119 ) ;
return - V_13 ;
}
while ( 1 ) {
V_24 = F_57 ( V_105 , V_36 , V_69 , V_59 ,
V_119 , * V_107 ) ;
if ( V_24 < 0 && V_24 != - V_120 ) {
F_29 ( V_119 ) ;
F_29 ( * V_107 ) ;
return V_24 ;
}
V_43 = F_26 ( V_119 , V_43 ) ;
if ( ! V_43 )
break;
V_69 = V_43 -> V_50 ;
}
F_29 ( V_119 ) ;
return 0 ;
}
static int F_74 ( T_1 V_121 , T_1 V_122 , T_2 V_123 ,
struct V_15 * V_124 , struct V_17 * V_18 ,
struct V_4 * V_125 )
{
int V_24 ;
struct V_4 V_5 ;
struct V_21 * V_22 ;
V_5 . type = V_123 ;
V_5 . V_33 = V_121 ;
V_5 . V_41 = V_122 ;
V_24 = F_19 ( NULL , V_124 , & V_5 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_22 = V_18 -> V_32 [ 0 ] ;
if ( V_24 && V_18 -> V_45 [ 0 ] >= F_7 ( V_22 ) ) {
V_24 = F_6 ( V_124 , V_18 ) ;
if ( V_24 )
return V_24 ;
V_22 = V_18 -> V_32 [ 0 ] ;
}
F_8 ( V_22 , V_125 , V_18 -> V_45 [ 0 ] ) ;
if ( V_125 -> type != V_5 . type || V_125 -> V_33 != V_5 . V_33 )
return 1 ;
return 0 ;
}
int F_75 ( T_1 V_121 , T_1 V_122 , struct V_15 * V_124 ,
struct V_17 * V_18 )
{
struct V_4 V_5 ;
return F_74 ( V_121 , V_122 , V_126 , V_124 , V_18 ,
& V_5 ) ;
}
static int F_76 ( T_1 V_121 , T_1 V_122 , struct V_15 * V_124 ,
struct V_17 * V_18 ,
struct V_4 * V_125 )
{
return F_74 ( V_121 , V_122 , V_127 , V_124 , V_18 ,
V_125 ) ;
}
static char * F_77 ( struct V_15 * V_124 , struct V_17 * V_18 ,
struct V_128 * V_98 ,
struct V_21 * V_129 , T_1 V_7 ,
char * V_130 , T_3 V_131 )
{
T_3 V_132 ;
int V_25 ;
T_1 V_133 ;
int V_24 ;
T_4 V_134 = V_131 - 1 ;
struct V_21 * V_22 = V_129 ;
struct V_4 V_125 ;
int V_135 = V_18 -> V_135 ;
if ( V_134 >= 0 )
V_130 [ V_134 ] = '\0' ;
V_18 -> V_135 = 1 ;
while ( 1 ) {
V_132 = F_78 ( V_22 , V_98 ) ;
V_134 -= V_132 ;
if ( V_134 >= 0 )
F_79 ( V_22 , V_130 + V_134 ,
( unsigned long ) ( V_98 + 1 ) , V_132 ) ;
if ( V_22 != V_129 ) {
F_80 ( V_22 ) ;
F_81 ( V_22 ) ;
}
V_24 = F_76 ( V_7 , 0 , V_124 , V_18 , & V_125 ) ;
if ( V_24 > 0 )
V_24 = - V_120 ;
if ( V_24 )
break;
V_133 = V_125 . V_41 ;
if ( V_7 == V_133 )
break;
V_25 = V_18 -> V_45 [ 0 ] ;
V_22 = V_18 -> V_32 [ 0 ] ;
if ( V_22 != V_129 ) {
F_62 ( & V_22 -> V_106 ) ;
F_82 ( V_22 ) ;
F_83 ( V_22 , V_136 ) ;
}
F_64 ( V_18 ) ;
V_98 = F_9 ( V_22 , V_25 , struct V_128 ) ;
V_7 = V_133 ;
-- V_134 ;
if ( V_134 >= 0 )
V_130 [ V_134 ] = '/' ;
}
F_64 ( V_18 ) ;
V_18 -> V_135 = V_135 ;
if ( V_24 )
return F_84 ( V_24 ) ;
return V_130 + V_134 ;
}
int F_85 ( struct V_35 * V_36 , T_1 V_137 ,
struct V_17 * V_18 , struct V_4 * V_125 )
{
int V_24 ;
T_1 V_89 ;
T_3 V_90 ;
struct V_21 * V_22 ;
struct V_87 * V_88 ;
struct V_4 V_5 ;
V_5 . type = V_112 ;
V_5 . V_33 = V_137 ;
V_5 . V_41 = ( T_1 ) - 1 ;
V_24 = F_19 ( NULL , V_36 -> V_103 , & V_5 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_86 ( V_36 -> V_103 , V_18 ,
0 , V_112 ) ;
if ( V_24 < 0 )
return V_24 ;
F_8 ( V_18 -> V_32 [ 0 ] , V_125 , V_18 -> V_45 [ 0 ] ) ;
if ( V_125 -> type != V_112 ||
V_125 -> V_33 > V_137 ||
V_125 -> V_33 + V_125 -> V_41 <= V_137 ) {
F_20 ( L_3 ,
( unsigned long long ) V_137 ) ;
return - V_120 ;
}
V_22 = V_18 -> V_32 [ 0 ] ;
V_90 = F_43 ( V_22 , V_18 -> V_45 [ 0 ] ) ;
F_39 ( V_90 < sizeof( * V_88 ) ) ;
V_88 = F_9 ( V_22 , V_18 -> V_45 [ 0 ] , struct V_87 ) ;
V_89 = F_44 ( V_22 , V_88 ) ;
F_20 ( L_4
L_5 ,
( unsigned long long ) V_137 ,
( unsigned long long ) ( V_137 - V_125 -> V_33 ) ,
( unsigned long long ) V_125 -> V_33 ,
( unsigned long long ) V_125 -> V_41 ,
( unsigned long long ) V_89 , V_90 ) ;
if ( V_89 & V_91 )
return V_91 ;
if ( V_89 & V_96 )
return V_96 ;
return - V_138 ;
}
static int F_87 ( unsigned long * V_85 , struct V_21 * V_22 ,
struct V_87 * V_88 , T_3 V_90 ,
struct V_97 * * V_139 ,
int * V_140 )
{
unsigned long V_86 ;
T_1 V_89 ;
struct V_92 * V_93 ;
if ( ! * V_85 ) {
V_89 = F_44 ( V_22 , V_88 ) ;
if ( V_89 & V_91 ) {
V_93 = (struct V_92 * ) ( V_88 + 1 ) ;
* V_139 =
(struct V_97 * ) ( V_93 + 1 ) ;
} else {
* V_139 = (struct V_97 * ) ( V_88 + 1 ) ;
}
* V_85 = ( unsigned long ) * V_139 ;
if ( ( void * ) * V_85 >= ( void * ) V_88 + V_90 )
return - V_120 ;
}
V_86 = ( unsigned long ) V_88 + V_90 ;
* V_139 = (struct V_97 * ) * V_85 ;
* V_140 = F_47 ( V_22 , * V_139 ) ;
* V_85 += F_54 ( * V_140 ) ;
F_21 ( * V_85 > V_86 ) ;
if ( * V_85 == V_86 )
return 1 ;
return 0 ;
}
int F_88 ( unsigned long * V_85 , struct V_21 * V_22 ,
struct V_87 * V_88 , T_3 V_90 ,
T_1 * V_141 , T_2 * V_142 )
{
int V_24 ;
int type ;
struct V_92 * V_93 ;
struct V_97 * V_143 ;
if ( * V_85 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_87 ( V_85 , V_22 , V_88 , V_90 ,
& V_143 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_76 ||
type == V_79 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_93 = (struct V_92 * ) ( V_88 + 1 ) ;
* V_141 = F_48 ( V_22 , V_143 ) ;
* V_142 = F_45 ( V_22 , V_93 ) ;
if ( V_24 == 1 )
* V_85 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_89 ( struct V_35 * V_36 , T_1 V_137 ,
T_1 V_144 ,
T_1 V_145 , T_1 V_16 ,
T_5 * V_146 , void * V_147 )
{
T_1 V_28 ;
struct V_4 V_5 ;
struct V_26 * V_27 ;
struct V_21 * V_22 ;
int V_25 ;
int V_148 ;
int V_24 = 0 ;
int V_149 ;
T_1 V_150 ;
T_1 V_151 ;
V_22 = F_90 ( V_36 -> V_152 , V_137 ,
V_36 -> V_152 -> V_153 , 0 ) ;
if ( ! V_22 )
return - V_138 ;
V_148 = F_7 ( V_22 ) ;
for ( V_25 = 0 ; V_25 < V_148 ; ++ V_25 ) {
F_8 ( V_22 , & V_5 , V_25 ) ;
if ( V_5 . type != V_34 )
continue;
V_27 = F_9 ( V_22 , V_25 , struct V_26 ) ;
V_149 = F_91 ( V_22 , V_27 ) ;
if ( V_149 == V_154 )
continue;
V_28 = F_10 ( V_22 , V_27 ) ;
if ( V_28 != V_144 )
continue;
V_150 = F_92 ( V_22 , V_27 ) ;
V_151 = F_93 ( V_22 , V_27 ) ;
if ( V_145 < V_150 ||
V_145 >= V_150 + V_151 )
continue;
F_20 ( L_6
L_7 , V_144 ,
V_5 . V_33 , V_5 . V_41 , V_16 ) ;
V_24 = V_146 ( V_5 . V_33 ,
V_5 . V_41 + ( V_145 - V_150 ) ,
V_16 , V_147 ) ;
if ( V_24 ) {
F_20 ( L_8 , V_24 ) ;
break;
}
}
F_81 ( V_22 ) ;
return V_24 ;
}
int F_94 ( struct V_35 * V_36 ,
T_1 V_155 , T_1 V_145 ,
int V_37 ,
T_5 * V_146 , void * V_147 )
{
int V_24 ;
struct V_1 V_156 = F_95 ( V_156 ) ;
struct V_1 V_157 = F_95 ( V_157 ) ;
struct V_104 * V_105 ;
struct V_19 * V_106 = NULL ;
struct V_19 * V_107 = NULL ;
struct V_49 * V_158 = NULL ;
struct V_49 * V_159 = NULL ;
struct V_160 V_161 ;
struct V_108 * V_109 = NULL ;
F_20 ( L_9 ,
V_155 ) ;
if ( V_37 ) {
V_105 = V_110 ;
} else {
V_105 = F_96 ( V_36 -> V_103 ) ;
if ( F_14 ( V_105 ) )
return F_15 ( V_105 ) ;
V_109 = & V_105 -> V_114 -> V_109 ;
F_59 ( & V_109 -> V_115 ) ;
F_97 ( V_109 , & V_161 ) ;
F_63 ( & V_109 -> V_115 ) ;
}
V_24 = F_72 ( V_105 , V_36 , V_155 ,
V_145 , V_161 . V_59 ,
& V_106 ) ;
if ( V_24 )
goto V_42;
while ( ! V_24 && ( V_158 = F_26 ( V_106 , V_158 ) ) ) {
V_24 = F_73 ( V_105 , V_36 , V_158 -> V_50 , - 1 ,
V_161 . V_59 , & V_107 ) ;
if ( V_24 )
break;
while ( ! V_24 && ( V_159 = F_26 ( V_107 , V_159 ) ) ) {
F_20 ( L_10 ,
V_159 -> V_50 , V_158 -> V_50 ) ;
V_24 = F_89 ( V_36 , V_158 -> V_50 ,
V_155 ,
V_145 , V_159 -> V_50 ,
V_146 , V_147 ) ;
}
}
F_29 ( V_106 ) ;
F_29 ( V_107 ) ;
V_42:
if ( ! V_37 ) {
F_98 ( V_109 , & V_161 ) ;
F_99 ( V_105 , V_36 -> V_103 ) ;
}
return V_24 ;
}
int F_100 ( T_1 V_137 , struct V_35 * V_36 ,
struct V_17 * V_18 ,
T_5 * V_146 , void * V_147 )
{
int V_24 ;
T_1 V_145 ;
struct V_4 V_125 ;
int V_37 = V_18 -> V_37 ;
V_24 = F_85 ( V_36 , V_137 , V_18 ,
& V_125 ) ;
F_64 ( V_18 ) ;
if ( V_24 & V_91 )
V_24 = - V_162 ;
if ( V_24 < 0 )
return V_24 ;
V_145 = V_137 - V_125 . V_33 ;
V_24 = F_94 ( V_36 , V_125 . V_33 ,
V_145 , V_37 ,
V_146 , V_147 ) ;
return V_24 ;
}
static int F_101 ( T_1 V_121 , struct V_15 * V_124 ,
struct V_17 * V_18 ,
T_6 * V_146 , void * V_147 )
{
int V_24 = 0 ;
int V_25 ;
T_3 V_163 ;
T_3 V_132 ;
T_3 V_164 ;
T_1 V_7 = 0 ;
int V_165 = 0 ;
struct V_21 * V_22 ;
struct V_166 * V_167 ;
struct V_128 * V_98 ;
struct V_4 V_125 ;
while ( ! V_24 ) {
V_18 -> V_135 = 1 ;
V_24 = F_76 ( V_121 , V_7 ? V_7 + 1 : 0 , V_124 , V_18 ,
& V_125 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_165 ? 0 : - V_120 ;
break;
}
++ V_165 ;
V_7 = V_125 . V_41 ;
V_25 = V_18 -> V_45 [ 0 ] ;
V_22 = V_18 -> V_32 [ 0 ] ;
F_62 ( & V_22 -> V_106 ) ;
F_82 ( V_22 ) ;
F_83 ( V_22 , V_136 ) ;
F_64 ( V_18 ) ;
V_167 = F_102 ( V_22 , V_25 ) ;
V_98 = F_9 ( V_22 , V_25 , struct V_128 ) ;
for ( V_163 = 0 ; V_163 < F_103 ( V_22 , V_167 ) ; V_163 += V_132 ) {
V_164 = F_78 ( V_22 , V_98 ) ;
F_20 ( L_11
L_12 , V_163 ,
( unsigned long long ) V_125 . V_33 ,
( unsigned long long ) V_124 -> V_33 ) ;
V_24 = V_146 ( V_7 , V_98 , V_22 , V_147 ) ;
if ( V_24 )
break;
V_132 = sizeof( * V_98 ) + V_164 ;
V_98 = (struct V_128 * ) ( ( char * ) V_98 + V_132 ) ;
}
F_80 ( V_22 ) ;
F_81 ( V_22 ) ;
}
F_64 ( V_18 ) ;
return V_24 ;
}
static int F_104 ( T_1 V_121 , struct V_128 * V_98 ,
struct V_21 * V_22 , void * V_147 )
{
struct V_168 * V_169 = V_147 ;
char * V_170 ;
char * V_171 ;
int V_172 = V_169 -> V_170 -> V_173 ;
const int V_174 = sizeof( char * ) ;
T_3 V_134 ;
V_134 = V_169 -> V_170 -> V_134 > V_174 ?
V_169 -> V_170 -> V_134 - V_174 : 0 ;
V_171 = ( char * ) V_169 -> V_170 -> V_50 + ( V_172 + 1 ) * V_174 ;
V_170 = F_77 ( V_169 -> V_124 , V_169 -> V_17 , V_98 , V_22 ,
V_121 , V_171 , V_134 ) ;
if ( F_14 ( V_170 ) )
return F_15 ( V_170 ) ;
if ( V_170 > V_171 ) {
F_20 ( L_13 , V_170 ) ;
V_169 -> V_170 -> V_50 [ V_172 ] = ( T_1 ) ( unsigned long ) V_170 ;
++ V_169 -> V_170 -> V_173 ;
V_169 -> V_170 -> V_134 = V_170 - V_171 ;
} else {
F_20 ( L_14
L_15 ,
( unsigned long ) ( V_171 - V_170 ) , V_171 ) ;
++ V_169 -> V_170 -> V_175 ;
V_169 -> V_170 -> V_176 += V_171 - V_170 ;
V_169 -> V_170 -> V_134 = 0 ;
}
return 0 ;
}
int F_105 ( T_1 V_121 , struct V_168 * V_169 )
{
return F_101 ( V_121 , V_169 -> V_124 , V_169 -> V_17 ,
F_104 , V_169 ) ;
}
struct V_177 * F_106 ( T_3 V_178 )
{
struct V_177 * V_179 ;
T_7 V_180 ;
V_180 = F_107 ( T_7 , V_178 , sizeof( * V_179 ) ) ;
V_179 = F_2 ( V_180 , V_31 ) ;
if ( ! V_179 )
return F_84 ( - V_13 ) ;
if ( V_178 >= sizeof( * V_179 ) ) {
V_179 -> V_134 = V_178 - sizeof( * V_179 ) ;
V_179 -> V_176 = 0 ;
} else {
V_179 -> V_176 = sizeof( * V_179 ) - V_178 ;
V_179 -> V_134 = 0 ;
}
V_179 -> V_173 = 0 ;
V_179 -> V_175 = 0 ;
return V_179 ;
}
struct V_168 * F_108 ( T_8 V_178 , struct V_15 * V_124 ,
struct V_17 * V_18 )
{
struct V_168 * V_181 ;
struct V_177 * V_170 ;
V_170 = F_106 ( V_178 ) ;
if ( F_14 ( V_170 ) )
return ( void * ) V_170 ;
V_181 = F_2 ( sizeof( * V_181 ) , V_31 ) ;
if ( ! V_181 ) {
F_34 ( V_170 ) ;
return F_84 ( - V_13 ) ;
}
V_181 -> V_17 = V_18 ;
V_181 -> V_170 = V_170 ;
V_181 -> V_124 = V_124 ;
return V_181 ;
}
void F_109 ( struct V_168 * V_169 )
{
if ( ! V_169 )
return;
F_34 ( V_169 -> V_170 ) ;
F_34 ( V_169 ) ;
}
