void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = V_5 ;
V_2 -> V_3 -> V_6 = 0 ;
V_2 -> V_3 -> V_7 ++ ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
}
bool F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_14 ;
if ( V_13 -> V_15 == V_16 ) {
struct V_17 * V_18 ;
T_1 V_19 , V_20 , V_21 ;
V_18 = ( void * ) ( V_11 -> V_14 + V_22 ) ;
V_19 = F_4 ( V_18 -> V_19 ) ;
V_20 = F_5 ( V_19 ) ;
V_21 = F_6 ( V_19 ) ;
if ( V_20 == V_23 &&
V_2 -> V_24 . V_25 ) {
V_2 -> V_24 . V_25 = false ;
V_2 -> V_3 -> V_26 = true ;
F_2 ( & V_2 -> V_3 -> V_27 ) ;
}
if ( V_21 == V_28 ) {
F_7 ( L_1 ,
V_21 , V_20 ) ;
F_8 ( V_11 ) ;
return false ;
}
}
return true ;
}
int F_9 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_29 * V_3 = V_2 -> V_3 ;
struct V_30 * V_31 ;
int V_32 = 0 ;
V_31 = (struct V_30 * ) V_11 -> V_14 ;
if ( V_31 -> V_18 != 0xff ) {
F_7 ( L_2 , V_31 -> V_18 ) ;
V_32 = - V_33 ;
goto exit;
}
switch ( V_31 -> V_14 [ 0 ] ) {
case V_34 :
if ( ! V_31 -> V_14 [ 2 ] ) {
if ( V_31 -> V_14 [ 1 ] == V_35 )
V_3 -> V_36 = 1 ;
else
V_3 -> V_36 = 0 ;
F_7 ( L_3 ,
( V_3 -> V_36 ) ? L_4 : L_5 ) ;
} else {
F_7 ( L_6 ) ;
}
break;
case V_37 :
if ( ! V_31 -> V_14 [ 3 ] )
F_7 ( L_7 , V_31 -> V_14 [ 1 ] ,
V_31 -> V_14 [ 2 ] ) ;
else
F_7 ( L_8 ) ;
break;
case V_38 :
if ( ! V_31 -> V_14 [ 1 ] ) {
V_3 -> V_39 = V_40 ;
if ( V_3 -> V_36 )
V_3 -> V_4 = V_41 ;
F_2 ( & V_3 -> V_27 ) ;
F_7 ( L_9 ) ;
} else {
F_7 ( L_10 ) ;
}
break;
case V_23 :
if ( V_2 -> V_24 . V_25 &&
V_31 -> V_14 [ 1 ] == V_42 ) {
F_7 ( L_11 ,
( ( V_31 -> V_14 [ 2 ] == V_43 ) ||
( V_31 -> V_14 [ 2 ] == V_44 ) ) ?
L_12 : L_13 ) ;
if ( V_31 -> V_45 > 3 && V_31 -> V_14 [ 3 ] )
V_2 -> V_24 . V_46 = V_47 ;
else
V_2 -> V_24 . V_46 = V_48 ;
F_7 ( L_14 , V_2 -> V_24 . V_46 ) ;
} else if ( V_2 -> V_24 . V_25 &&
V_31 -> V_14 [ 1 ] == V_49 ) {
F_7 ( L_11 , ( V_31 -> V_14 [ 2 ] ) ?
L_15 : L_16 ) ;
} else {
F_7 ( L_17 ) ;
V_32 = - V_33 ;
}
break;
case V_50 :
if ( V_31 -> V_14 [ 1 ] == V_51 )
V_3 -> V_4 = V_41 ;
F_7 ( L_11 ,
( V_3 -> V_4 ) ? L_18 : L_19 ) ;
break;
default:
F_7 ( L_20 , V_31 -> V_14 [ 0 ] ) ;
V_32 = - V_33 ;
break;
}
exit:
if ( ! V_32 )
F_8 ( V_11 ) ;
return V_32 ;
}
int F_10 ( struct V_1 * V_2 , int V_52 )
{
struct V_10 * V_11 ;
struct V_53 * V_54 ;
int V_32 = 0 ;
V_11 = F_11 ( sizeof( * V_54 ) , V_55 ) ;
if ( V_11 == NULL ) {
F_12 ( L_21 ) ;
return - V_56 ;
}
V_54 = (struct V_53 * ) F_13 ( V_11 , sizeof( * V_54 ) ) ;
V_54 -> V_57 = F_14 ( F_15 ( V_28 , V_23 ) ) ;
V_54 -> V_45 = 1 ;
V_54 -> V_14 [ 0 ] = V_52 ;
F_16 ( V_11 ) -> V_58 = V_59 ;
V_11 -> V_60 = ( void * ) V_2 -> V_24 . V_61 ;
F_17 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
V_2 -> V_24 . V_25 = true ;
V_2 -> V_3 -> V_26 = false ;
F_7 ( L_22 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_18 ( V_2 -> V_3 -> V_27 ,
V_2 -> V_3 -> V_26 ,
F_19 ( V_63 ) ) ) {
V_32 = - V_64 ;
F_12 ( L_23 ,
V_52 , V_2 -> V_24 . V_25 ) ;
}
F_7 ( L_24 ) ;
return V_32 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_53 * V_54 ;
V_11 = F_11 ( sizeof( * V_54 ) , V_55 ) ;
if ( ! V_11 ) {
F_12 ( L_21 ) ;
return - V_56 ;
}
V_54 = (struct V_53 * ) F_13 ( V_11 , sizeof( * V_54 ) ) ;
V_54 -> V_57 = F_14 ( F_15 ( V_28 ,
V_37 ) ) ;
V_54 -> V_45 = 2 ;
V_54 -> V_14 [ 0 ] = ( V_2 -> V_24 . V_65 & 0xff00 ) >> 8 ;
V_54 -> V_14 [ 1 ] = ( V_66 ) ( V_2 -> V_24 . V_65 & 0x00ff ) ;
F_16 ( V_11 ) -> V_58 = V_59 ;
V_11 -> V_60 = ( void * ) V_2 -> V_24 . V_61 ;
F_17 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
F_7 ( L_25 , V_54 -> V_14 [ 0 ] ,
V_54 -> V_14 [ 1 ] ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_53 * V_54 ;
V_11 = F_11 ( sizeof( * V_54 ) , V_55 ) ;
if ( V_11 == NULL ) {
F_12 ( L_21 ) ;
return - V_56 ;
}
V_54 = (struct V_53 * ) F_13 ( V_11 , sizeof( * V_54 ) ) ;
V_54 -> V_57 = F_14 ( F_15 ( V_28 ,
V_34 ) ) ;
V_54 -> V_45 = 1 ;
if ( V_2 -> V_24 . V_36 )
V_54 -> V_14 [ 0 ] = V_35 ;
else
V_54 -> V_14 [ 0 ] = V_67 ;
F_16 ( V_11 ) -> V_58 = V_59 ;
V_11 -> V_60 = ( void * ) V_2 -> V_24 . V_61 ;
F_17 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
F_7 ( L_26 , V_54 -> V_14 [ 0 ] ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_53 * V_54 ;
int V_32 = 0 ;
V_11 = F_11 ( sizeof( * V_54 ) , V_55 ) ;
if ( V_11 == NULL ) {
F_12 ( L_21 ) ;
return - V_56 ;
}
V_54 = (struct V_53 * ) F_13 ( V_11 , sizeof( * V_54 ) ) ;
V_54 -> V_57 = F_14 ( F_15 ( V_28 , V_38 ) ) ;
V_54 -> V_45 = 0 ;
F_16 ( V_11 ) -> V_58 = V_59 ;
V_11 -> V_60 = ( void * ) V_2 -> V_24 . V_61 ;
F_17 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
F_7 ( L_27 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_18 ( V_2 -> V_3 -> V_27 ,
V_2 -> V_3 -> V_39 ,
F_19 ( V_68 ) ) ) {
V_32 = - V_64 ;
F_12 ( L_28 , V_2 -> V_3 -> V_39 ,
V_2 -> V_3 -> V_4 ,
V_2 -> V_3 -> V_6 ) ;
}
return V_32 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
if ( V_2 -> V_24 . V_69 ) {
V_2 -> V_24 . V_69 = 0 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_70 ) {
V_2 -> V_24 . V_70 = 0 ;
F_21 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_71 ) {
V_2 -> V_24 . V_71 = 0 ;
if ( V_2 -> V_24 . V_72 ) {
V_32 = F_22 ( V_2 ) ;
} else {
V_32 = V_2 -> V_73 ( V_2 ) ;
V_2 -> V_3 -> V_39 = V_74 ;
}
}
return V_32 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_32 = 0 ;
if ( ! V_11 || ! V_11 -> V_14 )
return - V_33 ;
if ( ! V_11 -> V_75 || ( ( V_11 -> V_75 + V_76 ) > V_77 ) ) {
F_12 ( L_29 ,
V_11 -> V_75 , V_77 ) ;
return - V_33 ;
}
if ( F_25 ( V_11 ) < V_76 ) {
struct V_10 * V_78 = V_11 ;
V_11 = F_26 ( V_11 , V_76 ) ;
if ( ! V_11 ) {
F_12 ( L_30 ,
V_76 ) ;
V_11 = V_78 ;
return - V_33 ;
}
F_8 ( V_78 ) ;
}
F_27 ( V_11 , V_76 ) ;
V_11 -> V_14 [ 0 ] = ( V_11 -> V_75 & 0x0000ff ) ;
V_11 -> V_14 [ 1 ] = ( V_11 -> V_75 & 0x00ff00 ) >> 8 ;
V_11 -> V_14 [ 2 ] = ( V_11 -> V_75 & 0xff0000 ) >> 16 ;
V_11 -> V_14 [ 3 ] = F_16 ( V_11 ) -> V_58 ;
if ( V_2 -> V_79 )
V_32 = V_2 -> V_79 ( V_2 , V_11 -> V_14 , V_11 -> V_75 ) ;
return V_32 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_3 -> V_62 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
F_30 ( & V_2 -> V_3 -> V_27 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_3 -> V_62 ) ;
F_33 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_34 ( struct V_80 * V_81 ,
unsigned int V_54 , unsigned long V_82 )
{
return - V_83 ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_80 * V_81 = (struct V_80 * ) V_11 -> V_60 ;
struct V_1 * V_2 = NULL ;
F_7 ( L_31 , V_11 -> V_58 , V_11 -> V_75 ) ;
if ( ! V_81 ) {
F_12 ( L_32 ) ;
return - V_84 ;
}
V_2 = F_36 ( V_81 ) ;
if ( ! F_37 ( V_85 , & V_81 -> V_86 ) ) {
F_12 ( L_33 , V_81 -> V_86 ) ;
F_38 ( L_34 , V_87 ,
V_11 -> V_14 , V_11 -> V_75 ) ;
return - V_88 ;
}
switch ( F_16 ( V_11 ) -> V_58 ) {
case V_89 :
V_81 -> V_90 . V_91 ++ ;
break;
case V_92 :
V_81 -> V_90 . V_93 ++ ;
break;
case V_94 :
V_81 -> V_90 . V_95 ++ ;
break;
}
F_39 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
return 0 ;
}
static int F_40 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_36 ( V_81 ) ;
F_32 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_41 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_36 ( V_81 ) ;
if ( ! F_42 ( V_85 , & V_81 -> V_86 ) )
return 0 ;
F_32 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_43 ( struct V_80 * V_81 )
{
F_44 ( V_85 , & V_81 -> V_86 ) ;
return 0 ;
}
static int F_45 ( void * V_14 )
{
struct V_96 * V_97 = V_14 ;
struct V_1 * V_2 = V_97 -> V_2 ;
struct V_29 * V_3 = V_2 -> V_3 ;
T_2 V_98 ;
struct V_10 * V_11 ;
T_3 V_86 ;
F_46 ( & V_98 , V_99 ) ;
for (; ; ) {
F_47 ( & V_97 -> V_9 , & V_98 ) ;
F_48 ( V_100 ) ;
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_24 . V_101 ||
F_49 ( & V_3 -> V_62 ) ) ) ) {
F_7 ( L_35 ) ;
F_50 () ;
}
F_48 ( V_102 ) ;
F_51 ( & V_97 -> V_9 , & V_98 ) ;
F_7 ( L_36 ) ;
if ( F_52 () ) {
F_7 ( L_37 ) ;
break;
}
F_53 ( & V_2 -> V_103 , V_86 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_54 ( & V_2 -> V_103 , V_86 ) ;
V_2 -> V_104 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_41 &&
! F_49 ( & V_3 -> V_62 ) ) {
F_54 ( & V_2 -> V_103 , V_86 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_73 ( V_2 ) ;
continue;
} else {
F_54 ( & V_2 -> V_103 , V_86 ) ;
}
if ( V_3 -> V_4 == V_41 )
continue;
if ( ! V_2 -> V_24 . V_101 )
continue;
V_11 = F_55 ( & V_3 -> V_62 ) ;
if ( V_11 ) {
if ( F_24 ( V_2 , V_11 ) )
V_2 -> V_24 . V_61 -> V_90 . V_105 ++ ;
else
V_2 -> V_24 . V_61 -> V_90 . V_106 += V_11 -> V_75 ;
F_8 ( V_11 ) ;
}
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = NULL ;
int V_32 ;
V_81 = F_57 () ;
if ( ! V_81 ) {
F_12 ( L_38 ) ;
goto V_107;
}
V_2 -> V_24 . V_61 = V_81 ;
F_58 ( V_81 , V_2 ) ;
V_81 -> V_108 = V_109 ;
V_81 -> V_110 = F_43 ;
V_81 -> V_111 = F_41 ;
V_81 -> V_112 = F_40 ;
V_81 -> V_113 = F_35 ;
V_81 -> V_114 = F_34 ;
F_10 ( V_2 , V_42 ) ;
V_81 -> V_46 = V_2 -> V_24 . V_46 ;
V_32 = F_59 ( V_81 ) ;
if ( V_32 < 0 ) {
F_12 ( L_39 ) ;
goto V_115;
}
#ifdef F_60
F_61 ( V_81 ) ;
#endif
return 0 ;
V_115:
F_62 ( V_81 ) ;
V_107:
F_63 ( V_2 -> V_8 . V_116 ) ;
F_31 ( V_2 ) ;
F_33 ( V_2 ) ;
return - V_56 ;
}
struct V_1 * F_64 ( void * V_117 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 ) {
F_12 ( L_40 ) ;
goto V_119;
}
V_2 -> V_3 = F_65 ( sizeof( * V_2 -> V_3 ) , V_118 ) ;
if ( ! V_2 -> V_3 ) {
F_12 ( L_41 ) ;
goto V_120;
}
F_28 ( V_2 ) ;
F_7 ( L_42 ) ;
V_2 -> V_8 . V_2 = V_2 ;
F_66 ( & V_2 -> V_103 ) ;
F_30 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_116 = F_67 ( F_45 ,
& V_2 -> V_8 , L_43 ) ;
V_2 -> V_24 . V_117 = V_117 ;
V_2 -> V_24 . V_101 = true ;
return V_2 ;
V_120:
F_33 ( V_2 ) ;
V_119:
return NULL ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
V_81 = V_2 -> V_24 . V_61 ;
F_2 ( & V_2 -> V_3 -> V_27 ) ;
F_63 ( V_2 -> V_8 . V_116 ) ;
#ifdef F_60
F_69 ( V_81 ) ;
#endif
F_70 ( V_81 ) ;
F_62 ( V_81 ) ;
V_2 -> V_24 . V_61 = NULL ;
F_31 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
