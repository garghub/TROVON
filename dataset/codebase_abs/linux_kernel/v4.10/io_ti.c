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
static int F_29 ( T_3 * V_87 , const struct V_88 * V_89 )
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
static int F_40 ( struct V_34 * V_23 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_118 -> V_2 ;
int V_8 = 0 ;
struct V_119 * V_118 ;
const struct V_88 * V_89 ;
const char * V_120 = L_36 ;
struct V_96 * V_97 ;
V_8 = F_41 ( & V_89 , V_120 , V_2 ) ;
if ( V_8 ) {
F_18 ( V_2 , L_37 ,
V_120 , V_8 ) ;
return V_8 ;
}
if ( F_39 ( V_23 , V_89 ) ) {
V_8 = - V_65 ;
goto V_74;
}
V_97 = (struct V_96 * ) V_89 -> V_6 ;
V_23 -> V_121 = ( V_97 -> V_99 << 8 ) +
V_97 -> V_101 ;
V_23 -> V_61 . V_122 = V_123 ;
V_23 -> V_36 = V_105 ;
V_8 = F_20 ( V_23 -> V_23 -> V_2 ) ;
if ( V_8 )
goto V_74;
V_118 = & V_23 -> V_23 -> V_118 -> V_124 -> V_57 ;
if ( ! V_118 ) {
F_18 ( V_2 , L_38 , V_12 ) ;
V_8 = - V_60 ;
goto V_74;
}
if ( V_118 -> V_125 > 1 ) {
V_23 -> V_61 . V_62 = V_63 ;
V_8 = F_42 ( V_23 , V_89 ) ;
} else {
V_23 -> V_61 . V_62 = V_126 ;
V_8 = F_43 ( V_23 , V_89 ) ;
}
V_74:
F_44 ( V_89 ) ;
return V_8 ;
}
static int F_42 ( struct V_34 * V_23 ,
const struct V_88 * V_89 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_118 -> V_2 ;
int V_8 = 0 ;
int V_26 ;
struct V_80 * V_127 ;
int V_128 ;
int V_129 ;
struct V_96 * V_97 = (struct V_96 * ) V_89 -> V_6 ;
struct V_67 * V_68 ;
F_4 ( V_2 , L_39 , V_12 ) ;
V_8 = F_27 ( V_23 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_40 , V_12 ) ;
return V_8 ;
}
V_127 = F_15 ( sizeof( * V_127 ) , V_39 ) ;
if ( ! V_127 )
return - V_40 ;
V_8 = F_28 ( V_23 , ( T_1 * ) V_127 ) ;
if ( V_8 ) {
F_16 ( V_127 ) ;
return V_8 ;
}
if ( ! V_130 && F_37 ( V_127 ) < 2 ) {
F_4 ( V_2 , L_41 ,
V_12 , F_37 ( V_127 ) ) ;
F_16 ( V_127 ) ;
return - V_65 ;
}
V_68 = F_15 ( sizeof( * V_68 ) , V_39 ) ;
if ( ! V_68 ) {
F_16 ( V_127 ) ;
return - V_40 ;
}
V_26 = F_23 ( V_23 ,
V_77 , V_68 ) ;
if ( V_26 != 0 ) {
struct V_94 * V_131 ;
T_3 * V_132 ;
F_4 ( V_2 , L_42 ,
V_12 ) ;
V_131 = F_15 ( sizeof( * V_131 ) ,
V_39 ) ;
if ( ! V_131 ) {
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_40 ;
}
V_8 = F_21 ( V_23 , V_26 +
sizeof( struct V_67 ) ,
sizeof( struct V_94 ) ,
( T_1 * ) V_131 ) ;
if ( V_8 ) {
F_16 ( V_131 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return V_8 ;
}
V_128 = ( V_131 -> V_98 << 8 ) +
( V_131 -> V_100 ) ;
V_129 = ( V_97 -> V_99 << 8 ) +
( V_97 -> V_101 ) ;
F_4 ( V_2 , L_43 ,
V_12 , V_131 -> V_98 ,
V_131 -> V_100 ,
V_97 -> V_99 , V_97 -> V_101 ) ;
if ( V_128 < V_129 ) {
F_4 ( V_2 , L_44 ,
V_12 ,
V_131 -> V_98 ,
V_131 -> V_100 ,
V_97 -> V_99 ,
V_97 -> V_101 ) ;
V_132 = F_15 ( 1 , V_39 ) ;
if ( ! V_132 ) {
F_16 ( V_131 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_40 ;
}
* V_132 = V_104 ;
V_8 = F_22 ( V_23 , V_26 ,
sizeof( * V_132 ) , V_132 ) ;
if ( V_8 ) {
F_16 ( V_132 ) ;
F_16 ( V_131 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return V_8 ;
}
V_8 = F_21 ( V_23 ,
V_26 ,
sizeof( * V_132 ) ,
V_132 ) ;
if ( V_8 ) {
F_16 ( V_132 ) ;
F_16 ( V_131 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return V_8 ;
}
if ( * V_132 != V_104 ) {
F_18 ( V_2 , L_45 ,
V_12 ) ;
F_16 ( V_132 ) ;
F_16 ( V_131 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_60 ;
}
F_4 ( V_2 , L_46 , V_12 ) ;
V_8 = F_5 ( V_23 -> V_23 -> V_2 ,
V_133 ,
0 , 0 , NULL , 0 ,
V_18 ) ;
F_4 ( V_2 , L_47 ,
V_12 , V_8 ) ;
F_16 ( V_132 ) ;
F_16 ( V_131 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_60 ;
}
V_23 -> V_121 = V_128 ;
F_16 ( V_131 ) ;
}
else {
V_26 = F_23 ( V_23 ,
V_104 , V_68 ) ;
if ( V_26 != 0 ) {
#define F_45 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_87 ;
T_1 * V_134 ;
V_87 = F_15 ( F_45 , V_39 ) ;
if ( ! V_87 ) {
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_40 ;
}
V_134 = F_15 ( F_45 , V_39 ) ;
if ( ! V_134 ) {
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_40 ;
}
F_4 ( V_2 , L_48 ,
V_12 ) ;
V_8 = F_29 ( V_87 , V_89 ) ;
if ( V_8 ) {
F_16 ( V_134 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_65 ;
}
V_8 = F_22 ( V_23 ,
V_26 ,
F_45 ,
V_87 ) ;
if ( V_8 ) {
F_16 ( V_134 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_65 ;
}
V_8 = F_21 ( V_23 , V_26 ,
F_45 , V_134 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_49 ,
V_12 ) ;
F_16 ( V_134 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return V_8 ;
}
if ( memcmp ( V_134 , V_87 , F_45 ) ) {
F_4 ( V_2 , L_50 ,
V_12 ) ;
F_16 ( V_134 ) ;
F_16 ( V_87 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return - V_65 ;
}
F_16 ( V_134 ) ;
F_16 ( V_87 ) ;
F_4 ( V_2 , L_51 , V_12 ) ;
V_8 = F_5 ( V_23 -> V_23 -> V_2 ,
V_135 ,
0 , 0 , NULL , 0 ,
V_136 ) ;
F_4 ( V_2 , L_52 , V_12 ,
V_8 ) ;
if ( V_8 ) {
F_18 ( V_2 ,
L_53 ,
V_12 ) ;
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return V_8 ;
}
}
}
F_16 ( V_68 ) ;
F_16 ( V_127 ) ;
return 0 ;
}
static int F_43 ( struct V_34 * V_23 ,
const struct V_88 * V_89 )
{
struct V_42 * V_2 = & V_23 -> V_23 -> V_118 -> V_2 ;
int V_8 = 0 ;
struct V_80 * V_127 ;
struct V_96 * V_97 = (struct V_96 * ) V_89 -> V_6 ;
F_4 ( V_2 , L_54 , V_12 ) ;
V_8 = F_36 ( V_23 -> V_23 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_24 ( V_23 -> V_23 -> V_2 -> V_137 . V_138 )
!= V_139 ) {
F_4 ( V_2 , L_55 , V_12 ,
F_24 ( V_23 -> V_23 -> V_2 -> V_137 . V_138 ) ) ;
V_23 -> V_36 = V_105 ;
goto V_140;
}
if ( F_31 ( V_23 ) )
goto V_140;
if ( ! F_27 ( V_23 ) ) {
struct V_92 * V_87 ;
int V_35 ;
T_1 V_71 = 0 ;
T_1 * V_29 ;
int V_90 ;
V_127 = F_15 ( sizeof( * V_127 ) , V_39 ) ;
if ( ! V_127 )
return - V_40 ;
V_8 = F_28 ( V_23 , ( T_1 * ) V_127 ) ;
if ( V_8 ) {
F_16 ( V_127 ) ;
goto V_140;
}
if ( ! V_130 && F_37 ( V_127 ) < 2 ) {
F_4 ( V_2 , L_41 ,
V_12 , F_37 ( V_127 ) ) ;
F_16 ( V_127 ) ;
goto V_140;
}
F_16 ( V_127 ) ;
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
F_4 ( V_2 , L_56 ,
V_12 ,
V_97 -> V_99 , V_97 -> V_101 ) ;
V_8 = F_35 ( V_23 , V_29 , V_90 ) ;
F_16 ( V_29 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_57 , V_12 ) ;
return V_8 ;
}
V_23 -> V_61 . V_62 = V_141 ;
F_4 ( V_2 , L_58 , V_12 ) ;
return 1 ;
}
V_140:
F_4 ( V_2 , L_59 , V_12 ) ;
V_23 -> V_61 . V_62 = V_64 ;
return 1 ;
}
static int F_46 ( struct V_45 * V_20 , int V_142 , int V_143 )
{
int V_22 = V_20 -> V_20 -> V_22 ;
V_143 = ! ! V_143 ;
return F_7 ( V_20 -> V_20 -> V_23 -> V_2 ,
V_142 , ( T_1 ) ( V_25 + V_22 ) ,
V_143 , NULL , 0 ) ;
}
static int F_47 ( struct V_45 * V_20 , T_1 V_144 )
{
int V_8 = 0 ;
F_4 ( & V_20 -> V_20 -> V_2 , L_60 , V_12 , V_144 ) ;
V_8 = F_46 ( V_20 , V_145 , V_144 & V_146 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_46 ( V_20 , V_147 , V_144 & V_148 ) ;
if ( V_8 )
return V_8 ;
return F_46 ( V_20 , V_149 , V_144 & V_150 ) ;
}
static T_1 F_48 ( T_1 V_151 )
{
T_1 V_48 = 0 ;
#define F_49 ( T_5 , T_6 ) \
if (ti_lsr & flagUmp) \
lsr |= flagUart;
F_49 (UMP_UART_LSR_OV_MASK, LSR_OVER_ERR)
F_49 (UMP_UART_LSR_PE_MASK, LSR_PAR_ERR)
F_49 (UMP_UART_LSR_FE_MASK, LSR_FRM_ERR)
F_49 (UMP_UART_LSR_BR_MASK, LSR_BREAK)
F_49 (UMP_UART_LSR_RX_MASK, LSR_RX_AVAIL)
F_49 (UMP_UART_LSR_TX_MASK, LSR_TX_EMPTY)
#undef F_49
return V_48 ;
}
static void F_50 ( struct V_45 * V_152 , T_1 V_153 )
{
struct V_154 * V_155 ;
struct V_156 * V_157 ;
F_4 ( & V_152 -> V_20 -> V_2 , L_61 , V_12 , V_153 ) ;
if ( V_153 & ( V_158 | V_159 |
V_160 | V_161 ) ) {
V_155 = & V_152 -> V_20 -> V_155 ;
if ( V_153 & V_158 )
V_155 -> V_162 ++ ;
if ( V_153 & V_159 )
V_155 -> V_163 ++ ;
if ( V_153 & V_161 )
V_155 -> V_164 ++ ;
if ( V_153 & V_160 )
V_155 -> V_165 ++ ;
F_51 ( & V_152 -> V_20 -> V_20 . V_166 ) ;
}
V_152 -> V_167 = V_153 & 0xf0 ;
V_157 = F_52 ( & V_152 -> V_20 -> V_20 ) ;
if ( V_157 && F_53 ( V_157 ) ) {
if ( V_153 & V_168 )
F_54 ( V_157 ) ;
}
F_55 ( V_157 ) ;
}
static void F_56 ( struct V_45 * V_152 , int V_169 ,
T_1 V_48 , T_1 V_6 )
{
struct V_154 * V_155 ;
T_1 V_170 = ( T_1 ) ( V_48 & ( T_1 ) ( V_171 | V_172 |
V_173 | V_174 ) ) ;
F_4 ( & V_152 -> V_20 -> V_2 , L_61 , V_12 , V_170 ) ;
V_152 -> V_175 = V_48 ;
if ( V_170 & V_174 )
V_170 &= ( T_1 ) ( V_171 | V_174 ) ;
if ( V_169 )
F_57 ( V_152 -> V_20 , & V_6 , 1 ) ;
V_155 = & V_152 -> V_20 -> V_155 ;
if ( V_170 & V_174 )
V_155 -> V_176 ++ ;
if ( V_170 & V_171 )
V_155 -> V_177 ++ ;
if ( V_170 & V_172 )
V_155 -> V_178 ++ ;
if ( V_170 & V_173 )
V_155 -> V_179 ++ ;
}
static void F_58 ( struct V_180 * V_180 )
{
struct V_34 * V_181 = V_180 -> V_182 ;
struct V_19 * V_20 ;
struct V_45 * V_152 ;
struct V_42 * V_2 ;
unsigned char * V_6 = V_180 -> V_183 ;
int V_27 = V_180 -> V_184 ;
int V_22 ;
int V_185 ;
int V_186 ;
T_1 V_48 ;
T_1 V_153 ;
int V_8 = V_180 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_187 :
case - V_188 :
case - V_189 :
F_4 ( & V_180 -> V_2 -> V_2 , L_62 ,
V_12 , V_8 ) ;
return;
default:
F_18 ( & V_180 -> V_2 -> V_2 , L_63
L_64 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_27 ) {
F_4 ( & V_180 -> V_2 -> V_2 , L_65 , V_12 ) ;
goto exit;
}
V_2 = & V_181 -> V_23 -> V_2 -> V_2 ;
F_11 ( V_2 , V_12 , V_27 , V_6 ) ;
if ( V_27 != 2 ) {
F_4 ( V_2 , L_66 , V_12 , V_27 ) ;
goto exit;
}
V_22 = F_59 ( V_6 [ 0 ] ) ;
V_185 = F_60 ( V_6 [ 0 ] ) ;
F_4 ( V_2 , L_67 , V_12 ,
V_22 , V_185 , V_6 [ 1 ] ) ;
V_20 = V_181 -> V_23 -> V_20 [ V_22 ] ;
V_152 = F_61 ( V_20 ) ;
if ( ! V_152 ) {
F_4 ( V_2 , L_68 , V_12 ) ;
return;
}
switch ( V_185 ) {
case V_190 :
V_48 = F_48 ( V_6 [ 1 ] ) ;
if ( V_48 & V_191 ) {
F_4 ( V_2 , L_69 ,
V_12 , V_22 , V_48 ) ;
V_152 -> V_192 = 1 ;
V_152 -> V_193 = V_48 ;
} else {
F_4 ( V_2 , L_70 ,
V_12 , V_22 , V_48 ) ;
F_56 ( V_152 , 0 , V_48 , 0 ) ;
}
break;
case V_194 :
V_153 = V_6 [ 1 ] ;
F_4 ( V_2 , L_71 ,
V_12 , V_22 , V_153 ) ;
F_50 ( V_152 , V_153 ) ;
break;
default:
F_18 ( & V_180 -> V_2 -> V_2 ,
L_72 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_186 = F_62 ( V_180 , V_195 ) ;
if ( V_186 )
F_18 ( & V_180 -> V_2 -> V_2 ,
L_73 ,
V_12 , V_186 ) ;
}
static void F_63 ( struct V_180 * V_180 )
{
struct V_45 * V_152 = V_180 -> V_182 ;
struct V_42 * V_2 = & V_152 -> V_20 -> V_2 ;
unsigned char * V_6 = V_180 -> V_183 ;
int V_186 = 0 ;
int V_22 ;
int V_8 = V_180 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_187 :
case - V_188 :
case - V_189 :
F_4 ( & V_180 -> V_2 -> V_2 , L_62 , V_12 , V_8 ) ;
return;
default:
F_18 ( & V_180 -> V_2 -> V_2 , L_74 , V_12 , V_8 ) ;
}
if ( V_8 == - V_196 )
goto exit;
if ( V_8 ) {
F_18 ( & V_180 -> V_2 -> V_2 , L_75 , V_12 ) ;
return;
}
V_22 = V_152 -> V_20 -> V_22 ;
if ( V_152 -> V_192 ) {
V_152 -> V_192 = 0 ;
F_4 ( V_2 , L_76 ,
V_12 , V_22 , V_152 -> V_193 , * V_6 ) ;
F_56 ( V_152 , 1 , V_152 -> V_193 , * V_6 ) ;
-- V_180 -> V_184 ;
++ V_6 ;
}
if ( V_180 -> V_184 ) {
F_11 ( V_2 , V_12 , V_180 -> V_184 , V_6 ) ;
if ( V_152 -> V_197 )
F_4 ( V_2 , L_77 ,
V_12 ) ;
else
F_57 ( V_152 -> V_20 , V_6 ,
V_180 -> V_184 ) ;
V_152 -> V_20 -> V_155 . V_198 += V_180 -> V_184 ;
}
exit:
F_64 ( & V_152 -> V_199 ) ;
if ( V_152 -> V_200 == V_201 )
V_186 = F_62 ( V_180 , V_195 ) ;
else if ( V_152 -> V_200 == V_202 )
V_152 -> V_200 = V_203 ;
F_65 ( & V_152 -> V_199 ) ;
if ( V_186 )
F_18 ( V_2 , L_73 , V_12 , V_186 ) ;
}
static void F_57 ( struct V_19 * V_20 , unsigned char * V_6 ,
int V_27 )
{
int V_204 ;
V_204 = F_66 ( & V_20 -> V_20 , V_6 , V_27 ) ;
if ( V_204 < V_27 )
F_18 ( & V_20 -> V_2 , L_78 ,
V_12 , V_27 - V_204 ) ;
F_67 ( & V_20 -> V_20 ) ;
}
static void F_68 ( struct V_180 * V_180 )
{
struct V_19 * V_20 = V_180 -> V_182 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_8 = V_180 -> V_8 ;
struct V_156 * V_157 ;
V_152 -> V_205 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_187 :
case - V_188 :
case - V_189 :
F_4 ( & V_180 -> V_2 -> V_2 , L_62 ,
V_12 , V_8 ) ;
return;
default:
F_69 ( V_20 , L_79
L_80 , V_12 , V_8 ) ;
}
V_157 = F_52 ( & V_20 -> V_20 ) ;
F_70 ( V_20 , V_157 ) ;
F_55 ( V_157 ) ;
}
static int F_71 ( struct V_156 * V_157 , struct V_19 * V_20 )
{
struct V_45 * V_152 = F_61 ( V_20 ) ;
struct V_34 * V_181 ;
struct V_1 * V_2 ;
struct V_180 * V_180 ;
int V_22 ;
int V_8 ;
T_4 V_206 ;
T_3 V_207 ;
if ( V_152 == NULL )
return - V_60 ;
V_22 = V_20 -> V_22 ;
V_2 = V_20 -> V_23 -> V_2 ;
V_8 = F_46 ( V_152 , V_149 , 0 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_81 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_157 )
F_72 ( V_157 , V_20 , & V_157 -> V_208 ) ;
V_207 = 2 ;
V_152 -> V_209 =
F_73 ( 20 , ( ( V_207 * 3 ) / 2 ) ) ;
V_206 = ( T_3 ) ( V_210 |
V_211 |
( V_207 << 2 ) ) ;
F_4 ( & V_20 -> V_2 , L_82 , V_12 ) ;
V_8 = F_7 ( V_2 , V_212 ,
( T_3 ) ( V_25 + V_22 ) , V_206 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 , L_83 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_213 ,
( T_3 ) ( V_25 + V_22 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 , L_84 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_20 , V_214 | V_215 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_85 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_216 , 0 ,
( T_2 ) ( V_25 + V_22 ) ,
& V_152 -> V_167 , 1 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 , L_86 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( & V_20 -> V_2 , L_87 , V_152 -> V_167 ) ;
V_152 -> V_217 = V_148 | V_146 ;
F_4 ( & V_20 -> V_2 , L_88 , V_152 -> V_217 ) ;
V_181 = V_152 -> V_181 ;
if ( F_74 ( & V_181 -> V_218 ) )
return - V_219 ;
if ( V_181 -> V_220 == 0 ) {
V_180 = V_181 -> V_23 -> V_20 [ 0 ] -> V_221 ;
if ( ! V_180 ) {
F_18 ( & V_20 -> V_2 ,
L_89 ,
V_12 ) ;
V_8 = - V_65 ;
goto V_222;
}
V_180 -> V_182 = V_181 ;
V_8 = F_62 ( V_180 , V_39 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_90 ,
V_12 , V_8 ) ;
goto V_222;
}
}
F_75 ( V_2 , V_20 -> V_223 -> V_224 ) ;
F_75 ( V_2 , V_20 -> V_225 -> V_224 ) ;
V_180 = V_20 -> V_225 ;
if ( ! V_180 ) {
F_18 ( & V_20 -> V_2 , L_91 ,
V_12 ) ;
V_8 = - V_65 ;
goto V_226;
}
V_152 -> V_200 = V_201 ;
V_180 -> V_182 = V_152 ;
V_8 = F_62 ( V_180 , V_39 ) ;
if ( V_8 ) {
F_18 ( & V_20 -> V_2 ,
L_92 ,
V_12 , V_8 ) ;
goto V_226;
}
++ V_181 -> V_220 ;
goto V_222;
V_226:
if ( V_152 -> V_181 -> V_220 == 0 )
F_76 ( V_20 -> V_23 -> V_20 [ 0 ] -> V_221 ) ;
V_222:
F_77 ( & V_181 -> V_218 ) ;
return V_8 ;
}
static void F_78 ( struct V_19 * V_20 )
{
struct V_34 * V_181 ;
struct V_45 * V_152 ;
struct V_107 * V_23 = V_20 -> V_23 ;
unsigned long V_227 ;
int V_22 ;
V_181 = F_79 ( V_20 -> V_23 ) ;
V_152 = F_61 ( V_20 ) ;
if ( V_181 == NULL || V_152 == NULL )
return;
V_152 -> V_197 = 1 ;
F_76 ( V_20 -> V_225 ) ;
F_76 ( V_20 -> V_223 ) ;
V_152 -> V_205 = 0 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
F_81 ( & V_20 -> V_228 ) ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
F_4 ( & V_20 -> V_2 , L_93 , V_12 ) ;
V_22 = V_20 -> V_22 ;
F_7 ( V_23 -> V_2 , V_229 ,
( T_1 ) ( V_25 + V_22 ) , 0 , NULL , 0 ) ;
F_83 ( & V_181 -> V_218 ) ;
-- V_152 -> V_181 -> V_220 ;
if ( V_152 -> V_181 -> V_220 <= 0 ) {
F_76 ( V_20 -> V_23 -> V_20 [ 0 ] -> V_221 ) ;
V_152 -> V_181 -> V_220 = 0 ;
}
F_77 ( & V_181 -> V_218 ) ;
V_152 -> V_197 = 0 ;
}
static int F_84 ( struct V_156 * V_157 , struct V_19 * V_20 ,
const unsigned char * V_6 , int V_230 )
{
struct V_45 * V_152 = F_61 ( V_20 ) ;
if ( V_230 == 0 ) {
F_4 ( & V_20 -> V_2 , L_94 , V_12 ) ;
return 0 ;
}
if ( V_152 == NULL )
return - V_60 ;
if ( V_152 -> V_197 == 1 )
return - V_60 ;
V_230 = F_85 ( & V_20 -> V_228 , V_6 , V_230 ,
& V_152 -> V_199 ) ;
F_70 ( V_20 , V_157 ) ;
return V_230 ;
}
static void F_70 ( struct V_19 * V_20 , struct V_156 * V_157 )
{
int V_230 , V_231 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
unsigned long V_227 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
if ( V_152 -> V_205 ) {
F_82 ( & V_152 -> V_199 , V_227 ) ;
return;
}
V_230 = F_86 ( & V_20 -> V_228 ,
V_20 -> V_223 -> V_183 ,
V_20 -> V_232 ) ;
if ( V_230 == 0 ) {
F_82 ( & V_152 -> V_199 , V_227 ) ;
return;
}
V_152 -> V_205 = 1 ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
F_11 ( & V_20 -> V_2 , V_12 , V_230 , V_20 -> V_223 -> V_183 ) ;
V_20 -> V_223 -> V_233 = V_230 ;
V_231 = F_62 ( V_20 -> V_223 , V_195 ) ;
if ( V_231 ) {
F_69 ( V_20 ,
L_95 ,
V_12 , V_231 ) ;
V_152 -> V_205 = 0 ;
} else
V_152 -> V_20 -> V_155 . V_234 += V_230 ;
if ( V_157 )
F_54 ( V_157 ) ;
}
static int F_87 ( struct V_156 * V_157 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_236 = 0 ;
unsigned long V_227 ;
if ( V_152 == NULL )
return 0 ;
if ( V_152 -> V_197 == 1 )
return 0 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
V_236 = F_88 ( & V_20 -> V_228 ) ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
F_4 ( & V_20 -> V_2 , L_96 , V_12 , V_236 ) ;
return V_236 ;
}
static int F_89 ( struct V_156 * V_157 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_237 = 0 ;
unsigned long V_227 ;
if ( V_152 == NULL )
return 0 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
V_237 = F_90 ( & V_20 -> V_228 ) ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
F_4 ( & V_20 -> V_2 , L_96 , V_12 , V_237 ) ;
return V_237 ;
}
static bool F_91 ( struct V_19 * V_20 )
{
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_238 ;
V_238 = F_19 ( V_152 ) ;
if ( V_238 > 0 )
return false ;
return true ;
}
static void F_92 ( struct V_156 * V_157 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_8 ;
if ( V_152 == NULL )
return;
if ( F_93 ( V_157 ) ) {
unsigned char V_239 = F_94 ( V_157 ) ;
V_8 = F_84 ( V_157 , V_20 , & V_239 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_20 -> V_2 , L_97 , V_12 , V_8 ) ;
}
}
if ( F_53 ( V_157 ) )
F_95 ( V_152 ) ;
}
static void F_96 ( struct V_156 * V_157 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_8 ;
if ( V_152 == NULL )
return;
if ( F_93 ( V_157 ) ) {
unsigned char V_240 = F_97 ( V_157 ) ;
V_8 = F_84 ( V_157 , V_20 , & V_240 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_20 -> V_2 , L_98 , V_12 , V_8 ) ;
}
}
if ( F_53 ( V_157 ) ) {
V_8 = F_98 ( V_152 ) ;
if ( V_8 )
F_18 ( & V_20 -> V_2 ,
L_99 ,
V_12 , V_8 ) ;
}
}
static void F_95 ( struct V_45 * V_152 )
{
unsigned long V_227 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
if ( V_152 -> V_200 == V_201 )
V_152 -> V_200 = V_202 ;
V_152 -> V_217 &= ~ V_148 ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
}
static int F_98 ( struct V_45 * V_152 )
{
struct V_180 * V_180 ;
int V_8 = 0 ;
unsigned long V_227 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
if ( V_152 -> V_200 == V_203 ) {
V_180 = V_152 -> V_20 -> V_225 ;
V_8 = F_62 ( V_180 , V_195 ) ;
}
V_152 -> V_200 = V_201 ;
V_152 -> V_217 |= V_148 ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
return V_8 ;
}
static void F_99 ( struct V_156 * V_157 ,
struct V_45 * V_152 , struct V_241 * V_242 )
{
struct V_42 * V_2 = & V_152 -> V_20 -> V_2 ;
struct V_243 * V_56 ;
int V_244 ;
unsigned V_245 ;
int V_8 ;
int V_22 = V_152 -> V_20 -> V_22 ;
V_56 = F_15 ( sizeof ( * V_56 ) , V_39 ) ;
if ( ! V_56 ) {
V_157 -> V_208 = * V_242 ;
return;
}
V_245 = V_157 -> V_208 . V_246 ;
V_56 -> V_247 = 0 ;
V_56 -> V_247 |= V_248 ;
V_56 -> V_247 |= V_249 ;
V_56 -> V_250 = ( T_1 ) ( V_152 -> V_250 ) ;
switch ( V_245 & V_251 ) {
case V_252 :
V_56 -> V_253 = V_254 ;
F_4 ( V_2 , L_100 , V_12 ) ;
break;
case V_255 :
V_56 -> V_253 = V_256 ;
F_4 ( V_2 , L_101 , V_12 ) ;
break;
case V_257 :
V_56 -> V_253 = V_258 ;
F_4 ( V_2 , L_102 , V_12 ) ;
break;
default:
case V_259 :
V_56 -> V_253 = V_260 ;
F_4 ( V_2 , L_103 , V_12 ) ;
break;
}
if ( V_245 & V_261 ) {
if ( V_245 & V_262 ) {
V_56 -> V_247 |= V_263 ;
V_56 -> V_264 = V_265 ;
F_4 ( V_2 , L_104 , V_12 ) ;
} else {
V_56 -> V_247 |= V_263 ;
V_56 -> V_264 = V_266 ;
F_4 ( V_2 , L_105 , V_12 ) ;
}
} else {
V_56 -> V_264 = V_267 ;
F_4 ( V_2 , L_106 , V_12 ) ;
}
if ( V_245 & V_268 ) {
V_56 -> V_269 = V_270 ;
F_4 ( V_2 , L_107 , V_12 ) ;
} else {
V_56 -> V_269 = V_271 ;
F_4 ( V_2 , L_108 , V_12 ) ;
}
if ( V_245 & V_272 ) {
V_56 -> V_247 |= V_273 ;
V_56 -> V_247 |= V_274 ;
F_4 ( V_2 , L_109 , V_12 ) ;
} else {
F_4 ( V_2 , L_110 , V_12 ) ;
F_98 ( V_152 ) ;
}
V_56 -> V_275 = F_97 ( V_157 ) ;
V_56 -> V_276 = F_94 ( V_157 ) ;
if ( F_93 ( V_157 ) ) {
V_56 -> V_247 |= V_277 ;
F_4 ( V_2 , L_111 ,
V_12 , V_56 -> V_275 , V_56 -> V_276 ) ;
} else
F_4 ( V_2 , L_112 , V_12 ) ;
if ( F_100 ( V_157 ) ) {
V_56 -> V_247 |= V_278 ;
F_4 ( V_2 , L_113 ,
V_12 , V_56 -> V_275 , V_56 -> V_276 ) ;
} else
F_4 ( V_2 , L_114 , V_12 ) ;
V_157 -> V_208 . V_246 &= ~ V_279 ;
V_244 = F_101 ( V_157 ) ;
if ( ! V_244 ) {
V_244 = 9600 ;
} else
F_102 ( V_157 , V_244 , V_244 ) ;
V_152 -> V_280 = V_244 ;
V_56 -> V_281 = ( T_2 ) ( ( 461550L + V_244 / 2 ) / V_244 ) ;
F_4 ( V_2 , L_115 , V_12 , V_244 , V_56 -> V_281 ) ;
F_4 ( V_2 , L_116 , ( int ) ( 461550L / V_56 -> V_281 ) ) ;
F_4 ( V_2 , L_117 , V_56 -> V_247 ) ;
F_4 ( V_2 , L_118 , V_56 -> V_253 ) ;
F_4 ( V_2 , L_119 , V_56 -> V_264 ) ;
F_4 ( V_2 , L_120 , V_56 -> V_269 ) ;
F_4 ( V_2 , L_121 , V_56 -> V_275 ) ;
F_4 ( V_2 , L_122 , V_56 -> V_276 ) ;
F_4 ( V_2 , L_123 , V_56 -> V_250 ) ;
F_103 ( & V_56 -> V_247 ) ;
F_103 ( & V_56 -> V_281 ) ;
V_8 = F_7 ( V_152 -> V_20 -> V_23 -> V_2 , V_282 ,
( T_1 ) ( V_25 + V_22 ) ,
0 , ( T_1 * ) V_56 , sizeof( * V_56 ) ) ;
if ( V_8 )
F_4 ( V_2 , L_124 ,
V_12 , V_8 ) ;
F_16 ( V_56 ) ;
}
static void F_72 ( struct V_156 * V_157 ,
struct V_19 * V_20 , struct V_241 * V_242 )
{
struct V_45 * V_152 = F_61 ( V_20 ) ;
unsigned int V_245 ;
V_245 = V_157 -> V_208 . V_246 ;
F_4 ( & V_20 -> V_2 , L_125 , V_12 ,
V_157 -> V_208 . V_246 , V_157 -> V_208 . V_283 ) ;
F_4 ( & V_20 -> V_2 , L_126 , V_12 ,
V_242 -> V_246 , V_242 -> V_283 ) ;
if ( V_152 == NULL )
return;
F_99 ( V_157 , V_152 , V_242 ) ;
}
static int F_104 ( struct V_156 * V_157 ,
unsigned int V_284 , unsigned int V_285 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
unsigned int V_144 ;
unsigned long V_227 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
V_144 = V_152 -> V_217 ;
if ( V_284 & V_286 )
V_144 |= V_148 ;
if ( V_284 & V_287 )
V_144 |= V_146 ;
if ( V_284 & V_288 )
V_144 |= V_150 ;
if ( V_285 & V_286 )
V_144 &= ~ V_148 ;
if ( V_285 & V_287 )
V_144 &= ~ V_146 ;
if ( V_285 & V_288 )
V_144 &= ~ V_150 ;
V_152 -> V_217 = V_144 ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
F_47 ( V_152 , V_144 ) ;
return 0 ;
}
static int F_105 ( struct V_156 * V_157 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
unsigned int V_231 = 0 ;
unsigned int V_153 ;
unsigned int V_144 ;
unsigned long V_227 ;
F_80 ( & V_152 -> V_199 , V_227 ) ;
V_153 = V_152 -> V_167 ;
V_144 = V_152 -> V_217 ;
V_231 = ( ( V_144 & V_146 ) ? V_287 : 0 )
| ( ( V_144 & V_148 ) ? V_286 : 0 )
| ( ( V_153 & V_168 ) ? V_289 : 0 )
| ( ( V_153 & V_290 ) ? V_291 : 0 )
| ( ( V_153 & V_292 ) ? V_293 : 0 )
| ( ( V_153 & V_294 ) ? V_295 : 0 ) ;
F_4 ( & V_20 -> V_2 , L_127 , V_12 , V_231 ) ;
F_82 ( & V_152 -> V_199 , V_227 ) ;
return V_231 ;
}
static int F_106 ( struct V_45 * V_152 ,
struct V_296 T_7 * V_297 )
{
struct V_296 V_298 ;
unsigned V_299 ;
V_299 = V_152 -> V_20 -> V_20 . V_300 ;
if ( V_299 != V_301 )
V_299 = F_107 ( V_299 ) / 10 ;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
V_298 . type = V_302 ;
V_298 . line = V_152 -> V_20 -> V_303 ;
V_298 . V_20 = V_152 -> V_20 -> V_22 ;
V_298 . V_304 = 0 ;
V_298 . V_227 = V_305 | V_306 ;
V_298 . V_307 = V_152 -> V_20 -> V_232 ;
V_298 . V_308 = 9600 ;
V_298 . V_309 = 5 * V_310 ;
V_298 . V_300 = V_299 ;
if ( F_108 ( V_297 , & V_298 , sizeof( * V_297 ) ) )
return - V_311 ;
return 0 ;
}
static int F_109 ( struct V_156 * V_157 ,
unsigned int V_312 , unsigned long V_313 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
switch ( V_312 ) {
case V_314 :
F_4 ( & V_20 -> V_2 , L_128 , V_12 ) ;
return F_106 ( V_152 ,
(struct V_296 T_7 * ) V_313 ) ;
}
return - V_315 ;
}
static void F_110 ( struct V_156 * V_157 , int V_316 )
{
struct V_19 * V_20 = V_157 -> V_235 ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
int V_8 ;
int V_317 = 0 ;
if ( V_316 == - 1 )
V_317 = 1 ;
V_8 = F_46 ( V_152 , V_318 , V_317 ) ;
if ( V_8 )
F_4 ( & V_20 -> V_2 , L_129 ,
V_12 , V_8 ) ;
}
static void F_111 ( struct V_34 * V_181 )
{
if ( ! V_181 -> V_319 )
return;
F_112 ( & V_181 -> V_320 ,
V_321 * V_310 ) ;
}
static void F_113 ( struct V_322 * V_323 )
{
struct V_34 * V_23 ;
struct V_67 * V_68 ;
V_23 = F_114 ( V_323 , struct V_34 ,
V_320 . V_323 ) ;
V_68 = F_15 ( sizeof( * V_68 ) , V_39 ) ;
if ( ! V_68 || ! F_23 ( V_23 , V_79 ,
V_68 ) ) {
F_18 ( & V_23 -> V_23 -> V_118 -> V_2 ,
L_130 , V_12 ) ;
}
F_16 ( V_68 ) ;
F_111 ( V_23 ) ;
}
static int F_115 ( struct V_107 * V_23 )
{
struct V_34 * V_181 ;
int V_8 ;
T_4 V_324 ;
if ( V_23 -> V_118 -> V_124 -> V_57 . V_125 > 1 ) {
if ( V_23 -> V_325 < V_23 -> V_326 ||
V_23 -> V_327 < V_23 -> V_326 )
return - V_60 ;
}
V_181 = F_116 ( sizeof( struct V_34 ) , V_39 ) ;
if ( ! V_181 )
return - V_40 ;
F_117 ( & V_181 -> V_218 ) ;
V_181 -> V_23 = V_23 ;
F_118 ( & V_181 -> V_320 , F_113 ) ;
F_119 ( V_23 , V_181 ) ;
V_8 = F_40 ( V_181 ) ;
if ( V_8 < 0 ) {
F_16 ( V_181 ) ;
return V_8 ;
}
if ( V_8 > 0 )
return 1 ;
V_324 = F_24 (
V_181 -> V_23 -> V_2 -> V_137 . V_328 ) ;
if ( V_181 -> V_121 > V_329 ) {
if ( V_324 == V_330 ||
V_324 == V_331 ) {
V_181 -> V_319 = true ;
}
}
F_111 ( V_181 ) ;
return 0 ;
}
static void F_120 ( struct V_107 * V_23 )
{
struct V_34 * V_181 = F_79 ( V_23 ) ;
F_121 ( & V_181 -> V_320 ) ;
}
static void F_122 ( struct V_107 * V_23 )
{
struct V_34 * V_181 = F_79 ( V_23 ) ;
F_121 ( & V_181 -> V_320 ) ;
F_16 ( V_181 ) ;
}
static int F_123 ( struct V_19 * V_20 )
{
struct V_45 * V_152 ;
int V_238 ;
V_152 = F_116 ( sizeof( * V_152 ) , V_39 ) ;
if ( ! V_152 )
return - V_40 ;
F_124 ( & V_152 -> V_199 ) ;
V_152 -> V_20 = V_20 ;
V_152 -> V_181 = F_79 ( V_20 -> V_23 ) ;
V_152 -> V_250 = V_332 ;
switch ( V_20 -> V_22 ) {
case 0 :
V_152 -> V_53 = V_333 ;
V_152 -> V_50 = V_334 ;
break;
case 1 :
V_152 -> V_53 = V_335 ;
V_152 -> V_50 = V_336 ;
break;
default:
F_18 ( & V_20 -> V_2 , L_131 ) ;
V_238 = - V_60 ;
goto V_337;
}
F_4 ( & V_20 -> V_2 ,
L_132 ,
V_12 , V_20 -> V_22 , V_152 -> V_53 ,
V_152 -> V_50 ) ;
F_125 ( V_20 , V_152 ) ;
V_238 = F_126 ( V_20 ) ;
if ( V_238 )
goto V_337;
V_20 -> V_20 . V_300 = F_127 ( V_300 * 10 ) ;
V_20 -> V_20 . V_338 = 1 ;
return 0 ;
V_337:
F_16 ( V_152 ) ;
return V_238 ;
}
static int F_128 ( struct V_19 * V_20 )
{
struct V_45 * V_152 ;
V_152 = F_61 ( V_20 ) ;
F_129 ( V_20 ) ;
F_16 ( V_152 ) ;
return 0 ;
}
static T_8 F_130 ( struct V_42 * V_2 ,
struct V_339 * V_340 , char * V_341 )
{
struct V_19 * V_20 = F_131 ( V_2 ) ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
return sprintf ( V_341 , L_64 , V_152 -> V_250 ) ;
}
static T_8 F_132 ( struct V_42 * V_2 ,
struct V_339 * V_340 , const char * V_342 , T_9 V_230 )
{
struct V_19 * V_20 = F_131 ( V_2 ) ;
struct V_45 * V_152 = F_61 ( V_20 ) ;
unsigned int V_343 = F_133 ( V_342 , NULL , 0 ) ;
F_4 ( V_2 , L_133 , V_12 , V_343 ) ;
if ( V_343 < 256 )
V_152 -> V_250 = V_343 ;
else
F_18 ( V_2 , L_134 , V_12 , V_343 ) ;
return V_230 ;
}
static int F_126 ( struct V_19 * V_20 )
{
return F_134 ( & V_20 -> V_2 , & V_344 ) ;
}
static int F_129 ( struct V_19 * V_20 )
{
F_135 ( & V_20 -> V_2 , & V_344 ) ;
return 0 ;
}
static int F_136 ( struct V_107 * V_23 , T_10 V_345 )
{
struct V_34 * V_181 = F_79 ( V_23 ) ;
F_121 ( & V_181 -> V_320 ) ;
return 0 ;
}
static int F_137 ( struct V_107 * V_23 )
{
struct V_34 * V_181 = F_79 ( V_23 ) ;
F_111 ( V_181 ) ;
return 0 ;
}
