int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
T_1 V_7 ;
T_2 V_8 [ 3 ] = {
F_3 ( V_9 ) ,
F_3 ( V_10 ) ,
F_3 (MAUDIO_BOOTLOADER_CUE3)
} ;
V_5 = F_4 ( V_2 , V_11 ,
& V_7 , sizeof( T_1 ) ) ;
if ( V_5 < 0 )
goto V_12;
if ( V_7 < 0x3230303730343031LL ) {
F_5 ( & V_2 -> V_4 ,
L_1 ) ;
V_5 = - V_13 ;
goto V_12;
}
V_6 = F_6 ( V_4 -> V_14 , V_15 ,
V_4 -> V_16 , V_4 -> V_17 ,
V_4 -> V_18 , V_19 ,
V_8 , sizeof( V_8 ) ) ;
if ( V_6 != V_20 ) {
F_5 ( & V_2 -> V_4 ,
L_2 ) ;
V_5 = - V_21 ;
}
V_12:
return V_5 ;
}
static inline int
F_7 ( struct V_22 * V_23 , void * V_24 , unsigned int V_25 )
{
return F_8 ( V_23 -> V_2 , V_26 ,
V_27 + V_28 ,
V_24 , V_25 , 0 ) ;
}
static int
F_9 ( struct V_22 * V_23 , unsigned int V_25 , bool * V_29 )
{
int V_5 ;
T_3 * V_24 ;
V_24 = F_10 ( V_25 , V_30 ) ;
if ( V_24 == NULL )
return - V_31 ;
V_5 = F_7 ( V_23 , V_24 , V_25 ) ;
if ( V_5 < 0 )
goto V_12;
* V_29 = ( V_24 [ V_25 - 2 ] != 0xff ) ;
V_12:
F_11 ( V_24 ) ;
return V_5 ;
}
static int
F_12 ( struct V_22 * V_23 , unsigned int V_32 ,
unsigned int V_33 , unsigned int V_34 ,
unsigned int V_35 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
int V_5 ;
T_3 * V_24 ;
if ( F_13 ( & V_23 -> V_39 ) ||
F_13 ( & V_23 -> V_40 ) )
return - V_41 ;
V_24 = F_10 ( 12 , V_30 ) ;
if ( V_24 == NULL )
return - V_31 ;
V_24 [ 0 ] = 0x00 ;
V_24 [ 1 ] = 0xff ;
V_24 [ 2 ] = 0x00 ;
V_24 [ 3 ] = 0x04 ;
V_24 [ 4 ] = 0x00 ;
V_24 [ 5 ] = 0x04 ;
V_24 [ 6 ] = 0xff & V_32 ;
V_24 [ 7 ] = 0xff & V_33 ;
V_24 [ 8 ] = 0xff & V_34 ;
V_24 [ 9 ] = 0xff & V_35 ;
V_24 [ 10 ] = 0x00 ;
V_24 [ 11 ] = 0x00 ;
V_5 = F_14 ( V_23 -> V_2 , V_24 , 12 , V_24 , 12 ,
F_15 ( 1 ) | F_15 ( 2 ) | F_15 ( 3 ) | F_15 ( 4 ) |
F_15 ( 5 ) | F_15 ( 6 ) | F_15 ( 7 ) | F_15 ( 8 ) |
F_15 ( 9 ) ) ;
if ( ( V_5 > 0 ) && ( V_5 < 10 ) )
V_5 = - V_21 ;
else if ( V_24 [ 0 ] == 0x08 )
V_5 = - V_13 ;
else if ( V_24 [ 0 ] == 0x0a )
V_5 = - V_42 ;
if ( V_5 < 0 )
goto V_12;
V_37 -> V_32 = V_24 [ 6 ] ;
V_37 -> V_33 = V_24 [ 7 ] ;
V_37 -> V_34 = V_24 [ 8 ] ;
V_37 -> V_35 = V_24 [ 9 ] ;
if ( V_37 -> V_43 )
F_16 ( V_23 -> V_14 , V_44 ,
V_37 -> V_43 ) ;
V_5 = 0 ;
V_12:
F_11 ( V_24 ) ;
return V_5 ;
}
static void
F_17 ( struct V_22 * V_23 )
{
static const unsigned int V_45 [ 2 ] [ 2 ] [ 3 ] = {
{ { 6 , 6 , 4 } ,
{ 12 , 8 , 4 } } ,
{ { 10 , 10 , 2 } ,
{ 16 , 12 , 2 } }
} ;
struct V_36 * V_37 = V_23 -> V_38 ;
unsigned int V_46 , V_47 ;
V_47 = V_48 - 1 ;
if ( ! V_37 -> V_49 )
V_47 -= 2 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
V_23 -> V_50 [ V_46 + 1 ] . V_51 =
V_45 [ V_52 ] [ V_37 -> V_33 ] [ V_46 / 2 ] ;
V_23 -> V_50 [ V_46 + 1 ] . V_53 = 1 ;
V_23 -> V_54 [ V_46 + 1 ] . V_51 =
V_45 [ V_55 ] [ V_37 -> V_34 ] [ V_46 / 2 ] ;
V_23 -> V_54 [ V_46 + 1 ] . V_53 = 1 ;
}
}
int
F_18 ( struct V_22 * V_23 , bool V_49 )
{
struct V_36 * V_37 ;
int V_5 ;
V_37 = F_19 ( sizeof( struct V_36 ) , V_30 ) ;
if ( V_37 == NULL )
return - V_31 ;
F_20 ( & V_23 -> V_56 ) ;
V_23 -> V_38 = ( void * ) V_37 ;
V_37 -> V_49 = V_49 ;
V_23 -> V_39 . V_57 = F_21 ( - 1 ) ;
V_23 -> V_40 . V_57 = F_21 ( - 1 ) ;
V_5 = F_12 ( V_23 , 0x03 , 0x00 , 0x00 , 0x00 ) ;
if ( V_5 < 0 ) {
F_5 ( & V_23 -> V_2 -> V_4 ,
L_3 , V_5 ) ;
goto V_12;
}
V_5 = F_22 ( V_23 ) ;
if ( V_5 < 0 )
goto V_12;
F_17 ( V_23 ) ;
if ( V_37 -> V_49 ) {
V_23 -> V_58 = 1 ;
V_23 -> V_59 = 1 ;
} else {
V_23 -> V_58 = 2 ;
V_23 -> V_59 = 2 ;
}
V_12:
if ( V_5 < 0 ) {
F_11 ( V_37 ) ;
V_23 -> V_38 = NULL ;
}
F_23 ( & V_23 -> V_56 ) ;
return V_5 ;
}
static int F_24 ( struct V_22 * V_23 , unsigned int * V_60 )
{
int V_5 , V_61 ;
V_61 = 0 ;
do {
V_5 = F_25 ( V_23 -> V_2 , V_60 ,
V_62 , 0 ) ;
} while ( V_5 == - V_63 && ++ V_61 < 3 );
return V_5 ;
}
static int F_26 ( struct V_22 * V_23 , unsigned int V_60 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
int V_5 ;
V_5 = F_27 ( V_23 -> V_2 , V_60 ,
V_64 , 0 ) ;
if ( V_5 < 0 )
goto V_12;
F_28 ( 100 ) ;
V_5 = F_27 ( V_23 -> V_2 , V_60 ,
V_62 , 0 ) ;
if ( V_5 < 0 )
goto V_12;
if ( V_37 -> V_43 )
F_16 ( V_23 -> V_14 , V_44 ,
V_37 -> V_43 ) ;
V_12:
return V_5 ;
}
static int F_29 ( struct V_22 * V_23 , unsigned int * V_65 )
{
struct V_36 * V_37 = V_23 -> V_38 ;
* V_65 = V_37 -> V_32 ;
return 0 ;
}
static int F_30 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
return F_31 ( V_69 , 1 , F_32 ( V_70 ) ,
V_70 ) ;
}
static int F_33 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
struct V_36 * V_37 = V_23 -> V_38 ;
V_72 -> V_73 . V_74 . V_75 [ 0 ] = V_37 -> V_32 ;
return 0 ;
}
static int F_35 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
struct V_36 * V_37 = V_23 -> V_38 ;
int V_5 , V_65 ;
V_65 = V_72 -> V_73 . V_74 . V_75 [ 0 ] ;
if ( V_65 >= F_32 ( V_70 ) )
return - V_42 ;
F_20 ( & V_23 -> V_56 ) ;
V_5 = F_12 ( V_23 , V_65 ,
V_37 -> V_33 ,
V_37 -> V_34 ,
V_37 -> V_35 ) ;
F_23 ( & V_23 -> V_56 ) ;
if ( V_5 >= 0 )
V_5 = 1 ;
return V_5 ;
}
static int F_36 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
V_69 -> type = V_76 ;
V_69 -> V_77 = 1 ;
V_69 -> V_73 . integer . V_78 = 0 ;
V_69 -> V_73 . integer . V_47 = 1 ;
return 0 ;
}
static int F_37 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
int V_5 ;
bool V_79 = 0 ;
V_5 = F_9 ( V_23 , V_80 , & V_79 ) ;
if ( V_5 >= 0 )
V_72 -> V_73 . integer . V_73 [ 0 ] = V_79 ;
return 0 ;
}
static int F_38 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
return F_31 ( V_69 , 1 ,
F_32 ( V_81 ) ,
V_81 ) ;
}
static int F_39 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
struct V_36 * V_37 = V_23 -> V_38 ;
unsigned int V_82 ;
int V_5 , V_83 ;
F_20 ( & V_23 -> V_56 ) ;
V_5 = F_40 ( V_23 -> V_2 , 0x00 , 0x04 ,
& V_82 ) ;
if ( V_5 < 0 ) {
F_5 ( & V_23 -> V_2 -> V_4 ,
L_4 , V_5 ) ;
goto V_12;
}
V_83 = ( V_37 -> V_33 << 1 ) | ( V_82 & 0x01 ) ;
if ( V_83 > 2 )
V_83 = 2 ;
V_72 -> V_73 . V_74 . V_75 [ 0 ] = V_83 ;
V_12:
F_23 ( & V_23 -> V_56 ) ;
return V_5 ;
}
static int F_41 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
struct V_36 * V_37 = V_23 -> V_38 ;
unsigned int V_65 , V_33 , V_82 ;
int V_5 ;
V_65 = V_72 -> V_73 . V_74 . V_75 [ 0 ] ;
if ( V_65 >= F_32 ( V_81 ) )
return - V_42 ;
V_33 = ( V_65 >> 1 ) & 0x01 ;
V_82 = V_65 & 0x01 ;
F_20 ( & V_23 -> V_56 ) ;
V_5 = F_12 ( V_23 ,
V_37 -> V_32 ,
V_33 ,
V_37 -> V_34 ,
V_37 -> V_35 ) ;
if ( V_5 < 0 )
goto V_12;
if ( V_37 -> V_33 > 0 ) {
V_5 = 1 ;
goto V_12;
}
V_5 = F_42 ( V_23 -> V_2 , 0x00 , 0x04 , V_82 ) ;
if ( V_5 < 0 )
F_5 ( & V_23 -> V_2 -> V_4 ,
L_5 , V_5 ) ;
V_5 = 1 ;
V_12:
F_17 ( V_23 ) ;
F_23 ( & V_23 -> V_56 ) ;
return V_5 ;
}
static int F_43 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
return F_31 ( V_69 , 1 ,
F_32 ( V_84 ) ,
V_84 ) ;
}
static int F_44 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
struct V_36 * V_37 = V_23 -> V_38 ;
F_20 ( & V_23 -> V_56 ) ;
V_72 -> V_73 . V_74 . V_75 [ 0 ] = V_37 -> V_34 ;
F_23 ( & V_23 -> V_56 ) ;
return 0 ;
}
static int F_45 ( struct V_66 * V_67 ,
struct V_71 * V_72 )
{
struct V_22 * V_23 = F_34 ( V_67 ) ;
struct V_36 * V_37 = V_23 -> V_38 ;
unsigned int V_65 ;
int V_5 ;
V_65 = V_72 -> V_73 . V_74 . V_75 [ 0 ] ;
if ( V_65 >= F_32 ( V_84 ) )
return - V_42 ;
F_20 ( & V_23 -> V_56 ) ;
V_5 = F_12 ( V_23 ,
V_37 -> V_32 ,
V_37 -> V_33 ,
V_65 , V_37 -> V_35 ) ;
if ( V_5 >= 0 ) {
F_17 ( V_23 ) ;
V_5 = 1 ;
}
F_23 ( & V_23 -> V_56 ) ;
return V_5 ;
}
static int F_22 ( struct V_22 * V_23 )
{
struct V_66 * V_67 ;
struct V_36 * V_37 = V_23 -> V_38 ;
int V_5 ;
V_67 = F_46 ( & V_85 , V_23 ) ;
V_5 = F_47 ( V_23 -> V_14 , V_67 ) ;
if ( V_5 < 0 )
goto V_12;
V_67 = F_46 ( & V_86 , V_23 ) ;
V_5 = F_47 ( V_23 -> V_14 , V_67 ) ;
if ( V_5 < 0 )
goto V_12;
V_37 -> V_43 = & V_67 -> V_65 ;
V_67 = F_46 ( & V_87 , V_23 ) ;
V_5 = F_47 ( V_23 -> V_14 , V_67 ) ;
if ( V_5 < 0 )
goto V_12;
V_67 = F_46 ( & V_88 , V_23 ) ;
V_5 = F_47 ( V_23 -> V_14 , V_67 ) ;
V_12:
return V_5 ;
}
static int
F_48 ( struct V_22 * V_23 , T_4 * V_89 , unsigned int V_25 )
{
T_5 * V_24 ;
unsigned int V_46 , V_90 , V_91 ;
int V_5 ;
V_91 = F_32 ( V_92 ) * 2 ;
if ( V_25 < V_91 * sizeof( T_4 ) )
return - V_42 ;
V_24 = F_10 ( V_80 - 4 , V_30 ) ;
if ( V_24 == NULL )
return - V_31 ;
V_5 = F_7 ( V_23 , ( void * ) V_24 , V_80 - 4 ) ;
if ( V_5 < 0 )
goto V_12;
V_46 = 0 ;
for ( V_90 = 2 ; V_90 < V_91 + 2 ; V_90 ++ )
V_89 [ V_46 ++ ] = F_49 ( V_24 [ V_90 ] ) << 16 ;
V_12:
F_11 ( V_24 ) ;
return V_5 ;
}
static int
F_50 ( struct V_22 * V_23 , T_4 * V_24 , unsigned int V_25 )
{
struct V_93 * V_94 = V_23 -> V_94 -> V_95 ;
unsigned int V_90 , V_91 ;
int V_5 ;
V_91 = V_94 -> V_96 * 2 ;
if ( V_25 < V_91 * sizeof( T_4 ) )
return - V_42 ;
V_5 = F_7 ( V_23 , ( void * ) V_24 , V_25 ) ;
if ( V_5 < 0 )
goto V_12;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ )
F_51 ( & V_24 [ V_90 ] ) ;
if ( V_94 -> V_97 == V_98 ) {
F_52 ( V_24 [ 4 ] , V_24 [ 6 ] ) ;
F_52 ( V_24 [ 5 ] , V_24 [ 7 ] ) ;
}
V_12:
return V_5 ;
}
