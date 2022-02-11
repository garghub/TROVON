static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_4 * V_4 = (struct V_4 * ) 0 ;
T_2 V_8 = ( T_2 ) 0LL ;
unsigned V_9 ;
int V_10 ;
if ( V_2 -> V_11 ) {
return - V_12 ;
}
V_7 = F_2 ( V_2 ) ;
if( V_7 == NULL ) {
return - V_13 ;
}
V_5 = V_7 -> V_14 ;
if ( F_3 ( ( void * ) V_5 , V_3 , sizeof( struct V_15 ) ) ) {
F_4 ( V_7 ) ;
return - V_16 ;
}
V_9 = F_5 ( V_5 -> V_17 . V_18 ) + sizeof( struct V_15 ) ;
if ( V_9 < F_5 ( V_5 -> V_17 . V_19 ) )
V_9 = F_5 ( V_5 -> V_17 . V_19 ) ;
if ( V_9 > V_2 -> V_20 ) {
T_2 V_21 ;
if ( V_9 > 2048 ) {
V_10 = - V_22 ;
goto V_23;
}
V_5 = F_6 ( V_2 -> V_24 , V_9 , & V_21 ) ;
if ( ! V_5 ) {
V_10 = - V_13 ;
goto V_23;
}
V_4 = V_7 -> V_14 ;
V_8 = V_7 -> V_8 ;
V_7 -> V_14 = V_5 ;
V_7 -> V_8 = V_21 ;
memset ( ( ( char * ) V_5 ) + V_2 -> V_20 , 0 , V_9 - V_2 -> V_20 ) ;
memcpy ( V_5 , V_4 , V_2 -> V_20 ) ;
}
if ( F_3 ( V_5 , V_3 , V_9 ) ) {
V_10 = - V_16 ;
goto V_23;
}
if ( V_5 -> V_17 . V_25 == F_7 ( V_26 ) ) {
F_8 ( V_2 ) ;
V_5 -> V_17 . V_27 = 0 ;
} else {
V_10 = F_9 ( F_5 ( V_5 -> V_17 . V_25 ) , V_7 ,
F_5 ( V_5 -> V_17 . V_18 ) , V_28 ,
1 , 1 , NULL , NULL ) ;
if ( V_10 ) {
goto V_23;
}
if ( F_10 ( V_7 ) != 0 ) {
V_10 = - V_22 ;
goto V_23;
}
}
V_10 = 0 ;
if ( F_11 ( V_3 , ( void * ) V_5 , V_9 ) )
V_10 = - V_16 ;
V_23:
if ( V_4 ) {
F_12 ( V_2 -> V_24 , V_9 , V_5 , V_7 -> V_8 ) ;
V_7 -> V_8 = V_8 ;
V_7 -> V_14 = V_4 ;
}
if ( V_10 != - V_29 )
F_4 ( V_7 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_30 * V_31 ;
int V_32 ;
V_31 = F_14 ( sizeof( struct V_30 ) , V_33 ) ;
if ( V_31 == NULL ) {
V_32 = - V_13 ;
} else {
unsigned long V_34 ;
struct V_35 * V_36 ;
struct V_30 * V_37 ;
V_31 -> type = V_38 ;
V_31 -> V_9 = sizeof( struct V_30 ) ;
V_31 -> V_39 = ( V_40 ) ( ( V_41 ) V_31 & 0xFFFFFFFF ) ;
F_15 ( & V_31 -> V_42 , 0 ) ;
V_31 -> V_43 = 0 ;
V_31 -> V_44 = 0 ;
F_16 ( & V_31 -> V_45 ) ;
V_31 -> V_46 = V_46 / V_47 ;
F_17 ( & V_2 -> V_48 , V_34 ) ;
V_36 = V_2 -> V_45 . V_49 ;
while ( V_36 != & V_2 -> V_45 ) {
V_37 = F_18 ( V_36 , struct V_30 , V_49 ) ;
if ( V_37 -> V_39 == V_31 -> V_39 ) {
V_31 -> V_39 ++ ;
V_36 = V_2 -> V_45 . V_49 ;
} else {
V_36 = V_36 -> V_49 ;
}
}
F_19 ( & V_31 -> V_49 , & V_2 -> V_45 ) ;
F_20 ( & V_2 -> V_48 , V_34 ) ;
if ( F_11 ( V_3 , & V_31 -> V_39 ,
sizeof( V_31 -> V_39 ) ) ) {
V_32 = - V_16 ;
} else {
V_32 = 0 ;
}
}
return V_32 ;
}
static int F_21 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_50 V_51 ;
struct V_6 * V_6 ;
struct V_30 * V_31 ;
int V_32 ;
struct V_35 * V_36 ;
unsigned long V_34 ;
if( F_3 ( ( void * ) & V_51 , V_3 , sizeof( struct V_50 ) ) )
return - V_16 ;
F_17 ( & V_2 -> V_48 , V_34 ) ;
V_36 = V_2 -> V_45 . V_49 ;
V_31 = NULL ;
while ( V_36 != & V_2 -> V_45 ) {
V_31 = F_18 ( V_36 , struct V_30 , V_49 ) ;
if ( V_31 -> V_39 == V_51 . V_31 ) {
break;
}
V_36 = V_36 -> V_49 ;
V_31 = NULL ;
}
if ( ! V_31 ) {
F_20 ( & V_2 -> V_48 , V_34 ) ;
F_22 ( ( V_52 L_1 ) ) ;
return - V_22 ;
}
if( ( V_31 -> type != V_38 ) ||
( V_31 -> V_9 != sizeof( struct V_30 ) ) ) {
F_20 ( & V_2 -> V_48 , V_34 ) ;
F_22 ( ( V_52 L_2 ) ) ;
return - V_22 ;
}
V_32 = 0 ;
V_53:
if ( ! F_23 ( & V_31 -> V_45 ) ) {
V_36 = V_31 -> V_45 . V_49 ;
F_24 ( V_36 ) ;
V_6 = F_18 ( V_36 , struct V_6 , V_54 ) ;
V_31 -> V_44 -- ;
F_20 ( & V_2 -> V_48 , V_34 ) ;
if ( F_11 ( V_51 . V_6 , V_6 -> V_14 , sizeof( struct V_4 ) ) ) {
F_25 ( V_6 -> V_14 ) ;
F_25 ( V_6 ) ;
return - V_16 ;
}
F_25 ( V_6 -> V_14 ) ;
F_25 ( V_6 ) ;
V_32 = 0 ;
} else {
F_20 ( & V_2 -> V_48 , V_34 ) ;
V_32 = ! V_2 -> V_55 ;
if ( V_32 && ! V_2 -> V_11 && V_2 -> V_56 && V_2 -> V_57 ) {
F_26 ( V_2 -> V_58 ) ;
F_27 ( 1 ) ;
V_2 -> V_55 = 0 ;
V_2 -> V_58 = F_28 ( V_59 , V_2 ,
L_3 , V_2 -> V_60 ) ;
F_27 ( 1 ) ;
}
if ( V_51 . V_43 ) {
if( F_29 ( & V_31 -> V_42 ) < 0 ) {
V_32 = - V_29 ;
} else {
F_17 ( & V_2 -> V_48 , V_34 ) ;
goto V_53;
}
} else {
V_32 = - V_61 ;
}
}
V_31 -> V_46 = V_46 / V_47 ;
return V_32 ;
}
int F_30 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_6 * V_6 ;
while ( ! F_23 ( & V_31 -> V_45 ) ) {
struct V_35 * V_36 ;
V_36 = V_31 -> V_45 . V_49 ;
F_24 ( V_36 ) ;
V_6 = F_18 ( V_36 , struct V_6 , V_54 ) ;
V_31 -> V_44 -- ;
F_25 ( V_6 -> V_14 ) ;
F_25 ( V_6 ) ;
}
F_24 ( & V_31 -> V_49 ) ;
V_31 -> type = 0 ;
F_25 ( V_31 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_30 * V_31 ;
int V_32 ;
unsigned long V_34 ;
struct V_35 * V_36 ;
V_36 = V_2 -> V_45 . V_49 ;
V_31 = NULL ;
while( V_36 != & V_2 -> V_45 ) {
V_31 = F_18 ( V_36 , struct V_30 , V_49 ) ;
if ( V_31 -> V_39 == ( V_40 ) ( V_62 ) V_3 )
break;
V_36 = V_36 -> V_49 ;
V_31 = NULL ;
}
if ( ! V_31 )
return 0 ;
if( ( V_31 -> type != V_38 ) ||
( V_31 -> V_9 != sizeof( struct V_30 ) ) )
return - V_22 ;
F_17 ( & V_2 -> V_48 , V_34 ) ;
V_32 = F_30 ( V_2 , V_31 ) ;
F_20 ( & V_2 -> V_48 , V_34 ) ;
return V_32 ;
}
static int F_32 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_63 V_64 ;
char * V_65 = V_66 ;
V_40 V_67 ;
V_64 . V_68 = 1 ;
V_67 = ( F_33 ( V_65 ,
& V_65 , 10 ) << 24 ) | 0x00000400 ;
V_67 += F_33 ( V_65 + 1 , & V_65 , 10 ) << 16 ;
V_67 += F_33 ( V_65 + 1 , NULL , 10 ) ;
V_64 . V_67 = F_34 ( V_67 ) ;
# ifdef F_35
V_64 . V_69 = F_34 ( F_35 ) ;
# else
V_64 . V_69 = F_34 ( 9999 ) ;
# endif
if ( F_11 ( V_3 , & V_64 , sizeof( V_64 ) ) )
return - V_16 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_6 * V_70 ;
int V_32 ;
struct V_71 * V_72 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_73 T_1 * V_75 = V_3 ;
struct V_76 T_1 * V_77 ;
struct V_76 * V_78 ;
V_40 V_79 = 0 ;
V_40 V_34 = 0 ;
T_3 V_80 = 0 ;
V_40 V_81 ;
void T_1 * V_82 [ 32 ] ;
void * V_83 [ 32 ] ;
V_40 V_84 = 0 ;
V_40 V_85 = 0 ;
V_40 V_86 , V_87 = 0 ;
int V_88 ;
if ( V_2 -> V_11 ) {
F_22 ( ( V_89 L_4 ) ) ;
return - V_12 ;
}
if ( ! F_37 ( V_90 ) ) {
F_22 ( ( V_89 L_5 ) ) ;
return - V_91 ;
}
if ( ! ( V_70 = F_2 ( V_2 ) ) ) {
return - V_13 ;
}
F_38 ( V_70 ) ;
V_70 -> V_14 -> V_17 . V_27 &= ~ F_34 ( V_92 ) ;
V_72 = (struct V_71 * ) F_39 ( V_70 ) ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
if( F_3 ( & V_79 , & V_75 -> V_44 , sizeof( V_40 ) ) ) {
F_22 ( ( V_89 L_6 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
if ( ( V_79 < ( sizeof( struct V_73 ) - sizeof( struct V_93 ) ) ) ||
( V_79 > ( V_2 -> V_20 - sizeof( struct V_15 ) ) ) ) {
V_80 = - V_22 ;
goto V_23;
}
V_74 = F_14 ( V_79 , V_33 ) ;
if ( ! V_74 ) {
F_22 ( ( V_89 L_7 ) ) ;
V_80 = - V_13 ;
goto V_23;
}
if( F_3 ( V_74 , V_75 , V_79 ) ) {
F_22 ( ( V_89 L_8 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
V_77 = V_3 + V_79 ;
V_34 = V_74 -> V_34 ;
V_72 -> V_94 = F_34 ( V_95 ) ;
V_72 -> V_96 = F_34 ( V_74 -> V_96 ) ;
V_72 -> V_97 = F_34 ( V_74 -> V_97 ) ;
V_72 -> V_98 = F_34 ( V_74 -> V_98 ) ;
V_72 -> V_99 = F_34 ( V_74 -> V_99 ) ;
V_72 -> V_34 = F_34 ( V_34 ) ;
V_72 -> V_100 = 0 ;
V_72 -> V_101 = F_34 ( V_74 -> V_101 ) ;
memcpy ( V_72 -> V_102 , V_74 -> V_102 , sizeof( V_72 -> V_102 ) ) ;
switch ( V_34 & ( V_103 | V_104 ) ) {
case V_104 :
V_81 = V_105 ;
break;
case ( V_103 | V_104 ) :
V_81 = V_106 ;
break;
case V_103 :
V_81 = V_107 ;
break;
default:
V_81 = V_108 ;
}
if ( V_74 -> V_109 . V_44 > F_40 ( V_83 ) ) {
F_22 ( ( V_89 L_9 ,
F_41 ( V_72 -> V_109 . V_44 ) ) ) ;
V_80 = - V_22 ;
goto V_23;
}
V_87 = sizeof( struct V_71 ) - sizeof( struct V_110 ) +
( ( V_74 -> V_109 . V_44 & 0xff ) * sizeof( struct V_110 ) ) ;
V_86 = V_87 + ( V_74 -> V_109 . V_44 & 0xff ) *
( sizeof( struct V_111 ) - sizeof( struct V_110 ) ) ;
if ( ( V_87 != V_79 ) && ( V_86 != V_79 ) ) {
F_22 ( ( V_89 L_10
L_11
L_12
L_13 ,
V_87 , V_86 , V_74 -> V_109 . V_44 ,
sizeof( struct V_71 ) , sizeof( struct V_110 ) ,
sizeof( struct V_111 ) , V_79 ) ) ;
V_80 = - V_22 ;
goto V_23;
}
if ( ( V_81 == V_108 ) && V_74 -> V_109 . V_44 ) {
F_22 ( ( V_89 L_14 ) ) ;
V_80 = - V_22 ;
goto V_23;
}
V_85 = 0 ;
if ( V_2 -> V_112 . V_113 & V_114 ) {
struct V_115 * V_116 = (struct V_115 * ) & V_74 -> V_109 ;
struct V_117 * V_118 = (struct V_117 * ) & V_72 -> V_109 ;
if ( V_86 == V_79 ) {
V_87 = V_86 ;
for ( V_88 = 0 ; V_88 < V_116 -> V_44 ; V_88 ++ ) {
T_4 V_119 ;
void * V_120 ;
if ( V_116 -> V_109 [ V_88 ] . V_44 >
( ( V_2 -> V_112 . V_113 &
V_121 ) ?
( V_2 -> V_122 -> V_123 << 9 ) :
65536 ) ) {
V_80 = - V_22 ;
goto V_23;
}
V_120 = F_14 ( V_116 -> V_109 [ V_88 ] . V_44 , V_33 | V_124 ) ;
if( ! V_120 ) {
F_22 ( ( V_89 L_15 ,
V_116 -> V_109 [ V_88 ] . V_44 , V_88 , V_116 -> V_44 ) ) ;
V_80 = - V_13 ;
goto V_23;
}
V_119 = ( T_4 ) V_116 -> V_109 [ V_88 ] . V_119 [ 0 ] ;
V_119 += ( ( T_4 ) V_116 -> V_109 [ V_88 ] . V_119 [ 1 ] ) << 32 ;
V_82 [ V_88 ] = ( void T_1 * ) ( V_62 ) V_119 ;
V_83 [ V_88 ] = V_120 ;
V_84 = V_88 ;
if ( V_34 & V_104 ) {
if( F_3 ( V_120 , V_82 [ V_88 ] , V_116 -> V_109 [ V_88 ] . V_44 ) ) {
F_22 ( ( V_89 L_16 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
}
V_119 = F_42 ( V_2 -> V_24 , V_120 , V_116 -> V_109 [ V_88 ] . V_44 , V_81 ) ;
V_118 -> V_109 [ V_88 ] . V_119 [ 0 ] = F_34 ( V_119 & 0xffffffff ) ;
V_118 -> V_109 [ V_88 ] . V_119 [ 1 ] = F_34 ( V_119 >> 32 ) ;
V_85 += V_116 -> V_109 [ V_88 ] . V_44 ;
V_118 -> V_109 [ V_88 ] . V_44 = F_34 ( V_116 -> V_109 [ V_88 ] . V_44 ) ;
}
} else {
struct V_125 * V_126 ;
V_126 = F_14 ( V_87 - sizeof( struct V_71 )
+ sizeof( struct V_127 ) , V_33 ) ;
if ( ! V_126 ) {
F_22 ( ( V_89 L_17 ) ) ;
V_80 = - V_13 ;
goto V_23;
}
memcpy ( V_126 , V_116 , V_87 - sizeof( struct V_71 )
+ sizeof( struct V_127 ) ) ;
V_87 = V_86 ;
for ( V_88 = 0 ; V_88 < V_126 -> V_44 ; V_88 ++ ) {
T_4 V_119 ;
void * V_120 ;
if ( V_126 -> V_109 [ V_88 ] . V_44 >
( ( V_2 -> V_112 . V_113 &
V_121 ) ?
( V_2 -> V_122 -> V_123 << 9 ) :
65536 ) ) {
F_25 ( V_126 ) ;
V_80 = - V_22 ;
goto V_23;
}
V_120 = F_14 ( V_126 -> V_109 [ V_88 ] . V_44 , V_33 | V_124 ) ;
if( ! V_120 ) {
F_22 ( ( V_89 L_15 ,
V_126 -> V_109 [ V_88 ] . V_44 , V_88 , V_126 -> V_44 ) ) ;
F_25 ( V_126 ) ;
V_80 = - V_13 ;
goto V_23;
}
V_82 [ V_88 ] = ( void T_1 * ) ( V_62 ) V_126 -> V_109 [ V_88 ] . V_119 ;
V_83 [ V_88 ] = V_120 ;
V_84 = V_88 ;
if ( V_34 & V_104 ) {
if( F_3 ( V_120 , V_82 [ V_88 ] , V_116 -> V_109 [ V_88 ] . V_44 ) ) {
F_25 ( V_126 ) ;
F_22 ( ( V_89 L_16 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
}
V_119 = F_42 ( V_2 -> V_24 , V_120 , V_126 -> V_109 [ V_88 ] . V_44 , V_81 ) ;
V_118 -> V_109 [ V_88 ] . V_119 [ 0 ] = F_34 ( V_119 & 0xffffffff ) ;
V_118 -> V_109 [ V_88 ] . V_119 [ 1 ] = F_34 ( V_119 >> 32 ) ;
V_85 += V_126 -> V_109 [ V_88 ] . V_44 ;
V_118 -> V_109 [ V_88 ] . V_44 = F_34 ( V_126 -> V_109 [ V_88 ] . V_44 ) ;
}
F_25 ( V_126 ) ;
}
V_72 -> V_44 = F_34 ( V_85 ) ;
if ( V_74 -> V_109 . V_44 )
V_118 -> V_44 = F_34 ( V_84 + 1 ) ;
else
V_118 -> V_44 = 0 ;
V_32 = F_9 ( V_128 , V_70 , V_87 , V_28 , 1 , 1 , NULL , NULL ) ;
} else {
struct V_125 * V_116 = & V_74 -> V_109 ;
struct V_127 * V_118 = & V_72 -> V_109 ;
if ( V_86 == V_79 ) {
struct V_115 * V_126 = (struct V_115 * ) V_116 ;
for ( V_88 = 0 ; V_88 < V_116 -> V_44 ; V_88 ++ ) {
V_62 V_119 ;
void * V_120 ;
if ( V_126 -> V_109 [ V_88 ] . V_44 >
( ( V_2 -> V_112 . V_113 &
V_121 ) ?
( V_2 -> V_122 -> V_123 << 9 ) :
65536 ) ) {
V_80 = - V_22 ;
goto V_23;
}
V_120 = F_14 ( V_126 -> V_109 [ V_88 ] . V_44 , V_33 | V_124 ) ;
if( ! V_120 ) {
F_22 ( ( V_89 L_15 ,
V_126 -> V_109 [ V_88 ] . V_44 , V_88 , V_126 -> V_44 ) ) ;
V_80 = - V_13 ;
goto V_23;
}
V_119 = ( T_4 ) V_126 -> V_109 [ V_88 ] . V_119 [ 0 ] ;
V_119 += ( ( T_4 ) V_126 -> V_109 [ V_88 ] . V_119 [ 1 ] ) << 32 ;
V_82 [ V_88 ] = ( void T_1 * ) V_119 ;
V_83 [ V_88 ] = V_120 ;
V_84 = V_88 ;
if ( V_34 & V_104 ) {
if( F_3 ( V_120 , V_82 [ V_88 ] , V_126 -> V_109 [ V_88 ] . V_44 ) ) {
F_22 ( ( V_89 L_16 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
}
V_119 = F_42 ( V_2 -> V_24 , V_120 , V_126 -> V_109 [ V_88 ] . V_44 , V_81 ) ;
V_118 -> V_109 [ V_88 ] . V_119 = F_34 ( V_119 & 0xffffffff ) ;
V_85 += V_126 -> V_109 [ V_88 ] . V_44 ;
V_118 -> V_109 [ V_88 ] . V_44 = F_34 ( V_126 -> V_109 [ V_88 ] . V_44 ) ;
}
} else {
for ( V_88 = 0 ; V_88 < V_116 -> V_44 ; V_88 ++ ) {
T_2 V_119 ;
void * V_120 ;
if ( V_116 -> V_109 [ V_88 ] . V_44 >
( ( V_2 -> V_112 . V_113 &
V_121 ) ?
( V_2 -> V_122 -> V_123 << 9 ) :
65536 ) ) {
V_80 = - V_22 ;
goto V_23;
}
V_120 = F_14 ( V_116 -> V_109 [ V_88 ] . V_44 , V_33 ) ;
if ( ! V_120 ) {
F_22 ( ( V_89 L_15 ,
V_116 -> V_109 [ V_88 ] . V_44 , V_88 , V_116 -> V_44 ) ) ;
V_80 = - V_13 ;
goto V_23;
}
V_82 [ V_88 ] = ( void T_1 * ) ( V_62 ) V_116 -> V_109 [ V_88 ] . V_119 ;
V_83 [ V_88 ] = V_120 ;
V_84 = V_88 ;
if ( V_34 & V_104 ) {
if( F_3 ( V_120 , V_82 [ V_88 ] ,
V_116 -> V_109 [ V_88 ] . V_44 ) ) {
F_22 ( ( V_89 L_16 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
}
V_119 = F_42 ( V_2 -> V_24 , V_120 ,
V_116 -> V_109 [ V_88 ] . V_44 , V_81 ) ;
V_118 -> V_109 [ V_88 ] . V_119 = F_34 ( V_119 ) ;
V_85 += V_116 -> V_109 [ V_88 ] . V_44 ;
V_118 -> V_109 [ V_88 ] . V_44 = F_34 ( V_116 -> V_109 [ V_88 ] . V_44 ) ;
}
}
V_72 -> V_44 = F_34 ( V_85 ) ;
if ( V_74 -> V_109 . V_44 )
V_118 -> V_44 = F_34 ( V_84 + 1 ) ;
else
V_118 -> V_44 = 0 ;
V_32 = F_9 ( V_129 , V_70 , V_87 , V_28 , 1 , 1 , NULL , NULL ) ;
}
if ( V_32 == - V_29 ) {
V_80 = - V_29 ;
goto V_23;
}
if ( V_32 != 0 ) {
F_22 ( ( V_89 L_18 ) ) ;
V_80 = - V_130 ;
goto V_23;
}
if ( V_34 & V_103 ) {
for( V_88 = 0 ; V_88 <= V_84 ; V_88 ++ ) {
V_85 = F_41 (
( V_2 -> V_112 . V_113 & V_114 )
? ( (struct V_117 * ) & V_72 -> V_109 ) -> V_109 [ V_88 ] . V_44
: V_72 -> V_109 . V_109 [ V_88 ] . V_44 ) ;
if( F_11 ( V_82 [ V_88 ] , V_83 [ V_88 ] , V_85 ) ) {
F_22 ( ( V_89 L_19 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
}
}
V_78 = (struct V_76 * ) F_39 ( V_70 ) ;
if( F_11 ( V_77 , V_78 , sizeof( struct V_76 ) ) ) {
F_22 ( ( V_89 L_20 ) ) ;
V_80 = - V_16 ;
goto V_23;
}
V_23:
F_25 ( V_74 ) ;
for( V_88 = 0 ; V_88 <= V_84 ; V_88 ++ ) {
F_25 ( V_83 [ V_88 ] ) ;
}
if ( V_80 != - V_29 ) {
F_10 ( V_70 ) ;
F_4 ( V_70 ) ;
}
return V_80 ;
}
static int F_43 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_131 V_132 ;
V_132 . V_133 = V_2 -> V_24 -> V_133 -> V_134 ;
V_132 . V_135 = F_44 ( V_2 -> V_24 -> V_136 ) ;
if ( F_11 ( V_3 , & V_132 , sizeof( struct V_131 ) ) ) {
F_22 ( ( V_89 L_21 ) ) ;
return - V_16 ;
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 , int V_137 , void T_1 * V_3 )
{
int V_32 ;
F_46 ( & V_2 -> V_138 ) ;
if ( V_2 -> V_139 ) {
V_32 = - V_140 ;
goto V_23;
}
V_32 = F_47 ( V_2 , V_137 , V_3 ) ;
if ( V_32 != - V_141 )
goto V_23;
switch ( V_137 ) {
case V_142 :
V_32 = F_32 ( V_2 , V_3 ) ;
break;
case V_143 :
case V_144 :
V_32 = F_1 ( V_2 , V_3 ) ;
break;
case V_145 :
V_32 = F_13 ( V_2 , V_3 ) ;
break;
case V_146 :
V_32 = F_21 ( V_2 , V_3 ) ;
break;
case V_147 :
V_32 = F_31 ( V_2 , V_3 ) ;
break;
case V_148 :
V_32 = F_36 ( V_2 , V_3 ) ;
break;
case V_149 :
V_32 = F_43 ( V_2 , V_3 ) ;
break;
default:
V_32 = - V_141 ;
break;
}
V_23:
F_48 ( & V_2 -> V_138 ) ;
return V_32 ;
}
