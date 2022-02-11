static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) ( V_5 long ) V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( F_3 ( V_4 ) , 64 ) ;
struct V_9 * V_10 = & F_4 ( V_8 -> V_11 -> V_12 -> V_13 ) ;
int V_14 = F_5 (
V_2 -> V_15 . V_16 ) ;
char * V_17 = V_4 -> V_18 ;
V_14 = ( V_14 == V_19 ) ? 0 : - V_20 ;
if ( V_8 -> V_21 )
F_6 ( V_10 , V_8 -> V_11 -> V_22 , V_8 -> V_21 ,
V_8 -> V_23 . V_24 . V_25 ) ;
else
F_7 ( V_10 , V_8 -> V_23 . V_24 . V_25 , V_8 -> V_11 -> V_22 ,
V_26 ) ;
F_7 ( V_10 , V_8 -> V_27 . V_24 . V_28 , V_8 -> V_11 -> V_22 ,
V_29 ) ;
F_7 ( V_10 , V_8 -> V_30 , sizeof( struct V_31 ) ,
V_26 ) ;
F_7 ( V_10 , V_8 -> V_32 ,
sizeof( struct V_33 ) ,
V_26 ) ;
V_4 -> V_34 = V_8 -> V_11 -> V_22 ;
while ( ! ( * V_17 ) && V_4 -> V_34 ) {
V_4 -> V_34 -- ;
V_17 ++ ;
}
if ( V_4 -> V_34 != V_8 -> V_11 -> V_22 )
memmove ( V_4 -> V_18 , V_17 , V_4 -> V_34 ) ;
F_8 ( V_4 , V_14 ) ;
}
void F_9 ( void * V_35 )
{
struct V_1 * V_2 = V_35 ;
F_1 ( V_2 ) ;
}
static unsigned long F_10 ( unsigned int V_36 )
{
unsigned int V_37 = V_36 << 3 ;
switch ( V_37 ) {
case 512 :
return V_38 ;
case 1024 :
return V_39 ;
case 1536 :
return V_40 ;
case 2048 :
return V_41 ;
case 3072 :
return V_42 ;
case 4096 :
return V_43 ;
default:
return 0 ;
} ;
}
static unsigned long F_11 ( unsigned int V_36 )
{
unsigned int V_37 = V_36 << 3 ;
switch ( V_37 ) {
case 512 :
return V_44 ;
case 1024 :
return V_45 ;
case 1536 :
return V_46 ;
case 2048 :
return V_47 ;
case 3072 :
return V_48 ;
case 4096 :
return V_49 ;
default:
return 0 ;
} ;
}
static int F_12 ( struct V_3 * V_8 )
{
struct V_50 * V_51 = F_13 ( V_8 ) ;
struct V_52 * V_11 = F_14 ( V_51 ) ;
struct V_53 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
struct V_7 * V_54 =
F_2 ( F_3 ( V_8 ) , 64 ) ;
struct V_55 * V_56 = & V_54 -> V_8 ;
int V_57 , V_58 = 0 ;
if ( F_15 ( ! V_11 -> V_59 || ! V_11 -> V_60 ) )
return - V_20 ;
if ( V_8 -> V_34 < V_11 -> V_22 ) {
V_8 -> V_34 = V_11 -> V_22 ;
return - V_61 ;
}
memset ( V_56 , '\0' , sizeof( * V_56 ) ) ;
F_16 ( V_56 -> V_62 ,
V_63 ) ;
V_56 -> V_62 . V_64 . V_65 = F_10 ( V_11 -> V_22 ) ;
if ( F_15 ( ! V_56 -> V_62 . V_64 . V_65 ) )
return - V_20 ;
V_54 -> V_11 = V_11 ;
V_56 -> V_62 . V_66 = V_67 ;
V_56 -> V_62 . V_68 =
F_17 ( V_69 ,
V_70 ) ;
V_54 -> V_23 . V_24 . V_60 = V_11 -> V_71 ;
V_54 -> V_23 . V_24 . V_59 = V_11 -> V_72 ;
V_57 = - V_73 ;
if ( V_8 -> V_74 < V_11 -> V_22 ) {
int V_75 = V_11 -> V_22 - V_8 -> V_74 ;
V_54 -> V_21 = F_18 ( V_10 , V_11 -> V_22 ,
& V_54 -> V_23 . V_24 . V_25 ,
V_76 ) ;
if ( F_15 ( ! V_54 -> V_21 ) )
return V_57 ;
memcpy ( V_54 -> V_21 + V_75 , V_8 -> V_77 , V_8 -> V_74 ) ;
} else {
V_54 -> V_21 = NULL ;
V_54 -> V_23 . V_24 . V_25 = F_19 ( V_10 , V_8 -> V_77 , V_8 -> V_74 ,
V_26 ) ;
}
V_54 -> V_23 . V_78 [ 3 ] = 0 ;
V_54 -> V_27 . V_24 . V_28 = F_19 ( V_10 , V_8 -> V_18 , V_8 -> V_34 ,
V_29 ) ;
V_54 -> V_27 . V_79 [ 1 ] = 0 ;
V_54 -> V_30 = F_19 ( V_10 , & V_54 -> V_23 . V_24 . V_25 ,
sizeof( struct V_31 ) ,
V_26 ) ;
V_54 -> V_32 = F_19 ( V_10 , & V_54 -> V_27 . V_24 . V_28 ,
sizeof( struct V_33 ) ,
V_26 ) ;
if ( F_15 ( ( ! V_54 -> V_21 &&
F_20 ( V_10 , V_54 -> V_23 . V_24 . V_25 ) ) ||
F_20 ( V_10 , V_54 -> V_27 . V_24 . V_28 ) ||
F_20 ( V_10 , V_54 -> V_30 ) ||
F_20 ( V_10 , V_54 -> V_32 ) ) )
goto V_80;
V_56 -> V_81 . V_82 = V_54 -> V_30 ;
V_56 -> V_81 . V_83 = V_54 -> V_32 ;
V_56 -> V_81 . V_6 = ( V_84 ) ( V_5 long ) V_8 ;
V_56 -> V_85 = 3 ;
V_56 -> V_86 = 1 ;
do {
V_57 = F_21 ( V_11 -> V_12 -> V_87 , ( V_88 * ) V_56 ) ;
} while ( V_57 == - V_89 && V_58 ++ < 100 );
if ( ! V_57 )
return - V_90 ;
V_80:
if ( V_54 -> V_21 )
F_6 ( V_10 , V_11 -> V_22 , V_54 -> V_21 ,
V_54 -> V_23 . V_24 . V_25 ) ;
else
if ( ! F_20 ( V_10 , V_54 -> V_23 . V_24 . V_25 ) )
F_7 ( V_10 , V_54 -> V_23 . V_24 . V_25 , V_11 -> V_22 ,
V_26 ) ;
if ( ! F_20 ( V_10 , V_54 -> V_27 . V_24 . V_28 ) )
F_7 ( V_10 , V_54 -> V_27 . V_24 . V_28 , V_11 -> V_22 ,
V_29 ) ;
if ( ! F_20 ( V_10 , V_54 -> V_30 ) )
F_7 ( V_10 , V_54 -> V_30 ,
sizeof( struct V_31 ) ,
V_26 ) ;
if ( ! F_20 ( V_10 , V_54 -> V_32 ) )
F_7 ( V_10 , V_54 -> V_32 ,
sizeof( struct V_33 ) ,
V_26 ) ;
return V_57 ;
}
static int F_22 ( struct V_3 * V_8 )
{
struct V_50 * V_51 = F_13 ( V_8 ) ;
struct V_52 * V_11 = F_14 ( V_51 ) ;
struct V_53 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
struct V_7 * V_54 =
F_2 ( F_3 ( V_8 ) , 64 ) ;
struct V_55 * V_56 = & V_54 -> V_8 ;
int V_57 , V_58 = 0 ;
if ( F_15 ( ! V_11 -> V_59 || ! V_11 -> V_91 ) )
return - V_20 ;
if ( V_8 -> V_34 < V_11 -> V_22 ) {
V_8 -> V_34 = V_11 -> V_22 ;
return - V_61 ;
}
memset ( V_56 , '\0' , sizeof( * V_56 ) ) ;
F_16 ( V_56 -> V_62 ,
V_63 ) ;
V_56 -> V_62 . V_64 . V_65 = F_11 ( V_11 -> V_22 ) ;
if ( F_15 ( ! V_56 -> V_62 . V_64 . V_65 ) )
return - V_20 ;
V_54 -> V_11 = V_11 ;
V_56 -> V_62 . V_66 = V_67 ;
V_56 -> V_62 . V_68 =
F_17 ( V_69 ,
V_70 ) ;
V_54 -> V_23 . V_92 . V_91 = V_11 -> V_93 ;
V_54 -> V_23 . V_92 . V_59 = V_11 -> V_72 ;
V_57 = - V_73 ;
if ( V_8 -> V_74 < V_11 -> V_22 ) {
int V_75 = V_11 -> V_22 - V_8 -> V_74 ;
V_54 -> V_21 = F_18 ( V_10 , V_11 -> V_22 ,
& V_54 -> V_23 . V_92 . V_28 ,
V_76 ) ;
if ( F_15 ( ! V_54 -> V_21 ) )
return V_57 ;
memcpy ( V_54 -> V_21 + V_75 , V_8 -> V_77 , V_8 -> V_74 ) ;
} else {
V_54 -> V_21 = NULL ;
V_54 -> V_23 . V_92 . V_28 = F_19 ( V_10 , V_8 -> V_77 , V_8 -> V_74 ,
V_26 ) ;
}
V_54 -> V_23 . V_78 [ 3 ] = 0 ;
V_54 -> V_27 . V_92 . V_25 = F_19 ( V_10 , V_8 -> V_18 , V_8 -> V_34 ,
V_29 ) ;
V_54 -> V_27 . V_79 [ 1 ] = 0 ;
V_54 -> V_30 = F_19 ( V_10 , & V_54 -> V_23 . V_92 . V_28 ,
sizeof( struct V_31 ) ,
V_26 ) ;
V_54 -> V_32 = F_19 ( V_10 , & V_54 -> V_27 . V_92 . V_25 ,
sizeof( struct V_33 ) ,
V_26 ) ;
if ( F_15 ( ( ! V_54 -> V_21 &&
F_20 ( V_10 , V_54 -> V_23 . V_92 . V_28 ) ) ||
F_20 ( V_10 , V_54 -> V_27 . V_92 . V_25 ) ||
F_20 ( V_10 , V_54 -> V_30 ) ||
F_20 ( V_10 , V_54 -> V_32 ) ) )
goto V_80;
V_56 -> V_81 . V_82 = V_54 -> V_30 ;
V_56 -> V_81 . V_83 = V_54 -> V_32 ;
V_56 -> V_81 . V_6 = ( V_84 ) ( V_5 long ) V_8 ;
V_56 -> V_85 = 3 ;
V_56 -> V_86 = 1 ;
do {
V_57 = F_21 ( V_11 -> V_12 -> V_87 , ( V_88 * ) V_56 ) ;
} while ( V_57 == - V_89 && V_58 ++ < 100 );
if ( ! V_57 )
return - V_90 ;
V_80:
if ( V_54 -> V_21 )
F_6 ( V_10 , V_11 -> V_22 , V_54 -> V_21 ,
V_54 -> V_23 . V_92 . V_28 ) ;
else
if ( ! F_20 ( V_10 , V_54 -> V_23 . V_92 . V_28 ) )
F_7 ( V_10 , V_54 -> V_23 . V_92 . V_28 , V_11 -> V_22 ,
V_26 ) ;
if ( ! F_20 ( V_10 , V_54 -> V_27 . V_92 . V_25 ) )
F_7 ( V_10 , V_54 -> V_27 . V_92 . V_25 , V_11 -> V_22 ,
V_29 ) ;
if ( ! F_20 ( V_10 , V_54 -> V_30 ) )
F_7 ( V_10 , V_54 -> V_30 ,
sizeof( struct V_31 ) ,
V_26 ) ;
if ( ! F_20 ( V_10 , V_54 -> V_32 ) )
F_7 ( V_10 , V_54 -> V_32 ,
sizeof( struct V_33 ) ,
V_26 ) ;
return V_57 ;
}
int F_23 ( void * V_94 , T_1 V_95 , unsigned char V_96 ,
const void * V_97 , T_1 V_98 )
{
struct V_52 * V_11 = V_94 ;
struct V_53 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
const char * V_17 = V_97 ;
int V_57 ;
while ( ! * V_17 && V_98 ) {
V_17 ++ ;
V_98 -- ;
}
V_11 -> V_22 = V_98 ;
V_57 = - V_20 ;
if ( V_99 && ( V_11 -> V_22 != 256 && V_11 -> V_22 != 384 ) ) {
F_24 ( L_1 ) ;
goto V_14;
}
if ( ! F_10 ( V_11 -> V_22 ) )
goto V_14;
V_57 = - V_73 ;
V_11 -> V_59 = F_18 ( V_10 , V_11 -> V_22 , & V_11 -> V_72 , V_76 ) ;
if ( ! V_11 -> V_59 )
goto V_14;
memcpy ( V_11 -> V_59 , V_17 , V_11 -> V_22 ) ;
return 0 ;
V_14:
V_11 -> V_22 = 0 ;
V_11 -> V_59 = NULL ;
return V_57 ;
}
int F_25 ( void * V_94 , T_1 V_95 , unsigned char V_96 ,
const void * V_97 , T_1 V_98 )
{
struct V_52 * V_11 = V_94 ;
struct V_53 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
const char * V_17 = V_97 ;
while ( ! * V_17 && V_98 ) {
V_17 ++ ;
V_98 -- ;
}
if ( ! V_11 -> V_22 || ! V_98 || V_98 > V_11 -> V_22 ) {
V_11 -> V_60 = NULL ;
return - V_20 ;
}
V_11 -> V_60 = F_18 ( V_10 , V_11 -> V_22 , & V_11 -> V_71 , V_76 ) ;
if ( ! V_11 -> V_60 ) {
V_11 -> V_60 = NULL ;
return - V_73 ;
}
memcpy ( V_11 -> V_60 + ( V_11 -> V_22 - V_98 ) , V_17 , V_98 ) ;
return 0 ;
}
int F_26 ( void * V_94 , T_1 V_95 , unsigned char V_96 ,
const void * V_97 , T_1 V_98 )
{
struct V_52 * V_11 = V_94 ;
struct V_53 * V_12 = V_11 -> V_12 ;
struct V_9 * V_10 = & F_4 ( V_12 -> V_13 ) ;
const char * V_17 = V_97 ;
int V_57 ;
while ( ! * V_17 && V_98 ) {
V_17 ++ ;
V_98 -- ;
}
V_57 = - V_20 ;
if ( ! V_11 -> V_22 || ! V_98 || V_98 > V_11 -> V_22 )
goto V_14;
if ( V_99 && ( V_98 != 256 && V_98 != 384 ) ) {
F_24 ( L_1 ) ;
goto V_14;
}
V_57 = - V_73 ;
V_11 -> V_91 = F_18 ( V_10 , V_11 -> V_22 , & V_11 -> V_93 , V_76 ) ;
if ( ! V_11 -> V_59 )
goto V_14;
memcpy ( V_11 -> V_91 + ( V_11 -> V_22 - V_98 ) , V_17 , V_98 ) ;
return 0 ;
V_14:
V_11 -> V_91 = NULL ;
return V_57 ;
}
static int F_27 ( struct V_50 * V_51 , const void * V_100 ,
unsigned int V_101 )
{
struct V_52 * V_11 = F_14 ( V_51 ) ;
struct V_9 * V_10 = & F_4 ( V_11 -> V_12 -> V_13 ) ;
int V_57 ;
if ( V_11 -> V_59 )
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_59 , V_11 -> V_72 ) ;
if ( V_11 -> V_60 )
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_60 , V_11 -> V_71 ) ;
if ( V_11 -> V_91 ) {
memset ( V_11 -> V_91 , '\0' , V_11 -> V_22 ) ;
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_91 , V_11 -> V_93 ) ;
}
V_11 -> V_59 = NULL ;
V_11 -> V_60 = NULL ;
V_11 -> V_91 = NULL ;
V_57 = F_28 ( & V_102 , V_11 , V_100 , V_101 ) ;
if ( V_57 < 0 )
goto free;
if ( ! V_11 -> V_59 || ! V_11 -> V_60 ) {
V_57 = - V_20 ;
goto free;
}
return 0 ;
free:
if ( V_11 -> V_91 ) {
memset ( V_11 -> V_91 , '\0' , V_11 -> V_22 ) ;
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_91 , V_11 -> V_93 ) ;
V_11 -> V_91 = NULL ;
}
if ( V_11 -> V_60 ) {
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_60 , V_11 -> V_71 ) ;
V_11 -> V_60 = NULL ;
}
if ( V_11 -> V_59 ) {
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_59 , V_11 -> V_72 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_22 = 0 ;
}
return V_57 ;
}
static int F_29 ( struct V_50 * V_51 )
{
struct V_52 * V_11 = F_14 ( V_51 ) ;
struct V_53 * V_12 =
F_30 ( F_31 () ) ;
if ( ! V_12 )
return - V_20 ;
V_11 -> V_22 = 0 ;
V_11 -> V_12 = V_12 ;
return 0 ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_52 * V_11 = F_14 ( V_51 ) ;
struct V_9 * V_10 = & F_4 ( V_11 -> V_12 -> V_13 ) ;
if ( V_11 -> V_59 )
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_59 , V_11 -> V_72 ) ;
if ( V_11 -> V_60 )
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_60 , V_11 -> V_71 ) ;
if ( V_11 -> V_91 ) {
memset ( V_11 -> V_91 , '\0' , V_11 -> V_22 ) ;
F_6 ( V_10 , V_11 -> V_22 , V_11 -> V_91 , V_11 -> V_93 ) ;
}
F_33 ( V_11 -> V_12 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_91 = NULL ;
V_11 -> V_91 = NULL ;
}
int F_34 ( void )
{
int V_57 = 0 ;
F_35 ( & V_103 ) ;
if ( ++ V_104 == 1 ) {
V_105 . V_106 . V_107 = 0 ;
V_57 = F_36 ( & V_105 ) ;
}
F_37 ( & V_103 ) ;
return V_57 ;
}
void F_38 ( void )
{
F_35 ( & V_103 ) ;
if ( -- V_104 == 0 )
F_39 ( & V_105 ) ;
F_37 ( & V_103 ) ;
}
