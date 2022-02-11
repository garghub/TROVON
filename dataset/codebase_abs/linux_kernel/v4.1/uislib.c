static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_6 . V_3 = V_3 ;
V_2 -> V_6 . V_7 . V_8 = V_4 ;
V_2 -> V_6 . V_7 . V_9 = V_5 ;
}
static T_3 void * F_2 ( T_4 V_10 , T_1 V_11 )
{
void T_3 * V_12 = F_3 ( V_10 , V_11 ) ;
if ( ! V_12 )
return NULL ;
if ( ! F_4 ( V_12 ) ) {
F_5 ( V_12 ) ;
return NULL ;
}
return V_12 ;
}
static int
F_6 ( struct V_1 * V_2 , char * V_13 )
{
T_1 V_14 , V_15 ;
struct V_16 * V_17 , * V_18 ;
T_5 V_19 ;
if ( V_20 == V_21 ) {
F_7 ( V_22 , V_20 ,
V_23 ) ;
return V_24 ;
}
V_14 = V_2 -> V_25 . F_6 . V_14 ;
V_15 = V_2 -> V_25 . F_6 . V_15 ;
F_8 ( V_26 , V_14 , V_15 ,
V_27 ) ;
V_19 =
sizeof( struct V_16 ) +
( V_15 * sizeof( struct V_28 * ) ) ;
V_18 = F_9 ( V_19 , V_29 ) ;
if ( ! V_18 ) {
F_7 ( V_22 , V_14 ,
V_23 ) ;
return V_30 ;
}
if ( V_2 -> V_6 . V_7 . V_31 ) {
V_18 -> V_32 = 0 ;
V_18 -> V_14 = V_14 ;
V_18 -> V_33 = 1 ;
} else {
V_18 -> V_14 = V_14 ;
V_18 -> V_32 = V_14 ;
}
sprintf ( V_18 -> V_34 , L_1 , ( int ) V_18 -> V_14 ) ;
V_18 -> V_35 = V_15 ;
V_18 -> V_36 =
(struct V_28 * * ) ( ( char * ) V_18 + sizeof( struct V_16 ) ) ;
V_18 -> V_37 = V_2 -> V_25 . F_6 . V_37 ;
V_18 -> V_38 = 0 ;
V_18 -> V_39 = NULL ;
F_10 ( & V_40 ) ;
for ( V_17 = V_41 ; V_17 ; V_17 = V_17 -> V_42 ) {
if ( V_17 -> V_14 == V_18 -> V_14 )
break;
}
F_11 ( & V_40 ) ;
if ( V_17 ) {
F_7 ( V_22 , V_18 -> V_14 ,
V_23 ) ;
F_12 ( V_18 ) ;
return V_43 ;
}
if ( ( V_2 -> V_25 . F_6 . V_44 != 0 ) &&
( V_2 -> V_25 . F_6 . V_45 != 0 ) ) {
V_18 -> V_38 = V_2 -> V_25 . F_6 . V_45 ;
V_18 -> V_39 =
F_2 ( V_2 -> V_25 . F_6 . V_44 ,
V_2 -> V_25 . F_6 . V_45 ) ;
}
if ( ! V_2 -> V_6 . V_7 . V_9 ) {
struct V_46 V_25 ;
V_25 . V_47 = V_48 ;
V_25 . V_49 . V_14 = V_14 ;
V_25 . V_49 . V_50 = V_18 -> V_39 ;
V_25 . V_49 . V_15 = V_15 ;
V_25 . V_49 . V_51 = V_2 -> V_25 . F_6 . V_52 ;
V_25 . V_49 . V_53 = V_2 -> V_25 . F_6 . V_37 ;
if ( ! V_54 ) {
F_7 ( V_22 , V_18 -> V_14 ,
V_23 ) ;
F_12 ( V_18 ) ;
return V_55 ;
}
if ( ! V_54 ( & V_25 ) ) {
F_7 ( V_22 , V_18 -> V_14 ,
V_23 ) ;
F_12 ( V_18 ) ;
return
V_56 ;
}
}
F_13 ( & V_40 ) ;
if ( ! V_41 ) {
V_41 = V_18 ;
} else {
V_18 -> V_42 = V_41 ;
V_41 = V_18 ;
}
V_21 ++ ;
F_14 ( & V_40 ) ;
F_7 ( V_57 , V_18 -> V_14 ,
V_27 ) ;
return V_58 ;
}
static int
F_15 ( struct V_1 * V_2 , char * V_13 )
{
int V_59 ;
struct V_16 * V_18 , * V_60 = NULL ;
struct V_46 V_25 ;
T_1 V_14 ;
V_14 = V_2 -> V_25 . F_15 . V_14 ;
F_10 ( & V_40 ) ;
V_18 = V_41 ;
while ( V_18 ) {
if ( V_18 -> V_14 == V_14 )
break;
V_60 = V_18 ;
V_18 = V_18 -> V_42 ;
}
if ( ! V_18 ) {
F_11 ( & V_40 ) ;
return V_43 ;
}
for ( V_59 = 0 ; V_59 < V_18 -> V_35 ; V_59 ++ ) {
if ( V_18 -> V_36 [ V_59 ] ) {
F_11 ( & V_40 ) ;
return V_61 ;
}
}
F_11 ( & V_40 ) ;
if ( V_2 -> V_6 . V_7 . V_9 )
goto remove;
V_25 . V_47 = V_62 ;
V_25 . V_63 . V_14 = V_14 ;
if ( ! V_54 )
return V_55 ;
if ( ! V_54 ( & V_25 ) )
return V_56 ;
remove:
F_13 ( & V_40 ) ;
if ( V_60 )
V_60 -> V_42 = V_18 -> V_42 ;
else
V_41 = V_18 -> V_42 ;
V_21 -- ;
F_14 ( & V_40 ) ;
if ( V_18 -> V_39 ) {
F_5 ( V_18 -> V_39 ) ;
V_18 -> V_39 = NULL ;
}
F_12 ( V_18 ) ;
return V_58 ;
}
static int F_16 ( struct V_1 * V_2 , char * V_13 )
{
struct V_28 * V_64 ;
struct V_16 * V_18 ;
struct V_46 V_25 ;
T_1 V_14 , V_65 ;
int V_66 = V_58 ;
T_4 V_67 = V_68 ;
struct V_69 * V_70 ;
V_14 = V_2 -> V_25 . F_16 . V_14 ;
V_65 = V_2 -> V_25 . F_16 . V_65 ;
F_8 ( V_71 , V_65 , V_14 ,
V_27 ) ;
V_64 = F_9 ( sizeof( * V_64 ) , V_29 ) ;
if ( ! V_64 ) {
F_8 ( V_72 , V_65 , V_14 ,
V_23 ) ;
return V_30 ;
}
V_64 -> V_73 = V_2 -> V_25 . F_16 . V_74 ;
V_64 -> V_75 = V_2 -> V_25 . F_16 . V_75 ;
V_64 -> V_44 = V_2 -> V_25 . F_16 . V_44 ;
V_64 -> V_14 = V_14 ;
V_64 -> V_65 = V_65 ;
F_17 ( & V_64 -> V_76 , 1 ) ;
sprintf ( V_64 -> V_77 , L_2 , ( unsigned ) V_14 , ( unsigned ) V_65 ) ;
if ( V_2 -> V_6 . V_7 . V_31 ) {
V_64 -> V_50 = ( void T_3 * ) F_18 ( V_64 -> V_44 ) ;
} else {
V_70 = F_19 ( V_64 -> V_73 ) ;
if ( V_70 )
V_67 = V_70 -> V_78 ;
if ( V_67 > V_2 -> V_25 . F_16 . V_45 ) {
F_8 ( V_72 , V_65 ,
V_14 , V_23 ) ;
V_66 = V_79 ;
goto V_80;
}
V_64 -> V_50 =
F_3 ( V_64 -> V_44 ,
V_2 -> V_25 . F_16 . V_45 ) ;
if ( ! V_64 -> V_50 ) {
V_66 = V_81 ;
F_8 ( V_72 , V_65 ,
V_14 , V_23 ) ;
goto V_80;
}
}
V_64 -> V_53 = V_2 -> V_25 . F_16 . V_82 ;
V_64 -> V_45 = V_2 -> V_25 . F_16 . V_45 ;
F_10 ( & V_40 ) ;
for ( V_18 = V_41 ; V_18 ; V_18 = V_18 -> V_42 ) {
if ( V_18 -> V_14 != V_14 )
continue;
if ( V_65 >= V_18 -> V_35 ) {
V_66 = V_83 ;
F_8 ( V_72 , V_65 ,
V_14 , V_23 ) ;
F_11 ( & V_40 ) ;
goto V_80;
}
if ( V_18 -> V_36 [ V_65 ] ) {
F_8 ( V_72 ,
V_65 , V_14 ,
V_23 ) ;
V_66 = V_43 ;
F_11 ( & V_40 ) ;
goto V_80;
}
F_11 ( & V_40 ) ;
if ( V_2 -> V_6 . V_7 . V_9 ) {
V_18 -> V_36 [ V_65 ] = V_64 ;
F_8 ( V_84 , V_65 ,
V_14 , V_27 ) ;
return V_58 ;
}
if ( F_20 ( V_64 -> V_73 ,
V_85 ) == 0 ) {
F_21 ( & ( (struct V_86 T_3 * )
( V_64 -> V_50 ) ) -> V_87 ) ;
if ( ! F_22 ( V_64 -> V_50 ) ) {
F_8 ( V_72 ,
V_65 , V_14 ,
V_23 ) ;
V_66 = V_88 ;
goto V_80;
}
V_25 . V_47 = V_89 ;
V_25 . V_90 . V_50 = V_64 -> V_50 ;
V_25 . V_90 . V_14 = V_14 ;
V_25 . V_90 . V_91 = V_65 ;
V_25 . V_90 . V_53 = V_64 -> V_53 ;
V_25 . V_90 . V_75 = V_64 -> V_75 ;
} else if ( F_20 ( V_64 -> V_73 ,
V_92 ) == 0 ) {
F_21 ( & ( (struct V_86 T_3 * )
( V_64 -> V_50 ) ) -> V_87 ) ;
if ( ! F_23 ( V_64 -> V_50 ) ) {
F_8 ( V_72 ,
V_65 , V_14 ,
V_23 ) ;
V_66 = V_88 ;
goto V_80;
}
V_25 . V_47 = V_93 ;
V_25 . V_94 . V_50 = V_64 -> V_50 ;
V_25 . V_94 . V_14 = V_14 ;
V_25 . V_94 . V_91 = V_65 ;
V_25 . V_94 . V_53 = V_64 -> V_53 ;
V_25 . V_90 . V_75 = V_64 -> V_75 ;
} else {
F_8 ( V_72 , V_65 ,
V_14 , V_23 ) ;
V_66 = V_95 ;
goto V_80;
}
if ( ! V_54 ) {
F_8 ( V_72 , V_65 ,
V_14 , V_23 ) ;
V_66 = V_55 ;
goto V_80;
}
if ( ! V_54 ( & V_25 ) ) {
F_8 ( V_72 , V_65 ,
V_14 , V_23 ) ;
V_66 =
V_56 ;
goto V_80;
}
V_18 -> V_36 [ V_65 ] = V_64 ;
F_8 ( V_84 , V_65 ,
V_14 , V_27 ) ;
return V_58 ;
}
F_11 ( & V_40 ) ;
F_8 ( V_72 , V_65 , V_14 ,
V_23 ) ;
V_66 = V_96 ;
V_80:
if ( ! V_2 -> V_6 . V_7 . V_31 ) {
F_5 ( V_64 -> V_50 ) ;
V_64 -> V_50 = NULL ;
}
F_12 ( V_64 ) ;
return V_66 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_14 , V_65 ;
struct V_16 * V_18 ;
struct V_28 * V_64 ;
struct V_46 V_25 ;
int V_97 = V_58 ;
V_14 = V_2 -> V_25 . V_98 . V_14 ;
V_65 = V_2 -> V_25 . V_98 . V_65 ;
F_10 ( & V_40 ) ;
for ( V_18 = V_41 ; V_18 ; V_18 = V_18 -> V_42 ) {
if ( V_18 -> V_14 == V_14 ) {
if ( V_65 >= V_18 -> V_35 ) {
V_97 = V_99 ;
} else {
V_64 = V_18 -> V_36 [ V_65 ] ;
if ( ! V_64 ) {
V_97 =
V_43 ;
}
}
break;
}
}
if ( ! V_18 )
V_97 = V_96 ;
F_11 ( & V_40 ) ;
if ( V_97 == V_58 ) {
if ( F_20 ( V_64 -> V_73 ,
V_85 ) == 0 ) {
V_25 . V_47 = V_100 ;
V_25 . V_101 . V_50 = V_64 -> V_50 ;
} else if ( F_20 ( V_64 -> V_73 ,
V_92 ) == 0 ) {
V_25 . V_47 = V_102 ;
V_25 . V_103 . V_50 = V_64 -> V_50 ;
} else {
return V_95 ;
}
if ( ! V_54 )
return V_55 ;
if ( ! V_54 ( & V_25 ) ) {
return
V_56 ;
}
}
return V_97 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_14 , V_65 ;
struct V_16 * V_18 ;
struct V_28 * V_64 ;
struct V_46 V_25 ;
int V_97 = V_58 ;
V_14 = V_2 -> V_25 . V_98 . V_14 ;
V_65 = V_2 -> V_25 . V_98 . V_65 ;
F_10 ( & V_40 ) ;
for ( V_18 = V_41 ; V_18 ; V_18 = V_18 -> V_42 ) {
if ( V_18 -> V_14 == V_14 ) {
if ( V_65 >= V_18 -> V_35 ) {
V_97 = V_99 ;
} else {
V_64 = V_18 -> V_36 [ V_65 ] ;
if ( ! V_64 ) {
V_97 =
V_43 ;
}
}
break;
}
}
if ( ! V_18 )
V_97 = V_96 ;
F_11 ( & V_40 ) ;
if ( V_97 == V_58 ) {
if ( F_20 ( V_64 -> V_73 ,
V_85 ) == 0 ) {
V_25 . V_47 = V_104 ;
V_25 . V_105 . V_50 = V_64 -> V_50 ;
} else if ( F_20 ( V_64 -> V_73 ,
V_92 ) == 0 ) {
V_25 . V_47 = V_106 ;
V_25 . V_107 . V_50 = V_64 -> V_50 ;
} else {
return V_95 ;
}
if ( ! V_54 )
return V_55 ;
if ( ! V_54 ( & V_25 ) ) {
return
V_56 ;
}
}
return V_97 ;
}
static int F_26 ( struct V_1 * V_2 , char * V_13 )
{
T_1 V_14 , V_65 ;
struct V_16 * V_18 ;
struct V_28 * V_64 ;
struct V_46 V_25 ;
int V_97 = V_58 ;
V_14 = V_2 -> V_25 . F_26 . V_14 ;
V_65 = V_2 -> V_25 . F_26 . V_14 ;
F_10 ( & V_40 ) ;
for ( V_18 = V_41 ; V_18 ; V_18 = V_18 -> V_42 ) {
if ( V_18 -> V_14 == V_14 ) {
if ( V_65 >= V_18 -> V_35 ) {
V_97 = V_99 ;
} else {
V_64 = V_18 -> V_36 [ V_65 ] ;
if ( ! V_64 ) {
V_97 =
V_43 ;
}
}
break;
}
}
if ( ! V_18 )
V_97 = V_96 ;
F_11 ( & V_40 ) ;
if ( V_97 == V_58 ) {
if ( F_20 ( V_64 -> V_73 ,
V_85 ) == 0 ) {
V_25 . V_47 = V_108 ;
V_25 . V_109 . V_50 = V_64 -> V_50 ;
} else if ( F_20 ( V_64 -> V_73 ,
V_92 ) == 0 ) {
V_25 . V_47 = V_110 ;
V_25 . V_111 . V_50 = V_64 -> V_50 ;
} else {
return
V_95 ;
}
if ( ! V_54 ) {
return
V_55 ;
}
if ( ! V_54 ( & V_25 ) ) {
return
V_56 ;
}
if ( V_64 -> V_112 )
F_27 ( V_14 , V_65 ) ;
if ( ! V_2 -> V_6 . V_7 . V_31 )
F_5 ( V_64 -> V_50 ) ;
F_12 ( V_64 ) ;
V_18 -> V_36 [ V_65 ] = NULL ;
}
return V_97 ;
}
static int
F_28 ( struct V_1 * V_2 , char * V_13 )
{
F_29 ( V_113 , V_27 ) ;
V_20 = V_2 -> V_25 . F_28 . V_114 ;
V_115 = V_2 -> V_25 . F_28 . V_116 ;
V_117 = 0 ;
if ( ! V_2 -> V_6 . V_7 . V_31 )
F_30 ( V_54 ) ;
V_118 = 1 ;
F_29 ( V_119 , V_27 ) ;
return V_58 ;
}
static int F_31 ( T_1 V_14 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_120 , 0 , 0 ) ;
V_2 . V_25 . F_15 . V_14 = V_14 ;
if ( F_15 ( & V_2 , NULL ) != V_58 )
return 0 ;
return 1 ;
}
static int F_32 ( T_1 V_14 , T_1 V_65 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_121 , 0 , 0 ) ;
V_2 . V_25 . F_26 . V_14 = V_14 ;
V_2 . V_25 . F_26 . V_65 = V_65 ;
if ( F_26 ( & V_2 , NULL ) != V_58 )
return 0 ;
return 1 ;
}
int
F_33 ( T_1 V_14 , T_6 V_122 ,
T_4 V_44 , T_7 V_123 )
{
struct V_1 V_2 ;
F_7 ( V_113 , V_14 , V_27 ) ;
if ( ! V_118 ) {
F_1 ( & V_2 , V_124 , 0 , 0 ) ;
V_2 . V_25 . F_28 . V_114 = 23 ;
V_2 . V_25 . F_28 . V_125 = 0 ;
if ( F_28 ( & V_2 , NULL ) != V_58 )
return 0 ;
F_7 ( V_119 , V_14 ,
V_27 ) ;
}
F_7 ( V_26 , V_14 ,
V_126 ) ;
F_1 ( & V_2 , V_127 , 0 , 0 ) ;
V_2 . V_25 . F_6 . V_14 = V_14 ;
V_2 . V_25 . F_6 . V_15 = 23 ;
V_2 . V_25 . F_6 . V_44 = V_44 ;
V_2 . V_25 . F_6 . V_45 = V_123 ;
if ( F_6 ( & V_2 , NULL ) != V_58 ) {
F_7 ( V_22 , V_14 ,
V_23 ) ;
return 0 ;
}
F_7 ( V_57 , V_14 , V_27 ) ;
return 1 ;
}
int
F_34 ( T_1 V_14 )
{
return F_31 ( V_14 ) ;
}
int
F_35 ( T_1 V_14 , T_1 V_65 )
{
struct V_1 V_2 ;
int V_128 ;
F_1 ( & V_2 , V_129 , 0 , 0 ) ;
V_2 . V_25 . V_98 . V_14 = V_14 ;
V_2 . V_25 . V_98 . V_65 = V_65 ;
V_2 . V_25 . V_98 . V_130 = V_131 ;
V_128 = F_24 ( & V_2 ) ;
if ( V_128 != V_58 )
return V_128 ;
return 0 ;
}
int
F_36 ( T_1 V_14 , T_1 V_65 )
{
struct V_1 V_2 ;
int V_128 ;
F_1 ( & V_2 , V_129 , 0 , 0 ) ;
V_2 . V_25 . V_98 . V_14 = V_14 ;
V_2 . V_25 . V_98 . V_65 = V_65 ;
V_2 . V_25 . V_98 . V_130 = V_132 ;
V_128 = F_25 ( & V_2 ) ;
if ( V_128 != V_58 )
return V_128 ;
return 0 ;
}
int
F_37 ( T_1 V_14 , T_1 V_65 ,
T_4 V_133 , T_1 V_134 ,
int V_135 , T_6 V_122 ,
struct V_136 * V_75 )
{
struct V_1 V_2 ;
F_8 ( V_137 , V_65 , V_14 ,
V_27 ) ;
F_1 ( & V_2 , V_138 , 0 , 0 ) ;
if ( V_135 )
V_2 . V_6 . V_7 . V_31 = 1 ;
V_2 . V_25 . F_16 . V_14 = V_14 ;
V_2 . V_25 . F_16 . V_65 = V_65 ;
V_2 . V_25 . F_16 . V_82 = V_122 ;
if ( V_75 )
V_2 . V_25 . F_16 . V_75 = * V_75 ;
else
memset ( & V_2 . V_25 . F_16 . V_75 , 0 ,
sizeof( struct V_136 ) ) ;
V_2 . V_25 . F_16 . V_44 = V_133 ;
if ( V_134 < V_68 ) {
F_8 ( V_139 , V_134 ,
V_68 , V_23 ) ;
return 0 ;
}
V_2 . V_25 . F_16 . V_45 = V_134 ;
V_2 . V_25 . F_16 . V_74 = V_85 ;
if ( F_16 ( & V_2 , NULL ) != V_58 ) {
F_8 ( V_139 , V_65 , V_14 ,
V_23 ) ;
return 0 ;
}
F_8 ( V_140 , V_65 , V_14 ,
V_27 ) ;
return 1 ;
}
int
F_38 ( T_1 V_14 , T_1 V_65 )
{
return F_32 ( V_14 , V_65 ) ;
}
int
F_39 ( T_1 V_14 , T_1 V_65 ,
T_4 V_133 , T_1 V_134 ,
int V_135 , T_6 V_122 ,
struct V_136 * V_75 )
{
struct V_1 V_2 ;
F_8 ( V_141 , V_65 , V_14 ,
V_27 ) ;
F_1 ( & V_2 , V_138 , 0 , 0 ) ;
if ( V_135 )
V_2 . V_6 . V_7 . V_31 = 1 ;
V_2 . V_25 . F_16 . V_14 = V_14 ;
V_2 . V_25 . F_16 . V_65 = V_65 ;
V_2 . V_25 . F_16 . V_82 = V_122 ;
if ( V_75 )
V_2 . V_25 . F_16 . V_75 = * V_75 ;
else
memset ( & V_2 . V_25 . F_16 . V_75 , 0 ,
sizeof( struct V_136 ) ) ;
V_2 . V_25 . F_16 . V_44 = V_133 ;
if ( V_134 < V_68 ) {
F_8 ( V_142 , V_134 ,
V_68 , V_23 ) ;
return 0 ;
}
V_2 . V_25 . F_16 . V_45 = V_134 ;
V_2 . V_25 . F_16 . V_74 = V_92 ;
if ( F_16 ( & V_2 , NULL ) != V_58 ) {
F_8 ( V_142 , V_65 , V_14 ,
V_23 ) ;
return 0 ;
}
F_8 ( V_143 , V_65 , V_14 ,
V_27 ) ;
return 1 ;
}
int
F_40 ( T_1 V_14 , T_1 V_65 )
{
struct V_1 V_2 ;
int V_128 ;
F_1 ( & V_2 , V_129 , 0 , 0 ) ;
V_2 . V_25 . V_98 . V_14 = V_14 ;
V_2 . V_25 . V_98 . V_65 = V_65 ;
V_2 . V_25 . V_98 . V_130 = V_131 ;
V_128 = F_24 ( & V_2 ) ;
if ( V_128 != V_58 )
return - 1 ;
return 0 ;
}
int
F_41 ( T_1 V_14 , T_1 V_65 )
{
struct V_1 V_2 ;
int V_128 ;
F_1 ( & V_2 , V_129 , 0 , 0 ) ;
V_2 . V_25 . V_98 . V_14 = V_14 ;
V_2 . V_25 . V_98 . V_65 = V_65 ;
V_2 . V_25 . V_98 . V_130 = V_132 ;
V_128 = F_25 ( & V_2 ) ;
if ( V_128 != V_58 )
return - 1 ;
return 0 ;
}
int
F_42 ( T_1 V_14 , T_1 V_65 )
{
return F_32 ( V_14 , V_65 ) ;
}
void *
F_43 ( struct V_144 * V_145 , char * V_146 , int V_147 )
{
void * V_148 = F_44 ( V_145 , V_29 | V_149 ) ;
if ( ! V_148 )
return NULL ;
return V_148 ;
}
void
F_45 ( struct V_144 * V_145 , void * V_148 , char * V_146 , int V_147 )
{
if ( ! V_148 )
return;
F_46 ( V_145 , V_148 ) ;
}
static int
F_47 ( char * * V_150 , int * V_151 )
{
int V_59 , V_152 = 0 ;
struct V_16 * V_18 ;
if ( F_48 ( L_3 ) < 0 )
goto V_153;
F_10 ( & V_40 ) ;
for ( V_18 = V_41 ; V_18 ; V_18 = V_18 -> V_42 ) {
if ( F_48 ( L_4 ,
V_18 , V_18 -> V_14 , V_18 -> V_35 ) < 0 )
goto V_154;
if ( F_48 ( L_5 ) < 0 )
goto V_154;
for ( V_59 = 0 ; V_59 < V_18 -> V_35 ; V_59 ++ ) {
if ( V_18 -> V_36 [ V_59 ] ) {
if ( F_48 ( L_6 ,
V_18 -> V_14 , V_59 , V_18 -> V_36 [ V_59 ] ,
V_18 -> V_36 [ V_59 ] -> V_50 ,
V_18 -> V_36 [ V_59 ] -> V_155 ) < 0 )
goto V_154;
if ( F_48 ( L_7 ,
V_18 -> V_36 [ V_59 ] -> V_156 ,
V_18 -> V_36 [ V_59 ] -> V_157 ,
V_18 -> V_36 [ V_59 ] -> V_158 ) < 0 )
goto V_154;
}
}
}
F_11 ( & V_40 ) ;
if ( F_48 ( L_8 ,
F_49 ( & V_159 ) ) < 0 )
goto V_153;
if ( F_48 ( L_9 ,
V_160 , V_161 ) < 0 )
goto V_153;
if ( F_48 ( L_10 ,
V_162 , V_163 , V_164 ) < 0 )
goto V_153;
if ( F_48 ( L_11 , V_165 ) < 0 )
goto V_153;
if ( F_48 ( L_12 , V_166 ) < 0 )
goto V_153;
return V_152 ;
V_154:
F_11 ( & V_40 ) ;
V_153:
return - 1 ;
}
static T_8 F_50 ( struct V_167 * V_167 , char T_9 * V_13 ,
T_5 V_168 , T_10 * V_169 )
{
char * V_170 ;
int V_171 = 0 ;
int V_172 = V_173 ;
if ( ! V_174 ) {
V_174 = F_51 ( V_173 ) ;
if ( ! V_174 )
return - V_175 ;
}
V_170 = V_174 ;
if ( ( * V_169 == 0 ) || ( ! V_176 ) ) {
V_171 = F_47 ( & V_170 , & V_172 ) ;
V_176 = 1 ;
} else {
V_171 = strlen ( V_174 ) ;
}
return F_52 ( V_13 , V_168 , V_169 ,
V_174 , V_171 ) ;
}
static struct V_28 * F_53 ( T_1 V_14 , T_1 V_65 )
{
struct V_16 * V_18 ;
struct V_28 * V_64 = NULL ;
F_10 ( & V_40 ) ;
for ( V_18 = V_41 ; V_18 ; V_18 = V_18 -> V_42 ) {
if ( V_18 -> V_14 == V_14 ) {
if ( V_65 >= V_18 -> V_35 )
break;
V_64 = V_18 -> V_36 [ V_65 ] ;
break;
}
}
F_11 ( & V_40 ) ;
return V_64 ;
}
static int F_54 ( void * V_177 )
{
unsigned long long V_178 , V_179 , V_180 , V_181 ;
struct V_182 * V_183 = NULL ;
int V_59 ;
F_55 ( L_13 ) ;
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ ) {
V_179 = F_56 () ;
F_57 ( V_184 ,
0 , V_185 ) ;
V_178 = F_56 () ;
if ( V_161 == 0 ) {
V_161 = ( V_178 - V_179 ) ;
} else {
if ( V_161 < ( V_178 - V_179 ) )
V_161 = ( V_178 - V_179 ) ;
}
}
V_160 = V_161 ;
V_180 = 0 ;
V_186 = 0 ;
while ( 1 ) {
struct V_182 * V_187 , * V_17 ;
struct V_28 * V_64 = NULL ;
F_58 ( & V_188 ) ;
V_183 = NULL ;
F_59 (lelt, tmp, &poll_dev_chan) {
int V_128 = 0 ;
V_64 = F_60 ( V_187 , struct V_28 ,
V_189 ) ;
F_58 ( & V_64 -> V_76 ) ;
if ( V_64 -> V_190 )
V_128 = V_64 -> V_190 ( V_64 -> V_191 ) ;
else
continue;
F_61 ( & V_64 -> V_76 ) ;
if ( V_128 ) {
V_180 = 0 ;
if ( ! V_183 ) {
V_64 -> V_156 ++ ;
if ( !
( F_62
( V_187 ,
& V_192 ) ) ) {
V_183 = V_187 ;
V_64 -> V_157 ++ ;
} else {
V_64 -> V_158 ++ ;
}
}
}
if ( F_63 () )
break;
}
if ( V_183 ) {
V_166 ++ ;
F_64 ( V_183 , & V_192 ) ;
}
F_61 ( & V_188 ) ;
V_178 = F_56 () ;
V_181 = V_178 - V_179 ;
V_179 = V_178 ;
if ( F_63 () )
break;
if ( V_165 == 0xFF )
break;
if ( V_180 > V_160 ) {
V_186 = 0 ;
V_163 ++ ;
F_57 ( V_184 ,
V_186 ,
V_185 ) ;
V_186 = 1 ;
} else {
V_164 ++ ;
F_65 () ;
V_180 = V_180 + V_181 ;
}
}
F_66 ( & V_193 . V_194 , 0 ) ;
}
static BOOL
F_67 ( void )
{
if ( V_195 )
return TRUE ;
if ( ! F_68 ( & V_193 ,
& F_54 , NULL , L_13 ) ) {
return FALSE ;
}
V_195 = TRUE ;
return TRUE ;
}
void
F_69 ( T_1 V_14 , T_1 V_65 ,
int (* V_190)( void * ) ,
void * V_191 )
{
struct V_28 * V_64 ;
V_64 = F_53 ( V_14 , V_65 ) ;
if ( ! V_64 )
return;
F_58 ( & V_188 ) ;
F_67 () ;
V_64 -> V_190 = V_190 ;
V_64 -> V_191 = V_191 ;
V_64 -> V_112 = TRUE ;
F_70 ( & V_64 -> V_189 ,
& V_192 ) ;
F_61 ( & V_188 ) ;
}
void
F_27 ( T_1 V_14 , T_1 V_65 )
{
struct V_28 * V_64 ;
V_64 = F_53 ( V_14 , V_65 ) ;
if ( ! V_64 )
return;
F_58 ( & V_188 ) ;
F_71 ( & V_64 -> V_189 ) ;
V_64 -> V_112 = FALSE ;
V_64 -> V_190 = NULL ;
F_61 ( & V_188 ) ;
}
static void
F_72 ( struct V_196 * V_197 )
{
if ( ! V_186 ) {
V_186 = 1 ;
F_73 ( & V_184 ) ;
}
}
void
F_74 ( T_1 V_14 , T_1 V_65 )
{
if ( V_165 == 0 )
return;
if ( V_186 )
return;
V_162 ++ ;
F_75 ( & V_198 ) ;
}
static int T_11
F_76 ( void )
{
if ( ! V_199 )
return - V_200 ;
V_41 = NULL ;
V_21 = 0 ;
V_20 = 0 ;
F_77 ( & V_40 ) ;
V_54 = NULL ;
F_29 ( V_201 , V_27 ) ;
V_202 = F_78 ( V_203 , NULL ) ;
if ( V_202 ) {
V_204 = F_79 (
V_205 , 0444 , V_202 , NULL ,
& V_206 ) ;
V_207 = F_80 (
V_208 , 0444 , V_202 ,
& V_115 ) ;
V_209 = F_81 (
V_210 , 0666 , V_202 ,
& V_160 ) ;
V_211 = F_82 (
V_212 , 0666 , V_202 ,
& V_165 ) ;
}
F_7 ( V_213 , 0 , V_27 ) ;
return 0 ;
}
static void T_12
F_83 ( void )
{
if ( V_174 ) {
F_84 ( V_174 ) ;
V_174 = NULL ;
}
F_85 ( V_204 ) ;
F_85 ( V_211 ) ;
F_85 ( V_209 ) ;
F_85 ( V_207 ) ;
F_85 ( V_202 ) ;
}
