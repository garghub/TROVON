static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
return F_3 ( V_3 , V_6 , V_5 ) ;
}
static void
F_4 ( T_1 * V_7 , T_2 V_8 , T_3 V_9 , T_3 V_10 )
{
memset ( V_7 , 0 , sizeof( T_1 ) ) ;
V_7 -> V_11 . V_12 = V_8 ;
V_7 -> V_11 . V_13 . V_14 = V_9 ;
V_7 -> V_11 . V_13 . V_15 = V_10 ;
}
static void
F_5 ( struct V_4 * V_5 )
{
V_5 -> V_16 = F_6 ( V_5 -> V_17 , V_18 ) ;
if ( ! V_5 -> V_16 ) {
F_7 ( L_1 ,
V_5 -> V_17 ) ;
return;
}
V_5 -> V_19 = F_8 ( L_2 , 0 , V_5 -> V_16 ,
& V_20 , V_5 ) ;
if ( ! V_5 -> V_19 ) {
F_7 ( L_3 , V_5 -> V_17 ) ;
F_9 ( V_5 -> V_17 , V_18 ) ;
V_5 -> V_16 = NULL ;
return;
}
F_10 ( V_5 -> V_19 , V_21 ) ;
}
static T_4 void *
F_11 ( T_5 V_22 , T_2 V_23 , int V_24 )
{
void * V_25 = NULL ;
void T_4 * V_26 = F_12 ( V_22 , V_23 ) ;
if ( ! V_26 ) {
F_7 ( L_4 ,
( unsigned long long ) V_22 ,
( unsigned long long ) V_23 ) ;
V_25 = NULL ;
goto V_27;
}
if ( V_24 ) {
F_13 ( V_26 , 0 , V_23 ) ;
if ( ! F_14 ( V_23 , NULL ) ) {
F_15 ( L_5 , V_28 ) ;
F_16 ( V_26 ) ;
V_25 = NULL ;
goto V_27;
}
F_17 ( V_26 , V_23 ) ;
} else {
if ( ! F_18 ( V_26 , NULL ) ) {
F_15 ( L_5 , V_28 ) ;
F_16 ( V_26 ) ;
V_25 = NULL ;
goto V_27;
}
}
V_25 = V_26 ;
V_27:
return V_25 ;
}
static int
F_19 ( T_1 * V_7 , char * V_29 )
{
T_2 V_30 , V_31 ;
struct V_4 * V_32 , * V_5 ;
T_6 V_33 ;
if ( V_34 == V_35 ) {
F_7 ( L_6 ,
V_34 ) ;
F_20 ( V_36 , V_34 ,
V_37 ) ;
return V_38 ;
}
V_30 = V_7 -> V_39 . V_40 . V_30 ;
V_31 = V_7 -> V_39 . V_40 . V_31 ;
F_21 ( V_41 , V_30 , V_31 ,
V_42 ) ;
V_33 =
sizeof( struct V_4 ) +
( V_31 * sizeof( struct V_43 * ) ) ;
V_5 = F_22 ( V_33 , V_44 ) ;
if ( ! V_5 ) {
F_7 ( L_7 ) ;
F_20 ( V_36 , V_30 ,
V_37 ) ;
return V_45 ;
}
if ( V_7 -> V_11 . V_13 . V_46 ) {
V_5 -> V_47 = 0 ;
V_5 -> V_30 = V_30 ;
V_5 -> V_48 = 1 ;
} else
V_5 -> V_30 = V_5 -> V_47 = V_30 ;
sprintf ( V_5 -> V_17 , L_8 , ( int ) V_5 -> V_30 ) ;
V_5 -> V_31 = V_31 ;
V_5 -> V_49 =
(struct V_43 * * ) ( ( char * ) V_5 + sizeof( struct V_4 ) ) ;
V_5 -> V_50 = V_7 -> V_39 . V_40 . V_50 ;
V_5 -> V_51 = 0 ;
V_5 -> V_52 = NULL ;
F_23 ( & V_53 ) ;
for ( V_32 = V_54 ; V_32 ; V_32 = V_32 -> V_55 ) {
if ( V_32 -> V_30 == V_5 -> V_30 )
break;
}
F_24 ( & V_53 ) ;
if ( V_32 ) {
F_7 ( L_9 ,
V_5 -> V_30 ) ;
F_20 ( V_36 , V_5 -> V_30 ,
V_37 ) ;
F_25 ( V_5 ) ;
return V_56 ;
}
if ( ( V_7 -> V_39 . V_40 . V_22 != 0 )
&& ( V_7 -> V_39 . V_40 . V_23 != 0 ) ) {
V_5 -> V_51 = V_7 -> V_39 . V_40 . V_23 ;
V_5 -> V_52 =
F_11 ( V_7 -> V_39 . V_40 . V_22 ,
V_7 -> V_39 . V_40 . V_23 ,
V_7 -> V_11 . V_13 . V_15 ) ;
}
if ( ! V_7 -> V_11 . V_13 . V_15 ) {
struct V_57 V_39 ;
V_39 . V_58 = V_59 ;
V_39 . V_60 . V_30 = V_30 ;
V_39 . V_60 . V_61 = V_5 -> V_52 ;
V_39 . V_60 . V_31 = V_31 ;
V_39 . V_60 . V_62 = V_7 -> V_39 . V_40 . V_63 ;
V_39 . V_60 . V_50 = V_7 -> V_39 . V_40 . V_50 ;
if ( ! V_64 ) {
F_7 ( L_10 ) ;
F_20 ( V_36 , V_5 -> V_30 ,
V_37 ) ;
F_25 ( V_5 ) ;
return V_65 ;
}
if ( ! V_64 ( & V_39 ) ) {
F_7 ( L_11 ) ;
F_20 ( V_36 , V_5 -> V_30 ,
V_37 ) ;
F_25 ( V_5 ) ;
return
V_66 ;
}
}
F_5 ( V_5 ) ;
F_26 ( & V_53 ) ;
if ( ! V_54 )
V_54 = V_5 ;
else {
V_5 -> V_55 = V_54 ;
V_54 = V_5 ;
}
V_35 ++ ;
F_27 ( & V_53 ) ;
F_20 ( V_67 , V_5 -> V_30 ,
V_42 ) ;
return V_68 ;
}
static int
F_28 ( T_1 * V_7 , char * V_29 )
{
int V_69 ;
struct V_4 * V_5 , * V_70 = NULL ;
T_2 V_30 ;
V_30 = V_7 -> V_39 . V_71 . V_30 ;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_70 = V_5 , V_5 = V_5 -> V_55 ) {
if ( V_5 -> V_30 == V_30 ) {
for ( V_69 = 0 ; V_69 < V_5 -> V_31 ; V_69 ++ ) {
if ( V_5 -> V_49 [ V_69 ] != NULL ) {
F_7 ( L_12 ,
V_69 , V_30 ) ;
F_24 ( & V_53 ) ;
return V_72 ;
}
}
F_24 ( & V_53 ) ;
if ( ! V_7 -> V_11 . V_13 . V_15 ) {
struct V_57 V_39 ;
V_39 . V_58 = V_73 ;
V_39 . V_74 . V_30 = V_30 ;
if ( ! V_64 ) {
F_7 ( L_13 ) ;
return V_65 ;
}
if ( ! V_64 ( & V_39 ) ) {
F_7 ( L_14 ) ;
return V_66 ;
}
}
F_26 ( & V_53 ) ;
if ( V_70 )
V_70 -> V_55 = V_5 -> V_55 ;
else
V_54 = V_5 -> V_55 ;
V_35 -- ;
F_27 ( & V_53 ) ;
break;
}
}
if ( ! V_5 ) {
F_7 ( L_15 ,
V_30 ) ;
F_24 ( & V_53 ) ;
return V_56 ;
}
if ( V_5 -> V_19 ) {
F_9 ( L_2 , V_5 -> V_16 ) ;
V_5 -> V_19 = NULL ;
}
if ( V_5 -> V_16 ) {
F_9 ( V_5 -> V_17 , V_18 ) ;
V_5 -> V_16 = NULL ;
}
if ( V_5 -> V_52 ) {
F_16 ( V_5 -> V_52 ) ;
V_5 -> V_52 = NULL ;
}
F_25 ( V_5 ) ;
return V_68 ;
}
static int
F_29 ( T_1 * V_7 , char * V_29 )
{
struct V_43 * V_75 ;
struct V_4 * V_5 ;
T_2 V_30 , V_76 ;
int V_77 = V_68 ;
T_5 V_78 = V_79 ;
T_7 * V_80 ;
V_30 = V_7 -> V_39 . V_81 . V_30 ;
V_76 = V_7 -> V_39 . V_81 . V_76 ;
F_21 ( V_82 , V_76 , V_30 ,
V_42 ) ;
V_75 = F_22 ( sizeof( struct V_43 ) , V_44 ) ;
if ( ! V_75 ) {
F_7 ( L_16 ) ;
F_21 ( V_83 , V_76 , V_30 ,
V_37 ) ;
return V_45 ;
}
V_75 -> V_84 = V_7 -> V_39 . V_81 . V_85 ;
V_75 -> V_86 = V_7 -> V_39 . V_81 . V_86 ;
V_75 -> V_22 = V_7 -> V_39 . V_81 . V_22 ;
V_75 -> V_30 = V_30 ;
V_75 -> V_76 = V_76 ;
F_30 ( & V_75 -> V_87 , 1 ) ;
sprintf ( V_75 -> V_88 , L_17 , ( unsigned ) V_30 , ( unsigned ) V_76 ) ;
if ( V_7 -> V_11 . V_13 . V_46 )
V_75 -> V_61 = ( void T_4 * ) F_31 ( V_75 -> V_22 ) ;
else {
V_80 = F_32 ( V_75 -> V_84 ) ;
if ( V_80 )
V_78 = V_80 -> V_89 ;
if ( V_78 > V_7 -> V_39 . V_81 . V_23 ) {
F_7 ( L_18 ,
( V_90 ) V_7 -> V_39 . V_81 . V_23 ,
( V_90 ) V_78 ) ;
F_21 ( V_83 , V_76 , V_30 ,
V_37 ) ;
V_77 = V_91 ;
goto V_27;
}
V_75 -> V_61 =
F_12 ( V_75 -> V_22 ,
V_7 -> V_39 . V_81 . V_23 ) ;
if ( ! V_75 -> V_61 ) {
F_7 ( L_19 ,
V_75 -> V_22 ,
V_7 -> V_39 . V_81 . V_23 ) ;
V_77 = V_92 ;
F_21 ( V_83 , V_76 , V_30 ,
V_37 ) ;
goto V_27;
}
}
V_75 -> V_93 = V_7 -> V_39 . V_81 . V_93 ;
V_75 -> V_23 = V_7 -> V_39 . V_81 . V_23 ;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
if ( V_5 -> V_30 == V_30 ) {
if ( V_76 >= V_5 -> V_31 ) {
F_7 ( L_20 ,
V_76 , V_5 -> V_31 ) ;
V_77 = V_94 ;
F_21 ( V_83 ,
V_76 , V_30 ,
V_37 ) ;
F_24 ( & V_53 ) ;
goto V_27;
}
if ( V_5 -> V_49 [ V_76 ] ) {
F_7 ( L_21 ,
V_76 ) ;
F_21 ( V_83 ,
V_76 , V_30 ,
V_37 ) ;
V_77 = V_56 ;
F_24 ( & V_53 ) ;
goto V_27;
}
F_24 ( & V_53 ) ;
if ( ! V_7 -> V_11 . V_13 . V_15 ) {
struct V_57 V_39 ;
if ( ! memcmp
( & V_75 -> V_84 ,
& V_95 ,
sizeof( V_96 ) ) ) {
F_33 ( ( ( V_97
T_4 * ) ( V_75 ->
V_61 ) ) ->
Type ) ;
if ( ! F_34
( V_75 -> V_61 , NULL ) ) {
F_7 ( L_22 ,
V_76 ) ;
F_21
( V_83 ,
V_76 , V_30 ,
V_37 ) ;
V_77 = V_98 ;
goto V_27;
}
V_39 . V_58 = V_99 ;
V_39 . V_100 . V_61 = V_75 -> V_61 ;
V_39 . V_100 . V_30 = V_30 ;
V_39 . V_100 . V_101 = V_76 ;
V_39 . V_100 . V_93 =
V_75 -> V_93 ;
V_39 . V_100 . V_86 = V_75 -> V_86 ;
} else
if ( ! memcmp
( & V_75 -> V_84 ,
& V_102 ,
sizeof( V_96 ) ) ) {
F_33 ( ( ( V_97
T_4 * ) ( V_75 ->
V_61 ) ) ->
Type ) ;
if ( ! F_35
( V_75 -> V_61 , NULL ) ) {
F_7 ( L_23 ,
V_76 ) ;
F_21
( V_83 ,
V_76 , V_30 ,
V_37 ) ;
V_77 = V_98 ;
goto V_27;
}
V_39 . V_58 = V_103 ;
V_39 . V_104 . V_61 = V_75 -> V_61 ;
V_39 . V_104 . V_30 = V_30 ;
V_39 . V_104 . V_101 = V_76 ;
V_39 . V_104 . V_93 =
V_75 -> V_93 ;
V_39 . V_100 . V_86 = V_75 -> V_86 ;
} else {
F_7 ( L_24 ) ;
F_21
( V_83 , V_76 ,
V_30 , V_37 ) ;
V_77 = V_105 ;
goto V_27;
}
if ( ! V_64 ) {
F_7 ( L_25 ) ;
F_21
( V_83 , V_76 ,
V_30 , V_37 ) ;
V_77 = V_65 ;
goto V_27;
}
if ( ! V_64 ( & V_39 ) ) {
F_7 ( L_26 ) ;
F_21
( V_83 , V_76 ,
V_30 , V_37 ) ;
V_77 = V_66 ;
goto V_27;
}
}
V_5 -> V_49 [ V_76 ] = V_75 ;
F_21 ( V_106 , V_76 , V_30 ,
V_42 ) ;
return V_68 ;
}
}
F_24 ( & V_53 ) ;
F_7 ( L_27 , V_30 ) ;
F_21 ( V_83 , V_76 , V_30 ,
V_37 ) ;
V_77 = V_107 ;
V_27:
if ( ! V_7 -> V_11 . V_13 . V_46 ) {
F_16 ( V_75 -> V_61 ) ;
V_75 -> V_61 = NULL ;
}
F_25 ( V_75 ) ;
return V_77 ;
}
static int
F_36 ( T_1 * V_7 )
{
T_2 V_30 , V_76 ;
struct V_4 * V_5 ;
struct V_43 * V_75 ;
struct V_57 V_39 ;
V_30 = V_7 -> V_39 . V_108 . V_30 ;
V_76 = V_7 -> V_39 . V_108 . V_76 ;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
if ( V_5 -> V_30 == V_30 ) {
if ( V_76 >= V_5 -> V_31 ) {
F_7 ( L_28 ,
V_76 , V_5 -> V_31 ) ;
F_24 ( & V_53 ) ;
return V_109 ;
}
V_75 = V_5 -> V_49 [ V_76 ] ;
if ( ! V_75 ) {
F_7 ( L_29 ,
V_76 ) ;
F_24 ( & V_53 ) ;
return V_56 ;
}
F_24 ( & V_53 ) ;
if ( ! memcmp
( & V_75 -> V_84 ,
& V_95 , sizeof( V_96 ) ) ) {
V_39 . V_58 = V_110 ;
V_39 . V_111 . V_61 = V_75 -> V_61 ;
} else
if ( ! memcmp
( & V_75 -> V_84 ,
& V_102 ,
sizeof( V_96 ) ) ) {
V_39 . V_58 = V_112 ;
V_39 . V_113 . V_61 = V_75 -> V_61 ;
} else {
F_7 ( L_30 ) ;
return
V_105 ;
}
if ( ! V_64 ) {
F_7 ( L_31 ) ;
return
V_65 ;
}
if ( ! V_64 ( & V_39 ) ) {
F_7 ( L_32 ) ;
return V_66 ;
}
break;
}
}
if ( ! V_5 ) {
F_7 ( L_33 ,
V_30 ) ;
F_24 ( & V_53 ) ;
return V_107 ;
}
return V_68 ;
}
static int
F_37 ( T_1 * V_7 )
{
T_2 V_30 , V_76 ;
struct V_4 * V_5 ;
struct V_43 * V_75 ;
struct V_57 V_39 ;
V_30 = V_7 -> V_39 . V_108 . V_30 ;
V_76 = V_7 -> V_39 . V_108 . V_76 ;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
if ( V_5 -> V_30 == V_30 ) {
if ( V_76 >= V_5 -> V_31 ) {
F_7 ( L_34 ,
V_76 , V_5 -> V_31 ) ;
F_24 ( & V_53 ) ;
return V_109 ;
}
V_75 = V_5 -> V_49 [ V_76 ] ;
if ( ! V_75 ) {
F_7 ( L_35 ,
V_76 ) ;
F_24 ( & V_53 ) ;
return V_56 ;
}
F_24 ( & V_53 ) ;
if ( ! memcmp ( & V_75 -> V_84 ,
& V_95 ,
sizeof( V_96 ) ) ) {
V_39 . V_58 = V_114 ;
V_39 . V_115 . V_61 = V_75 -> V_61 ;
} else
if ( ! memcmp ( & V_75 -> V_84 ,
& V_102 ,
sizeof( V_96 ) ) ) {
V_39 . V_58 = V_116 ;
V_39 . V_117 . V_61 = V_75 -> V_61 ;
} else {
F_7 ( L_36 ) ;
return
V_105 ;
}
if ( ! V_64 ) {
F_7 ( L_31 ) ;
return
V_65 ;
}
if ( ! V_64 ( & V_39 ) ) {
F_7 ( L_37 ) ;
return V_66 ;
}
break;
}
}
if ( ! V_5 ) {
F_7 ( L_38 ,
V_30 ) ;
F_24 ( & V_53 ) ;
return V_107 ;
}
return V_68 ;
}
static int
F_38 ( T_1 * V_7 , char * V_29 )
{
T_2 V_30 , V_76 ;
struct V_4 * V_5 ;
struct V_43 * V_75 ;
struct V_57 V_39 ;
V_30 = V_7 -> V_39 . V_118 . V_30 ;
V_76 = V_7 -> V_39 . V_118 . V_76 ;
F_23 ( & V_53 ) ;
F_39 ( L_39 , V_30 , V_76 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
if ( V_5 -> V_30 == V_30 ) {
if ( V_76 >= V_5 -> V_31 ) {
F_7 ( L_40 ,
V_76 , V_5 -> V_31 ) ;
F_24 ( & V_53 ) ;
return V_109 ;
}
V_75 = V_5 -> V_49 [ V_76 ] ;
if ( ! V_75 ) {
F_7 ( L_41 ,
V_76 ) ;
F_24 ( & V_53 ) ;
return V_56 ;
}
F_24 ( & V_53 ) ;
if ( ! memcmp
( & V_75 -> V_84 ,
& V_95 , sizeof( V_96 ) ) ) {
V_39 . V_58 = V_119 ;
V_39 . V_120 . V_61 = V_75 -> V_61 ;
} else
if ( ! memcmp
( & V_75 -> V_84 ,
& V_102 ,
sizeof( V_96 ) ) ) {
V_39 . V_58 = V_121 ;
V_39 . V_122 . V_61 = V_75 -> V_61 ;
} else {
F_7 ( L_42 ) ;
return
V_105 ;
}
if ( ! V_64 ) {
F_7 ( L_43 ) ;
return
V_65 ;
}
if ( ! V_64 ( & V_39 ) ) {
F_7 ( L_44 ) ;
return V_66 ;
}
if ( V_75 -> V_123 ) {
F_39 ( L_45 ) ;
F_40 ( V_30 , V_76 ) ;
}
if ( ! V_7 -> V_11 . V_13 . V_46 ) {
F_39 ( L_46 ) ;
F_16 ( V_75 -> V_61 ) ;
}
F_25 ( V_75 ) ;
V_5 -> V_49 [ V_76 ] = NULL ;
break;
}
}
if ( ! V_5 ) {
F_7 ( L_47 ,
V_30 ) ;
F_24 ( & V_53 ) ;
return V_107 ;
}
return V_68 ;
}
static int
F_41 ( T_1 * V_7 , char * V_29 )
{
F_42 ( V_124 , V_42 ) ;
V_34 = V_7 -> V_39 . V_125 . V_126 ;
V_127 = V_7 -> V_39 . V_125 . V_128 ;
V_129 = 0 ;
if ( ! V_7 -> V_11 . V_13 . V_46 )
F_43 ( V_64 ) ;
V_130 = 1 ;
F_42 ( V_131 , V_42 ) ;
return V_68 ;
}
static int
F_44 ( T_1 * V_7 , char * V_29 )
{
if ( V_54 ) {
F_7 ( L_48 ) ;
return V_132 ;
}
if ( V_35 ) {
F_7 ( L_49 ) ;
return V_132 ;
}
return F_45 () ;
}
static int
F_46 ( T_2 V_30 )
{
T_1 V_7 ;
F_4 ( & V_7 , V_133 , 0 , 0 ) ;
V_7 . V_39 . V_71 . V_30 = V_30 ;
if ( F_28 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_50 , V_30 ) ;
return 0 ;
}
return 1 ;
}
static int
F_47 ( T_2 V_30 , T_2 V_76 )
{
T_1 V_7 ;
F_4 ( & V_7 , V_134 , 0 , 0 ) ;
V_7 . V_39 . V_118 . V_30 = V_30 ;
V_7 . V_39 . V_118 . V_76 = V_76 ;
if ( F_38 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_51 , V_30 ,
V_76 ) ;
return 0 ;
}
return 1 ;
}
int
F_48 ( T_2 V_30 , V_96 V_135 ,
T_5 V_22 , V_90 V_136 )
{
T_1 V_7 ;
F_39 ( L_52 , V_30 ) ;
F_20 ( V_124 , V_30 , V_42 ) ;
if ( ! V_130 ) {
F_4 ( & V_7 , V_137 , 0 , 0 ) ;
V_7 . V_39 . V_125 . V_126 = 23 ;
V_7 . V_39 . V_125 . V_138 = 0 ;
if ( F_41 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_53 ) ;
return 0 ;
}
F_39 ( L_54 ) ;
F_20 ( V_131 , V_30 ,
V_42 ) ;
}
F_20 ( V_41 , V_30 , V_139 ) ;
F_4 ( & V_7 , V_140 , 0 , 0 ) ;
V_7 . V_39 . V_40 . V_30 = V_30 ;
V_7 . V_39 . V_40 . V_31 = 23 ;
V_7 . V_39 . V_40 . V_22 = V_22 ;
V_7 . V_39 . V_40 . V_23 = V_136 ;
if ( F_19 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_55 ) ;
F_20 ( V_36 , V_30 ,
V_37 ) ;
return 0 ;
}
F_20 ( V_67 , V_30 , V_42 ) ;
return 1 ;
}
int
F_49 ( T_2 V_30 )
{
return F_46 ( V_30 ) ;
}
int
F_50 ( T_2 V_30 , T_2 V_76 )
{
T_1 V_7 ;
int V_25 ;
F_4 ( & V_7 , V_141 , 0 , 0 ) ;
V_7 . V_39 . V_108 . V_30 = V_30 ;
V_7 . V_39 . V_108 . V_76 = V_76 ;
V_7 . V_39 . V_108 . V_142 = V_143 ;
V_25 = F_36 ( & V_7 ) ;
if ( V_25 != V_68 ) {
F_7 ( L_56 ,
V_30 , V_76 ) ;
return V_25 ;
}
return 0 ;
}
int
F_51 ( T_2 V_30 , T_2 V_76 )
{
T_1 V_7 ;
int V_25 ;
F_4 ( & V_7 , V_141 , 0 , 0 ) ;
V_7 . V_39 . V_108 . V_30 = V_30 ;
V_7 . V_39 . V_108 . V_76 = V_76 ;
V_7 . V_39 . V_108 . V_142 = V_144 ;
V_25 = F_37 ( & V_7 ) ;
if ( V_25 != V_68 ) {
F_7 ( L_57 ,
V_30 , V_76 ) ;
return V_25 ;
}
return 0 ;
}
int
F_52 ( T_2 V_30 , T_2 V_76 ,
T_5 V_145 , T_2 V_146 ,
int V_147 , V_96 V_135 ,
struct V_148 * V_86 )
{
T_1 V_7 ;
F_39 ( L_58 , V_30 , V_76 ) ;
F_21 ( V_149 , V_76 , V_30 ,
V_42 ) ;
F_4 ( & V_7 , V_150 , 0 , 0 ) ;
if ( V_147 )
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_81 . V_30 = V_30 ;
V_7 . V_39 . V_81 . V_76 = V_76 ;
V_7 . V_39 . V_81 . V_93 = V_135 ;
if ( V_86 )
V_7 . V_39 . V_81 . V_86 = * V_86 ;
else
memset ( & V_7 . V_39 . V_81 . V_86 , 0 ,
sizeof( struct V_148 ) ) ;
V_7 . V_39 . V_81 . V_22 = V_145 ;
if ( V_146 < V_79 ) {
F_7 ( L_59 ,
V_146 , ( unsigned int ) V_79 ) ;
F_21 ( V_151 , V_146 ,
V_79 , V_37 ) ;
return 0 ;
}
V_7 . V_39 . V_81 . V_23 = V_146 ;
V_7 . V_39 . V_81 . V_85 = V_95 ;
if ( F_29 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_60 ) ;
F_21 ( V_151 , V_76 , V_30 ,
V_37 ) ;
return 0 ;
}
F_21 ( V_152 , V_76 , V_30 ,
V_42 ) ;
return 1 ;
}
int
F_53 ( T_2 V_30 , T_2 V_76 )
{
return F_47 ( V_30 , V_76 ) ;
}
int
F_54 ( T_2 V_30 , T_2 V_76 ,
T_5 V_145 , T_2 V_146 ,
int V_147 , V_96 V_135 ,
struct V_148 * V_86 )
{
T_1 V_7 ;
F_39 ( L_58 , V_30 , V_76 ) ;
F_21 ( V_153 , V_76 , V_30 ,
V_42 ) ;
F_4 ( & V_7 , V_150 , 0 , 0 ) ;
if ( V_147 )
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_81 . V_30 = V_30 ;
V_7 . V_39 . V_81 . V_76 = V_76 ;
V_7 . V_39 . V_81 . V_93 = V_135 ;
if ( V_86 )
V_7 . V_39 . V_81 . V_86 = * V_86 ;
else
memset ( & V_7 . V_39 . V_81 . V_86 , 0 ,
sizeof( struct V_148 ) ) ;
V_7 . V_39 . V_81 . V_22 = V_145 ;
if ( V_146 < V_79 ) {
F_7 ( L_59 ,
V_146 , ( unsigned int ) V_79 ) ;
F_21 ( V_154 , V_146 ,
V_79 , V_37 ) ;
return 0 ;
}
V_7 . V_39 . V_81 . V_23 = V_146 ;
V_7 . V_39 . V_81 . V_85 = V_102 ;
if ( F_29 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_61 ) ;
F_21 ( V_154 , V_76 , V_30 ,
V_37 ) ;
return 0 ;
}
F_21 ( V_155 , V_76 , V_30 ,
V_42 ) ;
return 1 ;
}
int
F_55 ( T_2 V_30 , T_2 V_76 )
{
T_1 V_7 ;
int V_25 ;
F_4 ( & V_7 , V_141 , 0 , 0 ) ;
V_7 . V_39 . V_108 . V_30 = V_30 ;
V_7 . V_39 . V_108 . V_76 = V_76 ;
V_7 . V_39 . V_108 . V_142 = V_143 ;
V_25 = F_36 ( & V_7 ) ;
if ( V_25 != V_68 ) {
F_7 ( L_62 ,
V_30 , V_76 ) ;
return - 1 ;
}
return 0 ;
}
int
F_56 ( T_2 V_30 , T_2 V_76 )
{
T_1 V_7 ;
int V_25 ;
F_4 ( & V_7 , V_141 , 0 , 0 ) ;
V_7 . V_39 . V_108 . V_30 = V_30 ;
V_7 . V_39 . V_108 . V_76 = V_76 ;
V_7 . V_39 . V_108 . V_142 = V_144 ;
V_25 = F_37 ( & V_7 ) ;
if ( V_25 != V_68 ) {
F_7 ( L_63 ,
V_30 , V_76 ) ;
return - 1 ;
}
return 0 ;
}
int
F_57 ( T_2 V_30 , T_2 V_76 )
{
return F_47 ( V_30 , V_76 ) ;
}
static int
F_58 ( T_2 V_30 )
{
BOOL V_156 = FALSE ;
int V_76 = 0 ;
V_96 V_157 = V_158 ;
T_1 V_7 ;
F_4 ( & V_7 , V_140 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_40 . V_30 = V_30 ;
V_7 . V_39 . V_40 . V_31 = 4 ;
V_7 . V_39 . V_40 . V_22 = 0 ;
V_7 . V_39 . V_40 . V_23 = 0 ;
if ( F_19 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_64 ) ;
return 0 ;
}
V_156 = TRUE ;
F_4 ( & V_7 , V_150 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_81 . V_30 = V_30 ;
V_7 . V_39 . V_81 . V_76 = V_76 ;
V_7 . V_39 . V_81 . V_93 = V_157 ;
memset ( & V_7 . V_39 . V_81 . V_86 , 0 , sizeof( struct V_148 ) ) ;
V_7 . V_39 . V_81 . V_22 = V_129 ;
V_7 . V_39 . V_81 . V_23 = V_79 ;
V_7 . V_39 . V_81 . V_85 = V_102 ;
if ( F_29 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_65 ) ;
goto V_159;
}
return 1 ;
V_159:
if ( V_156 ) {
F_4 ( & V_7 , V_133 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_71 . V_30 = V_30 ;
if ( F_28 ( & V_7 , NULL ) != V_68 )
F_7 ( L_66 ) ;
}
return 0 ;
}
static int
F_59 ( T_2 V_30 )
{
int V_76 = 0 ;
T_1 V_7 ;
F_4 ( & V_7 , V_134 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_118 . V_30 = V_30 ;
V_7 . V_39 . V_118 . V_76 = V_76 ;
if ( F_38 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_67 ) ;
}
F_4 ( & V_7 , V_133 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_71 . V_30 = V_30 ;
if ( F_28 ( & V_7 , NULL ) != V_68 )
F_7 ( L_66 ) ;
return 1 ;
}
void *
F_60 ( struct V_160 * V_161 , char * V_162 , int V_163 )
{
void * V_164 = F_61 ( V_161 , V_44 | V_165 ) ;
if ( V_164 == NULL ) {
F_7 ( L_68 ,
V_162 , V_163 ) ;
return NULL ;
}
return V_164 ;
}
void
F_62 ( struct V_160 * V_161 , void * V_164 , char * V_162 , int V_163 )
{
if ( V_164 == NULL ) {
F_7 ( L_69 , V_162 , V_163 ) ;
return;
}
F_63 ( V_161 , V_164 ) ;
}
static T_8
F_64 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
int V_169 = 0xffff , V_30 = 0 , V_69 , V_77 = 0 ;
char V_29 [ 4 ] ;
char V_170 ;
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_70 ) ;
return - V_172 ;
}
V_69 = sscanf ( V_29 , L_71 , & V_169 , & V_170 ) ;
if ( V_69 != 2 ) {
F_7 ( L_72 ) ;
return - V_172 ;
}
if ( ( V_170 != '-' ) && ( V_170 != '+' ) ) {
F_7 ( L_73 ) ;
return - V_172 ;
}
switch ( V_169 ) {
case 0 :
V_30 = 0 ;
if ( V_170 == '+' )
V_77 = F_58 ( V_30 ) ;
else
V_77 = F_59 ( V_30 ) ;
if ( ! V_77 ) {
F_7 ( L_74 ,
V_170 ) ;
return - V_172 ;
}
return V_167 ;
default:
break;
}
F_7 ( L_75 ) ;
F_7 ( L_76 ) ;
F_7 ( L_77 ) ;
F_7 ( L_78 ) ;
F_7 ( L_79 ) ;
F_7 ( L_80 ) ;
F_7 ( L_76 ) ;
return V_167 ;
}
static T_8
F_67 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
int V_69 , V_169 = 0xffff ;
char V_29 [ 4 ] ;
T_1 V_7 ;
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
memset ( & V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_81 ) ;
return - V_172 ;
}
if ( V_130 ) {
F_39 ( L_82 ) ;
return - V_172 ;
}
V_69 = sscanf ( V_29 , L_83 , & V_169 ) ;
switch ( V_169 ) {
case 1 :
F_4 ( & V_7 , V_137 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 0 ;
V_7 . V_39 . V_125 . V_126 = 23 ;
V_7 . V_39 . V_125 . V_138 = 23 ;
if ( F_41 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_53 ) ;
return 0 ;
}
return 1 ;
case 2 :
F_4 ( & V_7 , V_137 , 0 , 0 ) ;
V_7 . V_11 . V_13 . V_46 = 1 ;
V_7 . V_39 . V_125 . V_126 = 23 ;
V_7 . V_39 . V_125 . V_138 = 23 ;
if ( F_41 ( & V_7 , NULL ) != V_68 ) {
F_7 ( L_53 ) ;
return 0 ;
}
return 1 ;
default:
break;
}
F_7 ( L_84 ) ;
F_7 ( L_85 ) ;
return - V_172 ;
}
static int
F_68 ( char * * V_173 , int * V_174 )
{
int V_69 , V_175 = 0 ;
struct V_4 * V_5 ;
if ( F_69 ( L_86 ) < 0 )
goto V_176;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
if ( F_69 ( L_87 ,
V_5 , V_5 -> V_30 , V_5 -> V_31 ) < 0 )
goto V_177;
if ( F_69 ( L_88 ) < 0 )
goto V_177;
for ( V_69 = 0 ; V_69 < V_5 -> V_31 ; V_69 ++ ) {
if ( V_5 -> V_49 [ V_69 ] ) {
if ( F_69 ( L_89 ,
V_5 -> V_30 , V_69 , V_5 -> V_49 [ V_69 ] ,
V_5 -> V_49 [ V_69 ] -> V_61 ,
V_5 -> V_49 [ V_69 ] -> V_178 ) < 0 )
goto V_177;
if ( F_69 ( L_90 ,
V_5 -> V_49 [ V_69 ] -> V_179 ,
V_5 -> V_49 [ V_69 ] -> V_180 ,
V_5 -> V_49 [ V_69 ] -> V_181 ) < 0 )
goto V_177;
}
}
}
F_24 ( & V_53 ) ;
if ( F_69 ( L_91 ,
F_70 ( & V_182 ) ) < 0 )
goto V_176;
if ( F_69 ( L_92 ,
V_183 , V_184 ) < 0 )
goto V_176;
if ( F_69 ( L_93 ,
V_185 , V_186 , V_187 ) < 0 )
goto V_176;
if ( F_69 ( L_94 , V_188 ) < 0 )
goto V_176;
if ( F_69 ( L_95 , V_189 ) < 0 )
goto V_176;
return V_175 ;
V_177:
F_24 ( & V_53 ) ;
V_176:
return - 1 ;
}
static T_8
F_71 ( struct V_2 * V_2 , char T_9 * V_29 , T_6 V_190 , T_10 * V_191 )
{
char * V_192 ;
int V_193 = 0 ;
int V_194 = V_195 ;
if ( V_196 == NULL ) {
F_72 ( L_96 ) ;
V_196 = F_73 ( V_195 ) ;
if ( V_196 == NULL ) {
F_7 ( L_97 ) ;
return - V_197 ;
}
}
V_192 = V_196 ;
if ( ( * V_191 == 0 ) || ( ! V_198 ) ) {
F_72 ( L_98 ) ;
V_193 = F_68 ( & V_192 , & V_194 ) ;
V_198 = 1 ;
} else
V_193 = strlen ( V_196 ) ;
return F_74 ( V_29 , V_190 , V_191 ,
V_196 , V_193 ) ;
}
static T_8
F_75 ( struct V_2 * V_2 , char T_9 * V_29 ,
T_6 V_190 , T_10 * V_191 )
{
int V_199 = 0 ;
char * V_200 ;
T_10 V_201 = * V_191 ;
if ( V_201 < 0 )
return - V_171 ;
if ( V_201 > 0 || ! V_190 )
return 0 ;
V_200 = F_22 ( V_190 , V_202 ) ;
if ( ! V_200 )
return - V_197 ;
V_199 = sprintf ( V_200 , L_99 , V_127 ) ;
if ( F_76 ( V_29 , V_200 , V_199 ) ) {
F_25 ( V_200 ) ;
return - V_172 ;
}
F_25 ( V_200 ) ;
* V_191 += V_199 ;
return V_199 ;
}
static int
V_6 ( struct V_203 * V_204 , void * V_205 )
{
struct V_4 * V_5 = V_204 -> V_206 ;
int V_69 , V_207 , V_208 ;
char V_29 [ 999 ] ;
if ( V_5 == NULL )
return 0 ;
F_77 ( V_204 , L_100 ,
V_5 -> V_209 , V_5 -> V_30 ) ;
if ( ( V_5 -> V_51 == 0 ) || ( V_5 -> V_52 == NULL ) )
return 0 ;
V_207 =
( V_5 -> V_51 -
sizeof( V_210 ) ) /
sizeof( V_211 ) ;
V_208 = F_78 ( & V_5 -> V_52 -> V_212 , V_29 ,
sizeof( V_29 ) - 1 , - 1 ) ;
V_29 [ V_208 ] = '\0' ;
F_77 ( V_204 , L_101 , V_29 ) ;
V_208 = F_78 ( & V_5 -> V_52 -> V_213 ,
V_29 , sizeof( V_29 ) - 1 , - 1 ) ;
V_29 [ V_208 ] = '\0' ;
F_77 ( V_204 , L_101 , V_29 ) ;
for ( V_69 = 0 ; V_69 < V_207 ; V_69 ++ ) {
V_208 = F_78 ( & V_5 -> V_52 ->
V_214 [ V_69 ] , V_29 ,
sizeof( V_29 ) - 1 , V_69 ) ;
if ( V_208 > 0 ) {
V_29 [ V_208 ] = '\0' ;
F_77 ( V_204 , L_101 , V_29 ) ;
}
}
return 0 ;
}
static T_8
F_79 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
int V_215 = 0 ;
int V_69 , V_169 = 0xffff , V_77 ;
char V_29 [ 16 ] ;
T_1 V_7 ;
T_2 V_30 , V_31 ;
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
memset ( & V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_102 ) ;
return - V_172 ;
}
V_69 = sscanf ( V_29 , L_103 , & V_169 , & V_30 , & V_31 ) ;
switch ( V_169 ) {
case 0 :
if ( V_69 != 2 )
break;
F_4 ( & V_7 , V_133 , 0 , V_215 ) ;
V_7 . V_39 . V_71 . V_30 = V_30 ;
V_77 = F_28 ( & V_7 , NULL ) ;
if ( V_77 != V_68 ) {
F_7 ( L_104 ,
V_30 , V_77 ) ;
return - V_172 ;
}
return V_167 ;
case 1 :
if ( V_69 != 3 )
break;
F_4 ( & V_7 , V_140 , 0 , V_215 ) ;
V_7 . V_39 . V_40 . V_30 = V_30 ;
V_7 . V_39 . V_40 . V_31 = V_31 ;
V_77 = F_19 ( & V_7 , NULL ) ;
if ( V_77 != V_68 ) {
F_7 ( L_105 ,
V_30 , V_31 , V_77 ) ;
return - V_172 ;
}
return V_167 ;
default:
break;
}
F_7 ( L_106 ) ;
F_7 ( L_76 ) ;
F_7 ( L_107 ) ;
F_7 ( L_108 ) ;
F_7 ( L_109 ) ;
F_7 ( L_76 ) ;
F_7 ( L_110 ) ;
F_7 ( L_111 ) ;
F_7 ( L_112 ) ;
return - V_172 ;
}
static T_8
F_80 ( struct V_2 * V_2 , char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
return 0 ;
}
static T_8
F_81 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
int V_215 = 0 ;
T_1 V_7 ;
T_2 V_30 , V_76 ;
char V_29 [ 32 ] ;
unsigned int V_61 ;
int type , V_69 , V_169 = 0xffff , V_77 ;
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_113 ) ;
return - V_172 ;
}
V_69 = sscanf ( V_29 , L_114 ,
& V_169 , & V_30 , & V_76 , & V_61 , & type ) ;
switch ( V_169 ) {
case 0 :
if ( V_69 != 3 )
break;
F_4 ( & V_7 , V_134 , 0 , V_215 ) ;
V_7 . V_39 . V_118 . V_30 = V_30 ;
V_7 . V_39 . V_118 . V_76 = V_76 ;
V_77 = F_38 ( & V_7 , NULL ) ;
if ( V_77 != V_68 ) {
F_7 ( L_115 ,
V_30 , V_76 , V_77 ) ;
return - V_172 ;
}
return V_167 ;
case 1 :
if ( V_69 != 5 )
break;
F_4 ( & V_7 , V_150 , 0 , V_215 ) ;
V_7 . V_39 . V_81 . V_30 = V_30 ;
V_7 . V_39 . V_81 . V_76 = V_76 ;
V_7 . V_39 . V_81 . V_22 = F_82 ( V_61 ) ;
V_7 . V_39 . V_81 . V_23 = V_79 ;
if ( type == 0 )
V_7 . V_39 . V_81 . V_85 =
V_95 ;
else if ( type == 1 )
V_7 . V_39 . V_81 . V_85 =
V_102 ;
else {
F_7 ( L_116 ,
V_30 , V_76 , V_61 , type ) ;
return - V_172 ;
}
V_77 = F_29 ( & V_7 , NULL ) ;
if ( V_77 != V_68 ) {
if ( type == 0 )
F_7 ( L_117 ,
V_30 , V_76 , V_61 , V_77 ) ;
else
F_7 ( L_118 ,
V_30 , V_76 , V_61 , V_77 ) ;
return - V_172 ;
}
default:
break;
}
F_7 ( L_119 ) ;
F_7 ( L_76 ) ;
F_7 ( L_120 ) ;
F_7 ( L_121 ) ;
F_7 ( L_122 ) ;
F_7 ( L_76 ) ;
F_7 ( L_123 ) ;
F_7
( L_124 ) ;
F_7
( L_125 ) ;
F_7 ( L_126 ) ;
F_7 ( L_127 ) ;
F_7 ( L_76 ) ;
return - V_172 ;
}
static T_8
F_83 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
char V_29 [ 16 ] ;
#define F_84 { \
LOGERR("Incorrect Call Home Input.\n"); \
pr_info("Please pass Call Home Event Parameters in the form:\n"); \
pr_info("EventID Category Type[parameter1][parameter2][parameter3][parameter4][parameter5][parameter6]\n"); \
return -EFAULT; \
}
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
if ( V_167 == 0 )
F_84 ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_128 ) ;
return - V_172 ;
}
V_29 [ V_167 - 1 ] = '\0' ;
if ( sscanf ( V_29 , L_129 , & V_183 ) != 1 )
F_84 ;
return V_167 ;
}
static T_8
F_85 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
char V_29 [ 16 ] ;
unsigned long long V_216 ;
struct V_4 * V_5 ;
int V_69 ;
#define F_86 { \
LOGERR("Incorrect reset_counts Input.\n"); \
pr_info("Please pass the new value for the counters:\n"); \
pr_info("e.g. echo 0 > reset_counts\n"); \
return -EFAULT; \
}
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
if ( V_167 == 0 )
F_86 ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_128 ) ;
return - V_172 ;
}
V_29 [ V_167 - 1 ] = '\0' ;
if ( sscanf ( V_29 , L_130 , & V_216 ) != 1 )
F_86 ;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
for ( V_69 = 0 ; V_69 < V_5 -> V_31 ; V_69 ++ ) {
if ( V_5 -> V_49 [ V_69 ] ) {
V_5 -> V_49 [ V_69 ] -> V_179 = V_216 ;
V_5 -> V_49 [ V_69 ] -> V_180 = V_216 ;
V_5 -> V_49 [ V_69 ] -> V_181 = V_216 ;
}
}
}
F_24 ( & V_53 ) ;
V_189 = V_216 ;
V_186 = V_216 ;
V_185 = V_216 ;
V_187 = V_216 ;
return V_167 ;
}
static T_8
F_87 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
char V_29 [ 16 ] ;
int V_216 ;
#define F_88 { \
LOGERR("Incorrect smart_wakeup Input 0 disables smart_wakeup, and 1 enables smart_wakeup.\n"); \
pr_info("echo 0 > smart_wakeup\n"); \
pr_info("echo 1 > smart_wakeup\n"); \
return -EFAULT; \
}
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
if ( V_167 == 0 )
F_88 ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_128 ) ;
return - V_172 ;
}
V_29 [ V_167 - 1 ] = '\0' ;
if ( sscanf ( V_29 , L_8 , & V_216 ) != 1 )
F_88 ;
V_188 = V_216 ;
return V_167 ;
}
static T_8
F_89 ( struct V_2 * V_2 , const char T_9 * V_166 ,
T_6 V_167 , T_10 * V_168 )
{
int V_69 , V_169 = 0xffff ;
char V_29 [ 16 ] ;
T_1 V_7 ;
T_11 V_217 ;
if ( V_167 >= F_65 ( V_29 ) )
return - V_171 ;
memset ( & V_7 , 0 , sizeof( T_1 ) ) ;
if ( F_66 ( V_29 , V_166 , V_167 ) ) {
F_7 ( L_81 ) ;
return - V_172 ;
}
V_69 = sscanf ( V_29 , L_83 , & V_169 ) ;
switch ( V_169 ) {
case 6 :
V_7 . V_11 . V_12 = V_218 ;
V_7 . V_11 . V_13 . V_14 = 1 ;
F_44 ( & V_7 , NULL ) ;
break;
case 7 :
V_217 = 0 ;
F_7 ( L_131 , V_217 ) ;
V_217 = F_90 () ;
F_7 ( L_132 , V_217 ) ;
break;
case 8 :
V_217 = 60 ;
F_7 ( L_133 ,
V_217 ) ;
V_217 = F_91 ( V_217 ) ;
break;
case 9 :
V_217 = - 60 ;
F_7 ( L_134 ,
V_217 ) ;
V_217 = F_91 ( V_217 ) ;
break;
default:
F_7 ( L_135 ) ;
F_7 ( L_136 ) ;
F_7 ( L_137 ) ;
F_7 ( L_138 ) ;
return - V_172 ;
break;
}
return V_167 ;
}
static struct V_43 *
F_92 ( T_2 V_30 , T_2 V_76 )
{
struct V_4 * V_5 ;
struct V_43 * V_75 = NULL ;
F_23 ( & V_53 ) ;
for ( V_5 = V_54 ; V_5 ; V_5 = V_5 -> V_55 ) {
if ( V_5 -> V_30 == V_30 ) {
if ( V_76 >= V_5 -> V_31 ) {
F_7 ( L_139 ,
V_28 ,
( int ) ( V_30 ) , ( int ) ( V_76 ) ) ;
goto V_27;
}
V_75 = V_5 -> V_49 [ V_76 ] ;
if ( ! V_75 )
F_7 ( L_139 ,
V_28 ,
( int ) ( V_30 ) , ( int ) ( V_76 ) ) ;
goto V_27;
}
}
V_27:
F_24 ( & V_53 ) ;
return V_75 ;
}
static int
F_93 ( void * V_205 )
{
unsigned long long V_219 , V_220 , V_221 , V_222 ;
struct V_223 * V_224 = NULL ;
int V_69 ;
F_94 ( L_140 ) ;
for ( V_69 = 0 ; V_69 < 16 ; V_69 ++ ) {
V_220 = F_95 () ;
F_96 ( V_225 ,
0 , V_226 ) ;
V_219 = F_95 () ;
if ( V_184 == 0 ) {
V_184 = ( V_219 - V_220 ) ;
} else {
if ( V_184 < ( V_219 - V_220 ) )
V_184 = ( V_219 - V_220 ) ;
}
}
F_39 ( L_141 , V_184 ) ;
V_183 = V_184 ;
V_221 = 0 ;
V_227 = 0 ;
while ( 1 ) {
struct V_223 * V_228 , * V_32 ;
struct V_43 * V_75 = NULL ;
F_97 ( & V_229 ) ;
V_224 = NULL ;
F_98 (lelt, tmp, &List_Polling_Device_Channels) {
int V_25 = 0 ;
V_75 = F_99 ( V_228 , struct V_43 ,
V_230 ) ;
F_97 ( & V_75 -> V_87 ) ;
if ( V_75 -> V_231 )
V_25 = V_75 -> V_231 ( V_75 -> V_232 ) ;
else
continue;
F_100 ( & V_75 -> V_87 ) ;
if ( V_25 ) {
V_221 = 0 ;
if ( V_224 == NULL ) {
V_75 -> V_179 ++ ;
if ( !
( F_101
( V_228 ,
& V_233 ) ) ) {
V_224 = V_228 ;
V_75 -> V_180 ++ ;
} else
V_75 -> V_181 ++ ;
}
}
if ( V_234 . V_235 )
break;
}
if ( V_224 != NULL ) {
V_189 ++ ;
F_102 ( V_224 , & V_233 ) ;
}
F_100 ( & V_229 ) ;
V_219 = F_95 () ;
V_222 = V_219 - V_220 ;
V_220 = V_219 ;
if ( V_234 . V_235 )
break;
if ( V_188 == 0xFF ) {
F_39 ( L_142 ) ;
break;
}
if ( V_221 > V_183 ) {
V_227 = 0 ;
V_186 ++ ;
F_96 ( V_225 ,
V_227 ,
V_226 ) ;
V_227 = 1 ;
} else {
V_187 ++ ;
F_103 () ;
V_221 = V_221 + V_222 ;
}
}
F_72 ( L_143 ) ;
F_104 ( & V_234 . V_236 , 0 ) ;
}
static BOOL
F_105 ( void )
{
if ( V_237 )
return TRUE ;
if ( ! F_106 ( & V_234 ,
& F_93 , NULL , L_140 ) ) {
F_7 ( L_144 ) ;
return FALSE ;
}
V_237 = TRUE ;
return TRUE ;
}
void
F_107 ( T_2 V_30 , T_2 V_76 ,
int (* V_231)( void * ) ,
void * V_232 )
{
struct V_43 * V_75 ;
V_75 = F_92 ( V_30 , V_76 ) ;
if ( ! V_75 ) {
F_7 ( L_145 , V_28 , ( int ) ( V_30 ) ,
( int ) ( V_76 ) ) ;
return;
}
F_97 ( & V_229 ) ;
F_105 () ;
V_75 -> V_231 = V_231 ;
V_75 -> V_232 = V_232 ;
V_75 -> V_123 = TRUE ;
F_108 ( & ( V_75 -> V_230 ) ,
& V_233 ) ;
F_100 ( & V_229 ) ;
}
void
F_40 ( T_2 V_30 , T_2 V_76 )
{
struct V_43 * V_75 ;
V_75 = F_92 ( V_30 , V_76 ) ;
if ( ! V_75 ) {
F_7 ( L_145 , V_28 , ( int ) ( V_30 ) ,
( int ) ( V_76 ) ) ;
return;
}
F_97 ( & V_229 ) ;
F_109 ( & V_75 -> V_230 ) ;
V_75 -> V_123 = FALSE ;
V_75 -> V_231 = NULL ;
F_100 ( & V_229 ) ;
}
static void
F_110 ( struct V_238 * V_239 )
{
if ( ! V_227 ) {
V_227 = 1 ;
F_111 ( & V_225 ) ;
}
}
void
F_112 ( T_2 V_30 , T_2 V_76 )
{
if ( V_188 == 0 )
return;
if ( V_227 )
return;
V_185 ++ ;
F_113 ( & V_240 ) ;
}
static int T_12
F_114 ( void )
{
F_39 ( L_146 ) ;
F_39 ( L_147 ,
( V_90 ) sizeof( struct V_241 ) ) ;
F_39 ( L_148 ,
( V_90 ) sizeof( struct V_242 ) ) ;
F_39 ( L_149 ,
( V_90 ) sizeof( struct V_243 ) ) ;
F_39 ( L_150 ,
( V_90 ) sizeof( struct V_244 ) ) ;
F_39 ( L_151 ,
( V_90 ) sizeof( T_1 ) ) ;
F_39 ( L_152 ,
( V_90 ) sizeof( V_245 ) ) ;
F_39 ( L_153 ,
( V_90 ) sizeof( V_97 ) ) ;
F_39 ( L_154 ,
( V_90 ) sizeof( V_246 ) ) ;
F_39 ( L_155 , V_247 ) ;
F_39 ( L_156 , V_248 ) ;
V_54 = NULL ;
V_35 = V_34 = 0 ;
F_115 ( & V_53 ) ;
V_64 = NULL ;
F_42 ( V_249 , V_42 ) ;
V_250 = F_6 ( V_251 , NULL ) ;
V_18 = F_6 ( V_252 , V_250 ) ;
V_253 = F_116 ( V_254 , 0 , V_250 ,
& V_255 ) ;
F_10 ( V_253 , V_21 ) ;
V_256 =
F_116 ( V_257 , 0 , V_250 ,
& V_258 ) ;
F_10 ( V_256 , V_21 ) ;
V_259 = F_116 ( V_260 , 0 , V_250 ,
& V_261 ) ;
F_10 ( V_259 , V_21 ) ;
V_262 =
F_116 ( V_263 , 0 , V_250 ,
& V_264 ) ;
F_10 ( V_265 , V_21 ) ;
V_266 =
F_116 ( V_267 , 0 , V_250 ,
& V_268 ) ;
F_10 ( V_266 , V_21 ) ;
V_269 =
F_116 ( V_270 , 0 , V_250 ,
& V_271 ) ;
F_10 ( V_269 , V_21 ) ;
V_272 =
F_116 ( V_273 , 0 , V_250 ,
& V_274 ) ;
F_10 ( V_272 , V_21 ) ;
#ifdef F_117
V_275 = F_116 ( V_276 , 0 , V_250 ,
& V_277 ) ;
F_10 ( V_275 , V_21 ) ;
V_278 = F_116 ( V_279 , 0 , V_250 ,
& V_280 ) ;
F_10 ( V_278 , V_21 ) ;
V_281 = F_116 ( V_282 , 0 , V_250 ,
& V_283 ) ;
F_10 ( V_281 , V_21 ) ;
#endif
F_20 ( V_284 , 0 , V_42 ) ;
return 0 ;
}
static void T_13
F_118 ( void )
{
if ( V_285 )
F_9 ( V_286 , V_250 ) ;
if ( V_266 )
F_9 ( V_267 ,
V_250 ) ;
if ( V_269 )
F_9 ( V_270 , V_250 ) ;
if ( V_272 )
F_9 ( V_273 , V_250 ) ;
if ( V_287 )
F_9 ( V_288 , V_250 ) ;
if ( V_289 )
F_9 ( V_290 , V_250 ) ;
if ( V_259 )
F_9 ( V_260 , V_250 ) ;
if ( V_291 )
F_9 ( V_292 , V_250 ) ;
if ( V_293 )
F_9 ( V_294 , V_250 ) ;
if ( V_262 )
F_9 ( V_263 ,
V_250 ) ;
if ( V_278 )
F_9 ( V_279 , V_250 ) ;
if ( V_281 )
F_9 ( V_282 , V_250 ) ;
if ( V_253 )
F_9 ( V_254 , V_250 ) ;
if ( V_256 )
F_9 ( V_257 , V_250 ) ;
if ( V_18 )
F_9 ( V_252 , V_250 ) ;
if ( V_250 )
F_9 ( V_251 , NULL ) ;
if ( V_196 ) {
F_119 ( V_196 ) ;
V_196 = NULL ;
}
F_72 ( L_157 ) ;
return;
}
