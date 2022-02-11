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
T_2 long F_15 ( unsigned int V_41 , unsigned int V_44 ,
unsigned long V_45 )
{
struct V_46 V_47 ;
struct V_48 V_49 ;
T_3 V_50 = V_51 ;
unsigned long V_52 = V_45 ;
int V_53 ;
switch ( V_44 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
if ( F_16 ( & V_47 , (struct V_46 T_1 * ) V_45 ,
sizeof( V_47 ) ) )
return - V_39 ;
V_49 . V_60 = V_47 . V_60 ;
V_49 . V_61 = V_47 . V_61 ;
V_49 . V_62 = V_47 . V_62 ;
V_49 . V_63 = V_47 . V_63 ;
V_49 . V_64 = V_47 . V_64 ;
V_52 = ( unsigned long ) & V_49 ;
V_50 = F_17 () ;
F_18 ( V_65 ) ;
}
V_53 = F_19 ( V_41 , V_44 , V_52 ) ;
switch ( V_44 ) {
case V_57 :
if ( ! V_53 ) {
V_47 . V_60 = V_49 . V_60 ;
V_47 . V_61 = V_49 . V_61 ;
V_47 . V_62 = V_49 . V_62 ;
V_47 . V_63 = V_49 . V_63 ;
V_47 . V_64 = V_49 . V_64 ;
if ( F_6 ( (struct V_46 T_1 * ) V_45 ,
& V_47 , sizeof( V_47 ) ) )
V_53 = - V_39 ;
}
case V_58 :
case V_59 :
F_18 ( V_50 ) ;
}
return V_53 ;
}
T_2 long F_20 ( int V_66 , int V_67 , int V_41 ,
struct V_68 T_1 * V_69 )
{
struct V_68 V_47 ;
struct V_70 V_49 ;
T_3 V_50 ;
long V_53 ;
if ( V_67 == V_71 )
return F_21 ( V_66 , V_67 , V_41 , NULL ) ;
if ( F_16 ( & V_47 , V_69 , sizeof( V_47 ) ) )
return - V_39 ;
V_49 . V_72 = V_47 . V_72 ;
V_49 . V_73 = V_47 . V_73 ;
V_50 = F_17 () ;
F_18 ( V_65 ) ;
V_53 = F_21 ( V_66 , V_67 , V_41 , & V_49 ) ;
F_18 ( V_50 ) ;
return V_53 ;
}
T_2 long F_22 ( int V_66 ,
struct V_68 T_1 * V_72 ,
int V_74 , int V_75 )
{
struct V_70 * V_76 ;
T_3 V_50 ;
long V_53 , V_77 , V_78 ;
if ( V_74 <= 0 || V_74 > ( V_79 / sizeof( struct V_70 ) ) )
return - V_80 ;
V_76 = F_23 ( sizeof( * V_76 ) * V_74 , V_81 ) ;
if ( ! V_76 )
return - V_82 ;
V_50 = F_17 () ;
F_18 ( V_65 ) ;
V_53 = F_24 ( V_66 , V_76 , V_74 , V_75 ) ;
F_18 ( V_50 ) ;
V_77 = 0 ;
for ( V_78 = 0 ; V_78 < V_53 ; V_78 ++ ) {
F_25 ( V_76 [ V_78 ] . V_72 , & V_72 -> V_72 , V_77 ) ;
F_25 ( V_76 [ V_78 ] . V_73 , & V_72 -> V_73 , V_77 ) ;
V_72 ++ ;
}
F_26 ( V_76 ) ;
return V_77 ? - V_39 : V_53 ;
}
T_2 long F_27 ( int V_83 ,
struct V_84 T_1 * V_85 ,
unsigned V_86 ,
const struct V_87 T_1 * V_75 )
{
struct V_88 * V_89 ;
struct V_87 V_90 ;
long V_77 ;
int V_78 ;
if ( V_86 < 1 || V_86 > V_91 )
return - V_80 ;
V_89 = F_23 ( sizeof( * V_89 ) * V_86 , V_81 ) ;
if ( ! V_89 )
return - V_82 ;
V_77 = 0 ;
for ( V_78 = 0 ; V_78 < V_86 ; V_78 ++ ) {
F_28 ( V_89 [ V_78 ] . V_92 , & V_85 -> V_92 , V_77 ) ;
F_28 ( V_89 [ V_78 ] . V_93 , & V_85 -> V_93 , V_77 ) ;
F_28 ( V_89 [ V_78 ] . V_94 , & V_85 -> V_94 , V_77 ) ;
V_85 ++ ;
}
if ( V_75 ) {
V_77 |= F_16 ( & V_90 , V_75 , sizeof( * V_75 ) ) ;
V_75 = & V_90 ;
}
if ( V_77 ) {
V_77 = - V_39 ;
} else {
T_3 V_50 = F_17 () ;
F_18 ( V_65 ) ;
V_77 = F_29 ( V_83 , V_89 , V_86 , V_75 ) ;
F_18 ( V_50 ) ;
}
F_26 ( V_89 ) ;
return V_77 ;
}
T_2 long F_30 ( int V_83 , struct V_84 T_1 * V_85 ,
unsigned V_86 )
{
return F_27 ( V_83 , V_85 , V_86 , NULL ) ;
}
T_2 int F_31 ( T_4 V_95 , int V_96 , int V_97 , int V_98 ,
void T_1 * V_99 , long V_100 )
{
switch ( V_95 & 0xffff ) {
case V_101 :
return F_27 ( V_96 ,
(struct V_84 T_1 * ) V_99 ,
V_97 , NULL ) ;
case V_102 :
return F_27 ( V_96 ,
(struct V_84 T_1 * ) V_99 ,
V_97 ,
( const struct V_87 T_1 * ) V_100 ) ;
default:
return F_32 ( V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ) ;
}
}
T_2 long F_33 ( int V_41 , struct V_103 T_1 * V_104 , int V_105 )
{
T_5 V_106 ;
if ( V_105 == 112 &&
F_34 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
V_105 = 110 ;
return F_35 ( V_41 , V_104 , V_105 ) ;
}
T_2 long F_36 ( int V_41 , struct V_103 T_1 * V_104 , int V_105 )
{
T_5 V_106 ;
if ( V_105 == 112 &&
F_34 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
V_105 = 110 ;
return F_37 ( V_41 , V_104 , V_105 ) ;
}
T_2 long F_38 ( int V_41 , void T_1 * V_108 ,
T_6 V_109 , unsigned V_110 ,
struct V_103 T_1 * V_104 ,
int V_105 )
{
T_5 V_106 ;
if ( V_105 == 112 &&
F_34 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
V_105 = 110 ;
return F_39 ( V_41 , V_108 , V_109 , V_110 , V_104 , V_105 ) ;
}
T_2 long F_40 ( int V_41 , struct V_111 T_1 * V_112 , unsigned V_110 )
{
struct V_103 T_1 * V_104 ;
int V_113 ;
T_5 V_106 ;
if ( V_112 &&
F_34 ( V_113 , & V_112 -> V_113 ) == 0 &&
V_113 == 112 &&
F_34 ( V_104 , & V_112 -> V_114 ) == 0 &&
F_34 ( V_106 , & V_104 -> V_106 ) == 0 &&
V_106 == V_107 )
{
F_41 ( 110 , & V_112 -> V_113 ) ;
}
return F_42 ( V_41 , V_112 , V_110 ) ;
}
T_2 long F_43 ( int V_95 , unsigned long T_1 * args )
{
unsigned long V_115 = - V_39 , V_116 [ 6 ] ;
switch ( V_95 ) {
case V_117 :
if ( F_16 ( V_116 , args , 3 * sizeof( long ) ) == 0 )
V_115 = F_33 ( V_116 [ 0 ] , (struct V_103 T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] ) ;
break;
case V_118 :
if ( F_16 ( V_116 , args , 3 * sizeof( long ) ) == 0 )
V_115 = F_36 ( V_116 [ 0 ] , (struct V_103 T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] ) ;
break;
case V_119 :
if ( F_16 ( V_116 , args , 6 * sizeof( long ) ) == 0 )
V_115 = F_38 ( V_116 [ 0 ] , ( void T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] , V_116 [ 3 ] ,
(struct V_103 T_1 * ) V_116 [ 4 ] , V_116 [ 5 ] ) ;
break;
case V_120 :
if ( F_16 ( V_116 , args , 3 * sizeof( long ) ) == 0 )
V_115 = F_40 ( V_116 [ 0 ] , (struct V_111 T_1 * ) V_116 [ 1 ] , V_116 [ 2 ] ) ;
break;
default:
V_115 = F_44 ( V_95 , args ) ;
}
return V_115 ;
}
