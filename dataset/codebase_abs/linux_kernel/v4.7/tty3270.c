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
F_23 ( struct V_1 * V_2 )
{
struct string * V_39 , * V_40 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_12 . V_16 - 2 ; V_49 ++ )
V_2 -> V_50 [ V_49 ] . V_18 = 0 ;
V_2 -> V_28 = 0 ;
F_12 (s, n, &tp->lines, list) {
F_18 ( & V_39 -> V_45 ) ;
if ( ! F_19 ( & V_39 -> V_41 ) )
F_18 ( & V_39 -> V_41 ) ;
V_2 -> V_44 -- ;
F_20 ( & V_2 -> V_26 , V_39 ) ;
}
}
static void
F_24 ( struct V_51 * V_52 , void * V_53 )
{
struct V_1 * V_2 = F_25 ( V_52 -> V_12 , struct V_1 , V_12 ) ;
if ( V_52 -> V_54 != 0 ) {
V_2 -> V_19 = V_55 ;
F_1 ( V_2 , 1 ) ;
}
F_26 ( V_52 ) ;
F_27 ( & V_2 -> V_56 , V_52 ) ;
}
static void
F_28 ( struct V_1 * V_2 )
{
static char V_57 [ 2 ] = { 0xff , 0xff } ;
struct V_51 * V_58 ;
unsigned long V_59 ;
struct string * V_39 , * V_40 ;
char * V_60 , * V_27 ;
int V_54 , V_18 ;
V_58 = F_27 ( & V_2 -> V_56 , 0 ) ;
if ( ! V_58 ) {
F_1 ( V_2 , 1 ) ;
return;
}
F_29 ( & V_2 -> V_12 . V_61 ) ;
V_59 = 0 ;
if ( V_2 -> V_19 & V_55 ) {
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_19 = V_62 | V_42 |
V_20 | V_31 ;
}
if ( V_2 -> V_19 & V_62 ) {
F_30 ( V_58 , V_63 ) ;
V_59 |= V_62 ;
} else
F_30 ( V_58 , V_64 ) ;
F_31 ( V_58 , & V_2 -> V_65 , 1 ) ;
V_2 -> V_65 = V_66 ;
if ( V_2 -> V_19 & V_31 )
if ( F_31 ( V_58 , V_2 -> V_29 -> string ,
V_2 -> V_29 -> V_18 ) == 0 )
V_59 |= V_31 ;
if ( V_2 -> V_19 & V_20 )
if ( F_31 ( V_58 , V_2 -> V_9 -> string ,
V_2 -> V_9 -> V_18 ) == 0 )
V_59 |= V_20 ;
V_60 = V_57 ;
if ( V_2 -> V_19 & V_42 ) {
F_12 (s, n, &tp->update, update) {
V_27 = V_39 -> string ;
V_18 = V_39 -> V_18 ;
if ( V_39 -> string [ 1 ] == V_60 [ 0 ] && V_39 -> string [ 2 ] == V_60 [ 1 ] )
V_27 += 3 , V_18 -= 3 ;
if ( F_31 ( V_58 , V_27 , V_18 ) != 0 )
break;
F_13 ( & V_39 -> V_41 ) ;
if ( V_39 -> string [ V_39 -> V_18 - 4 ] == V_15 )
V_60 = V_39 -> string + V_39 -> V_18 - 3 ;
else
V_60 = V_57 ;
}
if ( F_19 ( & V_2 -> V_41 ) )
V_59 |= V_42 ;
}
V_58 -> V_67 = F_24 ;
V_54 = F_32 ( & V_2 -> V_12 , V_58 ) ;
if ( V_54 == 0 ) {
V_2 -> V_19 &= ~ V_59 ;
if ( V_2 -> V_19 )
F_1 ( V_2 , 1 ) ;
} else {
F_26 ( V_58 ) ;
F_27 ( & V_2 -> V_56 , V_58 ) ;
}
F_33 ( & V_2 -> V_12 . V_61 ) ;
}
static void
F_34 ( struct V_1 * V_2 , char * V_6 , int V_18 )
{
struct string * V_39 ;
V_2 -> V_68 = NULL ;
if ( V_18 <= 0 )
return;
if ( V_2 -> V_69 >= V_2 -> V_70 ) {
V_39 = F_35 ( V_2 -> V_71 . V_72 , struct string , V_45 ) ;
F_18 ( & V_39 -> V_45 ) ;
F_20 ( & V_2 -> V_26 , V_39 ) ;
V_2 -> V_69 -- ;
}
V_39 = F_16 ( V_2 , V_18 ) ;
memcpy ( V_39 -> string , V_6 , V_18 ) ;
F_22 ( & V_39 -> V_45 , & V_2 -> V_71 ) ;
V_2 -> V_69 ++ ;
}
static void
F_36 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_25 ( V_74 -> V_75 , struct V_1 , V_75 ) ;
struct string * V_39 ;
F_37 ( & V_2 -> V_12 . V_61 ) ;
if ( V_2 -> V_11 == V_24 ) {
if ( V_2 -> V_68 && V_2 -> V_68 -> V_76 != & V_2 -> V_71 )
V_2 -> V_68 = V_2 -> V_68 -> V_76 ;
else if ( ! F_19 ( & V_2 -> V_71 ) )
V_2 -> V_68 = V_2 -> V_71 . V_76 ;
V_39 = V_2 -> V_68 ?
F_35 ( V_2 -> V_68 , struct string , V_45 ) : NULL ;
if ( V_2 -> V_68 ) {
V_39 = F_35 ( V_2 -> V_68 , struct string , V_45 ) ;
F_3 ( V_2 , V_39 -> string , V_39 -> V_18 ) ;
} else
F_3 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_61 ) ;
}
static void
F_39 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_25 ( V_74 -> V_75 , struct V_1 , V_75 ) ;
F_40 ( & V_2 -> V_12 ) ;
}
static void
F_41 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_25 ( V_74 -> V_75 , struct V_1 , V_75 ) ;
int V_28 ;
F_37 ( & V_2 -> V_12 . V_61 ) ;
V_28 = V_2 -> V_28 - V_2 -> V_12 . V_16 + 2 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_61 ) ;
}
static void
F_42 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_25 ( V_74 -> V_75 , struct V_1 , V_75 ) ;
int V_28 ;
F_37 ( & V_2 -> V_12 . V_61 ) ;
V_28 = V_2 -> V_28 + V_2 -> V_12 . V_16 - 2 ;
if ( V_28 + V_2 -> V_12 . V_16 - 2 > V_2 -> V_44 )
V_28 = V_2 -> V_44 - V_2 -> V_12 . V_16 + 2 ;
if ( V_28 != V_2 -> V_28 ) {
V_2 -> V_28 = V_28 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_61 ) ;
}
static void
F_43 ( struct V_51 * V_77 )
{
static char V_78 = V_79 ;
struct V_1 * V_2 = F_25 ( V_77 -> V_12 , struct V_1 , V_12 ) ;
char * V_6 ;
int V_18 ;
F_37 ( & V_2 -> V_12 . V_61 ) ;
V_6 = NULL ;
V_18 = 0 ;
if ( V_2 -> V_6 -> string [ 0 ] == 0x7d ) {
V_6 = V_2 -> V_6 -> string + 6 ;
V_18 = V_2 -> V_6 -> V_18 - 6 - V_77 -> V_80 ;
if ( V_2 -> V_11 != V_81 )
F_34 ( V_2 , V_6 , V_18 ) ;
if ( V_2 -> V_28 > 0 ) {
V_2 -> V_28 = 0 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
}
F_3 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
} else if ( V_2 -> V_6 -> string [ 0 ] == 0x6d ) {
V_2 -> V_19 = V_55 ;
F_1 ( V_2 , 1 ) ;
}
F_38 ( & V_2 -> V_12 . V_61 ) ;
F_26 ( V_2 -> V_82 ) ;
F_30 ( V_2 -> V_82 , V_64 ) ;
F_31 ( V_2 -> V_82 , & V_78 , 1 ) ;
F_32 ( & V_2 -> V_12 , V_2 -> V_82 ) ;
while ( V_18 -- > 0 )
F_44 ( V_2 -> V_74 , * V_6 ++ ) ;
F_44 ( V_2 -> V_74 , 256 + V_2 -> V_6 -> string [ 0 ] ) ;
F_26 ( V_77 ) ;
F_27 ( & V_2 -> V_83 , V_77 ) ;
F_45 ( & V_2 -> V_12 ) ;
}
static void
F_46 ( struct V_51 * V_52 , void * V_53 )
{
struct V_1 * V_2 = F_25 ( V_52 -> V_12 , struct V_1 , V_12 ) ;
F_47 ( V_52 -> V_12 ) ;
F_48 ( & V_2 -> V_84 ) ;
}
static void
F_49 ( struct V_1 * V_2 , int V_61 )
{
struct V_51 * V_77 ;
int V_54 ;
V_77 = F_27 ( & V_2 -> V_83 , 0 ) ;
if ( ! V_77 )
return;
V_77 -> V_67 = F_46 ;
V_77 -> V_85 = V_2 ;
F_30 ( V_77 , V_86 ) ;
F_50 ( V_77 , V_2 -> V_6 -> string , V_2 -> V_6 -> V_18 ) ;
if ( V_61 ) {
V_54 = F_32 ( & V_2 -> V_12 , V_77 ) ;
} else
V_54 = F_51 ( & V_2 -> V_12 , V_77 ) ;
if ( V_54 ) {
F_26 ( V_77 ) ;
F_27 ( & V_2 -> V_83 , V_77 ) ;
}
}
static void
F_52 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_75 , true ) ;
F_45 ( & V_2 -> V_12 ) ;
}
static int
F_54 ( struct V_87 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
V_2 -> V_19 = V_55 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static void
F_55 ( struct V_87 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
F_56 ( & V_2 -> V_4 ) ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_51 * V_52 , struct V_88 * V_88 )
{
if ( V_88 -> V_89 . V_90 . V_91 & V_92 ) {
if ( ! V_2 -> V_93 )
F_49 ( V_2 , 0 ) ;
else
V_2 -> V_94 = 1 ;
}
if ( V_52 ) {
if ( V_88 -> V_89 . V_90 . V_91 & V_95 ) {
V_52 -> V_54 = - V_96 ;
F_47 ( & V_2 -> V_12 ) ;
F_48 ( & V_2 -> V_97 ) ;
} else {
V_52 -> V_80 = V_88 -> V_89 . V_90 . V_7 ;
}
} else if ( V_88 -> V_89 . V_90 . V_91 & V_98 ) {
V_2 -> V_19 = V_55 ;
F_1 ( V_2 , 1 ) ;
}
}
static struct V_1 *
F_58 ( void )
{
struct V_1 * V_2 ;
int V_99 ;
V_2 = F_59 ( sizeof( struct V_1 ) , V_100 ) ;
if ( ! V_2 )
goto V_101;
V_2 -> V_102 =
F_60 ( sizeof( void * ) * V_103 , V_100 ) ;
if ( ! V_2 -> V_102 )
goto V_104;
F_61 ( & V_2 -> V_26 ) ;
F_61 ( & V_2 -> V_48 ) ;
F_61 ( & V_2 -> V_41 ) ;
F_61 ( & V_2 -> V_71 ) ;
V_2 -> V_70 = 20 ;
for ( V_99 = 0 ; V_99 < V_103 ; V_99 ++ ) {
V_2 -> V_102 [ V_99 ] = ( void * )
F_62 ( V_100 | V_105 , 0 ) ;
if ( ! V_2 -> V_102 [ V_99 ] )
goto V_106;
F_63 ( & V_2 -> V_26 ,
V_2 -> V_102 [ V_99 ] , V_107 ) ;
}
V_2 -> V_56 = F_64 ( V_108 ) ;
if ( F_65 ( V_2 -> V_56 ) )
goto V_106;
V_2 -> V_83 = F_64 ( 0 ) ;
if ( F_65 ( V_2 -> V_83 ) )
goto V_109;
V_2 -> V_82 = F_64 ( 1 ) ;
if ( F_65 ( V_2 -> V_82 ) )
goto V_110;
V_2 -> V_74 = F_66 () ;
if ( ! V_2 -> V_74 )
goto V_111;
F_67 ( & V_2 -> V_75 ) ;
F_68 ( & V_2 -> V_4 , ( void (*) ( unsigned long ) ) F_28 ,
( unsigned long ) V_2 ) ;
F_69 ( & V_2 -> V_84 ,
( void (*) ( unsigned long ) ) F_43 ,
( unsigned long ) V_2 -> V_83 ) ;
F_69 ( & V_2 -> V_97 ,
( void (*) ( unsigned long ) ) F_52 ,
( unsigned long ) V_2 ) ;
F_70 ( & V_2 -> V_112 , V_113 ) ;
return V_2 ;
V_111:
F_71 ( V_2 -> V_82 ) ;
V_110:
F_71 ( V_2 -> V_83 ) ;
V_109:
F_71 ( V_2 -> V_56 ) ;
V_106:
while ( V_99 -- )
F_72 ( ( unsigned long ) V_2 -> V_102 [ V_99 ] , 0 ) ;
F_73 ( V_2 -> V_102 ) ;
F_74 ( & V_2 -> V_75 ) ;
V_104:
F_73 ( V_2 ) ;
V_101:
return F_75 ( - V_114 ) ;
}
static void
F_76 ( struct V_1 * V_2 )
{
int V_99 ;
F_77 ( V_2 -> V_74 ) ;
F_71 ( V_2 -> V_82 ) ;
F_71 ( V_2 -> V_83 ) ;
F_71 ( V_2 -> V_56 ) ;
for ( V_99 = 0 ; V_99 < V_103 ; V_99 ++ )
F_72 ( ( unsigned long ) V_2 -> V_102 [ V_99 ] , 0 ) ;
F_73 ( V_2 -> V_102 ) ;
F_74 ( & V_2 -> V_75 ) ;
F_73 ( V_2 ) ;
}
static struct V_115 *
F_78 ( unsigned int V_16 , unsigned int V_13 )
{
struct V_115 * V_50 ;
unsigned long V_43 ;
int V_48 ;
V_43 = sizeof( struct V_115 ) * ( V_16 - 2 ) ;
V_50 = F_59 ( V_43 , V_100 ) ;
if ( ! V_50 )
goto V_101;
for ( V_48 = 0 ; V_48 < V_16 - 2 ; V_48 ++ ) {
V_43 = sizeof( struct V_116 ) * V_13 ;
V_50 [ V_48 ] . V_117 = F_59 ( V_43 , V_100 ) ;
if ( ! V_50 [ V_48 ] . V_117 )
goto V_118;
}
return V_50 ;
V_118:
while ( V_48 -- )
F_73 ( V_50 [ V_48 ] . V_117 ) ;
F_73 ( V_50 ) ;
V_101:
return F_75 ( - V_114 ) ;
}
static void
F_79 ( struct V_115 * V_50 , unsigned int V_16 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_16 - 2 ; V_48 ++ )
F_73 ( V_50 [ V_48 ] . V_117 ) ;
F_73 ( V_50 ) ;
}
static void V_113 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_25 ( V_120 , struct V_1 , V_112 ) ;
struct V_115 * V_50 , * V_121 ;
struct V_122 * V_123 ;
unsigned int V_124 ;
struct V_125 V_126 ;
V_50 = F_78 ( V_2 -> V_127 , V_2 -> V_128 ) ;
if ( F_65 ( V_50 ) )
return;
F_37 ( & V_2 -> V_12 . V_61 ) ;
F_23 ( V_2 ) ;
V_121 = V_2 -> V_50 ;
V_124 = V_2 -> V_12 . V_16 ;
V_2 -> V_12 . V_129 = V_2 -> V_130 ;
V_2 -> V_12 . V_16 = V_2 -> V_127 ;
V_2 -> V_12 . V_13 = V_2 -> V_128 ;
V_2 -> V_50 = V_50 ;
F_20 ( & V_2 -> V_26 , V_2 -> V_9 ) ;
F_20 ( & V_2 -> V_26 , V_2 -> V_29 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 ) ;
while ( V_2 -> V_44 < V_2 -> V_12 . V_16 - 2 )
F_21 ( V_2 ) ;
V_2 -> V_19 = V_55 ;
F_38 ( & V_2 -> V_12 . V_61 ) ;
F_79 ( V_121 , V_124 ) ;
F_1 ( V_2 , 1 ) ;
V_123 = F_80 ( & V_2 -> V_75 ) ;
if ( ! V_123 )
return;
V_126 . V_131 = V_2 -> V_12 . V_16 - 2 ;
V_126 . V_132 = V_2 -> V_12 . V_13 ;
F_81 ( V_123 , & V_126 ) ;
F_82 ( V_123 ) ;
}
static void
F_83 ( struct V_87 * V_12 , int V_129 , int V_16 , int V_13 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
if ( V_2 -> V_130 == V_129 && V_2 -> V_127 == V_16 && V_2 -> V_128 == V_13 )
return;
V_2 -> V_130 = V_129 ;
V_2 -> V_127 = V_16 ;
V_2 -> V_128 = V_13 ;
F_84 ( & V_2 -> V_112 ) ;
}
static void
F_85 ( struct V_87 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
struct V_122 * V_123 = F_80 ( & V_2 -> V_75 ) ;
if ( V_123 ) {
V_123 -> V_133 = NULL ;
F_86 ( & V_2 -> V_75 , NULL ) ;
F_87 ( V_123 ) ;
F_45 ( & V_2 -> V_12 ) ;
F_82 ( V_123 ) ;
}
}
static void
F_88 ( struct V_87 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
F_89 ( & V_2 -> V_4 ) ;
F_79 ( V_2 -> V_50 , V_2 -> V_12 . V_16 ) ;
F_76 ( V_2 ) ;
}
static void
F_90 ( void )
{
int V_49 ;
for ( V_49 = V_134 ; V_49 <= V_135 ; V_49 ++ ) {
struct V_87 * V_12 = F_91 ( & V_136 , V_49 ) ;
if ( ! F_65 ( V_12 ) )
F_92 ( V_12 ) ;
}
}
static int F_93 ( struct V_137 * V_138 , struct V_122 * V_123 )
{
struct V_87 * V_12 ;
struct V_1 * V_2 ;
int V_49 , V_54 ;
V_12 = F_91 ( & V_136 , V_123 -> V_139 + V_134 ) ;
if ( ! F_65 ( V_12 ) ) {
V_2 = F_25 ( V_12 , struct V_1 , V_12 ) ;
V_123 -> V_133 = V_2 ;
V_123 -> V_125 . V_131 = V_2 -> V_12 . V_16 - 2 ;
V_123 -> V_125 . V_132 = V_2 -> V_12 . V_13 ;
V_2 -> V_75 . V_140 = 0 ;
V_2 -> V_11 = V_24 ;
goto V_141;
}
if ( V_135 < V_123 -> V_139 + 1 )
V_135 = V_123 -> V_139 + 1 ;
V_2 = F_58 () ;
if ( F_65 ( V_2 ) )
return F_94 ( V_2 ) ;
V_54 = F_95 ( & V_2 -> V_12 , & V_136 ,
V_123 -> V_139 + V_134 ) ;
if ( V_54 ) {
F_76 ( V_2 ) ;
return V_54 ;
}
V_2 -> V_50 = F_78 ( V_2 -> V_12 . V_16 , V_2 -> V_12 . V_13 ) ;
if ( F_65 ( V_2 -> V_50 ) ) {
V_54 = F_94 ( V_2 -> V_50 ) ;
F_45 ( & V_2 -> V_12 ) ;
F_92 ( & V_2 -> V_12 ) ;
F_76 ( V_2 ) ;
return V_54 ;
}
V_2 -> V_75 . V_140 = 0 ;
V_123 -> V_125 . V_131 = V_2 -> V_12 . V_16 - 2 ;
V_123 -> V_125 . V_132 = V_2 -> V_12 . V_13 ;
F_5 ( V_2 ) ;
F_9 ( V_2 ) ;
F_7 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_12 . V_16 - 2 ; V_49 ++ )
F_21 ( V_2 ) ;
V_2 -> V_74 -> V_75 = & V_2 -> V_75 ;
V_2 -> V_74 -> V_142 [ F_96 ( V_143 ) ] = F_39 ;
V_2 -> V_74 -> V_142 [ F_96 ( V_144 ) ] = F_42 ;
V_2 -> V_74 -> V_142 [ F_96 ( V_145 ) ] = F_41 ;
V_2 -> V_74 -> V_142 [ F_96 ( V_146 ) ] = F_36 ;
F_97 ( V_2 -> V_74 , V_2 -> V_12 . V_30 ) ;
F_98 ( & V_2 -> V_12 ) ;
V_141:
V_54 = F_99 ( & V_2 -> V_75 , V_138 , V_123 ) ;
if ( V_54 ) {
F_45 ( & V_2 -> V_12 ) ;
return V_54 ;
}
V_123 -> V_133 = V_2 ;
return 0 ;
}
static int
F_100 ( struct V_122 * V_123 , struct V_147 * V_148 )
{
struct V_1 * V_2 = V_123 -> V_133 ;
struct V_149 * V_75 = & V_2 -> V_75 ;
V_75 -> V_7 ++ ;
F_86 ( V_75 , V_123 ) ;
return 0 ;
}
static void
F_101 ( struct V_122 * V_123 , struct V_147 * V_148 )
{
struct V_1 * V_2 = V_123 -> V_133 ;
if ( V_123 -> V_7 > 1 )
return;
if ( V_2 )
F_86 ( & V_2 -> V_75 , NULL ) ;
}
static void F_102 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = V_123 -> V_133 ;
if ( V_2 ) {
V_123 -> V_133 = NULL ;
F_45 ( & V_2 -> V_12 ) ;
}
}
static int
F_103 ( struct V_122 * V_123 )
{
return V_150 ;
}
static void F_104 ( struct V_1 * V_2 , char V_151 )
{
struct V_115 * line ;
struct V_116 * V_152 ;
line = V_2 -> V_50 + V_2 -> V_153 ;
if ( line -> V_18 <= V_2 -> V_154 ) {
while ( line -> V_18 < V_2 -> V_154 ) {
V_152 = line -> V_117 + line -> V_18 ;
V_152 -> V_155 = V_2 -> V_12 . V_30 [ ' ' ] ;
V_152 -> V_156 = V_2 -> V_156 ;
V_152 -> V_157 = V_2 -> V_157 ;
line -> V_18 ++ ;
}
line -> V_18 ++ ;
}
V_152 = line -> V_117 + V_2 -> V_154 ;
V_152 -> V_155 = V_2 -> V_12 . V_30 [ ( unsigned int ) V_151 ] ;
V_152 -> V_156 = V_2 -> V_156 ;
V_152 -> V_157 = V_2 -> V_157 ;
}
static void
F_105 ( struct V_1 * V_2 , int V_158 )
{
struct V_115 * line ;
struct V_116 * V_152 ;
struct string * V_39 , * V_40 ;
unsigned char V_156 ;
unsigned char V_157 ;
char * V_38 ;
int V_159 , V_49 ;
V_159 = 3 ;
line = V_2 -> V_50 + V_158 ;
V_159 += line -> V_18 ;
V_156 = V_47 ;
V_157 = V_36 ;
for ( V_49 = 0 , V_152 = line -> V_117 ; V_49 < line -> V_18 ; V_49 ++ , V_152 ++ ) {
if ( V_152 -> V_156 != V_156 ) {
V_159 += 3 ;
V_156 = V_152 -> V_156 ;
}
if ( V_152 -> V_157 != V_157 ) {
V_159 += 3 ;
V_157 = V_152 -> V_157 ;
}
}
if ( V_156 != V_47 )
V_159 += 3 ;
if ( V_157 != V_36 )
V_159 += 3 ;
if ( line -> V_18 < V_2 -> V_12 . V_13 )
V_159 += 4 ;
V_49 = V_2 -> V_12 . V_16 - 2 - V_158 ;
F_14 (s, &tp->lines, list)
if ( -- V_49 <= 0 )
break;
if ( V_39 -> V_18 != V_159 ) {
V_40 = F_16 ( V_2 , V_159 ) ;
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
V_156 = V_47 ;
V_157 = V_36 ;
for ( V_49 = 0 , V_152 = line -> V_117 ; V_49 < line -> V_18 ; V_49 ++ , V_152 ++ ) {
if ( V_152 -> V_156 != V_156 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_46 ;
* V_38 ++ = V_152 -> V_156 ;
V_156 = V_152 -> V_156 ;
}
if ( V_152 -> V_157 != V_157 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_34 ;
* V_38 ++ = V_152 -> V_157 ;
V_157 = V_152 -> V_157 ;
}
* V_38 ++ = V_152 -> V_155 ;
}
if ( V_156 != V_47 ) {
* V_38 ++ = V_33 ;
* V_38 ++ = V_46 ;
* V_38 ++ = V_47 ;
}
if ( V_157 != V_36 ) {
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
if ( V_2 -> V_28 + V_158 < V_2 -> V_12 . V_16 - 2 ) {
F_10 ( V_2 , V_39 , V_158 ) ;
if ( F_19 ( & V_39 -> V_41 ) ) {
F_22 ( & V_39 -> V_41 , & V_2 -> V_41 ) ;
V_2 -> V_19 |= V_42 ;
}
}
}
static void
F_106 ( struct V_1 * V_2 )
{
V_2 -> V_154 = 0 ;
}
static void
F_107 ( struct V_1 * V_2 )
{
struct V_115 V_160 ;
int V_49 ;
F_105 ( V_2 , V_2 -> V_153 ) ;
if ( V_2 -> V_153 < V_2 -> V_12 . V_16 - 3 ) {
V_2 -> V_153 ++ ;
return;
}
F_21 ( V_2 ) ;
V_160 = V_2 -> V_50 [ 0 ] ;
V_160 . V_18 = 0 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_12 . V_16 - 3 ; V_49 ++ )
V_2 -> V_50 [ V_49 ] = V_2 -> V_50 [ V_49 + 1 ] ;
V_2 -> V_50 [ V_2 -> V_12 . V_16 - 3 ] = V_160 ;
F_11 ( V_2 ) ;
}
static void
F_108 ( struct V_1 * V_2 )
{
if ( V_2 -> V_153 > 0 ) {
F_105 ( V_2 , V_2 -> V_153 ) ;
V_2 -> V_153 -- ;
}
}
static void
F_109 ( struct V_1 * V_2 , int V_40 )
{
struct V_115 * line ;
int V_161 ;
line = V_2 -> V_50 + V_2 -> V_153 ;
while ( line -> V_18 < V_2 -> V_154 ) {
line -> V_117 [ line -> V_18 ] . V_155 = V_2 -> V_12 . V_30 [ ' ' ] ;
line -> V_117 [ line -> V_18 ] . V_156 = V_47 ;
line -> V_117 [ line -> V_18 ] . V_157 = V_36 ;
line -> V_18 ++ ;
}
if ( V_40 > V_2 -> V_12 . V_13 - V_2 -> V_154 )
V_40 = V_2 -> V_12 . V_13 - V_2 -> V_154 ;
V_161 = F_110 ( int , line -> V_18 - V_2 -> V_154 , V_2 -> V_12 . V_13 - V_2 -> V_154 - V_40 ) ;
while ( V_161 -- )
line -> V_117 [ V_2 -> V_154 + V_40 + V_161 ] = line -> V_117 [ V_2 -> V_154 + V_161 ] ;
line -> V_18 += V_40 ;
if ( line -> V_18 > V_2 -> V_12 . V_13 )
line -> V_18 = V_2 -> V_12 . V_13 ;
while ( V_40 -- > 0 ) {
line -> V_117 [ V_2 -> V_154 + V_40 ] . V_155 = V_2 -> V_12 . V_30 [ ' ' ] ;
line -> V_117 [ V_2 -> V_154 + V_40 ] . V_156 = V_2 -> V_156 ;
line -> V_117 [ V_2 -> V_154 + V_40 ] . V_157 = V_2 -> V_157 ;
}
}
static void
F_111 ( struct V_1 * V_2 , int V_40 )
{
struct V_115 * line ;
int V_49 ;
line = V_2 -> V_50 + V_2 -> V_153 ;
if ( line -> V_18 <= V_2 -> V_154 )
return;
if ( line -> V_18 - V_2 -> V_154 <= V_40 ) {
line -> V_18 = V_2 -> V_154 ;
return;
}
for ( V_49 = V_2 -> V_154 ; V_49 + V_40 < line -> V_18 ; V_49 ++ )
line -> V_117 [ V_49 ] = line -> V_117 [ V_49 + V_40 ] ;
line -> V_18 -= V_40 ;
}
static void
F_112 ( struct V_1 * V_2 , int V_40 )
{
struct V_115 * line ;
struct V_116 * V_152 ;
line = V_2 -> V_50 + V_2 -> V_153 ;
while ( line -> V_18 > V_2 -> V_154 && V_40 -- > 0 ) {
V_152 = line -> V_117 + V_2 -> V_154 ++ ;
V_152 -> V_155 = ' ' ;
V_152 -> V_156 = V_47 ;
V_152 -> V_157 = V_36 ;
}
V_2 -> V_154 += V_40 ;
V_2 -> V_154 = F_110 ( int , V_2 -> V_154 , V_2 -> V_12 . V_13 - 1 ) ;
}
static void
F_113 ( struct V_1 * V_2 , int V_162 )
{
struct V_115 * line ;
struct V_116 * V_152 ;
int V_49 ;
line = V_2 -> V_50 + V_2 -> V_153 ;
if ( V_162 == 0 )
line -> V_18 = V_2 -> V_154 ;
else if ( V_162 == 1 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_154 ; V_49 ++ ) {
V_152 = line -> V_117 + V_49 ;
V_152 -> V_155 = ' ' ;
V_152 -> V_156 = V_47 ;
V_152 -> V_157 = V_36 ;
}
if ( line -> V_18 <= V_2 -> V_154 )
line -> V_18 = V_2 -> V_154 + 1 ;
} else if ( V_162 == 2 )
line -> V_18 = 0 ;
F_105 ( V_2 , V_2 -> V_153 ) ;
}
static void
F_114 ( struct V_1 * V_2 , int V_162 )
{
int V_49 ;
if ( V_162 == 0 ) {
F_113 ( V_2 , 0 ) ;
for ( V_49 = V_2 -> V_153 + 1 ; V_49 < V_2 -> V_12 . V_16 - 2 ; V_49 ++ ) {
V_2 -> V_50 [ V_49 ] . V_18 = 0 ;
F_105 ( V_2 , V_49 ) ;
}
} else if ( V_162 == 1 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_153 ; V_49 ++ ) {
V_2 -> V_50 [ V_49 ] . V_18 = 0 ;
F_105 ( V_2 , V_49 ) ;
}
F_113 ( V_2 , 1 ) ;
} else if ( V_162 == 2 ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_12 . V_16 - 2 ; V_49 ++ ) {
V_2 -> V_50 [ V_49 ] . V_18 = 0 ;
F_105 ( V_2 , V_49 ) ;
}
}
F_11 ( V_2 ) ;
}
static void
F_115 ( struct V_1 * V_2 )
{
static unsigned char V_163 [] = {
V_164 , V_165 , V_35 , V_166 , V_167 ,
V_168 , V_169 , V_170 , 0 , V_164
} ;
int V_49 , V_171 ;
for ( V_49 = 0 ; V_49 <= V_2 -> V_172 ; V_49 ++ ) {
V_171 = V_2 -> V_173 [ V_49 ] ;
switch ( V_171 ) {
case 0 :
V_2 -> V_156 = V_47 ;
V_2 -> V_157 = V_36 ;
break;
case 4 :
V_2 -> V_156 = V_174 ;
break;
case 5 :
V_2 -> V_156 = V_175 ;
break;
case 7 :
V_2 -> V_156 = V_176 ;
break;
case 24 :
if ( V_2 -> V_156 == V_174 )
V_2 -> V_156 = V_47 ;
break;
case 25 :
if ( V_2 -> V_156 == V_175 )
V_2 -> V_156 = V_47 ;
break;
case 27 :
if ( V_2 -> V_156 == V_176 )
V_2 -> V_156 = V_47 ;
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
V_2 -> V_157 = V_163 [ V_171 - 30 ] ;
break;
}
}
}
static inline int
F_116 ( struct V_1 * V_2 , int V_177 )
{
return ( V_2 -> V_173 [ V_177 ] > 0 ) ? V_2 -> V_173 [ V_177 ] : 1 ;
}
static void
F_117 ( struct V_1 * V_2 , int V_154 , int V_153 )
{
int V_178 = F_118 ( 0 , V_154 ) ;
int V_179 = F_118 ( 0 , V_153 ) ;
V_2 -> V_154 = F_110 ( int , V_2 -> V_12 . V_13 - 1 , V_178 ) ;
V_153 = F_110 ( int , V_2 -> V_12 . V_16 - 3 , V_179 ) ;
if ( V_153 != V_2 -> V_153 ) {
F_105 ( V_2 , V_2 -> V_153 ) ;
V_2 -> V_153 = V_153 ;
}
}
static void
F_119 ( struct V_1 * V_2 , char V_151 )
{
enum { V_180 , V_181 , V_182 , V_183 };
if ( V_2 -> V_184 == V_180 ) {
if ( V_151 == 0x1b )
V_2 -> V_184 = V_181 ;
return;
}
if ( V_2 -> V_184 == V_181 ) {
V_2 -> V_184 = V_180 ;
switch ( V_151 ) {
case '[' :
V_2 -> V_184 = V_182 ;
break;
case 'E' :
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
break;
case 'M' :
F_108 ( V_2 ) ;
break;
case 'D' :
F_107 ( V_2 ) ;
break;
case 'Z' :
F_120 ( & V_2 -> V_75 , L_3 ) ;
break;
case '7' :
V_2 -> V_185 = V_2 -> V_154 ;
V_2 -> V_186 = V_2 -> V_153 ;
V_2 -> V_187 = V_2 -> V_156 ;
V_2 -> V_188 = V_2 -> V_157 ;
break;
case '8' :
F_105 ( V_2 , V_2 -> V_153 ) ;
F_117 ( V_2 , V_2 -> V_185 , V_2 -> V_186 ) ;
V_2 -> V_156 = V_2 -> V_187 ;
V_2 -> V_157 = V_2 -> V_188 ;
break;
case 'c' :
V_2 -> V_154 = V_2 -> V_185 = 0 ;
V_2 -> V_153 = V_2 -> V_186 = 0 ;
V_2 -> V_156 = V_2 -> V_187 = V_47 ;
V_2 -> V_157 = V_2 -> V_188 = V_36 ;
F_114 ( V_2 , 2 ) ;
break;
}
return;
}
if ( V_2 -> V_184 == V_182 ) {
V_2 -> V_184 = V_183 ;
memset ( V_2 -> V_173 , 0 , sizeof( V_2 -> V_173 ) ) ;
V_2 -> V_172 = 0 ;
V_2 -> V_189 = ( V_151 == '?' ) ;
if ( V_2 -> V_189 )
return;
}
if ( V_2 -> V_184 == V_183 ) {
if ( V_151 == ';' && V_2 -> V_172 < V_190 - 1 ) {
V_2 -> V_172 ++ ;
return;
}
if ( V_151 >= '0' && V_151 <= '9' ) {
V_2 -> V_173 [ V_2 -> V_172 ] *= 10 ;
V_2 -> V_173 [ V_2 -> V_172 ] += V_151 - '0' ;
return;
}
}
V_2 -> V_184 = V_180 ;
if ( V_151 == 'n' && ! V_2 -> V_189 ) {
if ( V_2 -> V_173 [ 0 ] == 5 )
F_120 ( & V_2 -> V_75 , L_4 ) ;
else if ( V_2 -> V_173 [ 0 ] == 6 ) {
char V_191 [ 40 ] ;
sprintf ( V_191 , L_5 , V_2 -> V_153 + 1 , V_2 -> V_154 + 1 ) ;
F_120 ( & V_2 -> V_75 , V_191 ) ;
}
return;
}
if ( V_2 -> V_189 )
return;
switch ( V_151 ) {
case 'm' :
F_115 ( V_2 ) ;
break;
case 'H' :
case 'f' :
F_117 ( V_2 , F_116 ( V_2 , 1 ) - 1 ,
F_116 ( V_2 , 0 ) - 1 ) ;
break;
case 'd' :
F_117 ( V_2 , V_2 -> V_154 , F_116 ( V_2 , 0 ) - 1 ) ;
break;
case 'A' :
case 'F' :
F_117 ( V_2 , V_2 -> V_154 , V_2 -> V_153 - F_116 ( V_2 , 0 ) ) ;
break;
case 'B' :
case 'e' :
case 'E' :
F_117 ( V_2 , V_2 -> V_154 , V_2 -> V_153 + F_116 ( V_2 , 0 ) ) ;
break;
case 'C' :
case 'a' :
F_117 ( V_2 , V_2 -> V_154 + F_116 ( V_2 , 0 ) , V_2 -> V_153 ) ;
break;
case 'D' :
F_117 ( V_2 , V_2 -> V_154 - F_116 ( V_2 , 0 ) , V_2 -> V_153 ) ;
break;
case 'G' :
case '`' :
F_117 ( V_2 , F_116 ( V_2 , 0 ) , V_2 -> V_153 ) ;
break;
case 'X' :
F_112 ( V_2 , F_116 ( V_2 , 0 ) ) ;
break;
case 'J' :
F_114 ( V_2 , V_2 -> V_173 [ 0 ] ) ;
break;
case 'K' :
F_113 ( V_2 , V_2 -> V_173 [ 0 ] ) ;
break;
case 'P' :
F_111 ( V_2 , F_116 ( V_2 , 0 ) ) ;
break;
case '@' :
F_109 ( V_2 , F_116 ( V_2 , 0 ) ) ;
break;
case 's' :
V_2 -> V_185 = V_2 -> V_154 ;
V_2 -> V_186 = V_2 -> V_153 ;
V_2 -> V_187 = V_2 -> V_156 ;
V_2 -> V_188 = V_2 -> V_157 ;
break;
case 'u' :
F_105 ( V_2 , V_2 -> V_153 ) ;
F_117 ( V_2 , V_2 -> V_185 , V_2 -> V_186 ) ;
V_2 -> V_156 = V_2 -> V_187 ;
V_2 -> V_157 = V_2 -> V_188 ;
break;
}
}
static void
F_121 ( struct V_1 * V_2 , struct V_122 * V_123 ,
const unsigned char * V_191 , int V_7 )
{
int V_192 , V_49 ;
F_37 ( & V_2 -> V_12 . V_61 ) ;
for ( V_192 = 0 ; ! V_123 -> V_193 && V_192 < V_7 ; V_192 ++ ) {
if ( V_2 -> V_184 != 0 ) {
F_119 ( V_2 , V_191 [ V_192 ] ) ;
continue;
}
switch ( V_191 [ V_192 ] ) {
case 0x07 :
V_2 -> V_65 |= V_194 ;
break;
case 0x08 :
if ( V_2 -> V_154 > 0 ) {
V_2 -> V_154 -- ;
F_104 ( V_2 , ' ' ) ;
}
break;
case 0x09 :
for ( V_49 = V_2 -> V_154 % 8 ; V_49 < 8 ; V_49 ++ ) {
if ( V_2 -> V_154 >= V_2 -> V_12 . V_13 ) {
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
break;
}
F_104 ( V_2 , ' ' ) ;
V_2 -> V_154 ++ ;
}
break;
case 0x0a :
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
break;
case 0x0c :
F_114 ( V_2 , 2 ) ;
V_2 -> V_154 = V_2 -> V_153 = 0 ;
break;
case 0x0d :
V_2 -> V_154 = 0 ;
break;
case 0x0f :
break;
case 0x1b :
F_119 ( V_2 , V_191 [ V_192 ] ) ;
break;
default:
if ( V_2 -> V_154 >= V_2 -> V_12 . V_13 ) {
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
}
F_104 ( V_2 , V_191 [ V_192 ] ) ;
V_2 -> V_154 ++ ;
break;
}
}
F_105 ( V_2 , V_2 -> V_153 ) ;
if ( ! F_122 ( & V_2 -> V_4 ) )
F_1 ( V_2 , V_195 / 10 ) ;
F_38 ( & V_2 -> V_12 . V_61 ) ;
}
static int
F_123 ( struct V_122 * V_123 ,
const unsigned char * V_191 , int V_7 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_196 > 0 ) {
F_121 ( V_2 , V_123 , V_2 -> V_197 , V_2 -> V_196 ) ;
V_2 -> V_196 = 0 ;
}
F_121 ( V_2 , V_123 , V_191 , V_7 ) ;
return V_7 ;
}
static int F_124 ( struct V_122 * V_123 , unsigned char V_151 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 || V_2 -> V_196 >= V_198 )
return 0 ;
V_2 -> V_197 [ V_2 -> V_196 ++ ] = V_151 ;
return 1 ;
}
static void
F_125 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return;
if ( V_2 -> V_196 > 0 ) {
F_121 ( V_2 , V_123 , V_2 -> V_197 , V_2 -> V_196 ) ;
V_2 -> V_196 = 0 ;
}
}
static int
F_126 ( struct V_122 * V_123 )
{
return 0 ;
}
static void
F_127 ( struct V_122 * V_123 )
{
}
static void
F_128 ( struct V_122 * V_123 , struct V_199 * V_200 )
{
struct V_1 * V_2 ;
int V_201 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return;
F_37 ( & V_2 -> V_12 . V_61 ) ;
if ( F_129 ( V_123 ) ) {
V_201 = F_130 ( V_123 ) ? V_24 : V_81 ;
if ( V_201 != V_2 -> V_11 ) {
V_2 -> V_11 = V_201 ;
F_3 ( V_2 , NULL , 0 ) ;
F_1 ( V_2 , 1 ) ;
}
}
F_38 ( & V_2 -> V_12 . V_61 ) ;
}
static void
F_131 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return;
V_2 -> V_93 = 1 ;
}
static void
F_132 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return;
V_2 -> V_93 = 0 ;
if ( V_2 -> V_94 )
F_49 ( V_2 , 1 ) ;
}
static void
F_133 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return;
F_37 ( & V_2 -> V_12 . V_61 ) ;
V_2 -> V_154 = V_2 -> V_185 = 0 ;
V_2 -> V_153 = V_2 -> V_186 = 0 ;
V_2 -> V_156 = V_2 -> V_187 = V_47 ;
V_2 -> V_157 = V_2 -> V_188 = V_36 ;
F_23 ( V_2 ) ;
while ( V_2 -> V_44 < V_2 -> V_12 . V_16 - 2 )
F_21 ( V_2 ) ;
V_2 -> V_19 = V_55 ;
F_38 ( & V_2 -> V_12 . V_61 ) ;
F_1 ( V_2 , 1 ) ;
}
static void
F_134 ( struct V_122 * V_123 , int V_202 )
{
}
static int F_135 ( struct V_122 * V_123 , unsigned int V_90 ,
unsigned long V_203 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return - V_204 ;
if ( F_136 ( V_123 ) )
return - V_96 ;
return F_137 ( V_2 -> V_74 , V_90 , V_203 ) ;
}
static long F_138 ( struct V_122 * V_123 ,
unsigned int V_90 , unsigned long V_203 )
{
struct V_1 * V_2 ;
V_2 = V_123 -> V_133 ;
if ( ! V_2 )
return - V_204 ;
if ( F_136 ( V_123 ) )
return - V_96 ;
return F_137 ( V_2 -> V_74 , V_90 , ( unsigned long ) F_139 ( V_203 ) ) ;
}
static void F_140 ( int V_205 )
{
F_141 ( V_206 , V_205 - V_134 , NULL ) ;
}
static void F_142 ( int V_205 )
{
F_143 ( V_206 , V_205 - V_134 ) ;
}
static int T_2 F_144 ( void )
{
struct V_137 * V_138 ;
int V_207 ;
V_138 = F_145 ( V_208 ,
V_209 |
V_210 |
V_211 ) ;
if ( F_65 ( V_138 ) )
return F_94 ( V_138 ) ;
V_138 -> V_212 = L_6 ;
V_138 -> V_213 = L_7 ;
V_138 -> V_214 = V_215 ;
V_138 -> V_216 = V_134 ;
V_138 -> V_217 = V_134 ;
V_138 -> type = V_218 ;
V_138 -> V_219 = V_220 ;
V_138 -> V_221 = V_222 ;
F_146 ( V_138 , & V_223 ) ;
V_207 = F_147 ( V_138 ) ;
if ( V_207 ) {
F_148 ( V_138 ) ;
return V_207 ;
}
V_206 = V_138 ;
F_149 ( & V_224 ) ;
return 0 ;
}
static void T_3
F_150 ( void )
{
struct V_137 * V_138 ;
F_151 ( & V_224 ) ;
V_138 = V_206 ;
V_206 = NULL ;
F_152 ( V_138 ) ;
F_148 ( V_138 ) ;
F_90 () ;
}
