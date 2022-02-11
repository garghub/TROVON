static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
F_2 ( & V_2 -> V_4 ) ;
else
F_3 ( & V_2 -> V_4 , V_5 + V_3 ) ;
}
static void
F_4 ( struct V_1 * V_2 , char * V_6 , int V_7 )
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
F_5 ( V_2 -> V_12 . V_17 , line -> string + V_7 + 8 , V_8 ) ;
line -> V_18 = 11 + V_7 ;
} else
line -> V_18 = 7 + V_7 ;
V_2 -> V_19 |= V_20 ;
}
static void
F_6 ( struct V_1 * V_2 )
{
static const unsigned char V_21 [] =
{ V_22 , 0 , 0 , 0x6e , V_23 , V_24 ,
V_14 , V_15 , 0 , 0 , 0 } ;
struct string * line ;
unsigned int V_25 ;
line = F_7 ( & V_2 -> V_26 ,
sizeof( V_21 ) + V_2 -> V_12 . V_13 * 2 - 9 ) ;
V_2 -> V_9 = line ;
V_2 -> V_11 = V_24 ;
memcpy ( line -> string , V_21 , sizeof( V_21 ) ) ;
line -> V_18 = sizeof( V_21 ) ;
V_25 = V_2 -> V_12 . V_13 * ( V_2 -> V_12 . V_16 - 2 ) ;
F_5 ( V_2 -> V_12 . V_17 , line -> string + 1 , V_25 ) ;
V_25 = V_2 -> V_12 . V_13 * V_2 -> V_12 . V_16 - 9 ;
F_5 ( V_2 -> V_12 . V_17 , line -> string + 8 , V_25 ) ;
V_2 -> V_6 = F_7 ( & V_2 -> V_26 , V_2 -> V_12 . V_13 * 2 - 9 + 6 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
char * V_27 ;
V_27 = ( V_2 -> V_28 != 0 ) ? L_1 : L_2 ;
memcpy ( V_2 -> V_29 -> string + 8 , V_27 , 7 ) ;
F_9 ( V_2 -> V_12 . V_30 , V_2 -> V_29 -> string + 8 , 7 ) ;
V_2 -> V_19 |= V_31 ;
}
static void
F_10 ( struct V_1 * V_2 )
{
static const unsigned char V_21 [] =
{ V_22 , 0 , 0 , V_23 , V_32 , V_33 , V_34 , V_35 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , V_23 , V_32 , V_33 , V_34 ,
V_36 } ;
struct string * line ;
unsigned int V_25 ;
line = F_7 ( & V_2 -> V_26 , sizeof( V_21 ) ) ;
V_2 -> V_29 = line ;
memcpy ( line -> string , V_21 , sizeof( V_21 ) ) ;
V_25 = V_2 -> V_12 . V_13 * V_2 -> V_12 . V_16 - 9 ;
F_5 ( V_2 -> V_12 . V_17 , line -> string + 1 , V_25 ) ;
}
static void
F_11 ( struct V_1 * V_2 , struct string * line , int V_37 )
{
unsigned char * V_38 ;
F_5 ( V_2 -> V_12 . V_17 , line -> string + 1 ,
V_2 -> V_12 . V_13 * V_37 ) ;
V_38 = line -> string + line -> V_18 - 4 ;
if ( * V_38 == V_15 )
F_5 ( V_2 -> V_12 . V_17 , V_38 + 1 ,
V_2 -> V_12 . V_13 * ( V_37 + 1 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct string * V_39 , * V_40 ;
int line , V_28 ;
F_13 (s, n, &tp->update, update)
F_14 ( & V_39 -> V_41 ) ;
line = V_2 -> V_12 . V_16 - 3 ;
V_28 = V_2 -> V_28 ;
F_15 (s, &tp->lines, list) {
if ( V_28 > 0 ) {
V_28 -- ;
continue;
}
F_11 ( V_2 , V_39 , line ) ;
F_16 ( & V_39 -> V_41 , & V_2 -> V_41 ) ;
if ( -- line < 0 )
break;
}
V_2 -> V_19 |= V_42 ;
}
static struct string *
F_17 ( struct V_1 * V_2 , T_1 V_43 )
{
struct string * V_39 , * V_40 ;
V_39 = F_7 ( & V_2 -> V_26 , V_43 ) ;
if ( V_39 )
return V_39 ;
F_13 (s, n, &tp->lines, list) {
F_18 ( V_2 -> V_44 <= V_2 -> V_12 . V_16 - 2 ) ;
F_19 ( & V_39 -> V_45 ) ;
if ( ! F_20 ( & V_39 -> V_41 ) )
F_19 ( & V_39 -> V_41 ) ;
V_2 -> V_44 -- ;
if ( F_21 ( & V_2 -> V_26 , V_39 ) >= V_43 )
break;
}
V_39 = F_7 ( & V_2 -> V_26 , V_43 ) ;
F_18 ( ! V_39 ) ;
if ( V_2 -> V_28 != 0 &&
V_2 -> V_28 + V_2 -> V_12 . V_16 - 2 >= V_2 -> V_44 ) {
V_2 -> V_28 = V_2 -> V_44 - V_2 -> V_12 . V_16 + 2 ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
}
return V_39 ;
}
static void
F_22 ( struct V_1 * V_2 )
{
static const unsigned char V_21 [] =
{ V_22 , 0 , 0 , V_33 , V_46 , V_47 ,
V_33 , V_34 , V_36 , V_15 , 0 , 0 , 0 } ;
struct string * V_39 ;
V_39 = F_17 ( V_2 , sizeof( V_21 ) ) ;
memcpy ( V_39 -> string , V_21 , sizeof( V_21 ) ) ;
V_39 -> V_18 = sizeof( V_21 ) ;
F_23 ( & V_39 -> V_45 , & V_2 -> V_48 ) ;
V_2 -> V_44 ++ ;
if ( V_2 -> V_28 != 0 )
V_2 -> V_28 ++ ;
}
static void
F_24 ( struct V_49 * V_50 , void * V_51 )
{
struct V_1 * V_2 = F_25 ( V_50 -> V_12 , struct V_1 , V_12 ) ;
if ( V_50 -> V_52 != 0 ) {
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
}
F_26 ( V_50 ) ;
F_27 ( & V_2 -> V_54 , V_50 ) ;
}
static void
F_28 ( struct V_1 * V_2 )
{
static char V_55 [ 2 ] = { 0xff , 0xff } ;
struct V_49 * V_56 ;
unsigned long V_57 ;
struct string * V_39 , * V_40 ;
char * V_58 , * V_27 ;
int V_52 , V_18 ;
V_56 = F_27 ( & V_2 -> V_54 , 0 ) ;
if ( ! V_56 ) {
F_1 ( V_2 , 1 ) ;
return;
}
F_29 ( & V_2 -> V_12 . V_59 ) ;
V_57 = 0 ;
if ( V_2 -> V_19 & V_53 ) {
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
V_2 -> V_19 = V_60 | V_42 |
V_20 | V_31 ;
}
if ( V_2 -> V_19 & V_60 ) {
F_30 ( V_56 , V_61 ) ;
V_57 |= V_60 ;
} else
F_30 ( V_56 , V_62 ) ;
F_31 ( V_56 , & V_2 -> V_63 , 1 ) ;
V_2 -> V_63 = V_64 ;
if ( V_2 -> V_19 & V_31 )
if ( F_31 ( V_56 , V_2 -> V_29 -> string ,
V_2 -> V_29 -> V_18 ) == 0 )
V_57 |= V_31 ;
if ( V_2 -> V_19 & V_20 )
if ( F_31 ( V_56 , V_2 -> V_9 -> string ,
V_2 -> V_9 -> V_18 ) == 0 )
V_57 |= V_20 ;
V_58 = V_55 ;
if ( V_2 -> V_19 & V_42 ) {
F_13 (s, n, &tp->update, update) {
V_27 = V_39 -> string ;
V_18 = V_39 -> V_18 ;
if ( V_39 -> string [ 1 ] == V_58 [ 0 ] && V_39 -> string [ 2 ] == V_58 [ 1 ] )
V_27 += 3 , V_18 -= 3 ;
if ( F_31 ( V_56 , V_27 , V_18 ) != 0 )
break;
F_14 ( & V_39 -> V_41 ) ;
V_58 = V_39 -> string + V_39 -> V_18 - 3 ;
}
if ( F_20 ( & V_2 -> V_41 ) )
V_57 |= V_42 ;
}
V_56 -> V_65 = F_24 ;
V_52 = F_32 ( & V_2 -> V_12 , V_56 ) ;
if ( V_52 == 0 ) {
V_2 -> V_19 &= ~ V_57 ;
if ( V_2 -> V_19 )
F_1 ( V_2 , 1 ) ;
} else {
F_26 ( V_56 ) ;
F_27 ( & V_2 -> V_54 , V_56 ) ;
}
F_33 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_34 ( struct V_1 * V_2 , char * V_6 , int V_18 )
{
struct string * V_39 ;
V_2 -> V_66 = NULL ;
if ( V_18 <= 0 )
return;
if ( V_2 -> V_67 >= V_2 -> V_68 ) {
V_39 = F_35 ( V_2 -> V_69 . V_70 , struct string , V_45 ) ;
F_19 ( & V_39 -> V_45 ) ;
F_21 ( & V_2 -> V_26 , V_39 ) ;
V_2 -> V_67 -- ;
}
V_39 = F_17 ( V_2 , V_18 ) ;
memcpy ( V_39 -> string , V_6 , V_18 ) ;
F_23 ( & V_39 -> V_45 , & V_2 -> V_69 ) ;
V_2 -> V_67 ++ ;
}
static void
F_36 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_25 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
struct string * V_39 ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
if ( V_2 -> V_11 == V_24 ) {
if ( V_2 -> V_66 && V_2 -> V_66 -> V_74 != & V_2 -> V_69 )
V_2 -> V_66 = V_2 -> V_66 -> V_74 ;
else if ( ! F_20 ( & V_2 -> V_69 ) )
V_2 -> V_66 = V_2 -> V_69 . V_74 ;
V_39 = V_2 -> V_66 ?
F_35 ( V_2 -> V_66 , struct string , V_45 ) : NULL ;
if ( V_2 -> V_66 ) {
V_39 = F_35 ( V_2 -> V_66 , struct string , V_45 ) ;
F_4 ( V_2 , V_39 -> string , V_39 -> V_18 ) ;
} else
F_4 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_39 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_25 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
F_40 ( & V_2 -> V_12 ) ;
}
static void
F_41 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_25 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
int V_28 ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
V_28 = V_2 -> V_28 - V_2 -> V_12 . V_16 + 2 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_42 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_25 ( V_72 -> V_73 , struct V_1 , V_73 ) ;
int V_28 ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
V_28 = V_2 -> V_28 + V_2 -> V_12 . V_16 - 2 ;
if ( V_28 + V_2 -> V_12 . V_16 - 2 > V_2 -> V_44 )
V_28 = V_2 -> V_44 - V_2 -> V_12 . V_16 + 2 ;
if ( V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_43 ( struct V_49 * V_75 )
{
static char V_76 = V_77 ;
struct V_1 * V_2 = F_25 ( V_75 -> V_12 , struct V_1 , V_12 ) ;
char * V_6 ;
int V_18 ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
V_6 = NULL ;
V_18 = 0 ;
if ( V_2 -> V_6 -> string [ 0 ] == 0x7d ) {
V_6 = V_2 -> V_6 -> string + 6 ;
V_18 = V_2 -> V_6 -> V_18 - 6 - V_75 -> V_78 ;
if ( V_2 -> V_11 != V_79 )
F_34 ( V_2 , V_6 , V_18 ) ;
if ( V_2 -> V_28 > 0 ) {
V_2 -> V_28 = 0 ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
}
F_4 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
} else if ( V_2 -> V_6 -> string [ 0 ] == 0x6d ) {
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_59 ) ;
F_26 ( V_2 -> V_80 ) ;
F_30 ( V_2 -> V_80 , V_62 ) ;
F_31 ( V_2 -> V_80 , & V_76 , 1 ) ;
F_32 ( & V_2 -> V_12 , V_2 -> V_80 ) ;
while ( V_18 -- > 0 )
F_44 ( V_2 -> V_72 , * V_6 ++ ) ;
F_44 ( V_2 -> V_72 , 256 + V_2 -> V_6 -> string [ 0 ] ) ;
F_26 ( V_75 ) ;
F_27 ( & V_2 -> V_81 , V_75 ) ;
F_45 ( & V_2 -> V_12 ) ;
}
static void
F_46 ( struct V_49 * V_50 , void * V_51 )
{
struct V_1 * V_2 = F_25 ( V_50 -> V_12 , struct V_1 , V_12 ) ;
F_47 ( V_50 -> V_12 ) ;
F_48 ( & V_2 -> V_82 ) ;
}
static void
F_49 ( struct V_1 * V_2 , int V_59 )
{
struct V_49 * V_75 ;
int V_52 ;
V_75 = F_27 ( & V_2 -> V_81 , 0 ) ;
if ( ! V_75 )
return;
V_75 -> V_65 = F_46 ;
V_75 -> V_83 = V_2 ;
F_30 ( V_75 , V_84 ) ;
F_50 ( V_75 , V_2 -> V_6 -> string , V_2 -> V_6 -> V_18 ) ;
if ( V_59 ) {
V_52 = F_32 ( & V_2 -> V_12 , V_75 ) ;
} else
V_52 = F_51 ( & V_2 -> V_12 , V_75 ) ;
if ( V_52 ) {
F_26 ( V_75 ) ;
F_27 ( & V_2 -> V_81 , V_75 ) ;
}
}
static int
F_52 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
V_2 -> V_19 = V_53 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static void
F_53 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
F_2 ( & V_2 -> V_4 ) ;
}
static int
F_54 ( struct V_1 * V_2 , struct V_49 * V_50 , struct V_86 * V_86 )
{
if ( V_86 -> V_87 . V_88 . V_89 & V_90 ) {
if ( ! V_2 -> V_91 )
F_49 ( V_2 , 0 ) ;
else
V_2 -> V_92 = 1 ;
}
if ( V_50 ) {
if ( V_86 -> V_87 . V_88 . V_89 & V_93 )
V_50 -> V_52 = - V_94 ;
else
V_50 -> V_78 = V_86 -> V_87 . V_88 . V_7 ;
}
return V_95 ;
}
static struct V_1 *
F_55 ( void )
{
struct V_1 * V_2 ;
int V_96 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_97 ) ;
if ( ! V_2 )
goto V_98;
V_2 -> V_99 =
F_57 ( sizeof( void * ) * V_100 , V_97 ) ;
if ( ! V_2 -> V_99 )
goto V_101;
F_58 ( & V_2 -> V_26 ) ;
F_58 ( & V_2 -> V_48 ) ;
F_58 ( & V_2 -> V_41 ) ;
F_58 ( & V_2 -> V_69 ) ;
V_2 -> V_68 = 20 ;
F_59 ( & V_2 -> V_73 ) ;
F_60 ( & V_2 -> V_4 , ( void (*) ( unsigned long ) ) F_28 ,
( unsigned long ) V_2 ) ;
F_61 ( & V_2 -> V_82 ,
( void (*) ( unsigned long ) ) F_43 ,
( unsigned long ) V_2 -> V_81 ) ;
for ( V_96 = 0 ; V_96 < V_100 ; V_96 ++ ) {
V_2 -> V_99 [ V_96 ] = ( void * )
F_62 ( V_97 | V_102 , 0 ) ;
if ( ! V_2 -> V_99 [ V_96 ] )
goto V_103;
F_63 ( & V_2 -> V_26 ,
V_2 -> V_99 [ V_96 ] , V_104 ) ;
}
V_2 -> V_54 = F_64 ( V_105 ) ;
if ( F_65 ( V_2 -> V_54 ) )
goto V_103;
V_2 -> V_81 = F_64 ( 0 ) ;
if ( F_65 ( V_2 -> V_81 ) )
goto V_106;
V_2 -> V_80 = F_64 ( 1 ) ;
if ( F_65 ( V_2 -> V_80 ) )
goto V_107;
V_2 -> V_72 = F_66 () ;
if ( ! V_2 -> V_72 )
goto V_108;
return V_2 ;
V_108:
F_67 ( V_2 -> V_80 ) ;
V_107:
F_67 ( V_2 -> V_81 ) ;
V_106:
F_67 ( V_2 -> V_54 ) ;
V_103:
while ( V_96 -- )
F_68 ( ( unsigned long ) V_2 -> V_99 [ V_96 ] , 0 ) ;
F_69 ( V_2 -> V_99 ) ;
V_101:
F_69 ( V_2 ) ;
V_98:
return F_70 ( - V_109 ) ;
}
static void
F_71 ( struct V_1 * V_2 )
{
int V_96 ;
F_72 ( & V_2 -> V_4 ) ;
F_73 ( V_2 -> V_72 ) ;
F_67 ( V_2 -> V_80 ) ;
F_67 ( V_2 -> V_81 ) ;
F_67 ( V_2 -> V_54 ) ;
for ( V_96 = 0 ; V_96 < V_100 ; V_96 ++ )
F_68 ( ( unsigned long ) V_2 -> V_99 [ V_96 ] , 0 ) ;
F_69 ( V_2 -> V_99 ) ;
F_69 ( V_2 ) ;
}
static int
F_74 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
int V_48 ;
V_43 = sizeof( struct V_110 ) * ( V_2 -> V_12 . V_16 - 2 ) ;
V_2 -> V_111 = F_56 ( V_43 , V_97 ) ;
if ( ! V_2 -> V_111 )
goto V_98;
for ( V_48 = 0 ; V_48 < V_2 -> V_12 . V_16 - 2 ; V_48 ++ ) {
V_43 = sizeof( struct V_112 ) * V_2 -> V_12 . V_13 ;
V_2 -> V_111 [ V_48 ] . V_113 = F_56 ( V_43 , V_97 ) ;
if ( ! V_2 -> V_111 [ V_48 ] . V_113 )
goto V_114;
}
return 0 ;
V_114:
while ( V_48 -- )
F_69 ( V_2 -> V_111 [ V_48 ] . V_113 ) ;
F_69 ( V_2 -> V_111 ) ;
V_98:
return - V_109 ;
}
static void
F_75 ( struct V_1 * V_2 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_12 . V_16 - 2 ; V_48 ++ )
F_69 ( V_2 -> V_111 [ V_48 ] . V_113 ) ;
F_69 ( V_2 -> V_111 ) ;
}
static void
F_76 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
struct V_115 * V_116 = F_77 ( & V_2 -> V_73 ) ;
if ( V_116 ) {
V_116 -> V_117 = NULL ;
F_78 ( & V_2 -> V_73 , NULL ) ;
F_79 ( V_116 ) ;
F_45 ( & V_2 -> V_12 ) ;
F_80 ( V_116 ) ;
}
}
static void
F_81 ( struct V_85 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
F_75 ( V_2 ) ;
F_71 ( V_2 ) ;
}
static void
F_82 ( void )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
struct V_85 * V_12 =
F_83 ( & V_120 , V_118 + V_121 ) ;
if ( ! F_65 ( V_12 ) )
F_84 ( V_12 ) ;
}
}
static int
F_85 ( struct V_115 * V_116 , struct V_122 * V_123 )
{
struct V_85 * V_12 ;
struct V_1 * V_2 ;
int V_118 , V_52 ;
if ( V_116 -> V_7 > 1 )
return 0 ;
V_12 = F_83 ( & V_120 ,
V_116 -> V_124 + V_121 ) ;
if ( ! F_65 ( V_12 ) ) {
V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
V_116 -> V_117 = V_2 ;
V_116 -> V_125 . V_126 = V_2 -> V_12 . V_16 - 2 ;
V_116 -> V_125 . V_127 = V_2 -> V_12 . V_13 ;
V_116 -> V_128 = 0 ;
F_78 ( & V_2 -> V_73 , V_116 ) ;
V_2 -> V_11 = V_24 ;
return 0 ;
}
if ( V_119 < V_116 -> V_124 + 1 )
V_119 = V_116 -> V_124 + 1 ;
if ( F_86 ( V_12 ) == - V_129 )
return - V_129 ;
V_2 = F_55 () ;
if ( F_65 ( V_2 ) )
return F_86 ( V_2 ) ;
V_52 = F_87 ( & V_2 -> V_12 , & V_120 ,
V_116 -> V_124 + V_121 ) ;
if ( V_52 ) {
F_71 ( V_2 ) ;
return V_52 ;
}
V_52 = F_74 ( V_2 ) ;
if ( V_52 ) {
F_45 ( & V_2 -> V_12 ) ;
F_84 ( & V_2 -> V_12 ) ;
return V_52 ;
}
F_78 ( & V_2 -> V_73 , V_116 ) ;
V_116 -> V_128 = 0 ;
V_116 -> V_117 = V_2 ;
V_116 -> V_125 . V_126 = V_2 -> V_12 . V_16 - 2 ;
V_116 -> V_125 . V_127 = V_2 -> V_12 . V_13 ;
F_6 ( V_2 ) ;
F_10 ( V_2 ) ;
F_8 ( V_2 ) ;
for ( V_118 = 0 ; V_118 < V_2 -> V_12 . V_16 - 2 ; V_118 ++ )
F_22 ( V_2 ) ;
V_2 -> V_72 -> V_73 = & V_2 -> V_73 ;
V_2 -> V_72 -> V_130 [ F_88 ( V_131 ) ] = F_39 ;
V_2 -> V_72 -> V_130 [ F_88 ( V_132 ) ] = F_42 ;
V_2 -> V_72 -> V_130 [ F_88 ( V_133 ) ] = F_41 ;
V_2 -> V_72 -> V_130 [ F_88 ( V_134 ) ] = F_36 ;
F_89 ( V_2 -> V_72 , V_2 -> V_12 . V_30 ) ;
F_90 ( & V_2 -> V_12 ) ;
return 0 ;
}
static void
F_91 ( struct V_115 * V_116 , struct V_122 * V_123 )
{
struct V_1 * V_2 = V_116 -> V_117 ;
if ( V_116 -> V_7 > 1 )
return;
if ( V_2 ) {
V_116 -> V_117 = NULL ;
F_78 ( & V_2 -> V_73 , NULL ) ;
F_45 ( & V_2 -> V_12 ) ;
}
}
static int
F_92 ( struct V_115 * V_116 )
{
return V_135 ;
}
static void F_93 ( struct V_1 * V_2 , char V_136 )
{
struct V_110 * line ;
struct V_112 * V_137 ;
line = V_2 -> V_111 + V_2 -> V_138 ;
if ( line -> V_18 <= V_2 -> V_139 ) {
while ( line -> V_18 < V_2 -> V_139 ) {
V_137 = line -> V_113 + line -> V_18 ;
V_137 -> V_140 = V_2 -> V_12 . V_30 [ ' ' ] ;
V_137 -> V_141 = V_2 -> V_141 ;
V_137 -> V_142 = V_2 -> V_142 ;
line -> V_18 ++ ;
}
line -> V_18 ++ ;
}
V_137 = line -> V_113 + V_2 -> V_139 ;
V_137 -> V_140 = V_2 -> V_12 . V_30 [ ( unsigned int ) V_136 ] ;
V_137 -> V_141 = V_2 -> V_141 ;
V_137 -> V_142 = V_2 -> V_142 ;
}
static void
F_94 ( struct V_1 * V_2 , int V_143 )
{
struct V_110 * line ;
struct V_112 * V_137 ;
struct string * V_39 , * V_40 ;
unsigned char V_141 ;
unsigned char V_142 ;
char * V_38 ;
int V_144 , V_118 ;
V_144 = 3 ;
line = V_2 -> V_111 + V_143 ;
V_144 += line -> V_18 ;
V_141 = V_47 ;
V_142 = V_36 ;
for ( V_118 = 0 , V_137 = line -> V_113 ; V_118 < line -> V_18 ; V_118 ++ , V_137 ++ ) {
if ( V_137 -> V_141 != V_141 ) {
V_144 += 3 ;
V_141 = V_137 -> V_141 ;
}
if ( V_137 -> V_142 != V_142 ) {
V_144 += 3 ;
V_142 = V_137 -> V_142 ;
}
}
if ( V_141 != V_47 )
V_144 += 3 ;
if ( V_142 != V_36 )
V_144 += 3 ;
if ( line -> V_18 < V_2 -> V_12 . V_13 )
V_144 += 4 ;
V_118 = V_2 -> V_12 . V_16 - 2 - V_143 ;
F_15 (s, &tp->lines, list)
if ( -- V_118 <= 0 )
break;
if ( V_39 -> V_18 != V_144 ) {
V_40 = F_17 ( V_2 , V_144 ) ;
F_16 ( & V_40 -> V_45 , & V_39 -> V_45 ) ;
F_14 ( & V_39 -> V_45 ) ;
if ( ! F_20 ( & V_39 -> V_41 ) )
F_14 ( & V_39 -> V_41 ) ;
F_21 ( & V_2 -> V_26 , V_39 ) ;
V_39 = V_40 ;
}
V_38 = V_39 -> string ;
* V_38 ++ = V_22 ;
* V_38 ++ = 0 ;
* V_38 ++ = 0 ;
V_141 = V_47 ;
V_142 = V_36 ;
for ( V_118 = 0 , V_137 = line -> V_113 ; V_118 < line -> V_18 ; V_118 ++ , V_137 ++ ) {
if ( V_137 -> V_141 != V_141 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_46 ;
* V_38 ++ = V_137 -> V_141 ;
V_141 = V_137 -> V_141 ;
}
if ( V_137 -> V_142 != V_142 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_34 ;
* V_38 ++ = V_137 -> V_142 ;
V_142 = V_137 -> V_142 ;
}
* V_38 ++ = V_137 -> V_140 ;
}
if ( V_141 != V_47 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_46 ;
* V_38 ++ = V_47 ;
}
if ( V_142 != V_36 ) {
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
if ( V_2 -> V_28 + V_143 < V_2 -> V_12 . V_16 - 2 ) {
F_11 ( V_2 , V_39 , V_143 ) ;
if ( F_20 ( & V_39 -> V_41 ) ) {
F_23 ( & V_39 -> V_41 , & V_2 -> V_41 ) ;
V_2 -> V_19 |= V_42 ;
}
}
}
static void
F_95 ( struct V_1 * V_2 )
{
V_2 -> V_139 = 0 ;
}
static void
F_96 ( struct V_1 * V_2 )
{
struct V_110 V_145 ;
int V_118 ;
F_94 ( V_2 , V_2 -> V_138 ) ;
if ( V_2 -> V_138 < V_2 -> V_12 . V_16 - 3 ) {
V_2 -> V_138 ++ ;
return;
}
F_22 ( V_2 ) ;
V_145 = V_2 -> V_111 [ 0 ] ;
V_145 . V_18 = 0 ;
for ( V_118 = 0 ; V_118 < V_2 -> V_12 . V_16 - 3 ; V_118 ++ )
V_2 -> V_111 [ V_118 ] = V_2 -> V_111 [ V_118 + 1 ] ;
V_2 -> V_111 [ V_2 -> V_12 . V_16 - 3 ] = V_145 ;
F_12 ( V_2 ) ;
}
static void
F_97 ( struct V_1 * V_2 )
{
if ( V_2 -> V_138 > 0 ) {
F_94 ( V_2 , V_2 -> V_138 ) ;
V_2 -> V_138 -- ;
}
}
static void
F_98 ( struct V_1 * V_2 , int V_40 )
{
struct V_110 * line ;
int V_146 ;
line = V_2 -> V_111 + V_2 -> V_138 ;
while ( line -> V_18 < V_2 -> V_139 ) {
line -> V_113 [ line -> V_18 ] . V_140 = V_2 -> V_12 . V_30 [ ' ' ] ;
line -> V_113 [ line -> V_18 ] . V_141 = V_47 ;
line -> V_113 [ line -> V_18 ] . V_142 = V_36 ;
line -> V_18 ++ ;
}
if ( V_40 > V_2 -> V_12 . V_13 - V_2 -> V_139 )
V_40 = V_2 -> V_12 . V_13 - V_2 -> V_139 ;
V_146 = F_99 ( int , line -> V_18 - V_2 -> V_139 , V_2 -> V_12 . V_13 - V_2 -> V_139 - V_40 ) ;
while ( V_146 -- )
line -> V_113 [ V_2 -> V_139 + V_40 + V_146 ] = line -> V_113 [ V_2 -> V_139 + V_146 ] ;
line -> V_18 += V_40 ;
if ( line -> V_18 > V_2 -> V_12 . V_13 )
line -> V_18 = V_2 -> V_12 . V_13 ;
while ( V_40 -- > 0 ) {
line -> V_113 [ V_2 -> V_139 + V_40 ] . V_140 = V_2 -> V_12 . V_30 [ ' ' ] ;
line -> V_113 [ V_2 -> V_139 + V_40 ] . V_141 = V_2 -> V_141 ;
line -> V_113 [ V_2 -> V_139 + V_40 ] . V_142 = V_2 -> V_142 ;
}
}
static void
F_100 ( struct V_1 * V_2 , int V_40 )
{
struct V_110 * line ;
int V_118 ;
line = V_2 -> V_111 + V_2 -> V_138 ;
if ( line -> V_18 <= V_2 -> V_139 )
return;
if ( line -> V_18 - V_2 -> V_139 <= V_40 ) {
line -> V_18 = V_2 -> V_139 ;
return;
}
for ( V_118 = V_2 -> V_139 ; V_118 + V_40 < line -> V_18 ; V_118 ++ )
line -> V_113 [ V_118 ] = line -> V_113 [ V_118 + V_40 ] ;
line -> V_18 -= V_40 ;
}
static void
F_101 ( struct V_1 * V_2 , int V_40 )
{
struct V_110 * line ;
struct V_112 * V_137 ;
line = V_2 -> V_111 + V_2 -> V_138 ;
while ( line -> V_18 > V_2 -> V_139 && V_40 -- > 0 ) {
V_137 = line -> V_113 + V_2 -> V_139 ++ ;
V_137 -> V_140 = ' ' ;
V_137 -> V_141 = V_47 ;
V_137 -> V_142 = V_36 ;
}
V_2 -> V_139 += V_40 ;
V_2 -> V_139 = F_99 ( int , V_2 -> V_139 , V_2 -> V_12 . V_13 - 1 ) ;
}
static void
F_102 ( struct V_1 * V_2 , int V_147 )
{
struct V_110 * line ;
struct V_112 * V_137 ;
int V_118 ;
line = V_2 -> V_111 + V_2 -> V_138 ;
if ( V_147 == 0 )
line -> V_18 = V_2 -> V_139 ;
else if ( V_147 == 1 ) {
for ( V_118 = 0 ; V_118 < V_2 -> V_139 ; V_118 ++ ) {
V_137 = line -> V_113 + V_118 ;
V_137 -> V_140 = ' ' ;
V_137 -> V_141 = V_47 ;
V_137 -> V_142 = V_36 ;
}
if ( line -> V_18 <= V_2 -> V_139 )
line -> V_18 = V_2 -> V_139 + 1 ;
} else if ( V_147 == 2 )
line -> V_18 = 0 ;
F_94 ( V_2 , V_2 -> V_138 ) ;
}
static void
F_103 ( struct V_1 * V_2 , int V_147 )
{
int V_118 ;
if ( V_147 == 0 ) {
F_102 ( V_2 , 0 ) ;
for ( V_118 = V_2 -> V_138 + 1 ; V_118 < V_2 -> V_12 . V_16 - 2 ; V_118 ++ ) {
V_2 -> V_111 [ V_118 ] . V_18 = 0 ;
F_94 ( V_2 , V_118 ) ;
}
} else if ( V_147 == 1 ) {
for ( V_118 = 0 ; V_118 < V_2 -> V_138 ; V_118 ++ ) {
V_2 -> V_111 [ V_118 ] . V_18 = 0 ;
F_94 ( V_2 , V_118 ) ;
}
F_102 ( V_2 , 1 ) ;
} else if ( V_147 == 2 ) {
for ( V_118 = 0 ; V_118 < V_2 -> V_12 . V_16 - 2 ; V_118 ++ ) {
V_2 -> V_111 [ V_118 ] . V_18 = 0 ;
F_94 ( V_2 , V_118 ) ;
}
}
F_12 ( V_2 ) ;
}
static void
F_104 ( struct V_1 * V_2 )
{
static unsigned char V_148 [] = {
V_149 , V_150 , V_35 , V_151 , V_152 ,
V_153 , V_154 , V_155 , 0 , V_149
} ;
int V_118 , V_156 ;
for ( V_118 = 0 ; V_118 <= V_2 -> V_157 ; V_118 ++ ) {
V_156 = V_2 -> V_158 [ V_118 ] ;
switch ( V_156 ) {
case 0 :
V_2 -> V_141 = V_47 ;
V_2 -> V_142 = V_36 ;
break;
case 4 :
V_2 -> V_141 = V_159 ;
break;
case 5 :
V_2 -> V_141 = V_160 ;
break;
case 7 :
V_2 -> V_141 = V_161 ;
break;
case 24 :
if ( V_2 -> V_141 == V_159 )
V_2 -> V_141 = V_47 ;
break;
case 25 :
if ( V_2 -> V_141 == V_160 )
V_2 -> V_141 = V_47 ;
break;
case 27 :
if ( V_2 -> V_141 == V_161 )
V_2 -> V_141 = V_47 ;
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
V_2 -> V_142 = V_148 [ V_156 - 30 ] ;
break;
}
}
}
static inline int
F_105 ( struct V_1 * V_2 , int V_162 )
{
return ( V_2 -> V_158 [ V_162 ] > 0 ) ? V_2 -> V_158 [ V_162 ] : 1 ;
}
static void
F_106 ( struct V_1 * V_2 , int V_139 , int V_138 )
{
int V_163 = F_107 ( 0 , V_139 ) ;
int V_164 = F_107 ( 0 , V_138 ) ;
V_2 -> V_139 = F_99 ( int , V_2 -> V_12 . V_13 - 1 , V_163 ) ;
V_138 = F_99 ( int , V_2 -> V_12 . V_16 - 3 , V_164 ) ;
if ( V_138 != V_2 -> V_138 ) {
F_94 ( V_2 , V_2 -> V_138 ) ;
V_2 -> V_138 = V_138 ;
}
}
static void
F_108 ( struct V_1 * V_2 , char V_136 )
{
enum { V_165 , V_166 , V_167 , V_168 };
if ( V_2 -> V_169 == V_165 ) {
if ( V_136 == 0x1b )
V_2 -> V_169 = V_166 ;
return;
}
if ( V_2 -> V_169 == V_166 ) {
V_2 -> V_169 = V_165 ;
switch ( V_136 ) {
case '[' :
V_2 -> V_169 = V_167 ;
break;
case 'E' :
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
break;
case 'M' :
F_97 ( V_2 ) ;
break;
case 'D' :
F_96 ( V_2 ) ;
break;
case 'Z' :
F_109 ( & V_2 -> V_73 , L_3 ) ;
break;
case '7' :
V_2 -> V_170 = V_2 -> V_139 ;
V_2 -> V_171 = V_2 -> V_138 ;
V_2 -> V_172 = V_2 -> V_141 ;
V_2 -> V_173 = V_2 -> V_142 ;
break;
case '8' :
F_94 ( V_2 , V_2 -> V_138 ) ;
F_106 ( V_2 , V_2 -> V_170 , V_2 -> V_171 ) ;
V_2 -> V_141 = V_2 -> V_172 ;
V_2 -> V_142 = V_2 -> V_173 ;
break;
case 'c' :
V_2 -> V_139 = V_2 -> V_170 = 0 ;
V_2 -> V_138 = V_2 -> V_171 = 0 ;
V_2 -> V_141 = V_2 -> V_172 = V_47 ;
V_2 -> V_142 = V_2 -> V_173 = V_36 ;
F_103 ( V_2 , 2 ) ;
break;
}
return;
}
if ( V_2 -> V_169 == V_167 ) {
V_2 -> V_169 = V_168 ;
memset ( V_2 -> V_158 , 0 , sizeof( V_2 -> V_158 ) ) ;
V_2 -> V_157 = 0 ;
V_2 -> V_174 = ( V_136 == '?' ) ;
if ( V_2 -> V_174 )
return;
}
if ( V_2 -> V_169 == V_168 ) {
if ( V_136 == ';' && V_2 -> V_157 < V_175 - 1 ) {
V_2 -> V_157 ++ ;
return;
}
if ( V_136 >= '0' && V_136 <= '9' ) {
V_2 -> V_158 [ V_2 -> V_157 ] *= 10 ;
V_2 -> V_158 [ V_2 -> V_157 ] += V_136 - '0' ;
return;
}
}
V_2 -> V_169 = V_165 ;
if ( V_136 == 'n' && ! V_2 -> V_174 ) {
if ( V_2 -> V_158 [ 0 ] == 5 )
F_109 ( & V_2 -> V_73 , L_4 ) ;
else if ( V_2 -> V_158 [ 0 ] == 6 ) {
char V_176 [ 40 ] ;
sprintf ( V_176 , L_5 , V_2 -> V_138 + 1 , V_2 -> V_139 + 1 ) ;
F_109 ( & V_2 -> V_73 , V_176 ) ;
}
return;
}
if ( V_2 -> V_174 )
return;
switch ( V_136 ) {
case 'm' :
F_104 ( V_2 ) ;
break;
case 'H' :
case 'f' :
F_106 ( V_2 , F_105 ( V_2 , 1 ) - 1 ,
F_105 ( V_2 , 0 ) - 1 ) ;
break;
case 'd' :
F_106 ( V_2 , V_2 -> V_139 , F_105 ( V_2 , 0 ) - 1 ) ;
break;
case 'A' :
case 'F' :
F_106 ( V_2 , V_2 -> V_139 , V_2 -> V_138 - F_105 ( V_2 , 0 ) ) ;
break;
case 'B' :
case 'e' :
case 'E' :
F_106 ( V_2 , V_2 -> V_139 , V_2 -> V_138 + F_105 ( V_2 , 0 ) ) ;
break;
case 'C' :
case 'a' :
F_106 ( V_2 , V_2 -> V_139 + F_105 ( V_2 , 0 ) , V_2 -> V_138 ) ;
break;
case 'D' :
F_106 ( V_2 , V_2 -> V_139 - F_105 ( V_2 , 0 ) , V_2 -> V_138 ) ;
break;
case 'G' :
case '`' :
F_106 ( V_2 , F_105 ( V_2 , 0 ) , V_2 -> V_138 ) ;
break;
case 'X' :
F_101 ( V_2 , F_105 ( V_2 , 0 ) ) ;
break;
case 'J' :
F_103 ( V_2 , V_2 -> V_158 [ 0 ] ) ;
break;
case 'K' :
F_102 ( V_2 , V_2 -> V_158 [ 0 ] ) ;
break;
case 'P' :
F_100 ( V_2 , F_105 ( V_2 , 0 ) ) ;
break;
case '@' :
F_98 ( V_2 , F_105 ( V_2 , 0 ) ) ;
break;
case 's' :
V_2 -> V_170 = V_2 -> V_139 ;
V_2 -> V_171 = V_2 -> V_138 ;
V_2 -> V_172 = V_2 -> V_141 ;
V_2 -> V_173 = V_2 -> V_142 ;
break;
case 'u' :
F_94 ( V_2 , V_2 -> V_138 ) ;
F_106 ( V_2 , V_2 -> V_170 , V_2 -> V_171 ) ;
V_2 -> V_141 = V_2 -> V_172 ;
V_2 -> V_142 = V_2 -> V_173 ;
break;
}
}
static void
F_110 ( struct V_1 * V_2 , struct V_115 * V_116 ,
const unsigned char * V_176 , int V_7 )
{
int V_177 , V_118 ;
F_37 ( & V_2 -> V_12 . V_59 ) ;
for ( V_177 = 0 ; ! V_116 -> V_178 && V_177 < V_7 ; V_177 ++ ) {
if ( V_2 -> V_169 != 0 ) {
F_108 ( V_2 , V_176 [ V_177 ] ) ;
continue;
}
switch ( V_176 [ V_177 ] ) {
case 0x07 :
V_2 -> V_63 |= V_179 ;
break;
case 0x08 :
if ( V_2 -> V_139 > 0 ) {
V_2 -> V_139 -- ;
F_93 ( V_2 , ' ' ) ;
}
break;
case 0x09 :
for ( V_118 = V_2 -> V_139 % 8 ; V_118 < 8 ; V_118 ++ ) {
if ( V_2 -> V_139 >= V_2 -> V_12 . V_13 ) {
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
break;
}
F_93 ( V_2 , ' ' ) ;
V_2 -> V_139 ++ ;
}
break;
case 0x0a :
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
break;
case 0x0c :
F_103 ( V_2 , 2 ) ;
V_2 -> V_139 = V_2 -> V_138 = 0 ;
break;
case 0x0d :
V_2 -> V_139 = 0 ;
break;
case 0x0f :
break;
case 0x1b :
F_108 ( V_2 , V_176 [ V_177 ] ) ;
break;
default:
if ( V_2 -> V_139 >= V_2 -> V_12 . V_13 ) {
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
}
F_93 ( V_2 , V_176 [ V_177 ] ) ;
V_2 -> V_139 ++ ;
break;
}
}
F_94 ( V_2 , V_2 -> V_138 ) ;
if ( ! F_111 ( & V_2 -> V_4 ) )
F_1 ( V_2 , V_180 / 10 ) ;
F_38 ( & V_2 -> V_12 . V_59 ) ;
}
static int
F_112 ( struct V_115 * V_116 ,
const unsigned char * V_176 , int V_7 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_181 > 0 ) {
F_110 ( V_2 , V_116 , V_2 -> V_182 , V_2 -> V_181 ) ;
V_2 -> V_181 = 0 ;
}
F_110 ( V_2 , V_116 , V_176 , V_7 ) ;
return V_7 ;
}
static int F_113 ( struct V_115 * V_116 , unsigned char V_136 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 || V_2 -> V_181 >= V_183 )
return 0 ;
V_2 -> V_182 [ V_2 -> V_181 ++ ] = V_136 ;
return 1 ;
}
static void
F_114 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return;
if ( V_2 -> V_181 > 0 ) {
F_110 ( V_2 , V_116 , V_2 -> V_182 , V_2 -> V_181 ) ;
V_2 -> V_181 = 0 ;
}
}
static int
F_115 ( struct V_115 * V_116 )
{
return 0 ;
}
static void
F_116 ( struct V_115 * V_116 )
{
}
static void
F_117 ( struct V_115 * V_116 , struct V_184 * V_185 )
{
struct V_1 * V_2 ;
int V_186 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return;
F_37 ( & V_2 -> V_12 . V_59 ) ;
if ( F_118 ( V_116 ) ) {
V_186 = F_119 ( V_116 ) ? V_24 : V_79 ;
if ( V_186 != V_2 -> V_11 ) {
V_2 -> V_11 = V_186 ;
F_4 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
}
}
F_38 ( & V_2 -> V_12 . V_59 ) ;
}
static void
F_120 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return;
V_2 -> V_91 = 1 ;
}
static void
F_121 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return;
V_2 -> V_91 = 0 ;
if ( V_2 -> V_92 )
F_49 ( V_2 , 1 ) ;
}
static void
F_122 ( struct V_115 * V_116 )
{
}
static void
F_123 ( struct V_115 * V_116 , int V_187 )
{
}
static int F_124 ( struct V_115 * V_116 , unsigned int V_88 ,
unsigned long V_188 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return - V_129 ;
if ( V_116 -> V_189 & ( 1 << V_190 ) )
return - V_94 ;
return F_125 ( V_2 -> V_72 , V_88 , V_188 ) ;
}
static long F_126 ( struct V_115 * V_116 ,
unsigned int V_88 , unsigned long V_188 )
{
struct V_1 * V_2 ;
V_2 = V_116 -> V_117 ;
if ( ! V_2 )
return - V_129 ;
if ( V_116 -> V_189 & ( 1 << V_190 ) )
return - V_94 ;
return F_125 ( V_2 -> V_72 , V_88 , ( unsigned long ) F_127 ( V_188 ) ) ;
}
static int T_2 F_128 ( void )
{
struct V_191 * V_192 ;
int V_193 ;
V_192 = F_129 ( V_194 ) ;
if ( ! V_192 )
return - V_109 ;
V_192 -> V_195 = L_6 ;
V_192 -> V_196 = L_6 ;
V_192 -> V_197 = V_198 ;
V_192 -> V_199 = V_121 ;
V_192 -> type = V_200 ;
V_192 -> V_201 = V_202 ;
V_192 -> V_203 = V_204 ;
V_192 -> V_189 = V_205 | V_206 ;
F_130 ( V_192 , & V_207 ) ;
V_193 = F_131 ( V_192 ) ;
if ( V_193 ) {
F_132 ( V_192 ) ;
return V_193 ;
}
V_208 = V_192 ;
return 0 ;
}
static void T_3
F_133 ( void )
{
struct V_191 * V_192 ;
V_192 = V_208 ;
V_208 = NULL ;
F_134 ( V_192 ) ;
F_82 () ;
}
