struct V_1 * T_1 F_1 ( int V_2 )
{
struct V_1 * V_3 = F_2 ( sizeof( struct V_4 ) ) ;
static const unsigned V_5 [] = { 0x280 , 0x300 , 0 } ;
const unsigned * V_6 ;
int V_7 = 0 ;
if ( ! V_3 )
return F_3 ( - V_8 ) ;
if ( V_2 >= 0 ) {
sprintf ( V_3 -> V_9 , L_1 , V_2 ) ;
F_4 ( V_3 ) ;
V_10 = V_3 -> V_11 ;
V_12 = V_3 -> V_12 ;
V_13 = V_3 -> V_13 & 7 ;
}
if ( V_10 > 0x1ff ) {
V_7 = F_5 ( V_3 , V_10 ) ;
} else if ( V_10 != 0 ) {
V_7 = - V_14 ;
} else {
for ( V_6 = V_5 ; * V_6 && F_5 ( V_3 , * V_6 ) ; V_6 ++ )
;
if ( ! * V_6 )
V_7 = - V_15 ;
}
if ( V_7 )
goto V_16;
V_7 = F_6 ( V_3 ) ;
if ( V_7 )
goto V_17;
return V_3 ;
V_17:
F_7 ( V_3 -> V_11 , V_18 ) ;
V_16:
F_8 ( V_3 ) ;
return F_3 ( V_7 ) ;
}
static int T_1 F_5 ( struct V_1 * V_3 , int V_19 )
{
struct V_4 * V_20 ;
const char * V_21 ;
unsigned char V_22 [ 6 ] ;
int V_23 = 0 ;
int V_24 ;
if ( ! F_9 ( V_19 , V_18 , V_25 ) )
return - V_15 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
F_10 ( V_24 , V_19 + V_26 ) ;
V_22 [ V_24 ] = F_11 ( V_19 + V_27 ) ;
}
if ( V_22 [ 0 ] == 0x02 && V_22 [ 1 ] == 0x60 &&
V_22 [ 2 ] == 0x8c )
V_21 = L_2 ;
else if ( V_22 [ 0 ] == 0x00 && V_22 [ 1 ] == 0x80 &&
V_22 [ 2 ] == 0xC8 )
V_21 = L_3 ;
else {
F_7 ( V_19 , V_18 ) ;
return - V_15 ;
}
V_3 -> V_12 = V_12 ;
if ( V_3 -> V_12 < 2 ) {
unsigned long V_28 ;
V_28 = F_12 () ;
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
F_13 ( V_31 + 1 , V_32 ) ;
F_13 ( 0x00 , V_32 ) ;
F_14 ( 20 ) ;
V_23 = F_15 ( V_28 ) ;
if ( V_23 == 0 ) {
F_16 ( L_4 ,
V_21 , V_19 ) ;
F_7 ( V_19 , V_18 ) ;
return - V_33 ;
}
}
F_13 ( V_34 + V_31 , V_32 ) ;
V_3 -> V_11 = V_19 ;
memcpy ( V_3 -> V_35 , V_22 , V_36 ) ;
if ( V_13 & 0xf )
V_37 = V_13 & 0x7 ;
if ( V_23 )
V_3 -> V_12 = V_23 ;
F_17 ( L_5 ,
V_3 -> V_9 , V_21 , V_3 -> V_11 ,
V_23 ? L_6 : L_7 , V_3 -> V_12 ) ;
#ifdef F_18
F_16 ( L_8 ) ;
#endif
if ( V_37 )
F_19 ( L_9 , V_38 ) ;
V_20 = F_20 ( V_3 ) ;
memset ( V_20 , 0 , sizeof( struct V_4 ) ) ;
F_21 ( & V_20 -> V_39 ) ;
V_3 -> V_40 = & V_41 ;
V_3 -> V_42 = V_43 ;
V_3 -> V_44 = & V_45 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_3 )
{
int V_46 ;
int V_19 = V_3 -> V_11 ;
struct V_4 * V_20 = F_20 ( V_3 ) ;
unsigned long V_47 ;
if ( V_37 > 2 )
F_19 ( L_10 , V_3 -> V_9 ) ;
V_46 = F_23 ( V_3 -> V_12 , V_48 , 0 , V_3 -> V_9 , V_3 ) ;
if ( V_46 )
return V_46 ;
F_24 ( & V_20 -> V_39 , V_47 ) ;
F_25 ( V_3 ) ;
F_26 ( & V_20 -> V_39 , V_47 ) ;
V_20 -> V_49 = 0 ;
F_13 ( V_50 , V_32 ) ;
F_27 ( V_3 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_3 )
{
struct V_4 * V_20 = F_20 ( V_3 ) ;
int V_19 = V_3 -> V_11 ;
if ( V_37 )
F_19 ( L_11 ,
V_3 -> V_9 , F_11 ( V_30 ) ,
F_11 ( V_51 ) , F_11 ( V_29 ) ) ;
V_3 -> V_52 . V_53 ++ ;
F_13 ( V_54 , V_55 ) ;
F_13 ( V_56 , V_57 ) ;
F_13 ( V_58 , V_32 ) ;
F_13 ( V_50 , V_32 ) ;
V_20 -> V_49 = 0 ;
F_29 ( V_3 ) ;
}
static T_2 F_30 ( struct V_59 * V_60 , struct V_1 * V_3 )
{
struct V_4 * V_20 = F_20 ( V_3 ) ;
int V_19 = V_3 -> V_11 ;
unsigned long V_47 ;
F_24 ( & V_20 -> V_39 , V_47 ) ;
F_31 ( V_3 ) ;
do {
int V_61 = V_60 -> V_61 ;
int V_62 = 0 ;
int V_63 ;
unsigned char * V_64 = V_60 -> V_65 ;
if ( V_61 < V_66 )
V_62 = V_66 - V_61 ;
V_63 = 0x800 - ( V_61 + V_62 ) ;
V_20 -> V_67 = V_63 ;
V_20 -> V_68 = 0 ;
V_3 -> V_52 . V_69 += V_60 -> V_61 ;
F_32 ( V_70 , V_32 ) ;
F_33 ( V_29 ) ;
F_33 ( V_30 ) ;
V_20 -> V_71 = 1 ;
V_20 -> V_49 = 1 ;
F_26 ( & V_20 -> V_39 , V_47 ) ;
F_10 ( 0x00 , V_72 ) ;
F_10 ( V_63 , V_73 ) ;
F_34 ( V_74 , V_64 , V_61 ) ;
if ( V_62 ) {
while ( V_62 -- )
F_13 ( 0 , V_74 ) ;
}
F_10 ( V_63 , V_73 ) ;
if ( V_20 -> V_71 != 2 ) {
F_13 ( V_75 , V_32 ) ;
V_20 -> V_71 = 0 ;
if ( V_37 > 2 )
F_19 ( L_12 ) ;
F_35 ( V_60 ) ;
return V_76 ;
}
if ( V_37 > 2 )
F_19 ( L_13 , V_3 -> V_9 ) ;
F_24 ( & V_20 -> V_39 , V_47 ) ;
} while ( 1 );
}
static T_3 V_48 ( int V_12 , void * V_77 )
{
struct V_1 * V_3 = V_77 ;
struct V_4 * V_20 ;
int V_19 ;
int V_78 ;
V_19 = V_3 -> V_11 ;
V_20 = F_20 ( V_3 ) ;
F_36 ( & V_20 -> V_39 ) ;
V_78 = F_11 ( V_51 ) ;
if ( V_37 > 3 )
F_19 ( L_14 , V_3 -> V_9 , V_78 ) ;
if ( V_20 -> V_71 == 1 && ! V_20 -> V_49 )
F_16 ( L_15 ,
V_3 -> V_9 ) ;
if ( V_20 -> V_49 ) {
int V_79 = F_11 ( V_30 ) ;
if ( V_20 -> V_71 == 1 ) {
if ( V_37 > 2 )
F_19 ( L_16 ,
V_3 -> V_9 , V_79 , F_37 ( V_73 ) , F_37 ( V_80 ) ) ;
V_20 -> V_71 = 2 ;
F_38 ( & V_20 -> V_39 ) ;
goto V_16;
}
if ( V_37 > 6 )
F_19 ( L_17 , V_3 -> V_9 ,
V_79 , F_37 ( V_73 ) , F_37 ( V_80 ) ) ;
if ( ( V_78 & 0x80 ) && ( V_79 & V_81 ) == 0 ) {
if ( V_37 > 1 )
F_19 ( L_18 ,
V_3 -> V_9 , V_79 , V_78 ,
F_37 ( V_19 + V_26 ) ,
F_37 ( V_19 + V_82 ) ) ;
V_20 -> V_49 = 0 ;
F_29 ( V_3 ) ;
} else if ( V_79 & V_83 ) {
if ( V_37 )
F_19 ( L_19 , V_3 -> V_9 ) ;
F_13 ( V_70 , V_32 ) ;
V_20 -> V_49 = 0 ;
V_3 -> V_52 . V_84 ++ ;
F_29 ( V_3 ) ;
} else if ( V_79 & V_85 ) {
if ( V_37 > 6 )
F_19 ( L_20 , V_3 -> V_9 ) ;
F_13 ( V_70 , V_32 ) ;
F_10 ( V_20 -> V_67 , V_73 ) ;
F_13 ( V_75 , V_32 ) ;
V_3 -> V_52 . V_68 ++ ;
F_38 ( & V_20 -> V_39 ) ;
goto V_16;
} else {
V_3 -> V_52 . V_86 ++ ;
if ( V_37 > 6 )
F_19 ( L_21 , V_3 -> V_9 ,
( V_79 & V_87 ) ? L_22 : L_23 ) ;
V_20 -> V_49 = 0 ;
F_29 ( V_3 ) ;
}
} else {
int V_88 = F_11 ( V_29 ) ;
if ( V_37 > 5 )
F_19 ( L_24 ,
V_3 -> V_9 , V_88 , F_11 ( V_30 ) , F_37 ( V_80 ) ) ;
if ( V_88 & V_89 )
V_3 -> V_52 . V_90 ++ ;
else if ( V_88 & V_91 ) {
V_3 -> V_52 . V_92 ++ ;
if ( V_37 > 5 )
F_19 ( L_25 , V_3 -> V_9 ) ;
} else if ( V_88 & V_93 ) {
F_39 ( V_3 ) ;
} else {
if ( V_37 > 2 )
F_19 ( L_26 ,
V_3 -> V_9 , V_88 ) ;
F_25 ( V_3 ) ;
}
}
F_13 ( V_50 , V_32 ) ;
F_10 ( 0x00 , V_72 ) ;
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
F_38 ( & V_20 -> V_39 ) ;
V_16:
return V_94 ;
}
static void F_39 ( struct V_1 * V_3 )
{
int V_19 = V_3 -> V_11 ;
int V_95 ;
struct V_59 * V_60 ;
V_95 = F_37 ( V_80 ) ;
if ( V_37 > 4 )
F_19 ( L_27 , V_95 ) ;
if ( V_95 < 60 || V_95 > 1536 ) {
if ( V_37 )
F_19 ( L_28 ,
V_3 -> V_9 , V_95 ) ;
V_3 -> V_52 . V_96 ++ ;
return;
}
F_13 ( V_70 , V_32 ) ;
V_60 = F_40 ( V_3 , V_95 + 2 ) ;
F_10 ( 0x00 , V_73 ) ;
if ( V_60 == NULL ) {
F_17 ( L_29 , V_3 -> V_9 ) ;
V_3 -> V_52 . V_97 ++ ;
return;
} else {
F_41 ( V_60 , 2 ) ;
F_42 ( V_74 , F_43 ( V_60 , V_95 ) , V_95 ) ;
V_60 -> V_98 = F_44 ( V_60 , V_3 ) ;
F_45 ( V_60 ) ;
V_3 -> V_52 . V_99 ++ ;
V_3 -> V_52 . V_100 += V_95 ;
}
}
static void F_25 ( struct V_1 * V_3 )
{
struct V_4 * V_20 = F_20 ( V_3 ) ;
int V_19 = V_3 -> V_11 ;
if ( V_37 > 2 )
F_17 ( L_30 ) ;
F_13 ( V_34 , V_32 ) ;
F_13 ( V_31 , V_32 ) ;
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ )
F_13 ( V_3 -> V_35 [ V_24 ] , V_19 + V_24 ) ;
}
F_10 ( 0 , V_72 ) ;
F_13 ( V_54 , V_55 ) ;
F_13 ( V_56 , V_57 ) ;
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
V_20 -> V_49 = 0 ;
}
static int F_46 ( struct V_1 * V_3 )
{
int V_19 = V_3 -> V_11 ;
if ( V_37 > 2 )
F_17 ( L_31 ,
V_3 -> V_9 , V_19 ) ;
F_31 ( V_3 ) ;
F_47 ( V_3 -> V_12 , V_3 ) ;
F_13 ( V_34 , V_32 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_3 )
{
int V_19 = V_3 -> V_11 ;
if ( V_3 -> V_47 & V_101 ) {
F_13 ( V_102 , V_57 ) ;
F_11 ( V_29 ) ;
} else if ( ! F_49 ( V_3 ) || V_3 -> V_47 & V_103 ) {
F_13 ( V_104 , V_57 ) ;
F_11 ( V_29 ) ;
} else {
F_13 ( V_56 , V_57 ) ;
F_11 ( V_29 ) ;
}
}
static void F_50 ( struct V_1 * V_3 ,
struct V_105 * V_106 )
{
strcpy ( V_106 -> V_107 , V_25 ) ;
strcpy ( V_106 -> V_38 , V_108 ) ;
sprintf ( V_106 -> V_109 , L_32 , V_3 -> V_11 ) ;
}
static T_4 F_51 ( struct V_1 * V_3 )
{
return V_110 ;
}
static void F_52 ( struct V_1 * V_3 , T_4 V_111 )
{
V_110 = V_111 ;
}
int T_1 F_53 ( void )
{
V_112 = F_1 ( - 1 ) ;
if ( F_54 ( V_112 ) )
return F_55 ( V_112 ) ;
return 0 ;
}
void T_5 F_56 ( void )
{
struct V_1 * V_3 = V_112 ;
F_57 ( V_3 ) ;
F_7 ( V_3 -> V_11 , V_18 ) ;
F_8 ( V_3 ) ;
}
