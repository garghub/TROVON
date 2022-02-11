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
F_3 ( V_3 -> V_7 , L_1 , V_8 ,
V_3 -> V_9 & 0x7F ,
V_3 -> V_4 , V_4 ) ;
V_3 -> V_4 = V_4 ;
}
static void
F_4 ( struct V_10 * V_11 )
{
V_11 -> V_3 -> V_7 -> V_12 . V_13 ( V_11 -> V_3 -> V_7 , V_11 -> V_14 , V_11 -> V_3 ) ;
}
void
F_5 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
V_11 -> V_3 = V_3 ;
V_11 -> V_15 . V_16 = ( void * ) F_4 ;
V_11 -> V_15 . V_17 = ( long ) V_11 ;
F_6 ( & V_11 -> V_15 ) ;
}
void
F_7 ( struct V_10 * V_11 )
{
F_8 ( & V_11 -> V_15 ) ;
}
int
F_9 ( struct V_10 * V_11 ,
int V_18 , int V_14 )
{
if ( F_10 ( & V_11 -> V_15 ) ) {
F_11 ( V_19 L_2 ) ;
return - 1 ;
}
F_6 ( & V_11 -> V_15 ) ;
V_11 -> V_14 = V_14 ;
V_11 -> V_15 . V_20 = V_21 + ( V_18 * V_22 ) / 1000 ;
F_12 ( & V_11 -> V_15 ) ;
return 0 ;
}
void
F_13 ( struct V_2 * V_3 )
{
F_7 ( & V_3 -> V_23 ) ;
}
struct V_24 *
F_14 ( int V_25 )
{
struct V_24 * V_26 ;
if ( ! ( V_26 = F_15 ( V_25 + V_27 , V_28 ) ) ) {
F_11 ( V_19 L_3 ) ;
return ( NULL ) ;
}
F_16 ( V_26 , V_27 ) ;
return ( V_26 ) ;
}
static void
F_17 ( struct V_29 * V_7 , int V_30 , void * V_31 )
{
struct V_24 * V_26 = V_31 ;
F_18 ( V_7 -> V_32 . V_33 , L_4 , L_5 ) ;
if ( V_26 ) {
F_19 ( V_26 ) ;
}
}
static int
F_20 ( struct V_29 * V_7 , T_1 * V_34 )
{
F_11 ( V_19 L_6 , V_34 -> V_31 & 0xFF ) ;
return ( - 1 ) ;
}
struct V_2
* F_21 ( struct V_29 * V_7 , int V_35 )
{
struct V_2 * V_36 = V_7 -> V_37 . V_38 ;
while ( V_36 )
if ( V_36 -> V_9 == V_35 )
return ( V_36 ) ;
else
V_36 = V_36 -> V_39 ;
return ( NULL ) ;
}
struct V_2
* F_22 ( struct V_29 * V_7 , int V_35 )
{
struct V_2 * V_36 , * V_40 ;
if ( ! ( V_36 = F_23 ( sizeof( struct V_2 ) , V_28 ) ) ) {
F_11 ( V_41 L_7 , V_35 ) ;
return ( NULL ) ;
}
if ( ! V_7 -> V_37 . V_38 )
V_7 -> V_37 . V_38 = V_36 ;
else {
V_40 = V_7 -> V_37 . V_38 ;
while ( V_40 -> V_39 )
V_40 = V_40 -> V_39 ;
V_40 -> V_39 = V_36 ;
}
V_36 -> V_39 = NULL ;
V_36 -> V_5 = V_7 -> V_37 . V_5 ;
V_36 -> V_9 = V_35 ;
V_36 -> V_4 = 0 ;
V_36 -> V_42 = NULL ;
V_36 -> V_7 = V_7 ;
V_36 -> V_43 = V_7 -> V_37 . V_43 ;
F_5 ( V_36 , & V_36 -> V_23 ) ;
return ( V_36 ) ;
}
void
F_24 ( struct V_2 * V_36 )
{
struct V_2 * V_40 , * V_44 = NULL ;
if ( ! V_36 )
return;
V_40 = V_36 -> V_7 -> V_37 . V_38 ;
while ( V_40 ) {
if ( V_40 == V_36 ) {
F_13 ( V_36 ) ;
if ( V_44 )
V_44 -> V_39 = V_40 -> V_39 ;
else if ( ! ( V_36 -> V_7 -> V_37 . V_38 = V_40 -> V_39 ) &&
! F_25 ( V_45 , & V_36 -> V_7 -> V_46 . V_47 ) ) {
if ( V_36 -> V_5 )
F_3 ( V_36 -> V_7 , L_8 ) ;
if ( F_26 ( & V_36 -> V_7 -> V_37 . V_48 ) ) {
if ( V_36 -> V_5 )
F_3 ( V_36 -> V_7 , L_9 ) ;
if ( V_36 -> V_7 -> V_49 != V_50 )
F_27 ( & V_36 -> V_7 -> V_37 . V_51 , V_52 , NULL ) ;
else
F_27 ( & V_36 -> V_7 -> V_37 . V_51 , V_53 , NULL ) ;
} else {
if ( V_36 -> V_5 )
F_3 ( V_36 -> V_7 , L_10 ) ;
}
}
F_28 ( V_36 ) ;
return;
}
V_44 = V_40 ;
V_40 = V_40 -> V_39 ;
}
F_11 ( V_41 L_11 , V_36 -> V_9 ) ;
F_3 ( V_36 -> V_7 , L_12 , V_36 -> V_9 ) ;
}
static void
F_29 ( struct V_29 * V_7 , int V_30 )
{
struct V_2 * V_36 = V_7 -> V_37 . V_38 ;
struct V_2 * V_40 ;
while ( V_36 ) {
V_40 = V_36 -> V_39 ;
V_7 -> V_37 . V_54 ( V_7 , V_30 , V_36 ) ;
V_36 = V_40 ;
}
}
void
F_30 ( struct V_29 * V_7 , struct V_55 * V_56 )
{
char V_57 [ 64 ] ;
V_7 -> V_37 . V_38 = NULL ;
V_7 -> V_37 . V_58 = NULL ;
F_31 ( & V_7 -> V_37 . V_48 ) ;
V_7 -> V_37 . V_51 . V_59 = & V_60 ;
V_7 -> V_37 . V_51 . V_4 = V_61 ;
V_7 -> V_37 . V_51 . V_5 = 1 ;
V_7 -> V_37 . V_51 . V_62 = V_7 ;
V_7 -> V_37 . V_51 . V_63 = 0 ;
V_7 -> V_37 . V_51 . V_64 = V_65 ;
F_32 ( & V_7 -> V_37 . V_51 , & V_7 -> V_37 . V_66 ) ;
strcpy ( V_7 -> V_37 . V_67 , L_13 ) ;
V_7 -> V_12 . V_68 = F_20 ;
#ifdef F_33
if ( V_7 -> V_49 == V_69 ) {
F_34 ( V_7 ) ;
} else
#endif
#ifdef F_35
if ( V_7 -> V_49 == V_50 ) {
F_36 ( V_7 ) ;
} else
#endif
#ifdef F_37
if ( V_7 -> V_49 == V_70 ) {
F_38 ( V_7 ) ;
} else
#endif
if ( V_7 -> V_49 == V_71 ) {
V_7 -> V_12 . V_13 = F_17 ;
V_7 -> V_46 . V_72 = F_17 ;
V_7 -> V_37 . V_54 = F_17 ;
F_11 ( V_73 L_14 ) ;
} else {
V_7 -> V_12 . V_13 = F_17 ;
V_7 -> V_46 . V_72 = F_17 ;
V_7 -> V_37 . V_54 = F_17 ;
sprintf ( V_57 , L_15 ,
( V_7 -> V_49 == V_70 ) ? L_16 :
( V_7 -> V_49 == V_69 ) ? L_17 :
( V_7 -> V_49 == V_50 ) ? L_18 :
L_19 ) ;
F_11 ( V_19 L_20 , V_57 ) ;
V_7 -> V_49 = - 1 ;
}
}
static void
F_39 ( struct V_29 * V_7 , int V_30 , void * V_31 ) {
V_7 -> V_37 . V_74 ( V_7 , V_30 , V_31 ) ;
}
void
F_40 ( struct V_29 * V_7 )
{
while ( V_7 -> V_37 . V_38 )
F_24 ( V_7 -> V_37 . V_38 ) ;
if ( V_7 -> V_37 . V_58 ) {
F_13 ( V_7 -> V_37 . V_58 ) ;
F_28 ( V_7 -> V_37 . V_58 ) ;
V_7 -> V_37 . V_58 = NULL ;
}
F_41 ( & V_7 -> V_37 . V_66 , 54 ) ;
F_42 ( & V_7 -> V_37 . V_48 ) ;
}
void
F_43 ( struct V_29 * V_7 , struct V_55 * V_56 )
{
V_7 -> V_37 . V_38 = NULL ;
V_7 -> V_37 . V_58 = NULL ;
F_31 ( & V_7 -> V_37 . V_48 ) ;
V_7 -> V_37 . V_51 . V_59 = & V_60 ;
V_7 -> V_37 . V_51 . V_4 = V_61 ;
V_7 -> V_37 . V_51 . V_5 = 1 ;
V_7 -> V_37 . V_51 . V_62 = V_7 ;
V_7 -> V_37 . V_51 . V_63 = 0 ;
V_7 -> V_37 . V_51 . V_64 = V_65 ;
strcpy ( V_7 -> V_37 . V_67 , L_21 ) ;
V_7 -> V_12 . V_13 = F_39 ;
}
static void
F_44 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
F_45 ( V_76 , V_77 ) ;
V_7 -> V_37 . V_74 ( V_7 , V_78 | V_79 , NULL ) ;
}
static void
F_46 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
struct V_24 * V_26 = V_31 ;
int V_80 = 0 ;
F_45 ( V_76 , V_81 ) ;
while ( ( V_26 = F_47 ( & V_7 -> V_37 . V_48 ) ) ) {
V_7 -> V_37 . V_74 ( V_7 , V_82 | V_79 , V_26 ) ;
V_80 ++ ;
}
if ( ( ! V_7 -> V_37 . V_38 ) && V_80 ) {
if ( V_7 -> V_37 . V_5 )
F_3 ( V_7 , L_22 ) ;
F_27 ( & V_7 -> V_37 . V_51 , V_52 , NULL ) ;
} else
F_29 ( V_7 , V_78 | V_83 ) ;
}
static void
F_48 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
struct V_24 * V_26 = V_31 ;
int V_80 = 0 ;
F_41 ( & V_7 -> V_37 . V_66 , 51 ) ;
F_45 ( V_76 , V_81 ) ;
while ( ( V_26 = F_47 ( & V_7 -> V_37 . V_48 ) ) ) {
V_7 -> V_37 . V_74 ( V_7 , V_82 | V_79 , V_26 ) ;
V_80 ++ ;
}
if ( ( ! V_7 -> V_37 . V_38 ) && V_80 ) {
if ( V_7 -> V_37 . V_5 )
F_3 ( V_7 , L_23 ) ;
F_27 ( & V_7 -> V_37 . V_51 , V_52 , NULL ) ;
} else
F_29 ( V_7 , V_78 | V_84 ) ;
}
static void
F_49 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
F_45 ( V_76 , V_85 ) ;
F_50 ( & V_7 -> V_37 . V_66 , V_86 , V_87 , NULL , 50 ) ;
}
static void
F_51 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
F_45 ( V_76 , V_85 ) ;
if ( V_7 -> V_49 != V_50 )
F_50 ( & V_7 -> V_37 . V_66 , V_86 , V_87 , NULL , 50 ) ;
}
static void
F_52 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
if ( F_25 ( V_88 , & V_7 -> V_46 . V_47 ) ) {
if ( V_7 -> V_37 . V_5 )
F_3 ( V_7 , L_24 ) ;
F_50 ( & V_7 -> V_37 . V_66 , V_86 , V_87 , NULL , 51 ) ;
} else {
F_45 ( V_76 , V_89 ) ;
V_7 -> V_37 . V_74 ( V_7 , V_90 | V_79 , NULL ) ;
}
}
static void
F_53 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
F_41 ( & V_7 -> V_37 . V_66 , 52 ) ;
F_45 ( V_76 , V_61 ) ;
F_42 ( & V_7 -> V_37 . V_48 ) ;
F_29 ( V_7 , V_90 | V_83 ) ;
}
static void
F_54 ( struct V_75 * V_76 , int V_14 , void * V_31 )
{
struct V_29 * V_7 = V_76 -> V_62 ;
F_45 ( V_76 , V_61 ) ;
F_42 ( & V_7 -> V_37 . V_48 ) ;
F_29 ( V_7 , V_90 | V_84 ) ;
}
void
F_55 ( struct V_29 * V_7 , int V_30 , void * V_31 )
{
switch ( V_30 ) {
case ( V_82 | V_79 ) :
if ( V_7 -> V_37 . V_51 . V_4 == V_81 ) {
V_7 -> V_37 . V_74 ( V_7 , V_30 , V_31 ) ;
} else {
struct V_24 * V_26 = V_31 ;
F_56 ( & V_7 -> V_37 . V_48 , V_26 ) ;
F_27 ( & V_7 -> V_37 . V_51 , V_91 , NULL ) ;
}
break;
case ( V_78 | V_79 ) :
F_27 ( & V_7 -> V_37 . V_51 , V_91 , NULL ) ;
break;
case ( V_78 | V_84 ) :
F_27 ( & V_7 -> V_37 . V_51 , V_92 , NULL ) ;
break;
case ( V_78 | V_83 ) :
F_27 ( & V_7 -> V_37 . V_51 , V_93 , NULL ) ;
break;
case ( V_90 | V_83 ) :
F_27 ( & V_7 -> V_37 . V_51 , V_53 , NULL ) ;
break;
case ( V_90 | V_84 ) :
F_27 ( & V_7 -> V_37 . V_51 , V_94 , NULL ) ;
break;
case ( V_90 | V_79 ) :
F_27 ( & V_7 -> V_37 . V_51 , V_52 , NULL ) ;
break;
}
}
int T_2
F_57 ( void )
{
V_60 . V_95 = V_96 ;
V_60 . V_97 = V_98 ;
V_60 . V_99 = V_100 ;
V_60 . V_101 = V_102 ;
return F_58 ( & V_60 , V_103 , F_59 ( V_103 ) ) ;
}
void
F_60 ( void )
{
F_61 ( & V_60 ) ;
}
