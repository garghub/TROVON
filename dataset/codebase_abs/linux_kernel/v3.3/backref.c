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
struct V_10 * V_11 ,
struct V_19 * V_20 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
struct V_4 V_37 ;
struct V_4 V_5 = { 0 } ;
struct V_21 * V_22 ;
int V_24 = 0 ;
int V_38 ;
int V_6 = V_11 -> V_6 ;
V_18 = F_12 () ;
if ( ! V_18 )
return - V_13 ;
V_37 . V_33 = V_11 -> V_3 ;
V_37 . type = V_39 ;
V_37 . V_40 = ( T_1 ) - 1 ;
V_16 = F_13 ( V_36 , & V_37 ) ;
if ( F_14 ( V_16 ) ) {
V_24 = F_15 ( V_16 ) ;
goto V_41;
}
F_16 () ;
V_38 = F_17 ( V_16 -> V_42 ) ;
F_18 () ;
if ( V_38 + 1 == V_6 )
goto V_41;
V_18 -> V_43 = V_6 ;
V_24 = F_19 ( NULL , V_16 , & V_11 -> V_5 , V_18 , 0 , 0 ) ;
F_20 ( L_1
L_2 ,
( unsigned long long ) V_11 -> V_3 , V_6 , V_11 -> V_9 , V_24 ,
( unsigned long long ) V_11 -> V_5 . V_33 , V_11 -> V_5 . type ,
( unsigned long long ) V_11 -> V_5 . V_40 ) ;
if ( V_24 < 0 )
goto V_41;
V_22 = V_18 -> V_32 [ V_6 ] ;
if ( ! V_22 ) {
F_21 ( 1 ) ;
V_24 = 1 ;
goto V_41;
}
if ( V_6 == 0 ) {
if ( V_24 == 1 && V_18 -> V_44 [ 0 ] >= F_7 ( V_22 ) ) {
V_24 = F_6 ( V_16 , V_18 ) ;
if ( V_24 )
goto V_41;
V_22 = V_18 -> V_32 [ 0 ] ;
}
F_8 ( V_22 , & V_5 , V_18 -> V_44 [ 0 ] ) ;
}
V_24 = F_4 ( V_16 , V_18 , V_20 , V_22 , V_6 , V_5 . V_33 ,
V_11 -> V_8 ) ;
V_41:
F_22 ( V_18 ) ;
return V_24 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
int V_45 ;
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_10 * V_46 ;
struct V_10 * V_47 ;
struct V_19 * V_20 ;
struct V_48 * V_42 ;
V_20 = F_24 ( V_31 ) ;
if ( ! V_20 )
return - V_13 ;
F_25 (ref, ref_safe, head, list) {
if ( V_11 -> V_7 )
continue;
if ( V_11 -> V_9 == 0 )
continue;
V_45 = F_11 ( V_36 , V_11 , V_20 ) ;
if ( V_45 ) {
if ( V_24 == 0 )
V_24 = V_45 ;
continue;
}
V_42 = F_26 ( V_20 , NULL ) ;
V_11 -> V_7 = V_42 ? V_42 -> V_49 : 0 ;
while ( ( V_42 = F_26 ( V_20 , V_42 ) ) ) {
V_47 = F_2 ( sizeof( * V_47 ) , V_31 ) ;
if ( ! V_47 ) {
V_24 = - V_13 ;
break;
}
memcpy ( V_47 , V_11 , sizeof( * V_11 ) ) ;
V_47 -> V_7 = V_42 -> V_49 ;
F_27 ( & V_47 -> V_14 , & V_11 -> V_14 ) ;
}
F_28 ( V_20 ) ;
}
F_29 ( V_20 ) ;
return V_24 ;
}
static int F_30 ( struct V_1 * V_2 , int V_50 )
{
struct V_1 * V_51 ;
F_31 (pos1, head) {
struct V_1 * V_52 ;
struct V_1 * V_53 ;
struct V_10 * V_54 ;
V_54 = F_32 ( V_51 , struct V_10 , V_14 ) ;
if ( V_50 == 1 && V_54 -> V_5 . type == 0 )
continue;
for ( V_53 = V_51 -> V_55 , V_52 = V_53 -> V_55 ; V_53 != V_2 ;
V_53 = V_52 , V_52 = V_53 -> V_55 ) {
struct V_10 * V_56 ;
V_56 = F_32 ( V_53 , struct V_10 , V_14 ) ;
if ( V_50 == 1 ) {
if ( memcmp ( & V_54 -> V_5 , & V_56 -> V_5 ,
sizeof( V_54 -> V_5 ) ) ||
V_54 -> V_6 != V_56 -> V_6 ||
V_54 -> V_3 != V_56 -> V_3 )
continue;
V_54 -> V_9 += V_56 -> V_9 ;
} else {
if ( V_54 -> V_7 != V_56 -> V_7 )
continue;
V_54 -> V_9 += V_56 -> V_9 ;
}
F_33 ( & V_56 -> V_14 ) ;
F_34 ( V_56 ) ;
}
}
return 0 ;
}
static int F_35 ( struct V_57 * V_2 , T_1 V_58 ,
struct V_4 * V_59 ,
struct V_1 * V_60 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_63 * V_64 = & V_2 -> V_42 . V_63 ;
int V_65 ;
int V_24 = 0 ;
if ( V_62 && V_62 -> V_66 )
F_36 ( V_59 , & V_62 -> V_5 ) ;
while ( ( V_64 = F_37 ( V_64 ) ) ) {
struct V_67 * V_42 ;
V_42 = F_38 ( V_64 , struct V_67 ,
V_63 ) ;
if ( V_42 -> V_68 != V_2 -> V_42 . V_68 )
break;
F_21 ( V_42 -> V_69 ) ;
if ( V_42 -> V_58 > V_58 )
continue;
switch ( V_42 -> V_70 ) {
case V_71 :
case V_72 :
F_21 ( 1 ) ;
continue;
case V_73 :
V_65 = 1 ;
break;
case V_74 :
V_65 = - 1 ;
break;
default:
F_39 ( 1 ) ;
}
switch ( V_42 -> type ) {
case V_75 : {
struct V_76 * V_11 ;
V_11 = F_40 ( V_42 ) ;
V_24 = F_1 ( V_60 , V_11 -> V_16 , V_59 ,
V_11 -> V_6 + 1 , 0 , V_42 -> V_68 ,
V_42 -> V_77 * V_65 ) ;
break;
}
case V_78 : {
struct V_76 * V_11 ;
V_11 = F_40 ( V_42 ) ;
V_24 = F_1 ( V_60 , V_11 -> V_16 , V_59 ,
V_11 -> V_6 + 1 , V_11 -> V_7 ,
V_42 -> V_68 ,
V_42 -> V_77 * V_65 ) ;
break;
}
case V_79 : {
struct V_80 * V_11 ;
struct V_4 V_5 ;
V_11 = F_41 ( V_42 ) ;
V_5 . V_33 = V_11 -> V_33 ;
V_5 . type = V_34 ;
V_5 . V_40 = V_11 -> V_40 ;
V_24 = F_1 ( V_60 , V_11 -> V_16 , & V_5 , 0 , 0 ,
V_42 -> V_68 ,
V_42 -> V_77 * V_65 ) ;
break;
}
case V_81 : {
struct V_80 * V_11 ;
struct V_4 V_5 ;
V_11 = F_41 ( V_42 ) ;
V_5 . V_33 = V_11 -> V_33 ;
V_5 . type = V_34 ;
V_5 . V_40 = V_11 -> V_40 ;
V_24 = F_1 ( V_60 , V_11 -> V_16 , & V_5 , 0 ,
V_11 -> V_7 , V_42 -> V_68 ,
V_42 -> V_77 * V_65 ) ;
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
struct V_17 * V_18 , T_1 V_68 ,
struct V_4 * V_59 , int * V_82 ,
struct V_1 * V_60 )
{
int V_24 = 0 ;
int V_25 ;
struct V_21 * V_83 ;
struct V_4 V_5 ;
unsigned long V_84 ;
unsigned long V_85 ;
struct V_86 * V_87 ;
T_1 V_88 ;
T_1 V_89 ;
V_83 = V_18 -> V_32 [ 0 ] ;
V_25 = V_18 -> V_44 [ 0 ] - 1 ;
V_89 = F_43 ( V_83 , V_25 ) ;
F_39 ( V_89 < sizeof( * V_87 ) ) ;
V_87 = F_9 ( V_83 , V_25 , struct V_86 ) ;
V_88 = F_44 ( V_83 , V_87 ) ;
V_84 = ( unsigned long ) ( V_87 + 1 ) ;
V_85 = ( unsigned long ) V_87 + V_89 ;
if ( V_88 & V_90 ) {
struct V_91 * V_92 ;
struct V_93 V_94 ;
V_92 = (struct V_91 * ) V_84 ;
* V_82 = F_45 ( V_83 , V_92 ) ;
F_46 ( V_83 , V_92 , & V_94 ) ;
F_36 ( V_59 , & V_94 ) ;
V_84 += sizeof( struct V_91 ) ;
F_39 ( V_84 > V_85 ) ;
} else {
F_39 ( ! ( V_88 & V_95 ) ) ;
}
while ( V_84 < V_85 ) {
struct V_96 * V_97 ;
T_1 V_40 ;
int type ;
V_97 = (struct V_96 * ) V_84 ;
type = F_47 ( V_83 , V_97 ) ;
V_40 = F_48 ( V_83 , V_97 ) ;
switch ( type ) {
case V_78 :
V_24 = F_1 ( V_60 , 0 , V_59 ,
* V_82 + 1 , V_40 ,
V_68 , 1 ) ;
break;
case V_81 : {
struct V_98 * V_99 ;
int V_9 ;
V_99 = (struct V_98 * ) ( V_97 + 1 ) ;
V_9 = F_49 ( V_83 , V_99 ) ;
V_24 = F_1 ( V_60 , 0 , NULL , 0 , V_40 ,
V_68 , V_9 ) ;
break;
}
case V_75 :
V_24 = F_1 ( V_60 , V_40 , V_59 ,
* V_82 + 1 , 0 , V_68 , 1 ) ;
break;
case V_79 : {
struct V_100 * V_101 ;
int V_9 ;
T_1 V_16 ;
V_101 = (struct V_100 * ) ( & V_97 -> V_40 ) ;
V_9 = F_50 ( V_83 , V_101 ) ;
V_5 . V_33 = F_51 ( V_83 ,
V_101 ) ;
V_5 . type = V_34 ;
V_5 . V_40 = F_52 ( V_83 , V_101 ) ;
V_16 = F_53 ( V_83 , V_101 ) ;
V_24 = F_1 ( V_60 , V_16 , & V_5 , 0 , 0 , V_68 ,
V_9 ) ;
break;
}
default:
F_21 ( 1 ) ;
}
F_39 ( V_24 ) ;
V_84 += F_54 ( type ) ;
}
return 0 ;
}
static int F_55 ( struct V_35 * V_36 ,
struct V_17 * V_18 , T_1 V_68 ,
struct V_4 * V_59 , int V_82 ,
struct V_1 * V_60 )
{
struct V_15 * V_102 = V_36 -> V_102 ;
int V_24 ;
int V_25 ;
struct V_21 * V_83 ;
struct V_4 V_5 ;
while ( 1 ) {
V_24 = F_56 ( V_102 , V_18 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_25 = V_18 -> V_44 [ 0 ] ;
V_83 = V_18 -> V_32 [ 0 ] ;
F_8 ( V_83 , & V_5 , V_25 ) ;
if ( V_5 . V_33 != V_68 )
break;
if ( V_5 . type < V_75 )
continue;
if ( V_5 . type > V_81 )
break;
switch ( V_5 . type ) {
case V_78 :
V_24 = F_1 ( V_60 , 0 , V_59 ,
V_82 + 1 , V_5 . V_40 ,
V_68 , 1 ) ;
break;
case V_81 : {
struct V_98 * V_99 ;
int V_9 ;
V_99 = F_9 ( V_83 , V_25 ,
struct V_98 ) ;
V_9 = F_49 ( V_83 , V_99 ) ;
V_24 = F_1 ( V_60 , 0 , NULL , 0 , V_5 . V_40 ,
V_68 , V_9 ) ;
break;
}
case V_75 :
V_24 = F_1 ( V_60 , V_5 . V_40 , V_59 ,
V_82 + 1 , 0 , V_68 , 1 ) ;
break;
case V_79 : {
struct V_100 * V_101 ;
int V_9 ;
T_1 V_16 ;
V_101 = F_9 ( V_83 , V_25 ,
struct V_100 ) ;
V_9 = F_50 ( V_83 , V_101 ) ;
V_5 . V_33 = F_51 ( V_83 ,
V_101 ) ;
V_5 . type = V_34 ;
V_5 . V_40 = F_52 ( V_83 , V_101 ) ;
V_16 = F_53 ( V_83 , V_101 ) ;
V_24 = F_1 ( V_60 , V_16 , & V_5 , 0 , 0 ,
V_68 , V_9 ) ;
break;
}
default:
F_21 ( 1 ) ;
}
F_39 ( V_24 ) ;
}
return V_24 ;
}
static int F_57 ( struct V_103 * V_104 ,
struct V_35 * V_36 , T_1 V_68 ,
T_1 V_58 , struct V_19 * V_105 , struct V_19 * V_106 )
{
struct V_4 V_5 ;
struct V_17 * V_18 ;
struct V_4 V_59 = { 0 } ;
struct V_107 * V_108 = NULL ;
struct V_57 * V_2 ;
int V_82 = 0 ;
int V_24 ;
struct V_1 V_109 ;
struct V_1 V_60 ;
struct V_10 * V_11 ;
F_58 ( & V_60 ) ;
F_58 ( & V_109 ) ;
V_5 . V_33 = V_68 ;
V_5 . type = V_110 ;
V_5 . V_40 = ( T_1 ) - 1 ;
V_18 = F_12 () ;
if ( ! V_18 )
return - V_13 ;
V_111:
V_2 = NULL ;
V_24 = F_19 ( V_104 , V_36 -> V_102 , & V_5 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_41;
F_39 ( V_24 == 0 ) ;
V_108 = & V_104 -> V_112 -> V_108 ;
F_59 ( & V_108 -> V_113 ) ;
V_2 = F_60 ( V_104 , V_68 ) ;
if ( V_2 ) {
if ( ! F_61 ( & V_2 -> V_114 ) ) {
F_62 ( & V_2 -> V_42 . V_105 ) ;
F_63 ( & V_108 -> V_113 ) ;
F_64 ( V_18 ) ;
F_65 ( & V_2 -> V_114 ) ;
F_66 ( & V_2 -> V_114 ) ;
F_67 ( & V_2 -> V_42 ) ;
goto V_111;
}
V_24 = F_35 ( V_2 , V_58 , & V_59 , & V_109 ) ;
if ( V_24 ) {
F_63 ( & V_108 -> V_113 ) ;
goto V_41;
}
}
F_63 ( & V_108 -> V_113 ) ;
if ( V_18 -> V_44 [ 0 ] ) {
struct V_21 * V_83 ;
int V_25 ;
V_83 = V_18 -> V_32 [ 0 ] ;
V_25 = V_18 -> V_44 [ 0 ] - 1 ;
F_8 ( V_83 , & V_5 , V_25 ) ;
if ( V_5 . V_33 == V_68 &&
V_5 . type == V_110 ) {
V_24 = F_42 ( V_36 , V_18 , V_68 ,
& V_59 , & V_82 , & V_60 ) ;
if ( V_24 )
goto V_41;
V_24 = F_55 ( V_36 , V_18 , V_68 , & V_59 ,
V_82 , & V_60 ) ;
if ( V_24 )
goto V_41;
}
}
F_64 ( V_18 ) ;
F_68 (ref, &prefs_delayed, list) {
if ( ( V_11 -> V_5 . V_40 | V_11 -> V_5 . type | V_11 -> V_5 . V_33 ) == 0 )
memcpy ( & V_11 -> V_5 , & V_59 , sizeof( V_11 -> V_5 ) ) ;
}
F_69 ( & V_109 , & V_60 ) ;
V_24 = F_30 ( & V_60 , 1 ) ;
if ( V_24 )
goto V_41;
V_24 = F_23 ( V_36 , & V_60 ) ;
if ( V_24 )
goto V_41;
V_24 = F_30 ( & V_60 , 2 ) ;
if ( V_24 )
goto V_41;
while ( ! F_70 ( & V_60 ) ) {
V_11 = F_71 ( & V_60 , struct V_10 , V_14 ) ;
F_33 ( & V_11 -> V_14 ) ;
if ( V_11 -> V_9 < 0 )
F_21 ( 1 ) ;
if ( V_11 -> V_9 && V_11 -> V_3 && V_11 -> V_7 == 0 ) {
V_24 = F_5 ( V_106 , V_11 -> V_3 , 0 , V_31 ) ;
F_39 ( V_24 < 0 ) ;
}
if ( V_11 -> V_9 && V_11 -> V_7 ) {
V_24 = F_5 ( V_105 , V_11 -> V_7 , 0 , V_31 ) ;
F_39 ( V_24 < 0 ) ;
}
F_34 ( V_11 ) ;
}
V_41:
if ( V_2 )
F_66 ( & V_2 -> V_114 ) ;
F_22 ( V_18 ) ;
while ( ! F_70 ( & V_60 ) ) {
V_11 = F_71 ( & V_60 , struct V_10 , V_14 ) ;
F_33 ( & V_11 -> V_14 ) ;
F_34 ( V_11 ) ;
}
while ( ! F_70 ( & V_109 ) ) {
V_11 = F_71 ( & V_109 , struct V_10 ,
V_14 ) ;
F_33 ( & V_11 -> V_14 ) ;
F_34 ( V_11 ) ;
}
return V_24 ;
}
static int F_72 ( struct V_103 * V_104 ,
struct V_35 * V_36 , T_1 V_68 ,
T_1 V_115 , T_1 V_58 , struct V_19 * * V_116 )
{
struct V_19 * V_117 ;
int V_24 ;
V_117 = F_24 ( V_31 ) ;
if ( ! V_117 )
return - V_13 ;
* V_116 = F_24 ( V_31 ) ;
if ( ! * V_116 ) {
F_29 ( V_117 ) ;
return - V_13 ;
}
V_24 = F_57 ( V_104 , V_36 , V_68 , V_58 , * V_116 , V_117 ) ;
F_29 ( V_117 ) ;
if ( V_24 < 0 && V_24 != - V_118 ) {
F_29 ( * V_116 ) ;
return V_24 ;
}
return 0 ;
}
int F_73 ( struct V_103 * V_104 ,
struct V_35 * V_36 , T_1 V_68 ,
T_1 V_115 , T_1 V_58 , struct V_19 * * V_106 )
{
struct V_19 * V_117 ;
struct V_48 * V_42 = NULL ;
int V_24 ;
V_117 = F_24 ( V_31 ) ;
if ( ! V_117 )
return - V_13 ;
* V_106 = F_24 ( V_31 ) ;
if ( ! * V_106 ) {
F_29 ( V_117 ) ;
return - V_13 ;
}
while ( 1 ) {
V_24 = F_57 ( V_104 , V_36 , V_68 , V_58 ,
V_117 , * V_106 ) ;
if ( V_24 < 0 && V_24 != - V_118 ) {
F_29 ( V_117 ) ;
F_29 ( * V_106 ) ;
return V_24 ;
}
V_42 = F_26 ( V_117 , V_42 ) ;
if ( ! V_42 )
break;
V_68 = V_42 -> V_49 ;
}
F_29 ( V_117 ) ;
return 0 ;
}
static int F_74 ( T_1 V_119 , T_1 V_120 , T_2 V_121 ,
struct V_15 * V_122 , struct V_17 * V_18 ,
struct V_4 * V_123 )
{
int V_24 ;
struct V_4 V_5 ;
struct V_21 * V_22 ;
V_5 . type = V_121 ;
V_5 . V_33 = V_119 ;
V_5 . V_40 = V_120 ;
V_24 = F_19 ( NULL , V_122 , & V_5 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_22 = V_18 -> V_32 [ 0 ] ;
if ( V_24 && V_18 -> V_44 [ 0 ] >= F_7 ( V_22 ) ) {
V_24 = F_6 ( V_122 , V_18 ) ;
if ( V_24 )
return V_24 ;
V_22 = V_18 -> V_32 [ 0 ] ;
}
F_8 ( V_22 , V_123 , V_18 -> V_44 [ 0 ] ) ;
if ( V_123 -> type != V_5 . type || V_123 -> V_33 != V_5 . V_33 )
return 1 ;
return 0 ;
}
int F_75 ( T_1 V_119 , T_1 V_120 , struct V_15 * V_122 ,
struct V_17 * V_18 )
{
struct V_4 V_5 ;
return F_74 ( V_119 , V_120 , V_124 , V_122 , V_18 ,
& V_5 ) ;
}
static int F_76 ( T_1 V_119 , T_1 V_120 , struct V_15 * V_122 ,
struct V_17 * V_18 ,
struct V_4 * V_123 )
{
return F_74 ( V_119 , V_120 , V_125 , V_122 , V_18 ,
V_123 ) ;
}
static char * F_77 ( struct V_15 * V_122 , struct V_17 * V_18 ,
struct V_126 * V_97 ,
struct V_21 * V_127 , T_1 V_7 ,
char * V_128 , T_3 V_129 )
{
T_3 V_130 ;
int V_25 ;
T_1 V_131 ;
int V_24 ;
T_4 V_132 = V_129 - 1 ;
struct V_21 * V_22 = V_127 ;
struct V_4 V_123 ;
if ( V_132 >= 0 )
V_128 [ V_132 ] = '\0' ;
while ( 1 ) {
V_130 = F_78 ( V_22 , V_97 ) ;
V_132 -= V_130 ;
if ( V_132 >= 0 )
F_79 ( V_22 , V_128 + V_132 ,
( unsigned long ) ( V_97 + 1 ) , V_130 ) ;
if ( V_22 != V_127 )
F_80 ( V_22 ) ;
V_24 = F_76 ( V_7 , 0 , V_122 , V_18 , & V_123 ) ;
if ( V_24 > 0 )
V_24 = - V_118 ;
if ( V_24 )
break;
V_131 = V_123 . V_40 ;
if ( V_7 == V_131 )
break;
V_25 = V_18 -> V_44 [ 0 ] ;
V_22 = V_18 -> V_32 [ 0 ] ;
if ( V_22 != V_127 )
F_62 ( & V_22 -> V_105 ) ;
F_64 ( V_18 ) ;
V_97 = F_9 ( V_22 , V_25 , struct V_126 ) ;
V_7 = V_131 ;
-- V_132 ;
if ( V_132 >= 0 )
V_128 [ V_132 ] = '/' ;
}
F_64 ( V_18 ) ;
if ( V_24 )
return F_81 ( V_24 ) ;
return V_128 + V_132 ;
}
int F_82 ( struct V_35 * V_36 , T_1 V_133 ,
struct V_17 * V_18 , struct V_4 * V_123 )
{
int V_24 ;
T_1 V_88 ;
T_3 V_89 ;
struct V_21 * V_22 ;
struct V_86 * V_87 ;
struct V_4 V_5 ;
V_5 . type = V_110 ;
V_5 . V_33 = V_133 ;
V_5 . V_40 = ( T_1 ) - 1 ;
V_24 = F_19 ( NULL , V_36 -> V_102 , & V_5 , V_18 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_83 ( V_36 -> V_102 , V_18 ,
0 , V_110 ) ;
if ( V_24 < 0 )
return V_24 ;
F_8 ( V_18 -> V_32 [ 0 ] , V_123 , V_18 -> V_44 [ 0 ] ) ;
if ( V_123 -> type != V_110 ||
V_123 -> V_33 > V_133 ||
V_123 -> V_33 + V_123 -> V_40 <= V_133 ) {
F_20 ( L_3 ,
( unsigned long long ) V_133 ) ;
return - V_118 ;
}
V_22 = V_18 -> V_32 [ 0 ] ;
V_89 = F_43 ( V_22 , V_18 -> V_44 [ 0 ] ) ;
F_39 ( V_89 < sizeof( * V_87 ) ) ;
V_87 = F_9 ( V_22 , V_18 -> V_44 [ 0 ] , struct V_86 ) ;
V_88 = F_44 ( V_22 , V_87 ) ;
F_20 ( L_4
L_5 ,
( unsigned long long ) V_133 ,
( unsigned long long ) ( V_133 - V_123 -> V_33 ) ,
( unsigned long long ) V_123 -> V_33 ,
( unsigned long long ) V_123 -> V_40 ,
( unsigned long long ) V_88 , V_89 ) ;
if ( V_88 & V_90 )
return V_90 ;
if ( V_88 & V_95 )
return V_95 ;
return - V_134 ;
}
static int F_84 ( unsigned long * V_84 , struct V_21 * V_22 ,
struct V_86 * V_87 , T_3 V_89 ,
struct V_96 * * V_135 ,
int * V_136 )
{
unsigned long V_85 ;
T_1 V_88 ;
struct V_91 * V_92 ;
if ( ! * V_84 ) {
V_88 = F_44 ( V_22 , V_87 ) ;
if ( V_88 & V_90 ) {
V_92 = (struct V_91 * ) ( V_87 + 1 ) ;
* V_135 =
(struct V_96 * ) ( V_92 + 1 ) ;
} else {
* V_135 = (struct V_96 * ) ( V_87 + 1 ) ;
}
* V_84 = ( unsigned long ) * V_135 ;
if ( ( void * ) * V_84 >= ( void * ) V_87 + V_89 )
return - V_118 ;
}
V_85 = ( unsigned long ) V_87 + V_89 ;
* V_135 = (struct V_96 * ) * V_84 ;
* V_136 = F_47 ( V_22 , * V_135 ) ;
* V_84 += F_54 ( * V_136 ) ;
F_21 ( * V_84 > V_85 ) ;
if ( * V_84 == V_85 )
return 1 ;
return 0 ;
}
int F_85 ( unsigned long * V_84 , struct V_21 * V_22 ,
struct V_86 * V_87 , T_3 V_89 ,
T_1 * V_137 , T_2 * V_138 )
{
int V_24 ;
int type ;
struct V_91 * V_92 ;
struct V_96 * V_139 ;
if ( * V_84 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_84 ( V_84 , V_22 , V_87 , V_89 ,
& V_139 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_75 ||
type == V_78 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_92 = (struct V_91 * ) ( V_87 + 1 ) ;
* V_137 = F_48 ( V_22 , V_139 ) ;
* V_138 = F_45 ( V_22 , V_92 ) ;
if ( V_24 == 1 )
* V_84 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_86 ( struct V_35 * V_36 ,
struct V_17 * V_18 , T_1 V_133 ,
T_1 V_140 ,
T_1 V_141 , T_1 V_16 ,
T_5 * V_142 , void * V_143 )
{
T_1 V_28 ;
struct V_4 V_5 ;
struct V_26 * V_27 ;
struct V_21 * V_22 ;
int V_25 ;
int V_144 ;
int V_24 = 0 ;
int V_145 ;
T_1 V_146 ;
T_1 V_147 ;
V_22 = F_87 ( V_36 -> V_148 , V_133 ,
V_36 -> V_148 -> V_149 , 0 ) ;
if ( ! V_22 )
return - V_134 ;
V_144 = F_7 ( V_22 ) ;
for ( V_25 = 0 ; V_25 < V_144 ; ++ V_25 ) {
F_8 ( V_22 , & V_5 , V_25 ) ;
if ( V_5 . type != V_34 )
continue;
V_27 = F_9 ( V_22 , V_25 , struct V_26 ) ;
V_145 = F_88 ( V_22 , V_27 ) ;
if ( V_145 == V_150 )
continue;
V_28 = F_10 ( V_22 , V_27 ) ;
if ( V_28 != V_140 )
continue;
V_146 = F_89 ( V_22 , V_27 ) ;
V_147 = F_90 ( V_22 , V_27 ) ;
if ( V_141 < V_146 ||
V_141 >= V_146 + V_147 )
continue;
F_20 ( L_6
L_7 , V_140 ,
V_5 . V_33 , V_5 . V_40 , V_16 ) ;
V_24 = V_142 ( V_5 . V_33 ,
V_5 . V_40 + ( V_141 - V_146 ) ,
V_16 , V_143 ) ;
if ( V_24 ) {
F_20 ( L_8 , V_24 ) ;
break;
}
}
F_80 ( V_22 ) ;
return V_24 ;
}
int F_91 ( struct V_35 * V_36 ,
struct V_17 * V_18 ,
T_1 V_151 , T_1 V_141 ,
T_5 * V_142 , void * V_143 )
{
int V_24 ;
struct V_1 V_152 = F_92 ( V_152 ) ;
struct V_1 V_153 = F_92 ( V_153 ) ;
struct V_103 * V_104 ;
struct V_19 * V_105 ;
struct V_19 * V_106 ;
struct V_48 * V_154 = NULL ;
struct V_48 * V_155 = NULL ;
struct V_156 V_157 ;
struct V_107 * V_108 ;
V_104 = F_93 ( V_36 -> V_102 ) ;
if ( F_14 ( V_104 ) )
return F_15 ( V_104 ) ;
F_20 ( L_9 ,
V_151 ) ;
V_108 = & V_104 -> V_112 -> V_108 ;
F_59 ( & V_108 -> V_113 ) ;
F_94 ( V_108 , & V_157 ) ;
F_63 ( & V_108 -> V_113 ) ;
V_24 = F_72 ( V_104 , V_36 , V_151 ,
V_141 , V_157 . V_58 ,
& V_105 ) ;
if ( V_24 )
goto V_41;
while ( ! V_24 && ( V_154 = F_26 ( V_105 , V_154 ) ) ) {
V_24 = F_73 ( V_104 , V_36 , V_154 -> V_49 , - 1 ,
V_157 . V_58 , & V_106 ) ;
if ( V_24 )
break;
while ( ! V_24 && ( V_155 = F_26 ( V_106 , V_155 ) ) ) {
F_20 ( L_10 ,
V_155 -> V_49 , V_154 -> V_49 ) ;
V_24 = F_86 ( V_36 , V_18 , V_154 -> V_49 ,
V_151 ,
V_141 , V_155 -> V_49 ,
V_142 , V_143 ) ;
}
}
F_29 ( V_105 ) ;
F_29 ( V_106 ) ;
V_41:
F_95 ( V_108 , & V_157 ) ;
F_96 ( V_104 , V_36 -> V_102 ) ;
return V_24 ;
}
int F_97 ( T_1 V_133 , struct V_35 * V_36 ,
struct V_17 * V_18 ,
T_5 * V_142 , void * V_143 )
{
int V_24 ;
T_1 V_141 ;
struct V_4 V_123 ;
V_24 = F_82 ( V_36 , V_133 , V_18 ,
& V_123 ) ;
F_64 ( V_18 ) ;
if ( V_24 & V_90 )
V_24 = - V_158 ;
if ( V_24 < 0 )
return V_24 ;
V_141 = V_133 - V_123 . V_33 ;
V_24 = F_91 ( V_36 , V_18 , V_123 . V_33 ,
V_141 , V_142 , V_143 ) ;
return V_24 ;
}
static int F_98 ( T_1 V_119 , struct V_15 * V_122 ,
struct V_17 * V_18 ,
T_6 * V_142 , void * V_143 )
{
int V_24 ;
int V_25 ;
T_3 V_159 ;
T_3 V_130 ;
T_3 V_160 ;
T_1 V_7 = 0 ;
int V_161 = 0 ;
struct V_21 * V_22 ;
struct V_162 * V_163 ;
struct V_126 * V_97 ;
struct V_4 V_123 ;
while ( 1 ) {
V_24 = F_76 ( V_119 , V_7 ? V_7 + 1 : 0 , V_122 , V_18 ,
& V_123 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_161 ? 0 : - V_118 ;
break;
}
++ V_161 ;
V_7 = V_123 . V_40 ;
V_25 = V_18 -> V_44 [ 0 ] ;
V_22 = V_18 -> V_32 [ 0 ] ;
F_62 ( & V_22 -> V_105 ) ;
F_64 ( V_18 ) ;
V_163 = F_99 ( V_22 , V_25 ) ;
V_97 = F_9 ( V_22 , V_25 , struct V_126 ) ;
for ( V_159 = 0 ; V_159 < F_100 ( V_22 , V_163 ) ; V_159 += V_130 ) {
V_160 = F_78 ( V_22 , V_97 ) ;
F_20 ( L_11
L_12 , V_159 ,
( unsigned long long ) V_123 . V_33 ,
( unsigned long long ) V_122 -> V_33 ) ;
V_24 = V_142 ( V_7 , V_97 , V_22 , V_143 ) ;
if ( V_24 ) {
F_80 ( V_22 ) ;
break;
}
V_130 = sizeof( * V_97 ) + V_160 ;
V_97 = (struct V_126 * ) ( ( char * ) V_97 + V_130 ) ;
}
F_80 ( V_22 ) ;
}
F_64 ( V_18 ) ;
return V_24 ;
}
static int F_101 ( T_1 V_119 , struct V_126 * V_97 ,
struct V_21 * V_22 , void * V_143 )
{
struct V_164 * V_165 = V_143 ;
char * V_166 ;
char * V_167 ;
int V_168 = V_165 -> V_166 -> V_169 ;
const int V_170 = sizeof( char * ) ;
T_3 V_132 ;
V_132 = V_165 -> V_166 -> V_132 > V_170 ?
V_165 -> V_166 -> V_132 - V_170 : 0 ;
V_167 = ( char * ) V_165 -> V_166 -> V_49 + ( V_168 + 1 ) * V_170 ;
V_166 = F_77 ( V_165 -> V_122 , V_165 -> V_17 , V_97 , V_22 ,
V_119 , V_167 , V_132 ) ;
if ( F_14 ( V_166 ) )
return F_15 ( V_166 ) ;
if ( V_166 > V_167 ) {
F_20 ( L_13 , V_166 ) ;
V_165 -> V_166 -> V_49 [ V_168 ] = ( T_1 ) ( unsigned long ) V_166 ;
++ V_165 -> V_166 -> V_169 ;
V_165 -> V_166 -> V_132 = V_166 - V_167 ;
} else {
F_20 ( L_14
L_15 ,
( unsigned long ) ( V_167 - V_166 ) , V_167 ) ;
++ V_165 -> V_166 -> V_171 ;
V_165 -> V_166 -> V_172 += V_167 - V_166 ;
V_165 -> V_166 -> V_132 = 0 ;
}
return 0 ;
}
int F_102 ( T_1 V_119 , struct V_164 * V_165 )
{
return F_98 ( V_119 , V_165 -> V_122 , V_165 -> V_17 ,
F_101 , V_165 ) ;
}
struct V_173 * F_103 ( T_3 V_174 )
{
struct V_173 * V_175 ;
T_7 V_176 ;
V_176 = F_104 ( T_7 , V_174 , sizeof( * V_175 ) ) ;
V_175 = F_2 ( V_176 , V_31 ) ;
if ( ! V_175 )
return F_81 ( - V_13 ) ;
if ( V_174 >= sizeof( * V_175 ) ) {
V_175 -> V_132 = V_174 - sizeof( * V_175 ) ;
V_175 -> V_172 = 0 ;
} else {
V_175 -> V_172 = sizeof( * V_175 ) - V_174 ;
V_175 -> V_132 = 0 ;
}
V_175 -> V_169 = 0 ;
V_175 -> V_171 = 0 ;
return V_175 ;
}
struct V_164 * F_105 ( T_8 V_174 , struct V_15 * V_122 ,
struct V_17 * V_18 )
{
struct V_164 * V_177 ;
struct V_173 * V_166 ;
V_166 = F_103 ( V_174 ) ;
if ( F_14 ( V_166 ) )
return ( void * ) V_166 ;
V_177 = F_2 ( sizeof( * V_177 ) , V_31 ) ;
if ( ! V_177 ) {
F_34 ( V_166 ) ;
return F_81 ( - V_13 ) ;
}
V_177 -> V_17 = V_18 ;
V_177 -> V_166 = V_166 ;
V_177 -> V_122 = V_122 ;
return V_177 ;
}
void F_106 ( struct V_164 * V_165 )
{
F_34 ( V_165 ) ;
}
