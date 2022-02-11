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
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_3 * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_6 ( V_2 , 0 ) , V_3 ,
( V_9 | V_10 | V_14 ) ,
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
static int F_7 ( struct V_1 * V_2 , T_1 V_15 ,
T_1 V_16 , T_2 V_4 , T_3 * V_6 ,
int V_7 )
{
return F_5 ( V_2 , V_15 , V_4 , V_16 , V_6 , V_7 ) ;
}
static int F_8 ( struct V_17 * V_18 , T_2 V_19 )
{
int V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
F_4 ( & V_18 -> V_2 , L_2 , V_12 , V_20 , V_19 ) ;
return F_7 ( V_18 -> V_22 -> V_2 ,
V_24 ,
( T_1 ) ( V_25 + V_20 ) ,
V_19 ,
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
V_31 = F_10 ( V_26 ) ;
V_8 = F_1 ( V_2 , V_32 ,
( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
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
V_34 , V_29 ) ;
}
static int F_13 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_27 ; V_36 ++ ) {
V_8 = F_1 ( V_22 -> V_22 -> V_2 ,
V_32 , V_22 -> V_37 ,
( T_2 ) ( V_26 + V_36 ) , & V_29 [ V_36 ] , 0x01 ) ;
if ( V_8 ) {
F_4 ( & V_22 -> V_22 -> V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
}
F_4 ( & V_22 -> V_22 -> V_2 -> V_2 , L_5 ,
V_12 , V_26 , V_27 ) ;
F_11 ( & V_22 -> V_22 -> V_2 -> V_2 , V_12 , V_27 , V_29 ) ;
V_22 -> V_38 = 1 ;
return V_8 ;
}
static int F_14 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_36 ;
T_3 * V_39 ;
if ( ! V_22 -> V_38 ) {
V_39 = F_15 ( 1 , V_40 ) ;
if ( ! V_39 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 ,
L_6 , V_12 ) ;
return - V_41 ;
}
V_8 = F_13 ( V_22 , 0 , 1 , V_39 ) ;
F_17 ( V_39 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_36 = 0 ; V_36 < V_27 ; ++ V_36 ) {
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_42 , V_29 [ V_36 ] ,
( T_2 ) ( V_36 + V_26 ) , NULL , 0 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( & V_22 -> V_22 -> V_2 -> V_2 , L_7 , V_12 , V_26 , V_27 ) ;
F_11 ( & V_22 -> V_22 -> V_2 -> V_2 , V_12 , V_27 , V_29 ) ;
return V_8 ;
}
static int F_18 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 V_28 , T_1 * V_29 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_44 ;
T_4 V_31 ;
V_44 = V_45 -
( V_26 & ( V_45 - 1 ) ) ;
if ( V_44 > V_27 )
V_44 = V_27 ;
F_4 ( V_2 , L_8 ,
V_12 , V_26 , V_44 ) ;
F_11 ( V_2 , V_12 , V_44 , V_29 ) ;
V_31 = F_10 ( V_26 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_42 , ( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_44 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_9 , V_12 , V_8 ) ;
return V_8 ;
}
V_27 -= V_44 ;
V_26 += V_44 ;
V_29 += V_44 ;
while ( V_27 ) {
if ( V_27 > V_45 )
V_44 = V_45 ;
else
V_44 = V_27 ;
F_4 ( V_2 , L_10 ,
V_12 , V_26 , V_44 ) ;
F_11 ( V_2 , V_12 , V_44 , V_29 ) ;
V_31 = F_10 ( V_26 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 , V_42 ,
( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_44 ) ;
if ( V_8 ) {
F_16 ( V_2 , L_9 , V_12 , V_8 ) ;
return V_8 ;
}
V_27 -= V_44 ;
V_26 += V_44 ;
V_29 += V_44 ;
}
return V_8 ;
}
static int F_19 ( struct V_46 * V_18 )
{
int V_8 ;
struct V_47 * V_48 ;
T_1 * V_49 ;
int V_50 = 0 ;
V_48 = F_15 ( sizeof( * V_48 ) , V_40 ) ;
if ( ! V_48 ) {
F_16 ( & V_18 -> V_18 -> V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_49 = F_15 ( 1 , V_40 ) ;
if ( ! V_49 ) {
F_17 ( V_48 ) ;
return - V_41 ;
}
V_8 = F_12 ( V_18 -> V_18 -> V_22 -> V_2 , V_18 -> V_51 ,
sizeof( * V_48 ) , ( void * ) V_48 ) ;
if ( V_8 )
goto V_52;
F_4 ( & V_18 -> V_18 -> V_2 , L_11 , V_12 , V_48 -> V_53 ) ;
V_8 = F_12 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_18 -> V_54 + V_55 , 1 , V_49 ) ;
if ( V_8 )
goto V_52;
F_4 ( & V_18 -> V_18 -> V_2 , L_12 , V_12 , * V_49 ) ;
if ( ( V_48 -> V_53 & 0x80 ) != 0 )
V_50 += 64 ;
if ( ( * V_49 & V_56 ) == 0 )
V_50 += 1 ;
V_52:
F_4 ( & V_18 -> V_18 -> V_2 , L_13 , V_12 , V_50 ) ;
F_17 ( V_49 ) ;
F_17 ( V_48 ) ;
return V_50 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 , L_14 ,
V_12 , V_2 -> V_57 -> V_58 . V_59 ) ;
F_4 ( & V_2 -> V_2 , L_15 ,
V_12 , V_2 -> V_57 -> V_58 . V_60 * 2 ) ;
if ( V_2 -> V_57 -> V_58 . V_59 != 1 ) {
F_16 ( & V_2 -> V_2 , L_16 , V_12 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_21 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 ;
if ( V_22 -> V_62 . V_63 == V_64 ) {
V_8 = F_9 ( V_22 -> V_22 -> V_2 ,
V_26 ,
V_27 ,
V_22 -> V_37 ,
V_29 ) ;
} else {
V_8 = F_13 ( V_22 , V_26 , V_27 ,
V_29 ) ;
}
return V_8 ;
}
static int F_22 ( struct V_35 * V_22 , int V_26 ,
int V_27 , T_1 * V_29 )
{
if ( V_22 -> V_62 . V_63 == V_65 )
return F_14 ( V_22 , V_26 , V_27 ,
V_29 ) ;
if ( V_22 -> V_62 . V_63 == V_64 )
return F_18 ( V_22 , V_26 , V_27 ,
V_22 -> V_37 , V_29 ) ;
return - V_66 ;
}
static int F_23 ( struct V_35 * V_22 ,
int V_67 , struct V_68 * V_69 )
{
int V_26 ;
int V_8 ;
V_26 = 2 ;
do {
V_8 = F_21 ( V_22 ,
V_26 ,
sizeof( struct V_68 ) ,
( T_1 * ) V_69 ) ;
if ( V_8 )
return 0 ;
if ( V_69 -> Type == V_67 )
return V_26 ;
V_26 = V_26 + sizeof( struct V_68 )
+ V_69 -> V_70 ;
} while ( ( V_26 < V_71 ) && V_69 -> Type );
return 0 ;
}
static int F_24 ( struct V_68 * V_69 , T_1 * V_29 )
{
T_2 V_36 ;
T_1 V_72 = 0 ;
for ( V_36 = 0 ; V_36 < V_69 -> V_70 ; V_36 ++ )
V_72 = ( T_1 ) ( V_72 + V_29 [ V_36 ] ) ;
if ( V_72 != V_69 -> V_73 ) {
F_25 ( L_17 , V_12 , V_69 -> V_73 , V_72 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_26 ( struct V_35 * V_22 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_68 * V_69 ;
int V_26 = 2 ;
T_1 * V_29 ;
T_2 V_74 ;
V_69 = F_15 ( sizeof( * V_69 ) , V_40 ) ;
if ( ! V_69 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_29 = F_15 ( V_71 , V_40 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_18 ,
V_12 ) ;
F_17 ( V_69 ) ;
return - V_41 ;
}
V_8 = F_21 ( V_22 , 0 , 1 , V_29 ) ;
if ( V_8 )
goto V_75;
if ( * V_29 != V_76 && * V_29 != V_77 ) {
F_16 ( V_2 , L_19 , V_12 ) ;
V_8 = - V_61 ;
goto V_75;
}
do {
V_8 = F_21 ( V_22 ,
V_26 ,
sizeof( struct V_68 ) ,
( T_1 * ) V_69 ) ;
if ( V_8 )
break;
if ( ( V_26 + sizeof( struct V_68 ) +
V_69 -> V_70 ) > V_71 ) {
V_8 = - V_61 ;
F_4 ( V_2 , L_20 , V_12 ) ;
break;
}
F_4 ( V_2 , L_21 , V_12 , V_69 -> Type ) ;
V_74 = V_69 -> Type & 0x0f ;
if ( V_74 != V_78
&& V_74 != V_79 ) {
V_8 = F_21 ( V_22 , V_26 +
sizeof( struct V_68 ) ,
V_69 -> V_70 , V_29 ) ;
if ( V_8 )
break;
V_8 = F_24 ( V_69 , V_29 ) ;
if ( V_8 )
break;
}
V_26 = V_26 + sizeof( struct V_68 ) +
V_69 -> V_70 ;
} while ( ( V_69 -> Type != V_80 ) &&
( V_26 < V_71 ) );
if ( ( V_69 -> Type != V_80 ) ||
( V_26 > V_71 ) )
V_8 = - V_61 ;
V_75:
F_17 ( V_29 ) ;
F_17 ( V_69 ) ;
return V_8 ;
}
static int F_27 ( struct V_35 * V_22 , T_1 * V_29 )
{
int V_8 ;
int V_26 ;
struct V_68 * V_69 ;
struct V_81 * V_58 ;
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
V_69 = F_15 ( sizeof( * V_69 ) , V_40 ) ;
if ( ! V_69 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_26 = F_23 ( V_22 , V_80 ,
V_69 ) ;
if ( ! V_26 ) {
F_4 ( V_2 , L_22 , V_12 ) ;
V_8 = - V_61 ;
goto exit;
}
V_8 = F_21 ( V_22 , V_26 + sizeof( struct V_68 ) ,
V_69 -> V_70 , V_29 ) ;
if ( V_8 )
goto exit;
V_8 = F_24 ( V_69 , V_29 ) ;
V_58 = (struct V_81 * ) V_29 ;
F_4 ( V_2 , L_23 , V_12 , V_58 -> V_82 ) ;
F_4 ( V_2 , L_24 , V_12 , V_58 -> V_83 ) ;
F_4 ( V_2 , L_25 , V_12 , V_58 -> V_84 ) ;
F_4 ( V_2 , L_26 , V_12 , V_58 -> V_85 ) ;
F_4 ( V_2 , L_27 , V_12 , V_58 -> V_86 ) ;
F_4 ( V_2 , L_28 , V_12 , V_58 -> V_87 ) ;
exit:
F_17 ( V_69 ) ;
return V_8 ;
}
static int F_28 ( T_1 * V_88 , struct V_43 * V_2 )
{
T_1 * V_29 ;
int V_89 ;
int V_36 ;
int V_90 ;
T_1 V_72 = 0 ;
struct V_68 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
const struct V_96 * V_97 ;
const char * V_98 = L_29 ;
V_89 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_94 ) ) ;
V_29 = F_15 ( V_89 , V_40 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
memset ( V_29 , 0xff , V_89 ) ;
V_90 = F_29 ( & V_97 , V_98 , V_2 ) ;
if ( V_90 ) {
F_16 ( V_2 , L_30 ,
V_98 , V_90 ) ;
F_17 ( V_29 ) ;
return V_90 ;
}
V_99 = V_97 -> V_6 [ 0 ] ;
V_100 = V_97 -> V_6 [ 1 ] ;
V_101 = V_97 -> V_6 [ 2 ] | ( V_97 -> V_6 [ 3 ] << 8 ) ;
V_95 = (struct V_94 * ) V_29 ;
V_95 -> V_102 = V_99 ;
V_95 -> V_103 = V_100 ;
V_93 = (struct V_92 * ) & V_97 -> V_6 [ 4 ] ;
memcpy ( V_29 + sizeof( struct V_94 ) ,
& V_97 -> V_6 [ 4 + sizeof( struct V_92 ) ] ,
F_30 ( V_93 -> V_104 ) ) ;
F_31 ( V_97 ) ;
for ( V_36 = 0 ; V_36 < V_89 ; V_36 ++ ) {
V_72 = ( T_1 ) ( V_72 + V_29 [ V_36 ] ) ;
}
F_17 ( V_29 ) ;
V_91 = (struct V_68 * ) V_88 ;
V_95 = (struct V_94 * ) V_91 -> V_105 ;
V_91 -> Type = V_106 ;
V_91 -> V_70 = ( T_2 ) V_89 ;
V_91 -> V_73 = V_72 ;
V_95 -> V_102 = V_99 ;
V_95 -> V_103 = V_100 ;
return 0 ;
}
static int F_32 ( struct V_35 * V_22 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 ;
T_3 * V_6 ;
V_6 = F_15 ( 1 , V_40 ) ;
if ( ! V_6 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_107 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_31 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_32 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_76 || * V_6 == V_77 ) ) {
F_4 ( V_2 , L_33 , V_12 ) ;
V_22 -> V_37 = V_107 ;
goto V_75;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_108 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_34 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_32 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_76 || * V_6 == V_77 ) ) {
F_4 ( V_2 , L_35 , V_12 ) ;
V_22 -> V_37 = V_108 ;
goto V_75;
}
F_4 ( V_2 , L_36 , V_12 ) ;
V_22 -> V_37 = V_107 ;
V_8 = - V_61 ;
V_75:
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_33 ( struct V_109 * V_22 , void * V_29 ,
int V_27 , int * V_110 )
{
int V_8 ;
V_8 = F_34 ( V_22 -> V_2 ,
F_35 ( V_22 -> V_2 ,
V_22 -> V_18 [ 0 ] -> V_111 ) ,
V_29 , V_27 , V_110 , 1000 ) ;
return V_8 ;
}
static int F_36 ( struct V_35 * V_22 , T_1 * V_112 ,
int V_113 )
{
int V_8 = 0 ;
int V_114 ;
int V_115 ;
int V_116 ;
for ( V_114 = 0 ; V_114 < V_113 ; ) {
V_115 = V_113 - V_114 ;
if ( V_115 > V_117 )
V_115 = V_117 ;
V_8 = F_33 ( V_22 -> V_22 , & V_112 [ V_114 ] ,
V_115 , & V_116 ) ;
if ( V_8 )
break;
V_114 += V_116 ;
}
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_38 ( struct V_81 * V_58 )
{
return F_39 ( V_58 -> V_84 ) ;
}
static int F_40 ( struct V_35 * V_22 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_26 ;
struct V_81 * V_118 ;
struct V_119 * V_120 ;
int V_121 ;
int V_122 ;
V_22 -> V_62 . V_123 = V_124 ;
V_22 -> V_37 = V_107 ;
V_8 = F_20 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_120 = & V_22 -> V_22 -> V_120 -> V_125 -> V_58 ;
if ( ! V_120 ) {
F_16 ( V_2 , L_37 , V_12 ) ;
return - V_61 ;
}
if ( V_120 -> V_126 > 1 )
V_22 -> V_62 . V_63 = V_64 ;
else
V_22 -> V_62 . V_63 = V_127 ;
if ( V_22 -> V_62 . V_63 == V_64 ) {
struct V_68 * V_69 ;
F_4 ( V_2 , L_38 , V_12 ) ;
V_8 = F_26 ( V_22 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_39 , V_12 ) ;
return V_8 ;
}
V_118 = F_15 ( sizeof( * V_118 ) , V_40 ) ;
if ( ! V_118 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
return - V_41 ;
}
V_8 = F_27 ( V_22 , ( T_1 * ) V_118 ) ;
if ( V_8 ) {
F_17 ( V_118 ) ;
return V_8 ;
}
if ( ! V_128 && F_38 ( V_118 ) < 2 ) {
F_4 ( V_2 , L_41 ,
V_12 , F_38 ( V_118 ) ) ;
F_17 ( V_118 ) ;
return - V_66 ;
}
V_69 = F_15 ( sizeof( * V_69 ) , V_40 ) ;
if ( ! V_69 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_118 ) ;
return - V_41 ;
}
V_26 = F_23 ( V_22 ,
V_78 , V_69 ) ;
if ( V_26 != 0 ) {
struct V_94 * V_129 ;
T_3 * V_130 ;
F_4 ( V_2 , L_42 , V_12 ) ;
V_129 = F_15 ( sizeof( * V_129 ) ,
V_40 ) ;
if ( ! V_129 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_41 ;
}
V_8 = F_21 ( V_22 , V_26 +
sizeof( struct V_68 ) ,
sizeof( struct V_94 ) ,
( T_1 * ) V_129 ) ;
if ( V_8 ) {
F_17 ( V_129 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return V_8 ;
}
V_121 = ( V_129 -> V_102 << 8 ) +
( V_129 -> V_103 ) ;
V_122 = ( V_99 << 8 ) +
( V_100 ) ;
F_4 ( V_2 , L_43 ,
V_12 , V_129 -> V_102 ,
V_129 -> V_103 ,
V_99 ,
V_100 ) ;
if ( V_121 < V_122 ) {
F_4 ( V_2 , L_44 ,
V_12 ,
V_129 -> V_102 ,
V_129 -> V_103 ,
V_99 ,
V_100 ) ;
V_130 = F_15 ( 1 , V_40 ) ;
if ( ! V_130 ) {
F_16 ( V_2 , L_40 ,
V_12 ) ;
F_17 ( V_129 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_41 ;
}
* V_130 = V_106 ;
V_8 = F_22 ( V_22 , V_26 ,
sizeof( * V_130 ) , V_130 ) ;
if ( V_8 ) {
F_17 ( V_130 ) ;
F_17 ( V_129 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return V_8 ;
}
V_8 = F_21 ( V_22 ,
V_26 ,
sizeof( * V_130 ) ,
V_130 ) ;
if ( V_8 ) {
F_17 ( V_130 ) ;
F_17 ( V_129 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return V_8 ;
}
if ( * V_130 != V_106 ) {
F_16 ( V_2 , L_45 , V_12 ) ;
F_17 ( V_130 ) ;
F_17 ( V_129 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_61 ;
}
F_4 ( V_2 , L_46 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_131 ,
0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_47 , V_12 , V_8 ) ;
F_17 ( V_130 ) ;
F_17 ( V_129 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_61 ;
}
F_17 ( V_129 ) ;
}
else if ( ( V_26 = F_23 ( V_22 , V_106 , V_69 ) ) != 0 ) {
#define F_41 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_88 ;
T_1 * V_132 ;
V_88 = F_15 ( F_41 , V_40 ) ;
if ( ! V_88 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_41 ;
}
V_132 = F_15 ( F_41 , V_40 ) ;
if ( ! V_132 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_88 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_41 ;
}
F_4 ( V_2 , L_48 , V_12 ) ;
V_8 = F_28 ( V_88 , V_2 ) ;
if ( V_8 ) {
F_17 ( V_132 ) ;
F_17 ( V_88 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_66 ;
}
V_8 = F_22 ( V_22 ,
V_26 ,
F_41 ,
V_88 ) ;
if ( V_8 ) {
F_17 ( V_132 ) ;
F_17 ( V_88 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_66 ;
}
V_8 = F_21 ( V_22 , V_26 ,
F_41 , V_132 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_49 , V_12 ) ;
F_17 ( V_132 ) ;
F_17 ( V_88 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return V_8 ;
}
if ( memcmp ( V_132 , V_88 , F_41 ) ) {
F_4 ( V_2 , L_50 , V_12 ) ;
F_17 ( V_132 ) ;
F_17 ( V_88 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return - V_66 ;
}
F_17 ( V_132 ) ;
F_17 ( V_88 ) ;
F_4 ( V_2 , L_51 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_133 , 0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_52 , V_12 , V_8 ) ;
if ( V_8 ) {
F_16 ( V_2 ,
L_53 ,
V_12 ) ;
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return V_8 ;
}
}
F_17 ( V_69 ) ;
F_17 ( V_118 ) ;
return 0 ;
}
F_4 ( V_2 , L_54 , V_12 ) ;
V_8 = F_37 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_30 ( V_22 -> V_22 -> V_2 -> V_134 . V_135 )
!= V_136 ) {
F_4 ( V_2 , L_55 , V_12 ,
F_30 ( V_22 -> V_22 -> V_2 -> V_134 . V_135 ) ) ;
V_22 -> V_37 = V_107 ;
goto V_137;
}
if ( F_32 ( V_22 ) )
goto V_137;
if ( ! F_26 ( V_22 ) ) {
struct V_92 * V_88 ;
int V_36 ;
T_1 V_72 = 0 ;
T_1 * V_29 ;
int V_89 ;
int V_90 ;
const struct V_96 * V_97 ;
const char * V_98 = L_29 ;
V_118 = F_15 ( sizeof( * V_118 ) , V_40 ) ;
if ( ! V_118 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
return - V_41 ;
}
V_8 = F_27 ( V_22 , ( T_1 * ) V_118 ) ;
if ( V_8 ) {
F_17 ( V_118 ) ;
goto V_137;
}
if ( ! V_128 && F_38 ( V_118 ) < 2 ) {
F_4 ( V_2 , L_41 ,
V_12 , F_38 ( V_118 ) ) ;
F_17 ( V_118 ) ;
goto V_137;
}
F_17 ( V_118 ) ;
V_89 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_92 ) ) ;
V_29 = F_15 ( V_89 , V_40 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
memset ( V_29 , 0xff , V_89 ) ;
V_90 = F_29 ( & V_97 , V_98 , V_2 ) ;
if ( V_90 ) {
F_16 ( V_2 , L_30 ,
V_98 , V_90 ) ;
F_17 ( V_29 ) ;
return V_90 ;
}
memcpy ( V_29 , & V_97 -> V_6 [ 4 ] , V_97 -> V_7 - 4 ) ;
F_31 ( V_97 ) ;
for ( V_36 = sizeof( struct V_92 ) ;
V_36 < V_89 ; V_36 ++ ) {
V_72 = ( T_1 ) ( V_72 + V_29 [ V_36 ] ) ;
}
V_88 = (struct V_92 * ) V_29 ;
V_88 -> V_104 = F_42 ( ( T_2 ) ( V_89 -
sizeof( struct V_92 ) ) ) ;
V_88 -> V_73 = V_72 ;
F_4 ( V_2 , L_56 , V_12 ) ;
V_8 = F_36 ( V_22 , V_29 , V_89 ) ;
F_17 ( V_29 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_57 , V_12 ) ;
return V_8 ;
}
V_22 -> V_62 . V_63 = V_138 ;
F_4 ( V_2 , L_58 , V_12 ) ;
return - V_61 ;
}
V_137:
F_4 ( V_2 , L_59 , V_12 ) ;
V_22 -> V_62 . V_63 = V_65 ;
return 0 ;
}
static int F_43 ( struct V_46 * V_18 , int V_139 , int V_140 )
{
int V_20 = V_18 -> V_18 -> V_21 - V_18 -> V_18 -> V_22 -> V_23 ;
V_140 = ! ! V_140 ;
return F_7 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_139 , ( T_1 ) ( V_25 + V_20 ) ,
V_140 , NULL , 0 ) ;
}
static int F_44 ( struct V_46 * V_18 , T_1 V_141 )
{
int V_8 = 0 ;
F_4 ( & V_18 -> V_18 -> V_2 , L_60 , V_12 , V_141 ) ;
V_8 = F_43 ( V_18 , V_142 , V_141 & V_143 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_43 ( V_18 , V_144 , V_141 & V_145 ) ;
if ( V_8 )
return V_8 ;
return F_43 ( V_18 , V_146 , V_141 & V_147 ) ;
}
static T_1 F_45 ( T_1 V_148 )
{
T_1 V_49 = 0 ;
#define F_46 ( T_5 , T_6 ) \
if (ti_lsr & flagUmp) \
lsr |= flagUart;
F_46 (UMP_UART_LSR_OV_MASK, LSR_OVER_ERR)
F_46 (UMP_UART_LSR_PE_MASK, LSR_PAR_ERR)
F_46 (UMP_UART_LSR_FE_MASK, LSR_FRM_ERR)
F_46 (UMP_UART_LSR_BR_MASK, LSR_BREAK)
F_46 (UMP_UART_LSR_RX_MASK, LSR_RX_AVAIL)
F_46 (UMP_UART_LSR_TX_MASK, LSR_TX_EMPTY)
#undef F_46
return V_49 ;
}
static void F_47 ( struct V_46 * V_149 , T_1 V_150 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 ;
F_4 ( & V_149 -> V_18 -> V_2 , L_61 , V_12 , V_150 ) ;
if ( V_150 & ( V_155 | V_156 |
V_157 | V_158 ) ) {
V_152 = & V_149 -> V_152 ;
if ( V_150 & V_155 )
V_152 -> V_159 ++ ;
if ( V_150 & V_156 )
V_152 -> V_160 ++ ;
if ( V_150 & V_158 )
V_152 -> V_161 ++ ;
if ( V_150 & V_157 )
V_152 -> V_162 ++ ;
F_48 ( & V_149 -> V_18 -> V_163 ) ;
}
V_149 -> V_164 = V_150 & 0xf0 ;
V_154 = F_49 ( & V_149 -> V_18 -> V_18 ) ;
if ( V_154 && F_50 ( V_154 ) ) {
if ( V_150 & V_165 ) {
V_154 -> V_166 = 0 ;
F_51 ( V_154 ) ;
} else {
V_154 -> V_166 = 1 ;
}
}
F_52 ( V_154 ) ;
}
static void F_53 ( struct V_46 * V_149 , int V_167 ,
T_1 V_49 , T_1 V_6 )
{
struct V_151 * V_152 ;
T_1 V_168 = ( T_1 ) ( V_49 & ( T_1 ) ( V_169 | V_170 |
V_171 | V_172 ) ) ;
F_4 ( & V_149 -> V_18 -> V_2 , L_61 , V_12 , V_168 ) ;
V_149 -> V_173 = V_49 ;
if ( V_168 & V_172 )
V_168 &= ( T_1 ) ( V_169 | V_172 ) ;
if ( V_167 )
F_54 ( V_149 -> V_18 , & V_6 , 1 ) ;
V_152 = & V_149 -> V_152 ;
if ( V_168 & V_172 )
V_152 -> V_174 ++ ;
if ( V_168 & V_169 )
V_152 -> V_175 ++ ;
if ( V_168 & V_170 )
V_152 -> V_176 ++ ;
if ( V_168 & V_171 )
V_152 -> V_177 ++ ;
}
static void F_55 ( struct V_178 * V_178 )
{
struct V_35 * V_179 = V_178 -> V_180 ;
struct V_17 * V_18 ;
struct V_46 * V_149 ;
struct V_43 * V_2 ;
unsigned char * V_6 = V_178 -> V_181 ;
int V_27 = V_178 -> V_182 ;
int V_20 ;
int V_183 ;
int V_184 ;
T_1 V_49 ;
T_1 V_150 ;
int V_8 = V_178 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_185 :
case - V_186 :
case - V_187 :
F_4 ( & V_178 -> V_2 -> V_2 , L_62 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_178 -> V_2 -> V_2 , L_63
L_64 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_27 ) {
F_4 ( & V_178 -> V_2 -> V_2 , L_65 , V_12 ) ;
goto exit;
}
V_2 = & V_179 -> V_22 -> V_2 -> V_2 ;
F_11 ( V_2 , V_12 , V_27 , V_6 ) ;
if ( V_27 != 2 ) {
F_4 ( V_2 , L_66 , V_12 , V_27 ) ;
goto exit;
}
V_20 = F_56 ( V_6 [ 0 ] ) ;
V_183 = F_57 ( V_6 [ 0 ] ) ;
F_4 ( V_2 , L_67 , V_12 ,
V_20 , V_183 , V_6 [ 1 ] ) ;
V_18 = V_179 -> V_22 -> V_18 [ V_20 ] ;
V_149 = F_58 ( V_18 ) ;
if ( ! V_149 ) {
F_4 ( V_2 , L_68 , V_12 ) ;
return;
}
switch ( V_183 ) {
case V_188 :
V_49 = F_45 ( V_6 [ 1 ] ) ;
if ( V_49 & V_189 ) {
F_4 ( V_2 , L_69 ,
V_12 , V_20 , V_49 ) ;
V_149 -> V_190 = 1 ;
V_149 -> V_191 = V_49 ;
} else {
F_4 ( V_2 , L_70 ,
V_12 , V_20 , V_49 ) ;
F_53 ( V_149 , 0 , V_49 , 0 ) ;
}
break;
case V_192 :
V_150 = V_6 [ 1 ] ;
F_4 ( V_2 , L_71 ,
V_12 , V_20 , V_150 ) ;
F_47 ( V_149 , V_150 ) ;
break;
default:
F_16 ( & V_178 -> V_2 -> V_2 ,
L_72 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_184 = F_59 ( V_178 , V_193 ) ;
if ( V_184 )
F_16 ( & V_178 -> V_2 -> V_2 ,
L_73 ,
V_12 , V_184 ) ;
}
static void F_60 ( struct V_178 * V_178 )
{
struct V_46 * V_149 = V_178 -> V_180 ;
struct V_43 * V_2 = & V_149 -> V_18 -> V_2 ;
unsigned char * V_6 = V_178 -> V_181 ;
int V_184 = 0 ;
int V_20 ;
int V_8 = V_178 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_185 :
case - V_186 :
case - V_187 :
F_4 ( & V_178 -> V_2 -> V_2 , L_62 , V_12 , V_8 ) ;
return;
default:
F_16 ( & V_178 -> V_2 -> V_2 , L_74 , V_12 , V_8 ) ;
}
if ( V_8 == - V_194 )
goto exit;
if ( V_8 ) {
F_16 ( & V_178 -> V_2 -> V_2 , L_75 , V_12 ) ;
return;
}
V_20 = V_149 -> V_18 -> V_21 - V_149 -> V_18 -> V_22 -> V_23 ;
if ( V_149 -> V_190 ) {
V_149 -> V_190 = 0 ;
F_4 ( V_2 , L_76 ,
V_12 , V_20 , V_149 -> V_191 , * V_6 ) ;
F_53 ( V_149 , 1 , V_149 -> V_191 , * V_6 ) ;
-- V_178 -> V_182 ;
++ V_6 ;
}
if ( V_178 -> V_182 ) {
F_11 ( V_2 , V_12 , V_178 -> V_182 , V_6 ) ;
if ( V_149 -> V_195 )
F_4 ( V_2 , L_77 ,
V_12 ) ;
else
F_54 ( V_149 -> V_18 , V_6 ,
V_178 -> V_182 ) ;
V_149 -> V_152 . V_196 += V_178 -> V_182 ;
}
exit:
F_61 ( & V_149 -> V_197 ) ;
if ( V_149 -> V_198 == V_199 )
V_184 = F_59 ( V_178 , V_193 ) ;
else if ( V_149 -> V_198 == V_200 )
V_149 -> V_198 = V_201 ;
F_62 ( & V_149 -> V_197 ) ;
if ( V_184 )
F_16 ( V_2 , L_73 , V_12 , V_184 ) ;
}
static void F_54 ( struct V_17 * V_18 , unsigned char * V_6 ,
int V_27 )
{
int V_202 ;
V_202 = F_63 ( & V_18 -> V_18 , V_6 , V_27 ) ;
if ( V_202 < V_27 )
F_16 ( & V_18 -> V_2 , L_78 ,
V_12 , V_27 - V_202 ) ;
F_64 ( & V_18 -> V_18 ) ;
}
static void F_65 ( struct V_178 * V_178 )
{
struct V_17 * V_18 = V_178 -> V_180 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
int V_8 = V_178 -> V_8 ;
struct V_153 * V_154 ;
V_149 -> V_203 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_185 :
case - V_186 :
case - V_187 :
F_4 ( & V_178 -> V_2 -> V_2 , L_62 ,
V_12 , V_8 ) ;
return;
default:
F_66 ( V_18 , L_79
L_80 , V_12 , V_8 ) ;
}
V_154 = F_49 ( & V_18 -> V_18 ) ;
F_67 ( V_154 ) ;
F_52 ( V_154 ) ;
}
static int F_68 ( struct V_153 * V_154 , struct V_17 * V_18 )
{
struct V_46 * V_149 = F_58 ( V_18 ) ;
struct V_35 * V_179 ;
struct V_1 * V_2 ;
struct V_178 * V_178 ;
int V_20 ;
int V_8 ;
T_7 V_204 ;
T_3 V_205 ;
if ( V_149 == NULL )
return - V_61 ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
switch ( V_20 ) {
case 0 :
V_149 -> V_54 = V_206 ;
V_149 -> V_51 = V_207 ;
break;
case 1 :
V_149 -> V_54 = V_208 ;
V_149 -> V_51 = V_209 ;
break;
default:
F_16 ( & V_18 -> V_2 , L_81 ) ;
return - V_61 ;
}
F_4 ( & V_18 -> V_2 , L_82 ,
V_12 , V_20 , V_149 -> V_54 , V_149 -> V_51 ) ;
V_2 = V_18 -> V_22 -> V_2 ;
memset ( & ( V_149 -> V_152 ) , 0x00 , sizeof( V_149 -> V_152 ) ) ;
V_8 = F_43 ( V_149 , V_146 , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_83 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_154 )
F_69 ( V_154 , V_18 , & V_154 -> V_210 ) ;
V_205 = 2 ;
V_149 -> V_211 =
F_70 ( 20 , ( ( V_205 * 3 ) / 2 ) ) ;
V_204 = ( T_3 ) ( V_212 |
V_213 |
( V_205 << 2 ) ) ;
F_4 ( & V_18 -> V_2 , L_84 , V_12 ) ;
V_8 = F_7 ( V_2 , V_214 ,
( T_3 ) ( V_25 + V_20 ) , V_204 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_85 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_215 ,
( T_3 ) ( V_25 + V_20 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_86 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_18 , V_216 | V_217 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_87 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_218 , 0 ,
( T_2 ) ( V_25 + V_20 ) ,
& V_149 -> V_164 , 1 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_88 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( & V_18 -> V_2 , L_89 , V_149 -> V_164 ) ;
V_149 -> V_219 = V_145 | V_143 ;
F_4 ( & V_18 -> V_2 , L_90 , V_149 -> V_219 ) ;
V_179 = V_149 -> V_179 ;
if ( F_71 ( & V_179 -> V_220 ) )
return - V_221 ;
if ( V_179 -> V_222 == 0 ) {
V_178 = V_179 -> V_22 -> V_18 [ 0 ] -> V_223 ;
if ( ! V_178 ) {
F_16 ( & V_18 -> V_2 ,
L_91 ,
V_12 ) ;
V_8 = - V_66 ;
goto V_224;
}
V_178 -> V_180 = V_179 ;
V_8 = F_59 ( V_178 , V_40 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_92 ,
V_12 , V_8 ) ;
goto V_224;
}
}
F_72 ( V_2 , V_18 -> V_225 -> V_226 ) ;
F_72 ( V_2 , V_18 -> V_227 -> V_226 ) ;
V_178 = V_18 -> V_227 ;
if ( ! V_178 ) {
F_16 ( & V_18 -> V_2 , L_93 ,
V_12 ) ;
V_8 = - V_66 ;
goto V_228;
}
V_149 -> V_198 = V_199 ;
V_178 -> V_180 = V_149 ;
V_8 = F_59 ( V_178 , V_40 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_94 ,
V_12 , V_8 ) ;
goto V_228;
}
++ V_179 -> V_222 ;
V_18 -> V_18 . V_229 = 1 ;
goto V_224;
V_228:
if ( V_149 -> V_179 -> V_222 == 0 )
F_73 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_223 ) ;
V_224:
F_74 ( & V_179 -> V_220 ) ;
return V_8 ;
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_35 * V_179 ;
struct V_46 * V_149 ;
struct V_109 * V_22 = V_18 -> V_22 ;
unsigned long V_230 ;
int V_20 ;
V_179 = F_76 ( V_18 -> V_22 ) ;
V_149 = F_58 ( V_18 ) ;
if ( V_179 == NULL || V_149 == NULL )
return;
V_149 -> V_195 = 1 ;
F_73 ( V_18 -> V_227 ) ;
F_73 ( V_18 -> V_225 ) ;
V_149 -> V_203 = 0 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
F_78 ( & V_149 -> V_231 ) ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
F_4 ( & V_18 -> V_2 , L_95 , V_12 ) ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
F_80 ( & V_22 -> V_232 ) ;
if ( ! V_22 -> V_233 ) {
F_7 ( V_22 -> V_2 ,
V_234 ,
( T_1 ) ( V_25 + V_20 ) ,
0 ,
NULL ,
0 ) ;
}
F_74 ( & V_22 -> V_232 ) ;
F_80 ( & V_179 -> V_220 ) ;
-- V_149 -> V_179 -> V_222 ;
if ( V_149 -> V_179 -> V_222 <= 0 ) {
F_73 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_223 ) ;
V_149 -> V_179 -> V_222 = 0 ;
}
F_74 ( & V_179 -> V_220 ) ;
V_149 -> V_195 = 0 ;
}
static int F_81 ( struct V_153 * V_154 , struct V_17 * V_18 ,
const unsigned char * V_6 , int V_235 )
{
struct V_46 * V_149 = F_58 ( V_18 ) ;
if ( V_235 == 0 ) {
F_4 ( & V_18 -> V_2 , L_96 , V_12 ) ;
return 0 ;
}
if ( V_149 == NULL )
return - V_61 ;
if ( V_149 -> V_195 == 1 )
return - V_61 ;
V_235 = F_82 ( & V_149 -> V_231 , V_6 , V_235 ,
& V_149 -> V_197 ) ;
F_67 ( V_154 ) ;
return V_235 ;
}
static void F_67 ( struct V_153 * V_154 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
int V_235 , V_237 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
unsigned long V_230 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
if ( V_149 -> V_203 ) {
F_79 ( & V_149 -> V_197 , V_230 ) ;
return;
}
V_235 = F_83 ( & V_149 -> V_231 ,
V_18 -> V_225 -> V_181 ,
V_18 -> V_238 ) ;
if ( V_235 == 0 ) {
F_79 ( & V_149 -> V_197 , V_230 ) ;
return;
}
V_149 -> V_203 = 1 ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
F_11 ( & V_18 -> V_2 , V_12 , V_235 , V_18 -> V_225 -> V_181 ) ;
V_18 -> V_225 -> V_239 = V_235 ;
V_237 = F_59 ( V_18 -> V_225 , V_193 ) ;
if ( V_237 ) {
F_66 ( V_18 ,
L_97 ,
V_12 , V_237 ) ;
V_149 -> V_203 = 0 ;
} else
V_149 -> V_152 . V_240 += V_235 ;
if ( V_154 )
F_51 ( V_154 ) ;
}
static int F_84 ( struct V_153 * V_154 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
int V_241 = 0 ;
unsigned long V_230 ;
if ( V_149 == NULL )
return 0 ;
if ( V_149 -> V_195 == 1 )
return 0 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
V_241 = F_85 ( & V_149 -> V_231 ) ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
F_4 ( & V_18 -> V_2 , L_98 , V_12 , V_241 ) ;
return V_241 ;
}
static int F_86 ( struct V_153 * V_154 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
int V_242 = 0 ;
unsigned long V_230 ;
int V_243 ;
if ( V_149 == NULL )
return 0 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
V_242 = F_87 ( & V_149 -> V_231 ) ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
if ( ! V_242 ) {
V_243 = F_19 ( V_149 ) ;
if ( V_243 > 0 )
V_242 = V_243 ;
}
F_4 ( & V_18 -> V_2 , L_98 , V_12 , V_242 ) ;
return V_242 ;
}
static void F_88 ( struct V_153 * V_154 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
int V_8 ;
if ( V_149 == NULL )
return;
if ( F_89 ( V_154 ) ) {
unsigned char V_244 = F_90 ( V_154 ) ;
V_8 = F_81 ( V_154 , V_18 , & V_244 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_99 , V_12 , V_8 ) ;
}
}
if ( F_50 ( V_154 ) )
F_91 ( V_149 ) ;
}
static void F_92 ( struct V_153 * V_154 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
int V_8 ;
if ( V_149 == NULL )
return;
if ( F_89 ( V_154 ) ) {
unsigned char V_245 = F_93 ( V_154 ) ;
V_8 = F_81 ( V_154 , V_18 , & V_245 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_100 , V_12 , V_8 ) ;
}
}
if ( F_50 ( V_154 ) ) {
V_8 = F_94 ( V_149 ) ;
if ( V_8 )
F_16 ( & V_18 -> V_2 ,
L_101 ,
V_12 , V_8 ) ;
}
}
static void F_91 ( struct V_46 * V_149 )
{
unsigned long V_230 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
if ( V_149 -> V_198 == V_199 )
V_149 -> V_198 = V_200 ;
V_149 -> V_219 &= ~ V_145 ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
}
static int F_94 ( struct V_46 * V_149 )
{
struct V_178 * V_178 ;
int V_8 = 0 ;
unsigned long V_230 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
if ( V_149 -> V_198 == V_201 ) {
V_178 = V_149 -> V_18 -> V_227 ;
V_8 = F_59 ( V_178 , V_193 ) ;
}
V_149 -> V_198 = V_199 ;
V_149 -> V_219 |= V_145 ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
return V_8 ;
}
static void F_95 ( struct V_153 * V_154 ,
struct V_46 * V_149 , struct V_246 * V_247 )
{
struct V_43 * V_2 = & V_149 -> V_18 -> V_2 ;
struct V_248 * V_57 ;
int V_249 ;
unsigned V_250 ;
int V_8 ;
int V_20 = V_149 -> V_18 -> V_21 -
V_149 -> V_18 -> V_22 -> V_23 ;
F_4 ( V_2 , L_102 , V_12 , V_149 -> V_18 -> V_21 ) ;
V_57 = F_15 ( sizeof ( * V_57 ) , V_40 ) ;
if ( ! V_57 ) {
V_154 -> V_210 = * V_247 ;
F_16 ( V_2 , L_6 , V_12 ) ;
return;
}
V_250 = V_154 -> V_210 . V_251 ;
V_57 -> V_252 = 0 ;
V_57 -> V_252 |= V_253 ;
V_57 -> V_252 |= V_254 ;
V_57 -> V_255 = ( T_1 ) ( V_149 -> V_255 ) ;
switch ( V_250 & V_256 ) {
case V_257 :
V_57 -> V_258 = V_259 ;
F_4 ( V_2 , L_103 , V_12 ) ;
break;
case V_260 :
V_57 -> V_258 = V_261 ;
F_4 ( V_2 , L_104 , V_12 ) ;
break;
case V_262 :
V_57 -> V_258 = V_263 ;
F_4 ( V_2 , L_105 , V_12 ) ;
break;
default:
case V_264 :
V_57 -> V_258 = V_265 ;
F_4 ( V_2 , L_106 , V_12 ) ;
break;
}
if ( V_250 & V_266 ) {
if ( V_250 & V_267 ) {
V_57 -> V_252 |= V_268 ;
V_57 -> V_269 = V_270 ;
F_4 ( V_2 , L_107 , V_12 ) ;
} else {
V_57 -> V_252 |= V_268 ;
V_57 -> V_269 = V_271 ;
F_4 ( V_2 , L_108 , V_12 ) ;
}
} else {
V_57 -> V_269 = V_272 ;
F_4 ( V_2 , L_109 , V_12 ) ;
}
if ( V_250 & V_273 ) {
V_57 -> V_274 = V_275 ;
F_4 ( V_2 , L_110 , V_12 ) ;
} else {
V_57 -> V_274 = V_276 ;
F_4 ( V_2 , L_111 , V_12 ) ;
}
if ( V_250 & V_277 ) {
V_57 -> V_252 |= V_278 ;
V_57 -> V_252 |= V_279 ;
F_4 ( V_2 , L_112 , V_12 ) ;
} else {
F_4 ( V_2 , L_113 , V_12 ) ;
V_154 -> V_166 = 0 ;
F_94 ( V_149 ) ;
}
V_57 -> V_280 = F_93 ( V_154 ) ;
V_57 -> V_281 = F_90 ( V_154 ) ;
if ( F_89 ( V_154 ) ) {
V_57 -> V_252 |= V_282 ;
F_4 ( V_2 , L_114 ,
V_12 , V_57 -> V_280 , V_57 -> V_281 ) ;
} else
F_4 ( V_2 , L_115 , V_12 ) ;
if ( F_96 ( V_154 ) ) {
V_57 -> V_252 |= V_283 ;
F_4 ( V_2 , L_116 ,
V_12 , V_57 -> V_280 , V_57 -> V_281 ) ;
} else
F_4 ( V_2 , L_117 , V_12 ) ;
V_154 -> V_210 . V_251 &= ~ V_284 ;
V_249 = F_97 ( V_154 ) ;
if ( ! V_249 ) {
V_249 = 9600 ;
} else
F_98 ( V_154 , V_249 , V_249 ) ;
V_149 -> V_285 = V_249 ;
V_57 -> V_286 = ( T_2 ) ( ( 461550L + V_249 / 2 ) / V_249 ) ;
F_4 ( V_2 , L_118 , V_12 , V_249 , V_57 -> V_286 ) ;
F_4 ( V_2 , L_119 , ( int ) ( 461550L / V_57 -> V_286 ) ) ;
F_4 ( V_2 , L_120 , V_57 -> V_252 ) ;
F_4 ( V_2 , L_121 , V_57 -> V_258 ) ;
F_4 ( V_2 , L_122 , V_57 -> V_269 ) ;
F_4 ( V_2 , L_123 , V_57 -> V_274 ) ;
F_4 ( V_2 , L_124 , V_57 -> V_280 ) ;
F_4 ( V_2 , L_125 , V_57 -> V_281 ) ;
F_4 ( V_2 , L_126 , V_57 -> V_255 ) ;
F_99 ( & V_57 -> V_252 ) ;
F_99 ( & V_57 -> V_286 ) ;
V_8 = F_7 ( V_149 -> V_18 -> V_22 -> V_2 , V_287 ,
( T_1 ) ( V_25 + V_20 ) ,
0 , ( T_1 * ) V_57 , sizeof( * V_57 ) ) ;
if ( V_8 )
F_4 ( V_2 , L_127 ,
V_12 , V_8 ) ;
F_17 ( V_57 ) ;
}
static void F_69 ( struct V_153 * V_154 ,
struct V_17 * V_18 , struct V_246 * V_247 )
{
struct V_46 * V_149 = F_58 ( V_18 ) ;
unsigned int V_250 ;
V_250 = V_154 -> V_210 . V_251 ;
F_4 ( & V_18 -> V_2 , L_128 , V_12 ,
V_154 -> V_210 . V_251 , V_154 -> V_210 . V_288 ) ;
F_4 ( & V_18 -> V_2 , L_129 , V_12 ,
V_247 -> V_251 , V_247 -> V_288 ) ;
F_4 ( & V_18 -> V_2 , L_102 , V_12 , V_18 -> V_21 ) ;
if ( V_149 == NULL )
return;
F_95 ( V_154 , V_149 , V_247 ) ;
}
static int F_100 ( struct V_153 * V_154 ,
unsigned int V_289 , unsigned int V_290 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
unsigned int V_141 ;
unsigned long V_230 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
V_141 = V_149 -> V_219 ;
if ( V_289 & V_291 )
V_141 |= V_145 ;
if ( V_289 & V_292 )
V_141 |= V_143 ;
if ( V_289 & V_293 )
V_141 |= V_147 ;
if ( V_290 & V_291 )
V_141 &= ~ V_145 ;
if ( V_290 & V_292 )
V_141 &= ~ V_143 ;
if ( V_290 & V_293 )
V_141 &= ~ V_147 ;
V_149 -> V_219 = V_141 ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
F_44 ( V_149 , V_141 ) ;
return 0 ;
}
static int F_101 ( struct V_153 * V_154 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
unsigned int V_237 = 0 ;
unsigned int V_150 ;
unsigned int V_141 ;
unsigned long V_230 ;
F_77 ( & V_149 -> V_197 , V_230 ) ;
V_150 = V_149 -> V_164 ;
V_141 = V_149 -> V_219 ;
V_237 = ( ( V_141 & V_143 ) ? V_292 : 0 )
| ( ( V_141 & V_145 ) ? V_291 : 0 )
| ( ( V_150 & V_165 ) ? V_294 : 0 )
| ( ( V_150 & V_295 ) ? V_296 : 0 )
| ( ( V_150 & V_297 ) ? V_298 : 0 )
| ( ( V_150 & V_299 ) ? V_300 : 0 ) ;
F_4 ( & V_18 -> V_2 , L_130 , V_12 , V_237 ) ;
F_79 ( & V_149 -> V_197 , V_230 ) ;
return V_237 ;
}
static int F_102 ( struct V_153 * V_154 ,
struct V_301 * V_152 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
struct V_151 * V_302 = & V_149 -> V_152 ;
V_152 -> V_159 = V_302 -> V_159 ;
V_152 -> V_160 = V_302 -> V_160 ;
V_152 -> V_162 = V_302 -> V_162 ;
V_152 -> V_161 = V_302 -> V_161 ;
V_152 -> V_240 = V_302 -> V_240 ;
V_152 -> V_196 = V_302 -> V_196 ;
V_152 -> V_177 = V_302 -> V_177 ;
V_152 -> V_176 = V_302 -> V_176 ;
V_152 -> V_175 = V_302 -> V_175 ;
V_152 -> V_174 = V_302 -> V_174 ;
V_152 -> V_303 = V_302 -> V_303 ;
return 0 ;
}
static int F_103 ( struct V_46 * V_149 ,
struct V_304 T_8 * V_305 )
{
struct V_304 V_306 ;
unsigned V_307 ;
if ( ! V_305 )
return - V_308 ;
V_307 = V_149 -> V_18 -> V_18 . V_309 ;
if ( V_307 != V_310 )
V_307 = F_104 ( V_309 ) / 10 ;
memset ( & V_306 , 0 , sizeof( V_306 ) ) ;
V_306 . type = V_311 ;
V_306 . line = V_149 -> V_18 -> V_22 -> V_23 ;
V_306 . V_18 = V_149 -> V_18 -> V_21 ;
V_306 . V_312 = 0 ;
V_306 . V_230 = V_313 | V_314 ;
V_306 . V_315 = V_149 -> V_18 -> V_238 ;
V_306 . V_316 = 9600 ;
V_306 . V_317 = 5 * V_318 ;
V_306 . V_309 = V_307 ;
if ( F_105 ( V_305 , & V_306 , sizeof( * V_305 ) ) )
return - V_308 ;
return 0 ;
}
static int F_106 ( struct V_153 * V_154 ,
unsigned int V_319 , unsigned long V_320 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
struct V_151 V_321 ;
struct V_151 V_322 ;
F_4 ( & V_18 -> V_2 , L_131 , V_12 , V_18 -> V_21 , V_319 ) ;
switch ( V_319 ) {
case V_323 :
F_4 ( & V_18 -> V_2 , L_132 , V_12 ) ;
return F_103 ( V_149 ,
(struct V_304 T_8 * ) V_320 ) ;
case V_324 :
F_4 ( & V_18 -> V_2 , L_133 , V_12 ) ;
V_322 = V_149 -> V_152 ;
while ( 1 ) {
F_107 ( & V_18 -> V_163 ) ;
if ( F_108 ( V_325 ) )
return - V_221 ;
if ( V_18 -> V_22 -> V_233 )
return - V_326 ;
V_321 = V_149 -> V_152 ;
if ( V_321 . V_162 == V_322 . V_162 && V_321 . V_160 == V_322 . V_160 &&
V_321 . V_161 == V_322 . V_161 && V_321 . V_159 == V_322 . V_159 )
return - V_326 ;
if ( ( ( V_320 & V_327 ) && ( V_321 . V_162 != V_322 . V_162 ) ) ||
( ( V_320 & V_300 ) && ( V_321 . V_160 != V_322 . V_160 ) ) ||
( ( V_320 & V_328 ) && ( V_321 . V_161 != V_322 . V_161 ) ) ||
( ( V_320 & V_294 ) && ( V_321 . V_159 != V_322 . V_159 ) ) ) {
return 0 ;
}
V_322 = V_321 ;
}
break;
}
return - V_329 ;
}
static void F_109 ( struct V_153 * V_154 , int V_330 )
{
struct V_17 * V_18 = V_154 -> V_236 ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
int V_8 ;
int V_331 = 0 ;
F_110 ( V_154 , 0 ) ;
if ( V_330 == - 1 )
V_331 = 1 ;
V_8 = F_43 ( V_149 , V_332 , V_331 ) ;
if ( V_8 )
F_4 ( & V_18 -> V_2 , L_134 ,
V_12 , V_8 ) ;
}
static int F_111 ( struct V_109 * V_22 )
{
struct V_35 * V_179 ;
int V_8 ;
V_179 = F_112 ( sizeof( struct V_35 ) , V_40 ) ;
if ( V_179 == NULL ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_135 , V_12 ) ;
return - V_41 ;
}
F_113 ( & V_179 -> V_220 ) ;
V_179 -> V_22 = V_22 ;
F_114 ( V_22 , V_179 ) ;
V_8 = F_40 ( V_179 ) ;
if ( V_8 ) {
F_17 ( V_179 ) ;
return V_8 ;
}
return 0 ;
}
static void F_115 ( struct V_109 * V_22 )
{
}
static void F_116 ( struct V_109 * V_22 )
{
F_17 ( F_76 ( V_22 ) ) ;
}
static int F_117 ( struct V_17 * V_18 )
{
struct V_46 * V_149 ;
int V_243 ;
V_149 = F_112 ( sizeof( * V_149 ) , V_40 ) ;
if ( ! V_149 )
return - V_41 ;
V_243 = F_118 ( & V_149 -> V_231 , V_333 ,
V_40 ) ;
if ( V_243 ) {
F_17 ( V_149 ) ;
return - V_41 ;
}
F_119 ( & V_149 -> V_197 ) ;
V_149 -> V_18 = V_18 ;
V_149 -> V_179 = F_76 ( V_18 -> V_22 ) ;
V_149 -> V_255 = V_334 ;
F_120 ( V_18 , V_149 ) ;
V_243 = F_121 ( V_18 ) ;
if ( V_243 ) {
F_122 ( & V_149 -> V_231 ) ;
F_17 ( V_149 ) ;
return V_243 ;
}
V_18 -> V_18 . V_309 = F_123 ( V_309 * 10 ) ;
return 0 ;
}
static int F_124 ( struct V_17 * V_18 )
{
struct V_46 * V_149 ;
V_149 = F_58 ( V_18 ) ;
F_125 ( V_18 ) ;
F_122 ( & V_149 -> V_231 ) ;
F_17 ( V_149 ) ;
return 0 ;
}
static T_9 F_126 ( struct V_43 * V_2 ,
struct V_335 * V_336 , char * V_337 )
{
struct V_17 * V_18 = F_127 ( V_2 ) ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
return sprintf ( V_337 , L_64 , V_149 -> V_255 ) ;
}
static T_9 F_128 ( struct V_43 * V_2 ,
struct V_335 * V_336 , const char * V_338 , T_10 V_235 )
{
struct V_17 * V_18 = F_127 ( V_2 ) ;
struct V_46 * V_149 = F_58 ( V_18 ) ;
unsigned int V_339 = F_129 ( V_338 , NULL , 0 ) ;
F_4 ( V_2 , L_136 , V_12 , V_339 ) ;
if ( V_339 < 256 )
V_149 -> V_255 = V_339 ;
else
F_16 ( V_2 , L_137 , V_12 , V_339 ) ;
return V_235 ;
}
static int F_121 ( struct V_17 * V_18 )
{
return F_130 ( & V_18 -> V_2 , & V_340 ) ;
}
static int F_125 ( struct V_17 * V_18 )
{
F_131 ( & V_18 -> V_2 , & V_340 ) ;
return 0 ;
}
