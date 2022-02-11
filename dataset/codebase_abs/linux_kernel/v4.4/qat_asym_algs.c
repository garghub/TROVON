static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) ( V_5 long ) V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( F_3 ( V_4 ) , 64 ) ;
struct V_9 * V_10 = & F_4 ( V_8 -> V_11 -> V_12 -> V_13 ) ;
int V_14 = F_5 (
V_2 -> V_15 . V_16 ) ;
V_14 = ( V_14 == V_17 ) ? 0 : - V_18 ;
if ( V_8 -> V_19 )
F_6 ( V_10 , V_8 -> V_11 -> V_20 , V_8 -> V_19 ,
V_8 -> V_21 . V_22 . V_23 ) ;
else
F_7 ( V_10 , V_8 -> V_21 . V_22 . V_23 , V_8 -> V_11 -> V_20 ,
V_24 ) ;
V_4 -> V_25 = V_8 -> V_11 -> V_20 ;
if ( V_8 -> V_26 ) {
char * V_27 = V_8 -> V_26 ;
while ( ! ( * V_27 ) && V_4 -> V_25 ) {
V_4 -> V_25 -- ;
V_27 ++ ;
}
if ( V_4 -> V_25 != V_8 -> V_11 -> V_20 )
memmove ( V_8 -> V_26 , V_27 , V_4 -> V_25 ) ;
F_8 ( V_8 -> V_26 , V_4 -> V_28 , 0 ,
V_4 -> V_25 , 1 ) ;
F_6 ( V_10 , V_8 -> V_11 -> V_20 , V_8 -> V_26 ,
V_8 -> V_29 . V_22 . V_30 ) ;
} else {
char * V_27 = F_9 ( V_4 -> V_28 ) ;
while ( ! ( * V_27 ) && V_4 -> V_25 ) {
V_4 -> V_25 -- ;
V_27 ++ ;
}
if ( F_9 ( V_4 -> V_28 ) != V_27 && V_4 -> V_25 )
memmove ( F_9 ( V_4 -> V_28 ) , V_27 , V_4 -> V_25 ) ;
F_7 ( V_10 , V_8 -> V_29 . V_22 . V_30 , V_8 -> V_11 -> V_20 ,
V_31 ) ;
}
F_7 ( V_10 , V_8 -> V_32 , sizeof( struct V_33 ) ,
V_24 ) ;
F_7 ( V_10 , V_8 -> V_34 ,
sizeof( struct V_35 ) ,
V_24 ) ;
F_10 ( V_4 , V_14 ) ;
}
void F_11 ( void * V_36 )
{
struct V_1 * V_2 = V_36 ;
F_1 ( V_2 ) ;
}
static unsigned long F_12 ( unsigned int V_37 )
{
unsigned int V_38 = V_37 << 3 ;
switch ( V_38 ) {
case 512 :
return V_39 ;
case 1024 :
return V_40 ;
case 1536 :
return V_41 ;
case 2048 :
return V_42 ;
case 3072 :
return V_43 ;
case 4096 :
return V_44 ;
default:
return 0 ;
} ;
}
static unsigned long F_13 ( unsigned int V_37 )
{
unsigned int V_38 = V_37 << 3 ;
switch ( V_38 ) {
case 512 :
return V_45 ;
case 1024 :
return V_46 ;
case 1536 :
return V_47 ;
case 2048 :
return V_48 ;
case 3072 :
return V_49 ;
case 4096 :
return V_50 ;
default:
return 0 ;
} ;
}
static int F_14 ( struct V_3 * V_8 )
{
struct V_51 * V_52 = F_15 ( V_8 ) ;
struct V_53 * V_11 = F_16 ( V_52 ) ;
struct V_54 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
struct V_7 * V_55 =
F_2 ( F_3 ( V_8 ) , 64 ) ;
struct V_56 * V_57 = & V_55 -> V_8 ;
int V_58 , V_59 = 0 ;
if ( F_17 ( ! V_11 -> V_60 || ! V_11 -> V_61 ) )
return - V_18 ;
if ( V_8 -> V_25 < V_11 -> V_20 ) {
V_8 -> V_25 = V_11 -> V_20 ;
return - V_62 ;
}
memset ( V_57 , '\0' , sizeof( * V_57 ) ) ;
F_18 ( V_57 -> V_63 ,
V_64 ) ;
V_57 -> V_63 . V_65 . V_66 = F_12 ( V_11 -> V_20 ) ;
if ( F_17 ( ! V_57 -> V_63 . V_65 . V_66 ) )
return - V_18 ;
V_55 -> V_11 = V_11 ;
V_57 -> V_63 . V_67 = V_68 ;
V_57 -> V_63 . V_69 =
F_19 ( V_70 ,
V_71 ) ;
V_55 -> V_21 . V_22 . V_61 = V_11 -> V_72 ;
V_55 -> V_21 . V_22 . V_60 = V_11 -> V_73 ;
V_58 = - V_74 ;
if ( F_20 ( V_8 -> V_75 ) && V_8 -> V_76 == V_11 -> V_20 ) {
V_55 -> V_19 = NULL ;
V_55 -> V_21 . V_22 . V_23 = F_21 ( V_10 , F_9 ( V_8 -> V_75 ) ,
V_8 -> V_76 , V_24 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_21 . V_22 . V_23 ) ) )
return V_58 ;
} else {
int V_77 = V_11 -> V_20 - V_8 -> V_76 ;
V_55 -> V_19 = F_23 ( V_10 , V_11 -> V_20 ,
& V_55 -> V_21 . V_22 . V_23 ,
V_78 ) ;
if ( F_17 ( ! V_55 -> V_19 ) )
return V_58 ;
F_8 ( V_55 -> V_19 + V_77 , V_8 -> V_75 ,
0 , V_8 -> V_76 , 0 ) ;
}
if ( F_20 ( V_8 -> V_28 ) && V_8 -> V_25 == V_11 -> V_20 ) {
V_55 -> V_26 = NULL ;
V_55 -> V_29 . V_22 . V_30 = F_21 ( V_10 , F_9 ( V_8 -> V_28 ) ,
V_8 -> V_25 ,
V_31 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_29 . V_22 . V_30 ) ) )
goto V_79;
} else {
V_55 -> V_26 = F_23 ( V_10 , V_11 -> V_20 ,
& V_55 -> V_29 . V_22 . V_30 ,
V_78 ) ;
if ( F_17 ( ! V_55 -> V_26 ) )
goto V_79;
}
V_55 -> V_21 . V_80 [ 3 ] = 0 ;
V_55 -> V_29 . V_81 [ 1 ] = 0 ;
V_55 -> V_32 = F_21 ( V_10 , & V_55 -> V_21 . V_22 . V_23 ,
sizeof( struct V_33 ) ,
V_24 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_32 ) ) )
goto V_82;
V_55 -> V_34 = F_21 ( V_10 , & V_55 -> V_29 . V_22 . V_30 ,
sizeof( struct V_35 ) ,
V_24 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_34 ) ) )
goto V_83;
V_57 -> V_84 . V_85 = V_55 -> V_32 ;
V_57 -> V_84 . V_86 = V_55 -> V_34 ;
V_57 -> V_84 . V_6 = ( V_87 ) ( V_5 long ) V_8 ;
V_57 -> V_88 = 3 ;
V_57 -> V_89 = 1 ;
do {
V_58 = F_24 ( V_11 -> V_12 -> V_90 , ( V_91 * ) V_57 ) ;
} while ( V_58 == - V_92 && V_59 ++ < 100 );
if ( ! V_58 )
return - V_93 ;
V_79:
if ( V_55 -> V_19 )
F_6 ( V_10 , V_11 -> V_20 , V_55 -> V_19 ,
V_55 -> V_21 . V_22 . V_23 ) ;
else
if ( ! F_22 ( V_10 , V_55 -> V_21 . V_22 . V_23 ) )
F_7 ( V_10 , V_55 -> V_21 . V_22 . V_23 , V_11 -> V_20 ,
V_24 ) ;
V_82:
if ( V_55 -> V_26 )
F_6 ( V_10 , V_11 -> V_20 , V_55 -> V_26 ,
V_55 -> V_29 . V_22 . V_30 ) ;
else
if ( ! F_22 ( V_10 , V_55 -> V_29 . V_22 . V_30 ) )
F_7 ( V_10 , V_55 -> V_29 . V_22 . V_30 , V_11 -> V_20 ,
V_31 ) ;
V_83:
if ( ! F_22 ( V_10 , V_55 -> V_32 ) )
F_7 ( V_10 , V_55 -> V_32 ,
sizeof( struct V_33 ) ,
V_24 ) ;
if ( ! F_22 ( V_10 , V_55 -> V_34 ) )
F_7 ( V_10 , V_55 -> V_34 ,
sizeof( struct V_35 ) ,
V_24 ) ;
return V_58 ;
}
static int F_25 ( struct V_3 * V_8 )
{
struct V_51 * V_52 = F_15 ( V_8 ) ;
struct V_53 * V_11 = F_16 ( V_52 ) ;
struct V_54 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
struct V_7 * V_55 =
F_2 ( F_3 ( V_8 ) , 64 ) ;
struct V_56 * V_57 = & V_55 -> V_8 ;
int V_58 , V_59 = 0 ;
if ( F_17 ( ! V_11 -> V_60 || ! V_11 -> V_94 ) )
return - V_18 ;
if ( V_8 -> V_25 < V_11 -> V_20 ) {
V_8 -> V_25 = V_11 -> V_20 ;
return - V_62 ;
}
memset ( V_57 , '\0' , sizeof( * V_57 ) ) ;
F_18 ( V_57 -> V_63 ,
V_64 ) ;
V_57 -> V_63 . V_65 . V_66 = F_13 ( V_11 -> V_20 ) ;
if ( F_17 ( ! V_57 -> V_63 . V_65 . V_66 ) )
return - V_18 ;
V_55 -> V_11 = V_11 ;
V_57 -> V_63 . V_67 = V_68 ;
V_57 -> V_63 . V_69 =
F_19 ( V_70 ,
V_71 ) ;
V_55 -> V_21 . V_95 . V_94 = V_11 -> V_96 ;
V_55 -> V_21 . V_95 . V_60 = V_11 -> V_73 ;
V_58 = - V_74 ;
if ( F_20 ( V_8 -> V_75 ) && V_8 -> V_76 == V_11 -> V_20 ) {
V_55 -> V_19 = NULL ;
V_55 -> V_21 . V_95 . V_30 = F_21 ( V_10 , F_9 ( V_8 -> V_75 ) ,
V_8 -> V_25 , V_24 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_21 . V_95 . V_30 ) ) )
return V_58 ;
} else {
int V_77 = V_11 -> V_20 - V_8 -> V_76 ;
V_55 -> V_19 = F_23 ( V_10 , V_11 -> V_20 ,
& V_55 -> V_21 . V_95 . V_30 ,
V_78 ) ;
if ( F_17 ( ! V_55 -> V_19 ) )
return V_58 ;
F_8 ( V_55 -> V_19 + V_77 , V_8 -> V_75 ,
0 , V_8 -> V_76 , 0 ) ;
}
if ( F_20 ( V_8 -> V_28 ) && V_8 -> V_25 == V_11 -> V_20 ) {
V_55 -> V_26 = NULL ;
V_55 -> V_29 . V_95 . V_23 = F_21 ( V_10 , F_9 ( V_8 -> V_28 ) ,
V_8 -> V_25 ,
V_31 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_29 . V_95 . V_23 ) ) )
goto V_79;
} else {
V_55 -> V_26 = F_23 ( V_10 , V_11 -> V_20 ,
& V_55 -> V_29 . V_95 . V_23 ,
V_78 ) ;
if ( F_17 ( ! V_55 -> V_26 ) )
goto V_79;
}
V_55 -> V_21 . V_80 [ 3 ] = 0 ;
V_55 -> V_29 . V_81 [ 1 ] = 0 ;
V_55 -> V_32 = F_21 ( V_10 , & V_55 -> V_21 . V_95 . V_30 ,
sizeof( struct V_33 ) ,
V_24 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_32 ) ) )
goto V_82;
V_55 -> V_34 = F_21 ( V_10 , & V_55 -> V_29 . V_95 . V_23 ,
sizeof( struct V_35 ) ,
V_24 ) ;
if ( F_17 ( F_22 ( V_10 , V_55 -> V_34 ) ) )
goto V_83;
V_57 -> V_84 . V_85 = V_55 -> V_32 ;
V_57 -> V_84 . V_86 = V_55 -> V_34 ;
V_57 -> V_84 . V_6 = ( V_87 ) ( V_5 long ) V_8 ;
V_57 -> V_88 = 3 ;
V_57 -> V_89 = 1 ;
do {
V_58 = F_24 ( V_11 -> V_12 -> V_90 , ( V_91 * ) V_57 ) ;
} while ( V_58 == - V_92 && V_59 ++ < 100 );
if ( ! V_58 )
return - V_93 ;
V_79:
if ( V_55 -> V_19 )
F_6 ( V_10 , V_11 -> V_20 , V_55 -> V_19 ,
V_55 -> V_21 . V_95 . V_30 ) ;
else
if ( ! F_22 ( V_10 , V_55 -> V_21 . V_95 . V_30 ) )
F_7 ( V_10 , V_55 -> V_21 . V_95 . V_30 , V_11 -> V_20 ,
V_24 ) ;
V_82:
if ( V_55 -> V_26 )
F_6 ( V_10 , V_11 -> V_20 , V_55 -> V_26 ,
V_55 -> V_29 . V_95 . V_23 ) ;
else
if ( ! F_22 ( V_10 , V_55 -> V_29 . V_95 . V_23 ) )
F_7 ( V_10 , V_55 -> V_29 . V_95 . V_23 , V_11 -> V_20 ,
V_31 ) ;
V_83:
if ( ! F_22 ( V_10 , V_55 -> V_32 ) )
F_7 ( V_10 , V_55 -> V_32 ,
sizeof( struct V_33 ) ,
V_24 ) ;
if ( ! F_22 ( V_10 , V_55 -> V_34 ) )
F_7 ( V_10 , V_55 -> V_34 ,
sizeof( struct V_35 ) ,
V_24 ) ;
return V_58 ;
}
int F_26 ( void * V_97 , T_1 V_98 , unsigned char V_99 ,
const void * V_100 , T_1 V_101 )
{
struct V_53 * V_11 = V_97 ;
struct V_54 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
const char * V_27 = V_100 ;
int V_58 ;
while ( ! * V_27 && V_101 ) {
V_27 ++ ;
V_101 -- ;
}
V_11 -> V_20 = V_101 ;
V_58 = - V_18 ;
if ( V_102 && ( V_11 -> V_20 != 256 && V_11 -> V_20 != 384 ) ) {
F_27 ( L_1 ) ;
goto V_14;
}
if ( ! F_12 ( V_11 -> V_20 ) )
goto V_14;
V_58 = - V_74 ;
V_11 -> V_60 = F_23 ( V_10 , V_11 -> V_20 , & V_11 -> V_73 , V_78 ) ;
if ( ! V_11 -> V_60 )
goto V_14;
memcpy ( V_11 -> V_60 , V_27 , V_11 -> V_20 ) ;
return 0 ;
V_14:
V_11 -> V_20 = 0 ;
V_11 -> V_60 = NULL ;
return V_58 ;
}
int F_28 ( void * V_97 , T_1 V_98 , unsigned char V_99 ,
const void * V_100 , T_1 V_101 )
{
struct V_53 * V_11 = V_97 ;
struct V_54 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
const char * V_27 = V_100 ;
while ( ! * V_27 && V_101 ) {
V_27 ++ ;
V_101 -- ;
}
if ( ! V_11 -> V_20 || ! V_101 || V_101 > V_11 -> V_20 ) {
V_11 -> V_61 = NULL ;
return - V_18 ;
}
V_11 -> V_61 = F_23 ( V_10 , V_11 -> V_20 , & V_11 -> V_72 , V_78 ) ;
if ( ! V_11 -> V_61 ) {
V_11 -> V_61 = NULL ;
return - V_74 ;
}
memcpy ( V_11 -> V_61 + ( V_11 -> V_20 - V_101 ) , V_27 , V_101 ) ;
return 0 ;
}
int F_29 ( void * V_97 , T_1 V_98 , unsigned char V_99 ,
const void * V_100 , T_1 V_101 )
{
struct V_53 * V_11 = V_97 ;
struct V_54 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
const char * V_27 = V_100 ;
int V_58 ;
while ( ! * V_27 && V_101 ) {
V_27 ++ ;
V_101 -- ;
}
V_58 = - V_18 ;
if ( ! V_11 -> V_20 || ! V_101 || V_101 > V_11 -> V_20 )
goto V_14;
if ( V_102 && ( V_101 != 256 && V_101 != 384 ) ) {
F_27 ( L_1 ) ;
goto V_14;
}
V_58 = - V_74 ;
V_11 -> V_94 = F_23 ( V_10 , V_11 -> V_20 , & V_11 -> V_96 , V_78 ) ;
if ( ! V_11 -> V_60 )
goto V_14;
memcpy ( V_11 -> V_94 + ( V_11 -> V_20 - V_101 ) , V_27 , V_101 ) ;
return 0 ;
V_14:
V_11 -> V_94 = NULL ;
return V_58 ;
}
static int F_30 ( struct V_51 * V_52 , const void * V_103 ,
unsigned int V_104 , bool V_105 )
{
struct V_53 * V_11 = F_16 ( V_52 ) ;
struct V_9 * V_10 = & F_4 ( V_11 -> V_12 -> V_13 ) ;
int V_58 ;
if ( V_11 -> V_60 )
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_60 , V_11 -> V_73 ) ;
if ( V_11 -> V_61 )
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_61 , V_11 -> V_72 ) ;
if ( V_11 -> V_94 ) {
memset ( V_11 -> V_94 , '\0' , V_11 -> V_20 ) ;
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_94 , V_11 -> V_96 ) ;
}
V_11 -> V_60 = NULL ;
V_11 -> V_61 = NULL ;
V_11 -> V_94 = NULL ;
if ( V_105 )
V_58 = F_31 ( & V_106 , V_11 , V_103 ,
V_104 ) ;
else
V_58 = F_31 ( & V_107 , V_11 , V_103 ,
V_104 ) ;
if ( V_58 < 0 )
goto free;
if ( ! V_11 -> V_60 || ! V_11 -> V_61 ) {
V_58 = - V_18 ;
goto free;
}
if ( V_105 && ! V_11 -> V_94 ) {
V_58 = - V_18 ;
goto free;
}
return 0 ;
free:
if ( V_11 -> V_94 ) {
memset ( V_11 -> V_94 , '\0' , V_11 -> V_20 ) ;
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_94 , V_11 -> V_96 ) ;
V_11 -> V_94 = NULL ;
}
if ( V_11 -> V_61 ) {
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_61 , V_11 -> V_72 ) ;
V_11 -> V_61 = NULL ;
}
if ( V_11 -> V_60 ) {
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_60 , V_11 -> V_73 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_20 = 0 ;
}
return V_58 ;
}
static int F_32 ( struct V_51 * V_52 , const void * V_103 ,
unsigned int V_104 )
{
return F_30 ( V_52 , V_103 , V_104 , false ) ;
}
static int F_33 ( struct V_51 * V_52 , const void * V_103 ,
unsigned int V_104 )
{
return F_30 ( V_52 , V_103 , V_104 , true ) ;
}
static int F_34 ( struct V_51 * V_52 )
{
struct V_53 * V_11 = F_16 ( V_52 ) ;
return ( V_11 -> V_60 ) ? V_11 -> V_20 : - V_18 ;
}
static int F_35 ( struct V_51 * V_52 )
{
struct V_53 * V_11 = F_16 ( V_52 ) ;
struct V_54 * V_12 =
F_36 ( F_37 () ) ;
if ( ! V_12 )
return - V_18 ;
V_11 -> V_20 = 0 ;
V_11 -> V_12 = V_12 ;
return 0 ;
}
static void F_38 ( struct V_51 * V_52 )
{
struct V_53 * V_11 = F_16 ( V_52 ) ;
struct V_9 * V_10 = & F_4 ( V_11 -> V_12 -> V_13 ) ;
if ( V_11 -> V_60 )
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_60 , V_11 -> V_73 ) ;
if ( V_11 -> V_61 )
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_61 , V_11 -> V_72 ) ;
if ( V_11 -> V_94 ) {
memset ( V_11 -> V_94 , '\0' , V_11 -> V_20 ) ;
F_6 ( V_10 , V_11 -> V_20 , V_11 -> V_94 , V_11 -> V_96 ) ;
}
F_39 ( V_11 -> V_12 ) ;
V_11 -> V_60 = NULL ;
V_11 -> V_94 = NULL ;
V_11 -> V_94 = NULL ;
}
int F_40 ( void )
{
int V_58 = 0 ;
F_41 ( & V_108 ) ;
if ( ++ V_109 == 1 ) {
V_110 . V_111 . V_112 = 0 ;
V_58 = F_42 ( & V_110 ) ;
}
F_43 ( & V_108 ) ;
return V_58 ;
}
void F_44 ( void )
{
F_41 ( & V_108 ) ;
if ( -- V_109 == 0 )
F_45 ( & V_110 ) ;
F_43 ( & V_108 ) ;
}
