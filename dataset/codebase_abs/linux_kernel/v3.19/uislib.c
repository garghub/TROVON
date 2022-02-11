static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_6 . V_3 = V_3 ;
V_2 -> V_6 . V_7 . V_8 = V_4 ;
V_2 -> V_6 . V_7 . V_9 = V_5 ;
}
static T_3 void *
F_2 ( T_4 V_10 , T_1 V_11 )
{
void T_3 * V_12 = NULL ;
void T_3 * V_13 = F_3 ( V_10 , V_11 ) ;
if ( ! V_13 ) {
F_4 ( L_1 ,
( unsigned long long ) V_10 ,
( unsigned long long ) V_11 ) ;
V_12 = NULL ;
goto V_14;
}
if ( ! F_5 ( V_13 ) ) {
F_6 ( L_2 , V_15 ) ;
F_7 ( V_13 ) ;
V_12 = NULL ;
goto V_14;
}
V_12 = V_13 ;
V_14:
return V_12 ;
}
static int
F_8 ( struct V_1 * V_2 , char * V_16 )
{
T_1 V_17 , V_18 ;
struct V_19 * V_20 , * V_21 ;
T_5 V_22 ;
if ( V_23 == V_24 ) {
F_4 ( L_3 ,
V_23 ) ;
F_9 ( V_25 , V_23 ,
V_26 ) ;
return V_27 ;
}
V_17 = V_2 -> V_28 . F_8 . V_29 ;
V_18 = V_2 -> V_28 . F_8 . V_30 ;
F_10 ( V_31 , V_17 , V_18 ,
V_32 ) ;
V_22 =
sizeof( struct V_19 ) +
( V_18 * sizeof( struct V_33 * ) ) ;
V_21 = F_11 ( V_22 , V_34 ) ;
if ( ! V_21 ) {
F_4 ( L_4 ) ;
F_9 ( V_25 , V_17 ,
V_26 ) ;
return V_35 ;
}
if ( V_2 -> V_6 . V_7 . V_36 ) {
V_21 -> V_37 = 0 ;
V_21 -> V_29 = V_17 ;
V_21 -> V_38 = 1 ;
} else
V_21 -> V_29 = V_21 -> V_37 = V_17 ;
sprintf ( V_21 -> V_39 , L_5 , ( int ) V_21 -> V_29 ) ;
V_21 -> V_40 = V_18 ;
V_21 -> V_41 =
(struct V_33 * * ) ( ( char * ) V_21 + sizeof( struct V_19 ) ) ;
V_21 -> V_42 = V_2 -> V_28 . F_8 . V_42 ;
V_21 -> V_43 = 0 ;
V_21 -> V_44 = NULL ;
F_12 ( & V_45 ) ;
for ( V_20 = V_46 ; V_20 ; V_20 = V_20 -> V_47 ) {
if ( V_20 -> V_29 == V_21 -> V_29 )
break;
}
F_13 ( & V_45 ) ;
if ( V_20 ) {
F_4 ( L_6 ,
V_21 -> V_29 ) ;
F_9 ( V_25 , V_21 -> V_29 ,
V_26 ) ;
F_14 ( V_21 ) ;
return V_48 ;
}
if ( ( V_2 -> V_28 . F_8 . V_49 != 0 )
&& ( V_2 -> V_28 . F_8 . V_50 != 0 ) ) {
V_21 -> V_43 = V_2 -> V_28 . F_8 . V_50 ;
V_21 -> V_44 =
F_2 ( V_2 -> V_28 . F_8 . V_49 ,
V_2 -> V_28 . F_8 . V_50 ) ;
}
if ( ! V_2 -> V_6 . V_7 . V_9 ) {
struct V_51 V_28 ;
V_28 . V_52 = V_53 ;
V_28 . V_54 . V_29 = V_17 ;
V_28 . V_54 . V_55 = V_21 -> V_44 ;
V_28 . V_54 . V_30 = V_18 ;
V_28 . V_54 . V_56 = V_2 -> V_28 . F_8 . V_57 ;
V_28 . V_54 . V_58 = V_2 -> V_28 . F_8 . V_42 ;
if ( ! V_59 ) {
F_4 ( L_7 ) ;
F_9 ( V_25 , V_21 -> V_29 ,
V_26 ) ;
F_14 ( V_21 ) ;
return V_60 ;
}
if ( ! V_59 ( & V_28 ) ) {
F_4 ( L_8 ) ;
F_9 ( V_25 , V_21 -> V_29 ,
V_26 ) ;
F_14 ( V_21 ) ;
return
V_61 ;
}
}
F_15 ( & V_45 ) ;
if ( ! V_46 )
V_46 = V_21 ;
else {
V_21 -> V_47 = V_46 ;
V_46 = V_21 ;
}
V_24 ++ ;
F_16 ( & V_45 ) ;
F_9 ( V_62 , V_21 -> V_29 ,
V_32 ) ;
return V_63 ;
}
static int
F_17 ( struct V_1 * V_2 , char * V_16 )
{
int V_64 ;
struct V_19 * V_21 , * V_65 = NULL ;
struct V_51 V_28 ;
T_1 V_17 ;
V_17 = V_2 -> V_28 . F_17 . V_29 ;
F_12 ( & V_45 ) ;
V_21 = V_46 ;
while ( V_21 ) {
if ( V_21 -> V_29 == V_17 )
break;
V_65 = V_21 ;
V_21 = V_21 -> V_47 ;
}
if ( ! V_21 ) {
F_4 ( L_9 ,
V_17 ) ;
F_13 ( & V_45 ) ;
return V_48 ;
}
for ( V_64 = 0 ; V_64 < V_21 -> V_40 ; V_64 ++ ) {
if ( V_21 -> V_41 [ V_64 ] != NULL ) {
F_4 ( L_10 ,
V_64 , V_17 ) ;
F_13 ( & V_45 ) ;
return V_66 ;
}
}
F_13 ( & V_45 ) ;
if ( V_2 -> V_6 . V_7 . V_9 )
goto remove;
V_28 . V_52 = V_67 ;
V_28 . V_68 . V_29 = V_17 ;
if ( ! V_59 ) {
F_4 ( L_11 ) ;
return V_60 ;
}
if ( ! V_59 ( & V_28 ) ) {
F_4 ( L_12 ) ;
return V_61 ;
}
remove:
F_15 ( & V_45 ) ;
if ( V_65 )
V_65 -> V_47 = V_21 -> V_47 ;
else
V_46 = V_21 -> V_47 ;
V_24 -- ;
F_16 ( & V_45 ) ;
if ( V_21 -> V_44 ) {
F_7 ( V_21 -> V_44 ) ;
V_21 -> V_44 = NULL ;
}
F_14 ( V_21 ) ;
return V_63 ;
}
static int
F_18 ( struct V_1 * V_2 , char * V_16 )
{
struct V_33 * V_69 ;
struct V_19 * V_21 ;
T_1 V_17 , V_70 ;
int V_71 = V_63 ;
T_4 V_72 = V_73 ;
struct V_74 * V_75 ;
V_17 = V_2 -> V_28 . F_18 . V_29 ;
V_70 = V_2 -> V_28 . F_18 . V_76 ;
F_10 ( V_77 , V_70 , V_17 ,
V_32 ) ;
V_69 = F_11 ( sizeof( struct V_33 ) , V_34 ) ;
if ( ! V_69 ) {
F_4 ( L_13 ) ;
F_10 ( V_78 , V_70 , V_17 ,
V_26 ) ;
return V_35 ;
}
V_69 -> V_79 = V_2 -> V_28 . F_18 . V_80 ;
V_69 -> V_81 = V_2 -> V_28 . F_18 . V_81 ;
V_69 -> V_49 = V_2 -> V_28 . F_18 . V_49 ;
V_69 -> V_29 = V_17 ;
V_69 -> V_76 = V_70 ;
F_19 ( & V_69 -> V_82 , 1 ) ;
sprintf ( V_69 -> V_83 , L_14 , ( unsigned ) V_17 , ( unsigned ) V_70 ) ;
if ( V_2 -> V_6 . V_7 . V_36 )
V_69 -> V_55 = ( void T_3 * ) F_20 ( V_69 -> V_49 ) ;
else {
V_75 = F_21 ( V_69 -> V_79 ) ;
if ( V_75 )
V_72 = V_75 -> V_84 ;
if ( V_72 > V_2 -> V_28 . F_18 . V_50 ) {
F_4 ( L_15 ,
( V_85 ) V_2 -> V_28 . F_18 . V_50 ,
( V_85 ) V_72 ) ;
F_10 ( V_78 , V_70 , V_17 ,
V_26 ) ;
V_71 = V_86 ;
goto V_14;
}
V_69 -> V_55 =
F_3 ( V_69 -> V_49 ,
V_2 -> V_28 . F_18 . V_50 ) ;
if ( ! V_69 -> V_55 ) {
F_4 ( L_16 ,
V_69 -> V_49 ,
V_2 -> V_28 . F_18 . V_50 ) ;
V_71 = V_87 ;
F_10 ( V_78 , V_70 , V_17 ,
V_26 ) ;
goto V_14;
}
}
V_69 -> V_58 = V_2 -> V_28 . F_18 . V_88 ;
V_69 -> V_50 = V_2 -> V_28 . F_18 . V_50 ;
F_12 ( & V_45 ) ;
for ( V_21 = V_46 ; V_21 ; V_21 = V_21 -> V_47 ) {
if ( V_21 -> V_29 == V_17 ) {
if ( V_70 >= V_21 -> V_40 ) {
F_4 ( L_17 ,
V_70 , V_21 -> V_40 ) ;
V_71 = V_89 ;
F_10 ( V_78 ,
V_70 , V_17 ,
V_26 ) ;
F_13 ( & V_45 ) ;
goto V_14;
}
if ( V_21 -> V_41 [ V_70 ] ) {
F_4 ( L_18 ,
V_70 ) ;
F_10 ( V_78 ,
V_70 , V_17 ,
V_26 ) ;
V_71 = V_48 ;
F_13 ( & V_45 ) ;
goto V_14;
}
F_13 ( & V_45 ) ;
if ( ! V_2 -> V_6 . V_7 . V_9 ) {
struct V_51 V_28 ;
if ( ! F_22 ( V_69 -> V_79 ,
V_90 ) ) {
F_23 ( & ( (
struct V_91
T_3 * ) ( V_69 ->
V_55 ) ) ->
V_92 ) ;
if ( ! F_24
( V_69 -> V_55 ) ) {
F_4 ( L_19 ,
V_70 ) ;
F_10
( V_78 ,
V_70 , V_17 ,
V_26 ) ;
V_71 = V_93 ;
goto V_14;
}
V_28 . V_52 = V_94 ;
V_28 . V_95 . V_55 = V_69 -> V_55 ;
V_28 . V_95 . V_29 = V_17 ;
V_28 . V_95 . V_96 = V_70 ;
V_28 . V_95 . V_58 =
V_69 -> V_58 ;
V_28 . V_95 . V_81 = V_69 -> V_81 ;
} else
if ( ! F_22 ( V_69 -> V_79 ,
V_97 ) ) {
F_23 ( & ( (
struct V_91
T_3 * ) ( V_69 ->
V_55 ) ) ->
V_92 ) ;
if ( ! F_25
( V_69 -> V_55 ) ) {
F_4 ( L_20 ,
V_70 ) ;
F_10
( V_78 ,
V_70 , V_17 ,
V_26 ) ;
V_71 = V_93 ;
goto V_14;
}
V_28 . V_52 = V_98 ;
V_28 . V_99 . V_55 = V_69 -> V_55 ;
V_28 . V_99 . V_29 = V_17 ;
V_28 . V_99 . V_96 = V_70 ;
V_28 . V_99 . V_58 =
V_69 -> V_58 ;
V_28 . V_95 . V_81 = V_69 -> V_81 ;
} else {
F_4 ( L_21 ) ;
F_10
( V_78 , V_70 ,
V_17 , V_26 ) ;
V_71 = V_100 ;
goto V_14;
}
if ( ! V_59 ) {
F_4 ( L_22 ) ;
F_10
( V_78 , V_70 ,
V_17 , V_26 ) ;
V_71 = V_60 ;
goto V_14;
}
if ( ! V_59 ( & V_28 ) ) {
F_4 ( L_23 ) ;
F_10
( V_78 , V_70 ,
V_17 , V_26 ) ;
V_71 = V_61 ;
goto V_14;
}
}
V_21 -> V_41 [ V_70 ] = V_69 ;
F_10 ( V_101 , V_70 , V_17 ,
V_32 ) ;
return V_63 ;
}
}
F_13 ( & V_45 ) ;
F_4 ( L_24 , V_17 ) ;
F_10 ( V_78 , V_70 , V_17 ,
V_26 ) ;
V_71 = V_102 ;
V_14:
if ( ! V_2 -> V_6 . V_7 . V_36 ) {
F_7 ( V_69 -> V_55 ) ;
V_69 -> V_55 = NULL ;
}
F_14 ( V_69 ) ;
return V_71 ;
}
static int
F_26 ( struct V_1 * V_2 )
{
T_1 V_17 , V_70 ;
struct V_19 * V_21 ;
struct V_33 * V_69 ;
struct V_51 V_28 ;
int V_103 = V_63 ;
V_17 = V_2 -> V_28 . V_104 . V_29 ;
V_70 = V_2 -> V_28 . V_104 . V_76 ;
F_12 ( & V_45 ) ;
for ( V_21 = V_46 ; V_21 ; V_21 = V_21 -> V_47 ) {
if ( V_21 -> V_29 == V_17 ) {
if ( V_70 >= V_21 -> V_40 ) {
F_4 ( L_25 ,
V_70 , V_21 -> V_40 ) ;
V_103 = V_105 ;
} else {
V_69 = V_21 -> V_41 [ V_70 ] ;
if ( ! V_69 ) {
F_4 ( L_26 ,
V_70 ) ;
V_103 =
V_48 ;
}
}
break;
}
}
if ( ! V_21 ) {
F_4 ( L_27 ,
V_17 ) ;
V_103 = V_102 ;
}
F_13 ( & V_45 ) ;
if ( V_103 == V_63 ) {
if ( ! F_22 ( V_69 -> V_79 ,
V_90 ) ) {
V_28 . V_52 = V_106 ;
V_28 . V_107 . V_55 = V_69 -> V_55 ;
} else if ( ! F_22 ( V_69 -> V_79 ,
V_97 ) ) {
V_28 . V_52 = V_108 ;
V_28 . V_109 . V_55 = V_69 -> V_55 ;
} else {
F_4 ( L_28 ) ;
return V_100 ;
}
if ( ! V_59 ) {
F_4 ( L_29 ) ;
return V_60 ;
}
if ( ! V_59 ( & V_28 ) ) {
F_4 ( L_30 ) ;
return
V_61 ;
}
}
return V_103 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
T_1 V_17 , V_70 ;
struct V_19 * V_21 ;
struct V_33 * V_69 ;
struct V_51 V_28 ;
int V_103 = V_63 ;
V_17 = V_2 -> V_28 . V_104 . V_29 ;
V_70 = V_2 -> V_28 . V_104 . V_76 ;
F_12 ( & V_45 ) ;
for ( V_21 = V_46 ; V_21 ; V_21 = V_21 -> V_47 ) {
if ( V_21 -> V_29 == V_17 ) {
if ( V_70 >= V_21 -> V_40 ) {
F_4 ( L_31 ,
V_70 , V_21 -> V_40 ) ;
V_103 = V_105 ;
} else {
V_69 = V_21 -> V_41 [ V_70 ] ;
if ( ! V_69 ) {
F_4 ( L_32 ,
V_70 ) ;
V_103 =
V_48 ;
}
}
break;
}
}
if ( ! V_21 ) {
F_4 ( L_33 ,
V_17 ) ;
V_103 = V_102 ;
}
F_13 ( & V_45 ) ;
if ( V_103 == V_63 ) {
if ( ! F_22 ( V_69 -> V_79 ,
V_90 ) ) {
V_28 . V_52 = V_110 ;
V_28 . V_111 . V_55 = V_69 -> V_55 ;
} else if ( ! F_22 ( V_69 -> V_79 ,
V_97 ) ) {
V_28 . V_52 = V_112 ;
V_28 . V_113 . V_55 = V_69 -> V_55 ;
} else {
F_4 ( L_34 ) ;
return V_100 ;
}
if ( ! V_59 ) {
F_4 ( L_29 ) ;
return V_60 ;
}
if ( ! V_59 ( & V_28 ) ) {
F_4 ( L_35 ) ;
return
V_61 ;
}
}
return V_103 ;
}
static int
F_28 ( struct V_1 * V_2 , char * V_16 )
{
T_1 V_17 , V_70 ;
struct V_19 * V_21 ;
struct V_33 * V_69 ;
struct V_51 V_28 ;
int V_103 = V_63 ;
V_17 = V_2 -> V_28 . F_28 . V_29 ;
V_70 = V_2 -> V_28 . F_28 . V_29 ;
F_12 ( & V_45 ) ;
F_29 ( L_36 , V_17 , V_70 ) ;
for ( V_21 = V_46 ; V_21 ; V_21 = V_21 -> V_47 ) {
if ( V_21 -> V_29 == V_17 ) {
if ( V_70 >= V_21 -> V_40 ) {
F_4 ( L_37 ,
V_70 , V_21 -> V_40 ) ;
V_103 = V_105 ;
} else {
V_69 = V_21 -> V_41 [ V_70 ] ;
if ( ! V_69 ) {
F_4 ( L_38 ,
V_70 ) ;
V_103 =
V_48 ;
}
}
break;
}
}
if ( ! V_21 ) {
F_4 ( L_39 ,
V_17 ) ;
V_103 = V_102 ;
}
F_13 ( & V_45 ) ;
if ( V_103 == V_63 ) {
if ( ! F_22 ( V_69 -> V_79 ,
V_90 ) ) {
V_28 . V_52 = V_114 ;
V_28 . V_115 . V_55 = V_69 -> V_55 ;
} else if ( ! F_22 ( V_69 -> V_79 ,
V_97 ) ) {
V_28 . V_52 = V_116 ;
V_28 . V_117 . V_55 = V_69 -> V_55 ;
} else {
F_4 ( L_40 ) ;
return
V_100 ;
}
if ( ! V_59 ) {
F_4 ( L_41 ) ;
return
V_60 ;
}
if ( ! V_59 ( & V_28 ) ) {
F_4 ( L_42 ) ;
return
V_61 ;
}
if ( V_69 -> V_118 ) {
F_29 ( L_43 ) ;
F_30 ( V_17 , V_70 ) ;
}
if ( ! V_2 -> V_6 . V_7 . V_36 ) {
F_29 ( L_44 ) ;
F_7 ( V_69 -> V_55 ) ;
}
F_14 ( V_69 ) ;
V_21 -> V_41 [ V_70 ] = NULL ;
}
return V_103 ;
}
static int
F_31 ( struct V_1 * V_2 , char * V_16 )
{
F_32 ( V_119 , V_32 ) ;
V_23 = V_2 -> V_28 . F_31 . V_120 ;
V_121 = V_2 -> V_28 . F_31 . V_122 ;
V_123 = 0 ;
if ( ! V_2 -> V_6 . V_7 . V_36 )
F_33 ( V_59 ) ;
V_124 = 1 ;
F_32 ( V_125 , V_32 ) ;
return V_63 ;
}
static int
F_34 ( T_1 V_17 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_126 , 0 , 0 ) ;
V_2 . V_28 . F_17 . V_29 = V_17 ;
if ( F_17 ( & V_2 , NULL ) != V_63 ) {
F_4 ( L_45 , V_17 ) ;
return 0 ;
}
return 1 ;
}
static int
F_35 ( T_1 V_17 , T_1 V_70 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_127 , 0 , 0 ) ;
V_2 . V_28 . F_28 . V_29 = V_17 ;
V_2 . V_28 . F_28 . V_76 = V_70 ;
if ( F_28 ( & V_2 , NULL ) != V_63 ) {
F_4 ( L_46 , V_17 ,
V_70 ) ;
return 0 ;
}
return 1 ;
}
int
F_36 ( T_1 V_29 , T_6 V_128 ,
T_4 V_49 , V_85 V_129 )
{
struct V_1 V_2 ;
F_29 ( L_47 , V_29 ) ;
F_9 ( V_119 , V_29 , V_32 ) ;
if ( ! V_124 ) {
F_1 ( & V_2 , V_130 , 0 , 0 ) ;
V_2 . V_28 . F_31 . V_120 = 23 ;
V_2 . V_28 . F_31 . V_131 = 0 ;
if ( F_31 ( & V_2 , NULL ) != V_63 ) {
F_4 ( L_48 ) ;
return 0 ;
}
F_29 ( L_49 ) ;
F_9 ( V_125 , V_29 ,
V_32 ) ;
}
F_9 ( V_31 , V_29 ,
V_132 ) ;
F_1 ( & V_2 , V_133 , 0 , 0 ) ;
V_2 . V_28 . F_8 . V_29 = V_29 ;
V_2 . V_28 . F_8 . V_30 = 23 ;
V_2 . V_28 . F_8 . V_49 = V_49 ;
V_2 . V_28 . F_8 . V_50 = V_129 ;
if ( F_8 ( & V_2 , NULL ) != V_63 ) {
F_4 ( L_50 ) ;
F_9 ( V_25 , V_29 ,
V_26 ) ;
return 0 ;
}
F_9 ( V_62 , V_29 , V_32 ) ;
return 1 ;
}
int
F_37 ( T_1 V_29 )
{
return F_34 ( V_29 ) ;
}
int
F_38 ( T_1 V_29 , T_1 V_76 )
{
struct V_1 V_2 ;
int V_12 ;
F_1 ( & V_2 , V_134 , 0 , 0 ) ;
V_2 . V_28 . V_104 . V_29 = V_29 ;
V_2 . V_28 . V_104 . V_76 = V_76 ;
V_2 . V_28 . V_104 . V_135 = V_136 ;
V_12 = F_26 ( & V_2 ) ;
if ( V_12 != V_63 ) {
F_4 ( L_51 ,
V_29 , V_76 ) ;
return V_12 ;
}
return 0 ;
}
int
F_39 ( T_1 V_29 , T_1 V_76 )
{
struct V_1 V_2 ;
int V_12 ;
F_1 ( & V_2 , V_134 , 0 , 0 ) ;
V_2 . V_28 . V_104 . V_29 = V_29 ;
V_2 . V_28 . V_104 . V_76 = V_76 ;
V_2 . V_28 . V_104 . V_135 = V_137 ;
V_12 = F_27 ( & V_2 ) ;
if ( V_12 != V_63 ) {
F_4 ( L_52 ,
V_29 , V_76 ) ;
return V_12 ;
}
return 0 ;
}
int
F_40 ( T_1 V_29 , T_1 V_76 ,
T_4 V_138 , T_1 V_139 ,
int V_140 , T_6 V_128 ,
struct V_141 * V_81 )
{
struct V_1 V_2 ;
F_29 ( L_53 , V_29 , V_76 ) ;
F_10 ( V_142 , V_76 , V_29 ,
V_32 ) ;
F_1 ( & V_2 , V_143 , 0 , 0 ) ;
if ( V_140 )
V_2 . V_6 . V_7 . V_36 = 1 ;
V_2 . V_28 . F_18 . V_29 = V_29 ;
V_2 . V_28 . F_18 . V_76 = V_76 ;
V_2 . V_28 . F_18 . V_88 = V_128 ;
if ( V_81 )
V_2 . V_28 . F_18 . V_81 = * V_81 ;
else
memset ( & V_2 . V_28 . F_18 . V_81 , 0 ,
sizeof( struct V_141 ) ) ;
V_2 . V_28 . F_18 . V_49 = V_138 ;
if ( V_139 < V_73 ) {
F_4 ( L_54 ,
V_139 , ( unsigned int ) V_73 ) ;
F_10 ( V_144 , V_139 ,
V_73 , V_26 ) ;
return 0 ;
}
V_2 . V_28 . F_18 . V_50 = V_139 ;
V_2 . V_28 . F_18 . V_80 = V_90 ;
if ( F_18 ( & V_2 , NULL ) != V_63 ) {
F_4 ( L_55 ) ;
F_10 ( V_144 , V_76 , V_29 ,
V_26 ) ;
return 0 ;
}
F_10 ( V_145 , V_76 , V_29 ,
V_32 ) ;
return 1 ;
}
int
F_41 ( T_1 V_29 , T_1 V_76 )
{
return F_35 ( V_29 , V_76 ) ;
}
int
F_42 ( T_1 V_29 , T_1 V_76 ,
T_4 V_138 , T_1 V_139 ,
int V_140 , T_6 V_128 ,
struct V_141 * V_81 )
{
struct V_1 V_2 ;
F_29 ( L_53 , V_29 , V_76 ) ;
F_10 ( V_146 , V_76 , V_29 ,
V_32 ) ;
F_1 ( & V_2 , V_143 , 0 , 0 ) ;
if ( V_140 )
V_2 . V_6 . V_7 . V_36 = 1 ;
V_2 . V_28 . F_18 . V_29 = V_29 ;
V_2 . V_28 . F_18 . V_76 = V_76 ;
V_2 . V_28 . F_18 . V_88 = V_128 ;
if ( V_81 )
V_2 . V_28 . F_18 . V_81 = * V_81 ;
else
memset ( & V_2 . V_28 . F_18 . V_81 , 0 ,
sizeof( struct V_141 ) ) ;
V_2 . V_28 . F_18 . V_49 = V_138 ;
if ( V_139 < V_73 ) {
F_4 ( L_54 ,
V_139 , ( unsigned int ) V_73 ) ;
F_10 ( V_147 , V_139 ,
V_73 , V_26 ) ;
return 0 ;
}
V_2 . V_28 . F_18 . V_50 = V_139 ;
V_2 . V_28 . F_18 . V_80 = V_97 ;
if ( F_18 ( & V_2 , NULL ) != V_63 ) {
F_4 ( L_56 ) ;
F_10 ( V_147 , V_76 , V_29 ,
V_26 ) ;
return 0 ;
}
F_10 ( V_148 , V_76 , V_29 ,
V_32 ) ;
return 1 ;
}
int
F_43 ( T_1 V_29 , T_1 V_76 )
{
struct V_1 V_2 ;
int V_12 ;
F_1 ( & V_2 , V_134 , 0 , 0 ) ;
V_2 . V_28 . V_104 . V_29 = V_29 ;
V_2 . V_28 . V_104 . V_76 = V_76 ;
V_2 . V_28 . V_104 . V_135 = V_136 ;
V_12 = F_26 ( & V_2 ) ;
if ( V_12 != V_63 ) {
F_4 ( L_57 ,
V_29 , V_76 ) ;
return - 1 ;
}
return 0 ;
}
int
F_44 ( T_1 V_29 , T_1 V_76 )
{
struct V_1 V_2 ;
int V_12 ;
F_1 ( & V_2 , V_134 , 0 , 0 ) ;
V_2 . V_28 . V_104 . V_29 = V_29 ;
V_2 . V_28 . V_104 . V_76 = V_76 ;
V_2 . V_28 . V_104 . V_135 = V_137 ;
V_12 = F_27 ( & V_2 ) ;
if ( V_12 != V_63 ) {
F_4 ( L_58 ,
V_29 , V_76 ) ;
return - 1 ;
}
return 0 ;
}
int
F_45 ( T_1 V_29 , T_1 V_76 )
{
return F_35 ( V_29 , V_76 ) ;
}
void *
F_46 ( struct V_149 * V_150 , char * V_151 , int V_152 )
{
void * V_153 = F_47 ( V_150 , V_34 | V_154 ) ;
if ( V_153 == NULL ) {
F_4 ( L_59 ,
V_151 , V_152 ) ;
return NULL ;
}
return V_153 ;
}
void
F_48 ( struct V_149 * V_150 , void * V_153 , char * V_151 , int V_152 )
{
if ( V_153 == NULL ) {
F_4 ( L_60 , V_151 , V_152 ) ;
return;
}
F_49 ( V_150 , V_153 ) ;
}
static int
F_50 ( char * * V_155 , int * V_156 )
{
int V_64 , V_157 = 0 ;
struct V_19 * V_21 ;
if ( F_51 ( L_61 ) < 0 )
goto V_158;
F_12 ( & V_45 ) ;
for ( V_21 = V_46 ; V_21 ; V_21 = V_21 -> V_47 ) {
if ( F_51 ( L_62 ,
V_21 , V_21 -> V_29 , V_21 -> V_40 ) < 0 )
goto V_159;
if ( F_51 ( L_63 ) < 0 )
goto V_159;
for ( V_64 = 0 ; V_64 < V_21 -> V_40 ; V_64 ++ ) {
if ( V_21 -> V_41 [ V_64 ] ) {
if ( F_51 ( L_64 ,
V_21 -> V_29 , V_64 , V_21 -> V_41 [ V_64 ] ,
V_21 -> V_41 [ V_64 ] -> V_55 ,
V_21 -> V_41 [ V_64 ] -> V_160 ) < 0 )
goto V_159;
if ( F_51 ( L_65 ,
V_21 -> V_41 [ V_64 ] -> V_161 ,
V_21 -> V_41 [ V_64 ] -> V_162 ,
V_21 -> V_41 [ V_64 ] -> V_163 ) < 0 )
goto V_159;
}
}
}
F_13 ( & V_45 ) ;
if ( F_51 ( L_66 ,
F_52 ( & V_164 ) ) < 0 )
goto V_158;
if ( F_51 ( L_67 ,
V_165 , V_166 ) < 0 )
goto V_158;
if ( F_51 ( L_68 ,
V_167 , V_168 , V_169 ) < 0 )
goto V_158;
if ( F_51 ( L_69 , V_170 ) < 0 )
goto V_158;
if ( F_51 ( L_70 , V_171 ) < 0 )
goto V_158;
return V_157 ;
V_159:
F_13 ( & V_45 ) ;
V_158:
return - 1 ;
}
static T_7
F_53 ( struct V_172 * V_172 , char T_8 * V_16 ,
T_5 V_173 , T_9 * V_174 )
{
char * V_175 ;
int V_176 = 0 ;
int V_177 = V_178 ;
if ( V_179 == NULL ) {
F_54 ( L_71 ) ;
V_179 = F_55 ( V_178 ) ;
if ( V_179 == NULL ) {
F_4 ( L_72 ) ;
return - V_180 ;
}
}
V_175 = V_179 ;
if ( ( * V_174 == 0 ) || ( ! V_181 ) ) {
F_54 ( L_73 ) ;
V_176 = F_50 ( & V_175 , & V_177 ) ;
V_181 = 1 ;
} else
V_176 = strlen ( V_179 ) ;
return F_56 ( V_16 , V_173 , V_174 ,
V_179 , V_176 ) ;
}
static struct V_33 *
F_57 ( T_1 V_17 , T_1 V_70 )
{
struct V_19 * V_21 ;
struct V_33 * V_69 = NULL ;
F_12 ( & V_45 ) ;
for ( V_21 = V_46 ; V_21 ; V_21 = V_21 -> V_47 ) {
if ( V_21 -> V_29 == V_17 ) {
if ( V_70 >= V_21 -> V_40 ) {
F_4 ( L_74 ,
V_15 ,
( int ) ( V_17 ) , ( int ) ( V_70 ) ) ;
goto V_14;
}
V_69 = V_21 -> V_41 [ V_70 ] ;
if ( ! V_69 )
F_4 ( L_74 ,
V_15 ,
( int ) ( V_17 ) , ( int ) ( V_70 ) ) ;
goto V_14;
}
}
V_14:
F_13 ( & V_45 ) ;
return V_69 ;
}
static int
F_58 ( void * V_182 )
{
unsigned long long V_183 , V_184 , V_185 , V_186 ;
struct V_187 * V_188 = NULL ;
int V_64 ;
F_59 ( L_75 ) ;
for ( V_64 = 0 ; V_64 < 16 ; V_64 ++ ) {
V_184 = F_60 () ;
F_61 ( V_189 ,
0 , V_190 ) ;
V_183 = F_60 () ;
if ( V_166 == 0 ) {
V_166 = ( V_183 - V_184 ) ;
} else {
if ( V_166 < ( V_183 - V_184 ) )
V_166 = ( V_183 - V_184 ) ;
}
}
F_29 ( L_76 , V_166 ) ;
V_165 = V_166 ;
V_185 = 0 ;
V_191 = 0 ;
while ( 1 ) {
struct V_187 * V_192 , * V_20 ;
struct V_33 * V_69 = NULL ;
F_62 ( & V_193 ) ;
V_188 = NULL ;
F_63 (lelt, tmp, &List_Polling_Device_Channels) {
int V_12 = 0 ;
V_69 = F_64 ( V_192 , struct V_33 ,
V_194 ) ;
F_62 ( & V_69 -> V_82 ) ;
if ( V_69 -> V_195 )
V_12 = V_69 -> V_195 ( V_69 -> V_196 ) ;
else
continue;
F_65 ( & V_69 -> V_82 ) ;
if ( V_12 ) {
V_185 = 0 ;
if ( V_188 == NULL ) {
V_69 -> V_161 ++ ;
if ( !
( F_66
( V_192 ,
& V_197 ) ) ) {
V_188 = V_192 ;
V_69 -> V_162 ++ ;
} else
V_69 -> V_163 ++ ;
}
}
if ( V_198 . V_199 )
break;
}
if ( V_188 != NULL ) {
V_171 ++ ;
F_67 ( V_188 , & V_197 ) ;
}
F_65 ( & V_193 ) ;
V_183 = F_60 () ;
V_186 = V_183 - V_184 ;
V_184 = V_183 ;
if ( V_198 . V_199 )
break;
if ( V_170 == 0xFF ) {
F_29 ( L_77 ) ;
break;
}
if ( V_185 > V_165 ) {
V_191 = 0 ;
V_168 ++ ;
F_61 ( V_189 ,
V_191 ,
V_190 ) ;
V_191 = 1 ;
} else {
V_169 ++ ;
F_68 () ;
V_185 = V_185 + V_186 ;
}
}
F_54 ( L_78 ) ;
F_69 ( & V_198 . V_200 , 0 ) ;
}
static BOOL
F_70 ( void )
{
if ( V_201 )
return TRUE ;
if ( ! F_71 ( & V_198 ,
& F_58 , NULL , L_75 ) ) {
F_4 ( L_79 ) ;
return FALSE ;
}
V_201 = TRUE ;
return TRUE ;
}
void
F_72 ( T_1 V_29 , T_1 V_76 ,
int (* V_195)( void * ) ,
void * V_196 )
{
struct V_33 * V_69 ;
V_69 = F_57 ( V_29 , V_76 ) ;
if ( ! V_69 ) {
F_4 ( L_80 , V_15 , ( int ) ( V_29 ) ,
( int ) ( V_76 ) ) ;
return;
}
F_62 ( & V_193 ) ;
F_70 () ;
V_69 -> V_195 = V_195 ;
V_69 -> V_196 = V_196 ;
V_69 -> V_118 = TRUE ;
F_73 ( & ( V_69 -> V_194 ) ,
& V_197 ) ;
F_65 ( & V_193 ) ;
}
void
F_30 ( T_1 V_29 , T_1 V_76 )
{
struct V_33 * V_69 ;
V_69 = F_57 ( V_29 , V_76 ) ;
if ( ! V_69 ) {
F_4 ( L_80 , V_15 , ( int ) ( V_29 ) ,
( int ) ( V_76 ) ) ;
return;
}
F_62 ( & V_193 ) ;
F_74 ( & V_69 -> V_194 ) ;
V_69 -> V_118 = FALSE ;
V_69 -> V_195 = NULL ;
F_65 ( & V_193 ) ;
}
static void
F_75 ( struct V_202 * V_203 )
{
if ( ! V_191 ) {
V_191 = 1 ;
F_76 ( & V_189 ) ;
}
}
void
F_77 ( T_1 V_29 , T_1 V_76 )
{
if ( V_170 == 0 )
return;
if ( V_191 )
return;
V_167 ++ ;
F_78 ( & V_204 ) ;
}
static int T_10
F_79 ( void )
{
if ( ! V_205 )
return - V_206 ;
F_29 ( L_81 ) ;
F_29 ( L_82 ,
( V_85 ) sizeof( struct V_207 ) ) ;
F_29 ( L_83 ,
( V_85 ) sizeof( struct V_208 ) ) ;
F_29 ( L_84 ,
( V_85 ) sizeof( struct V_209 ) ) ;
F_29 ( L_85 ,
( V_85 ) sizeof( struct V_210 ) ) ;
F_29 ( L_86 ,
( V_85 ) sizeof( struct V_1 ) ) ;
F_29 ( L_87 ,
( V_85 ) sizeof( struct V_211 ) ) ;
F_29 ( L_88 ,
( V_85 ) sizeof( struct V_91 ) ) ;
F_29 ( L_89 ,
( V_85 ) sizeof( struct V_212 ) ) ;
F_29 ( L_90 , V_213 ) ;
F_29 ( L_91 , V_214 ) ;
V_46 = NULL ;
V_24 = V_23 = 0 ;
F_80 ( & V_45 ) ;
V_59 = NULL ;
F_32 ( V_215 , V_32 ) ;
V_216 = F_81 ( V_217 , NULL ) ;
if ( V_216 ) {
V_218 = F_82 (
V_219 , 0444 , V_216 , NULL ,
& V_220 ) ;
V_221 = F_83 (
V_222 , 0444 , V_216 ,
& V_121 ) ;
V_223 = F_84 (
V_224 , 0666 , V_216 ,
& V_165 ) ;
V_225 = F_85 (
V_226 , 0666 , V_216 ,
& V_170 ) ;
}
F_9 ( V_227 , 0 , V_32 ) ;
return 0 ;
}
static void T_11
F_86 ( void )
{
if ( V_179 ) {
F_87 ( V_179 ) ;
V_179 = NULL ;
}
F_88 ( V_218 ) ;
F_88 ( V_225 ) ;
F_88 ( V_223 ) ;
F_88 ( V_221 ) ;
F_88 ( V_216 ) ;
F_54 ( L_92 ) ;
}
