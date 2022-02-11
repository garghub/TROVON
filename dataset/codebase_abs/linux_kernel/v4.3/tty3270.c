static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 , V_5 + V_3 ) ;
}
static void
F_3 ( struct V_1 * V_2 , char * V_6 , int V_7 )
{
struct string * line ;
unsigned int V_8 ;
line = V_2 -> V_9 ;
if ( V_7 != 0 )
line -> string [ 5 ] = V_10 ;
else
line -> string [ 5 ] = V_2 -> V_11 ;
if ( V_7 > V_2 -> V_12 . V_13 * 2 - 11 )
V_7 = V_2 -> V_12 . V_13 * 2 - 11 ;
memcpy ( line -> string + 6 , V_6 , V_7 ) ;
line -> string [ 6 + V_7 ] = V_14 ;
if ( V_7 < V_2 -> V_12 . V_13 * 2 - 11 ) {
line -> string [ 7 + V_7 ] = V_15 ;
line -> string [ 10 + V_7 ] = 0 ;
V_8 = V_2 -> V_12 . V_13 * V_2 -> V_12 . V_16 - 9 ;
F_4 ( V_2 -> V_12 . V_17 , line -> string + V_7 + 8 , V_8 ) ;
line -> V_18 = 11 + V_7 ;
} else
line -> V_18 = 7 + V_7 ;
V_2 -> V_19 |= V_20 ;
}
static void
F_5 ( struct V_1 * V_2 )
{
static const unsigned char V_21 [] =
{ V_22 , 0 , 0 , 0x6e , V_23 , V_24 ,
V_14 , V_15 , 0 , 0 , 0 } ;
struct string * line ;
unsigned int V_25 ;
line = F_6 ( & V_2 -> V_26 ,
sizeof( V_21 ) + V_2 -> V_12 . V_13 * 2 - 9 ) ;
V_2 -> V_9 = line ;
V_2 -> V_11 = V_24 ;
memcpy ( line -> string , V_21 , sizeof( V_21 ) ) ;
line -> V_18 = sizeof( V_21 ) ;
V_25 = V_2 -> V_12 . V_13 * ( V_2 -> V_12 . V_16 - 2 ) ;
F_4 ( V_2 -> V_12 . V_17 , line -> string + 1 , V_25 ) ;
V_25 = V_2 -> V_12 . V_13 * V_2 -> V_12 . V_16 - 9 ;
F_4 ( V_2 -> V_12 . V_17 , line -> string + 8 , V_25 ) ;
V_2 -> V_6 = F_6 ( & V_2 -> V_26 , V_2 -> V_12 . V_13 * 2 - 9 + 6 ) ;
}
static void
F_7 ( struct V_1 * V_2 )
{
char * V_27 ;
V_27 = ( V_2 -> V_28 != 0 ) ? L_1 : L_2 ;
memcpy ( V_2 -> V_29 -> string + 8 , V_27 , 7 ) ;
F_8 ( V_2 -> V_12 . V_30 , V_2 -> V_29 -> string + 8 , 7 ) ;
V_2 -> V_19 |= V_31 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
static const unsigned char V_21 [] =
{ V_22 , 0 , 0 , V_23 , V_32 , V_33 , V_34 , V_35 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , V_23 , V_32 , V_33 , V_34 ,
V_36 } ;
struct string * line ;
unsigned int V_25 ;
line = F_6 ( & V_2 -> V_26 , sizeof( V_21 ) ) ;
V_2 -> V_29 = line ;
memcpy ( line -> string , V_21 , sizeof( V_21 ) ) ;
V_25 = V_2 -> V_12 . V_13 * V_2 -> V_12 . V_16 - 9 ;
F_4 ( V_2 -> V_12 . V_17 , line -> string + 1 , V_25 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct string * line , int V_37 )
{
unsigned char * V_38 ;
F_4 ( V_2 -> V_12 . V_17 , line -> string + 1 ,
V_2 -> V_12 . V_13 * V_37 ) ;
V_38 = line -> string + line -> V_18 - 4 ;
if ( * V_38 == V_15 )
F_4 ( V_2 -> V_12 . V_17 , V_38 + 1 ,
V_2 -> V_12 . V_13 * ( V_37 + 1 ) ) ;
}
static void
F_11 ( struct V_1 * V_2 )
{
struct string * V_39 , * V_40 ;
int line , V_28 ;
F_12 (s, n, &tp->update, update)
F_13 ( & V_39 -> V_41 ) ;
line = V_2 -> V_12 . V_16 - 3 ;
V_28 = V_2 -> V_28 ;
F_14 (s, &tp->lines, list) {
if ( V_28 > 0 ) {
V_28 -- ;
continue;
}
F_10 ( V_2 , V_39 , line ) ;
F_15 ( & V_39 -> V_41 , & V_2 -> V_41 ) ;
if ( -- line < 0 )
break;
}
V_2 -> V_19 |= V_42 ;
}
static struct string *
F_16 ( struct V_1 * V_2 , T_1 V_43 )
{
struct string * V_39 , * V_40 ;
V_39 = F_6 ( & V_2 -> V_26 , V_43 ) ;
if ( V_39 )
return V_39 ;
F_12 (s, n, &tp->lines, list) {
F_17 ( V_2 -> V_44 <= V_2 -> V_12 . V_16 - 2 ) ;
F_18 ( & V_39 -> V_45 ) ;
if ( ! F_19 ( & V_39 -> V_41 ) )
F_18 ( & V_39 -> V_41 ) ;
V_2 -> V_44 -- ;
if ( F_20 ( & V_2 -> V_26 , V_39 ) >= V_43 )
break;
}
V_39 = F_6 ( & V_2 -> V_26 , V_43 ) ;
F_17 ( ! V_39 ) ;
if ( V_2 -> V_28 != 0 &&
V_2 -> V_28 + V_2 -> V_12 . V_16 - 2 >= V_2 -> V_44 ) {
V_2 -> V_28 = V_2 -> V_44 - V_2 -> V_12 . V_16 + 2 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
}
return V_39 ;
}
static void
F_21 ( struct V_1 * V_2 )
{
static const unsigned char V_21 [] =
{ V_22 , 0 , 0 , V_33 , V_46 , V_47 ,
V_33 , V_34 , V_36 , V_15 , 0 , 0 , 0 } ;
struct string * V_39 ;
V_39 = F_16 ( V_2 , sizeof( V_21 ) ) ;
memcpy ( V_39 -> string , V_21 , sizeof( V_21 ) ) ;
V_39 -> V_18 = sizeof( V_21 ) ;
F_22 ( & V_39 -> V_45 , & V_2 -> V_48 ) ;
V_2 -> V_44 ++ ;
if ( V_2 -> V_28 != 0 )
V_2 -> V_28 ++ ;
}
static void
F_23 ( struct V_49 * V_50 , void * V_51 )
{
struct V_1 * V_2 = F_24 ( V_50 -> V_12 , struct V_1 , V_12 ) ;
if ( V_50 -> V_52 != 0 ) {
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
}
F_25 ( V_50 ) ;
F_26 ( & V_2 -> V_54 , V_50 ) ;
}
static void
F_27 ( struct V_1 * V_2 )
{
static char V_55 [ 2 ] = { 0xff , 0xff } ;
struct V_49 * V_56 ;
unsigned long V_57 ;
struct string * V_39 , * V_40 ;
char * V_58 , * V_27 ;
int V_52 , V_18 ;
V_56 = F_26 ( & V_2 -> V_54 , 0 ) ;
if ( ! V_56 ) {
F_1 ( V_2 , 1 ) ;
return;
}
F_28 ( & V_2 -> V_12 . V_59 ) ;
V_57 = 0 ;
if ( V_2 -> V_19 & V_53 ) {
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_19 = V_60 | V_42 |
V_20 | V_31 ;
}
if ( V_2 -> V_19 & V_60 ) {
F_29 ( V_56 , V_61 ) ;
V_57 |= V_60 ;
} else
F_29 ( V_56 , V_62 ) ;
F_30 ( V_56 , & V_2 -> V_63 , 1 ) ;
V_2 -> V_63 = V_64 ;
if ( V_2 -> V_19 & V_31 )
if ( F_30 ( V_56 , V_2 -> V_29 -> string ,
V_2 -> V_29 -> V_18 ) == 0 )
V_57 |= V_31 ;
if ( V_2 -> V_19 & V_20 )
if ( F_30 ( V_56 , V_2 -> V_9 -> string ,
V_2 -> V_9 -> V_18 ) == 0 )
V_57 |= V_20 ;
V_58 = V_55 ;
if ( V_2 -> V_19 & V_42 ) {
F_12 (s, n, &tp->update, update) {
V_27 = V_39 -> string ;
V_18 = V_39 -> V_18 ;
if ( V_39 -> string [ 1 ] == V_58 [ 0 ] && V_39 -> string [ 2 ] == V_58 [ 1 ] )
V_27 += 3 , V_18 -= 3 ;
if ( F_30 ( V_56 , V_27 , V_18 ) != 0 )
break;
F_13 ( & V_39 -> V_41 ) ;
V_58 = V_39 -> string + V_39 -> V_18 - 3 ;
}
if ( F_19 ( & V_2 -> V_41 ) )
V_57 |= V_42 ;
}
V_56 -> V_65 = F_23 ;
V_52 = F_31 ( & V_2 -> V_12 , V_56 ) ;
if ( V_52 == 0 ) {
V_2 -> V_19 &= ~ V_57 ;
if ( V_2 -> V_19 )
F_1 ( V_2 , 1 ) ;
} else {
F_25 ( V_56 ) ;
F_26 ( & V_2 -> V_54 , V_56 ) ;
}
F_32 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_33 ( struct V_1 * V_2 , char * V_6 , int V_18 )
{
struct string * V_39 ;
V_2 -> V_66 = NULL ;
if ( V_18 <= 0 )
return;
if ( V_2 -> V_67 >= V_2 -> V_68 ) {
V_39 = F_34 ( V_2 -> V_69 . V_70 , struct string , V_45 ) ;
F_18 ( & V_39 -> V_45 ) ;
F_20 ( & V_2 -> V_26 , V_39 ) ;
V_2 -> V_67 -- ;
}
V_39 = F_16 ( V_2 , V_18 ) ;
memcpy ( V_39 -> string , V_6 , V_18 ) ;
F_22 ( & V_39 -> V_45 , & V_2 -> V_69 ) ;
V_2 -> V_67 ++ ;
}
static void
F_35 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_24 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
struct string * V_39 ;
F_36 ( & V_2 -> V_12 . V_59 ) ;
if ( V_2 -> V_11 == V_24 ) {
if ( V_2 -> V_66 && V_2 -> V_66 -> V_74 != & V_2 -> V_69 )
V_2 -> V_66 = V_2 -> V_66 -> V_74 ;
else if ( ! F_19 ( & V_2 -> V_69 ) )
V_2 -> V_66 = V_2 -> V_69 . V_74 ;
V_39 = V_2 -> V_66 ?
F_34 ( V_2 -> V_66 , struct string , V_45 ) : NULL ;
if ( V_2 -> V_66 ) {
V_39 = F_34 ( V_2 -> V_66 , struct string , V_45 ) ;
F_3 ( V_2 , V_39 -> string , V_39 -> V_18 ) ;
} else
F_3 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
}
F_37 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_38 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_24 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
F_39 ( & V_2 -> V_12 ) ;
}
static void
F_40 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_24 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
int V_28 ;
F_36 ( & V_2 -> V_12 . V_59 ) ;
V_28 = V_2 -> V_28 - V_2 -> V_12 . V_16 + 2 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_37 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_41 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_24 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
int V_28 ;
F_36 ( & V_2 -> V_12 . V_59 ) ;
V_28 = V_2 -> V_28 + V_2 -> V_12 . V_16 - 2 ;
if ( V_28 + V_2 -> V_12 . V_16 - 2 > V_2 -> V_44 )
V_28 = V_2 -> V_44 - V_2 -> V_12 . V_16 + 2 ;
if ( V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_37 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_42 ( struct V_49 * V_75 )
{
static char V_76 = V_77 ;
struct V_1 * V_2 = F_24 ( V_75 -> V_12 , struct V_1 , V_12 ) ;
char * V_6 ;
int V_18 ;
F_36 ( & V_2 -> V_12 . V_59 ) ;
V_6 = NULL ;
V_18 = 0 ;
if ( V_2 -> V_6 -> string [ 0 ] == 0x7d ) {
V_6 = V_2 -> V_6 -> string + 6 ;
V_18 = V_2 -> V_6 -> V_18 - 6 - V_75 -> V_78 ;
if ( V_2 -> V_11 != V_79 )
F_33 ( V_2 , V_6 , V_18 ) ;
if ( V_2 -> V_28 > 0 ) {
V_2 -> V_28 = 0 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
}
F_3 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
} else if ( V_2 -> V_6 -> string [ 0 ] == 0x6d ) {
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
}
F_37 ( & V_2 -> V_12 . V_59 ) ;
F_25 ( V_2 -> V_80 ) ;
F_29 ( V_2 -> V_80 , V_62 ) ;
F_30 ( V_2 -> V_80 , & V_76 , 1 ) ;
F_31 ( & V_2 -> V_12 , V_2 -> V_80 ) ;
while ( V_18 -- > 0 )
F_43 ( V_2 -> V_72 , * V_6 ++ ) ;
F_43 ( V_2 -> V_72 , 256 + V_2 -> V_6 -> string [ 0 ] ) ;
F_25 ( V_75 ) ;
F_26 ( & V_2 -> V_81 , V_75 ) ;
F_44 ( & V_2 -> V_12 ) ;
}
static void
F_45 ( struct V_49 * V_50 , void * V_51 )
{
struct V_1 * V_2 = F_24 ( V_50 -> V_12 , struct V_1 , V_12 ) ;
F_46 ( V_50 -> V_12 ) ;
F_47 ( & V_2 -> V_82 ) ;
}
static void
F_48 ( struct V_1 * V_2 , int V_59 )
{
struct V_49 * V_75 ;
int V_52 ;
V_75 = F_26 ( & V_2 -> V_81 , 0 ) ;
if ( ! V_75 )
return;
V_75 -> V_65 = F_45 ;
V_75 -> V_83 = V_2 ;
F_29 ( V_75 , V_84 ) ;
F_49 ( V_75 , V_2 -> V_6 -> string , V_2 -> V_6 -> V_18 ) ;
if ( V_59 ) {
V_52 = F_31 ( & V_2 -> V_12 , V_75 ) ;
} else
V_52 = F_50 ( & V_2 -> V_12 , V_75 ) ;
if ( V_52 ) {
F_25 ( V_75 ) ;
F_26 ( & V_2 -> V_81 , V_75 ) ;
}
}
static int
F_51 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_24 ( V_12 , struct V_1 , V_12 ) ;
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static void
F_52 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_24 ( V_12 , struct V_1 , V_12 ) ;
F_53 ( & V_2 -> V_4 ) ;
}
static int
F_54 ( struct V_1 * V_2 , struct V_49 * V_50 , struct V_86 * V_86 )
{
if ( V_86 -> V_87 . V_88 . V_89 & V_90 ) {
if ( ! V_2 -> V_91 )
F_48 ( V_2 , 0 ) ;
else
V_2 -> V_92 = 1 ;
}
if ( V_50 ) {
if ( V_86 -> V_87 . V_88 . V_89 & V_93 )
V_50 -> V_52 = - V_94 ;
else
V_50 -> V_78 = V_86 -> V_87 . V_88 . V_7 ;
} else if ( V_86 -> V_87 . V_88 . V_89 & V_95 ) {
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
}
return V_96 ;
}
static struct V_1 *
F_55 ( void )
{
struct V_1 * V_2 ;
int V_97 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_2 )
goto V_99;
V_2 -> V_100 =
F_57 ( sizeof( void * ) * V_101 , V_98 ) ;
if ( ! V_2 -> V_100 )
goto V_102;
F_58 ( & V_2 -> V_26 ) ;
F_58 ( & V_2 -> V_48 ) ;
F_58 ( & V_2 -> V_41 ) ;
F_58 ( & V_2 -> V_69 ) ;
V_2 -> V_68 = 20 ;
for ( V_97 = 0 ; V_97 < V_101 ; V_97 ++ ) {
V_2 -> V_100 [ V_97 ] = ( void * )
F_59 ( V_98 | V_103 , 0 ) ;
if ( ! V_2 -> V_100 [ V_97 ] )
goto V_104;
F_60 ( & V_2 -> V_26 ,
V_2 -> V_100 [ V_97 ] , V_105 ) ;
}
V_2 -> V_54 = F_61 ( V_106 ) ;
if ( F_62 ( V_2 -> V_54 ) )
goto V_104;
V_2 -> V_81 = F_61 ( 0 ) ;
if ( F_62 ( V_2 -> V_81 ) )
goto V_107;
V_2 -> V_80 = F_61 ( 1 ) ;
if ( F_62 ( V_2 -> V_80 ) )
goto V_108;
V_2 -> V_72 = F_63 () ;
if ( ! V_2 -> V_72 )
goto V_109;
F_64 ( & V_2 -> V_73 ) ;
F_65 ( & V_2 -> V_4 , ( void (*) ( unsigned long ) ) F_27 ,
( unsigned long ) V_2 ) ;
F_66 ( & V_2 -> V_82 ,
( void (*) ( unsigned long ) ) F_42 ,
( unsigned long ) V_2 -> V_81 ) ;
F_67 ( & V_2 -> V_110 , V_111 ) ;
return V_2 ;
V_109:
F_68 ( V_2 -> V_80 ) ;
V_108:
F_68 ( V_2 -> V_81 ) ;
V_107:
F_68 ( V_2 -> V_54 ) ;
V_104:
while ( V_97 -- )
F_69 ( ( unsigned long ) V_2 -> V_100 [ V_97 ] , 0 ) ;
F_70 ( V_2 -> V_100 ) ;
F_71 ( & V_2 -> V_73 ) ;
V_102:
F_70 ( V_2 ) ;
V_99:
return F_72 ( - V_112 ) ;
}
static void
F_73 ( struct V_1 * V_2 )
{
int V_97 ;
F_74 ( V_2 -> V_72 ) ;
F_68 ( V_2 -> V_80 ) ;
F_68 ( V_2 -> V_81 ) ;
F_68 ( V_2 -> V_54 ) ;
for ( V_97 = 0 ; V_97 < V_101 ; V_97 ++ )
F_69 ( ( unsigned long ) V_2 -> V_100 [ V_97 ] , 0 ) ;
F_70 ( V_2 -> V_100 ) ;
F_71 ( & V_2 -> V_73 ) ;
F_70 ( V_2 ) ;
}
static struct V_113 *
F_75 ( unsigned int V_16 , unsigned int V_13 )
{
struct V_113 * V_114 ;
unsigned long V_43 ;
int V_48 ;
V_43 = sizeof( struct V_113 ) * ( V_16 - 2 ) ;
V_114 = F_56 ( V_43 , V_98 ) ;
if ( ! V_114 )
goto V_99;
for ( V_48 = 0 ; V_48 < V_16 - 2 ; V_48 ++ ) {
V_43 = sizeof( struct V_115 ) * V_13 ;
V_114 [ V_48 ] . V_116 = F_56 ( V_43 , V_98 ) ;
if ( ! V_114 [ V_48 ] . V_116 )
goto V_117;
}
return V_114 ;
V_117:
while ( V_48 -- )
F_70 ( V_114 [ V_48 ] . V_116 ) ;
F_70 ( V_114 ) ;
V_99:
return F_72 ( - V_112 ) ;
}
static void
F_76 ( struct V_113 * V_114 , unsigned int V_16 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_16 - 2 ; V_48 ++ )
F_70 ( V_114 [ V_48 ] . V_116 ) ;
F_70 ( V_114 ) ;
}
static void V_111 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_24 ( V_119 , struct V_1 , V_110 ) ;
struct V_113 * V_114 , * V_120 ;
struct V_121 * V_122 ;
unsigned int V_123 ;
struct V_124 V_125 ;
V_114 = F_75 ( V_2 -> V_126 , V_2 -> V_127 ) ;
if ( F_62 ( V_114 ) )
return;
F_36 ( & V_2 -> V_12 . V_59 ) ;
V_120 = V_2 -> V_114 ;
V_123 = V_2 -> V_12 . V_16 ;
V_2 -> V_12 . V_128 = V_2 -> V_129 ;
V_2 -> V_12 . V_16 = V_2 -> V_126 ;
V_2 -> V_12 . V_13 = V_2 -> V_127 ;
V_2 -> V_114 = V_114 ;
F_20 ( & V_2 -> V_26 , V_2 -> V_9 ) ;
F_20 ( & V_2 -> V_26 , V_2 -> V_29 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_28 = 0 ;
while ( V_2 -> V_44 < V_2 -> V_12 . V_16 - 2 )
F_21 ( V_2 ) ;
V_2 -> V_19 = V_53 ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
F_76 ( V_120 , V_123 ) ;
F_1 ( V_2 , 1 ) ;
V_122 = F_77 ( & V_2 -> V_73 ) ;
if ( ! V_122 )
return;
V_125 . V_130 = V_2 -> V_12 . V_16 - 2 ;
V_125 . V_131 = V_2 -> V_12 . V_13 ;
F_78 ( V_122 , & V_125 ) ;
}
static void
F_79 ( struct V_85 * V_12 , int V_128 , int V_16 , int V_13 )
{
struct V_1 * V_2 = F_24 ( V_12 , struct V_1 , V_12 ) ;
V_2 -> V_129 = V_128 ;
V_2 -> V_126 = V_16 ;
V_2 -> V_127 = V_13 ;
F_80 ( & V_2 -> V_110 ) ;
}
static void
F_81 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_24 ( V_12 , struct V_1 , V_12 ) ;
struct V_121 * V_122 = F_77 ( & V_2 -> V_73 ) ;
if ( V_122 ) {
V_122 -> V_132 = NULL ;
F_82 ( & V_2 -> V_73 , NULL ) ;
F_83 ( V_122 ) ;
F_44 ( & V_2 -> V_12 ) ;
F_84 ( V_122 ) ;
}
}
static void
F_85 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_24 ( V_12 , struct V_1 , V_12 ) ;
F_86 ( & V_2 -> V_4 ) ;
F_76 ( V_2 -> V_114 , V_2 -> V_12 . V_16 ) ;
F_73 ( V_2 ) ;
}
static void
F_87 ( void )
{
int V_133 ;
for ( V_133 = V_134 ; V_133 <= V_135 ; V_133 ++ ) {
struct V_85 * V_12 = F_88 ( & V_136 , V_133 ) ;
if ( ! F_62 ( V_12 ) )
F_89 ( V_12 ) ;
}
}
static int F_90 ( struct V_137 * V_138 , struct V_121 * V_122 )
{
struct V_85 * V_12 ;
struct V_1 * V_2 ;
int V_133 , V_52 ;
V_12 = F_88 ( & V_136 , V_122 -> V_139 + V_134 ) ;
if ( ! F_62 ( V_12 ) ) {
V_2 = F_24 ( V_12 , struct V_1 , V_12 ) ;
V_122 -> V_132 = V_2 ;
V_122 -> V_124 . V_130 = V_2 -> V_12 . V_16 - 2 ;
V_122 -> V_124 . V_131 = V_2 -> V_12 . V_13 ;
V_2 -> V_73 . V_140 = 0 ;
F_82 ( & V_2 -> V_73 , V_122 ) ;
V_2 -> V_11 = V_24 ;
return F_91 ( & V_2 -> V_73 , V_138 , V_122 ) ;
}
if ( V_135 < V_122 -> V_139 + 1 )
V_135 = V_122 -> V_139 + 1 ;
V_2 = F_55 () ;
if ( F_62 ( V_2 ) )
return F_92 ( V_2 ) ;
V_52 = F_93 ( & V_2 -> V_12 , & V_136 ,
V_122 -> V_139 + V_134 ) ;
if ( V_52 ) {
F_73 ( V_2 ) ;
return V_52 ;
}
V_2 -> V_114 = F_75 ( V_2 -> V_12 . V_16 , V_2 -> V_12 . V_13 ) ;
if ( F_62 ( V_2 -> V_114 ) ) {
V_52 = F_92 ( V_2 -> V_114 ) ;
F_44 ( & V_2 -> V_12 ) ;
F_89 ( & V_2 -> V_12 ) ;
F_73 ( V_2 ) ;
return V_52 ;
}
F_82 ( & V_2 -> V_73 , V_122 ) ;
V_2 -> V_73 . V_140 = 0 ;
V_122 -> V_124 . V_130 = V_2 -> V_12 . V_16 - 2 ;
V_122 -> V_124 . V_131 = V_2 -> V_12 . V_13 ;
F_5 ( V_2 ) ;
F_9 ( V_2 ) ;
F_7 ( V_2 ) ;
for ( V_133 = 0 ; V_133 < V_2 -> V_12 . V_16 - 2 ; V_133 ++ )
F_21 ( V_2 ) ;
V_2 -> V_72 -> V_73 = & V_2 -> V_73 ;
V_2 -> V_72 -> V_141 [ F_94 ( V_142 ) ] = F_38 ;
V_2 -> V_72 -> V_141 [ F_94 ( V_143 ) ] = F_41 ;
V_2 -> V_72 -> V_141 [ F_94 ( V_144 ) ] = F_40 ;
V_2 -> V_72 -> V_141 [ F_94 ( V_145 ) ] = F_35 ;
F_95 ( V_2 -> V_72 , V_2 -> V_12 . V_30 ) ;
F_96 ( & V_2 -> V_12 ) ;
V_52 = F_91 ( & V_2 -> V_73 , V_138 , V_122 ) ;
if ( V_52 ) {
F_44 ( & V_2 -> V_12 ) ;
return V_52 ;
}
V_122 -> V_132 = V_2 ;
return 0 ;
}
static int
F_97 ( struct V_121 * V_122 , struct V_146 * V_147 )
{
struct V_1 * V_2 = V_122 -> V_132 ;
struct V_148 * V_73 = & V_2 -> V_73 ;
V_73 -> V_7 ++ ;
F_82 ( V_73 , V_122 ) ;
return 0 ;
}
static void
F_98 ( struct V_121 * V_122 , struct V_146 * V_147 )
{
struct V_1 * V_2 = V_122 -> V_132 ;
if ( V_122 -> V_7 > 1 )
return;
if ( V_2 ) {
V_122 -> V_132 = NULL ;
F_82 ( & V_2 -> V_73 , NULL ) ;
}
}
static void F_99 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = V_122 -> V_132 ;
if ( V_2 )
F_44 ( & V_2 -> V_12 ) ;
}
static int
F_100 ( struct V_121 * V_122 )
{
return V_149 ;
}
static void F_101 ( struct V_1 * V_2 , char V_150 )
{
struct V_113 * line ;
struct V_115 * V_151 ;
line = V_2 -> V_114 + V_2 -> V_152 ;
if ( line -> V_18 <= V_2 -> V_153 ) {
while ( line -> V_18 < V_2 -> V_153 ) {
V_151 = line -> V_116 + line -> V_18 ;
V_151 -> V_154 = V_2 -> V_12 . V_30 [ ' ' ] ;
V_151 -> V_155 = V_2 -> V_155 ;
V_151 -> V_156 = V_2 -> V_156 ;
line -> V_18 ++ ;
}
line -> V_18 ++ ;
}
V_151 = line -> V_116 + V_2 -> V_153 ;
V_151 -> V_154 = V_2 -> V_12 . V_30 [ ( unsigned int ) V_150 ] ;
V_151 -> V_155 = V_2 -> V_155 ;
V_151 -> V_156 = V_2 -> V_156 ;
}
static void
F_102 ( struct V_1 * V_2 , int V_157 )
{
struct V_113 * line ;
struct V_115 * V_151 ;
struct string * V_39 , * V_40 ;
unsigned char V_155 ;
unsigned char V_156 ;
char * V_38 ;
int V_158 , V_133 ;
V_158 = 3 ;
line = V_2 -> V_114 + V_157 ;
V_158 += line -> V_18 ;
V_155 = V_47 ;
V_156 = V_36 ;
for ( V_133 = 0 , V_151 = line -> V_116 ; V_133 < line -> V_18 ; V_133 ++ , V_151 ++ ) {
if ( V_151 -> V_155 != V_155 ) {
V_158 += 3 ;
V_155 = V_151 -> V_155 ;
}
if ( V_151 -> V_156 != V_156 ) {
V_158 += 3 ;
V_156 = V_151 -> V_156 ;
}
}
if ( V_155 != V_47 )
V_158 += 3 ;
if ( V_156 != V_36 )
V_158 += 3 ;
if ( line -> V_18 < V_2 -> V_12 . V_13 )
V_158 += 4 ;
V_133 = V_2 -> V_12 . V_16 - 2 - V_157 ;
F_14 (s, &tp->lines, list)
if ( -- V_133 <= 0 )
break;
if ( V_39 -> V_18 != V_158 ) {
V_40 = F_16 ( V_2 , V_158 ) ;
F_15 ( & V_40 -> V_45 , & V_39 -> V_45 ) ;
F_13 ( & V_39 -> V_45 ) ;
if ( ! F_19 ( & V_39 -> V_41 ) )
F_13 ( & V_39 -> V_41 ) ;
F_20 ( & V_2 -> V_26 , V_39 ) ;
V_39 = V_40 ;
}
V_38 = V_39 -> string ;
* V_38 ++ = V_22 ;
* V_38 ++ = 0 ;
* V_38 ++ = 0 ;
V_155 = V_47 ;
V_156 = V_36 ;
for ( V_133 = 0 , V_151 = line -> V_116 ; V_133 < line -> V_18 ; V_133 ++ , V_151 ++ ) {
if ( V_151 -> V_155 != V_155 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_46 ;
* V_38 ++ = V_151 -> V_155 ;
V_155 = V_151 -> V_155 ;
}
if ( V_151 -> V_156 != V_156 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_34 ;
* V_38 ++ = V_151 -> V_156 ;
V_156 = V_151 -> V_156 ;
}
* V_38 ++ = V_151 -> V_154 ;
}
if ( V_155 != V_47 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_46 ;
* V_38 ++ = V_47 ;
}
if ( V_156 != V_36 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_34 ;
* V_38 ++ = V_36 ;
}
if ( line -> V_18 < V_2 -> V_12 . V_13 ) {
* V_38 ++ = V_15 ;
* V_38 ++ = 0 ;
* V_38 ++ = 0 ;
* V_38 ++ = 0 ;
}
if ( V_2 -> V_28 + V_157 < V_2 -> V_12 . V_16 - 2 ) {
F_10 ( V_2 , V_39 , V_157 ) ;
if ( F_19 ( & V_39 -> V_41 ) ) {
F_22 ( & V_39 -> V_41 , & V_2 -> V_41 ) ;
V_2 -> V_19 |= V_42 ;
}
}
}
static void
F_103 ( struct V_1 * V_2 )
{
V_2 -> V_153 = 0 ;
}
static void
F_104 ( struct V_1 * V_2 )
{
struct V_113 V_159 ;
int V_133 ;
F_102 ( V_2 , V_2 -> V_152 ) ;
if ( V_2 -> V_152 < V_2 -> V_12 . V_16 - 3 ) {
V_2 -> V_152 ++ ;
return;
}
F_21 ( V_2 ) ;
V_159 = V_2 -> V_114 [ 0 ] ;
V_159 . V_18 = 0 ;
for ( V_133 = 0 ; V_133 < V_2 -> V_12 . V_16 - 3 ; V_133 ++ )
V_2 -> V_114 [ V_133 ] = V_2 -> V_114 [ V_133 + 1 ] ;
V_2 -> V_114 [ V_2 -> V_12 . V_16 - 3 ] = V_159 ;
F_11 ( V_2 ) ;
}
static void
F_105 ( struct V_1 * V_2 )
{
if ( V_2 -> V_152 > 0 ) {
F_102 ( V_2 , V_2 -> V_152 ) ;
V_2 -> V_152 -- ;
}
}
static void
F_106 ( struct V_1 * V_2 , int V_40 )
{
struct V_113 * line ;
int V_160 ;
line = V_2 -> V_114 + V_2 -> V_152 ;
while ( line -> V_18 < V_2 -> V_153 ) {
line -> V_116 [ line -> V_18 ] . V_154 = V_2 -> V_12 . V_30 [ ' ' ] ;
line -> V_116 [ line -> V_18 ] . V_155 = V_47 ;
line -> V_116 [ line -> V_18 ] . V_156 = V_36 ;
line -> V_18 ++ ;
}
if ( V_40 > V_2 -> V_12 . V_13 - V_2 -> V_153 )
V_40 = V_2 -> V_12 . V_13 - V_2 -> V_153 ;
V_160 = F_107 ( int , line -> V_18 - V_2 -> V_153 , V_2 -> V_12 . V_13 - V_2 -> V_153 - V_40 ) ;
while ( V_160 -- )
line -> V_116 [ V_2 -> V_153 + V_40 + V_160 ] = line -> V_116 [ V_2 -> V_153 + V_160 ] ;
line -> V_18 += V_40 ;
if ( line -> V_18 > V_2 -> V_12 . V_13 )
line -> V_18 = V_2 -> V_12 . V_13 ;
while ( V_40 -- > 0 ) {
line -> V_116 [ V_2 -> V_153 + V_40 ] . V_154 = V_2 -> V_12 . V_30 [ ' ' ] ;
line -> V_116 [ V_2 -> V_153 + V_40 ] . V_155 = V_2 -> V_155 ;
line -> V_116 [ V_2 -> V_153 + V_40 ] . V_156 = V_2 -> V_156 ;
}
}
static void
F_108 ( struct V_1 * V_2 , int V_40 )
{
struct V_113 * line ;
int V_133 ;
line = V_2 -> V_114 + V_2 -> V_152 ;
if ( line -> V_18 <= V_2 -> V_153 )
return;
if ( line -> V_18 - V_2 -> V_153 <= V_40 ) {
line -> V_18 = V_2 -> V_153 ;
return;
}
for ( V_133 = V_2 -> V_153 ; V_133 + V_40 < line -> V_18 ; V_133 ++ )
line -> V_116 [ V_133 ] = line -> V_116 [ V_133 + V_40 ] ;
line -> V_18 -= V_40 ;
}
static void
F_109 ( struct V_1 * V_2 , int V_40 )
{
struct V_113 * line ;
struct V_115 * V_151 ;
line = V_2 -> V_114 + V_2 -> V_152 ;
while ( line -> V_18 > V_2 -> V_153 && V_40 -- > 0 ) {
V_151 = line -> V_116 + V_2 -> V_153 ++ ;
V_151 -> V_154 = ' ' ;
V_151 -> V_155 = V_47 ;
V_151 -> V_156 = V_36 ;
}
V_2 -> V_153 += V_40 ;
V_2 -> V_153 = F_107 ( int , V_2 -> V_153 , V_2 -> V_12 . V_13 - 1 ) ;
}
static void
F_110 ( struct V_1 * V_2 , int V_161 )
{
struct V_113 * line ;
struct V_115 * V_151 ;
int V_133 ;
line = V_2 -> V_114 + V_2 -> V_152 ;
if ( V_161 == 0 )
line -> V_18 = V_2 -> V_153 ;
else if ( V_161 == 1 ) {
for ( V_133 = 0 ; V_133 < V_2 -> V_153 ; V_133 ++ ) {
V_151 = line -> V_116 + V_133 ;
V_151 -> V_154 = ' ' ;
V_151 -> V_155 = V_47 ;
V_151 -> V_156 = V_36 ;
}
if ( line -> V_18 <= V_2 -> V_153 )
line -> V_18 = V_2 -> V_153 + 1 ;
} else if ( V_161 == 2 )
line -> V_18 = 0 ;
F_102 ( V_2 , V_2 -> V_152 ) ;
}
static void
F_111 ( struct V_1 * V_2 , int V_161 )
{
int V_133 ;
if ( V_161 == 0 ) {
F_110 ( V_2 , 0 ) ;
for ( V_133 = V_2 -> V_152 + 1 ; V_133 < V_2 -> V_12 . V_16 - 2 ; V_133 ++ ) {
V_2 -> V_114 [ V_133 ] . V_18 = 0 ;
F_102 ( V_2 , V_133 ) ;
}
} else if ( V_161 == 1 ) {
for ( V_133 = 0 ; V_133 < V_2 -> V_152 ; V_133 ++ ) {
V_2 -> V_114 [ V_133 ] . V_18 = 0 ;
F_102 ( V_2 , V_133 ) ;
}
F_110 ( V_2 , 1 ) ;
} else if ( V_161 == 2 ) {
for ( V_133 = 0 ; V_133 < V_2 -> V_12 . V_16 - 2 ; V_133 ++ ) {
V_2 -> V_114 [ V_133 ] . V_18 = 0 ;
F_102 ( V_2 , V_133 ) ;
}
}
F_11 ( V_2 ) ;
}
static void
F_112 ( struct V_1 * V_2 )
{
static unsigned char V_162 [] = {
V_163 , V_164 , V_35 , V_165 , V_166 ,
V_167 , V_168 , V_169 , 0 , V_163
} ;
int V_133 , V_170 ;
for ( V_133 = 0 ; V_133 <= V_2 -> V_171 ; V_133 ++ ) {
V_170 = V_2 -> V_172 [ V_133 ] ;
switch ( V_170 ) {
case 0 :
V_2 -> V_155 = V_47 ;
V_2 -> V_156 = V_36 ;
break;
case 4 :
V_2 -> V_155 = V_173 ;
break;
case 5 :
V_2 -> V_155 = V_174 ;
break;
case 7 :
V_2 -> V_155 = V_175 ;
break;
case 24 :
if ( V_2 -> V_155 == V_173 )
V_2 -> V_155 = V_47 ;
break;
case 25 :
if ( V_2 -> V_155 == V_174 )
V_2 -> V_155 = V_47 ;
break;
case 27 :
if ( V_2 -> V_155 == V_175 )
V_2 -> V_155 = V_47 ;
break;
case 30 :
case 31 :
case 32 :
case 33 :
case 34 :
case 35 :
case 36 :
case 37 :
case 39 :
V_2 -> V_156 = V_162 [ V_170 - 30 ] ;
break;
}
}
}
static inline int
F_113 ( struct V_1 * V_2 , int V_176 )
{
return ( V_2 -> V_172 [ V_176 ] > 0 ) ? V_2 -> V_172 [ V_176 ] : 1 ;
}
static void
F_114 ( struct V_1 * V_2 , int V_153 , int V_152 )
{
int V_177 = F_115 ( 0 , V_153 ) ;
int V_178 = F_115 ( 0 , V_152 ) ;
V_2 -> V_153 = F_107 ( int , V_2 -> V_12 . V_13 - 1 , V_177 ) ;
V_152 = F_107 ( int , V_2 -> V_12 . V_16 - 3 , V_178 ) ;
if ( V_152 != V_2 -> V_152 ) {
F_102 ( V_2 , V_2 -> V_152 ) ;
V_2 -> V_152 = V_152 ;
}
}
static void
F_116 ( struct V_1 * V_2 , char V_150 )
{
enum { V_179 , V_180 , V_181 , V_182 };
if ( V_2 -> V_183 == V_179 ) {
if ( V_150 == 0x1b )
V_2 -> V_183 = V_180 ;
return;
}
if ( V_2 -> V_183 == V_180 ) {
V_2 -> V_183 = V_179 ;
switch ( V_150 ) {
case '[' :
V_2 -> V_183 = V_181 ;
break;
case 'E' :
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
break;
case 'M' :
F_105 ( V_2 ) ;
break;
case 'D' :
F_104 ( V_2 ) ;
break;
case 'Z' :
F_117 ( & V_2 -> V_73 , L_3 ) ;
break;
case '7' :
V_2 -> V_184 = V_2 -> V_153 ;
V_2 -> V_185 = V_2 -> V_152 ;
V_2 -> V_186 = V_2 -> V_155 ;
V_2 -> V_187 = V_2 -> V_156 ;
break;
case '8' :
F_102 ( V_2 , V_2 -> V_152 ) ;
F_114 ( V_2 , V_2 -> V_184 , V_2 -> V_185 ) ;
V_2 -> V_155 = V_2 -> V_186 ;
V_2 -> V_156 = V_2 -> V_187 ;
break;
case 'c' :
V_2 -> V_153 = V_2 -> V_184 = 0 ;
V_2 -> V_152 = V_2 -> V_185 = 0 ;
V_2 -> V_155 = V_2 -> V_186 = V_47 ;
V_2 -> V_156 = V_2 -> V_187 = V_36 ;
F_111 ( V_2 , 2 ) ;
break;
}
return;
}
if ( V_2 -> V_183 == V_181 ) {
V_2 -> V_183 = V_182 ;
memset ( V_2 -> V_172 , 0 , sizeof( V_2 -> V_172 ) ) ;
V_2 -> V_171 = 0 ;
V_2 -> V_188 = ( V_150 == '?' ) ;
if ( V_2 -> V_188 )
return;
}
if ( V_2 -> V_183 == V_182 ) {
if ( V_150 == ';' && V_2 -> V_171 < V_189 - 1 ) {
V_2 -> V_171 ++ ;
return;
}
if ( V_150 >= '0' && V_150 <= '9' ) {
V_2 -> V_172 [ V_2 -> V_171 ] *= 10 ;
V_2 -> V_172 [ V_2 -> V_171 ] += V_150 - '0' ;
return;
}
}
V_2 -> V_183 = V_179 ;
if ( V_150 == 'n' && ! V_2 -> V_188 ) {
if ( V_2 -> V_172 [ 0 ] == 5 )
F_117 ( & V_2 -> V_73 , L_4 ) ;
else if ( V_2 -> V_172 [ 0 ] == 6 ) {
char V_190 [ 40 ] ;
sprintf ( V_190 , L_5 , V_2 -> V_152 + 1 , V_2 -> V_153 + 1 ) ;
F_117 ( & V_2 -> V_73 , V_190 ) ;
}
return;
}
if ( V_2 -> V_188 )
return;
switch ( V_150 ) {
case 'm' :
F_112 ( V_2 ) ;
break;
case 'H' :
case 'f' :
F_114 ( V_2 , F_113 ( V_2 , 1 ) - 1 ,
F_113 ( V_2 , 0 ) - 1 ) ;
break;
case 'd' :
F_114 ( V_2 , V_2 -> V_153 , F_113 ( V_2 , 0 ) - 1 ) ;
break;
case 'A' :
case 'F' :
F_114 ( V_2 , V_2 -> V_153 , V_2 -> V_152 - F_113 ( V_2 , 0 ) ) ;
break;
case 'B' :
case 'e' :
case 'E' :
F_114 ( V_2 , V_2 -> V_153 , V_2 -> V_152 + F_113 ( V_2 , 0 ) ) ;
break;
case 'C' :
case 'a' :
F_114 ( V_2 , V_2 -> V_153 + F_113 ( V_2 , 0 ) , V_2 -> V_152 ) ;
break;
case 'D' :
F_114 ( V_2 , V_2 -> V_153 - F_113 ( V_2 , 0 ) , V_2 -> V_152 ) ;
break;
case 'G' :
case '`' :
F_114 ( V_2 , F_113 ( V_2 , 0 ) , V_2 -> V_152 ) ;
break;
case 'X' :
F_109 ( V_2 , F_113 ( V_2 , 0 ) ) ;
break;
case 'J' :
F_111 ( V_2 , V_2 -> V_172 [ 0 ] ) ;
break;
case 'K' :
F_110 ( V_2 , V_2 -> V_172 [ 0 ] ) ;
break;
case 'P' :
F_108 ( V_2 , F_113 ( V_2 , 0 ) ) ;
break;
case '@' :
F_106 ( V_2 , F_113 ( V_2 , 0 ) ) ;
break;
case 's' :
V_2 -> V_184 = V_2 -> V_153 ;
V_2 -> V_185 = V_2 -> V_152 ;
V_2 -> V_186 = V_2 -> V_155 ;
V_2 -> V_187 = V_2 -> V_156 ;
break;
case 'u' :
F_102 ( V_2 , V_2 -> V_152 ) ;
F_114 ( V_2 , V_2 -> V_184 , V_2 -> V_185 ) ;
V_2 -> V_155 = V_2 -> V_186 ;
V_2 -> V_156 = V_2 -> V_187 ;
break;
}
}
static void
F_118 ( struct V_1 * V_2 , struct V_121 * V_122 ,
const unsigned char * V_190 , int V_7 )
{
int V_191 , V_133 ;
F_36 ( & V_2 -> V_12 . V_59 ) ;
for ( V_191 = 0 ; ! V_122 -> V_192 && V_191 < V_7 ; V_191 ++ ) {
if ( V_2 -> V_183 != 0 ) {
F_116 ( V_2 , V_190 [ V_191 ] ) ;
continue;
}
switch ( V_190 [ V_191 ] ) {
case 0x07 :
V_2 -> V_63 |= V_193 ;
break;
case 0x08 :
if ( V_2 -> V_153 > 0 ) {
V_2 -> V_153 -- ;
F_101 ( V_2 , ' ' ) ;
}
break;
case 0x09 :
for ( V_133 = V_2 -> V_153 % 8 ; V_133 < 8 ; V_133 ++ ) {
if ( V_2 -> V_153 >= V_2 -> V_12 . V_13 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
break;
}
F_101 ( V_2 , ' ' ) ;
V_2 -> V_153 ++ ;
}
break;
case 0x0a :
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
break;
case 0x0c :
F_111 ( V_2 , 2 ) ;
V_2 -> V_153 = V_2 -> V_152 = 0 ;
break;
case 0x0d :
V_2 -> V_153 = 0 ;
break;
case 0x0f :
break;
case 0x1b :
F_116 ( V_2 , V_190 [ V_191 ] ) ;
break;
default:
if ( V_2 -> V_153 >= V_2 -> V_12 . V_13 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
}
F_101 ( V_2 , V_190 [ V_191 ] ) ;
V_2 -> V_153 ++ ;
break;
}
}
F_102 ( V_2 , V_2 -> V_152 ) ;
if ( ! F_119 ( & V_2 -> V_4 ) )
F_1 ( V_2 , V_194 / 10 ) ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
}
static int
F_120 ( struct V_121 * V_122 ,
const unsigned char * V_190 , int V_7 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_195 > 0 ) {
F_118 ( V_2 , V_122 , V_2 -> V_196 , V_2 -> V_195 ) ;
V_2 -> V_195 = 0 ;
}
F_118 ( V_2 , V_122 , V_190 , V_7 ) ;
return V_7 ;
}
static int F_121 ( struct V_121 * V_122 , unsigned char V_150 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 || V_2 -> V_195 >= V_197 )
return 0 ;
V_2 -> V_196 [ V_2 -> V_195 ++ ] = V_150 ;
return 1 ;
}
static void
F_122 ( struct V_121 * V_122 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return;
if ( V_2 -> V_195 > 0 ) {
F_118 ( V_2 , V_122 , V_2 -> V_196 , V_2 -> V_195 ) ;
V_2 -> V_195 = 0 ;
}
}
static int
F_123 ( struct V_121 * V_122 )
{
return 0 ;
}
static void
F_124 ( struct V_121 * V_122 )
{
}
static void
F_125 ( struct V_121 * V_122 , struct V_198 * V_199 )
{
struct V_1 * V_2 ;
int V_200 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return;
F_36 ( & V_2 -> V_12 . V_59 ) ;
if ( F_126 ( V_122 ) ) {
V_200 = F_127 ( V_122 ) ? V_24 : V_79 ;
if ( V_200 != V_2 -> V_11 ) {
V_2 -> V_11 = V_200 ;
F_3 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
}
}
F_37 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_128 ( struct V_121 * V_122 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return;
V_2 -> V_91 = 1 ;
}
static void
F_129 ( struct V_121 * V_122 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return;
V_2 -> V_91 = 0 ;
if ( V_2 -> V_92 )
F_48 ( V_2 , 1 ) ;
}
static void
F_130 ( struct V_121 * V_122 )
{
}
static void
F_131 ( struct V_121 * V_122 , int V_201 )
{
}
static int F_132 ( struct V_121 * V_122 , unsigned int V_88 ,
unsigned long V_202 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return - V_203 ;
if ( V_122 -> V_204 & ( 1 << V_205 ) )
return - V_94 ;
return F_133 ( V_2 -> V_72 , V_88 , V_202 ) ;
}
static long F_134 ( struct V_121 * V_122 ,
unsigned int V_88 , unsigned long V_202 )
{
struct V_1 * V_2 ;
V_2 = V_122 -> V_132 ;
if ( ! V_2 )
return - V_203 ;
if ( V_122 -> V_204 & ( 1 << V_205 ) )
return - V_94 ;
return F_133 ( V_2 -> V_72 , V_88 , ( unsigned long ) F_135 ( V_202 ) ) ;
}
static void F_136 ( int V_206 )
{
F_137 ( V_207 , V_206 - V_134 , NULL ) ;
}
static void F_138 ( int V_206 )
{
F_139 ( V_207 , V_206 - V_134 ) ;
}
static int T_2 F_140 ( void )
{
struct V_137 * V_138 ;
int V_208 ;
V_138 = F_141 ( V_209 ,
V_210 |
V_211 |
V_212 ) ;
if ( F_62 ( V_138 ) )
return F_92 ( V_138 ) ;
V_138 -> V_213 = L_6 ;
V_138 -> V_214 = L_7 ;
V_138 -> V_215 = V_216 ;
V_138 -> V_217 = V_134 ;
V_138 -> V_218 = V_134 ;
V_138 -> type = V_219 ;
V_138 -> V_220 = V_221 ;
V_138 -> V_222 = V_223 ;
F_142 ( V_138 , & V_224 ) ;
V_208 = F_143 ( V_138 ) ;
if ( V_208 ) {
F_144 ( V_138 ) ;
return V_208 ;
}
V_207 = V_138 ;
F_145 ( & V_225 ) ;
return 0 ;
}
static void T_3
F_146 ( void )
{
struct V_137 * V_138 ;
F_147 ( & V_225 ) ;
V_138 = V_207 ;
V_207 = NULL ;
F_148 ( V_138 ) ;
F_144 ( V_138 ) ;
F_87 () ;
}
