static long F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
struct V_3 V_5 ;
V_5 . V_6 = F_2 ( V_2 -> V_7 ) ;
V_5 . V_8 = 0 ;
V_5 . V_9 = V_2 -> V_10 ;
V_5 . V_11 = V_2 -> V_12 ;
V_5 . V_13 = V_2 -> V_14 ;
V_5 . V_15 = F_3 ( F_4 () , V_2 -> V_16 ) ;
V_5 . V_17 = F_5 ( F_4 () , V_2 -> V_18 ) ;
V_5 . V_19 = F_2 ( V_2 -> V_20 ) ;
V_5 . V_21 = V_2 -> V_22 ;
V_5 . V_23 = V_2 -> V_24 ;
V_5 . V_25 = 0 ;
V_5 . V_26 = V_2 -> V_27 ;
V_5 . V_28 = V_2 -> V_29 . V_30 ;
V_5 . V_31 = V_2 -> V_29 . V_32 ;
V_5 . V_33 = V_2 -> V_34 . V_30 ;
V_5 . V_35 = V_2 -> V_34 . V_32 ;
V_5 . V_36 = V_2 -> ctime . V_30 ;
V_5 . V_37 = V_2 -> ctime . V_32 ;
V_5 . V_38 = V_2 -> V_10 ;
return F_6 ( V_4 , & V_5 , sizeof( V_5 ) ) ? - V_39 : 0 ;
}
T_2 long F_7 ( const char T_1 * V_40 ,
struct V_3 T_1 * V_4 )
{
struct V_1 V_2 ;
int error = F_8 ( V_40 , & V_2 ) ;
if ( ! error )
error = F_1 ( & V_2 , V_4 ) ;
return error ;
}
T_2 long F_9 ( const char T_1 * V_40 ,
struct V_3 T_1 * V_4 )
{
struct V_1 V_2 ;
int error = F_10 ( V_40 , & V_2 ) ;
if ( ! error )
error = F_1 ( & V_2 , V_4 ) ;
return error ;
}
T_2 long F_11 ( unsigned long V_41 ,
struct V_3 T_1 * V_4 )
{
struct V_1 V_2 ;
int error = F_12 ( V_41 , & V_2 ) ;
if ( ! error )
error = F_1 ( & V_2 , V_4 ) ;
return error ;
}
T_2 long F_13 ( int V_42 ,
const char T_1 * V_40 ,
struct V_3 T_1 * V_4 ,
int V_43 )
{
struct V_1 V_2 ;
int error ;
error = F_14 ( V_42 , V_40 , & V_2 , V_43 ) ;
if ( error )
return error ;
return F_1 ( & V_2 , V_4 ) ;
}
static long F_15 ( unsigned int V_41 , unsigned int V_44 ,
unsigned long V_45 )
{
struct V_46 V_47 ;
struct V_48 V_49 ;
T_3 V_50 ;
long V_51 ;
if ( F_16 ( & V_49 , (struct V_48 T_1 * ) V_45 ,
sizeof( V_49 ) ) )
return - V_39 ;
V_47 . V_52 = V_49 . V_52 ;
V_47 . V_53 = V_49 . V_53 ;
V_47 . V_54 = V_49 . V_54 ;
V_47 . V_55 = V_49 . V_55 ;
V_47 . V_56 = V_49 . V_56 ;
V_50 = F_17 () ;
F_18 ( V_57 ) ;
V_51 = F_19 ( V_41 , V_44 , ( unsigned long ) & V_47 ) ;
F_18 ( V_50 ) ;
if ( ! V_51 && ( V_44 == V_58 || V_44 == V_59 ) ) {
V_49 . V_52 = V_47 . V_52 ;
V_49 . V_53 = V_47 . V_53 ;
V_49 . V_54 = V_47 . V_54 ;
V_49 . V_55 = V_47 . V_55 ;
V_49 . V_56 = V_47 . V_56 ;
if ( F_6 ( (struct V_48 T_1 * ) V_45 ,
& V_49 , sizeof( V_49 ) ) )
V_51 = - V_39 ;
}
return V_51 ;
}
T_2 long F_20 ( unsigned int V_41 , unsigned int V_44 ,
unsigned long V_45 )
{
switch ( V_44 ) {
case V_59 :
case V_60 :
case V_61 :
case V_58 :
case V_62 :
case V_63 :
return F_15 ( V_41 , V_44 , V_45 ) ;
default:
return F_19 ( V_41 , V_44 , V_45 ) ;
}
}
T_2 long F_21 ( int V_64 , int V_65 , int V_41 ,
struct V_66 T_1 * V_67 )
{
struct V_66 V_49 ;
struct V_68 V_47 ;
T_3 V_50 ;
long V_51 ;
if ( V_65 == V_69 )
return F_22 ( V_64 , V_65 , V_41 , NULL ) ;
if ( F_16 ( & V_49 , V_67 , sizeof( V_49 ) ) )
return - V_39 ;
V_47 . V_70 = V_49 . V_70 ;
V_47 . V_71 = V_49 . V_71 ;
V_50 = F_17 () ;
F_18 ( V_57 ) ;
V_51 = F_22 ( V_64 , V_65 , V_41 , & V_47 ) ;
F_18 ( V_50 ) ;
return V_51 ;
}
T_2 long F_23 ( int V_64 ,
struct V_66 T_1 * V_70 ,
int V_72 , int V_73 )
{
struct V_68 * V_74 ;
T_3 V_50 ;
long V_51 , V_75 , V_76 ;
if ( V_72 <= 0 ||
V_72 > ( V_77 / sizeof( * V_74 ) ) ||
V_72 > ( V_77 / sizeof( * V_70 ) ) )
return - V_78 ;
if ( ! F_24 ( V_79 , V_70 , sizeof( * V_70 ) * V_72 ) )
return - V_39 ;
V_74 = F_25 ( sizeof( * V_74 ) * V_72 , V_80 ) ;
if ( ! V_74 )
return - V_81 ;
V_50 = F_17 () ;
F_18 ( V_57 ) ;
V_51 = F_26 ( V_64 , V_74 , V_72 , V_73 ) ;
F_18 ( V_50 ) ;
V_75 = 0 ;
for ( V_76 = 0 ; V_76 < V_51 ; V_76 ++ ) {
F_27 ( V_74 [ V_76 ] . V_70 , & V_70 -> V_70 , V_75 ) ;
F_27 ( V_74 [ V_76 ] . V_71 , & V_70 -> V_71 , V_75 ) ;
V_70 ++ ;
}
F_28 ( V_74 ) ;
return V_75 ? - V_39 : V_51 ;
}
T_2 long F_29 ( int V_82 ,
struct V_83 T_1 * V_84 ,
unsigned V_85 ,
const struct V_86 T_1 * V_73 )
{
struct V_87 * V_88 ;
struct V_86 V_89 ;
long V_75 ;
int V_76 ;
if ( V_85 < 1 || V_85 > V_90 )
return - V_78 ;
if ( ! F_24 ( V_91 , V_84 , sizeof( * V_84 ) * V_85 ) )
return - V_39 ;
V_88 = F_25 ( sizeof( * V_88 ) * V_85 , V_80 ) ;
if ( ! V_88 )
return - V_81 ;
V_75 = 0 ;
for ( V_76 = 0 ; V_76 < V_85 ; V_76 ++ ) {
F_30 ( V_88 [ V_76 ] . V_92 , & V_84 -> V_92 , V_75 ) ;
F_30 ( V_88 [ V_76 ] . V_93 , & V_84 -> V_93 , V_75 ) ;
F_30 ( V_88 [ V_76 ] . V_94 , & V_84 -> V_94 , V_75 ) ;
V_84 ++ ;
}
if ( V_73 ) {
V_75 |= F_16 ( & V_89 , V_73 , sizeof( * V_73 ) ) ;
V_73 = & V_89 ;
}
if ( V_75 ) {
V_75 = - V_39 ;
} else {
T_3 V_50 = F_17 () ;
F_18 ( V_57 ) ;
V_75 = F_31 ( V_82 , V_88 , V_85 , V_73 ) ;
F_18 ( V_50 ) ;
}
F_28 ( V_88 ) ;
return V_75 ;
}
T_2 long F_32 ( int V_82 , struct V_83 T_1 * V_84 ,
unsigned V_85 )
{
return F_29 ( V_82 , V_84 , V_85 , NULL ) ;
}
T_2 int F_33 ( T_4 V_95 , int V_96 , int V_97 , int V_98 ,
void T_1 * V_99 , long V_100 )
{
switch ( V_95 & 0xffff ) {
case V_101 :
return F_29 ( V_96 ,
(struct V_83 T_1 * ) V_99 ,
V_97 , NULL ) ;
case V_102 :
return F_29 ( V_96 ,
(struct V_83 T_1 * ) V_99 ,
V_97 ,
( const struct V_86 T_1 * ) V_100 ) ;
default:
return F_34 ( V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ) ;
}
}
T_2 long F_35 ( int V_41 , struct V_103 T_1 * V_104 , int V_105 )
{
T_5 V_106 ;
if ( V_105 == 112 &&
F_36 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
V_105 = 110 ;
return F_37 ( V_41 , V_104 , V_105 ) ;
}
T_2 long F_38 ( int V_41 , struct V_103 T_1 * V_104 , int V_105 )
{
T_5 V_106 ;
if ( V_105 == 112 &&
F_36 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
V_105 = 110 ;
return F_39 ( V_41 , V_104 , V_105 ) ;
}
T_2 long F_40 ( int V_41 , void T_1 * V_108 ,
T_6 V_109 , unsigned V_110 ,
struct V_103 T_1 * V_104 ,
int V_105 )
{
T_5 V_106 ;
if ( V_105 == 112 &&
F_36 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
V_105 = 110 ;
return F_41 ( V_41 , V_108 , V_109 , V_110 , V_104 , V_105 ) ;
}
T_2 long F_42 ( int V_41 , struct V_111 T_1 * V_112 , unsigned V_110 )
{
struct V_103 T_1 * V_104 ;
int V_113 ;
T_5 V_106 ;
if ( V_112 &&
F_36 ( V_113 , & V_112 -> V_113 ) == 0 &&
V_113 == 112 &&
F_36 ( V_104 , & V_112 -> V_114 ) == 0 &&
F_36 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
{
F_43 ( 110 , & V_112 -> V_113 ) ;
}
return F_44 ( V_41 , V_112 , V_110 ) ;
}
T_2 long F_45 ( int V_95 , unsigned long T_1 * args )
{
unsigned long V_115 = - V_39 , V_116 [ 6 ] ;
switch ( V_95 ) {
case V_117 :
if ( F_16 ( V_116 , args , 3 * sizeof( long ) ) == 0 )
V_115 = F_35 ( V_116 [ 0 ] , (struct V_103 T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] ) ;
break;
case V_118 :
if ( F_16 ( V_116 , args , 3 * sizeof( long ) ) == 0 )
V_115 = F_38 ( V_116 [ 0 ] , (struct V_103 T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] ) ;
break;
case V_119 :
if ( F_16 ( V_116 , args , 6 * sizeof( long ) ) == 0 )
V_115 = F_40 ( V_116 [ 0 ] , ( void T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] , V_116 [ 3 ] ,
(struct V_103 T_1 * ) V_116 [ 4 ] , V_116 [ 5 ] ) ;
break;
case V_120 :
if ( F_16 ( V_116 , args , 3 * sizeof( long ) ) == 0 )
V_115 = F_42 ( V_116 [ 0 ] , (struct V_111 T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] ) ;
break;
default:
V_115 = F_46 ( V_95 , args ) ;
}
return V_115 ;
}
