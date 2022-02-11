static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 )
return F_3 ( V_4 -> V_5 ) & V_6 ;
else
return 0 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 ;
void * V_13 ;
int V_14 ;
V_13 = ( void * ) F_2 ( V_2 ) ;
V_14 = F_1 ( V_2 ) ;
if ( ! V_13 || V_14 == 0 )
return;
V_12 = F_5 ( V_10 -> V_15 , 20 + V_14 ,
V_16 ) ;
if ( V_12 == NULL ) {
F_6 ( V_8 ,
L_1 ) ;
return;
}
F_7 ( V_12 , V_17 , V_18 ) ;
F_8 ( V_12 , V_19 , V_14 , V_13 ) ;
F_9 ( V_12 , V_16 ) ;
return;
V_20:
F_10 ( V_12 ) ;
F_6 ( V_8 , L_2 ) ;
}
void F_11 ( struct V_7 * V_8 )
{
V_8 -> V_21 = F_4 ;
V_8 -> V_22 . V_23 = false ;
}
static void F_12 ( struct V_7 * V_8 )
{
if ( V_8 -> V_22 . V_23 ) {
if ( V_8 -> V_22 . V_24 &&
V_8 -> V_22 . V_25 )
F_13 ( V_8 -> V_26 -> V_27 ,
V_8 -> V_22 . V_28 ,
V_8 -> V_22 . V_24 ,
V_8 -> V_22 . V_25 ) ;
V_8 -> V_22 . V_23 = false ;
V_8 -> V_22 . V_24 = NULL ;
V_8 -> V_22 . V_29 = NULL ;
V_8 -> V_22 . V_25 = 0 ;
V_8 -> V_22 . V_30 = 0 ;
V_8 -> V_22 . V_28 = 0 ;
}
}
void F_14 ( struct V_7 * V_8 )
{
F_12 ( V_8 ) ;
}
static int F_15 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( struct V_33 ) ) ;
if ( ! V_32 [ V_35 ] ||
! V_32 [ V_36 ] ) {
F_6 ( V_8 ,
L_3 ) ;
return - V_37 ;
}
V_34 . V_38 = V_39 ;
V_34 . V_40 = F_16 ( V_32 [ V_35 ] ) ;
V_34 . V_13 [ 0 ] = F_17 ( V_32 [ V_36 ] ) ;
V_34 . V_41 [ 0 ] = F_18 ( V_32 [ V_36 ] ) ;
V_34 . V_42 [ 0 ] = V_43 ;
F_19 ( V_8 , L_4
L_5 , V_34 . V_40 , V_34 . V_38 , V_34 . V_41 [ 0 ] ) ;
return F_20 ( & V_8 -> V_44 , & V_34 ) ;
}
static int F_21 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
T_1 V_45 , V_46 ;
T_2 V_47 ;
struct V_11 * V_12 ;
int V_48 = 0 ;
if ( ! V_32 [ V_49 ] ) {
F_6 ( V_8 , L_6 ) ;
return - V_37 ;
}
V_45 = F_22 ( V_32 [ V_49 ] ) ;
F_19 ( V_8 , L_7 , V_45 ) ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_50 :
V_46 = F_23 ( V_8 , V_45 ) ;
F_19 ( V_8 , L_8 , V_46 ) ;
V_12 = F_24 ( V_10 -> V_15 , 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 , L_9 ) ;
return - V_51 ;
}
F_7 ( V_12 , V_52 , V_46 ) ;
V_48 = F_25 ( V_12 ) ;
if ( V_48 < 0 )
F_6 ( V_8 ,
L_10 , V_48 ) ;
break;
case V_53 :
if ( ! V_32 [ V_52 ] ) {
F_6 ( V_8 ,
L_11 ) ;
return - V_37 ;
} else {
V_46 = F_22 ( V_32 [ V_52 ] ) ;
F_19 ( V_8 , L_12 , V_46 ) ;
F_26 ( V_8 , V_45 , V_46 ) ;
}
break;
case V_54 :
if ( ! V_32 [ V_55 ] ) {
F_6 ( V_8 , L_11 ) ;
return - V_37 ;
} else {
V_47 = F_16 ( V_32 [ V_55 ] ) ;
F_19 ( V_8 , L_13 , V_47 ) ;
F_27 ( V_8 , V_45 , V_47 ) ;
}
break;
default:
F_6 ( V_8 , L_14 ) ;
return - V_56 ;
}
return V_48 ;
V_20:
F_10 ( V_12 ) ;
return - V_57 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_58 V_59 ;
int V_60 ;
F_29 ( V_8 , & V_59 ,
V_61 ,
NULL , NULL ) ;
V_60 = F_30 ( V_8 ) ;
if ( V_60 ) {
F_6 ( V_8 ,
L_15 , V_60 ) ;
goto V_62;
}
V_60 = F_31 ( V_8 , & V_59 , 2 * V_63 ) ;
if ( V_60 )
F_6 ( V_8 , L_16
L_17 , V_60 ) ;
return V_60 ;
V_62:
F_32 ( V_8 , & V_59 ) ;
return V_60 ;
}
static int F_33 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 ;
unsigned char * V_64 = NULL ;
int V_48 = 0 , V_65 = 0 ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_66 :
V_64 = ( unsigned char * ) V_8 -> V_67 -> V_68 ;
V_65 = strlen ( V_8 -> V_67 -> V_68 ) ;
V_12 = F_24 ( V_10 -> V_15 ,
V_65 + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_51 ;
}
F_7 ( V_12 , V_17 ,
V_69 ) ;
F_8 ( V_12 , V_70 ,
V_65 , V_64 ) ;
V_48 = F_25 ( V_12 ) ;
if ( V_48 < 0 )
F_6 ( V_8 , L_10 ,
V_48 ) ;
break;
case V_71 :
V_48 = F_34 ( V_8 , & V_8 -> V_72 ,
V_73 ) ;
if ( V_48 )
F_6 ( V_8 ,
L_18 , V_48 ) ;
break;
case V_74 :
F_28 ( V_8 ) ;
F_35 ( & V_8 -> V_44 ) ;
break;
case V_75 :
V_48 = F_34 ( V_8 ,
& V_8 -> V_76 ,
V_77 ) ;
if ( V_48 ) {
F_6 ( V_8 ,
L_19 , V_48 ) ;
break;
}
V_48 = F_36 ( V_8 ) ;
if ( V_48 )
F_6 ( V_8 ,
L_20 , V_48 ) ;
break;
case V_78 :
if ( V_8 -> V_79 ) {
V_12 = F_24 ( V_10 -> V_15 ,
V_8 -> V_67 -> V_80 -> V_81 + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_51 ;
}
F_7 ( V_12 , V_17 ,
V_82 ) ;
F_8 ( V_12 , V_83 ,
V_8 -> V_67 -> V_80 -> V_81 ,
V_8 -> V_79 ) ;
V_48 = F_25 ( V_12 ) ;
if ( V_48 < 0 )
F_6 ( V_8 ,
L_10 ,
V_48 ) ;
} else
return - V_84 ;
break;
case V_85 :
if ( ! V_32 [ V_86 ] ) {
F_6 ( V_8 ,
L_21 ) ;
return - V_37 ;
}
V_8 -> V_87 = F_22 ( V_32 [ V_86 ] ) ;
break;
default:
F_6 ( V_8 , L_22 ) ;
return - V_56 ;
}
return V_48 ;
V_20:
F_10 ( V_12 ) ;
return - V_57 ;
}
static int F_37 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 ;
int V_48 = 0 ;
struct V_88 * V_27 = V_8 -> V_26 -> V_27 ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_89 :
if ( V_8 -> V_22 . V_23 )
return - V_90 ;
if ( ! V_32 [ V_91 ] )
V_8 -> V_22 . V_30 = V_92 ;
else
V_8 -> V_22 . V_30 =
F_22 ( V_32 [ V_91 ] ) ;
if ( ! V_8 -> V_22 . V_30 )
return - V_93 ;
if ( V_8 -> V_22 . V_30 < V_94 ||
V_8 -> V_22 . V_30 > V_95 )
return - V_93 ;
V_8 -> V_22 . V_28 =
V_8 -> V_22 . V_30 + V_96 ;
V_8 -> V_22 . V_24 =
F_38 ( V_27 ,
V_8 -> V_22 . V_28 ,
& V_8 -> V_22 . V_25 ,
V_97 ) ;
if ( ! V_8 -> V_22 . V_24 )
return - V_51 ;
V_8 -> V_22 . V_23 = true ;
V_8 -> V_22 . V_29 = ( T_2 * ) F_39 (
V_8 -> V_22 . V_24 , 0x100 ) ;
memset ( V_8 -> V_22 . V_29 , 0x03B ,
V_8 -> V_22 . V_30 ) ;
V_12 = F_24 ( V_10 -> V_15 ,
sizeof( V_8 -> V_22 . V_25 ) + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
F_12 ( V_8 ) ;
return - V_51 ;
}
F_8 ( V_12 , V_98 ,
sizeof( V_8 -> V_22 . V_25 ) ,
( V_99 * ) & V_8 -> V_22 . V_25 ) ;
V_48 = F_25 ( V_12 ) ;
if ( V_48 < 0 ) {
F_6 ( V_8 ,
L_10 ,
V_48 ) ;
}
V_8 -> V_22 . V_100 =
F_40 ( V_8 -> V_22 . V_30 ,
V_101 ) ;
break;
case V_102 :
F_12 ( V_8 ) ;
break;
default:
F_6 ( V_8 , L_23 ) ;
return - V_56 ;
}
return V_48 ;
V_20:
F_10 ( V_12 ) ;
if ( F_22 ( V_32 [ V_17 ] ) ==
V_89 )
F_12 ( V_8 ) ;
return - V_57 ;
}
static int F_41 ( struct V_9 * V_10 , struct V_31 * * V_32 ,
struct V_11 * V_12 ,
struct V_103 * V_104 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
int V_105 , V_14 ;
if ( V_8 -> V_22 . V_23 &&
V_8 -> V_22 . V_29 ) {
V_105 = V_104 -> args [ 4 ] ;
if ( V_105 >= V_8 -> V_22 . V_100 )
return - V_106 ;
V_14 = V_101 ;
if ( ( ( V_105 + 1 ) == V_8 -> V_22 . V_100 ) &&
( V_8 -> V_22 . V_30 % V_101 ) )
V_14 = V_8 -> V_22 . V_30 %
V_101 ;
F_8 ( V_12 , V_107 , V_14 ,
V_8 -> V_22 . V_29 +
( V_101 * V_105 ) ) ;
V_105 ++ ;
V_104 -> args [ 4 ] = V_105 ;
return 0 ;
} else
return - V_84 ;
V_20:
return - V_108 ;
}
static int F_42 ( struct V_9 * V_10 , struct V_31 * * V_32 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
T_2 V_109 ;
if ( ! V_32 [ V_110 ] ) {
F_6 ( V_8 , L_24 ) ;
return - V_37 ;
}
V_109 = F_16 ( V_32 [ V_110 ] ) ;
if ( ( V_109 == V_111 ) || ( V_109 == V_112 ) )
V_8 -> V_113 = V_109 ;
else {
F_6 ( V_8 , L_25 ) ;
return - V_93 ;
}
return 0 ;
}
int F_43 ( struct V_9 * V_10 , void * V_13 , int V_41 )
{
struct V_31 * V_32 [ V_114 ] ;
struct V_7 * V_8 = V_10 -> V_8 ;
int V_115 ;
V_115 = F_44 ( V_32 , V_114 - 1 , V_13 , V_41 ,
V_116 ) ;
if ( V_115 != 0 ) {
F_6 ( V_8 ,
L_26 , V_115 ) ;
return V_115 ;
}
if ( ! V_32 [ V_17 ] ) {
F_6 ( V_8 , L_27 ) ;
return - V_37 ;
}
F_45 ( & V_8 -> V_117 ) ;
switch ( F_22 ( V_32 [ V_17 ] ) ) {
case V_118 :
F_6 ( V_8 , L_28 ) ;
V_115 = F_15 ( V_10 , V_32 ) ;
break;
case V_50 :
case V_53 :
case V_54 :
F_6 ( V_8 , L_29 ) ;
V_115 = F_21 ( V_10 , V_32 ) ;
break;
case V_66 :
case V_71 :
case V_74 :
case V_75 :
case V_78 :
case V_85 :
F_6 ( V_8 , L_30 ) ;
V_115 = F_33 ( V_10 , V_32 ) ;
break;
case V_89 :
case V_102 :
case V_119 :
F_6 ( V_8 , L_31 ) ;
V_115 = F_37 ( V_10 , V_32 ) ;
break;
case V_120 :
F_6 ( V_8 , L_32 ) ;
V_115 = F_42 ( V_10 , V_32 ) ;
break;
default:
F_6 ( V_8 , L_33 ) ;
V_115 = - V_56 ;
break;
}
F_46 ( & V_8 -> V_117 ) ;
return V_115 ;
}
int F_47 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_103 * V_104 ,
void * V_13 , int V_41 )
{
struct V_31 * V_32 [ V_114 ] ;
struct V_7 * V_8 = V_10 -> V_8 ;
int V_115 ;
T_1 V_34 ;
if ( V_104 -> args [ 3 ] ) {
V_34 = V_104 -> args [ 3 ] - 1 ;
} else {
V_115 = F_44 ( V_32 , V_114 - 1 , V_13 , V_41 ,
V_116 ) ;
if ( V_115 ) {
F_6 ( V_8 ,
L_26 , V_115 ) ;
return V_115 ;
}
if ( ! V_32 [ V_17 ] ) {
F_6 ( V_8 ,
L_27 ) ;
return - V_37 ;
}
V_34 = F_22 ( V_32 [ V_17 ] ) ;
V_104 -> args [ 3 ] = V_34 + 1 ;
}
F_45 ( & V_8 -> V_117 ) ;
switch ( V_34 ) {
case V_119 :
F_6 ( V_8 , L_34 ) ;
V_115 = F_41 ( V_10 , V_32 , V_12 , V_104 ) ;
break;
default:
V_115 = - V_93 ;
break;
}
F_46 ( & V_8 -> V_117 ) ;
return V_115 ;
}
