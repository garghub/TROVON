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
F_6 ( & V_11 -> V_15 , ( void * ) F_4 , ( long ) V_11 ) ;
}
void
F_7 ( struct V_10 * V_11 )
{
F_8 ( & V_11 -> V_15 ) ;
}
int
F_9 ( struct V_10 * V_11 ,
int V_16 , int V_14 )
{
if ( F_10 ( & V_11 -> V_15 ) ) {
F_11 ( V_17 L_2 ) ;
return - 1 ;
}
F_12 ( & V_11 -> V_15 ) ;
V_11 -> V_14 = V_14 ;
V_11 -> V_15 . V_18 = V_19 + ( V_16 * V_20 ) / 1000 ;
F_13 ( & V_11 -> V_15 ) ;
return 0 ;
}
void
F_14 ( struct V_2 * V_3 )
{
F_7 ( & V_3 -> V_21 ) ;
}
struct V_22 *
F_15 ( int V_23 )
{
struct V_22 * V_24 ;
if ( ! ( V_24 = F_16 ( V_23 + V_25 , V_26 ) ) ) {
F_11 ( V_17 L_3 ) ;
return ( NULL ) ;
}
F_17 ( V_24 , V_25 ) ;
return ( V_24 ) ;
}
static void
F_18 ( struct V_27 * V_7 , int V_28 , void * V_29 )
{
struct V_22 * V_24 = V_29 ;
F_19 ( V_7 -> V_30 . V_31 , L_4 , L_5 ) ;
if ( V_24 ) {
F_20 ( V_24 ) ;
}
}
static int
F_21 ( struct V_27 * V_7 , T_1 * V_32 )
{
F_11 ( V_17 L_6 , V_32 -> V_29 & 0xFF ) ;
return ( - 1 ) ;
}
struct V_2
* F_22 ( struct V_27 * V_7 , int V_33 )
{
struct V_2 * V_34 = V_7 -> V_35 . V_36 ;
while ( V_34 )
if ( V_34 -> V_9 == V_33 )
return ( V_34 ) ;
else
V_34 = V_34 -> V_37 ;
return ( NULL ) ;
}
struct V_2
* F_23 ( struct V_27 * V_7 , int V_33 )
{
struct V_2 * V_34 , * V_38 ;
if ( ! ( V_34 = F_24 ( sizeof( struct V_2 ) , V_26 ) ) ) {
F_11 ( V_39 L_7 , V_33 ) ;
return ( NULL ) ;
}
if ( ! V_7 -> V_35 . V_36 )
V_7 -> V_35 . V_36 = V_34 ;
else {
V_38 = V_7 -> V_35 . V_36 ;
while ( V_38 -> V_37 )
V_38 = V_38 -> V_37 ;
V_38 -> V_37 = V_34 ;
}
V_34 -> V_37 = NULL ;
V_34 -> V_5 = V_7 -> V_35 . V_5 ;
V_34 -> V_9 = V_33 ;
V_34 -> V_4 = 0 ;
V_34 -> V_40 = NULL ;
V_34 -> V_7 = V_7 ;
V_34 -> V_41 = V_7 -> V_35 . V_41 ;
F_5 ( V_34 , & V_34 -> V_21 ) ;
return ( V_34 ) ;
}
void
F_25 ( struct V_2 * V_34 )
{
struct V_2 * V_38 , * V_42 = NULL ;
if ( ! V_34 )
return;
V_38 = V_34 -> V_7 -> V_35 . V_36 ;
while ( V_38 ) {
if ( V_38 == V_34 ) {
F_14 ( V_34 ) ;
if ( V_42 )
V_42 -> V_37 = V_38 -> V_37 ;
else if ( ! ( V_34 -> V_7 -> V_35 . V_36 = V_38 -> V_37 ) &&
! F_26 ( V_43 , & V_34 -> V_7 -> V_44 . V_45 ) ) {
if ( V_34 -> V_5 )
F_3 ( V_34 -> V_7 , L_8 ) ;
if ( F_27 ( & V_34 -> V_7 -> V_35 . V_46 ) ) {
if ( V_34 -> V_5 )
F_3 ( V_34 -> V_7 , L_9 ) ;
if ( V_34 -> V_7 -> V_47 != V_48 )
F_28 ( & V_34 -> V_7 -> V_35 . V_49 , V_50 , NULL ) ;
else
F_28 ( & V_34 -> V_7 -> V_35 . V_49 , V_51 , NULL ) ;
} else {
if ( V_34 -> V_5 )
F_3 ( V_34 -> V_7 , L_10 ) ;
}
}
F_29 ( V_34 ) ;
return;
}
V_42 = V_38 ;
V_38 = V_38 -> V_37 ;
}
F_11 ( V_39 L_11 , V_34 -> V_9 ) ;
F_3 ( V_34 -> V_7 , L_12 , V_34 -> V_9 ) ;
}
static void
F_30 ( struct V_27 * V_7 , int V_28 )
{
struct V_2 * V_34 = V_7 -> V_35 . V_36 ;
struct V_2 * V_38 ;
while ( V_34 ) {
V_38 = V_34 -> V_37 ;
V_7 -> V_35 . V_52 ( V_7 , V_28 , V_34 ) ;
V_34 = V_38 ;
}
}
void
F_31 ( struct V_27 * V_7 , struct V_53 * V_54 )
{
char V_55 [ 64 ] ;
V_7 -> V_35 . V_36 = NULL ;
V_7 -> V_35 . V_56 = NULL ;
F_32 ( & V_7 -> V_35 . V_46 ) ;
V_7 -> V_35 . V_49 . V_57 = & V_58 ;
V_7 -> V_35 . V_49 . V_4 = V_59 ;
V_7 -> V_35 . V_49 . V_5 = 1 ;
V_7 -> V_35 . V_49 . V_60 = V_7 ;
V_7 -> V_35 . V_49 . V_61 = 0 ;
V_7 -> V_35 . V_49 . V_62 = V_63 ;
F_33 ( & V_7 -> V_35 . V_49 , & V_7 -> V_35 . V_64 ) ;
strcpy ( V_7 -> V_35 . V_65 , L_13 ) ;
V_7 -> V_12 . V_66 = F_21 ;
#ifdef F_34
if ( V_7 -> V_47 == V_67 ) {
F_35 ( V_7 ) ;
} else
#endif
#ifdef F_36
if ( V_7 -> V_47 == V_48 ) {
F_37 ( V_7 ) ;
} else
#endif
#ifdef F_38
if ( V_7 -> V_47 == V_68 ) {
F_39 ( V_7 ) ;
} else
#endif
if ( V_7 -> V_47 == V_69 ) {
V_7 -> V_12 . V_13 = F_18 ;
V_7 -> V_44 . V_70 = F_18 ;
V_7 -> V_35 . V_52 = F_18 ;
F_11 ( V_71 L_14 ) ;
} else {
V_7 -> V_12 . V_13 = F_18 ;
V_7 -> V_44 . V_70 = F_18 ;
V_7 -> V_35 . V_52 = F_18 ;
sprintf ( V_55 , L_15 ,
( V_7 -> V_47 == V_68 ) ? L_16 :
( V_7 -> V_47 == V_67 ) ? L_17 :
( V_7 -> V_47 == V_48 ) ? L_18 :
L_19 ) ;
F_11 ( V_17 L_20 , V_55 ) ;
V_7 -> V_47 = - 1 ;
}
}
static void
F_40 ( struct V_27 * V_7 , int V_28 , void * V_29 ) {
V_7 -> V_35 . V_72 ( V_7 , V_28 , V_29 ) ;
}
void
F_41 ( struct V_27 * V_7 )
{
while ( V_7 -> V_35 . V_36 )
F_25 ( V_7 -> V_35 . V_36 ) ;
if ( V_7 -> V_35 . V_56 ) {
F_14 ( V_7 -> V_35 . V_56 ) ;
F_29 ( V_7 -> V_35 . V_56 ) ;
V_7 -> V_35 . V_56 = NULL ;
}
F_42 ( & V_7 -> V_35 . V_64 , 54 ) ;
F_43 ( & V_7 -> V_35 . V_46 ) ;
}
void
F_44 ( struct V_27 * V_7 , struct V_53 * V_54 )
{
V_7 -> V_35 . V_36 = NULL ;
V_7 -> V_35 . V_56 = NULL ;
F_32 ( & V_7 -> V_35 . V_46 ) ;
V_7 -> V_35 . V_49 . V_57 = & V_58 ;
V_7 -> V_35 . V_49 . V_4 = V_59 ;
V_7 -> V_35 . V_49 . V_5 = 1 ;
V_7 -> V_35 . V_49 . V_60 = V_7 ;
V_7 -> V_35 . V_49 . V_61 = 0 ;
V_7 -> V_35 . V_49 . V_62 = V_63 ;
strcpy ( V_7 -> V_35 . V_65 , L_21 ) ;
V_7 -> V_12 . V_13 = F_40 ;
}
static void
F_45 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
F_46 ( V_74 , V_75 ) ;
V_7 -> V_35 . V_72 ( V_7 , V_76 | V_77 , NULL ) ;
}
static void
F_47 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
struct V_22 * V_24 = V_29 ;
int V_78 = 0 ;
F_46 ( V_74 , V_79 ) ;
while ( ( V_24 = F_48 ( & V_7 -> V_35 . V_46 ) ) ) {
V_7 -> V_35 . V_72 ( V_7 , V_80 | V_77 , V_24 ) ;
V_78 ++ ;
}
if ( ( ! V_7 -> V_35 . V_36 ) && V_78 ) {
if ( V_7 -> V_35 . V_5 )
F_3 ( V_7 , L_22 ) ;
F_28 ( & V_7 -> V_35 . V_49 , V_50 , NULL ) ;
} else
F_30 ( V_7 , V_76 | V_81 ) ;
}
static void
F_49 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
struct V_22 * V_24 = V_29 ;
int V_78 = 0 ;
F_42 ( & V_7 -> V_35 . V_64 , 51 ) ;
F_46 ( V_74 , V_79 ) ;
while ( ( V_24 = F_48 ( & V_7 -> V_35 . V_46 ) ) ) {
V_7 -> V_35 . V_72 ( V_7 , V_80 | V_77 , V_24 ) ;
V_78 ++ ;
}
if ( ( ! V_7 -> V_35 . V_36 ) && V_78 ) {
if ( V_7 -> V_35 . V_5 )
F_3 ( V_7 , L_23 ) ;
F_28 ( & V_7 -> V_35 . V_49 , V_50 , NULL ) ;
} else
F_30 ( V_7 , V_76 | V_82 ) ;
}
static void
F_50 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
F_46 ( V_74 , V_83 ) ;
F_51 ( & V_7 -> V_35 . V_64 , V_84 , V_85 , NULL , 50 ) ;
}
static void
F_52 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
F_46 ( V_74 , V_83 ) ;
if ( V_7 -> V_47 != V_48 )
F_51 ( & V_7 -> V_35 . V_64 , V_84 , V_85 , NULL , 50 ) ;
}
static void
F_53 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
if ( F_26 ( V_86 , & V_7 -> V_44 . V_45 ) ) {
if ( V_7 -> V_35 . V_5 )
F_3 ( V_7 , L_24 ) ;
F_51 ( & V_7 -> V_35 . V_64 , V_84 , V_85 , NULL , 51 ) ;
} else {
F_46 ( V_74 , V_87 ) ;
V_7 -> V_35 . V_72 ( V_7 , V_88 | V_77 , NULL ) ;
}
}
static void
F_54 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
F_42 ( & V_7 -> V_35 . V_64 , 52 ) ;
F_46 ( V_74 , V_59 ) ;
F_43 ( & V_7 -> V_35 . V_46 ) ;
F_30 ( V_7 , V_88 | V_81 ) ;
}
static void
F_55 ( struct V_73 * V_74 , int V_14 , void * V_29 )
{
struct V_27 * V_7 = V_74 -> V_60 ;
F_46 ( V_74 , V_59 ) ;
F_43 ( & V_7 -> V_35 . V_46 ) ;
F_30 ( V_7 , V_88 | V_82 ) ;
}
void
F_56 ( struct V_27 * V_7 , int V_28 , void * V_29 )
{
switch ( V_28 ) {
case ( V_80 | V_77 ) :
if ( V_7 -> V_35 . V_49 . V_4 == V_79 ) {
V_7 -> V_35 . V_72 ( V_7 , V_28 , V_29 ) ;
} else {
struct V_22 * V_24 = V_29 ;
F_57 ( & V_7 -> V_35 . V_46 , V_24 ) ;
F_28 ( & V_7 -> V_35 . V_49 , V_89 , NULL ) ;
}
break;
case ( V_76 | V_77 ) :
F_28 ( & V_7 -> V_35 . V_49 , V_89 , NULL ) ;
break;
case ( V_76 | V_82 ) :
F_28 ( & V_7 -> V_35 . V_49 , V_90 , NULL ) ;
break;
case ( V_76 | V_81 ) :
F_28 ( & V_7 -> V_35 . V_49 , V_91 , NULL ) ;
break;
case ( V_88 | V_81 ) :
F_28 ( & V_7 -> V_35 . V_49 , V_51 , NULL ) ;
break;
case ( V_88 | V_82 ) :
F_28 ( & V_7 -> V_35 . V_49 , V_92 , NULL ) ;
break;
case ( V_88 | V_77 ) :
F_28 ( & V_7 -> V_35 . V_49 , V_50 , NULL ) ;
break;
}
}
int T_2
F_58 ( void )
{
V_58 . V_93 = V_94 ;
V_58 . V_95 = V_96 ;
V_58 . V_97 = V_98 ;
V_58 . V_99 = V_100 ;
return F_59 ( & V_58 , V_101 , F_60 ( V_101 ) ) ;
}
void
F_61 ( void )
{
F_62 ( & V_58 ) ;
}
