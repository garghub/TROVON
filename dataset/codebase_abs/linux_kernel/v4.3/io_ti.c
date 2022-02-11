static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_3 * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_3 ( V_2 , 0 ) , V_3 ,
( V_9 | V_10 | V_11 ) ,
V_4 , V_5 , V_6 , V_7 , 1000 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != V_7 ) {
F_4 ( & V_2 -> V_2 , L_1 ,
V_12 , V_7 , V_8 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_3 V_3 , T_4 V_4 ,
T_4 V_5 , T_3 * V_6 , int V_7 , int V_14 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_6 ( V_2 , 0 ) , V_3 ,
( V_9 | V_10 | V_15 ) ,
V_4 , V_5 , V_6 , V_7 , V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != V_7 ) {
F_4 ( & V_2 -> V_2 , L_1 ,
V_12 , V_7 , V_8 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_16 ,
T_1 V_17 , T_2 V_4 , T_3 * V_6 ,
int V_7 )
{
return F_5 ( V_2 , V_16 , V_4 , V_17 , V_6 , V_7 ,
V_18 ) ;
}
static int F_8 ( struct V_19 * V_20 , T_2 V_21 )
{
int V_22 = V_20 -> V_22 ;
F_4 ( & V_20 -> V_2 , L_2 , V_12 , V_22 , V_21 ) ;
return F_7 ( V_20 -> V_23 -> V_2 ,
V_24 ,
( T_1 ) ( V_25 + V_22 ) ,
V_21 ,
NULL ,
0 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_26 ,
int V_27 , T_1 V_28 , T_1 * V_29 )
{
int V_8 = 0 ;
T_1 V_30 ;
T_4 V_31 ;
F_4 ( & V_2 -> V_2 , L_3 , V_12 , V_26 , V_27 ) ;
while ( V_27 ) {
if ( V_27 > 64 )
V_30 = 64 ;
else
V_30 = ( T_1 ) V_27 ;
if ( V_30 > 1 ) {
F_4 ( & V_2 -> V_2 , L_3 , V_12 , V_26 , V_30 ) ;
}
V_31 = F_10 ( ( T_4 ) V_26 ) ;
V_8 = F_1 ( V_2 , V_32 ,
( T_2 ) V_28 ,
V_31 ,
V_29 , V_30 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
if ( V_30 > 1 )
F_11 ( & V_2 -> V_2 , V_12 , V_30 , V_29 ) ;
V_26 += V_30 ;
V_29 += V_30 ;
V_27 -= V_30 ;
}
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 , int V_26 ,
int V_27 , T_1 * V_29 )
{
return F_9 ( V_2 , V_26 , V_27 ,
V_33 , V_29 ) ;
}
static int F_13 ( struct V_34 * V_23 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_27 ; V_35 ++ ) {
V_8 = F_1 ( V_23 -> V_23 -> V_2 ,
V_32 , V_23 -> V_36 ,
( T_2 ) ( V_26 + V_35 ) , & V_29 [ V_35 ] , 0x01 ) ;
if ( V_8 ) {
F_4 ( & V_23 -> V_23 -> V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
}
F_4 ( & V_23 -> V_23 -> V_2 -> V_2 , L_5 ,
V_12 , V_26 , V_27 ) ;
F_11 ( & V_23 -> V_23 -> V_2 -> V_2 , V_12 , V_27 , V_29 ) ;
V_23 -> V_37 = 1 ;
return V_8 ;
}
static int F_14 ( struct V_34 * V_23 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_35 ;
T_3 * V_38 ;
if ( ! V_23 -> V_37 ) {
V_38 = F_15 ( 1 , V_39 ) ;
if ( ! V_38 )
return - V_40 ;
V_8 = F_13 ( V_23 , 0 , 1 , V_38 ) ;
F_16 ( V_38 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_35 = 0 ; V_35 < V_27 ; ++ V_35 ) {
V_8 = F_5 ( V_23 -> V_23 -> V_2 , V_41 ,
V_29 [ V_35 ] , ( T_4 ) ( V_35 + V_26 ) , NULL ,
0 , V_18 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( & V_23 -> V_23 -> V_2 -> V_2 , L_6 , V_12 , V_26 , V_27 ) ;
F_11 ( & V_23 -> V_23 -> V_2 -> V_2 , V_12 , V_27 , V_29 ) ;
return V_8 ;
}
static int F_17 ( struct V_34 * V_23 ,
int V_26 , int V_27 , T_1 V_28 , T_1 * V_29 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_43 ;
T_4 V_31 ;
V_43 = V_44 -
( V_26 & ( V_44 - 1 ) ) ;
if ( V_43 > V_27 )
V_43 = V_27 ;
F_4 ( V_2 , L_7 ,
V_12 , V_26 , V_43 ) ;
F_11 ( V_2 , V_12 , V_43 , V_29 ) ;
V_31 = F_10 ( ( T_4 ) V_26 ) ;
V_8 = F_5 ( V_23 -> V_23 -> V_2 , V_41 ,
( T_4 ) V_28 , V_31 ,
V_29 , V_43 , V_18 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_8 , V_12 , V_8 ) ;
return V_8 ;
}
V_27 -= V_43 ;
V_26 += V_43 ;
V_29 += V_43 ;
while ( V_27 ) {
if ( V_27 > V_44 )
V_43 = V_44 ;
else
V_43 = V_27 ;
F_4 ( V_2 , L_9 ,
V_12 , V_26 , V_43 ) ;
F_11 ( V_2 , V_12 , V_43 , V_29 ) ;
V_31 = F_10 ( ( T_4 ) V_26 ) ;
V_8 = F_5 ( V_23 -> V_23 -> V_2 , V_41 ,
( T_4 ) V_28 , V_31 , V_29 ,
V_43 , V_18 ) ;
if ( V_8 ) {
F_18 ( V_2 , L_8 , V_12 , V_8 ) ;
return V_8 ;
}
V_27 -= V_43 ;
V_26 += V_43 ;
V_29 += V_43 ;
}
return V_8 ;
}
static int F_19 ( struct V_45 * V_20 )
{
int V_8 ;
struct V_46 * V_47 ;
T_1 * V_48 ;
int V_49 = 0 ;
V_47 = F_15 ( sizeof( * V_47 ) , V_39 ) ;
if ( ! V_47 )
return - V_40 ;
V_48 = F_15 ( 1 , V_39 ) ;
if ( ! V_48 ) {
F_16 ( V_47 ) ;
return - V_40 ;
}
V_8 = F_12 ( V_20 -> V_20 -> V_23 -> V_2 , V_20 -> V_50 ,
sizeof( * V_47 ) , ( void * ) V_47 ) ;
if ( V_8 )
goto V_51;
F_4 ( & V_20 -> V_20 -> V_2 , L_10 , V_12 , V_47 -> V_52 ) ;
V_8 = F_12 ( V_20 -> V_20 -> V_23 -> V_2 ,
V_20 -> V_53 + V_54 , 1 , V_48 ) ;
if ( V_8 )
goto V_51;
F_4 ( & V_20 -> V_20 -> V_2 , L_11 , V_12 , * V_48 ) ;
if ( ( V_47 -> V_52 & 0x80 ) != 0 )
V_49 += 64 ;
if ( ( * V_48 & V_55 ) == 0 )
V_49 += 1 ;
V_51:
F_4 ( & V_20 -> V_20 -> V_2 , L_12 , V_12 , V_49 ) ;
F_16 ( V_48 ) ;
F_16 ( V_47 ) ;
return V_49 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 , L_13 ,
V_12 , V_2 -> V_56 -> V_57 . V_58 ) ;
F_4 ( & V_2 -> V_2 , L_14 ,
V_12 , V_2 -> V_56 -> V_57 . V_59 * 2 ) ;
if ( V_2 -> V_56 -> V_57 . V_58 != 1 ) {
F_18 ( & V_2 -> V_2 , L_15 , V_12 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_21 ( struct V_34 * V_23 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 ;
if ( V_23 -> V_61 . V_62 == V_63 ) {
V_8 = F_9 ( V_23 -> V_23 -> V_2 ,
V_26 ,
V_27 ,
V_23 -> V_36 ,
V_29 ) ;
} else {
V_8 = F_13 ( V_23 , V_26 , V_27 ,
V_29 ) ;
}
return V_8 ;
}
static int F_22 ( struct V_34 * V_23 , int V_26 ,
int V_27 , T_1 * V_29 )
{
if ( V_23 -> V_61 . V_62 == V_64 )
return F_14 ( V_23 , V_26 , V_27 ,
V_29 ) ;
if ( V_23 -> V_61 . V_62 == V_63 )
return F_17 ( V_23 , V_26 , V_27 ,
V_23 -> V_36 , V_29 ) ;
return - V_65 ;
}
static int F_23 ( struct V_34 * V_23 ,
int V_66 , struct V_67 * V_68 )
{
int V_26 ;
int V_8 ;
V_26 = 2 ;
do {
V_8 = F_21 ( V_23 ,
V_26 ,
sizeof( struct V_67 ) ,
( T_1 * ) V_68 ) ;
if ( V_8 )
return 0 ;
if ( V_68 -> Type == V_66 )
return V_26 ;
V_26 = V_26 + sizeof( struct V_67 ) +
F_24 ( V_68 -> V_69 ) ;
} while ( ( V_26 < V_70 ) && V_68 -> Type );
return 0 ;
}
static int F_25 ( struct V_67 * V_68 , T_1 * V_29 )
{
T_2 V_35 ;
T_1 V_71 = 0 ;
for ( V_35 = 0 ; V_35 < F_24 ( V_68 -> V_69 ) ; V_35 ++ )
V_71 = ( T_1 ) ( V_71 + V_29 [ V_35 ] ) ;
if ( V_71 != V_68 -> V_72 ) {
F_26 ( L_16 , V_12 , V_68 -> V_72 , V_71 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_27 ( struct V_34 * V_23 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_67 * V_68 ;
int V_26 = 2 ;
T_1 * V_29 ;
T_2 V_73 ;
V_68 = F_15 ( sizeof( * V_68 ) , V_39 ) ;
if ( ! V_68 )
return - V_40 ;
V_29 = F_15 ( V_70 , V_39 ) ;
if ( ! V_29 ) {
F_16 ( V_68 ) ;
return - V_40 ;
}
V_8 = F_21 ( V_23 , 0 , 1 , V_29 ) ;
if ( V_8 )
goto V_74;
if ( * V_29 != V_75 && * V_29 != V_76 ) {
F_18 ( V_2 , L_17 , V_12 ) ;
V_8 = - V_60 ;
goto V_74;
}
do {
V_8 = F_21 ( V_23 ,
V_26 ,
sizeof( struct V_67 ) ,
( T_1 * ) V_68 ) ;
if ( V_8 )
break;
if ( ( V_26 + sizeof( struct V_67 ) +
F_24 ( V_68 -> V_69 ) ) > V_70 ) {
V_8 = - V_60 ;
F_4 ( V_2 , L_18 , V_12 ) ;
break;
}
F_4 ( V_2 , L_19 , V_12 , V_68 -> Type ) ;
V_73 = V_68 -> Type & 0x0f ;
if ( V_73 != V_77
&& V_73 != V_78 ) {
V_8 = F_21 ( V_23 , V_26 +
sizeof( struct V_67 ) ,
F_24 ( V_68 -> V_69 ) ,
V_29 ) ;
if ( V_8 )
break;
V_8 = F_25 ( V_68 , V_29 ) ;
if ( V_8 )
break;
}
V_26 = V_26 + sizeof( struct V_67 ) +
F_24 ( V_68 -> V_69 ) ;
} while ( ( V_68 -> Type != V_79 ) &&
( V_26 < V_70 ) );
if ( ( V_68 -> Type != V_79 ) ||
( V_26 > V_70 ) )
V_8 = - V_60 ;
V_74:
F_16 ( V_29 ) ;
F_16 ( V_68 ) ;
return V_8 ;
}
static int F_28 ( struct V_34 * V_23 , T_1 * V_29 )
{
int V_8 ;
int V_26 ;
struct V_67 * V_68 ;
struct V_80 * V_57 ;
struct V_42 * V_2 = & V_23 -> V_23 -> V_2 -> V_2 ;
V_68 = F_15 ( sizeof( * V_68 ) , V_39 ) ;
if ( ! V_68 )
return - V_40 ;
V_26 = F_23 ( V_23 , V_79 ,
V_68 ) ;
if ( ! V_26 ) {
F_4 ( V_2 , L_20 , V_12 ) ;
V_8 = - V_60 ;
goto exit;
}
V_8 = F_21 ( V_23 , V_26 + sizeof( struct V_67 ) ,
F_24 ( V_68 -> V_69 ) , V_29 ) ;
if ( V_8 )
goto exit;
V_8 = F_25 ( V_68 , V_29 ) ;
V_57 = (struct V_80 * ) V_29 ;
F_4 ( V_2 , L_21 , V_12 , V_57 -> V_81 ) ;
F_4 ( V_2 , L_22 , V_12 , V_57 -> V_82 ) ;
F_4 ( V_2 , L_23 , V_12 , V_57 -> V_83 ) ;
F_4 ( V_2 , L_24 , V_12 , V_57 -> V_84 ) ;
F_4 ( V_2 , L_25 , V_12 , V_57 -> V_85 ) ;
F_4 ( V_2 , L_26 , V_12 , V_57 -> V_86 ) ;
exit:
F_16 ( V_68 ) ;
return V_8 ;
}
static int F_29 ( T_3 * V_87 , struct V_42 * V_2 ,
const struct V_88 * V_89 )
{
T_1 * V_29 ;
int V_90 ;
int V_35 ;
T_1 V_71 = 0 ;
struct V_67 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 = (struct V_96 * ) V_89 -> V_6 ;
V_90 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_94 ) ) ;
V_29 = F_15 ( V_90 , V_39 ) ;
if ( ! V_29 )
return - V_40 ;
memset ( V_29 , 0xff , V_90 ) ;
V_95 = (struct V_94 * ) V_29 ;
V_95 -> V_98 = V_97 -> V_99 ;
V_95 -> V_100 = V_97 -> V_101 ;
V_93 = (struct V_92 * ) & V_89 -> V_6 [ 4 ] ;
memcpy ( V_29 + sizeof( struct V_94 ) ,
& V_89 -> V_6 [ 4 + sizeof( struct V_92 ) ] ,
F_24 ( V_93 -> V_102 ) ) ;
for ( V_35 = 0 ; V_35 < V_90 ; V_35 ++ ) {
V_71 = ( T_1 ) ( V_71 + V_29 [ V_35 ] ) ;
}
F_16 ( V_29 ) ;
V_91 = (struct V_67 * ) V_87 ;
V_95 = (struct V_94 * ) V_91 -> V_103 ;
V_91 -> Type = V_104 ;
V_91 -> V_69 = F_30 ( V_90 ) ;
V_91 -> V_72 = V_71 ;
V_95 -> V_98 = V_97 -> V_99 ;
V_95 -> V_100 = V_97 -> V_101 ;
return 0 ;
}
static int F_31 ( struct V_34 * V_23 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_2 -> V_2 ;
int V_8 ;
T_3 * V_6 ;
V_6 = F_15 ( 1 , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
V_8 = F_1 ( V_23 -> V_23 -> V_2 , V_32 ,
V_105 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_27 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_28 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_75 || * V_6 == V_76 ) ) {
F_4 ( V_2 , L_29 , V_12 ) ;
V_23 -> V_36 = V_105 ;
goto V_74;
}
V_8 = F_1 ( V_23 -> V_23 -> V_2 , V_32 ,
V_106 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_30 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_28 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_75 || * V_6 == V_76 ) ) {
F_4 ( V_2 , L_31 , V_12 ) ;
V_23 -> V_36 = V_106 ;
goto V_74;
}
F_4 ( V_2 , L_32 , V_12 ) ;
V_23 -> V_36 = V_105 ;
V_8 = - V_60 ;
V_74:
F_16 ( V_6 ) ;
return V_8 ;
}
static int F_32 ( struct V_107 * V_23 , void * V_29 ,
int V_27 , int * V_108 )
{
int V_8 ;
V_8 = F_33 ( V_23 -> V_2 ,
F_34 ( V_23 -> V_2 ,
V_23 -> V_20 [ 0 ] -> V_109 ) ,
V_29 , V_27 , V_108 , 1000 ) ;
return V_8 ;
}
static int F_35 ( struct V_34 * V_23 , T_1 * V_110 ,
int V_111 )
{
int V_8 = 0 ;
int V_112 ;
int V_113 ;
int V_114 ;
for ( V_112 = 0 ; V_112 < V_111 ; ) {
V_113 = V_111 - V_112 ;
if ( V_113 > V_115 )
V_113 = V_115 ;
V_8 = F_32 ( V_23 -> V_23 , & V_110 [ V_112 ] ,
V_113 , & V_114 ) ;
if ( V_8 )
break;
V_112 += V_114 ;
}
return V_8 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_37 ( struct V_80 * V_57 )
{
return F_38 ( V_57 -> V_83 ) ;
}
static int F_39 ( struct V_34 * V_23 ,
const struct V_88 * V_89 )
{
T_4 V_116 ;
T_3 V_117 = 0 ;
int V_112 ;
struct V_42 * V_2 = & V_23 -> V_23 -> V_118 -> V_2 ;
struct V_96 * V_97 = (struct V_96 * ) V_89 -> V_6 ;
if ( V_89 -> V_7 < sizeof( struct V_96 ) ) {
F_18 ( V_2 , L_33 ) ;
return - V_65 ;
}
V_116 = F_24 ( V_97 -> V_27 ) +
sizeof( struct V_96 ) ;
if ( V_89 -> V_7 != V_116 ) {
F_18 ( V_2 , L_34 ,
V_116 , V_89 -> V_7 ) ;
return - V_65 ;
}
for ( V_112 = sizeof( struct V_96 ) ; V_112 < V_89 -> V_7 ; ++ V_112 )
V_117 += V_89 -> V_6 [ V_112 ] ;
if ( V_117 != V_97 -> V_117 ) {
F_18 ( V_2 , L_35 ,
V_97 -> V_117 , V_117 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_40 ( struct V_34 * V_23 ,
const struct V_88 * V_89 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_26 ;
struct V_80 * V_119 ;
struct V_120 * V_118 ;
int V_121 ;
int V_122 ;
struct V_96 * V_97 = (struct V_96 * ) V_89 -> V_6 ;
if ( F_39 ( V_23 , V_89 ) )
return - V_65 ;
V_23 -> V_123 = ( V_97 -> V_99 << 8 ) +
V_97 -> V_101 ;
V_23 -> V_61 . V_124 = V_125 ;
V_23 -> V_36 = V_105 ;
V_8 = F_20 ( V_23 -> V_23 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_118 = & V_23 -> V_23 -> V_118 -> V_126 -> V_57 ;
if ( ! V_118 ) {
F_18 ( V_2 , L_36 , V_12 ) ;
return - V_60 ;
}
if ( V_118 -> V_127 > 1 )
V_23 -> V_61 . V_62 = V_63 ;
else
V_23 -> V_61 . V_62 = V_128 ;
if ( V_23 -> V_61 . V_62 == V_63 ) {
struct V_67 * V_68 ;
F_4 ( V_2 , L_37 , V_12 ) ;
V_8 = F_27 ( V_23 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_38 , V_12 ) ;
return V_8 ;
}
V_119 = F_15 ( sizeof( * V_119 ) , V_39 ) ;
if ( ! V_119 )
return - V_40 ;
V_8 = F_28 ( V_23 , ( T_1 * ) V_119 ) ;
if ( V_8 ) {
F_16 ( V_119 ) ;
return V_8 ;
}
if ( ! V_129 && F_37 ( V_119 ) < 2 ) {
F_4 ( V_2 , L_39 ,
V_12 , F_37 ( V_119 ) ) ;
F_16 ( V_119 ) ;
return - V_65 ;
}
V_68 = F_15 ( sizeof( * V_68 ) , V_39 ) ;
if ( ! V_68 ) {
F_16 ( V_119 ) ;
return - V_40 ;
}
V_26 = F_23 ( V_23 ,
V_77 , V_68 ) ;
if ( V_26 != 0 ) {
struct V_94 * V_130 ;
T_3 * V_131 ;
F_4 ( V_2 , L_40 , V_12 ) ;
V_130 = F_15 ( sizeof( * V_130 ) ,
V_39 ) ;
if ( ! V_130 ) {
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_40 ;
}
V_8 = F_21 ( V_23 , V_26 +
sizeof( struct V_67 ) ,
sizeof( struct V_94 ) ,
( T_1 * ) V_130 ) ;
if ( V_8 ) {
F_16 ( V_130 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return V_8 ;
}
V_121 = ( V_130 -> V_98 << 8 ) +
( V_130 -> V_100 ) ;
V_122 = ( V_97 -> V_99 << 8 ) +
( V_97 -> V_101 ) ;
F_4 ( V_2 , L_41 ,
V_12 , V_130 -> V_98 ,
V_130 -> V_100 ,
V_97 -> V_99 , V_97 -> V_101 ) ;
if ( V_121 < V_122 ) {
F_4 ( V_2 , L_42 ,
V_12 ,
V_130 -> V_98 ,
V_130 -> V_100 ,
V_97 -> V_99 ,
V_97 -> V_101 ) ;
V_131 = F_15 ( 1 , V_39 ) ;
if ( ! V_131 ) {
F_16 ( V_130 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_40 ;
}
* V_131 = V_104 ;
V_8 = F_22 ( V_23 , V_26 ,
sizeof( * V_131 ) , V_131 ) ;
if ( V_8 ) {
F_16 ( V_131 ) ;
F_16 ( V_130 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return V_8 ;
}
V_8 = F_21 ( V_23 ,
V_26 ,
sizeof( * V_131 ) ,
V_131 ) ;
if ( V_8 ) {
F_16 ( V_131 ) ;
F_16 ( V_130 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return V_8 ;
}
if ( * V_131 != V_104 ) {
F_18 ( V_2 , L_43 , V_12 ) ;
F_16 ( V_131 ) ;
F_16 ( V_130 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_60 ;
}
F_4 ( V_2 , L_44 , V_12 ) ;
V_8 = F_5 ( V_23 -> V_23 -> V_2 ,
V_132 ,
0 , 0 , NULL , 0 ,
V_18 ) ;
F_4 ( V_2 , L_45 , V_12 , V_8 ) ;
F_16 ( V_131 ) ;
F_16 ( V_130 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_60 ;
} else {
V_23 -> V_123 = V_121 ;
}
F_16 ( V_130 ) ;
}
else if ( ( V_26 = F_23 ( V_23 , V_104 , V_68 ) ) != 0 ) {
#define F_41 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_87 ;
T_1 * V_133 ;
V_87 = F_15 ( F_41 , V_39 ) ;
if ( ! V_87 ) {
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_40 ;
}
V_133 = F_15 ( F_41 , V_39 ) ;
if ( ! V_133 ) {
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_40 ;
}
F_4 ( V_2 , L_46 , V_12 ) ;
V_8 = F_29 ( V_87 , V_2 , V_89 ) ;
if ( V_8 ) {
F_16 ( V_133 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_65 ;
}
V_8 = F_22 ( V_23 ,
V_26 ,
F_41 ,
V_87 ) ;
if ( V_8 ) {
F_16 ( V_133 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_65 ;
}
V_8 = F_21 ( V_23 , V_26 ,
F_41 , V_133 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_47 , V_12 ) ;
F_16 ( V_133 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return V_8 ;
}
if ( memcmp ( V_133 , V_87 , F_41 ) ) {
F_4 ( V_2 , L_48 , V_12 ) ;
F_16 ( V_133 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return - V_65 ;
}
F_16 ( V_133 ) ;
F_16 ( V_87 ) ;
F_4 ( V_2 , L_49 , V_12 ) ;
V_8 = F_5 ( V_23 -> V_23 -> V_2 ,
V_134 ,
0 , 0 , NULL , 0 ,
V_135 ) ;
F_4 ( V_2 , L_50 , V_12 , V_8 ) ;
if ( V_8 ) {
F_18 ( V_2 ,
L_51 ,
V_12 ) ;
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return V_8 ;
}
}
F_16 ( V_68 ) ;
F_16 ( V_119 ) ;
return 0 ;
}
F_4 ( V_2 , L_52 , V_12 ) ;
V_8 = F_36 ( V_23 -> V_23 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_24 ( V_23 -> V_23 -> V_2 -> V_136 . V_137 )
!= V_138 ) {
F_4 ( V_2 , L_53 , V_12 ,
F_24 ( V_23 -> V_23 -> V_2 -> V_136 . V_137 ) ) ;
V_23 -> V_36 = V_105 ;
goto V_139;
}
if ( F_31 ( V_23 ) )
goto V_139;
if ( ! F_27 ( V_23 ) ) {
struct V_92 * V_87 ;
int V_35 ;
T_1 V_71 = 0 ;
T_1 * V_29 ;
int V_90 ;
V_119 = F_15 ( sizeof( * V_119 ) , V_39 ) ;
if ( ! V_119 )
return - V_40 ;
V_8 = F_28 ( V_23 , ( T_1 * ) V_119 ) ;
if ( V_8 ) {
F_16 ( V_119 ) ;
goto V_139;
}
if ( ! V_129 && F_37 ( V_119 ) < 2 ) {
F_4 ( V_2 , L_39 ,
V_12 , F_37 ( V_119 ) ) ;
F_16 ( V_119 ) ;
goto V_139;
}
F_16 ( V_119 ) ;
V_90 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_92 ) ) ;
V_29 = F_15 ( V_90 , V_39 ) ;
if ( ! V_29 )
return - V_40 ;
memset ( V_29 , 0xff , V_90 ) ;
memcpy ( V_29 , & V_89 -> V_6 [ 4 ] , V_89 -> V_7 - 4 ) ;
for ( V_35 = sizeof( struct V_92 ) ;
V_35 < V_90 ; V_35 ++ ) {
V_71 = ( T_1 ) ( V_71 + V_29 [ V_35 ] ) ;
}
V_87 = (struct V_92 * ) V_29 ;
V_87 -> V_102 = F_30 ( ( T_2 ) ( V_90 -
sizeof( struct V_92 ) ) ) ;
V_87 -> V_72 = V_71 ;
F_4 ( V_2 , L_54 ,
V_12 ,
V_97 -> V_99 , V_97 -> V_101 ) ;
V_8 = F_35 ( V_23 , V_29 , V_90 ) ;
F_16 ( V_29 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_55 , V_12 ) ;
return V_8 ;
}
V_23 -> V_61 . V_62 = V_140 ;
F_4 ( V_2 , L_56 , V_12 ) ;
return - V_60 ;
}
V_139:
F_4 ( V_2 , L_57 , V_12 ) ;
V_23 -> V_61 . V_62 = V_64 ;
return 0 ;
}
static int F_42 ( struct V_45 * V_20 , int V_141 , int V_142 )
{
int V_22 = V_20 -> V_20 -> V_22 ;
V_142 = ! ! V_142 ;
return F_7 ( V_20 -> V_20 -> V_23 -> V_2 ,
V_141 , ( T_1 ) ( V_25 + V_22 ) ,
V_142 , NULL , 0 ) ;
}
static int F_43 ( struct V_45 * V_20 , T_1 V_143 )
{
int V_8 = 0 ;
F_4 ( & V_20 -> V_20 -> V_2 , L_58 , V_12 , V_143 ) ;
V_8 = F_42 ( V_20 , V_144 , V_143 & V_145 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_42 ( V_20 , V_146 , V_143 & V_147 ) ;
if ( V_8 )
return V_8 ;
return F_42 ( V_20 , V_148 , V_143 & V_149 ) ;
}
static T_1 F_44 ( T_1 V_150 )
{
T_1 V_48 = 0 ;
#define F_45 ( T_5 , T_6 ) \
if (ti_lsr & flagUmp) \
lsr |= flagUart;
F_45 (UMP_UART_LSR_OV_MASK, LSR_OVER_ERR)
F_45 (UMP_UART_LSR_PE_MASK, LSR_PAR_ERR)
F_45 (UMP_UART_LSR_FE_MASK, LSR_FRM_ERR)
F_45 (UMP_UART_LSR_BR_MASK, LSR_BREAK)
F_45 (UMP_UART_LSR_RX_MASK, LSR_RX_AVAIL)
F_45 (UMP_UART_LSR_TX_MASK, LSR_TX_EMPTY)
#undef F_45
return V_48 ;
}
static void F_46 ( struct V_45 * V_151 , T_1 V_152 )
{
struct V_153 * V_154 ;
struct V_155 * V_156 ;
F_4 ( & V_151 -> V_20 -> V_2 , L_59 , V_12 , V_152 ) ;
if ( V_152 & ( V_157 | V_158 |
V_159 | V_160 ) ) {
V_154 = & V_151 -> V_20 -> V_154 ;
if ( V_152 & V_157 )
V_154 -> V_161 ++ ;
if ( V_152 & V_158 )
V_154 -> V_162 ++ ;
if ( V_152 & V_160 )
V_154 -> V_163 ++ ;
if ( V_152 & V_159 )
V_154 -> V_164 ++ ;
F_47 ( & V_151 -> V_20 -> V_20 . V_165 ) ;
}
V_151 -> V_166 = V_152 & 0xf0 ;
V_156 = F_48 ( & V_151 -> V_20 -> V_20 ) ;
if ( V_156 && F_49 ( V_156 ) ) {
if ( V_152 & V_167 )
F_50 ( V_156 ) ;
}
F_51 ( V_156 ) ;
}
static void F_52 ( struct V_45 * V_151 , int V_168 ,
T_1 V_48 , T_1 V_6 )
{
struct V_153 * V_154 ;
T_1 V_169 = ( T_1 ) ( V_48 & ( T_1 ) ( V_170 | V_171 |
V_172 | V_173 ) ) ;
F_4 ( & V_151 -> V_20 -> V_2 , L_59 , V_12 , V_169 ) ;
V_151 -> V_174 = V_48 ;
if ( V_169 & V_173 )
V_169 &= ( T_1 ) ( V_170 | V_173 ) ;
if ( V_168 )
F_53 ( V_151 -> V_20 , & V_6 , 1 ) ;
V_154 = & V_151 -> V_20 -> V_154 ;
if ( V_169 & V_173 )
V_154 -> V_175 ++ ;
if ( V_169 & V_170 )
V_154 -> V_176 ++ ;
if ( V_169 & V_171 )
V_154 -> V_177 ++ ;
if ( V_169 & V_172 )
V_154 -> V_178 ++ ;
}
static void F_54 ( struct V_179 * V_179 )
{
struct V_34 * V_180 = V_179 -> V_181 ;
struct V_19 * V_20 ;
struct V_45 * V_151 ;
struct V_42 * V_2 ;
unsigned char * V_6 = V_179 -> V_182 ;
int V_27 = V_179 -> V_183 ;
int V_22 ;
int V_184 ;
int V_185 ;
T_1 V_48 ;
T_1 V_152 ;
int V_8 = V_179 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_186 :
case - V_187 :
case - V_188 :
F_4 ( & V_179 -> V_2 -> V_2 , L_60 ,
V_12 , V_8 ) ;
return;
default:
F_18 ( & V_179 -> V_2 -> V_2 , L_61
L_62 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_27 ) {
F_4 ( & V_179 -> V_2 -> V_2 , L_63 , V_12 ) ;
goto exit;
}
V_2 = & V_180 -> V_23 -> V_2 -> V_2 ;
F_11 ( V_2 , V_12 , V_27 , V_6 ) ;
if ( V_27 != 2 ) {
F_4 ( V_2 , L_64 , V_12 , V_27 ) ;
goto exit;
}
V_22 = F_55 ( V_6 [ 0 ] ) ;
V_184 = F_56 ( V_6 [ 0 ] ) ;
F_4 ( V_2 , L_65 , V_12 ,
V_22 , V_184 , V_6 [ 1 ] ) ;
V_20 = V_180 -> V_23 -> V_20 [ V_22 ] ;
V_151 = F_57 ( V_20 ) ;
if ( ! V_151 ) {
F_4 ( V_2 , L_66 , V_12 ) ;
return;
}
switch ( V_184 ) {
case V_189 :
V_48 = F_44 ( V_6 [ 1 ] ) ;
if ( V_48 & V_190 ) {
F_4 ( V_2 , L_67 ,
V_12 , V_22 , V_48 ) ;
V_151 -> V_191 = 1 ;
V_151 -> V_192 = V_48 ;
} else {
F_4 ( V_2 , L_68 ,
V_12 , V_22 , V_48 ) ;
F_52 ( V_151 , 0 , V_48 , 0 ) ;
}
break;
case V_193 :
V_152 = V_6 [ 1 ] ;
F_4 ( V_2 , L_69 ,
V_12 , V_22 , V_152 ) ;
F_46 ( V_151 , V_152 ) ;
break;
default:
F_18 ( & V_179 -> V_2 -> V_2 ,
L_70 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_185 = F_58 ( V_179 , V_194 ) ;
if ( V_185 )
F_18 ( & V_179 -> V_2 -> V_2 ,
L_71 ,
V_12 , V_185 ) ;
}
static void F_59 ( struct V_179 * V_179 )
{
struct V_45 * V_151 = V_179 -> V_181 ;
struct V_42 * V_2 = & V_151 -> V_20 -> V_2 ;
unsigned char * V_6 = V_179 -> V_182 ;
int V_185 = 0 ;
int V_22 ;
int V_8 = V_179 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_186 :
case - V_187 :
case - V_188 :
F_4 ( & V_179 -> V_2 -> V_2 , L_60 , V_12 , V_8 ) ;
return;
default:
F_18 ( & V_179 -> V_2 -> V_2 , L_72 , V_12 , V_8 ) ;
}
if ( V_8 == - V_195 )
goto exit;
if ( V_8 ) {
F_18 ( & V_179 -> V_2 -> V_2 , L_73 , V_12 ) ;
return;
}
V_22 = V_151 -> V_20 -> V_22 ;
if ( V_151 -> V_191 ) {
V_151 -> V_191 = 0 ;
F_4 ( V_2 , L_74 ,
V_12 , V_22 , V_151 -> V_192 , * V_6 ) ;
F_52 ( V_151 , 1 , V_151 -> V_192 , * V_6 ) ;
-- V_179 -> V_183 ;
++ V_6 ;
}
if ( V_179 -> V_183 ) {
F_11 ( V_2 , V_12 , V_179 -> V_183 , V_6 ) ;
if ( V_151 -> V_196 )
F_4 ( V_2 , L_75 ,
V_12 ) ;
else
F_53 ( V_151 -> V_20 , V_6 ,
V_179 -> V_183 ) ;
V_151 -> V_20 -> V_154 . V_197 += V_179 -> V_183 ;
}
exit:
F_60 ( & V_151 -> V_198 ) ;
if ( V_151 -> V_199 == V_200 )
V_185 = F_58 ( V_179 , V_194 ) ;
else if ( V_151 -> V_199 == V_201 )
V_151 -> V_199 = V_202 ;
F_61 ( & V_151 -> V_198 ) ;
if ( V_185 )
F_18 ( V_2 , L_71 , V_12 , V_185 ) ;
}
static void F_53 ( struct V_19 * V_20 , unsigned char * V_6 ,
int V_27 )
{
int V_203 ;
V_203 = F_62 ( & V_20 -> V_20 , V_6 , V_27 ) ;
if ( V_203 < V_27 )
F_18 ( & V_20 -> V_2 , L_76 ,
V_12 , V_27 - V_203 ) ;
F_63 ( & V_20 -> V_20 ) ;
}
static void F_64 ( struct V_179 * V_179 )
{
struct V_19 * V_20 = V_179 -> V_181 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_8 = V_179 -> V_8 ;
struct V_155 * V_156 ;
V_151 -> V_204 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_186 :
case - V_187 :
case - V_188 :
F_4 ( & V_179 -> V_2 -> V_2 , L_60 ,
V_12 , V_8 ) ;
return;
default:
F_65 ( V_20 , L_77
L_78 , V_12 , V_8 ) ;
}
V_156 = F_48 ( & V_20 -> V_20 ) ;
F_66 ( V_20 , V_156 ) ;
F_51 ( V_156 ) ;
}
static int F_67 ( struct V_155 * V_156 , struct V_19 * V_20 )
{
struct V_45 * V_151 = F_57 ( V_20 ) ;
struct V_34 * V_180 ;
struct V_1 * V_2 ;
struct V_179 * V_179 ;
int V_22 ;
int V_8 ;
T_4 V_205 ;
T_3 V_206 ;
if ( V_151 == NULL )
return - V_60 ;
V_22 = V_20 -> V_22 ;
V_2 = V_20 -> V_23 -> V_2 ;
V_8 = F_42 ( V_151 , V_148 , 0 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_79 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_156 )
F_68 ( V_156 , V_20 , & V_156 -> V_207 ) ;
V_206 = 2 ;
V_151 -> V_208 =
F_69 ( 20 , ( ( V_206 * 3 ) / 2 ) ) ;
V_205 = ( T_3 ) ( V_209 |
V_210 |
( V_206 << 2 ) ) ;
F_4 ( & V_20 -> V_2 , L_80 , V_12 ) ;
V_8 = F_7 ( V_2 , V_211 ,
( T_3 ) ( V_25 + V_22 ) , V_205 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 , L_81 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_212 ,
( T_3 ) ( V_25 + V_22 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 , L_82 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_20 , V_213 | V_214 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_83 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_215 , 0 ,
( T_2 ) ( V_25 + V_22 ) ,
& V_151 -> V_166 , 1 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 , L_84 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( & V_20 -> V_2 , L_85 , V_151 -> V_166 ) ;
V_151 -> V_216 = V_147 | V_145 ;
F_4 ( & V_20 -> V_2 , L_86 , V_151 -> V_216 ) ;
V_180 = V_151 -> V_180 ;
if ( F_70 ( & V_180 -> V_217 ) )
return - V_218 ;
if ( V_180 -> V_219 == 0 ) {
V_179 = V_180 -> V_23 -> V_20 [ 0 ] -> V_220 ;
if ( ! V_179 ) {
F_18 ( & V_20 -> V_2 ,
L_87 ,
V_12 ) ;
V_8 = - V_65 ;
goto V_221;
}
V_179 -> V_181 = V_180 ;
V_8 = F_58 ( V_179 , V_39 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_88 ,
V_12 , V_8 ) ;
goto V_221;
}
}
F_71 ( V_2 , V_20 -> V_222 -> V_223 ) ;
F_71 ( V_2 , V_20 -> V_224 -> V_223 ) ;
V_179 = V_20 -> V_224 ;
if ( ! V_179 ) {
F_18 ( & V_20 -> V_2 , L_89 ,
V_12 ) ;
V_8 = - V_65 ;
goto V_225;
}
V_151 -> V_199 = V_200 ;
V_179 -> V_181 = V_151 ;
V_8 = F_58 ( V_179 , V_39 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_90 ,
V_12 , V_8 ) ;
goto V_225;
}
++ V_180 -> V_219 ;
goto V_221;
V_225:
if ( V_151 -> V_180 -> V_219 == 0 )
F_72 ( V_20 -> V_23 -> V_20 [ 0 ] -> V_220 ) ;
V_221:
F_73 ( & V_180 -> V_217 ) ;
return V_8 ;
}
static void F_74 ( struct V_19 * V_20 )
{
struct V_34 * V_180 ;
struct V_45 * V_151 ;
struct V_107 * V_23 = V_20 -> V_23 ;
unsigned long V_226 ;
int V_22 ;
V_180 = F_75 ( V_20 -> V_23 ) ;
V_151 = F_57 ( V_20 ) ;
if ( V_180 == NULL || V_151 == NULL )
return;
V_151 -> V_196 = 1 ;
F_72 ( V_20 -> V_224 ) ;
F_72 ( V_20 -> V_222 ) ;
V_151 -> V_204 = 0 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
F_77 ( & V_20 -> V_227 ) ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
F_4 ( & V_20 -> V_2 , L_91 , V_12 ) ;
V_22 = V_20 -> V_22 ;
F_7 ( V_23 -> V_2 , V_228 ,
( T_1 ) ( V_25 + V_22 ) , 0 , NULL , 0 ) ;
F_79 ( & V_180 -> V_217 ) ;
-- V_151 -> V_180 -> V_219 ;
if ( V_151 -> V_180 -> V_219 <= 0 ) {
F_72 ( V_20 -> V_23 -> V_20 [ 0 ] -> V_220 ) ;
V_151 -> V_180 -> V_219 = 0 ;
}
F_73 ( & V_180 -> V_217 ) ;
V_151 -> V_196 = 0 ;
}
static int F_80 ( struct V_155 * V_156 , struct V_19 * V_20 ,
const unsigned char * V_6 , int V_229 )
{
struct V_45 * V_151 = F_57 ( V_20 ) ;
if ( V_229 == 0 ) {
F_4 ( & V_20 -> V_2 , L_92 , V_12 ) ;
return 0 ;
}
if ( V_151 == NULL )
return - V_60 ;
if ( V_151 -> V_196 == 1 )
return - V_60 ;
V_229 = F_81 ( & V_20 -> V_227 , V_6 , V_229 ,
& V_151 -> V_198 ) ;
F_66 ( V_20 , V_156 ) ;
return V_229 ;
}
static void F_66 ( struct V_19 * V_20 , struct V_155 * V_156 )
{
int V_229 , V_230 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
unsigned long V_226 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
if ( V_151 -> V_204 ) {
F_78 ( & V_151 -> V_198 , V_226 ) ;
return;
}
V_229 = F_82 ( & V_20 -> V_227 ,
V_20 -> V_222 -> V_182 ,
V_20 -> V_231 ) ;
if ( V_229 == 0 ) {
F_78 ( & V_151 -> V_198 , V_226 ) ;
return;
}
V_151 -> V_204 = 1 ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
F_11 ( & V_20 -> V_2 , V_12 , V_229 , V_20 -> V_222 -> V_182 ) ;
V_20 -> V_222 -> V_232 = V_229 ;
V_230 = F_58 ( V_20 -> V_222 , V_194 ) ;
if ( V_230 ) {
F_65 ( V_20 ,
L_93 ,
V_12 , V_230 ) ;
V_151 -> V_204 = 0 ;
} else
V_151 -> V_20 -> V_154 . V_233 += V_229 ;
if ( V_156 )
F_50 ( V_156 ) ;
}
static int F_83 ( struct V_155 * V_156 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_235 = 0 ;
unsigned long V_226 ;
if ( V_151 == NULL )
return 0 ;
if ( V_151 -> V_196 == 1 )
return 0 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
V_235 = F_84 ( & V_20 -> V_227 ) ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
F_4 ( & V_20 -> V_2 , L_94 , V_12 , V_235 ) ;
return V_235 ;
}
static int F_85 ( struct V_155 * V_156 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_236 = 0 ;
unsigned long V_226 ;
if ( V_151 == NULL )
return 0 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
V_236 = F_86 ( & V_20 -> V_227 ) ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
F_4 ( & V_20 -> V_2 , L_94 , V_12 , V_236 ) ;
return V_236 ;
}
static bool F_87 ( struct V_19 * V_20 )
{
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_237 ;
V_237 = F_19 ( V_151 ) ;
if ( V_237 > 0 )
return false ;
return true ;
}
static void F_88 ( struct V_155 * V_156 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_8 ;
if ( V_151 == NULL )
return;
if ( F_89 ( V_156 ) ) {
unsigned char V_238 = F_90 ( V_156 ) ;
V_8 = F_80 ( V_156 , V_20 , & V_238 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_20 -> V_2 , L_95 , V_12 , V_8 ) ;
}
}
if ( F_49 ( V_156 ) )
F_91 ( V_151 ) ;
}
static void F_92 ( struct V_155 * V_156 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_8 ;
if ( V_151 == NULL )
return;
if ( F_89 ( V_156 ) ) {
unsigned char V_239 = F_93 ( V_156 ) ;
V_8 = F_80 ( V_156 , V_20 , & V_239 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_20 -> V_2 , L_96 , V_12 , V_8 ) ;
}
}
if ( F_49 ( V_156 ) ) {
V_8 = F_94 ( V_151 ) ;
if ( V_8 )
F_18 ( & V_20 -> V_2 ,
L_97 ,
V_12 , V_8 ) ;
}
}
static void F_91 ( struct V_45 * V_151 )
{
unsigned long V_226 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
if ( V_151 -> V_199 == V_200 )
V_151 -> V_199 = V_201 ;
V_151 -> V_216 &= ~ V_147 ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
}
static int F_94 ( struct V_45 * V_151 )
{
struct V_179 * V_179 ;
int V_8 = 0 ;
unsigned long V_226 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
if ( V_151 -> V_199 == V_202 ) {
V_179 = V_151 -> V_20 -> V_224 ;
V_8 = F_58 ( V_179 , V_194 ) ;
}
V_151 -> V_199 = V_200 ;
V_151 -> V_216 |= V_147 ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
return V_8 ;
}
static void F_95 ( struct V_155 * V_156 ,
struct V_45 * V_151 , struct V_240 * V_241 )
{
struct V_42 * V_2 = & V_151 -> V_20 -> V_2 ;
struct V_242 * V_56 ;
int V_243 ;
unsigned V_244 ;
int V_8 ;
int V_22 = V_151 -> V_20 -> V_22 ;
V_56 = F_15 ( sizeof ( * V_56 ) , V_39 ) ;
if ( ! V_56 ) {
V_156 -> V_207 = * V_241 ;
return;
}
V_244 = V_156 -> V_207 . V_245 ;
V_56 -> V_246 = 0 ;
V_56 -> V_246 |= V_247 ;
V_56 -> V_246 |= V_248 ;
V_56 -> V_249 = ( T_1 ) ( V_151 -> V_249 ) ;
switch ( V_244 & V_250 ) {
case V_251 :
V_56 -> V_252 = V_253 ;
F_4 ( V_2 , L_98 , V_12 ) ;
break;
case V_254 :
V_56 -> V_252 = V_255 ;
F_4 ( V_2 , L_99 , V_12 ) ;
break;
case V_256 :
V_56 -> V_252 = V_257 ;
F_4 ( V_2 , L_100 , V_12 ) ;
break;
default:
case V_258 :
V_56 -> V_252 = V_259 ;
F_4 ( V_2 , L_101 , V_12 ) ;
break;
}
if ( V_244 & V_260 ) {
if ( V_244 & V_261 ) {
V_56 -> V_246 |= V_262 ;
V_56 -> V_263 = V_264 ;
F_4 ( V_2 , L_102 , V_12 ) ;
} else {
V_56 -> V_246 |= V_262 ;
V_56 -> V_263 = V_265 ;
F_4 ( V_2 , L_103 , V_12 ) ;
}
} else {
V_56 -> V_263 = V_266 ;
F_4 ( V_2 , L_104 , V_12 ) ;
}
if ( V_244 & V_267 ) {
V_56 -> V_268 = V_269 ;
F_4 ( V_2 , L_105 , V_12 ) ;
} else {
V_56 -> V_268 = V_270 ;
F_4 ( V_2 , L_106 , V_12 ) ;
}
if ( V_244 & V_271 ) {
V_56 -> V_246 |= V_272 ;
V_56 -> V_246 |= V_273 ;
F_4 ( V_2 , L_107 , V_12 ) ;
} else {
F_4 ( V_2 , L_108 , V_12 ) ;
F_94 ( V_151 ) ;
}
V_56 -> V_274 = F_93 ( V_156 ) ;
V_56 -> V_275 = F_90 ( V_156 ) ;
if ( F_89 ( V_156 ) ) {
V_56 -> V_246 |= V_276 ;
F_4 ( V_2 , L_109 ,
V_12 , V_56 -> V_274 , V_56 -> V_275 ) ;
} else
F_4 ( V_2 , L_110 , V_12 ) ;
if ( F_96 ( V_156 ) ) {
V_56 -> V_246 |= V_277 ;
F_4 ( V_2 , L_111 ,
V_12 , V_56 -> V_274 , V_56 -> V_275 ) ;
} else
F_4 ( V_2 , L_112 , V_12 ) ;
V_156 -> V_207 . V_245 &= ~ V_278 ;
V_243 = F_97 ( V_156 ) ;
if ( ! V_243 ) {
V_243 = 9600 ;
} else
F_98 ( V_156 , V_243 , V_243 ) ;
V_151 -> V_279 = V_243 ;
V_56 -> V_280 = ( T_2 ) ( ( 461550L + V_243 / 2 ) / V_243 ) ;
F_4 ( V_2 , L_113 , V_12 , V_243 , V_56 -> V_280 ) ;
F_4 ( V_2 , L_114 , ( int ) ( 461550L / V_56 -> V_280 ) ) ;
F_4 ( V_2 , L_115 , V_56 -> V_246 ) ;
F_4 ( V_2 , L_116 , V_56 -> V_252 ) ;
F_4 ( V_2 , L_117 , V_56 -> V_263 ) ;
F_4 ( V_2 , L_118 , V_56 -> V_268 ) ;
F_4 ( V_2 , L_119 , V_56 -> V_274 ) ;
F_4 ( V_2 , L_120 , V_56 -> V_275 ) ;
F_4 ( V_2 , L_121 , V_56 -> V_249 ) ;
F_99 ( & V_56 -> V_246 ) ;
F_99 ( & V_56 -> V_280 ) ;
V_8 = F_7 ( V_151 -> V_20 -> V_23 -> V_2 , V_281 ,
( T_1 ) ( V_25 + V_22 ) ,
0 , ( T_1 * ) V_56 , sizeof( * V_56 ) ) ;
if ( V_8 )
F_4 ( V_2 , L_122 ,
V_12 , V_8 ) ;
F_16 ( V_56 ) ;
}
static void F_68 ( struct V_155 * V_156 ,
struct V_19 * V_20 , struct V_240 * V_241 )
{
struct V_45 * V_151 = F_57 ( V_20 ) ;
unsigned int V_244 ;
V_244 = V_156 -> V_207 . V_245 ;
F_4 ( & V_20 -> V_2 , L_123 , V_12 ,
V_156 -> V_207 . V_245 , V_156 -> V_207 . V_282 ) ;
F_4 ( & V_20 -> V_2 , L_124 , V_12 ,
V_241 -> V_245 , V_241 -> V_282 ) ;
if ( V_151 == NULL )
return;
F_95 ( V_156 , V_151 , V_241 ) ;
}
static int F_100 ( struct V_155 * V_156 ,
unsigned int V_283 , unsigned int V_284 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
unsigned int V_143 ;
unsigned long V_226 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
V_143 = V_151 -> V_216 ;
if ( V_283 & V_285 )
V_143 |= V_147 ;
if ( V_283 & V_286 )
V_143 |= V_145 ;
if ( V_283 & V_287 )
V_143 |= V_149 ;
if ( V_284 & V_285 )
V_143 &= ~ V_147 ;
if ( V_284 & V_286 )
V_143 &= ~ V_145 ;
if ( V_284 & V_287 )
V_143 &= ~ V_149 ;
V_151 -> V_216 = V_143 ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
F_43 ( V_151 , V_143 ) ;
return 0 ;
}
static int F_101 ( struct V_155 * V_156 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
unsigned int V_230 = 0 ;
unsigned int V_152 ;
unsigned int V_143 ;
unsigned long V_226 ;
F_76 ( & V_151 -> V_198 , V_226 ) ;
V_152 = V_151 -> V_166 ;
V_143 = V_151 -> V_216 ;
V_230 = ( ( V_143 & V_145 ) ? V_286 : 0 )
| ( ( V_143 & V_147 ) ? V_285 : 0 )
| ( ( V_152 & V_167 ) ? V_288 : 0 )
| ( ( V_152 & V_289 ) ? V_290 : 0 )
| ( ( V_152 & V_291 ) ? V_292 : 0 )
| ( ( V_152 & V_293 ) ? V_294 : 0 ) ;
F_4 ( & V_20 -> V_2 , L_125 , V_12 , V_230 ) ;
F_78 ( & V_151 -> V_198 , V_226 ) ;
return V_230 ;
}
static int F_102 ( struct V_45 * V_151 ,
struct V_295 T_7 * V_296 )
{
struct V_295 V_297 ;
unsigned V_298 ;
if ( ! V_296 )
return - V_299 ;
V_298 = V_151 -> V_20 -> V_20 . V_300 ;
if ( V_298 != V_301 )
V_298 = F_103 ( V_298 ) / 10 ;
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
V_297 . type = V_302 ;
V_297 . line = V_151 -> V_20 -> V_303 ;
V_297 . V_20 = V_151 -> V_20 -> V_22 ;
V_297 . V_304 = 0 ;
V_297 . V_226 = V_305 | V_306 ;
V_297 . V_307 = V_151 -> V_20 -> V_231 ;
V_297 . V_308 = 9600 ;
V_297 . V_309 = 5 * V_310 ;
V_297 . V_300 = V_298 ;
if ( F_104 ( V_296 , & V_297 , sizeof( * V_296 ) ) )
return - V_299 ;
return 0 ;
}
static int F_105 ( struct V_155 * V_156 ,
unsigned int V_311 , unsigned long V_312 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
switch ( V_311 ) {
case V_313 :
F_4 ( & V_20 -> V_2 , L_126 , V_12 ) ;
return F_102 ( V_151 ,
(struct V_295 T_7 * ) V_312 ) ;
}
return - V_314 ;
}
static void F_106 ( struct V_155 * V_156 , int V_315 )
{
struct V_19 * V_20 = V_156 -> V_234 ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
int V_8 ;
int V_316 = 0 ;
if ( V_315 == - 1 )
V_316 = 1 ;
V_8 = F_42 ( V_151 , V_317 , V_316 ) ;
if ( V_8 )
F_4 ( & V_20 -> V_2 , L_127 ,
V_12 , V_8 ) ;
}
static void F_107 ( struct V_34 * V_180 )
{
if ( ! V_180 -> V_318 )
return;
F_108 ( & V_180 -> V_319 ,
V_320 * V_310 ) ;
}
static void F_109 ( struct V_321 * V_322 )
{
struct V_34 * V_23 ;
struct V_67 * V_68 ;
V_23 = F_110 ( V_322 , struct V_34 ,
V_319 . V_322 ) ;
V_68 = F_15 ( sizeof( * V_68 ) , V_39 ) ;
if ( ! V_68 || ! F_23 ( V_23 , V_79 ,
V_68 ) ) {
F_18 ( & V_23 -> V_23 -> V_118 -> V_2 ,
L_128 , V_12 ) ;
}
F_16 ( V_68 ) ;
F_107 ( V_23 ) ;
}
static int F_111 ( struct V_107 * V_23 )
{
struct V_34 * V_180 ;
int V_8 ;
const struct V_88 * V_89 ;
const char * V_323 = L_129 ;
struct V_42 * V_2 = & V_23 -> V_118 -> V_2 ;
T_4 V_324 ;
V_180 = F_112 ( sizeof( struct V_34 ) , V_39 ) ;
if ( ! V_180 )
return - V_40 ;
F_113 ( & V_180 -> V_217 ) ;
V_180 -> V_23 = V_23 ;
F_114 ( V_23 , V_180 ) ;
V_8 = F_115 ( & V_89 , V_323 , V_2 ) ;
if ( V_8 ) {
F_18 ( V_2 , L_130 ,
V_323 , V_8 ) ;
F_16 ( V_180 ) ;
return V_8 ;
}
V_8 = F_40 ( V_180 , V_89 ) ;
F_116 ( V_89 ) ;
if ( V_8 ) {
F_16 ( V_180 ) ;
return V_8 ;
}
V_324 = F_24 (
V_180 -> V_23 -> V_2 -> V_136 . V_325 ) ;
if ( V_180 -> V_123 > V_326 ) {
if ( V_324 == V_327 ||
V_324 == V_328 ) {
V_180 -> V_318 = true ;
}
}
F_117 ( & V_180 -> V_319 , F_109 ) ;
F_107 ( V_180 ) ;
return 0 ;
}
static void F_118 ( struct V_107 * V_23 )
{
}
static void F_119 ( struct V_107 * V_23 )
{
struct V_34 * V_180 = F_75 ( V_23 ) ;
F_120 ( & V_180 -> V_319 ) ;
F_16 ( V_180 ) ;
}
static int F_121 ( struct V_19 * V_20 )
{
struct V_45 * V_151 ;
int V_237 ;
V_151 = F_112 ( sizeof( * V_151 ) , V_39 ) ;
if ( ! V_151 )
return - V_40 ;
F_122 ( & V_151 -> V_198 ) ;
V_151 -> V_20 = V_20 ;
V_151 -> V_180 = F_75 ( V_20 -> V_23 ) ;
V_151 -> V_249 = V_329 ;
switch ( V_20 -> V_22 ) {
case 0 :
V_151 -> V_53 = V_330 ;
V_151 -> V_50 = V_331 ;
break;
case 1 :
V_151 -> V_53 = V_332 ;
V_151 -> V_50 = V_333 ;
break;
default:
F_18 ( & V_20 -> V_2 , L_131 ) ;
V_237 = - V_60 ;
goto V_334;
}
F_4 ( & V_20 -> V_2 ,
L_132 ,
V_12 , V_20 -> V_22 , V_151 -> V_53 ,
V_151 -> V_50 ) ;
F_123 ( V_20 , V_151 ) ;
V_237 = F_124 ( V_20 ) ;
if ( V_237 )
goto V_334;
V_20 -> V_20 . V_300 = F_125 ( V_300 * 10 ) ;
V_20 -> V_20 . V_335 = 1 ;
return 0 ;
V_334:
F_16 ( V_151 ) ;
return V_237 ;
}
static int F_126 ( struct V_19 * V_20 )
{
struct V_45 * V_151 ;
V_151 = F_57 ( V_20 ) ;
F_127 ( V_20 ) ;
F_16 ( V_151 ) ;
return 0 ;
}
static T_8 F_128 ( struct V_42 * V_2 ,
struct V_336 * V_337 , char * V_338 )
{
struct V_19 * V_20 = F_129 ( V_2 ) ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
return sprintf ( V_338 , L_62 , V_151 -> V_249 ) ;
}
static T_8 F_130 ( struct V_42 * V_2 ,
struct V_336 * V_337 , const char * V_339 , T_9 V_229 )
{
struct V_19 * V_20 = F_129 ( V_2 ) ;
struct V_45 * V_151 = F_57 ( V_20 ) ;
unsigned int V_340 = F_131 ( V_339 , NULL , 0 ) ;
F_4 ( V_2 , L_133 , V_12 , V_340 ) ;
if ( V_340 < 256 )
V_151 -> V_249 = V_340 ;
else
F_18 ( V_2 , L_134 , V_12 , V_340 ) ;
return V_229 ;
}
static int F_124 ( struct V_19 * V_20 )
{
return F_132 ( & V_20 -> V_2 , & V_341 ) ;
}
static int F_127 ( struct V_19 * V_20 )
{
F_133 ( & V_20 -> V_2 , & V_341 ) ;
return 0 ;
}
static int F_134 ( struct V_107 * V_23 , T_10 V_342 )
{
struct V_34 * V_180 = F_75 ( V_23 ) ;
F_120 ( & V_180 -> V_319 ) ;
return 0 ;
}
static int F_135 ( struct V_107 * V_23 )
{
struct V_34 * V_180 = F_75 ( V_23 ) ;
F_107 ( V_180 ) ;
return 0 ;
}
