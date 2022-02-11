static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_4 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) ( V_11 + 1 ) ;
V_11 -> type = V_15 ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = V_11 -> V_18 + sizeof( struct V_10 ) ;
V_14 -> V_16 = V_17 ;
F_2 ( & V_2 -> V_19 ) ;
if ( V_8 == 0 ) {
V_14 -> V_20 = V_6 -> V_21 ++ ;
if ( V_6 -> V_21 == 0 )
V_6 -> V_21 = 1 ;
}
V_9 = F_3 ( V_2 , V_8 , V_7 , V_4 ) ;
if ( V_9 )
F_4 ( V_2 , V_4 ) ;
F_5 ( & V_2 -> V_19 ) ;
return V_9 ;
}
int F_6 ( void * V_22 , T_1 V_23 , T_1 V_24 , T_1 V_25 ,
T_1 V_26 , T_2 V_27 , int V_28 , int V_29 )
{
struct V_5 * V_6 = V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_32 * V_33 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
F_8 ( V_35 , L_1 , V_24 ) ;
F_8 ( V_35 , L_2 , V_25 ) ;
F_8 ( V_35 , L_3 , V_26 ) ;
F_8 ( V_35 , L_4 , V_27 ) ;
F_8 ( V_35 , L_5 , V_28 ) ;
F_8 ( V_35 , L_6 , V_29 ) ;
if ( V_29 > 200 )
V_29 = 200 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_32 ) ;
V_33 = (struct V_32 * ) ( V_11 + 1 ) ;
V_33 -> type = V_36 ;
V_33 -> V_23 = V_23 ;
F_9 ( F_10 ( V_28 ) , & V_33 -> V_28 ) ;
F_9 ( F_10 ( V_29 ) , & V_33 -> V_37 ) ;
V_33 -> V_24 = V_24 ;
V_33 -> V_25 = V_25 ;
V_33 -> V_38 = V_27 ;
V_33 -> V_26 = V_26 ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_11 ( void * V_22 , T_1 V_23 , T_1 V_26 )
{
struct V_5 * V_6 = V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_39 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_39 ) ;
V_33 = (struct V_39 * ) ( V_11 + 1 ) ;
V_33 -> type = V_40 ;
V_33 -> V_23 = V_23 ;
V_33 -> V_26 = V_26 ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_12 ( void * V_22 , T_1 V_23 , T_1 V_26 , T_1 V_41 )
{
struct V_5 * V_6 = V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_42 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_42 ) ;
V_33 = (struct V_42 * ) ( V_11 + 1 ) ;
V_33 -> type = V_43 ;
V_33 -> V_23 = V_23 ;
V_33 -> V_26 = V_26 ;
V_33 -> V_44 = V_41 ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_13 ( void * V_22 , T_1 V_23 , T_1 type ,
T_1 V_45 , T_1 V_26 , T_2 V_46 )
{
struct V_5 * V_6 = V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_47 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_47 ) ;
V_33 = (struct V_47 * ) ( V_11 + 1 ) ;
V_33 -> type = type ;
V_33 -> V_23 = V_23 ;
V_33 -> V_45 = V_45 ;
V_33 -> V_26 = V_26 ;
F_9 ( V_46 , & V_33 -> V_46 ) ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_14 ( void * V_22 , T_1 V_23 , T_1 V_24 ,
T_1 V_48 , T_2 V_49 , T_2 V_26 , const T_1 * V_12 , int V_50 )
{
struct V_5 * V_6 = V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_51 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_51 ) - 1 + V_50 ;
V_33 = (struct V_51 * ) ( V_11 + 1 ) ;
V_33 -> type = V_52 ;
V_33 -> V_23 = V_23 ;
V_33 -> V_24 = V_24 ;
V_33 -> V_48 = V_48 ;
F_9 ( V_49 , & V_33 -> V_49 ) ;
F_9 ( V_26 , & V_33 -> V_26 ) ;
if ( V_50 )
memcpy ( V_33 -> V_12 , V_12 , V_50 ) ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
int F_15 ( void * V_22 , T_1 V_23 , struct V_53 * V_54 ,
const T_1 * V_12 , int V_50 )
{
unsigned V_55 = F_16 ( V_54 -> V_56 ) ;
unsigned V_27 = F_16 ( V_54 -> V_57 ) ;
unsigned V_58 = F_16 ( V_54 -> V_59 ) ;
int V_60 = 0 ;
if ( ( V_54 -> V_61 & V_62 ) == V_63 ) {
switch ( V_54 -> V_64 ) {
case V_65 :
V_60 = F_6 ( V_22 , V_23 ,
V_54 -> V_61 , ( T_1 ) ( V_55 >> 8 ) ,
( T_1 ) V_55 , V_54 -> V_57 , 0 , V_58 ) ;
break;
case V_66 :
V_60 = F_11 ( V_22 , V_23 , ( T_1 ) V_55 ) ;
break;
case V_67 : {
T_1 V_68 = ( T_1 ) V_27 ;
T_1 V_41 = ( T_1 ) V_55 ;
V_60 = F_12 ( V_22 , V_23 ,
V_68 , V_41 ) ;
}
break;
case V_69 :
V_60 = F_13 ( V_22 , V_23 ,
V_70 ,
V_54 -> V_61 & 0xf , ( T_1 ) V_27 ,
V_54 -> V_56 ) ;
break;
case V_71 :
V_60 = F_13 ( V_22 , V_23 ,
V_72 ,
V_54 -> V_61 & 0xf ,
( T_1 ) V_27 , V_54 -> V_56 ) ;
break;
}
} else {
V_60 = F_14 ( V_22 , V_23 , V_54 -> V_61 ,
V_54 -> V_64 , V_54 -> V_56 , V_54 -> V_57 ,
V_12 , V_50 ) ;
}
return V_60 ;
}
int F_17 ( void * V_22 , T_1 V_73 , struct V_74 * V_74 )
{
struct V_5 * V_6 = V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_1 * V_2 ;
int V_75 ;
int V_76 ;
T_1 * V_12 ;
struct V_77 * V_78 ;
if ( V_31 -> V_79 & V_80 ) {
for ( V_75 = 0 ; V_75 < V_74 -> V_81 ; V_75 ++ ) {
T_1 * V_12 ;
V_78 = & V_74 -> V_82 [ V_75 ] ;
V_12 = ( ( T_1 * ) V_74 -> V_83 ) + V_78 -> V_28 ;
F_18 ( V_31 , V_73 , V_12 , V_78 -> V_18 ) ;
}
return 0 ;
}
V_76 = sizeof( struct V_84 ) - 1 ;
V_2 = & V_31 -> V_34 ;
V_75 = 0 ;
while ( V_75 < V_74 -> V_81 ) {
struct V_3 * V_4 = F_7 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_84 * V_33 ;
int V_85 ;
int V_86 ;
int V_87 ;
if ( V_4 == NULL )
return - 1 ;
V_87 = V_88 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_33 = (struct V_84 * ) ( V_11 + 1 ) ;
V_33 -> type = V_89 ;
V_33 -> V_90 = V_73 ;
V_33 -> V_91 = V_92 ;
V_86 = V_74 -> V_82 [ V_75 ] . V_18 ;
V_33 -> V_86 = ( T_1 ) V_86 ;
V_12 = ( ( T_1 * ) ( V_11 + 1 ) ) + V_76 ;
V_85 = 0 ;
while ( V_75 < V_74 -> V_81 ) {
V_78 = & V_74 -> V_82 [ V_75 ] ;
if ( ( V_86 == V_78 -> V_18 ) &&
( V_78 -> V_18 <= V_87 ) ) {
memcpy ( V_12 , ( ( T_1 * ) V_74 -> V_83 ) +
V_78 -> V_28 , V_86 ) ;
V_12 += V_86 ;
V_87 -= V_86 ;
V_85 ++ ;
V_78 -> V_93 = 0 ;
V_78 -> V_94 = V_78 -> V_18 ;
V_75 ++ ;
} else {
break;
}
}
V_11 -> V_18 = V_76 + V_88 - V_87 ;
V_33 -> V_95 = ( T_1 ) V_85 ;
F_1 ( V_2 , V_4 , V_6 , V_73 ,
V_31 -> V_79 & V_96 ) ;
}
return 0 ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_97 * V_98 , int V_29 )
{
struct V_99 * V_100 = (struct V_99 * ) V_98 ;
switch ( V_100 -> V_91 ) {
case V_101 : {
struct V_102 * V_33 =
(struct V_102 * ) V_100 ;
T_1 * V_12 = V_33 -> V_12 ;
int V_103 = ( V_29 - sizeof( struct V_102 ) + 1 )
/ V_33 -> V_86 ;
while ( V_103 -- ) {
F_20 ( V_6 -> V_104 , V_33 -> V_90 ,
V_12 , V_33 -> V_86 ) ;
V_12 += V_33 -> V_86 ;
}
}
break;
case V_92 : {
struct V_84 * V_33 =
(struct V_84 * ) V_100 ;
int V_50 = V_29 - sizeof( struct V_84 ) + 1 ;
int V_86 = V_33 -> V_86 ;
T_1 * V_12 = V_33 -> V_12 ;
int V_105 ;
int V_75 ;
if ( ! V_86 )
break;
V_105 = V_50 / V_86 ;
for ( V_75 = 0 ; V_75 < V_105 ; V_75 ++ ) {
F_20 ( V_6 -> V_104 ,
V_33 -> V_90 , V_12 , V_86 ) ;
V_12 += V_86 ;
}
}
break;
}
}
void F_21 ( struct V_30 * V_31 , struct V_10 * V_11 )
{
struct V_97 * V_98 = (struct V_97 * ) ( V_11 + 1 ) ;
struct V_5 * V_6 ;
F_2 ( & V_31 -> V_106 [ V_17 ] ) ;
V_6 = (struct V_5 * ) V_31 -> V_107 [ V_17 ] ;
if ( V_6 )
F_22 ( V_6 ) ;
F_5 ( & V_31 -> V_106 [ V_17 ] ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_108 )
goto V_109;
if ( V_98 -> V_20 != 0 ) {
if ( ( ( V_6 -> V_110 - V_98 -> V_20 ) & 0x80 ) == 0 )
goto V_109;
}
V_6 -> V_110 = V_98 -> V_20 ;
switch ( V_98 -> type ) {
case V_111 : {
struct V_112 * V_33 =
(struct V_112 * ) V_98 ;
int V_50 = V_11 -> V_18 -
sizeof( struct V_112 ) + 1 ;
T_3 V_113 = F_16 ( F_23 ( & V_33 -> V_28 ) ) ;
T_3 V_114 =
F_16 ( F_23 ( & V_33 -> V_114 ) ) ;
F_8 ( V_35 , L_7 ) ;
F_24 ( V_6 -> V_104 , V_33 -> V_23 ,
V_33 -> V_115 , V_33 -> V_12 ,
V_50 , V_113 , V_114 ) ;
}
break;
case V_116 : {
struct V_117 * V_33 =
(struct V_117 * ) V_98 ;
F_25 ( V_6 -> V_104 , V_33 -> V_23 ,
V_33 -> V_115 , NULL , 0 ) ;
}
break;
case V_118 : {
struct V_119 * V_33 =
(struct V_119 * ) V_98 ;
F_25 ( V_6 -> V_104 ,
V_33 -> V_23 , V_33 -> V_115 , NULL , 0 ) ;
}
break;
case V_120 : {
struct V_121 * V_33 =
(struct V_121 * ) V_98 ;
F_25 ( V_6 -> V_104 , V_33 -> V_23 ,
V_33 -> V_115 , V_33 -> V_12 , V_11 -> V_18 -
sizeof( struct V_121 ) + 1 ) ;
}
break;
case V_89 :
F_19 ( V_6 , V_98 , V_11 -> V_18 ) ;
break;
}
V_109:
F_26 ( V_6 ) ;
}
void F_27 ( struct V_30 * V_31 , T_1 V_73 , T_1 * V_12 , T_1 V_29 )
{
struct V_5 * V_6 ;
F_2 ( & V_31 -> V_106 [ V_17 ] ) ;
V_6 = (struct V_5 * ) V_31 -> V_107 [ V_17 ] ;
if ( V_6 )
F_22 ( V_6 ) ;
F_5 ( & V_31 -> V_106 [ V_17 ] ) ;
if ( V_6 == NULL )
return;
if ( ! V_6 -> V_108 ) {
F_8 ( V_35 , L_8 , V_73 ) ;
F_20 ( V_6 -> V_104 , V_73 , V_12 , V_29 ) ;
}
F_26 ( V_6 ) ;
}
