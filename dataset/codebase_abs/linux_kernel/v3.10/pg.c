static void F_1 ( void )
{
int V_1 ;
V_2 = 0 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
int * V_4 = * V_5 [ V_1 ] ;
struct V_6 * V_7 = & V_8 [ V_1 ] ;
V_7 -> V_9 = & V_7 -> V_10 ;
F_2 ( 0 , & V_7 -> V_11 ) ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = V_4 [ V_16 ] ;
snprintf ( V_7 -> V_17 , V_18 , L_1 , V_17 , 'a' + V_1 ) ;
if ( V_4 [ V_19 ] )
V_2 ++ ;
}
}
static inline int F_3 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_9 , 1 , 6 ) ;
}
static inline int F_5 ( struct V_6 * V_7 , int V_20 )
{
return F_4 ( V_7 -> V_9 , 0 , V_20 ) ;
}
static inline void F_6 ( struct V_6 * V_7 , int V_20 , int V_21 )
{
F_7 ( V_7 -> V_9 , 0 , V_20 , V_21 ) ;
}
static inline T_1 F_8 ( struct V_6 * V_7 )
{
return 0xa0 + 0x10 * V_7 -> V_15 ;
}
static void F_9 ( int V_22 )
{
F_10 ( V_22 ) ;
}
static int F_11 ( struct V_6 * V_7 , int V_23 , int V_24 , unsigned long V_25 , char * V_26 )
{
int V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ;
V_7 -> V_33 = 0 ;
V_27 = 0 ;
while ( ( ( ( V_28 = F_3 ( V_7 ) ) & V_23 ) || ( V_24 && ( ! ( V_28 & V_24 ) ) ) )
&& F_12 ( V_34 , V_25 ) ) {
if ( V_27 ++ < V_35 )
F_13 ( V_36 ) ;
else
F_9 ( 1 ) ;
}
V_32 = F_14 ( V_34 , V_25 ) ;
if ( ( V_28 & ( V_37 & V_24 ) ) || V_32 ) {
V_30 = F_5 ( V_7 , 7 ) ;
V_29 = F_5 ( V_7 , 1 ) ;
V_31 = F_5 ( V_7 , 2 ) ;
if ( V_38 > 1 )
F_15 ( L_2 ,
V_7 -> V_17 , V_26 , V_30 , V_29 , V_31 , V_32 ? L_3 : L_4 ) ;
if ( V_32 )
V_29 |= 0x100 ;
V_7 -> V_33 = ( V_29 >> 4 ) & 0xff ;
return - 1 ;
}
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , char * V_39 , int V_40 , unsigned long V_25 )
{
int V_41 ;
F_17 ( V_7 -> V_9 ) ;
F_6 ( V_7 , 6 , F_8 ( V_7 ) ) ;
if ( F_11 ( V_7 , V_42 | V_43 , 0 , V_25 , L_5 ) )
goto V_44;
F_6 ( V_7 , 4 , V_40 % 256 ) ;
F_6 ( V_7 , 5 , V_40 / 256 ) ;
F_6 ( V_7 , 7 , 0xa0 ) ;
if ( F_11 ( V_7 , V_42 , V_43 , V_25 , L_6 ) )
goto V_44;
if ( F_5 ( V_7 , 2 ) != 1 ) {
F_15 ( L_7 , V_7 -> V_17 ) ;
goto V_44;
}
F_18 ( V_7 -> V_9 , V_39 , 12 ) ;
if ( V_38 > 1 ) {
F_15 ( L_8 , V_7 -> V_17 , V_40 ) ;
for ( V_41 = 0 ; V_41 < 12 ; V_41 ++ )
F_15 ( L_9 , V_39 [ V_41 ] & 0xff ) ;
F_15 ( L_10 ) ;
}
return 0 ;
V_44:
F_19 ( V_7 -> V_9 ) ;
return - 1 ;
}
static int F_20 ( struct V_6 * V_7 , char * V_45 , unsigned long V_25 )
{
int V_28 , V_46 , V_47 , V_31 ;
V_28 = F_11 ( V_7 , V_42 , V_43 | V_48 | V_37 ,
V_25 , L_11 ) ;
V_7 -> V_40 = 0 ;
while ( F_5 ( V_7 , 7 ) & V_43 ) {
V_46 = ( F_5 ( V_7 , 4 ) + 256 * F_5 ( V_7 , 5 ) ) ;
V_47 = ( ( V_46 + 3 ) & 0xfffc ) ;
V_31 = F_5 ( V_7 , 2 ) & 3 ;
if ( V_31 == 0 )
F_18 ( V_7 -> V_9 , V_45 , V_47 ) ;
if ( V_31 == 2 )
F_21 ( V_7 -> V_9 , V_45 , V_47 ) ;
if ( V_38 > 1 )
F_15 ( L_12 , V_7 -> V_17 ,
V_31 ? L_13 : L_14 , V_47 ) ;
V_7 -> V_40 += ( 1 - V_31 ) * V_46 ;
V_45 += V_46 ;
V_28 = F_11 ( V_7 , V_42 , V_43 | V_48 | V_37 ,
V_25 , L_11 ) ;
}
F_19 ( V_7 -> V_9 ) ;
return V_28 ;
}
static int F_22 ( struct V_6 * V_7 )
{
int V_49 , V_41 , V_50 ;
int V_51 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
int V_52 [ 5 ] ;
F_17 ( V_7 -> V_9 ) ;
F_6 ( V_7 , 6 , F_8 ( V_7 ) ) ;
F_6 ( V_7 , 7 , 8 ) ;
F_9 ( 20 * V_53 / 1000 ) ;
V_41 = 0 ;
while ( ( V_41 ++ < V_54 ) && ( F_3 ( V_7 ) & V_42 ) )
F_9 ( 1 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ )
V_52 [ V_49 ] = F_5 ( V_7 , V_49 + 1 ) ;
V_50 = memcmp ( V_51 , V_52 , sizeof( V_52 ) ) ? - 1 : 0 ;
if ( V_38 ) {
F_15 ( L_15 , V_7 -> V_17 , V_41 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ )
F_15 ( L_16 , V_52 [ V_49 ] ) ;
if ( V_50 )
F_15 ( L_17 ) ;
F_15 ( L_10 ) ;
}
F_19 ( V_7 -> V_9 ) ;
return V_50 ;
}
static void F_23 ( char * V_45 , char * V_55 , int V_56 )
{
char V_57 = '\0' ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_56 ; V_41 ++ ) {
char V_58 = * V_45 ++ ;
if ( V_58 != ' ' && V_58 != V_57 )
V_57 = * V_55 ++ = V_58 ;
}
if ( V_57 == ' ' )
V_55 -- ;
* V_55 = '\0' ;
}
static int F_24 ( struct V_6 * V_7 , int log )
{
int V_30 ;
char * V_59 [ 2 ] = { L_18 , L_19 } ;
char V_60 [ 10 ] , V_61 [ 18 ] ;
char V_62 [ 12 ] = { V_63 , 0 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_45 [ 36 ] ;
V_30 = F_16 ( V_7 , V_62 , 36 , V_34 + V_64 ) ;
if ( V_30 )
return - 1 ;
V_30 = F_20 ( V_7 , V_45 , V_34 + V_64 ) ;
if ( V_30 )
return - 1 ;
if ( log ) {
F_23 ( V_45 + 8 , V_60 , 8 ) ;
F_23 ( V_45 + 16 , V_61 , 16 ) ;
F_15 ( L_20 , V_7 -> V_17 , V_60 , V_61 , V_59 [ V_7 -> V_15 ] ) ;
}
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
if ( V_7 -> V_15 == - 1 ) {
for ( V_7 -> V_15 = 0 ; V_7 -> V_15 <= 1 ; V_7 -> V_15 ++ )
if ( ! F_22 ( V_7 ) )
return F_24 ( V_7 , 1 ) ;
} else {
if ( ! F_22 ( V_7 ) )
return F_24 ( V_7 , 1 ) ;
}
return - 1 ;
}
static int F_26 ( void )
{
struct V_6 * V_7 = & V_8 [ 0 ] ;
int V_41 , V_1 ;
F_15 ( L_21 , V_17 , V_17 , V_65 , V_66 ) ;
V_41 = 0 ;
if ( V_2 == 0 ) {
if ( F_27 ( V_7 -> V_9 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_67 ,
V_68 , V_38 , V_7 -> V_17 ) ) {
if ( ! F_25 ( V_7 ) ) {
V_7 -> V_13 = 1 ;
V_41 ++ ;
} else
F_28 ( V_7 -> V_9 ) ;
}
} else
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ , V_7 ++ ) {
int * V_4 = * V_5 [ V_1 ] ;
if ( ! V_4 [ V_19 ] )
continue;
if ( F_27 ( V_7 -> V_9 , 0 , V_4 [ V_19 ] , V_4 [ V_69 ] ,
V_4 [ V_70 ] , V_4 [ V_71 ] , V_4 [ V_72 ] ,
V_67 , V_68 , V_38 , V_7 -> V_17 ) ) {
if ( ! F_25 ( V_7 ) ) {
V_7 -> V_13 = 1 ;
V_41 ++ ;
} else
F_28 ( V_7 -> V_9 ) ;
}
}
if ( V_41 )
return 0 ;
F_15 ( L_22 , V_17 ) ;
return - 1 ;
}
static int F_29 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
int V_1 = F_30 ( V_73 ) & 0x7f ;
struct V_6 * V_7 = & V_8 [ V_1 ] ;
int V_75 = 0 ;
F_31 ( & V_76 ) ;
if ( ( V_1 >= V_3 ) || ( ! V_7 -> V_13 ) ) {
V_75 = - V_77 ;
goto V_78;
}
if ( F_32 ( 0 , & V_7 -> V_11 ) ) {
V_75 = - V_79 ;
goto V_78;
}
if ( V_7 -> V_12 ) {
F_22 ( V_7 ) ;
V_7 -> V_12 = 0 ;
}
F_24 ( V_7 , ( V_38 > 1 ) ) ;
V_7 -> V_14 = F_33 ( V_80 , V_81 ) ;
if ( V_7 -> V_14 == NULL ) {
F_2 ( 0 , & V_7 -> V_11 ) ;
F_15 ( L_23 , V_7 -> V_17 ) ;
V_75 = - V_82 ;
goto V_78;
}
V_74 -> V_83 = V_7 ;
V_78:
F_34 ( & V_76 ) ;
return V_75 ;
}
static int F_35 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
struct V_6 * V_7 = V_74 -> V_83 ;
F_36 ( V_7 -> V_14 ) ;
V_7 -> V_14 = NULL ;
F_2 ( 0 , & V_7 -> V_11 ) ;
return 0 ;
}
static T_2 F_37 ( struct V_74 * V_84 , const char T_3 * V_45 , T_4 V_85 , T_5 * V_86 )
{
struct V_6 * V_7 = V_84 -> V_83 ;
struct V_87 V_88 ;
int V_89 = sizeof ( V_88 ) ;
if ( V_7 -> V_12 )
return - V_79 ;
if ( V_85 < V_89 )
return - V_90 ;
if ( F_38 ( & V_88 , V_45 , V_89 ) )
return - V_91 ;
if ( V_88 . V_92 != V_93 )
return - V_90 ;
if ( V_88 . V_40 > V_80 )
return - V_90 ;
if ( ( V_85 - V_89 ) > V_80 )
return - V_90 ;
if ( V_88 . V_94 == V_95 ) {
if ( V_85 != V_89 )
return - V_90 ;
if ( F_22 ( V_7 ) )
return - V_96 ;
return V_85 ;
}
if ( V_88 . V_94 != V_97 )
return - V_90 ;
V_7 -> V_98 = V_34 ;
V_7 -> V_99 = V_88 . V_99 * V_53 + V_53 / 2 + V_34 ;
if ( F_16 ( V_7 , V_88 . V_100 , V_88 . V_40 , V_34 + V_64 ) ) {
if ( V_7 -> V_33 & 0x10 )
return - V_101 ;
return - V_96 ;
}
V_7 -> V_12 = 1 ;
if ( F_38 ( V_7 -> V_14 , V_45 + V_89 , V_85 - V_89 ) )
return - V_91 ;
return V_85 ;
}
static T_2 F_39 ( struct V_74 * V_84 , char T_3 * V_45 , T_4 V_85 , T_5 * V_86 )
{
struct V_6 * V_7 = V_84 -> V_83 ;
struct V_102 V_88 ;
int V_89 = sizeof ( V_88 ) ;
int V_103 ;
if ( ! V_7 -> V_12 )
return - V_90 ;
if ( V_85 < V_89 )
return - V_90 ;
V_7 -> V_12 = 0 ;
if ( F_20 ( V_7 , V_7 -> V_14 , V_7 -> V_99 ) )
if ( V_7 -> V_33 & 0x10 )
return - V_101 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_92 = V_93 ;
V_88 . V_40 = V_7 -> V_40 ;
V_103 = 0 ;
if ( V_88 . V_40 < 0 ) {
V_88 . V_40 = - 1 * V_88 . V_40 ;
V_103 = V_88 . V_40 ;
if ( V_103 > ( V_85 - V_89 ) )
V_103 = V_85 - V_89 ;
}
V_88 . V_104 = ( V_34 - V_7 -> V_98 + V_53 / 2 ) / V_53 ;
V_88 . V_105 = V_7 -> V_33 & 0x0f ;
if ( F_40 ( V_45 , & V_88 , V_89 ) )
return - V_91 ;
if ( V_103 > 0 )
if ( F_40 ( V_45 + V_89 , V_7 -> V_14 , V_103 ) )
return - V_91 ;
return V_103 + V_89 ;
}
static int T_6 F_41 ( void )
{
int V_1 ;
int V_50 ;
if ( V_106 ) {
V_50 = - V_90 ;
goto V_78;
}
F_1 () ;
if ( F_26 () ) {
V_50 = - V_77 ;
goto V_78;
}
V_50 = F_42 ( V_66 , V_17 , & V_107 ) ;
if ( V_50 < 0 ) {
F_15 ( L_24 , V_66 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
struct V_6 * V_7 = & V_8 [ V_1 ] ;
if ( V_7 -> V_13 )
F_28 ( V_7 -> V_9 ) ;
}
goto V_78;
}
V_66 = V_50 ;
V_108 = F_43 ( V_109 , L_25 ) ;
if ( F_44 ( V_108 ) ) {
V_50 = F_45 ( V_108 ) ;
goto V_110;
}
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
struct V_6 * V_7 = & V_8 [ V_1 ] ;
if ( V_7 -> V_13 )
F_46 ( V_108 , NULL , F_47 ( V_66 , V_1 ) , NULL ,
L_26 , V_1 ) ;
}
V_50 = 0 ;
goto V_78;
V_110:
F_48 ( V_66 , L_25 ) ;
V_78:
return V_50 ;
}
static void T_7 F_49 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
struct V_6 * V_7 = & V_8 [ V_1 ] ;
if ( V_7 -> V_13 )
F_50 ( V_108 , F_47 ( V_66 , V_1 ) ) ;
}
F_51 ( V_108 ) ;
F_48 ( V_66 , V_17 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
struct V_6 * V_7 = & V_8 [ V_1 ] ;
if ( V_7 -> V_13 )
F_28 ( V_7 -> V_9 ) ;
}
}
