static void F_1 ( const unsigned char * V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 ;
char V_5 [ 16 * 3 + 1 ] ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 += 16 ) {
for ( V_4 = 0 ; ( V_4 < 16 ) && ( V_4 + V_3 < V_2 ) ; V_4 ++ ) {
sprintf ( V_5 + 3 * V_4 , L_1 , V_1 [ V_3 + V_4 ] ) ;
}
V_5 [ 3 * V_4 ] = '\0' ;
F_2 ( L_2 , V_5 ) ;
}
}
static void T_1 F_3 ( void )
{
int V_6 ;
F_4 ( L_3 ) ;
V_6 = F_5 ( V_7 ) ;
if ( V_6 != 0 ) {
F_6 ( V_8 L_4
L_5 , V_6 ) ;
} else {
F_7 ( L_6 ) ;
}
}
static int T_2 F_8 ( void )
{
int V_6 ;
F_6 ( L_7 ) ;
V_6 = F_9 ( V_7 , & V_9 ) ;
if ( V_6 == 0 ) {
F_7 ( L_8 , V_7 ) ;
F_7 ( L_9 , V_9 . V_10 ,
V_9 . V_11 ) ;
F_7 ( L_10 , V_9 . V_12 ) ;
F_7 ( L_11 , & V_9 ) ;
} else {
F_6 ( V_8 L_12
L_5 , V_6 ) ;
}
return V_6 ;
}
static void F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
unsigned long V_10 ;
F_11 ( & V_14 -> V_17 , V_10 ) ;
V_16 -> V_18 = NULL ;
if ( V_14 -> V_19 == NULL ) {
V_14 -> V_20 = V_14 -> V_19 = V_16 ;
} else {
V_14 -> V_19 -> V_18 = V_16 ;
V_14 -> V_19 = V_16 ;
}
F_12 ( & V_14 -> V_17 , V_10 ) ;
F_13 ( L_13 ,
V_16 , V_16 -> V_2 , V_14 -> V_20 ) ;
}
static void F_14 ( struct V_13 * V_14 , int V_21 )
{
struct V_15 * V_16 ;
unsigned long V_10 ;
#ifdef F_15
struct V_15 * V_22 ;
#endif
V_16 = V_14 -> V_20 ;
if ( V_16 == NULL )
return;
#ifdef F_15
F_6 ( L_14 ,
V_16 , V_16 -> V_2 ) ;
for ( V_22 = V_16 ; V_22 ; V_22 = V_22 -> V_18 )
F_6 ( L_15 , V_22 ) ;
F_6 ( L_16 ) ;
#endif
if ( V_16 -> V_23 ) {
if ( V_21 ) {
F_16 ( V_16 -> V_23 , V_24 , 0 ,
V_21 , NULL ) ;
} else {
F_16 ( V_16 -> V_23 , V_24 , V_16 -> V_2 ,
V_21 , NULL ) ;
}
F_17 ( & V_14 -> V_25 ) ;
}
F_11 ( & V_14 -> V_17 , V_10 ) ;
V_14 -> V_20 = V_16 -> V_18 ;
if ( V_14 -> V_20 == NULL ) {
V_14 -> V_19 = NULL ;
}
F_12 ( & V_14 -> V_17 , V_10 ) ;
F_18 ( V_16 ) ;
F_4 ( L_17 , V_16 ) ;
F_13 ( L_18 ,
V_14 -> V_20 , V_14 -> V_19 ) ;
}
static void F_19 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
unsigned long V_10 ;
F_11 ( & V_14 -> V_17 , V_10 ) ;
V_16 -> V_18 = NULL ;
if ( V_14 -> V_26 == NULL ) {
V_14 -> V_27 = V_14 -> V_26 = V_16 ;
} else {
V_14 -> V_26 -> V_18 = V_16 ;
V_14 -> V_26 = V_16 ;
}
V_14 -> V_28 ++ ;
F_12 ( & V_14 -> V_17 , V_10 ) ;
F_13 ( L_19 ,
V_16 , V_16 -> V_2 ,
V_14 -> V_27 , V_14 -> V_28 ) ;
}
static void F_20 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
unsigned long V_10 ;
struct V_15 * V_29 ;
if ( V_16 == NULL )
return;
F_13 ( L_20 ,
V_14 -> V_27 , V_14 -> V_26 , V_14 -> V_28 ) ;
F_13 ( L_21 ,
V_16 , V_16 -> V_2 ) ;
F_11 ( & V_14 -> V_17 , V_10 ) ;
if ( V_14 -> V_27 == V_16 ) {
V_14 -> V_27 = V_16 -> V_18 ;
if ( V_14 -> V_27 == NULL ) {
V_14 -> V_26 = NULL ;
}
V_14 -> V_28 -- ;
} else {
for ( V_29 = V_14 -> V_27 ; V_29 ; V_29 = V_29 -> V_18 ) {
if ( V_29 -> V_18 == V_16 ) {
V_29 -> V_18 = V_16 -> V_18 ;
V_14 -> V_28 -- ;
if ( V_29 -> V_18 == NULL ) {
V_14 -> V_26 = V_29 ;
}
break;
}
}
}
F_12 ( & V_14 -> V_17 , V_10 ) ;
F_18 ( V_16 ) ;
F_4 ( L_22 , V_16 ) ;
F_13 ( L_20 ,
V_14 -> V_27 , V_14 -> V_26 , V_14 -> V_28 ) ;
}
static void F_21 ( struct V_13 * V_14 , unsigned char V_30 )
{
struct V_31 * V_32 = V_14 -> V_32 ;
F_22 ( V_32 , V_30 ) ;
V_14 -> V_33 ^= V_30 ;
}
static void F_23 ( struct V_13 * V_14 )
{
struct V_31 * V_32 = V_14 -> V_32 ;
if ( V_32 == NULL || V_32 -> V_34 -> V_35 == NULL )
return;
V_32 -> V_34 -> V_35 ( V_32 ) ;
}
static void F_24 ( struct V_13 * V_14 )
{
unsigned long V_10 ;
F_11 ( & V_14 -> V_17 , V_10 ) ;
if ( ( V_14 -> V_36 == V_37 ) && ( V_14 -> V_20 != NULL ) ) {
V_14 -> V_36 = V_38 ;
V_14 -> V_39 = 0 ;
V_14 -> V_10 &= ~ V_40 ;
F_25 ( & V_14 -> V_41 , V_42 + V_43 ) ;
F_12 ( & V_14 -> V_17 , V_10 ) ;
F_2 ( L_23 ) ;
F_21 ( V_14 , V_44 ) ;
F_23 ( V_14 ) ;
V_14 -> V_33 = 0 ;
} else {
F_12 ( & V_14 -> V_17 , V_10 ) ;
}
}
static void F_26 ( struct V_13 * V_14 )
{
if ( V_14 -> V_39 < V_45 ) {
F_27 ( L_24 , V_14 -> V_39 ) ;
V_14 -> V_33 = 0 ;
F_21 ( V_14 , V_44 ) ;
F_23 ( V_14 ) ;
V_14 -> V_36 = V_38 ;
V_14 -> V_39 ++ ;
F_25 ( & V_14 -> V_41 , V_42 + V_43 ) ;
} else {
F_27 ( L_25 ,
V_45 ) ;
F_14 ( V_14 , V_46 ) ;
F_21 ( V_14 , V_47 ) ;
F_23 ( V_14 ) ;
V_14 -> V_36 = V_37 ;
F_24 ( V_14 ) ;
}
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_31 * V_32 = V_14 -> V_32 ;
struct V_15 * V_48 = V_14 -> V_20 ;
int V_49 = 0 ;
if ( V_32 == NULL || V_48 == NULL ) {
return;
}
V_49 = F_29 ( V_32 ) ;
F_2 ( L_26 ,
V_48 , V_49 , V_48 -> V_2 ) ;
while ( V_14 -> V_50 < V_48 -> V_2 ) {
if ( V_49 < 2 )
break;
if ( V_48 -> V_51 [ V_14 -> V_50 ] == V_52 ) {
F_21 ( V_14 , V_52 ) ;
}
F_21 ( V_14 , V_48 -> V_51 [ V_14 -> V_50 ++ ] ) ;
V_49 -- ;
}
if ( ( V_14 -> V_50 == V_48 -> V_2 ) && ( V_49 >= 3 ) ) {
F_21 ( V_14 , V_52 ) ;
F_21 ( V_14 , V_53 ) ;
if ( V_14 -> V_10 & V_54 ) {
F_21 ( V_14 , V_14 -> V_33 ) ;
}
V_14 -> V_36 = V_55 ;
F_25 ( & V_14 -> V_41 , V_42 + V_43 ) ;
}
F_23 ( V_14 ) ;
}
static void F_30 ( struct V_13 * V_14 )
{
unsigned int V_2 ;
struct V_56 * V_57 ;
struct V_15 * V_48 ;
V_2 = V_14 -> V_58 ;
if ( V_14 -> V_10 & V_54 ) {
if ( V_14 -> V_33 != V_14 -> V_59 ) {
F_27 ( L_27 ,
V_14 -> V_59 , V_14 -> V_33 ) ;
V_14 -> V_10 |= V_60 ;
}
}
if ( V_14 -> V_10 & V_40 ) {
F_27 ( L_28 ,
V_14 -> V_10 & V_40 ) ;
F_21 ( V_14 , V_47 ) ;
F_23 ( V_14 ) ;
if ( V_14 -> V_39 < V_45 ) {
V_14 -> V_36 = V_61 ;
V_14 -> V_39 ++ ;
F_25 ( & V_14 -> V_41 , V_42 + V_62 ) ;
} else {
F_27 ( L_29 ) ;
V_14 -> V_36 = V_37 ;
}
return;
}
F_21 ( V_14 , V_52 ) ;
F_23 ( V_14 ) ;
F_31 ( & V_14 -> V_41 ) ;
F_2 ( L_30 , V_2 ) ;
V_48 = F_32 ( V_2 + sizeof( struct V_15 ) ,
V_63 ) ;
F_4 ( L_31 , V_48 ) ;
if ( V_48 == NULL )
return;
V_48 -> V_2 = V_2 ;
V_48 -> V_51 = ( ( unsigned char * ) V_48 ) +
sizeof( struct V_15 ) ;
V_48 -> V_64 = 0 ;
V_48 -> V_18 = NULL ;
V_48 -> V_23 = NULL ;
memcpy ( V_48 -> V_51 , V_14 -> V_65 , V_2 ) ;
F_19 ( V_14 , V_48 ) ;
for ( V_57 = V_14 -> V_66 ; V_57 ; V_57 = V_57 -> V_18 ) {
if ( V_57 -> V_67 & V_68 ) {
F_16 ( V_57 , V_69 , V_2 , V_70 ,
V_48 ) ;
}
}
F_17 ( & V_14 -> V_25 ) ;
V_14 -> V_36 = V_37 ;
F_24 ( V_14 ) ;
}
static void F_33 ( struct V_13 * V_14 , const unsigned char V_71 )
{
switch ( V_14 -> V_36 ) {
case V_38 :
if ( V_71 == V_52 ) {
F_2 ( L_32 ) ;
V_14 -> V_36 = V_72 ;
V_14 -> V_50 = 0 ;
F_28 ( V_14 ) ;
} else if ( V_71 == V_44 ) {
if ( V_14 -> V_39 == 0 ) {
F_27 ( L_33 ) ;
if ( V_14 -> V_73 == V_74 ) {
goto V_75;
}
} else {
F_27 ( L_34
L_35
L_36 ) ;
goto V_75;
}
} else {
F_27 ( L_37 , V_71 ) ;
F_26 ( V_14 ) ;
}
break;
case V_72 :
if ( V_71 == V_47 ) {
F_27 ( L_38 ) ;
F_26 ( V_14 ) ;
} else {
F_27 ( L_39 ) ;
V_14 -> V_36 = V_76 ;
F_25 ( & V_14 -> V_41 , V_42 + V_77 ) ;
}
break;
case V_55 :
if ( V_71 == V_52 ) {
F_2 ( L_40 ) ;
F_14 ( V_14 , V_70 ) ;
V_14 -> V_36 = V_37 ;
F_24 ( V_14 ) ;
} else {
F_26 ( V_14 ) ;
}
break;
case V_61 :
case V_37 :
if ( V_71 == V_44 ) {
if ( V_14 -> V_28 >=
V_78 ) {
F_27 ( L_41
L_42 ) ;
V_14 -> V_36 = V_79 ;
F_25 ( & V_14 -> V_41 ,
V_42 + V_80 ) ;
break;
}
V_75:
F_2 ( L_43 ) ;
V_14 -> V_58 = 0 ;
V_14 -> V_59 = 0 ;
V_14 -> V_10 &= ~ V_40 ;
V_14 -> V_36 = V_81 ;
F_25 ( & V_14 -> V_41 , V_42 + V_77 ) ;
V_14 -> V_39 = 0 ;
F_21 ( V_14 , V_52 ) ;
F_23 ( V_14 ) ;
V_14 -> V_33 = 0 ;
}
break;
case V_81 :
if ( V_14 -> V_58 < V_82 ) {
V_14 -> V_33 ^= V_71 ;
if ( V_71 == V_52 ) {
if ( V_14 -> V_59 == V_52 ) {
V_14 -> V_59 = 0 ;
goto V_83;
}
V_14 -> V_59 = V_52 ;
break;
} else if ( ( V_71 == V_53 ) && ( V_14 -> V_59 == V_52 ) ) {
if ( V_14 -> V_10 & V_54 ) {
V_14 -> V_36 = V_84 ;
F_25 ( & V_14 -> V_41 ,
V_42 + V_77 ) ;
} else {
F_30 ( V_14 ) ;
}
} else {
V_14 -> V_59 = V_71 ;
V_83:
V_14 -> V_65 [ V_14 -> V_58 ++ ] = V_71 ;
F_25 ( & V_14 -> V_41 , V_42 + V_77 ) ;
}
}
break;
case V_84 :
V_14 -> V_59 = V_71 ;
F_30 ( V_14 ) ;
break;
}
}
static void F_34 ( struct V_13 * V_14 , const char V_85 )
{
switch ( V_85 ) {
case V_86 :
break;
case V_87 :
F_27 ( L_44 ) ;
V_14 -> V_10 |= V_88 ;
break;
case V_89 :
F_27 ( L_45 ) ;
V_14 -> V_10 |= V_90 ;
break;
case V_91 :
F_27 ( L_46 ) ;
V_14 -> V_10 |= V_92 ;
break;
case V_93 :
F_27 ( L_47 ) ;
V_14 -> V_10 |= V_94 ;
break;
default:
F_27 ( L_48 , V_85 ) ;
V_14 -> V_10 |= V_95 ;
break;
}
}
static void F_35 ( unsigned long V_96 )
{
struct V_13 * V_14 = ( void * ) V_96 ;
switch ( V_14 -> V_36 ) {
case V_38 :
F_27 ( L_49 ) ;
F_26 ( V_14 ) ;
break;
case V_76 :
F_21 ( V_14 , V_47 ) ;
F_23 ( V_14 ) ;
F_26 ( V_14 ) ;
break;
case V_55 :
F_27 ( L_50 ) ;
F_26 ( V_14 ) ;
break;
case V_79 :
F_27 ( L_51 ) ;
F_21 ( V_14 , V_47 ) ;
F_23 ( V_14 ) ;
V_14 -> V_36 = V_37 ;
break;
case V_81 :
F_27 ( L_52 ,
V_14 -> V_58 ) ;
F_21 ( V_14 , V_47 ) ;
F_23 ( V_14 ) ;
V_14 -> V_36 = V_37 ;
break;
case V_61 :
F_27 ( L_53 ) ;
V_14 -> V_36 = V_37 ;
break;
case V_84 :
F_27 ( L_54 ) ;
F_21 ( V_14 , V_47 ) ;
F_23 ( V_14 ) ;
V_14 -> V_36 = V_37 ;
break;
}
}
static struct V_56 * F_36 ( struct V_13 * V_14 ,
struct V_97 * V_97 )
{
struct V_56 * V_57 ;
for ( V_57 = V_14 -> V_66 ; V_57 ; V_57 = V_57 -> V_18 ) {
if ( V_57 -> V_97 == V_97 ) {
return V_57 ;
}
}
return NULL ;
}
static int F_37 ( struct V_13 * V_14 , struct V_97 * V_97 , int V_98 )
{
struct V_56 * V_57 ;
struct V_56 * * V_99 ;
struct V_100 * V_101 ;
if ( ( V_98 & V_102 ) == 0 ) {
for ( V_99 = & V_14 -> V_66 ; * V_99 ;
V_99 = & ( * V_99 ) -> V_18 ) {
V_57 = * V_99 ;
if ( V_57 -> V_97 == V_97 ) {
F_2 ( L_55 ,
F_38 ( V_97 ) ) ;
* V_99 = V_57 -> V_18 ;
while ( V_57 -> V_103 ) {
V_101 = F_39 ( V_14 , V_57 ) ;
if ( V_101 ) {
F_18 ( V_101 ) ;
F_4 ( L_56
L_57 , V_101 ) ;
}
}
F_40 ( V_57 -> V_97 ) ;
F_18 ( V_57 ) ;
F_4 ( L_58 , V_57 ) ;
return 0 ;
}
}
return - V_104 ;
} else {
V_57 = F_36 ( V_14 , V_97 ) ;
if ( V_57 ) {
V_57 -> V_67 = V_98 ;
} else {
V_57 = F_32 ( sizeof( struct V_56 ) ,
V_63 ) ;
F_4 ( L_59 , V_57 ) ;
if ( V_57 == NULL )
return - V_105 ;
F_2 ( L_60 , F_38 ( V_97 ) ) ;
F_41 ( & V_57 -> V_17 ) ;
V_57 -> V_67 = V_98 ;
V_57 -> V_97 = F_42 ( V_97 ) ;
V_57 -> V_18 = V_14 -> V_66 ;
V_57 -> V_106 = NULL ;
V_57 -> V_107 = NULL ;
V_57 -> V_108 = NULL ;
V_57 -> V_103 = 0 ;
V_14 -> V_66 = V_57 ;
}
}
return 0 ;
}
static int F_43 ( struct V_13 * V_14 , struct V_97 * V_97 ,
unsigned char T_3 * V_109 )
{
struct V_56 * V_57 ;
struct V_15 * V_1 ;
if ( ! V_109 ) {
return - V_104 ;
}
V_57 = F_36 ( V_14 , V_97 ) ;
if ( V_57 == NULL ) {
return - V_104 ;
}
V_1 = V_57 -> V_108 ;
if ( ! V_1 ) {
return 0 ;
} else {
if ( F_44 ( V_109 , V_1 -> V_51 , V_1 -> V_2 ) )
return - V_110 ;
F_45 ( V_14 , V_57 ) ;
return V_1 -> V_2 ;
}
return - V_104 ;
}
static void F_16 ( struct V_56 * V_57 , int V_111 , int V_98 ,
int V_21 , struct V_15 * V_48 )
{
struct V_100 * V_101 ;
unsigned long V_10 ;
if ( V_57 -> V_103 < V_112 - 1 ) {
V_113:
V_101 = F_32 ( sizeof( struct V_100 ) ,
V_21 ? V_114 : V_63 ) ;
F_4 ( L_61 , V_101 ) ;
if ( V_101 == NULL ) {
return;
}
F_11 ( & V_57 -> V_17 , V_10 ) ;
V_101 -> V_111 = V_111 ;
V_101 -> V_98 = V_98 ;
V_101 -> V_21 = V_21 ;
V_101 -> V_1 = V_48 ;
V_101 -> V_18 = NULL ;
if ( V_57 -> V_107 == NULL ) {
V_57 -> V_106 = V_57 -> V_107 = V_101 ;
} else {
V_57 -> V_107 -> V_18 = V_101 ;
V_57 -> V_107 = V_101 ;
}
V_57 -> V_103 ++ ;
if ( V_48 != NULL ) {
V_48 -> V_64 ++ ;
}
F_12 ( & V_57 -> V_17 , V_10 ) ;
} else {
if ( ( V_57 -> V_107 -> V_111 == V_24 )
&& ( V_57 -> V_107 -> V_21 == V_115 ) ) {
V_57 -> V_107 -> V_98 ++ ;
F_27 ( L_62 ) ;
} else {
V_111 = V_24 ;
V_98 = 0 ;
V_21 = V_115 ;
V_48 = NULL ;
F_27 ( L_63 ) ;
goto V_113;
}
}
if ( V_57 -> V_67 & V_116 ) {
F_46 ( V_57 -> V_97 , V_117 , 1 ) ;
}
}
static struct V_100 * F_39 ( struct V_13 * V_14 ,
struct V_56 * V_57 )
{
struct V_100 * V_101 = NULL ;
unsigned long V_10 ;
if ( V_57 -> V_106 ) {
F_11 ( & V_57 -> V_17 , V_10 ) ;
V_101 = V_57 -> V_106 ;
V_57 -> V_106 = V_101 -> V_18 ;
if ( V_57 -> V_106 == NULL ) {
V_57 -> V_107 = NULL ;
}
V_57 -> V_103 -- ;
if ( V_101 -> V_1 ) {
F_45 ( V_14 , V_57 ) ;
V_57 -> V_108 = V_101 -> V_1 ;
}
F_12 ( & V_57 -> V_17 , V_10 ) ;
}
return V_101 ;
}
static void F_45 ( struct V_13 * V_14 ,
struct V_56 * V_57 )
{
struct V_15 * V_1 ;
F_2 ( L_64 , F_38 ( V_57 -> V_97 ) ) ;
V_1 = V_57 -> V_108 ;
if ( V_1 ) {
V_1 -> V_64 -- ;
if ( V_1 -> V_64 == 0 ) {
F_20 ( V_14 , V_1 ) ;
}
}
V_57 -> V_108 = NULL ;
}
static int F_47 ( struct V_31 * V_32 )
{
struct V_13 * V_14 ;
F_7 ( L_65 ) ;
F_7 ( L_66 ,
V_32 , V_118 -> V_97 , V_32 -> V_119 ) ;
V_14 = F_32 ( sizeof( struct V_13 ) , V_63 ) ;
F_4 ( L_67 , V_14 ) ;
if ( ! V_14 ) {
F_6 ( V_8 L_68 ) ;
return - V_105 ;
}
V_14 -> V_65 = F_32 ( V_82 , V_63 ) ;
F_4 ( L_69 , V_14 -> V_65 ) ;
if ( ! V_14 -> V_65 ) {
F_6 ( V_8 L_70 ) ;
F_18 ( V_14 ) ;
F_4 ( L_71 , V_14 ) ;
return - V_105 ;
}
V_14 -> V_120 = F_32 ( V_121 , V_63 ) ;
F_4 ( L_72 , V_14 -> V_120 ) ;
if ( ! V_14 -> V_120 ) {
F_6 ( V_8 L_73 ) ;
F_18 ( V_14 -> V_65 ) ;
F_4 ( L_74 , V_14 -> V_65 ) ;
F_18 ( V_14 ) ;
F_4 ( L_71 , V_14 ) ;
return - V_105 ;
}
F_41 ( & V_14 -> V_17 ) ;
V_14 -> V_32 = V_32 ;
F_48 ( & V_14 -> V_25 ) ;
V_14 -> V_73 = V_122 ;
V_14 -> V_27 = V_14 -> V_26 = NULL ;
V_14 -> V_20 = V_14 -> V_19 = NULL ;
V_14 -> V_58 = 0 ;
V_14 -> V_50 = 0 ;
V_14 -> V_59 = 0 ;
V_14 -> V_28 = 0 ;
V_14 -> V_66 = NULL ;
V_14 -> V_36 = V_37 ;
V_14 -> V_10 = V_123 ;
V_14 -> V_39 = 0 ;
V_32 -> V_119 = V_14 ;
V_32 -> V_124 = 65536 ;
F_49 ( & V_14 -> V_41 , F_35 , ( unsigned long ) V_14 ) ;
return 0 ;
}
static void F_50 ( struct V_31 * V_32 )
{
struct V_13 * V_14 = V_32 -> V_119 ;
struct V_56 * V_57 , * V_125 ;
struct V_100 * V_101 ;
struct V_15 * V_16 , * V_126 ;
unsigned long V_10 ;
F_7 ( L_75 ) ;
F_31 ( & V_14 -> V_41 ) ;
V_57 = V_14 -> V_66 ;
while ( V_57 ) {
V_125 = V_57 -> V_18 ;
while ( V_57 -> V_103 ) {
V_101 = F_39 ( V_14 , V_57 ) ;
if ( V_101 ) {
F_18 ( V_101 ) ;
F_4 ( L_76 , V_101 ) ;
}
}
F_40 ( V_57 -> V_97 ) ;
F_18 ( V_57 ) ;
F_4 ( L_77 , V_57 ) ;
V_57 = V_125 ;
}
F_11 ( & V_14 -> V_17 , V_10 ) ;
V_16 = V_14 -> V_20 ;
V_14 -> V_20 = V_14 -> V_19 = NULL ;
F_12 ( & V_14 -> V_17 , V_10 ) ;
while ( V_16 ) {
V_126 = V_16 -> V_18 ;
F_18 ( V_16 ) ;
V_16 = V_126 ;
}
F_17 ( & V_14 -> V_25 ) ;
F_18 ( V_14 -> V_65 ) ;
F_4 ( L_78 , V_14 -> V_65 ) ;
F_18 ( V_14 -> V_120 ) ;
F_4 ( L_79 , V_14 -> V_120 ) ;
F_18 ( V_14 ) ;
F_4 ( L_80 , V_14 ) ;
}
static T_4 F_51 ( struct V_31 * V_32 , struct V_127 * V_127 ,
unsigned char T_3 * V_109 , T_5 V_128 )
{
struct V_13 * V_14 = V_32 -> V_119 ;
struct V_56 * V_57 ;
struct V_100 * V_101 ;
struct V_129 V_130 ;
int V_131 ;
F_7 ( L_81 ) ;
F_52 ( V_32 ) ;
V_57 = F_36 ( V_14 , F_53 ( V_118 ) ) ;
if ( V_57 ) {
V_101 = F_39 ( V_14 , V_57 ) ;
if ( V_101 == NULL ) {
if ( V_127 -> V_132 & V_133 ) {
V_131 = - V_134 ;
goto V_135;
}
F_54 ( V_32 , V_14 -> V_25 ,
( V_101 = F_39 ( V_14 , V_57 ) ) ) ;
}
if ( ! V_101 ) {
V_131 = - V_136 ;
goto V_135;
}
V_130 . V_111 = V_101 -> V_111 ;
V_130 . V_98 = V_101 -> V_98 ;
V_130 . V_21 = V_101 -> V_21 ;
V_131 = sizeof( struct V_129 ) ;
F_18 ( V_101 ) ;
F_4 ( L_82 , V_101 ) ;
if ( F_44 ( V_109 , & V_130 , V_131 ) ) {
V_131 = - V_110 ;
goto V_135;
}
F_2 ( L_83 , V_131 ) ;
goto V_135;
}
V_131 = - V_137 ;
V_135:
F_55 ( V_32 ) ;
return V_131 ;
}
static T_4 F_56 ( struct V_31 * V_32 , struct V_127 * V_127 ,
const unsigned char * V_51 , T_5 V_138 )
{
struct V_13 * V_14 = V_32 -> V_119 ;
struct V_15 * V_16 ;
struct V_56 * V_57 ;
unsigned char * V_139 ;
F_7 ( L_84 , V_138 ) ;
if ( ! V_14 )
return - V_140 ;
if ( V_138 > V_141 ) {
if ( V_14 -> V_10 & V_123 ) {
F_7 ( V_142 L_85
L_86 , V_138 , V_141 ) ;
}
V_138 = V_141 ;
}
V_139 = F_32 ( V_138 + sizeof( struct V_15 ) ,
V_63 ) ;
F_4 ( L_87 , V_139 ) ;
if ( V_139 == NULL ) {
if ( V_14 -> V_10 & V_123 ) {
F_6 ( V_8 L_88 ) ;
}
return - V_143 ;
}
V_16 = (struct V_15 * ) V_139 ;
V_16 -> V_51 = V_139 + sizeof( struct V_15 ) ;
V_16 -> V_2 = V_138 ;
V_16 -> V_64 = 0 ;
V_16 -> V_23 = NULL ;
F_52 ( V_32 ) ;
V_57 = F_36 ( V_14 , F_53 ( V_118 ) ) ;
if ( V_57 ) {
V_16 -> V_23 = V_57 ;
}
memcpy ( V_16 -> V_51 , V_51 , V_138 ) ;
if ( V_14 -> V_10 & V_123 ) {
F_1 ( V_16 -> V_51 , V_138 ) ;
}
F_10 ( V_14 , V_16 ) ;
F_24 ( V_14 ) ;
F_55 ( V_32 ) ;
return 0 ;
}
static int F_57 ( struct V_31 * V_32 , struct V_127 * V_127 ,
unsigned int V_144 , unsigned long V_98 )
{
struct V_13 * V_14 = V_32 -> V_119 ;
if ( V_14 == NULL )
return - V_104 ;
switch ( V_144 ) {
case V_145 :
return F_37 ( V_14 , F_53 ( V_118 ) , V_98 ) ;
case V_146 :
if ( V_98 < V_122 || V_98 > V_74 )
return - V_104 ;
V_14 -> V_73 = V_98 & 0xff ;
return 0 ;
case V_147 :
if ( V_98 )
V_14 -> V_10 |= V_54 ;
else
V_14 -> V_10 &= ~ V_54 ;
return 0 ;
case V_148 :
return F_43 ( V_14 , F_53 ( V_118 ) ,
( unsigned char T_3 * ) V_98 ) ;
default:
return - V_149 ;
}
}
static void F_58 ( struct V_31 * V_32 , struct V_150 * V_151 )
{
F_7 ( L_89 ) ;
}
static unsigned int F_59 ( struct V_31 * V_32 , struct V_127 * V_127 ,
struct V_152 * V_153 )
{
struct V_13 * V_14 = V_32 -> V_119 ;
struct V_56 * V_57 ;
struct V_100 * V_101 = NULL ;
unsigned long V_10 ;
int V_154 = V_155 ;
F_7 ( L_90 ) ;
V_57 = F_36 ( V_14 , F_53 ( V_118 ) ) ;
if ( V_57 ) {
F_60 ( V_127 , & V_14 -> V_25 , V_153 ) ;
F_11 ( & V_14 -> V_17 , V_10 ) ;
V_101 = V_57 -> V_106 ;
F_12 ( & V_14 -> V_17 , V_10 ) ;
if ( V_101 )
V_154 |= V_156 | V_157 ;
} else {
V_154 = - V_104 ;
}
return V_154 ;
}
static void F_61 ( struct V_31 * V_32 , const unsigned char * V_158 ,
char * V_159 , int V_138 )
{
struct V_13 * V_14 = V_32 -> V_119 ;
const unsigned char * V_160 ;
char * V_161 , V_10 = V_86 ;
int V_3 ;
for ( V_3 = V_138 , V_160 = V_158 , V_161 = V_159 ; V_3 ; V_3 -- , V_160 ++ ) {
if ( V_161 )
V_10 = * V_161 ++ ;
if ( V_10 == V_86 ) {
F_33 ( V_14 , * V_160 ) ;
} else {
F_34 ( V_14 , V_10 ) ;
}
}
}
