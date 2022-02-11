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
V_29 = F_10 ( ( T_4 ) V_24 ) ;
V_8 = F_1 ( V_2 , V_30 ,
( T_2 ) V_26 ,
V_29 ,
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
V_31 , V_27 ) ;
}
static int F_13 ( struct V_32 * V_21 ,
int V_24 , int V_25 , T_1 * V_27 )
{
int V_8 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_25 ; V_33 ++ ) {
V_8 = F_1 ( V_21 -> V_21 -> V_2 ,
V_30 , V_21 -> V_34 ,
( T_2 ) ( V_24 + V_33 ) , & V_27 [ V_33 ] , 0x01 ) ;
if ( V_8 ) {
F_4 ( & V_21 -> V_21 -> V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
}
F_4 ( & V_21 -> V_21 -> V_2 -> V_2 , L_5 ,
V_12 , V_24 , V_25 ) ;
F_11 ( & V_21 -> V_21 -> V_2 -> V_2 , V_12 , V_25 , V_27 ) ;
V_21 -> V_35 = 1 ;
return V_8 ;
}
static int F_14 ( struct V_32 * V_21 ,
int V_24 , int V_25 , T_1 * V_27 )
{
int V_8 = 0 ;
int V_33 ;
T_3 * V_36 ;
if ( ! V_21 -> V_35 ) {
V_36 = F_15 ( 1 , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_8 = F_13 ( V_21 , 0 , 1 , V_36 ) ;
F_16 ( V_36 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_33 = 0 ; V_33 < V_25 ; ++ V_33 ) {
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_39 , V_27 [ V_33 ] ,
( T_2 ) ( V_33 + V_24 ) , NULL , 0 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( & V_21 -> V_21 -> V_2 -> V_2 , L_6 , V_12 , V_24 , V_25 ) ;
F_11 ( & V_21 -> V_21 -> V_2 -> V_2 , V_12 , V_25 , V_27 ) ;
return V_8 ;
}
static int F_17 ( struct V_32 * V_21 ,
int V_24 , int V_25 , T_1 V_26 , T_1 * V_27 )
{
struct V_40 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_41 ;
T_4 V_29 ;
V_41 = V_42 -
( V_24 & ( V_42 - 1 ) ) ;
if ( V_41 > V_25 )
V_41 = V_25 ;
F_4 ( V_2 , L_7 ,
V_12 , V_24 , V_41 ) ;
F_11 ( V_2 , V_12 , V_41 , V_27 ) ;
V_29 = F_10 ( ( T_4 ) V_24 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_39 , ( T_2 ) V_26 ,
V_29 ,
V_27 , V_41 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_8 , V_12 , V_8 ) ;
return V_8 ;
}
V_25 -= V_41 ;
V_24 += V_41 ;
V_27 += V_41 ;
while ( V_25 ) {
if ( V_25 > V_42 )
V_41 = V_42 ;
else
V_41 = V_25 ;
F_4 ( V_2 , L_9 ,
V_12 , V_24 , V_41 ) ;
F_11 ( V_2 , V_12 , V_41 , V_27 ) ;
V_29 = F_10 ( ( T_4 ) V_24 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 , V_39 ,
( T_2 ) V_26 ,
V_29 ,
V_27 , V_41 ) ;
if ( V_8 ) {
F_18 ( V_2 , L_8 , V_12 , V_8 ) ;
return V_8 ;
}
V_25 -= V_41 ;
V_24 += V_41 ;
V_27 += V_41 ;
}
return V_8 ;
}
static int F_19 ( struct V_43 * V_18 )
{
int V_8 ;
struct V_44 * V_45 ;
T_1 * V_46 ;
int V_47 = 0 ;
V_45 = F_15 ( sizeof( * V_45 ) , V_37 ) ;
if ( ! V_45 )
return - V_38 ;
V_46 = F_15 ( 1 , V_37 ) ;
if ( ! V_46 ) {
F_16 ( V_45 ) ;
return - V_38 ;
}
V_8 = F_12 ( V_18 -> V_18 -> V_21 -> V_2 , V_18 -> V_48 ,
sizeof( * V_45 ) , ( void * ) V_45 ) ;
if ( V_8 )
goto V_49;
F_4 ( & V_18 -> V_18 -> V_2 , L_10 , V_12 , V_45 -> V_50 ) ;
V_8 = F_12 ( V_18 -> V_18 -> V_21 -> V_2 ,
V_18 -> V_51 + V_52 , 1 , V_46 ) ;
if ( V_8 )
goto V_49;
F_4 ( & V_18 -> V_18 -> V_2 , L_11 , V_12 , * V_46 ) ;
if ( ( V_45 -> V_50 & 0x80 ) != 0 )
V_47 += 64 ;
if ( ( * V_46 & V_53 ) == 0 )
V_47 += 1 ;
V_49:
F_4 ( & V_18 -> V_18 -> V_2 , L_12 , V_12 , V_47 ) ;
F_16 ( V_46 ) ;
F_16 ( V_45 ) ;
return V_47 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 , L_13 ,
V_12 , V_2 -> V_54 -> V_55 . V_56 ) ;
F_4 ( & V_2 -> V_2 , L_14 ,
V_12 , V_2 -> V_54 -> V_55 . V_57 * 2 ) ;
if ( V_2 -> V_54 -> V_55 . V_56 != 1 ) {
F_18 ( & V_2 -> V_2 , L_15 , V_12 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_21 ( struct V_32 * V_21 ,
int V_24 , int V_25 , T_1 * V_27 )
{
int V_8 ;
if ( V_21 -> V_59 . V_60 == V_61 ) {
V_8 = F_9 ( V_21 -> V_21 -> V_2 ,
V_24 ,
V_25 ,
V_21 -> V_34 ,
V_27 ) ;
} else {
V_8 = F_13 ( V_21 , V_24 , V_25 ,
V_27 ) ;
}
return V_8 ;
}
static int F_22 ( struct V_32 * V_21 , int V_24 ,
int V_25 , T_1 * V_27 )
{
if ( V_21 -> V_59 . V_60 == V_62 )
return F_14 ( V_21 , V_24 , V_25 ,
V_27 ) ;
if ( V_21 -> V_59 . V_60 == V_61 )
return F_17 ( V_21 , V_24 , V_25 ,
V_21 -> V_34 , V_27 ) ;
return - V_63 ;
}
static int F_23 ( struct V_32 * V_21 ,
int V_64 , struct V_65 * V_66 )
{
int V_24 ;
int V_8 ;
V_24 = 2 ;
do {
V_8 = F_21 ( V_21 ,
V_24 ,
sizeof( struct V_65 ) ,
( T_1 * ) V_66 ) ;
if ( V_8 )
return 0 ;
if ( V_66 -> Type == V_64 )
return V_24 ;
V_24 = V_24 + sizeof( struct V_65 ) +
F_24 ( V_66 -> V_67 ) ;
} while ( ( V_24 < V_68 ) && V_66 -> Type );
return 0 ;
}
static int F_25 ( struct V_65 * V_66 , T_1 * V_27 )
{
T_2 V_33 ;
T_1 V_69 = 0 ;
for ( V_33 = 0 ; V_33 < F_24 ( V_66 -> V_67 ) ; V_33 ++ )
V_69 = ( T_1 ) ( V_69 + V_27 [ V_33 ] ) ;
if ( V_69 != V_66 -> V_70 ) {
F_26 ( L_16 , V_12 , V_66 -> V_70 , V_69 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_27 ( struct V_32 * V_21 )
{
struct V_40 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_65 * V_66 ;
int V_24 = 2 ;
T_1 * V_27 ;
T_2 V_71 ;
V_66 = F_15 ( sizeof( * V_66 ) , V_37 ) ;
if ( ! V_66 )
return - V_38 ;
V_27 = F_15 ( V_68 , V_37 ) ;
if ( ! V_27 ) {
F_16 ( V_66 ) ;
return - V_38 ;
}
V_8 = F_21 ( V_21 , 0 , 1 , V_27 ) ;
if ( V_8 )
goto V_72;
if ( * V_27 != V_73 && * V_27 != V_74 ) {
F_18 ( V_2 , L_17 , V_12 ) ;
V_8 = - V_58 ;
goto V_72;
}
do {
V_8 = F_21 ( V_21 ,
V_24 ,
sizeof( struct V_65 ) ,
( T_1 * ) V_66 ) ;
if ( V_8 )
break;
if ( ( V_24 + sizeof( struct V_65 ) +
F_24 ( V_66 -> V_67 ) ) > V_68 ) {
V_8 = - V_58 ;
F_4 ( V_2 , L_18 , V_12 ) ;
break;
}
F_4 ( V_2 , L_19 , V_12 , V_66 -> Type ) ;
V_71 = V_66 -> Type & 0x0f ;
if ( V_71 != V_75
&& V_71 != V_76 ) {
V_8 = F_21 ( V_21 , V_24 +
sizeof( struct V_65 ) ,
F_24 ( V_66 -> V_67 ) ,
V_27 ) ;
if ( V_8 )
break;
V_8 = F_25 ( V_66 , V_27 ) ;
if ( V_8 )
break;
}
V_24 = V_24 + sizeof( struct V_65 ) +
F_24 ( V_66 -> V_67 ) ;
} while ( ( V_66 -> Type != V_77 ) &&
( V_24 < V_68 ) );
if ( ( V_66 -> Type != V_77 ) ||
( V_24 > V_68 ) )
V_8 = - V_58 ;
V_72:
F_16 ( V_27 ) ;
F_16 ( V_66 ) ;
return V_8 ;
}
static int F_28 ( struct V_32 * V_21 , T_1 * V_27 )
{
int V_8 ;
int V_24 ;
struct V_65 * V_66 ;
struct V_78 * V_55 ;
struct V_40 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
V_66 = F_15 ( sizeof( * V_66 ) , V_37 ) ;
if ( ! V_66 )
return - V_38 ;
V_24 = F_23 ( V_21 , V_77 ,
V_66 ) ;
if ( ! V_24 ) {
F_4 ( V_2 , L_20 , V_12 ) ;
V_8 = - V_58 ;
goto exit;
}
V_8 = F_21 ( V_21 , V_24 + sizeof( struct V_65 ) ,
F_24 ( V_66 -> V_67 ) , V_27 ) ;
if ( V_8 )
goto exit;
V_8 = F_25 ( V_66 , V_27 ) ;
V_55 = (struct V_78 * ) V_27 ;
F_4 ( V_2 , L_21 , V_12 , V_55 -> V_79 ) ;
F_4 ( V_2 , L_22 , V_12 , V_55 -> V_80 ) ;
F_4 ( V_2 , L_23 , V_12 , V_55 -> V_81 ) ;
F_4 ( V_2 , L_24 , V_12 , V_55 -> V_82 ) ;
F_4 ( V_2 , L_25 , V_12 , V_55 -> V_83 ) ;
F_4 ( V_2 , L_26 , V_12 , V_55 -> V_84 ) ;
exit:
F_16 ( V_66 ) ;
return V_8 ;
}
static int F_29 ( T_1 * V_85 , struct V_40 * V_2 )
{
T_1 * V_27 ;
int V_86 ;
int V_33 ;
int V_87 ;
T_1 V_69 = 0 ;
struct V_65 * V_88 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
const struct V_93 * V_94 ;
const char * V_95 = L_27 ;
V_86 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_91 ) ) ;
V_27 = F_15 ( V_86 , V_37 ) ;
if ( ! V_27 )
return - V_38 ;
memset ( V_27 , 0xff , V_86 ) ;
V_87 = F_30 ( & V_94 , V_95 , V_2 ) ;
if ( V_87 ) {
F_18 ( V_2 , L_28 ,
V_95 , V_87 ) ;
F_16 ( V_27 ) ;
return V_87 ;
}
V_96 = V_94 -> V_6 [ 0 ] ;
V_97 = V_94 -> V_6 [ 1 ] ;
V_98 = V_94 -> V_6 [ 2 ] | ( V_94 -> V_6 [ 3 ] << 8 ) ;
V_92 = (struct V_91 * ) V_27 ;
V_92 -> V_99 = V_96 ;
V_92 -> V_100 = V_97 ;
V_90 = (struct V_89 * ) & V_94 -> V_6 [ 4 ] ;
memcpy ( V_27 + sizeof( struct V_91 ) ,
& V_94 -> V_6 [ 4 + sizeof( struct V_89 ) ] ,
F_24 ( V_90 -> V_101 ) ) ;
F_31 ( V_94 ) ;
for ( V_33 = 0 ; V_33 < V_86 ; V_33 ++ ) {
V_69 = ( T_1 ) ( V_69 + V_27 [ V_33 ] ) ;
}
F_16 ( V_27 ) ;
V_88 = (struct V_65 * ) V_85 ;
V_92 = (struct V_91 * ) V_88 -> V_102 ;
V_88 -> Type = V_103 ;
V_88 -> V_67 = F_32 ( V_86 ) ;
V_88 -> V_70 = V_69 ;
V_92 -> V_99 = V_96 ;
V_92 -> V_100 = V_97 ;
return 0 ;
}
static int F_33 ( struct V_32 * V_21 )
{
struct V_40 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 ;
T_3 * V_6 ;
V_6 = F_15 ( 1 , V_37 ) ;
if ( ! V_6 )
return - V_38 ;
V_8 = F_1 ( V_21 -> V_21 -> V_2 , V_30 ,
V_104 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_29 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_30 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_73 || * V_6 == V_74 ) ) {
F_4 ( V_2 , L_31 , V_12 ) ;
V_21 -> V_34 = V_104 ;
goto V_72;
}
V_8 = F_1 ( V_21 -> V_21 -> V_2 , V_30 ,
V_105 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_32 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_30 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_73 || * V_6 == V_74 ) ) {
F_4 ( V_2 , L_33 , V_12 ) ;
V_21 -> V_34 = V_105 ;
goto V_72;
}
F_4 ( V_2 , L_34 , V_12 ) ;
V_21 -> V_34 = V_104 ;
V_8 = - V_58 ;
V_72:
F_16 ( V_6 ) ;
return V_8 ;
}
static int F_34 ( struct V_106 * V_21 , void * V_27 ,
int V_25 , int * V_107 )
{
int V_8 ;
V_8 = F_35 ( V_21 -> V_2 ,
F_36 ( V_21 -> V_2 ,
V_21 -> V_18 [ 0 ] -> V_108 ) ,
V_27 , V_25 , V_107 , 1000 ) ;
return V_8 ;
}
static int F_37 ( struct V_32 * V_21 , T_1 * V_109 ,
int V_110 )
{
int V_8 = 0 ;
int V_111 ;
int V_112 ;
int V_113 ;
for ( V_111 = 0 ; V_111 < V_110 ; ) {
V_112 = V_110 - V_111 ;
if ( V_112 > V_114 )
V_112 = V_114 ;
V_8 = F_34 ( V_21 -> V_21 , & V_109 [ V_111 ] ,
V_112 , & V_113 ) ;
if ( V_8 )
break;
V_111 += V_113 ;
}
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_39 ( struct V_78 * V_55 )
{
return F_40 ( V_55 -> V_81 ) ;
}
static int F_41 ( struct V_32 * V_21 )
{
struct V_40 * V_2 = & V_21 -> V_21 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_24 ;
struct V_78 * V_115 ;
struct V_116 * V_117 ;
int V_118 ;
int V_119 ;
V_21 -> V_59 . V_120 = V_121 ;
V_21 -> V_34 = V_104 ;
V_8 = F_20 ( V_21 -> V_21 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_117 = & V_21 -> V_21 -> V_117 -> V_122 -> V_55 ;
if ( ! V_117 ) {
F_18 ( V_2 , L_35 , V_12 ) ;
return - V_58 ;
}
if ( V_117 -> V_123 > 1 )
V_21 -> V_59 . V_60 = V_61 ;
else
V_21 -> V_59 . V_60 = V_124 ;
if ( V_21 -> V_59 . V_60 == V_61 ) {
struct V_65 * V_66 ;
F_4 ( V_2 , L_36 , V_12 ) ;
V_8 = F_27 ( V_21 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_37 , V_12 ) ;
return V_8 ;
}
V_115 = F_15 ( sizeof( * V_115 ) , V_37 ) ;
if ( ! V_115 )
return - V_38 ;
V_8 = F_28 ( V_21 , ( T_1 * ) V_115 ) ;
if ( V_8 ) {
F_16 ( V_115 ) ;
return V_8 ;
}
if ( ! V_125 && F_39 ( V_115 ) < 2 ) {
F_4 ( V_2 , L_38 ,
V_12 , F_39 ( V_115 ) ) ;
F_16 ( V_115 ) ;
return - V_63 ;
}
V_66 = F_15 ( sizeof( * V_66 ) , V_37 ) ;
if ( ! V_66 ) {
F_16 ( V_115 ) ;
return - V_38 ;
}
V_24 = F_23 ( V_21 ,
V_75 , V_66 ) ;
if ( V_24 != 0 ) {
struct V_91 * V_126 ;
T_3 * V_127 ;
F_4 ( V_2 , L_39 , V_12 ) ;
V_126 = F_15 ( sizeof( * V_126 ) ,
V_37 ) ;
if ( ! V_126 ) {
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_38 ;
}
V_8 = F_21 ( V_21 , V_24 +
sizeof( struct V_65 ) ,
sizeof( struct V_91 ) ,
( T_1 * ) V_126 ) ;
if ( V_8 ) {
F_16 ( V_126 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return V_8 ;
}
V_118 = ( V_126 -> V_99 << 8 ) +
( V_126 -> V_100 ) ;
V_119 = ( V_96 << 8 ) +
( V_97 ) ;
F_4 ( V_2 , L_40 ,
V_12 , V_126 -> V_99 ,
V_126 -> V_100 ,
V_96 ,
V_97 ) ;
if ( V_118 < V_119 ) {
F_4 ( V_2 , L_41 ,
V_12 ,
V_126 -> V_99 ,
V_126 -> V_100 ,
V_96 ,
V_97 ) ;
V_127 = F_15 ( 1 , V_37 ) ;
if ( ! V_127 ) {
F_16 ( V_126 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_38 ;
}
* V_127 = V_103 ;
V_8 = F_22 ( V_21 , V_24 ,
sizeof( * V_127 ) , V_127 ) ;
if ( V_8 ) {
F_16 ( V_127 ) ;
F_16 ( V_126 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return V_8 ;
}
V_8 = F_21 ( V_21 ,
V_24 ,
sizeof( * V_127 ) ,
V_127 ) ;
if ( V_8 ) {
F_16 ( V_127 ) ;
F_16 ( V_126 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return V_8 ;
}
if ( * V_127 != V_103 ) {
F_18 ( V_2 , L_42 , V_12 ) ;
F_16 ( V_127 ) ;
F_16 ( V_126 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_58 ;
}
F_4 ( V_2 , L_43 , V_12 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_128 ,
0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_44 , V_12 , V_8 ) ;
F_16 ( V_127 ) ;
F_16 ( V_126 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_58 ;
}
F_16 ( V_126 ) ;
}
else if ( ( V_24 = F_23 ( V_21 , V_103 , V_66 ) ) != 0 ) {
#define F_42 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_85 ;
T_1 * V_129 ;
V_85 = F_15 ( F_42 , V_37 ) ;
if ( ! V_85 ) {
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_38 ;
}
V_129 = F_15 ( F_42 , V_37 ) ;
if ( ! V_129 ) {
F_16 ( V_85 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_38 ;
}
F_4 ( V_2 , L_45 , V_12 ) ;
V_8 = F_29 ( V_85 , V_2 ) ;
if ( V_8 ) {
F_16 ( V_129 ) ;
F_16 ( V_85 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_63 ;
}
V_8 = F_22 ( V_21 ,
V_24 ,
F_42 ,
V_85 ) ;
if ( V_8 ) {
F_16 ( V_129 ) ;
F_16 ( V_85 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_63 ;
}
V_8 = F_21 ( V_21 , V_24 ,
F_42 , V_129 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_46 , V_12 ) ;
F_16 ( V_129 ) ;
F_16 ( V_85 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return V_8 ;
}
if ( memcmp ( V_129 , V_85 , F_42 ) ) {
F_4 ( V_2 , L_47 , V_12 ) ;
F_16 ( V_129 ) ;
F_16 ( V_85 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return - V_63 ;
}
F_16 ( V_129 ) ;
F_16 ( V_85 ) ;
F_4 ( V_2 , L_48 , V_12 ) ;
V_8 = F_5 ( V_21 -> V_21 -> V_2 ,
V_130 , 0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_49 , V_12 , V_8 ) ;
if ( V_8 ) {
F_18 ( V_2 ,
L_50 ,
V_12 ) ;
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return V_8 ;
}
}
F_16 ( V_66 ) ;
F_16 ( V_115 ) ;
return 0 ;
}
F_4 ( V_2 , L_51 , V_12 ) ;
V_8 = F_38 ( V_21 -> V_21 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_24 ( V_21 -> V_21 -> V_2 -> V_131 . V_132 )
!= V_133 ) {
F_4 ( V_2 , L_52 , V_12 ,
F_24 ( V_21 -> V_21 -> V_2 -> V_131 . V_132 ) ) ;
V_21 -> V_34 = V_104 ;
goto V_134;
}
if ( F_33 ( V_21 ) )
goto V_134;
if ( ! F_27 ( V_21 ) ) {
struct V_89 * V_85 ;
int V_33 ;
T_1 V_69 = 0 ;
T_1 * V_27 ;
int V_86 ;
int V_87 ;
const struct V_93 * V_94 ;
const char * V_95 = L_27 ;
V_115 = F_15 ( sizeof( * V_115 ) , V_37 ) ;
if ( ! V_115 )
return - V_38 ;
V_8 = F_28 ( V_21 , ( T_1 * ) V_115 ) ;
if ( V_8 ) {
F_16 ( V_115 ) ;
goto V_134;
}
if ( ! V_125 && F_39 ( V_115 ) < 2 ) {
F_4 ( V_2 , L_38 ,
V_12 , F_39 ( V_115 ) ) ;
F_16 ( V_115 ) ;
goto V_134;
}
F_16 ( V_115 ) ;
V_86 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_89 ) ) ;
V_27 = F_15 ( V_86 , V_37 ) ;
if ( ! V_27 )
return - V_38 ;
memset ( V_27 , 0xff , V_86 ) ;
V_87 = F_30 ( & V_94 , V_95 , V_2 ) ;
if ( V_87 ) {
F_18 ( V_2 , L_28 ,
V_95 , V_87 ) ;
F_16 ( V_27 ) ;
return V_87 ;
}
memcpy ( V_27 , & V_94 -> V_6 [ 4 ] , V_94 -> V_7 - 4 ) ;
F_31 ( V_94 ) ;
for ( V_33 = sizeof( struct V_89 ) ;
V_33 < V_86 ; V_33 ++ ) {
V_69 = ( T_1 ) ( V_69 + V_27 [ V_33 ] ) ;
}
V_85 = (struct V_89 * ) V_27 ;
V_85 -> V_101 = F_32 ( ( T_2 ) ( V_86 -
sizeof( struct V_89 ) ) ) ;
V_85 -> V_70 = V_69 ;
F_4 ( V_2 , L_53 , V_12 ) ;
V_8 = F_37 ( V_21 , V_27 , V_86 ) ;
F_16 ( V_27 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_54 , V_12 ) ;
return V_8 ;
}
V_21 -> V_59 . V_60 = V_135 ;
F_4 ( V_2 , L_55 , V_12 ) ;
return - V_58 ;
}
V_134:
F_4 ( V_2 , L_56 , V_12 ) ;
V_21 -> V_59 . V_60 = V_62 ;
return 0 ;
}
static int F_43 ( struct V_43 * V_18 , int V_136 , int V_137 )
{
int V_20 = V_18 -> V_18 -> V_20 ;
V_137 = ! ! V_137 ;
return F_7 ( V_18 -> V_18 -> V_21 -> V_2 ,
V_136 , ( T_1 ) ( V_23 + V_20 ) ,
V_137 , NULL , 0 ) ;
}
static int F_44 ( struct V_43 * V_18 , T_1 V_138 )
{
int V_8 = 0 ;
F_4 ( & V_18 -> V_18 -> V_2 , L_57 , V_12 , V_138 ) ;
V_8 = F_43 ( V_18 , V_139 , V_138 & V_140 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_43 ( V_18 , V_141 , V_138 & V_142 ) ;
if ( V_8 )
return V_8 ;
return F_43 ( V_18 , V_143 , V_138 & V_144 ) ;
}
static T_1 F_45 ( T_1 V_145 )
{
T_1 V_46 = 0 ;
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
return V_46 ;
}
static void F_47 ( struct V_43 * V_146 , T_1 V_147 )
{
struct V_148 * V_149 ;
struct V_150 * V_151 ;
F_4 ( & V_146 -> V_18 -> V_2 , L_58 , V_12 , V_147 ) ;
if ( V_147 & ( V_152 | V_153 |
V_154 | V_155 ) ) {
V_149 = & V_146 -> V_18 -> V_149 ;
if ( V_147 & V_152 )
V_149 -> V_156 ++ ;
if ( V_147 & V_153 )
V_149 -> V_157 ++ ;
if ( V_147 & V_155 )
V_149 -> V_158 ++ ;
if ( V_147 & V_154 )
V_149 -> V_159 ++ ;
F_48 ( & V_146 -> V_18 -> V_18 . V_160 ) ;
}
V_146 -> V_161 = V_147 & 0xf0 ;
V_151 = F_49 ( & V_146 -> V_18 -> V_18 ) ;
if ( V_151 && F_50 ( V_151 ) ) {
if ( V_147 & V_162 ) {
V_151 -> V_163 = 0 ;
F_51 ( V_151 ) ;
} else {
V_151 -> V_163 = 1 ;
}
}
F_52 ( V_151 ) ;
}
static void F_53 ( struct V_43 * V_146 , int V_164 ,
T_1 V_46 , T_1 V_6 )
{
struct V_148 * V_149 ;
T_1 V_165 = ( T_1 ) ( V_46 & ( T_1 ) ( V_166 | V_167 |
V_168 | V_169 ) ) ;
F_4 ( & V_146 -> V_18 -> V_2 , L_58 , V_12 , V_165 ) ;
V_146 -> V_170 = V_46 ;
if ( V_165 & V_169 )
V_165 &= ( T_1 ) ( V_166 | V_169 ) ;
if ( V_164 )
F_54 ( V_146 -> V_18 , & V_6 , 1 ) ;
V_149 = & V_146 -> V_18 -> V_149 ;
if ( V_165 & V_169 )
V_149 -> V_171 ++ ;
if ( V_165 & V_166 )
V_149 -> V_172 ++ ;
if ( V_165 & V_167 )
V_149 -> V_173 ++ ;
if ( V_165 & V_168 )
V_149 -> V_174 ++ ;
}
static void F_55 ( struct V_175 * V_175 )
{
struct V_32 * V_176 = V_175 -> V_177 ;
struct V_17 * V_18 ;
struct V_43 * V_146 ;
struct V_40 * V_2 ;
unsigned char * V_6 = V_175 -> V_178 ;
int V_25 = V_175 -> V_179 ;
int V_20 ;
int V_180 ;
int V_181 ;
T_1 V_46 ;
T_1 V_147 ;
int V_8 = V_175 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_182 :
case - V_183 :
case - V_184 :
F_4 ( & V_175 -> V_2 -> V_2 , L_59 ,
V_12 , V_8 ) ;
return;
default:
F_18 ( & V_175 -> V_2 -> V_2 , L_60
L_61 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_25 ) {
F_4 ( & V_175 -> V_2 -> V_2 , L_62 , V_12 ) ;
goto exit;
}
V_2 = & V_176 -> V_21 -> V_2 -> V_2 ;
F_11 ( V_2 , V_12 , V_25 , V_6 ) ;
if ( V_25 != 2 ) {
F_4 ( V_2 , L_63 , V_12 , V_25 ) ;
goto exit;
}
V_20 = F_56 ( V_6 [ 0 ] ) ;
V_180 = F_57 ( V_6 [ 0 ] ) ;
F_4 ( V_2 , L_64 , V_12 ,
V_20 , V_180 , V_6 [ 1 ] ) ;
V_18 = V_176 -> V_21 -> V_18 [ V_20 ] ;
V_146 = F_58 ( V_18 ) ;
if ( ! V_146 ) {
F_4 ( V_2 , L_65 , V_12 ) ;
return;
}
switch ( V_180 ) {
case V_185 :
V_46 = F_45 ( V_6 [ 1 ] ) ;
if ( V_46 & V_186 ) {
F_4 ( V_2 , L_66 ,
V_12 , V_20 , V_46 ) ;
V_146 -> V_187 = 1 ;
V_146 -> V_188 = V_46 ;
} else {
F_4 ( V_2 , L_67 ,
V_12 , V_20 , V_46 ) ;
F_53 ( V_146 , 0 , V_46 , 0 ) ;
}
break;
case V_189 :
V_147 = V_6 [ 1 ] ;
F_4 ( V_2 , L_68 ,
V_12 , V_20 , V_147 ) ;
F_47 ( V_146 , V_147 ) ;
break;
default:
F_18 ( & V_175 -> V_2 -> V_2 ,
L_69 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_181 = F_59 ( V_175 , V_190 ) ;
if ( V_181 )
F_18 ( & V_175 -> V_2 -> V_2 ,
L_70 ,
V_12 , V_181 ) ;
}
static void F_60 ( struct V_175 * V_175 )
{
struct V_43 * V_146 = V_175 -> V_177 ;
struct V_40 * V_2 = & V_146 -> V_18 -> V_2 ;
unsigned char * V_6 = V_175 -> V_178 ;
int V_181 = 0 ;
int V_20 ;
int V_8 = V_175 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_182 :
case - V_183 :
case - V_184 :
F_4 ( & V_175 -> V_2 -> V_2 , L_59 , V_12 , V_8 ) ;
return;
default:
F_18 ( & V_175 -> V_2 -> V_2 , L_71 , V_12 , V_8 ) ;
}
if ( V_8 == - V_191 )
goto exit;
if ( V_8 ) {
F_18 ( & V_175 -> V_2 -> V_2 , L_72 , V_12 ) ;
return;
}
V_20 = V_146 -> V_18 -> V_20 ;
if ( V_146 -> V_187 ) {
V_146 -> V_187 = 0 ;
F_4 ( V_2 , L_73 ,
V_12 , V_20 , V_146 -> V_188 , * V_6 ) ;
F_53 ( V_146 , 1 , V_146 -> V_188 , * V_6 ) ;
-- V_175 -> V_179 ;
++ V_6 ;
}
if ( V_175 -> V_179 ) {
F_11 ( V_2 , V_12 , V_175 -> V_179 , V_6 ) ;
if ( V_146 -> V_192 )
F_4 ( V_2 , L_74 ,
V_12 ) ;
else
F_54 ( V_146 -> V_18 , V_6 ,
V_175 -> V_179 ) ;
V_146 -> V_18 -> V_149 . V_193 += V_175 -> V_179 ;
}
exit:
F_61 ( & V_146 -> V_194 ) ;
if ( V_146 -> V_195 == V_196 )
V_181 = F_59 ( V_175 , V_190 ) ;
else if ( V_146 -> V_195 == V_197 )
V_146 -> V_195 = V_198 ;
F_62 ( & V_146 -> V_194 ) ;
if ( V_181 )
F_18 ( V_2 , L_70 , V_12 , V_181 ) ;
}
static void F_54 ( struct V_17 * V_18 , unsigned char * V_6 ,
int V_25 )
{
int V_199 ;
V_199 = F_63 ( & V_18 -> V_18 , V_6 , V_25 ) ;
if ( V_199 < V_25 )
F_18 ( & V_18 -> V_2 , L_75 ,
V_12 , V_25 - V_199 ) ;
F_64 ( & V_18 -> V_18 ) ;
}
static void F_65 ( struct V_175 * V_175 )
{
struct V_17 * V_18 = V_175 -> V_177 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_8 = V_175 -> V_8 ;
struct V_150 * V_151 ;
V_146 -> V_200 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_182 :
case - V_183 :
case - V_184 :
F_4 ( & V_175 -> V_2 -> V_2 , L_59 ,
V_12 , V_8 ) ;
return;
default:
F_66 ( V_18 , L_76
L_77 , V_12 , V_8 ) ;
}
V_151 = F_49 ( & V_18 -> V_18 ) ;
F_67 ( V_18 , V_151 ) ;
F_52 ( V_151 ) ;
}
static int F_68 ( struct V_150 * V_151 , struct V_17 * V_18 )
{
struct V_43 * V_146 = F_58 ( V_18 ) ;
struct V_32 * V_176 ;
struct V_1 * V_2 ;
struct V_175 * V_175 ;
int V_20 ;
int V_8 ;
T_4 V_201 ;
T_3 V_202 ;
if ( V_146 == NULL )
return - V_58 ;
V_20 = V_18 -> V_20 ;
V_2 = V_18 -> V_21 -> V_2 ;
V_8 = F_43 ( V_146 , V_143 , 0 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_78 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_151 )
F_69 ( V_151 , V_18 , & V_151 -> V_203 ) ;
V_202 = 2 ;
V_146 -> V_204 =
F_70 ( 20 , ( ( V_202 * 3 ) / 2 ) ) ;
V_201 = ( T_3 ) ( V_205 |
V_206 |
( V_202 << 2 ) ) ;
F_4 ( & V_18 -> V_2 , L_79 , V_12 ) ;
V_8 = F_7 ( V_2 , V_207 ,
( T_3 ) ( V_23 + V_20 ) , V_201 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 , L_80 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_208 ,
( T_3 ) ( V_23 + V_20 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 , L_81 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_18 , V_209 | V_210 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_82 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_211 , 0 ,
( T_2 ) ( V_23 + V_20 ) ,
& V_146 -> V_161 , 1 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 , L_83 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( & V_18 -> V_2 , L_84 , V_146 -> V_161 ) ;
V_146 -> V_212 = V_142 | V_140 ;
F_4 ( & V_18 -> V_2 , L_85 , V_146 -> V_212 ) ;
V_176 = V_146 -> V_176 ;
if ( F_71 ( & V_176 -> V_213 ) )
return - V_214 ;
if ( V_176 -> V_215 == 0 ) {
V_175 = V_176 -> V_21 -> V_18 [ 0 ] -> V_216 ;
if ( ! V_175 ) {
F_18 ( & V_18 -> V_2 ,
L_86 ,
V_12 ) ;
V_8 = - V_63 ;
goto V_217;
}
V_175 -> V_177 = V_176 ;
V_8 = F_59 ( V_175 , V_37 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_87 ,
V_12 , V_8 ) ;
goto V_217;
}
}
F_72 ( V_2 , V_18 -> V_218 -> V_219 ) ;
F_72 ( V_2 , V_18 -> V_220 -> V_219 ) ;
V_175 = V_18 -> V_220 ;
if ( ! V_175 ) {
F_18 ( & V_18 -> V_2 , L_88 ,
V_12 ) ;
V_8 = - V_63 ;
goto V_221;
}
V_146 -> V_195 = V_196 ;
V_175 -> V_177 = V_146 ;
V_8 = F_59 ( V_175 , V_37 ) ;
if ( V_8 ) {
F_18 ( & V_18 -> V_2 ,
L_89 ,
V_12 , V_8 ) ;
goto V_221;
}
++ V_176 -> V_215 ;
goto V_217;
V_221:
if ( V_146 -> V_176 -> V_215 == 0 )
F_73 ( V_18 -> V_21 -> V_18 [ 0 ] -> V_216 ) ;
V_217:
F_74 ( & V_176 -> V_213 ) ;
return V_8 ;
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_32 * V_176 ;
struct V_43 * V_146 ;
struct V_106 * V_21 = V_18 -> V_21 ;
unsigned long V_222 ;
int V_20 ;
V_176 = F_76 ( V_18 -> V_21 ) ;
V_146 = F_58 ( V_18 ) ;
if ( V_176 == NULL || V_146 == NULL )
return;
V_146 -> V_192 = 1 ;
F_73 ( V_18 -> V_220 ) ;
F_73 ( V_18 -> V_218 ) ;
V_146 -> V_200 = 0 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
F_78 ( & V_18 -> V_223 ) ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
F_4 ( & V_18 -> V_2 , L_90 , V_12 ) ;
V_20 = V_18 -> V_20 ;
F_7 ( V_21 -> V_2 , V_224 ,
( T_1 ) ( V_23 + V_20 ) , 0 , NULL , 0 ) ;
F_80 ( & V_176 -> V_213 ) ;
-- V_146 -> V_176 -> V_215 ;
if ( V_146 -> V_176 -> V_215 <= 0 ) {
F_73 ( V_18 -> V_21 -> V_18 [ 0 ] -> V_216 ) ;
V_146 -> V_176 -> V_215 = 0 ;
}
F_74 ( & V_176 -> V_213 ) ;
V_146 -> V_192 = 0 ;
}
static int F_81 ( struct V_150 * V_151 , struct V_17 * V_18 ,
const unsigned char * V_6 , int V_225 )
{
struct V_43 * V_146 = F_58 ( V_18 ) ;
if ( V_225 == 0 ) {
F_4 ( & V_18 -> V_2 , L_91 , V_12 ) ;
return 0 ;
}
if ( V_146 == NULL )
return - V_58 ;
if ( V_146 -> V_192 == 1 )
return - V_58 ;
V_225 = F_82 ( & V_18 -> V_223 , V_6 , V_225 ,
& V_146 -> V_194 ) ;
F_67 ( V_18 , V_151 ) ;
return V_225 ;
}
static void F_67 ( struct V_17 * V_18 , struct V_150 * V_151 )
{
int V_225 , V_226 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
unsigned long V_222 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
if ( V_146 -> V_200 ) {
F_79 ( & V_146 -> V_194 , V_222 ) ;
return;
}
V_225 = F_83 ( & V_18 -> V_223 ,
V_18 -> V_218 -> V_178 ,
V_18 -> V_227 ) ;
if ( V_225 == 0 ) {
F_79 ( & V_146 -> V_194 , V_222 ) ;
return;
}
V_146 -> V_200 = 1 ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
F_11 ( & V_18 -> V_2 , V_12 , V_225 , V_18 -> V_218 -> V_178 ) ;
V_18 -> V_218 -> V_228 = V_225 ;
V_226 = F_59 ( V_18 -> V_218 , V_190 ) ;
if ( V_226 ) {
F_66 ( V_18 ,
L_92 ,
V_12 , V_226 ) ;
V_146 -> V_200 = 0 ;
} else
V_146 -> V_18 -> V_149 . V_229 += V_225 ;
if ( V_151 )
F_51 ( V_151 ) ;
}
static int F_84 ( struct V_150 * V_151 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_231 = 0 ;
unsigned long V_222 ;
if ( V_146 == NULL )
return 0 ;
if ( V_146 -> V_192 == 1 )
return 0 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
V_231 = F_85 ( & V_18 -> V_223 ) ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
F_4 ( & V_18 -> V_2 , L_93 , V_12 , V_231 ) ;
return V_231 ;
}
static int F_86 ( struct V_150 * V_151 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_232 = 0 ;
unsigned long V_222 ;
if ( V_146 == NULL )
return 0 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
V_232 = F_87 ( & V_18 -> V_223 ) ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
F_4 ( & V_18 -> V_2 , L_93 , V_12 , V_232 ) ;
return V_232 ;
}
static bool F_88 ( struct V_17 * V_18 )
{
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_233 ;
V_233 = F_19 ( V_146 ) ;
if ( V_233 > 0 )
return false ;
return true ;
}
static void F_89 ( struct V_150 * V_151 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_8 ;
if ( V_146 == NULL )
return;
if ( F_90 ( V_151 ) ) {
unsigned char V_234 = F_91 ( V_151 ) ;
V_8 = F_81 ( V_151 , V_18 , & V_234 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_18 -> V_2 , L_94 , V_12 , V_8 ) ;
}
}
if ( F_50 ( V_151 ) )
F_92 ( V_146 ) ;
}
static void F_93 ( struct V_150 * V_151 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_8 ;
if ( V_146 == NULL )
return;
if ( F_90 ( V_151 ) ) {
unsigned char V_235 = F_94 ( V_151 ) ;
V_8 = F_81 ( V_151 , V_18 , & V_235 , 1 ) ;
if ( V_8 <= 0 ) {
F_18 ( & V_18 -> V_2 , L_95 , V_12 , V_8 ) ;
}
}
if ( F_50 ( V_151 ) ) {
V_8 = F_95 ( V_146 ) ;
if ( V_8 )
F_18 ( & V_18 -> V_2 ,
L_96 ,
V_12 , V_8 ) ;
}
}
static void F_92 ( struct V_43 * V_146 )
{
unsigned long V_222 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
if ( V_146 -> V_195 == V_196 )
V_146 -> V_195 = V_197 ;
V_146 -> V_212 &= ~ V_142 ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
}
static int F_95 ( struct V_43 * V_146 )
{
struct V_175 * V_175 ;
int V_8 = 0 ;
unsigned long V_222 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
if ( V_146 -> V_195 == V_198 ) {
V_175 = V_146 -> V_18 -> V_220 ;
V_8 = F_59 ( V_175 , V_190 ) ;
}
V_146 -> V_195 = V_196 ;
V_146 -> V_212 |= V_142 ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
return V_8 ;
}
static void F_96 ( struct V_150 * V_151 ,
struct V_43 * V_146 , struct V_236 * V_237 )
{
struct V_40 * V_2 = & V_146 -> V_18 -> V_2 ;
struct V_238 * V_54 ;
int V_239 ;
unsigned V_240 ;
int V_8 ;
int V_20 = V_146 -> V_18 -> V_20 ;
V_54 = F_15 ( sizeof ( * V_54 ) , V_37 ) ;
if ( ! V_54 ) {
V_151 -> V_203 = * V_237 ;
return;
}
V_240 = V_151 -> V_203 . V_241 ;
V_54 -> V_242 = 0 ;
V_54 -> V_242 |= V_243 ;
V_54 -> V_242 |= V_244 ;
V_54 -> V_245 = ( T_1 ) ( V_146 -> V_245 ) ;
switch ( V_240 & V_246 ) {
case V_247 :
V_54 -> V_248 = V_249 ;
F_4 ( V_2 , L_97 , V_12 ) ;
break;
case V_250 :
V_54 -> V_248 = V_251 ;
F_4 ( V_2 , L_98 , V_12 ) ;
break;
case V_252 :
V_54 -> V_248 = V_253 ;
F_4 ( V_2 , L_99 , V_12 ) ;
break;
default:
case V_254 :
V_54 -> V_248 = V_255 ;
F_4 ( V_2 , L_100 , V_12 ) ;
break;
}
if ( V_240 & V_256 ) {
if ( V_240 & V_257 ) {
V_54 -> V_242 |= V_258 ;
V_54 -> V_259 = V_260 ;
F_4 ( V_2 , L_101 , V_12 ) ;
} else {
V_54 -> V_242 |= V_258 ;
V_54 -> V_259 = V_261 ;
F_4 ( V_2 , L_102 , V_12 ) ;
}
} else {
V_54 -> V_259 = V_262 ;
F_4 ( V_2 , L_103 , V_12 ) ;
}
if ( V_240 & V_263 ) {
V_54 -> V_264 = V_265 ;
F_4 ( V_2 , L_104 , V_12 ) ;
} else {
V_54 -> V_264 = V_266 ;
F_4 ( V_2 , L_105 , V_12 ) ;
}
if ( V_240 & V_267 ) {
V_54 -> V_242 |= V_268 ;
V_54 -> V_242 |= V_269 ;
F_4 ( V_2 , L_106 , V_12 ) ;
} else {
F_4 ( V_2 , L_107 , V_12 ) ;
V_151 -> V_163 = 0 ;
F_95 ( V_146 ) ;
}
V_54 -> V_270 = F_94 ( V_151 ) ;
V_54 -> V_271 = F_91 ( V_151 ) ;
if ( F_90 ( V_151 ) ) {
V_54 -> V_242 |= V_272 ;
F_4 ( V_2 , L_108 ,
V_12 , V_54 -> V_270 , V_54 -> V_271 ) ;
} else
F_4 ( V_2 , L_109 , V_12 ) ;
if ( F_97 ( V_151 ) ) {
V_54 -> V_242 |= V_273 ;
F_4 ( V_2 , L_110 ,
V_12 , V_54 -> V_270 , V_54 -> V_271 ) ;
} else
F_4 ( V_2 , L_111 , V_12 ) ;
V_151 -> V_203 . V_241 &= ~ V_274 ;
V_239 = F_98 ( V_151 ) ;
if ( ! V_239 ) {
V_239 = 9600 ;
} else
F_99 ( V_151 , V_239 , V_239 ) ;
V_146 -> V_275 = V_239 ;
V_54 -> V_276 = ( T_2 ) ( ( 461550L + V_239 / 2 ) / V_239 ) ;
F_4 ( V_2 , L_112 , V_12 , V_239 , V_54 -> V_276 ) ;
F_4 ( V_2 , L_113 , ( int ) ( 461550L / V_54 -> V_276 ) ) ;
F_4 ( V_2 , L_114 , V_54 -> V_242 ) ;
F_4 ( V_2 , L_115 , V_54 -> V_248 ) ;
F_4 ( V_2 , L_116 , V_54 -> V_259 ) ;
F_4 ( V_2 , L_117 , V_54 -> V_264 ) ;
F_4 ( V_2 , L_118 , V_54 -> V_270 ) ;
F_4 ( V_2 , L_119 , V_54 -> V_271 ) ;
F_4 ( V_2 , L_120 , V_54 -> V_245 ) ;
F_100 ( & V_54 -> V_242 ) ;
F_100 ( & V_54 -> V_276 ) ;
V_8 = F_7 ( V_146 -> V_18 -> V_21 -> V_2 , V_277 ,
( T_1 ) ( V_23 + V_20 ) ,
0 , ( T_1 * ) V_54 , sizeof( * V_54 ) ) ;
if ( V_8 )
F_4 ( V_2 , L_121 ,
V_12 , V_8 ) ;
F_16 ( V_54 ) ;
}
static void F_69 ( struct V_150 * V_151 ,
struct V_17 * V_18 , struct V_236 * V_237 )
{
struct V_43 * V_146 = F_58 ( V_18 ) ;
unsigned int V_240 ;
V_240 = V_151 -> V_203 . V_241 ;
F_4 ( & V_18 -> V_2 , L_122 , V_12 ,
V_151 -> V_203 . V_241 , V_151 -> V_203 . V_278 ) ;
F_4 ( & V_18 -> V_2 , L_123 , V_12 ,
V_237 -> V_241 , V_237 -> V_278 ) ;
if ( V_146 == NULL )
return;
F_96 ( V_151 , V_146 , V_237 ) ;
}
static int F_101 ( struct V_150 * V_151 ,
unsigned int V_279 , unsigned int V_280 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
unsigned int V_138 ;
unsigned long V_222 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
V_138 = V_146 -> V_212 ;
if ( V_279 & V_281 )
V_138 |= V_142 ;
if ( V_279 & V_282 )
V_138 |= V_140 ;
if ( V_279 & V_283 )
V_138 |= V_144 ;
if ( V_280 & V_281 )
V_138 &= ~ V_142 ;
if ( V_280 & V_282 )
V_138 &= ~ V_140 ;
if ( V_280 & V_283 )
V_138 &= ~ V_144 ;
V_146 -> V_212 = V_138 ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
F_44 ( V_146 , V_138 ) ;
return 0 ;
}
static int F_102 ( struct V_150 * V_151 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
unsigned int V_226 = 0 ;
unsigned int V_147 ;
unsigned int V_138 ;
unsigned long V_222 ;
F_77 ( & V_146 -> V_194 , V_222 ) ;
V_147 = V_146 -> V_161 ;
V_138 = V_146 -> V_212 ;
V_226 = ( ( V_138 & V_140 ) ? V_282 : 0 )
| ( ( V_138 & V_142 ) ? V_281 : 0 )
| ( ( V_147 & V_162 ) ? V_284 : 0 )
| ( ( V_147 & V_285 ) ? V_286 : 0 )
| ( ( V_147 & V_287 ) ? V_288 : 0 )
| ( ( V_147 & V_289 ) ? V_290 : 0 ) ;
F_4 ( & V_18 -> V_2 , L_124 , V_12 , V_226 ) ;
F_79 ( & V_146 -> V_194 , V_222 ) ;
return V_226 ;
}
static int F_103 ( struct V_43 * V_146 ,
struct V_291 T_7 * V_292 )
{
struct V_291 V_293 ;
unsigned V_294 ;
if ( ! V_292 )
return - V_295 ;
V_294 = V_146 -> V_18 -> V_18 . V_296 ;
if ( V_294 != V_297 )
V_294 = F_104 ( V_294 ) / 10 ;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
V_293 . type = V_298 ;
V_293 . line = V_146 -> V_18 -> V_299 ;
V_293 . V_18 = V_146 -> V_18 -> V_20 ;
V_293 . V_300 = 0 ;
V_293 . V_222 = V_301 | V_302 ;
V_293 . V_303 = V_146 -> V_18 -> V_227 ;
V_293 . V_304 = 9600 ;
V_293 . V_305 = 5 * V_306 ;
V_293 . V_296 = V_294 ;
if ( F_105 ( V_292 , & V_293 , sizeof( * V_292 ) ) )
return - V_295 ;
return 0 ;
}
static int F_106 ( struct V_150 * V_151 ,
unsigned int V_307 , unsigned long V_308 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
switch ( V_307 ) {
case V_309 :
F_4 ( & V_18 -> V_2 , L_125 , V_12 ) ;
return F_103 ( V_146 ,
(struct V_291 T_7 * ) V_308 ) ;
}
return - V_310 ;
}
static void F_107 ( struct V_150 * V_151 , int V_311 )
{
struct V_17 * V_18 = V_151 -> V_230 ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
int V_8 ;
int V_312 = 0 ;
if ( V_311 == - 1 )
V_312 = 1 ;
V_8 = F_43 ( V_146 , V_313 , V_312 ) ;
if ( V_8 )
F_4 ( & V_18 -> V_2 , L_126 ,
V_12 , V_8 ) ;
}
static int F_108 ( struct V_106 * V_21 )
{
struct V_32 * V_176 ;
int V_8 ;
V_176 = F_109 ( sizeof( struct V_32 ) , V_37 ) ;
if ( ! V_176 )
return - V_38 ;
F_110 ( & V_176 -> V_213 ) ;
V_176 -> V_21 = V_21 ;
F_111 ( V_21 , V_176 ) ;
V_8 = F_41 ( V_176 ) ;
if ( V_8 ) {
F_16 ( V_176 ) ;
return V_8 ;
}
return 0 ;
}
static void F_112 ( struct V_106 * V_21 )
{
}
static void F_113 ( struct V_106 * V_21 )
{
F_16 ( F_76 ( V_21 ) ) ;
}
static int F_114 ( struct V_17 * V_18 )
{
struct V_43 * V_146 ;
int V_233 ;
V_146 = F_109 ( sizeof( * V_146 ) , V_37 ) ;
if ( ! V_146 )
return - V_38 ;
F_115 ( & V_146 -> V_194 ) ;
V_146 -> V_18 = V_18 ;
V_146 -> V_176 = F_76 ( V_18 -> V_21 ) ;
V_146 -> V_245 = V_314 ;
switch ( V_18 -> V_20 ) {
case 0 :
V_146 -> V_51 = V_315 ;
V_146 -> V_48 = V_316 ;
break;
case 1 :
V_146 -> V_51 = V_317 ;
V_146 -> V_48 = V_318 ;
break;
default:
F_18 ( & V_18 -> V_2 , L_127 ) ;
V_233 = - V_58 ;
goto V_87;
}
F_4 ( & V_18 -> V_2 ,
L_128 ,
V_12 , V_18 -> V_20 , V_146 -> V_51 ,
V_146 -> V_48 ) ;
F_116 ( V_18 , V_146 ) ;
V_233 = F_117 ( V_18 ) ;
if ( V_233 )
goto V_87;
V_18 -> V_18 . V_296 = F_118 ( V_296 * 10 ) ;
V_18 -> V_18 . V_319 = 1 ;
return 0 ;
V_87:
F_16 ( V_146 ) ;
return V_233 ;
}
static int F_119 ( struct V_17 * V_18 )
{
struct V_43 * V_146 ;
V_146 = F_58 ( V_18 ) ;
F_120 ( V_18 ) ;
F_16 ( V_146 ) ;
return 0 ;
}
static T_8 F_121 ( struct V_40 * V_2 ,
struct V_320 * V_321 , char * V_322 )
{
struct V_17 * V_18 = F_122 ( V_2 ) ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
return sprintf ( V_322 , L_61 , V_146 -> V_245 ) ;
}
static T_8 F_123 ( struct V_40 * V_2 ,
struct V_320 * V_321 , const char * V_323 , T_9 V_225 )
{
struct V_17 * V_18 = F_122 ( V_2 ) ;
struct V_43 * V_146 = F_58 ( V_18 ) ;
unsigned int V_324 = F_124 ( V_323 , NULL , 0 ) ;
F_4 ( V_2 , L_129 , V_12 , V_324 ) ;
if ( V_324 < 256 )
V_146 -> V_245 = V_324 ;
else
F_18 ( V_2 , L_130 , V_12 , V_324 ) ;
return V_225 ;
}
static int F_117 ( struct V_17 * V_18 )
{
return F_125 ( & V_18 -> V_2 , & V_325 ) ;
}
static int F_120 ( struct V_17 * V_18 )
{
F_126 ( & V_18 -> V_2 , & V_325 ) ;
return 0 ;
}
