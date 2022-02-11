static void
F_1 ( struct V_1 * V_2 , int V_3 , int * V_4 ,
int * V_5 )
{
struct V_6 * V_7 ;
struct V_6 * V_8 ;
struct V_9 * V_10 ;
V_7 = F_2 ( V_2 ) ;
while ( V_7 ) {
V_8 = V_7 ;
V_7 = F_3 ( V_8 ) ;
V_10 = F_4 ( V_8 , struct V_9 , V_11 ) ;
if ( V_3 == 0 || * V_5 == V_3 )
++ ( * V_4 ) ;
else {
if ( F_5 ( V_12 , V_10 -> time + V_13 )
&& V_10 -> V_14 == 0 ) {
F_6 ( V_8 , V_2 ) ;
++ ( * V_5 ) ;
} else
++ ( * V_4 ) ;
}
}
}
static int
F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_3 = V_18 -> V_3 ;
int V_5 = 0 ;
int V_4 = 0 ;
struct V_1 * V_2 ;
V_2 = & V_19 ;
F_8 ( & V_20 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_20 ) ;
V_2 = & V_21 ;
F_8 ( & V_22 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_22 ) ;
V_2 = & V_23 ;
F_8 ( & V_24 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_24 ) ;
V_2 = & V_25 ;
F_8 ( & V_26 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_26 ) ;
return V_4 ;
}
static void
F_10 ( struct V_1 * V_2 , unsigned long V_27 ,
struct V_9 * * V_10 , char * V_28 )
{
char * V_29 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_6 * V_30 = NULL ;
struct V_6 * * V_31 = & ( V_2 -> V_6 ) ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_30 = V_7 ;
if ( V_27 > V_32 -> V_33 ) {
V_31 = & ( V_7 -> V_34 ) ;
V_7 = V_7 -> V_34 ;
}
if ( V_27 < V_32 -> V_33 ) {
V_31 = & ( V_7 -> V_35 ) ;
V_7 = V_7 -> V_35 ;
}
}
( * V_10 ) -> V_33 = V_27 ;
( * V_10 ) -> time = V_12 - ( V_36 + 1 ) ;
( * V_10 ) -> V_14 = 0 ;
sprintf ( ( * V_10 ) -> V_37 , L_1 , V_28 ) ;
V_29 = ( * V_10 ) -> V_37 + strlen ( ( * V_10 ) -> V_37 ) ;
sprintf ( V_29 , L_2 , V_27 ) ;
F_11 ( V_38 , & ( * V_10 ) -> V_39 ) ;
F_11 ( V_40 , & ( * V_10 ) -> V_39 ) ;
F_12 ( & ( * V_10 ) -> V_11 , V_30 , V_31 ) ;
F_13 ( & ( * V_10 ) -> V_11 , V_2 ) ;
}
static struct V_9 *
F_14 ( struct V_1 * V_2 , unsigned long V_27 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
if ( V_27 > V_32 -> V_33 )
V_7 = V_7 -> V_34 ;
else if ( V_27 < V_32 -> V_33 )
V_7 = V_7 -> V_35 ;
else
return V_32 ;
}
return NULL ;
}
static int
F_15 ( struct V_41 * V_41 , const void * V_42 , T_1 V_43 )
{
char * V_44 ;
V_44 = F_16 ( V_43 , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
memcpy ( V_44 , V_42 , V_43 ) ;
V_41 -> V_44 . V_42 = V_44 ;
V_41 -> V_43 = V_43 ;
return 0 ;
}
static inline void
F_17 ( struct V_41 * V_41 )
{
F_18 ( V_41 -> V_44 . V_42 ) ;
}
static void
F_19 ( struct V_47 * V_48 , char * V_37 )
{
int V_49 ;
unsigned long V_50 ;
char * V_29 ;
V_29 = V_37 ;
sprintf ( V_29 , L_1 , L_3 ) ;
V_29 = V_37 + strlen ( V_37 ) ;
sprintf ( V_29 , L_4 , V_48 -> V_51 ) ;
V_29 = V_37 + strlen ( V_37 ) ;
for ( V_49 = 0 ; V_49 < 6 ; ++ V_49 ) {
if ( V_48 -> V_52 [ V_49 ] ) {
sprintf ( V_29 , L_4 , V_48 -> V_52 [ V_49 ] ) ;
V_29 = V_37 + strlen ( V_37 ) ;
}
}
for ( V_49 = 0 ; V_49 < V_48 -> V_53 ; ++ V_49 ) {
V_50 = F_20 ( V_48 -> V_54 [ V_49 ] ) ;
sprintf ( V_29 , L_5 , V_50 ) ;
V_29 = V_37 + strlen ( V_37 ) ;
}
}
static void
F_21 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_9 * * V_10 , char * V_28 )
{
int V_55 ;
char * V_29 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_6 * V_30 = NULL ;
struct V_6 * * V_31 = & ( V_2 -> V_6 ) ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_30 = V_7 ;
V_55 = F_22 ( V_48 , & ( ( V_32 ) -> V_56 ) ) ;
if ( V_55 > 0 ) {
V_31 = & ( V_7 -> V_34 ) ;
V_7 = V_7 -> V_34 ;
} else if ( V_55 < 0 ) {
V_31 = & ( V_7 -> V_35 ) ;
V_7 = V_7 -> V_35 ;
}
}
memcpy ( & ( * V_10 ) -> V_56 , V_48 , sizeof( struct V_47 ) ) ;
( * V_10 ) -> time = V_12 - ( V_36 + 1 ) ;
( * V_10 ) -> V_14 = 0 ;
sprintf ( ( * V_10 ) -> V_37 , L_1 , V_28 ) ;
V_29 = ( * V_10 ) -> V_37 + strlen ( ( * V_10 ) -> V_37 ) ;
F_19 ( & ( * V_10 ) -> V_56 , V_29 ) ;
F_11 ( V_38 , & ( * V_10 ) -> V_39 ) ;
F_11 ( V_40 , & ( * V_10 ) -> V_39 ) ;
F_12 ( & ( * V_10 ) -> V_11 , V_30 , V_31 ) ;
F_13 ( & ( * V_10 ) -> V_11 , V_2 ) ;
}
static struct V_9 *
F_23 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_55 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_55 = F_22 ( V_48 , & ( ( V_32 ) -> V_56 ) ) ;
if ( V_55 > 0 ) {
V_7 = V_7 -> V_34 ;
} else if ( V_55 < 0 ) {
V_7 = V_7 -> V_35 ;
} else
return V_32 ;
}
return NULL ;
}
static int
F_24 ( void * V_57 )
{
F_25 () ;
return F_26 ( V_58 ) ? - V_59 : 0 ;
}
static int
F_27 ( unsigned long V_27 , T_2 V_60 , struct V_47 * V_61 )
{
int V_55 = 0 ;
struct V_41 * V_62 ;
const struct V_63 * V_64 ;
struct V_47 * V_65 ;
struct V_9 * V_10 , * V_66 ;
struct V_1 * V_67 ;
T_3 * V_68 ;
if ( V_60 == V_69 ) {
V_68 = & V_20 ;
V_67 = & V_19 ;
} else if ( V_60 == V_70 ) {
V_68 = & V_22 ;
V_67 = & V_21 ;
} else
return - V_71 ;
F_8 ( V_68 ) ;
V_10 = F_14 ( V_67 , V_27 ) ;
if ( ! V_10 ) {
F_9 ( V_68 ) ;
V_66 = F_28 ( sizeof( struct V_9 ) , V_45 ) ;
if ( ! V_66 )
return - V_46 ;
V_66 -> V_37 = F_16 ( V_72 , V_45 ) ;
if ( ! V_66 -> V_37 ) {
F_18 ( V_66 ) ;
return - V_46 ;
}
F_8 ( V_68 ) ;
V_10 = F_14 ( V_67 , V_27 ) ;
if ( V_10 ) {
++ V_10 -> V_14 ;
F_9 ( V_68 ) ;
F_18 ( V_66 -> V_37 ) ;
F_18 ( V_66 ) ;
} else {
V_10 = V_66 ;
F_10 ( V_67 , V_27 , & V_10 ,
V_60 == V_69 ? L_6 : L_7 ) ;
++ V_10 -> V_14 ;
F_9 ( V_68 ) ;
}
} else {
++ V_10 -> V_14 ;
F_9 ( V_68 ) ;
}
if ( F_29 ( V_40 , & V_10 -> V_39 ) ) {
memcpy ( V_61 , & V_10 -> V_56 , sizeof( struct V_47 ) ) ;
V_10 -> time = V_12 ;
goto V_73;
}
if ( F_5 ( V_10 -> time + V_36 , V_12 ) ) {
V_55 = - V_71 ;
goto V_73;
}
if ( ! F_30 ( V_38 , & V_10 -> V_39 ) ) {
V_64 = F_31 ( V_74 ) ;
V_62 = F_32 ( & V_75 , V_10 -> V_37 , L_8 ) ;
if ( F_33 ( V_62 ) ) {
V_55 = - V_71 ;
F_34 ( 1 , L_9 , V_76 ) ;
} else {
V_65 = (struct V_47 * ) V_62 -> V_44 . V_42 ;
memcpy ( & V_10 -> V_56 , V_65 ,
V_62 -> V_43 < sizeof( struct V_47 ) ?
V_62 -> V_43 : sizeof( struct V_47 ) ) ;
memcpy ( V_61 , & V_10 -> V_56 ,
V_62 -> V_43 < sizeof( struct V_47 ) ?
V_62 -> V_43 : sizeof( struct V_47 ) ) ;
F_35 ( V_40 , & V_10 -> V_39 ) ;
F_36 ( V_62 ) ;
F_18 ( V_10 -> V_37 ) ;
}
V_10 -> time = V_12 ;
F_37 ( V_64 ) ;
F_11 ( V_38 , & V_10 -> V_39 ) ;
F_38 ( & V_10 -> V_39 , V_38 ) ;
} else {
V_55 = F_39 ( & V_10 -> V_39 , V_38 ,
F_24 , V_77 ) ;
if ( V_55 ) {
F_34 ( 1 , L_10 ,
V_76 , V_55 ) ;
-- V_10 -> V_14 ;
return V_55 ;
}
if ( F_29 ( V_40 , & V_10 -> V_39 ) )
memcpy ( V_61 , & V_10 -> V_56 , sizeof( struct V_47 ) ) ;
else
V_55 = - V_71 ;
}
V_73:
-- V_10 -> V_14 ;
return V_55 ;
}
static int
F_40 ( struct V_78 * V_79 , struct V_47 * V_80 ,
struct V_81 * V_82 , T_2 V_60 )
{
int V_55 ;
unsigned long V_27 ;
struct V_41 * V_83 ;
const struct V_63 * V_64 ;
struct V_9 * V_10 , * V_66 ;
struct V_1 * V_67 ;
T_3 * V_68 ;
if ( V_60 == V_69 ) {
V_27 = V_79 -> V_84 ;
V_68 = & V_20 ;
V_67 = & V_19 ;
} else if ( V_60 == V_70 ) {
V_27 = V_79 -> V_85 ;
V_68 = & V_22 ;
V_67 = & V_21 ;
} else
return - V_86 ;
F_8 ( V_68 ) ;
V_10 = F_23 ( V_67 , V_80 ) ;
if ( ! V_10 ) {
F_9 ( V_68 ) ;
V_66 = F_28 ( sizeof( struct V_9 ) , V_45 ) ;
if ( ! V_66 )
return - V_46 ;
V_66 -> V_37 = F_16 ( V_72 , V_45 ) ;
if ( ! V_66 -> V_37 ) {
F_18 ( V_66 ) ;
return - V_46 ;
}
F_8 ( V_68 ) ;
V_10 = F_23 ( V_67 , V_80 ) ;
if ( V_10 ) {
++ V_10 -> V_14 ;
F_9 ( V_68 ) ;
F_18 ( V_66 -> V_37 ) ;
F_18 ( V_66 ) ;
} else {
V_10 = V_66 ;
F_21 ( V_67 , V_80 , & V_10 ,
V_60 == V_69 ? L_11 : L_12 ) ;
++ V_10 -> V_14 ;
F_9 ( V_68 ) ;
}
} else {
++ V_10 -> V_14 ;
F_9 ( V_68 ) ;
}
if ( F_29 ( V_40 , & V_10 -> V_39 ) ) {
V_27 = V_10 -> V_33 ;
V_10 -> time = V_12 ;
goto V_87;
}
if ( F_5 ( V_10 -> time + V_36 , V_12 ) )
goto V_87;
if ( ! F_30 ( V_38 , & V_10 -> V_39 ) ) {
V_64 = F_31 ( V_74 ) ;
V_83 = F_32 ( & V_75 , V_10 -> V_37 , L_8 ) ;
if ( F_33 ( V_83 ) )
F_34 ( 1 , L_13 , V_76 ) ;
else {
V_27 = * ( unsigned long * ) V_83 -> V_44 . V_88 ;
V_10 -> V_33 = V_27 ;
F_35 ( V_40 , & V_10 -> V_39 ) ;
F_36 ( V_83 ) ;
F_18 ( V_10 -> V_37 ) ;
}
F_37 ( V_64 ) ;
V_10 -> time = V_12 ;
F_11 ( V_38 , & V_10 -> V_39 ) ;
F_38 ( & V_10 -> V_39 , V_38 ) ;
} else {
V_55 = F_39 ( & V_10 -> V_39 , V_38 ,
F_24 , V_77 ) ;
if ( V_55 ) {
F_34 ( 1 , L_10 ,
V_76 , V_55 ) ;
-- V_10 -> V_14 ;
return V_55 ;
}
if ( F_29 ( V_40 , & V_10 -> V_39 ) )
V_27 = V_10 -> V_33 ;
}
V_87:
-- V_10 -> V_14 ;
if ( V_60 == V_69 )
V_82 -> V_89 = V_27 ;
else
V_82 -> V_90 = V_27 ;
return 0 ;
}
int
F_41 ( void )
{
struct V_63 * V_63 ;
struct V_41 * V_91 ;
int V_92 ;
F_34 ( 1 , L_14 , V_75 . V_93 ) ;
V_63 = F_42 ( NULL ) ;
if ( ! V_63 )
return - V_46 ;
V_91 = F_43 ( & V_94 , L_15 , 0 , 0 , V_63 ,
( V_95 & ~ V_96 ) |
V_97 | V_98 ,
V_99 ) ;
if ( F_33 ( V_91 ) ) {
V_92 = F_44 ( V_91 ) ;
goto V_100;
}
V_92 = F_45 ( V_91 , NULL , 0 , NULL , NULL ) ;
if ( V_92 < 0 )
goto V_101;
V_92 = F_46 ( & V_75 ) ;
if ( V_92 < 0 )
goto V_101;
F_35 ( V_102 , & V_91 -> V_103 ) ;
V_63 -> V_104 = V_91 ;
V_63 -> V_105 = V_106 ;
V_74 = V_63 ;
F_47 ( & V_20 ) ;
V_19 = V_107 ;
F_47 ( & V_22 ) ;
V_21 = V_107 ;
F_47 ( & V_24 ) ;
V_23 = V_107 ;
F_47 ( & V_26 ) ;
V_25 = V_107 ;
F_48 ( & V_108 ) ;
F_34 ( 1 , L_16 , F_49 ( V_91 ) ) ;
return 0 ;
V_101:
F_36 ( V_91 ) ;
V_100:
F_50 ( V_63 ) ;
return V_92 ;
}
void
F_51 ( void )
{
F_52 ( V_74 -> V_104 ) ;
F_53 ( & V_75 ) ;
F_50 ( V_74 ) ;
F_54 ( & V_108 ) ;
F_34 ( 1 , L_17 , V_75 . V_93 ) ;
}
void
F_55 ( void )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_2 = & V_19 ;
F_8 ( & V_20 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_20 ) ;
V_2 = & V_21 ;
F_8 ( & V_22 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_22 ) ;
V_2 = & V_23 ;
F_8 ( & V_24 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_24 ) ;
V_2 = & V_25 ;
F_8 ( & V_26 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_26 ) ;
}
int F_22 ( const struct V_47 * V_109 , const struct V_47 * V_110 )
{
int V_49 ;
int V_53 , V_111 , V_112 ;
if ( ( ! V_109 ) || ( ! V_110 ) )
return 1 ;
if ( V_109 -> V_51 != V_110 -> V_51 ) {
if ( V_109 -> V_51 > V_110 -> V_51 )
return 1 ;
else
return - 1 ;
}
for ( V_49 = 0 ; V_49 < 6 ; ++ V_49 ) {
if ( V_109 -> V_52 [ V_49 ] != V_110 -> V_52 [ V_49 ] ) {
if ( V_109 -> V_52 [ V_49 ] > V_110 -> V_52 [ V_49 ] )
return 1 ;
else
return - 1 ;
}
}
V_111 = V_109 -> V_53 ;
V_112 = V_110 -> V_53 ;
V_53 = V_111 < V_112 ? V_111 : V_112 ;
if ( V_53 ) {
for ( V_49 = 0 ; V_49 < V_53 ; ++ V_49 ) {
if ( V_109 -> V_54 [ V_49 ] != V_110 -> V_54 [ V_49 ] ) {
if ( F_20 ( V_109 -> V_54 [ V_49 ] ) >
F_20 ( V_110 -> V_54 [ V_49 ] ) )
return 1 ;
else
return - 1 ;
}
}
}
return 0 ;
}
static void F_56 ( const struct V_113 * V_114 ,
struct V_113 * V_115 , T_4 V_116 )
{
int V_49 ;
struct V_47 * V_117 , * V_118 ;
struct V_47 * V_119 , * V_120 ;
V_115 -> V_51 = V_114 -> V_51 ;
V_115 -> type = V_114 -> type ;
V_115 -> V_121 = F_57 ( sizeof( struct V_113 ) ) ;
V_115 -> V_122 = 0 ;
V_115 -> V_123 = F_57 ( V_116 ) ;
V_115 -> V_124 = F_57 ( V_116 + sizeof( struct V_47 ) ) ;
V_117 = (struct V_47 * ) ( ( char * ) V_114 +
F_20 ( V_114 -> V_123 ) ) ;
V_119 = (struct V_47 * ) ( ( char * ) V_115 + V_116 ) ;
V_119 -> V_51 = V_117 -> V_51 ;
V_119 -> V_53 = V_117 -> V_53 ;
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_119 -> V_52 [ V_49 ] = V_117 -> V_52 [ V_49 ] ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ )
V_119 -> V_54 [ V_49 ] = V_117 -> V_54 [ V_49 ] ;
V_118 = (struct V_47 * ) ( ( char * ) V_114 +
F_20 ( V_114 -> V_124 ) ) ;
V_120 = (struct V_47 * ) ( ( char * ) V_115 + V_116 +
sizeof( struct V_47 ) ) ;
V_120 -> V_51 = V_118 -> V_51 ;
V_120 -> V_53 = V_118 -> V_53 ;
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_120 -> V_52 [ V_49 ] = V_118 -> V_52 [ V_49 ] ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ )
V_120 -> V_54 [ V_49 ] = V_118 -> V_54 [ V_49 ] ;
return;
}
static void F_58 ( T_5 V_125 , int type , T_6 * V_126 ,
T_6 * V_127 )
{
T_4 V_103 = F_20 ( V_125 ) ;
if ( type == V_128 ) {
if ( V_103 & V_129 )
* V_127 &= ~ V_130 ;
if ( ( V_103 & V_131 ) ||
( ( V_103 & V_132 ) == V_132 ) )
* V_127 &= ~ V_133 ;
if ( ( V_103 & V_134 ) ||
( ( V_103 & V_135 ) == V_135 ) )
* V_127 &= ~ V_136 ;
if ( ( V_103 & V_137 ) ||
( ( V_103 & V_138 ) == V_138 ) )
* V_127 &= ~ V_139 ;
return;
} else if ( type != V_140 ) {
F_59 ( 1 , L_18 , type ) ;
return;
}
if ( V_103 & V_129 ) {
* V_126 |= ( V_130 & ( * V_127 ) ) ;
F_34 ( V_141 , L_19 ) ;
return;
}
if ( ( V_103 & V_131 ) ||
( ( V_103 & V_132 ) == V_132 ) )
* V_126 |= ( V_133 & ( * V_127 ) ) ;
if ( ( V_103 & V_134 ) ||
( ( V_103 & V_135 ) == V_135 ) )
* V_126 |= ( V_136 & ( * V_127 ) ) ;
if ( ( V_103 & V_137 ) ||
( ( V_103 & V_138 ) == V_138 ) )
* V_126 |= ( V_139 & ( * V_127 ) ) ;
F_34 ( V_141 , L_20 , V_103 , * V_126 ) ;
return;
}
static void F_60 ( T_6 V_142 , T_6 V_143 ,
T_4 * V_144 )
{
* V_144 = 0x0 ;
V_142 &= V_143 ;
if ( V_142 & V_136 )
* V_144 |= V_145 ;
if ( V_142 & V_133 )
* V_144 |= V_146 ;
if ( V_142 & V_139 )
* V_144 |= V_147 ;
F_34 ( V_141 , L_21 , V_142 , * V_144 ) ;
return;
}
static T_7 F_61 ( struct V_148 * V_149 ,
const struct V_47 * V_80 , T_8 V_150 , T_6 V_151 )
{
int V_49 ;
T_7 V_152 = 0 ;
T_4 V_153 = 0 ;
V_149 -> type = V_140 ;
V_149 -> V_103 = 0x0 ;
F_60 ( V_150 , V_151 , & V_153 ) ;
if ( ! V_153 )
V_153 = V_154 ;
V_149 -> V_153 = F_57 ( V_153 ) ;
V_149 -> V_56 . V_51 = V_80 -> V_51 ;
V_149 -> V_56 . V_53 = V_80 -> V_53 ;
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_149 -> V_56 . V_52 [ V_49 ] = V_80 -> V_52 [ V_49 ] ;
for ( V_49 = 0 ; V_49 < V_80 -> V_53 ; V_49 ++ )
V_149 -> V_56 . V_54 [ V_49 ] = V_80 -> V_54 [ V_49 ] ;
V_152 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_80 -> V_53 * 4 ) ;
V_149 -> V_152 = F_62 ( V_152 ) ;
return V_152 ;
}
static void F_63 ( struct V_148 * V_155 , char * V_156 )
{
int V_53 ;
if ( F_64 ( V_155 -> V_152 ) < 16 ) {
F_59 ( 1 , L_22 , F_64 ( V_155 -> V_152 ) ) ;
return;
}
if ( V_156 < ( char * ) V_155 + F_64 ( V_155 -> V_152 ) ) {
F_59 ( 1 , L_23 ) ;
return;
}
V_53 = V_155 -> V_56 . V_53 ;
if ( V_53 ) {
int V_49 ;
F_34 ( 1 , L_24 ,
V_155 -> V_56 . V_51 , V_155 -> V_56 . V_53 , V_155 -> type ,
V_155 -> V_103 , F_64 ( V_155 -> V_152 ) ) ;
for ( V_49 = 0 ; V_49 < V_53 ; ++ V_49 ) {
F_34 ( 1 , L_25 , V_49 ,
F_20 ( V_155 -> V_56 . V_54 [ V_49 ] ) ) ;
}
}
return;
}
static void F_65 ( struct V_157 * V_158 , char * V_156 ,
struct V_47 * V_159 , struct V_47 * V_160 ,
struct V_81 * V_82 )
{
int V_49 ;
int V_161 = 0 ;
int V_162 ;
char * V_163 ;
struct V_148 * * V_164 ;
if ( ! V_158 ) {
V_82 -> V_165 |= V_130 ;
return;
}
if ( V_156 < ( char * ) V_158 + F_64 ( V_158 -> V_152 ) ) {
F_59 ( 1 , L_26 ) ;
return;
}
F_34 ( V_141 , L_27 ,
F_64 ( V_158 -> V_51 ) , F_64 ( V_158 -> V_152 ) ,
F_20 ( V_158 -> V_161 ) ) ;
V_82 -> V_165 &= ~ ( V_130 ) ;
V_163 = ( char * ) V_158 ;
V_162 = sizeof( struct V_157 ) ;
V_161 = F_20 ( V_158 -> V_161 ) ;
if ( V_161 > 0 ) {
T_6 V_166 = V_167 ;
T_6 V_168 = V_169 ;
T_6 V_170 = V_167 | V_169 | V_171 ;
if ( V_161 > V_172 / sizeof( struct V_148 * ) )
return;
V_164 = F_16 ( V_161 * sizeof( struct V_148 * ) ,
V_45 ) ;
if ( ! V_164 ) {
F_59 ( 1 , L_28 ) ;
return;
}
for ( V_49 = 0 ; V_49 < V_161 ; ++ V_49 ) {
V_164 [ V_49 ] = (struct V_148 * ) ( V_163 + V_162 ) ;
#ifdef F_66
F_63 ( V_164 [ V_49 ] , V_156 ) ;
#endif
if ( F_22 ( & ( V_164 [ V_49 ] -> V_56 ) , V_159 ) == 0 )
F_58 ( V_164 [ V_49 ] -> V_153 ,
V_164 [ V_49 ] -> type ,
& V_82 -> V_165 ,
& V_166 ) ;
if ( F_22 ( & ( V_164 [ V_49 ] -> V_56 ) , V_160 ) == 0 )
F_58 ( V_164 [ V_49 ] -> V_153 ,
V_164 [ V_49 ] -> type ,
& V_82 -> V_165 ,
& V_168 ) ;
if ( F_22 ( & ( V_164 [ V_49 ] -> V_56 ) , & V_173 ) == 0 )
F_58 ( V_164 [ V_49 ] -> V_153 ,
V_164 [ V_49 ] -> type ,
& V_82 -> V_165 ,
& V_170 ) ;
if ( F_22 ( & ( V_164 [ V_49 ] -> V_56 ) , & V_174 ) == 0 )
F_58 ( V_164 [ V_49 ] -> V_153 ,
V_164 [ V_49 ] -> type ,
& V_82 -> V_165 ,
& V_170 ) ;
V_163 = ( char * ) V_164 [ V_49 ] ;
V_162 = F_64 ( V_164 [ V_49 ] -> V_152 ) ;
}
F_18 ( V_164 ) ;
}
return;
}
static int F_67 ( struct V_157 * V_175 , struct V_47 * V_159 ,
struct V_47 * V_160 , T_8 V_150 )
{
T_9 V_152 = 0 ;
struct V_157 * V_176 ;
V_176 = (struct V_157 * ) ( ( char * ) V_175 + sizeof( struct V_157 ) ) ;
V_152 += F_61 ( (struct V_148 * ) ( ( char * ) V_176 + V_152 ) ,
V_159 , V_150 , V_167 ) ;
V_152 += F_61 ( (struct V_148 * ) ( ( char * ) V_176 + V_152 ) ,
V_160 , V_150 , V_169 ) ;
V_152 += F_61 ( (struct V_148 * ) ( ( char * ) V_176 + V_152 ) ,
& V_173 , V_150 , V_171 ) ;
V_175 -> V_152 = F_62 ( V_152 + sizeof( struct V_157 ) ) ;
V_175 -> V_161 = F_57 ( 3 ) ;
return 0 ;
}
static int F_68 ( struct V_47 * V_80 , char * V_156 )
{
if ( V_156 < ( char * ) V_80 + 8 ) {
F_59 ( 1 , L_29 , V_80 ) ;
return - V_71 ;
}
if ( V_80 -> V_53 ) {
#ifdef F_66
int V_49 ;
F_34 ( 1 , L_30 ,
V_80 -> V_51 , V_80 -> V_53 ) ;
for ( V_49 = 0 ; V_49 < V_80 -> V_53 ; V_49 ++ ) {
F_34 ( 1 , L_31 , V_49 ,
F_20 ( V_80 -> V_54 [ V_49 ] ) ) ;
}
F_34 ( 1 , L_32 ,
F_20 ( V_80 -> V_54 [ V_80 -> V_53 - 1 ] ) ) ;
#endif
}
return 0 ;
}
static int F_69 ( struct V_78 * V_79 ,
struct V_113 * V_114 , int V_177 , struct V_81 * V_82 )
{
int V_55 = 0 ;
struct V_47 * V_117 , * V_118 ;
struct V_157 * V_178 ;
char * V_156 = ( ( char * ) V_114 ) + V_177 ;
T_4 V_121 ;
if ( V_114 == NULL )
return - V_179 ;
V_117 = (struct V_47 * ) ( ( char * ) V_114 +
F_20 ( V_114 -> V_123 ) ) ;
V_118 = (struct V_47 * ) ( ( char * ) V_114 +
F_20 ( V_114 -> V_124 ) ) ;
V_121 = F_20 ( V_114 -> V_121 ) ;
V_178 = (struct V_157 * ) ( ( char * ) V_114 + V_121 ) ;
F_34 ( V_141 , L_33
L_34 ,
V_114 -> V_51 , V_114 -> type , F_20 ( V_114 -> V_123 ) ,
F_20 ( V_114 -> V_124 ) ,
F_20 ( V_114 -> V_122 ) , V_121 ) ;
V_55 = F_68 ( V_117 , V_156 ) ;
if ( V_55 ) {
F_34 ( 1 , L_35 , V_76 , V_55 ) ;
return V_55 ;
}
V_55 = F_40 ( V_79 , V_117 , V_82 , V_69 ) ;
if ( V_55 ) {
F_34 ( 1 , L_36 , V_76 , V_55 ) ;
return V_55 ;
}
V_55 = F_68 ( V_118 , V_156 ) ;
if ( V_55 ) {
F_34 ( 1 , L_37 , V_76 , V_55 ) ;
return V_55 ;
}
V_55 = F_40 ( V_79 , V_118 , V_82 , V_70 ) ;
if ( V_55 ) {
F_34 ( 1 , L_38 , V_76 , V_55 ) ;
return V_55 ;
}
if ( V_121 )
F_65 ( V_178 , V_156 , V_117 ,
V_118 , V_82 ) ;
else
F_34 ( 1 , L_39 ) ;
return V_55 ;
}
static int F_70 ( struct V_113 * V_114 , struct V_113 * V_115 ,
T_4 V_180 , T_8 V_150 , T_10 V_181 , T_11 V_182 , int * V_183 )
{
int V_55 = 0 ;
T_4 V_121 ;
T_4 V_184 ;
T_4 V_116 ;
struct V_47 * V_117 , * V_118 ;
struct V_47 * V_119 , * V_120 ;
struct V_157 * V_178 = NULL ;
struct V_157 * V_185 = NULL ;
if ( V_150 != V_186 ) {
V_117 = (struct V_47 * ) ( ( char * ) V_114 +
F_20 ( V_114 -> V_123 ) ) ;
V_118 = (struct V_47 * ) ( ( char * ) V_114 +
F_20 ( V_114 -> V_124 ) ) ;
V_121 = F_20 ( V_114 -> V_121 ) ;
V_178 = (struct V_157 * ) ( ( char * ) V_114 + V_121 ) ;
V_184 = sizeof( struct V_113 ) ;
V_185 = (struct V_157 * ) ( ( char * ) V_115 + V_184 ) ;
V_185 -> V_51 = V_178 -> V_51 ;
V_185 -> V_152 = 0 ;
V_185 -> V_161 = 0 ;
V_55 = F_67 ( V_185 , V_117 , V_118 ,
V_150 ) ;
V_116 = V_184 + F_64 ( V_185 -> V_152 ) ;
F_56 ( V_114 , V_115 , V_116 ) ;
* V_183 = V_187 ;
} else {
memcpy ( V_115 , V_114 , V_180 ) ;
if ( V_181 != V_188 ) {
V_117 = (struct V_47 * ) ( ( char * ) V_115 +
F_20 ( V_115 -> V_123 ) ) ;
V_119 = F_16 ( sizeof( struct V_47 ) ,
V_45 ) ;
if ( ! V_119 )
return - V_46 ;
V_55 = F_27 ( V_181 , V_69 , V_119 ) ;
if ( V_55 ) {
F_34 ( 1 , L_40 ,
V_76 , V_55 , V_181 ) ;
F_18 ( V_119 ) ;
return V_55 ;
}
memcpy ( V_117 , V_119 ,
sizeof( struct V_47 ) ) ;
F_18 ( V_119 ) ;
* V_183 = V_189 ;
}
if ( V_182 != V_188 ) {
V_118 = (struct V_47 * ) ( ( char * ) V_115 +
F_20 ( V_115 -> V_124 ) ) ;
V_120 = F_16 ( sizeof( struct V_47 ) ,
V_45 ) ;
if ( ! V_120 )
return - V_46 ;
V_55 = F_27 ( V_182 , V_70 , V_120 ) ;
if ( V_55 ) {
F_34 ( 1 , L_41 ,
V_76 , V_55 , V_182 ) ;
F_18 ( V_120 ) ;
return V_55 ;
}
memcpy ( V_118 , V_120 ,
sizeof( struct V_47 ) ) ;
F_18 ( V_120 ) ;
* V_183 = V_190 ;
}
}
return V_55 ;
}
static struct V_113 * F_71 ( struct V_78 * V_79 ,
T_7 V_191 , T_12 * V_192 )
{
struct V_113 * V_114 = NULL ;
unsigned int V_193 ;
int V_55 ;
struct V_194 * V_195 = F_72 ( V_79 ) ;
if ( F_33 ( V_195 ) )
return F_73 ( V_195 ) ;
V_193 = F_74 () ;
V_55 = F_75 ( V_193 , F_76 ( V_195 ) , V_191 , & V_114 , V_192 ) ;
F_77 ( V_193 ) ;
F_78 ( V_195 ) ;
F_34 ( 1 , L_42 , V_76 , V_55 , * V_192 ) ;
if ( V_55 )
return F_79 ( V_55 ) ;
return V_114 ;
}
static struct V_113 * F_80 ( struct V_78 * V_79 ,
const char * V_196 , T_12 * V_192 )
{
struct V_113 * V_114 = NULL ;
int V_197 = 0 ;
unsigned int V_193 ;
int V_55 , V_198 = 0 ;
T_7 V_191 ;
struct V_199 * V_200 ;
struct V_194 * V_195 = F_72 ( V_79 ) ;
if ( F_33 ( V_195 ) )
return F_73 ( V_195 ) ;
V_200 = F_76 ( V_195 ) ;
V_193 = F_74 () ;
if ( F_81 ( V_79 ) )
V_198 |= V_201 ;
V_55 = F_82 ( V_193 , V_200 , V_196 , V_202 , V_203 ,
V_198 , & V_191 , & V_197 , NULL , V_79 -> V_204 ,
V_79 -> V_205 & V_206 ) ;
if ( ! V_55 ) {
V_55 = F_75 ( V_193 , V_200 , V_191 , & V_114 , V_192 ) ;
F_83 ( V_193 , V_200 , V_191 ) ;
}
F_78 ( V_195 ) ;
F_77 ( V_193 ) ;
F_34 ( 1 , L_42 , V_76 , V_55 , * V_192 ) ;
if ( V_55 )
return F_79 ( V_55 ) ;
return V_114 ;
}
struct V_113 * F_84 ( struct V_78 * V_79 ,
struct V_207 * V_207 , const char * V_196 ,
T_12 * V_192 )
{
struct V_113 * V_114 = NULL ;
struct V_208 * V_209 = NULL ;
if ( V_207 )
V_209 = F_85 ( F_86 ( V_207 ) , true ) ;
if ( ! V_209 )
return F_80 ( V_79 , V_196 , V_192 ) ;
V_114 = F_71 ( V_79 , V_209 -> V_210 , V_192 ) ;
F_87 ( V_209 ) ;
return V_114 ;
}
int F_88 ( struct V_113 * V_115 , T_4 V_211 ,
struct V_207 * V_207 , const char * V_196 , int V_183 )
{
int V_197 = 0 ;
unsigned int V_193 ;
int V_55 , V_212 , V_198 = 0 ;
T_7 V_191 ;
struct V_199 * V_200 ;
struct V_78 * V_79 = F_89 ( V_207 -> V_213 ) ;
struct V_194 * V_195 = F_72 ( V_79 ) ;
if ( F_33 ( V_195 ) )
return F_44 ( V_195 ) ;
V_200 = F_76 ( V_195 ) ;
V_193 = F_74 () ;
if ( F_81 ( V_79 ) )
V_198 |= V_201 ;
if ( V_183 == V_189 || V_183 == V_190 )
V_212 = V_214 ;
else
V_212 = V_215 ;
V_55 = F_82 ( V_193 , V_200 , V_196 , V_202 , V_212 ,
V_198 , & V_191 , & V_197 , NULL , V_79 -> V_204 ,
V_79 -> V_205 & V_206 ) ;
if ( V_55 ) {
F_59 ( 1 , L_43 ) ;
goto V_216;
}
V_55 = F_90 ( V_193 , V_200 , V_191 , V_115 , V_211 , V_183 ) ;
F_34 ( V_141 , L_44 , V_55 ) ;
F_83 ( V_193 , V_200 , V_191 ) ;
V_216:
F_77 ( V_193 ) ;
F_78 ( V_195 ) ;
return V_55 ;
}
int
F_91 ( struct V_78 * V_79 , struct V_81 * V_82 ,
struct V_207 * V_207 , const char * V_196 , const T_7 * V_217 )
{
struct V_113 * V_114 = NULL ;
T_12 V_211 = 0 ;
int V_55 = 0 ;
F_34 ( V_141 , L_45 , V_196 ) ;
if ( V_217 )
V_114 = F_71 ( V_79 , * V_217 , & V_211 ) ;
else
V_114 = F_84 ( V_79 , V_207 , V_196 , & V_211 ) ;
if ( F_33 ( V_114 ) ) {
V_55 = F_44 ( V_114 ) ;
F_59 ( 1 , L_46 , V_76 , V_55 ) ;
} else {
V_55 = F_69 ( V_79 , V_114 , V_211 , V_82 ) ;
F_18 ( V_114 ) ;
if ( V_55 )
F_59 ( 1 , L_47 , V_55 ) ;
}
return V_55 ;
}
int
F_92 ( struct V_207 * V_207 , const char * V_196 , T_8 V_150 ,
T_10 V_181 , T_11 V_182 )
{
int V_55 = 0 ;
int V_183 = V_187 ;
T_4 V_180 = 0 ;
struct V_113 * V_114 = NULL ;
struct V_113 * V_115 = NULL ;
F_34 ( V_141 , L_48 , V_196 ) ;
V_114 = F_84 ( F_89 ( V_207 -> V_213 ) , V_207 , V_196 , & V_180 ) ;
if ( F_33 ( V_114 ) ) {
V_55 = F_44 ( V_114 ) ;
F_59 ( 1 , L_46 , V_76 , V_55 ) ;
} else {
V_180 = V_180 < V_218 ?
V_218 : V_180 ;
V_115 = F_16 ( V_180 , V_45 ) ;
if ( ! V_115 ) {
F_59 ( 1 , L_49 ) ;
F_18 ( V_114 ) ;
return - V_46 ;
}
V_55 = F_70 ( V_114 , V_115 , V_180 , V_150 , V_181 , V_182 ,
& V_183 ) ;
F_34 ( V_141 , L_50 , V_55 ) ;
if ( ! V_55 ) {
V_55 = F_88 ( V_115 , V_180 , V_207 ,
V_196 , V_183 ) ;
F_34 ( V_141 , L_51 , V_55 ) ;
}
F_18 ( V_115 ) ;
F_18 ( V_114 ) ;
}
return V_55 ;
}
