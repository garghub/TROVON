int
F_1 ( void )
{
if ( V_1 == 127 )
V_1 = 1 ;
else
V_1 ++ ;
return ( V_1 ) ;
}
void
F_2 ( struct V_2 * V_3 , int V_4 )
{
if ( V_3 -> V_5 & V_6 )
F_3 ( V_3 -> V_7 , L_1 ,
V_3 -> V_8 & 0x7F ,
V_3 -> V_4 , V_4 ) ;
V_3 -> V_4 = V_4 ;
}
static void
F_4 ( struct V_9 * V_10 )
{
V_10 -> V_3 -> V_7 -> V_11 . V_12 ( V_10 -> V_3 -> V_7 , V_10 -> V_13 , V_10 -> V_3 ) ;
}
void
F_5 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
V_10 -> V_3 = V_3 ;
V_10 -> V_14 . V_15 = ( void * ) F_4 ;
V_10 -> V_14 . V_16 = ( long ) V_10 ;
F_6 ( & V_10 -> V_14 ) ;
}
void
F_7 ( struct V_9 * V_10 )
{
F_8 ( & V_10 -> V_14 ) ;
}
int
F_9 ( struct V_9 * V_10 ,
int V_17 , int V_13 )
{
if ( F_10 ( & V_10 -> V_14 ) ) {
F_11 ( V_18 L_2 ) ;
return - 1 ;
}
F_6 ( & V_10 -> V_14 ) ;
V_10 -> V_13 = V_13 ;
V_10 -> V_14 . V_19 = V_20 + ( V_17 * V_21 ) / 1000 ;
F_12 ( & V_10 -> V_14 ) ;
return 0 ;
}
void
F_13 ( struct V_2 * V_3 )
{
F_7 ( & V_3 -> V_22 ) ;
}
struct V_23 *
F_14 ( int V_24 )
{
struct V_23 * V_25 ;
if ( ! ( V_25 = F_15 ( V_24 + V_26 , V_27 ) ) ) {
F_11 ( V_18 L_3 ) ;
return ( NULL ) ;
}
F_16 ( V_25 , V_26 ) ;
return ( V_25 ) ;
}
static void
F_17 ( struct V_28 * V_7 , int V_29 , void * V_30 )
{
struct V_23 * V_25 = V_30 ;
F_18 ( V_7 -> V_31 . V_32 , L_4 , L_5 ) ;
if ( V_25 ) {
F_19 ( V_25 ) ;
}
}
static int
F_20 ( struct V_28 * V_7 , T_1 * V_33 )
{
F_11 ( V_18 L_6 , V_33 -> V_30 & 0xFF ) ;
return ( - 1 ) ;
}
struct V_2
* F_21 ( struct V_28 * V_7 , int V_34 )
{
struct V_2 * V_35 = V_7 -> V_36 . V_37 ;
while ( V_35 )
if ( V_35 -> V_8 == V_34 )
return ( V_35 ) ;
else
V_35 = V_35 -> V_38 ;
return ( NULL ) ;
}
struct V_2
* F_22 ( struct V_28 * V_7 , int V_34 )
{
struct V_2 * V_35 , * V_39 ;
if ( ! ( V_35 = F_23 ( sizeof( struct V_2 ) , V_27 ) ) ) {
F_11 ( V_40 L_7 , V_34 ) ;
return ( NULL ) ;
}
if ( ! V_7 -> V_36 . V_37 )
V_7 -> V_36 . V_37 = V_35 ;
else {
V_39 = V_7 -> V_36 . V_37 ;
while ( V_39 -> V_38 )
V_39 = V_39 -> V_38 ;
V_39 -> V_38 = V_35 ;
}
V_35 -> V_38 = NULL ;
V_35 -> V_5 = V_7 -> V_36 . V_5 ;
V_35 -> V_8 = V_34 ;
V_35 -> V_4 = 0 ;
V_35 -> V_41 = NULL ;
V_35 -> V_7 = V_7 ;
V_35 -> V_42 = V_7 -> V_36 . V_42 ;
F_5 ( V_35 , & V_35 -> V_22 ) ;
return ( V_35 ) ;
}
void
F_24 ( struct V_2 * V_35 )
{
struct V_2 * V_39 , * V_43 = NULL ;
if ( ! V_35 )
return;
V_39 = V_35 -> V_7 -> V_36 . V_37 ;
while ( V_39 ) {
if ( V_39 == V_35 ) {
F_13 ( V_35 ) ;
if ( V_43 )
V_43 -> V_38 = V_39 -> V_38 ;
else if ( ! ( V_35 -> V_7 -> V_36 . V_37 = V_39 -> V_38 ) &&
! F_25 ( V_44 , & V_35 -> V_7 -> V_45 . V_46 ) ) {
if ( V_35 -> V_5 )
F_3 ( V_35 -> V_7 , L_8 ) ;
if ( F_26 ( & V_35 -> V_7 -> V_36 . V_47 ) ) {
if ( V_35 -> V_5 )
F_3 ( V_35 -> V_7 , L_9 ) ;
if ( V_35 -> V_7 -> V_48 != V_49 )
F_27 ( & V_35 -> V_7 -> V_36 . V_50 , V_51 , NULL ) ;
else
F_27 ( & V_35 -> V_7 -> V_36 . V_50 , V_52 , NULL ) ;
} else {
if ( V_35 -> V_5 )
F_3 ( V_35 -> V_7 , L_10 ) ;
}
}
F_28 ( V_35 ) ;
return;
}
V_43 = V_39 ;
V_39 = V_39 -> V_38 ;
}
F_11 ( V_40 L_11 , V_35 -> V_8 ) ;
F_3 ( V_35 -> V_7 , L_12 , V_35 -> V_8 ) ;
}
static void
F_29 ( struct V_28 * V_7 , int V_29 )
{
struct V_2 * V_35 = V_7 -> V_36 . V_37 ;
struct V_2 * V_39 ;
while ( V_35 ) {
V_39 = V_35 -> V_38 ;
V_7 -> V_36 . V_53 ( V_7 , V_29 , V_35 ) ;
V_35 = V_39 ;
}
}
void
F_30 ( struct V_28 * V_7 , struct V_54 * V_55 )
{
char V_56 [ 64 ] ;
V_7 -> V_36 . V_37 = NULL ;
V_7 -> V_36 . V_57 = NULL ;
F_31 ( & V_7 -> V_36 . V_47 ) ;
V_7 -> V_36 . V_50 . V_58 = & V_59 ;
V_7 -> V_36 . V_50 . V_4 = V_60 ;
V_7 -> V_36 . V_50 . V_5 = 1 ;
V_7 -> V_36 . V_50 . V_61 = V_7 ;
V_7 -> V_36 . V_50 . V_62 = 0 ;
V_7 -> V_36 . V_50 . V_63 = V_64 ;
F_32 ( & V_7 -> V_36 . V_50 , & V_7 -> V_36 . V_65 ) ;
strcpy ( V_7 -> V_36 . V_66 , L_13 ) ;
V_7 -> V_11 . V_67 = F_20 ;
#ifdef F_33
if ( V_7 -> V_48 == V_68 ) {
F_34 ( V_7 ) ;
} else
#endif
#ifdef F_35
if ( V_7 -> V_48 == V_49 ) {
F_36 ( V_7 ) ;
} else
#endif
#ifdef F_37
if ( V_7 -> V_48 == V_69 ) {
F_38 ( V_7 ) ;
} else
#endif
if ( V_7 -> V_48 == V_70 ) {
V_7 -> V_11 . V_12 = F_17 ;
V_7 -> V_45 . V_71 = F_17 ;
V_7 -> V_36 . V_53 = F_17 ;
F_11 ( V_72 L_14 ) ;
} else {
V_7 -> V_11 . V_12 = F_17 ;
V_7 -> V_45 . V_71 = F_17 ;
V_7 -> V_36 . V_53 = F_17 ;
sprintf ( V_56 , L_15 ,
( V_7 -> V_48 == V_69 ) ? L_16 :
( V_7 -> V_48 == V_68 ) ? L_17 :
( V_7 -> V_48 == V_49 ) ? L_18 :
L_19 ) ;
F_11 ( V_18 L_20 , V_56 ) ;
V_7 -> V_48 = - 1 ;
}
}
static void
F_39 ( struct V_28 * V_7 , int V_29 , void * V_30 ) {
V_7 -> V_36 . V_73 ( V_7 , V_29 , V_30 ) ;
}
void
F_40 ( struct V_28 * V_7 )
{
while ( V_7 -> V_36 . V_37 )
F_24 ( V_7 -> V_36 . V_37 ) ;
if ( V_7 -> V_36 . V_57 ) {
F_13 ( V_7 -> V_36 . V_57 ) ;
F_28 ( V_7 -> V_36 . V_57 ) ;
V_7 -> V_36 . V_57 = NULL ;
}
F_41 ( & V_7 -> V_36 . V_65 , 54 ) ;
F_42 ( & V_7 -> V_36 . V_47 ) ;
}
void
F_43 ( struct V_28 * V_7 , struct V_54 * V_55 )
{
V_7 -> V_36 . V_37 = NULL ;
V_7 -> V_36 . V_57 = NULL ;
F_31 ( & V_7 -> V_36 . V_47 ) ;
V_7 -> V_36 . V_50 . V_58 = & V_59 ;
V_7 -> V_36 . V_50 . V_4 = V_60 ;
V_7 -> V_36 . V_50 . V_5 = 1 ;
V_7 -> V_36 . V_50 . V_61 = V_7 ;
V_7 -> V_36 . V_50 . V_62 = 0 ;
V_7 -> V_36 . V_50 . V_63 = V_64 ;
strcpy ( V_7 -> V_36 . V_66 , L_21 ) ;
V_7 -> V_11 . V_12 = F_39 ;
}
static void
F_44 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
F_45 ( V_75 , V_76 ) ;
V_7 -> V_36 . V_73 ( V_7 , V_77 | V_78 , NULL ) ;
}
static void
F_46 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
struct V_23 * V_25 = V_30 ;
int V_79 = 0 ;
F_45 ( V_75 , V_80 ) ;
while ( ( V_25 = F_47 ( & V_7 -> V_36 . V_47 ) ) ) {
V_7 -> V_36 . V_73 ( V_7 , V_81 | V_78 , V_25 ) ;
V_79 ++ ;
}
if ( ( ! V_7 -> V_36 . V_37 ) && V_79 ) {
if ( V_7 -> V_36 . V_5 )
F_3 ( V_7 , L_22 ) ;
F_27 ( & V_7 -> V_36 . V_50 , V_51 , NULL ) ;
} else
F_29 ( V_7 , V_77 | V_82 ) ;
}
static void
F_48 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
struct V_23 * V_25 = V_30 ;
int V_79 = 0 ;
F_41 ( & V_7 -> V_36 . V_65 , 51 ) ;
F_45 ( V_75 , V_80 ) ;
while ( ( V_25 = F_47 ( & V_7 -> V_36 . V_47 ) ) ) {
V_7 -> V_36 . V_73 ( V_7 , V_81 | V_78 , V_25 ) ;
V_79 ++ ;
}
if ( ( ! V_7 -> V_36 . V_37 ) && V_79 ) {
if ( V_7 -> V_36 . V_5 )
F_3 ( V_7 , L_23 ) ;
F_27 ( & V_7 -> V_36 . V_50 , V_51 , NULL ) ;
} else
F_29 ( V_7 , V_77 | V_83 ) ;
}
static void
F_49 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
F_45 ( V_75 , V_84 ) ;
F_50 ( & V_7 -> V_36 . V_65 , V_85 , V_86 , NULL , 50 ) ;
}
static void
F_51 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
F_45 ( V_75 , V_84 ) ;
if ( V_7 -> V_48 != V_49 )
F_50 ( & V_7 -> V_36 . V_65 , V_85 , V_86 , NULL , 50 ) ;
}
static void
F_52 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
if ( F_25 ( V_87 , & V_7 -> V_45 . V_46 ) ) {
if ( V_7 -> V_36 . V_5 )
F_3 ( V_7 , L_24 ) ;
F_50 ( & V_7 -> V_36 . V_65 , V_85 , V_86 , NULL , 51 ) ;
} else {
F_45 ( V_75 , V_88 ) ;
V_7 -> V_36 . V_73 ( V_7 , V_89 | V_78 , NULL ) ;
}
}
static void
F_53 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
F_41 ( & V_7 -> V_36 . V_65 , 52 ) ;
F_45 ( V_75 , V_60 ) ;
F_42 ( & V_7 -> V_36 . V_47 ) ;
F_29 ( V_7 , V_89 | V_82 ) ;
}
static void
F_54 ( struct V_74 * V_75 , int V_13 , void * V_30 )
{
struct V_28 * V_7 = V_75 -> V_61 ;
F_45 ( V_75 , V_60 ) ;
F_42 ( & V_7 -> V_36 . V_47 ) ;
F_29 ( V_7 , V_89 | V_83 ) ;
}
void
F_55 ( struct V_28 * V_7 , int V_29 , void * V_30 )
{
switch ( V_29 ) {
case ( V_81 | V_78 ) :
if ( V_7 -> V_36 . V_50 . V_4 == V_80 ) {
V_7 -> V_36 . V_73 ( V_7 , V_29 , V_30 ) ;
} else {
struct V_23 * V_25 = V_30 ;
F_56 ( & V_7 -> V_36 . V_47 , V_25 ) ;
F_27 ( & V_7 -> V_36 . V_50 , V_90 , NULL ) ;
}
break;
case ( V_77 | V_78 ) :
F_27 ( & V_7 -> V_36 . V_50 , V_90 , NULL ) ;
break;
case ( V_77 | V_83 ) :
F_27 ( & V_7 -> V_36 . V_50 , V_91 , NULL ) ;
break;
case ( V_77 | V_82 ) :
F_27 ( & V_7 -> V_36 . V_50 , V_92 , NULL ) ;
break;
case ( V_89 | V_82 ) :
F_27 ( & V_7 -> V_36 . V_50 , V_52 , NULL ) ;
break;
case ( V_89 | V_83 ) :
F_27 ( & V_7 -> V_36 . V_50 , V_93 , NULL ) ;
break;
case ( V_89 | V_78 ) :
F_27 ( & V_7 -> V_36 . V_50 , V_51 , NULL ) ;
break;
}
}
int T_2
F_57 ( void )
{
V_59 . V_94 = V_95 ;
V_59 . V_96 = V_97 ;
V_59 . V_98 = V_99 ;
V_59 . V_100 = V_101 ;
return F_58 ( & V_59 , V_102 , F_59 ( V_102 ) ) ;
}
void
F_60 ( void )
{
F_61 ( & V_59 ) ;
}
