static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 0 )
F_2 ( & V_2 -> V_4 ) ;
else
F_3 ( & V_2 -> V_4 , V_5 + V_3 ) ;
}
static void
F_4 ( struct V_1 * V_2 )
{
char * V_6 ;
V_6 = ( V_2 -> V_7 != 0 ) ? L_1 : L_2 ;
memcpy ( V_2 -> V_8 -> string + 24 , V_6 , 7 ) ;
F_5 ( V_2 -> V_9 . V_10 , V_2 -> V_8 -> string + 24 , 7 ) ;
V_2 -> V_11 |= V_12 ;
}
static void
F_6 ( struct V_1 * V_2 )
{
static const unsigned char V_13 [] =
{ V_14 , 0 , 0 , V_15 , V_16 , V_17 , V_18 , V_19 ,
'c' , 'o' , 'n' , 's' , 'o' , 'l' , 'e' , ' ' , 'v' , 'i' , 'e' , 'w' ,
V_20 , 0 , 0 , 0 , 'R' , 'u' , 'n' , 'n' , 'i' , 'n' , 'g' , V_15 , V_16 } ;
V_2 -> V_8 = F_7 ( & V_2 -> V_21 , sizeof( V_13 ) ) ;
memcpy ( V_2 -> V_8 -> string , V_13 , sizeof( V_13 ) ) ;
F_8 ( V_2 -> V_9 . V_22 , V_2 -> V_8 -> string + 1 ,
V_2 -> V_9 . V_23 * ( V_2 -> V_9 . V_24 - 1 ) ) ;
F_8 ( V_2 -> V_9 . V_22 , V_2 -> V_8 -> string + 21 ,
V_2 -> V_9 . V_23 * V_2 -> V_9 . V_24 - 8 ) ;
F_5 ( V_2 -> V_9 . V_10 , V_2 -> V_8 -> string + 8 , 12 ) ;
F_5 ( V_2 -> V_9 . V_10 , V_2 -> V_8 -> string + 24 , 7 ) ;
}
static void
F_9 ( struct V_1 * V_2 , struct string * V_25 , int V_26 )
{
if ( V_25 -> V_27 >= V_2 -> V_9 . V_23 - 5 )
return;
F_8 ( V_2 -> V_9 . V_22 , V_25 -> string + V_25 -> V_27 - 3 ,
V_2 -> V_9 . V_23 * ( V_26 + 1 ) ) ;
}
static void
F_10 ( struct V_1 * V_2 )
{
struct string * V_25 , * V_28 ;
int V_26 ;
F_11 (s, n, &cp->update, update)
F_12 ( & V_25 -> V_29 ) ;
V_26 = V_2 -> V_9 . V_24 - 2 + V_2 -> V_7 ;
F_13 (s, &cp->lines, list) {
if ( V_26 < V_2 -> V_9 . V_24 - 1 )
F_14 ( & V_25 -> V_29 , & V_2 -> V_29 ) ;
if ( -- V_26 < 0 )
break;
}
V_2 -> V_30 = 0 ;
V_2 -> V_11 |= V_31 ;
}
static struct string *
F_15 ( struct V_1 * V_2 , T_1 V_32 )
{
struct string * V_25 , * V_28 ;
V_25 = F_7 ( & V_2 -> V_21 , V_32 ) ;
if ( V_25 )
return V_25 ;
F_11 (s, n, &cp->lines, list) {
F_16 ( & V_25 -> V_33 ) ;
if ( ! F_17 ( & V_25 -> V_29 ) )
F_16 ( & V_25 -> V_29 ) ;
V_2 -> V_34 -- ;
if ( F_18 ( & V_2 -> V_21 , V_25 ) >= V_32 )
break;
}
V_25 = F_7 ( & V_2 -> V_21 , V_32 ) ;
F_19 ( ! V_25 ) ;
if ( V_2 -> V_7 != 0 && V_2 -> V_7 + V_2 -> V_9 . V_24 > V_2 -> V_34 ) {
V_2 -> V_7 = V_2 -> V_34 - V_2 -> V_9 . V_24 + 1 ;
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
}
return V_25 ;
}
static void
F_20 ( struct V_35 * V_36 , void * V_37 )
{
F_21 ( V_36 ) ;
F_22 ( & ( (struct V_1 * ) V_36 -> V_9 ) -> V_38 , V_36 ) ;
}
static void
F_23 ( struct V_1 * V_2 )
{
struct V_35 * V_39 ;
char V_40 , V_41 [ 6 ] ;
unsigned long V_42 ;
unsigned long V_43 ;
struct string * V_25 , * V_28 ;
int V_44 ;
if ( V_2 -> V_9 . V_22 )
F_24 ( & V_2 -> V_9 ) ;
V_39 = F_22 ( & V_2 -> V_38 , 0 ) ;
if ( ! V_39 ) {
F_1 ( V_2 , 1 ) ;
return;
}
F_25 ( & V_2 -> V_9 . V_45 , V_42 ) ;
V_43 = 0 ;
if ( V_2 -> V_11 & V_46 ) {
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
V_2 -> V_11 = V_47 | V_31 |
V_12 ;
}
if ( V_2 -> V_11 & V_47 ) {
F_26 ( V_39 , V_48 ) ;
V_43 |= V_47 ;
} else
F_26 ( V_39 , V_49 ) ;
V_40 = V_50 ;
F_27 ( V_39 , & V_40 , 1 ) ;
if ( V_2 -> V_11 & V_12 )
if ( F_27 ( V_39 , V_2 -> V_8 -> string ,
V_2 -> V_8 -> V_27 ) == 0 )
V_43 |= V_12 ;
if ( V_2 -> V_11 & V_31 ) {
V_41 [ 0 ] = V_14 ;
V_41 [ 3 ] = V_17 ;
V_41 [ 4 ] = V_18 ;
V_41 [ 5 ] = V_51 ;
F_8 ( V_2 -> V_9 . V_22 , V_41 + 1 ,
V_2 -> V_9 . V_23 * V_2 -> V_30 ) ;
F_27 ( V_39 , V_41 , 6 ) ;
F_11 (s, n, &cp->update, update) {
if ( V_25 != V_2 -> V_52 )
F_9 ( V_2 , V_25 , V_2 -> V_30 ) ;
if ( F_27 ( V_39 , V_25 -> string ,
V_25 -> V_27 ) != 0 )
break;
F_12 ( & V_25 -> V_29 ) ;
if ( V_25 != V_2 -> V_52 )
V_2 -> V_30 ++ ;
}
if ( F_17 ( & V_2 -> V_29 ) )
V_43 |= V_31 ;
}
V_39 -> V_53 = F_20 ;
V_44 = F_28 ( & V_2 -> V_9 , V_39 ) ;
if ( V_44 == 0 ) {
V_2 -> V_11 &= ~ V_43 ;
if ( V_2 -> V_11 )
F_1 ( V_2 , 1 ) ;
} else {
F_21 ( V_39 ) ;
F_22 ( & V_2 -> V_38 , V_39 ) ;
}
F_29 ( & V_2 -> V_9 . V_45 , V_42 ) ;
}
static void
F_30 ( struct V_35 * V_54 )
{
static char V_55 = V_56 ;
struct V_1 * V_2 ;
unsigned long V_42 ;
int V_7 , V_57 ;
V_2 = (struct V_1 * ) V_54 -> V_9 ;
F_25 ( & V_2 -> V_9 . V_45 , V_42 ) ;
V_7 = V_2 -> V_7 ;
V_57 = 0 ;
switch ( V_2 -> V_58 -> string [ 0 ] ) {
case 0x7d :
V_7 = 0 ;
break;
case 0xf3 :
V_57 = 1 ;
break;
case 0x6d :
V_2 -> V_11 = V_46 ;
F_1 ( V_2 , 1 ) ;
break;
case 0xf7 :
V_7 += V_2 -> V_9 . V_24 - 2 ;
if ( V_7 + V_2 -> V_9 . V_24 - 1 > V_2 -> V_34 ) {
V_7 = V_2 -> V_34 - V_2 -> V_9 . V_24 + 1 ;
if ( V_7 < 0 )
V_7 = 0 ;
}
break;
case 0xf8 :
V_7 -= V_2 -> V_9 . V_24 - 2 ;
if ( V_7 < 0 )
V_7 = 0 ;
break;
}
if ( V_7 != V_2 -> V_7 ) {
V_2 -> V_7 = V_7 ;
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
}
F_29 ( & V_2 -> V_9 . V_45 , V_42 ) ;
F_21 ( V_2 -> V_59 ) ;
F_26 ( V_2 -> V_59 , V_49 ) ;
F_27 ( V_2 -> V_59 , & V_55 , 1 ) ;
F_28 ( & V_2 -> V_9 , V_2 -> V_59 ) ;
if ( V_57 )
F_31 ( & V_2 -> V_9 ) ;
F_21 ( V_54 ) ;
F_22 ( & V_2 -> V_60 , V_54 ) ;
F_32 ( & V_2 -> V_9 ) ;
}
static void
F_33 ( struct V_35 * V_36 , void * V_37 )
{
F_34 ( V_36 -> V_9 ) ;
F_35 ( & ( (struct V_1 * ) V_36 -> V_9 ) -> V_61 ) ;
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_35 * V_54 ;
int V_44 ;
V_54 = F_22 ( & V_2 -> V_60 , 0 ) ;
if ( ! V_54 )
return;
V_54 -> V_53 = F_33 ;
V_54 -> V_62 = V_2 ;
F_26 ( V_54 , V_63 ) ;
F_37 ( V_54 , V_2 -> V_58 -> string , V_2 -> V_58 -> V_27 ) ;
V_44 = F_38 ( & V_2 -> V_9 , V_54 ) ;
if ( V_44 )
F_21 ( V_54 ) ;
}
static int
F_39 ( struct V_64 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 ;
V_2 -> V_11 = V_46 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static void
F_40 ( struct V_64 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 ;
F_2 ( & V_2 -> V_4 ) ;
}
static int
F_41 ( struct V_1 * V_2 , struct V_35 * V_36 , struct V_65 * V_65 )
{
if ( V_65 -> V_66 . V_67 . V_68 & V_69 )
F_36 ( V_2 ) ;
if ( V_36 ) {
if ( V_65 -> V_66 . V_67 . V_68 & V_70 )
V_36 -> V_44 = - V_71 ;
else
V_36 -> V_72 = V_65 -> V_66 . V_67 . V_73 ;
}
return V_74 ;
}
static inline void
F_42 ( struct V_1 * V_2 )
{
if ( ! F_17 ( & V_2 -> V_52 -> V_33 ) )
return;
F_43 ( & V_2 -> V_52 -> V_33 , & V_2 -> V_75 ) ;
V_2 -> V_34 ++ ;
F_10 ( V_2 ) ;
}
static inline void
F_44 ( struct V_1 * V_2 , unsigned char V_76 )
{
V_2 -> V_52 -> string [ V_2 -> V_52 -> V_27 ++ ] =
V_2 -> V_9 . V_10 [ ( V_76 < ' ' ) ? ' ' : V_76 ] ;
if ( F_17 ( & V_2 -> V_52 -> V_29 ) ) {
F_43 ( & V_2 -> V_52 -> V_29 , & V_2 -> V_29 ) ;
V_2 -> V_11 |= V_31 ;
}
}
static inline void
F_45 ( struct V_1 * V_2 )
{
struct string * V_25 ;
unsigned int V_32 ;
V_32 = ( V_2 -> V_52 -> V_27 < V_2 -> V_9 . V_23 - 5 ) ?
V_2 -> V_52 -> V_27 + 4 : V_2 -> V_9 . V_23 ;
V_25 = F_15 ( V_2 , V_32 ) ;
memcpy ( V_25 -> string , V_2 -> V_52 -> string , V_2 -> V_52 -> V_27 ) ;
if ( V_25 -> V_27 < V_2 -> V_9 . V_23 - 5 ) {
V_25 -> string [ V_25 -> V_27 - 4 ] = V_20 ;
V_25 -> string [ V_25 -> V_27 - 1 ] = 0 ;
} else {
while ( -- V_32 > V_2 -> V_52 -> V_27 )
V_25 -> string [ V_32 ] = V_2 -> V_9 . V_10 [ ' ' ] ;
}
F_14 ( & V_25 -> V_33 , & V_2 -> V_52 -> V_33 ) ;
F_12 ( & V_2 -> V_52 -> V_33 ) ;
if ( ! F_17 ( & V_2 -> V_52 -> V_29 ) ) {
F_14 ( & V_25 -> V_29 , & V_2 -> V_52 -> V_29 ) ;
F_12 ( & V_2 -> V_52 -> V_29 ) ;
}
V_2 -> V_52 -> V_27 = 0 ;
}
static void
F_46 ( struct V_77 * V_78 , const char * V_6 , unsigned int V_73 )
{
struct V_1 * V_2 ;
unsigned long V_42 ;
unsigned char V_76 ;
V_2 = V_79 ;
F_25 ( & V_2 -> V_9 . V_45 , V_42 ) ;
while ( V_73 -- > 0 ) {
V_76 = * V_6 ++ ;
if ( V_2 -> V_52 -> V_27 == 0 )
F_42 ( V_2 ) ;
if ( V_76 != '\n' )
F_44 ( V_2 , V_76 ) ;
if ( V_76 == '\n' || V_2 -> V_52 -> V_27 >= V_2 -> V_9 . V_23 )
F_45 ( V_2 ) ;
}
V_2 -> V_7 = 0 ;
if ( V_2 -> V_9 . V_22 && ! F_47 ( & V_2 -> V_4 ) )
F_1 ( V_2 , V_80 / 10 ) ;
F_29 ( & V_2 -> V_9 . V_45 , V_42 ) ;
}
static struct V_81 *
F_48 ( struct V_77 * V_76 , int * V_82 )
{
* V_82 = V_76 -> V_82 ;
return V_83 ;
}
static void
F_49 ( struct V_1 * V_2 )
{
while ( ! V_2 -> V_38 ) {
F_50 ( V_2 -> V_9 . V_22 ) ;
F_51 () ;
}
}
static void
F_52 ( void )
{
struct V_1 * V_2 ;
unsigned long V_42 ;
V_2 = V_79 ;
if ( ! V_2 -> V_9 . V_22 )
return;
F_53 ( & V_2 -> V_9 ) ;
F_25 ( & V_2 -> V_9 . V_45 , V_42 ) ;
F_49 ( V_2 ) ;
V_2 -> V_7 = 0 ;
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( V_2 -> V_11 != 0 ) {
F_29 ( & V_2 -> V_9 . V_45 , V_42 ) ;
F_23 ( V_2 ) ;
F_25 ( & V_2 -> V_9 . V_45 , V_42 ) ;
F_49 ( V_2 ) ;
}
F_29 ( & V_2 -> V_9 . V_45 , V_42 ) ;
}
static int F_54 ( struct V_84 * V_85 ,
unsigned long V_86 , void * V_37 )
{
F_52 () ;
return V_87 ;
}
static int T_2
F_55 ( void )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
void * V_92 ;
int V_93 ;
if ( ! V_94 )
return - V_95 ;
if ( V_96 ) {
F_56 ( L_3 , NULL , 0 , NULL ) ;
F_56 ( L_4 , NULL , 0 , NULL ) ;
}
V_89 = F_57 () ;
if ( F_58 ( V_89 ) )
return - V_95 ;
V_91 = F_59 ( V_89 ) ;
if ( F_58 ( V_91 ) )
return F_60 ( V_91 ) ;
V_79 = F_61 ( sizeof( struct V_1 ) , V_97 | V_98 ) ;
V_79 -> V_9 . V_22 = V_91 ;
V_79 -> V_60 = F_62 ( 0 ) ;
V_79 -> V_60 -> V_53 = F_33 ;
V_79 -> V_60 -> V_62 = V_79 ;
V_79 -> V_38 = F_62 ( V_99 ) ;
V_79 -> V_59 = F_62 ( 1 ) ;
F_63 ( & V_79 -> V_75 ) ;
F_63 ( & V_79 -> V_29 ) ;
F_64 ( & V_79 -> V_4 , ( void (*) ( unsigned long ) ) F_23 ,
( unsigned long ) V_79 ) ;
F_65 ( & V_79 -> V_61 ,
( void (*) ( unsigned long ) ) F_30 ,
( unsigned long ) V_79 -> V_60 ) ;
F_66 ( & V_79 -> V_9 , & V_100 , 1 ) ;
F_63 ( & V_79 -> V_21 ) ;
for ( V_93 = 0 ; V_93 < V_101 ; V_93 ++ ) {
V_92 = ( void * ) F_67 ( V_97 | V_98 ) ;
F_68 ( & V_79 -> V_21 , V_92 , V_102 ) ;
}
V_79 -> V_52 = F_7 ( & V_79 -> V_21 , V_79 -> V_9 . V_23 ) ;
V_79 -> V_52 -> V_27 = 0 ;
F_6 ( V_79 ) ;
V_79 -> V_58 = F_7 ( & V_79 -> V_21 , 80 ) ;
F_69 ( & V_103 , & V_104 ) ;
F_70 ( & V_105 ) ;
F_71 ( & V_1 ) ;
return 0 ;
}
