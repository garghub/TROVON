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
if ( ! V_45 && ! F_24 ( & V_2 -> V_9 ) )
return;
if ( V_2 -> V_9 . V_22 )
F_25 ( & V_2 -> V_9 ) ;
V_39 = F_22 ( & V_2 -> V_38 , 0 ) ;
if ( ! V_39 ) {
F_1 ( V_2 , 1 ) ;
return;
}
F_26 ( & V_2 -> V_9 . V_46 , V_42 ) ;
V_43 = 0 ;
if ( V_2 -> V_11 & V_47 ) {
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
V_2 -> V_11 = V_48 | V_31 |
V_12 ;
}
if ( V_2 -> V_11 & V_48 ) {
F_27 ( V_39 , V_49 ) ;
V_43 |= V_48 ;
} else
F_27 ( V_39 , V_50 ) ;
V_40 = V_51 ;
F_28 ( V_39 , & V_40 , 1 ) ;
if ( V_2 -> V_11 & V_12 )
if ( F_28 ( V_39 , V_2 -> V_8 -> string ,
V_2 -> V_8 -> V_27 ) == 0 )
V_43 |= V_12 ;
if ( V_2 -> V_11 & V_31 ) {
V_41 [ 0 ] = V_14 ;
V_41 [ 3 ] = V_17 ;
V_41 [ 4 ] = V_18 ;
V_41 [ 5 ] = V_52 ;
F_8 ( V_2 -> V_9 . V_22 , V_41 + 1 ,
V_2 -> V_9 . V_23 * V_2 -> V_30 ) ;
F_28 ( V_39 , V_41 , 6 ) ;
F_11 (s, n, &cp->update, update) {
if ( V_25 != V_2 -> V_53 )
F_9 ( V_2 , V_25 , V_2 -> V_30 ) ;
if ( F_28 ( V_39 , V_25 -> string ,
V_25 -> V_27 ) != 0 )
break;
F_12 ( & V_25 -> V_29 ) ;
if ( V_25 != V_2 -> V_53 )
V_2 -> V_30 ++ ;
}
if ( F_17 ( & V_2 -> V_29 ) )
V_43 |= V_31 ;
}
V_39 -> V_54 = F_20 ;
V_44 = F_29 ( & V_2 -> V_9 , V_39 ) ;
if ( V_44 == 0 ) {
V_2 -> V_11 &= ~ V_43 ;
if ( V_2 -> V_11 )
F_1 ( V_2 , 1 ) ;
} else {
F_21 ( V_39 ) ;
F_22 ( & V_2 -> V_38 , V_39 ) ;
}
F_30 ( & V_2 -> V_9 . V_46 , V_42 ) ;
}
static void
F_31 ( struct V_35 * V_55 )
{
static char V_56 = V_57 ;
struct V_1 * V_2 ;
unsigned long V_42 ;
int V_7 , V_58 ;
V_2 = (struct V_1 * ) V_55 -> V_9 ;
F_26 ( & V_2 -> V_9 . V_46 , V_42 ) ;
V_7 = V_2 -> V_7 ;
V_58 = 0 ;
switch ( V_2 -> V_59 -> string [ 0 ] ) {
case 0x7d :
V_7 = 0 ;
break;
case 0xf3 :
V_58 = 1 ;
break;
case 0x6d :
V_2 -> V_11 = V_47 ;
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
F_30 ( & V_2 -> V_9 . V_46 , V_42 ) ;
F_21 ( V_2 -> V_60 ) ;
F_27 ( V_2 -> V_60 , V_50 ) ;
F_28 ( V_2 -> V_60 , & V_56 , 1 ) ;
F_29 ( & V_2 -> V_9 , V_2 -> V_60 ) ;
if ( V_58 )
F_32 ( & V_2 -> V_9 ) ;
F_21 ( V_55 ) ;
F_22 ( & V_2 -> V_61 , V_55 ) ;
F_33 ( & V_2 -> V_9 ) ;
}
static void
F_34 ( struct V_35 * V_36 , void * V_37 )
{
F_35 ( V_36 -> V_9 ) ;
F_36 ( & ( (struct V_1 * ) V_36 -> V_9 ) -> V_62 ) ;
}
static void
F_37 ( struct V_1 * V_2 )
{
struct V_35 * V_55 ;
int V_44 ;
V_55 = F_22 ( & V_2 -> V_61 , 0 ) ;
if ( ! V_55 )
return;
V_55 -> V_54 = F_34 ;
V_55 -> V_63 = V_2 ;
F_27 ( V_55 , V_64 ) ;
F_38 ( V_55 , V_2 -> V_59 -> string , V_2 -> V_59 -> V_27 ) ;
V_44 = F_39 ( & V_2 -> V_9 , V_55 ) ;
if ( V_44 )
F_21 ( V_55 ) ;
}
static int
F_40 ( struct V_65 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 ;
V_2 -> V_11 = V_47 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static void
F_41 ( struct V_65 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 ;
F_2 ( & V_2 -> V_4 ) ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_35 * V_36 , struct V_66 * V_66 )
{
if ( V_66 -> V_67 . V_68 . V_69 & V_70 )
F_37 ( V_2 ) ;
if ( V_36 ) {
if ( V_66 -> V_67 . V_68 . V_69 & V_71 )
V_36 -> V_44 = - V_72 ;
else
V_36 -> V_73 = V_66 -> V_67 . V_68 . V_74 ;
} else if ( V_66 -> V_67 . V_68 . V_69 & V_75 ) {
V_2 -> V_11 = V_47 ;
F_1 ( V_2 , 1 ) ;
}
return V_76 ;
}
static inline void
F_43 ( struct V_1 * V_2 )
{
if ( ! F_17 ( & V_2 -> V_53 -> V_33 ) )
return;
F_44 ( & V_2 -> V_53 -> V_33 , & V_2 -> V_77 ) ;
V_2 -> V_34 ++ ;
F_10 ( V_2 ) ;
}
static inline void
F_45 ( struct V_1 * V_2 , unsigned char V_78 )
{
V_2 -> V_53 -> string [ V_2 -> V_53 -> V_27 ++ ] =
V_2 -> V_9 . V_10 [ ( V_78 < ' ' ) ? ' ' : V_78 ] ;
if ( F_17 ( & V_2 -> V_53 -> V_29 ) ) {
F_44 ( & V_2 -> V_53 -> V_29 , & V_2 -> V_29 ) ;
V_2 -> V_11 |= V_31 ;
}
}
static inline void
F_46 ( struct V_1 * V_2 )
{
struct string * V_25 ;
unsigned int V_32 ;
V_32 = ( V_2 -> V_53 -> V_27 < V_2 -> V_9 . V_23 - 5 ) ?
V_2 -> V_53 -> V_27 + 4 : V_2 -> V_9 . V_23 ;
V_25 = F_15 ( V_2 , V_32 ) ;
memcpy ( V_25 -> string , V_2 -> V_53 -> string , V_2 -> V_53 -> V_27 ) ;
if ( V_25 -> V_27 < V_2 -> V_9 . V_23 - 5 ) {
V_25 -> string [ V_25 -> V_27 - 4 ] = V_20 ;
V_25 -> string [ V_25 -> V_27 - 1 ] = 0 ;
} else {
while ( -- V_32 > V_2 -> V_53 -> V_27 )
V_25 -> string [ V_32 ] = V_2 -> V_9 . V_10 [ ' ' ] ;
}
F_14 ( & V_25 -> V_33 , & V_2 -> V_53 -> V_33 ) ;
F_12 ( & V_2 -> V_53 -> V_33 ) ;
if ( ! F_17 ( & V_2 -> V_53 -> V_29 ) ) {
F_14 ( & V_25 -> V_29 , & V_2 -> V_53 -> V_29 ) ;
F_12 ( & V_2 -> V_53 -> V_29 ) ;
}
V_2 -> V_53 -> V_27 = 0 ;
}
static void
F_47 ( struct V_79 * V_80 , const char * V_6 , unsigned int V_74 )
{
struct V_1 * V_2 ;
unsigned long V_42 ;
unsigned char V_78 ;
V_2 = V_81 ;
F_26 ( & V_2 -> V_9 . V_46 , V_42 ) ;
while ( V_74 -- > 0 ) {
V_78 = * V_6 ++ ;
if ( V_2 -> V_53 -> V_27 == 0 )
F_43 ( V_2 ) ;
if ( V_78 != '\n' )
F_45 ( V_2 , V_78 ) ;
if ( V_78 == '\n' || V_2 -> V_53 -> V_27 >= V_2 -> V_9 . V_23 )
F_46 ( V_2 ) ;
}
V_2 -> V_7 = 0 ;
if ( V_2 -> V_9 . V_22 && ! F_48 ( & V_2 -> V_4 ) )
F_1 ( V_2 , V_82 / 10 ) ;
F_30 ( & V_2 -> V_9 . V_46 , V_42 ) ;
}
static struct V_83 *
F_49 ( struct V_79 * V_78 , int * V_84 )
{
* V_84 = V_78 -> V_84 ;
return V_85 ;
}
static void
F_50 ( struct V_1 * V_2 )
{
while ( ! V_2 -> V_38 ) {
F_51 ( V_2 -> V_9 . V_22 ) ;
F_52 () ;
}
}
static void
F_53 ( void )
{
struct V_1 * V_2 ;
unsigned long V_42 ;
V_2 = V_81 ;
if ( ! V_2 -> V_9 . V_22 )
return;
F_54 ( & V_2 -> V_9 ) ;
F_25 ( & V_2 -> V_9 ) ;
F_26 ( & V_2 -> V_9 . V_46 , V_42 ) ;
F_50 ( V_2 ) ;
V_2 -> V_7 = 0 ;
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
while ( V_2 -> V_11 != 0 ) {
F_30 ( & V_2 -> V_9 . V_46 , V_42 ) ;
F_23 ( V_2 ) ;
F_26 ( & V_2 -> V_9 . V_46 , V_42 ) ;
F_50 ( V_2 ) ;
}
F_30 ( & V_2 -> V_9 . V_46 , V_42 ) ;
}
static int F_55 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_37 )
{
F_53 () ;
return V_89 ;
}
static int T_2
F_56 ( void )
{
struct V_90 * V_91 ;
void * V_92 ;
int V_93 ;
if ( ! V_94 )
return - V_95 ;
if ( V_96 ) {
F_57 ( L_3 , NULL , 0 , NULL ) ;
F_57 ( L_4 , NULL , 0 , NULL ) ;
}
V_91 = F_58 () ;
if ( F_59 ( V_91 ) )
return F_60 ( V_91 ) ;
V_81 = F_61 ( sizeof( struct V_1 ) , V_97 | V_98 ) ;
if ( ! V_81 )
return - V_99 ;
V_81 -> V_9 . V_22 = V_91 ;
V_81 -> V_61 = F_62 ( 0 ) ;
V_81 -> V_61 -> V_54 = F_34 ;
V_81 -> V_61 -> V_63 = V_81 ;
V_81 -> V_38 = F_62 ( V_100 ) ;
V_81 -> V_60 = F_62 ( 1 ) ;
F_63 ( & V_81 -> V_77 ) ;
F_63 ( & V_81 -> V_29 ) ;
F_64 ( & V_81 -> V_4 , ( void (*) ( unsigned long ) ) F_23 ,
( unsigned long ) V_81 ) ;
F_65 ( & V_81 -> V_62 ,
( void (*) ( unsigned long ) ) F_31 ,
( unsigned long ) V_81 -> V_61 ) ;
F_66 ( & V_81 -> V_9 , & V_101 , 1 ) ;
F_63 ( & V_81 -> V_21 ) ;
for ( V_93 = 0 ; V_93 < V_102 ; V_93 ++ ) {
V_92 = ( void * ) F_67 ( V_97 | V_98 ) ;
F_68 ( & V_81 -> V_21 , V_92 , V_103 ) ;
}
V_81 -> V_53 = F_7 ( & V_81 -> V_21 , V_81 -> V_9 . V_23 ) ;
V_81 -> V_53 -> V_27 = 0 ;
F_6 ( V_81 ) ;
V_81 -> V_59 = F_7 ( & V_81 -> V_21 , 80 ) ;
F_69 ( & V_104 , & V_105 ) ;
F_70 ( & V_106 ) ;
F_71 ( & V_1 ) ;
return 0 ;
}
