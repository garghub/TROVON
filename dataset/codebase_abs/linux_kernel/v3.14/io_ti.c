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
int V_20 = V_18 -> V_20 ;
F_4 ( & V_18 -> V_2 , L_2 , V_12 , V_20 , V_19 ) ;
return F_7 ( V_18 -> V_21 -> V_2 ,
V_22 ,
( T_1 ) ( V_23 + V_20 ) ,
V_19 ,
NULL ,
0 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_24 ,
int V_25 , T_1 V_26 , T_1 * V_27 )
{
int V_8 = 0 ;
T_1 V_28 ;
T_4 V_29 ;
F_4 ( & V_2 -> V_2 , L_3 , V_12 , V_24 , V_25 ) ;
while ( V_25 ) {
if ( V_25 > 64 )
V_28 = 64 ;
else
V_28 = ( T_1 ) V_25 ;
if ( V_28 > 1 ) {
F_4 ( & V_2 -> V_2 , L_3 , V_12 , V_24 , V_28 ) ;
}
V_29 = F_10 ( V_24 ) ;
V_8 = F_1 ( V_2 , V_30 ,
( T_2 ) V_26 ,
( V_31 T_2 ) V_29 ,
V_27 , V_28 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
if ( V_28 > 1 )
F_11 ( & V_2 -> V_2 , V_12 , V_28 , V_27 ) ;
V_24 += V_28 ;
V_27 += V_28 ;
V_25 -= V_28 ;
}
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 , int V_24 ,
int V_25 , T_1 * V_27 )
{
return F_9 ( V_2 , V_24 , V_25 ,
V_32 , V_27 ) ;
}
static int F_13 ( struct V_33 * V_21 ,
int V_24 , int V_25 , T_1 * V_27 )
{
int V_8 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_25 ; V_34 ++ ) {
V_8 = F_1 ( V_21 -> V_21 -> V_2 ,
V_30 , V_21 -> V_35 ,
( T_2 ) ( V_24 + V_34 ) , & V_27 [ V_34 ] , 0x01 ) ;
if ( V_8 ) {
F_4 ( & V_21 -> V_21 -> V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
}
F_4 ( & V_21 -> V_21 -> V_2 -> V_2 , L_5 ,
V_12 , V_24 , V_25 ) ;
F_11 ( & V_21 -> V_21 -> V_2 -> V_2 , V_12 , V_25 , V_27 ) ;
V_21 -> V_36 = 1 ;
return V_8 ;
}
static int F_14 ( struct V_33 * V_21 ,
int V_24 , int V_25 , T_1 * V_27 )
{
int V_8 = 0 ;
int V_34 ;
T_3 * V_37 ;
if ( ! V_21 -> V_36 ) {
V_37 = F_15 ( 1 , V_38 ) ;
if ( ! V_37 )
return - V_39 ;
V_8 = F_13 ( V_21 , 0 , 1 , V_37 ) ;
F_16 ( V_37 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_34 = 0 ; V_34 < V_25 ; ++ V_34 ) {
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_40 , V_27 [ V_34 ] ,
( T_2 ) ( V_34 + V_24 ) , NULL , 0 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( & V_21 -> V_21 -> V_2 -> V_2 , L_6 , V_12 , V_24 , V_25 ) ;
F_11 ( & V_21 -> V_21 -> V_2 -> V_2 , V_12 , V_25 , V_27 ) ;
return V_8 ;
}
static int F_17 ( struct V_33 * V_21 ,
int V_24 , int V_25 , T_1 V_26 , T_1 * V_27 )
{
struct V_41 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_42 ;
T_4 V_29 ;
V_42 = V_43 -
( V_24 & ( V_43 - 1 ) ) ;
if ( V_42 > V_25 )
V_42 = V_25 ;
F_4 ( V_2 , L_7 ,
V_12 , V_24 , V_42 ) ;
F_11 ( V_2 , V_12 , V_42 , V_27 ) ;
V_29 = F_10 ( V_24 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_40 , ( T_2 ) V_26 ,
( V_31 T_2 ) V_29 ,
V_27 , V_42 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_8 , V_12 , V_8 ) ;
return V_8 ;
}
V_25 -= V_42 ;
V_24 += V_42 ;
V_27 += V_42 ;
while ( V_25 ) {
if ( V_25 > V_43 )
V_42 = V_43 ;
else
V_42 = V_25 ;
F_4 ( V_2 , L_9 ,
V_12 , V_24 , V_42 ) ;
F_11 ( V_2 , V_12 , V_42 , V_27 ) ;
V_29 = F_10 ( V_24 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 , V_40 ,
( T_2 ) V_26 ,
( V_31 T_2 ) V_29 ,
V_27 , V_42 ) ;
if ( V_8 ) {
F_18 ( V_2 , L_8 , V_12 , V_8 ) ;
return V_8 ;
}
V_25 -= V_42 ;
V_24 += V_42 ;
V_27 += V_42 ;
}
return V_8 ;
}
static int F_19 ( struct V_44 * V_18 )
{
int V_8 ;
struct V_45 * V_46 ;
T_1 * V_47 ;
int V_48 = 0 ;
V_46 = F_15 ( sizeof( * V_46 ) , V_38 ) ;
if ( ! V_46 )
return - V_39 ;
V_47 = F_15 ( 1 , V_38 ) ;
if ( ! V_47 ) {
F_16 ( V_46 ) ;
return - V_39 ;
}
V_8 = F_12 ( V_18 -> V_18 -> V_21 -> V_2 , V_18 -> V_49 ,
sizeof( * V_46 ) , ( void * ) V_46 ) ;
if ( V_8 )
goto V_50;
F_4 ( & V_18 -> V_18 -> V_2 , L_10 , V_12 , V_46 -> V_51 ) ;
V_8 = F_12 ( V_18 -> V_18 -> V_21 -> V_2 ,
V_18 -> V_52 + V_53 , 1 , V_47 ) ;
if ( V_8 )
goto V_50;
F_4 ( & V_18 -> V_18 -> V_2 , L_11 , V_12 , * V_47 ) ;
if ( ( V_46 -> V_51 & 0x80 ) != 0 )
V_48 += 64 ;
if ( ( * V_47 & V_54 ) == 0 )
V_48 += 1 ;
V_50:
F_4 ( & V_18 -> V_18 -> V_2 , L_12 , V_12 , V_48 ) ;
F_16 ( V_47 ) ;
F_16 ( V_46 ) ;
return V_48 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 , L_13 ,
V_12 , V_2 -> V_55 -> V_56 . V_57 ) ;
F_4 ( & V_2 -> V_2 , L_14 ,
V_12 , V_2 -> V_55 -> V_56 . V_58 * 2 ) ;
if ( V_2 -> V_55 -> V_56 . V_57 != 1 ) {
F_18 ( & V_2 -> V_2 , L_15 , V_12 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_21 ( struct V_33 * V_21 ,
int V_24 , int V_25 , T_1 * V_27 )
{
int V_8 ;
if ( V_21 -> V_60 . V_61 == V_62 ) {
V_8 = F_9 ( V_21 -> V_21 -> V_2 ,
V_24 ,
V_25 ,
V_21 -> V_35 ,
V_27 ) ;
} else {
V_8 = F_13 ( V_21 , V_24 , V_25 ,
V_27 ) ;
}
return V_8 ;
}
static int F_22 ( struct V_33 * V_21 , int V_24 ,
int V_25 , T_1 * V_27 )
{
if ( V_21 -> V_60 . V_61 == V_63 )
return F_14 ( V_21 , V_24 , V_25 ,
V_27 ) ;
if ( V_21 -> V_60 . V_61 == V_62 )
return F_17 ( V_21 , V_24 , V_25 ,
V_21 -> V_35 , V_27 ) ;
return - V_64 ;
}
static int F_23 ( struct V_33 * V_21 ,
int V_65 , struct V_66 * V_67 )
{
int V_24 ;
int V_8 ;
V_24 = 2 ;
do {
V_8 = F_21 ( V_21 ,
V_24 ,
sizeof( struct V_66 ) ,
( T_1 * ) V_67 ) ;
if ( V_8 )
return 0 ;
if ( V_67 -> Type == V_65 )
return V_24 ;
V_24 = V_24 + sizeof( struct V_66 )
+ V_67 -> V_68 ;
} while ( ( V_24 < V_69 ) && V_67 -> Type );
return 0 ;
}
static int F_24 ( struct V_66 * V_67 , T_1 * V_27 )
{
T_2 V_34 ;
T_1 V_70 = 0 ;
for ( V_34 = 0 ; V_34 < V_67 -> V_68 ; V_34 ++ )
V_70 = ( T_1 ) ( V_70 + V_27 [ V_34 ] ) ;
if ( V_70 != V_67 -> V_71 ) {
F_25 ( L_16 , V_12 , V_67 -> V_71 , V_70 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_26 ( struct V_33 * V_21 )
{
struct V_41 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_66 * V_67 ;
int V_24 = 2 ;
T_1 * V_27 ;
T_2 V_72 ;
V_67 = F_15 ( sizeof( * V_67 ) , V_38 ) ;
if ( ! V_67 )
return - V_39 ;
V_27 = F_15 ( V_69 , V_38 ) ;
if ( ! V_27 ) {
F_16 ( V_67 ) ;
return - V_39 ;
}
V_8 = F_21 ( V_21 , 0 , 1 , V_27 ) ;
if ( V_8 )
goto V_73;
if ( * V_27 != V_74 && * V_27 != V_75 ) {
F_18 ( V_2 , L_17 , V_12 ) ;
V_8 = - V_59 ;
goto V_73;
}
do {
V_8 = F_21 ( V_21 ,
V_24 ,
sizeof( struct V_66 ) ,
( T_1 * ) V_67 ) ;
if ( V_8 )
break;
if ( ( V_24 + sizeof( struct V_66 ) +
V_67 -> V_68 ) > V_69 ) {
V_8 = - V_59 ;
F_4 ( V_2 , L_18 , V_12 ) ;
break;
}
F_4 ( V_2 , L_19 , V_12 , V_67 -> Type ) ;
V_72 = V_67 -> Type & 0x0f ;
if ( V_72 != V_76
&& V_72 != V_77 ) {
V_8 = F_21 ( V_21 , V_24 +
sizeof( struct V_66 ) ,
V_67 -> V_68 , V_27 ) ;
if ( V_8 )
break;
V_8 = F_24 ( V_67 , V_27 ) ;
if ( V_8 )
break;
}
V_24 = V_24 + sizeof( struct V_66 ) +
V_67 -> V_68 ;
} while ( ( V_67 -> Type != V_78 ) &&
( V_24 < V_69 ) );
if ( ( V_67 -> Type != V_78 ) ||
( V_24 > V_69 ) )
V_8 = - V_59 ;
V_73:
F_16 ( V_27 ) ;
F_16 ( V_67 ) ;
return V_8 ;
}
static int F_27 ( struct V_33 * V_21 , T_1 * V_27 )
{
int V_8 ;
int V_24 ;
struct V_66 * V_67 ;
struct V_79 * V_56 ;
struct V_41 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
V_67 = F_15 ( sizeof( * V_67 ) , V_38 ) ;
if ( ! V_67 )
return - V_39 ;
V_24 = F_23 ( V_21 , V_78 ,
V_67 ) ;
if ( ! V_24 ) {
F_4 ( V_2 , L_20 , V_12 ) ;
V_8 = - V_59 ;
goto exit;
}
V_8 = F_21 ( V_21 , V_24 + sizeof( struct V_66 ) ,
V_67 -> V_68 , V_27 ) ;
if ( V_8 )
goto exit;
V_8 = F_24 ( V_67 , V_27 ) ;
V_56 = (struct V_79 * ) V_27 ;
F_4 ( V_2 , L_21 , V_12 , V_56 -> V_80 ) ;
F_4 ( V_2 , L_22 , V_12 , V_56 -> V_81 ) ;
F_4 ( V_2 , L_23 , V_12 , V_56 -> V_82 ) ;
F_4 ( V_2 , L_24 , V_12 , V_56 -> V_83 ) ;
F_4 ( V_2 , L_25 , V_12 , V_56 -> V_84 ) ;
F_4 ( V_2 , L_26 , V_12 , V_56 -> V_85 ) ;
exit:
F_16 ( V_67 ) ;
return V_8 ;
}
static int F_28 ( T_1 * V_86 , struct V_41 * V_2 )
{
T_1 * V_27 ;
int V_87 ;
int V_34 ;
int V_88 ;
T_1 V_70 = 0 ;
struct V_66 * V_89 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
const struct V_94 * V_95 ;
const char * V_96 = L_27 ;
V_87 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_92 ) ) ;
V_27 = F_15 ( V_87 , V_38 ) ;
if ( ! V_27 )
return - V_39 ;
memset ( V_27 , 0xff , V_87 ) ;
V_88 = F_29 ( & V_95 , V_96 , V_2 ) ;
if ( V_88 ) {
F_18 ( V_2 , L_28 ,
V_96 , V_88 ) ;
F_16 ( V_27 ) ;
return V_88 ;
}
V_97 = V_95 -> V_6 [ 0 ] ;
V_98 = V_95 -> V_6 [ 1 ] ;
V_99 = V_95 -> V_6 [ 2 ] | ( V_95 -> V_6 [ 3 ] << 8 ) ;
V_93 = (struct V_92 * ) V_27 ;
V_93 -> V_100 = V_97 ;
V_93 -> V_101 = V_98 ;
V_91 = (struct V_90 * ) & V_95 -> V_6 [ 4 ] ;
memcpy ( V_27 + sizeof( struct V_92 ) ,
& V_95 -> V_6 [ 4 + sizeof( struct V_90 ) ] ,
F_30 ( V_91 -> V_102 ) ) ;
F_31 ( V_95 ) ;
for ( V_34 = 0 ; V_34 < V_87 ; V_34 ++ ) {
V_70 = ( T_1 ) ( V_70 + V_27 [ V_34 ] ) ;
}
F_16 ( V_27 ) ;
V_89 = (struct V_66 * ) V_86 ;
V_93 = (struct V_92 * ) V_89 -> V_103 ;
V_89 -> Type = V_104 ;
V_89 -> V_68 = ( T_2 ) V_87 ;
V_89 -> V_71 = V_70 ;
V_93 -> V_100 = V_97 ;
V_93 -> V_101 = V_98 ;
return 0 ;
}
static int F_32 ( struct V_33 * V_21 )
{
struct V_41 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 ;
T_3 * V_6 ;
V_6 = F_15 ( 1 , V_38 ) ;
if ( ! V_6 )
return - V_39 ;
V_8 = F_1 ( V_21 -> V_21 -> V_2 , V_30 ,
V_105 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_29 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_30 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_74 || * V_6 == V_75 ) ) {
F_4 ( V_2 , L_31 , V_12 ) ;
V_21 -> V_35 = V_105 ;
goto V_73;
}
V_8 = F_1 ( V_21 -> V_21 -> V_2 , V_30 ,
V_106 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_32 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_30 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_74 || * V_6 == V_75 ) ) {
F_4 ( V_2 , L_33 , V_12 ) ;
V_21 -> V_35 = V_106 ;
goto V_73;
}
F_4 ( V_2 , L_34 , V_12 ) ;
V_21 -> V_35 = V_105 ;
V_8 = - V_59 ;
V_73:
F_16 ( V_6 ) ;
return V_8 ;
}
static int F_33 ( struct V_107 * V_21 , void * V_27 ,
int V_25 , int * V_108 )
{
int V_8 ;
V_8 = F_34 ( V_21 -> V_2 ,
F_35 ( V_21 -> V_2 ,
V_21 -> V_18 [ 0 ] -> V_109 ) ,
V_27 , V_25 , V_108 , 1000 ) ;
return V_8 ;
}
static int F_36 ( struct V_33 * V_21 , T_1 * V_110 ,
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
V_8 = F_33 ( V_21 -> V_21 , & V_110 [ V_112 ] ,
V_113 , & V_114 ) ;
if ( V_8 )
break;
V_112 += V_114 ;
}
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_38 ( struct V_79 * V_56 )
{
return F_39 ( V_56 -> V_82 ) ;
}
static int F_40 ( struct V_33 * V_21 )
{
struct V_41 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_24 ;
struct V_79 * V_116 ;
struct V_117 * V_118 ;
int V_119 ;
int V_120 ;
V_21 -> V_60 . V_121 = V_122 ;
V_21 -> V_35 = V_105 ;
V_8 = F_20 ( V_21 -> V_21 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_118 = & V_21 -> V_21 -> V_118 -> V_123 -> V_56 ;
if ( ! V_118 ) {
F_18 ( V_2 , L_35 , V_12 ) ;
return - V_59 ;
}
if ( V_118 -> V_124 > 1 )
V_21 -> V_60 . V_61 = V_62 ;
else
V_21 -> V_60 . V_61 = V_125 ;
if ( V_21 -> V_60 . V_61 == V_62 ) {
struct V_66 * V_67 ;
F_4 ( V_2 , L_36 , V_12 ) ;
V_8 = F_26 ( V_21 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_37 , V_12 ) ;
return V_8 ;
}
V_116 = F_15 ( sizeof( * V_116 ) , V_38 ) ;
if ( ! V_116 )
return - V_39 ;
V_8 = F_27 ( V_21 , ( T_1 * ) V_116 ) ;
if ( V_8 ) {
F_16 ( V_116 ) ;
return V_8 ;
}
if ( ! V_126 && F_38 ( V_116 ) < 2 ) {
F_4 ( V_2 , L_38 ,
V_12 , F_38 ( V_116 ) ) ;
F_16 ( V_116 ) ;
return - V_64 ;
}
V_67 = F_15 ( sizeof( * V_67 ) , V_38 ) ;
if ( ! V_67 ) {
F_16 ( V_116 ) ;
return - V_39 ;
}
V_24 = F_23 ( V_21 ,
V_76 , V_67 ) ;
if ( V_24 != 0 ) {
struct V_92 * V_127 ;
T_3 * V_128 ;
F_4 ( V_2 , L_39 , V_12 ) ;
V_127 = F_15 ( sizeof( * V_127 ) ,
V_38 ) ;
if ( ! V_127 ) {
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_39 ;
}
V_8 = F_21 ( V_21 , V_24 +
sizeof( struct V_66 ) ,
sizeof( struct V_92 ) ,
( T_1 * ) V_127 ) ;
if ( V_8 ) {
F_16 ( V_127 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return V_8 ;
}
V_119 = ( V_127 -> V_100 << 8 ) +
( V_127 -> V_101 ) ;
V_120 = ( V_97 << 8 ) +
( V_98 ) ;
F_4 ( V_2 , L_40 ,
V_12 , V_127 -> V_100 ,
V_127 -> V_101 ,
V_97 ,
V_98 ) ;
if ( V_119 < V_120 ) {
F_4 ( V_2 , L_41 ,
V_12 ,
V_127 -> V_100 ,
V_127 -> V_101 ,
V_97 ,
V_98 ) ;
V_128 = F_15 ( 1 , V_38 ) ;
if ( ! V_128 ) {
F_16 ( V_127 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_39 ;
}
* V_128 = V_104 ;
V_8 = F_22 ( V_21 , V_24 ,
sizeof( * V_128 ) , V_128 ) ;
if ( V_8 ) {
F_16 ( V_128 ) ;
F_16 ( V_127 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return V_8 ;
}
V_8 = F_21 ( V_21 ,
V_24 ,
sizeof( * V_128 ) ,
V_128 ) ;
if ( V_8 ) {
F_16 ( V_128 ) ;
F_16 ( V_127 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return V_8 ;
}
if ( * V_128 != V_104 ) {
F_18 ( V_2 , L_42 , V_12 ) ;
F_16 ( V_128 ) ;
F_16 ( V_127 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_59 ;
}
F_4 ( V_2 , L_43 , V_12 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_129 ,
0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_44 , V_12 , V_8 ) ;
F_16 ( V_128 ) ;
F_16 ( V_127 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_59 ;
}
F_16 ( V_127 ) ;
}
else if ( ( V_24 = F_23 ( V_21 , V_104 , V_67 ) ) != 0 ) {
#define F_41 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_86 ;
T_1 * V_130 ;
V_86 = F_15 ( F_41 , V_38 ) ;
if ( ! V_86 ) {
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_39 ;
}
V_130 = F_15 ( F_41 , V_38 ) ;
if ( ! V_130 ) {
F_16 ( V_86 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_39 ;
}
F_4 ( V_2 , L_45 , V_12 ) ;
V_8 = F_28 ( V_86 , V_2 ) ;
if ( V_8 ) {
F_16 ( V_130 ) ;
F_16 ( V_86 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_64 ;
}
V_8 = F_22 ( V_21 ,
V_24 ,
F_41 ,
V_86 ) ;
if ( V_8 ) {
F_16 ( V_130 ) ;
F_16 ( V_86 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_64 ;
}
V_8 = F_21 ( V_21 , V_24 ,
F_41 , V_130 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_46 , V_12 ) ;
F_16 ( V_130 ) ;
F_16 ( V_86 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return V_8 ;
}
if ( memcmp ( V_130 , V_86 , F_41 ) ) {
F_4 ( V_2 , L_47 , V_12 ) ;
F_16 ( V_130 ) ;
F_16 ( V_86 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return - V_64 ;
}
F_16 ( V_130 ) ;
F_16 ( V_86 ) ;
F_4 ( V_2 , L_48 , V_12 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_131 , 0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_49 , V_12 , V_8 ) ;
if ( V_8 ) {
F_18 ( V_2 ,
L_50 ,
V_12 ) ;
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return V_8 ;
}
}
F_16 ( V_67 ) ;
F_16 ( V_116 ) ;
return 0 ;
}
F_4 ( V_2 , L_51 , V_12 ) ;
V_8 = F_37 ( V_21 -> V_21 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_30 ( V_21 -> V_21 -> V_2 -> V_132 . V_133 )
!= V_134 ) {
F_4 ( V_2 , L_52 , V_12 ,
F_30 ( V_21 -> V_21 -> V_2 -> V_132 . V_133 ) ) ;
V_21 -> V_35 = V_105 ;
goto V_135;
}
if ( F_32 ( V_21 ) )
goto V_135;
if ( ! F_26 ( V_21 ) ) {
struct V_90 * V_86 ;
int V_34 ;
T_1 V_70 = 0 ;
T_1 * V_27 ;
int V_87 ;
int V_88 ;
const struct V_94 * V_95 ;
const char * V_96 = L_27 ;
V_116 = F_15 ( sizeof( * V_116 ) , V_38 ) ;
if ( ! V_116 )
return - V_39 ;
V_8 = F_27 ( V_21 , ( T_1 * ) V_116 ) ;
if ( V_8 ) {
F_16 ( V_116 ) ;
goto V_135;
}
if ( ! V_126 && F_38 ( V_116 ) < 2 ) {
F_4 ( V_2 , L_38 ,
V_12 , F_38 ( V_116 ) ) ;
F_16 ( V_116 ) ;
goto V_135;
}
F_16 ( V_116 ) ;
V_87 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_90 ) ) ;
V_27 = F_15 ( V_87 , V_38 ) ;
if ( ! V_27 )
return - V_39 ;
memset ( V_27 , 0xff , V_87 ) ;
V_88 = F_29 ( & V_95 , V_96 , V_2 ) ;
if ( V_88 ) {
F_18 ( V_2 , L_28 ,
V_96 , V_88 ) ;
F_16 ( V_27 ) ;
return V_88 ;
}
memcpy ( V_27 , & V_95 -> V_6 [ 4 ] , V_95 -> V_7 - 4 ) ;
F_31 ( V_95 ) ;
for ( V_34 = sizeof( struct V_90 ) ;
V_34 < V_87 ; V_34 ++ ) {
V_70 = ( T_1 ) ( V_70 + V_27 [ V_34 ] ) ;
}
V_86 = (struct V_90 * ) V_27 ;
V_86 -> V_102 = F_42 ( ( T_2 ) ( V_87 -
sizeof( struct V_90 ) ) ) ;
V_86 -> V_71 = V_70 ;
F_4 ( V_2 , L_53 , V_12 ) ;
V_8 = F_36 ( V_21 , V_27 , V_87 ) ;
F_16 ( V_27 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_54 , V_12 ) ;
return V_8 ;
}
V_21 -> V_60 . V_61 = V_136 ;
F_4 ( V_2 , L_55 , V_12 ) ;
return - V_59 ;
}
V_135:
F_4 ( V_2 , L_56 , V_12 ) ;
V_21 -> V_60 . V_61 = V_63 ;
return 0 ;
}
static int F_43 ( struct V_44 * V_18 , int V_137 , int V_138 )
{
int V_20 = V_18 -> V_18 -> V_20 ;
V_138 = ! ! V_138 ;
return F_7 ( V_18 -> V_18 -> V_21 -> V_2 ,
V_137 , ( T_1 ) ( V_23 + V_20 ) ,
V_138 , NULL , 0 ) ;
}
static int F_44 ( struct V_44 * V_18 , T_1 V_139 )
{
int V_8 = 0 ;
F_4 ( & V_18 -> V_18 -> V_2 , L_57 , V_12 , V_139 ) ;
V_8 = F_43 ( V_18 , V_140 , V_139 & V_141 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_43 ( V_18 , V_142 , V_139 & V_143 ) ;
if ( V_8 )
return V_8 ;
return F_43 ( V_18 , V_144 , V_139 & V_145 ) ;
}
static T_1 F_45 ( T_1 V_146 )
{
T_1 V_47 = 0 ;
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
return V_47 ;
}
static void F_47 ( struct V_44 * V_147 , T_1 V_148 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
F_4 ( & V_147 -> V_18 -> V_2 , L_58 , V_12 , V_148 ) ;
if ( V_148 & ( V_153 | V_154 |
V_155 | V_156 ) ) {
V_150 = & V_147 -> V_18 -> V_150 ;
if ( V_148 & V_153 )
V_150 -> V_157 ++ ;
if ( V_148 & V_154 )
V_150 -> V_158 ++ ;
if ( V_148 & V_156 )
V_150 -> V_159 ++ ;
if ( V_148 & V_155 )
V_150 -> V_160 ++ ;
F_48 ( & V_147 -> V_18 -> V_18 . V_161 ) ;
}
V_147 -> V_162 = V_148 & 0xf0 ;
V_152 = F_49 ( & V_147 -> V_18 -> V_18 ) ;
if ( V_152 && F_50 ( V_152 ) ) {
if ( V_148 & V_163 ) {
V_152 -> V_164 = 0 ;
F_51 ( V_152 ) ;
} else {
V_152 -> V_164 = 1 ;
}
}
F_52 ( V_152 ) ;
}
static void F_53 ( struct V_44 * V_147 , int V_165 ,
T_1 V_47 , T_1 V_6 )
{
struct V_149 * V_150 ;
T_1 V_166 = ( T_1 ) ( V_47 & ( T_1 ) ( V_167 | V_168 |
V_169 | V_170 ) ) ;
F_4 ( & V_147 -> V_18 -> V_2 , L_58 , V_12 , V_166 ) ;
V_147 -> V_171 = V_47 ;
if ( V_166 & V_170 )
V_166 &= ( T_1 ) ( V_167 | V_170 ) ;
if ( V_165 )
F_54 ( V_147 -> V_18 , & V_6 , 1 ) ;
V_150 = & V_147 -> V_18 -> V_150 ;
if ( V_166 & V_170 )
V_150 -> V_172 ++ ;
if ( V_166 & V_167 )
V_150 -> V_173 ++ ;
if ( V_166 & V_168 )
V_150 -> V_174 ++ ;
if ( V_166 & V_169 )
V_150 -> V_175 ++ ;
}
static void F_55 ( struct V_176 * V_176 )
{
struct V_33 * V_177 = V_176 -> V_178 ;
struct V_17 * V_18 ;
struct V_44 * V_147 ;
struct V_41 * V_2 ;
unsigned char * V_6 = V_176 -> V_179 ;
int V_25 = V_176 -> V_180 ;
int V_20 ;
int V_181 ;
int V_182 ;
T_1 V_47 ;
T_1 V_148 ;
int V_8 = V_176 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_183 :
case - V_184 :
case - V_185 :
F_4 ( & V_176 -> V_2 -> V_2 , L_59 ,
V_12 , V_8 ) ;
return;
default:
F_18 ( & V_176 -> V_2 -> V_2 , L_60
L_61 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_25 ) {
F_4 ( & V_176 -> V_2 -> V_2 , L_62 , V_12 ) ;
goto exit;
}
V_2 = & V_177 -> V_21 -> V_2 -> V_2 ;
F_11 ( V_2 , V_12 , V_25 , V_6 ) ;
if ( V_25 != 2 ) {
F_4 ( V_2 , L_63 , V_12 , V_25 ) ;
goto exit;
}
V_20 = F_56 ( V_6 [ 0 ] ) ;
V_181 = F_57 ( V_6 [ 0 ] ) ;
F_4 ( V_2 , L_64 , V_12 ,
V_20 , V_181 , V_6 [ 1 ] ) ;
V_18 = V_177 -> V_21 -> V_18 [ V_20 ] ;
V_147 = F_58 ( V_18 ) ;
if ( ! V_147 ) {
F_4 ( V_2 , L_65 , V_12 ) ;
return;
}
switch ( V_181 ) {
case V_186 :
V_47 = F_45 ( V_6 [ 1 ] ) ;
if ( V_47 & V_187 ) {
F_4 ( V_2 , L_66 ,
V_12 , V_20 , V_47 ) ;
V_147 -> V_188 = 1 ;
V_147 -> V_189 = V_47 ;
} else {
F_4 ( V_2 , L_67 ,
V_12 , V_20 , V_47 ) ;
F_53 ( V_147 , 0 , V_47 , 0 ) ;
}
break;
case V_190 :
V_148 = V_6 [ 1 ] ;
F_4 ( V_2 , L_68 ,
V_12 , V_20 , V_148 ) ;
F_47 ( V_147 , V_148 ) ;
break;
default:
F_18 ( & V_176 -> V_2 -> V_2 ,
L_69 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_182 = F_59 ( V_176 , V_191 ) ;
if ( V_182 )
F_18 ( & V_176 -> V_2 -> V_2 ,
L_70 ,
V_12 , V_182 ) ;
}
static void F_60 ( struct V_176 * V_176 )
{
struct V_44 * V_147 = V_176 -> V_178 ;
struct V_41 * V_2 = & V_147 -> V_18 -> V_2 ;
unsigned char * V_6 = V_176 -> V_179 ;
int V_182 = 0 ;
int V_20 ;
int V_8 = V_176 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_183 :
case - V_184 :
case - V_185 :
F_4 ( & V_176 -> V_2 -> V_2 , L_59 , V_12 , V_8 ) ;
return;
default:
F_18 ( & V_176 -> V_2 -> V_2 , L_71 , V_12 , V_8 ) ;
}
if ( V_8 == - V_192 )
goto exit;
if ( V_8 ) {
F_18 ( & V_176 -> V_2 -> V_2 , L_72 , V_12 ) ;
return;
}
V_20 = V_147 -> V_18 -> V_20 ;
if ( V_147 -> V_188 ) {
V_147 -> V_188 = 0 ;
F_4 ( V_2 , L_73 ,
V_12 , V_20 , V_147 -> V_189 , * V_6 ) ;
F_53 ( V_147 , 1 , V_147 -> V_189 , * V_6 ) ;
-- V_176 -> V_180 ;
++ V_6 ;
}
if ( V_176 -> V_180 ) {
F_11 ( V_2 , V_12 , V_176 -> V_180 , V_6 ) ;
if ( V_147 -> V_193 )
F_4 ( V_2 , L_74 ,
V_12 ) ;
else
F_54 ( V_147 -> V_18 , V_6 ,
V_176 -> V_180 ) ;
V_147 -> V_18 -> V_150 . V_194 += V_176 -> V_180 ;
}
exit:
F_61 ( & V_147 -> V_195 ) ;
if ( V_147 -> V_196 == V_197 )
V_182 = F_59 ( V_176 , V_191 ) ;
else if ( V_147 -> V_196 == V_198 )
V_147 -> V_196 = V_199 ;
F_62 ( & V_147 -> V_195 ) ;
if ( V_182 )
F_18 ( V_2 , L_70 , V_12 , V_182 ) ;
}
static void F_54 ( struct V_17 * V_18 , unsigned char * V_6 ,
int V_25 )
{
int V_200 ;
V_200 = F_63 ( & V_18 -> V_18 , V_6 , V_25 ) ;
if ( V_200 < V_25 )
F_18 ( & V_18 -> V_2 , L_75 ,
V_12 , V_25 - V_200 ) ;
F_64 ( & V_18 -> V_18 ) ;
}
static void F_65 ( struct V_176 * V_176 )
{
struct V_17 * V_18 = V_176 -> V_178 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_8 = V_176 -> V_8 ;
struct V_151 * V_152 ;
V_147 -> V_201 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_183 :
case - V_184 :
case - V_185 :
F_4 ( & V_176 -> V_2 -> V_2 , L_59 ,
V_12 , V_8 ) ;
return;
default:
F_66 ( V_18 , L_76
L_77 , V_12 , V_8 ) ;
}
V_152 = F_49 ( & V_18 -> V_18 ) ;
F_67 ( V_18 , V_152 ) ;
F_52 ( V_152 ) ;
}
static int F_68 ( struct V_151 * V_152 , struct V_17 * V_18 )
{
struct V_44 * V_147 = F_58 ( V_18 ) ;
struct V_33 * V_177 ;
struct V_1 * V_2 ;
struct V_176 * V_176 ;
int V_20 ;
int V_8 ;
T_7 V_202 ;
T_3 V_203 ;
if ( V_147 == NULL )
return - V_59 ;
V_20 = V_18 -> V_20 ;
V_2 = V_18 -> V_21 -> V_2 ;
V_8 = F_43 ( V_147 , V_144 , 0 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_78 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_152 )
F_69 ( V_152 , V_18 , & V_152 -> V_204 ) ;
V_203 = 2 ;
V_147 -> V_205 =
F_70 ( 20 , ( ( V_203 * 3 ) / 2 ) ) ;
V_202 = ( T_3 ) ( V_206 |
V_207 |
( V_203 << 2 ) ) ;
F_4 ( & V_18 -> V_2 , L_79 , V_12 ) ;
V_8 = F_7 ( V_2 , V_208 ,
( T_3 ) ( V_23 + V_20 ) , V_202 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 , L_80 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_209 ,
( T_3 ) ( V_23 + V_20 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 , L_81 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_18 , V_210 | V_211 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_82 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_212 , 0 ,
( T_2 ) ( V_23 + V_20 ) ,
& V_147 -> V_162 , 1 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 , L_83 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( & V_18 -> V_2 , L_84 , V_147 -> V_162 ) ;
V_147 -> V_213 = V_143 | V_141 ;
F_4 ( & V_18 -> V_2 , L_85 , V_147 -> V_213 ) ;
V_177 = V_147 -> V_177 ;
if ( F_71 ( & V_177 -> V_214 ) )
return - V_215 ;
if ( V_177 -> V_216 == 0 ) {
V_176 = V_177 -> V_21 -> V_18 [ 0 ] -> V_217 ;
if ( ! V_176 ) {
F_18 ( & V_18 -> V_2 ,
L_86 ,
V_12 ) ;
V_8 = - V_64 ;
goto V_218;
}
V_176 -> V_178 = V_177 ;
V_8 = F_59 ( V_176 , V_38 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_87 ,
V_12 , V_8 ) ;
goto V_218;
}
}
F_72 ( V_2 , V_18 -> V_219 -> V_220 ) ;
F_72 ( V_2 , V_18 -> V_221 -> V_220 ) ;
V_176 = V_18 -> V_221 ;
if ( ! V_176 ) {
F_18 ( & V_18 -> V_2 , L_88 ,
V_12 ) ;
V_8 = - V_64 ;
goto V_222;
}
V_147 -> V_196 = V_197 ;
V_176 -> V_178 = V_147 ;
V_8 = F_59 ( V_176 , V_38 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_89 ,
V_12 , V_8 ) ;
goto V_222;
}
++ V_177 -> V_216 ;
goto V_218;
V_222:
if ( V_147 -> V_177 -> V_216 == 0 )
F_73 ( V_18 -> V_21 -> V_18 [ 0 ] -> V_217 ) ;
V_218:
F_74 ( & V_177 -> V_214 ) ;
return V_8 ;
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_33 * V_177 ;
struct V_44 * V_147 ;
struct V_107 * V_21 = V_18 -> V_21 ;
unsigned long V_223 ;
int V_20 ;
V_177 = F_76 ( V_18 -> V_21 ) ;
V_147 = F_58 ( V_18 ) ;
if ( V_177 == NULL || V_147 == NULL )
return;
V_147 -> V_193 = 1 ;
F_73 ( V_18 -> V_221 ) ;
F_73 ( V_18 -> V_219 ) ;
V_147 -> V_201 = 0 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
F_78 ( & V_18 -> V_224 ) ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
F_4 ( & V_18 -> V_2 , L_90 , V_12 ) ;
V_20 = V_18 -> V_20 ;
F_7 ( V_21 -> V_2 , V_225 ,
( T_1 ) ( V_23 + V_20 ) , 0 , NULL , 0 ) ;
F_80 ( & V_177 -> V_214 ) ;
-- V_147 -> V_177 -> V_216 ;
if ( V_147 -> V_177 -> V_216 <= 0 ) {
F_73 ( V_18 -> V_21 -> V_18 [ 0 ] -> V_217 ) ;
V_147 -> V_177 -> V_216 = 0 ;
}
F_74 ( & V_177 -> V_214 ) ;
V_147 -> V_193 = 0 ;
}
static int F_81 ( struct V_151 * V_152 , struct V_17 * V_18 ,
const unsigned char * V_6 , int V_226 )
{
struct V_44 * V_147 = F_58 ( V_18 ) ;
if ( V_226 == 0 ) {
F_4 ( & V_18 -> V_2 , L_91 , V_12 ) ;
return 0 ;
}
if ( V_147 == NULL )
return - V_59 ;
if ( V_147 -> V_193 == 1 )
return - V_59 ;
V_226 = F_82 ( & V_18 -> V_224 , V_6 , V_226 ,
& V_147 -> V_195 ) ;
F_67 ( V_18 , V_152 ) ;
return V_226 ;
}
static void F_67 ( struct V_17 * V_18 , struct V_151 * V_152 )
{
int V_226 , V_227 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
unsigned long V_223 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
if ( V_147 -> V_201 ) {
F_79 ( & V_147 -> V_195 , V_223 ) ;
return;
}
V_226 = F_83 ( & V_18 -> V_224 ,
V_18 -> V_219 -> V_179 ,
V_18 -> V_228 ) ;
if ( V_226 == 0 ) {
F_79 ( & V_147 -> V_195 , V_223 ) ;
return;
}
V_147 -> V_201 = 1 ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
F_11 ( & V_18 -> V_2 , V_12 , V_226 , V_18 -> V_219 -> V_179 ) ;
V_18 -> V_219 -> V_229 = V_226 ;
V_227 = F_59 ( V_18 -> V_219 , V_191 ) ;
if ( V_227 ) {
F_66 ( V_18 ,
L_92 ,
V_12 , V_227 ) ;
V_147 -> V_201 = 0 ;
} else
V_147 -> V_18 -> V_150 . V_230 += V_226 ;
if ( V_152 )
F_51 ( V_152 ) ;
}
static int F_84 ( struct V_151 * V_152 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_232 = 0 ;
unsigned long V_223 ;
if ( V_147 == NULL )
return 0 ;
if ( V_147 -> V_193 == 1 )
return 0 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
V_232 = F_85 ( & V_18 -> V_224 ) ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
F_4 ( & V_18 -> V_2 , L_93 , V_12 , V_232 ) ;
return V_232 ;
}
static int F_86 ( struct V_151 * V_152 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_233 = 0 ;
unsigned long V_223 ;
if ( V_147 == NULL )
return 0 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
V_233 = F_87 ( & V_18 -> V_224 ) ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
F_4 ( & V_18 -> V_2 , L_93 , V_12 , V_233 ) ;
return V_233 ;
}
static bool F_88 ( struct V_17 * V_18 )
{
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_234 ;
V_234 = F_19 ( V_147 ) ;
if ( V_234 > 0 )
return false ;
return true ;
}
static void F_89 ( struct V_151 * V_152 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_8 ;
if ( V_147 == NULL )
return;
if ( F_90 ( V_152 ) ) {
unsigned char V_235 = F_91 ( V_152 ) ;
V_8 = F_81 ( V_152 , V_18 , & V_235 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_18 -> V_2 , L_94 , V_12 , V_8 ) ;
}
}
if ( F_50 ( V_152 ) )
F_92 ( V_147 ) ;
}
static void F_93 ( struct V_151 * V_152 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_8 ;
if ( V_147 == NULL )
return;
if ( F_90 ( V_152 ) ) {
unsigned char V_236 = F_94 ( V_152 ) ;
V_8 = F_81 ( V_152 , V_18 , & V_236 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_18 -> V_2 , L_95 , V_12 , V_8 ) ;
}
}
if ( F_50 ( V_152 ) ) {
V_8 = F_95 ( V_147 ) ;
if ( V_8 )
F_18 ( & V_18 -> V_2 ,
L_96 ,
V_12 , V_8 ) ;
}
}
static void F_92 ( struct V_44 * V_147 )
{
unsigned long V_223 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
if ( V_147 -> V_196 == V_197 )
V_147 -> V_196 = V_198 ;
V_147 -> V_213 &= ~ V_143 ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
}
static int F_95 ( struct V_44 * V_147 )
{
struct V_176 * V_176 ;
int V_8 = 0 ;
unsigned long V_223 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
if ( V_147 -> V_196 == V_199 ) {
V_176 = V_147 -> V_18 -> V_221 ;
V_8 = F_59 ( V_176 , V_191 ) ;
}
V_147 -> V_196 = V_197 ;
V_147 -> V_213 |= V_143 ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
return V_8 ;
}
static void F_96 ( struct V_151 * V_152 ,
struct V_44 * V_147 , struct V_237 * V_238 )
{
struct V_41 * V_2 = & V_147 -> V_18 -> V_2 ;
struct V_239 * V_55 ;
int V_240 ;
unsigned V_241 ;
int V_8 ;
int V_20 = V_147 -> V_18 -> V_20 ;
V_55 = F_15 ( sizeof ( * V_55 ) , V_38 ) ;
if ( ! V_55 ) {
V_152 -> V_204 = * V_238 ;
return;
}
V_241 = V_152 -> V_204 . V_242 ;
V_55 -> V_243 = 0 ;
V_55 -> V_243 |= V_244 ;
V_55 -> V_243 |= V_245 ;
V_55 -> V_246 = ( T_1 ) ( V_147 -> V_246 ) ;
switch ( V_241 & V_247 ) {
case V_248 :
V_55 -> V_249 = V_250 ;
F_4 ( V_2 , L_97 , V_12 ) ;
break;
case V_251 :
V_55 -> V_249 = V_252 ;
F_4 ( V_2 , L_98 , V_12 ) ;
break;
case V_253 :
V_55 -> V_249 = V_254 ;
F_4 ( V_2 , L_99 , V_12 ) ;
break;
default:
case V_255 :
V_55 -> V_249 = V_256 ;
F_4 ( V_2 , L_100 , V_12 ) ;
break;
}
if ( V_241 & V_257 ) {
if ( V_241 & V_258 ) {
V_55 -> V_243 |= V_259 ;
V_55 -> V_260 = V_261 ;
F_4 ( V_2 , L_101 , V_12 ) ;
} else {
V_55 -> V_243 |= V_259 ;
V_55 -> V_260 = V_262 ;
F_4 ( V_2 , L_102 , V_12 ) ;
}
} else {
V_55 -> V_260 = V_263 ;
F_4 ( V_2 , L_103 , V_12 ) ;
}
if ( V_241 & V_264 ) {
V_55 -> V_265 = V_266 ;
F_4 ( V_2 , L_104 , V_12 ) ;
} else {
V_55 -> V_265 = V_267 ;
F_4 ( V_2 , L_105 , V_12 ) ;
}
if ( V_241 & V_268 ) {
V_55 -> V_243 |= V_269 ;
V_55 -> V_243 |= V_270 ;
F_4 ( V_2 , L_106 , V_12 ) ;
} else {
F_4 ( V_2 , L_107 , V_12 ) ;
V_152 -> V_164 = 0 ;
F_95 ( V_147 ) ;
}
V_55 -> V_271 = F_94 ( V_152 ) ;
V_55 -> V_272 = F_91 ( V_152 ) ;
if ( F_90 ( V_152 ) ) {
V_55 -> V_243 |= V_273 ;
F_4 ( V_2 , L_108 ,
V_12 , V_55 -> V_271 , V_55 -> V_272 ) ;
} else
F_4 ( V_2 , L_109 , V_12 ) ;
if ( F_97 ( V_152 ) ) {
V_55 -> V_243 |= V_274 ;
F_4 ( V_2 , L_110 ,
V_12 , V_55 -> V_271 , V_55 -> V_272 ) ;
} else
F_4 ( V_2 , L_111 , V_12 ) ;
V_152 -> V_204 . V_242 &= ~ V_275 ;
V_240 = F_98 ( V_152 ) ;
if ( ! V_240 ) {
V_240 = 9600 ;
} else
F_99 ( V_152 , V_240 , V_240 ) ;
V_147 -> V_276 = V_240 ;
V_55 -> V_277 = ( T_2 ) ( ( 461550L + V_240 / 2 ) / V_240 ) ;
F_4 ( V_2 , L_112 , V_12 , V_240 , V_55 -> V_277 ) ;
F_4 ( V_2 , L_113 , ( int ) ( 461550L / V_55 -> V_277 ) ) ;
F_4 ( V_2 , L_114 , V_55 -> V_243 ) ;
F_4 ( V_2 , L_115 , V_55 -> V_249 ) ;
F_4 ( V_2 , L_116 , V_55 -> V_260 ) ;
F_4 ( V_2 , L_117 , V_55 -> V_265 ) ;
F_4 ( V_2 , L_118 , V_55 -> V_271 ) ;
F_4 ( V_2 , L_119 , V_55 -> V_272 ) ;
F_4 ( V_2 , L_120 , V_55 -> V_246 ) ;
F_100 ( & V_55 -> V_243 ) ;
F_100 ( & V_55 -> V_277 ) ;
V_8 = F_7 ( V_147 -> V_18 -> V_21 -> V_2 , V_278 ,
( T_1 ) ( V_23 + V_20 ) ,
0 , ( T_1 * ) V_55 , sizeof( * V_55 ) ) ;
if ( V_8 )
F_4 ( V_2 , L_121 ,
V_12 , V_8 ) ;
F_16 ( V_55 ) ;
}
static void F_69 ( struct V_151 * V_152 ,
struct V_17 * V_18 , struct V_237 * V_238 )
{
struct V_44 * V_147 = F_58 ( V_18 ) ;
unsigned int V_241 ;
V_241 = V_152 -> V_204 . V_242 ;
F_4 ( & V_18 -> V_2 , L_122 , V_12 ,
V_152 -> V_204 . V_242 , V_152 -> V_204 . V_279 ) ;
F_4 ( & V_18 -> V_2 , L_123 , V_12 ,
V_238 -> V_242 , V_238 -> V_279 ) ;
if ( V_147 == NULL )
return;
F_96 ( V_152 , V_147 , V_238 ) ;
}
static int F_101 ( struct V_151 * V_152 ,
unsigned int V_280 , unsigned int V_281 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
unsigned int V_139 ;
unsigned long V_223 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
V_139 = V_147 -> V_213 ;
if ( V_280 & V_282 )
V_139 |= V_143 ;
if ( V_280 & V_283 )
V_139 |= V_141 ;
if ( V_280 & V_284 )
V_139 |= V_145 ;
if ( V_281 & V_282 )
V_139 &= ~ V_143 ;
if ( V_281 & V_283 )
V_139 &= ~ V_141 ;
if ( V_281 & V_284 )
V_139 &= ~ V_145 ;
V_147 -> V_213 = V_139 ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
F_44 ( V_147 , V_139 ) ;
return 0 ;
}
static int F_102 ( struct V_151 * V_152 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
unsigned int V_227 = 0 ;
unsigned int V_148 ;
unsigned int V_139 ;
unsigned long V_223 ;
F_77 ( & V_147 -> V_195 , V_223 ) ;
V_148 = V_147 -> V_162 ;
V_139 = V_147 -> V_213 ;
V_227 = ( ( V_139 & V_141 ) ? V_283 : 0 )
| ( ( V_139 & V_143 ) ? V_282 : 0 )
| ( ( V_148 & V_163 ) ? V_285 : 0 )
| ( ( V_148 & V_286 ) ? V_287 : 0 )
| ( ( V_148 & V_288 ) ? V_289 : 0 )
| ( ( V_148 & V_290 ) ? V_291 : 0 ) ;
F_4 ( & V_18 -> V_2 , L_124 , V_12 , V_227 ) ;
F_79 ( & V_147 -> V_195 , V_223 ) ;
return V_227 ;
}
static int F_103 ( struct V_44 * V_147 ,
struct V_292 T_8 * V_293 )
{
struct V_292 V_294 ;
unsigned V_295 ;
if ( ! V_293 )
return - V_296 ;
V_295 = V_147 -> V_18 -> V_18 . V_297 ;
if ( V_295 != V_298 )
V_295 = F_104 ( V_295 ) / 10 ;
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
V_294 . type = V_299 ;
V_294 . line = V_147 -> V_18 -> V_300 ;
V_294 . V_18 = V_147 -> V_18 -> V_20 ;
V_294 . V_301 = 0 ;
V_294 . V_223 = V_302 | V_303 ;
V_294 . V_304 = V_147 -> V_18 -> V_228 ;
V_294 . V_305 = 9600 ;
V_294 . V_306 = 5 * V_307 ;
V_294 . V_297 = V_295 ;
if ( F_105 ( V_293 , & V_294 , sizeof( * V_293 ) ) )
return - V_296 ;
return 0 ;
}
static int F_106 ( struct V_151 * V_152 ,
unsigned int V_308 , unsigned long V_309 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
switch ( V_308 ) {
case V_310 :
F_4 ( & V_18 -> V_2 , L_125 , V_12 ) ;
return F_103 ( V_147 ,
(struct V_292 T_8 * ) V_309 ) ;
}
return - V_311 ;
}
static void F_107 ( struct V_151 * V_152 , int V_312 )
{
struct V_17 * V_18 = V_152 -> V_231 ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
int V_8 ;
int V_313 = 0 ;
if ( V_312 == - 1 )
V_313 = 1 ;
V_8 = F_43 ( V_147 , V_314 , V_313 ) ;
if ( V_8 )
F_4 ( & V_18 -> V_2 , L_126 ,
V_12 , V_8 ) ;
}
static int F_108 ( struct V_107 * V_21 )
{
struct V_33 * V_177 ;
int V_8 ;
V_177 = F_109 ( sizeof( struct V_33 ) , V_38 ) ;
if ( ! V_177 )
return - V_39 ;
F_110 ( & V_177 -> V_214 ) ;
V_177 -> V_21 = V_21 ;
F_111 ( V_21 , V_177 ) ;
V_8 = F_40 ( V_177 ) ;
if ( V_8 ) {
F_16 ( V_177 ) ;
return V_8 ;
}
return 0 ;
}
static void F_112 ( struct V_107 * V_21 )
{
}
static void F_113 ( struct V_107 * V_21 )
{
F_16 ( F_76 ( V_21 ) ) ;
}
static int F_114 ( struct V_17 * V_18 )
{
struct V_44 * V_147 ;
int V_234 ;
V_147 = F_109 ( sizeof( * V_147 ) , V_38 ) ;
if ( ! V_147 )
return - V_39 ;
F_115 ( & V_147 -> V_195 ) ;
V_147 -> V_18 = V_18 ;
V_147 -> V_177 = F_76 ( V_18 -> V_21 ) ;
V_147 -> V_246 = V_315 ;
switch ( V_18 -> V_20 ) {
case 0 :
V_147 -> V_52 = V_316 ;
V_147 -> V_49 = V_317 ;
break;
case 1 :
V_147 -> V_52 = V_318 ;
V_147 -> V_49 = V_319 ;
break;
default:
F_18 ( & V_18 -> V_2 , L_127 ) ;
V_234 = - V_59 ;
goto V_88;
}
F_4 ( & V_18 -> V_2 ,
L_128 ,
V_12 , V_18 -> V_20 , V_147 -> V_52 ,
V_147 -> V_49 ) ;
F_116 ( V_18 , V_147 ) ;
V_234 = F_117 ( V_18 ) ;
if ( V_234 )
goto V_88;
V_18 -> V_18 . V_297 = F_118 ( V_297 * 10 ) ;
V_18 -> V_18 . V_320 = 1 ;
return 0 ;
V_88:
F_16 ( V_147 ) ;
return V_234 ;
}
static int F_119 ( struct V_17 * V_18 )
{
struct V_44 * V_147 ;
V_147 = F_58 ( V_18 ) ;
F_120 ( V_18 ) ;
F_16 ( V_147 ) ;
return 0 ;
}
static T_9 F_121 ( struct V_41 * V_2 ,
struct V_321 * V_322 , char * V_323 )
{
struct V_17 * V_18 = F_122 ( V_2 ) ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
return sprintf ( V_323 , L_61 , V_147 -> V_246 ) ;
}
static T_9 F_123 ( struct V_41 * V_2 ,
struct V_321 * V_322 , const char * V_324 , T_10 V_226 )
{
struct V_17 * V_18 = F_122 ( V_2 ) ;
struct V_44 * V_147 = F_58 ( V_18 ) ;
unsigned int V_325 = F_124 ( V_324 , NULL , 0 ) ;
F_4 ( V_2 , L_129 , V_12 , V_325 ) ;
if ( V_325 < 256 )
V_147 -> V_246 = V_325 ;
else
F_18 ( V_2 , L_130 , V_12 , V_325 ) ;
return V_226 ;
}
static int F_117 ( struct V_17 * V_18 )
{
return F_125 ( & V_18 -> V_2 , & V_326 ) ;
}
static int F_120 ( struct V_17 * V_18 )
{
F_126 ( & V_18 -> V_2 , & V_326 ) ;
return 0 ;
}
