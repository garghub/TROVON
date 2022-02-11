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
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_32 * V_33 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
F_8 ( L_1 , V_24 ) ;
F_8 ( L_2 , V_25 ) ;
F_8 ( L_3 , V_26 ) ;
F_8 ( L_4 , V_27 ) ;
F_8 ( L_5 , V_28 ) ;
F_8 ( L_6 , V_29 ) ;
if ( V_29 > 200 )
V_29 = 200 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_32 ) ;
V_33 = (struct V_32 * ) ( V_11 + 1 ) ;
V_33 -> type = V_35 ;
V_33 -> V_23 = V_23 ;
F_9 ( F_10 ( V_28 ) , & V_33 -> V_28 ) ;
F_9 ( F_10 ( V_29 ) , & V_33 -> V_36 ) ;
V_33 -> V_24 = V_24 ;
V_33 -> V_25 = V_25 ;
V_33 -> V_37 = V_27 ;
V_33 -> V_26 = V_26 ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_11 ( void * V_22 , T_1 V_23 , T_1 V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_38 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_38 ) ;
V_33 = (struct V_38 * ) ( V_11 + 1 ) ;
V_33 -> type = V_39 ;
V_33 -> V_23 = V_23 ;
V_33 -> V_26 = V_26 ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_12 ( void * V_22 , T_1 V_23 , T_1 V_26 , T_1 V_40 )
{
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_41 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_41 ) ;
V_33 = (struct V_41 * ) ( V_11 + 1 ) ;
V_33 -> type = V_42 ;
V_33 -> V_23 = V_23 ;
V_33 -> V_26 = V_26 ;
V_33 -> V_43 = V_40 ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_13 ( void * V_22 , T_1 V_23 , T_1 type ,
T_1 V_44 , T_1 V_26 , T_3 V_45 )
{
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_46 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_46 ) ;
V_33 = (struct V_46 * ) ( V_11 + 1 ) ;
V_33 -> type = type ;
V_33 -> V_23 = V_23 ;
V_33 -> V_44 = V_44 ;
V_33 -> V_26 = V_26 ;
F_9 ( V_45 , & V_33 -> V_45 ) ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
static int F_14 ( void * V_22 , T_1 V_23 , T_1 V_24 ,
T_1 V_47 , T_3 V_48 , T_3 V_26 , const T_1 * V_12 , int V_49 )
{
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = & V_31 -> V_34 ;
struct V_3 * V_4 = F_7 ( & V_31 -> V_34 ) ;
struct V_50 * V_33 ;
if ( V_4 == NULL )
return - 1 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_11 -> V_18 = sizeof( struct V_50 ) - 1 + V_49 ;
V_33 = (struct V_50 * ) ( V_11 + 1 ) ;
V_33 -> type = V_51 ;
V_33 -> V_23 = V_23 ;
V_33 -> V_24 = V_24 ;
V_33 -> V_47 = V_47 ;
F_9 ( V_48 , & V_33 -> V_48 ) ;
F_9 ( V_26 , & V_33 -> V_26 ) ;
if ( V_49 )
memcpy ( V_33 -> V_12 , V_12 , V_49 ) ;
return F_1 ( V_2 , V_4 , V_6 , 0 , 0 ) ;
}
int F_15 ( void * V_22 , T_1 V_23 , struct V_52 * V_53 ,
const T_1 * V_12 , int V_49 )
{
unsigned V_54 = F_16 ( V_53 -> V_55 ) ;
unsigned V_27 = F_16 ( V_53 -> V_56 ) ;
unsigned V_57 = F_16 ( V_53 -> V_58 ) ;
int V_59 = 0 ;
if ( ( V_53 -> V_60 & V_61 ) == V_62 ) {
switch ( V_53 -> V_63 ) {
case V_64 :
V_59 = F_6 ( V_22 , V_23 ,
V_53 -> V_60 , ( T_1 ) ( V_54 >> 8 ) ,
( T_1 ) V_54 , V_53 -> V_56 , 0 , V_57 ) ;
break;
case V_65 :
V_59 = F_11 ( V_22 , V_23 , ( T_1 ) V_54 ) ;
break;
case V_66 : {
T_1 V_67 = ( T_1 ) V_27 ;
T_1 V_40 = ( T_1 ) V_54 ;
V_59 = F_12 ( V_22 , V_23 ,
V_67 , V_40 ) ;
}
break;
case V_68 :
V_59 = F_13 ( V_22 , V_23 ,
V_69 ,
V_53 -> V_60 & 0xf , ( T_1 ) V_27 ,
V_53 -> V_55 ) ;
break;
case V_70 :
V_59 = F_13 ( V_22 , V_23 ,
V_71 ,
V_53 -> V_60 & 0xf ,
( T_1 ) V_27 , V_53 -> V_55 ) ;
break;
}
} else {
V_59 = F_14 ( V_22 , V_23 , V_53 -> V_60 ,
V_53 -> V_63 , V_53 -> V_55 , V_53 -> V_56 ,
V_12 , V_49 ) ;
}
return V_59 ;
}
int F_17 ( void * V_22 , T_1 V_72 , struct V_73 * V_73 )
{
struct V_5 * V_6 = (struct V_5 * ) V_22 ;
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_1 * V_2 ;
int V_74 ;
int V_75 ;
T_1 * V_12 ;
struct V_76 * V_77 ;
if ( V_31 -> V_78 & V_79 ) {
for ( V_74 = 0 ; V_74 < V_73 -> V_80 ; V_74 ++ ) {
T_1 * V_12 ;
V_77 = & V_73 -> V_81 [ V_74 ] ;
V_12 = ( ( T_1 * ) V_73 -> V_82 ) + V_77 -> V_28 ;
F_18 ( V_31 , V_72 , V_12 , V_77 -> V_18 ) ;
}
return 0 ;
}
V_75 = sizeof( struct V_83 ) - 1 ;
V_2 = & V_31 -> V_34 ;
V_74 = 0 ;
while ( V_74 < V_73 -> V_80 ) {
struct V_3 * V_4 = F_7 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_83 * V_33 ;
int V_84 ;
int V_85 ;
int V_86 ;
if ( V_4 == NULL )
return - 1 ;
V_86 = V_87 ;
V_11 = (struct V_10 * ) V_4 -> V_12 ;
V_33 = (struct V_83 * ) ( V_11 + 1 ) ;
V_33 -> type = V_88 ;
V_33 -> V_89 = V_72 ;
V_33 -> V_90 = V_91 ;
V_85 = V_73 -> V_81 [ V_74 ] . V_18 ;
V_33 -> V_85 = ( T_1 ) V_85 ;
V_12 = ( ( T_1 * ) ( V_11 + 1 ) ) + V_75 ;
V_84 = 0 ;
while ( V_74 < V_73 -> V_80 ) {
V_77 = & V_73 -> V_81 [ V_74 ] ;
if ( ( V_85 == V_77 -> V_18 ) &&
( V_77 -> V_18 <= V_86 ) ) {
memcpy ( V_12 , ( ( T_1 * ) V_73 -> V_82 ) +
V_77 -> V_28 , V_85 ) ;
V_12 += V_85 ;
V_86 -= V_85 ;
V_84 ++ ;
V_77 -> V_92 = 0 ;
V_77 -> V_93 = V_77 -> V_18 ;
V_74 ++ ;
} else {
break;
}
}
V_11 -> V_18 = V_75 + V_87 - V_86 ;
V_33 -> V_94 = ( T_1 ) V_84 ;
F_1 ( V_2 , V_4 , V_6 , V_72 ,
V_31 -> V_78 & V_95 ) ;
}
return 0 ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_96 * V_97 , int V_29 )
{
struct V_98 * V_99 = (struct V_98 * ) V_97 ;
switch ( V_99 -> V_90 ) {
case V_100 : {
struct V_101 * V_33 =
(struct V_101 * ) V_99 ;
T_1 * V_12 = V_33 -> V_12 ;
int V_102 = ( V_29 - sizeof( struct V_101 ) + 1 )
/ V_33 -> V_85 ;
while ( V_102 -- ) {
F_20 ( V_6 -> V_103 , V_33 -> V_89 ,
V_12 , V_33 -> V_85 ) ;
V_12 += V_33 -> V_85 ;
}
}
break;
case V_91 : {
struct V_83 * V_33 =
(struct V_83 * ) V_99 ;
int V_49 = V_29 - sizeof( struct V_83 ) + 1 ;
int V_85 = V_33 -> V_85 ;
T_1 * V_12 = V_33 -> V_12 ;
int V_104 ;
int V_74 ;
if ( ! V_85 )
break;
V_104 = V_49 / V_85 ;
for ( V_74 = 0 ; V_74 < V_104 ; V_74 ++ ) {
F_20 ( V_6 -> V_103 ,
V_33 -> V_89 , V_12 , V_85 ) ;
V_12 += V_85 ;
}
}
break;
}
}
void F_21 ( struct V_30 * V_31 , struct V_10 * V_11 )
{
struct V_96 * V_97 = (struct V_96 * ) ( V_11 + 1 ) ;
struct V_5 * V_6 ;
F_2 ( & V_31 -> V_105 [ V_17 - 1 ] ) ;
V_6 = (struct V_5 * ) V_31 -> V_106 [ V_17 - 1 ] ;
if ( V_6 )
F_22 ( V_6 ) ;
F_5 ( & V_31 -> V_105 [ V_17 - 1 ] ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_107 )
goto V_108;
if ( V_97 -> V_20 != 0 ) {
if ( ( ( V_6 -> V_109 - V_97 -> V_20 ) & 0x80 ) == 0 )
goto V_108;
}
V_6 -> V_109 = V_97 -> V_20 ;
switch ( V_97 -> type ) {
case V_110 : {
struct V_111 * V_33 =
(struct V_111 * ) V_97 ;
int V_49 = V_11 -> V_18 -
sizeof( struct V_111 ) + 1 ;
T_2 V_112 = F_16 ( F_23 ( & V_33 -> V_28 ) ) ;
T_2 V_113 =
F_16 ( F_23 ( & V_33 -> V_113 ) ) ;
F_8 ( L_7 ) ;
F_24 ( V_6 -> V_103 , V_33 -> V_23 ,
V_33 -> V_114 , V_33 -> V_12 ,
V_49 , V_112 , V_113 ) ;
}
break;
case V_115 : {
struct V_116 * V_33 =
(struct V_116 * ) V_97 ;
F_25 ( V_6 -> V_103 , V_33 -> V_23 ,
V_33 -> V_114 , NULL , 0 ) ;
}
break;
case V_117 : {
struct V_118 * V_33 =
(struct V_118 * ) V_97 ;
F_25 ( V_6 -> V_103 ,
V_33 -> V_23 , V_33 -> V_114 , NULL , 0 ) ;
}
break;
case V_119 : {
struct V_120 * V_33 =
(struct V_120 * ) V_97 ;
F_25 ( V_6 -> V_103 , V_33 -> V_23 ,
V_33 -> V_114 , V_33 -> V_12 , V_11 -> V_18 -
sizeof( struct V_120 ) + 1 ) ;
}
break;
case V_88 :
F_19 ( V_6 , V_97 , V_11 -> V_18 ) ;
break;
}
V_108:
F_26 ( V_6 ) ;
}
void F_27 ( struct V_30 * V_31 , T_1 V_72 , T_1 * V_12 , T_1 V_29 )
{
struct V_5 * V_6 ;
F_2 ( & V_31 -> V_105 [ V_17 - 1 ] ) ;
V_6 = (struct V_5 * ) V_31 -> V_106 [ V_17 - 1 ] ;
if ( V_6 )
F_22 ( V_6 ) ;
F_5 ( & V_31 -> V_105 [ V_17 - 1 ] ) ;
if ( V_6 == NULL )
return;
if ( ! V_6 -> V_107 ) {
F_8 ( L_8 , V_72 ) ;
F_20 ( V_6 -> V_103 , V_72 , V_12 , V_29 ) ;
}
F_26 ( V_6 ) ;
}
