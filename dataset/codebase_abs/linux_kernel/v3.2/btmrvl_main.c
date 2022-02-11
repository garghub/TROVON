void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = V_5 ;
V_2 -> V_3 -> V_6 = 0 ;
V_2 -> V_3 -> V_7 ++ ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_14 ;
struct V_15 * V_16 ;
T_1 V_17 , V_18 ;
if ( V_13 -> V_19 == V_20 ) {
V_16 = ( void * ) ( V_11 -> V_14 + V_21 ) ;
V_17 = F_4 ( V_16 -> V_17 ) ;
V_18 = F_5 ( V_17 ) ;
if ( V_18 == V_22 &&
V_2 -> V_23 . V_24 ) {
V_2 -> V_23 . V_24 = false ;
V_2 -> V_3 -> V_25 = true ;
F_2 ( & V_2 -> V_3 -> V_26 ) ;
}
}
}
int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_27 * V_3 = V_2 -> V_3 ;
struct V_28 * V_29 ;
int V_30 = 0 ;
V_29 = (struct V_28 * ) V_11 -> V_14 ;
if ( V_29 -> V_16 != 0xff ) {
F_7 ( L_1 , V_29 -> V_16 ) ;
V_30 = - V_31 ;
goto exit;
}
switch ( V_29 -> V_14 [ 0 ] ) {
case V_32 :
if ( ! V_29 -> V_14 [ 2 ] ) {
if ( V_29 -> V_14 [ 1 ] == V_33 )
V_3 -> V_34 = 1 ;
else
V_3 -> V_34 = 0 ;
F_7 ( L_2 ,
( V_3 -> V_34 ) ? L_3 : L_4 ) ;
} else {
F_7 ( L_5 ) ;
}
break;
case V_35 :
if ( ! V_29 -> V_14 [ 3 ] )
F_7 ( L_6 , V_29 -> V_14 [ 1 ] ,
V_29 -> V_14 [ 2 ] ) ;
else
F_7 ( L_7 ) ;
break;
case V_36 :
if ( ! V_29 -> V_14 [ 1 ] ) {
V_3 -> V_37 = V_38 ;
if ( V_3 -> V_34 )
V_3 -> V_4 = V_39 ;
F_2 ( & V_3 -> V_26 ) ;
F_7 ( L_8 ) ;
} else {
F_7 ( L_9 ) ;
}
break;
case V_22 :
if ( V_2 -> V_23 . V_24 &&
V_29 -> V_14 [ 1 ] == V_40 ) {
F_7 ( L_10 ,
( ( V_29 -> V_14 [ 2 ] == V_41 ) ||
( V_29 -> V_14 [ 2 ] == V_42 ) ) ?
L_11 : L_12 ) ;
if ( V_29 -> V_43 > 3 && V_29 -> V_14 [ 3 ] )
V_2 -> V_23 . V_44 = V_45 ;
else
V_2 -> V_23 . V_44 = V_46 ;
F_7 ( L_13 , V_2 -> V_23 . V_44 ) ;
} else if ( V_2 -> V_23 . V_24 &&
V_29 -> V_14 [ 1 ] == V_47 ) {
F_7 ( L_10 , ( V_29 -> V_14 [ 2 ] ) ?
L_14 : L_15 ) ;
} else {
F_7 ( L_16 ) ;
V_30 = - V_31 ;
}
break;
case V_48 :
if ( V_29 -> V_14 [ 1 ] == V_49 )
V_3 -> V_4 = V_39 ;
F_7 ( L_10 ,
( V_3 -> V_4 ) ? L_17 : L_18 ) ;
break;
default:
F_7 ( L_19 , V_29 -> V_14 [ 0 ] ) ;
V_30 = - V_31 ;
break;
}
exit:
if ( ! V_30 )
F_8 ( V_11 ) ;
return V_30 ;
}
int F_9 ( struct V_1 * V_2 , int V_50 )
{
struct V_10 * V_11 ;
struct V_51 * V_52 ;
int V_30 = 0 ;
V_11 = F_10 ( sizeof( * V_52 ) , V_53 ) ;
if ( V_11 == NULL ) {
F_11 ( L_20 ) ;
return - V_54 ;
}
V_52 = (struct V_51 * ) F_12 ( V_11 , sizeof( * V_52 ) ) ;
V_52 -> V_55 = F_13 ( F_14 ( V_56 , V_22 ) ) ;
V_52 -> V_43 = 1 ;
V_52 -> V_14 [ 0 ] = V_50 ;
F_15 ( V_11 ) -> V_57 = V_58 ;
V_11 -> V_59 = ( void * ) V_2 -> V_23 . V_60 ;
F_16 ( & V_2 -> V_3 -> V_61 , V_11 ) ;
V_2 -> V_23 . V_24 = true ;
V_2 -> V_3 -> V_25 = false ;
F_7 ( L_21 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_17 ( V_2 -> V_3 -> V_26 ,
V_2 -> V_3 -> V_25 ,
F_18 ( V_62 ) ) ) {
V_30 = - V_63 ;
F_11 ( L_22 ,
V_50 , V_2 -> V_23 . V_24 ) ;
}
F_7 ( L_23 ) ;
return V_30 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_51 * V_52 ;
V_11 = F_10 ( sizeof( * V_52 ) , V_53 ) ;
if ( V_11 == NULL ) {
F_11 ( L_20 ) ;
return - V_54 ;
}
V_52 = (struct V_51 * ) F_12 ( V_11 , sizeof( * V_52 ) ) ;
V_52 -> V_55 = F_13 ( F_14 ( V_56 ,
V_32 ) ) ;
V_52 -> V_43 = 1 ;
if ( V_2 -> V_23 . V_34 )
V_52 -> V_14 [ 0 ] = V_33 ;
else
V_52 -> V_14 [ 0 ] = V_64 ;
F_15 ( V_11 ) -> V_57 = V_58 ;
V_11 -> V_59 = ( void * ) V_2 -> V_23 . V_60 ;
F_16 ( & V_2 -> V_3 -> V_61 , V_11 ) ;
F_7 ( L_24 , V_52 -> V_14 [ 0 ] ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_51 * V_52 ;
int V_30 = 0 ;
V_11 = F_10 ( sizeof( * V_52 ) , V_53 ) ;
if ( V_11 == NULL ) {
F_11 ( L_20 ) ;
return - V_54 ;
}
V_52 = (struct V_51 * ) F_12 ( V_11 , sizeof( * V_52 ) ) ;
V_52 -> V_55 = F_13 ( F_14 ( V_56 , V_36 ) ) ;
V_52 -> V_43 = 0 ;
F_15 ( V_11 ) -> V_57 = V_58 ;
V_11 -> V_59 = ( void * ) V_2 -> V_23 . V_60 ;
F_16 ( & V_2 -> V_3 -> V_61 , V_11 ) ;
F_7 ( L_25 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_17 ( V_2 -> V_3 -> V_26 ,
V_2 -> V_3 -> V_37 ,
F_18 ( V_65 ) ) ) {
V_30 = - V_63 ;
F_11 ( L_26 , V_2 -> V_3 -> V_37 ,
V_2 -> V_3 -> V_4 ,
V_2 -> V_3 -> V_6 ) ;
}
return V_30 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = NULL ;
struct V_51 * V_52 ;
int V_30 = 0 ;
if ( V_2 -> V_23 . V_66 ) {
V_2 -> V_23 . V_66 = 0 ;
V_11 = F_10 ( sizeof( * V_52 ) , V_53 ) ;
if ( V_11 == NULL ) {
F_11 ( L_20 ) ;
return - V_54 ;
}
V_52 = (struct V_51 * ) F_12 ( V_11 , sizeof( * V_52 ) ) ;
V_52 -> V_55 = F_13 ( F_14 ( V_56 , V_35 ) ) ;
V_52 -> V_43 = 2 ;
V_52 -> V_14 [ 0 ] = ( V_2 -> V_23 . V_67 & 0xff00 ) >> 8 ;
V_52 -> V_14 [ 1 ] = ( V_68 ) ( V_2 -> V_23 . V_67 & 0x00ff ) ;
F_15 ( V_11 ) -> V_57 = V_58 ;
V_11 -> V_59 = ( void * ) V_2 -> V_23 . V_60 ;
F_16 ( & V_2 -> V_3 -> V_61 , V_11 ) ;
F_7 ( L_27 ,
V_52 -> V_14 [ 0 ] , V_52 -> V_14 [ 1 ] ) ;
}
if ( V_2 -> V_23 . V_69 ) {
V_2 -> V_23 . V_69 = 0 ;
F_19 ( V_2 ) ;
}
if ( V_2 -> V_23 . V_70 ) {
V_2 -> V_23 . V_70 = 0 ;
if ( V_2 -> V_23 . V_71 ) {
V_30 = F_20 ( V_2 ) ;
} else {
V_30 = V_2 -> V_72 ( V_2 ) ;
V_2 -> V_3 -> V_37 = V_73 ;
}
}
return V_30 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_30 = 0 ;
if ( ! V_11 || ! V_11 -> V_14 )
return - V_31 ;
if ( ! V_11 -> V_74 || ( ( V_11 -> V_74 + V_75 ) > V_76 ) ) {
F_11 ( L_28 ,
V_11 -> V_74 , V_76 ) ;
return - V_31 ;
}
if ( F_23 ( V_11 ) < V_75 ) {
struct V_10 * V_77 = V_11 ;
V_11 = F_24 ( V_11 , V_75 ) ;
if ( ! V_11 ) {
F_11 ( L_29 ,
V_75 ) ;
V_11 = V_77 ;
return - V_31 ;
}
F_8 ( V_77 ) ;
}
F_25 ( V_11 , V_75 ) ;
V_11 -> V_14 [ 0 ] = ( V_11 -> V_74 & 0x0000ff ) ;
V_11 -> V_14 [ 1 ] = ( V_11 -> V_74 & 0x00ff00 ) >> 8 ;
V_11 -> V_14 [ 2 ] = ( V_11 -> V_74 & 0xff0000 ) >> 16 ;
V_11 -> V_14 [ 3 ] = F_15 ( V_11 ) -> V_57 ;
if ( V_2 -> V_78 )
V_30 = V_2 -> V_78 ( V_2 , V_11 -> V_14 , V_11 -> V_74 ) ;
return V_30 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_3 -> V_61 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
F_28 ( & V_2 -> V_3 -> V_26 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_3 -> V_61 ) ;
F_31 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_32 ( struct V_79 * V_80 ,
unsigned int V_52 , unsigned long V_81 )
{
return - V_82 ;
}
static void F_33 ( struct V_79 * V_80 )
{
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_79 * V_80 = (struct V_79 * ) V_11 -> V_59 ;
struct V_1 * V_2 = NULL ;
F_7 ( L_30 , V_11 -> V_57 , V_11 -> V_74 ) ;
if ( ! V_80 || ! V_80 -> V_83 ) {
F_11 ( L_31 ) ;
return - V_84 ;
}
V_2 = (struct V_1 * ) V_80 -> V_83 ;
if ( ! F_35 ( V_85 , & V_80 -> V_86 ) ) {
F_11 ( L_32 , V_80 -> V_86 ) ;
F_36 ( L_33 , V_87 ,
V_11 -> V_14 , V_11 -> V_74 ) ;
return - V_88 ;
}
switch ( F_15 ( V_11 ) -> V_57 ) {
case V_89 :
V_80 -> V_90 . V_91 ++ ;
break;
case V_92 :
V_80 -> V_90 . V_93 ++ ;
break;
case V_94 :
V_80 -> V_90 . V_95 ++ ;
break;
}
F_37 ( & V_2 -> V_3 -> V_61 , V_11 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
return 0 ;
}
static int F_38 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
F_30 ( & V_2 -> V_3 -> V_61 ) ;
return 0 ;
}
static int F_39 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
if ( ! F_40 ( V_85 , & V_80 -> V_86 ) )
return 0 ;
F_30 ( & V_2 -> V_3 -> V_61 ) ;
return 0 ;
}
static int F_41 ( struct V_79 * V_80 )
{
F_42 ( V_85 , & V_80 -> V_86 ) ;
return 0 ;
}
static int F_43 ( void * V_14 )
{
struct V_96 * V_97 = V_14 ;
struct V_1 * V_2 = V_97 -> V_2 ;
struct V_27 * V_3 = V_2 -> V_3 ;
T_2 V_98 ;
struct V_10 * V_11 ;
T_3 V_86 ;
F_44 ( & V_98 , V_99 ) ;
V_99 -> V_86 |= V_100 ;
for (; ; ) {
F_45 ( & V_97 -> V_9 , & V_98 ) ;
F_46 ( V_101 ) ;
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_23 . V_102 ||
F_47 ( & V_3 -> V_61 ) ) ) ) {
F_7 ( L_34 ) ;
F_48 () ;
}
F_46 ( V_103 ) ;
F_49 ( & V_97 -> V_9 , & V_98 ) ;
F_7 ( L_35 ) ;
if ( F_50 () ) {
F_7 ( L_36 ) ;
break;
}
F_51 ( & V_2 -> V_104 , V_86 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_52 ( & V_2 -> V_104 , V_86 ) ;
V_2 -> V_105 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_39 &&
! F_47 ( & V_3 -> V_61 ) ) {
F_52 ( & V_2 -> V_104 , V_86 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_72 ( V_2 ) ;
continue;
} else {
F_52 ( & V_2 -> V_104 , V_86 ) ;
}
if ( V_3 -> V_4 == V_39 )
continue;
if ( ! V_2 -> V_23 . V_102 )
continue;
V_11 = F_53 ( & V_3 -> V_61 ) ;
if ( V_11 ) {
if ( F_22 ( V_2 , V_11 ) )
V_2 -> V_23 . V_60 -> V_90 . V_106 ++ ;
else
V_2 -> V_23 . V_60 -> V_90 . V_107 += V_11 -> V_74 ;
F_8 ( V_11 ) ;
}
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = NULL ;
int V_30 ;
V_80 = F_55 () ;
if ( ! V_80 ) {
F_11 ( L_37 ) ;
goto V_108;
}
V_2 -> V_23 . V_60 = V_80 ;
V_80 -> V_83 = V_2 ;
V_80 -> V_109 = V_110 ;
V_80 -> V_111 = F_41 ;
V_80 -> V_112 = F_39 ;
V_80 -> V_113 = F_38 ;
V_80 -> V_114 = F_34 ;
V_80 -> V_115 = F_33 ;
V_80 -> V_116 = F_32 ;
V_80 -> V_117 = V_118 ;
F_9 ( V_2 , V_40 ) ;
V_80 -> V_44 = V_2 -> V_23 . V_44 ;
V_30 = F_56 ( V_80 ) ;
if ( V_30 < 0 ) {
F_11 ( L_38 ) ;
goto V_119;
}
#ifdef F_57
F_58 ( V_80 ) ;
#endif
return 0 ;
V_119:
F_59 ( V_80 ) ;
V_108:
F_60 ( V_2 -> V_8 . V_120 ) ;
F_29 ( V_2 ) ;
F_31 ( V_2 ) ;
return - V_54 ;
}
struct V_1 * F_61 ( void * V_121 )
{
struct V_1 * V_2 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_122 ) ;
if ( ! V_2 ) {
F_11 ( L_39 ) ;
goto V_123;
}
V_2 -> V_3 = F_62 ( sizeof( * V_2 -> V_3 ) , V_122 ) ;
if ( ! V_2 -> V_3 ) {
F_11 ( L_40 ) ;
goto V_124;
}
F_26 ( V_2 ) ;
F_7 ( L_41 ) ;
V_2 -> V_8 . V_2 = V_2 ;
F_63 ( & V_2 -> V_104 ) ;
F_28 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_120 = F_64 ( F_43 ,
& V_2 -> V_8 , L_42 ) ;
V_2 -> V_23 . V_121 = V_121 ;
V_2 -> V_23 . V_102 = true ;
return V_2 ;
V_124:
F_31 ( V_2 ) ;
V_123:
return NULL ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
V_80 = V_2 -> V_23 . V_60 ;
F_2 ( & V_2 -> V_3 -> V_26 ) ;
F_60 ( V_2 -> V_8 . V_120 ) ;
#ifdef F_57
F_66 ( V_80 ) ;
#endif
F_67 ( V_80 ) ;
F_59 ( V_80 ) ;
V_2 -> V_23 . V_60 = NULL ;
F_29 ( V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
