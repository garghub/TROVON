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
if ( V_72 <= 0 || V_72 > ( V_77 / sizeof( struct V_68 ) ) )
return - V_78 ;
V_74 = F_24 ( sizeof( * V_74 ) * V_72 , V_79 ) ;
if ( ! V_74 )
return - V_80 ;
V_50 = F_17 () ;
F_18 ( V_57 ) ;
V_51 = F_25 ( V_64 , V_74 , V_72 , V_73 ) ;
F_18 ( V_50 ) ;
V_75 = 0 ;
for ( V_76 = 0 ; V_76 < V_51 ; V_76 ++ ) {
F_26 ( V_74 [ V_76 ] . V_70 , & V_70 -> V_70 , V_75 ) ;
F_26 ( V_74 [ V_76 ] . V_71 , & V_70 -> V_71 , V_75 ) ;
V_70 ++ ;
}
F_27 ( V_74 ) ;
return V_75 ? - V_39 : V_51 ;
}
T_2 long F_28 ( int V_81 ,
struct V_82 T_1 * V_83 ,
unsigned V_84 ,
const struct V_85 T_1 * V_73 )
{
struct V_86 * V_87 ;
struct V_85 V_88 ;
long V_75 ;
int V_76 ;
if ( V_84 < 1 || V_84 > V_89 )
return - V_78 ;
V_87 = F_24 ( sizeof( * V_87 ) * V_84 , V_79 ) ;
if ( ! V_87 )
return - V_80 ;
V_75 = 0 ;
for ( V_76 = 0 ; V_76 < V_84 ; V_76 ++ ) {
F_29 ( V_87 [ V_76 ] . V_90 , & V_83 -> V_90 , V_75 ) ;
F_29 ( V_87 [ V_76 ] . V_91 , & V_83 -> V_91 , V_75 ) ;
F_29 ( V_87 [ V_76 ] . V_92 , & V_83 -> V_92 , V_75 ) ;
V_83 ++ ;
}
if ( V_73 ) {
V_75 |= F_16 ( & V_88 , V_73 , sizeof( * V_73 ) ) ;
V_73 = & V_88 ;
}
if ( V_75 ) {
V_75 = - V_39 ;
} else {
T_3 V_50 = F_17 () ;
F_18 ( V_57 ) ;
V_75 = F_30 ( V_81 , V_87 , V_84 , V_73 ) ;
F_18 ( V_50 ) ;
}
F_27 ( V_87 ) ;
return V_75 ;
}
T_2 long F_31 ( int V_81 , struct V_82 T_1 * V_83 ,
unsigned V_84 )
{
return F_28 ( V_81 , V_83 , V_84 , NULL ) ;
}
T_2 int F_32 ( T_4 V_93 , int V_94 , int V_95 , int V_96 ,
void T_1 * V_97 , long V_98 )
{
switch ( V_93 & 0xffff ) {
case V_99 :
return F_28 ( V_94 ,
(struct V_82 T_1 * ) V_97 ,
V_95 , NULL ) ;
case V_100 :
return F_28 ( V_94 ,
(struct V_82 T_1 * ) V_97 ,
V_95 ,
( const struct V_85 T_1 * ) V_98 ) ;
default:
return F_33 ( V_93 , V_94 , V_95 , V_96 , V_97 , V_98 ) ;
}
}
T_2 long F_34 ( int V_41 , struct V_101 T_1 * V_102 , int V_103 )
{
T_5 V_104 ;
if ( V_103 == 112 &&
F_35 ( V_104 , & V_102 -> V_104 ) == 0 &&
V_104 == V_105 )
V_103 = 110 ;
return F_36 ( V_41 , V_102 , V_103 ) ;
}
T_2 long F_37 ( int V_41 , struct V_101 T_1 * V_102 , int V_103 )
{
T_5 V_104 ;
if ( V_103 == 112 &&
F_35 ( V_104 , & V_102 -> V_104 ) == 0 &&
V_104 == V_105 )
V_103 = 110 ;
return F_38 ( V_41 , V_102 , V_103 ) ;
}
T_2 long F_39 ( int V_41 , void T_1 * V_106 ,
T_6 V_107 , unsigned V_108 ,
struct V_101 T_1 * V_102 ,
int V_103 )
{
T_5 V_104 ;
if ( V_103 == 112 &&
F_35 ( V_104 , & V_102 -> V_104 ) == 0 &&
V_104 == V_105 )
V_103 = 110 ;
return F_40 ( V_41 , V_106 , V_107 , V_108 , V_102 , V_103 ) ;
}
T_2 long F_41 ( int V_41 , struct V_109 T_1 * V_110 , unsigned V_108 )
{
struct V_101 T_1 * V_102 ;
int V_111 ;
T_5 V_104 ;
if ( V_110 &&
F_35 ( V_111 , & V_110 -> V_111 ) == 0 &&
V_111 == 112 &&
F_35 ( V_102 , & V_110 -> V_112 ) == 0 &&
F_35 ( V_104 , & V_102 -> V_104 ) == 0 &&
V_104 == V_105 )
{
F_42 ( 110 , & V_110 -> V_111 ) ;
}
return F_43 ( V_41 , V_110 , V_108 ) ;
}
T_2 long F_44 ( int V_93 , unsigned long T_1 * args )
{
unsigned long V_113 = - V_39 , V_114 [ 6 ] ;
switch ( V_93 ) {
case V_115 :
if ( F_16 ( V_114 , args , 3 * sizeof( long ) ) == 0 )
V_113 = F_34 ( V_114 [ 0 ] , (struct V_101 T_1 * ) V_114 [ 1 ] , V_114 [ 2 ] ) ;
break;
case V_116 :
if ( F_16 ( V_114 , args , 3 * sizeof( long ) ) == 0 )
V_113 = F_37 ( V_114 [ 0 ] , (struct V_101 T_1 * ) V_114 [ 1 ] , V_114 [ 2 ] ) ;
break;
case V_117 :
if ( F_16 ( V_114 , args , 6 * sizeof( long ) ) == 0 )
V_113 = F_39 ( V_114 [ 0 ] , ( void T_1 * ) V_114 [ 1 ] , V_114 [ 2 ] , V_114 [ 3 ] ,
(struct V_101 T_1 * ) V_114 [ 4 ] , V_114 [ 5 ] ) ;
break;
case V_118 :
if ( F_16 ( V_114 , args , 3 * sizeof( long ) ) == 0 )
V_113 = F_41 ( V_114 [ 0 ] , (struct V_109 T_1 * ) V_114 [ 1 ] , V_114 [ 2 ] ) ;
break;
default:
V_113 = F_45 ( V_93 , args ) ;
}
return V_113 ;
}
