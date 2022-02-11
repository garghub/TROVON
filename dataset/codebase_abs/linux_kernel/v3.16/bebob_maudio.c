int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
T_1 V_7 ;
T_2 V_8 [ 3 ] = {
V_9 ,
V_10 ,
V_11
} ;
V_5 = F_3 ( V_2 , V_12 ,
& V_7 , sizeof( T_1 ) ) ;
if ( V_5 < 0 )
goto V_13;
if ( V_7 < 0x3230303730343031LL ) {
F_4 ( & V_2 -> V_4 ,
L_1 ) ;
V_5 = - V_14 ;
goto V_13;
}
V_6 = F_5 ( V_4 -> V_15 , V_16 ,
V_4 -> V_17 , V_4 -> V_18 ,
V_4 -> V_19 , V_20 ,
V_8 , sizeof( V_8 ) ) ;
if ( V_6 != V_21 ) {
F_4 ( & V_2 -> V_4 ,
L_2 ) ;
V_5 = - V_22 ;
}
V_13:
return V_5 ;
}
static inline int
F_6 ( struct V_23 * V_24 , void * V_25 , unsigned int V_26 )
{
return F_7 ( V_24 -> V_2 , V_27 ,
V_28 + V_29 ,
V_25 , V_26 , 0 ) ;
}
static int
F_8 ( struct V_23 * V_24 , unsigned int V_26 , bool * V_30 )
{
int V_5 ;
T_3 * V_25 ;
V_25 = F_9 ( V_26 , V_31 ) ;
if ( V_25 == NULL )
return - V_32 ;
V_5 = F_6 ( V_24 , V_25 , V_26 ) ;
if ( V_5 < 0 )
goto V_13;
* V_30 = ( V_25 [ V_26 - 2 ] != 0xff ) ;
V_13:
F_10 ( V_25 ) ;
return V_5 ;
}
static int
F_11 ( struct V_23 * V_24 , unsigned int V_33 ,
unsigned int V_34 , unsigned int V_35 ,
unsigned int V_36 )
{
struct V_37 * V_38 = V_24 -> V_39 ;
int V_5 ;
T_3 * V_25 ;
if ( F_12 ( & V_24 -> V_40 ) ||
F_12 ( & V_24 -> V_41 ) )
return - V_42 ;
V_25 = F_9 ( 12 , V_31 ) ;
if ( V_25 == NULL )
return - V_32 ;
V_25 [ 0 ] = 0x00 ;
V_25 [ 1 ] = 0xff ;
V_25 [ 2 ] = 0x00 ;
V_25 [ 3 ] = 0x04 ;
V_25 [ 4 ] = 0x00 ;
V_25 [ 5 ] = 0x04 ;
V_25 [ 6 ] = 0xff & V_33 ;
V_25 [ 7 ] = 0xff & V_34 ;
V_25 [ 8 ] = 0xff & V_35 ;
V_25 [ 9 ] = 0xff & V_36 ;
V_25 [ 10 ] = 0x00 ;
V_25 [ 11 ] = 0x00 ;
V_5 = F_13 ( V_24 -> V_2 , V_25 , 12 , V_25 , 12 ,
F_14 ( 1 ) | F_14 ( 2 ) | F_14 ( 3 ) | F_14 ( 4 ) |
F_14 ( 5 ) | F_14 ( 6 ) | F_14 ( 7 ) | F_14 ( 8 ) |
F_14 ( 9 ) ) ;
if ( ( V_5 > 0 ) && ( V_5 < 10 ) )
V_5 = - V_22 ;
else if ( V_25 [ 0 ] == 0x08 )
V_5 = - V_14 ;
else if ( V_25 [ 0 ] == 0x0a )
V_5 = - V_43 ;
if ( V_5 < 0 )
goto V_13;
V_38 -> V_33 = V_25 [ 6 ] ;
V_38 -> V_34 = V_25 [ 7 ] ;
V_38 -> V_35 = V_25 [ 8 ] ;
V_38 -> V_36 = V_25 [ 9 ] ;
if ( V_38 -> V_44 )
F_15 ( V_24 -> V_15 , V_45 ,
V_38 -> V_44 ) ;
V_5 = 0 ;
V_13:
F_10 ( V_25 ) ;
return V_5 ;
}
static void
F_16 ( struct V_23 * V_24 )
{
static const unsigned int V_46 [ 2 ] [ 2 ] [ 3 ] = {
{ { 6 , 6 , 4 } ,
{ 12 , 8 , 4 } } ,
{ { 10 , 10 , 2 } ,
{ 16 , 12 , 2 } }
} ;
struct V_37 * V_38 = V_24 -> V_39 ;
unsigned int V_47 , V_48 ;
V_48 = V_49 - 1 ;
if ( ! V_38 -> V_50 )
V_48 -= 2 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_24 -> V_51 [ V_47 + 1 ] . V_52 =
V_46 [ V_53 ] [ V_38 -> V_34 ] [ V_47 / 2 ] ;
V_24 -> V_51 [ V_47 + 1 ] . V_54 = 1 ;
V_24 -> V_55 [ V_47 + 1 ] . V_52 =
V_46 [ V_56 ] [ V_38 -> V_35 ] [ V_47 / 2 ] ;
V_24 -> V_55 [ V_47 + 1 ] . V_54 = 1 ;
}
}
int
F_17 ( struct V_23 * V_24 , bool V_50 )
{
struct V_37 * V_38 ;
int V_5 ;
V_38 = F_18 ( sizeof( struct V_37 ) , V_31 ) ;
if ( V_38 == NULL )
return - V_32 ;
F_19 ( & V_24 -> V_57 ) ;
V_24 -> V_39 = ( void * ) V_38 ;
V_38 -> V_50 = V_50 ;
V_24 -> V_40 . V_58 = F_20 ( - 1 ) ;
V_24 -> V_41 . V_58 = F_20 ( - 1 ) ;
V_5 = F_11 ( V_24 , 0x03 , 0x00 , 0x00 , 0x00 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_24 -> V_2 -> V_4 ,
L_3 , V_5 ) ;
goto V_13;
}
V_5 = F_21 ( V_24 ) ;
if ( V_5 < 0 )
goto V_13;
F_16 ( V_24 ) ;
if ( V_38 -> V_50 ) {
V_24 -> V_59 = 1 ;
V_24 -> V_60 = 1 ;
} else {
V_24 -> V_59 = 2 ;
V_24 -> V_60 = 2 ;
}
V_13:
if ( V_5 < 0 ) {
F_10 ( V_38 ) ;
V_24 -> V_39 = NULL ;
}
F_22 ( & V_24 -> V_57 ) ;
return V_5 ;
}
static int F_23 ( struct V_23 * V_24 , unsigned int * V_61 )
{
int V_5 , V_62 ;
V_62 = 0 ;
do {
V_5 = F_24 ( V_24 -> V_2 , V_61 ,
V_63 , 0 ) ;
} while ( V_5 == - V_64 && ++ V_62 < 3 );
return V_5 ;
}
static int F_25 ( struct V_23 * V_24 , unsigned int V_61 )
{
struct V_37 * V_38 = V_24 -> V_39 ;
int V_5 ;
V_5 = F_26 ( V_24 -> V_2 , V_61 ,
V_65 , 0 ) ;
if ( V_5 < 0 )
goto V_13;
F_27 ( 100 ) ;
V_5 = F_26 ( V_24 -> V_2 , V_61 ,
V_63 , 0 ) ;
if ( V_5 < 0 )
goto V_13;
if ( V_38 -> V_44 )
F_15 ( V_24 -> V_15 , V_45 ,
V_38 -> V_44 ) ;
V_13:
return V_5 ;
}
static int F_28 ( struct V_23 * V_24 , unsigned int * V_66 )
{
struct V_37 * V_38 = V_24 -> V_39 ;
* V_66 = V_38 -> V_33 ;
return 0 ;
}
static int F_29 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
V_70 -> type = V_71 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 . V_74 . V_75 = F_30 ( V_76 ) ;
if ( V_70 -> V_73 . V_74 . V_77 >= V_70 -> V_73 . V_74 . V_75 )
V_70 -> V_73 . V_74 . V_77 = V_70 -> V_73 . V_74 . V_75 - 1 ;
strcpy ( V_70 -> V_73 . V_74 . V_78 ,
V_76 [ V_70 -> V_73 . V_74 . V_77 ] ) ;
return 0 ;
}
static int F_31 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
struct V_37 * V_38 = V_24 -> V_39 ;
V_80 -> V_73 . V_74 . V_77 [ 0 ] = V_38 -> V_33 ;
return 0 ;
}
static int F_33 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
struct V_37 * V_38 = V_24 -> V_39 ;
int V_5 , V_66 ;
V_66 = V_80 -> V_73 . V_74 . V_77 [ 0 ] ;
if ( V_66 >= F_30 ( V_76 ) )
return - V_43 ;
F_19 ( & V_24 -> V_57 ) ;
V_5 = F_11 ( V_24 , V_66 ,
V_38 -> V_34 ,
V_38 -> V_35 ,
V_38 -> V_36 ) ;
F_22 ( & V_24 -> V_57 ) ;
if ( V_5 >= 0 )
V_5 = 1 ;
return V_5 ;
}
static int F_34 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
V_70 -> type = V_81 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 . integer . V_82 = 0 ;
V_70 -> V_73 . integer . V_48 = 1 ;
return 0 ;
}
static int F_35 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
int V_5 ;
bool V_83 = 0 ;
V_5 = F_8 ( V_24 , V_84 , & V_83 ) ;
if ( V_5 >= 0 )
V_80 -> V_73 . integer . V_73 [ 0 ] = V_83 ;
return 0 ;
}
static int F_36 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
V_70 -> type = V_71 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 . V_74 . V_75 = F_30 ( V_85 ) ;
if ( V_70 -> V_73 . V_74 . V_77 >= V_70 -> V_73 . V_74 . V_75 )
V_70 -> V_73 . V_74 . V_77 = V_70 -> V_73 . V_74 . V_75 - 1 ;
strcpy ( V_70 -> V_73 . V_74 . V_78 ,
V_85 [ V_70 -> V_73 . V_74 . V_77 ] ) ;
return 0 ;
}
static int F_37 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
struct V_37 * V_38 = V_24 -> V_39 ;
unsigned int V_86 ;
int V_5 , V_87 ;
F_19 ( & V_24 -> V_57 ) ;
V_5 = F_38 ( V_24 -> V_2 , 0x00 , 0x04 ,
& V_86 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_24 -> V_2 -> V_4 ,
L_4 , V_5 ) ;
goto V_13;
}
V_87 = ( V_38 -> V_34 << 1 ) | ( V_86 & 0x01 ) ;
if ( V_87 > 2 )
V_87 = 2 ;
V_80 -> V_73 . V_74 . V_77 [ 0 ] = V_87 ;
V_13:
F_22 ( & V_24 -> V_57 ) ;
return V_5 ;
}
static int F_39 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
struct V_37 * V_38 = V_24 -> V_39 ;
unsigned int V_66 , V_34 , V_86 ;
int V_5 ;
V_66 = V_80 -> V_73 . V_74 . V_77 [ 0 ] ;
if ( V_66 >= F_30 ( V_85 ) )
return - V_43 ;
V_34 = ( V_66 >> 1 ) & 0x01 ;
V_86 = V_66 & 0x01 ;
F_19 ( & V_24 -> V_57 ) ;
V_5 = F_11 ( V_24 ,
V_38 -> V_33 ,
V_34 ,
V_38 -> V_35 ,
V_38 -> V_36 ) ;
if ( V_5 < 0 )
goto V_13;
if ( V_38 -> V_34 > 0 ) {
V_5 = 1 ;
goto V_13;
}
V_5 = F_40 ( V_24 -> V_2 , 0x00 , 0x04 , V_86 ) ;
if ( V_5 < 0 )
F_4 ( & V_24 -> V_2 -> V_4 ,
L_5 , V_5 ) ;
V_5 = 1 ;
V_13:
F_16 ( V_24 ) ;
F_22 ( & V_24 -> V_57 ) ;
return V_5 ;
}
static int F_41 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
V_70 -> type = V_71 ;
V_70 -> V_72 = 1 ;
V_70 -> V_73 . V_74 . V_75 = F_30 ( V_88 ) ;
if ( V_70 -> V_73 . V_74 . V_77 >= V_70 -> V_73 . V_74 . V_75 )
V_70 -> V_73 . V_74 . V_77 = V_70 -> V_73 . V_74 . V_75 - 1 ;
strcpy ( V_70 -> V_73 . V_74 . V_78 ,
V_88 [ V_70 -> V_73 . V_74 . V_77 ] ) ;
return 0 ;
}
static int F_42 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
struct V_37 * V_38 = V_24 -> V_39 ;
F_19 ( & V_24 -> V_57 ) ;
V_80 -> V_73 . V_74 . V_77 [ 0 ] = V_38 -> V_35 ;
F_22 ( & V_24 -> V_57 ) ;
return 0 ;
}
static int F_43 ( struct V_67 * V_68 ,
struct V_79 * V_80 )
{
struct V_23 * V_24 = F_32 ( V_68 ) ;
struct V_37 * V_38 = V_24 -> V_39 ;
unsigned int V_66 ;
int V_5 ;
V_66 = V_80 -> V_73 . V_74 . V_77 [ 0 ] ;
if ( V_66 >= F_30 ( V_88 ) )
return - V_43 ;
F_19 ( & V_24 -> V_57 ) ;
V_5 = F_11 ( V_24 ,
V_38 -> V_33 ,
V_38 -> V_34 ,
V_66 , V_38 -> V_36 ) ;
if ( V_5 >= 0 ) {
F_16 ( V_24 ) ;
V_5 = 1 ;
}
F_22 ( & V_24 -> V_57 ) ;
return V_5 ;
}
static int F_21 ( struct V_23 * V_24 )
{
struct V_67 * V_68 ;
struct V_37 * V_38 = V_24 -> V_39 ;
int V_5 ;
V_68 = F_44 ( & V_89 , V_24 ) ;
V_5 = F_45 ( V_24 -> V_15 , V_68 ) ;
if ( V_5 < 0 )
goto V_13;
V_68 = F_44 ( & V_90 , V_24 ) ;
V_5 = F_45 ( V_24 -> V_15 , V_68 ) ;
if ( V_5 < 0 )
goto V_13;
V_38 -> V_44 = & V_68 -> V_66 ;
V_68 = F_44 ( & V_91 , V_24 ) ;
V_5 = F_45 ( V_24 -> V_15 , V_68 ) ;
if ( V_5 < 0 )
goto V_13;
V_68 = F_44 ( & V_92 , V_24 ) ;
V_5 = F_45 ( V_24 -> V_15 , V_68 ) ;
V_13:
return V_5 ;
}
static int
F_46 ( struct V_23 * V_24 , T_4 * V_93 , unsigned int V_26 )
{
T_5 * V_25 ;
unsigned int V_47 , V_94 , V_95 ;
int V_5 ;
V_95 = F_30 ( V_96 ) * 2 ;
if ( V_26 < V_95 * sizeof( T_4 ) )
return - V_43 ;
V_25 = F_9 ( V_84 - 4 , V_31 ) ;
if ( V_25 == NULL )
return - V_32 ;
V_5 = F_6 ( V_24 , ( void * ) V_25 , V_84 - 4 ) ;
if ( V_5 < 0 )
goto V_13;
V_47 = 0 ;
for ( V_94 = 2 ; V_94 < V_95 + 2 ; V_94 ++ )
V_93 [ V_47 ++ ] = F_47 ( V_25 [ V_94 ] ) << 16 ;
V_13:
F_10 ( V_25 ) ;
return V_5 ;
}
static int
F_48 ( struct V_23 * V_24 , T_4 * V_25 , unsigned int V_26 )
{
struct V_97 * V_98 = V_24 -> V_98 -> V_99 ;
unsigned int V_94 , V_95 ;
int V_5 ;
V_95 = V_98 -> V_100 * 2 ;
if ( V_26 < V_95 * sizeof( T_4 ) )
return - V_43 ;
V_5 = F_6 ( V_24 , ( void * ) V_25 , V_26 ) ;
if ( V_5 < 0 )
goto V_13;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ )
F_49 ( & V_25 [ V_94 ] ) ;
if ( V_98 -> V_101 == V_102 ) {
F_50 ( V_25 [ 4 ] , V_25 [ 6 ] ) ;
F_50 ( V_25 [ 5 ] , V_25 [ 7 ] ) ;
}
V_13:
return V_5 ;
}
