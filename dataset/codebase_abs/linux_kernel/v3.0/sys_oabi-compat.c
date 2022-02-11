static long F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
struct V_3 V_5 ;
V_5 . V_6 = F_2 ( V_2 -> V_7 ) ;
V_5 . V_8 = 0 ;
V_5 . V_9 = V_2 -> V_10 ;
V_5 . V_11 = V_2 -> V_12 ;
V_5 . V_13 = V_2 -> V_14 ;
V_5 . V_15 = V_2 -> V_16 ;
V_5 . V_17 = V_2 -> V_18 ;
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
return F_3 ( V_4 , & V_5 , sizeof( V_5 ) ) ? - V_39 : 0 ;
}
T_2 long F_4 ( const char T_1 * V_40 ,
struct V_3 T_1 * V_4 )
{
struct V_1 V_2 ;
int error = F_5 ( V_40 , & V_2 ) ;
if ( ! error )
error = F_1 ( & V_2 , V_4 ) ;
return error ;
}
T_2 long F_6 ( const char T_1 * V_40 ,
struct V_3 T_1 * V_4 )
{
struct V_1 V_2 ;
int error = F_7 ( V_40 , & V_2 ) ;
if ( ! error )
error = F_1 ( & V_2 , V_4 ) ;
return error ;
}
T_2 long F_8 ( unsigned long V_41 ,
struct V_3 T_1 * V_4 )
{
struct V_1 V_2 ;
int error = F_9 ( V_41 , & V_2 ) ;
if ( ! error )
error = F_1 ( & V_2 , V_4 ) ;
return error ;
}
T_2 long F_10 ( int V_42 ,
const char T_1 * V_40 ,
struct V_3 T_1 * V_4 ,
int V_43 )
{
struct V_1 V_2 ;
int error ;
error = F_11 ( V_42 , V_40 , & V_2 , V_43 ) ;
if ( error )
return error ;
return F_1 ( & V_2 , V_4 ) ;
}
T_2 long F_12 ( unsigned int V_41 , unsigned int V_44 ,
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
if ( F_13 ( & V_47 , (struct V_46 T_1 * ) V_45 ,
sizeof( V_47 ) ) )
return - V_39 ;
V_49 . V_57 = V_47 . V_57 ;
V_49 . V_58 = V_47 . V_58 ;
V_49 . V_59 = V_47 . V_59 ;
V_49 . V_60 = V_47 . V_60 ;
V_49 . V_61 = V_47 . V_61 ;
V_52 = ( unsigned long ) & V_49 ;
V_50 = F_14 () ;
F_15 ( V_62 ) ;
}
V_53 = F_16 ( V_41 , V_44 , V_52 ) ;
switch ( V_44 ) {
case V_54 :
if ( ! V_53 ) {
V_47 . V_57 = V_49 . V_57 ;
V_47 . V_58 = V_49 . V_58 ;
V_47 . V_59 = V_49 . V_59 ;
V_47 . V_60 = V_49 . V_60 ;
V_47 . V_61 = V_49 . V_61 ;
if ( F_3 ( (struct V_46 T_1 * ) V_45 ,
& V_47 , sizeof( V_47 ) ) )
V_53 = - V_39 ;
}
case V_55 :
case V_56 :
F_15 ( V_50 ) ;
}
return V_53 ;
}
T_2 long F_17 ( int V_63 , int V_64 , int V_41 ,
struct V_65 T_1 * V_66 )
{
struct V_65 V_47 ;
struct V_67 V_49 ;
T_3 V_50 ;
long V_53 ;
if ( V_64 == V_68 )
return F_18 ( V_63 , V_64 , V_41 , NULL ) ;
if ( F_13 ( & V_47 , V_66 , sizeof( V_47 ) ) )
return - V_39 ;
V_49 . V_69 = V_47 . V_69 ;
V_49 . V_70 = V_47 . V_70 ;
V_50 = F_14 () ;
F_15 ( V_62 ) ;
V_53 = F_18 ( V_63 , V_64 , V_41 , & V_49 ) ;
F_15 ( V_50 ) ;
return V_53 ;
}
T_2 long F_19 ( int V_63 ,
struct V_65 T_1 * V_69 ,
int V_71 , int V_72 )
{
struct V_67 * V_73 ;
T_3 V_50 ;
long V_53 , V_74 , V_75 ;
if ( V_71 <= 0 || V_71 > ( V_76 / sizeof( struct V_67 ) ) )
return - V_77 ;
V_73 = F_20 ( sizeof( * V_73 ) * V_71 , V_78 ) ;
if ( ! V_73 )
return - V_79 ;
V_50 = F_14 () ;
F_15 ( V_62 ) ;
V_53 = F_21 ( V_63 , V_73 , V_71 , V_72 ) ;
F_15 ( V_50 ) ;
V_74 = 0 ;
for ( V_75 = 0 ; V_75 < V_53 ; V_75 ++ ) {
F_22 ( V_73 [ V_75 ] . V_69 , & V_69 -> V_69 , V_74 ) ;
F_22 ( V_73 [ V_75 ] . V_70 , & V_69 -> V_70 , V_74 ) ;
V_69 ++ ;
}
F_23 ( V_73 ) ;
return V_74 ? - V_39 : V_53 ;
}
T_2 long F_24 ( int V_80 ,
struct V_81 T_1 * V_82 ,
unsigned V_83 ,
const struct V_84 T_1 * V_72 )
{
struct V_85 * V_86 ;
struct V_84 V_87 ;
long V_74 ;
int V_75 ;
if ( V_83 < 1 || V_83 > V_88 )
return - V_77 ;
V_86 = F_20 ( sizeof( * V_86 ) * V_83 , V_78 ) ;
if ( ! V_86 )
return - V_79 ;
V_74 = 0 ;
for ( V_75 = 0 ; V_75 < V_83 ; V_75 ++ ) {
F_25 ( V_86 [ V_75 ] . V_89 , & V_82 -> V_89 , V_74 ) ;
F_25 ( V_86 [ V_75 ] . V_90 , & V_82 -> V_90 , V_74 ) ;
F_25 ( V_86 [ V_75 ] . V_91 , & V_82 -> V_91 , V_74 ) ;
V_82 ++ ;
}
if ( V_72 ) {
V_74 |= F_13 ( & V_87 , V_72 , sizeof( * V_72 ) ) ;
V_72 = & V_87 ;
}
if ( V_74 ) {
V_74 = - V_39 ;
} else {
T_3 V_50 = F_14 () ;
F_15 ( V_62 ) ;
V_74 = F_26 ( V_80 , V_86 , V_83 , V_72 ) ;
F_15 ( V_50 ) ;
}
F_23 ( V_86 ) ;
return V_74 ;
}
T_2 long F_27 ( int V_80 , struct V_81 T_1 * V_82 ,
unsigned V_83 )
{
return F_24 ( V_80 , V_82 , V_83 , NULL ) ;
}
T_2 int F_28 ( T_4 V_92 , int V_93 , int V_94 , int V_95 ,
void T_1 * V_96 , long V_97 )
{
switch ( V_92 & 0xffff ) {
case V_98 :
return F_24 ( V_93 ,
(struct V_81 T_1 * ) V_96 ,
V_94 , NULL ) ;
case V_99 :
return F_24 ( V_93 ,
(struct V_81 T_1 * ) V_96 ,
V_94 ,
( const struct V_84 T_1 * ) V_97 ) ;
default:
return F_29 ( V_92 , V_93 , V_94 , V_95 , V_96 , V_97 ) ;
}
}
T_2 long F_30 ( int V_41 , struct V_100 T_1 * V_101 , int V_102 )
{
T_5 V_103 ;
if ( V_102 == 112 &&
F_31 ( V_103 , & V_101 -> V_103 ) == 0 &&
V_103 == V_104 )
V_102 = 110 ;
return F_32 ( V_41 , V_101 , V_102 ) ;
}
T_2 long F_33 ( int V_41 , struct V_100 T_1 * V_101 , int V_102 )
{
T_5 V_103 ;
if ( V_102 == 112 &&
F_31 ( V_103 , & V_101 -> V_103 ) == 0 &&
V_103 == V_104 )
V_102 = 110 ;
return F_34 ( V_41 , V_101 , V_102 ) ;
}
T_2 long F_35 ( int V_41 , void T_1 * V_105 ,
T_6 V_106 , unsigned V_107 ,
struct V_100 T_1 * V_101 ,
int V_102 )
{
T_5 V_103 ;
if ( V_102 == 112 &&
F_31 ( V_103 , & V_101 -> V_103 ) == 0 &&
V_103 == V_104 )
V_102 = 110 ;
return F_36 ( V_41 , V_105 , V_106 , V_107 , V_101 , V_102 ) ;
}
T_2 long F_37 ( int V_41 , struct V_108 T_1 * V_109 , unsigned V_107 )
{
struct V_100 T_1 * V_101 ;
int V_110 ;
T_5 V_103 ;
if ( V_109 &&
F_31 ( V_110 , & V_109 -> V_110 ) == 0 &&
V_110 == 112 &&
F_31 ( V_101 , & V_109 -> V_111 ) == 0 &&
F_31 ( V_103 , & V_101 -> V_103 ) == 0 &&
V_103 == V_104 )
{
F_38 ( 110 , & V_109 -> V_110 ) ;
}
return F_39 ( V_41 , V_109 , V_107 ) ;
}
T_2 long F_40 ( int V_92 , unsigned long T_1 * args )
{
unsigned long V_112 = - V_39 , V_113 [ 6 ] ;
switch ( V_92 ) {
case V_114 :
if ( F_13 ( V_113 , args , 3 * sizeof( long ) ) == 0 )
V_112 = F_30 ( V_113 [ 0 ] , (struct V_100 T_1 * ) V_113 [ 1 ] , V_113 [ 2 ] ) ;
break;
case V_115 :
if ( F_13 ( V_113 , args , 3 * sizeof( long ) ) == 0 )
V_112 = F_33 ( V_113 [ 0 ] , (struct V_100 T_1 * ) V_113 [ 1 ] , V_113 [ 2 ] ) ;
break;
case V_116 :
if ( F_13 ( V_113 , args , 6 * sizeof( long ) ) == 0 )
V_112 = F_35 ( V_113 [ 0 ] , ( void T_1 * ) V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 3 ] ,
(struct V_100 T_1 * ) V_113 [ 4 ] , V_113 [ 5 ] ) ;
break;
case V_117 :
if ( F_13 ( V_113 , args , 3 * sizeof( long ) ) == 0 )
V_112 = F_37 ( V_113 [ 0 ] , (struct V_108 T_1 * ) V_113 [ 1 ] , V_113 [ 2 ] ) ;
break;
default:
V_112 = F_41 ( V_92 , args ) ;
}
return V_112 ;
}
