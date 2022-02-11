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
F_13 ( F_14 ( V_8 ) -> V_26 ,
V_8 -> V_22 . V_27 ,
V_8 -> V_22 . V_24 ,
V_8 -> V_22 . V_25 ) ;
V_8 -> V_22 . V_23 = false ;
V_8 -> V_22 . V_24 = NULL ;
V_8 -> V_22 . V_28 = NULL ;
V_8 -> V_22 . V_25 = 0 ;
V_8 -> V_22 . V_29 = 0 ;
V_8 -> V_22 . V_27 = 0 ;
}
}
void F_15 ( struct V_7 * V_8 )
{
F_12 ( V_8 ) ;
}
static int F_16 ( struct V_9 * V_10 , struct V_30 * * V_31 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( struct V_32 ) ) ;
if ( ! V_31 [ V_34 ] ||
! V_31 [ V_35 ] ) {
F_6 ( V_8 ,
L_3 ) ;
return - V_36 ;
}
V_33 . V_37 = V_38 ;
V_33 . V_39 = F_17 ( V_31 [ V_34 ] ) ;
V_33 . V_13 [ 0 ] = F_18 ( V_31 [ V_35 ] ) ;
V_33 . V_40 [ 0 ] = F_19 ( V_31 [ V_35 ] ) ;
V_33 . V_41 [ 0 ] = V_42 ;
F_20 ( V_8 , L_4
L_5 , V_33 . V_39 , V_33 . V_37 , V_33 . V_40 [ 0 ] ) ;
return F_21 ( F_22 ( V_8 ) , & V_33 ) ;
}
static int F_23 ( struct V_9 * V_10 , struct V_30 * * V_31 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
T_1 V_43 , V_44 ;
T_2 V_45 ;
struct V_11 * V_12 ;
int V_46 = 0 ;
if ( ! V_31 [ V_47 ] ) {
F_6 ( V_8 , L_6 ) ;
return - V_36 ;
}
V_43 = F_24 ( V_31 [ V_47 ] ) ;
F_20 ( V_8 , L_7 , V_43 ) ;
switch ( F_24 ( V_31 [ V_17 ] ) ) {
case V_48 :
V_44 = F_25 ( F_14 ( V_8 ) , V_43 ) ;
F_20 ( V_8 , L_8 , V_44 ) ;
V_12 = F_26 ( V_10 -> V_15 , 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 , L_9 ) ;
return - V_49 ;
}
F_7 ( V_12 , V_50 , V_44 ) ;
V_46 = F_27 ( V_12 ) ;
if ( V_46 < 0 )
F_6 ( V_8 ,
L_10 , V_46 ) ;
break;
case V_51 :
if ( ! V_31 [ V_50 ] ) {
F_6 ( V_8 ,
L_11 ) ;
return - V_36 ;
} else {
V_44 = F_24 ( V_31 [ V_50 ] ) ;
F_20 ( V_8 , L_12 , V_44 ) ;
F_28 ( F_14 ( V_8 ) , V_43 , V_44 ) ;
}
break;
case V_52 :
if ( ! V_31 [ V_53 ] ) {
F_6 ( V_8 , L_11 ) ;
return - V_36 ;
} else {
V_45 = F_17 ( V_31 [ V_53 ] ) ;
F_20 ( V_8 , L_13 , V_45 ) ;
F_29 ( F_14 ( V_8 ) , V_43 , V_45 ) ;
}
break;
default:
F_6 ( V_8 , L_14 ) ;
return - V_54 ;
}
return V_46 ;
V_20:
F_10 ( V_12 ) ;
return - V_55 ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_56 V_57 ;
int V_58 ;
F_31 ( V_8 , & V_57 ,
V_59 ,
NULL , NULL ) ;
V_58 = F_32 ( V_8 ) ;
if ( V_58 ) {
F_6 ( V_8 ,
L_15 , V_58 ) ;
goto V_60;
}
V_58 = F_33 ( V_8 , & V_57 , 2 * V_61 ) ;
if ( V_58 )
F_6 ( V_8 , L_16
L_17 , V_58 ) ;
return V_58 ;
V_60:
F_34 ( V_8 , & V_57 ) ;
return V_58 ;
}
static int F_35 ( struct V_9 * V_10 , struct V_30 * * V_31 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 ;
unsigned char * V_62 = NULL ;
int V_46 = 0 , V_63 = 0 ;
switch ( F_24 ( V_31 [ V_17 ] ) ) {
case V_64 :
V_62 = ( unsigned char * ) V_8 -> V_65 -> V_66 ;
V_63 = strlen ( V_8 -> V_65 -> V_66 ) ;
V_12 = F_26 ( V_10 -> V_15 ,
V_63 + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_49 ;
}
F_7 ( V_12 , V_17 ,
V_67 ) ;
F_8 ( V_12 , V_68 ,
V_63 , V_62 ) ;
V_46 = F_27 ( V_12 ) ;
if ( V_46 < 0 )
F_6 ( V_8 , L_10 ,
V_46 ) ;
break;
case V_69 :
V_46 = F_36 ( V_8 , & V_8 -> V_70 ,
V_71 ) ;
if ( V_46 )
F_6 ( V_8 ,
L_18 , V_46 ) ;
break;
case V_72 :
F_30 ( V_8 ) ;
F_37 ( F_22 ( V_8 ) ) ;
break;
case V_73 :
V_46 = F_36 ( V_8 ,
& V_8 -> V_74 ,
V_75 ) ;
if ( V_46 ) {
F_6 ( V_8 ,
L_19 , V_46 ) ;
break;
}
V_46 = F_38 ( V_8 ) ;
if ( V_46 )
F_6 ( V_8 ,
L_20 , V_46 ) ;
break;
case V_76 :
if ( V_8 -> V_77 ) {
V_12 = F_26 ( V_10 -> V_15 ,
V_8 -> V_65 -> V_78 -> V_79 + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
return - V_49 ;
}
F_7 ( V_12 , V_17 ,
V_80 ) ;
F_8 ( V_12 , V_81 ,
V_8 -> V_65 -> V_78 -> V_79 ,
V_8 -> V_77 ) ;
V_46 = F_27 ( V_12 ) ;
if ( V_46 < 0 )
F_6 ( V_8 ,
L_10 ,
V_46 ) ;
} else
return - V_82 ;
break;
case V_83 :
if ( ! V_31 [ V_84 ] ) {
F_6 ( V_8 ,
L_21 ) ;
return - V_36 ;
}
V_8 -> V_85 = F_24 ( V_31 [ V_84 ] ) ;
break;
default:
F_6 ( V_8 , L_22 ) ;
return - V_54 ;
}
return V_46 ;
V_20:
F_10 ( V_12 ) ;
return - V_55 ;
}
static int F_39 ( struct V_9 * V_10 , struct V_30 * * V_31 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 ;
int V_46 = 0 ;
struct V_86 * V_26 = F_14 ( V_8 ) -> V_26 ;
switch ( F_24 ( V_31 [ V_17 ] ) ) {
case V_87 :
if ( V_8 -> V_22 . V_23 )
return - V_88 ;
if ( ! V_31 [ V_89 ] )
V_8 -> V_22 . V_29 = V_90 ;
else
V_8 -> V_22 . V_29 =
F_24 ( V_31 [ V_89 ] ) ;
if ( ! V_8 -> V_22 . V_29 )
return - V_91 ;
if ( V_8 -> V_22 . V_29 < V_92 ||
V_8 -> V_22 . V_29 > V_93 )
return - V_91 ;
V_8 -> V_22 . V_27 =
V_8 -> V_22 . V_29 + V_94 ;
V_8 -> V_22 . V_24 =
F_40 ( V_26 ,
V_8 -> V_22 . V_27 ,
& V_8 -> V_22 . V_25 ,
V_95 ) ;
if ( ! V_8 -> V_22 . V_24 )
return - V_49 ;
V_8 -> V_22 . V_23 = true ;
V_8 -> V_22 . V_28 = ( T_2 * ) F_41 (
V_8 -> V_22 . V_24 , 0x100 ) ;
memset ( V_8 -> V_22 . V_28 , 0x03B ,
V_8 -> V_22 . V_29 ) ;
V_12 = F_26 ( V_10 -> V_15 ,
sizeof( V_8 -> V_22 . V_25 ) + 20 ) ;
if ( ! V_12 ) {
F_6 ( V_8 ,
L_9 ) ;
F_12 ( V_8 ) ;
return - V_49 ;
}
F_8 ( V_12 , V_96 ,
sizeof( V_8 -> V_22 . V_25 ) ,
( V_97 * ) & V_8 -> V_22 . V_25 ) ;
V_46 = F_27 ( V_12 ) ;
if ( V_46 < 0 ) {
F_6 ( V_8 ,
L_10 ,
V_46 ) ;
}
V_8 -> V_22 . V_98 =
F_42 ( V_8 -> V_22 . V_29 ,
V_99 ) ;
break;
case V_100 :
F_12 ( V_8 ) ;
break;
default:
F_6 ( V_8 , L_23 ) ;
return - V_54 ;
}
return V_46 ;
V_20:
F_10 ( V_12 ) ;
if ( F_24 ( V_31 [ V_17 ] ) ==
V_87 )
F_12 ( V_8 ) ;
return - V_55 ;
}
static int F_43 ( struct V_9 * V_10 , struct V_30 * * V_31 ,
struct V_11 * V_12 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
int V_103 , V_14 ;
if ( V_8 -> V_22 . V_23 &&
V_8 -> V_22 . V_28 ) {
V_103 = V_102 -> args [ 4 ] ;
if ( V_103 >= V_8 -> V_22 . V_98 )
return - V_104 ;
V_14 = V_99 ;
if ( ( ( V_103 + 1 ) == V_8 -> V_22 . V_98 ) &&
( V_8 -> V_22 . V_29 % V_99 ) )
V_14 = V_8 -> V_22 . V_29 %
V_99 ;
F_8 ( V_12 , V_105 , V_14 ,
V_8 -> V_22 . V_28 +
( V_99 * V_103 ) ) ;
V_103 ++ ;
V_102 -> args [ 4 ] = V_103 ;
return 0 ;
} else
return - V_82 ;
V_20:
return - V_106 ;
}
static int F_44 ( struct V_9 * V_10 , struct V_30 * * V_31 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
T_2 V_107 ;
if ( ! V_31 [ V_108 ] ) {
F_6 ( V_8 , L_24 ) ;
return - V_36 ;
}
V_107 = F_17 ( V_31 [ V_108 ] ) ;
if ( ( V_107 == V_109 ) || ( V_107 == V_110 ) )
V_8 -> V_111 -> V_112 = V_107 ;
else {
F_6 ( V_8 , L_25 ) ;
return - V_91 ;
}
return 0 ;
}
int F_45 ( struct V_9 * V_10 , void * V_13 , int V_40 )
{
struct V_30 * V_31 [ V_113 ] ;
struct V_7 * V_8 = V_10 -> V_8 ;
int V_114 ;
V_114 = F_46 ( V_31 , V_113 - 1 , V_13 , V_40 ,
V_115 ) ;
if ( V_114 != 0 ) {
F_6 ( V_8 ,
L_26 , V_114 ) ;
return V_114 ;
}
if ( ! V_31 [ V_17 ] ) {
F_6 ( V_8 , L_27 ) ;
return - V_36 ;
}
F_47 ( & V_8 -> V_111 -> V_116 ) ;
switch ( F_24 ( V_31 [ V_17 ] ) ) {
case V_117 :
F_6 ( V_8 , L_28 ) ;
V_114 = F_16 ( V_10 , V_31 ) ;
break;
case V_48 :
case V_51 :
case V_52 :
F_6 ( V_8 , L_29 ) ;
V_114 = F_23 ( V_10 , V_31 ) ;
break;
case V_64 :
case V_69 :
case V_72 :
case V_73 :
case V_76 :
case V_83 :
F_6 ( V_8 , L_30 ) ;
V_114 = F_35 ( V_10 , V_31 ) ;
break;
case V_87 :
case V_100 :
case V_118 :
F_6 ( V_8 , L_31 ) ;
V_114 = F_39 ( V_10 , V_31 ) ;
break;
case V_119 :
F_6 ( V_8 , L_32 ) ;
V_114 = F_44 ( V_10 , V_31 ) ;
break;
default:
F_6 ( V_8 , L_33 ) ;
V_114 = - V_54 ;
break;
}
F_48 ( & V_8 -> V_111 -> V_116 ) ;
return V_114 ;
}
int F_49 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_101 * V_102 ,
void * V_13 , int V_40 )
{
struct V_30 * V_31 [ V_113 ] ;
struct V_7 * V_8 = V_10 -> V_8 ;
int V_114 ;
T_1 V_33 ;
if ( V_102 -> args [ 3 ] ) {
V_33 = V_102 -> args [ 3 ] - 1 ;
} else {
V_114 = F_46 ( V_31 , V_113 - 1 , V_13 , V_40 ,
V_115 ) ;
if ( V_114 ) {
F_6 ( V_8 ,
L_26 , V_114 ) ;
return V_114 ;
}
if ( ! V_31 [ V_17 ] ) {
F_6 ( V_8 ,
L_27 ) ;
return - V_36 ;
}
V_33 = F_24 ( V_31 [ V_17 ] ) ;
V_102 -> args [ 3 ] = V_33 + 1 ;
}
F_47 ( & V_8 -> V_111 -> V_116 ) ;
switch ( V_33 ) {
case V_118 :
F_6 ( V_8 , L_34 ) ;
V_114 = F_43 ( V_10 , V_31 , V_12 , V_102 ) ;
break;
default:
V_114 = - V_91 ;
break;
}
F_48 ( & V_8 -> V_111 -> V_116 ) ;
return V_114 ;
}
